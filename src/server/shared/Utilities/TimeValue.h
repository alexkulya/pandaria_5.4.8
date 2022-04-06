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

#ifndef  TIME_VALUE_H
#define  TIME_VALUE_H

#include "Duration.h"

//! Class for representing the time value.
//! Wrapper around std::chrono::duration.
//! Commonly used to standardize time intervals in he high level code layer.
class TimeValue
{
public:

    typedef std::chrono::milliseconds Duration;

public:
    //! Default constructor.
    TimeValue()
        : _duration(std::chrono::milliseconds::zero())
    {
    }

    //! Copy constructor.
    TimeValue(TimeValue const& other)
        : _duration(other._duration)
    {
    }

    //! Constructor.
    //! Creates TimeValue from std::chrono::duration.
    //! @param d Duration.
    template <class Rep, class Period>
    TimeValue(std::chrono::duration<Rep, Period> const& d)
        : _duration(std::chrono::duration_cast<Duration>(d))
    {

    }

    //! Constructor.
    //! Creates TimeValue from std::chrono::time_point.
    //! @param tp Time point.
    template <class Clock>
    TimeValue(std::chrono::time_point<Clock> const& tp)
        : _duration(std::chrono::duration_cast<Duration>(tp.time_since_epoch()))
    {
    }

    //! Destructor.
    ~TimeValue()
    {
    }

    //! Converts to the number of seconds.
    //! @return The number of seconds.
    Seconds::rep ToSeconds() const
    {
        return std::chrono::duration_cast<Seconds>(GetDuration()).count();
    }

    //! Converts to the number of milliseconds.
    //! @return The number of milliseconds.
    Milliseconds::rep ToMilliseconds() const
    {
        return std::chrono::duration_cast<Milliseconds>(GetDuration()).count();
    }

    //! Converts to the number of microseconds.
    //! @return The number of microseconds.
    Microseconds::rep ToMicroseconds() const
    {
        return std::chrono::duration_cast<Microseconds>(GetDuration()).count();
    }

    //! Returns duratiron.
    //! @return The underlying duration object.
    Duration GetDuration() const
    {
        return _duration;
    }

    //! Subtracts @tv from this TimeValue.
    //! @param tv TimeVaule to substract.
    //! @return *this.
    TimeValue& operator-=(TimeValue const& tv)
    {
        _duration -= tv._duration;
        return *this;
    }

    //! Adds @a tv to this TimeValue.
    //! @param tv TimeVaule to add.
    //! @return *this.
    TimeValue& operator+=(TimeValue const& tv)
    {
        _duration += tv._duration;
        return *this;
    }

    //! Assings @tv to this TimeValue.
    //! @param tv TimeValue to assign.
    //! @return *this.
    TimeValue& operator=(TimeValue const& tv)
    {
        _duration = tv._duration;
        return *this;
    }

    operator bool() const
    {
        return _duration.count() != 0;
    }

    //! Returns TimeValue with zero duration.
    //! @return Constant reference to the static TimeValue object with zero duration.
    static TimeValue const& zero()
    {
        static TimeValue _null;
        return _null;
    }

    static TimeValue Now()
    {
        return TimeValue{ std::chrono::system_clock::now() };
    }

private:
    Duration _duration;
};


inline TimeValue operator-(TimeValue const& lhs, TimeValue const& rhs)
{
    auto diff = lhs.GetDuration() - rhs.GetDuration();
    return TimeValue(diff);
}

inline TimeValue operator+(TimeValue const& lhs, TimeValue const& rhs)
{
    auto sum = lhs.GetDuration() + rhs.GetDuration();
    return TimeValue(sum);
}

//
// Compare two TimeValues.
//

inline bool operator > (TimeValue const& lhs, TimeValue const& rhs)
{
    return lhs.GetDuration() > rhs.GetDuration();
}

inline bool operator < (TimeValue const& lhs, TimeValue const& rhs)
{
    return lhs.GetDuration() < rhs.GetDuration();
}

inline bool operator >= (TimeValue const& lhs, TimeValue const& rhs)
{
    return lhs.GetDuration() >= rhs.GetDuration();
}

inline bool operator <= (TimeValue const& lhs, TimeValue const& rhs)
{
    return lhs.GetDuration() <= rhs.GetDuration();
}

inline bool operator == (TimeValue const& lhs, TimeValue const& rhs)
{
    return lhs.GetDuration() == rhs.GetDuration();
}

inline bool operator != (TimeValue const& lhs, TimeValue const& rhs)
{
    return lhs.GetDuration() != rhs.GetDuration();
}

#endif //TIME_VALUE_H
