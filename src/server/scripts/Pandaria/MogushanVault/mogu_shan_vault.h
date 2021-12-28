#ifndef MOGUSHAN_VAULT_H_
#define MOGUSHAN_VAULT_H_

#define CRYSTALL_AURA 4
#define WYVERN_TAXI 5
#define ENCOUNTERS 6
#define MAX_TILES 12
#define MAX_CHO_WP 26
#define MAX_TILES_ON_LINE 33 // in totally i`m so lazy for calculate it :D

const Position TilesStartPos[MAX_TILES]
{
    { 3885.07f, 1267.91f, 466.17f, 4.721f }, // affix -4.1f
    { 3881.01f, 1267.91f, 466.17f, 4.721f },
    { 3876.86f, 1267.91f, 466.17f, 4.721f },
    { 3872.87f, 1267.91f, 466.17f, 4.721f },
    { 3868.81f, 1267.91f, 466.17f, 4.721f },
    { 3864.75f, 1267.91f, 466.17f, 4.721f },
    { 3913.77f, 1267.91f, 466.17f, 4.721f },
    { 3917.99f, 1267.91f, 466.17f, 4.721f },
    { 3921.94f, 1267.91f, 466.17f, 4.721f },
    { 3926.14f, 1267.91f, 466.17f, 4.721f },
    { 3930.19f, 1267.91f, 466.17f, 4.721f },
    { 3934.25f, 1267.91f, 466.17f, 4.721f }
};

const Position GarajalTaxiWp[WYVERN_TAXI]
{
    { 4231.59f, 1415.06f, 482.75f, 5.53f },
    { 4294.19f, 1349.56f, 476.52f, 5.14f },
    { 4281.10f, 1322.09f, 470.31f, 2.63f },
    { 4278.97f, 1341.31f, 462.61f, 3.17f },
    { 4321.33f, 1284.60f, 465.18f, 5.29f }
};

const Position ChoWaypoints[MAX_CHO_WP]
{
    { 3899.61f, 1065.92f, 485.61f, 1.57f },
    { 3899.62f, 1075.77f, 481.13f, 1.57f },
    { 3899.46f, 1093.46f, 481.13f, 1.57f }, // Quilen
    { 3899.40f, 1141.01f, 481.13f, 1.57f },
    { 3899.31f, 1166.93f, 466.17f, 1.57f },
    { 3899.08f, 1258.88f, 466.17f, 1.57f },
    { 3898.90f, 1266.85f, 470.83f, 1.57f },
    { 3899.30f, 1290.44f, 470.83f, 1.57f }, // Door opened
    { 3899.46f, 1310.37f, 470.89f, 1.57f },
    { 3899.37f, 1320.83f, 466.42f, 1.57f },
    { 3899.45f, 1341.52f, 466.56f, 0.02f }, // Cursed mogu
    { 3919.74f, 1341.47f, 466.42f, 0.02f },
    { 3930.33f, 1341.61f, 461.94f, 0.02f },
    { 3947.74f, 1341.54f, 461.94f, 0.02f }, // Feng
    { 4122.83f, 1341.56f, 461.91f, 0.02f },
    { 4136.24f, 1341.61f, 461.91f, 0.02f }, // Talk about Zandalari
    { 4175.31f, 1341.69f, 461.91f, 0.02f },  // Talk Garajal
    { 4285.19f, 1531.82f, 438.78f, 3.64f },
    { 4259.42f, 1531.59f, 423.93f, 3.15f },
    { 4226.63f, 1488.79f, 423.93f, 4.70f }, // Talk about Zian
    { 4192.69f, 1489.01f, 423.93f, 4.70f }, // Talk about Qiang
    { 4178.07f, 1489.12f, 423.93f, 4.70f }, // Talk about Subetai
    { 4163.81f, 1488.84f, 423.93f, 3.17f }, // Talk about Meng
    { 4176.84f, 1540.98f, 423.93f, 1.60f },
    { 4177.08f, 1566.69f, 438.79f, 1.60f },
    { 4182.71f, 1574.30f, 438.79f, 0.01f }
};

const Position EncountersEntrance[ENCOUNTERS - 3]
{
    { 3861.55f, 1045.11f, 490.17f, 0.00f }, // Original Entrance
    { 3963.22f, 1384.11f, 461.95f, 4.72f }, // after feng defeat
    { 4241.00f, 1483.24f, 423.79f, 1.59f }, // after spirit kings defeat
};

