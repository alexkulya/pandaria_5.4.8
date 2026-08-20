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

#ifndef SF_NETWORKTHREAD_H
#define SF_NETWORKTHREAD_H

#include "Define.h"
#include "Log.h"

#include <boost/asio/executor_work_guard.hpp>
#include <boost/asio/io_context.hpp>
#include <boost/asio/steady_timer.hpp>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

// Replacement for the ACE reactor thread. Each instance owns one io_context
// and one thread; every socket handed to it lives on that thread for its whole
// life, which is what makes Socket<T> lock-free.
template<class SocketType>
class NetworkThread
{
public:
    NetworkThread() : _connections(0), _stopped(false), _ioContext(1),
        _updateTimer(_ioContext) { }

    virtual ~NetworkThread()
    {
        Stop();
        if (_thread)
        {
            Wait();
            _thread.reset();
        }
    }

    void Stop()
    {
        _stopped = true;
        _ioContext.stop();
    }

    bool Start()
    {
        if (_thread)
            return false;

        _thread.reset(new std::thread(&NetworkThread::Run, this));
        return true;
    }

    void Wait()
    {
        if (_thread && _thread->joinable())
            _thread->join();
    }

    int32 GetConnectionCount() const { return _connections; }

    // Called from the acceptor's thread, not ours: this is the one hand-off
    // point in the design that crosses threads, hence the only lock.
    virtual void AddSocket(std::shared_ptr<SocketType> sock)
    {
        std::lock_guard<std::mutex> lock(_newSocketsLock);

        ++_connections;
        _newSockets.push_back(sock);
        SocketAdded(sock);
    }

    boost::asio::io_context& GetIoContext() { return _ioContext; }

protected:
    virtual void SocketAdded(std::shared_ptr<SocketType> /*sock*/) { }
    virtual void SocketRemoved(std::shared_ptr<SocketType> /*sock*/) { }

private:
    void AddNewSockets()
    {
        std::lock_guard<std::mutex> lock(_newSocketsLock);

        if (_newSockets.empty())
            return;

        for (std::shared_ptr<SocketType>& sock : _newSockets)
        {
            if (!sock->IsOpen())
            {
                SocketRemoved(sock);
                --_connections;
            }
            else
                _sockets.push_back(sock);
        }

        _newSockets.clear();
    }

    void Run()
    {
        TC_LOG_DEBUG("network", "Network Thread Starting");

        _updateTimer.expires_after(std::chrono::milliseconds(1));
        _updateTimer.async_wait([this](boost::system::error_code const&) { Update(); });

        // The timer keeps the context armed for as long as we run, so no
        // separate work guard is needed here.
        _ioContext.run();

        TC_LOG_DEBUG("network", "Network Thread exits");
        _newSockets.clear();
        _sockets.clear();
    }

    void Update()
    {
        if (_stopped)
            return;

        _updateTimer.expires_after(std::chrono::milliseconds(1));
        _updateTimer.async_wait([this](boost::system::error_code const&) { Update(); });

        AddNewSockets();

        _sockets.erase(std::remove_if(_sockets.begin(), _sockets.end(),
            [this](std::shared_ptr<SocketType> sock)
            {
                if (!sock->Update())
                {
                    if (sock->IsOpen())
                        sock->CloseSocket();

                    SocketRemoved(sock);
                    --_connections;
                    return true;
                }

                return false;
            }), _sockets.end());
    }

    std::atomic<int32> _connections;
    std::atomic<bool> _stopped;

    std::unique_ptr<std::thread> _thread;

    std::vector<std::shared_ptr<SocketType>> _sockets;

    std::mutex _newSocketsLock;
    std::vector<std::shared_ptr<SocketType>> _newSockets;

    boost::asio::io_context _ioContext;
    boost::asio::steady_timer _updateTimer;
};

#endif // SF_NETWORKTHREAD_H
