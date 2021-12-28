#ifndef DEF_FIRELANDS_H
#define DEF_FIRELANDS_H

const Position FLEntrancePos = {-547.313f, 318.42f, 115.473f, 5.91667f}; // Firelands Entrance
const Position alysraEvadePos = { -11.40f, -299.22f, 49.087f, 2.93f };
const Position majordomoEventPos = { 24.80f, -326.34f, 51.178f, 2.408f };
const Position fandralLeavePoint = { 143.28f, -309.59f, 151.86f, 0.0f };

enum Data
{
    DATA_SHANNOX                = 0,
    DATA_RHYOLITH               = 1,
    DATA_BETHTILAC              = 2,
    DATA_ALYSRAZOR              = 3,
    DATA_BALEROC                = 4,
    DATA_STAGHELM               = 5,
    DATA_RAGNAROS               = 6,
    DATA_RIPLIMB                = 7,
    DATA_RAGEFACE               = 8,
    DATA_RHYOLITH_HEALTH_SHARED = 9,
    DATA_EVENT                  = 10,
    DATA_RAGNAROS_FLOOR         = 11,
    DATA_RAGNAROS_CACHE_10      = 12,
    DATA_RAGNAROS_CACHE_25      = 13,
    DATA_RITUAL_FAILED          = 14,
    DATA_VOLCANO,
    DATA_FIRELANDS_EVENT_BUNNY,
};

enum CreatureIds
{
    NPC_SHANNOX                     = 53691,
    NPC_RAGEFACE                    = 53695, 
    NPC_RIPLIMB                     = 53694,
    NPC_RHYOLITH                    = 52558,
    NPC_BETHTILAC                   = 52498,
    NPC_ALYSRAZOR                   = 52530, 
    NPC_BALEROC                     = 53494,
    NPC_STAGHELM                    = 52571,
    NPC_RAGNAROS                    = 52409,
    
    // alysrazor event
    NPC_BLAZING_MONSTROSITY_LEFT    = 53786,
    NPC_BLAZING_MONSTROSITY_RIGHT   = 53791,
    NPC_EGG_PILE                    = 53795,
    NPC_HARBINGER_OF_FLAME          = 53793,
    NPC_MOLTEN_EGG_TRASH            = 53914,
    NPC_SMOULDERING_HATCHLING       = 53794,
    NPC_FIRELANDS_EVENT_BUNNY       = 53154,
    NPC_MAJORDOMO_STAGHELM_EVENT    = 54015,
    NPC_CAPTIVE_DRUID_OF_THE_TALON  = 54019,

    NPC_CIRCLE_OF_THRONES_PORTAL    = 54247,
    NPC_DRUID_OF_THE_FLAME          = 53619,
};

enum GameobjectIds
{
    GO_CIRCLE_OF_THORNS_PORTAL1 = 209137,
    GO_CIRCLE_OF_THORNS_PORTAL2 = 209346,
    GO_CIRCLE_OF_THORNS_PORTAL3 = 209098,

    GO_BRIDGE_OF_RHYOLITH       = 209255,
    GO_FIRE_WALL_BALEROC        = 209066,
    GO_RAID_BRIDGE_FORMING      = 209277,
    GO_SULFURON_BRIDGE          = 209251,
    GO_RAGNAROS_FLOOR           = 208835,
    GO_STICKY_WEB               = 208877,
    GO_MOLTEN_METEOR            = 208966,
    GO_FIRE_WALL_FANDRAL_1      = 208906,
    GO_FIRE_WALL_FANDRAL_2      = 208873,
    GO_SULFURON_KEEP            = 209073,
    GO_VOLCANO                  = 209253,
    
    GO_CACHE_OF_THE_FIRELORD_10 = 208967,
    GO_CACHE_OF_THE_FIRELORD_25 = 209261,
};

enum QuestDefines
{
    // quest
    GO_BRANCH_OF_NORDRASSIL                     = 209100,

    // Cannot find rhyolith fragment, summon it manualy
    SPELL_CREATE_EMBERSTONE_FRAGMENT            = 100518,
    SPELL_CREATE_CHITINOUS_FRAGMENT             = 100520,
    SPELL_CREATE_PYRESHELL_FRAGMENT             = 100519,

