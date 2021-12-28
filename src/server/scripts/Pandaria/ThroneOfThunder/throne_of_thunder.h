#ifndef THRONE_OF_THUNDER_H
#define THRONE_OF_THUNDER_H

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"
#include "ScriptMgr.h"

const Position stormCallerThrowPos = { 5891.75f, 6410.02f, 124.02f, 4.76f  };
const Position stormCallerSumPos   = { 5899.00f, 6277.47f, 125.11f, 4.24f  };
const Position pMidBridge          = { 6046.22f, 5100.34f, 154.f           };
const Position backBridge          = { 6046.0f, 5186.62f, 148.002f, 1.567f };
// Megaera spawn / original body position.
const Position bossSpawnPos        = { 6442.61f, 4599.18f, -210.032f       };
const Position jikunJumpPos        = { 6112.219f, 4285.634f, -30.04051f, 0.0f };
const Position quetZalFlyPos       = { 6045.53f, 4744.17f,  167.71f, 1.56f };
const Position radenCenter         = { 5448.36f, 4656.12f, -2.476f, 3.175f };
const Position radenChestPos       = { 5430.376f, 4656.079f, -2.476f, 0.0f };
const Position discCollision       = { 5710.5f,   4094.24f, 156.723f, 0.0f };
const Position jiKunCenter         = { 6146.085f, 4319.261f, -30.608f, 2.739f };
const Position megaeraChestPos     = { 6405.11f, 4525.69f, -209.17f, 5.58f };
const Position ironQonCenter       = { 6045.47f, 4693.22f, 142.91f, 0.0f   };
const Position tortosCenter        = { 6040.13f, 4971.08f, -61.19f, 4.75f  };
const Position exitChamberJikun    = { 6099.95f, 4213.05f, -6.35f, 4.14f     };
const Position CenterDurumu        = { 5895.829f, 4512.626f, -6.276f, 6.542f };
const Position netherTearPos       = { 6394.29f, 4532.36f, -209.17f, 5.31f };
const Position quetzalStormPos     = { 6045.69f, 4707.01f, 167.71f, 1.59f };
const Position councilRingCenter   = { 6046.01f, 5403.13f, 136.08f, 5.84f };
const Position goldenEggThrowPos   = { 6075.09f, 4283.53f, 38.54f, 0.28f };
const Position goldenEggJumpPos    = { 6075.92f, 4283.62f, -101.17f, 2.01f };

// Ji-Kun intro movement.
Position const IntroMoving[2] =
{
    { 6213.971f, 4289.072f, -14.402f, 2.873f },
    { 6146.085f, 4319.261f, -30.608f, 2.739f }
};

const Position aTurtlePos[3] =
{
    { 6055.85f, 4861.87f, -60.4f },
    { 6071.43f, 4866.66f, -60.4f },
    { 6047.93f, 4859.66f, -60.4f }
};

const Position aBatPos[4] =
{
    { 6043.39f, 5039.37f, -16.43f, 4.66f },
    { 6040.19f, 4922.61f, -15.34f, 1.53f },
    { 6092.45f, 4958.73f, -14.09f, 2.82f },
    { 5996.11f, 4978.12f, -11.01f, 6.21f }
};

const Position sunMoonPath[17]=
{
    { 6217.979f, 4225.716f,  168.4048f, 0.0f },
    { 6218.046f, 4225.649f,  171.299f,  0.0f },
    { 6215.095f, 4222.78f,   178.4184f, 0.0f },
    { 6207.799f, 4214.622f,  183.2281f, 0.0f },
    { 6202.793f, 4208.838f,  184.4083f, 0.0f },
    { 6199.251f, 4205.091f,  185.4729f, 0.0f },
    { 6193.768f, 4199.311f,  183.4405f, 0.0f },
    { 6187.245f, 4191.88f,   178.752f,  0.0f },
    { 6181.278f, 4185.742f,  169.216f,  0.0f },
    { 6182.882f, 4184.192f,  154.3378f, 0.0f },
    { 6189.455f, 4190.372f,  147.6713f, 0.0f },
    { 6201.451f, 4205.37f,   146.7243f, 0.0f },
    { 6209.772f, 4216.129f,  149.1966f, 0.0f },
    { 6216.751f, 4224.799f,  155.657f,  0.0f },
    { 6217.979f, 4225.716f,  168.4048f, 0.0f },
    { 6218.046f, 4225.649f,  171.299f,  0.0f },
    { 6215.095f, 4222.78f,   178.4184f, 0.0f },
};

const Position nestPos[10] =
{
    { 6193.02f, 4267.89f, -70.78f,  0.0f },
    { 6070.89f, 4284.81f, -101.57f, 0.0f },
    { 6095.59f, 4339.13f, -93.75f,  0.0f },
    { 6159.08f, 4371.62f, -70.70f,  0.0f },
    { 6219.98f, 4333.65f, -59.11f,  0.0f },
    { 6078.04f, 4270.80f,  37.65f,  0.0f }, // blue
    { 6081.88f, 4372.10f,  43.42f,  0.0f }, // star
    { 6218.20f, 4352.41f,  65.96f,  0.0f }, // purple
    { 6173.31f, 4238.68f,  41.00f,  0.0f }, // green
    { 6152.42f, 4330.48f,  69.82f,  0.0f }, // red
};

