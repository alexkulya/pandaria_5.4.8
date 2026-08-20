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

#include <algorithm>
#include <chrono>
#include <cstring>
#include <memory>
#include <thread>


#include "WorldSocket.h"
#include "Common.h"
#include "Errors.h"
#include "Player.h"
#include "Util.h"
#include "World.h"
#include "WorldPacket.h"
#include "SharedDefines.h"
#include "ByteBuffer.h"
#include "Opcodes.h"
#include "DatabaseEnv.h"
#include "BigNumber.h"
#include "SHA1.h"
#include "WorldSession.h"
#include "WorldSocketMgr.h"
#include "Log.h"
#include "PacketLog.h"
#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "Chat.h"

#if defined(__GNUC__)
#pragma pack(1)
#else
#pragma pack(push, 1)
#endif

struct ServerPktHeader
{
    ServerPktHeader(uint32 size, uint32 cmd, AuthCrypt* _authCrypt) : size(size)
    {
        if (_authCrypt->IsInitialized())
        {
            uint32 data = (size << 13) | (cmd & MAX_OPCODE);
            memcpy(&header[0], &data, 4);
            _authCrypt->EncryptSend((uint8*)&header[0], getHeaderLength());
        }
        else
        {
            // Dynamic header size is not needed anymore, we are using not encrypted part for only the first few packets
            memcpy(&header[0], &size, 2);
            memcpy(&header[2], &cmd, 2);
        }
    }

    uint8 getHeaderLength()
    {
        return 4;
    }

    const uint32 size;
    uint8 header[4];
};

struct AuthClientPktHeader
{
    uint16 size;
    uint32 cmd;
};

struct WorldClientPktHeader
{
    uint16 size;
    uint16 cmd;
};

#if defined(__GNUC__)
#pragma pack()
#else
#pragma pack(pop)
#endif

WorldSocket::WorldSocket(boost::asio::ip::tcp::socket&& socket) : Base(std::move(socket)),
m_LastPingTime(), m_OverSpeedPings(0), m_Session(nullptr),
m_RecvWPct(nullptr), m_RecvPctReceived(0),
m_Header(sizeof(AuthClientPktHeader)), m_WorldHeader(sizeof(WorldClientPktHeader)),
m_OutBuffer(), m_LastFlushTime(std::chrono::steady_clock::now()),
m_Seed(static_cast<uint32>(rand32()))
{
    m_Address = GetRemoteIpAddress().to_string();

    // 64 KB, as the ACE version had. The core does a great many small writes
    // and coalescing them is what keeps that cheap.
    m_OutBuffer.Resize(65536);
}

WorldSocket::~WorldSocket()
{
    delete m_RecvWPct;
}

bool WorldSocket::IsClosed() const
{
    return !IsOpen();
}

std::string const& WorldSocket::GetRemoteAddress() const
{
    return m_Address;
}

void WorldSocket::Start()
{
    // not an opcode. this packet sends raw string WORLD OF WARCRAFT CONNECTION - SERVER TO CLIENT"
    // because of our implementation, bytes "WO" become the opcode
    WorldPacket packet(MSG_VERIFY_CONNECTIVITY);
    packet << std::string("RLD OF WARCRAFT CONNECTION - SERVER TO CLIENT");

    if (SendPacket(packet) == -1)
    {
        CloseSocket();
        return;
    }

    AsyncRead();
}

void WorldSocket::OnClose()
{
    std::lock_guard<std::mutex> guard(m_SessionLock);
    m_Session = nullptr;
}

// Called once per network thread tick.
//
// Guard 18: the output buffer is flushed on a 10 ms ceiling rather than once
// per packet. The ACE version got the same effect by not arming the reactor for
// output until Update() ran; here the packets accumulate in m_OutBuffer and go
// out in one write.
bool WorldSocket::Update()
{
    if (!IsOpen())
        return Base::Update();

    {
        std::unique_lock<std::mutex> guard(m_OutBufferLock);

        if (m_OutBuffer.GetActiveSize() > 0)
        {
            std::chrono::steady_clock::time_point const now = std::chrono::steady_clock::now();
            if (now - m_LastFlushTime >= std::chrono::milliseconds(10))
            {
                FlushOutBuffer();
                m_LastFlushTime = now;
            }
        }
    }

    return Base::Update();
}

