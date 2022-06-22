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
    SPELL_HURL_BRICK          = 121762,
    SPELL_COUSTIC_PITCH       = 121442,
    
    //Hackfix achiev Run with the Wind
    SPELL_TENWU_RESOLVE       = 125146,
};

class boss_wing_leader_neronok : public CreatureScript
{
    public:
        boss_wing_leader_neronok() : CreatureScript("boss_wing_leader_neronok") {}

        struct boss_wing_leader_neronokAI : public BossAI
        {
            boss_wing_leader_neronokAI(Creature* creature) : BossAI(creature, NPC_PAVALAK)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            uint32 hurltimer;
            uint32 coustictimer;

            void Reset()
            {
                _Reset();
                hurltimer = 0;
                coustictimer = 0;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                hurltimer = 3000;
                coustictimer = 6000;
                instance->DoCastSpellOnPlayers(SPELL_TENWU_RESOLVE);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (hurltimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, true))
                        DoCast(target, SPELL_HURL_BRICK);
                    hurltimer = 6000;
                }
                else
                    hurltimer -= diff;

                if (coustictimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 20.0f, true))
                        DoCast(target, SPELL_COUSTIC_PITCH);
                    coustictimer = 10000;
                }
                else
                    coustictimer -= diff;
                
                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_wing_leader_neronokAI(creature);
        }
};

void AddSC_boss_wing_leader_neronok()
{
    new boss_wing_leader_neronok();
}