const Position ironQonQuilensPath[4] =
{
    { 6067.66f, 4623.13f, 189.20f, 1.56f },
    { 6027.61f, 4748.70f, 189.20f, 1.56f },
    { 6067.66f, 4748.70f, 189.20f, 1.56f },
    { 6027.61f, 4623.13f, 189.20f, 1.56f },
};

const Position displacementPath[6]=
{
    { 5869.999f, 4100.385f, 206.3141f },
    { 5871.007f, 4136.986f, 206.3142f },
    { 5801.572f, 4173.038f, 206.3142f },
    { 5763.638f, 4176.987f, 192.3525f },
    { 5746.596f, 4114.077f, 192.3525f },
    { 5709.889f, 4094.213f, 157.5921f },
};

enum DataTypes
{
    DATA_JINROKH,
    DATA_HORRIDON,
    DATA_COUNCIL_OF_ELDERS,
    DATA_TORTOS,
    DATA_MEGAERA,
    DATA_JI_KUN,
    DATA_DURUMU_THE_FORGOTTEN,
    DATA_PRIMORDIUS,
    DATA_DARK_ANIMUS,
    DATA_IRON_QON,
    DATA_TWIN_CONSORTS,
    DATA_LEI_SHEN,
    DATA_RA_DEN,
    MAX_DATA,

    // Misc Data
    DATA_JINROKH_EVENT,
    DATA_PRE_HORIDON_EVENT,
    DATA_HORIDON_EVENT,
    DATA_PRE_COUNCIL_EVENT_1,
    DATA_PRE_COUNCIL_EVENT_2,
    DATA_COUNCIL_EVENT,
    DATA_TORTOS_EVENT,
    DATA_MEGERA_EVENT,
    DATA_JI_KUN_EVENT,
    DATA_DURUMU_EVENT,
    DATA_PRIMORDIUS_EVENT,
    DATA_ANIMUS_EVENT,
    DATA_TWIN_CONSORT_EVENT,
    DATA_LEI_SHEN_EVENT,
    DATA_RA_DEN_EVENT,
    MAX_EVENT_DATA,

    LFR_DATA,
    GOLEM_DATA,
};

enum miscSpells
{
    SHIELD_OF_RIGHTEOUS   = 132403,
    SHIELD_BLOCK          = 132404,
    SPELL_BLOOD_SHIELD    = 77535,
    SPELL_SHUFFLE         = 115307,
    SPELL_SAVAGE_DEFENCE  = 132402,
    SPELL_EXIT_CHAMBER_AT = 141014,
};

const std::map<uint32, uint32> invDataType =
{
    { DATA_JINROKH,  DATA_PRE_HORIDON_EVENT },
    { DATA_HORRIDON, DATA_PRE_COUNCIL_EVENT_1 },
    { DATA_COUNCIL_OF_ELDERS, DATA_TORTOS_EVENT },
};

const Position EncountersEntrance[MAX_DATA - 1]
{
    { 5892.08f, 6615.74f,  106.109f, 4.687f }, // Original Entrance
    { 5855.56f, 6263.36f,  124.034f, 3.149f }, // after jinrokh defeat
    { 5518.97f, 5753.58f,  130.041f, 6.281f }, // after horridon defeat
    { 6046.07f, 5403.06f,  136.087f, 4.702f }, // after council defeat
    { 6042.37f, 5084.21f,  -43.377f, 4.685f }, // after tortos defeat
    { 6244.06f, 4499.00f, -189.943f, 3.996f }, // after megaera defeat
    { 6061.84f, 4443.76f,  -12.120f, 2.072f }, // after jikun defeat
    { 5803.96f, 4512.60f,   -6.276f, 3.136f }, // after durumy defeat
    { 5592.28f, 4526.03f,   55.760f, 1.565f }, // after primordius defeat
    { 5790.03f, 4766.43f,   77.611f, 2.621f }, // after dark animus defeat
    { 6045.63f, 4835.95f,  148.780f, 4.702f }, // after iron qon defeat
    { 6230.33f, 4297.56f,  146.472f, 3.960f }, // after twin consort defeat
};

// Tank Abilities for dodge some mechanic
const std::vector<uint32> ProtectiveSpells
{
    SHIELD_OF_RIGHTEOUS, // prot paladin
    SHIELD_BLOCK, // prot warrior
    SPELL_BLOOD_SHIELD, // Death Knight
    SPELL_SHUFFLE, // Monk
    SPELL_SAVAGE_DEFENCE, // Guard
};

