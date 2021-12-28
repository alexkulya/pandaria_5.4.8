#include "ScriptPCH.h"
#include "the_vortex_pinnacle.h"

#define MAX_ENCOUNTER 3

class instance_the_vortex_pinnacle : public InstanceMapScript
{
    public:
        instance_the_vortex_pinnacle() : InstanceMapScript("instance_the_vortex_pinnacle", 657) { }

        struct instance_the_vortex_pinnacle_InstanceMapScript: public InstanceScript
        {
            instance_the_vortex_pinnacle_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

            uint64 uiGrandVizierErtanGUID;
            uint64 uiAltairusGUID;
            uint64 uiAsaadGUID;
            uint32 goldenOrbsCollected;
            uint32 archaeologyQuestAura;

            void Initialize() override
            {
                SetBossNumber(MAX_ENCOUNTER);
                uiGrandVizierErtanGUID = 0;
                uiAltairusGUID = 0;
                uiAsaadGUID = 0;                
                goldenOrbsCollected = 0;
                archaeologyQuestAura = 0;
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
                    case NPC_GRAND_VIZIER_ERTAN:
                        uiGrandVizierErtanGUID = creature->GetGUID();
                        break;
                    case NPC_ALTAIRUS:
                        uiAltairusGUID = creature->GetGUID();
                        break;
                    case NPC_ASAAD:
                        uiAsaadGUID = creature->GetGUID();
                        break;
                }
                
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == uint32(-1))
                {
                    archaeologyQuestAura = data;
                    SaveToDB();
                }
                else if (type == DATA_GOLDEN_ORB)
                    ++goldenOrbsCollected;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (state == DONE)
                {
                    switch (type)
                    {
                        case DATA_ERTAN:
                        case DATA_ALTAIRUS:
                            instance->SummonCreature(NPC_SLIPSTREAM, type == DATA_ERTAN ? PastVortexSpawnPos[0] : PastVortexSpawnPos[1]);
                            break;
                    }
                }
                return true;
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_GOLDEN_ORB)
                    return goldenOrbsCollected;

                return 0;
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_ERTAN:
                        return uiGrandVizierErtanGUID;
                    case DATA_ALTAIRUS:
                        return uiAltairusGUID;
                    case DATA_ASAAD:
                        return uiAsaadGUID;
                }
                return 0;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::string str_data;
                std::ostringstream saveStream;
                saveStream << "V P " << GetBossSaveData() << goldenOrbsCollected << ' ' << archaeologyQuestAura; 
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

                char dataHead1, dataHead2;

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'V' && dataHead2 == 'P')
                {
                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                    loadStream >> goldenOrbsCollected;
                    loadStream >> archaeologyQuestAura;
                }
                else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_the_vortex_pinnacle_InstanceMapScript(map);
        }
};

void AddSC_instance_the_vortex_pinnacle()
{
    new instance_the_vortex_pinnacle();
}
