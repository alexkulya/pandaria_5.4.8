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

#include "Errors.h"
#include "Log.h"
#include <ace/Stack_Trace.h>
#include <ace/OS_NS_unistd.h>
#include <cstdlib>

namespace Trinity {

void Fatal(char const* file, int line, char const* function, char const* message)
{
    fprintf(stderr, "\n%s:%i in %s FATAL ERROR:\n  %s\n",
                   file, line, function, message);
    std::abort();
}

void Error(char const* file, int line, char const* function, char const* message)
{
    fprintf(stderr, "\n%s:%i in %s ERROR:\n  %s\n",
                   file, line, function, message);
    std::abort();
}

void Warning(char const* file, int line, char const* function, char const* message)
{
    fprintf(stderr, "\n%s:%i in %s WARNING:\n  %s\n",
                   file, line, function, message);
}

} // namespace Trinity

void LogAndDie(char const* msg, char const* func)
{
    ACE_Stack_Trace st;
    sLog->outError("server", "%s\nIn funtion: %s\n%s", msg, func, st.c_str());
    //std::abort();
}

void LogNotImplementedCall(char const* func)
{
    sLog->outError("server", "Call of not implemented function: %s", func);
}
