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

#ifndef DEF_SUNKEN_TEMPLE_H
#define DEF_SUNKEN_TEMPLE_H

int32 const EncounterCount = 4;

enum eData
{
    DATA_HAKKAR   = 0,
    DATA_JAMMAL   = 1,
    DATA_WARDENS  = 2,
    DATA_ERANIKUS = 3,
};

enum eCreature
{
    NPC_AVATAR_OF_HAKKAR  = 8443,
    NPC_JAMMALAN_PROPHET  = 5710,
    // Wardens            
    NPC_WEAVER            = 5720,
    NPC_DREAMSCYTHE       = 5721,
    NPC_MORPHAZ           = 5719,
    NPC_HAZZAS            = 5722,
    NPC_SHADE_OF_ERANIKUS = 5709,
    NPC_OGOM_WRETCHED     = 5711,
    NPC_EARTHGRAB_TOTEM   = 6066,
};

enum eActions
{
    ACTION_ERANIKUS_DREAM = 0,
    ACTION_HAKKAR_RISE    = 1,
};

enum eGameObjects
{
    GO_SHRINE_OF_SOULFLAYER = 208321,
};

#endif // DEF_SUNKEN_TEMPLE_H

