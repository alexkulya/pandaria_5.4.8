#include "ScriptPCH.h"
#include "the_stonecore.h"

static std::vector<DoorData> const doorData =
{
    { GO_ROCKDOOR_ENTERANCE_SLABHIDE, DATA_SLABHIDE, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
};

class instance_the_stonecore : public InstanceMapScript
{
    public:
        instance_the_stonecore() : InstanceMapScript("instance_the_stonecore", 725) { }

        struct instance_the_stonecore_InstanceMapScript : public InstanceScript
        {
            instance_the_stonecore_InstanceMapScript(Map* map) : InstanceScript(map) { };

            uint32 uiTeamInInstance;
            uint32 archaeologyQuestAura;
            uint64 uiCorborusGUID;
            uint64 uiSlabhideGUID;
            uint64 uiOzrukGUID;
            uint64 uiAzulGUID;
            uint64 ManstormGUID;

            uint64 RockdoorGUID;

            uint32 HasManastormEventDone;
            uint32 m_auiEncounter[MAX_ENCOUNTERS];

            void Initialize() override
            {
                SetBossNumber(MAX_ENCOUNTERS);
                LoadDoorData(doorData);
                memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
                archaeologyQuestAura  = 0;
                uiCorborusGUID        = 0;
                uiSlabhideGUID        = 0;
                uiOzrukGUID           = 0;
                uiAzulGUID            = 0;
                ManstormGUID          = 0;
                RockdoorGUID          = 0;
                HasManastormEventDone = 0;
            }

            void OnPlayerEnter(Player* player) override
            {
                if (archaeologyQuestAura)
                    if (!player->HasAura(archaeologyQuestAura))
                        player->CastSpell(player, archaeologyQuestAura, true);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_CORBORUS:
                        uiCorborusGUID = creature->GetGUID();
                        break;
                    case NPC_SLABHIDE:
                        uiSlabhideGUID = creature->GetGUID();
                        break;
                    case NPC_OZRUK:
                        uiOzrukGUID = creature->GetGUID();
                        break;
                    case NPC_HIGH_PRIESTESS_AZIL:
                        uiAzulGUID = creature->GetGUID();
                        break;
                    case NPC_MILLHOUSE_MANASTORM:
                        ManstormGUID = creature->GetGUID();
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_ROCKDOOR_BREAK:
                        RockdoorGUID = go->GetGUID();
                        break;
                    case GO_ROCKDOOR_ENTERANCE_SLABHIDE:
                        if (go->GetDBTableGUIDLow())
                            AddDoor(go, true);
                        break;
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_CORBORUS - 1:
                        archaeologyQuestAura = data;
                        SaveToDB();
                        break;
                    case DATA_CORBORUS:
                        if (HasManastormEventDone)
                            break;

                        HasManastormEventDone = 1;

                        if (Creature* Corborus = instance->GetCreature(GetData64(DATA_CORBORUS)))
                        {
                            Corborus->GetMotionMaster()->MoveCharge(ManaStormPathEvent[3].GetPositionX(), ManaStormPathEvent[3].GetPositionY(), ManaStormPathEvent[3].GetPositionZ(), 38.0f, EVENT_CHARGE);

                            if (GameObject* breakWall = ObjectAccessor::GetGameObject(*Corborus, GetData64(GO_ROCKDOOR_BREAK)))
                                breakWall->UseDoorOrButton();

                            if (Creature* Milhouse = instance->GetCreature(GetData64(NPC_MILLHOUSE_MANASTORM)))
                                Milhouse->GetMotionMaster()->MoveJump(ManastormJumpEvent, 30.0f, 15.0f, EVENT_JUMP);
                        }
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                return true;
            }

            uint64 GetData64(uint32 data) const override
            {
                switch (data)
                {
                    case DATA_CORBORUS:
                        return uiCorborusGUID;
                    case DATA_SLABHIDE:
                        return uiSlabhideGUID;
                    case DATA_OZRUK:
                        return uiOzrukGUID;
                    case DATA_HIGH_PRIESTESS_AZIL:
                        return uiAzulGUID;
                    case GO_ROCKDOOR_BREAK:
                        return RockdoorGUID;
                    case NPC_MILLHOUSE_MANASTORM:
                        return ManstormGUID;
                }
                return 0;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::string str_data;

                std::ostringstream saveStream;
                saveStream << "S T C " << GetBossSaveData() << archaeologyQuestAura << HasManastormEventDone;

                str_data = saveStream.str();

                OUT_SAVE_INST_DATA_COMPLETE;
                return str_data;
            }

            void Load(const char* in) override
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

                if (dataHead1 == 'S' && dataHead2 == 'T' && dataHead3 == 'C')
                {
                    for (uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                    loadStream >> archaeologyQuestAura;
                    loadStream >> HasManastormEventDone;

                    if (HasManastormEventDone)
                        SetData(DATA_CORBORUS, SPECIAL);
                } 
                else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_the_stonecore_InstanceMapScript(map);
        }
};

void AddSC_instance_the_stonecore()
{
    new instance_the_stonecore();
}