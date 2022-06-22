#include "NewScriptPCH.h"
#include "shadowfang_keep.h"

DoorData const doorData[] =
{
    {GO_COURTYARD_DOOR, DATA_ASHBURY,   DOOR_TYPE_PASSAGE,  BOUNDARY_NONE},
    {GO_SORCERER_DOOR,  DATA_VALDEN,    DOOR_TYPE_PASSAGE,  BOUNDARY_NONE},
    {GO_ARUGAL_DOOR,    DATA_VALDEN,    DOOR_TYPE_PASSAGE,  BOUNDARY_NONE},
    {GO_ARUGAL_DOOR,    DATA_GODFREY,   DOOR_TYPE_ROOM,     BOUNDARY_NONE},
};

class instance_shadowfang_keep : public InstanceMapScript
{
    public:
        instance_shadowfang_keep() : InstanceMapScript("instance_shadowfang_keep", 33) { }

        InstanceScript* GetInstanceScript(InstanceMap* pMap) const
        {
            return new instance_shadowfang_keep_InstanceMapScript(pMap);
        }

        struct instance_shadowfang_keep_InstanceMapScript : public InstanceScript
        {
            instance_shadowfang_keep_InstanceMapScript(Map* pMap) : InstanceScript(pMap) 
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                uiAshburyGUID = 0;
                uiSilverlaineGUID = 0;
                uiSpringvaleGUID = 0;
                uiValdenGUID = 0;
                uiGodfreyGUID = 0;
                teamInInstance = 0;
            };

            void BeforePlayerEnter(Player* pPlayer)
            {
                if (!teamInInstance)
                    teamInInstance = pPlayer->GetTeam();
            }

            void OnCreatureCreate(Creature* pCreature)
            {
                if (!teamInInstance)
                {
                    Map::PlayerList const &players = instance->GetPlayers();
                    if (!players.isEmpty())
                        if (Player* player = players.begin()->getSource())
                            teamInInstance = player->GetTeam();
                }

                switch(pCreature->GetEntry())
                {
                    case NPC_BELMONT:
                        if (teamInInstance == ALLIANCE)
                            pCreature->UpdateEntry(NPC_IVAR);
                        break;
                    case NPC_GUARD_HORDE1:
                        if (teamInInstance == ALLIANCE)
                            pCreature->UpdateEntry(NPC_GUARD_ALLY);
                        break;
                    case NPC_GUARD_HORDE2:
                        if (teamInInstance == ALLIANCE)
                            pCreature->UpdateEntry(NPC_GUARD_ALLY);
                        break;
                    case NPC_CROMUSH:
                        if (teamInInstance == ALLIANCE)
                            pCreature->SetPhaseMask(2, true);
                        break;
                    case NPC_ASHBURY:
                        uiAshburyGUID = pCreature->GetGUID();
                        break;
                    case NPC_SILVERLAINE:
                        uiSilverlaineGUID = pCreature->GetGUID();
                        break;
                    case NPC_SPRINGVALE:
                        uiSpringvaleGUID = pCreature->GetGUID();
                        break;
                    case NPC_VALDEN:
                        uiValdenGUID = pCreature->GetGUID();
                        break;
                    case NPC_GODFREY:
                        uiGodfreyGUID = pCreature->GetGUID();
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* pGo)
            {
                switch(pGo->GetEntry())
                {
                    case GO_COURTYARD_DOOR:
                    case GO_SORCERER_DOOR:
                    case GO_ARUGAL_DOOR:
                        AddDoor(pGo, true);
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;
                return true;
            }

            uint32 GetData(uint32 type)
            {
                if (type == DATA_TEAM)
                    return teamInInstance;

                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "S K " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            uint64 GetData64(uint32 type)
            {
                switch (type)
                {
                    case DATA_ASHBURY: return uiAshburyGUID;
                    case DATA_SILVERLAINE: return uiSilverlaineGUID;
                    case DATA_SPRINGVALE: return uiSpringvaleGUID;
                    case DATA_VALDEN: return uiValdenGUID;
                    case DATA_GODFREY: return uiGodfreyGUID;
                }
                return 0;
            }

            void Load(const char* str)
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'S' && dataHead2 == 'K')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }
        
        private:
            uint64 uiAshburyGUID;
            uint64 uiSilverlaineGUID;
            uint64 uiSpringvaleGUID;
            uint64 uiValdenGUID;
            uint64 uiGodfreyGUID;
            uint32 teamInInstance;
        };

};


void AddSC_instance_shadowfang_keep()
{
    new instance_shadowfang_keep();
}