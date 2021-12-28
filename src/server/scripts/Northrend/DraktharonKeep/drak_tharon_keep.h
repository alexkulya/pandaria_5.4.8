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

#ifndef DEF_DRAK_THARON_H
#define DEF_DRAK_THARON_H

enum Data
{
    DATA_TROLLGORE_EVENT,
    DATA_NOVOS_EVENT,
    DATA_DRED_EVENT,
    DATA_THARON_JA_EVENT,
    DATA_KING_DRED_ACHIEV
};
enum Data64
{
    DATA_TROLLGORE,
    DATA_NOVOS,
    DATA_DRED,
    DATA_THARON_JA,
    DATA_NOVOS_CRYSTAL_1,
    DATA_NOVOS_CRYSTAL_2,
    DATA_NOVOS_CRYSTAL_3,
    DATA_NOVOS_CRYSTAL_4,
    DATA_NOVOS_SUMMONER_1,
    DATA_NOVOS_SUMMONER_2,
    DATA_NOVOS_SUMMONER_3,
    DATA_NOVOS_SUMMONER_4,

    ACTION_CRYSTAL_HANDLER_DIED
};

enum CreatureIds
{
    NPC_DRAKKARI_GUARDIAN               = 26620,
    NPC_SCOURGE_REANIMATOR              = 26626,
    NPC_RISEN_DRAKKARI_WARRIOR          = 26635,
    NPC_RISEN_DRAKKARI_SOULMAGE         = 26636,
    NPC_DARKWEB_VICTIM                  = 27909,
    NPC_DRAKTHARON_COCOON_BUNNY         = 27910,
    // Novos
    NPC_CRYSTAL_CHANNEL_TARGET          = 26712,
    NPC_CRYSTAL_HANDLER                 = 26627,
    NPC_HULKING_CORPSE                  = 27597,
    NPC_FETID_TROLL_CORPSE              = 27598,
    NPC_RISEN_SHADOWCASTER              = 27600,
};

enum InstanceSpells
{
    SPELL_SIPHON_LIFE_VISUAL            = 47503,
    SPELL_TELEPORT_REANIMATOR           = 47506,
    SPELL_RAISE_DEAD_RIGHT              = 48597,
    SPELL_RAISE_DEAD_LEFT               = 48605,
    SPELL_BIRTH_DEAD_VISUAL             = 48624,
    SPELL_SUMMON_KURZEL                 = 49952,
    SPELL_SUMMON_RANDOM_DRAKKARI        = 49960,
};

enum InstanceEvents
{
    EVENT_RAISE_DEAD_RIGHT              = 17739,
    EVENT_RAISE_DEAD_LEFT               = 17740,
};

enum Worldstates
{
    WORLDSTATE_CONSUMPTION_JUNCTION = 6420,
    WORLDSTATE_BETTER_OF_DRED       = 6330,
    WORLDSTATE_OH_NOVOS             = 6378,
};

#endif
