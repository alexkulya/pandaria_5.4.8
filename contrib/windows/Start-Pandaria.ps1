param(
    [string]$ServerDir = (Resolve-Path (Join-Path $PSScriptRoot '..\..\server')).Path,
    [int]$AuthPort = 3724,
    [int]$WorldPort = 8085
)

$ErrorActionPreference = 'Stop'
Set-Location $ServerDir

function Start-CoreProcess {
    param(
        [string]$Exe,
        [int]$Port,
        [string]$Label,
        [int]$TimeoutSec
    )

    $fullPath = Join-Path $ServerDir $Exe
    if (-not (Test-Path $fullPath)) {
        throw "$Label executable not found at $fullPath"
    }

    $running = Get-CimInstance Win32_Process -Filter "Name = '$Exe'" |
        Where-Object {
            $_.ExecutablePath -and
            [System.IO.Path]::GetFullPath($_.ExecutablePath) -eq [System.IO.Path]::GetFullPath($fullPath)
        } |
        Select-Object -First 1

    if ($running) {
        Write-Host "$Label already running (PID $($running.ProcessId))."
    }
    else {
        Start-Process -FilePath $fullPath -WorkingDirectory $ServerDir | Out-Null
        Write-Host "$Label started."
    }

    $deadline = (Get-Date).AddSeconds($TimeoutSec)
    while ((Get-Date) -lt $deadline) {
        $listening = Get-NetTCPConnection -State Listen -ErrorAction SilentlyContinue |
            Where-Object { $_.LocalPort -eq $Port } |
            Select-Object -First 1
        if ($listening) {
            Write-Host "$Label listening on port $Port."
            return
        }
        Start-Sleep -Seconds 2
    }

    Write-Warning "$Label did not open port $Port in $TimeoutSec seconds. Check Logs\Server.log, Logs\Auth.log, and Crashes\."
}

if (-not (Test-Path (Join-Path $ServerDir 'authserver.conf'))) {
    Copy-Item (Join-Path $ServerDir 'authserver.conf.dist') (Join-Path $ServerDir 'authserver.conf')
}

if (-not (Test-Path (Join-Path $ServerDir 'worldserver.conf'))) {
    Copy-Item (Join-Path $ServerDir 'worldserver.conf.dist') (Join-Path $ServerDir 'worldserver.conf')
}

New-Item -ItemType Directory -Force -Path (Join-Path $ServerDir 'Logs') | Out-Null

Start-CoreProcess -Exe 'authserver.exe' -Port $AuthPort -Label 'authserver' -TimeoutSec 40
Start-CoreProcess -Exe 'worldserver.exe' -Port $WorldPort -Label 'worldserver' -TimeoutSec 420

Write-Host ''
Write-Host 'Pandaria state:'
Write-Host "  Auth  -> 0.0.0.0:$AuthPort"
Write-Host "  World -> 0.0.0.0:$WorldPort"
Write-Host ''
Write-Host 'Before exposing the realm, verify auth.realmlist address/localAddress for the target machine.'