enum Types
{
    TYPE_TRIBE_PHASE,
    TYPE_SELECTED_SPEAR,
    TYPE_DESTROY_BRIDGE,
    TYPE_HEAD_SPAWNED,
    TYPE_CURRENT_PHASE,
    TYPE_FLAME_OF_PASSION_TARGET,
    TYPE_CONDUIT_LEVEL_POWER,
    TYPE_CONDUIT_LEVEL,
    TYPE_CONDUIT_OVERRIDE,
    TYPE_LEI_SHEN_PHASE,
    TYPE_VIOLENT_GALE_WINDS,
    TYPE_WIND_STORM,
    TYPE_TARGET_ID,
    TYPE_DEAD_ZONE,
    TYPE_ANIMA_ENERGY,
    TYPE_FEED,
    TYPE_NEST,
    TYPE_DARK_ANIMUS,
    TYPE_LIVING_FLUID,
    TYPE_DIREHORN_SPIRIT,
    TYPE_IN_AIR,
    TYPE_IN_TWILIGHT,
    TYPE_STAR_IN_SEQ,
    TYPE_NEXT_IN_LINK,
    TYPE_SELECTED_CELESTIAL,
    TYPE_ACTIVE_STAR_COUNTER,
    TYPE_TORRENT_OF_ICE,
    TYPE_ONE_UP,
    TYPE_RITUALIST,
    TYPE_SOFT_HANDS,
};

enum InstanceEvents
{
    EVENT_JINROKH_DOOR = 1,
    EVENT_MOGU_BELLS,
    EVENT_PRIMORDIUS_INTRO,
    EVENT_THUNDER_TRAP_INTRO,
    EVENT_GOLEM_INITIALIZE,
    EVENT_RITUALIST_INITIALIZE,
};

enum GlobalToTSpells
{
    SPELL_BERSERK                    = 144369,
    SPELL_FOCUSED_LIGHTNING_FIXATE   = 137422,
    SPELL_FOCUSED_LIGHTNING_VISUAL   = 137425,
    SPELL_CRITICALLY_DAMAGED         = 138400,
    SPELL_THUNDER_TRAP               = 138172,
    SPELL_FEIGN_DEATH                = 114371, // used by 70224 only if quest in sewer access point is available

    /*Ritualist Transform*/
    SPELL_RITUALIST_WIRRN            = 137954,
    SPELL_RITUALIST_TETRAP           = 137960,
    SPELL_RITUALIST_OGRON            = 137952,
    SPELL_RITUALIST_DRAHVIN          = 137948,
    SPELL_RITUALIST_BANDRIL          = 137949,
    SPELL_RITUALIST_GOND             = 137951,
    SPELL_RITUALIST_SIRIAN           = 137945,
    SPELL_RITUALIST_RILL             = 137946,
    SPELL_RITUALIST_XERON            = 137944,
    SPELL_RITUALIST_VOORD            = 137906,
    SPELL_RITUALIST_MOROK            = 137904,
    SPELL_RITUALIST_DRASHIG          = 137953,
    SPELL_RITUALIST_JAGAROTH         = 137903,
    SPELL_RITUALIST_MALUS            = 137955,
    SPELL_RITUALIST_MEGARA           = 137902,
    SPELL_RITUALIST_OGRI             = 137957,
    SPELL_RITUALIST_KITILING         = 137899,
    SPELL_RITUALIST_FENDAHL          = 137956,
    SPELL_RITUALIST_AUTON            = 137900,
    SPELL_RITUALIST_RUTAN            = 137958,
    SPELL_RITUALIST_KROLL            = 137898,
    SPELL_RITUALIST_MANDRELL         = 137959,
    SPELL_RITUALIST_THAL             = 137618,
    SPELL_RITUALIST_ARADIAN          = 137947,
};

const std::list<uint32> ritualistReformId=
{
    SPELL_RITUALIST_WIRRN,
    SPELL_RITUALIST_TETRAP,
    SPELL_RITUALIST_OGRON,
    SPELL_RITUALIST_DRAHVIN,
    SPELL_RITUALIST_BANDRIL,
    SPELL_RITUALIST_GOND,
    SPELL_RITUALIST_SIRIAN,
    SPELL_RITUALIST_RILL,
    SPELL_RITUALIST_XERON,
    SPELL_RITUALIST_VOORD,
    SPELL_RITUALIST_MOROK,
    SPELL_RITUALIST_DRASHIG,
    SPELL_RITUALIST_JAGAROTH,
    SPELL_RITUALIST_MALUS,
    SPELL_RITUALIST_MEGARA,
    SPELL_RITUALIST_OGRI,
    SPELL_RITUALIST_KITILING,
    SPELL_RITUALIST_FENDAHL,
    SPELL_RITUALIST_AUTON,
    SPELL_RITUALIST_RUTAN,
    SPELL_RITUALIST_KROLL,
    SPELL_RITUALIST_MANDRELL,
    SPELL_RITUALIST_THAL,
    SPELL_RITUALIST_ARADIAN,
};

enum ActionIds
{
    ACTION_START_INTRO,
    ACTION_ACTIVATE_NEST,
    ACTION_SWITCH_QUELIN,
    ACTION_ENCHANT_SPEAR,
    ACTION_EVOLVE,
    ACTION_COUNCIL_INTRO, // should be > 4
    ACTION_MEGAERA_EMERGE,
    ACTION_BROKEN_GOLEM,
    ACTION_FREEZE_CYCLONE,
    ACTION_ADDITIONAL_QUILEN,
    ACTION_REMOVE_ADDITIONAL_QUILEN,
    ACTION_CALL_QUILENS,
};

