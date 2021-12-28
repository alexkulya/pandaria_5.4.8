#ifndef DEF_VORTEX_PINNACLE_H
#define DEF_VORTEX_PINNACLE_H

const Position PastVortexSpawnPos[2]
{
    { -313.26f, -28.47f, 626.23f, 2.84f },
    { -381.66f, 38.43f, 625.29f, 5.02f },
};

const Position ertanvortexPos_1[8] =
{
    { -702.11f, -13.50f, 635.67f, 0.0f },
    { -694.54f,   4.25f, 635.67f, 0.0f },
    { -702.07f,  22.15f, 635.67f, 0.0f },
    { -720.19f,  29.54f, 635.67f, 0.0f },
    { -737.65f,  21.79f, 635.67f, 0.0f },
    { -745.00f,   3.99f, 635.67f, 0.0f },
    { -737.42f, -13.97f, 635.67f, 0.0f },
    { -719.55f, -21.19f, 635.67f, 0.0f },
};

const Position twisterPos[8] =
{
    { -1213.09f, 37.58f, 734.17f, 0.0f },
    { -1208.80f, 54.49f, 734.17f, 0.0f },
    { -1219.45f, 68.33f, 734.17f, 0.0f },
};

const Position EranCenterPos  = { -719.97f, 4.33f, 635.67f, 5.4f };
const Position AlrairusCenter = { -1183.97f, 51.14f, 734.17f, 5.89f };
const float orientations[4]   = { 5.70f, 2.54f, 0.84f, 4.44f };

enum Data
{
    DATA_ERTAN      = 1,
    DATA_ALTAIRUS   = 2,
    DATA_ASAAD      = 3,

    DATA_GOLDEN_ORB = 4,
};

enum CreatureIds
{
    NPC_GRAND_VIZIER_ERTAN = 43878,
    NPC_ALTAIRUS           = 43873,
    NPC_ASAAD              = 43875,
    NPC_SLIPSTREAM         = 45455,
    NPC_FALL_CATCHER       = 48165,
    NPC_ERTAN_VORTEX       = 46007,
    NPC_TWISTER            = 47342,
    NPC_AIR_CURRENT        = 47305,
};

enum GameObjectIds
{
    GO_MAGIC_BRAZIER = 207408,
};

const std::vector<uint32> bossData =
{
    DATA_ERTAN,
    DATA_ALTAIRUS,
    DATA_ASAAD,
};

template<class AI>
CreatureAI* GetInstanceAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_the_vortex_pinnacle"))
                return new AI(creature);
    return NULL;
}

#endif
