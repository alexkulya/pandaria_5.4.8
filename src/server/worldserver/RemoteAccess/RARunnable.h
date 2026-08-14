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

/// \addtogroup Trinityd
/// @{
/// \file

#ifndef _TRINITY_RARUNNABLE_H_
#define _TRINITY_RARUNNABLE_H_

#include "Common.h"

#include <boost/asio/io_context.hpp>

#include <memory>

class AsyncAcceptor;

// Owns the RA listener. Still an ACE_Based::Runnable so Master.cpp keeps
// starting it the same way -- the thread abstraction is a separate migration
// from the socket one, and mixing the two would widen this change for nothing.
class RARunnable : public ACE_Based::Runnable
{
public:
    RARunnable();
    virtual ~RARunnable();

    void run() override;

private:
    void OnAccept(boost::asio::ip::tcp::socket&& socket);

    boost::asio::io_context _ioContext;
    std::unique_ptr<AsyncAcceptor> _acceptor;
};

#endif /* _TRINITY_RARUNNABLE_H_ */

/// @}
