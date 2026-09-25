param(
    [string]$ServerDir = (Resolve-Path (Join-Path $PSScriptRoot '..\..\server')).Path,
    [int]$AuthPort = 1119,
    [int]$WorldPort = 8085,
    [int]$CheckIntervalSec = 30
)

$ErrorActionPreference = 'Stop'

function Get-CoreProcess {
    param([string]$Exe)

    $fullPath = [System.IO.Path]::GetFullPath((Join-Path $ServerDir $Exe))
    Get-CimInstance Win32_Process -Filter "Name = '$Exe'" |
        Where-Object {
            $_.ExecutablePath -and
            [System.IO.Path]::GetFullPath($_.ExecutablePath) -eq $fullPath
        } |
        Select-Object -First 1
}

function Test-PortListening {
    param([int]$Port)

    [bool](Get-NetTCPConnection -State Listen -ErrorAction SilentlyContinue |
        Where-Object { $_.LocalPort -eq $Port } |
        Select-Object -First 1)
}

function Ensure-CoreProcess {
    param(
        [string]$Exe,
        [string]$Label,
        [int]$Port
    )

    $running = Get-CoreProcess -Exe $Exe
    if ($running) {
        return
    }

    $fullPath = Join-Path $ServerDir $Exe
    if (-not (Test-Path $fullPath)) {
        throw "$Label executable not found at $fullPath"
    }

    Start-Process -FilePath $fullPath -WorkingDirectory $ServerDir -WindowStyle Hidden | Out-Null
    Write-Host "$(Get-Date -Format o) Started $Label."
}

function Stop-CoreProcess {
    param([string]$Exe)

    $running = Get-CoreProcess -Exe $Exe
    if ($running) {
        Stop-Process -Id $running.ProcessId -Force -ErrorAction SilentlyContinue
    }
}

Set-Location $ServerDir
New-Item -ItemType Directory -Force -Path (Join-Path $ServerDir 'Logs') | Out-Null

try {
    while ($true) {
        Ensure-CoreProcess -Exe 'authserver.exe' -Label 'authserver' -Port $AuthPort
        Ensure-CoreProcess -Exe 'worldserver.exe' -Label 'worldserver' -Port $WorldPort
        Start-Sleep -Seconds $CheckIntervalSec
    }
}
finally {
    Stop-CoreProcess -Exe 'worldserver.exe'
    Stop-CoreProcess -Exe 'authserver.exe'
}
