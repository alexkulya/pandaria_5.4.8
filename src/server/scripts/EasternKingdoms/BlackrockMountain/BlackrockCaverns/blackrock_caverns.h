#ifndef DEF_BLACKROCK_CAVERNS_H
#define DEF_BLACKROCK_CAVERNS_H

const Position RazFirstBridgePath[9]
{
    { 216.90f, 948.65f, 191.16f, 3.07f },
    { 203.01f, 929.77f, 190.88f, 4.08f },
    { 218.00f, 911.60f, 190.98f, 5.40f },
    { 265.99f, 917.59f, 191.00f, 0.12f },
    { 296.27f, 950.01f, 191.15f, 0.81f },
    { 328.31f, 950.07f, 190.82f, 0.00f },
    { 375.67f, 948.71f, 192.23f, 6.26f },
    { 406.94f, 936.18f, 194.91f, 5.90f },
    { 406.19f, 906.01f, 163.49f, 4.31f },
};

const Position RazSecondBridgePath[5]
{
    { 387.33f, 817.09f, 103.67f, 3.23f },
    { 360.05f, 815.88f, 105.27f, 3.11f },
    { 317.85f, 815.45f, 103.55f, 3.15f },
    { 293.12f, 815.62f, 103.51f, 3.12f },
    { 219.40f, 718.88f, 106.42f, 4.16f }, // Jump to these
};

enum Data
{
    DATA_ROMOGG                     = 0,
    DATA_CORLA                      = 1,
    DATA_KARSH                      = 2,
    DATA_BEAUTY                     = 3,
    DATA_ASCENDANT_LORD_OBSIDIUS    = 4,
    DATA_TEAM_IN_INSTANCE           = 5,
};

enum iSpells
{
    SPELL_INVISIBLE_DETECT = 18950,
};

enum NPCs
{
    NPC_ROMOGG                  = 39665,
    NPC_CORLA                   = 39679,
    NPC_KARSH                   = 39698,
    NPC_BEAUTY                  = 39700,
    NPC_ASCENDANT_LORD_OBSIDIUS = 39705,

    NPC_CONFLAGRATION            = 39994,
    NPC_CRAZED_MAGE              = 39982,
    NPC_DEFILED_EARTH_RAGER      = 40023,
    NPC_EVOLVED_TWILIGHT_ZEALOT  = 39987,
    NPC_INCENDIARY_SPARK         = 40021,
    NPC_MAD_PRISONER             = 39985,
    NPC_TWILIGHT_ELEMENT_WARDEN  = 40017,
    NPC_TWILIGHT_FLAME_CALLER    = 39708,
    NPC_TWILIGHT_OBSIDIAN_BORER  = 40019,
    NPC_TWILIGHT_SADIST          = 39980,
    NPC_TWILIGHT_TORTURER        = 39978,
    NPC_TWILIGHT_ZEALOT          = 39990,

    NPC_RAZ_THE_CRAZED           = 39670,
    NPC_FINKLE_EINHORN           = 49476,
    NPC_TWILIGHT_PORTAL          = 51340,

    // Corla, Herald of Twilight
    NPC_TWILIGHT_ZEALOT_CORLA    = 50284,
    NPC_NETHER_ESSENCE_TRIGGER   = 49526,
};

enum GameObjectIds
{
    GO_STONE_TABLET             = 207412,
    GO_PORTA1                   = 402092,
    GO_PORTA2                   = 315000,
    GO_PORTA3                   = 315001,
    GO_PORTA4                   = 315002,
};

enum eActions
{
    ACTION_RAZ_BREAK_PRISON = 0,
    ACTION_RAZ_NEXT_BRIDGE  = 1,
};

enum Types
{
    TYPE_KILLED_ANGERED_EARTH,
    TYPE_EVOLVED_SUCCESSED,
};

enum Worldstates
{
    WORLDSTATE_CRUSHING_BONES_AND_CRACKING_SKULLS = 8770,
    WORLDSTATE_ARRESTED_DEVELOPMENT               = 8772,
    WORLDSTATE_TOO_HOT_TO_HANDLE                  = 8773,
    WORLDSTATE_ASCENDANT_DESCENDING               = 8774,
};

template<class AI>
CreatureAI* GetInstanceAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_blackrock_caverns"))
                return new AI(creature);
    return NULL;
}

#endif
