#ifndef BRAWLERS_GUILD_H_
#define BRAWLERS_GUILD_H_

const Position ArenaGizmoPos            = { -106.63f, 2499.95f, -49.10f, M_PI  };
const Position RingOfValor              = { 2031.75f, -4763.80f, 86.37f, 1.56f };
const Position EncounterSpawnPos        = { -137.74f, 2500.72f, -49.10f, 6.26f };
const Position hordeEncounterSpawnPos   = { 2030.84f, -4734.90f, 86.77f, 4.72f };
const Position WipePos                  = { -94.59f,  2473.31f, -43.10f, 3.11f };
const Position hordeWipePos             = { 2001.32f, -4751.70f, 86.77f, 0.10f };
const Position AlianceCenterOfRectangle = { -115.10f, 2500.35f, -49.10f, 3.13f };
const Position HordeCenterOfRectangle   = { 2031.118f, -4753.29f, 86.77f, 4.75f };
const Position lowRightField            = { 2051.47f, -4772.45f, 86.77f, 1.598888f };
const Position lowRightFieldBizmo       = { -96.98f, 2482.74f, -49.10f, 1.598888f };
const Position blingtronSpawnPos        = { 2048.75f, -4733.87f, 86.77f, 3.88f };
const Position teslaCoilSpawnPos        = { 2012.50f, -4772.84f, 86.77f, 0.76f };
const Position blingtronSpawnPosA       = { -142.15f, 2516.31f, -49.10f, 5.47f };
const Position teslaCoilSpawnPosA       = { -97.75f,  2483.07f, -49.10f, 2.35f };

const Position ShieldGeneratorAliance[4] =
{
    {  -98.76f, 2515.18f, -49.10f, 3.14f },
    {  -98.76f, 2483.61f, -49.10f, 3.14f },
    { -141.16f, 2483.54f, -49.10f, 6.25f },
    { -141.16f, 2515.80f, -49.10f, 6.25f },
};

const Position ShieldGeneratorHorde[4] =
{
    { 2014.96f, -4771.58f, 86.77f, 0.0f },
    { 2049.13f, -4770.80f, 86.77f, 0.0f },
    { 2048.04f, -4733.54f, 86.77f, 0.0f },
    { 2014.25f, -4734.19f, 86.77f, 0.0f },
};

const Position BazzelflangePath[5]=
{
    { 2047.26f, -4736.842f, 96.40759f, 0.0f },
    { 2048.991f, -4770.262f, 96.40759f, 0.0f },
    { 2012.858f, -4771.691f, 96.40759f, 0.0f },
    { 2011.47f, -4735.361f, 96.40759f, 0.0f },
    { 2048.16f, -4733.13f, 96.40759f, 0.0f},
};

const Position bizmoPath[5]=
{
    { -140.6134f, 2487.038f, -38.27213f, 0.0f },
    { -140.1694f, 2514.957f, -38.27213f, 0.0f },
    { -104.8112f, 2514.618f, -38.27213f, 0.0f },
    { -104.7063f, 2486.469f, -38.27213f, 0.0f },
    { -140.4696f, 2485.249f, -38.27213f, 0.0f },
};

enum eCreatures
{
    NPC_BIZMO                    = 68323, // Aliance (using like queue controller)
    NPC_BOSS_BAZZELFLANGE        = 67260, // Horde
                                 
    // Rank 1                    
    NPC_BRUCE                    = 67262,
    NPC_VIAN_THE_VOLATILE        = 67579,
    NPC_GOREDOME                 = 68257,
    NPC_DUNGEON_MASTER_VISHAS    = 67572,
                                 
    // Rank 2                    
    NPC_DIPPY                    = 68255,
    NPC_KIRRAWK                  = 67269,
    NPC_RIDDOH                   = 67524, // vehicle for 67525
    NPC_FRAN                     = 67525,
    NPC_KING_KULAKA              = 68254,
                                 
    // Rank 3                    
    NPC_BLAT                     = 67594,
    NPC_SANORIAK                 = 67268,
    NPC_IXX                      = 68253,
    NPC_MAZHAREEN                = 68251,

    // Rank 4
    NPC_CRUSH                    = 67540,
    NPC_LEONA_EARTHWIND          = 68377,
    NPC_DOMINIKA_THE_ILLUSIONIST = 67485,
    NPC_DEEKEN                   = 67451,

