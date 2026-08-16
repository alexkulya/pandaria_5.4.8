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

#include "LogWorker.h"

LogWorker::LogWorker()
    : m_queue(HIGH_WATERMARK / sizeof(LogOperation))
{
    m_thread = std::thread([this] { svc(); });
}

LogWorker::~LogWorker()
{
    m_queue.deactivate();

    if (m_thread.joinable())
        m_thread.join();
}

int LogWorker::enqueue(LogOperation* op)
{
    return m_queue.enqueue(op) ? 0 : -1;
}

int LogWorker::svc()
{
    while (1)
    {
        Trinity::MethodRequest* request = m_queue.dequeue();
        if (!request)
            break;

        request->call();
        delete request;
    }

    return 0;
}
