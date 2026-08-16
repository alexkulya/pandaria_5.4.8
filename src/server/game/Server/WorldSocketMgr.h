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

/** \addtogroup u2w
 * @{
 * \file WorldSocketMgr.h
 */

#ifndef __WORLDSOCKETMGR_H
#define __WORLDSOCKETMGR_H

#include "SocketMgr.h"
#include "WorldSocket.h"

/// Manages all sockets connected to peers and network threads.
///
/// Replaces the ACE ReactorRunnable pool. The accept loop, the out-of-
/// descriptors backoff and the per-thread socket lists all live in
/// AsyncAcceptor, SocketMgr and NetworkThread now, so what is left here is the
/// world-specific configuration: send buffer sizes and TCP_NODELAY.
class WorldSocketMgr : public SocketMgr<WorldSocket>
{
    typedef SocketMgr<WorldSocket> BaseSocketMgr;

public:
    static WorldSocketMgr& Instance()
    {
        static WorldSocketMgr instance;
        return instance;
    }

    bool StartNetwork(boost::asio::io_context& ioContext, std::string const& bindIp, uint16 port, int threadCount) override;

    void OnSocketOpen(boost::asio::ip::tcp::socket&& sock, uint32 threadIndex) override;

    /// Kernel send buffer size, in bytes. -1 leaves the system default alone.
    int GetSocketSendBufferSize() const { return m_SockOutKBuff; }

    /// Userspace coalescing buffer size for each socket.
    int GetSocketOutUBuffSize() const { return m_SockOutUBuff; }

    bool UseNoDelay() const { return m_UseNoDelay; }

protected:
    WorldSocketMgr();

    NetworkThread<WorldSocket>* CreateThreads() const override;

private:
    static void OnSocketAccept(boost::asio::ip::tcp::socket&& sock, uint32 threadIndex);

    int m_SockOutKBuff;
    int m_SockOutUBuff;
    bool m_UseNoDelay;
};

#define sWorldSocketMgr (&WorldSocketMgr::Instance())

#endif
/// @}
