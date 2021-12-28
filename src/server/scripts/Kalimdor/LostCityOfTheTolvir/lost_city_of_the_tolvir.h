#ifndef DEF_LOST_CITY_OF_THE_TOLVIR_H
#define DEF_LOST_CITY_OF_THE_TOLVIR_H

enum Data
{
    DATA_GENERAL_HUSAM          = 0,
    DATA_LOCKMAW                = 1,
    DATA_AUGH                   = 2,
    DATA_HIGH_PROPHET_BARIM     = 3,
    DATA_SIAMAT                 = 4,
    DATA_HARBINGER              = 5,
    DATA_BLAZE                  = 6,
};

enum Creatures
{
    // Dungeon Bosses
    BOSS_GENERAL_HUSAM           = 44577,
    BOSS_LOCKMAW                 = 43614,
    BOSS_AUGH                    = 49045,
    BOSS_HIGH_PROPHET_BARIM      = 43612,
    BOSS_SIAMAT                  = 44819,
    // Various NPCs
    NPC_WIND_TUNNEL              = 48092,
};

enum GameObjects
{
    SIAMAT_PLATFORM              = 205365,
};

template<class AI>
CreatureAI* GetInstanceAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_lost_city_of_the_tolvir"))
                return new AI(creature);
    return NULL;
}

#endif