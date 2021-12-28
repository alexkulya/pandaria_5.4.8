#ifndef HEART_OF_FEAR_H_
#define HEART_OF_FEAR_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

#define DataHeader "HOF"
#define heart_of_fear_scriptname "instance_heart_of_fear"
#define MAX_TYPES 6
#define ZORLOK_MAX 4
#define INSTRUCTORS_MAX 5 // diff last points [prim 4] cuz we need switch point for each
#define SWARM 3
#define ROYAL_GUARDS 2
#define DISSONANCE_FIELD 2
#define SHA_MAX 2
#define M_PI_DEGREES 180.0f

const Position GaralonSpawn     = { -1834.48f, 474.18f, 445.83f,  3.04f   };
const Position AbominationSpawn = { -2538.82f, 709.22f, 581.54f,  0.49f   };
const Position UnsokUnleashed   = { -2479.47f, 699.75f, 580.08f,  4.71f   };
const Position ShaOfFearSpawn   = { -2478.57f, 1077.41f, 579.98f, 4.71f   };
const Position EmpressCrysalis  = { -2478.99f, 1077.61f, 572.82f, 4.83f   };
const Position PlayerTelePos    = { -2119.34f, 281.375f, 420.901f, 0.053f }; // Tele point for players on P2 start.
const Position PlayerVehPos     = { -2119.15f, 184.444f, 422.24f, 1.64f   }; // end point of players vehicle at 2td phase

const Position TayakStormPoints[2] =
{
    { -2119.072f, 379.372f, 422.162f, 4.703f }, // 20 - 10% TP point 
    { -2119.072f, 184.985f, 422.162f, 1.585f }  // 10 -  0% TP point
};

const Position ZorlokWaypoints[ZORLOK_MAX]
{
    {-2238.86f, 222.48f, 427.52f, 2.37f}, // set facing to o-pi/4
    { -2315.28f, 298.20f, 427.52f, 5.50f }, // set o-pi
    { -2276.06f, 259.36f, 427.52f, 3.96f }, // set o-pi/2
    { -2300.39f, 233.56f, 427.52f, 0.78f } // set o-pi
};

const Position zorlokPlatforms[3] =
{
    { -2317.21f, 300.67f, 409.90f, 0.0f },  // SW Platform
    { -2234.36f, 216.88f, 409.90f, 0.0f },  // NE Platform
    { -2315.77f, 218.20f, 409.90f, 0.0f },  // SE Platform
};

const Position zorlokReachPoints[3] =
{
    { -2317.21f, 300.67f, 420.0f, 0.0f },  // NE Platform
    { -2234.50f, 216.72f, 420.0f, 0.0f },  // SW Platform
    { -2315.77f, 218.20f, 420.0f, 0.0f },  // SE Platform
};

const Position oratiumCenter[2] =
{
    { -2274.80f, 259.19f, 420.0f, 0.318021f },
    { -2274.80f, 259.19f, 406.5f, 0.318021f }
};

// 212943 - Final Phase Door
const Position finalPhaseWalls1[3] =
{
    { -2299.195f, 282.5938f, 408.5445f, 2.383867f },
    { -2250.401f, 234.0122f, 408.5445f, 2.333440f },
    { -2299.63f, 233.3889f, 408.5445f, 0.7598741f }
};

// 212916 - Arena Walls
const Position finalPhaseWalls2[3] =
{
    { -2255.168f, 308.7326f, 406.0f, 0.7853968f },
    { -2240.0f, 294.0f, 406.0f, 0.7853968f },
    { -2225.753f, 280.1424f, 406.381f, 0.7853968f },
};

const Position tabCenter = { -2275.27f, 258.48f, 406.38f };

const float rangeAttenuation1[2][2] =
{
    -2256.0f, -2208.0f,
    190.0f, 240.0f
};

const float rangeAttenuation2[2][2] =
{
    // Coords to redone
    -2297.0f, -2250.0f,
    237.0f, 280.0f
};

