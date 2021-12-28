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

#ifndef DEF_STRATHOLME_H
#define DEF_STRATHOLME_H

const Position oldRiflemanSpawn [9]=
{
    { 3553.851807f, -2945.885986f, 125.001015f, 0.592007f },
    { 3559.206299f, -2952.929932f, 125.001015f, 0.592007f },
    { 3552.417480f, -2948.667236f, 125.001015f, 0.592007f },
    { 3555.651855f, -2953.519043f, 125.001015f, 0.592007f },
    { 3547.927246f, -2950.977295f, 125.001015f, 0.592007f },
    { 3553.094697f, -2952.123291f, 125.001015f, 0.592007f },
    { 3552.727539f, -2957.776123f, 125.001015f, 0.592007f },
    { 3547.156250f, -2953.162354f, 125.001015f, 0.592007f },
    { 3550.202148f, -2957.437744f, 125.001015f, 0.592007f },
};

const Position StoneBruiserPath[2] =
{
    { 3434.65f, -3070.02f, 136.53f, 2.20f },
    { 3435.61f, -3064.97f, 136.51f, 2.26f },
};

const Position EligorPath = { 3429.58f, -3064.53f, 136.49f, 2.19f };

enum DataTypes
{
    TYPE_BARON_RUN                      = 1,
    TYPE_BARONESS                       = 2,
    TYPE_NERUB                          = 3,
    TYPE_PALLID                         = 4,
    TYPE_RAMSTEIN                       = 5,
    TYPE_BARON                          = 6,

    TYPE_MALOWN                         = 7,

    DATA_BARON                          = 10,
    DATA_YSIDA_TRIGGER                  = 11,

    TYPE_SH_QUEST                       = 20,
    TYPE_SH_CATHELA                     = 21,
    TYPE_SH_GREGOR                      = 22,
    TYPE_SH_NEMAS                       = 23,
    TYPE_SH_VICAR                       = 24,
    TYPE_SH_AELMAR                      = 25
};

enum CreatureIds
{
    NPC_CRYSTAL                         = 10415, // ziggurat crystal
    NPC_BARON                           = 45412, // ziggurat crystal
    NPC_YSIDA_TRIGGER                   = 16100, // ziggurat crystal

    NPC_RAMSTEIN                        = 10439,
    NPC_ABOM_BILE                       = 10416,
    NPC_ABOM_VENOM                      = 10417,
    NPC_BLACK_GUARD                     = 10394,
    NPC_YSIDA                           = 16031,
    NPC_BALNAZZAR                       = 10813,
    NPC_WILHELM                         = 45201,

    // Trash
    NPC_SKELETAL_GUARDIAN               = 10390,
    NPC_SKELETAL_BERSERKER              = 10391,
    NPC_BROKEN_CADAVER                  = 10383,
    NPC_MANGLED_CADAVER                 = 10382,
    NPC_PLAGUE_GHNOUL                   = 42975,
    NPC_RISEN_GUARDSMAN                 = 10418,
    NPC_RISEN_INITIATE                  = 10420,
    NPC_RISEN_DEFENDER                  = 10421,

    // Questers
    NPC_COMMANDER_ELIGOR                = 45200,
    NPC_PACKMASTER_STONEBRUISER         = 45323,
};

enum Actions
{
    ACTION_BALNAZZAR = 0,
};

enum GameobjectIds
{
    GO_DOOR_HALAZZI                     = 186303,
    GO_SERVICE_ENTRANCE                 = 175368,
    GO_GAUNTLET_GATE1                   = 175357,
    GO_ZIGGURAT1                        = 175380,  // baroness
    GO_ZIGGURAT2                        = 175379,  // nerub'enkan
    GO_ZIGGURAT3                        = 175381,  // maleki
    GO_ZIGGURAT4                        = 175405,  // rammstein
    GO_ZIGGURAT5                        = 175796,  // baron
    GO_PORT_GAUNTLET                    = 175374,  // port from gauntlet to slaugther
    GO_PORT_SLAUGTHER                   = 175373,  // port at slaugther
    GO_PORT_ELDERS                      = 175377,  // port at elders square
    GO_LARGE_PORTCULLIS_DOOR            = 187800,
};

enum QuestIds
{
    QUEST_DEAD_MAN_PLEA                 = 8945
};

enum SpellIds
{
    SPELL_BARON_ULTIMATUM               = 27861
};

// for init combat with Argent Crusader
const std::vector<uint32> CitizenType
{
    NPC_SKELETAL_GUARDIAN,
    NPC_SKELETAL_BERSERKER,
    NPC_BROKEN_CADAVER,
    NPC_MANGLED_CADAVER,
    NPC_PLAGUE_GHNOUL,
    NPC_RISEN_GUARDSMAN,
    NPC_RISEN_INITIATE,
};

#endif