enum CreaturesIds
{
    NPC_JINROKH                             = 69465,
    NPC_HORRIDON                            = 68476,

    NPC_COUNCIL_KAZRAJIN                    = 69134,
    NPC_COUNCIL_SUL_THE_SANDCRAWLER         = 69078,
    NPC_COUNCIL_FROST_KING_MALAKK           = 69131,
    NPC_COUNCIL_HIGH_PRIESTESS_MARLI        = 69132,

    NPC_TORTOS                              = 67977,
    NPC_MEGAERA                             = 68065,
    NPC_JI_KUN                              = 69712,

    NPC_DURUMU_THE_FORGOTTEN                = 68036,
    NPC_PRIMORDIUS                          = 69017,
    NPC_DARK_ANIMUS                         = 69427,

    NPC_IRON_QON                            = 68078,
    NPC_LULIN                               = 68905,
    NPC_SUEN                                = 68904,
    NPC_LEI_SHEN                            = 68397,

    NPC_RA_DEN                              = 69473,

    /*JinRokh*/
    NPC_LIGHTNING_STIKE_CHARGES             = 69344,
    NPC_CALL_DA_STORM_STALKER               = 69676,
    NPC_ZANDALARI_STORM_CALLER              = 70236,
    NPC_JINROKH_STATUE                      = 69467,

    /*Horidon*/
    NPC_WAR_GOD_JALAK                       = 69374,
    NPC_HORRIDON_EVENT_HELPER               = 662202,
    NPC_SUL_LITHUZ_STONEGAZER               = 69172,
    NPC_FARRAKI_SKIRMISHER                  = 69173,
    NPC_FARRAKI_WASTEWALKER                 = 69175, // Total of three will be called to action
    NPC_GURUBASHI_BLOODLORD                 = 69167,
    NPC_GURUBASHI_VENOM_PRIEST              = 69164, // Total of three will be called to action
    NPC_RISEN_DRAKKARI_WARRIOR              = 69184,
    NPC_RISEN_DRAKKARI_CHAMPION             = 69185,
    NPC_DRAKKARI_FROZEN_WARLORD             = 69178, // Total of three will be called to action
    NPC_AMANI_SHI_PROTECTOR                 = 69169,
    NPC_AMANI_SHI_FLAME_CASTER              = 69168,
    NPC_AMANI_WARBEAR                       = 69177, // Total of three will be called to action
    NPC_AMANI_SHI_BEAST_SHAMAN              = 69176, // Riding Amani Warbears, attackable once Amani Warbear has fallen
    NPC_ZANDALARI_DINOMANCER                = 69221, // Jumping periodically during subphases
    NPC_DIREHORN_SPIRIT                     = 70688, // Only spawn in Heroic
    NPC_SAND_TRAP                           = 69346, // Summoned by Farraki Wastewalker
    NPC_VENOMOUS_EFFUSION                   = 69314, // Summoned by Gurubashi Venom Priests
    NPC_LIVING_POISON                       = 69313, // Created when a Venomous Effusion is created
    NPC_FROZEN_ORB                          = 69268, // Summoned by Drakkari Frozen Warlords
    NPC_LIGHTNING_NOVA_TOTEM                = 69215, // Summoned by Amani'Shi Beast Shaman
    NPC_GENERAL_PUR_BUNNY                   = 54020, // using like spawn point for tribes

    /*Council of Elders*/
    NPC_GARA_JAL                            = 69135,
    NPC_GARA_JALS_SOUL                      = 69182,
    NPC_LIVING_SAND                         = 69153, // Summoned when Sandstorm hits a Quicksand
    NPC_BLESSED_LOA_SPIRIT                  = 69480, // Summoned by Mar'li, heals a councillor
    NPC_SHADOWED_LOA_SPIRIT                 = 69548, // Summoned by Mar'li, kills player
    NPC_TWISTED_FATE_FIRST                  = 69740, // First Twisted Fate npc to be summoned, will move toward the second and vice-versa
    NPC_TWISTED_FATE_SECOND                 = 69746, // Second Twisted Fate npc to be summoned
    NPC_RECKLESS_CHARGE                     = 69453,

    /*Torots*/
    NPC_LEI_SHEN_TRIGGER                    = 70437,
    NPC_WHIRL_TURTLE                        = 67966,
    NPC_VAMPIRIC_CAVE_BAT                   = 68497,
    NPC_ROCKFALL_TORTOS                     = 68219,
    NPC_HUMMING_CRYSTAL                     = 69639,

