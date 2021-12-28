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

#ifndef DEF_ONYXIAS_LAIR_H
#define DEF_ONYXIAS_LAIR_H

uint32 const EncounterCount     = 1;

enum DataTypes
{
    DATA_ONYXIA                 = 0,
};

enum Data32
{
    DATA_ONYXIA_PHASE           = 0,
};

enum Data64
{
    DATA_ONYXIA_GUID            = 0,
    DATA_FLOOR_ERUPTION_GUID    = 1,
};

enum OnyxiaPhases
{
    PHASE_START                 = 1,
    PHASE_BREATH                = 2,
    PHASE_END                   = 3
};

enum CreatureIds
{
    NPC_WHELP                   = 11262,
    NPC_LAIRGUARD               = 36561,
    NPC_ONYXIA                  = 10184
};

enum GameObjectIds
{
    GO_WHELP_SPAWNER            = 176510,
    GO_WHELP_EGG                = 176511
};

enum AchievementData
{
    ACHIEV_TIMED_START_EVENT            = 6601, // Timed event for achievement 4402, 4005: More Dots! (10, 25 player) 5 min kill

    WORLD_STATE_MANY_WHELPS             = 7441,
    WORLD_STATE_SHE_DEEP_BREATHS_MORE   = 7442,
};

#endif