// Caller holds m_OutBufferLock. Hands the accumulated bytes to Socket<T>, which
// owns the async write and enforces the 8 MB queue cap (guard 17).
void WorldSocket::FlushOutBuffer()
{
    if (m_OutBuffer.GetActiveSize() == 0)
        return;

    MessageBuffer outgoing(m_OutBuffer.GetActiveSize());
    outgoing.Write(m_OutBuffer.GetReadPointer(), m_OutBuffer.GetActiveSize());
    m_OutBuffer.Reset();

    QueuePacket(std::move(outgoing));
}

int WorldSocket::SendPacket(WorldPacket const& pct)
{
    if (!IsOpen())
        return -1;

    // Dump outgoing packet
    if (sPacketLog->CanLogPacket())
        sPacketLog->LogPacket(pct, SERVER_TO_CLIENT);

    WorldPacket const* pkt = &pct;

    uint16 opcodeNumber = serverOpcodeTable[pkt->GetOpcode()]->OpcodeNumber;

    if (m_Session)
        TC_LOG_TRACE("network.opcode", "S->C: %u %s", m_Session->GetAccountId(), GetOpcodeNameForLogging(pkt->GetOpcode(), true).c_str());

    sScriptMgr->OnPacketSend(this, *pkt);

    // Guard 19: the header sizes differently depending on the crypt state.
    ServerPktHeader header(!m_Crypt.IsInitialized() ? pkt->size() + 2 : pct.size(), opcodeNumber, &m_Crypt);

    std::size_t const needed = header.getHeaderLength() + pkt->size();

    std::unique_lock<std::mutex> guard(m_OutBufferLock);

    // A packet that will not fit in what is left of the buffer forces the
    // buffer out first; one larger than the buffer itself goes on its own.
    if (needed > m_OutBuffer.GetRemainingSpace())
        FlushOutBuffer();

    if (needed > m_OutBuffer.GetBufferSize())
    {
        MessageBuffer single(needed);
        single.Write(header.header, header.getHeaderLength());
        if (!pkt->empty())
            single.Write(pkt->contents(), pkt->size());

        QueuePacket(std::move(single));
        return 0;
    }

    m_OutBuffer.Write(header.header, header.getHeaderLength());
    if (!pkt->empty())
        m_OutBuffer.Write(pkt->contents(), pkt->size());

    return 0;
}

// Consumes everything the last read delivered, which may be part of a header,
// several whole packets, or anything in between. Returning false closes the
// connection, which is how the guards below reject bad input.
bool WorldSocket::ReadHandler()
{
    if (!IsOpen())
        return false;

    MessageBuffer& packet = GetReadBuffer();

    while (packet.GetActiveSize() > 0)
    {
        MessageBuffer& header = m_Crypt.IsInitialized() ? m_WorldHeader : m_Header;
        std::size_t const headerSize = m_Crypt.IsInitialized()
            ? sizeof(WorldClientPktHeader) : sizeof(AuthClientPktHeader);

        if (header.GetActiveSize() < headerSize)
        {
            std::size_t const toHeader = std::min<std::size_t>(packet.GetActiveSize(),
                headerSize - header.GetActiveSize());
            header.Write(packet.GetReadPointer(), toHeader);
            packet.ReadCompleted(toHeader);

            if (header.GetActiveSize() < headerSize)
                break;  // partial header; the rest arrives on a later read

            if (!ReadHeaderHandler())
                return false;
        }

        // Its possible on some error situations that this happens
        // for example on closing when epoll receives more chunked data and stuff
        if (!m_RecvWPct)
        {
            TC_LOG_ERROR("network", "Forcing close on input m_RecvWPct = NULL");
            return false;
        }

        std::size_t const payloadSize = m_RecvWPct->size();

        if (m_RecvPctReceived < payloadSize)
        {
            std::size_t const toData = std::min<std::size_t>(packet.GetActiveSize(),
                payloadSize - m_RecvPctReceived);

            if (toData > 0)
            {
                std::memcpy(m_RecvWPct->contents() + m_RecvPctReceived, packet.GetReadPointer(), toData);
                packet.ReadCompleted(toData);
                m_RecvPctReceived += toData;
            }

            if (m_RecvPctReceived < payloadSize)
                break;  // partial payload; wait for the rest
        }

        if (!ReadDataHandler())
            return false;
    }

    AsyncRead();
    return true;
}

