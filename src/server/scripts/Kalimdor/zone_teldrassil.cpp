/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
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

/* ScriptData
SDName: Teldrassil
SD%Complete: 100
SDComment: Quest support: 938
SDCategory: Teldrassil
EndScriptData */

/* ContentData
npc_mist
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedFollowerAI.h"
#include "Player.h"

/*####
# npc_mist
####*/

enum Mist
{
    SAY_AT_HOME             = 0,
    EMOTE_AT_HOME           = 1,
    QUEST_MIST              = 938,
    NPC_ARYNIA              = 3519,
    FACTION_DARNASSUS       = 79
};

class npc_mist : public CreatureScript
{
public:
    npc_mist() : CreatureScript("npc_mist") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_MIST)
            if (npc_mistAI* pMistAI = CAST_AI(npc_mist::npc_mistAI, creature->AI()))
                pMistAI->StartFollow(player, FACTION_DARNASSUS, quest);

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_mistAI(creature);
    }

    struct npc_mistAI : public FollowerAI
    {
        npc_mistAI(Creature* creature) : FollowerAI(creature) { }

        void Reset() override { }

        void MoveInLineOfSight(Unit* who) override

        {
            FollowerAI::MoveInLineOfSight(who);

            if (!me->GetVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE) && who->GetEntry() == NPC_ARYNIA)
            {
                if (me->IsWithinDistInMap(who, 10.0f))
                {
                    Talk(SAY_AT_HOME, who);
                    DoComplete();
                }
            }
        }

        void DoComplete()
        {
            Talk(EMOTE_AT_HOME);

            Player* player = GetLeaderForFollower();
            if (player && player->GetQuestStatus(QUEST_MIST) == QUEST_STATUS_INCOMPLETE)
                player->GroupEventHappens(QUEST_MIST, me);

            //The follow is over (and for later development, run off to the woods before really end)
            SetFollowComplete();
        }

        //call not needed here, no known abilities
        /*void UpdateFollowerAI(const uint32 Diff) override
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }*/
    };
};

enum
{
    GO_BARROW_DEN_DOOR      = 195112,
    QUEST_DRUID_OF_THE_CLAW = 2561,
};

class at_barrow_den_door : public AreaTriggerScript
{
    public:
        at_barrow_den_door() : AreaTriggerScript("at_barrow_den_door") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const*) override
        {
            if (player->GetQuestStatus(QUEST_DRUID_OF_THE_CLAW) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_DRUID_OF_THE_CLAW) == QUEST_STATUS_COMPLETE)
                if (GameObject* go = GetClosestGameObjectWithEntry(player, GO_BARROW_DEN_DOOR, 20.0f))
                    if (go->getLootState() == GO_READY)
                        go->UseDoorOrButton();
            return false;
        }
};

enum eData
{
    QUEST_CROWN_OF_AZEROTH                  = 28729,
    QUEST_PASSING_AWARENESS                 = 28731,
    QUEST_REFUSAL_OF_ASPECTS                = 929,
    QUEST_BURDEN_OF_KALDOREI                = 7383,
    QUEST_COMING_DAWN                       = 933,

    NPC_SHADE_OF_KALDOREI_SHADOWGLEN        = 34574,
    NPC_SHADE_OF_KALDOREI_DOLANAAR          = 34586,
    NPC_SHADE_OF_KALDOREI_STARBREEZE        = 34583,
    NPC_SHADE_OF_KALDOREI_ORACLEGLADE       = 34584,
    NPC_SHADE_OF_KALDOREI_ARLITHRIEN        = 34585,

    AREA_ID_SHADOWGLEN                      = 188,
    AREA_ID_DOLANAAR                        = 186,
    AREA_ID_STARBREEZE                      = 260,
    AREA_ID_ORACLE_GLADE                    = 264,
    AREA_ID_ARLITHRIEN                      = 478,

