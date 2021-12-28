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

#ifndef DEF_ULDUAR_H
#define DEF_ULDUAR_H

#include "ObjectMgr.h"

extern Position const ObservationRingKeepersPos[4];
extern Position const YSKeepersPos[4];
extern Position const AlgalonLandPos;

enum UlduarBosses
{
    MAX_ENCOUNTER            = 20,

    BOSS_LEVIATHAN           = 0,
    BOSS_IGNIS               = 1,
    BOSS_RAZORSCALE          = 2,
    BOSS_XT002               = 3,
    BOSS_ASSEMBLY_OF_IRON    = 4,
    BOSS_KOLOGARN            = 5,
    BOSS_AURIAYA             = 6,
    BOSS_HODIR               = 7,
    BOSS_THORIM              = 8,
    BOSS_FREYA               = 9,
    BOSS_MIMIRON             = 10,
    BOSS_VEZAX               = 11,
    BOSS_YOGG_SARON          = 12,
    BOSS_ALGALON             = 13,
    BOSS_BRIGHTLEAF          = 14,
    BOSS_IRONBRANCH          = 15,
    BOSS_STONEBARK           = 16,
    BOSS_STEELBREAKER        = 17,
    BOSS_MOLGEIM             = 18,
    BOSS_BRUNDIR             = 19,
};

enum UlduarNPCs
{
    // Ulduar Gauntlet
    NPC_RHYDIAN                             = 33696,
    NPC_KEEPER_UNIT                         = 33721,
    NPC_NORGANNON                           = 33686,
    NPC_BRONZEBEARD_RADIO                   = 34054,    
    NPC_LOREKEEPER                          = 33686, // Hard mode starter
    NPC_BRANN_BRONZBEARD                    = 33579,
    NPC_DELORAH                             = 33701,
    NPC_ULDUAR_GAUNTLET_GENERATOR           = 33571, // Trigger tied to towers
    NPC_TRANSITUS_SHIELD_DUMMY              = 27306,
    NPC_PENTARUS                            = 33624,
    NPC_HIRED_ENGINEER                      = 33626,
    NPC_TOR_MAGE                            = 33672,
    NPC_ULDUAR_WARMAGE                      = 33662,
    NPC_LEVIATHAN_SEATS                     = 33114,
    NPC_MECHANOLIFT                         = 33214,
    NPC_ULDUAR_GAUNTLET_GENERATOR_SMALL     = 34159,
    NPC_LIQUID                              = 33189,
    NPC_CONTAINER                           = 33218,
    NPC_CHOPPER                             = 33062,
    NPC_SALVAGED_DEMOLISHER                 = 33109,
    NPC_SALVAGED_SIEGE_ENGINE               = 33060,
    NPC_IRONWORK_CANNON                     = 33264,
    NPC_SALVAGED_SIEGE_TURRET               = 33067,
    NPC_SALVAGED_DEMOLISHER_MECHANIC_SEAT   = 33167,
    NPC_STEELFORGED_DEFENDER                = 33572,

    // Leviathan
    NPC_LEVIATHAN                           = 33113,
    NPC_ORBITAL_SUPPORT                     = 34286,
    NPC_HODIRS_FURY_TARGETTING_RETICLE      = 33108,
    NPC_HODIRS_FURY                         = 33212,
    NPC_THORIMS_HAMMER_TARGETTING_RETICLE   = 33364,
    NPC_THORIMS_HAMMER                      = 33365,
    NPC_FREYAS_WARD_TARGETTING_RETICLE      = 33366,
    NPC_FREYAS_WARD                         = 33367,
    NPC_MIMIRONS_INFERNO_TARGETTING_RETICLE = 33369,
    NPC_MIMIRONS_INFERNO                    = 33370,

    // Ignis
    NPC_IGNIS                               = 33118,
    NPC_IRON_CONSTRUCT                      = 33121,
    NPC_GROUND_SCORCH                       = 33221,