// Guards 1-5: the header is decrypted whole, the size is bounded, the opcode
// and size are split out of the packed value, and the high byte is dropped
// before the opcode is looked up.
bool WorldSocket::ReadHeaderHandler()
{
    ASSERT(m_RecvWPct == NULL);

    if (m_Crypt.IsInitialized())
    {
        ASSERT(m_WorldHeader.GetActiveSize() == sizeof(WorldClientPktHeader));
        uint8* uintHeader = m_WorldHeader.GetReadPointer();
        m_Crypt.DecryptRecv(uintHeader, sizeof(WorldClientPktHeader));
        WorldClientPktHeader& header = *(WorldClientPktHeader*)uintHeader;

        uint32 value = *(uint32*)uintHeader;
        header.cmd = value & 0x1FFF;
        header.size = ((value & ~(uint32)0x1FFF) >> 13);

        // Guard 1: encrypted payload ceiling.
        if (header.size > 10236)
        {
            TC_LOG_ERROR("network", "WorldSocket::ReadHeaderHandler(): client %s sent malformed packet (size: %u)",
                GetRemoteAddress().c_str(), header.size);
            return false;
        }

        // Guard 5: high byte dropped before the opcode lookup.
        uint16 opcodeNumber = PacketFilter::DropHighBytes(header.cmd);
        m_RecvWPct = new WorldPacket(clientOpcodeTable.GetOpcodeByNumber(opcodeNumber), header.size);
        m_RecvWPct->SetReceivedOpcode(opcodeNumber);

        if (header.size > 0)
            m_RecvWPct->resize(header.size);
    }
    else
    {
        ASSERT(m_Header.GetActiveSize() == sizeof(AuthClientPktHeader));
        uint8* uintHeader = m_Header.GetReadPointer();
        AuthClientPktHeader& header = *((AuthClientPktHeader*)uintHeader);

        // Guard 2: unencrypted size window, checked before the -4 adjustment.
        if ((header.size < 4) || (header.size > 10240))
        {
            TC_LOG_ERROR("network", "WorldSocket::ReadHeaderHandler(): client %s sent malformed packet (size: %u)",
                GetRemoteAddress().c_str(), header.size);
            return false;
        }

        header.size -= 4;

        uint16 opcodeNumber = PacketFilter::DropHighBytes(header.cmd);
        m_RecvWPct = new WorldPacket(clientOpcodeTable.GetOpcodeByNumber(opcodeNumber), header.size);
        m_RecvWPct->SetReceivedOpcode(opcodeNumber);

        if (header.size > 0)
            m_RecvWPct->resize(header.size);
    }

    m_RecvPctReceived = 0;
    return true;
}

// A complete packet is in hand: hand it to ProcessIncoming and reset the
// fragment state for the next one.
bool WorldSocket::ReadDataHandler()
{
    ASSERT(m_RecvWPct != NULL);

    int const ret = ProcessIncoming(m_RecvWPct);

    m_RecvWPct = nullptr;
    m_RecvPctReceived = 0;

    if (m_Crypt.IsInitialized())
        m_WorldHeader.Reset();
    else
        m_Header.Reset();

    return ret != -1;
}

