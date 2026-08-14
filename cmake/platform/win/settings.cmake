# Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/
# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Package overloads
set(ACE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/dep/acelite)
set(ACE_LIBRARY "ace")

# ACE is always built static from dep/acelite here. The ace target marks this
# PUBLIC, but that only reaches targets that link it, and game/scripts pull ACE
# headers in without a target_link_libraries of their own - so their objects end
# up referencing __declspec(dllimport) symbols that the static library does not
# export, and the final link fails with LNK2001 on ACE_RW_Mutex and friends.
add_definitions(-DACE_AS_STATIC_LIBS)
set(BZIP2_LIBRARIES "bzip2")
set(ZLIB_LIBRARIES "zlib")

# The MySQL client comes from the system here as it does everywhere else, so
# nothing overrides what find_package(MySQL) resolved. Point the build at a
# client with -DMYSQL_LIBRARY and -DMYSQL_INCLUDE_DIR when it lives outside the
# paths FindMySQL searches.

# check the CMake preload parameters (commented out by default)

# overload CMAKE_INSTALL_PREFIX if not being set properly
#if( WIN32 )
#  if( NOT CYGWIN )
#    if( NOT CMAKE_INSTALL_PREFIX )
#      set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/bin")
#    endif()
#  endif()
#endif()

if ( MSVC )
  include(${CMAKE_SOURCE_DIR}/cmake/compiler/msvc/settings.cmake)
elseif ( MINGW )
  include(${CMAKE_SOURCE_DIR}/cmake/compiler/mingw/settings.cmake)
endif()