    SPELL_CHARGED_RHYOLITH_FOCUS                = 100481,
    SPELL_CHARGED_EMBERSTONE_FOCUS              = 100499,
    SPELL_CHARGED_CHITINOUS_FOCUS               = 100501,
    SPELL_CHARGED_PYRESHELL_FOCUS               = 100500,

    SPELL_TRANSFORM_CHARGED_RHYOLITH_FOCUS      = 100477,
    SPELL_TRANSFORM_CHARGED_EMBERSTONE_FOCUS    = 100496,
    SPELL_TRANSFORM_CHARGED_CHITINOUS_FOCUS     = 100498,
    SPELL_TRANSFORM_CHARGED_PYRESHELL_FOCUS     = 100497,

    GO_RHYOLITH_FRAGMENT                        = 209033,
    GO_EMBERSTONE_FRAGMENT                      = 209035,
    GO_PYRESHELL_FRAGMENT                       = 209036,
    GO_OBSIDIAN_FLECKED_CHITIN                  = 209037,

    NPC_DULL_RHYOLITH_FOCUS                     = 53951,
    NPC_DULL_EMBERSTONE_FOCUS                   = 53968,
    NPC_DULL_CHITINOUS_FOCUS                    = 53970,
    NPC_DULL_PYRESHELL_FOCUS                    = 53963,

    NPC_CHARGED_RHYOLITH_FOCUS                  = 53955,
    NPC_CHARGED_EMBERSTONE_FOCUS                = 53969,
    NPC_CHARGED_CHITINOUS_FOCUS                 = 53971,
    NPC_CHARGED_PYRESHELL_FOCUS                 = 53967,

    EVENT_PORTALS                               = 28888,
    EVENT_RITUAL_OF_FLAMES_1                    = 28303,
    EVENT_RITUAL_OF_FLAMES_2                    = 16624,
    GO_RITUAL_OF_FLAMES_1                       = 208933,
    GO_RITUAL_OF_FLAMES_2                       = 208934,

    WORLD_STATE_RITUAL_ACHIEVEMENT              = 5926,
    SPELL_RITUAL_ACHIEVEMENT                    = 99763,

    SPELL_LEGENDARY_PORTAL_OPENING              = 101029,
    SPELL_BRANCH_OF_NORDRASSIL_WIN_COSMETIC     = 100326,
    SPELL_SMOLDERING_AURA                       = 101093,
    SPELL_SIPHON_ESSENCE_CREDIT                 = 101149,
    SPELL_HEART_OF_RAGNAROS_CREATE              = 101125,

    QUEST_HEART_OF_FLAME_ALLIANCE               = 29307,
    QUEST_HEART_OF_FLAME_HORDE                  = 29308,
};

enum Worldstates
{
    WORLDSTATE_DEATH_FROM_ABOVE          = 9331,
    WORLDSTATE_NOT_AN_AMBI_TURNER        = 9324,
    WORLDSTATE_BUCKET_LIST               = 9423,
    WORLDSTATE_SHARE_THE_PAIN            = 9377,
    WORLDSTATE_ONLY_THE_PENITENT         = 9313,
    WORLDSTATE_RANGAR_OS                 = 9472,
    WORLDSTATE_DO_A_BARREL_BRUSHFIRE     = 9332,
    WORLDSTATE_DO_A_BARREL_FIERY_TORNADO = 9330,
    WORLDSTATE_DO_A_BARREL_CLOUD         = 9334,
    WORLDSTATE_DO_A_BARREL_LAVA_SPEW     = 9333,
};

static void AddSmoulderingAura(Creature* creature)
{
    Map::PlayerList const &PlayerList = creature->GetMap()->GetPlayers();
    if (!PlayerList.isEmpty())
        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (Player* pPlayer = i->GetSource())
                if (pPlayer->GetQuestStatus(QUEST_HEART_OF_FLAME_ALLIANCE) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(QUEST_HEART_OF_FLAME_HORDE) == QUEST_STATUS_INCOMPLETE)
                {
                    creature->CastSpell(creature, SPELL_SMOLDERING_AURA, true);
                    break;
                }
}

template<class AI>
CreatureAI* GetInstanceAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_firelands"))
                return new AI(creature);
    return NULL;
}

#endif
