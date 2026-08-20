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

#ifndef SF_REALMSOCKETMGR_H
#define SF_REALMSOCKETMGR_H

#include "RealmSocket.h"
#include "SocketMgr.h"

// Replaces RealmAcceptor. The out-of-descriptors backoff that lived in
// RealmAcceptor::handle_accept_error now sits in AsyncAcceptor, so it is shared
// by every listener rather than being specific to auth.
class RealmSocketMgr : public SocketMgr<RealmSocket>
{
    typedef SocketMgr<RealmSocket> BaseSocketMgr;

public:
    static RealmSocketMgr& Instance()
    {
        static RealmSocketMgr instance;
        return instance;
    }

    bool StartNetwork(boost::asio::io_context& ioContext, std::string const& bindIp, uint16 port, int threadCount) override
    {
        if (!BaseSocketMgr::StartNetwork(ioContext, bindIp, port, threadCount))
            return false;

        _acceptor->AsyncAcceptWithCallback(&OnSocketAccept, 0);
        return true;
    }

protected:
    RealmSocketMgr() : BaseSocketMgr() { }

    NetworkThread<RealmSocket>* CreateThreads() const override
    {
        return new NetworkThread<RealmSocket>[GetNetworkThreadCount()];
    }

private:
    // The index handed over by the acceptor is ignored on purpose: spreading by
    // current load keeps a login burst off a single thread.
    static void OnSocketAccept(boost::asio::ip::tcp::socket&& sock, uint32 /*threadIndex*/)
    {
        RealmSocketMgr& mgr = Instance();
        mgr.OnSocketOpen(std::move(sock), mgr.SelectThreadWithMinConnections());
    }
};

#define sRealmSocketMgr RealmSocketMgr::Instance()

#endif // SF_REALMSOCKETMGR_H
