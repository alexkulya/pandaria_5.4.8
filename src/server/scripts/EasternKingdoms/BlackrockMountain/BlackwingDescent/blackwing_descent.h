#ifndef DEF_BLACKWING_DESCENT_H
#define DEF_BLACKWING_DESCENT_H

enum Data
{
    DATA_MAGMAW                     = 0, 
    DATA_OMNOTRON                   = 1,
    DATA_MALORIAK                   = 2,
    DATA_CHIMAERON                  = 3,
    DATA_ATRAMEDES                  = 4,
    DATA_NEFARIAN                   = 5,
    DATA_ARCANOTRON                 = 6,
    DATA_ELECTRON                   = 7,
    DATA_MAGMATRON                  = 8,
    DATA_TOXITRON                   = 9,
    DATA_HEALTH_OMNOTRON_SHARED     = 10,
    DATA_MALORIAK_ABERRATIONS       = 11,
    DATA_BILE_O_TRON_800            = 12,
    DATA_INNER_CHAMBER_DOOR         = 13,
    DATA_MAGMAW_HEAD                = 14,
    DATA_ONYXIA                     = 15,
    DATA_NEFARIAN_FLOOR             = 16,
};

enum Creatures
{
    NPC_MAGMAW                      = 41570,
    NPC_MAGMAW_HEAD                 = 42347,
    NPC_OMNOTRON                    = 42186,
    NPC_ARCANOTRON                  = 42166, 
    NPC_ELECTRON                    = 42179, 
    NPC_MAGMATRON                   = 42178, 
    NPC_TOXITRON                    = 42180, 
    NPC_MALORIAK                    = 41378,
    NPC_ATRAMEDES                   = 41442,
    NPC_CHIMAERON                   = 43296, 
    NPC_BILE_O_TRON_800             = 44418, 

    NPC_NEFARIAN                    = 41376, 
    NPC_ONYXIA                      = 41270, 

    NPC_LORD_VICTOR_NEFARIAN        = 41379,
    NPC_LORD_VICTOR_NEFARIUS_HEROIC = 49226,
    NPC_MALORIAK_EVENT              = 43404,
    NPC_ATRAMEDES_EVENT             = 43407,

    NPC_ORB_OF_CULMINATION_STALKER  = 35592,
};

enum GOs
{
    GO_INNER_CHAMBER_DOOR    = 205830,
    GO_NEFARIAN_FLOOR        = 207834,
    GO_ORB_OF_CULMINATION    = 203254,
};

enum InstanceSpells
{
    SPELL_DRAGON_ORB = 78173,
};

enum NefariusActions
{
    // Omnotron
    ACTION_GRIP_OF_DEATH            = 1,
    ACTION_SHADOW_INFUSION          = 2,
    ACTION_OVERCHARGE               = 3,
    ACTION_ENCASING_SHADOWS         = 4,
    ACTION_OMNOTRON_DEATH           = 5,
    ACTION_OMNOTRON_INTRO           = 6,
    // Magmaw
    ACTION_SHADOW_BREATH            = 7,
    ACTION_BLAZING_INFERNO          = 8,
    ACTION_MAGMAW_INTRO             = 9,
    ACTION_MAGMAW_DEATH             = 10,
    // Maloriak
    ACTION_MALORIAK_DARK_MAGIC      = 11,
    ACTION_MALORIAK_INTRO           = 12,
    ACTION_MALORIAK_DEATH           = 13,
    // Chimaeron
    ACTION_CHIMAERON_INTRO          = 14,
    ACTION_CHIMAERON_DEATH          = 15,
    ACTION_CHIMAERON_FEUD           = 16,
    ACTION_CHIMAERON_LOW            = 17,
};

enum Worldstates
{
    WORLDSTATE_PARASITE_EVENING               = 8784,
    WORLDSTATE_ACHIEVE_A_TRON_SHOCK           = 8797,
    WORLDSTATE_ACHIEVE_A_TRON_BOMB            = 8798,
    WORLDSTATE_ACHIEVE_A_TRON_ANNIHILATOR     = 8799,
    WORLDSTATE_ACHIEVE_A_TRON_FLAMETHOWER     = 8800,
    WORLDSTATE_SILENCE_IS_GOLD = 8807,
    WORLDSTATE_FULL_OF_SOUND_AND_FURY         = 8795,
    WORLDSTATE_KEEPING_IT_IN_THE_FAMILY       = 8803,
};

template<class AI>
CreatureAI* GetInstanceAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_blackwing_descent"))
                return new AI(creature);
    return NULL;
}

#endif