const Position KlithakMaltikWaypoints[INSTRUCTORS_MAX]
{
    {-2104.61f,300.10f,422.16f,0.0f},
    {-2109.17f,304.02f,421.00f,0.0f},
    {-2118.90f,336.95f,420.90f,0.0f},
    {-2068.38f,337.35f,420.39f,0.0f}, // Klithak
    {-2169.81f,337.27f,420.39f,0.0f}  // Maltik
};

const Position TakthokZarikWaypoints[INSTRUCTORS_MAX]
{
    {-2104.54f,259.20f,422.16f,0.0f},
    {-2109.10f,252.33f,421.02f,0.0f},
    {-2118.84f,226.58f,420.90f,0.0f},
    {-2169.81f,225.26f,420.39f,0.0f}, // Zarik
    {-2068.45f,225.54f,420.39f,0.0f}  // Takthok
};

const Position KorthikSpawn[SWARM]
{
    {-2088.58f, 483.263f, 503.57f, 3.2f},
    { -2092.15f, 475.87f, 503.56f, 3.2f },
    { -2088.77f, 468.71f, 503.56f, 3.2f }
};

const Position ZarthikSpawn[SWARM]
{
    {-2076.62f, 467.52f, 503.57f, 3.2f},
    { -2080.39f, 459.07f, 503.57f, 3.2f },
    { -2072.23f, 454.48f, 503.57f, 3.2f }
};

const Position SrathikSpawn[SWARM]
{
    {-2072.11f, 498.11f, 503.56f, 3.2f},
    { -2080.35f, 493.19f, 503.56f, 3.2f },
    { -2075.78f, 485.97f, 503.56f, 3.2f }
};

const Position SwarmLanding[SWARM - 1]
{
    { -2025.82f, 476.21f, 524.62f, 3.16f },
    { -2061.28f, 476.08f, 503.56f, 3.14f }
};

const Position RoyalGuardsSpawn[ROYAL_GUARDS]
{
    {-2558.73f, 1012.77f, 569.62f, 6.09f},
    { -2397.58f, 1014.13f, 569.62f, 3.33f }
};

const Position DissonanceField[DISSONANCE_FIELD]
{
    { -2489.33f, 990.29f, 569.63f, 1.16f },
    { -2470.39f, 987.59f, 569.62f, 1.86f }
};

const Position ShaWaypoints[SHA_MAX]
{
    { -2478.34f, 1013.28f, 571.13f, 4.73f },
    { -2478.00f, 1013.00f, 738.67f, 2.80f },
};

const Position EncountersEntrance[MAX_TYPES - 1]
{
    { -2378.92f, 459.879f, 422.441f, 0.00f }, // Original Entrance
    { -2119.51f, 181.29f,  422.16f,  1.48f }, // after tayak defeat
    { -2035.31f, 476.00f,  473.11f,  6.28f }, // after garalon defeat
    { -2084.87f, 475.88f,  503.57f,  3.06f }, // after Meljarak defeat
    { -2478.69f, 624.60f,  581.55f,  1.51f }, // after Unsok defeat
};

enum eData
{
    DATA_ZORLOK                         = 0,
    DATA_TAYAK,
    DATA_GARALON,
    DATA_MELJARAK,
    DATA_UNSOK,
    DATA_SHEKZEER,
    DATA_MAX_BOSS_DATA,
    DATA_LFR,
    DATA_LFR_SECOND_QUARTER,
};

