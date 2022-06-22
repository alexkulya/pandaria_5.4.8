/*
    Dungeon : Stormstout Brewery 85-87
    Instance General Script
*/

#include "NewScriptPCH.h"
#include "stormstout_brewery.h"

class instance_stormstout_brewery : public InstanceMapScript
{
public:
    instance_stormstout_brewery() : InstanceMapScript("instance_stormstout_brewery", 961) { }

    struct instance_stormstout_brewery_InstanceMapScript : public InstanceScript
    {
        instance_stormstout_brewery_InstanceMapScript(Map* map) : InstanceScript(map) {}

        uint64 ookookGuid;
        uint64 hoptallusGuid;
        uint64 yanzhuGuid;
        uint64 ookexitdoorGuid;
        uint64 doorGuid;
        uint64 door2Guid;
        uint64 door3Guid;
        uint64 door4Guid;
        uint64 lastdoorGuid;
        uint64 carrotdoorGuid;
        uint64 sTriggerGuid;
        uint16 HoplingCount;
        uint16 GoldenHoplingCount;

        void Initialize()
        {
            SetBossNumber(3);
            ookookGuid      = 0;
            hoptallusGuid   = 0;
            yanzhuGuid      = 0;
            ookexitdoorGuid = 0;
            doorGuid = 0;
            door2Guid = 0;
            door3Guid = 0;
            door4Guid = 0;
            lastdoorGuid = 0;
            carrotdoorGuid = 0;
            HoplingCount = 0;
            GoldenHoplingCount = 0;
            sTriggerGuid = 0;
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
            case GO_EXIT_OOK_OOK:
                ookexitdoorGuid = go->GetGUID();
                break;
            case GO_DOOR:
                doorGuid = go->GetGUID();
                break;
            case GO_DOOR2:
                door2Guid = go->GetGUID();
                break;
            case GO_DOOR3:
                door3Guid = go->GetGUID();
                break;
            case GO_DOOR4:
                door4Guid = go->GetGUID();
                break;
            case GO_LAST_DOOR:
                lastdoorGuid = go->GetGUID();
                break;
            case GO_CARROT_DOOR:
                carrotdoorGuid = go->GetGUID();
                break;
            }
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_OOK_OOK:
                    ookookGuid = creature->GetGUID();
                    break;
                case NPC_HOPTALLUS:
                    hoptallusGuid = creature->GetGUID();
                    break;
                case NPC_YAN_ZHU:
                    yanzhuGuid = creature->GetGUID();
                    break;
                case NPC_TRIGGER_SUMMONER:
                    sTriggerGuid = creature->GetGUID();
                    break;
            }
        }
        
        bool SetBossState(uint32 id, EncounterState state)
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
            case DATA_OOK_OOK:
                {
                    if (state == DONE)
                    {
                        HandleGameObject(ookexitdoorGuid, true);
                        HandleGameObject(doorGuid, true);
                        HandleGameObject(door2Guid, true);
                        if (Creature* trigger = instance->GetCreature(sTriggerGuid))
                        {
                            trigger->CastSpell(trigger, SPELL_HOPPER_SUM_EXPLOSIVE);
                            trigger->CastSpell(trigger, SPELL_HOPPER_SUM_HAMMER);
                            trigger->CastSpell(trigger, SPELL_HOPLING_AURA_3);
                        }
                    }
                }
                break;
            case DATA_HOPTALLUS:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        HandleGameObject(door2Guid, true);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(door2Guid, false);
                        if (Creature* trigger = instance->GetCreature(sTriggerGuid))
                        {
                            trigger->RemoveAurasDueToSpell(SPELL_HOPPER_SUM_EXPLOSIVE);
                            trigger->RemoveAurasDueToSpell(SPELL_HOPPER_SUM_HAMMER);
                            trigger->RemoveAurasDueToSpell(SPELL_HOPLING_AURA_3);
                        }
                        break;
                    case DONE:
                        {
                            HandleGameObject(door2Guid, true);
                            HandleGameObject(door3Guid, true);
                            HandleGameObject(door4Guid, true);
                            if (GameObject* go = instance->GetGameObject(carrotdoorGuid))
                                go->Delete();
                        }
                        break;
                    }
                }
                break;
            case DATA_YAN_ZHU:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                    case DONE:
                        HandleGameObject(lastdoorGuid, true);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(lastdoorGuid, false);
                        break;
                    }
                }
                break;
            }

            return true;
        }

        void SetData(uint32 type, uint32 data)
        {
            if (type == DATA_HOPLING)
            {
                HoplingCount = data;
                if (HoplingCount > 100)
                    HoplingCount = 100;
            }

            if (type == DATA_GOLDEN_HOPLING)
                GoldenHoplingCount = data;
        }

        uint32 GetData(uint32 type)
        {
            if (type == DATA_HOPLING)
                return HoplingCount;

            if (type == DATA_GOLDEN_HOPLING)
                return GoldenHoplingCount;

            return 0;
        }

        uint64 GetData64(uint32 type)
        {
            switch (type)
            {
                case NPC_OOK_OOK:
                    return ookookGuid;
                case NPC_HOPTALLUS:
                    return hoptallusGuid;
                case NPC_YAN_ZHU:
                    return yanzhuGuid;
            }

            return 0;
        }

        void Update(uint32 diff) 
        {
            // Challenge
            InstanceScript::Update(diff);
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_stormstout_brewery_InstanceMapScript(map);
    }
};

void AddSC_instance_stormstout_brewery()
{
    new instance_stormstout_brewery();
}
