/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "pursuing_the_black_harvest.h"

class instance_pursuing_the_black_harvest : public InstanceMapScript
{
public:
    instance_pursuing_the_black_harvest() : InstanceMapScript("instance_pursuing_the_black_harvest", 1112) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_pursuing_the_black_harvest_InstanceMapScript(map);
    }

    struct instance_pursuing_the_black_harvest_InstanceMapScript : public InstanceScript
    {
        instance_pursuing_the_black_harvest_InstanceMapScript(Map* map) : InstanceScript(map)
        { }

        void Initialize()
        {
            essenceData = 0;
            nodelData = 0;
            kanrethadData = 0;
            sceneEventData = 0;
            plunderData = 0;
            stage2Data = 0;
            allowedStage = STAGE_1;

            akamaGUID = 0;
            essenceGUID = 0;
            soulwellGUID = 0;
            gatewayGUID = 0;
            jubekaGUID = 0;
            doorGUID = 0;
            secondDoorGUID = 0;
            trashP2GUIDs.clear();
            trapGUIDs.clear();
            soulGUIDs.clear();
            treasuresGUIDs.clear();
        }

        void OnPlayerEnter(Player* player)
        {
            std::set<uint32> phaseIds;
            std::set<uint32> terrainswaps;
            std::set<uint32> WorldMapAreaIds;
            WorldMapAreaIds.insert(992);
            WorldMapAreaIds.insert(683);
            phaseIds.insert(1982);
            player->GetSession()->SendSetPhaseShift(phaseIds, terrainswaps, WorldMapAreaIds, 16);

            player->CastSpell(player, SPELL_ENTER_THE_BLACK_TEMPLE, true);
            player->CastSpell(player, SPELL_CSA_AT_DUMMY_TIMED_AURA);

            if (player->GetQuestStatus(32340) == QUEST_STATUS_REWARDED)
            {
                if (GetData(DATA_ALLOWED_STAGE) == STAGE_1)
                {
                    SetData(DATA_ALLOWED_STAGE, STAGE_8);
                    Events.ScheduleEvent(EVENT_3, 3 * IN_MILLISECONDS);
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 34539, 1); //< set stage 2
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 34543, 1); //< set stage 3-1
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 34540, 1); //< set stage 3-2
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 34545, 1); //< set stage 4
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 34552, 1); //< set stage 5
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_LOOT_ITEM, 92556, 1);      //< set stage 6
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 34554, 1); //< set stage 7
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 34558, 1); //< set stage 8-1
                    player->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 34579, 1); //< set stage 8-2
                }
                if (GetData(DATA_ALLOWED_STAGE) > STAGE_8)
                    Events.ScheduleEvent(EVENT_3, 3 * IN_MILLISECONDS);
            }
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_ESSENCE_OF_ORDER:
                    essenceGUID = creature->GetGUID();
                    break;
                case NPC_AKAMA:
                    creature->SetVisible(false);
                    akamaGUID = creature->GetGUID();
                    break;
                case NPC_JUBEKA_SHADOWBREAKER:
                    creature->SetVisible(false);
                    jubekaGUID = creature->GetGUID();
                    break;
                case NPC_DEMONIC_SOULWELL:
                    soulwellGUID = creature->GetGUID();
                    creature->SetVisible(false);
                    break;
                case NPC_DEMONIC_GATEWAY:
                    gatewayGUID = creature->GetGUID();;
                    break;
                case NPC_UNBOUND_NIGHTLORD:
                case NPC_UNBOUND_CENTURION:
                case NPC_UNBOUND_BONEMENDER:
                case NPC_PORTALS_VISUAL:
                case NPC_FREED_IMP:
                case NPC_UNBOUND_SUCCUB:
                    creature->SetVisible(false);
                    creature->SetReactState(REACT_PASSIVE);
                    trashP2GUIDs.push_back(creature->GetGUID());
                    break;
                case NPC_SUFFERING_SOUL_FRAGMENT:
                    soulGUIDs.push_back(creature->GetGUID());
                    break;
                case NPC_ASTHONGUE_PRIMALIST:
                case NPC_ASHTONGUE_SHAMAN:
                    trashGUIDconteiner.push_back(creature->GetGUID());
                    break;
                default:
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_MAIN_TEMPLATE_DOORS:
                    doorGUID = go->GetGUID();
                    break;
                case GO_SECOND_DOOR:
                    secondDoorGUID = go->GetGUID();
                    break;
                case GO_TRAP:
                    trapGUIDs.push_back(go->GetGUID());
                    go->m_invisibility.AddFlag(INVISIBILITY_GENERAL);
                    go->m_invisibility.AddValue(INVISIBILITY_GENERAL, 100);
                    break;
                case GO_TREASURE_CHEST:
                case GO_GOLDEN_HIGH_ELF_STATUETTE:
                case GO_GOLD_PLATTER:
                case GO_SHINY_YARN:
                case GO_GORGEOUS_GEM:
                case GO_GOLD_FRUIT_BOWL:
                case GO_DUSTY_PAINTING:
                case GO_FLUFFY_PILLOW:
                case GO_ANCIENT_ORCISH_SHIELD:
                case GO_RUSTED_SWORD:
                case GO_FRAGRANT_PERFUME:
                case GO_COLOGNE:
                case GO_EXPENSIVE_RUBY:
                case GO_SPARKLING_SAPPHIRE:
                case GO_JADE_KITTEN:
                case GO_RUBY_NECKLACE:
                case GO_SPELLSTONE_NECKLACE:
                case GO_DIAMOND_RING:
                case GO_RUBY_RING:
                case GO_GOLD_RING:
                case GO_SMALL_PILE_OF_COINS:
                case GO_LARGE_PILE_OF_COINS:
                case GO_GOLDEN_GOBLET:
                    go->SetVisible(false);
                    treasuresGUIDs.push_back(go->GetGUID());
                    break;
                default:
                    break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case DATA_ALLOWED_STAGE:
                    allowedStage = data;
                    if (data == STAGE_LAST)
                        if (Creature* soulwell = instance->GetCreature(soulwellGUID))
                            soulwell->SetVisible(true);
                    break;
                case DATA_ESSENCE_OF_ORDER_EVENT:
                    essenceData = data;
                    if (data == DONE)
                    {
                        for (std::vector<uint64>::const_iterator itr = trashP2GUIDs.begin(); itr != trashP2GUIDs.end(); itr++)
                            if (Creature* trash = instance->GetCreature(*itr))
                            {
                                trash->SetVisible(true);
                                trash->SetReactState(REACT_AGGRESSIVE);
                            }

                        for (std::vector<uint64>::const_iterator itr = soulGUIDs.begin(); itr != soulGUIDs.end(); itr++)
                            if (Creature* soul = instance->GetCreature(*itr))
                                soul->RemoveFromWorld();

                        for (std::vector<uint64>::const_iterator itr = trapGUIDs.begin(); itr != trapGUIDs.end(); itr++)
                            if (GameObject* trap = instance->GetGameObject(*itr))
                                trap->RemoveFromWorld();
                    }
                    break;
                case DATA_AKAMA:
                    nodelData = data;
                    break;
                case DATA_KANRETHAD:
                    kanrethadData = data;
                    if (data == NOT_STARTED)
                        if (Creature* soulwell = instance->GetCreature(soulwellGUID))
                            soulwell->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        if (Creature* gateway = instance->GetCreature(gatewayGUID))
                            gateway->DespawnOrUnsummon();
                    if (data == DONE)
                        if (Creature* jubeka = instance->SummonCreature(NPC_JUBEKA_SHADOWBREAKER, JubekaPos))
                            jubeka->AI()->DoAction(ACTION_1);
                    break;
                case DATA_SCENE_EVENT:
                    sceneEventData = data;
                    if (data == DONE)
                        Events.ScheduleEvent(EVENT_1, 2 * MINUTE * IN_MILLISECONDS + 40 * IN_MILLISECONDS);
                    break;
                case DATA_NOBEL_EVENT:
                    nodelData = data;
                    break;
                case DATA_PLUNDER_EVENT:
                    plunderData = data;
                    if (data == DONE)
                    {
                        for (std::list<uint64>::iterator itr = treasuresGUIDs.begin(); itr != treasuresGUIDs.end(); ++itr)
                            if (GameObject* trap = instance->GetGameObject(*itr))
                                trap->SetVisible(true);
                    }
                    break;
                case DATA_STAGE_2:
                    stage2Data = data;
                    break;
                case DATA_EVADE:
                    if (data == IN_PROGRESS)
                    {
                        for (std::list<ObjectGuid>::iterator itr = trashGUIDconteiner.begin(); itr != trashGUIDconteiner.end(); ++itr)
                            if (Creature* trash = instance->GetCreature(*itr))
                            {
                                if (!trash->isInCombat())
                                    continue;

                                trash->DespawnOrUnsummon();
                                trash->SetRespawnTime(1);
                            }
                    }
                    break;
                default:
                    break;
            }
        }

        uint64 GetData64(uint32 type)
        {
            switch (type)
            {
                case DATA_AKAMA:
                    return akamaGUID;
                case DATA_MAIN_DOORS:
                    return doorGUID;
                case DATA_SECOND_DOOR:
                    return secondDoorGUID;
                case NPC_ESSENCE_OF_ORDER:
                    return essenceGUID;
                case NPC_DEMONIC_SOULWELL:
                    return soulwellGUID;
                case NPC_DEMONIC_GATEWAY:
                    return gatewayGUID;
                default:
                    return 0;
            }
        }

        uint32 GetData(uint32 type)
        {
            switch (type)
            {
                case DATA_ALLOWED_STAGE:
                    return allowedStage;
                case DATA_ESSENCE_OF_ORDER_EVENT:
                    return essenceData;
                case DATA_NOBEL_EVENT:
                    return nodelData;
                case DATA_SCENE_EVENT:
                    return sceneEventData;
                case DATA_PLUNDER_EVENT:
                    return plunderData;
                case DATA_STAGE_2:
                    return stage2Data;
                default:
                    return 0;
            }
        }

        void Update(uint32 diff)
            {
                Events.Update(diff);

                while (uint32 eventId = Events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_1:
                            if (Creature* essence = instance->GetCreature(GetData64(NPC_ESSENCE_OF_ORDER)))
                            {
                                essence->AI()->DoAction(ACTION_1);
                                essence->AI()->Talk(0);
                            }
                            Events.ScheduleEvent(EVENT_2, 5 * IN_MILLISECONDS);
                            break;
                        case EVENT_2:
                            if (Creature* essence = instance->GetCreature(GetData64(NPC_ESSENCE_OF_ORDER)))
                            {
                                essence->AI()->Talk(1);
                                essence->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                            }
                            break;
                        case EVENT_3:
                            Map::PlayerList const &players = instance->GetPlayers();
                            if (!players.isEmpty())
                                if (Player* player = players.begin()->getSource())
                                    player->TeleportTo(1112, 786.0955f, 304.3524f, 319.7598f, 0.0f);
                            break;
                    }
                }
            }

    private:
        uint32 essenceData;
        uint32 nodelData;
        uint32 kanrethadData;
        uint32 sceneEventData;
        uint32 plunderData;
        uint32 stage2Data;
        uint32 allowedStage;

        uint64 akamaGUID;
        uint64 essenceGUID;
        uint64 jubekaGUID;
        uint64 soulwellGUID;
        uint64 gatewayGUID;
        uint64 doorGUID;
        uint64 secondDoorGUID;
        std::vector<uint64> trashP2GUIDs;
        std::vector<uint64> trapGUIDs;
        std::vector<uint64> soulGUIDs;
        std::list<uint64> treasuresGUIDs;
        std::list<ObjectGuid> trashGUIDconteiner;

        EventMap Events;
    };
};

bool IsNextStageAllowed(InstanceScript* instance, uint8 stage)
{
    switch (stage)
    {
        case STAGE_2:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_1)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_2);
                instance->HandleGameObject(instance->GetData64(DATA_MAIN_DOORS), true);
                return true;
            }
            return false;
        case STAGE_3:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_2)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_3);
                return true;
            }
            return false;
        case STAGE_4:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_3)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_4);
                return true;
            }
            return false;
        case STAGE_5:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_4)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_5);
                return true;
            }
            return false;
        case STAGE_6:
            if (instance->GetData(DATA_ESSENCE_OF_ORDER_EVENT) == DONE)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_6);
                return true;
            }
            return false;
        case STAGE_7:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_6)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_7);
                return true;
            }
            return false;
        case STAGE_8:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_7)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_8);
                return true;
            }
            return false;
        case STAGE_LAST:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_8)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_LAST);
                return true;
            }
            return false;
        default:
            return false;
    }
    return false;
}

void AddSC_instance_pursuing_the_black_harvest()
{
    new instance_pursuing_the_black_harvest();
}
