#ifndef DEF_THESTONECORE_H
#define DEF_THESTONECORE_H

#define MAX_ENCOUNTERS 4

const Position ManastormJumpEvent   = { 1129.48f,  810.92f, 293.84f, 1.34f };
const Position SlabhideEntranceDoor = { 1235.72f, 1197.74f, 247.60f, 0.97f }; // we should make it handle cuz entrace/exit is same id

const Position ManaStormPathEvent[4]
{
    {  962.83f, 933.75f, 314.13f, 5.32f },
    {  979.68f, 888.54f, 304.97f, 5.01f }, // Reach this [1]
    { 1056.98f, 863.18f, 293.79f, 6.28f }, // Reach this [2]
    { 1143.77f, 880.94f, 285.03f, 0.20f }, // Reach this [3]
};

const Position SlabhidePath[2]
{
    { 1217.09f, 1219.81f, 261.12f, 6.26f },
    { 1285.66f, 1216.81f, 246.93f, 3.58f },
};

const Position StalactitePreEventPos[5]
{
    { 1201.67f, 1114.74f, 264.32f, 0.83f },
    { 1166.00f, 1115.09f, 264.16f, 3.20f },
    { 1216.86f, 1127.45f, 262.46f, 0.76f },
    { 1216.75f, 1150.14f, 256.77f, 1.57f },
    { 1218.78f, 1167.26f, 253.58f, 1.10f },
};

enum Data
{
    DATA_CORBORUS               = 0,
    DATA_SLABHIDE               = 1,
    DATA_OZRUK                  = 2,
    DATA_HIGH_PRIESTESS_AZIL    = 3,
    DATA_TEAM_IN_INSTANCE       = 4,
};

enum eSpells
{
    SPELL_TWILIGHT_FIRE_BEAM_AURA = 83743,
    SPELL_PURPLE_VORTEX_STATE     = 83237,
};

enum CreatureIds
{
    NPC_CORBORUS                  = 43438,
    NPC_SLABHIDE                  = 43214,
    NPC_OZRUK                     = 42188,
    NPC_HIGH_PRIESTESS_AZIL       = 42333,

    NPC_CRYSTALSPAWN_GIANT         = 42810,
    NPC_IMP                        = 43014,
    NPC_MILLHOUSE_MANASTORM        = 43391,
    NPC_STONECORE_BERSERKER        = 43430,
    NPC_STONECORE_BRUISER          = 42692,
    NPC_STONECORE_EARTHSHAPER      = 43537,
    NPC_STONECORE_FLAYER           = 42808,
    NPC_MAGMALORD                  = 42789,
    NPC_RIFT_CONJURER              = 42691,
    NPC_STONECORE_SENTRY           = 42695,
    NPC_STONECORE_WARBRINGER       = 42696,

    NPC_EARTHWARDEN_YRSA           = 50048,
    NPC_STONECORE_TELEPORTER1      = 51396,
    NPC_STONECORE_TELEPORTER2      = 51397,

    // Misc
    NPC_STALACTITE_TRASH           = 43357,
    NPC_STALACTITE_ENCOUNTER       = 43159,
    NPC_GENERAL_BUNNY_JMF          = 45979,
};

enum GameObjectIds
{
    GO_BROKEN_PILLAR               = 207407,
    GO_TWILIGHT_DOCUMENTS          = 207415,
    GO_ROCKDOOR_BREAK              = 207343,
    GO_ROCKDOOR_ENTERANCE_SLABHIDE = 204381,
};

enum eActions
{
    ACTION_MANASTORM_PULL    = 0,
    ACTION_STALACTITE_REMOVE = 1,
};

template<class AI>
CreatureAI* GetInstanceAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_the_stonecore"))
                return new AI(creature);
    return NULL;
}

#endif