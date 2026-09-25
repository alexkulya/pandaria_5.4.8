param(
    [string]$RepoDir = (Resolve-Path (Join-Path $PSScriptRoot '..\..')).Path,
    [string]$MySqlExe = 'C:\Program Files\MySQL\MySQL Server 8.4\bin\mysql.exe',
    [string]$DbHost = '127.0.0.1',
    [int]$DbPort = 3307,
    [string]$DbUser = 'pandaria',
    [string]$DbPassword = 'ascent',
    [string]$AuthDb = 'pandaria_auth',
    [string]$CharactersDb = 'pandaria_characters',
    [string]$WorldDb = 'pandaria_world',
    [int]$AuthPort = 1119,
    [int]$WorldPort = 8085,
    [switch]$WarnOnly
)

$ErrorActionPreference = 'Stop'
$serverDir = Join-Path $RepoDir 'server'
$dataDir = Join-Path $serverDir 'Data'
$failures = New-Object System.Collections.Generic.List[string]

function Add-Failure {
    param([string]$Message)
    $script:failures.Add($Message) | Out-Null
    Write-Host "[FAIL] $Message" -ForegroundColor Red
}

function Add-Ok {
    param([string]$Message)
    Write-Host "[ OK ] $Message" -ForegroundColor Green
}

function Test-FilePresent {
    param([string]$Path, [string]$Label)
    if (Test-Path $Path) { Add-Ok "$Label found" } else { Add-Failure "$Label missing: $Path" }
}

function Test-ConfigContains {
    param([string]$Path, [string]$Pattern, [string]$Label)
    if ((Test-Path $Path) -and (Select-String -LiteralPath $Path -Pattern $Pattern -Quiet)) {
        Add-Ok $Label
    }
    else {
        Add-Failure "$Label not found in $Path"
    }
}

Test-FilePresent -Path (Join-Path $serverDir 'authserver.exe') -Label 'authserver.exe'
Test-FilePresent -Path (Join-Path $serverDir 'worldserver.exe') -Label 'worldserver.exe'
Test-FilePresent -Path (Join-Path $serverDir 'libmysql.dll') -Label 'libmysql.dll'
Test-FilePresent -Path (Join-Path $serverDir 'libssl-3-x64.dll') -Label 'OpenSSL libssl'
Test-FilePresent -Path (Join-Path $serverDir 'libcrypto-3-x64.dll') -Label 'OpenSSL libcrypto'

$authConf = Join-Path $serverDir 'authserver.conf'
$worldConf = Join-Path $serverDir 'worldserver.conf'
Test-ConfigContains -Path $authConf -Pattern "RealmServerPort\s*=\s*$AuthPort" -Label "authserver port is $AuthPort"
Test-ConfigContains -Path $authConf -Pattern "$DbHost;$DbPort;$DbUser;$DbPassword;$AuthDb" -Label 'auth DB connection is Pandaria'
Test-ConfigContains -Path $worldConf -Pattern 'DataDir\s*=\s*"Data"' -Label 'worldserver DataDir is Data'
Test-ConfigContains -Path $worldConf -Pattern "$DbHost;$DbPort;$DbUser;$DbPassword;$AuthDb" -Label 'world auth DB connection is Pandaria'
Test-ConfigContains -Path $worldConf -Pattern "$DbHost;$DbPort;$DbUser;$DbPassword;$WorldDb" -Label 'world DB connection is Pandaria'
Test-ConfigContains -Path $worldConf -Pattern "$DbHost;$DbPort;$DbUser;$DbPassword;$CharactersDb" -Label 'characters DB connection is Pandaria'
Test-ConfigContains -Path $worldConf -Pattern "WorldServerPort\s*=\s*$WorldPort" -Label "worldserver port is $WorldPort"

foreach ($folder in @('maps', 'vmaps', 'mmaps')) {
    $path = Join-Path $dataDir $folder
    if (-not (Test-Path $path)) {
        Add-Failure "data folder missing: $path"
        continue
    }
    $count = (Get-ChildItem -LiteralPath $path -File -ErrorAction SilentlyContinue | Measure-Object).Count
    if ($count -gt 0) {
        Add-Ok "$folder has $count file(s)"
    }
    else {
        Add-Failure "$folder exists but is empty: $path"
    }
}

if (Test-Path $MySqlExe) {
    $oldPwd = $env:MYSQL_PWD
    try {
        $env:MYSQL_PWD = $DbPassword
        $sql = "SELECT COUNT(*) FROM $WorldDb.creature_template; SELECT COUNT(*) FROM $CharactersDb.characters; SELECT id,name,address,port,gamePort,gamebuild FROM $AuthDb.realmlist ORDER BY id LIMIT 1;"
        $output = & $MySqlExe -h $DbHost -P $DbPort -u $DbUser -N -B -e $sql
        if ($LASTEXITCODE -eq 0 -and $output) {
            Add-Ok 'Pandaria DB login/query works'
            $output | ForEach-Object { Write-Host "       $_" }
        }
        else {
            Add-Failure 'Pandaria DB login/query failed'
        }
    }
    finally {
        if ($null -ne $oldPwd) { $env:MYSQL_PWD = $oldPwd } else { Remove-Item Env:\MYSQL_PWD -ErrorAction SilentlyContinue }
    }
}
else {
    Add-Failure "mysql.exe missing: $MySqlExe"
}

Write-Host ''
if ($failures.Count -eq 0) {
    Write-Host 'Pandaria is ready for cutover.' -ForegroundColor Green
    exit 0
}

Write-Host "Pandaria is not ready: $($failures.Count) issue(s)." -ForegroundColor Red
if ($WarnOnly) { exit 0 }
exit 1
