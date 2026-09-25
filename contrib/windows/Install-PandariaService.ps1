param(
    [string]$RepoDir = (Resolve-Path (Join-Path $PSScriptRoot '..\..')).Path,
    [string]$ServerDir = (Resolve-Path (Join-Path $PSScriptRoot '..\..\server')).Path,
    [string]$WinSWPath,
    [string]$ServiceName = 'TLF-Pandaria',
    [string]$DisplayName = 'TLF Pandaria WoW Server',
    [int]$AuthPort = 1119,
    [int]$WorldPort = 8085
)

$ErrorActionPreference = 'Stop'

if (-not $WinSWPath) {
    $candidates = @(
        'F:\hosting\backup\mcpanel\node-agent\node_modules\node-windows\bin\winsw\winsw.exe',
        'F:\hosting\backup\mcpanel\node-agent\node-agent\node_modules\node-windows\bin\winsw\winsw.exe',
        'C:\Users\yos\Desktop\hosting\backup\mcpanel\node-agent\node_modules\node-windows\bin\winsw\winsw.exe',
        'C:\Users\yos\Desktop\hosting\backup\mcpanel\node-agent\node-agent\node_modules\node-windows\bin\winsw\winsw.exe'
    )
    $WinSWPath = $candidates | Where-Object { Test-Path $_ } | Select-Object -First 1
}

if (-not $WinSWPath -or -not (Test-Path $WinSWPath)) {
    throw 'WinSW was not found. Pass -WinSWPath with the path to winsw.exe.'
}

$serviceExe = Join-Path $ServerDir "$ServiceName.exe"
$serviceExeConfig = "$serviceExe.config"
$serviceXml = Join-Path $ServerDir "$ServiceName.xml"
$serviceLogDir = Join-Path $ServerDir 'Logs\Service'
$serviceScript = Join-Path $RepoDir 'contrib\windows\Pandaria-Service.ps1'

New-Item -ItemType Directory -Force -Path $serviceLogDir | Out-Null
Copy-Item -LiteralPath $WinSWPath -Destination $serviceExe -Force
$winSWConfig = "$WinSWPath.config"
if (Test-Path $winSWConfig) {
    Copy-Item -LiteralPath $winSWConfig -Destination $serviceExeConfig -Force
}

$escapedScript = [System.Security.SecurityElement]::Escape($serviceScript)
$escapedServerDir = [System.Security.SecurityElement]::Escape($ServerDir)
$escapedLogDir = [System.Security.SecurityElement]::Escape($serviceLogDir)
$xml = @"
<service>
  <id>$ServiceName</id>
  <name>$DisplayName</name>
  <description>Keeps Pandaria authserver and worldserver online after reboot.</description>
  <executable>powershell.exe</executable>
  <arguments>-NoProfile -ExecutionPolicy Bypass -File "$escapedScript" -ServerDir "$escapedServerDir" -AuthPort $AuthPort -WorldPort $WorldPort</arguments>
  <workingdirectory>$escapedServerDir</workingdirectory>
  <startmode>Automatic</startmode>
  <delayedAutoStart>true</delayedAutoStart>
  <stoptimeout>30 sec</stoptimeout>
  <stopparentprocessfirst>false</stopparentprocessfirst>
  <logpath>$escapedLogDir</logpath>
  <log mode="roll-by-size">
    <sizeThreshold>10485760</sizeThreshold>
    <keepFiles>5</keepFiles>
  </log>
  <onfailure action="restart" delay="10 sec" />
  <onfailure action="restart" delay="30 sec" />
  <onfailure action="restart" delay="60 sec" />
</service>
"@

Set-Content -LiteralPath $serviceXml -Value $xml -Encoding UTF8

$existing = Get-CimInstance Win32_Service -Filter "Name='$ServiceName'" -ErrorAction SilentlyContinue
if ($existing) {
    & $serviceExe stop
    & $serviceExe uninstall
}

& $serviceExe install
Set-Service -Name $ServiceName -StartupType Automatic
& $serviceExe start

Get-CimInstance Win32_Service -Filter "Name='$ServiceName'" |
    Select-Object Name,DisplayName,State,StartMode,PathName
