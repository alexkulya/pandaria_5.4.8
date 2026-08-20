/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/** \addtogroup u2w User to World Communication
 * @{
 * \file WorldSocket.h
 * \author Derex <derex101@gmail.com>
 */

#ifndef SF_WORLDSOCKET_H
#define SF_WORLDSOCKET_H

#include <chrono>
#include <memory>
#include <mutex>

#include <boost/asio/ip/tcp.hpp>

#include "Common.h"
#include "AuthCrypt.h"
#include "MessageBuffer.h"
#include "Socket.h"
#include "WorldPacket.h"

class WorldSession;

/**
 * WorldSocket.
 *
 * Transport for the world protocol, backed by Boost.Asio through Socket<T>
 * instead of ACE_Svc_Handler and the ACE reactor.
 *
 * Two things the ACE version did are deliberately kept, because dropping them
 * is a regression rather than a simplification:
 *
 * - The 64 KB output buffer. The core does a great many small writes, and the
 *   ACE version coalesced them into one buffer rather than handing each packet
 *   to the socket on its own. Writes are flushed on a 10 ms ceiling from
 *   Update(), which is the same idea as TCP_CORK with a shorter delay.
 * - The header/payload split. A read can deliver a partial header, so the
 *   fragment is retained and completed on the next read rather than assuming
 *   whole packets arrive at once.
 *
 * Lifetime is now the shared_ptr Socket<T> provides. The ACE reference counting
 * (AddReference/RemoveReference) is gone: WorldSession holds a
 * std::shared_ptr<WorldSocket> and the socket dies when the last owner, which
 * is normally the network thread's list, lets go of it.
 *
 * doc/WorldSocketGuards.md lists every check the ACE implementation performed.
 * They are numbered there and referenced from the implementation, because
 * upstream lost two of them in this same migration and did not notice for
 * months.
 */
class WorldSocket : public Socket<WorldSocket>
{
    typedef Socket<WorldSocket> Base;

public:
    explicit WorldSocket(boost::asio::ip::tcp::socket&& socket);
    ~WorldSocket();

    WorldSocket(WorldSocket const&) = delete;
    WorldSocket& operator=(WorldSocket const&) = delete;

    void Start() override;
    bool Update() override;

    /// Send a packet on the socket, this function is reentrant.
    /// @param pct packet to send
    /// @return -1 on failure. The return is kept for WorldSession, which
    ///         checks it to decide whether to drop the session.
    int SendPacket(WorldPacket const& pct);

    /// Check if socket is closed.
    bool IsClosed() const;

    /// Get address of connected peer.
    std::string const& GetRemoteAddress() const;

protected:
    void OnClose() override;
    bool ReadHandler() override;

private:
    /// Header and payload arrive separately; these consume whatever is
    /// currently buffered and report whether the socket should stay open.
    /// Guards 1-5 live in ReadHeaderHandler.
    bool ReadHeaderHandler();
    bool ReadDataHandler();

    /// Process one incoming packet. Guards 6-12.
    /// @param new_pct received packet, ownership is taken here.
    int ProcessIncoming(WorldPacket* new_pct);

    /// Called by ProcessIncoming() on CMSG_AUTH_SESSION.
    int HandleAuthSession(WorldPacket& recvPacket);

    /// Called by ProcessIncoming() on CMSG_PING. Guards 13-16.
    int HandlePing(WorldPacket& recvPacket);

    /// Called by MSG_VERIFY_CONNECTIVITY_RESPONSE
    int HandleSendAuthSession();

    void SendAuthResponseError(uint8 code);

    /// Flush whatever the output buffer holds. Caller holds m_OutBufferLock.
    void FlushOutBuffer();

    /// Time in which the last ping was received.
    /// steady_clock rather than a wall clock read: this is only ever used to
    /// measure the gap between two pings, and a clock stepped backwards by NTP
    /// would otherwise produce a negative gap and kick an honest client for
    /// flooding.
    std::chrono::steady_clock::time_point m_LastPingTime;

    /// Keep track of over-speed pings, to prevent ping flood.
    uint32 m_OverSpeedPings;

    /// Address of the remote peer
    std::string m_Address;

    /// Class used for managing encryption of the headers
    AuthCrypt m_Crypt;

    /// Mutex lock to protect m_Session
    std::mutex m_SessionLock;

    /// Session to which received packets are routed
    WorldSession* m_Session;

    /// Packet currently being received, and how much of its payload is already
    /// in it. The ACE version aliased a Message_Block onto the packet's storage
    /// so writes landed inside it directly; MessageBuffer cannot alias, so the
    /// payload is written into the packet and the progress tracked here.
    WorldPacket* m_RecvWPct;
    std::size_t m_RecvPctReceived;

    /// Fragment of the header received so far. Which one is in use depends on
    /// whether the crypt is initialised, exactly as the sizes do.
    MessageBuffer m_Header;
    MessageBuffer m_WorldHeader;

    /// Mutex for protecting output related data.
    std::mutex m_OutBufferLock;

    /// Coalescing buffer for outgoing packets, and the deadline at which it is
    /// flushed even if it has not filled.
    MessageBuffer m_OutBuffer;
    std::chrono::steady_clock::time_point m_LastFlushTime;

    uint32 m_Seed;
};

#endif  /* _WORLDSOCKET_H */

/// @}