    // Rank 5
    NPC_MILLIE_WATT              = 67591,
    NPC_FJOLL                    = 67596,
    NPC_PROBOSKUS                = 68252,
    NPC_FLEASY                   = 67515, // Lepergnome
    NPC_GREAZY                   = 67514, // Lepergnome
    NPC_SLEAZY                   = 67513, // Lepergnome
    NPC_QUEAZY                   = 67511, // Lepergnome
    NPC_WHEEZY                   = 67516, // Lepergnome

    // Rank 6
    NPC_YIKKAN_IZU               = 68256,
    NPC_AKAMA                    = 67588,
    NPC_SMASH_HOOFSTOMP          = 68305,
    NPC_UNGULOXX                 = 68250,

    // Rank 7
    NPC_MAX_MEGABLAST            = 67488, // with bobble
    NPC_BO_BOBBLE                = 67487, // with megablast
    NPC_DARK_SUMMONER            = 67678,
    NPC_BATTLETRON               = 67424,
    NPC_MEATBALL                 = 67573,

    // Rank 8
    NPC_HEXOS                    = 70659,
    NPC_TYSON_SANDERS            = 70733,
    NPC_T440_DUAL_MODE_ROBOT     = 70983,
    NPC_ANTHRACITE               = 70977,

    // Rank 9
    NPC_BIG_BADDA_BOOM           = 70694,
    NPC_NIBBLEH                  = 70656,
    NPC_DOCTOR_FIST              = 70739,
    NPC_AHOORU                   = 70068,

    // Non Ranked
    NPC_MECHA_BRUCE              = 71081,
    NPC_GRANDPA_GRUMPLEFLOOT     = 70678,
    NPC_BLINGTRON_3000           = 70740,
    NPC_MASTER_BOOM_BOOM         = 70677,

    // Triggers and Summons
    NPC_VOLATILE_FLAME           = 68379,
    NPC_FIRE_LINE                = 67773,
    NPC_LUMBERING_CHARGE_TARGET  = 68264,
    NPC_TWISTER                  = 67270,
    NPC_GOBLIN_LAND_MINE         = 67539,
    NPC_BLAT_SPLITED             = 67595,
    NPC_EARTHLIVING_SEED         = 68382,
    NPC_EARTHLIVING_SPROUT       = 68383,
    NPC_SHOCK_FIELD              = 67459,
    NPC_DOMINIKA_ILLUSION        = 67489,
    NPC_IZUS_RAVEN               = 68268,
    NPC_SHIELD_GENERATOR         = 67500,
    NPC_TORMENTED_GHOST          = 67664,
    NPC_BATTLE_MINE              = 67422,
    NPC_GOOD_LUCK_GOBLIN         = 68306,
    NPC_LUCKYDO                  = 70692,
    NPC_LUCKYDONT                = 70693,
    NPC_BAD_LUCKYDO              = 70735,
    NPC_BAD_LUCKYDO_2            = 70738,
    NPC_GNOMISH_TESLA_COIL       = 70743,
    NPC_BLINGTRON_2000           = 70802,
    NPC_PILE_OF_GOLD             = 71134,

    // Citizens
    NPC_BRAWLGAR_ARENA_GRUNT     = 67267,
    NPC_BIZMOS_BRAWLPUB_BOUNCER  = 68408,
    NPC_BRAWL_ENTHUSIAST         = 68403,
    NPC_BRAWL_ENTHUSIAST_A       = 68406,

    // Credits
    NPC_MECHA_BRUCE_CREDIT       = 71570,
    NPC_GRANDPA_CREDIT           = 71565,
    NPC_BLINGTRON_CREDIT         = 71571,
    NPC_BOOM_BOOM_CREDIT         = 71567,
};

enum Spells
{
    SPELL_RING_OF_VALOR_IN_THE_ARENA   = 132633,
    SPELL_FIRE_LINE                    = 133607,
    SPELL_FRENZIED_RIDDOH              = 133296,
    SPELL_GOBLIN_LAND_MINE_MISSLE      = 133221,
    SPELL_FEATHERED_FURY               = 134790,
    SPELL_FALLEN_KIN                   = 134789,
    SPELL_SHIELD_GENERATOR_ACTIVATION  = 133137,
    SPELL_GOBLIN_ROCKET_BARRAGE_MISSLE = 133228,
    SPELL_GUARDIANS_LIGHT              = 133426,
};

