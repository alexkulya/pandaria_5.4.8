#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Gilneas
{
    SPELL_PING_GILNEAN_CROW                 = 93275,

    EVENT_START_TALK_WITH_CITIZEN           = 1,
    EVENT_TALK_WITH_CITIZEN_1               = 2,
    EVENT_TALK_WITH_CITIZEN_2               = 3,
    EVENT_TALK_WITH_CITIZEN_3               = 4,

    EVENT_START_DIALOG                      = 1,
    EVENT_START_TALK_TO_GUARD               = 2,
    EVENT_TALK_TO_GUARD_1                   = 3,
    EVENT_TALK_TO_GUARD_2                   = 4,
    EVENT_RESET_DIALOG                      = 5,

    PRINCE_LIAM_GREYMANE_TEXT_00            = 0,
    PRINCE_LIAM_GREYMANE_TEXT_01            = 1,
    PRINCE_LIAM_GREYMANE_TEXT_02            = 2,

    NPC_PANICKED_CITIZEN_GATE               = 44086
};

struct npc_gilneas_crow : public ScriptedAI
{
    npc_gilneas_crow(Creature* creature) : ScriptedAI(creature) { }

    uint32 spawn;
    bool flying;

    void Reset() override
    {
        flying = false;
        spawn = 0;
        me->SetPosition(me->GetCreatureData()->posX, me->GetCreatureData()->posY, me->GetCreatureData()->posZ, me->GetCreatureData()->orientation);
    }

    void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
    {
        if (spell->Id == SPELL_PING_GILNEAN_CROW)
        {
            if (!flying)
            {
                me->SetStandState(UNIT_STAND_STATE_STAND);
                me->SetDisableGravity(true);
                flying = true;
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!flying)
            return;

        if (spawn <= diff)
        {
            me->GetMotionMaster()->MovePoint(0, (me->GetPositionX() + irand(-15, 15)), (me->GetPositionY() + irand(-15, 15)), (me->GetPositionZ() + irand(5, 15)));
            spawn = urand (500, 1000);
        }
        else spawn -= diff;

        if ((me->GetPositionZ() - me->GetCreatureData()->posZ) >= 20.0f)
        {
            me->DisappearAndDie();
            me->RemoveCorpse(true);
            flying = false;
        }
    }
};

struct npc_gilneas_city_guard_gate : public ScriptedAI
{
    npc_gilneas_city_guard_gate(Creature* creature) : ScriptedAI(creature) { }

    EventMap m_events;
    uint8 m_say;
    uint8 m_emote;
    ObjectGuid m_citizenGUID;

    void Reset() override
    {
        if (me->GetDistance2d(-1430.47f, 1345.55f) < 10.0f)
            m_events.ScheduleEvent(EVENT_START_TALK_WITH_CITIZEN, 10 * IN_MILLISECONDS, 30 * IN_MILLISECONDS);
    }

    void UpdateAI(uint32 diff) override
    {
        m_events.Update(diff);

        while (uint32 eventId = m_events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START_TALK_WITH_CITIZEN:
                {
                    m_citizenGUID = GetRandomCitizen();
                    m_emote = RAND(EMOTE_ONESHOT_COWER, EMOTE_STATE_TALK, EMOTE_ONESHOT_CRY, EMOTE_ONESHOT_BEG, EMOTE_ONESHOT_EXCLAMATION, EMOTE_ONESHOT_POINT);
                    m_say = 0;

                    if (Creature* npc = ObjectAccessor::GetCreature(*me, m_citizenGUID))
                        npc->HandleEmoteCommand(m_emote);

                    m_events.ScheduleEvent(EVENT_TALK_WITH_CITIZEN_1, 2 * IN_MILLISECONDS + 200, 3 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_TALK_WITH_CITIZEN_1:
                {
                    if (Creature* npc = ObjectAccessor::GetCreature(*me, m_citizenGUID))
                        npc->AI()->Talk(m_say);

                    m_events.ScheduleEvent(EVENT_TALK_WITH_CITIZEN_2, 5 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_TALK_WITH_CITIZEN_2:
                {
                    Talk(m_say);
                    m_events.ScheduleEvent(EVENT_TALK_WITH_CITIZEN_3, 5 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_TALK_WITH_CITIZEN_3:
                {
                    if (Creature* npc = ObjectAccessor::GetCreature(*me, m_citizenGUID))
                        npc->HandleEmoteCommand(EMOTE_STATE_NONE);

                    m_events.ScheduleEvent(EVENT_START_TALK_WITH_CITIZEN, 5 * IN_MILLISECONDS, 30 * IN_MILLISECONDS);
                    break;
                }
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void FillCitizenList()
    {
        listOfCitizenGUID.clear();
        std::list<Creature*> listOfCitizen;
        me->GetCreatureListWithEntryInGrid(listOfCitizen, NPC_PANICKED_CITIZEN_GATE, 35.0f);

        for (std::list<Creature*>::iterator itr = listOfCitizen.begin(); itr != listOfCitizen.end(); ++itr)
            listOfCitizenGUID.push_back((*itr)->GetGUID());
    }

    ObjectGuid GetRandomCitizen()
    {
        if (listOfCitizenGUID.empty())
            FillCitizenList();

        uint8 rol = urand(0, listOfCitizenGUID.size() - 1);
        std::list<ObjectGuid>::iterator itr = listOfCitizenGUID.begin();
        std::advance(itr, rol);
        return (*itr);
    }

private:
    std::list<ObjectGuid> listOfCitizenGUID;
};

struct npc_prince_liam_greymane : public ScriptedAI
{
    npc_prince_liam_greymane(Creature *c) : ScriptedAI(c) { }

    EventMap _events;

    void Reset() override
    {
        _events.RescheduleEvent(EVENT_START_DIALOG, 1 * IN_MILLISECONDS);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_START_DIALOG:
                {
                    _events.ScheduleEvent(EVENT_RESET_DIALOG, 2 * MINUTE * IN_MILLISECONDS);
                    _events.ScheduleEvent(EVENT_START_TALK_TO_GUARD, 1 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_START_TALK_TO_GUARD:
                {
                    Talk(PRINCE_LIAM_GREYMANE_TEXT_00);
                    _events.ScheduleEvent(EVENT_TALK_TO_GUARD_1, 15 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_TALK_TO_GUARD_1:
                {
                    Talk(PRINCE_LIAM_GREYMANE_TEXT_01);
                    _events.ScheduleEvent(EVENT_TALK_TO_GUARD_2, 18 * IN_MILLISECONDS);
                    break;
                }
                case EVENT_TALK_TO_GUARD_2:
                {
                    Talk(PRINCE_LIAM_GREYMANE_TEXT_02);
                    break;
                }
                case EVENT_RESET_DIALOG:
                {
                    Reset();
                    break;
                }
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

void AddSC_gilneas()
{
    new creature_script<npc_gilneas_crow>("npc_gilneas_crow");
    new creature_script<npc_gilneas_city_guard_gate>("npc_gilneas_city_guard_gate");
    new creature_script<npc_prince_liam_greymane>("npc_prince_liam_greymane");
}
