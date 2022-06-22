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
#include "scarlet_monastery.h"

enum Says
{
    SAY_AGGRO       = 0,
    SAY_AGGRO_2     = 1,
    SAY_EVADE       = 2, // Evade?
    SAY_DEATH       = 3,
};

enum Spells
{
    SPELL_RISING_FLAME      = 114410,
    SPELL_FLYING_KICK       = 114487,
    SPELL_BLAZING_FISTS     = 114807,
    SPELL_SCORCHED_EARTH    = 114460,
    //Achiev
    SPELL_BURNING_MAN_1     = 125852,
    SPELL_BURNING_MAN_2     = 125844,
};

enum Events
{
    EVENT_FLYING_KICK       = 1,
    EVENT_BLAZING_FISTS     = 2,
};

const Position dummyPos[6] =
{
    {896.24f, 649.75f, 10.20f, 4.67f},
    {896.53f, 562.22f, 10.39f, 1.61f}, 
    {899.97f, 562.03f, 10.47f, 1.68f},
    {903.60f, 562.01f, 10.55f, 1.55f},
    {899.69f, 649.56f, 10.23f, 4.66f},
    {903.32f, 649.54f, 10.26f, 4.65f},
};

class boss_brother_korloff : public CreatureScript
{
public:
    boss_brother_korloff() : CreatureScript("boss_brother_korloff") { }

    struct boss_brother_korloffAI : public BossAI
    {
        boss_brother_korloffAI(Creature* creature) : BossAI(creature, DATA_KORLOFF)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        uint32 DamageCount;
        uint32 HealthPct;
        uint8 dummieFire; // achiev
        bool LowHp;

        void Reset()
        {
            events.Reset();
            LowHp = false;
            DamageCount = 0;
            HealthPct = 0;
            dummieFire = 0;
            me->RemoveAllAuras();
            _Reset();
            for(uint8 i = 0; i < 6; i++)
                me->SummonCreature(NPC_TRAINING_DUMMY, dummyPos[i]);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_FLYING_KICK, 10000);
            events.ScheduleEvent(EVENT_BLAZING_FISTS, 20000);
            _EnterCombat();
        }

        void EnterEvadeMode()
        {
            Talk(SAY_EVADE);
            BossAI::EnterEvadeMode();
        }

        bool AllowAchieve()
        {
            return dummieFire >= 6;
        }

        void DamageTaken(Unit* attacker, uint32 &damage)
        {
            DamageCount += damage;
            HealthPct = me->CountPctFromMaxHealth(10);

            if (DamageCount >= HealthPct)
            {
                DamageCount -= HealthPct;
                DoCast(me, SPELL_RISING_FLAME, true);
            }
            if (damage >= me->GetHealth() && !LowHp)
            {
                LowHp = true;
                DoCast(SPELL_SCORCHED_EARTH);
            }
        }

        void DoAction(const int32 action)
        {
            dummieFire++;
        }

        void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
            _JustDied();
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FLYING_KICK:
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(pTarget, SPELL_FLYING_KICK);
                        events.ScheduleEvent(EVENT_FLYING_KICK, 26000);
                        break;
                    case EVENT_BLAZING_FISTS:
                        if (Unit* pTarget = me->getVictim())
                            DoCast(pTarget, SPELL_BLAZING_FISTS);
                        events.ScheduleEvent(EVENT_BLAZING_FISTS, 30000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_brother_korloffAI (creature);
    }
};

//npc 64446
class npc_korloff_training_dummy : public CreatureScript
{
public:
    npc_korloff_training_dummy() : CreatureScript("npc_korloff_training_dummy") { }

    struct npc_korloff_training_dummyAI : public Scripted_NoMovementAI
    {
        npc_korloff_training_dummyAI(Creature* creature) : Scripted_NoMovementAI(creature)
        {
            instance = me->GetInstanceScript();
            me->SetReactState(REACT_PASSIVE);
            burn = false;
        }

        InstanceScript* instance;

        bool burn;

        void SpellHit(Unit* attacker, const SpellInfo* spell)
        {
            if ((spell->Id == SPELL_BURNING_MAN_1 || spell->Id == SPELL_BURNING_MAN_2) && !burn)
            {
                burn = true;
                if (attacker->ToCreature())
                    if (attacker->ToCreature()->GetEntry() == NPC_BROTHER_KORLOFF)
                        attacker->ToCreature()->AI()->DoAction(true);
            }
        }

        void DamageTaken(Unit* attacker, uint32 &damage)
        {
            damage = 0;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_korloff_training_dummyAI (creature);
    }
};

typedef boss_brother_korloff::boss_brother_korloffAI KorloffAI;

class achievement_burning_man : public AchievementCriteriaScript
{
public:
    achievement_burning_man() : AchievementCriteriaScript("achievement_burning_man") { }

    bool OnCheck(Player* source, Unit* target)
    {
        if (!target)
            return false;

        if (KorloffAI* korloffAI = CAST_AI(KorloffAI, target->GetAI()))
            return korloffAI->AllowAchieve();

        return false;
    }
};

void AddSC_boss_brother_korloff()
{
    new boss_brother_korloff();
    new npc_korloff_training_dummy();
    new achievement_burning_man();
}
