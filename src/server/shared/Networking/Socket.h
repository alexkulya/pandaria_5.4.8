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
*/

#ifndef SF_SOCKET_H
#define SF_SOCKET_H

#include "Define.h"
#include "Log.h"
#include "MessageBuffer.h"

#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/write.hpp>

#include <atomic>
#include <memory>
#include <queue>
#include <type_traits>

#define READ_BLOCK_SIZE 4096

// Replacement for ACE_Svc_Handler. CRTP base for a connection: the derived
// class T supplies the protocol by overriding Start() and ReadHandler().
//
// THREADING CONTRACT: a socket is created on the acceptor's io_context and
// then moved onto exactly one NetworkThread's io_context. Every member below
// runs on that single thread, which is why none of this is locked. Calling
// into a socket from another thread (the world thread, a script, a command
// handler) is a data race -- post the work to the socket's io_context instead.
template<class T>
class Socket : public std::enable_shared_from_this<T>
{
public:
    explicit Socket(boost::asio::ip::tcp::socket&& socket) :
        _socket(std::move(socket)), _remoteAddress(_socket.remote_endpoint().address()),
        _remotePort(_socket.remote_endpoint().port()), _readBuffer(READ_BLOCK_SIZE),
        _closed(false), _closing(false), _isWritingAsync(false)
    {
    }

    virtual ~Socket()
    {
        _closed = true;
        boost::system::error_code error;
        _socket.close(error);
    }

    virtual void Start() = 0;

    // Called once per NetworkThread tick. Returning false drops the socket
    // from the thread's list, which releases the last shared_ptr to it.
    virtual bool Update()
    {
        if (_closed)
            return false;

        // A socket asked to close politely stays alive until its queued bytes
        // have gone out; that is what lets a disconnect reason reach the client.
        if (_closing && _writeQueue.empty() && !_isWritingAsync)
        {
            CloseSocket();
            return false;
        }

        return true;
    }

    boost::asio::ip::address GetRemoteIpAddress() const { return _remoteAddress; }

    uint16 GetRemotePort() const { return _remotePort; }

    void AsyncRead()
    {
        if (!IsOpen())
            return;

        _readBuffer.Normalize();
        _readBuffer.EnsureFreeSpace();

        _socket.async_read_some(
            boost::asio::buffer(_readBuffer.GetWritePointer(), _readBuffer.GetRemainingSpace()),
            [self = this->shared_from_this()](boost::system::error_code const& error, std::size_t transferredBytes)
            {
                self->ReadHandlerInternal(error, transferredBytes);
            });
    }

    void QueuePacket(MessageBuffer&& buffer)
    {
        _writeQueue.push(std::move(buffer));
        AsyncProcessQueue();
    }

    bool IsOpen() const { return !_closed && !_closing; }

    void CloseSocket()
    {
        if (_closed.exchange(true))
            return;

        boost::system::error_code shutdownError;
        _socket.shutdown(boost::asio::socket_base::shutdown_send, shutdownError);
        if (shutdownError)
            TC_LOG_DEBUG("network", "Socket::CloseSocket: %s errored when shutting down socket: %s",
                GetRemoteIpAddress().to_string().c_str(), shutdownError.message().c_str());

        OnClose();
    }

    // Stop accepting new writes but let the queue drain first.
    void DelayedCloseSocket() { _closing = true; }

    MessageBuffer& GetReadBuffer() { return _readBuffer; }

protected:
    virtual void OnClose() { }

    // Return false to close the connection: that is how a protocol rejects
    // malformed input. Overrides are responsible for calling AsyncRead() again
    // when they want more data.
    virtual bool ReadHandler() = 0;

    void SetNoDelay(bool enable)
    {
        boost::system::error_code err;
        _socket.set_option(boost::asio::ip::tcp::no_delay(enable), err);
        if (err)
            TC_LOG_DEBUG("network", "Socket::SetNoDelay: failed to set_option(no_delay) for %s: %s",
                GetRemoteIpAddress().to_string().c_str(), err.message().c_str());
    }

private:
    void ReadHandlerInternal(boost::system::error_code const& error, std::size_t transferredBytes)
    {
        if (error)
        {
            CloseSocket();
            return;
        }

        _readBuffer.WriteCompleted(transferredBytes);

        if (!ReadHandler())
            CloseSocket();
    }

    void AsyncProcessQueue()
    {
        if (_isWritingAsync || _writeQueue.empty() || _closed)
            return;

        _isWritingAsync = true;

        MessageBuffer& buffer = _writeQueue.front();

        boost::asio::async_write(_socket,
            boost::asio::buffer(buffer.GetReadPointer(), buffer.GetActiveSize()),
            [self = this->shared_from_this()](boost::system::error_code const& error, std::size_t transferredBytes)
            {
                self->WriteHandler(error, transferredBytes);
            });
    }

    void WriteHandler(boost::system::error_code const& error, std::size_t /*transferredBytes*/)
    {
        _isWritingAsync = false;

        if (error)
        {
            CloseSocket();
            return;
        }

        // async_write completes only once the whole buffer has gone out, so
        // the front entry is always fully consumed here.
        _writeQueue.pop();

        AsyncProcessQueue();
    }

    boost::asio::ip::tcp::socket _socket;
    boost::asio::ip::address _remoteAddress;
    uint16 _remotePort;

    MessageBuffer _readBuffer;
    std::queue<MessageBuffer> _writeQueue;

    std::atomic<bool> _closed;
    std::atomic<bool> _closing;
    bool _isWritingAsync;
};

#endif // SF_SOCKET_H
