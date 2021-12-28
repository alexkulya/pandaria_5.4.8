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

#ifndef DEF_HALLS_OF_LIGHTNING_H
#define DEF_HALLS_OF_LIGHTNING_H

const Position QuestgiverPath[7]
{
    { 1053.67f, -4.48f, 61.19f, 2.30f },
    { 1042.07f, 14.28f, 61.19f, 1.96f },
    { 1038.20f, 25.80f, 58.34f, 1.76f },
    { 1048.65f, 26.85f, 58.34f, 0.02f },
    { 1059.19f, 20.68f, 53.38f, 5.72f },
    { 1094.12f, 15.11f, 53.38f, 6.20f },
    { 1105.41f, 34.09f, 53.39f, 6.21f },
};

enum Types
{
    MAX_ENCOUNTER           = 4,

    DATA_BJARNGRIM          = 1,
    DATA_IONAR              = 2,
    DATA_LOKEN              = 3,
    DATA_VOLKHAN            = 4,

    TYPE_BJARNGRIM          = 10,
    TYPE_IONAR              = 11,
    TYPE_LOKEN              = 12,
    TYPE_VOLKHAN            = 13,

    TYPE_HALL_OF_THE_WATCHERS = 14,
};

enum Creatures
{
    NPC_STORMFORGED_TACTICIAN  = 28581,
    NPC_STORMFORGED_MENDER     = 28582,
    NPC_BJARNGRIM              = 28586,
    NPC_VOLKHAN                = 28587,
    NPC_IONAR                  = 28546,
    NPC_LOKEN                  = 28923,

    // Quest Type
    NPC_STORMHERALD_ELJRRIN_QG = 56027,
    NPC_STORMHERALD_ELJRRIN_QE = 56027,
};

enum GameObjects
{
    GO_BJARNGRIM_DOOR       = 191416,                       //_doors10
    GO_VOLKHAN_DOOR         = 191325,                       //_doors07
    GO_IONAR_DOOR           = 191326,                       //_doors05
    GO_LOKEN_DOOR           = 191324,                       //_doors02
    GO_LOKEN_THRONE         = 192654
};

#endif
