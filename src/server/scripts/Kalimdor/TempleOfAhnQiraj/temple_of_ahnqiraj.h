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

#ifndef DEF_TEMPLE_OF_AHNQIRAJ_H
#define DEF_TEMPLE_OF_AHNQIRAJ_H
#define ENCOUNTERS 8

enum DataTypes
{
    DATA_SKERAM             = 0,
    DATA_BUG_TRIO_DEATH     = 1,
    DATA_SARTURA            = 2,
    DATA_FANKRISS           = 3,
    DATA_VISCIDUS           = 4,
    DATA_HUHURAN            = 5,
    DATA_TWIN_EMPERORS      = 6,
    DATA_CTHUN              = 7,

    // Misc
    DATA_KRI                = 8,
    DATA_VEM                = 9,
    DATA_VEMISDEAD          = 10,
    DATA_VEM_DEATH          = 11,
    DATA_CTHUN_PHASE        = 12,
};

enum Creatures
{
    BOSS_EYE_OF_CTHUN       = 15589,
    NPC_CTHUN_PORTAL        = 15896,
    NPC_CLAW_TENTACLE       = 15725,
    NPC_EYE_TENTACLE        = 15726,
    NPC_SMALL_PORTAL        = 15904,
    NPC_BODY_OF_CTHUN       = 15809,
    NPC_GIANT_CLAW_TENTACLE = 15728,
    NPC_GIANT_EYE_TENTACLE  = 15334,
    NPC_FLESH_TENTACLE      = 15802,
    NPC_GIANT_PORTAL        = 15910,

    NPC_VISCIDUS            = 15299,
    NPC_GLOB_OF_VISCIDUS    = 15667,

    NPC_SKERAM              = 15263,
    NPC_VEM                 = 15544,
    NPC_KRI                 = 15511,
    NPC_VEKLOR              = 15276,
    NPC_VEKNILASH           = 15275,
    NPC_MASTERS_OF_EYE      = 15963,
};

enum GameObjects
{
    GO_SKERAM_EXIT_DOOR       = 180636,
    GO_TWIN_EMPEROR_EXIT_DOOR = 180635,
};

#endif // DEF_TEMPLE_OF_AHNQIRAJ_H

