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

#include <chrono>
#include <functional>
#include <thread>

#include "Threading.h"
#include "Errors.h"

#ifdef _WIN32
#  include <windows.h>
#else
#  include <pthread.h>
#  include <sched.h>
#endif

using namespace Trinity;

namespace
{
#ifdef _WIN32
    int NativePriority(Priority p)
    {
        switch (p)
        {
            case Priority::Idle:     return THREAD_PRIORITY_IDLE;
            case Priority::Lowest:   return THREAD_PRIORITY_LOWEST;
            case Priority::Low:      return THREAD_PRIORITY_BELOW_NORMAL;
            case Priority::High:     return THREAD_PRIORITY_ABOVE_NORMAL;
            case Priority::Highest:  return THREAD_PRIORITY_HIGHEST;
            case Priority::Realtime: return THREAD_PRIORITY_TIME_CRITICAL;
            case Priority::Normal:
            default:       return THREAD_PRIORITY_NORMAL;
        }
    }
#endif
}

Thread::Thread(): m_task(nullptr)
{
}

Thread::Thread(Runnable* instance): m_task(instance)
{
    // register reference to m_task to prevent it deeltion until destructor
    if (m_task)
        m_task->incReference();

    bool _start = start();
    ASSERT (_start);
}

Thread::~Thread()
{
    // The ACE implementation never joined here - AuthSocket creates a Thread on
    // the stack and lets it go out of scope immediately while the patcher keeps
    // running. std::thread calls std::terminate on a joinable thread, so that
    // same "leave it running" has to be spelled out.
    if (m_thread.joinable())
        m_thread.detach();

    // deleted runnable object (if no other references)
    if (m_task)
        m_task->decReference();
}

bool Thread::start()
{
    if (m_task == nullptr || m_thread.joinable())
        return false;

    // incRef before spawing the thread, otherwise Thread::ThreadTask() might call decRef and delete m_task
    m_task->incReference();

    try
    {
        m_thread = std::thread(&Thread::ThreadTask, m_task);
    }
    catch (std::system_error const&)
    {
        m_task->decReference();
        return false;
    }

    return true;
}

bool Thread::wait()
{
    if (!m_thread.joinable() || !m_task)
        return false;

    m_thread.join();
    return true;
}

void Thread::destroy()
{
    // ACE_Thread::kill with a signal number of -1 was never able to take a
    // thread down: pthread_kill rejects the signal and the call returned early.
    // This is only ever reached with the process already shutting down, so
    // letting the thread go is what actually happened before.
    if (m_thread.joinable())
        m_thread.detach();
}

void Thread::ThreadTask(Runnable* task)
{
    task->run();

    // task execution complete, free referecne added at
    task->decReference();
}

uint64_t Thread::currentId()
{
    // Only ever used to label log lines, so any stable per-thread number does.
    return static_cast<uint64_t>(std::hash<std::thread::id>()(std::this_thread::get_id()));
}

void Thread::setPriority(Priority type)
{
#ifdef _WIN32
    if (m_thread.joinable())
        SetThreadPriority(static_cast<HANDLE>(m_thread.native_handle()), NativePriority(type));
#else
    // Under SCHED_OTHER, which is what the server runs on, Linux reports a
    // priority range of exactly one value, so the elaborate mapping ACE built
    // collapsed to a single number and setting it did nothing. Kept as a no-op
    // rather than pretending otherwise; nice(2) is the knob that would work,
    // and it applies to the whole process.
    (void)type;
#endif
}

void Thread::Sleep(unsigned long msecs)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(msecs));
}
