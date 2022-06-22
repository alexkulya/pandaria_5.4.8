/*
    Dungeon : Template of the Jade Serpent 85-87
    Wise mari first boss
    Jade servers
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stormstout_brewery.h"

enum Spells
{
    SPELL_BLACKOUT_BREW_AURA   = 114930,
    SPELL_BLACKOUT_BREW        = 106851,
    SPELL_BREW_BOLT            = 114548,
};

class boss_yan_zhu : public CreatureScript
{
    public:
        boss_yan_zhu() : CreatureScript("boss_yan_zhu") { }

        struct boss_yan_zhu_AI : public BossAI
        {
            boss_yan_zhu_AI(Creature* creature) : BossAI(creature, DATA_YAN_ZHU)
            {
                InstanceScript* instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            uint32 brewtimer;
            uint32 bolttimer;

            void Reset()
            {
                _Reset();
                bolttimer = 0;
                brewtimer = 0;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                if (!me->HasAura(SPELL_BLACKOUT_BREW_AURA))
                    DoCast(me, SPELL_BLACKOUT_BREW_AURA);
                bolttimer = 8000;
                brewtimer = 12000;
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (bolttimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, true))
                    {
                        DoCast(target, SPELL_BREW_BOLT);
                        bolttimer = 8000;
                    }
                }
                else
                    bolttimer -= diff;

                if (brewtimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, true))
                    {
                        DoCast(target, SPELL_BLACKOUT_BREW);
                        brewtimer = 12000;
                    }
                }
                else
                    brewtimer -= diff;

                
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_yan_zhu_AI(creature);
        }
};

void AddSC_boss_yan_zhu()
{
    new boss_yan_zhu();
}
