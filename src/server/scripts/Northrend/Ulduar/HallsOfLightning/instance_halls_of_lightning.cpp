/*
 * Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2006-2014 ScriptDev2 <https://github.com/scriptdev2/scriptdev2/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Instance_Halls_of_Lightning
SD%Complete: 90%
SDComment: All ready.
SDCategory: Halls of Lightning
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "halls_of_lightning.h"

/* Halls of Lightning encounters:
 0 - General Bjarngrim
 1 - Volkhan
 2 - Ionar
 3 - Loken
*/

class instance_halls_of_lightning : public InstanceMapScript
{
    public:
        instance_halls_of_lightning() : InstanceMapScript("instance_halls_of_lightning", 602) { }

        struct instance_halls_of_lightning_InstanceMapScript : public InstanceScript
        {
            instance_halls_of_lightning_InstanceMapScript(Map* map) : InstanceScript(map) { }

            uint32 m_auiEncounter[MAX_ENCOUNTER];

            uint32 hallOfTheWatchersTriggeredMask = 0;

            uint64 m_uiGeneralBjarngrimGUID;
            uint64 m_uiIonarGUID;
            uint64 m_uiLokenGUID;
            uint64 m_uiVolkhanGUID;

            uint64 m_uiBjarngrimDoorGUID;
            uint64 m_uiVolkhanDoorGUID;
            uint64 m_uiIonarDoorGUID;
            uint64 m_uiLokenDoorGUID;
            uint64 m_uiLokenGlobeGUID;
            uint64 m_questGiverGUID;
            uint64 m_questEnderGUID;

            void Initialize()
            {
                memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

                m_uiGeneralBjarngrimGUID = 0;
                m_uiVolkhanGUID          = 0;
                m_uiIonarGUID            = 0;
                m_uiLokenGUID            = 0;

                m_uiBjarngrimDoorGUID    = 0;
                m_uiVolkhanDoorGUID      = 0;
                m_uiIonarDoorGUID        = 0;
                m_uiLokenDoorGUID        = 0;
                m_uiLokenGlobeGUID       = 0;
                m_questGiverGUID         = 0;
                m_questEnderGUID         = 0;
            }

            void OnPlayerLeave(Player* player) override
            {
                player->RemoveTimedAchievement(CRITERIA_START_TYPE_EVENT, 20384);
            }

