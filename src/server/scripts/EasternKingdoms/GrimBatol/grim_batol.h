#ifndef DEF_GRIMBATOL_H
#define DEF_GRIMBATOL_H

const Position eggPos[23] =
{
    { -720.21f, -875.28f, 232.56f, 4.59f },
    { -728.52f, -875.78f, 232.55f, 3.33f },
    { -736.79f, -877.43f, 232.58f, 3.33f },
    { -748.38f, -876.34f, 233.23f, 2.87f },
    { -757.47f, -873.80f, 233.23f, 2.87f },
    { -749.23f, -871.13f, 233.23f, 0.30f },
    { -740.28f, -870.06f, 232.58f, 6.17f },
    { -731.70f, -868.19f, 232.47f, 0.00f },
    { -752.09f, -860.58f, 232.54f, 3.13f },
    { -747.30f, -779.60f, 233.23f, 1.92f },
    { -740.44f, -778.07f, 233.23f, 0.22f },
    { -729.57f, -778.52f, 232.57f, 0.11f },
    { -719.22f, -770.13f, 233.44f, 0.72f },
    { -722.09f, -780.99f, 232.55f, 4.45f },
    { -735.99f, -786.08f, 232.57f, 3.05f },
    { -751.92f, -788.38f, 233.23f, 3.33f },
    { -745.56f, -785.41f, 233.23f, 0.43f },
    { -757.08f, -780.37f, 233.23f, 2.68f },
    { -746.64f, -770.96f, 233.23f, 0.95f },
    { -731.53f, -770.02f, 236.14f, 0.10f },
    { -730.15f, -885.09f, 235.96f, 5.93f },
    { -717.82f, -887.81f, 233.95f, 6.05f },
    { -751.01f, -886.38f, 234.87f, 3.27f },
};

const Position eggsSpawnPath[2] =
{
    { -729.98f, -784.89f, 232.50f, 1.77f },
    { -728.31f, -867.80f, 232.47f, 5.16f },
};

const Position shadowgalePos[3] =
{
    { -745.07f, -845.16f, 232.41f, 0.0f },
    { -724.05f, -823.47f, 232.41f, 0.0f },
    { -741.81f, -819.44f, 232.41f, 0.0f },
};

const Position erudaxportalPos = { -641.515f, -827.8f, 235.5f, 3.069f };

enum Npcs
{
    NPC_GENERAL_UMBRISS              = 39625,
    NPC_FORGEMASTER_THRONGUS         = 40177,
    NPC_DRAHGA_SHADOWBURNER          = 40319,
    NPC_ERUDAX                       = 40484,
};

enum Data
{
    DATA_GENERAL_UMBRISS        = 0,
    DATA_FORGEMASTER_THRONGUS   = 1,
    DATA_DRAHGA_SHADOWBURNER    = 2,
    DATA_ERUDAX                 = 3,
};

enum Achievements
{
    ACHIEV_UMBRAGE_FOR_UMBRISS      = 5297,
};

enum Worldstates
{
    WORLDSTATE_BREAK_THE_EGGS = 8793,
};

template<class AI>
CreatureAI* GetInstanceAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_grim_batol"))
                return new AI(creature);
    return NULL;
}

#endif