    // Razorscale
    NPC_RAZORSCALE                          = 33186,
    NPC_RAZORSCALE_CONTROLLER               = 33233,
    NPC_DARK_RUNE_GUARDIAN                  = 33388,
    NPC_DARK_RUNE_SENTINEL                  = 33846,
    NPC_DARK_RUNE_WATCHER                   = 33453,
    NPC_MOLE_MACHINE_TRIGGER                = 33245,
    NPC_COMMANDER                           = 33210,
    NPC_ENGINEER                            = 33287,
    NPC_DEFENDER                            = 33816,
    NPC_STEELFORGED_DEFFENDER               = 33236,
    NPC_EXPEDITION_COMMANDER                = 33210,

    NPC_XT002                               = 33293,
    NPC_XT_TOY_PILE                         = 33337,

    NPC_STEELBREAKER                        = 32867,
    NPC_MOLGEIM                             = 32927,
    NPC_BRUNDIR                             = 32857,
    
    // Kologarn
    NPC_KOLOGARN                            = 32930,
    NPC_FOCUSED_EYEBEAM                     = 33632,
    NPC_FOCUSED_EYEBEAM_RIGHT               = 33802,
    NPC_LEFT_ARM                            = 32933,
    NPC_RIGHT_ARM                           = 32934,
    NPC_RUBBLE                              = 33768,
    NPC_RUBBLE_STALKER                      = 33809,
    NPC_ARM_SWEEP_STALKER                   = 33661,

    NPC_AURIAYA                             = 33515,
    
    // Thorim
    NPC_THORIM                              = 32865,
    NPC_JORMUNGAR_BEHEMOTH                  = 32882,
    NPC_MERCENARY_CAPTAIN_A                 = 32908,
    NPC_MERCENARY_SOLDIER_A                 = 32885,
    NPC_DARK_RUNE_ACOLYTE                   = 32886,
    NPC_MERCENARY_CAPTAIN_H                 = 32907,
    NPC_MERCENARY_SOLDIER_H                 = 32883,
    NPC_RUNE_GIANT                          = 32873,
    NPC_RUNIC_COLOSSUS                      = 32872,
    NPC_THORIM_CTRL                         = 32879,
    NPC_SIF                                 = 33196,
    NPC_LIGHTNING_ORB                       = 33138,
    NPC_THUNDER_ORB                         = 33378,
    NPC_THORIM_COMBAT_TRIGGER               = 34055,
    NPC_THORIM_GOLEM_RH_BUNNY               = 33140,
    NPC_THORIM_GOLEM_LH_BUNNY               = 33141,
    NPC_DARK_RUNE_CHAMPION                  = 32876,
    NPC_DARK_RUNE_COMMONER                  = 32904,
    NPC_DARK_RUNE_EVOKER                    = 32878,
    NPC_DARK_RUNE_WARBRINGER                = 32877,
    NPC_IRON_RING_GUARD                     = 32874,
    NPC_IRON_HONOR_GUARD                    = 32875,
    NPC_DARK_RUNE_ACOLYTE_TUNNEL            = 33110,
    NPC_THORIM_TRAP_BUNNY_1                 = 33054,
    NPC_THORIM_TRAP_BUNNY_2                 = 33725,
    NPC_THORIM_EVENT_BUNNY                  = 32892,

    // Mimiron
    NPC_LEVIATHAN_MKII                      = 33432,
    NPC_VX_001                              = 33651,
    NPC_AERIAL_COMMAND_UNIT                 = 33670,
    NPC_MIMIRON                             = 33350,

    // Hodir
    NPC_HODIR                               = 32845,
    NPC_FLASH_FREEZE                        = 32926,
    NPC_ICE_BLOCK                           = 32938,
    NPC_SNOWPACKED_ICICLE                   = 33174,
    NPC_ICICLE                              = 33169,
    NPC_ICICLE_SNOWDRIFT                    = 33173,
    NPC_TOASTY_FIRE                         = 33342,

