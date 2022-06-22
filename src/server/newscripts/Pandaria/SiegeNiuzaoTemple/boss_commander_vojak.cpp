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
#include "siege_of_the_niuzoa_temple.h"

enum eSpells
{
    SPELL_CAUSTIC_TAR    = 120269,
    SPELL_THOUSED_BLADES = 120759,
    SPELL_DASHING_STRIKE = 120789,
};

enum eEvents
{
    EVENT_STRIKE         = 0,
    EVENT_BLADES         = 1,
};

class boss_commander_vojak : public CreatureScript
{
    public:
        boss_commander_vojak() : CreatureScript("boss_commander_vojak") {}

        struct boss_commander_vojakAI : public BossAI
        {
            boss_commander_vojakAI(Creature* creature) : BossAI(creature, NPC_VOJAK)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            uint32 striketimer;
            uint32 bladetimer;

            void Reset()
            {
                _Reset();
                striketimer = 0;
                bladetimer = 0;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                striketimer = 3000;
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (striketimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
                        DoCast(target, SPELL_DASHING_STRIKE);
                    striketimer = urand(8000, 10000);
                    bladetimer = 2000;
                }
                else
                    striketimer -= diff;

                if (bladetimer)
                {
                    if (bladetimer <= diff)
                    {
                        bladetimer = 0;
                        DoCast(me, SPELL_THOUSED_BLADES);
                    }
                    else
                        bladetimer -= diff;
                }

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_commander_vojakAI(creature);
        }
};

void AddSC_boss_commander_vojak()
{
    new boss_commander_vojak();
}