const Position ChoPastStoneGuardsSpawn = { 3894.55f, 1298.70f, 470.87f, 5.4f  };
const Position ChoPastFengSpawn        = { 4093.19f, 1354.93f, 461.91f, 4.72f };
const Position ChoPastGarajalSpawn     = { 4290.11f, 1536.00f, 438.80f, 4.77f };
const Position GarajalHomePos          = { 4276.72f, 1341.38f, 454.46f, 3.12f };
const Position GhostEssenceMovePos     = { 3989.27f, 1341.67f, 470.82f, 3.15f };
const Position GhostEssenceFeng        = { 4042.24f, 1342.09f, 470.52f, 3.19f };

enum eData
{
    DATA_STONE_GUARD                        = 0,
    DATA_FENG,
    DATA_GARAJAL,
    DATA_SPIRIT_KINGS,
    DATA_ELEGON,
    DATA_WILL_OF_EMPEROR,
    DATA_STONE_GUARD_STATE,
    DATA_SPIRIT_KINGS_STATE,
    DATA_SPIRIT_SECOND,
    DATA_SPIRIT_THIRD,
    DATA_SPIRIT_FOUR,
    DATA_MAX_BOSS_DATA,
    DATA_LFR,
    DATA_LFR_SECOND_QUARTER,
};

enum eTypes
{
    TYPE_PETRIFICATION = 0,
};

enum eActions
{
    ACTION_ENTER_COMBAT                     = 1,
    ACTION_FAIL                             = 2,

    // Stone Guard
    ACTION_GUARDIAN_DIED                    = 3,
    ACTION_PETRIFICATION                    = 4,

    // Feng
    ACTION_SPARK                            = 5,

    // Spirit Kings
    ACTION_FIRST_FIGHT                      = 6,
    ACTION_FLANKING_MOGU                    = 7,
    ACTION_SAY_INTRO_FOR_NEXT_SPIRIT_IF_ANY = 8,
    ACTION_SPIRIT_KILLED                    = 9,

    ACTION_CONTINUE_ESCORT                  = 10,
    ACTION_RUN                              = 11,
    ACTION_SAY_ZANDALARI_BEGIN              = 12,
    ACTION_SAY_ZANDALARI_DEATH              = 13,

    ACTION_SET_GHOST_VISUAL                 = 14,
    ACTION_SET_NATIVE_DISPLAYID             = 15,

    ACTION_SETDISPLAYID_QIANG               = 16,
    ACTION_SETDISPLAYID_SUBETAI             = 17,
    ACTION_SETDISPLAYID_ZIAN                = 18,
    ACTION_SETDISPLAYID_MENG                = 19,

    ACTION_BEFORE_COMBAT                    = 20,
    ACTION_START_FIRST_COMBAT               = 21,
    ACTION_END_FIRST_COMBAT                 = 22,
    ACTION_START_SECOND_COMBAT              = 23,
    ACTION_END_SECOND_COMBAT                = 24,
    ACTION_START_THIRD_COMBAT               = 25,
    ACTION_END_THIRD_COMBAT                 = 26,
    ACTION_START_FOURTH_COMBAT              = 27,
    ACTION_END_FOURTH_COMBAT                = 28,

    ACTION_KEEPER_ENTER_COMBAT              = 29,
    ACTION_KEEPER_DIED                      = 30,
    ACTION_ELEGON_GO_ACTIVATION             = 31,
    ACTION_TALK_WILL_OF_EMPEROR             = 32,
    ACTION_EMPERORS_DEATH                   = 33,
    ACTION_ACTIVATE_SPIRIT                  = 34,

    // Heroic Feng
    ACTION_SCHEDULE_SHIELD                  = 35,

    // Heroic Stone Guard
    ACTION_POWER_DOWN                       = 36,
    ACTION_TILING                           = 37,

    // Lorewalker Cho
    ACTION_CHO_DOGS_DIE                     = 38,
    ACTION_CHO_FENG_DIE                     = 39,
    ACTION_SPIRIT_KINGS_INTRO               = 40,
    ACTION_CURSED_MOGU_ATTACK_PLAYER        = 41,

    // Achievements Misc
    ACTION_PILLAGE_ACHIEVEMENT              = 42,
    ACTION_EVADE                            = 43,
    ACTION_SPECIAL_DESPAWN_UNDYING_SHADOWS  = 44,
};