    /*Megaera*/
    NPC_FLAMING_HEAD                        = 70212,
    NPC_FROZEN_HEAD                         = 70235,
    NPC_VENOMOUS_HEAD                       = 70247,
    NPC_ARCANE_HEAD                         = 70252, // After flaming head dies - Heroic only!
    NPC_CINDERS                             = 70432,
    NPC_TORRENT_OF_ICE                      = 70439,
    NPC_ICY_GROUND                          = 70446,
    NPC_NETHER_WYRM                         = 70507,  // From Nether Tear.
    NPC_ACID_RAIN                           = 70435,
    NPC_BACK_HEAD_SPAWNER                   = 68136,
    NPC_NETHER_TEAR_SPAWNER                 = 70506,

    /*Ji-Kun*/
    NPC_JUVENILE                            = 70095,
    NPC_FALL_CATCHER                        = 69839,
    NPC_JUMP_TO_BOSS_PLATFORM               = 69885,
    NPC_YOUNG_EGG_OF_JIKUN                  = 68194, // Hatches to Hatchling.
    NPC_FLEDGLING_EGG_JIKUN                 = 68202, // Hatches to Juvenile.
    NPC_MATURE_EGG_OF_JIKUN                 = 69628, // Hatches to Juvenile.
    NPC_JIKUN_HATCHLING                     = 68192,
    NPC_JIKUN_FLEDGLING                     = 68193,
    NPC_JIKUN_JUVENILE                      = 70095,
    NPC_JIKUN_NEST_GUARDIAN                 = 70134, // HEROIC only!
    NPC_FEED_POOL                           = 68178, // Feed NPC's.
    NPC_FEED_HATCHLINGS                     = 70130,                                       
    NPC_POOL_OF_FEED                        = 68188, // Feed Pool NPC's.
    NPC_POOL_OF_FEED_HATCHLING              = 70216,
    NPC_INCUBATOR                           = 69626,
    NPC_EXIT_CHAMBER                        = 70734,
    NPC_NEST_GUARDIAN                       = 70134,
    NPC_GOLDEN_EGG                          = 69816,

    /*Durumu*/
    NPC_YELLOW_EYE                          = 67856, // for yellow beam
    NPC_BLUE_EYE                            = 67854, // for blue beam
    NPC_RED_EYE                             = 67855, // for red beam
    NPC_YELLOW_EYE_MOVER                    = 67829, // yellow eye not work with player, just with invisible
    NPC_MIND_EYE                            = 67875,
    NPC_HUNGRY_EYE                          = 67859,
    NPC_APPRAYISYING_EYE                    = 67858,
    NPC_RED_FOG                             = 69050,
    NPC_BLUE_FOG                            = 69052,
    NPC_ROAMING_FOG                         = 68313,
    NPC_YELLOW_FOG                          = 69051,
    NPC_ICE_WALL                            = 69582,
    NPC_WANDERING_EYE                       = 68024,
    NPC_ORANGE_FOG_BEAST                    = 70142,
    NPC_PURPLE_FOG_BEAST                    = 70151,
    NPC_GREEN_FOG_BEAST                     = 70152,

    /*Primordius*/
    NPC_LIVING_FLUID                        = 69069,
    NPC_VISCOUS_HORROR                      = 69070,
    NPC_AT_STALKER                          = 69081,

    /*Animus*/
    NPC_ANIMUS_GOLEM                        = 69701,
    NPC_LARGE_ANIMA_GOLEM                   = 69700,
    NPC_MASSIVE_ANIMA_GOLEM                 = 69699,
    NPC_ANIMA_ORB                           = 69756,
    NPC_CRIMSON_WAKE                        = 69951,

    /*Dark Ritualists*/
    NPC_DARK_RITUALIST                      = 69702, // just template with same model - need override this
    NPC_RITUALIST_XERON                     = 69724,
    NPC_RITUALIST_VOORD                     = 69723,
    NPC_RITUALIST_TETRAP                    = 69738,
    NPC_RITUALIST_RUTAN                     = 69736,
    NPC_RITUALIST_OGRON                     = 69730,
    NPC_RITUALIST_MOROK                     = 69722,
    NPC_RITUALIST_MANDREL                   = 69737,
    NPC_RITUALIST_KITLING                   = 69716,
    NPC_RITUALIST_JAGAROTH                  = 69721,
    NPC_RITUALIST_FENDAHL                   = 69734,
    NPC_RITUALIST_DRAHVIN                   = 69727,
    NPC_RITUALIST_AUTON                     = 69718,
    NPC_RITUALIST_ARIDIAN                   = 69726,
    NPC_RITUALIST_BANDRIL                   = 69728,
    NPC_RITUALIST_DRASHIG                   = 69731,
    NPC_RITUALIST_GOND                      = 69729,
    NPC_RITUALIST_KROLL                     = 69710,
    NPC_RITUALIST_MALUS                     = 69733,
    NPC_RITUALIST_MEGARA                    = 69719,
    NPC_RITUALIST_OGRI                      = 69735,
    NPC_RITUALIST_RILL                      = 69725,
    NPC_RITUALIST_SIRIAN                    = 69720,
    NPC_RITUALIST_WIRRN                     = 69732,
    NPC_RITUALIST_THAL                      = 69709, // ok, after this i saw about spells... total fail