    // Hodir's Helper NPCs
    NPC_TOR_GREYCLOUD                       = 32941,
    NPC_KAR_GREYCLOUD                       = 33333,
    NPC_EIVI_NIGHTFEATHER                   = 33325,
    NPC_ELLIE_NIGHTFEATHER                  = 32901,
    NPC_SPIRITWALKER_TARA                   = 33332,
    NPC_SPIRITWALKER_YONA                   = 32950,
    NPC_ELEMENTALIST_MAHFUUN                = 33328,
    NPC_ELEMENTALIST_AVUUN                  = 32900,
    NPC_AMIRA_BLAZEWEAVER                   = 33331,
    NPC_VEESHA_BLAZEWEAVER                  = 32946,
    NPC_MISSY_FLAMECUFFS                    = 32893,
    NPC_SISSY_FLAMECUFFS                    = 33327,
    NPC_BATTLE_PRIEST_ELIZA                 = 32948,
    NPC_BATTLE_PRIEST_GINA                  = 33330,
    NPC_FIELD_MEDIC_PENNY                   = 32897,
    NPC_FIELD_MEDIC_JESSI                   = 33326,

    // Freya
    NPC_FREYA                               = 32906,
    NPC_ELDER_IRONBRANCH                    = 32913,
    NPC_ELDER_STONEBARK                     = 32914,
    NPC_ELDER_BRIGHTLEAF                    = 32915,

    // Freya's Keepers
    NPC_IRONBRANCH                          = 32913,
    NPC_BRIGHTLEAF                          = 32915,
    NPC_STONEBARK                           = 32914,

    // Freya's trash NPCs
    NPC_CORRUPTED_SERVITOR                  = 33354,
    NPC_MISGUIDED_NYMPH                     = 33355,
    NPC_GUARDIAN_LASHER                     = 33430,
    NPC_FOREST_SWARMER                      = 33431,
    NPC_MANGROVE_ENT                        = 33525,
    NPC_IRONROOT_LASHER                     = 33526,
    NPC_NATURES_BLADE                       = 33527,
    NPC_GUARDIAN_OF_LIFE                    = 33528,

    NPC_VEZAX                               = 33271,
    NPC_YOGG_SARON                          = 33288,
    NPC_ALGALON                             = 32871,

    // Yogg-Saron
    NPC_SARA                                = 33134,
    NPC_GUARDIAN_OF_YOGG_SARON              = 33136,
    NPC_HODIR_OBSERVATION_RING              = 33213,
    NPC_FREYA_OBSERVATION_RING              = 33241,
    NPC_THORIM_OBSERVATION_RING             = 33242,
    NPC_MIMIRON_OBSERVATION_RING            = 33244,
    NPC_VOICE_OF_YOGG_SARON                 = 33280,
    NPC_OMINOUS_CLOUD                       = 33292,
    NPC_FREYA_YS                            = 33410,
    NPC_HODIR_YS                            = 33411,
    NPC_MIMIRON_YS                          = 33412,
    NPC_THORIM_YS                           = 33413,
    NPC_SUIT_OF_ARMOR                       = 33433,
    NPC_KING_LLANE                          = 33437,
    NPC_THE_LICH_KING                       = 33441,
    NPC_IMMOLATED_CHAMPION                  = 33442,
    NPC_YSERA                               = 33495,
    NPC_NELTHARION                          = 33523,
    NPC_MALYGOS                             = 33535,
    NPC_DEATH_RAY                           = 33881,
    NPC_DEATH_ORB                           = 33882,
    NPC_BRAIN_OF_YOGG_SARON                 = 33890,
    NPC_INFLUENCE_TENTACLE                  = 33943,
    NPC_TURNED_CHAMPION                     = 33962,
    NPC_CRUSHER_TENTACLE                    = 33966,
    NPC_CONSTRICTOR_TENTACLE                = 33983,
    NPC_CORRUPTOR_TENTACLE                  = 33985,
    NPC_IMMORTAL_GUARDIAN                   = 33988,
    NPC_SANITY_WELL                         = 33991,
    NPC_DESCEND_INTO_MADNESS                = 34072,
    NPC_MARKED_IMMORTAL_GUARDIAN            = 36064,

    // Algalon the Observer
    NPC_BRANN_BRONZBEARD_ALG                = 34064,
    NPC_AZEROTH                             = 34246,
    NPC_LIVING_CONSTELLATION                = 33052,
    NPC_ALGALON_STALKER                     = 33086,
    NPC_COLLAPSING_STAR                     = 32955,
    NPC_BLACK_HOLE                          = 32953,
    NPC_WORM_HOLE                           = 34099,
    NPC_ALGALON_VOID_ZONE_VISUAL_STALKER    = 34100,
    NPC_ALGALON_STALKER_ASTEROID_TARGET_01  = 33104,
    NPC_ALGALON_STALKER_ASTEROID_TARGET_02  = 33105,
    NPC_UNLEASHED_DARK_MATTER               = 34097,
};

