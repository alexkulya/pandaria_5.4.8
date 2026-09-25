# Windows bring-up notes

These notes mirror the local Legion workflow used for TLFrontier, adapted for
Pandaria 5.4.8.

## Build

Use the helper with a low parallel count so the machine stays usable:

```powershell
.\contrib\windows\Build-Pandaria.ps1 -Parallel 2
```

The script expects the same local dependency layout used by the Legion build:

- Visual Studio 2022 Community
- OpenSSL in `C:\libs\openssl`
- Boost in `C:\local\boost_1_84_0`
- MySQL client in `C:\Program Files\MySQL\MySQL Server 8.4`

It configures `RelWithDebInfo`, builds the core and extraction tools, then
installs the runnable files into `server\`.

## First run in the target machine

Copy or generate the client data folders next to `worldserver.exe`:

- `Data\dbc`
- `Data\maps`
- `Data\vmaps`
- `Data\mmaps`

Copy the configs if needed and edit the database credentials:

```powershell
Copy-Item .\server\authserver.conf.dist .\server\authserver.conf
Copy-Item .\server\worldserver.conf.dist .\server\worldserver.conf
```

Important values:

- `LoginDatabaseInfo`, `WorldDatabaseInfo`, `CharacterDatabaseInfo`
- `DataDir = "Data"`
- `RealmServerPort = 3724`
- `WorldServerPort = 8085`

Start the realm:

```powershell
.\contrib\windows\Start-Pandaria.ps1
```

If the client is not on the same machine, update `auth.realmlist` so `address`
and `localAddress` match the target network. A client on another PC cannot use
`127.0.0.1`.

For clean DB error checks, set file appenders to write mode while diagnosing,
for example `Appender.DBErrors=2,2,0,DBErrors.log,w`.
