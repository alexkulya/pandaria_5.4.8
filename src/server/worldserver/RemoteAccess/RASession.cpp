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

#include "RASession.h"
#include "AccountMgr.h"
#include "Chat.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "Log.h"
#include "World.h"

#include <boost/asio/buffer.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/write.hpp>

#include <chrono>
#include <istream>
#include <sstream>
#include <thread>

void RASession::Start()
{
    std::string ipAddress = GetRemoteIpAddress().to_string();
    TC_LOG_INFO("commands.ra", "Incoming connection from %s", ipAddress.c_str());

    Subnegotiate();

    Send("Authentication Required\r\n");

    Send("Username: ");
    std::string username = ReadString();
    if (username.empty())
        return;

    Send("Password: ");
    std::string password = ReadString();
    if (password.empty())
        return;

    TC_LOG_INFO("commands.ra", "Login attempt for user: %s", username.c_str());

    if (!CheckAccessLevel(username) || !CheckPassword(username, password))
    {
        Send("Authentication failed\r\n");
        boost::system::error_code error;
        _socket.close(error);
        return;
    }

    TC_LOG_INFO("commands.ra", "User login: %s", username.c_str());

    for (;;)
    {
        Send("TC> ");

        std::string command = ReadString();
        if (command.empty())
            break;                                          // connection dropped

        if (ProcessCommand(command))
            break;
    }

    TC_LOG_INFO("commands.ra", "Closing connection");
    boost::system::error_code error;
    _socket.close(error);
}

void RASession::Send(std::string const& line)
{
    boost::system::error_code error;
    boost::asio::write(_socket, boost::asio::buffer(line), error);
}

// Reads one line, dropping CR and stopping at LF, matching RASocket::recv_line.
// An empty return means the connection is gone, which is how every caller
// detects a dropped client.
std::string RASession::ReadString()
{
    boost::system::error_code error;
    std::size_t length = boost::asio::read_until(_socket, _readBuffer, '\n', error);
    if (error || !length)
    {
        boost::system::error_code closeError;
        _socket.close(closeError);
        return std::string();
    }

    std::string line;
    std::istream is(&_readBuffer);
    std::getline(is, line);

    // getline strips the LF; Windows telnet clients leave the CR behind.
    if (!line.empty() && line.back() == '\r')
        line.pop_back();

    return line;
}

// Telnet clients announce their options with an IAC block on connect, but not
// all of them do. The ACE version waited up to one second for it and carried on
// regardless; polling available() reproduces that without a deadline timer.
void RASession::Subnegotiate()
{
    for (int counter = 0; counter < 10 && !_socket.available(); ++counter)
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    if (!_socket.available())
        return;

    char buf[1024];
    boost::system::error_code error;
    std::size_t const readSize = _socket.read_some(boost::asio::buffer(buf), error);

    if (error)
        return;

    // Preserved from RASocket::subnegotiate: a negotiation block that fills the
    // buffer is rejected rather than parsed from truncated data.
    if (readSize >= sizeof(buf))
    {
        TC_LOG_DEBUG("commands.ra", "RASession::Subnegotiate: 1024 byte buffer was too small for the negotiation packet, size: " SZFMTD, readSize);
        return;
    }

    std::ostringstream tcpMessage;
    for (std::size_t i = 0; i < readSize; )
    {
        uint8 iac = uint8(buf[i]);
        if (iac != 0xFF)                                    // "Interpret As Command"
            break;

        if (i + 2 >= readSize)
            break;

        uint8 const command = uint8(buf[++i]);
        switch (command)
        {
            case 0xFB: tcpMessage << "WILL ";  break;
            case 0xFC: tcpMessage << "WON'T "; break;
            case 0xFD: tcpMessage << "DO ";    break;
            case 0xFE: tcpMessage << "DON'T "; break;
            default:
                return;                                     // not allowed
        }

        tcpMessage << uint32(uint8(buf[++i])) << ' ';
        ++i;
    }

    if (tcpMessage.tellp())
        TC_LOG_DEBUG("commands.ra", "Telnet subnegotiation: %s", tcpMessage.str().c_str());
}

bool RASession::CheckAccessLevel(std::string const& user)
{
    std::string safeUser = user;
    AccountMgr::normalizeString(safeUser);

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_ACCOUNT_ACCESS);
    stmt->setString(0, safeUser);
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("commands.ra", "User %s does not exist in database", user.c_str());
        return false;
    }

    Field* fields = result->Fetch();

    if (fields[1].GetUInt8() < uint8(sConfigMgr->GetIntDefault("RA.MinLevel", 3)))
    {
        TC_LOG_INFO("commands.ra", "User %s has no privilege to login", user.c_str());
        return false;
    }

    if (fields[2].GetInt32() != -1)
    {
        TC_LOG_INFO("commands.ra", "User %s has to be assigned on all realms (with RealmID = '-1')", user.c_str());
        return false;
    }

    return true;
}

bool RASession::CheckPassword(std::string const& user, std::string const& pass)
{
    std::string safeUser = user;
    AccountMgr::normalizeString(safeUser);

    std::string safePass = pass;
    AccountMgr::normalizeString(safePass);

    std::string hash = AccountMgr::CalculateShaPassHash(safeUser, safePass);

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_CHECK_PASSWORD_BY_NAME);
    stmt->setString(0, safeUser);
    stmt->setString(1, hash);

    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("commands.ra", "Wrong password for user: %s", user.c_str());
        return false;
    }

    return true;
}

bool RASession::ProcessCommand(std::string const& command)
{
    if (command.empty())
        return false;

    TC_LOG_INFO("commands.ra", "Received command: %s", command.c_str());

    if (command == "quit" || command == "exit" || command == "logout")
    {
        Send("Bye\r\n");
        return true;
    }

    // The promise lives on this stack frame and is fulfilled by the world
    // thread. Blocking here until then is what makes the raw pointer in
    // _commandExecuting safe, and what keeps CommandPrint's writes from racing
    // this thread. The ACE version needed a separate atomic flag to stop the
    // socket being destroyed underneath a still-running command; that whole
    // failure mode disappears because the session cannot be torn down while
    // this frame is alive.
    std::promise<void> commandFinished;
    _commandExecuting = &commandFinished;

    // Ownership passes to the world, which deletes the holder after running it.
    sWorld->QueueCliCommand(new CliCommandHolder(this, command.c_str(), &RASession::CommandPrint, &RASession::CommandFinished));

    commandFinished.get_future().wait();
    _commandExecuting = nullptr;

    return false;
}

// Called on the world thread while the RA thread is parked in ProcessCommand.
void RASession::CommandPrint(void* callbackArg, char const* text)
{
    if (!text || !*text)
        return;

    RASession* session = static_cast<RASession*>(callbackArg);
    session->Send(text);
}

// Also called on the world thread; releases ProcessCommand.
void RASession::CommandFinished(void* callbackArg, bool /*success*/)
{
    RASession* session = static_cast<RASession*>(callbackArg);
    if (session->_commandExecuting)
        session->_commandExecuting->set_value();
}
