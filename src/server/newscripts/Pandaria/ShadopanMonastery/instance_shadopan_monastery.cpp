/*
    Dungeon : Shandopan Monastery 87-89
    Instance General Script
*/

#include "NewScriptPCH.h"
#include "shadopan_monastery.h"

Position snowdriftCenterPos = {3659.08f, 3015.38f, 804.74f};

class instance_shadopan_monastery : public InstanceMapScript
{
public:
    instance_shadopan_monastery() : InstanceMapScript("instance_shadopan_monastery", 959) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_shadopan_monastery_InstanceMapScript(map);
    }

    struct instance_shadopan_monastery_InstanceMapScript : public InstanceScript
    {
        uint8 aliveNoviceCount;
        uint8 aliveMinibossCount;

        uint64 guCloudstikeGuid;
        uint64 masterSnowdriftGuid;
        uint64 shaViolenceGuid;
        uint64 taranZhuGuid;

        uint64 azureSerpentGuid;

        uint64 cloudstikeEntranceGuid;
        uint64 cloudstikeExitGuid;
        uint64 snowdriftEntranceGuid;
        uint64 snowdriftPossessionsGuid;
        uint64 zhuchestGuid;
        uint64 snowdriftFirewallGuid;
        uint64 snowdriftDojoDoorGuid;
        uint64 snowdriftExitGuid;
        
        uint64 shaEntranceGuid;
        uint64 shaExitGuid;
        
        std::list<uint64> minibossPositionsGuid;
        std::list<uint64> minibossPositionsGuidSave;

        std::list<uint64> firstDefeatedNovicePositionsGuid;
        std::list<uint64> firstDefeatedNovicePositionsGuidSave;

        std::list<uint64> secondDefeatedNovicePositionsGuid;
        std::list<uint64> secondDefeatedNovicePositionsGuidSave;
        
        std::list<uint64> firstArcherySet;
        std::list<uint64> secondArcherySet;
        std::list<uint64> archeryTargetGuids;

        uint32 dataStorage[MAX_DATA];

        instance_shadopan_monastery_InstanceMapScript(Map* map) : InstanceScript(map)
        {}

        void Initialize()
        {
            SetBossNumber(EncounterCount);

            aliveNoviceCount            = MAX_NOVICE;
            aliveMinibossCount          = 2;

            guCloudstikeGuid            = 0;
            masterSnowdriftGuid         = 0;
            shaViolenceGuid             = 0;
            taranZhuGuid                = 0;

            azureSerpentGuid            = 0;

            cloudstikeEntranceGuid      = 0;
            cloudstikeExitGuid          = 0;
            snowdriftEntranceGuid       = 0;
            snowdriftEntranceGuid       = 0;
            snowdriftPossessionsGuid    = 0;
            zhuchestGuid                = 0,
            snowdriftFirewallGuid       = 0;
            snowdriftDojoDoorGuid       = 0;
            snowdriftExitGuid           = 0;

            shaEntranceGuid             = 0;
            shaExitGuid                 = 0;
            
            firstArcherySet.clear();
            secondArcherySet.clear();

            memset(dataStorage, 0, MAX_DATA * sizeof(uint32));
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_GU_CLOUDSTRIKE:    guCloudstikeGuid    = creature->GetGUID();          return;
                case NPC_MASTER_SNOWDRIFT:  masterSnowdriftGuid = creature->GetGUID();          return;
                case NPC_SHA_VIOLENCE:      shaViolenceGuid     = creature->GetGUID();          return;
                case NPC_TARAN_ZHU:         taranZhuGuid        = creature->GetGUID();          return;
                case NPC_AZURE_SERPENT:     azureSerpentGuid    = creature->GetGUID();          return;
                case NPC_ARCHERY_TARGET:    archeryTargetGuids.push_back(creature->GetGUID());  return;
                case NPC_SNOWDRIFT_POSITION:
                {
                    uint32 guid = creature->GetDBTableGUIDLow();

                    if (creature->GetDistance(snowdriftCenterPos) > 5.0f && creature->GetDistance(snowdriftCenterPos) < 15.0f)
                    {
                        minibossPositionsGuid.push_back(creature->GetGUID());
                        minibossPositionsGuidSave.push_back(creature->GetGUID());
                    }
                    else if (creature->GetDistance(snowdriftCenterPos) > 15.0f  && creature->GetDistance(snowdriftCenterPos) < 17.5f)
                    {
                        firstDefeatedNovicePositionsGuid.push_back(creature->GetGUID());
                        firstDefeatedNovicePositionsGuidSave.push_back(creature->GetGUID());
                    }
                    else if (creature->GetDistance(snowdriftCenterPos) > 17.5f && creature->GetDistance(snowdriftCenterPos) < 25.0f)
                    {
                        secondDefeatedNovicePositionsGuid.push_back(creature->GetGUID());
                        secondDefeatedNovicePositionsGuidSave.push_back(creature->GetGUID());
                    }
                    break;
                }
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_CLOUDSTRIKE_ENTRANCE:
                    cloudstikeEntranceGuid = go->GetGUID();
                    HandleGameObject(0, true, go);
                    break;
                case GO_CLOUDSTRIKE_EXIT:
                    cloudstikeExitGuid = go->GetGUID();
                    break;
                case GO_SNOWDRIFT_ENTRANCE:
                    snowdriftEntranceGuid = go->GetGUID();
                    HandleGameObject(0, true, go);
                    break;
                case GO_SNOWDRIFT_POSSESSIONS:
                case GO_SNOWDRIFT_POSSESSIONS2:
                    snowdriftPossessionsGuid = go->GetGUID();
                    break;
                case GO_ZHU_CHEST:
                case GO_ZHU_CHEST2:
                    zhuchestGuid = go->GetGUID();
                    break;
                case GO_SNOWDRIFT_FIRE_WALL:
                    snowdriftFirewallGuid = go->GetGUID();
                    break;
                case GO_SNOWDRIFT_DOJO_DOOR:
                    snowdriftDojoDoorGuid = go->GetGUID();
                    break;
                case GO_SNOWDRIFT_EXIT:
                    snowdriftExitGuid = go->GetGUID();
                    break;
                case GO_SHA_ENTRANCE:
                    shaEntranceGuid = go->GetGUID();
                    HandleGameObject(0, true, go);
                    break;
                case GO_SHA_EXIT:
                    shaExitGuid = go->GetGUID();
                    break;
                default:
                    return;
            }
        }

        bool SetBossState(uint32 id, EncounterState state)
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case DATA_GU_CLOUDSTRIKE:
                {
                    switch (state)
                    {
                        case NOT_STARTED:
                        case FAIL:
                        {
                            HandleGameObject(cloudstikeEntranceGuid, true);
                            HandleGameObject(cloudstikeExitGuid,     false);
                            break;
                        }
                        case IN_PROGRESS:
                        {
                            HandleGameObject(cloudstikeEntranceGuid, false);
                            HandleGameObject(cloudstikeExitGuid,     false);
                            break;
                        }
                        case DONE:
                        {
                            HandleGameObject(cloudstikeEntranceGuid, true);
                            HandleGameObject(cloudstikeExitGuid,     true);
                            HandleGameObject(snowdriftEntranceGuid,  true);
                            break;
                        }
                    }
                    break;
                }
                case DATA_MASTER_SNOWDRIFT:
                {
                    switch (state)
                    {
                        case NOT_STARTED:
                        case FAIL:
                            aliveNoviceCount                    = MAX_NOVICE;
                            aliveMinibossCount                  = 2;
                            minibossPositionsGuid               = minibossPositionsGuidSave;
                            firstDefeatedNovicePositionsGuid    = firstDefeatedNovicePositionsGuidSave;
                            secondDefeatedNovicePositionsGuid   = secondDefeatedNovicePositionsGuidSave;
                            
                            HandleGameObject(snowdriftEntranceGuid, true);
                            HandleGameObject(snowdriftFirewallGuid, false);
                            HandleGameObject(snowdriftDojoDoorGuid, false);
                            HandleGameObject(snowdriftExitGuid,     false);
                            break;
                        case IN_PROGRESS:
                            HandleGameObject(snowdriftEntranceGuid, false);
                            HandleGameObject(snowdriftDojoDoorGuid, false);
                            break;
                        case DONE:
                            if (GameObject* possessions = instance->GetGameObject(snowdriftPossessionsGuid))
                                possessions->SetRespawnTime(604800);
                            
                            HandleGameObject(snowdriftEntranceGuid, true);
                            HandleGameObject(snowdriftFirewallGuid, true);
                            HandleGameObject(snowdriftDojoDoorGuid, true);
                            HandleGameObject(snowdriftExitGuid,     true);
                            HandleGameObject(shaEntranceGuid,       true);
                            break;
                    }
                    break;
                }
                case DATA_SHA_VIOLENCE:
                {
                    switch (state)
                    {
                        case NOT_STARTED:
                        case FAIL:
                            HandleGameObject(shaEntranceGuid,   true);
                            HandleGameObject(shaExitGuid,       false);
                            break;
                        case IN_PROGRESS:
                            HandleGameObject(shaEntranceGuid,   false);
                            break;
                        case DONE:
                            HandleGameObject(shaEntranceGuid,   true);
                            HandleGameObject(shaExitGuid,       true);
                            break;
                    }
                    break;
                }
                case DATA_TARAN_ZHU:
                {
                    switch (state)
                    {
                    case IN_PROGRESS:
                        DoAddAuraOnPlayers(SPELL_HATE);
                        break;
                    case NOT_STARTED:
                    case FAIL:
                        {
                            Map::PlayerList const &PlayerList = instance->GetPlayers();
                            
                            if (!PlayerList.isEmpty())
                                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                    if (Player* player = i->getSource())
                                    {
                                        player->RemoveAurasDueToSpell(SPELL_HATE);
                                        player->RemoveAurasDueToSpell(SPELL_HAZE_OF_HATE);
                                        player->RemoveAurasDueToSpell(SPELL_HAZE_OF_HATE_VISUAL);
                                    }
                        }
                        break;
                    case DONE:
                        if (GameObject* chest = instance->GetGameObject(zhuchestGuid))
                            chest->SetRespawnTime(604800);
                        
                        Map::PlayerList const &PlayerList = instance->GetPlayers();

                        if (!PlayerList.isEmpty())
                        {
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                if (Player* player = i->getSource())
                                {
                                    if (player->HasAura(SPELL_HAZE_OF_HATE))
                                        player->CastSpell(player, SPELL_ACHIEVEMENT_CHECK, true);
                                    player->RemoveAurasDueToSpell(SPELL_HATE);
                                    player->RemoveAurasDueToSpell(SPELL_HAZE_OF_HATE);
                                    player->RemoveAurasDueToSpell(SPELL_HAZE_OF_HATE_VISUAL);
                                }
                        }
                        break;
                    }
                    break;
                }
            }
            return true;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case DATA_DEFEATED_NOVICE:
                    if (!--aliveNoviceCount)
                        if (Creature* snowdrift = instance->GetCreature(masterSnowdriftGuid))
                            if (snowdrift->IsAIEnabled)
                                snowdrift->AI()->DoAction(ACTION_NOVICE_DONE);
                    break;
                case DATA_DEFEATED_MINIBOSS:
                    if (!--aliveMinibossCount)
                    {
                        if (Creature* snowdrift = instance->GetCreature(masterSnowdriftGuid))
                            if (snowdrift->IsAIEnabled)
                                snowdrift->AI()->DoAction(ACTION_MINIBOSS_DONE);

                        HandleGameObject(snowdriftFirewallGuid, true);
                        HandleGameObject(snowdriftDojoDoorGuid, true);
                    }
                    break;
                default:
                    if (type < MAX_DATA)
                        dataStorage[type] = data;
                    break;
            }
        }

        uint32 GetData(uint32 type)
        {
            if (type < MAX_DATA)
                return dataStorage[type];

            return 0;
        }

        uint64 GetData64(uint32 type)
        {
            switch (type)
            {
                case NPC_GU_CLOUDSTRIKE:        return guCloudstikeGuid;
                case NPC_MASTER_SNOWDRIFT:      return masterSnowdriftGuid;
                case NPC_SHA_VIOLENCE:          return shaViolenceGuid;
                case NPC_TARAN_ZHU:             return taranZhuGuid;
                case NPC_AZURE_SERPENT:         return azureSerpentGuid;
                case NPC_ARCHERY_TARGET:        return Trinity::Containers::SelectRandomContainerElement(archeryTargetGuids);
                case DATA_RANDOM_FIRST_POS:
                {
                    if (firstDefeatedNovicePositionsGuid.empty())
                        return 0;

                    uint64 guid = Trinity::Containers::SelectRandomContainerElement(firstDefeatedNovicePositionsGuid);
                    firstDefeatedNovicePositionsGuid.remove(guid);
                    return guid;
                }
                case DATA_RANDOM_SECOND_POS:
                {
                    if (secondDefeatedNovicePositionsGuid.empty())
                        return 0;

                    uint64 guid = Trinity::Containers::SelectRandomContainerElement(secondDefeatedNovicePositionsGuid);
                    secondDefeatedNovicePositionsGuid.remove(guid);
                    return guid;
                }
                case DATA_RANDOM_MINIBOSS_POS:
                {
                    if (minibossPositionsGuid.empty())
                        return 0;

                    uint64 guid = Trinity::Containers::SelectRandomContainerElement(minibossPositionsGuid);
                    minibossPositionsGuid.remove(guid);
                    return guid;
                }
            }

            return 0;
        }

        void Update(uint32 diff) 
        {
            // Challenge
            InstanceScript::Update(diff);
        }
    };

};

void AddSC_instance_shadopan_monastery()
{
    new instance_shadopan_monastery();
}
