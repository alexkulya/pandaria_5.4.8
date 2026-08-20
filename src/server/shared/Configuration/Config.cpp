/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Config.h"
#include "Errors.h"

#include <boost/property_tree/ini_parser.hpp>

namespace
{
    // Config keys contain dots - Logger.root, Appender.Console, Rate.Health -
    // and ptree treats '.' as a path separator by default, so a plain
    // get("Logger.root") looks for a child node "Logger" holding a "root",
    // finds nothing, and every such setting silently falls back to its default.
    // read_ini stores the key verbatim, so lookups have to ask for it verbatim
    // too: a separator that cannot occur in a key turns the path back into one
    // literal name.
    boost::property_tree::ptree::path_type LiteralKey(std::string const& key)
    {
        return boost::property_tree::ptree::path_type(key, '\x01');
    }

    // Every string in the .conf files is written quoted - LogsDir = "Logs",
    // LoginDatabaseInfo = "127.0.0.1;3306;..." - and ACE_Ini_ImpExp stripped the
    // quotes while importing. read_ini keeps them, which would hand the database
    // a connection string that still has a quote at each end, and turn the empty
    // PidFile = "" into a two character file name instead of "unset".
    std::string Unquote(std::string const& value)
    {
        if (value.length() >= 2 && value.front() == '"' && value.back() == '"')
            return value.substr(1, value.length() - 2);

        return value;
    }
}

// Defined here as it must not be exposed to end-users.
//
// Section names carry no meaning to callers: the ACE version walked every
// section looking for the key and returned the first hit, so "LoginDatabaseInfo"
// resolves no matter which section holds it. Changing that would silently stop
// half the configuration from being read, so the scan is kept.
bool ConfigMgr::GetValueHelper(const char* name, std::string& result)
{
    GuardType guard(_configLock);

    if (!_loaded)
        return false;

    for (auto const& section : _config)
    {
        if (boost::optional<std::string> value = section.second.get_optional<std::string>(LiteralKey(name)))
        {
            result = *value;
            return true;
        }
    }

    return false;
}

bool ConfigMgr::LoadInitial(char const* file)
{
    ASSERT(file);

    GuardType guard(_configLock);

    _filename = file;
    _config.clear();
    _loaded = false;

    if (!LoadData(_filename.c_str()))
        return false;

    _loaded = true;
    return true;
}

bool ConfigMgr::LoadMore(char const* file)
{
    ASSERT(file);
    ASSERT(_loaded);

    GuardType guard(_configLock);

    return LoadData(file);
}

bool ConfigMgr::Reload()
{
    return LoadInitial(_filename.c_str());
}

bool ConfigMgr::LoadData(char const* file)
{
    try
    {
        // Merged rather than assigned, so LoadMore adds to what is already
        // there the way ACE_Ini_ImpExp::import_config did - the script hooks
        // in OnConfigLoad rely on it.
        boost::property_tree::ptree loaded;
        boost::property_tree::read_ini(file, loaded);

        for (auto const& section : loaded)
        {
            boost::property_tree::ptree& target = _config.count(section.first)
                ? _config.get_child(section.first)
                : _config.add_child(section.first, boost::property_tree::ptree());

            for (auto const& entry : section.second)
                target.put(LiteralKey(entry.first), Unquote(entry.second.data()));
        }

        return true;
    }
    catch (boost::property_tree::ptree_error const&)
    {
        return false;
    }
}

std::string ConfigMgr::GetStringDefault(const char* name, const std::string &def)
{
    std::string val;
    return GetValueHelper(name, val) ? val : def;
}

bool ConfigMgr::GetBoolDefault(const char* name, bool def)
{
    std::string val;

    if (!GetValueHelper(name, val))
        return def;

    return (val == "true" || val == "TRUE" || val == "yes" || val == "YES" ||
        val == "1");
}

int ConfigMgr::GetIntDefault(const char* name, int def)
{
    std::string val;
    return GetValueHelper(name, val) ? atoi(val.c_str()) : def;
}

float ConfigMgr::GetFloatDefault(const char* name, float def)
{
    std::string val;
    return GetValueHelper(name, val) ? (float)atof(val.c_str()) : def;
}

bool ConfigMgr::SetValue(char const* name, char const* value)
{
    GuardType guard(_configLock);

    if (!_loaded)
        return false;

    // Only overwrites a key that already exists, in the first section holding
    // it. ACE behaved the same: set_string_value on a section that did not have
    // the key still succeeded there, but the scan stopped at the first section
    // either way.
    for (auto& section : _config)
    {
        if (section.second.get_optional<std::string>(LiteralKey(name)))
        {
            section.second.put(LiteralKey(name), value);
            return true;
        }
    }

    return false;
}

std::string const& ConfigMgr::GetFilename()
{
    GuardType guard(_configLock);
    return _filename;
}

std::list<std::string> ConfigMgr::GetKeysByString(std::string const& name)
{
    GuardType guard(_configLock);

    std::list<std::string> keys;
    if (!_loaded)
        return keys;

    // Prefix match, not equality: the original wrote `!temp.find(name)`, which
    // is find() returning 0. Module loading depends on it.
    for (auto const& section : _config)
        for (auto const& entry : section.second)
            if (entry.first.compare(0, name.length(), name) == 0)
                keys.push_back(entry.first);

    return keys;
}
