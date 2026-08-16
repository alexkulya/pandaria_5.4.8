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

#ifndef TRINITY_ACTIVATION_QUEUE_H
#define TRINITY_ACTIVATION_QUEUE_H

#include <condition_variable>
#include <mutex>
#include <queue>
#include <vector>

namespace Trinity
{

/// Replaces ACE_Method_Request: a unit of work a worker thread will run.
class MethodRequest
{
    public:
        MethodRequest() : _priority(0) { }
        virtual ~MethodRequest() { }
        virtual int call() = 0;

        /// Higher runs first. MapUpdater sets this from the instance count and
        /// the player load of the map, so busy maps are not left behind quiet
        /// ones - dropping it would have turned map updates into plain FIFO.
        unsigned long priority() const { return _priority; }
        void priority(unsigned long priority) { _priority = priority; }

    private:
        unsigned long _priority;
};

/**
 * Replaces ACE_Activation_Queue. Producers enqueue work, one or more worker
 * threads block in dequeue() until there is some.
 *
 * Ordering follows ACE: the underlying ACE_Message_Queue is a priority queue,
 * not a FIFO, so the highest priority request is served first and equal
 * priorities keep insertion order.
 *
 * One deliberate difference from ACE. ACE_Message_Queue::deactivate made every
 * pending and future dequeue fail at once, so whatever was still queued was
 * dropped - and leaked, since nothing owned those requests any more. Here
 * deactivate() stops new work from being accepted but lets the workers finish
 * what is already queued before dequeue() starts returning nullptr. On the
 * database pool that queue holds character saves at shutdown, so draining it is
 * the behaviour worth having.
 */
class ActivationQueue
{
    public:
        /// maxSize 0 leaves the queue unbounded. A non-zero value makes
        /// enqueue() block once that many requests are pending, which is the
        /// back pressure ACE_Message_Queue's high water mark provided: without
        /// it a stalled consumer lets the queue grow until memory runs out.
        explicit ActivationQueue(size_t maxSize = 0)
            : _maxSize(maxSize), _sequence(0), _active(true) { }

        ~ActivationQueue()
        {
            std::lock_guard<std::mutex> guard(_lock);
            while (!_queue.empty())
            {
                delete _queue.top().request;
                _queue.pop();
            }
        }

        /// False if the queue is closed, in which case the request is destroyed
        /// rather than leaked the way the ACE version left it.
        bool enqueue(MethodRequest* request)
        {
            {
                std::unique_lock<std::mutex> guard(_lock);

                if (_maxSize)
                    _spaceAvailable.wait(guard, [this] { return _queue.size() < _maxSize || !_active; });

                if (!_active)
                {
                    delete request;
                    return false;
                }

                _queue.push(Entry{ request, request->priority(), _sequence++ });
            }

            _condition.notify_one();
            return true;
        }

        /// Blocks until work arrives. Returns nullptr once the queue has been
        /// deactivated and drained, which is how workers learn to stop.
        MethodRequest* dequeue()
        {
            std::unique_lock<std::mutex> guard(_lock);
            _condition.wait(guard, [this] { return !_queue.empty() || !_active; });

            if (_queue.empty())
                return nullptr;

            MethodRequest* request = _queue.top().request;
            _queue.pop();

            if (_maxSize)
                _spaceAvailable.notify_one();

            return request;
        }

        void activate()
        {
            std::lock_guard<std::mutex> guard(_lock);
            _active = true;
        }

        void deactivate()
        {
            {
                std::lock_guard<std::mutex> guard(_lock);
                _active = false;
            }

            // Every worker has to wake up, not just one, or the others stay
            // blocked forever and their join never returns. Producers parked on
            // a full queue have to be released too, for the same reason.
            _condition.notify_all();
            _spaceAvailable.notify_all();
        }

    private:
        ActivationQueue(ActivationQueue const&);
        ActivationQueue& operator=(ActivationQueue const&);

        struct Entry
        {
            MethodRequest* request;
            unsigned long priority;
            // Breaks ties so equal priorities come out in insertion order;
            // std::priority_queue gives no ordering guarantee on its own.
            unsigned long long sequence;
        };

        struct LowerPriorityFirst
        {
            bool operator()(Entry const& left, Entry const& right) const
            {
                if (left.priority != right.priority)
                    return left.priority < right.priority;

                return left.sequence > right.sequence;
            }
        };

        std::priority_queue<Entry, std::vector<Entry>, LowerPriorityFirst> _queue;
        size_t _maxSize;
        unsigned long long _sequence;
        std::mutex _lock;
        std::condition_variable _condition;      // work is available
        std::condition_variable _spaceAvailable; // room to enqueue, bounded only
        bool _active;
};

}

#endif