enum eGameObjects
{
    GO_ANTECHAMBER_DOOR_ENTRANCE        = 214483,
    GO_ANTECHAMBER_DOOR_EXIT            = 214484,
    GO_ORATIUM_DOOR_ENTRANCE            = 214485,
    GO_QUARTERS_DOOR_ENTRANCE           = 214486,
    GO_QUARTERS_DOOR_EXIT               = 214487,
    GO_STAIRWAYS_DOOR_EXIT              = 214488,
    GO_BALCONY_DOOR_EXIT                = 214489,
    GO_ATRIUM_DOOR_ENTRANCE             = 214490,
    GO_ATRIUM_DOOR_EXIT                 = 214491,
    GO_SANCTUM_DOOR_ENTRANCE            = 214492,
    GO_HEARTOFFEAR_DOOR_ENTRANCE        = 214493,
    GO_GARALON_DOOR_UPPER               = 214634,
    GO_GARALON_DOOR                     = 212695,

    // Meljarak
    GO_MANTID_WEAPON_RACK               = 212386,

    // Zor'lok Barriers
    GO_ARENA_WALLS                      = 212916,
    GO_FINAL_PHASE_WALLS                = 212943,

    // Shek`zeer go
    GO_EMPRESS_CHRYSALIS                = 213277,
    GO_TOP_HEART_OF_FEAR                = 213276,
};

enum eActions
{
    ACTION_MELJARAK_LEAVE               = 0,
    ACTION_MELJARAK_GARALON_IN_COMBAT   = 1,
    ACTION_TAYAK_TALK_TRASH             = 2,
    ACTION_INSTRUCTORS_MOVE             = 3,
    ACTION_TAYAK_ENTRANCE               = 4,
    ACTION_GARALON_INITIALIZE           = 5,
    ACTION_TAYAK_PREEVENT_DONE          = 6,
    ACTION_ROYAL_GUARDIAN_DIE           = 7,
    ACTION_MISC                         = 8,
};

enum eCreature
{
    // bosses
    NPC_IMPERIAL_VIZIER_ZORLOK          = 62980,
    NPC_BLADE_LORD_TAYAK                = 62543,
    NPC_GARALON                         = 62164,
    NPC_WIND_LORD_MELJARAK              = 62397,
    NPC_AMBER_SHAPER_UNSOK              = 62511,
    NPC_GRAND_EMPRESS_SHEKZEER          = 62837,

    //Zorlok
    NPC_STORM_SPIRIT                    = 69680,
    NPC_SONIC_RING_FORWARD              = 62689,
    NPC_SONIC_RING_30LEFT               = 62694,
    NPC_SONIC_RING_30RIGHT              = 62696,
    NPC_SONIC_RING_60LEFT               = 62716,
    NPC_SONIC_RING_60RIGHT              = 62717,
    NPC_SONIC_RING_120LEFT              = 62718,
    NPC_SONIC_RING_120RIGHT             = 62719,
    NPC_SONIC_RING_90LEFT               = 62726,
    NPC_SONIC_RING_90RIGHT              = 62727,
    NPC_SONIC_RING_150LEFT              = 62743,
    NPC_SONIC_RING_150RIGHT             = 62744,
    NPC_SONIC_RING_BACK                 = 62746,
    NPC_GENERAL_BUNNY_JMF               = 45979, // main idea in using this triggers in concept like wall/texture for correct spawn noised cancell
    NPC_INHALE_POINT                    = 63563,
    NPC_PLAYER_KICKER                   = 65756,

    // Heroic Adds
    NPC_ECHO_OF_ATTENUATION             = 65173,
    NPC_ECHO_OF_FORCE_AND_VERVE         = 65174,
    NPC_SONIC_PULSE_40RIGHT             = 63835,
    NPC_SONIC_PULSE_40LEFT              = 63836,
    NPC_SONIC_PULSE_225LEFT             = 63837,

