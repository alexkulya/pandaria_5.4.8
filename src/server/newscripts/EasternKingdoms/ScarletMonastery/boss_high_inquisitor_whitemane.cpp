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
    //Whitemane says
    SAY_WH_AGGRO                 = 0,
    SAY_WH_WARN_RESSURECT        = 1,
    SAY_WH_RESSURECT             = 2,
    SAY_WH_DEATH                 = 3,
    
    //Durand says
    SAY_D_INTRO         = 0,
    SAY_D_AGGRO         = 1,
    SAY_D_DEATH         = 2,
};

enum Spells
{
    //Whitemanes Spells
    SPELL_HOLYSMITE              = 114848,
    SPELL_POWERWORDSHIELD        = 127399,
    SPELL_DEEPSLEEP              = 9256,
    SPELL_SCARLET_RESURRECTION   = 9232,
    SPELL_MASS_RESURRECTION      = 113134,
    SPELL_DOMINATE_MIND          = 130857,

    SPELL_ACHIEV_CREDIT          = 132022,
    
    //Durand
    SPELL_FLASH_OF_STEEL         = 115629,
    SPELL_FEIGN_DEATH            = 29266,
    SPELL_FURIOUS_RESOLVE        = 115876,
    SPELL_SUICIDE_NO_BLOOD       = 42278,
};

enum Events
{
    EVENT_HOLYSMITE             = 1,
    EVENT_POWERWORDSHIELD       = 2,
    EVENT_RESURRECT             = 3,
    EVENT_MASS_RESURRECTION     = 4,
    EVENT_DOMINATE_MIND         = 5, //Challenge mode only
    
    EVENT_FLASH_OF_STEEL        = 6,
};

const Position judPos[13] =
{
    {752.32f, 546.028f, 12.80f, 0.59f},
    {753.15f, 550.778f, 12.80f, 0.89f},
    {755.33f, 544.255f, 12.80f, 1.23f},
    {756.57f, 550.286f, 12.80f, 6.21f},
    {758.66f, 544.073f, 12.80f, 5.86f},
    {758.92f, 548.054f, 12.80f, 4.01f},
    {761.47f, 546.904f, 12.80f, 1.22f},
    {763.87f, 543.892f, 12.80f, 5.07f},
    {765.29f, 546.938f, 12.80f, 3.43f},
    {767.08f, 551.016f, 12.80f, 1.09f},
    {767.94f, 543.682f, 12.80f, 0.01f},
    {768.95f, 547.529f, 12.80f, 3.29f},
    {770.43f, 549.938f, 12.80f, 1.65f},
};
class boss_high_inquisitor_whitemane : public CreatureScript
{
public:
    boss_high_inquisitor_whitemane() : CreatureScript("boss_high_inquisitor_whitemane") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_high_inquisitor_whitemaneAI (creature);
    }

    struct boss_high_inquisitor_whitemaneAI : public BossAI
    {
        boss_high_inquisitor_whitemaneAI(Creature* creature) : BossAI(creature, DATA_WHITEMANE)
        {
            instance = creature->GetInstanceScript();
        }

        InstanceScript* instance;
        
        uint8 JudCount;
        bool Resurrect;
        bool MassRes;
        bool ResurrectCheck;

        void Reset()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            JudCount = 0;
            Resurrect = false;
            MassRes = false;
            ResurrectCheck = false;
            events.Reset();
            _Reset();
            for(uint8 i = 0; i < 13; i++)
                me->SummonCreature(NPC_SCARLET_JUDICATOR, judPos[i]);
            me->SummonCreature(NPC_DURAND, 747.96f, 605.97f, 15.07f, -0.04f);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_WH_AGGRO);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            events.ScheduleEvent(EVENT_HOLYSMITE, 5000);
            events.ScheduleEvent(EVENT_POWERWORDSHIELD, 26000);
            events.ScheduleEvent(EVENT_MASS_RESURRECTION, 12000);
            if (instance->instance->GetDifficulty() == CHALLENGE_MODE_DIFFICULTY)
                events.ScheduleEvent(EVENT_DOMINATE_MIND, 14000);
            _EnterCombat();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if ((damage >= me->GetHealth() && !Resurrect) || ResurrectCheck)
                damage = 0;

            if (me->HealthBelowPct(50) && !Resurrect)
            {
                Resurrect = true;
                ResurrectCheck = true;
                DoStopAttack();
                DoCast(me, SPELL_DEEPSLEEP, true);
                if (Creature* durand = instance->instance->GetCreature(instance->GetData64(DATA_DURAND)))
                {
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(1, durand->GetPositionX(), durand->GetPositionY(), durand->GetPositionZ());
                }
            }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type == POINT_MOTION_TYPE)
                if (id == 1)
                {
                    DoCast(SPELL_SCARLET_RESURRECTION);
                    Talk(SAY_WH_RESSURECT);
                    ResurrectCheck = false;
                    events.ScheduleEvent(EVENT_RESURRECT, 1000);
                }
        }

        void JustDied(Unit* /*killer*/)
        {
            instance->DoUpdateAchievementCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEV_CREDIT, 0, 0, me);
            Talk(SAY_WH_DEATH);
            if (instance->instance->GetDifficulty() != CHALLENGE_MODE_DIFFICULTY)
                if (Creature* durand = instance->instance->GetCreature(instance->GetData64(DATA_DURAND)))
                    durand->AI()->DoCast(SPELL_SUICIDE_NO_BLOOD);
            _JustDied();
        }

        void DoAction(const int32 action)
        {
            if (action == 1)
                me->SetInCombatWithZone();
            
            if (action == 2)
                JudCount++;
        }

        bool AllowAchieve()
        {
            return JudCount >= 13;
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_MASS_RESURRECTION && !MassRes)
                MassRes = true;
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() || ResurrectCheck)
                return;

            if (me->GetDistance(me->GetHomePosition()) > 70.0f)
            {
                EnterEvadeMode();
                return;
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_HOLYSMITE:
                        if (Unit* pTarget = me->getVictim())
                            DoCast(pTarget, SPELL_HOLYSMITE);
                        events.ScheduleEvent(EVENT_HOLYSMITE, 1000);
                        break;
                    case EVENT_POWERWORDSHIELD:
                        DoCast(me, SPELL_POWERWORDSHIELD, true);
                        events.ScheduleEvent(EVENT_POWERWORDSHIELD, 15000);
                        break;
                    case EVENT_RESURRECT:
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    case EVENT_MASS_RESURRECTION:
                        if (!MassRes)
                        {
                            Talk(SAY_WH_WARN_RESSURECT);
                            DoCast(SPELL_MASS_RESURRECTION);
                            events.ScheduleEvent(EVENT_MASS_RESURRECTION, 22000);
                        }
                        break;
                    case EVENT_DOMINATE_MIND:
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(pTarget, SPELL_DOMINATE_MIND);
                        events.ScheduleEvent(EVENT_DOMINATE_MIND, 18000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class npc_commander_durand : public CreatureScript
{
public:
    npc_commander_durand() : CreatureScript("npc_commander_durand") { }

    struct npc_commander_durandAI : public ScriptedAI
    {
        npc_commander_durandAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
            into = true;
        }

        InstanceScript* instance;
        EventMap events;

        bool into;
        bool fakeDeath;
        bool sayDeath;

        void Reset()
        {
            fakeDeath = false;
            sayDeath = false;
            me->RemoveAllAuras();
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
        }

        void EnterCombat(Unit* /*who*/)
        {
            Talk(SAY_D_AGGRO);
            events.ScheduleEvent(EVENT_FLASH_OF_STEEL, 10000);
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;

                if (!fakeDeath)
                {
                    fakeDeath = true;
                    DoStopAttack();
                    DoCast(SPELL_FEIGN_DEATH);
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
                    me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);

                    if (!sayDeath)
                    {
                        sayDeath = true;
                        Talk(SAY_D_DEATH);

                        if (Creature* Wh = instance->instance->GetCreature(instance->GetData64(DATA_WHITEMANE)))
                            Wh->AI()->DoAction(1);
                    }
                }
            }
        }

        void DoAction(const int32 action)
        {
            if (into)
            {
                into = false;
                Talk(SAY_D_INTRO);
            }
        }

        void SpellHit(Unit* attacker, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_SCARLET_RESURRECTION)
            {
                me->RemoveAura(SPELL_FEIGN_DEATH);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                me->SetHealth(me->GetMaxHealth());
                attacker->CastSpell(attacker, SPELL_FURIOUS_RESOLVE, true);
                me->SetReactState(REACT_AGGRESSIVE);
                fakeDeath = false;
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim() || fakeDeath)
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_FLASH_OF_STEEL:
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(pTarget, SPELL_FLASH_OF_STEEL);
                        events.ScheduleEvent(EVENT_FLASH_OF_STEEL, 26000);
                        break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_commander_durandAI (creature);
    }
};

