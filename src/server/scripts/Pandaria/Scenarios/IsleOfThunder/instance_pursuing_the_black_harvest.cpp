#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "pursuing_the_black_harvest.h"
#include "ScenarioMgr.h"

class instance_pursuing_the_black_harvest : public InstanceMapScript
{
    public:
        instance_pursuing_the_black_harvest() : InstanceMapScript("instance_pursuing_the_black_harvest", 1112) { }
    
        struct instance_pursuing_the_black_harvest_InstanceScript : public InstanceScript
        {
            instance_pursuing_the_black_harvest_InstanceScript(Map* map) : InstanceScript(map) { }
    
            EventMap m_mEvents;

            uint32 m_auiEncounter[CHAPTERS];
            uint32 chapterOne, chapterTwo, chapterThree, chapterFour, chapterFive, chapterSix, chapterSeven, chapterEight, chapterEleven;
            uint64 playerGUID;
            uint64 akamaGUID;
            uint64 essenceOrderGUID;
            uint64 kanrethardGUID;
            uint64 jubekaGUID;
            uint64 soulwellGUID;
            uint64 demongateGUID;
            std::vector<uint64> unboundDemonsList;

            void Initialize() override
            {
                SetBossNumber(CHAPTERS);
                memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

                chapterOne       = 0;
                chapterTwo       = 0;
                chapterThree     = 0;
                chapterFour      = 0;
                chapterFive      = 0;
                chapterSix       = 0;
                chapterSeven     = 0;
                chapterEight     = 0;
                chapterEleven    = 0;
                playerGUID       = 0;
                akamaGUID        = 0;
                essenceOrderGUID = 0;
                kanrethardGUID   = 0;
                jubekaGUID       = 0;
                soulwellGUID     = 0;
                demongateGUID    = 0;

                unboundDemonsList.clear();
            }

            void OnPlayerEnter(Player* player) override
            {
                // Init Scenario
                sScenarioMgr->SendScenarioState(player, 1112, STEP_ENTER_THE_BLACK_TEMPLE, 0);
                playerGUID = player->GetGUID();
            }
    
            void OnCreatureCreate(Creature* creature) override 
            {
                switch (creature->GetEntry())
                {
                    case NPC_UNBOUND_BONEMENDER:
                    case NPC_UNBOUND_CENTURION:
                    case NPC_UNBOUND_NIGHTLORD:
                    case NPC_UNBOUND_SHIVARRA:
                    case NPC_UNBOUND_SUCCUBUS:
                    case NPC_FREED_IMP:
                        creature->SetVisible(false);
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
                        unboundDemonsList.push_back(creature->GetGUID());
                        break;
                    case NPC_AKAMA:
                        akamaGUID = creature->GetGUID();
                        break;
                    case NPC_ESSENCE_OF_ORDER:
                        creature->SetVisible(false);
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
                        essenceOrderGUID = creature->GetGUID();
                        break;
                    case NPC_KANRETHAD_EBONLOCKE:
                        kanrethardGUID = creature->GetGUID();
                        break;
                    case NPC_JUBEKA_SHADOWBREAKER:
                        creature->SetVisible(false);
                        jubekaGUID = creature->GetGUID();
                        break;
                    case NPC_DEMONIC_SOULWELL:
                        soulwellGUID = creature->GetGUID();
                        break;
                    case NPC_DEMONIC_GATEWAY:
                        demongateGUID = creature->GetGUID();
                        break;
                }
            }
    
            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;
    
                return true;
            }
    
            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case STEP_ENTER_THE_BLACK_TEMPLE:
                        chapterOne = data;

                        for (auto&& itr : instance->GetPlayers())
                            if (Player* player = itr.GetSource())
                                sScenarioMgr->SendScenarioState(player, 1112, STEP_SEARCH_FOR_SIGNS, 0);
                        break;
                    case STEP_SEARCH_FOR_SIGNS:
                        chapterTwo = data;

                        for (auto&& itr : instance->GetPlayers())
                            if (Player* player = itr.GetSource())
                                sScenarioMgr->SendScenarioState(player, 1112, STEP_FOLLOW_AKAMA, 0);

                        if (Creature* akama = instance->GetCreature(GetData64(NPC_AKAMA)))
                            akama->AI()->DoAction(ACTION_MOVE_TO_SANCTUM);
                        break;
                    case STEP_FOLLOW_AKAMA:
                        chapterThree = data;

                        for (auto&& itr : instance->GetPlayers())
                            if (Player* player = itr.GetSource())
                                sScenarioMgr->SendScenarioState(player, 1112, STEP_UNCOVER_COUNCILS_PLAN, 0);
                        break;
                    case STEP_UNCOVER_COUNCILS_PLAN:
                        chapterFour = data;

                        for (auto&& itr : instance->GetPlayers())
                            if (Player* player = itr.GetSource())
                                sScenarioMgr->SendScenarioState(player, 1112, STEP_DEFEAT_ESSENCE_OF_ORDER, 0);

                        // Activate Essence of Order
                        if (Creature* essence = instance->GetCreature(GetData64(NPC_ESSENCE_OF_ORDER)))
                            essence->AI()->DoAction(ACTION_START_INTRO);
                        break;
                    case STEP_DEFEAT_ESSENCE_OF_ORDER:
                        chapterFive = data;

                        for (auto&& itr : instance->GetPlayers())
                            if (Player* player = itr.GetSource())
                                sScenarioMgr->SendScenarioState(player, 1112, STEP_ESCAPE_SHRINE_OF_LOST_SOULS, 0);