enum eActions
{
    ACTION_WIPE,
    ACTION_BRUCE,
    ACTION_VIAN,
    ACTION_GOREDOME,
    ACTION_VISHAS,
    ACTION_DIPPY,
    ACTION_KIRRAWK,
    ACTION_FRAN_AND_RIDDOH,
    ACTION_KING_KULAKA,
    ACTION_BLAT,
    ACTION_SANORIAK,
    ACTION_IXX,
    ACTION_MAZHAREEN,
    ACTION_CRUSH,
    ACTION_LEONA,
    ACTION_DOMINIKA,
    ACTION_DEEKEN,
    ACTION_MILLIE_WATT,
    ACTION_FJOLL,
    ACTION_PROBOSKUS,
    ACTION_LEPREGNOMES,
    ACTION_YIKKAN_IZU,
    ACTION_AKAMA,
    ACTION_HOOFSTOMP,
    ACTION_UNGULOXX,
    ACTION_GG_INGENEERING,
    ACTION_DARK_SUMMONER,
    ACTION_BATTLETRON,
    ACTION_MEATBALL,
    ACTION_VIAN_REMOVE_FIRELINE,
    ACTION_TWISTER,
    ACTION_NET_TOSS,
    ACTION_RIDDOH_DEATH,
    ACTION_DEVASTATING_THRUST,
    ACTION_LEPRO_DEATH,
    ACTION_LEPRO_DEATH_ENCOUNTER,
    ACTION_REMOVE_DISCOMBOBUMORPHNATOR,
    ACTION_GHOST_DEATH,
    ACTION_BATTLEMINE_DEATH,
    ACTION_CREATE_FLAME_WALL,
    ACTION_MOVE_SHOCK_FIELD,
    ACTION_FORCE_DESPAWNED,
    ACTION_MECHA_BRUCE,
    ACTION_GRANDPA_GRUMPLEFLOOT,
    ACTION_BLINGTRON_3000,
    ACTION_CHARGE_CONDUIT,
    ACTION_BOOM_BOOM,
};

enum Talks
{
    TALK_INTR0,
    TALK_DEATH,
    TALK_SPECIAL,
    TALK_SPECIAL_2,
    TALK_SPECIAL_3,
    TALK_SPECIAL_4,

    TALK_RANK_1 = 0,
    TALK_RANK_2,
    TALK_RANK_3,
    TALK_RANK_4,
    TALK_RANK_5,
    TALK_RANK_6,
    TALK_RANK_7,
    TALK_RANK_8,
    TALK_RANK_9,
    TALK_BRUCE_ANN,
    TALK_VIAN_ANN,
    TALK_GOREDOME_ANN,
    TALK_VISHAS_ANN,
    TALK_DIPPY_ANN,
    TALK_KIRRAWK_ANN,
    TALK_FRAN_ANN,
    TALK_KULAKA_ANN,
    TALK_BLAT_ANN,
    TALK_SANORIAK_ANN,
    TALK_IXX_ANN,
    TALK_MAZHAREEN_ANN,
    TALK_CRUSH_ANN,
    TALK_LEONA_ANN,
    TALK_DOMINIKA_ANN,
    TALK_DEEKEN_ANN,
    TALK_MILLIE_WATT_ANN,
    TALK_FJOLL_ANN,
    TALK_PROBKOSUS_ANN,
    TALK_LEPREGNOMES_ANN,
    TALK_YIKKAN_IZU_ANN,
    TALK_AKAMA_ANN,
    TALK_HOOFSTOMP_ANN,
    TALK_UNGULOXX_ANN,
    TALK_GG_ENGINEERING_ANN,
    TALK_DARK_SUMMONER_ANN,
    TALK_BATTLETRON_ANN,
    TALK_MEATBALL_ANN,
    TALK_BRAWLER_WON,
    TALK_BRAWLER_DEFEAT,
    TALK_MECHA_BRUCE_ANN,
    TALK_GRANDPA_GRUMPLEFLOOT_ANN,
    TALK_BLINGTRON_3000_ANN,
    TALK_BOOM_BOOM_ANN,
};

