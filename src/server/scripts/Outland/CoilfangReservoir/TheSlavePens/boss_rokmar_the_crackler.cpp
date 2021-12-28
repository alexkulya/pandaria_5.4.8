#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "the_slave_pens.h"

enum Spells
{
    SPELL_GRIEVOUS_WOUND = 38772,
    SPELL_ENSNARING_MOSS = 31948,
    SPELL_WATER_SPIT = 35008,
    SPELL_FRENZY = 34970,
};

enum Events
{
    EVENT_WOUND      = 1,
    EVENT_MOSS       = 2,
    EVENT_WATER_SPIT = 3,
};

enum Talks
{
    TALK_FRENZY = 0,
};

class boss_rokmar_the_crackler : public CreatureScript
{
    public:
        boss_rokmar_the_crackler() : CreatureScript("boss_rokmar_the_crackler") { }

        struct boss_rokmar_the_cracklerAI : public BossAI
        {
            boss_rokmar_the_cracklerAI(Creature* creature) : BossAI(creature, DATA_ROKMAR) { }

            bool Frenzy;

            void Reset() override
            {
                _Reset();
                events.Reset();
                Frenzy = false;

                if (instance)
                    instance->SetData(DATA_ROKMAR, NOT_STARTED);
            }

            void EnterCombat(Unit* who) override
            {
                _EnterCombat();

                events.ScheduleEvent(EVENT_WOUND, urand(8 * IN_MILLISECONDS, 20 * IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_MOSS, urand(15 * IN_MILLISECONDS, 27.5 * IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_WATER_SPIT, urand(10.5 * IN_MILLISECONDS, 19 * IN_MILLISECONDS));
            }

            void EnterEvadeMode() override
            {
                _EnterEvadeMode();

                if (instance)
                    instance->SetData(DATA_MENNU_THE_BETRAYER, FAIL);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (HealthBelowPct(20) && !Frenzy)
                {
                    Frenzy = true;
                    Talk(TALK_FRENZY);
                    DoCast(me, SPELL_FRENZY);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WOUND:
                            if (Unit* vict = me->GetVictim())
                                DoCast(vict, SPELL_GRIEVOUS_WOUND);

                            events.ScheduleEvent(EVENT_WOUND, urand(8 * IN_MILLISECONDS, 21 * IN_MILLISECONDS));
                            break;
                        case EVENT_MOSS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_ENSNARING_MOSS);
                            else if (Unit* target = me->GetVictim())
                                DoCast(target, SPELL_ENSNARING_MOSS);

                            events.ScheduleEvent(EVENT_MOSS, urand(16 * IN_MILLISECONDS, 27.5 * IN_MILLISECONDS));
                            break;
                        case EVENT_WATER_SPIT:
                            DoCastAOE(SPELL_WATER_SPIT);
                            events.ScheduleEvent(EVENT_WATER_SPIT, urand(10.5 * IN_MILLISECONDS, 19 * IN_MILLISECONDS));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_rokmar_the_cracklerAI(creature);
        }
};

void AddSC_boss_rokmar_the_crackler()
{
    new boss_rokmar_the_crackler();
}