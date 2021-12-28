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

#include "ScriptPCH.h"
#include "ahnkahet.h"

/* Ahn'kahet encounters:
 0 - Elder Nadox
 1 - Prince Taldaram
 2 - Jedoga Shadowseeker
 3 - Herald Volazj
 4 - Amanitar (Heroic only)
*/

#define MAX_ENCOUNTER           5

enum Achievements
{
    ACHIEV_VOLUNTEER_WORK                         = 2056
};

class instance_ahnkahet : public InstanceMapScript
{
    public:
        instance_ahnkahet() : InstanceMapScript("instance_ahnkahet", 619) { }

        struct instance_ahnkahet_InstanceScript : public InstanceScript
        {
            instance_ahnkahet_InstanceScript(Map* map) : InstanceScript(map) { }

            uint64 ElderNadoxGUID;
            uint64 PrinceTaldaramGUID;
            uint64 JedogaShadowseekerGUID;
            uint64 HeraldVolazjGUID;
            uint64 AmanitarGUID;

            uint64 PrinceTaldaramSphereGUIDs[2];
            uint64 PrinceTaldaramPlatformGUID;
            uint64 PrinceTaldaramGateGUID;

            std::set<uint64> InitiandGUIDs;
            std::list<uint64> questCreatures;
            uint64 JedogaSacrifices;
            uint64 JedogaTarget;

            uint32 m_auiEncounter[MAX_ENCOUNTER];
            uint32 spheres[2];

            uint8 InitiandCnt;
            uint8 switchtrigger;

            std::string str_data;

            void Initialize() override
            {
                memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
                InitiandGUIDs.clear();

                ElderNadoxGUID =0;
                PrinceTaldaramGUID =0;
                JedogaShadowseekerGUID =0;
                HeraldVolazjGUID =0;
                AmanitarGUID =0;

                spheres[0] = NOT_STARTED;
                spheres[1] = NOT_STARTED;

                InitiandCnt = 0;
                switchtrigger = 0;
                JedogaSacrifices = 0;
                JedogaTarget = 0;
            }

            bool IsEncounterInProgress() const override
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        return true;

                return false;
            }