enum BrawlFactions
{
    FACTION_BRAWLGAR_ARENA = 1374,
    FACTION_BIZMO_BRAWLPUB = 1419,
};

enum ChallengeCards
{
    ITEM_CHALLENGE_CARD_BRUCE          = 93823,
    ITEM_CHALLENGE_CARD_VIAN           = 93824,
    ITEM_CHALLENGE_CARD_GOREDOME       = 94160,
    ITEM_CHALLENGE_CARD_VISHAS         = 94161,
    ITEM_CHALLENGE_CARD_DIPPY          = 94162,
    ITEM_CHALLENGE_CARD_KIRRAWK        = 94163,
    ITEM_CHALLENGE_CARD_FRAN           = 94164,
    ITEM_CHALLENGE_CARD_KULAKA         = 94165,
    ITEM_CHALLENGE_CARD_BLAT           = 94166,
    ITEM_CHALLENGE_CARD_SANORIAK       = 94167,
    ITEM_CHALLENGE_CARD_IXX            = 94168,
    ITEM_CHALLENGE_CARD_MAZHAREEN      = 94169,
    ITEM_CHALLENGE_CARD_CRUSH          = 94170,
    ITEM_CHALLENGE_CARD_LEONA          = 94171,
    ITEM_CHALLENGE_CARD_DOMINIKA       = 94172,
    ITEM_CHALLENGE_CARD_DEEKEN         = 94173,
    ITEM_CHALLENGE_CARD_MILLIE_WATT    = 94174,
    ITEM_CHALLENGE_CARD_FJOLL          = 94175,
    ITEM_CHALLENGE_CARD_PROBKOSUS      = 94176,
    ITEM_CHALLENGE_CARD_LEPREGNOMES    = 94177,
    ITEM_CHALLENGE_CARD_YIKKAN         = 94183,
    ITEM_CHALLENGE_CARD_AKAMA          = 94184,
    ITEM_CHALLENGE_CARD_HOOFSTOMP      = 94185,
    ITEM_CHALLENGE_CARD_UNGULOXX       = 94186,
    ITEM_CHALLENGE_CARD_GG_ENGINEERING = 94178,
    ITEM_CHALLENGE_CARD_DARK_SUMMONER  = 94179,
    ITEM_CHALLENGE_CARD_BATTLETRONE    = 94180,
    ITEM_CHALLENGE_CARD_MEATBALL       = 94181,

    // Non default challenge cards
    ITEM_CHALLENGE_CARD_MECHA_BRUCE    = 97563,
    ITEM_CHALLENGE_CARD_GRANDPA_GRUMPL = 97285,
    ITEM_CHALLENGE_CARD_BLINGTRON_3000 = 97445,
    ITEM_CHALLENGE_CARD_MASTER_BOOM    = 97284,
};

const std::map<uint32, uint32> EncounterMatchType =
{
    { ACTION_BRUCE,           NPC_BRUCE },
    { ACTION_VIAN,            NPC_VIAN_THE_VOLATILE },
    { ACTION_GOREDOME,        NPC_GOREDOME },
    { ACTION_VISHAS,          NPC_DUNGEON_MASTER_VISHAS },
    { ACTION_DIPPY,           NPC_DIPPY },
    { ACTION_KIRRAWK,         NPC_KIRRAWK },
    { ACTION_FRAN_AND_RIDDOH, NPC_FRAN },
    { ACTION_KING_KULAKA,     NPC_KING_KULAKA },
    { ACTION_BLAT,            NPC_BLAT },
    { ACTION_SANORIAK,        NPC_SANORIAK },
    { ACTION_IXX,             NPC_IXX },
    { ACTION_MAZHAREEN,       NPC_MAZHAREEN },
    { ACTION_CRUSH,           NPC_CRUSH },
    { ACTION_LEONA,           NPC_LEONA_EARTHWIND },
    { ACTION_DOMINIKA,        NPC_DOMINIKA_THE_ILLUSIONIST },
    { ACTION_DEEKEN,          NPC_DEEKEN},
    { ACTION_MILLIE_WATT,     NPC_MILLIE_WATT },
    { ACTION_FJOLL,           NPC_FJOLL },
    { ACTION_PROBOSKUS,       NPC_PROBOSKUS },
    { ACTION_LEPREGNOMES,     NPC_QUEAZY },
    { ACTION_YIKKAN_IZU,      NPC_YIKKAN_IZU },
    { ACTION_AKAMA,           NPC_AKAMA },
    { ACTION_HOOFSTOMP,       NPC_SMASH_HOOFSTOMP },
    { ACTION_UNGULOXX,        NPC_UNGULOXX },
    { ACTION_GG_INGENEERING,  NPC_MAX_MEGABLAST },
    { ACTION_DARK_SUMMONER,   NPC_DARK_SUMMONER },
    { ACTION_BATTLETRON,      NPC_BATTLETRON },
    { ACTION_MEATBALL,        NPC_MEATBALL },
    { ACTION_MECHA_BRUCE,     NPC_MECHA_BRUCE },
    { ACTION_GRANDPA_GRUMPLEFLOOT, NPC_GRANDPA_GRUMPLEFLOOT },
    { ACTION_BLINGTRON_3000,  NPC_BLINGTRON_3000 },
    //{ ACTION_BOOM_BOOM,       NPC_MASTER_BOOM_BOOM },
};

