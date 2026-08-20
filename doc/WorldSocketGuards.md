# WorldSocket guard inventory

Checklist for moving `WorldSocket` from ACE to Boost.Asio. Every entry is a
check that exists in the ACE implementation and that must still exist after the
port, verified one by one rather than assumed.

This document exists because of what happened upstream. TrinityCore migrated the
same code in July 2014 and shipped two regressions that were only found much
later:

- `36e32cc` (2014-08-19) — *"Restored opcode and size checks lost during
  ace->boost changes, fixes crashes caused by invalid packets"*, six weeks after
  the migration.
- `d0db999` (2014-10-12) — *"Restored client opcode handler check lost in
  ace->boost transition"*, three months after.

Neither was an Asio bug. Both were guards that quietly failed to survive a
rewrite, leaving a server that crashed on malformed packets.

## Header parsing — `handle_input_header`

| # | Guard | Detail |
|---|-------|--------|
| 1 | Encrypted payload size ceiling | `header.size > 10236` is rejected. Applies once `m_Crypt.IsInitialized()`. |
| 2 | Unencrypted size window | `header.size < 4 \|\| header.size > 10240` is rejected, before the `-= 4` adjustment. |
| 3 | Opcode/size bit split | Encrypted header packs both into one uint32: `cmd = value & 0x1FFF`, `size = (value & ~0x1FFF) >> 13`. Getting the shift wrong silently corrupts every packet. |
| 4 | Header decrypted before parsing | `DecryptRecv` runs over exactly `sizeof(WorldClientPktHeader)` bytes. |
| 5 | High byte drop | `PacketFilter::DropHighBytes(header.cmd)` before the opcode lookup. |

## Packet dispatch — `ProcessIncoming`

| # | Guard | Detail |
|---|-------|--------|
| 6 | Reject while closing | `closing_` short-circuits before any handling. |
| 7 | Duplicate auth | A second `CMSG_AUTH_SESSION` on an authenticated socket drops the connection. |
| 8 | Unauthenticated opcodes | Any opcode other than the handful allowed pre-auth is refused when `m_Session` is null. |
| 9 | **Opcode bounds** | `opcode >= NUM_OPCODES` returns early. This is the check upstream lost in `36e32cc`; without it a custom opcode indexes past the handler table. |
| 10 | **Handler exists** | `!handler \|\| handler->Status == STATUS_UNHANDLED` returns early. Lost upstream in `d0db999`. |
| 11 | Connectivity string | `MSG_VERIFY_CONNECTIVITY` must carry exactly `"D OF WARCRAFT CONNECTION - CLIENT TO SERVER"`. |
| 12 | Idle timer reset | `ResetTimeOutTime()` on any non-ping opcode, which is what disconnects clients idling on the login screen. |

## Ping handling — `HandlePing`

| # | Guard | Detail |
|---|-------|--------|
| 13 | Over-speed ping kick | Pings closer together than 27 seconds increment `m_OverSpeedPings`; crossing `CONFIG_MAX_OVERSPEED_PINGS` drops the connection. |
| 14 | Counter reset | A ping at or beyond 27 seconds resets the counter to zero, so honest clients never accumulate. |
| 15 | Player security exemption | The kick applies only to `SEC_PLAYER`; staff sessions are exempt. |
| 16 | Ping before auth | `CMSG_PING` with no session is logged and refused. |

## Output path

| # | Guard | Detail |
|---|-------|--------|
| 17 | Output queue bound | 8 MB high water mark. Already carried into `Socket<T>::WRITE_QUEUE_HIGH_WATER_MARK`. |
| 18 | 64 KB output buffer | `m_OutBufferSize(65536)`, with writes coalesced on a 10 ms ceiling rather than flushed per packet. Behavioural, not safety, but dropping it will show up as a throughput regression under load. |
| 19 | Header built per crypt state | `ServerPktHeader` sizes differently when the crypt is uninitialised (`size() + 2`). |

## Session lifetime

| # | Guard | Detail |
|---|-------|--------|
| 20 | Auth seed | `m_Seed` from `rand32()` per socket, sent in the auth challenge. |
| 21 | Session lock | `m_SessionLock` guards `m_Session` against the world thread. Under the new design a socket lives on one network thread, so the lock's scope must be re-derived rather than copied. |

## Notes for the port

Guard 21 is the one that cannot be transcribed mechanically. The ACE design had
sockets touched from several threads, so `m_Session` needed a mutex. In the Asio
design a socket lives on exactly one `NetworkThread`, but `m_Session` is still
reachable from the world thread, so the boundary has to be reasoned about again,
not copied across.

Guards 9 and 10 deserve a deliberate test with a crafted packet: they are the
two that upstream lost, and neither shows up in normal play.