    // Ta'yak
    NPC_TAYAK                           = 62543,
    NPC_TEMPEST_TARGET                  = 62897,
    NPC_TEMPEST_STALKER                 = 62908,
    NPC_GALE_WINDS_STALKER              = 63292,
    NPC_STORM_UNLEASHED_EAST1           = 63301,
    NPC_STORM_UNLEASHED_EAST2           = 63302,
    NPC_STORM_UNLEASHED_EAST3           = 63303,
    NPC_STORM_UNLEASHED_WEST1           = 63278,
    NPC_STORM_UNLEASHED_WEST2           = 63299,
    NPC_STORM_UNLEASHED_WEST3           = 63300,
    NPC_STORM_PLAYER_VEHICLE            = 63567,
    NPC_STORM_UNLEASHED_STALKER_EAST1   = 63212,
    NPC_STORM_UNLEASHED_STALKER_EAST2   = 63213,
    NPC_STORM_UNLEASHED_STALKER_EAST3   = 63214,
    NPC_STORM_UNLEASHED_STALKER_WEST1   = 63207,
    NPC_STORM_UNLEASHED_STALKER_WEST2   = 63208,
    NPC_STORM_UNLEASHED_STALKER_WEST3   = 63209,
    NPC_BRAZIER                         = 65593,

    // Garalon
    NPC_KORTHIK_ELITE_BLADEMASTER       = 65500,
    NPC_ZARTHIK_BATTLE_MENDER           = 65498,
    NPC_SRATHIK_AMBER_TRAPPER           = 65499,
    NPC_WIND_LORD_MELJARAK_INTRO        = 65501,
    NPC_ZETTHIK_GUSTWIND                = 63592,
    NPC_ZETTHIK_ZEPHYRIAN               = 63593,
    NPC_GARALON_LEG                     = 63053,
    NPC_PHEROMONE_TRAIL                 = 63021,

    // Mel`jarak
    NPC_WHIRLING_BLADE                  = 63930,
    NPC_WIND_BOMB                       = 67053,
    NPC_CORROSIVE_RESIN_POOL            = 67046,
    NPC_KORTHIK_SPAWN_HEROIC            = 62447, // point where swarm is spawn for fly to patform in heroic [If group were killed]
    NPC_ZARTHIK_SPAWN_HEROIC            = 62452,
    NPC_SRATHIK_SPAWN_HEROIC            = 62451,
    NPC_AMBER_PRISON                    = 62531,

    // Unsok
    NPC_MUTATED_CONSTRUCT               = 62701, // Player abominatio. some vehicle for players that affected by reshaper?
    NPC_BURNING_AMBER                   = 62512,
    NPC_MOLTEN_AMBER                    = 62513,
    NPC_AMBER_MONSTROSITY               = 62711,
    NPC_AMBER_POOL_STALKER              = 62762,
    NPC_LIVING_AMBER                    = 62691,
    NPC_AMBER_SCALPEL                   = 62510,
    NPC_AMBER_GLOBULE                   = 73332,

    //Shek`zeer
    NPC_STICKY_RESIN                    = 63730,
    NPC_BUBBLING_RESIN                  = 64383,
    NPC_AMBER_TRAP_SHEKZEER             = 64351,
    NPC_SHA_OF_FEAR                     = 63942,
    NPC_SETTHIK_WINDBLADE               = 64453,
    NPC_KORTHIK_REAVER                  = 63591,
    NPC_DISSONANCE_FIELD                = 62847,