            void OnPlayerLeave(Player* player) override
            {
                player->RemoveTimedAchievement(CRITERIA_START_TYPE_EVENT, 20382);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_ELDER_NADOX:
                        ElderNadoxGUID = creature->GetGUID();
                        break;
                    case NPC_PRINCE_TALDARAM:
                        PrinceTaldaramGUID = creature->GetGUID();
                        break;
                    case NPC_JEDOGA_SHADOWSEEKER:
                        JedogaShadowseekerGUID = creature->GetGUID();
                        break;
                    case NPC_HERALD_VOLAZJ:
                        HeraldVolazjGUID = creature->GetGUID();
                        break;
                    case NPC_AMANITAR:
                        AmanitarGUID = creature->GetGUID();
                        break;
                    case NPC_TWILIGHT_INITIATE:
                        InitiandGUIDs.insert(creature->GetGUID());
                        break;
                    case NPC_SEER_IXIT:
                        creature->CastSpell(creature, 88920, true); // prevent crash in crt_addons

                        if (creature->GetPositionZ() < 30.0f)
                        {
                            if (GetData64(DATA_HERALD_VOLAZJ) != DONE)
                                creature->SetVisible(false);

                            questCreatures.push_back(creature->GetGUID());
                        }
                        break;
                    case NPC_AZJOL_ANAK_SORCERER:
                    case NPC_AZJOL_ANAK_WARRIROR:
                        if (GetData64(DATA_HERALD_VOLAZJ) != DONE)
                            creature->SetVisible(false);
                        questCreatures.push_back(creature->GetGUID());
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_PRINCE_TALDARAM_PLATFORM:
                        PrinceTaldaramPlatformGUID = go->GetGUID();
                        if (m_auiEncounter[1] == DONE)
                            HandleGameObject(0, true, go);
                        break;
                    case GO_PRINCE_TALDARAM_SPHERE_1:
                        PrinceTaldaramSphereGUIDs[0] = go->GetGUID();
                        if (spheres[0] == IN_PROGRESS)
                        {
                            go->SetGoState(GO_STATE_ACTIVE);
                            go->SetFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        else
                            go->RemoveFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_PRINCE_TALDARAM_SPHERE_2:
                        PrinceTaldaramSphereGUIDs[1] = go->GetGUID();
                        if (spheres[1] == IN_PROGRESS)
                        {
                            go->SetGoState(GO_STATE_ACTIVE);
                            go->SetFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        else
                            go->RemoveFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case GO_PRINCE_TALDARAM_GATE:
                        PrinceTaldaramGateGUID = go->GetGUID(); // Web gate past Prince Taldaram
                        if (m_auiEncounter[1] == DONE)
                            HandleGameObject(0, true, go);
                        break;
                }
            }

            void SetData64(uint32 type, uint64 guid) override
            {
                switch (type)
                {
                    case DATA_ADD_JEDOGA_OPFER: JedogaSacrifices = guid; break;
                    case DATA_PL_JEDOGA_TARGET: JedogaTarget = guid;     break;
                }
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_ELDER_NADOX:                return ElderNadoxGUID;
                    case DATA_PRINCE_TALDARAM:            return PrinceTaldaramGUID;
                    case DATA_JEDOGA_SHADOWSEEKER:        return JedogaShadowseekerGUID;
                    case DATA_HERALD_VOLAZJ:              return HeraldVolazjGUID;
                    case DATA_AMANITAR:                   return AmanitarGUID;
                    case DATA_SPHERE1:                    return PrinceTaldaramSphereGUIDs[0];
                    case DATA_SPHERE2:                    return PrinceTaldaramSphereGUIDs[1];
                    case DATA_PRINCE_TALDARAM_PLATFORM:   return PrinceTaldaramPlatformGUID;
                    case DATA_ADD_JEDOGA_INITIAND:
                    {
                        std::vector<uint64> vInitiands;
                        vInitiands.clear();
                        for (auto&& guid : InitiandGUIDs)
                        {
                            Creature* cr = instance->GetCreature(guid);
                            if (cr && cr->IsAlive())
                                vInitiands.push_back(guid);
                        }
                        if (vInitiands.empty())
                            return 0;
                        uint8 j = urand(0, vInitiands.size() - 1);
                        return vInitiands[j];
                    }
                    case DATA_ADD_JEDOGA_OPFER: return JedogaSacrifices;
                    case DATA_PL_JEDOGA_TARGET: return JedogaTarget;
                }
                return 0;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_ELDER_NADOX_EVENT:
                        m_auiEncounter[0] = data;
                        break;
                    case DATA_PRINCE_TALDARAM_EVENT:
                        if (data == DONE)
                            HandleGameObject(PrinceTaldaramGateGUID,true);
                        m_auiEncounter[1] = data;
                        break;
                    case DATA_JEDOGA_SHADOWSEEKER_EVENT:
                        m_auiEncounter[2] = data;
                        if (data == DONE)
                        {
                            for (auto&& guid : InitiandGUIDs)
                            {
                                Creature* cr = instance->GetCreature(guid);
                                if (cr && cr->IsAlive())
                                {
                                    cr->SetVisible(false);
                                    cr->setDeathState(JUST_DIED);
                                    cr->RemoveCorpse();
                                }
                            }
                        }
                        break;
                    case DATA_HERALD_VOLAZJ_EVENT:
                        m_auiEncounter[3] = data;
                        if (data == DONE)
                        {
                            for (auto&& questCreatureGUID : questCreatures)
                                if (Creature* creature = instance->GetCreature(questCreatureGUID))
                                    creature->SetVisible(true);
                        }
                        break;
                    case DATA_AMANITAR_EVENT:
                        m_auiEncounter[4] = data;
                        break;
                    case DATA_SPHERE1_EVENT:
                        spheres[0] = data;
                        break;
                    case DATA_SPHERE2_EVENT:
                        spheres[1] = data;
                        break;
                    case DATA_JEDOGA_TRIGGER_SWITCH:
                        switchtrigger = data;
                        break;
                    case DATA_JEDOGA_RESET_INITIANDS:
                        for (auto&& guid : InitiandGUIDs)
                        {
                            Creature* cr = instance->GetCreature(guid);
                            if (cr)
                            {
                                cr->Respawn();
                                if (!cr->IsInEvadeMode()) cr->AI()->EnterEvadeMode();
                            }
                        }
                        break;
                }
                if (data == DONE)
                    SaveToDB();
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_ELDER_NADOX_EVENT:            return m_auiEncounter[0];
                    case DATA_PRINCE_TALDARAM_EVENT:        return m_auiEncounter[1];
                    case DATA_JEDOGA_SHADOWSEEKER_EVENT:    return m_auiEncounter[2];
                    case DATA_HERALD_VOLAZJ:                return m_auiEncounter[3];
                    case DATA_AMANITAR_EVENT:               return m_auiEncounter[4];
                    case DATA_SPHERE1_EVENT:                return spheres[0];
                    case DATA_SPHERE2_EVENT:                return spheres[1];
                    case DATA_ALL_INITIAND_DEAD:
                        for (auto&& guid : InitiandGUIDs)
                        {
                            Creature* cr = instance->GetCreature(guid);
                            if (!cr || (cr && cr->IsAlive())) return 0;
                        }
                        return 1;
                    case DATA_JEDOGA_TRIGGER_SWITCH: return switchtrigger;
                }
                return 0;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "A K " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
                    << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " << m_auiEncounter[4] << " "
                    << spheres[0] << " " << spheres[1];

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
                uint16 data0, data1, data2, data3, data4, data5, data6;

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4 >> data5 >> data6;

                if (dataHead1 == 'A' && dataHead2 == 'K')
                {
                    m_auiEncounter[0] = data0;
                    m_auiEncounter[1] = data1;
                    m_auiEncounter[2] = data2;
                    m_auiEncounter[3] = data3;
                    m_auiEncounter[4] = data4;

                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                        if (m_auiEncounter[i] == IN_PROGRESS)
                            m_auiEncounter[i] = NOT_STARTED;

                    spheres[0] = data5;
                    spheres[1] = data6;

                } else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
           return new instance_ahnkahet_InstanceScript(map);
        }
};

void AddSC_instance_ahnkahet()
{
   new instance_ahnkahet;
}
