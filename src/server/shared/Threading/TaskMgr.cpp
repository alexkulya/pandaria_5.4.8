#include "TaskMgr.h"
#include "Task.h"

ThreadPool TaskMgr::_pool{ 1 };

// Yes, this must be here.
TaskMgr::~TaskMgr()
{
}

void TaskMgr::Update()
{
    TaskObject task;
    while (_queue.next(task))
        _tasks.push_back(task);

    if (_tasks.empty())
        return;

    using namespace std::chrono;
    steady_clock::time_point end = steady_clock::now() + _max;

    auto it = _tasks.begin();

    do
    {
        if (!(*it)->Update()) // even if task canceled, it is not in process, we can delete it now
            _tasks.erase(it++);
        else
            ++it;
    } while (it != _tasks.end() && steady_clock::now() < end);
}

void TaskMgr::ScheduleInvocation(std::function<void()> func)
{
    _queue.add(TaskObject{ new CallbackTask(std::move(func)) });
}

void TaskMgr::ScheduleInvocation(TaskBase* task)
{
    _queue.add(TaskObject{ task });
}

void Schedulable::NewAction(TaskBase* task)
{
    CancelationToken tok = task->GetToken();
    for (auto&& token : _tokens)
    {
        if (token->IsExpired())
        {
            token = std::move(tok);
            return;
        }
    }

    _tokens.push_back(std::move(tok));
}
