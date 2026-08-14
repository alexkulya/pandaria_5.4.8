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

#ifndef SF_STACKTRACE_H
#define SF_STACKTRACE_H

#include <string>

namespace Trinity
{
    // Replacement for ACE_Stack_Trace. Captures the calling thread's stack on
    // construction and renders it once, so existing call sites keep the shape
    //
    //     Trinity::StackTrace st;
    //     TC_LOG_ERROR("x", "...%s", st.c_str());
    //
    // Capturing in the constructor matters: the trace must reflect the point of
    // the failure, not wherever the string is eventually formatted.
    class StackTrace
    {
    public:
        StackTrace();

        char const* c_str() const { return _buffer.c_str(); }
        std::string const& str() const { return _buffer; }

    private:
        std::string _buffer;
    };
}

#endif // SF_STACKTRACE_H
