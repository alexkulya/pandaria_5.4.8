/*
 * Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2006-2014 ScriptDev2 <https://github.com/scriptdev2/scriptdev2/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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

#ifndef DEF_AZJOL_NERUB_H
#define DEF_AZJOL_NERUB_H

enum Data64
{
    DATA_KRIKTHIR_THE_GATEWATCHER,
    DATA_HADRONOX,
    DATA_ANUBARAK,
    DATA_WATCHER_GASHRA,
    DATA_WATCHER_SILTHIK,
    DATA_WATCHER_NARJIL,
    DATA_HADRONOX_FRONT_DOOR_1,
    DATA_HADRONOX_FRONT_DOOR_2,
    DATA_HADRONOX_SIDE_DOOR,
};

enum Data
{
    DATA_KRIKTHIR_THE_GATEWATCHER_EVENT,
    DATA_HADRONOX_EVENT,
    DATA_ANUBARAK_EVENT,
    DATA_TRASH_LEFT,
};

enum InstanceCreatures
{
    NPC_KRIKTHIR                    = 28684,
    NPC_HADRONOX                    = 28921,
    NPC_ANUBARAK                    = 29120,
    NPC_WATCHER_GASHRA              = 28730,
    NPC_WATCHER_SILTHIK             = 28731,
    NPC_WATCHER_NARJIL              = 28729,

    // Hadronox event
    NPC_WORLD_TRIGGER_LARGE_AOI     = 23472,
    NPC_ANUBAR_CRUSHER              = 28922,
    NPC_ANUBAR_CHAMPION             = 29117,
    NPC_ANUBAR_CRYPT_FIEND          = 29118,
    NPC_ANUBAR_CHAMPION_TRASH       = 29096,
    NPC_ANUBAR_CRYPT_FIEND_TRASH    = 29097,

    NPC_RECLAIMER_AZAK              = 55564,
    NPC_AZJOL_ANAK_WARRIOR          = 55566,
    NPC_NERUBIAN_FLYER              = 55573,
};

enum InstanceGameObjects
{
    GO_KRIKTHIR_DOOR                = 192395,
    GO_ANUBARAK_DOOR_1              = 192396,
    GO_ANUBARAK_DOOR_2              = 192397,
    GO_ANUBARAK_DOOR_3              = 192398,
};

enum InstanceScriptEvents
{
    SCRIPT_EVENT_WEB_FRONT_DOORS    = 19101,
    SCRIPT_EVENT_WEB_SIDE_DOOR      = 19102,
};

enum InstanceSpells
{
    SPELL_WEB_FRONT_DOORS           = 53177,
    SPELL_WEB_SIDE_DOORS            = 53185,
};

enum
{
    WORLD_STATE_HADRONOX_DENIED = 5820,
};

#endif
