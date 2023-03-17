#include "Utilities/Util.h"
#include "Configuration/Config.h"
#include "DatabaseEnv.h"
#include <signal.h>
#include <utf8.h>
#include <mysql.h>
#include <errmsg.h>
#include <fstream>
#include <memory>
#include <iostream>
#include "AppenderDB.h"

void AppenderDB::_write(LogMessage const&) { }

static bool CreateDir(std::string const& path)
{
#ifdef _WIN32
    if (!CreateDirectory(path.c_str(), nullptr))
        return GetLastError() == ERROR_ALREADY_EXISTS;
#else
    if (mkdir(path.c_str(), 0755) != 0)
        return errno == EEXIST;
#endif
    return true;
}

#ifdef _WIN32
static std::string ConvertForConsole(std::string const& what)
{
    std::wstring wstr;
    if (!Utf8toWStr(what, wstr))
        return what;

    char temp_buf[32 * 1024];
    temp_buf[wstr.length()] = 0;
    CharToOemBuffW(wstr.c_str(), &temp_buf[0], DWORD(wstr.length()));
    return temp_buf;
}
#else
static std::string const& ConvertForConsole(std::string const& what)
{
    return what;
}
#endif

static void GetFiles(std::vector<std::string>& out, std::string const& directory)
{
#ifdef _WIN32
    HANDLE dir;
    WIN32_FIND_DATA file_data;

    if ((dir = FindFirstFile((directory + "/*").c_str(), &file_data)) == INVALID_HANDLE_VALUE)
        return; /* No files found */

    do
    {
        std::string file_name = file_data.cFileName;
        std::string full_file_name = directory + file_name;

        if ((file_data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
            continue;

        if (file_name[0] == '.')
            continue;

        out.push_back(full_file_name);
    } while (FindNextFile(dir, &file_data));

    FindClose(dir);
#else
    DIR *dir;
    struct dirent *ent;
    struct stat st;

    dir = opendir(directory.c_str());
    if (!dir)
        throw Exception(Format("Can't open directory \"%s\", errno: %u", directory.c_str(), errno));
    while ((ent = readdir(dir)) != NULL) {
        std::string file_name = ent->d_name;
        std::string full_file_name = directory + "/" + file_name;

        if (file_name[0] == '.')
            continue;

        if (stat(full_file_name.c_str(), &st) == -1)
            continue;

        if ((st.st_mode & S_IFDIR) != 0)
            continue;

        out.push_back(full_file_name);
    }
    closedir(dir);
#endif
}

class SQLConnection
{
public:
    SQLConnection(MySQLConnectionInfo const& info)
        : _info(info), _conn(nullptr)
    {
        if (!Open())
            throw Exception("Coudn't connect to database: " + info.database);
    }

    ~SQLConnection()
    {
        if (_conn)
            mysql_close(_conn);
    }

    bool Open()
    {
        MYSQL* init = mysql_init(nullptr);
        int port = strtol(_info.port_or_socket.c_str(), nullptr, 10);
        _conn = mysql_real_connect(init, _info.host.c_str(), _info.user.c_str(), _info.password.c_str(), _info.database.c_str(), port, 0, 0);
        if (!_conn)
        {
            mysql_close(init);
            return false;
        }
        mysql_autocommit(_conn, 1);
        mysql_set_character_set(_conn, "utf8");
        return true;
    }

    void Execute(char const* sql)
    {
        if (mysql_query(_conn, sql) != 0)
        {
            auto err = mysql_errno(_conn);
            switch (err)
            {
                case CR_SERVER_GONE_ERROR:
                case CR_SERVER_LOST:
                case CR_INVALID_CONN_HANDLE:
                case CR_SERVER_LOST_EXTENDED:
                    if (!Open())
                        throw Exception("Connection to database " + _info.database + " was lost, reconnect failed");
                    break;
                default:
                    throw Exception(GetErrorString());
            }
        }
    }

    std::shared_ptr<ResultSet> Query(char const* sql)
    {
        Execute(sql);

        MYSQL_RES* result = nullptr;
        MYSQL_FIELD* fields = nullptr;
        uint64 rowCount = 0;
        uint32 fieldCount = 0;

        result = mysql_store_result(_conn);
        if (!result)
            return nullptr;

        rowCount = mysql_affected_rows(_conn);
        if (!rowCount)
        {
            mysql_free_result(result);
            return nullptr;
        }

        fieldCount = mysql_field_count(_conn);
        fields = mysql_fetch_fields(result);
        return std::make_shared<ResultSet>(result, fields, rowCount, fieldCount);
    }

    void BeginTransaction()
    {
        Execute("START TRANSACTION");
    }

    void CommitTransaction()
    {
        Execute("COMMIT");
    }

    void RollbackTransaction()
    {
        Execute("ROLLBACK");
    }

    std::string GetErrorString() const
    {
        return Format("Error %u:\n%s", mysql_errno(_conn), mysql_error(_conn));
    }

    uint32 RowsAffected() const
    {
        return mysql_affected_rows(_conn);
    }

    void EscapeString(std::string& str)
    {
        char* buff = new char[str.size() * 2 + 1];
        mysql_real_escape_string(_conn, buff, str.c_str(), str.length());
        str.assign(buff);
        delete buff;
    }

private:
    MYSQL* _conn;
    MySQLConnectionInfo _info;
};

class App
{
    struct SqlFile
    {
        uint32 Revision;
        std::string Name;
        std::string FullName;
        std::string DBName;
    };

public:
    App(int argc, char** argv);

    ~App()
    {
        CloseDatabases();
    }

    int Run();

private:
    void LoadConfig();
    void OpenDatabases();
    void CloseDatabases();
    void Report(std::string const& str);
    void GetQueriesFromFile(std::vector<std::string>& dest, SqlFile const& file);
    void UpdateSql();

private:
    std::string _configFile;

    std::list<SqlFile> _sqlUpdates;
    std::set<std::string> _executed;

    std::shared_ptr<SQLConnection> _charConn;
    std::shared_ptr<SQLConnection> _loginConn;
    std::shared_ptr<SQLConnection> _worldConn;
    std::shared_ptr<SQLConnection> _archiveConn;

    std::string _query;
    std::ofstream _log;
};

App::App(int argc, char** argv)
{
    _configFile = "updater.conf";
    int32 i = 0;
    while (i < argc)
    {
        if (::strcmp(argv[i], "-c") == 0)
        {
            if (++i >= argc)
            {
                std::cout << "Usage: updater [-c <path_to_config>]" << std::endl;
                exit(-1);
            }
            _configFile = argv[i];
        }
        ++i;
    }
}

int App::Run()
{
    try
    {
        LoadConfig();
        UpdateSql();
    }
    catch (Exception const& e)
    {
        Report(e.what());
        return 1;
    }
    return 0;
}

void App::CloseDatabases()
{
    _charConn.reset();
    _worldConn.reset();
    _loginConn.reset();
    _archiveConn.reset();
}

void App::LoadConfig()
{
    if (!sConfigMgr->LoadInitial(_configFile.c_str()))
    {
        bool found = false;
        // Try to find.
        for (auto&& iter : { "./updater.conf", "../etc/updater.conf", "/etc/updater.conf" })
        {
            if (sConfigMgr->LoadInitial(iter))
            {
                found = true;
                break;
            }
        }

        if (!found)
            throw Exception("Can't open file: " + _configFile);
    }

    std::string logsDir = sConfigMgr->GetStringDefault("LogsDir", "");
    if (!logsDir.empty())
    {
        if (!CreateDir(logsDir))
            throw Exception(Format("Can't create log directory, errno %u", errno));
    }

    std::string logFile;
    if (!logsDir.empty())
        logsDir += "/";

    logFile = logsDir + sConfigMgr->GetStringDefault("Log.Main.File", "build.log");

    if (sConfigMgr->GetBoolDefault("Log.Main.Timestamp", false))
    {
        std::string::size_type extPos = logFile.find_last_of(".");
        if (extPos == std::string::npos)
            extPos = logFile.length();
        logFile.insert(extPos, TimeStr(time(nullptr), "_%d-%m-%y_%H-%M-%S"));
    }

    if (!logFile.empty())
    {
        _log.open(logFile, std::fstream::trunc | std::fstream::out);
        if (!_log.is_open())
            throw Exception(Format("Can't create log file, error: %u", errno));
    }
}

void App::OpenDatabases()
{
    std::string dbstr = sConfigMgr->GetStringDefault("CharacterDatabaseInfo", "");
    _charConn.reset(new SQLConnection(MySQLConnectionInfo{ dbstr }));
    dbstr = sConfigMgr->GetStringDefault("WorldDatabaseInfo", "");
    _worldConn.reset(new SQLConnection(MySQLConnectionInfo{ dbstr }));
    dbstr = sConfigMgr->GetStringDefault("LoginDatabaseInfo", "");
    _loginConn.reset(new SQLConnection(MySQLConnectionInfo{ dbstr }));
}

void App::Report(std::string const& msg)
{
    std::cout << ConvertForConsole(msg) << std::endl;
    _log << msg << std::endl;
}

void App::GetQueriesFromFile(std::vector<std::string>& dest, SqlFile const& file)
{
    dest.clear();

    std::ifstream f(file.FullName);
    if (!f.is_open())
        throw Exception("Can't open sql file: \"" + file.FullName + "\"");

    std::string sql((std::istreambuf_iterator<char>(f)),
        std::istreambuf_iterator<char>());

    char quote = 0;
    bool escape = false;
    bool oneLineComment = false;
    bool manyLineComment = false;

    char const* str = sql.c_str();
    char const* begin = str;
    char ch;

    do
    {
        ch = *str;
        ++str;

        if (escape)
        {
            escape = false;
        }
        else if (oneLineComment)
        {
            if (ch == '\n')
                oneLineComment = false;
        }
        else if (manyLineComment)
        {
            if (ch == '*' && *str == '/')
            {
                ++str;
                manyLineComment = false;
            }
        }
        else
        {
            switch (ch)
            {
                case '\'':
                    if (!quote)
                        quote = ch;
                    else if (quote == ch)
                        quote = 0;
                    break;
                case '\"':
                    if (!quote)
                        quote = ch;
                    else if (quote == ch)
                        quote = 0;
                    break;
                case '\\':
                    if (quote)
                        escape = true;
                    break;
                case ';':
                case '\0':
                    if (quote)
                        break;
                    _query.assign(begin, str - 1);
                    begin = str;
                    if (_query.empty() || _query.find_first_not_of(" \r\n\t") == std::string::npos)
                        break;
                    if (!utf8::is_valid(_query.begin(), _query.end()))
                        throw Exception("Invalid file encoding: \"" + file.FullName + "\"");
                    dest.push_back(_query.c_str());
                    break;
                case '-':
                    if (!quote && *str == '-')
                    {
                        ++str;
                        oneLineComment = true;
                    }
                    break;
                case '#':
                    if (!quote)
                        oneLineComment = true;
                    break;
                case '/':
                    if (!quote && *str == '*')
                        manyLineComment = true;
                    break;
                default:
                    break;
            }
        }

    } while (ch);
}

void App::UpdateSql()
{
    std::string dir = sConfigMgr->GetStringDefault("SqlPath", "");
    int32 realmid = sConfigMgr->GetIntDefault("RealmID", 0);
    if (realmid <= 0)
        throw Exception("\"RealmID\" is not specified in the config");

    std::vector<std::string> files;
    GetFiles(files, dir);

    OpenDatabases();
    Report("Connection to database opened.");

    std::string file;

    auto res = _loginConn->Query(Format("SELECT file FROM sql_update WHERE realmid = '%i' or realmid = -1", realmid).c_str());
    if (res)
    {
        do
        {
            _executed.insert((*res)[0].GetString());
        } while (res->NextRow());
    }

    for (auto&& iter : files)
    {
        file = iter;
        std::string::size_type pos = file.rfind('.');
        if (pos == file.npos)
        {
            Report("File without extension: \"" + iter + "\". Skipped.");
            continue;
        }

        if (::strncmp(&file[pos + 1], "sql", 3) != 0)
        {
            Report("File with incorrect extension: \"" + iter + "\". Skipped.");
            continue;
        }

        std::string::size_type sep = file.find_last_of("\\/");
        if (sep != file.npos)
            file.assign(&iter[sep + 1], &iter[pos]);

        if (_executed.find(file) != _executed.end())
            continue;

        pos = file.find('_');
        if (pos == file.npos)
        {
            Report("Revision number not found: \"" + iter + "\". Skipped.");
            continue;
        }

        char* end;
        uint32 curr = ::strtoul(file.c_str(), &end, 10);
        if (!curr || end != &file[pos] || errno == ERANGE)
        {
            if (file != "rev_database_table")
                Report("Revision number not found: \"" + iter + "\". Skipped.");
            continue;
        }

        std::string::size_type pos2 = file.find('_', pos + 1);
        if (pos2 == file.npos)
        {
            char const* str = &file[pos + 1];
            while (isalpha(*str))
                ++str;
            if (*str != '\0')
                Report("Database name not found: \"" + iter + "\". Skipped.");
            continue;
        }

        std::string dbname(&file[pos + 1], &file[pos2]);
        bool valid = dbname == "characters"
            || dbname == "world"
            || dbname == "auth";
            // || dbname == "conserve";
        if (!valid)
        {
            Report("Incorrect database name: \"" + iter + "\". Skipped.");
            continue;
        }

        _sqlUpdates.push_back({ curr, file, iter, dbname });
    }

    _sqlUpdates.sort([](SqlFile const& lhs, SqlFile const& rhs)
    {
        return lhs.Revision < rhs.Revision;
    });

    if (_sqlUpdates.empty())
    {
        Report("No one sql file found.");
        return;
    }

    std::size_t num = _sqlUpdates.size();

    Report(Format("Found %u sql files to execute.", num));


    std::string query;
    std::vector<std::string> queries;

    Report("");
    Report("======================================\n");

    std::string str;
    std::string result;
    while (!_sqlUpdates.empty())
    {
        auto sfile = _sqlUpdates.front();

        SQLConnection* conn = nullptr;
        int32 realm = realmid;
        if (sfile.DBName == "world")
            conn = _worldConn.get();
        else if (sfile.DBName == "characters")
            conn = _charConn.get();
        else if (sfile.DBName == "auth")
        {
            conn = _loginConn.get();
            realm = -1;
        }
        /*else if (sfile.DBName == "conserve")
        {
            conn = _archiveConn.get();
            realm = -1;
        }*/
        else
            throw Exception();

        conn->BeginTransaction();

        Report(sfile.Name + "\n");

        try
        {
            GetQueriesFromFile(queries, sfile);

            for (auto&& iter : queries)
            {
                conn->Execute(iter.c_str());
                str = Format("OK. %u row(s) affected\n", conn->RowsAffected());
                result += str;
                Report(str);
            }

            conn->CommitTransaction();
            file = sfile.Name;
            _loginConn->EscapeString(file);
            _loginConn->EscapeString(result);
            str = "INSERT into `sql_update` (`file`, `date`, `result`, `realmid`) VALUES ('" + file + "', TIMESTAMP(NOW()), '" + result + "', " + std::to_string(realm) + ")";
            result.clear();
            _loginConn->Execute(str.c_str());
            Report("======================================\n");
        }
        catch (Exception const& e)
        {
            conn->RollbackTransaction();
            throw Exception(Format("Error durung execution \"%s\": %s", sfile.Name.c_str(), e.what()));
        }
        _sqlUpdates.erase(_sqlUpdates.begin());
    }
    Report(Format("%u files executed!", num));
    CloseDatabases();
    Report("Connection to database closed.");
}

#undef main

int main(int argc, char** argv)
{
    App app(argc, argv);
    int code = app.Run();

#ifdef _WIN32
    std::cout << "Press enter for exit..." << std::endl;
    std::cin.get();
#endif

    return code;
}