    // Trash
    NPC_SETTHIK_TEMPEST                 = 64358,
    NPC_KORTHIK_SLICER                  = 63048,
    NPC_KORTHIK_EXTREMIST               = 63036,
    NPC_KAZRIK                          = 64826,
    NPC_SPEARED_KLAXXI                  = 65521,
    NPC_MANTID_SPEAR                    = 65519, // vehicle for 65521
    NPC_SPEARED_KLAXXI_2                = 65524,
    NPC_SETTHIK_SWIFTBLADE              = 63049,
    NPC_SRATHIK_SHIELD_MASTER           = 63032,
    NPC_ZARTHIK_SUPPLICANT              = 63853,
    NPC_SETTHIK_ZEPHYRIAN               = 63593,
    NPC_BURNING_BRAZIER                 = 65597,
    NPC_ZARTHIK_BATTLEMENDER            = 65498,
    NPC_JADE_SERPENT_STATUE             = 60849,
    NPC_KORTHIK_SILENTWING              = 64355,
    NPC_ZARTHIK_SUPPLICANT_2            = 67177,
    NPC_SETTHIK_GALESLICER              = 64353,
    NPC_XUEN                            = 63508,
    NPC_ENSLAVED_BONESMASHER            = 63030,
    NPC_ZARTHIK_SUPPLICANT_3            = 66181,
    NPC_SETTHIK_FANATIC                 = 63031,
    NPC_INSTRUCTOR_MALTIK               = 64340,
    NPC_INSTRUCTOR_KLITHAK              = 64338,
    NPC_INSTRUCTOR_ZARIK                = 64341,
    NPC_INSTRUCTOR_TAKTHOK              = 64339,
    NPC_ZARTHIK_ZEALOT                  = 63035,
    NPC_KORTHIK_SWARMER                 = 64357,
    NPC_SETTHIK_GUSTWING                = 63592,
    NPC_KORTHIK_SWARMGUARD              = 64916, 
    NPC_SRATHIK_AMBERCALLER             = 64917,
    NPC_KORTHIK_FLESHRENDER             = 64902,
    NPC_SRATHIK_POOL_TENDER             = 63570, 
    NPC_AMBER_RIDDEN_MUSHAN             = 63568, // script
    NPC_AMBER_GROWTH                    = 64132, // script for muchan
    NPC_AMBER_SEARSTRING                = 63569,
    NPC_COAGULATED_AMBER                = 63597, // script
    NPC_SETTHIK_WINDBLADE_T             = 63589,
    NPC_ZARTHIK_AUGURER                 = 64454,
    NPC_KORTHIK_WARSINGER               = 64458,
    NPC_WORLD_TRIGGER                   = 59481,
};

enum iSpells
{
    SPELL_MANTID_SPRAY                  = 128723,
    SPELL_RIDE_VEHICLE_HARDCODED        = 46598,
};

enum eTypes
{
    // Zor'lok
    TYPE_EXHALE_TARGET                  = 1,
    // Tayak
    TYPE_NEW_STORMID                    = 2,
    TYPE_CURRENT_STORMID                = 3,
    TYPE_TARGET_ID                      = 4,
    TYPE_MELJARAK_RECKLESSNES           = 5,
    TYPE_UNSOK_ALTER_TANK_PRIORITY      = 6,
    TYPE_WHIRLING_BLADE                 = 7,
    TYPE_PHEROMONES_DELAY               = 8,
    TYPE_UNSOK_PHASE                    = 9,
    TYPE_ZORLOK_LAST_ECHO               = 10,
    TYPE_BRAZIERS,
};

enum Worldstates
{
    WORLDSTATE_CANDLE_IN_THE_WIND     = 12411,
    WORLDSTATE_I_HEARD_YOU_LIKE_AMBER = 11934,
};

const std::vector<AuraType> controlMechanicType =
{
    SPELL_AURA_MOD_STUN,
    SPELL_AURA_MOD_FEAR,
    SPELL_AURA_MOD_FEAR_2,
    SPELL_AURA_MOD_BLIND,
    SPELL_AURA_MOD_CONFUSE,
    SPELL_AURA_MOD_ROOT,
};

const std::vector<uint32> meljarakSwarmType=
{
    NPC_WIND_LORD_MELJARAK,
    NPC_SRATHIK_AMBER_TRAPPER,
    NPC_KORTHIK_ELITE_BLADEMASTER,
    NPC_ZARTHIK_BATTLE_MENDER,
};

// weapons
#define MELJARAK_2H_WEAPON 89398
#define ZARTHIK_2H_WEAPON 89395
#define KORTHIK_2H_WEAPON 89394
#define SRATHIK_1H_WEAPON 89397

#define UNSOK_1H_WEAPON 86983

// types
#define DISPLAYID_INVISIBLE 11686
#define PI 3.141593f

#endif // HEART_OF_FEAR_H_
