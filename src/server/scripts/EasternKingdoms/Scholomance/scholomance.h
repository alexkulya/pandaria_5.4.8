#ifndef SCHOLOMANCE_H
#define SCHOLOMANCE_H

#define SCMScriptName "instance_scholomance"
#define MAX_ILLUSIONS 15
#define MAX_BONE_PILES 6

#define JandiceStuff 59184
#define LilianSword 50732
#define GandlingStaff 82859
#define RisenGuardSword 73475

const Position IllusionsPoints[MAX_ILLUSIONS] =
{
    { 311.34f, 47.12f, 113.40f, 3.15f },
    { 302.13f, 47.23f, 113.40f, 3.15f },
    { 292.95f, 47.17f, 113.40f, 3.15f },
    { 283.48f, 47.28f, 113.40f, 3.15f },
    { 274.34f, 47.05f, 113.40f, 3.15f },
    { 311.45f, 37.43f, 113.40f, 3.15f },
    { 302.22f, 37.55f, 113.40f, 3.15f },
    { 292.86f, 37.44f, 113.40f, 3.15f },
    { 283.59f, 37.50f, 113.40f, 3.15f },
    { 274.44f, 37.47f, 113.40f, 3.15f },
    { 311.10f, 22.84f, 113.40f, 3.15f },
    { 301.96f, 22.92f, 113.40f, 3.15f },
    { 292.53f, 22.99f, 113.40f, 3.15f },
    { 283.32f, 23.06f, 113.40f, 3.15f },
    { 274.00f, 23.14f, 113.40f, 3.15f }
};

const Position BonePilePoints[MAX_BONE_PILES] =
{
    {248.64f, 99.89f, 113.31f, 0.08f},
    { 247.84f, 80.36f, 113.34f, 0.07f },
    { 248.84f, 118.08f, 113.14f, 0.01f },
    { 274.29f, 118.16f, 113.18f, 3.16f },
    { 274.11f, 99.97f, 113.23f, 3.16f },
    { 274.08f, 80.70f, 113.24f, 3.08f },
};

const Position SoulFlamePoints[MAX_BONE_PILES] =
{
    { 277.25f, 117.79f, 114.369f, 3.075803f },
    { 277.14f, 99.54f, 113.726f, 3.181833f },
    { 277.27f, 80.90f, 113.738f, 3.126854f },
    { 245.32f, 80.81f, 113.600f, 6.248809f },
    { 245.39f, 100.112f, 113.869f, 6.268443f },
    { 246.01f, 117.728f, 113.715f, 6.260589f }
};

const Position SkullPath[30] =
{
    { 200.70f,  45.02f,  132.37f, 4.70f }, // s IC
    { 209.48f,  48.92f,  132.33f, 0.41f },
    { 229.89f,  49.09f,  119.22f, 0.00f },
    { 231.26f,  25.83f,  119.24f, 4.77f },
    { 215.05f, -22.02f,  119.22f, 4.38f },
    { 215.17f, -43.60f,  119.24f, 4.71f },
    { 225.47f, -43.50f,  119.24f, 6.27f },
    { 250.28f, -43.57f,  113.43f, 6.27f },
    { 261.05f, -43.73f,  113.43f, 6.27f },
    { 261.12f, -27.27f,  113.45f, 1.58f }, // not longest s [emote]
    { 258.16f,  11.97f,  113.40f, 1.58f }, // s JB
    { 259.08f,  67.95f,  113.49f, 1.55f }, // s RT
    { 259.05f,  139.99f, 113.33f, 1.59f },
    { 202.21f,  138.55f, 113.31f, 3.16f },
    { 202.28f,  126.76f, 113.31f, 4.71f }, // not longest s [till lilian event]
    { 202.39f,  119.86f, 113.37f, 4.72f },
    { 202.58f,  107.69f, 108.26f, 4.72f }, // s LV
    { 181.53f,  94.64f,  108.23f, 3.69f },
    { 182.85f,  74.08f,  108.23f, 4.77f },
    { 169.07f,  73.79f,  108.24f, 3.15f },
    { 165.94f,  73.66f,  106.53f, 3.17f },
    { 145.33f,  73.47f,  106.39f, 3.15f },
    { 130.90f,  63.96f,  106.40f, 3.72f },
    { 103.02f,  64.30f,  100.94f, 3.12f },
    { 95.71f,   101.35f, 100.92f, 2.40f },
    { 75.69f,   100.80f, 101.02f, 3.16f },
    { 75.65f,   90.38f,  101.02f, 4.74f },
    { 75.70f,   68.49f,   87.03f, 4.69f },
    { 59.60f,   58.23f,   87.02f, 3.69f },
    { 53.56f,   59.90f,   87.22f, 2.87f }  // s DG
};