    /*Iron Qon*/
    NPC_ROSHAK                              = 68079,
    NPC_QUETZAL                             = 68080,
    NPC_DAMREN                              = 68081,
    NPC_IRON_SPEAR                          = 68480,
    NPC_RUSHING_WINDS                       = 69703,
    NPC_RUSHING_WINDS_2                     = 68852,
    NPC_RUSHING_WINDS_CONTROLLER            = 64693,
    NPC_LIGHTNING_CLOUD                     = 70660,

    /*Twin Consort*/
    NPC_MOON_LOTUS                          = 69456, // real lotus
    NPC_MOON_LOTUS_WAVE                     = 69340,
    NPC_WORLD_TRIGGER                       = 59481,
    NPC_SUN                                 = 69460,
    NPC_INVISIBLE_MAN                       = 64188, // moon trigger
    NPC_FADED_IMAGE_OF_NIUZAO               = 69777,
    NPC_FADED_IMAGE_OF_CHI_JI               = 69774,
    NPC_FADED_IMAGE_OF_XUEN                 = 69771,
    NPC_FADED_IMAGE_OF_YULON                = 69779,
    NPC_CRASHING_STAR                       = 69365,
    NPC_CRASHING_STAR_SLOW                  = 69477,
    NPC_CONSORT_CONTROLLER                  = 64367,
    NPC_BEAST_OF_NIGHTMARES                 = 69479,
    NPC_ICE_COMET                           = 69596,
    NPC_DEEP_SUBMERGE                       = 69629,
    NPC_LURKER_IN_THE_NIGHT                 = 69591,
    NPC_CELESTIAL_STAR                      = 70124,

    /*Lei Shen*/
    NPC_STATIC_SHOCK_CONDUIT                = 68398,
    NPC_BOUNCING_BOLT_CONDUIT               = 68698,
    NPC_OVERCHARGE_CONDUIT                  = 68697,
    NPC_DIFFUSION_CHAIN_CONDUIT             = 68696,
    NPC_QUADRANT_STALKER                    = 69024,
    NPC_OVERWHELMING_POWER                  = 69645,
    NPC_THUNDERSTRUCK                       = 68574,
    NPC_UNHARNESSED_POWER                   = 69133,
    NPC_BALL_LIGHTNING                      = 69232,
    NPC_LESSER_DIFFUSING_LIGHTNING          = 69012,
    NPC_DIFFUSING_LIGHTNING                 = 69013,
    NPC_GREATER_DIFFUSING_LIGHTNING         = 69014,
    NPC_LIGHTNING_VISUAL_FIRST_STAGE        = 69920,
    NPC_LIGHTNING_VISUAL_SECOND_STAGE       = 69921,

    /*Raden*/
    NPC_ESSENSE_OF_VITA                     = 69870,
    NPC_ESSENSE_OF_ANIMA                    = 69869,
    NPC_SANGUINE_HORROR                     = 69871,
    NPC_CRACKLING_STALKER                   = 69872,
    NPC_CORRUPTED_ANIMA                     = 69957,
    NPC_CORRUPTED_VITA                      = 69958,
    NPC_GEN_PURPOSE_BUNNY_FLYING            = 54020,