enum UlduarGameObjects
{
    // Misc
    GO_ULDUAR_TELEPORTER                    = 194569,
    GO_CUPOLE                               = 194484,
    GO_TELEPORTER                           = 194569,

    // Leviathan
    GO_LEVIATHAN_DOOR                       = 194905,
    GO_LEVIATHAN_DOOR_BACK                  = 194416,
    GO_LEVIATHAN_GATE                       = 194630,
    GO_TOWER_OF_STORMS                      = 194377,
    GO_TOWER_OF_FLAMES                      = 194371,
    GO_TOWER_OF_FROST                       = 194370,
    GO_TOWER_OF_LIFE                        = 194375,
    GO_REPAIR_STATION                       = 194261,
    GO_CRYSTAL_STORMS                       = 194706,
    GO_CRYSTAL_FLAMES                       = 194705,
    GO_CRYSTAL_FROST                        = 194707,
    GO_CRYSTAL_LIFE                         = 194704,

    // Razorscale
    GO_RAZOR_HARPOON_1                      = 194542,
    GO_RAZOR_HARPOON_2                      = 194541,
    GO_RAZOR_HARPOON_3                      = 194543,
    GO_RAZOR_HARPOON_4                      = 194519,
    GO_RAZOR_BROKEN_HARPOON                 = 194565,
    GO_MOLE_MACHINE                         = 194316,

    // XT-002
    GO_XT_002_DOOR                          = 194631,

    // Iron Council
    GO_IRON_COUNCIL_ENTRANCE                = 194554,
    GO_ARCHIVUM_DOOR                        = 194556,

    // Kologarn
    GO_KOLOGARN_BRIDGE                      = 194232,
    GO_KOLOGARN_DOOR                        = 194553,
    GO_KOLOGARN_CHEST_10                    = 195046,
    GO_KOLOGARN_CHEST_25                    = 195047,

    // Hodir
    GO_TOASTY_FIRE                          = 194300,
    GO_SNOWDRIFT                            = 194173,
    GO_HODIR_ENTRANCE                       = 194442,
    GO_HODIR_DOOR                           = 194634,
    GO_HODIR_ICE_DOOR                       = 194441,
    GO_HODIR_CHEST_10                       = 194307,
    GO_HODIR_CHEST_25                       = 194308,
    GO_HODIR_RARE_HARDMODE_10               = 194200,
    GO_HODIR_RARE_HARDMODE_25               = 194201,

    // Thorim
    GO_LEVER                                = 194264,
    GO_THORIM_RUNIC_DOOR                    = 194557,
    GO_THORIM_STONE_DOOR                    = 194558,
    GO_THORIM_LIGHTNING_FIELD               = 194559,
    GO_THORIM_DARK_IRON_PROTCULLIS          = 194560,
    GO_CACHE_OF_STORMS_10                   = 194312,
    GO_CACHE_OF_STORMS_25                   = 194314,
    GO_CACHE_OF_STORMS_HARDMODE_10          = 194313,
    GO_CACHE_OF_STORMS_HARDMODE_25          = 194315,

    // Freya
    GO_NATURE_BOMB                          = 194902,

    // Mimiron
    GO_MIMIRON_TRAIN                        = 194675,
    GO_MIMIRON_ELEVATOR                     = 194749,
    GO_MIMIRON_DOOR_1                       = 194776,
    GO_MIMIRON_DOOR_2                       = 194774,
    GO_MIMIRON_DOOR_3                       = 194775,
    GO_BIG_RED_BUTTON                       = 194739,
    GO_ACTIVATE_TRAM                        = 194437,
    GO_CALL_TRAM_LAST                       = 194912,
    GO_CALL_TRAM_FIRST                      = 194914,
    CACHE_OF_INNOVATION_10                  = 194789,
    CACHE_OF_INNOVATION_25                  = 194956,
    CACHE_OF_INNOVATION_HARDMODE_10         = 194957,
    CACHE_OF_INNOVATION_HARDMODE_25         = 194958,