const Position LilianTeleportPos = { 200.17f, 83.82f, 107.76f, 1.56f };
const Position GandlingTeleportPos = { 220.98f, 68.88f, 109.64f, 2.25f };
const Position GandlinglilianDoorPoint = { 261.03f, 132.80f, 113.49f, 1.59f };
const Position lilianDeathPoint = { 201.25f, 84.80f, 107.76f, 5.68f };
const Position GandlingLeavePoint = { 176.94f, 73.73f, 108.23f, 3.15f };

enum eSpells
{
    // Chillheart
    SPELL_ICE_WALL_INSTA_KILL           = 111231,
    SPELL_ICE_WALL_DUMMY_1              = 122443, // has visual effect
    SPELL_ICE_WALL_DUMMY_2              = 122449, // hasn`t
    SPELL_ICE_WALL_AREA_TRIGGER         = 122482,
    SPELL_COSMETIC_SHADOW_CHANNEL       = 122499,
    SPELL_ARCANE_BOMB_COSMETIC          = 113848,  // cosmetic at ground
    SPELL_ARCNE_BOMB_COSMETIC_SPHERE    = 109122,
    SPELL_FILL_PHYLACTERY               = 111441, // cosmetic implosion
    
    // Rattlegore
    SPELL_BONEWEAVING                   = 113647, // cosmetic
    SPELL_BONE_SHARDS                   = 113629,
    SPELL_BONE_WHIRL_WIND               = 114079,
    SPELL_BONE_STORM_COSMETIC           = 114076,

    SPELL_VISUAL_FIRE                   = 32993,
    SPELL_BURNING                       = 100397,
    SPELL_TELEPORT_VISUAL               = 41232,
    SPELL_SHADOW_STEP_VISUAL            = 127511,
    SPELL_BONE_ARMOR_VISUAL             = 11445,
    SPELL_SOUL_RIP_VISUAL               = 112058,

    // Lilian
    SPELL_COSMETIC_SOUL_RIP             = 112081, // aura beam on dummy
    SPELL_IMPROVED_BONE_SHIELD          = 113865,
    SPELL_GANDLING_INTRO_CHANNEL        = 114201, // aura behind
    SPELL_LILIAN_VOSS_DEAD              = 112057,
    SPELL_LILIAN_KNELL                  = 123821, // just emote
    SPELL_GANDLING_CASTING              = 112058,
};

enum eCreatures
{
    NPC_INSTRUCTOR_CHILLHEART           = 58633,
    NPC_JANDICE_BAROV                   = 59184,
    NPC_RATTLEGORE                      = 59153,
    NPC_LILIAN_VOSS                     = 59200,
    NPC_GRANDMASTER_GANDLING_1          = 58875,
    NPC_GRANDMASTER_GANDLING_2          = 59080,
    NPC_TALKING_SKULL                   = 64562,

    // stalkers
    NPC_ICE_WALL_STALKER                = 68291,
    NPC_ICE_WALL_STALKER_ENTRANCE       = 69582,
    NPC_ICE_WALL_MOVE                   = 62731,
    NPC_FROSTGRASP_STALKER              = 57860,
    NPC_GRAVITY_FLUX_STALKER            = 67272,

    // Chillheart
    NPC_ANARCHIST_ARCANIST              = 59707,
    NPC_ANTONIDAS_GUIDE                 = 66240,
    NPC_WANDERS_BOOK                    = 59227,
    NPC_PHYLACTERY                      = 58664,
    NPC_ARCANE_BOMB                     = 58753, // summoned vy arcanist book
    NPC_ARCANE_BOMB_CHASE               = 59711, // fall to ground
    NPC_BOOK_SPAWN_TARGET               = 58917,

    NPC_SCHOLOMANCE_NEOPHYTE            = 58823,
    NPC_SCHOLOMANCE_ACOLYTE             = 58757,

    // Jandice
    NPC_JANDICE_ILLUSION                = 59220,
    NPC_CANDLESTICK_MAGE                = 59467,
    NPC_CANDLE                          = 59481,

    // Rattlegore
    NPC_BONE_PILE                       = 59304,
    NPC_SOULFLAME_STALKER               = 59316,
    NPC_BONEWEAVER                      = 59193,
    NPC_WOVEN_BONEGUARD                 = 59242,
    NPC_SOULFLAME_ACTIVATED_STALKER     = 45979,

