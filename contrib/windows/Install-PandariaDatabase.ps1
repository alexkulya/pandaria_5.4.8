param(
    [string]$MySqlExe = 'C:\Program Files\MySQL\MySQL Server 8.4\bin\mysql.exe',
    [string]$HostName = '127.0.0.1',
    [int]$Port = 3307,
    [string]$AdminUser = 'root',
    [string]$AdminPassword = '',
    [string]$DbUser = 'pandaria',
    [string]$DbPassword = 'ascent',
    [string]$AuthDb = 'pandaria_auth',
    [string]$CharactersDb = 'pandaria_characters',
    [string]$WorldDb = 'pandaria_world',
    [string]$RealmName = 'Shadows of Azeroth - Pandaria',
    [string]$PublicAddress = '97.69.12.41',
    [int]$WorldPort = 8085,
    [int]$GamePort = 8086,
    [string]$WorkDir = (Join-Path $env:TEMP 'pandaria-db-import')
)

$ErrorActionPreference = 'Stop'
$repoRoot = (Resolve-Path (Join-Path $PSScriptRoot '..\..')).Path

if (-not (Test-Path $MySqlExe)) {
    throw "mysql.exe was not found at $MySqlExe"
}

function Invoke-MySql {
    param([string]$Sql, [string]$Database = '')

    $oldPwd = $env:MYSQL_PWD
    try {
        if ($AdminPassword) { $env:MYSQL_PWD = $AdminPassword } else { Remove-Item Env:\MYSQL_PWD -ErrorAction SilentlyContinue }
        $args = @('-h', $HostName, '-P', $Port, '-u', $AdminUser, '--binary-mode=1')
        if ($Database) { $args += $Database }
        $Sql | & $MySqlExe @args
        if ($LASTEXITCODE -ne 0) { throw "mysql failed for database '$Database'" }
    }
    finally {
        if ($null -ne $oldPwd) { $env:MYSQL_PWD = $oldPwd } else { Remove-Item Env:\MYSQL_PWD -ErrorAction SilentlyContinue }
    }
}

function Invoke-MySqlFile {
    param([string]$Path, [string]$Database = '')
    Write-Host "Applying $Path"
    $oldPwd = $env:MYSQL_PWD
    try {
        if ($AdminPassword) { $env:MYSQL_PWD = $AdminPassword } else { Remove-Item Env:\MYSQL_PWD -ErrorAction SilentlyContinue }
        $mysqlPath = $Path -replace '\\', '/'
        $args = @('-h', $HostName, '-P', $Port, '-u', $AdminUser, '--binary-mode=1')
        if ($Database) { $args += $Database }
        $args += @('-e', "source $mysqlPath")
        & $MySqlExe @args
        if ($LASTEXITCODE -ne 0) { throw "mysql failed while applying $Path" }
    }
    finally {
        if ($null -ne $oldPwd) { $env:MYSQL_PWD = $oldPwd } else { Remove-Item Env:\MYSQL_PWD -ErrorAction SilentlyContinue }
    }
}

function Prepare-BaseSql {
    param(
        [string]$ZipName,
        [string]$OriginalDb,
        [string]$TargetDb,
        [string]$OutputName
    )

    $zipPath = Join-Path $repoRoot "sql\base\$ZipName"
    $extractDir = Join-Path $WorkDir ([IO.Path]::GetFileNameWithoutExtension($ZipName))
    New-Item -ItemType Directory -Force -Path $extractDir | Out-Null
    Expand-Archive -LiteralPath $zipPath -DestinationPath $extractDir -Force

    $sourceSql = Get-ChildItem -Path $extractDir -File -Filter '*.sql' | Select-Object -First 1
    if (-not $sourceSql) { throw "No SQL file found inside $zipPath" }

    $targetPath = Join-Path $WorkDir $OutputName
    $text = Get-Content -LiteralPath $sourceSql.FullName -Raw
    $text = $text -replace "CREATE DATABASE /\*!32312 IF NOT EXISTS\*/ ``$OriginalDb``", "CREATE DATABASE /*!32312 IF NOT EXISTS*/ ``$TargetDb``"
    $text = $text -replace "USE ``$OriginalDb``;", "USE ``$TargetDb``;"
    [IO.File]::WriteAllText($targetPath, $text, [Text.UTF8Encoding]::new($false))
    return $targetPath
}

function Add-ColumnIfMissing {
    param([string]$Database, [string]$Table, [string]$Column, [string]$Definition)

    $safeSql = @"
SET @exists := (
  SELECT COUNT(*)
  FROM information_schema.columns
  WHERE table_schema = '$Database'
    AND table_name = '$Table'
    AND column_name = '$Column'
);
SET @ddl := IF(@exists = 0, 'ALTER TABLE $Database.$Table ADD COLUMN $Column $Definition', 'SELECT 1');
PREPARE stmt FROM @ddl;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;
"@
    Invoke-MySql -Sql $safeSql
}

Remove-Item -LiteralPath $WorkDir -Recurse -Force -ErrorAction SilentlyContinue
New-Item -ItemType Directory -Force -Path $WorkDir | Out-Null

$authBase = Prepare-BaseSql -ZipName 'auth_04_03_2023.zip' -OriginalDb 'auth' -TargetDb $AuthDb -OutputName "$AuthDb.sql"
$charsBase = Prepare-BaseSql -ZipName 'characters_29_12_2024.zip' -OriginalDb 'characters' -TargetDb $CharactersDb -OutputName "$CharactersDb.sql"
$worldBase = Prepare-BaseSql -ZipName 'world_04_03_2023.zip' -OriginalDb 'world' -TargetDb $WorldDb -OutputName "$WorldDb.sql"

