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

#ifndef DEF_SUNWELLPLATEAU_H
#define DEF_SUNWELLPLATEAU_H

// Encounters
enum Data
{
    DATA_KALECGOS_EVENT,
    DATA_BRUTALLUS_EVENT,
    DATA_FELMYST_EVENT,
    DATA_EREDAR_TWINS_EVENT,
    DATA_MURU_EVENT,
    DATA_KILJAEDEN_EVENT,
};

enum Data64
{
    // Creatures
    DATA_KALECGOS_DRAGON,
    DATA_KALECGOS_HUMAN,
    DATA_SATHROVARR,
    DATA_BRUTALLUS,
    DATA_MADRIGOSA,
    DATA_FELMYST,
    DATA_ALYTHESS,
    DATA_SACROLASH,
    DATA_MURU,
    DATA_KILJAEDEN,
    DATA_KILJAEDEN_CONTROLLER,
    DATA_ANVEENA,
    DATA_KALECGOS_KJ,

    // GameObjects
    DATA_GO_FORCEFIELD,
    DATA_ORB_OF_THE_BLUE_DRAGONFLIGHT_1,
    DATA_ORB_OF_THE_BLUE_DRAGONFLIGHT_2,
    DATA_ORB_OF_THE_BLUE_DRAGONFLIGHT_3,
    DATA_ORB_OF_THE_BLUE_DRAGONFLIGHT_4,

    // Misc
    DATA_PLAYER_GUID,
};

enum Creatures
{
    BOSS_MURU                                     = 25741,
    BOSS_ENTROPIUS                                = 25840,
    NPC_KALECGOS                                  = 24850,
    NPC_KALEC                                     = 24891,
    NPC_SATHROVARR                                = 24892,

    NPC_DEAD                                      = 25268,
    NPC_FLIGHT_LEFT                               = 25357,
    NPC_FLIGHT_RIGHT                              = 25358,
    NPC_DEATH_CLOUD                               = 25703,
    NPC_VAPOR                                     = 25265,
    NPC_VAPOR_TRAIL                               = 25267,
    NPC_WORLD_TRIGGER_LARGE_AOI_NOT_IMMUNE_PC_NPC = 23472,
    NPC_BRUTALLUS_DEATH_CLOUD                     = 25703,

    NPC_GRAND_WARLOCK_ALYTHESS                    = 25166,
    NPC_SHADOW_IMAGE                              = 25214,
    NPC_LADY_SACROLASH                            = 25165,

    NPC_ANVEENA                                   = 26046, // Embodiment of the Sunwell
    NPC_KALECGOS_OUTRO                            = 25319, // Helps the raid throughout the fight
    NPC_PROPHET                                   = 26246, // Outro
    NPC_KILJAEDEN                                 = 25315, // Give it to 'em KJ!
    NPC_HAND_OF_THE_DECEIVER                      = 25588, // Adds found before KJ emerges
    NPC_FELFIRE_PORTAL                            = 25603, // Portal spawned be Hand of the Deceivers
    NPC_VOLATILE_FELFIRE_FIEND                    = 25598, // Fiends spawned by the above portal
    NPC_ARMAGEDDON_TARGET                         = 25735, // This mob casts meteor on itself.. I think
    NPC_SHIELD_ORB                                = 25502, // Shield orbs circle the room raining shadow bolts on raid
    NPC_THE_CORE_OF_ENTROPIUS                     = 26262, // Used in the ending cinematic?
    NPC_POWER_OF_THE_BLUE_DRAGONFLIGHT            = 25653, // NPC that players possess when using the Orb of the Blue Dragonflight
    NPC_SPIKE_TARGET1                             = 30598, // Should summon these under Shadow Spike Channel on targets place
    NPC_SPIKE_TARGET2                             = 30614,
    NPC_SINISTER_REFLECTION                       = 25708, // Sinister Relection spawnd on phase swichtes

    NPC_DARKNESS                                  = 25879,
    NPC_DARK_FIENDS                               = 25744,
    NPC_BERSERKER                                 = 25798,
    NPC_FURY_MAGE                                 = 25799,
    NPC_VOID_SENTINEL                             = 25772,
    NPC_VOID_SPAWN                                = 25824,
    NPC_BLACK_HOLE                                = 25855,
};

enum GameObjects
{
    GO_ORB_OF_THE_BLUE_DRAGONFLIGHT               = 188415,
};

enum InstanceSpells
{
    SPELL_SUMMON_FELBLAZE                         = 45069,
    SPELL_ELEPORT_TO_APEX_POINT                   = 46881,
    SPELL_TELEPORT_TO_WITCHS_SANCTUM              = 46883,
    SPELL_TELEPORT_TO_SUNWELL_PLATEAU             = 46884,
};

#endif
