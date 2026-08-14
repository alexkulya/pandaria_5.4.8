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

#ifndef SF_ASYNCACCEPTOR_H
#define SF_ASYNCACCEPTOR_H

#include "Define.h"
#include "Log.h"

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/steady_timer.hpp>

#include <atomic>
#include <functional>
#include <string>

// Replacement for ACE_Acceptor. Owns the listening socket and hands every
// accepted connection to a callback, which is responsible for deciding where
// the new socket lives (see SocketMgr).
class AsyncAcceptor
{
public:
    typedef void(*AcceptCallback)(boost::asio::ip::tcp::socket&& newSocket, uint32 threadIndex);

    AsyncAcceptor(boost::asio::io_context& ioContext, std::string const& bindIp, uint16 port) :
        _acceptor(ioContext), _endpoint(boost::asio::ip::make_address(bindIp), port),
        _socket(ioContext), _closed(false), _retryTimer(ioContext)
    {
    }

    // Separated from the constructor so a bind failure is reported to the
    // caller as a bool rather than an exception escaping daemon startup.
    bool Bind()
    {
        boost::system::error_code errorCode;

        _acceptor.open(_endpoint.protocol(), errorCode);
        if (errorCode)
        {
            TC_LOG_ERROR("network", "Failed to open acceptor: %s", errorCode.message().c_str());
            return false;
        }

        _acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true), errorCode);
        if (errorCode)
        {
            TC_LOG_ERROR("network", "Failed to set reuse_address: %s", errorCode.message().c_str());
            return false;
        }

        _acceptor.bind(_endpoint, errorCode);
        if (errorCode)
        {
            TC_LOG_ERROR("network", "Could not bind to %s:%u: %s", _endpoint.address().to_string().c_str(),
                _endpoint.port(), errorCode.message().c_str());
            return false;
        }

        _acceptor.listen(boost::asio::socket_base::max_listen_connections, errorCode);
        if (errorCode)
        {
            TC_LOG_ERROR("network", "Failed to listen on %s:%u: %s", _endpoint.address().to_string().c_str(),
                _endpoint.port(), errorCode.message().c_str());
            return false;
        }

        return true;
    }

    void AsyncAcceptWithCallback(AcceptCallback acceptCallback, uint32 threadIndex)
    {
        _acceptor.async_accept(_socket, [this, acceptCallback, threadIndex](boost::system::error_code error)
        {
            if (!error)
            {
                try
                {
                    // The socket is moved out before the next accept is armed,
                    // so _socket is always free when async_accept reuses it.
                    acceptCallback(std::move(_socket), threadIndex);
                }
                catch (boost::system::system_error const& err)
                {
                    TC_LOG_INFO("network", "Failed to retrieve client's remote address %s", err.what());
                }
            }
            else if (error == boost::asio::error::operation_aborted)
                return;                                     // Close() cancelled us; do not re-arm
            else if (IsDescriptorExhaustion(error))
            {
                // The ACE acceptor suspended incoming connections for ten
                // seconds when the process ran out of file descriptors rather
                // than spinning on a failing accept(). Preserve that: without
                // it an exhausted fd table becomes a busy loop that floods the
                // log. Re-arming happens from the timer, not from here.
                TC_LOG_ERROR("network", "Out of file descriptors, suspending incoming connections for 10 seconds");

                _retryTimer.expires_after(std::chrono::seconds(10));
                _retryTimer.async_wait([this, acceptCallback, threadIndex](boost::system::error_code const& timerError)
                {
                    if (!timerError && !_closed)
                    {
                        TC_LOG_INFO("network", "Resuming acceptor");
                        AsyncAcceptWithCallback(acceptCallback, threadIndex);
                    }
                });

                return;
            }
            else
                TC_LOG_ERROR("network", "Failed to accept connection: %s", error.message().c_str());

            if (!_closed)
                AsyncAcceptWithCallback(acceptCallback, threadIndex);
        });
    }

    // Variant for a single listener that needs a stateful callback (RA), where
    // the fn-pointer form above would not bind to a member function.
    void AsyncAcceptSocket(std::function<void(boost::asio::ip::tcp::socket&&)> callback)
    {
        _acceptor.async_accept(_socket, [this, callback](boost::system::error_code error)
        {
            if (!error)
            {
                try
                {
                    callback(std::move(_socket));
                }
                catch (boost::system::system_error const& err)
                {
                    TC_LOG_INFO("network", "Failed to retrieve client's remote address %s", err.what());
                }
            }
            else if (error == boost::asio::error::operation_aborted)
                return;
            else
                TC_LOG_ERROR("network", "Failed to accept connection: %s", error.message().c_str());

            if (!_closed)
                AsyncAcceptSocket(callback);
        });
    }

    void Close()
    {
        if (_closed.exchange(true))
            return;

        // cancel() takes no error_code: the overload that did was removed after
        // Boost 1.74, and the no-argument form compiles on every version we
        // build against.
        _retryTimer.cancel();

        boost::system::error_code err;
        _acceptor.close(err);
    }

private:
    static bool IsDescriptorExhaustion(boost::system::error_code const& error)
    {
        return error == boost::system::errc::too_many_files_open ||
               error == boost::system::errc::too_many_files_open_in_system;
    }

    boost::asio::ip::tcp::acceptor _acceptor;
    boost::asio::ip::tcp::endpoint _endpoint;
    boost::asio::ip::tcp::socket _socket;
    std::atomic<bool> _closed;
    boost::asio::steady_timer _retryTimer;
};

#endif // SF_ASYNCACCEPTOR_H