    EVENT_CHECK_PLAYER                      = 0,
    EVENT_SUMMON_SHADE_OF_KALDOREI          = 1,
    EVENT_CHECK_WHERE_PLAYER                = 2,

    ACTION_CHECK_FOR_SHADE                  = 0
};

Position const l_ShadeShadowGlen = { 10702.7f, 761.221f, 1322.88f, 3.0f };
Position const l_ShadeDolanaar = { 9735.41f, 963.216f, 1295.47f, 6.0f };
Position const l_ShadeStarbreeze = { 9866.76f, 591.828f, 1302.09f, 3.7194f };
Position const l_ShadeOracleGlade = { 10669.2f, 1855.89f, 1325.84f, 2.8f };
Position const l_ShadeArlithrien = { 9556.4941f, 1648.8970f, 1300.9762f, 1.735402f };

// 66163
/// Moonwell Bunny - 34575
struct npc_moonwell_bunny : public ScriptedAI
{
    npc_moonwell_bunny(Creature* p_Creature) : ScriptedAI(p_Creature)
    {
        m_SummonedShade = false;
        m_PlayerGuid = false;
    }

    EventMap m_CosmeticEvents;
    EventMap m_Events;
    bool m_SummonedShade;
    bool m_PlayerGuid;

    // Lists
    std::list<Player*> PlayersInRange;
    std::list<uint32> Quests;
    std::list<uint32> ShadesOfKaldorei;
    std::list<Player*> PlayersInAreaWithQuest;

    void Reset() override
    {
        // Push Quest IDs into list
        Quests.push_back(QUEST_CROWN_OF_AZEROTH);
        Quests.push_back(QUEST_PASSING_AWARENESS);
        Quests.push_back(QUEST_REFUSAL_OF_ASPECTS);
        Quests.push_back(QUEST_BURDEN_OF_KALDOREI);
        Quests.push_back(QUEST_COMING_DAWN);

        // Push Npc IDs into list
        ShadesOfKaldorei.push_back(NPC_SHADE_OF_KALDOREI_SHADOWGLEN);
        ShadesOfKaldorei.push_back(NPC_SHADE_OF_KALDOREI_DOLANAAR);
        ShadesOfKaldorei.push_back(NPC_SHADE_OF_KALDOREI_STARBREEZE);
        ShadesOfKaldorei.push_back(NPC_SHADE_OF_KALDOREI_ORACLE_GLADE);
        ShadesOfKaldorei.push_back(NPC_SHADE_OF_KALDOREI_ARLITHRIEN);

        // Reset Events
        m_Events.Reset();
        ClearDelayedOperations();

        // Check for Players
        m_CosmeticEvents.ScheduleEvent(EVENT_CHECK_PLAYER, 0.5 * TimeConstants::IN_MILLISECONDS);
    }

