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

#include "DatabaseEnv.h"
#include "DatabaseWorker.h"
#include "SQLOperation.h"
#include "MySQLConnection.h"
#include "MySQLThreading.h"

DatabaseWorker::DatabaseWorker(MySQLConnection* conn)
    : m_conn(conn)
{
    _thr = std::thread([this]() { Run(); });
}

DatabaseWorker::~DatabaseWorker()
{
    m_queue.queue()->deactivate();
    if (_thr.joinable())
        _thr.join();

    delete m_conn;
}

void DatabaseWorker::Run()
{
    SQLOperation *request = NULL;
    while (true)
    {
        request = (SQLOperation*)(m_queue.dequeue());
        if (!request)
            break;

        request->SetConnection(m_conn);
        request->call();
        --_count;
        delete request;
    }
}