    // Lilian Voss
    NPC_LILIAN_SOUL                     = 58791,
    NPC_DARK_BLAZE                      = 58780,
    NPC_KRASTINOV_CARVER                = 59368,
    NPC_MEAT_GRAFT                      = 59980,
    NPC_THEOLEN_KRASTINOV               = 59369,

    // Gandling
    NPC_EXPIRED_TEST_SUBJECT            = 59100,
    NPC_FRESH_TEST_SUBJECT              = 59099,
    NPC_GANDLING_ROOM_STALKER           = 59167,
    NPC_GANDLING_FIRE_STALKER           = 30298,
    NPC_ALEXIY_BAROV                    = 64683,
};

enum eDatas
{
    DATA_INSTRUCTOR_CHILLHEART          = 0,
    DATA_JANDICE_BAROV                  = 1,
    DATA_RATTLEGORE                     = 2,
    DATA_LILIAN_VOSS                    = 3,
    DATA_GRANDMASTER_GANDLING           = 4,
    DATA_GRANDMASTER_GANDLING_INTRO     = 5,
};

enum eActions
{
    ACTION_JANDICE_REMOVE_ILLUSIONS     = 0,
    ACTION_LILIAN_RESSURECTED           = 1,
    ACTION_REMOVE_LILIAN_SOUL           = 2,
    ACTION_INTRO                        = 3,
    ACTION_DIFF_INTRO                   = 4,
    ACTION_CHILLHEART_DEATH             = 5,
    ACTION_COUNTINUE_MOVE               = 6,
    ACTION_ALEXEI                       = 7,
    ACTION_CANDLESTICK_DEATH            = 8,
};

enum eGameObjects
{
    GO_CHILLHEART_INTRO_DOOR            = 211259,
    GO_CHILLHEART_EXIT_DOOR             = 211258,
    GO_JANDICE_INTRO_DOOR               = 211257,
    GO_JANDICE_TO_RATTLEGORE_DOOR       = 211256,
    GO_RATTLEGORE_EXIT_DOOR             = 211262,
    GO_LILIAN_INTRO_DOOR                = 211261,
    GO_LILIAN_CHEST_DOOR                = 210781,
    GO_LILIAN_TO_GANDLING_DOOR          = 210771,
    GO_GANDLING_PRE_INTRO_DOOR          = 211260,
    GO_GANDLING_INTRO_DOOR              = 210789,
    GO_COFFER_OF_FORGOTTEN_SOULS        = 211277,
    GO_COFFER_OF_FORGOTTEN_SOULS_HC     = 211278,
    GO_ALCHEMY_BOTTLE_WHITE             = 211669,
    GO_HARSH_LESSON_EAST_LOW            = 210783,
    GO_HARSH_LESSON_NORTH_LOW           = 210784,
    GO_HARSH_LESSON_WEST_LOW            = 210788,
    GO_HARSH_LESSON_WEST_HIGH           = 210786,
    GO_HARSH_LESSON_NORTH_HIGH          = 210787,
    GO_HARSH_LESSON_EAST_HIGH           = 210785,
    GO_CHALLENGE_DOOR                   = 211989,
};

enum eSkullTalk
{
    TALK_CHILLHEART_ENTRANCE            = 0,
    TALK_CHILLHEART                     = 1,
    TALK_CHILLHEART_DEATH               = 2,
    TALK_JANDICE_ENTRANCE               = 3,
    TALK_JANDICE_COMBAT                 = 4,
    TALK_JANDICE_DEATH                  = 5,
    TALK_RATTLEGORE_ENTRANCE            = 6,
    TALK_GANDLING_LEAVE                 = 7,
    TALK_RATTLEGORE_DEATH               = 8,
    TALK_LILIAN_ENTRANCE                = 9,
    TALK_LILIAN_DEFEAT                  = 10,
    TALK_GANDLING_ENTRANCE              = 11,
};

enum Worldstates
{
    WORLDSTATE_ATTENTION_TO_DETAIL = 11983,
    WORLDSTATE_RATTLE_NO_MORE      = 11544,
};

enum InstanceScenarioData
{
    SCENARIO_ID                    = 51,
    // Bosses data
    CRITERIA_INSTRUCTOR_CHILLHEART = 19259,
    CRITERIA_JANDICE_BAROV         = 19260,
    CRITERIA_RATTLEGORE            = 19261,
    CRITERIA_LILIAN_VOSS           = 19262,
    CRITERIA_GRANDMASTER_GANDLING  = 19263,
    CRITERIA_ENEMIES               = 20030,
    ENEMIES_COUNT                  = 35,
};

#endif // SCHOLOMANCE_H