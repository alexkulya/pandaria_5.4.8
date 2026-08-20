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

#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <memory>
#include <list>
#include <mutex>
#include "Singleton.h"

#include <boost/property_tree/ptree.hpp>

class ConfigMgr
{
    friend class Trinity::Singleton<ConfigMgr>;
    friend class ConfigLoader;

    ConfigMgr() { }
    ~ConfigMgr() { }

public:
    /// Method used only for loading main configuration files (authserver.conf and worldserver.conf)
    bool LoadInitial(char const* file);

    /**
     * This method loads additional configuration files
     * It is recommended to use this method in WorldScript::OnConfigLoad hooks
     *
     * @return true if loading was successful
     */
    bool LoadMore(char const* file);

    bool Reload();

    std::string GetStringDefault(const char* name, const std::string& def);
    bool GetBoolDefault(const char* name, bool def);
    int GetIntDefault(const char* name, int def);
    float GetFloatDefault(const char* name, float def);

    bool SetValue(char const* name, char const* value);

    std::string const& GetFilename();
    std::list<std::string> GetKeysByString(std::string const& name);

private:
    bool GetValueHelper(const char* name, std::string& result);
    bool LoadData(char const* file);

    typedef std::mutex LockType;
    typedef std::lock_guard<LockType> GuardType;

    std::string _filename;
    // Was an ACE_Configuration_Heap. The section names are only structure for
    // the file itself: every lookup scans all of them for the key, so this is a
    // flat namespace with an INI file on top, and it stays that way.
    boost::property_tree::ptree _config;
    bool _loaded = false;
    LockType _configLock;

    ConfigMgr(ConfigMgr const&);
    ConfigMgr& operator=(ConfigMgr const&);
};

#define sConfigMgr Trinity::Singleton<ConfigMgr>::instance()

#endif