    void DoAction(int32 const p_Action) override
    {
        switch (p_Action)
        {
            case CHECK_FOR_SHADE:
            {
                if (m_SummonedShade)
                    return;

                for (uint32 Shade : ShadesOfKaldorei)
                    if (me->FindNearestCreature(Shade, 10.0f, true))
                        break; // If Shade is found, break loop - event ongoing

                m_CosmeticEvents.ScheduleEvent(EVENT_SUMMON_SHADE_OF_KALDOREI, 0.2 * TimeConstants::IN_MILLISECONDS); // Summon shade
                m_SummonedShade = true; // Event Check for Shade returns if the variable is true
                break;
            }
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateOperations(diff);

        m_Events.Update(diff);

        m_CosmeticEvents.Update(diff);

        switch (m_Events.ExecuteEvent()) { }

        switch (m_CosmeticEvents.ExecuteEvent())
        {
            case EVENT_CHECK_PLAYER:
                me->GetPlayerListInGrid(PlayersInRange, 10.0f);
                for (Player* p_Player : PlayersInRange)
                    for (uint32 Quest : Quests)
                        if (p_Player->GetQuestStatus(Quest) == QUEST_STATUS_INCOMPLETE)
                        {
                            m_PlayerGuid = p_Player->GetGUID();
                            DoAction(CHECK_FOR_SHADE);
                        }
                break;
            case EVENT_CHECK_WHERE_PLAYER:
                // This event checks if the same player that the event was played for is still in the area. If it doesn't find said player, reset m_SummonedShade in order to play event for new players.
                me->GetPlayerListInGrid(PlayersInAreaWithQuest, 20.0f);
                for (Player* p_Player : PlayersInAreaWithQuest)
                    if (!m_PlayerGuid == p_Player->GetGUID())
                            m_SummonedShade = false;

                break;
            case EVENT_SUMMON_SHADE_OF_KALDOREI:
            {
                // Creature texts and events are handled in SmartAI
                if (me->GetAreaId() == AREAID_SHADOWGLEN)
                {
                    Creature* Shade = me->SummonCreature(NPC_SHADE_OF_KALDOREI_SHADOWGLEN, l_ShadeShadowGlen, TEMPSUMMON_MANUAL_DESPAWN);
                    // NPC despawns after 30 seconds from spawning
                    AddTimedDelayedOperation(31 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        m_CosmeticEvents.ScheduleEvent(EVENT_CHECK_WHERE_PLAYER, 0 * TimeConstants::IN_MILLISECONDS); // Check for same player
                    });
                }
                else if (me->GetAreaId() == AREAID_DOLANAAR)
                {
                    Creature* Shade = me->SummonCreature(NPC_SHADE_OF_KALDOREI_DOLANAAR, l_ShadeDolanaar, TEMPSUMMON_MANUAL_DESPAWN);
                    // NPC despawns after 32 seconds from spawning
                    AddTimedDelayedOperation(33 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        m_CosmeticEvents.ScheduleEvent(EVENT_CHECK_WHERE_PLAYER, 0 * TimeConstants::IN_MILLISECONDS); // Check for same player
                    });
                }
                else if (me->GetAreaId() == AREAID_STARBREEZE)
                {
                    Creature* Shade = me->SummonCreature(NPC_SHADE_OF_KALDOREI_STARBREEZE, l_ShadeStarbreeze, TEMPSUMMON_MANUAL_DESPAWN);
                    // NPC despawns after 40 seconds from spawning
                    AddTimedDelayedOperation(41 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        m_CosmeticEvents.ScheduleEvent(EVENT_CHECK_WHERE_PLAYER, 0 * TimeConstants::IN_MILLISECONDS); // Check for same player
                    });
                }    
                else if (me->GetAreaId() == AREAID_ORACLEGLADE)
                {
                    Creature* Shade = me->SummonCreature(NPC_SHADE_OF_KALDOREI_ORACLEGLADE, l_ShadeOracleGlade, TEMPSUMMON_MANUAL_DESPAWN);
                    // NPC despawns after 40 seconds from spawning
                    AddTimedDelayedOperation(41 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        m_CosmeticEvents.ScheduleEvent(EVENT_CHECK_WHERE_PLAYER, 0 * TimeConstants::IN_MILLISECONDS); // Check for same player
                    });
                }
                else if (me->GetAreaId() == AREAID_ARLITHRIEN)
                {
                    Creature* Shade = me->SummonCreature(NPC_SHADE_OF_KALDOREI_ARLITHRIEN, l_ShadeArlithrien, TEMPSUMMON_MANUAL_DESPAWN);
                    // NPC despawns after 50 seconds from spawning
                    AddTimedDelayedOperation(51 * TimeConstants::IN_MILLISECONDS, [this]() -> void
                    {
                        m_CosmeticEvents.ScheduleEvent(EVENT_CHECK_WHERE_PLAYER, 0 * TimeConstants::IN_MILLISECONDS); // Check for same player
                    });
                }    
                break;
            }
        }
    }
};

void AddSC_teldrassil()
{
    new npc_mist();
    new at_barrow_den_door();
    creature_script<npc_moonwell_bunny>("npc_moonwell_bunny");
}
