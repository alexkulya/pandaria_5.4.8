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

#ifndef TRINITY_FUTURE_H
#define TRINITY_FUTURE_H

#include <atomic>
#include <chrono>
#include <future>
#include <memory>

namespace Trinity
{

/**
 * Replacement for the slice of ACE_Future the core actually used.
 *
 * std::future is move-only and has no non-blocking readiness check, so it does
 * not fit on its own: the database pool hands a copy of the same future to the
 * worker task and to the caller, and the caller polls it every world tick. This
 * pairs a promise with a shared_future behind one shared_ptr, which gives back
 * ACE's shape - default constructible, freely copyable, one producer filling it
 * in once - on top of the standard library.
 */
template <typename T>
class Future
{
    public:
        Future() : _state(std::make_shared<State>()) { }

        /// Producer side, called once from the database worker thread.
        /// False if the value was already set or the future was cancelled.
        bool set(T const& value)
        {
            if (!_state || _state->assigned.exchange(true))
                return false;

            _state->promise.set_value(value);
            return true;
        }

        /// Non-blocking. False while the worker has not answered yet.
        bool ready() const
        {
            return _state
                && _state->future.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
        }

        /// Blocks until the value is available, like ACE_Future::get did.
        bool get(T& value) const
        {
            if (!_state)
                return false;

            value = _state->future.get();
            return true;
        }

        /// Drop this handle on the shared state. Any other copy keeps working.
        void cancel() { _state.reset(); }

    private:
        struct State
        {
            State() : future(promise.get_future()), assigned(false) { }

            std::promise<T> promise;
            std::shared_future<T> future;
            // set() runs on a worker thread; guards against a second producer.
            std::atomic<bool> assigned;
        };

        std::shared_ptr<State> _state;
};

}

#endif