enum eDogPets
{
    PET_WORG_PUP           = 10259,
    PET_CURIOUS_WOLVAR_PUP = 33529,
    PET_CORE_HOUND_PUP     = 36871,
    PET_PERKY_PUG          = 37865,
    PET_FOX_KIT            = 48641,
    PET_LUCKY_QUILEN_CUB   = 85871,
};

enum eCreatures
{
    // Lorewalker Cho
    NPC_LOREWALKER_CHO              = 61348,

    // The Stone Guard
    NPC_STONE_GUARD_CONTROLLER      = 60089,
    NPC_JASPER                      = 59915,
    NPC_JADE                        = 60043,
    NPC_AMETHYST                    = 60047,
    NPC_COBALT                      = 60051,
    NPC_COBALT_MINE                 = 65803,
    NPC_TILING_CREATURE             = 62026,
    NPC_LIVING_COBALT_CRYSTAL       = 60304,
    NPC_LIVING_JADE_CRYSTAL         = 60306,
    NPC_LIVING_JASPER_CRYSTAL       = 60307,
    NPC_LIVING_AMETHYST_CRYSTAL     = 60308,
    NPC_STONE_QUILEN                = 60576,
    NPC_FRENZIED_STONE_QUILEN       = 60833, // i`ll use it like trigger for found any stone quilen around his area.
    NPC_ENORMOUS_STONE_QUILEN       = 64183,

    // Feng
    NPC_CURSED_MOGU_SCULPTURE_1     = 61989,
    NPC_CURSED_MOGU_SCULPTURE_2     = 61334,
    NPC_GHOST_ESSENCE               = 62004,
    NPC_FENG                        = 60009,
    NPC_PHASE_CONTROLLER            = 61124,
    NPC_WILDFIRE_SPARK              = 60438,
    NPC_SIPHONING_SHIELD            = 60627,
    NPC_SOUL_FRAGMENT               = 60781,
    NPC_LIGHTNING_CHARGE            = 60241,

    // Garajal
    NPC_GARAJAL                     = 60143,
    NPC_ZANDALARI_WAR_WYVERN        = 60385,
    NPC_ZANDALARI_SKULLCHARGER      = 60375,
    NPC_ZANDALARI_FIRE_DANCER       = 60402,
    NPC_ZANDALARI_INFILTRATOR       = 60381,
    NPC_SHADOWY_MINION_REAL         = 60940,
    NPC_SHADOWY_MINION_SPIRIT       = 60184,
    NPC_SOUL_CUTTER                 = 62003,
    NPC_SPIRIT_TOTEM                = 60240,
    NPC_SPIRIT_TOTEM_INTRO          = 60512,
    NPC_SPIRIT_TOTEM_SKULL_INTRO    = 60513,
    NPC_SPIRITUAL_PORTAL            = 61172,
    NPC_EXPLOSION_BUNNY_N_M         = 60388,
    NPC_EXPLOSION_BUNNY_N_P         = 60392,
    NPC_EXPLOSION_BUNNY_S_M         = 60390,
    NPC_EXPLOSION_BUNNY_S_P         = 60394,
    NPC_EXPLOSION_BUNNY_E_M         = 60389,
    NPC_EXPLOSION_BUNNY_E_P         = 60395,
    NPC_EXPLOSION_BUNNY_W_M         = 60391,
    NPC_EXPLOSION_BUNNY_W_P         = 60393,
    NPC_ZANDALARI_PTERROR_WING      = 60384,
    NPC_ZANDALARI_TERROR_RIDER      = 60386,
    NPC_TROLL_EXPLOSIVES            = 60644,

    // Spirit Kings Pre event
    NPC_ZIAN_THE_ENDLESS_SHADOW     = 61421,
    NPC_QIANG_THE_MERCILESS         = 61423,
    NPC_SUBETAI_THE_SWIFT           = 61427,
    NPC_MENG_THE_DEMENTED           = 61429,
    NPC_SORCERER_MOGU               = 61250,
    NPC_MOUNTED_MOGU                = 61341,
    NPC_MOGU_ARCHER                 = 61345,
    NPC_KINGSGUARD                  = 61347,

    // Spirit kings
    NPC_SPIRIT_GUID_CONTROLLER      = 60984,

    NPC_ZIAN                        = 60701,
    NPC_MENG                        = 60708,
    NPC_QIANG                       = 60709,
    NPC_SUBETAI                     = 60710,

