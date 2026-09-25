param(
    [Parameter(Mandatory = $true)]
    [string]$ClientDir,

    [string]$ServerDir = (Resolve-Path (Join-Path $PSScriptRoot '..\..\server')).Path,

    [int]$Threads = 2,

    [string]$Locale = '',

    [switch]$Force
)

$ErrorActionPreference = 'Stop'

$clientPath = (Resolve-Path $ClientDir).Path
$serverPath = (Resolve-Path $ServerDir).Path
$dataPath = Join-Path $serverPath 'Data'

function Get-ClientVersion {
    param([string]$Path)

    $buildInfo = Join-Path $Path '.build.info'
    if (Test-Path $buildInfo) {
        $lines = Get-Content -LiteralPath $buildInfo | Select-Object -First 2
        if ($lines.Count -ge 2) {
            $headers = $lines[0] -split '\|' | ForEach-Object { ($_ -split '!')[0] }
            $line = $lines[1]
            $parts = $line -split '\|'
            $versionIndex = [Array]::IndexOf($headers, 'Version')
            if ($versionIndex -ge 0 -and $parts.Count -gt $versionIndex) {
                return $parts[$versionIndex]
            }
        }
    }

    $wowExe = Get-ChildItem -LiteralPath $Path -Recurse -File -Include 'Wow.exe', 'Wow-64.exe' -ErrorAction SilentlyContinue |
        Select-Object -First 1
    if ($wowExe) {
        return $wowExe.VersionInfo.ProductVersion
    }

    return ''
}

$clientVersion = Get-ClientVersion -Path $clientPath
if (-not $Force -and $clientVersion -and -not $clientVersion.StartsWith('5.4.8')) {
    throw "Client version '$clientVersion' is not WoW 5.4.8. Use a matching Pandaria 5.4.8 client, or pass -Force if you are certain."
}

foreach ($tool in @('mapextractor.exe', 'vmap4extractor.exe', 'vmap4assembler.exe', 'mmaps_generator.exe')) {
    $source = Join-Path $serverPath $tool
    if (-not (Test-Path $source)) {
        throw "$tool was not found in $serverPath. Build and install the extraction tools first."
    }
    Copy-Item -LiteralPath $source -Destination (Join-Path $clientPath $tool) -Force
}

New-Item -ItemType Directory -Force -Path $dataPath | Out-Null

$mapArgs = @('-i', $clientPath, '-o', $dataPath)
if ($Locale) {
    $mapArgs += @('-l', $Locale)
}

Write-Host 'Extracting maps, dbc/db2, cameras, and gt...'
& (Join-Path $clientPath 'mapextractor.exe') @mapArgs
if ($LASTEXITCODE -ne 0) { throw 'mapextractor failed.' }

Write-Host 'Extracting raw vmaps Buildings data...'
Push-Location $clientPath
try {
    & '.\vmap4extractor.exe'
    if ($LASTEXITCODE -ne 0) { throw 'vmap4extractor failed.' }

    Write-Host 'Assembling vmaps...'
    & '.\vmap4assembler.exe' 'Buildings' (Join-Path $dataPath 'vmaps')
    if ($LASTEXITCODE -ne 0) { throw 'vmap4assembler failed.' }
}
finally {
    Pop-Location
}

Write-Host "Generating mmaps with $Threads thread(s). This is the long CPU-heavy step."
Push-Location $dataPath
try {
    & (Join-Path $clientPath 'mmaps_generator.exe') '--threads' $Threads '--silent'
    if ($LASTEXITCODE -ne 0) { throw 'mmaps_generator failed.' }
}
finally {
    Pop-Location
}

Write-Host ''
Write-Host "Extraction complete. worldserver.conf can stay at DataDir = `"Data`"."
