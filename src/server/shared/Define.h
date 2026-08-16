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

#ifndef TRINITY_DEFINE_H
#define TRINITY_DEFINE_H

#include "CompilerDefs.h"

#include <cinttypes>
#include <cstddef>
#include <cstdint>

#define TRINITY_LITTLEENDIAN 0
#define TRINITY_BIGENDIAN    1

#if !defined(TRINITY_ENDIAN)
// GCC and Clang publish the byte order; MSVC does not, but every target it
// builds for here is little-endian. Same shape as the ACE_BIG_ENDIAN test this
// replaces: big-endian only when the compiler says so, little otherwise.
#  if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ == __ORDER_BIG_ENDIAN__)
#    define TRINITY_ENDIAN TRINITY_BIGENDIAN
#  else
#    define TRINITY_ENDIAN TRINITY_LITTLEENDIAN
#  endif
#endif //TRINITY_ENDIAN

#if PLATFORM == PLATFORM_WINDOWS
#  define TRINITY_PATH_MAX MAX_PATH
#  ifndef DECLSPEC_NORETURN
#    define DECLSPEC_NORETURN __declspec(noreturn)
#  endif //DECLSPEC_NORETURN
#  ifndef DECLSPEC_DEPRECATED
#    define DECLSPEC_DEPRECATED __declspec(deprecated)
#  endif //DECLSPEC_DEPRECATED
#else //PLATFORM != PLATFORM_WINDOWS
#  define TRINITY_PATH_MAX PATH_MAX
#  define DECLSPEC_NORETURN
#  define DECLSPEC_DEPRECATED
#endif //PLATFORM

#if !defined(COREDEBUG)
#  define TRINITY_INLINE inline
#else //COREDEBUG
#  if !defined(TRINITY_DEBUG)
#    define TRINITY_DEBUG
#  endif //TRINITY_DEBUG
#  define TRINITY_INLINE
#endif //!COREDEBUG

#if COMPILER == COMPILER_GNU
#  define ATTR_NORETURN __attribute__((noreturn))
#  define ATTR_PRINTF(F, V) __attribute__ ((format (printf, F, V)))
#  define ATTR_DEPRECATED __attribute__((deprecated))
#else //COMPILER != COMPILER_GNU
#  define ATTR_NORETURN
#  define ATTR_PRINTF(F, V)
#  define ATTR_DEPRECATED
#endif //COMPILER == COMPILER_GNU

// The ACE specifiers these replace carried their own '%', and every call site
// relies on that - they are written as `", " UI64FMTD ", "` with no percent of
// their own - so the '%' stays part of the macro rather than moving to the
// hundreds of format strings that use them.
#define UI64FMTD "%" PRIu64
#define UI64LIT(N) UINT64_C(N)

#define SI64FMTD "%" PRId64
#define SI64LIT(N) INT64_C(N)

#define SIZEFMTD "%zu"

#if COMPILER == COMPILER_MICROSOFT
#  define SZFMTD "%Iu"
#else
#  define SZFMTD "%zu"
#endif

typedef std::int64_t  int64;
typedef std::int32_t  int32;
typedef std::int16_t  int16;
typedef std::int8_t   int8;
typedef std::uint64_t uint64;
typedef std::uint32_t uint32;
typedef std::uint16_t uint16;
typedef std::uint8_t  uint8;

enum DBCFormer
{
    FT_NA='x',                                              //not used or unknown, 4 byte size
    FT_NA_BYTE='X',                                         //not used or unknown, byte
    FT_STRING='s',                                          //char*
    FT_FLOAT='f',                                           //float
    FT_INT='i',                                             //uint32
    FT_BYTE='b',                                            //uint8
    FT_SORT='d',                                            //sorted by this field, field is not included
    FT_IND='n',                                             //the same, but parsed to data
    FT_SQL_PRESENT='p',                                     //Used in sql format to mark column present in sql dbc
    FT_SQL_ABSENT='a'                                       //Used in sql format to mark column absent in sql dbc
};

#endif //TRINITY_DEFINE_H
