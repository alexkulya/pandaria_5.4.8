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
 * \file WorldSocketMgr.cpp
 */

#include "WorldSocketMgr.h"

#include <boost/system/error_code.hpp>

#include "Common.h"
#include "Config.h"
#include "Log.h"
#include "NetworkThread.h"
#include "WorldSocket.h"

WorldSocketMgr::WorldSocketMgr() : BaseSocketMgr(),
    m_SockOutKBuff(-1), m_SockOutUBuff(65536), m_UseNoDelay(true)
{
}

NetworkThread<WorldSocket>* WorldSocketMgr::CreateThreads() const
{
    return new NetworkThread<WorldSocket>[GetNetworkThreadCount()];
}

void WorldSocketMgr::OnSocketAccept(boost::asio::ip::tcp::socket&& sock, uint32 threadIndex)
{
    Instance().OnSocketOpen(std::move(sock), threadIndex);
}

bool WorldSocketMgr::StartNetwork(boost::asio::io_context& ioContext, std::string const& bindIp, uint16 port, int threadCount)
{
    m_UseNoDelay = sConfigMgr->GetBoolDefault("Network.TcpNodelay", true);

    int const max_connections = 1024;
    TC_LOG_DEBUG("misc", "Max allowed socket connections %d", max_connections);

    // -1 means use default
    m_SockOutKBuff = sConfigMgr->GetIntDefault("Network.OutKBuff", -1);

    m_SockOutUBuff = sConfigMgr->GetIntDefault("Network.OutUBuff", 65536);

    if (m_SockOutUBuff <= 0)
    {
        TC_LOG_ERROR("misc", "Network.OutUBuff is wrong in your config file");
        return false;
    }

    if (!BaseSocketMgr::StartNetwork(ioContext, bindIp, port, threadCount))
        return false;

    _acceptor->AsyncAcceptWithCallback(&OnSocketAccept, 0);

    TC_LOG_INFO("misc", "Max allowed socket connections %d", max_connections);
    return true;
}

void WorldSocketMgr::OnSocketOpen(boost::asio::ip::tcp::socket&& sock, uint32 threadIndex)
{
    // The ACE version applied these in WorldSocket::open through
    // peer().set_option; with Asio the socket is still bare here, so they are
    // applied before it is handed to a network thread.
    if (m_SockOutKBuff >= 0)
    {
        boost::system::error_code err;
        sock.set_option(boost::asio::socket_base::send_buffer_size(m_SockOutKBuff), err);
        if (err && err != boost::system::errc::not_supported)
        {
            TC_LOG_ERROR("misc", "WorldSocketMgr::OnSocketOpen set_option SO_SNDBUF: %s", err.message().c_str());
            return;
        }
    }

    if (m_UseNoDelay)
    {
        boost::system::error_code err;
        sock.set_option(boost::asio::ip::tcp::no_delay(true), err);
        if (err)
        {
            TC_LOG_ERROR("misc", "WorldSocketMgr::OnSocketOpen: set_option TCP_NODELAY: %s", err.message().c_str());
            return;
        }
    }

    BaseSocketMgr::OnSocketOpen(std::move(sock), threadIndex);
}

/// @}
