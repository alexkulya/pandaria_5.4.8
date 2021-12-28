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
SDName: boss_cannon_master_willey
SD%Complete: 100
SDComment:
SDCategory: Stratholme
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_KNOCKAWAY                 = 10101,
    SPELL_PUMMEL                    = 15615,
    SPELL_SHOOT                     = 16496,
    SPELL_SUMMONCRIMSONRIFLEMAN     = 17279,
};

class boss_cannon_master_willey : public CreatureScript
{
    public:
        boss_cannon_master_willey() : CreatureScript("boss_cannon_master_willey") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_cannon_master_willeyAI(creature);
        }

        struct boss_cannon_master_willeyAI : public ScriptedAI
        {
            boss_cannon_master_willeyAI(Creature* creature) : ScriptedAI(creature) { }

            uint32 KnockAway_Timer;
            uint32 Pummel_Timer;
            uint32 Shoot_Timer;
            uint32 SummonRifleman_Timer;

            void Reset() override
            {
                Shoot_Timer = 1000;
                Pummel_Timer = 7000;
                KnockAway_Timer = 11000;
                SummonRifleman_Timer = 15000;
            }

            void UpdateAI(uint32 diff) override
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //Pummel
                if (Pummel_Timer <= diff)
                {
                    //Cast
                    if (rand()%100 < 90) //90% chance to cast
                    {
                        DoCastVictim(SPELL_PUMMEL);
                    }
                    //12 seconds until we should cast this again
                    Pummel_Timer = 12000;
                } else Pummel_Timer -= diff;

                //KnockAway
                if (KnockAway_Timer <= diff)
                {
                    //Cast
                    if (rand()%100 < 80) //80% chance to cast
                    {
                        DoCastVictim(SPELL_KNOCKAWAY);
                    }
                    //14 seconds until we should cast this again
                    KnockAway_Timer = 14000;
                } else KnockAway_Timer -= diff;

                //Shoot
                if (Shoot_Timer <= diff)
                {
                    //Cast
                    DoCastVictim(SPELL_SHOOT);
                    //1 seconds until we should cast this again
                    Shoot_Timer = 1000;
                } else Shoot_Timer -= diff;

                //SummonRifleman
                if (SummonRifleman_Timer <= diff)
                {
                    //Cast
                    DoCast(me, SPELL_SUMMONCRIMSONRIFLEMAN);

                    //30 seconds until we should cast this again
                    SummonRifleman_Timer = 30000;
                } else SummonRifleman_Timer -= diff;

                DoMeleeAttackIfReady();
            }
        };
};

void AddSC_boss_cannon_master_willey()
{
    new boss_cannon_master_willey();
}
