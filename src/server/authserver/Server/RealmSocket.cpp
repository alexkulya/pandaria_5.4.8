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

#include "RealmSocket.h"
#include "AuthSocket.h"
#include "Log.h"

#include <cstring>

RealmSocket::Session::Session(void) { }

RealmSocket::Session::~Session(void) { }

RealmSocket::RealmSocket(boost::asio::ip::tcp::socket&& socket) :
    Base(std::move(socket)), session_(NULL),
    _remoteAddress(GetRemoteIpAddress().to_string()), _remotePort(Base::GetRemotePort())
{
    // The acceptor used to attach the protocol handler in make_svc_handler.
    // SocketMgr constructs sockets generically, so the pairing lives here now.
    session_ = new AuthSocket(*this);
}

RealmSocket::~RealmSocket(void)
{
    delete session_;
}

void RealmSocket::Start()
{
    TC_LOG_DEBUG("server.authserver", "Accepted connection from %s:%u", _remoteAddress.c_str(), _remotePort);

    if (session_)
        session_->OnAccept();

    AsyncRead();
}

// Called once bytes have landed in the read buffer. AuthSocket consumes what it
// can through recv/recv_skip and leaves any partial packet behind; the next
// AsyncRead normalizes the buffer so the remainder stays contiguous.
bool RealmSocket::ReadHandler()
{
    if (!session_)
        return false;

    session_->OnRead();

    // Only arm another read while the socket is still live. Returning true
    // regardless is deliberate: after shutdown() the socket must stay in the
    // network thread's list long enough for Update() to flush the write queue,
    // and returning false here would close it and drop the queued packet.
    if (IsOpen())
        AsyncRead();

    return true;
}

void RealmSocket::OnClose()
{
    if (session_)
        session_->OnClose();
}

const std::string& RealmSocket::getRemoteAddress(void) const
{
    return _remoteAddress;
}

uint16 RealmSocket::getRemotePort(void) const
{
    return _remotePort;
}

size_t RealmSocket::recv_len(void) const
{
    return GetReadBuffer().GetActiveSize();
}

bool RealmSocket::recv_soft(char *buf, size_t len)
{
    MessageBuffer& packet = GetReadBuffer();

    if (packet.GetActiveSize() < len)
        return false;

    memcpy(buf, packet.GetReadPointer(), len);

    return true;
}

bool RealmSocket::recv(char *buf, size_t len)
{
    bool ret = recv_soft(buf, len);

    if (ret)
        recv_skip(len);

    return ret;
}

void RealmSocket::recv_skip(size_t len)
{
    GetReadBuffer().ReadCompleted(len);
}

bool RealmSocket::send(const char *buf, size_t len)
{
    if (buf == NULL || len == 0)
        return true;

    if (!IsOpen())
        return false;

    MessageBuffer buffer(len);
    buffer.Write(buf, len);
    QueuePacket(std::move(buffer));

    return true;
}

void RealmSocket::shutdown(void)
{
    DelayedCloseSocket();
}

void RealmSocket::set_session(Session* session)
{
    delete session_;
    session_ = session;
}
