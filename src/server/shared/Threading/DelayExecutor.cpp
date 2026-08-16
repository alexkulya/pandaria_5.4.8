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

#include "Singleton.h"
#include "Log.h"

#include "DelayExecutor.h"

DelayExecutor* DelayExecutor::instance()
{
    return Trinity::Singleton<DelayExecutor>::instance();
}

DelayExecutor::DelayExecutor()
    : pre_svc_hook_(0), post_svc_hook_(0), activated_(false) { }

DelayExecutor::~DelayExecutor()
{
    if (pre_svc_hook_)
        delete pre_svc_hook_;

    if (post_svc_hook_)
        delete post_svc_hook_;

    deactivate();
}

int DelayExecutor::deactivate()
{
    if (!activated())
        return -1;

    activated(false);
    queue_.deactivate();

    for (std::thread& worker : threads_)
        if (worker.joinable())
            worker.join();

    threads_.clear();

    return 0;
}

int DelayExecutor::svc()
{
    if (pre_svc_hook_)
        pre_svc_hook_->call();

    for (;;)
    {
        Trinity::MethodRequest* rq = queue_.dequeue();

        if (!rq)
            break;

        rq->call();
        delete rq;
    }

    if (post_svc_hook_)
        post_svc_hook_->call();

    return 0;
}

int DelayExecutor::start(int num_threads, Trinity::MethodRequest* pre_svc_hook, Trinity::MethodRequest* post_svc_hook)
{
    if (activated())
        return -1;

    if (num_threads < 1)
        return -1;

    if (pre_svc_hook_)
        delete pre_svc_hook_;

    if (post_svc_hook_)
        delete post_svc_hook_;

    pre_svc_hook_ = pre_svc_hook;
    post_svc_hook_ = post_svc_hook;

    queue_.activate();

    // ACE_Task_Base::activate spawned num_threads threads all running svc().
    threads_.reserve(num_threads);
    for (int i = 0; i < num_threads; ++i)
        threads_.emplace_back([this] { svc(); });

    activated(true);

    return true;
}

int DelayExecutor::execute(Trinity::MethodRequest* new_req)
{
    if (new_req == NULL)
        return -1;

    // enqueue takes ownership either way: it destroys the request itself when
    // the queue is closed, where the ACE version leaked it.
    if (!queue_.enqueue(new_req))
    {
        TC_LOG_ERROR("server", "DelayExecutor::execute enqueue failed, queue is not active");
        return -1;
    }

    return 0;
}

bool DelayExecutor::activated()
{
    return activated_;
}

void DelayExecutor::activated(bool s)
{
    activated_ = s;
}
