#ifndef DEF_ZULGURUB_H
#define DEF_ZULGURUB_H

uint32 const EncounterCount = 6;

enum DataTypes
{
    DATA_VENOXIS                    = 0,
    DATA_MANDOKIR                   = 1,
    DATA_CACHE_OF_MADNESS_BOSS      = 2,
    DATA_KILNARA                    = 3,
    DATA_ZANZIL                     = 4,
    DATA_JINDO                      = 5,

    // Cache of Madness
    DATA_ARTIFACT_DWARVEN           = 6,
    DATA_ARTIFACT_ELVEN             = 7,
    DATA_ARTIFACT_TROLL             = 8,
    DATA_ARTIFACT_FOSSIL            = 9,

    DATA_BOSSES                     = 10,

    DATA_ARTIFACTS_ACTIVATED,
};

enum CreatureIds
{
    NPC_VENOXIS                     = 52155,
    NPC_MANDOKIR                    = 52151,
    NPC_KILNARA                     = 52059,
    NPC_ZANZIL                      = 52053,
    NPC_JINDO                       = 52148,

    // Bloodlord Mandokir
    NPC_CHAINED_SPIRIT              = 52156,
    NPC_OHGAN                       = 52157,

    // Cache of Madness
    NPC_HAZZARAH                    = 52271,
    NPC_RENATAKI                    = 52269,
    NPC_WUSHOOLAY                   = 52286,
    NPC_GRILEK                      = 52258,

    NPC_NIGHTMARE_ILLUSION          = 52284,

    NPC_CACHE_OF_MADNESS_SUMMONER   = 45979,

    NPC_ARTIFACT_DWARVEN            = 52449,
    NPC_ARTIFACT_ELVEN              = 52451,
    NPC_ARTIFACT_TROLL              = 52453,
    NPC_ARTIFACT_FOSSIL             = 52455,
    NPC_ARTIFACT_ACTIVE_DWARVEN     = 52446,
    NPC_ARTIFACT_ACTIVE_ELVEN       = 52450,
    NPC_ARTIFACT_ACTIVE_TROLL       = 52452,
    NPC_ARTIFACT_ACTIVE_FOSSIL      = 52454,
};

enum GameObjectIds
{
    GO_VENOXIS_EXIT     = 208844,
    GO_MANDOKIR_EXIT1   = 208845,
    GO_MANDOKIR_EXIT2   = 208846,
    GO_MANDOKIR_EXIT3   = 208847,
    GO_MANDOKIR_EXIT4   = 208848,
    GO_MANDOKIR_EXIT5   = 208849,
    GO_ZANZIL_EXIT      = 208850,
    GO_KILNARA_EXIT     = 180497,

    // Cache of Madness
    GO_THE_CACHE_OF_MADNESS_DOOR    = 208843
};

enum OtherSpells
{
    SPELL_FROSTBURN_FORMULA = 96331,
    SPELL_HYPPOTHERMIA      = 96332,
};

enum InstanceSpells
{
    CACHE_OF_MADNESS_SUMMON_VISUAL    = 97081,
    CACHE_OF_MADNESS_SHATTER_ARTIFACT = 97065
};
enum InstanceEvents
{
    EVENT_CACHE_OF_MADNESS_START_SUMMON      = 1,
    EVENT_CACHE_OF_MADNESS_SHATTER_ARTIFACTS = 2,
    EVENT_CACHE_OF_MADNESS_SUMMON            = 3,
    EVENT_CACHE_OF_MADNESS_HIDE_PORTAL       = 4
};

enum Worldstates
{
    WORLDSTATE_OHGANOT_SO_FAST = 9161,
    WORLDSTATE_SPIRIT_TWISTER  = 9146,
};

uint64 const CACHE_OF_MADNESS_SUMMONER_GUID = 335569;
uint32 const CACHE_OF_MADNESS_BOSSES[] =
{
    NPC_HAZZARAH,
    NPC_RENATAKI,
    NPC_WUSHOOLAY,
    NPC_GRILEK
};
uint32 const CACHE_OF_MADNESS_BOSSES_COUNT = 4;
uint64 const ARTIFACT_GUIDS_BY_TYPE[][6] =
{
    { 5, 335460, 335461, 335462, 337768, 337769 },
    { 4, 335447, 335448, 337765, 337766 },
    { 4, 335455, 335456, 335457, 335458 },
    { 5, 335450, 335451, 335452, 335453, 337771 }
};
uint32 const ARTIFACT_ENTRIES[] =
{
    NPC_ARTIFACT_DWARVEN,
    NPC_ARTIFACT_ELVEN,
    NPC_ARTIFACT_TROLL,
    NPC_ARTIFACT_FOSSIL
};
uint32 const ARTIFACT_WAYPOINTS_BY_TYPE[] =
{
    5244600,
    5245000,
    5245200,
    5245400
};
uint32 const ARTIFACT_TYPE_COUNT = 4;

template<class AI>
CreatureAI* GetInstanceAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_zulgurub"))
                return new AI(creature);
    return NULL;
}

#endif

