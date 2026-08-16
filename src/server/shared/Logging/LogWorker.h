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

#ifndef LOGWORKER_H
#define LOGWORKER_H

#include "LogOperation.h"
#include "Threading/ActivationQueue.h"

#include <thread>

class LogWorker
{
    public:
        LogWorker();
        ~LogWorker();

        enum
        {
            // ACE_Message_Queue_Ex counted bytes and wrapped each entry in a
            // block of sizeof(LogOperation), so the 8 MB mark was really a cap
            // on how many messages could pile up. Kept as that count, so a
            // stalled appender still blocks the caller instead of growing
            // without bound.
            HIGH_WATERMARK = 8 * 1024 * 1024
        };

        int enqueue(LogOperation* op);

    private:
        int svc();

        Trinity::ActivationQueue m_queue;
        std::thread m_thread;
};

#endif