    // General Vezax
    GO_WAY_TO_YOGG                          = 194255,
    GO_VEZAX_DOOR                           = 194750,

    // Yogg-Saron
    GO_YOGG_SARON_DOOR                      = 194773,
    GO_BRAIN_ROOM_DOOR_1                    = 194635,
    GO_BRAIN_ROOM_DOOR_2                    = 194636,
    GO_BRAIN_ROOM_DOOR_3                    = 194637,

    // Algalon the Observer
    GO_CELESTIAL_PLANETARIUM_ACCESS_10      = 194628,
    GO_CELESTIAL_PLANETARIUM_ACCESS_25      = 194752,
    GO_DOODAD_UL_SIGILDOOR_01               = 194767,
    GO_DOODAD_UL_SIGILDOOR_02               = 194911,
    GO_DOODAD_UL_SIGILDOOR_03               = 194910,
    GO_DOODAD_UL_UNIVERSEFLOOR_01           = 194715,
    GO_DOODAD_UL_UNIVERSEFLOOR_02           = 194716,
    GO_DOODAD_UL_UNIVERSEGLOBE01            = 194148,
    GO_DOODAD_UL_ULDUAR_TRAPDOOR_03         = 194253,
    GO_GIFT_OF_THE_OBSERVER_10              = 194821,
    GO_GIFT_OF_THE_OBSERVER_25              = 194822,
};

enum EventIds
{
    EVENT_TOWER_OF_STORM_DESTROYED      = 21031,
    EVENT_TOWER_OF_FROST_DESTROYED      = 21032,
    EVENT_TOWER_OF_FLAMES_DESTROYED     = 21033,
    EVENT_TOWER_OF_LIFE_DESTROYED       = 21030,
    EVENT_TRAM_FIRST_STOP               = 21393,
    EVENT_TRAM_LAST_STOP                = 21394,
    EVENT_ACTIVATE_SANITY_WELL          = 21432,
    EVENT_HODIRS_PROTECTIVE_GAZE_PROC   = 21437,
};

enum LeviathanActions
{
    ACTION_TOWER_OF_STORM_DESTROYED     = 1,
    ACTION_TOWER_OF_FROST_DESTROYED     = 2,
    ACTION_TOWER_OF_FLAMES_DESTROYED    = 3,
    ACTION_TOWER_OF_LIFE_DESTROYED      = 4,
    ACTION_START_HARD_MODE              = 5,
    ACTION_MOVE_TO_CENTER_POSITION      = 10,
    ACTION_SUMMON_VEHICLES              = 13
};

enum UlduarAchievementCriteriaIds
{
    CRITERIA_CON_SPEED_ATORY                 = 21597,
    CRITERIA_LUMBERJACKED_10                 = 10720,
    CRITERIA_LUMBERJACKED_25                 = 10721,
    CRITERIA_DISARMED                        = 21687,
    CRITERIA_WAITS_DREAMING_STORMWIND_25     = 10321,
    CRITERIA_WAITS_DREAMING_CHAMBER_25       = 10322,
    CRITERIA_WAITS_DREAMING_ICECROWN_25      = 10323,
    CRITERIA_WAITS_DREAMING_STORMWIND_10     = 10324,
    CRITERIA_WAITS_DREAMING_CHAMBER_10       = 10325,
    CRITERIA_WAITS_DREAMING_ICECROWN_10      = 10326,
    CRITERIA_DRIVE_ME_CRAZY_10               = 10185,
    CRITERIA_DRIVE_ME_CRAZY_25               = 10296,
    CRITERIA_THREE_LIGHTS_IN_THE_DARKNESS_10 = 10410,
    CRITERIA_THREE_LIGHTS_IN_THE_DARKNESS_25 = 10414,
    CRITERIA_TWO_LIGHTS_IN_THE_DARKNESS_10   = 10388,
    CRITERIA_TWO_LIGHTS_IN_THE_DARKNESS_25   = 10415,
    CRITERIA_ONE_LIGHT_IN_THE_DARKNESS_10    = 10409,
    CRITERIA_ONE_LIGHT_IN_THE_DARKNESS_25    = 10416,
    CRITERIA_ALONE_IN_THE_DARKNESS_10        = 10412,
    CRITERIA_ALONE_IN_THE_DARKNESS_25        = 10417,
    CRITERIA_REALM_FIRST_DEATHS_DEMISE       = 10279,
    CRITERIA_HERALD_OF_TITANS                = 10678,
    CRITERIA_REALM_FIRST_CELESTIAL_DEFENDER  = 10698,