    // Misc | Trash
    NPC_GENERAL_BUNNY                       = 45979,
    NPC_GENERAL_BUNNY_GROUND                = 59394,
    NPC_SPEAR                               = 69438,
    NPC_CRAZED_STORMCALLER                  = 70491,
    NPC_ZANDALARI_STORMCALLER               = 70236,
    NPC_ERUPTION                            = 70029,
    NPC_ZANDALARI_WATER_BINDER              = 69455,
    NPC_ZANDALARI_BLADE_INITIATE            = 70230,
    NPC_ZANDALARI_STORMCALLER_2             = 69390, // in trash pack
    NPC_SPIRIT_FLAYER                       = 70246,
    NPC_ANCIENT_PYTHON                      = 70448,
    NPC_TORMENTED_SPIRIT                    = 70341,
    NPC_LOST_SOUL                           = 70441, // just for visual
    NPC_SOUL_FED_CONSTRUCT                  = 70308,
    NPC_STORMBRINGER_DRAZKIL                = 70445,
    NPC_SHADOWED_VOODO_SPIRIT               = 70060,
    NPC_HIDDEN_FOG                          = 69375,
    NPC_QUIVERING_BLOD                      = 69383,
    NPC_AMANISHI_FLAME_CHANTER              = 69909,
    NPC_DRAKKARI_FROST_WARDEN               = 69910,
    NPC_GLACIAL_FREEZE_TOTEM                = 70047,
    NPC_FARRAKI_SAND_CONJURER               = 69899,
    NPC_GURUBASHI_BERSERKER                 = 69905,
    NPC_GURUBASHI_BERSERKER_2               = 69916,
    NPC_ZANDALARI_HIGH_PRIEST               = 69906,
    NPC_SHADOWED_VOODOO_SPIRIT              = 70060,
    NPC_ZANDALARI_PROPHET                   = 70557,
    NPC_GARAJAL_THE_SPIRITBINDER_TRASH      = 70056,
    NPC_ZANDALARI_WARLORD                   = 69911,
    NPC_ZANDALARI_PRELATE                   = 69927,
    NPC_BRIDGE_TRIGGER                      = 66305,
    NPC_TORTOS_TRIGGER                      = 55091,
    NPC_GREATER_CAVE_BAT                    = 69351,
    NPC_SHALE_STALKER                       = 70587,
    NPC_FUNGAL_GROWTH                       = 70153,
    NPC_MIST_LURKER                         = 70594,
    NPC_CAVERN_BURROWER                     = 70589,
    NPC_BORE_WORM                           = 68221,
    NPC_CORPSE_SPIDER                       = 68248,
    NPC_BOW_FLY_SWARM                       = 68222,
    NPC_GASTROPOD                           = 68220,
    NPC_SLG_GENERIC_MOP                     = 63420,
    NPC_THUNDER_LORD                        = 69821,
    NPC_LIGHTNING_GUARDIAN                  = 69834,
    NPC_THUNDER_TRAP                        = 69825,
    NPC_MANCHU                              = 70202,
    NPC_WEISHEN                             = 70205,
    NPC_UNTRAINED_QUILEN                    = 70206,
    NPC_UNTRAINED_QUILEN_2                  = 70209,
    NPC_SHANZE_CELESTIAL_SHAPER             = 70240,
    NPC_RITUAL_GUARD                        = 70179,
    NPC_MUCKBAT                             = 70232,
    NPC_SKITTERING_SPIDERLING               = 70227,
    NPC_PUTRID_WASTE                        = 70219,
    NPC_ROTTING_SCAVENGER                   = 70224,
    NPC_CHOKING_GAS                         = 70306,
    NPC_SPLASH_GRATE                        = 69494,
    NPC_GARAJAL_THRASH_SOUL                 = 70137,
    NPC_INVIS_STALKER_UNK                   = 70633,
};

enum ObjectsIds
{
    GO_JIN_ROKH_ENTRANCE                   = 218664,
    GO_JIN_ROKH_PREDOOR                    = 218665,
    GO_JIN_ROKH_EXIT                       = 218663,
    GO_HORRIDON_ENTRANCE                   = 218667,
    GO_HORRIDON_PREDOOR                    = 218669,
    GO_HORRIDON_EXIT                       = 218666,
    GO_COUNCIL_TRASH_DOOR_ONE              = 218658,
    GO_COUNCIL_TRASH_DOOR_TWO              = 218660,
    GO_COUNCIL_ENTRANCE1                   = 218655,
    GO_COUNCIL_ENTRANCE2                   = 218656,
    GO_COUNCIL_EXIT                        = 218657,
    GO_TORTOS_DOOR                         = 218980,
    GO_TORTOS_COLLISION                    = 218987,
    GO_MEGAERA_EXIT                        = 218746,
    GO_JI_KUN_EXIT                         = 218888,
    GO_BEHOLDER_GRATE_ENTRANCE             = 218396,
    GO_ANCIENT_STONE_DOOR_DURUMU_EXIT      = 218390,
    GO_BEHOLDER_GRATE_EXIT                 = 218395,
    GO_MOGU_GATE_DURUMU                    = 218114, // invisible wall
    GO_PRIMORDIUS_ENTRANCE                 = 218584,
    GO_PRIMORDIUS_EXIT                     = 218585,
    GO_ANIMUS_ENTRANCE                     = 218392,
    GO_ANCIENT_STONE_DOOR                  = 218393,
    GO_IRON_QON_BACK_DOOR                  = 218699,
    GO_IRON_QON_SEWER_GATE                 = 218388,
    GO_IRON_QON_EXIT_1                     = 218588,
    GO_IRON_QON_EXIT_2                     = 218589,
    GO_TWIN_CONSORT_BACK_DOOR              = 218711,
    GO_TWIN_CONSORT_FORWARD_DOOR           = 218712,
    GO_TWIN_CONSORT_PASSAGE_DOOR           = 218394,
 
    GO_TRIBAL_DOOR_GURUBASHI               = 218670,
    GO_TRIBAL_DOOR_DRAKKARI                = 218671,
    GO_TRIBAL_DOOR_FARRAKI                 = 218672,
    GO_TRIBAL_DOOR_AMANI                   = 218673,
    GO_HORRIDON_PRISON_DOOR                = 218674,

    // Orbs of Control
    GO_ORB_OF_CONTROL_FARRAKI              = 218193,
    GO_ORB_OF_CONTROL_GURUBASHI            = 218374,
    GO_ORB_OF_CONTROL_DRAKKARI             = 218375,
    GO_ORB_OF_CONTROL_AMANI                = 218376,

    GO_MOGU_STATUE_1                       = 218675,
    GO_MOGU_STATUE_2                       = 218676,
    GO_MOGU_STATUE_3                       = 218677,
    GO_MOGU_STATUE_4                       = 218678,

    GO_TORTOS_BRIDGE                       = 218869,