    NPC_FLANKING_MOGU               = 60847,
    NPC_PINNING_ARROW               = 60958,

    NPC_UNDYING_SHADOW              = 60731,

    // Elegon
    NPC_ELEGON                      = 60410,

    NPC_MOGUSHAN_ARCANIST           = 64063,
    NPC_MOGUSHAN_WARDEN_T           = 64061,
    NPC_EMPYREAL_FOCUS              = 60776,
    NPC_CELESTIAL_PROTECTOR         = 60793,
    NPC_INFINITE_ENERGY             = 65293,
    NPC_ENERGY_CHARGE               = 60913,
    NPC_MOGUSHAN_ENGINE_KEEPER      = 64068,

    // Will of Emperor
    NPC_QIN_XI                      = 60399,
    NPC_JAN_XI                      = 60400,

    NPC_MOGUSHAN_SECRET_KEEPER      = 61131,
    NPC_SHAN_XI_WATERSHAPER         = 61139,
    NPC_EMPEROR_RAGE                = 60396,
    NPC_EMPEROR_STRENGHT            = 60397,
    NPC_EMPEROR_COURAGE             = 60398,
    NPC_TITAN_SPARK                 = 60480,
    NPC_MOGUSHAN_WARDEN             = 64947,

    NPC_GENERAL_PURPOSE_BUNNY_JMF    = 55091,
    NPC_ANCIENT_MOGU_MACHINE         = 60648,
    NPC_TERRACOTA_BOSS               = 60575, // this trigger used for cast devast arc (not visual)
    NPC_EMPEROR_STRENGTH_TRIGGER     = 60768,
};

enum eGameObjects
{
    GO_STONE_GUARD_DOOR_ENTRANCE   = 214497,
    GO_STONE_GUARD_DOOR_EXIT       = 214526,
    GO_FENG_DOOR_FENCE             = 214452, // Both entrance and exit
    GO_FENG_DOOR_EXIT              = 214696,
    GO_GARAJAL_FENCE               = 213933, // Both entrance and exit
    GO_GARAJAL_EXIT                = 213285,
    GO_SPIRIT_KINGS_WIND_WALL      = 215114,
    GO_SPIRIT_KINGS_EXIT           = 213373,

    // Elegon
    GO_CELESTIAL_DOOR              = 214412,
    GO_ELEGON_DOOR_ENTRANCE        = 213244,
    GO_ELEGON_CELESTIAL_DOOR       = 214412,
    GO_WILL_OF_EMPEROR_ENTRANCE    = 213258,
    GO_ELEGON_CHEST                = 214383,
    GO_ELEGON_CHEST_HEROIC         = 214384,

    // Feng
    GO_SPEAR_STATUE                = 213245,
    GO_FIST_STATUE                 = 213246,
    GO_SHIELD_STATUE               = 213247,
    GO_STAFF_STATUE                = 213248,

    GO_INVERSION                   = 211628,
    GO_CANCEL                      = 211626,

    // Elegon
    GO_ENERGY_PLATFORM             = 213526,
    GO_ENERGY_TITAN_DISK           = 213506,
    GO_ENERGY_TITAN_CIRCLE_1       = 213528,
    GO_ENERGY_TITAN_CIRCLE_2       = 213527,
    GO_ENERGY_TITAN_CIRCLE_3       = 213529,
    GO_CELESTIAL_COMMAND           = 211650,

    GO_MOGU_RUNE_FIRST             = 213937,
    GO_MOGU_RUNE_END               = 213955,

    // Will of Emperator
    GO_TERRACOTTA_DOOR             = 211603,
    GO_ANCIEN_CONTROL_CONSOLE      = 211584
};

enum Types
{
    TYPE_GHOST_ESSENCE_STATE,
    TYPE_BANISHMENT,
    TYPE_GUARDIAN_LOOT,
};

enum sharedSpells
{
    SPELL_BERSERK                   = 26662,
    SPELL_STONE                     = 120663,
    SPELL_BRONZE                    = 120661,
};

enum iEvents
{
    EVENT_RESET_WOE_CONSOLE = 1
};

const std::vector<uint32> vDogs =
{
    PET_WORG_PUP,
    PET_CURIOUS_WOLVAR_PUP,
    PET_CORE_HOUND_PUP,
    PET_PERKY_PUG,
    PET_FOX_KIT,
    PET_LUCKY_QUILEN_CUB,
};

#endif // MOGUSHAN_VAULT_H_
