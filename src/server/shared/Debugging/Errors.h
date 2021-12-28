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

#ifndef TRINITYCORE_ERRORS_H
#define TRINITYCORE_ERRORS_H

#include "Define.h"
#include <string>

namespace Trinity
{
    DECLSPEC_NORETURN void Fatal(char const* file, int line, char const* function, char const* message) ATTR_NORETURN;

    DECLSPEC_NORETURN void Error(char const* file, int line, char const* function, char const* message) ATTR_NORETURN;

    void Warning(char const* file, int line, char const* function, char const* message);

} // namespace Trinity

#define WPFatal(cond, msg) do { if (!(cond)) Trinity::Fatal(__FILE__, __LINE__, __FUNCTION__, (msg)); } while (0)
#define WPError(cond, msg) do { if (!(cond)) Trinity::Error(__FILE__, __LINE__, __FUNCTION__, (msg)); } while (0)
#define WPWarning(cond, msg) do { if (!(cond)) Trinity::Warning(__FILE__, __LINE__, __FUNCTION__, (msg)); } while (0)

#define STR(x) #x
#define STR_(x) STR(x)
#define STR_LINE STR_(__LINE__)
#define DEBUG_STR(x) ("ASSERTION FAILED: " #x " at " __FILE__ ":" STR_LINE )

#ifdef _WIN32
__declspec(noreturn)
#endif
void LogAndDie(char const* msg, char const* func);

#ifdef _WIN32
#define WPAssert(assertion) do { if (!(assertion)) LogAndDie(DEBUG_STR((assertion)), __FUNCTION__); } while(0)
#else
#define WPAssert(assertion) do { if (!(assertion)) LogAndDie(DEBUG_STR((assertion)), __PRETTY_FUNCTION__); } while(0)
#endif
#define ASSERT WPAssert

void LogNotImplementedCall(char const* name);

#define CALL_NOT_IMPLEMENTED() LogNotImplementedCall(__FUNCTION__)

class Exception : public std::exception
{
public:
    Exception() { }
    Exception(std::string const& what) : _what(what) { }
    Exception(char const* what) : _what(what) { }
    Exception(Exception const& other) : _what(other._what) { }
    ~Exception() { }

    char const* what() const throw()
    {
        return _what.c_str();
    }

private:
    std::string _what;
};

#endif