const std::vector<AuraType> controlMechanicType=
{
    SPELL_AURA_MOD_STUN,
    SPELL_AURA_MOD_FEAR,
    SPELL_AURA_MOD_FEAR_2,
    SPELL_AURA_MOD_BLIND,
    SPELL_AURA_MOD_CONFUSE,
};

const std::vector<uint32> Leprognomes =
{
    NPC_FLEASY,
    NPC_GREAZY,
    NPC_SLEAZY,
    NPC_WHEEZY,
};

enum eAreaTriggers
{
    AT_BOZMO_BRAWPUB_ARENA = 8717,
};

enum eType
{
    TYPE_ARENA_FILL,
    TYPE_VOLATILE_FLAMES,
    TYPE_FIRELINE,
    TYPE_LUMBERING,
    TYPE_LEPRO_OWNER,
    TYPE_IN_QUEUE,
    TYPE_QUEUE_NEXT,
    TYPE_CHARGING,
    TYPE_FIELD_MOVING,
    TYPE_CHALLENGE_CARD,
    TYPE_BLINGTRON_CHARGED,
};

const std::map<uint32, uint32> queueGossipType =
{
    { 0, 724006 },
    { 1, 724007 },
    { 2, 724008 },
    { 3, 724009 },
    { 4, 724010 },
    { 5, 724011 },
    { 6, 724012 },
    { 7, 724013 },
    { 8, 724014 },
    { 9, 724015 },
};

const std::map<uint32, std::array<uint32, 2>> reputationYellType =
{
    {TALK_RANK_1, { 0, 1000    }},
    {TALK_RANK_2, { 1000, 2000 }},
    {TALK_RANK_3, { 2000, 3000 }},
    {TALK_RANK_4, { 3000, 4000 }},
    {TALK_RANK_5, { 4000, 5000 }},
    {TALK_RANK_6, { 5000, 6000 }},
    {TALK_RANK_7, { 6000, 7000 }},
    {TALK_RANK_8, { 7000, 8000 }},
    {TALK_RANK_9, { 8000, 9000 }},
};

const std::map<uint32, uint32> reputationEncounterType =
{
    { 0,    ACTION_BRUCE           },
    { 250,  ACTION_VIAN            },
    { 500,  ACTION_GOREDOME        },
    { 750,  ACTION_VISHAS          },
    { 1000, ACTION_DIPPY           },
    { 1250, ACTION_KIRRAWK         },
    { 1500, ACTION_FRAN_AND_RIDDOH },
    { 1750, ACTION_KING_KULAKA     },
    { 2000, ACTION_BLAT            },
    { 2250, ACTION_SANORIAK        },
    { 2500, ACTION_IXX             },
    { 2750, ACTION_MAZHAREEN       },
    { 3000, ACTION_CRUSH           },
    { 3250, ACTION_LEONA           },
    { 3500, ACTION_DOMINIKA        },
    { 3750, ACTION_DEEKEN          },
    { 4000, ACTION_MILLIE_WATT     },
    { 4250, ACTION_FJOLL           },
    { 4500, ACTION_PROBOSKUS       },
    { 4750, ACTION_LEPREGNOMES     },
    { 5000, ACTION_YIKKAN_IZU      },
    { 5250, ACTION_AKAMA           },
    { 5500, ACTION_HOOFSTOMP       },
    { 5750, ACTION_UNGULOXX        },
    { 6000, ACTION_GG_INGENEERING  },
    { 6250, ACTION_DARK_SUMMONER   },
    { 6500, ACTION_BATTLETRON      },
    { 6750, ACTION_MEATBALL        },
};