Invoke-MySql -Sql "DROP DATABASE IF EXISTS $AuthDb; DROP DATABASE IF EXISTS $CharactersDb; DROP DATABASE IF EXISTS $WorldDb;"
Invoke-MySqlFile -Path $authBase
Invoke-MySqlFile -Path $charsBase
Invoke-MySqlFile -Path $worldBase

$authUpdates = Get-ChildItem -Path (Join-Path $repoRoot 'sql\updates\auth') -Recurse -File -Filter '*.sql' -ErrorAction SilentlyContinue | Sort-Object FullName
$charUpdates = @(
    Get-ChildItem -Path (Join-Path $repoRoot 'sql\old\characters') -Recurse -File -Filter '*.sql' -ErrorAction SilentlyContinue
    Get-ChildItem -Path (Join-Path $repoRoot 'sql\updates\characters') -Recurse -File -Filter '*.sql' -ErrorAction SilentlyContinue
) | Sort-Object FullName

foreach ($file in $authUpdates) { Invoke-MySqlFile -Path $file.FullName -Database $AuthDb }
foreach ($file in $charUpdates) { Invoke-MySqlFile -Path $file.FullName -Database $CharactersDb }

$oldWorldDir = Join-Path $repoRoot 'sql\old\world'
$localeRename = Join-Path $oldWorldDir '2026_08_14_01_world_locales_update.sql'
if (Test-Path $localeRename) { Invoke-MySqlFile -Path $localeRename -Database $WorldDb }

$oldWorldUpdates = Get-ChildItem -Path $oldWorldDir -File -Filter '*.sql' -ErrorAction SilentlyContinue |
    Where-Object { $_.Name -match '^\d{4}_' -and $_.FullName -ne $localeRename } |
    Sort-Object Name
foreach ($file in $oldWorldUpdates) { Invoke-MySqlFile -Path $file.FullName -Database $WorldDb }

$worldUpdates = Get-ChildItem -Path (Join-Path $repoRoot 'sql\updates\world') -Recurse -File -Filter '*.sql' -ErrorAction SilentlyContinue | Sort-Object FullName
foreach ($file in $worldUpdates) { Invoke-MySqlFile -Path $file.FullName -Database $WorldDb }

Invoke-MySql -Sql "CREATE USER IF NOT EXISTS '$DbUser'@'127.0.0.1' IDENTIFIED BY '$DbPassword'; CREATE USER IF NOT EXISTS '$DbUser'@'localhost' IDENTIFIED BY '$DbPassword'; ALTER USER '$DbUser'@'127.0.0.1' IDENTIFIED BY '$DbPassword'; ALTER USER '$DbUser'@'localhost' IDENTIFIED BY '$DbPassword'; GRANT ALL PRIVILEGES ON $AuthDb.* TO '$DbUser'@'127.0.0.1'; GRANT ALL PRIVILEGES ON $CharactersDb.* TO '$DbUser'@'127.0.0.1'; GRANT ALL PRIVILEGES ON $WorldDb.* TO '$DbUser'@'127.0.0.1'; GRANT ALL PRIVILEGES ON $AuthDb.* TO '$DbUser'@'localhost'; GRANT ALL PRIVILEGES ON $CharactersDb.* TO '$DbUser'@'localhost'; GRANT ALL PRIVILEGES ON $WorldDb.* TO '$DbUser'@'localhost'; FLUSH PRIVILEGES;"

Add-ColumnIfMissing -Database $AuthDb -Table 'account' -Column 'balans' -Definition 'int unsigned NOT NULL DEFAULT 0 AFTER sha_pass_hash'
Add-ColumnIfMissing -Database $AuthDb -Table 'account' -Column 'karma' -Definition 'int unsigned NOT NULL DEFAULT 0 AFTER balans'
Add-ColumnIfMissing -Database $AuthDb -Table 'account' -Column 'activate' -Definition 'tinyint unsigned NOT NULL DEFAULT 1 AFTER karma'
Add-ColumnIfMissing -Database $AuthDb -Table 'account' -Column 'donate' -Definition 'int unsigned NOT NULL DEFAULT 0 AFTER activate'
Add-ColumnIfMissing -Database $AuthDb -Table 'account' -Column 'invite' -Definition "varchar(32) NOT NULL DEFAULT '' AFTER recruiter"
Add-ColumnIfMissing -Database $AuthDb -Table 'realmlist' -Column 'gamePort' -Definition "int NOT NULL DEFAULT $GamePort AFTER port"
Add-ColumnIfMissing -Database $AuthDb -Table 'realmlist' -Column 'localAddress' -Definition "varchar(255) NOT NULL DEFAULT '127.0.0.1' AFTER address"
Add-ColumnIfMissing -Database $AuthDb -Table 'realmlist' -Column 'localSubnetMask' -Definition "varchar(255) NOT NULL DEFAULT '255.0.0.0' AFTER localAddress"

Invoke-MySql -Sql "UPDATE $AuthDb.realmlist SET name='$RealmName', address='$PublicAddress', localAddress='127.0.0.1', localSubnetMask='255.0.0.0', port=$WorldPort, gamePort=$GamePort, gamebuild=18414, flag=2 WHERE id=1;"

Write-Host ''
Write-Host "Pandaria databases are ready:"
Write-Host "  $AuthDb"
Write-Host "  $CharactersDb"
Write-Host "  $WorldDb"
