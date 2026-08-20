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

#ifndef SF_RASESSION_H
#define SF_RASESSION_H

#include "Common.h"

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>

#include <future>
#include <string>

// Remote administration session, the Boost.Asio replacement for RASocket.
//
// Deliberately NOT a Socket<T>: the admin console is a request/response REPL,
// so it keeps the thread-per-connection model the ACE version used and does
// blocking reads. Turning it into an async state machine would be more code
// for no benefit -- there are never many RA connections.
//
// THREADING: Start() owns the session's thread and blocks inside it. While a
// command runs, that thread parks on a future and the *world* thread writes
// output through CommandPrint. The two never write concurrently precisely
// because the RA thread is parked; do not "optimise" that wait away.
class RASession
{
public:
    explicit RASession(boost::asio::ip::tcp::socket&& socket) :
        _socket(std::move(socket)), _commandExecuting(nullptr) { }

    void Start();

    boost::asio::ip::address GetRemoteIpAddress() const { return _socket.remote_endpoint().address(); }
    uint16 GetRemotePort() const { return _socket.remote_endpoint().port(); }

private:
    void Send(std::string const& line);
    std::string ReadString();
    void Subnegotiate();

    bool CheckAccessLevel(std::string const& user);
    bool CheckPassword(std::string const& user, std::string const& pass);

    // Returns true when the session should end.
    bool ProcessCommand(std::string const& command);

    static void CommandPrint(void* callbackArg, char const* text);
    static void CommandFinished(void* callbackArg, bool success);

    boost::asio::ip::tcp::socket _socket;
    boost::asio::streambuf _readBuffer;

    // Non-owning: points at a promise living on ProcessCommand's stack, which
    // outlives every use because ProcessCommand blocks until it is fulfilled.
    std::promise<void>* _commandExecuting;
};

#endif // SF_RASESSION_H
