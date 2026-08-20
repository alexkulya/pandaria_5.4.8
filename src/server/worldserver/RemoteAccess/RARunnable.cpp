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

/** \file
    \ingroup Trinityd
 */

#include "RARunnable.h"
#include "AsyncAcceptor.h"
#include "Common.h"
#include "Config.h"
#include "Log.h"
#include "RASession.h"
#include "World.h"

#include <chrono>
#include <thread>

RARunnable::RARunnable() { }

RARunnable::~RARunnable() { }

void RARunnable::run()
{
    if (!sConfigMgr->GetBoolDefault("Ra.Enable", false))
        return;

    uint16 const raPort = uint16(sConfigMgr->GetIntDefault("Ra.Port", 3443));
    std::string const stringIp = sConfigMgr->GetStringDefault("Ra.IP", "0.0.0.0");

    try
    {
        _acceptor.reset(new AsyncAcceptor(_ioContext, stringIp, raPort));
    }
    catch (boost::system::system_error const& err)
    {
        TC_LOG_ERROR("server.worldserver", "Trinity RA can not bind to port %u on %s: %s", raPort, stringIp.c_str(), err.what());
        return;
    }

    if (!_acceptor->Bind())
    {
        TC_LOG_ERROR("server.worldserver", "Trinity RA can not bind to port %u on %s", raPort, stringIp.c_str());
        return;
    }

    TC_LOG_INFO("server.worldserver", "Starting Trinity RA on port %u on %s", raPort, stringIp.c_str());

    _acceptor->AsyncAcceptSocket([this](boost::asio::ip::tcp::socket&& socket)
    {
        OnAccept(std::move(socket));
    });

    // Same 100ms cadence the ACE reactor loop used, so shutdown latency is
    // unchanged. run_for stops the context when the deadline passes, hence the
    // restart() before going round again.
    while (!World::IsStopped())
    {
        _ioContext.run_for(std::chrono::milliseconds(100));
        _ioContext.restart();
    }

    _acceptor->Close();

    TC_LOG_DEBUG("server.worldserver", "Trinity RA thread exiting");
}

void RARunnable::OnAccept(boost::asio::ip::tcp::socket&& socket)
{
    // One thread per connection, as ACE_Svc_Handler::activate() did. The
    // session blocks on reads and, while a command runs, on a future; giving it
    // its own thread is what keeps that model simple.
    std::thread([](boost::asio::ip::tcp::socket&& sock)
    {
        try
        {
            RASession session(std::move(sock));
            session.Start();
        }
        catch (std::exception const& ex)
        {
            // A client that vanishes mid-handshake makes remote_endpoint()
            // throw; that must not take the worldserver down with it.
            TC_LOG_DEBUG("commands.ra", "RA session ended with exception: %s", ex.what());
        }
    }, std::move(socket)).detach();
}
