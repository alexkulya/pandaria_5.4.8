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

#include "StackTrace.h"

#include <mutex>
#include <sstream>

#ifdef _WIN32
#  include <windows.h>
#  include <DbgHelp.h>
#  pragma comment(linker, "/DEFAULTLIB:dbghelp.lib")
#else
#  include <cstdlib>
#  include <execinfo.h>
#endif

namespace
{
    // How many frames to capture. ACE_Stack_Trace defaulted to a similar depth;
    // the first frames are this file itself and are skipped when rendering.
    std::size_t const MAX_FRAMES = 32;
    std::size_t const SKIP_FRAMES = 1;

#ifdef _WIN32
    // DbgHelp is explicitly documented as not thread safe: every Sym* call has
    // to be serialised, or two threads tracing at once corrupt its state.
    std::mutex g_symbolLock;
    bool g_symbolsInitialised = false;
#endif
}

namespace Trinity
{

StackTrace::StackTrace()
{
    std::ostringstream out;

#ifdef _WIN32
    void* frames[MAX_FRAMES];
    USHORT const captured = CaptureStackBackTrace(static_cast<DWORD>(SKIP_FRAMES), static_cast<DWORD>(MAX_FRAMES), frames, nullptr);

    std::lock_guard<std::mutex> lock(g_symbolLock);

    HANDLE const process = GetCurrentProcess();
    if (!g_symbolsInitialised)
    {
        SymSetOptions(SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES | SYMOPT_UNDNAME);
        // Failure is not fatal: without symbols the trace still carries
        // addresses, which is better than no trace at all.
        g_symbolsInitialised = SymInitialize(process, nullptr, TRUE) != FALSE;
    }

    // SYMBOL_INFO is a variable length struct: the name is written past the end
    // of the declared struct, so the storage has to be oversized by hand.
    char symbolStorage[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(char)] = { };
    SYMBOL_INFO* symbol = reinterpret_cast<SYMBOL_INFO*>(symbolStorage);
    symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
    symbol->MaxNameLen = MAX_SYM_NAME;

    for (USHORT i = 0; i < captured; ++i)
    {
        DWORD64 const address = reinterpret_cast<DWORD64>(frames[i]);

        out << "  " << frames[i];

        DWORD64 displacement = 0;
        if (g_symbolsInitialised && SymFromAddr(process, address, &displacement, symbol))
        {
            out << ' ' << symbol->Name;

            IMAGEHLP_LINE64 line = { };
            line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
            DWORD lineDisplacement = 0;
            if (SymGetLineFromAddr64(process, address, &lineDisplacement, &line))
                out << " (" << line.FileName << ':' << line.LineNumber << ')';
        }

        out << '\n';
    }
#else
    void* frames[MAX_FRAMES];
    int const captured = backtrace(frames, static_cast<int>(MAX_FRAMES));

    if (char** symbols = backtrace_symbols(frames, captured))
    {
        for (int i = static_cast<int>(SKIP_FRAMES); i < captured; ++i)
            out << "  " << symbols[i] << '\n';

        // backtrace_symbols allocates the whole table with malloc; the strings
        // are inside that single block, so one free releases all of them.
        free(symbols);
    }
#endif

    _buffer = out.str();
}

} // namespace Trinity
