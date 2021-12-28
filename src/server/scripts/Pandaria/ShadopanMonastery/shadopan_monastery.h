#ifndef SHADOPAN_MONASTERY_H_
#define SHADOPAN_MONASTERY_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"

uint32 const EncounterCount = 4;

#define MAX_NOVICE              24

enum DataTypes
{
    DATA_GU_CLOUDSTRIKE         = 0,
    DATA_MASTER_SNOWDRIFT       = 1,
    DATA_SHA_VIOLENCE           = 2,
    DATA_TARAN_ZHU              = 3,
    DATA_SNOWDRIFT_STATE        = 4,
    DATA_RANDOM_FIRST_POS       = 5,
    DATA_RANDOM_SECOND_POS      = 6,
    DATA_RANDOM_MINIBOSS_POS    = 7,
    DATA_DEFEATED_NOVICE        = 8,
    DATA_DEFEATED_MINIBOSS      = 9,
    DATA_ARCHERY                = 10,
    DATA_FIRE_ARCHERY           = 11,
    DATA_AZURE_SERPENT          = 12,
    DATA_ARCHERY_TARGET         = 13,
    DATA_PANDAREN_REFEREE       = 14,
    DATA_TARAN_ZHU_CACHE        = 15,
    DATA_POSSESSIONS            = 16,
    MAX_DATA,

    TYPE_OBVIOUS_SOLUTION,
    DATA_SHA_PRISON_1,
    DATA_SHA_PRISON_2,
    DATA_SHA_PRISON_3,
    DATA_CONTAINMENT_OVERRIDE,
};

enum CreaturesIds
{
    NPC_GU_CLOUDSTRIKE          = 56747,
    NPC_MASTER_SNOWDRIFT        = 56541,
    NPC_SHA_VIOLENCE            = 56719,
    NPC_TARAN_ZHU               = 56884,
    // Gu Cloudstrike
    NPC_AZURE_SERPENT           = 56754,
    NPC_GUARDIAN                = 59741,
    // Master Snowdrift
    NPC_NOVICE                  = 56395,
    NPC_SNOWDRIFT_POSITION      = 56397,
    NPC_FLAGRANT_LOTUS          = 56472,
    NPC_FLYING_SNOW             = 56473,
    NPC_SNOWDRIFT_CLONE         = 56713,
    NPC_PANDAREEN_REFEREE       = 56505,
    NPC_LOTUS_STAFF             = 56678,
    NPC_SNOWDRIFT_QUESTENDER    = 64387,
    // Sha of Violence
    NPC_LESSER_VOLATILE_ENERGY  = 66652,
    // Trashs
    NPC_ARCHERY_FIRST           = 64549,
    NPC_ARCHERY_SECOND          = 56767,
    NPC_ARCHERY_TARGET          = 64550,
    NPC_RESIDUAL_OF_HATRED      = 58803,
    NPC_VESTIGE_OF_HATRED       = 58807,
    NPC_FRAGMENT_OF_HATRED      = 58810,
    NPC_SHADO_PAN_AMBUSHER      = 59752,
    NPC_SHADO_PAN_WARDEN        = 59751,
    NPC_UNSTABLE_ENERGY         = 59811,
    NPC_TRAINING_TARGET         = 60162,
    NPC_HATEFUL_ESSENCE         = 58812,

    // Achiev Required
    NPC_VOLATILE_ENERGY         = 56766,
    NPC_DESTROYING_SHA          = 56765,
    NPC_SHA_MANIFESTATION       = 58201,
};

enum ObjectsIds
{
    GO_CLOUDSTRIKE_ENTRANCE     = 210863,
    GO_CLOUDSTRIKE_EXIT         = 210864,
    GO_SNOWDRIFT_ENTRANCE       = 213194,
    GO_SNOWDRIFT_FIRE_WALL      = 212908,
    GO_SNOWDRIFT_DOJO_DOOR      = 210800,
    GO_SNOWDRIFT_EXIT           = 210862,
    GO_SNOWDRIFT_POSSESSIONS    = 214519,
    GO_SHA_ENTRANCE             = 210867,
    GO_SHA_EXIT                 = 210866,
    GO_TARAN_ZHU_CACHE          = 213888,
    GO_SNOWDRIFT_POSSISIONS_H   = 214518,
    GO_TARAN_ZHU_CACHE_H        = 213889,
    GO_CHALLENGE_DOOR           = 211989,

    GO_CONTAINMENT_OVERRIDE     = 213457,
    GO_SHA_PRISON_1             = 212062,
    GO_SHA_PRISON_2             = 212063,
    GO_SHA_PRISON_3             = 212064,
};

enum SharedSpells
{
    SPELL_HATE                  = 107085,
    SPELL_HAZE_OF_HATE          = 107087,
    SPELL_HAZE_OF_HATE_VISUAL   = 107217,
    SPELL_RESPECT               = 118918,
};

Position const IceArchersPosition[3] =
{
    {3670.379f, 2974.310f, 874.172f, 4.673f},
    {3657.360f, 2996.389f, 863.440f, 4.952f},
    {3673.500f, 2998.620f, 863.341f, 4.877f}
};

Position const FireArchersPosition[3] =
{
    {3978.959f, 2977.770f, 832.538f, 1.84f},
    {3984.889f, 2979.379f, 832.414f, 1.84f},
    {3971.669f, 2976.040f, 832.411f, 1.84f}
};

// Real jump points
const std::vector<Position> m_NovicePos =
{
    { 3657.27f, 3039.42f, 804.30f, 4.06f },
    { 3659.71f, 3037.72f, 804.30f, 4.06f },
    { 3662.04f, 3036.03f, 804.30f, 4.06f },
    { 3675.17f, 3026.88f, 804.30f, 4.08f },
    { 3677.58f, 3025.08f, 804.30f, 4.08f },
    { 3680.14f, 3023.08f, 804.30f, 4.06f },
    { 3682.78f, 3021.06f, 804.30f, 4.06f },
};

enum InstanceScenarioData
{
    SCENARIO_ID               = 46,
    // Bosses data
    CRITERIA_GU_CLOUDSTRIKE   = 19239,
    CRITERIA_MASTER_SNOWDRIFT = 19244,
    CRITERIA_SHA_VIOLENCE     = 19240,
    CRITERIA_TARAN_ZHU        = 20672,
    CRITERIA_ENEMIES          = 19994,
    ENEMIES_COUNT             = 32,
};

enum Worldstates
{
    WORLDSTATE_RESPECT          = 9637,
    WORLDSTATE_OBVIOUS_SOLUTION = 12362,
};

const std::multimap<uint32, Position> invPrisonedShaType =
{
    { NPC_VOLATILE_ENERGY,   { 3977.97f, 2980.77f, 780.09f, 0.00f } },
    { NPC_VOLATILE_ENERGY,   { 3980.21f, 2981.08f, 780.00f, 0.15f } },
    { NPC_DESTROYING_SHA,    { 4069.58f, 2925.11f, 780.00f, 2.43f } },
    { NPC_DESTROYING_SHA,    { 4071.90f, 2925.00f, 780.00f, 3.25f } },
    { NPC_SHA_MANIFESTATION, { 4015.65f, 2829.41f, 780.09f, 0.00f } },
};

#endif // SHADOPAN_MONASTERY_H_