int WorldSocket::ProcessIncoming(WorldPacket* new_pct)
{
    ASSERT(new_pct);

    // manage memory ;)
    // release() means the same in both: give up ownership without deleting,
    // which is what the hand-off to QueuePacket below relies on.
    std::unique_ptr<WorldPacket> aptr(new_pct);

    Opcodes opcode = new_pct->GetOpcode();

    if (!IsOpen())
        return -1;

    // Dump received packet.
    if (sPacketLog->CanLogPacket())
        sPacketLog->LogPacket(*new_pct, CLIENT_TO_SERVER);

    std::string opcodeName = GetOpcodeNameForLogging(opcode, false);
    if (m_Session)
        TC_LOG_TRACE("network.opcode", "C->S: %u %s", m_Session->GetAccountId(), GetOpcodeNameForLogging(opcode,false).c_str());

    try
    {
        switch (opcode)
        {
            case CMSG_PING:
                return HandlePing(*new_pct);
            case CMSG_AUTH_SESSION:
                if (m_Session)
                {
                    TC_LOG_ERROR("network", "WorldSocket::ProcessIncoming: received duplicate CMSG_AUTH_SESSION from %u", m_Session->GetAccountId());
                    return -1;
                }

                sScriptMgr->OnPacketReceive(this, WorldPacket(*new_pct));
                return HandleAuthSession(*new_pct);
            case CMSG_KEEP_ALIVE:
                sScriptMgr->OnPacketReceive(this, WorldPacket(*new_pct));
                return 0;
            case CMSG_LOG_DISCONNECT:
                new_pct->rfinish(); // contains uint32 disconnectReason;
                sScriptMgr->OnPacketReceive(this, WorldPacket(*new_pct));
                return 0;
            // not an opcode, client sends string "WORLD OF WARCRAFT CONNECTION - CLIENT TO SERVER" without opcode
            // first 4 bytes become the opcode (2 dropped)
            case MSG_VERIFY_CONNECTIVITY:
            {
                sScriptMgr->OnPacketReceive(this, WorldPacket(*new_pct));
                std::string str;
                *new_pct >> str;
                if (str != "D OF WARCRAFT CONNECTION - CLIENT TO SERVER")
                    return -1;
                return HandleSendAuthSession();
            }
            /*case CMSG_ENABLE_NAGLE:
            {
                TC_LOG_DEBUG("network", "%s", GetOpcodeNameForLogging(opcode,false).c_str());
                sScriptMgr->OnPacketReceive(this, WorldPacket(*new_pct));
                return m_Session ? m_Session->HandleEnableNagleAlgorithm() : -1;
            }*/
            default:
            {
                std::unique_lock<std::mutex> Guard(m_SessionLock);
                if (!m_Session)
                {
                    TC_LOG_ERROR("network.opcode", "ProcessIncoming: Client not authed opcode = %u", GetRemoteAddress().c_str(),uint32(opcode));
                    return -1;
                    CloseSocket();
                }

                // prevent invalid memory access/crash with custom opcodes
                if (opcode >= NUM_OPCODES)
                    return 0;

                OpcodeHandler const* handler = clientOpcodeTable[opcode];
                if (!handler || handler->Status == STATUS_UNHANDLED)
                {
                    TC_LOG_ERROR("network.opcode", "No defined handler for opcode %s sent by %u", GetRemoteAddress().c_str() ,GetOpcodeNameForLogging(new_pct->GetOpcode(), false, new_pct->GetReceivedOpcode()).c_str(), m_Session->GetAccountId());
                    if (m_Session->GetPlayer() && !handler && sWorld->getBoolConfig(CONFIG_DEBUG_OPCODES))
                        ChatHandler(m_Session->GetPlayer()).PSendSysMessage("Ваш клиент отправил некий пакет %s. Если вы случайно обнаружили гарантированный способ повторения данной ошибки, сообщите об этом администрации сервера.", GetOpcodeNameForLogging(new_pct->GetOpcode(), false, new_pct->GetReceivedOpcode()).c_str());
                    return 0;
                }

                // Our Idle timer will reset on any non PING opcodes.
                // Catches people idling on the login screen and any lingering ingame connections.
                m_Session->ResetTimeOutTime();

                // OK, give the packet to WorldSession
                aptr.release();
                // WARNING here we call it with locks held.
                // Its possible to cause deadlock if QueuePacket calls back
                m_Session->QueuePacket(new_pct);
                return 0;
            }
        }
    }
    catch (ByteBufferException &)
    {
        TC_LOG_ERROR("network", "WorldSocket::ProcessIncoming ByteBufferException occured while parsing an instant handled packet %s from client %s, accountid=%i. Disconnected client.",
                       GetOpcodeNameForLogging(opcode,false).c_str(), GetRemoteAddress().c_str(), m_Session ? int32(m_Session->GetAccountId()) : -1);
        new_pct->hexlike();
        return -1;
    }
}

