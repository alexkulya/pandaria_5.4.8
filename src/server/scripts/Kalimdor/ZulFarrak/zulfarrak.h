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

#ifndef DEF_ZF_H
#define DEF_ZF_H

const Position GahzrillaPath[3] =
{
    { 1668.52f, 1190.06f, 6.46f, 0.75f },
    { 1684.22f, 1206.11f, 7.66f, 0.73f },
    { 1695.79f, 1216.60f, 8.87f, 0.73f },
};

enum Creatures
{
    NPC_ZUM_RAH    = 7271,
    NPC_BLY        = 7604,
    NPC_RAVEN      = 7605,
    NPC_ORO        = 7606,
    NPC_WEEGLI     = 7607,
    NPC_MURTA      = 7608,
    NPC_GAHZRILLA  = 7273,
    NPC_NEKRUM     = 7796,
    NPC_SEZZIZ     = 7275,
    NPC_DUSTWRAITH = 10081,
};

enum iEvents
{
    EVENT_PYRAMID = 1,
    EVENT_GAHZRILLA
};

enum GameObjects
{
    GO_END_DOOR = 146084,
};

enum DataTypes
{
    DATA_ZUM_RAH = 0
};

enum zfPyramidPhases
{
    PYRAMID_NOT_STARTED, //default
    PYRAMID_CAGES_OPEN, //happens in GO hello for cages
    PYRAMID_ARRIVED_AT_STAIR, //happens in Weegli's movementinform
    PYRAMID_WAVE_1,
    PYRAMID_PRE_WAVE_2,
    PYRAMID_WAVE_2,
    PYRAMID_PRE_WAVE_3,
    PYRAMID_WAVE_3,
    PYRAMID_KILLED_ALL_TROLLS,
};

#endif