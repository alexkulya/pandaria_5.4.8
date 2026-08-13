# Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Must precede project(). 3.5 is the oldest value CMake 4.x still accepts; the
# upper bound of the range keeps the policy defaults of the toolchain this was
# written against, so newer CMake does not silently change behaviour.
cmake_minimum_required(VERSION 3.5...3.31)

# Before project or language initialization
if (UNIX)
  if (EXISTS "/usr/bin/gcc-4.9")
    message (STATUS "gcc 4.9 found. Force switching to 4.8")
    if (NOT EXISTS "/usr/bin/gcc-4.8")
      message (FATAL_ERROR "gcc 4.8 not found")
    endif()
    if (NOT EXISTS "/usr/bin/g++-4.8")
      message (FATAL_ERROR "g++ 4.8 not installed")
    endif()
    set (CMAKE_C_COMPILER "/usr/bin/gcc-4.8")
    set (CMAKE_CXX_COMPILER "/usr/bin/g++-4.8")
  endif()
endif()

# Set projectname (must be done AFTER setting configurationtypes)
project(Pandaria_5.4.8)

# CMP0005 (escaping of add_definitions values) and CMP0043 (per-config
# COMPILE_DEFINITIONS) were both removed in CMake 4.x, so they can no longer be
# set to OLD. Their NEW behaviour is the default under the minimum required
# above; _BUILD_DIRECTIVE is the only definition that depended on the old
# escaping, and it fails loudly at compile time in SystemConfig.h if it breaks.

# add this options before PROJECT keyword
set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

# Set RPATH-handing (CMake parameters)
set(CMAKE_SKIP_BUILD_RPATH 0)
set(CMAKE_BUILD_WITH_INSTALL_RPATH 0)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH 1)
	   
# set macro-directory
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/macros")

# build in Release-mode by default if not explicitly set
if( NOT CMAKE_BUILD_TYPE )
  set(CMAKE_BUILD_TYPE "Release")
endif()

include(CheckCXXSourceRuns)
include(CheckIncludeFiles)

# set default buildoptions and print them
include(cmake/options.cmake)

# turn off PCH totally if enabled (hidden setting, mainly for devs)
if( NOPCH )
  set(USE_COREPCH 0)
  set(USE_SCRIPTPCH 0)
endif()

include(CheckPlatform)

# basic packagesearching and setup (further support will be needed, this is a preliminary release!)
set(OPENSSL_EXPECTED_VERSION 1.0.0)
set(ACE_EXPECTED_VERSION 5.8.3)

find_package(PCHSupport)
find_package(ACE REQUIRED)
# 1.0.x, 1.1.x and 3.x are all supported: HMACSHA1 carries the shim for the
# pre-1.1.0 HMAC_CTX API, and OpenSSLCrypto loads the legacy provider that
# 3.0 moved RC4 into.
find_package(OpenSSL ${OPENSSL_EXPECTED_VERSION} REQUIRED)
find_package(Threads REQUIRED)

find_package(MySQL REQUIRED)

if( UNIX )
  find_package(Readline)
  find_package(ZLIB)
  find_package(BZip2)
endif()

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system locale filesystem thread regex serialization
    REQUIRED
)

# Find revision ID and hash of the sourcetree
include(cmake/genrev.cmake)

# print out the results before continuing
include(cmake/showoptions.cmake)

# add dependencies
add_subdirectory(dep)

# add core sources
add_subdirectory(src)
