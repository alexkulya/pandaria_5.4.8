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

#ifndef ARCATRAZ_H_
#define ARCATRAZ_H_

enum eDataTypes
{
    TYPE_ZEREKETH          = 1,
    TYPE_DALLIAH           = 2,
    TYPE_SOCCOTHRATES      = 3,
    TYPE_HARBINGERSKYRISS  = 4,
    TYPE_WARDEN_1          = 5,
    TYPE_WARDEN_2          = 6,
    TYPE_WARDEN_3          = 7,
    TYPE_WARDEN_4          = 8,
    TYPE_WARDEN_5          = 9,
    DATA_MELLICHAR         = 10,
    TYPE_SHIELD_OPEN       = 11,
    DATA_SPHERE_SHIELD     = 12,
    TYPE_FELFIRE           = 13,
    TYPE_FELFIRE_COUNT     = 14,
};

enum eCreatures
{
    NPC_ZEREKETH_THE_UNBOUND     = 20870,
    NPC_MELLICHAR                = 20904, //skyriss will kill this unit
    NPC_WRATH_SCRYER_SOCCOTHRATE = 20886,
    NPC_DALLIAH_THE_DOOMSAYER    = 20885,
    NPC_SCRYER_FELFIRE           = 20978,
};

enum eActions
{
    ACTION_REMOVE_WHIRLWIND = 0,
};

enum eYells
{
    // Soccothrates
    TALK_DALLIAH_IN_COMBAT_AND_ME_ALIVE      = 0,
    TALK_SD_AGGRO                            = 1,
    TALK_SD_SLAY                             = 2,
    TALK_FELFIRE_CHARGE                      = 3,
    TALK_SOCCOTHRATES_DEATH                  = 4,
    TALK_DALLIAH_AT_LOW                      = 5,
    TALK_DALLIAH_DIE                         = 6,
    TALK_CONVERSATION_TO_DALLIAH_1           = 7,
    TALK_CONVERSATION_TO_DALLIAH_2           = 8,
    TALK_CONVERSATION_TO_DALLIAH_3           = 9,
    TALK_CONVERSATION_TO_DALLIAH_4           = 10,

    // Dalliah
    TALK_SOCCOTHRATES_IN_COMBAT_AND_ME_ALIVE = 0,
    TALK_WHIRLWIND                           = 3,
    TALK_HEAL                                = 4,
    TALK_DALIAH_DEATH                        = 5,
    TALK_SOCCOTHRATES_AT_LOW                 = 6,
    TALK_SOCCOTHRATES_DIE                    = 7,
    TALK_CONVERSATION_TO_SOCCOTHRATES_1      = 8,
    TALK_CONVERSATION_TO_SOCCOTHRATES_2      = 9,
    TALK_CONVERSATION_TO_SOCCOTHRATES_3      = 10,
};

enum eGameObjects
{
    GO_CONTAINMENT_CORE_SECURITY_FIELD_ALPHA = 184318, //door opened when Wrath-Scryer Soccothrates dies
    GO_CONTAINMENT_CORE_SECURITY_FIELD_BETA  = 184319, //door opened when Dalliah the Doomsayer dies
    GO_POD_ALPHA                             = 183961, //pod first boss wave
    GO_POD_BETA                              = 183963, //pod second boss wave
    GO_POD_DELTA                             = 183964, //pod third boss wave
    GO_POD_GAMMA                             = 183962, //pod fourth boss wave
    GO_POD_OMEGA                             = 183965, //pod fifth boss wave
    GO_WARDENS_SHIELD                        = 184802, // warden shield
    GO_SEAL_SPHERE                           = 184802, //shield 'protecting' mellichar
};

#endif // ARCATRAZ_H_