class npc_scarlet_judicator : public CreatureScript
{
public:
    npc_scarlet_judicator() : CreatureScript("npc_scarlet_judicator") { }

    struct npc_scarlet_judicatorAI : public ScriptedAI
    {
        npc_scarlet_judicatorAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = me->GetInstanceScript();
        }

        InstanceScript* instance;

        void Reset() {}

        void IsSummonedBy(Unit* summoner)
        {
            DoCast(SPELL_FEIGN_DEATH);
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
        }

        void SpellHit(Unit* attacker, const SpellInfo* spell)
        {
            if (spell->Id == SPELL_MASS_RESURRECTION)
            {
                me->RemoveAura(SPELL_FEIGN_DEATH);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me, 120.0f);
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            if (me->ToTempSummon() && me->ToTempSummon()->GetSummoner())
                if (Creature* Wh = me->ToTempSummon()->GetSummoner()->ToCreature())
                    Wh->AI()->DoAction(2);
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_scarlet_judicatorAI (creature);
    }
};

class at_enter_durand_room : public AreaTriggerScript
{
public:
    at_enter_durand_room() : AreaTriggerScript("at_enter_durand_room") { }

    bool OnTrigger(Player* pPlayer, const AreaTriggerEntry* /*pAt*/, bool /*enter*/)
    {
        if (pPlayer->isGameMaster())
            return false;
        
        if (InstanceScript* pInstance = pPlayer->GetInstanceScript())
        {
            if (Creature* durand = pInstance->instance->GetCreature(pInstance->GetData64(DATA_DURAND)))
                durand->AI()->DoAction(true);
        }
        return true;
    }
};

typedef boss_high_inquisitor_whitemane::boss_high_inquisitor_whitemaneAI WhitemaneAI;

class achievement_and_stay_dead : public AchievementCriteriaScript
{
public:
    achievement_and_stay_dead() : AchievementCriteriaScript("achievement_and_stay_dead") { }

    bool OnCheck(Player* source, Unit* target)
    {
        if (!target)
            return false;

        if (WhitemaneAI* whitemaneAI = CAST_AI(WhitemaneAI, target->GetAI()))
            return whitemaneAI->AllowAchieve();

        return false;
    }
};

void AddSC_boss_high_inquisitor_whitemane()
{
    new boss_high_inquisitor_whitemane();
    new npc_commander_durand();
    new npc_scarlet_judicator();
    new at_enter_durand_room();
    new achievement_and_stay_dead();
}
