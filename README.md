
**Mists of Pandaria 5.4.8 Build 18414**

Discord link: https://discord.gg/y3zspxan7k

Client exe files" https://drive.google.com/file/d/1OCrtyvRXSvxnR9EoHWYfc-2Tbm5hX3ca

Compiled exe files: https://drive.google.com/file/d/1UxdZ51hR-nqC3HAvE8_0GkP_JnFiexrE

Geodata (RU dbc): https://drive.google.com/file/d/103QiAyR5lJsfFPaEAkWqWV2HkqrV8PzN

Pandaria 5.4.8 docker [(Thanks diff3)](https://github.com/diff3): https://github.com/diff3/pandaria_5.4.8_docker

## Requirements

| | |
|---|---|
| Platform | Linux, Windows or Mac |
| Processor | SSE2 support |
| CMake | ≥ 3.5 (4.x works) |
| MySQL **client** | 5.7 or 8.0 — **required on every platform, Windows included** |
| OpenSSL | 1.0.x, 1.1.x or 3.x |
| Boost | ≥ 1.70 |
| ACE | Windows: included in `dep/acelite`, built statically. Linux: from the system (`libace-dev`) |

### MySQL

Install a MySQL client (headers and library) before building. If CMake does not find
it on its own, pass the paths:

```
-DMYSQL_LIBRARY="<path>/lib/libmysql.lib" -DMYSQL_INCLUDE_DIR="<path>/include"
```

Use a MySQL client, not a MariaDB one: MariaDB reports version 10.x, which trips the
`MYSQL_VERSION_ID >= 80000` branch in `MySQLCompat.h` and collides with its own
`my_bool` typedef.

### Linux

+ GCC ≥ 9
+ Clang ≥ 11

Verified on Ubuntu 22.04 with GCC 11, OpenSSL 3.0.2, Boost 1.74 and the MySQL 8.0 client.

```bash
git clone https://github.com/alexkulya/pandaria_5.4.8.git
cd pandaria_5.4.8 && mkdir build && cd build

cmake ../ -DCMAKE_INSTALL_PREFIX=$HOME/yourUser/folder -DSCRIPTS=1
make -j $(nproc)
make install
```

To build with clang instead, add `-DCMAKE_C_COMPILER=/usr/bin/clang-XX
-DCMAKE_CXX_COMPILER=/usr/bin/clang++-XX`, replacing XX with your version.

To also build the tools that extract data from the MoP client, add `-DTOOLS=1`. Under
clang that needs `-DCMAKE_CXX_FLAGS=-pthread` as well.

### Windows

+ Windows SDK 10
+ MS Visual Studio (Community) ≥ 16.4 (2019), Desktop workload, no previews

Verified with the **v142** toolset, OpenSSL 3.5.2, Boost 1.74 (msvc-14.2) and MySQL
Connector/C 6.1.11. Newer Visual Studio installs usually still carry v142 as an
optional component; select it with `-T v142`.

Replace the generator name below with the Visual Studio you actually have installed
(`cmake --help` lists the ones it recognises); `-T v142` selects the toolset and is
independent of it.

```
cmake -S . -B build -G "Visual Studio 16 2019" -A x64 -T v142 ^
  -DOPENSSL_ROOT_DIR="<path>\openssl" ^
  -DBOOST_ROOT="<path>\boost_1_74_0" ^
  -DBOOST_LIBRARYDIR="<path>\boost_1_74_0\lib64-msvc-14.2" ^
  -DMYSQL_LIBRARY="<path>\lib\libmysql.lib" ^
  -DMYSQL_INCLUDE_DIR="<path>\include"

cmake --build build --config Release --parallel
```

`BOOST_LIBRARYDIR` is not optional: Boost's headers auto-link libraries such as
`date_time` through `#pragma comment(lib, ...)`, which emits a bare file name that the
linker can only resolve if the directory is on its search path.

If msys2 or another MinGW toolchain is installed, keep CMake away from its libraries
with `-DCMAKE_IGNORE_PREFIX_PATH="<msys>/ucrt64;<msys>/mingw64"`. They will be found
first otherwise, and MinGW binaries do not link with MSVC.

Copy `libcrypto-*.dll`, `libssl-*.dll` and `libmysql.dll` next to the built
executables before running them. With OpenSSL 3.x also copy `legacy.dll`, which is
where RC4 lives from 3.0 on — the worldserver aborts at startup with a message naming
it if it cannot be loaded.

  

### Enjoy

## Copyright
License: GPL 2.0

Read file [COPYING](COPYING.md)

## Authors &amp; Contributors
Read file [THANKS](THANKS.md)