    // Champion of Ulduar
    CRITERIA_C_O_U_LEVIATHAN_10              = 10042,
    CRITERIA_C_O_U_IGNIS_10                  = 10342,
    CRITERIA_C_O_U_RAZORSCALE_10             = 10340,
    CRITERIA_C_O_U_XT002_10                  = 10341,
    CRITERIA_C_O_U_IRON_COUNCIL_10           = 10598,
    CRITERIA_C_O_U_KOLOGARN_10               = 10348,
    CRITERIA_C_O_U_AURIAYA_10                = 10351,
    CRITERIA_C_O_U_HODIR_10                  = 10439,
    CRITERIA_C_O_U_THORIM_10                 = 10403,
    CRITERIA_C_O_U_FREYA_10                  = 10582,
    CRITERIA_C_O_U_MIMIRON_10                = 10347,
    CRITERIA_C_O_U_VEZAX_10                  = 10349,
    CRITERIA_C_O_U_YOGG_SARON_10             = 10350,
    // Conqueror of Ulduar
    CRITERIA_C_O_U_LEVIATHAN_25              = 10352,
    CRITERIA_C_O_U_IGNIS_25                  = 10355,
    CRITERIA_C_O_U_RAZORSCALE_25             = 10353,
    CRITERIA_C_O_U_XT002_25                  = 10354,
    CRITERIA_C_O_U_IRON_COUNCIL_25           = 10599,
    CRITERIA_C_O_U_KOLOGARN_25               = 10357,
    CRITERIA_C_O_U_AURIAYA_25                = 10363,
    CRITERIA_C_O_U_HODIR_25                  = 10719,
    CRITERIA_C_O_U_THORIM_25                 = 10404,
    CRITERIA_C_O_U_FREYA_25                  = 10583,
    CRITERIA_C_O_U_MIMIRON_25                = 10361,
    CRITERIA_C_O_U_VEZAX_25                  = 10362,
    CRITERIA_C_O_U_YOGG_SARON_25             = 10364
};

enum UlduarSpells
{
    SPELL_LUMBERJACKED_ACHIEVEMENT_CHECK    = 65296,
    SPELL_DWARFAGEDDON_ACHIEVEMENT          = 65387,
};

enum UlduarTeleportSpells
{
    SPELL_BASE_CAMP_TELEPORT            = 64014,
    SPELL_FORMATION_GROUNDS_TELEPORT    = 64032,
    SPELL_COLOSSAL_FORGE_TELEPORT       = 64028,
    SPELL_SCRAPYARD_TELEPORT            = 64031,
    SPELL_ANTECHAMBER_TELEPORT          = 64030,
    SPELL_SHATTERED_WALKWAY_TELEPORT    = 64029,
    SPELL_CONSERVATORY_TELEPORT         = 64024,
    SPELL_SPARK_OF_IMAGINATION_TELEPORT = 64025,
    SPELL_DESCENT_INTO_MADNESS_TELEPORT = 64027
};

enum UlduarData
{
    // Leviathan
    DATA_COLOSSUS = 20,
    DATA_LEVI_VEHICLES,
    DATA_LEVI_HARD_MODE,
    DATA_SHIELD_DISABLED,
    DATA_TOWER_OF_STORMS_CRYSTAL,
    DATA_TOWER_OF_FLAMES_CRYSTAL,
    DATA_TOWER_OF_FROST_CRYSTAL,
    DATA_TOWER_OF_LIFE_CRYSTAL,
    DATA_LEVI_DOOR,

    // Razorscale
    DATA_EXPEDITION_COMMANDER,
    DATA_RAZORSCALE_CONTROL,

    // XT-002
    DATA_TOY_PILE_0,
    DATA_TOY_PILE_1,
    DATA_TOY_PILE_2,
    DATA_TOY_PILE_3,

