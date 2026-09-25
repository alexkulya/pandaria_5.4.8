param(
    [string]$SourceDir = (Resolve-Path (Join-Path $PSScriptRoot '..\..')).Path,
    [string]$BuildDir = (Join-Path $SourceDir 'build'),
    [string]$InstallDir = (Join-Path $SourceDir 'server'),
    [string]$Configuration = 'RelWithDebInfo',
    [int]$Parallel = 2,
    [string]$OpenSslRoot = 'C:\libs\openssl',
    [string]$BoostRoot = 'C:\local\boost_1_84_0',
    [string]$MySqlRoot = 'C:\Program Files\MySQL\MySQL Server 8.4'
)

$ErrorActionPreference = 'Stop'

function Invoke-VsDevCmd {
    $vsDevCmd = 'C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\Tools\VsDevCmd.bat'
    if (-not (Test-Path $vsDevCmd)) {
        throw "VsDevCmd.bat not found at $vsDevCmd"
    }

    cmd /c "set Path=& set PATH=C:\Program Files\CMake\bin;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files\Git\cmd&& call ""$vsDevCmd"" -arch=x64 -host_arch=x64 >nul && set" |
        ForEach-Object {
            if ($_ -match '^([^=]+)=(.*)$') {
                [Environment]::SetEnvironmentVariable($matches[1], $matches[2], 'Process')
            }
        }
}

Invoke-VsDevCmd

$boostLibraryDir = @(
    Join-Path $BoostRoot 'stage\lib'
    Join-Path $BoostRoot 'lib64-msvc-14.3'
    Join-Path $BoostRoot 'lib64-msvc-14.2'
    Join-Path $BoostRoot 'lib64-msvc-14.1'
    Join-Path $BoostRoot 'lib64-msvc-14.0'
) -join ';'

cmake -S $SourceDir -B $BuildDir -G 'Visual Studio 17 2022' -A x64 `
    -DCMAKE_INSTALL_PREFIX="$InstallDir" `
    -DSCRIPTS=1 `
    -DTOOLS=1 `
    -DOPENSSL_ROOT_DIR="$OpenSslRoot" `
    -DBOOST_ROOT="$BoostRoot" `
    -DBOOST_LIBRARYDIR="$boostLibraryDir" `
    -DMYSQL_LIBRARY="$(Join-Path $MySqlRoot 'lib\libmysql.lib')" `
    -DMYSQL_INCLUDE_DIR="$(Join-Path $MySqlRoot 'include')"

cmake --build $BuildDir --config $Configuration --parallel $Parallel
cmake --install $BuildDir --config $Configuration

Write-Host "Installed Pandaria binaries to $InstallDir"
