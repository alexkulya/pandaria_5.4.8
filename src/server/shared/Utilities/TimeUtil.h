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

#ifndef SF_TIMEUTIL_H
#define SF_TIMEUTIL_H

#include <ctime>

namespace Trinity
{
    // Portable replacement for ACE_OS::localtime_r.
    //
    // This wrapper exists because the two platform functions disagree on both
    // argument order and return value:
    //
    //     POSIX:  struct tm* localtime_r(time_t const*, struct tm*)
    //     MSVC:   errno_t    localtime_s(struct tm*, time_t const*)
    //
    // No caller in this codebase uses the result, so the wrapper returns void
    // and the difference stays contained here.
    inline void LocalTime(time_t const& time, struct tm& result)
    {
#ifdef _WIN32
        localtime_s(&result, &time);
#else
        localtime_r(&time, &result);
#endif
    }
}

#endif // SF_TIMEUTIL_H
