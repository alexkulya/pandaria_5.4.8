#include "NewScriptPCH.h"
#include "the_stonecore.h"

enum ScriptTexts
{
    SAY_AGGRO    = 0,
    SAY_KILL    = 1,
    SAY_SKILL    = 2,
    SAY_DEATH    = 3,
};
enum Spells
{
    SPELL_GROUND_SLAM    = 78903,
    SPELL_GROUND_SLAM_H    = 92410,
    SPELL_SHATTER        = 78807,
    SPELL_SHATTER_H        = 92662,
    SPELL_PARALYZE        = 92426,
    SPELL_PARALYZE_DMG    = 94661,
    SPELL_ENRAGE        = 80467,
    SPELL_SHIELD        = 78835,
    SPELL_SHIELD_H        = 92429,
    SPELL_BULWARK        = 78939,
    SPELL_BULWARK_H        = 92659,
};

enum Events
{
    EVENT_GROUND_SLAM    = 1,
    EVENT_SHATTER        = 2,
    EVENT_PARALYZE        = 3,
    EVENT_SHIELD        = 4,
    EVENT_BULWARK        = 5,
    EVENT_SHATTER_1        = 6,
};

class boss_ozruk : public CreatureScript
{
    public:
        boss_ozruk() : CreatureScript("boss_ozruk") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetStonecoreAI<boss_ozrukAI>(pCreature);
        }

        struct boss_ozrukAI : public BossAI
        {
            boss_ozrukAI(Creature* pCreature) : BossAI(pCreature, DATA_OZRUK)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
            }

            EventMap events;
            bool bEnrage;

            void Reset()
            {
                _Reset();
                bEnrage = false;
                events.Reset();
            }

            void EnterCombat(Unit * /*who*/)
            {
                events.ScheduleEvent(EVENT_SHATTER, 21000);
                events.ScheduleEvent(EVENT_GROUND_SLAM, 7000);
                events.ScheduleEvent(EVENT_BULWARK, 80000);
                events.ScheduleEvent(EVENT_SHIELD, 3000);
                Talk(SAY_AGGRO);
                instance->SetBossState(DATA_OZRUK, IN_PROGRESS);
            }

            void JustDied(Unit* killer)
            {
                _JustDied();
                Talk(SAY_DEATH);
            }

            void KilledUnit(Unit* victim)
            {
                Talk(SAY_KILL);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (me->HealthBelowPct(20) && !bEnrage)
                {
                    DoCast(me, SPELL_ENRAGE);
                    bEnrage = true;
                }

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_GROUND_SLAM:
                        DoCast(SPELL_GROUND_SLAM);
                        events.ScheduleEvent(EVENT_GROUND_SLAM, 15000);
                        break;
                    case EVENT_SHATTER:
                        if (IsHeroic())
                        {
                            events.RescheduleEvent(EVENT_GROUND_SLAM, 15000);
                            DoCast(SPELL_PARALYZE);
                            events.ScheduleEvent(EVENT_SHATTER_1, 600);
                        }
                        else
                            DoCast(SPELL_SHATTER);
                        events.ScheduleEvent(EVENT_SHATTER, 20000);
                        break;
                    case EVENT_SHATTER_1:
                        DoCast(SPELL_SHATTER_H);
                        break;
                    case EVENT_SHIELD:
                        DoCast(SPELL_SHIELD);
                        events.ScheduleEvent(EVENT_SHIELD, 15000);
                        break;
                    case EVENT_BULWARK:
                        DoCast(SPELL_BULWARK);
                        events.ScheduleEvent(EVENT_BULWARK, 15000);
                        break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

void AddSC_boss_ozruk()
{
    new boss_ozruk();
}