                        // Set Scene with demons is active
                        for (auto&& itr : unboundDemonsList)
                            if (Creature* unboundDemon = instance->GetCreature(itr))
                                unboundDemon->AI()->DoAction(ACTION_START_INTRO);
                        break;
                    case STEP_ESCAPE_SHRINE_OF_LOST_SOULS:
                        chapterSix = data;

                        for (auto&& itr : instance->GetPlayers())
                            if (Player* player = itr.GetSource())
                                sScenarioMgr->SendScenarioState(player, 1112, STEP_PLUNDER_THE_DEN_OF_MORTAL_DELIGHTS, 0);
                        break;
                    case STEP_PLUNDER_THE_DEN_OF_MORTAL_DELIGHTS:
                        chapterSeven = data;

                        for (auto&& itr : instance->GetPlayers())
                            if (Player* player = itr.GetSource())
                                sScenarioMgr->SendScenarioState(player, 1112, STEP_HEAD_OF_THE_TEMPLE_SUMMIT, 0);
                        break;
                    case STEP_HEAD_OF_THE_TEMPLE_SUMMIT:
                        chapterEight = data;

                        for (auto&& itr : instance->GetPlayers())
                            if (Player* player = itr.GetSource())
                                sScenarioMgr->SendScenarioState(player, 1112, STEP_DEFEAT_KANRETHAD, 0);
                        break;
                    case STEP_DEFEAT_KANRETHAD:
                        chapterEleven = data;
                        DoFinishLFGDungeon(594);
                        break;
                }

                if (data == DONE || data == SPECIAL)
                    SaveToDB();
            }
    
            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case STEP_ENTER_THE_BLACK_TEMPLE:
                        return chapterOne;
                    case STEP_SEARCH_FOR_SIGNS:
                        return chapterTwo;
                    case STEP_FOLLOW_AKAMA:
                        return chapterThree;
                    case STEP_UNCOVER_COUNCILS_PLAN:
                        return chapterFour;
                    case STEP_DEFEAT_ESSENCE_OF_ORDER:
                        return chapterFive;
                    case STEP_ESCAPE_SHRINE_OF_LOST_SOULS:
                        return chapterSix;
                    case STEP_PLUNDER_THE_DEN_OF_MORTAL_DELIGHTS:
                        return chapterSeven;
                    case STEP_HEAD_OF_THE_TEMPLE_SUMMIT:
                        return chapterEight;
                    case STEP_DEFEAT_KANRETHAD:
                        return chapterEleven;
                }

                return 0;
            }
    
            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case NPC_AKAMA:
                        return akamaGUID;
                    case NPC_ESSENCE_OF_ORDER:
                        return essenceOrderGUID;
                    case NPC_KANRETHAD_EBONLOCKE:
                        return kanrethardGUID;
                    case NPC_JUBEKA_SHADOWBREAKER:
                        return jubekaGUID;
                    case PLAYER_DATA:
                        return playerGUID;
                    case NPC_DEMONIC_SOULWELL:
                        return soulwellGUID;
                    case NPC_DEMONIC_GATEWAY:
                        return demongateGUID;
                }

                return 0;
            }
    
            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;
    
                std::ostringstream saveStream;
                saveStream << "P B H " << GetBossSaveData();
    
                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }
    
            void Load(char const* in) override
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }
    
                OUT_LOAD_INST_DATA(in);
    
                char dataHead1, dataHead2, dataHead3;
    
                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2 >> dataHead3;
    
                if (dataHead1 == 'P' && dataHead2 == 'B' && dataHead3 == 'H')
                {
                    uint32 temp = 0;
                    loadStream >> temp; // chapterOne complete
                    chapterOne = temp;
                    SetData(STEP_ENTER_THE_BLACK_TEMPLE, chapterOne);
                    loadStream >> temp; // chapterTwo complete
                    chapterTwo = temp;
                    SetData(STEP_SEARCH_FOR_SIGNS, chapterTwo);
                    loadStream >> temp; // chapterThree complete
                    chapterThree = temp;
                    SetData(STEP_FOLLOW_AKAMA, chapterThree);
                    loadStream >> temp;
                    chapterFour = temp; // chapterFour complete
                    SetData(STEP_UNCOVER_COUNCILS_PLAN, chapterFour);
                    loadStream >> temp;
                    chapterFour = temp; // chapterFive complete
                    SetData(STEP_DEFEAT_ESSENCE_OF_ORDER, chapterFive);
                    loadStream >> temp;
                    chapterSix = temp; // chapterSix complete
                    SetData(STEP_ESCAPE_SHRINE_OF_LOST_SOULS, chapterSix);
                    loadStream >> temp;
                    chapterSeven = temp; // chapterSeven complete
                    SetData(STEP_PLUNDER_THE_DEN_OF_MORTAL_DELIGHTS, chapterSeven);
                    loadStream >> temp;
                    chapterEight = temp; // chapterEight complete
                    SetData(STEP_HEAD_OF_THE_TEMPLE_SUMMIT, chapterEight);
                    loadStream >> temp;
                    chapterEleven = temp; // chapterEleven complete
                    SetData(STEP_DEFEAT_KANRETHAD, chapterEleven);
                }
                else OUT_LOAD_INST_DATA_FAIL;
    
                OUT_LOAD_INST_DATA_COMPLETE;
            }
    
            void Update(uint32 diff) override
            {
                m_mEvents.Update(diff);
            }
        };
    
        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_pursuing_the_black_harvest_InstanceScript(map);
        }
};

void AddSC_instance_pursuing_the_black_harvest()
{
    new instance_pursuing_the_black_harvest();
}