int WorldSocket::HandleSendAuthSession()
{
    WorldPacket packet(SMSG_AUTH_CHALLENGE, 37);
    packet << uint16(0); // header?

    BigNumber _encryptSeed;
    _encryptSeed.SetRand(16 * 8);
    packet.append(_encryptSeed.AsByteArray(16), 16); // new encryption seeds

    BigNumber _decryptSeed;
    _decryptSeed.SetRand(16 * 8);
    packet.append(_decryptSeed.AsByteArray(16), 16); // new decryption seeds

    packet << uint8(1);
    packet << uint32(m_Seed);

    return SendPacket(packet);

}

int WorldSocket::HandleAuthSession(WorldPacket& recvPacket)
{
    uint8 digest[20];
    uint32 clientSeed;
    uint8 security;
    uint16 clientBuild;
    uint32 id;
    uint32 addonSize;
    LocaleConstant locale;
    std::string account;
    SHA1Hash sha;
    BigNumber k;
    WorldPacket addonsData;
    bool hasBoost = false;

    recvPacket.read_skip<uint32>();
    recvPacket.read_skip<uint32>();
    recvPacket >> digest[18];
    recvPacket >> digest[14];
    recvPacket >> digest[3];
    recvPacket >> digest[4];
    recvPacket >> digest[0];
    recvPacket.read_skip<uint32>();
    recvPacket >> digest[11];
    recvPacket >> clientSeed;
    recvPacket >> digest[19];
    recvPacket.read_skip<uint8>();
    recvPacket.read_skip<uint8>();
    recvPacket >> digest[2];
    recvPacket >> digest[9];
    recvPacket >> digest[12];
    recvPacket.read_skip<uint64>();
    recvPacket.read_skip<uint32>();
    recvPacket >> digest[16];
    recvPacket >> digest[5];
    recvPacket >> digest[6];
    recvPacket >> digest[8];
    recvPacket >> clientBuild;
    recvPacket >> digest[17];
    recvPacket >> digest[7];
    recvPacket >> digest[13];
    recvPacket >> digest[15];
    recvPacket >> digest[1];
    recvPacket >> digest[10];
    recvPacket >> addonSize;

    addonsData.resize(addonSize);
    recvPacket.read((uint8*)addonsData.contents(), addonSize);

    recvPacket.ReadBit();
    uint32 accountNameLength = recvPacket.ReadBits(11);

    account = recvPacket.ReadString(accountNameLength);

    if (sWorld->IsClosed())
    {
        SendAuthResponseError(AUTH_REJECT);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: World closed, denying client (%s).", GetRemoteAddress().c_str());
        return -1;
    }

    // Get the account information from the realmd database
    //         0           1        2       3          4         5       6          7   8   9         10                    11
    // SELECT id, sessionkey, last_ip, locked, expansion, mutetime, locale, recruiter, os, flags, online_mute_timer, active_mute_id FROM account WHERE username = ?
    size_t hashPos = account.find_last_of('#');
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_INFO_BY_NAME);
    stmt->setString(0, account);

    PreparedQueryResult result = LoginDatabase.Query(stmt);

    // Stop if the account is not found
    if (!result)
    {
        SendAuthResponseError(AUTH_UNKNOWN_ACCOUNT);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Sent Auth Response (unknown account).");
        return -1;
    }

    Field* fields = result->Fetch();

    uint8 expansion = fields[4].GetUInt8();
    uint32 world_expansion = sWorld->getIntConfig(CONFIG_EXPANSION);
    if (expansion > world_expansion)
        expansion = world_expansion;

    uint32 flags = fields[9].GetUInt32();

    ///- Re-check ip locking (same check as in realmd).
    if (fields[3].GetUInt8() == 1) // if ip is locked
    {
        if (strcmp (fields[2].GetCString(), GetRemoteAddress().c_str()))
        {
            SendAuthResponseError(AUTH_FAILED);
            TC_LOG_DEBUG("network", "WorldSocket::HandleAuthSession: Sent Auth Response (Account IP differs).");
            return -1;
        }
    }

    id = fields[0].GetUInt32();

    k.SetHexStr(fields[1].GetCString());

    time_t mutetime = time_t(fields[5].GetUInt64());

    locale = LocaleConstant (fields[6].GetUInt8());
    if (locale >= TOTAL_LOCALES)
        locale = LOCALE_enUS;

    uint32 recruiter = fields[7].GetUInt32();
    std::string os = fields[8].GetString();

    // Must be done before WorldSession is created
    if (sWorld->getBoolConfig(CONFIG_WARDEN_ENABLED) && os != "Win" && os != "Wn64" && os != "OSX")
    {
        SendAuthResponseError(AUTH_REJECT);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Client %s attempted to log in using invalid client OS (%s).", GetRemoteAddress().c_str(), os.c_str());
        return -1;
    }

    // get boost info
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_BOOST);
    stmt->setUInt32(0, id);
    stmt->setUInt32(1, realmID);

    if (LoginDatabase.Query(stmt))
        hasBoost = true;

    // Get mute info
    std::string mutedBy = "";
    std::string muteReason = "";
    bool mutedInPublicChannelsOnly = false;
    uint32 onlineMuteTimer = 0;

    if (auto muteRes = LoginDatabase.PQuery("SELECT am.muted_by, am.mute_reason, am.public_channels_only, m.mute_timer FROM mute_active AS m, account_muted AS am WHERE m.realmid = '%u' AND m.account = '%u' AND m.mute_id = am.id AND m.realmid = am.realmid", realmID, id))
    {
        fields = muteRes->Fetch();
        mutedBy = fields[0].GetString();
        muteReason = fields[1].GetString();
        mutedInPublicChannelsOnly = fields[2].GetBool();
        onlineMuteTimer = fields[3].GetUInt32();
    }

    // Checks gmlevel per Realm
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_GET_GMLEVEL_BY_REALMID);

    stmt->setUInt32(0, id);
    stmt->setInt32(1, int32(realmID));

    result = LoginDatabase.Query(stmt);

    if (!result)
        security = 0;
    else
    {
        fields = result->Fetch();
        security = fields[0].GetUInt8();
    }

    bool betaTest = LoginDatabase.PQuery("SELECT 1 FROM project_betatesters WHERE account_id = %u", id) != nullptr;

    if (security < SEC_GAMEMASTER && sWorld->getBoolConfig(CONFIG_BETA_TEST_MODE))
    {
        if (!betaTest)
        {
            SendAuthResponseError(AUTH_REJECT);
            return -1;
        }
    }

    // Re-check account ban (same check as in realmd)
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_BANS);

    stmt->setUInt32(0, id);
    stmt->setString(1, GetRemoteAddress());

    PreparedQueryResult banresult = LoginDatabase.Query(stmt);

    if (banresult) // if account banned
    {
        SendAuthResponseError(AUTH_BANNED);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Sent Auth Response (Account banned).");
        return -1;
    }

    // Check locked state for server
    AccountTypes allowedAccountType = sWorld->GetPlayerSecurityLimit();
    TC_LOG_DEBUG("network", "Allowed Level: %u Player Level %u", allowedAccountType, AccountTypes(security));
    if (allowedAccountType > SEC_PLAYER && AccountTypes(security) < allowedAccountType)
    {
        SendAuthResponseError(AUTH_UNAVAILABLE);
        TC_LOG_INFO("network", "WorldSocket::HandleAuthSession: User tries to login but his security level is not enough");
        return -1;
    }

    // Check that Key and account name are the same on client and server
    uint32 t = 0;
    uint32 seed = m_Seed;

    sha.UpdateData(account);
    sha.UpdateData((uint8*)&t, 4);
    sha.UpdateData((uint8*)&clientSeed, 4);
    sha.UpdateData((uint8*)&seed, 4);
    sha.UpdateBigNumbers(&k, NULL);
    sha.Finalize();

    std::string address = GetRemoteAddress();

    if (memcmp(sha.GetDigest(), digest, 20))
    {
        SendAuthResponseError(AUTH_FAILED);
        TC_LOG_ERROR("network", "WorldSocket::HandleAuthSession: Authentication failed for account: %u ('%s') address: %s", id, account.c_str(), address.c_str());
        return -1;
    }

    TC_LOG_DEBUG("network", "WorldSocket::HandleAuthSession: Client '%s' authenticated successfully from %s.",
        account.c_str(),
        address.c_str());

    // Check if this user is by any chance a recruiter
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_RECRUITER);

    stmt->setUInt32(0, id);

    result = LoginDatabase.Query(stmt);

    bool isRecruiter = false;
    if (result)
        isRecruiter = true;

    // Update the last_ip in the database

    stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_LAST_IP);

    stmt->setString(0, address);
    stmt->setString(1, account);

    LoginDatabase.Execute(stmt);

    // Before session construction.
    sWorld->LoadprojectMemberInfoIfNeeded(id);

    if (sWorld->getBoolConfig(CONFIG_BOOST_PROMOTION) && !hasBoost)
    {
        uint32 memberId = sWorld->GetprojectMemberID(id);
        auto promoted = LoginDatabase.PQuery("SELECT member_id FROM boost_promotion_executed WHERE member_id = '%d'", memberId);

        projectMemberInfo* info = sWorld->GetprojectMemberInfo(memberId, false);
        bool verified = info && info->IsVerified;

        if (!promoted && verified)
            hasBoost = true;
    }

    // NOTE ATM the socket is single-threaded, have this in mind ...
    m_Session = new WorldSession(id, shared_from_this(), AccountTypes(security), expansion, mutetime, locale, recruiter, flags, isRecruiter, hasBoost);
    m_Session->SetMute({ onlineMuteTimer, mutedBy, muteReason, mutedInPublicChannelsOnly });

    m_Crypt.Init(&k);

    m_Session->LoadGlobalAccountData();
    m_Session->LoadTutorialsData();
    m_Session->ReadAddonsInfo(addonsData);

    // Initialize Warden system only if it is enabled by config
    if (sWorld->getBoolConfig(CONFIG_WARDEN_ENABLED))
        m_Session->InitWarden(&k, os);

    // Sleep this Network thread for
    uint32 sleepTime = sWorld->getIntConfig(CONFIG_SESSION_ADD_DELAY);
    // ACE_Time_Value(0, sleepTime) put the config in the microseconds field,
    // so SessionAddDelay's default of 10000 is 10 ms, not 10 seconds.
    std::this_thread::sleep_for(std::chrono::microseconds(sleepTime));

    sWorld->AddSession(m_Session);
    return 0;
}