    // Hodir
    DATA_HODIR_RARE_CACHE,

    // Thorim
    DATA_RUNIC_COLOSSUS,
    DATA_RUNE_GIANT,
    DATA_RUNIC_DOOR,
    DATA_STONE_DOOR,
    DATA_THORIM_HARDMODE,

    // Mimiron
    DATA_CALL_TRAM,
    DATA_LEVIATHAN_MK_II,
    DATA_VX_001,
    DATA_AERIAL_UNIT,
    DATA_MIMIRON_ELEVATOR,
    DATA_TRAM,
    DATA_MIMIRON_HARDMODE,

    // Yogg-Saron
    DATA_VOICE_OF_YOGG_SARON,
    DATA_SARA,
    DATA_BRAIN_OF_YOGG_SARON,
    DATA_FREYA_YS,
    DATA_HODIR_YS,
    DATA_THORIM_YS,
    DATA_MIMIRON_YS,
    DATA_ILLUSION,
    DATA_DRIVE_ME_CRAZY,
    DATA_KEEPERS_COUNT,

    // Algalon the Observer
    DATA_ALGALON_SUMMON_STATE,
    DATA_SIGILDOOR_01,
    DATA_SIGILDOOR_02,
    DATA_SIGILDOOR_03,
    DATA_UNIVERSE_FLOOR_01,
    DATA_UNIVERSE_FLOOR_02,
    DATA_UNIVERSE_GLOBE,
    DATA_ALGALON_TRAPDOOR,
    DATA_BRANN_BRONZEBEARD_ALG,

    DATA_AREATRIGGER_EVENT,
};

enum UlduarWorldStates
{
    WORLD_STATE_LEVIATHAN               = 4096,
    WORLD_STATE_IGNIS                   = 4161,
    WORLD_STATE_RAZORSCALE              = 4162,
    WORLD_STATE_XT002                   = 4164,
    WORLD_STATE_MIMIRON                 = 4122,
    WORLD_STATE_YOGG_SARON              = 4061,
    WORLD_STATE_ALGALON                 = 4150,
    WORLD_STATE_ALGALON_DESPAWN_TIMER   = 4131,
    WORLD_STATE_ALGALON_TIMER_ENABLED   = 4132,

    // Achievements
    WORLDSTATE_SHUTOUT                  = 6916,
    WORLDSTATE_UNBROKEN                 = 6917,
    WORLDSTATE_SHATTERED                = 6977,
    WORLDSTATE_NERF_ENGINEERING         = 6913,
    WORLDSTATE_NERF_GRAVITY_BOMBS       = 6915,
    WORLDSTATE_CHOISE_ASSEMBLY_OF_IRON  = 6971,
    WORLDSTATE_ON_YOUR_SIDE             = 6971,
    WORLDSTATE_CANT_DO_THIS_WHILE_STUN  = 6972,
    WORLDSTATE_WITH_OPEN_ARMS           = 6878,
    WORLDSTATE_DISARMED                 = 7013,
    WORLDSTATE_IF_LOOKS_COULD_KILL      = 6886,
    WORLDSTATE_RUBBLE_AND_ROLL          = 6888, // require spell hit 143000
    WORLDSTATE_CRAZY_CAT_LADY_10        = 6930,
    WORLDSTATE_CRAZY_CAT_LADY_25        = 6929,
    WORLDSTATE_NINE_LIVES               = 6823,
    WORLDSTATE_CHEESE_THE_FREEZE        = 6875, // require spell hit [2] 64899
    WORLDSTATE_I_HAVE_COOLEST_FRIENDS   = 6876,
    WORLDSTATE_GETTING_COLD_IN_HERE     = 6873,
    WORLDSTATE_THIS_CACHE_WAS_RARE      = 6984,
    WORLDSTATE_DONT_STAND_IN_LIGHTNING  = 6895,
    WORLDSTATE_SIFFED                   = 6676,
    WORLDSTATE_LOSE_YOUR_ILLUSION       = 6676, // same
    WORLDSTATE_GETTING_BACK_TO_NATURE   = 6926,
    WORLDSTATE_KNOCK_ON_WOOD            = 6980,
    WORLDSTATE_KNOCK_ON_WOOD_x2         = 6981,
    WORLDSTATE_KNOCK_ON_WOOD_x3         = 6982,
    WORLDSTATE_ORBITAL_BOMBARDMENT      = 6919,
    WORLDSTATE_ORBITAL_DEVASTATION      = 6918,
    WORLDSTATE_NUKED_FROM_ORBIT         = 6920,
    WORLDSTATE_ORBIT_UARY               = 6921,
    WORLDSTATE_A_QUICK_SHAVE            = 6900,
    WORLDSTATE_SET_UP_US_BOMB_MINE      = 6883,
    WORLDSTATE_SET_UP_US_BOMB_ROCKET    = 6885,
    WORLDSTATE_SET_UP_US_BOMB_BOT       = 6884,
    WORLDSTATE_FIRE_FIGHTER             = 6853,
    WORLDSTATE_SHADOW_DODGER            = 6889,
    WORLDSTATE_SMELL_OF_SARONITE        = 6983,
    WORLDSTATE_KISS_AND_MAKE_UP         = 6791,
    WORLDSTATE_THREE_LIGHTS_IN_DARKNESS = 6969,
    WORLDSTATE_DRIVE_ME_CRAZY           = 6892,
    WORLDSTATE_TWO_LIGHTS_IN_DARKNESS   = 6909,
    WORLDSTATE_ONE_LIGHT_IN_DARKNESS    = 6968,
    WORLDSTATE_ALONE_IN_DARKNESS        = 6785,
};

