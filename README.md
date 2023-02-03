
**Mists of Pandaria 5.4.8 Build 18414**

Discord link: https://discord.gg/y3zspxan7k

Client exe files" https://mega.nz/file/xUJDkIDA#I3TMdPymMw8ISNwIUgSaXLl5oHJHYFxAKyPNMXUQjgY

Compiled exe files: https://mega.nz/file/0dxU1b4I#axVg6aXsNfgQeKcglV_RLHOPV4gXB_kpd2uSP1_OTOw

Geodata (RU dbc): https://mega.nz/file/EAZUmZiD#PxdHN7jcEKCA8qaIBTIWLWLGZcT5PdsKfIgkygTZgTs

Pandaria 5.4.8 docker [(Thanks diff3)](https://github.com/diff3): https://github.com/diff3/pandaria_5.4.8_docker

## Requirements
+ Platform: Linux, Windows or Mac
+ Processor with SSE2 support
+ ACE = 7.0.0 (included for Windows) 
+ MySQL = 5.7
+ CMake ≥ 3.14 (latest stable recommended) 
+ OpenSSL = 1.x.x
+ Boost ≥ 1.70 (latest stable recommended)
+ Windows SDK version 10
+ MS Visual Studio (Community) ≥ 16.4 (2019) (Desktop) (Not previews) 
+ ### Linux
+ GCC ≥ 9 (Linux only)
+ Clang ≥ 11 (Linux only)
+ #### Build :
+ ```bash
    $ git clone https://github.com/alexkulya/pandaria_5.4.8.git
    $ cd pandaria_5.4.8 mkdir build && cd build
+ command cmake (replace XX by your clang version) :
+ ```bash
  $ cmake ../ -DCMAKE_INSTALL_PREFIX=$HOME/yourUser/folder -DCMAKE_C_COMPILER=/usr/bin/clang-XX -DCMAKE_CXX_COMPILER=/usr/bin/clang++-XX -DSCRIPTS=static
  (Replace n by the number of cores you have)
  $ make -jn
  $ make install
  (if permission denied, use sudo make install)
  ```
### Enjoy

## Copyright
License: GPL 2.0

Read file [COPYING](COPYING.md)

## Authors &amp; Contributors
Read file [THANKS](THANKS.md)
