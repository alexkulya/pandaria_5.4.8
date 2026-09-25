param(
    [string]$LegionServerDir = 'F:\WOWLegion\LegionTLF-server',
    [string]$PandariaRepoDir = (Resolve-Path (Join-Path $PSScriptRoot '..\..')).Path,
    [int]$AuthPort = 1119,
    [int]$WorldPort = 8085
)

$ErrorActionPreference = 'Stop'

$legionPath = [System.IO.Path]::GetFullPath($LegionServerDir)
$readiness = Join-Path $PandariaRepoDir 'contrib\windows\Test-PandariaReadiness.ps1'
& $readiness -RepoDir $PandariaRepoDir -AuthPort $AuthPort -WorldPort $WorldPort
if ($LASTEXITCODE -ne 0) { throw 'Pandaria readiness check failed. Legion was not stopped.' }

Get-CimInstance Win32_Process |
    Where-Object {
        $_.Name -in @('bnetserver.exe', 'authserver.exe', 'worldserver.exe') -and
        $_.ExecutablePath -and
        [System.IO.Path]::GetFullPath((Split-Path $_.ExecutablePath -Parent)) -eq $legionPath
    } |
    ForEach-Object {
        Write-Host "Stopping Legion $($_.Name) PID $($_.ProcessId)"
        Stop-Process -Id $_.ProcessId -Force
    }

& (Join-Path $PandariaRepoDir 'contrib\windows\Start-Pandaria.ps1') `
    -ServerDir (Join-Path $PandariaRepoDir 'server') `
    -AuthPort $AuthPort `
    -WorldPort $WorldPort
