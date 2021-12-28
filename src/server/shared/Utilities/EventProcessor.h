/*
 * Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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

#ifndef __EVENTPROCESSOR_H
#define __EVENTPROCESSOR_H

#include "Define.h"

#include <map>

// Note. All times are in milliseconds here.

class BasicEvent
{
    public:
        BasicEvent() { to_Abort = false; }
        virtual ~BasicEvent() { }                           // override destructor to perform some actions on event removal

        // this method executes when the event is triggered
        // return false if event does not want to be deleted
        // e_time is execution time, p_time is update interval
        virtual bool Execute(uint64 /*e_time*/, uint32 /*p_time*/) { return true; }

        virtual bool IsDeletable() const { return true; }   // this event can be safely deleted

        virtual void Abort(uint64 /*e_time*/) { }           // this method executes when the event is aborted

        bool to_Abort;                                      // set by externals when the event is aborted, aborted events don't execute
        // and get Abort call when deleted

        // these can be used for time offset control
        uint64 m_addTime = 0;                               // time when the event was added to queue, filled by event handler
        uint64 m_execTime = 0;                              // planned time of next execution, filled by event handler
};

class GroupedEvent : public BasicEvent
{
public:
    typedef uint32 group_type;

    GroupedEvent(group_type group) : m_group(group) { }

    group_type GetGroup() const { return m_group; }
    group_type GetGroupMask() const { return 1 << m_group; }

private:
    group_type m_group;
};

class FunctionEvent : public GroupedEvent
{
public:
    typedef std::function<void()> function_type;

    FunctionEvent(function_type const& function, group_type group = 0) : GroupedEvent(group), m_function(function) { }
    bool Execute(uint64, uint32) override { m_function(); return true; }

protected:
    function_type m_function;
};

class EventProcessor;

class RepeatableFunctionEvent : public GroupedEvent
{
public:
    typedef std::function<bool()> function_type;

    RepeatableFunctionEvent(EventProcessor* events, function_type const& function, uint32 repeat, group_type group = 0) : GroupedEvent(group), m_events(events), m_function(function), m_repeat(repeat) { }
    bool Execute(uint64, uint32) override;

protected:
    EventProcessor* m_events;
    function_type m_function;
    uint32 m_repeat;
};


typedef std::multimap<uint64, BasicEvent*> EventList;

class EventProcessor
{
    public:
        EventProcessor();
        ~EventProcessor();

        void Update(uint32 p_time);
        template<class EventFilter>
        BasicEvent* FindEvent(EventFilter const& filter);
        template<class EventFilter>
        void ProcessCustomEvents(EventFilter const& filter);
        void KillAllEvents(bool force);
        template<class EventFilter>
        void KillCustomEvents(EventFilter const& filter);
        void AddEvent(BasicEvent* Event, uint64 e_time, bool set_addtime = true);
        void RescheduleEvent(BasicEvent* event, uint64 e_time);

        uint64 CalculateTime(uint64 t_offset) const;

        void Schedule(uint32 delay, BasicEvent* Event) { AddEvent(Event, CalculateTime(delay)); }
        void Schedule(uint32 delay, FunctionEvent::function_type const& function) { Schedule(delay, new FunctionEvent(function)); }
        void Schedule(uint32 delay, GroupedEvent::group_type group, FunctionEvent::function_type const& function) { Schedule(delay, new FunctionEvent(function, group)); }
        void Repeated(uint32 delay, uint32 repeat, RepeatableFunctionEvent::function_type const& function) { Schedule(delay, new RepeatableFunctionEvent(this, function, repeat)); }
        void Repeated(uint32 delay, uint32 repeat, GroupedEvent::group_type group, RepeatableFunctionEvent::function_type const& function) { Schedule(delay, new RepeatableFunctionEvent(this, function, repeat, group)); }

        void KillEventsByGroup(GroupedEvent::group_type group) { KillCustomEvents([group](BasicEvent* event) { if (GroupedEvent* e = dynamic_cast<GroupedEvent*>(event)) return e->GetGroup() == group; return false; }); }
        void KillEventsByGroupMask(GroupedEvent::group_type groupMask) { KillCustomEvents([groupMask](BasicEvent* event) { if (GroupedEvent* e = dynamic_cast<GroupedEvent*>(event)) return (e->GetGroupMask() & groupMask) != 0; return false; }); }

    protected:
        uint64 m_time;
        EventList m_events;
        bool m_aborting;
};

template<class EventFilter>
BasicEvent* EventProcessor::FindEvent(EventFilter const& filter)
{
    for (auto&& event : m_events)
        if (filter(event.second))
            return event.second;

    return NULL;
}

template<class EventFilter>
void EventProcessor::ProcessCustomEvents(EventFilter const& filter)
{
    auto copy = m_events;
    for (auto&& itr : copy)
    {
        BasicEvent* event = itr.second;
        if (filter(event))
        {
            auto origItr = std::find_if(m_events.begin(), m_events.end(), [=](EventList::value_type const& p)
            {
                return p.second == event;
            });
            ASSERT(origItr != m_events.end());
            m_events.erase(origItr);

            if (!event->to_Abort)
            {
                if (event->Execute(m_time, 0))
                {
                    // completely destroy event if it is not re-added
                    delete event;
                }
            }
            else
            {
                event->Abort(m_time);
                delete event;
            }
        }
    }
}

template<class EventFilter>
void EventProcessor::KillCustomEvents(EventFilter const& filter)
{
    // prevent event insertions
    m_aborting = true;

    // first, abort all existing events
    for (EventList::iterator i = m_events.begin(); i != m_events.end();)
    {
        EventList::iterator i_old = i;
        ++i;

        if (!filter(i_old->second))
            continue;

        i_old->second->to_Abort = true;
        i_old->second->Abort(m_time);
        if (i_old->second->IsDeletable())
        {
            delete i_old->second;
            m_events.erase(i_old);
        }
    }
}

#endif