    GO_MOGU_BELL                           = 218723,
    GO_CACHE_OF_ANCIENT_TREAS              = 218805,
    GO_MEGAERA_CHEST_NORMAL                = 218805,
    GO_MEGAERA_CHEST_HEROIC                = 218806,

    GO_JIKUN_FEATHER                       = 218543,
    GO_JIKUN_FEATHER_2                     = 218625, // same, why?
    GO_JIKUN_EGG                           = 218382,

    GO_MOGU_BLOOD_VAT                      = 218866, // blood pillar

    GO_ASTRAL_PLANE                        = 218720, // Celestial Pillar
    GO_ICE_TOMB                            = 218627,
    GO_ICE_WALL                            = 216606,

    GO_CHARGING_STATION                    = 218397, // center station (phase switch)
    GO_NORTH_PILLAR                        = 218398, // conduits
    GO_SOUTH_PILLAR                        = 218400,
    GO_EAST_PILLAR                         = 218399,
    GO_WEST_PILLAR                         = 218401,
    GO_SW_WINDOW                           = 218408, // wind windows
    GO_NW_WINDOW                           = 218409,
    GO_SE_WINDOW                           = 218410,
    GO_NE_WINDOW                           = 218411,
    GO_WIND_FX_NE                          = 218412, // floor wind animation
    GO_WIND_FX_SE                          = 218413,
    GO_WIND_FX_SW                          = 218414,
    GO_WIND_FX_NW                          = 218415,
    GO_DISPLACEMENT_PAD_1                  = 218417, // teleports (disable while in combat)
    GO_DISPLACEMENT_PAD_2                  = 218418,
    GO_THUNDER_KING_DISC_COLLISION         = 218488, // collision for station (need handle spawn)
    GO_THUNDER_KING_CONDUIT_COLLISION      = 218540, // what is?
    GO_FLOOR_FX_SOUTH                      = 218419, // floor active animation
    GO_FLOOR_FX_NORTH                      = 218420,
    GO_FLOOR_FX_WEST                       = 218421,
    GO_FLOOR_FX_EAST                       = 218422,

    GO_RADEN_SECRET_DOOR                   = 218553,
    GO_CACHE_OF_STORMS                     = 218997, // Ra-Den Loot
};

enum cinematicIds
{
    CINEMATIC_TORTOS_INTRO = 271,
    CINEMATIC_RADEN_INTRO  = 272,
};

enum EquipmentIds
{
    EQUIPMENT_AXE     = 94982,
    EQUIPMENT_POLEARM = 94983,
};

enum RaidFinder
{
    QUARTER_NONE                        = 0,
    QUARTER_LAST_STAND_OF_THE_ZANDALARI = 610,
    QUARTER_FORGOTTEN_DEPTH             = 611,
    QUARTER_HALLS_OF_FLESH_SHAPING      = 612,
    QUARTER_PINNACLE_OF_STORMS          = 613,
};

enum Worldstates
{
    WORLDSTATE_FOG_BEASTS_REMAINING = 7889,
    WORLDSTATE_ATTEMPS_REMAINING    = 7844,

    // Achievements
    WORLDSTATE_I_THOUGHT_HE_WAS_SUPPOSED_TO_BE_HARD = 13698,
    WORLDSTATE_CRETACEOUS_COLLECTOR                 = 13239,
    WORLDSTATE_ONE_UP                               = 13689,
    WORLDSTATE_HEAD_CASE_DEFAULT                    = 12630,
    WORLDSTATE_HEAD_CASE_FLAMING                    = 13636,
    WORLDSTATE_HEAD_CASE_FROZEN                     = 13637,
    WORLDSTATE_HEAD_CASE_VENOM                      = 13638,
    WORLDSTATE_GEN_UNMODIFIED_ORGANISM              = 13207,
    WORLDSTATE_FROM_DUSK_TILL_DOWN                  = 13690,
    WORLDSTATE_DIFFUSION_CHAIN_CONDUIT_FIRST        = 13866,
    WORLDSTATE_OVERLOAD_CONDUIT_FIRST               = 13867,
    WORLDSTATE_STATIC_SHOCK_CONDUIT_FIRST           = 13865,
    WORLDSTATE_BOUNCING_BOLT_CONDUIT_FIRST          = 13868,
};

enum Misc
{
    ANIMUS_GOLEMS_COUNT                    = 25,
    LARGE_ANIMUS_GOLEMS_COUNT              = 8,
    MASSIVE_ANIMUS_GOLEMS_COUNT            = 2,

    ANIMUS_GOLEM_BROKEN_MAX                = 13,
    LARGE_ANIMUS_GOLEM_BROKEN_MAX          = 3,
};

const std::map<uint32, uint32> invCaseHeadType =
{
    { NPC_FLAMING_HEAD,  WORLDSTATE_HEAD_CASE_FLAMING },
    { NPC_FROZEN_HEAD,   WORLDSTATE_HEAD_CASE_FROZEN  },
    { NPC_VENOMOUS_HEAD, WORLDSTATE_HEAD_CASE_VENOM   },
};

#endif