const std::map<uint32, uint32> invChallengeCardsType
{
     { ITEM_CHALLENGE_CARD_BRUCE,          ACTION_BRUCE,           },
     { ITEM_CHALLENGE_CARD_VIAN,           ACTION_VIAN,            },
     { ITEM_CHALLENGE_CARD_GOREDOME,       ACTION_GOREDOME,        },
     { ITEM_CHALLENGE_CARD_VISHAS,         ACTION_VISHAS,          },
     { ITEM_CHALLENGE_CARD_DIPPY,          ACTION_DIPPY,           },
     { ITEM_CHALLENGE_CARD_KIRRAWK,        ACTION_KIRRAWK,         },
     { ITEM_CHALLENGE_CARD_FRAN,           ACTION_FRAN_AND_RIDDOH, },
     { ITEM_CHALLENGE_CARD_KULAKA,         ACTION_KING_KULAKA,     },
     { ITEM_CHALLENGE_CARD_BLAT,           ACTION_BLAT,            },
     { ITEM_CHALLENGE_CARD_SANORIAK,       ACTION_SANORIAK,        },
     { ITEM_CHALLENGE_CARD_IXX,            ACTION_IXX,             },
     { ITEM_CHALLENGE_CARD_MAZHAREEN,      ACTION_MAZHAREEN,       },
     { ITEM_CHALLENGE_CARD_CRUSH,          ACTION_CRUSH,           },
     { ITEM_CHALLENGE_CARD_LEONA,          ACTION_LEONA,           },
     { ITEM_CHALLENGE_CARD_DOMINIKA,       ACTION_DOMINIKA,        },
     { ITEM_CHALLENGE_CARD_DEEKEN,         ACTION_DEEKEN,          },
     { ITEM_CHALLENGE_CARD_MILLIE_WATT,    ACTION_MILLIE_WATT,     },
     { ITEM_CHALLENGE_CARD_FJOLL,          ACTION_FJOLL,           },
     { ITEM_CHALLENGE_CARD_PROBKOSUS,      ACTION_PROBOSKUS,       },
     { ITEM_CHALLENGE_CARD_LEPREGNOMES,    ACTION_LEPREGNOMES,     },
     { ITEM_CHALLENGE_CARD_YIKKAN,         ACTION_YIKKAN_IZU,      },
     { ITEM_CHALLENGE_CARD_AKAMA,          ACTION_AKAMA,           },
     { ITEM_CHALLENGE_CARD_HOOFSTOMP,      ACTION_HOOFSTOMP,       },
     { ITEM_CHALLENGE_CARD_UNGULOXX,       ACTION_UNGULOXX,        },
     { ITEM_CHALLENGE_CARD_GG_ENGINEERING, ACTION_GG_INGENEERING,  },
     { ITEM_CHALLENGE_CARD_DARK_SUMMONER,  ACTION_DARK_SUMMONER,   },
     { ITEM_CHALLENGE_CARD_BATTLETRONE,    ACTION_BATTLETRON,      },
     { ITEM_CHALLENGE_CARD_MEATBALL,       ACTION_MEATBALL,        },
     { ITEM_CHALLENGE_CARD_MECHA_BRUCE,    ACTION_MECHA_BRUCE      },
     { ITEM_CHALLENGE_CARD_GRANDPA_GRUMPL, ACTION_GRANDPA_GRUMPLEFLOOT },
     { ITEM_CHALLENGE_CARD_BLINGTRON_3000, ACTION_BLINGTRON_3000   },
     //{ ITEM_CHALLENGE_CARD_MASTER_BOOM,    ACTION_BOOM_BOOM        },
};

#endif // BRAWLERS_GUILD_H_