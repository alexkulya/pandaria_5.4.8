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

#ifndef  TASK_H
#define  TASK_H

#include <ace/Future.h>
#include "Common.h"
#include "TaskMgr.h"

//! Base class for tasks that can be scheduled in TaskMgr.
class TaskBase : public std::enable_shared_from_this<TaskBase>
{
    friend class TaskMgr;

public:
    TaskBase()
    {
        _token.reset(new TaskToken());
    }

    virtual ~TaskBase() { }

    //! Get linked object for safe cancelation.
    CancelationToken GetToken()
    {
        return _token;
    }

protected:
    virtual bool Update() = 0;
    CancelationToken _token;
};

//! Class of task with continuation.
template <class T>
class Task : public TaskBase
{
public:
    typedef std::function<T()> Impl;
    typedef std::function<void(T&&)> Continuation;

public:
    //! Default construtor.
    Task()
    {
    }

    //! Constructor with main task implementation.
    //! Not used at current time.
    Task(Impl&& impl)
        : _impl(std::move(impl))
    {
    }

    //! Creates task continuation that will be executed in context of the specified task manager.
    void ContinueWith(Continuation&& continuation, TaskMgr* taskMgr = TaskMgr::Default())
    {
        _continuation = std::move(continuation);
        taskMgr->ScheduleInvocation(this);
    }

    void SetResult(T const& result)
    {
        _ret = result;
        _ready = true;
    }

private:
    //! Update state of the task.
    //! If false returned - task has no need to be updated more and it can be deleted.
    bool Update()
    {
        // Wait for task end anyway, after _ready == true task can be deleted safely.
        // Also no data races here, one thread check, other set true value, it can't be anymore modifed.
        if (_ready)
        {
            if (!TaskBase::_token->IsCanceled())
                _continuation(std::move(_ret));
            TaskBase::_token->Delink();
            return false;
        }
        return true;
    }

    //! Not used at current time.
    void DoTask()
    {
        _ret = std::move(_impl());
        _ready = true;
    }

protected:
    T _ret;
    std::function<T()> _impl;
    Continuation _continuation;
    bool _ready = false;
};

//! Task which generally...wait another task :D
//! I don't want rewrite large amount of existing code, therefore, be so.
template <typename T>
class WaitResultTask : public Task<T>
{
public:
    WaitResultTask(ACE_Future<T> const& future)
    {
        _future = future;
    }

    bool Update() override
    {
        if (_future.ready())
        {
            if (!TaskBase::_token->IsCanceled())
            {
                T res;
                _future.get(res);
                Task<T>::_continuation(std::move(res));
            }
            _future.cancel();
            TaskBase::_token->Delink();
            return false;
        }
        return true;
    }

private:
    ACE_Future<T> _future;
};

//! Just callback for execution in scheduler context.
class CallbackTask : public TaskBase
{
public:
    explicit CallbackTask(std::function<void()>&& callback)
        : _callback(std::move(callback))
    {
    }

    explicit CallbackTask(std::function<void()> const& callback)
        : _callback(callback)
    {
    }

    //! Just call function, or not if canceled.
    bool Update()
    {
        if (!_token->IsCanceled())
            _callback();
        _token->Delink();
        return false;
    }

private:
    std::function<void()> _callback;
};

#endif //TASK_H
