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

#ifndef SF_REALMSOCKET_H
#define SF_REALMSOCKET_H

#include "Common.h"
#include "Socket.h"

#include <boost/asio/ip/tcp.hpp>

#include <string>

// Transport for the auth protocol, now backed by Boost.Asio instead of
// ACE_Svc_Handler.
//
// The public API is deliberately unchanged from the ACE version: AuthSocket
// contains the SRP6 handshake and reads through recv/recv_soft/recv_skip, so
// keeping these signatures keeps that file out of this migration entirely.
class RealmSocket : public Socket<RealmSocket>
{
    typedef Socket<RealmSocket> Base;

public:
    class Session
    {
    public:
        Session(void);
        virtual ~Session(void);

        virtual void OnRead(void) = 0;
        virtual void OnAccept(void) = 0;
        virtual void OnClose(void) = 0;
    };

    explicit RealmSocket(boost::asio::ip::tcp::socket&& socket);
    virtual ~RealmSocket(void);

    void Start() override;

    // Bytes received and not yet consumed.
    size_t recv_len(void) const;

    // Copies len bytes out without consuming them; false when fewer are
    // buffered. This peek-then-commit pattern is how AuthSocket waits for a
    // complete packet before parsing it.
    bool recv_soft(char *buf, size_t len);

    bool recv(char *buf, size_t len);
    void recv_skip(size_t len);

    bool send(const char *buf, size_t len);

    // Kept for AuthSocket, which calls it to drop abusive clients. Mapped to a
    // delayed close so a rejection packet queued just before it still reaches
    // the client: with async writes an immediate close would discard it, which
    // the ACE version did not do because send() tried a direct write first.
    void shutdown(void);

    const std::string& getRemoteAddress(void) const;
    uint16 getRemotePort(void) const;

    void set_session(Session* session);

protected:
    bool ReadHandler() override;
    void OnClose() override;

private:
    Session* session_;
    std::string _remoteAddress;
    uint16 _remotePort;
};

#endif /* SF_REALMSOCKET_H */