int WorldSocket::HandlePing (WorldPacket& recvPacket)
{
    uint32 ping;
    uint32 latency;

    // Get the ping packet content
    recvPacket >> latency;
    recvPacket >> ping;

    if (m_LastPingTime == std::chrono::steady_clock::time_point())
        m_LastPingTime = std::chrono::steady_clock::now(); // for 1st ping
    else
    {
        std::chrono::steady_clock::time_point cur_time = std::chrono::steady_clock::now();
        std::chrono::steady_clock::duration diff_time = cur_time - m_LastPingTime;
        m_LastPingTime = cur_time;

        if (diff_time < std::chrono::seconds(27))
        {
            ++m_OverSpeedPings;

            uint32 max_count = sWorld->getIntConfig (CONFIG_MAX_OVERSPEED_PINGS);

            if (max_count && m_OverSpeedPings > max_count)
            {
                std::unique_lock<std::mutex> Guard(m_SessionLock);

                if (m_Session && m_Session->GetSecurity() == SEC_PLAYER)
                {
                    TC_LOG_ERROR("network", "WorldSocket::HandlePing: %u kicked for over-speed pings (address: %s)",
                        m_Session->GetAccountId(), GetRemoteAddress().c_str());

                    return -1;
                }
            }
        }
        else
            m_OverSpeedPings = 0;
    }

    // critical section
    {
        std::unique_lock<std::mutex> Guard(m_SessionLock);

        if (m_Session)
        {
            m_Session->SetLatency (latency);
            uint32 id = m_Session->GetAccountId();
            TaskMgr::Default()->ScheduleInvocation([=]
            {
                if (WorldSession* session = sWorld->FindSession(id))
                    session->HandlePingUpdate(latency);
            });
        }
        else
        {
            TC_LOG_ERROR("network", "WorldSocket::HandlePing: peer sent CMSG_PING, "
                            "but is not authenticated or got recently kicked, "
                            " address = %s",
                            GetRemoteAddress().c_str());
             return -1;
        }
    }

    WorldPacket packet(SMSG_PONG, 4);
    packet << ping;
    return SendPacket(packet);
}

void WorldSocket::SendAuthResponseError(uint8 code)
{
    WorldPacket packet(SMSG_AUTH_RESPONSE, 1);
    packet.WriteBit(0); // has account info
    packet.WriteBit(0); // has queue info
    packet.FlushBits();
    packet << uint8(code);
    SendPacket(packet);
}