enum UlduarAchievementData
{
    // FL Achievement boolean
    DATA_UNBROKEN = 29052906, // 2905, 2906 are achievement IDs,
    MAX_HERALD_ARMOR_ITEMLEVEL  = 226,
    MAX_HERALD_WEAPON_ITEMLEVEL = 232,
};

enum UlduarEvents
{
    EVENT_DESPAWN_ALGALON       = 1,
    EVENT_UPDATE_ALGALON_TIMER  = 2,
    EVENT_FLAME_LEVIATHAN_1,
    EVENT_FLAME_LEVIATHAN_2,
    EVENT_FLAME_LEVIATHAN_3,
    EVENT_FLAME_LEVIATHAN_4,

    ACTION_INIT_ALGALON         = 6,
    ACTION_INIT_ALGALON_FIRST   = 7,
};

enum YoggSaronIllusions
{
    CHAMBER_ILLUSION            = 0,
    ICECROWN_ILLUSION           = 1,
    STORMWIND_ILLUSION          = 2,
};

enum UlduarArea
{
    MAP_ULDUAR                  = 603,
    AREA_FORMATION_GROUNDS      = 4652
};

enum UlduarAreaTriggers
{
    AT_REPAIR_STATION_1     = 5369,
    AT_REPAIR_STATION_2     = 5423,
    AT_TOWER_OF_LIFE        = 5414,
    AT_TOWER_OF_FLAME       = 5415,
    AT_TOWER_OF_FROST       = 5416,
    AT_TOWER_OF_STORM       = 5417,
    AT_TELEPORTER_EVENT     = 5420,
    AT_LORE_KEEPER_EVENT    = 5388,
    AT_BUNKERS_1            = 5443,
    AT_BUNKERS_2            = 5428,
    AT_BUNKERS_3            = 5426,
    AT_BUNKERS_4            = 5442,

    RADIO_ORBITAL_SUPPORT   = 10000,
};

template<class AI>
CreatureAI* GetInstanceAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_ulduar"))
                return new AI(creature);
    return nullptr;
}

template<class AI>
GameObjectAI* GetInstanceAI(GameObject* go)
{
    if (InstanceMap* instance = go->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_ulduar"))
                return new AI(go);
    return nullptr;
}

class PlayerOrPetCheck
{
    public:
        bool operator()(WorldObject* object) const
        {
            if (object->GetTypeId() != TYPEID_PLAYER)
                if (!object->ToCreature()->IsPet())
                    return true;

            return false;
        }
};

class NoPlayerOrPetCheck
{
    public:
        bool operator() (WorldObject* object) const
        {
            if (object->GetTypeId() != TYPEID_PLAYER)
                if (!object->ToCreature()->IsPet())
                    return false;

            return true;
        }
};

#endif