            uint32 GetCreatureEntry(uint32 guidlow, CreatureData const* data) override
            {
                switch (data->id)
                {
                    case NPC_STORMFORGED_TACTICIAN:
                    case NPC_STORMFORGED_MENDER:
                        return RAND(NPC_STORMFORGED_TACTICIAN, NPC_STORMFORGED_MENDER);
                    default:
                        return data->id;
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_BJARNGRIM:
                        m_uiGeneralBjarngrimGUID = creature->GetGUID();
                        break;
                    case NPC_VOLKHAN:
                        m_uiVolkhanGUID = creature->GetGUID();
                        break;
                    case NPC_IONAR:
                        m_uiIonarGUID = creature->GetGUID();
                        break;
                    case NPC_LOKEN:
                        m_uiLokenGUID = creature->GetGUID();
                        break;
                    case NPC_STORMHERALD_ELJRRIN_QG:
                        if (creature->GetPositionX() < 1320.0f)
                        {
                            m_questEnderGUID = creature->GetGUID();
                            creature->SetVisible(false);
                            creature->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        }
                        else
                            m_questGiverGUID = creature->GetGUID();
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_BJARNGRIM_DOOR:
                        m_uiBjarngrimDoorGUID = go->GetGUID();
                        go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_VOLKHAN_DOOR:
                        m_uiVolkhanDoorGUID = go->GetGUID();
                        if (m_auiEncounter[1] == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        else
                            go->SetGoState(GO_STATE_READY);
                        break;
                    case GO_IONAR_DOOR:
                        m_uiIonarDoorGUID = go->GetGUID();
                        if (m_auiEncounter[2] == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        else
                            go->SetGoState(GO_STATE_READY);
                        break;
                    case GO_LOKEN_DOOR:
                        m_uiLokenDoorGUID = go->GetGUID();
                        if (m_auiEncounter[3] == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        else
                            go->SetGoState(GO_STATE_READY);
                        break;
                    case GO_LOKEN_THRONE:
                        m_uiLokenGlobeGUID = go->GetGUID();
                        break;
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case TYPE_BJARNGRIM:
                         if (data == DONE)
                                if (GameObject* pDoor = instance->GetGameObject(m_uiBjarngrimDoorGUID))
                                pDoor->SetGoState(GO_STATE_ACTIVE);
                        m_auiEncounter[0] = data;
                        break;
                    case TYPE_VOLKHAN:
                        if (data == DONE)
                               if (GameObject* pDoor = instance->GetGameObject(m_uiVolkhanDoorGUID))
                               pDoor->SetGoState(GO_STATE_ACTIVE);
                        m_auiEncounter[1] = data;
                        break;
                    case TYPE_IONAR:
                        if (data == DONE)
                               if (GameObject* pDoor = instance->GetGameObject(m_uiIonarDoorGUID))
                               pDoor->SetGoState(GO_STATE_ACTIVE);
                        m_auiEncounter[2] = data;
                        break;
                    case TYPE_LOKEN:
                        if (data == DONE)
                        {
                            if (GameObject* pDoor = instance->GetGameObject(m_uiLokenDoorGUID))
                                pDoor->SetGoState(GO_STATE_ACTIVE);

                            //Appears to be type 5 GO with animation. Need to figure out how this work, code below only placeholder
                            if (GameObject* pGlobe = instance->GetGameObject(m_uiLokenGlobeGUID))
                                pGlobe->SendCustomAnim(0);

                            if (Creature* qStarter = instance->GetCreature(GetData64(NPC_STORMHERALD_ELJRRIN_QG)))
                            {
                                qStarter->SetVisible(false);
                                qStarter->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                            }

                            if (Creature* qEnder = instance->GetCreature(GetData64(NPC_STORMHERALD_ELJRRIN_QG + 1)))
                            {
                                qEnder->SetVisible(true);

                                Movement::MoveSplineInit init(qEnder);
                                for (auto itr : QuestgiverPath)
                                    init.Path().push_back(G3D::Vector3(itr.GetPositionX(), itr.GetPositionY(), itr.GetPositionZ()));

                                init.SetSmooth();
                                init.SetUncompressed();
                                init.Launch();

                                uint32 delay = 0;
                                qEnder->m_Events.Schedule(delay += qEnder->GetSplineDuration(), 1, [qEnder]()
                                {
                                    qEnder->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                                });
                            }
                        }
                        m_auiEncounter[3] = data;
                        break;
                    case TYPE_HALL_OF_THE_WATCHERS:
                        hallOfTheWatchersTriggeredMask |= data;
                        SaveToDB();
                        return;
                }

                if (data == DONE)
                    SaveToDB();
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case TYPE_BJARNGRIM:
                        return m_auiEncounter[0];
                    case TYPE_VOLKHAN:
                        return m_auiEncounter[1];
                    case TYPE_IONAR:
                        return m_auiEncounter[2];
                    case TYPE_LOKEN:
                        return m_auiEncounter[3];
                    case TYPE_HALL_OF_THE_WATCHERS:
                        return hallOfTheWatchersTriggeredMask;
                }
                return 0;
            }

            uint64 GetData64(uint32 data) const override
            {
                switch (data)
                {
                    case DATA_BJARNGRIM:
                        return m_uiGeneralBjarngrimGUID;
                    case DATA_VOLKHAN:
                        return m_uiVolkhanGUID;
                    case DATA_IONAR:
                        return m_uiIonarGUID;
                    case DATA_LOKEN:
                        return m_uiLokenGUID;
                    case NPC_STORMHERALD_ELJRRIN_QG:
                        return m_questGiverGUID;
                    case NPC_STORMHERALD_ELJRRIN_QG + 1:
                        return m_questEnderGUID;
                }
                return 0;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "H L " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
                << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " << hallOfTheWatchersTriggeredMask;

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
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
                uint16 data0, data1, data2, data3, data4 = 0;

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4;

                if (dataHead1 == 'H' && dataHead2 == 'L')
                {
                    m_auiEncounter[0] = data0;
                    m_auiEncounter[1] = data1;
                    m_auiEncounter[2] = data2;
                    m_auiEncounter[3] = data3;
                    hallOfTheWatchersTriggeredMask = data4;

                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                        if (m_auiEncounter[i] == IN_PROGRESS)
                            m_auiEncounter[i] = NOT_STARTED;
                } else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_halls_of_lightning_InstanceMapScript(map);
        }
};

void AddSC_instance_halls_of_lightning()
{
    new instance_halls_of_lightning();
}
