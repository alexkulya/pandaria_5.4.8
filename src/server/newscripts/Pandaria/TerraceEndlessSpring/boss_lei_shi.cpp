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

#include "NewScriptPCH.h"
#include "terrace_of_endless_spring.h"

enum eSpells
{
    SPELL_AFRAID            = 123181,
    SPELL_SPRAY             = 123121,
    SPELL_GETAWAY           = 123461,
    SPELL_GETAWAY_TELEPORT  = 123441,
    SPELL_PROTECT           = 123250,
    SPELL_HIDE              = 123244,
    SPELL_HIDE_SUM_CLONE    = 123213,
    SPELL_HIDE_PROC         = 123233,
    SPELL_HIDE_TELEPORT     = 123189,
    SPELL_BERSERK           = 26662,
    //Heroic
    SPELL_SCARY_FOG         = 123797,
};

enum eEvents
{
    EVENT_CHECK_VICTIM      = 1,
    EVENT_PROTECTION        = 2,
    EVENT_SPECIAL_EVENT     = 3,
    EVENT_BERSERK           = 4,
};

enum sSummon
{
    NPC_ANIMATED_PROTECTOR  = 62995,
    NPC_LEI_SHI_CLONE       = 63099,
};

enum ePhase
{
    PHASE_HIDE              = 0,
    PHASE_GETAWAY           = 1,
};

Position const sumprpos[3] = 
{
    {-990.73f,  -2927.51f, 19.1718f},
    {-1045.78f, -2925.12f, 19.1729f},
    {-1017.72f, -2885.31f, 19.6366f},
};

float const minpullpos = -2978.5349f;
float const maxpullpos = -2851.7839f;

bool CheckTsulong(InstanceScript* instance, Creature* caller)
{
    if (instance && caller)
    {
        if (Creature* ts = caller->GetCreature(*caller, instance->GetData64(NPC_TSULONG)))
        {
            if (ts->IsAlive())
                return true;
        }
    }
    return false;
}

class boss_lei_shi : public CreatureScript
{
    public:
        boss_lei_shi() : CreatureScript("boss_lei_shi") {}

        struct boss_lei_shiAI : public BossAI
        {
            boss_lei_shiAI(Creature* creature) : BossAI(creature, DATA_LEI_SHI)
            {
                instance = creature->GetInstanceScript();
                if (instance)
                {
                    if (CheckTsulong(instance, me))
                    {
                        me->SetVisible(false);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    }
                }
            }

            InstanceScript* instance;
            uint8 health;
            uint8 specPhaseId;
            bool specEvent;

            void Reset()
            {
                _Reset();
                health = 80;
                specPhaseId = PHASE_HIDE;
                specEvent = false;
                me->SetReactState(REACT_DEFENSIVE);
                me->RemoveAllAuras();
                me->RemoveAreaObject(SPELL_GETAWAY);
                instance->DoRemoveAurasDueToSpellOnPlayers(123705);
                DoCast(me, SPELL_AFRAID, true);
            }

            void JustReachedHome()
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_DEFENSIVE);
            }
            
            void EnterCombat(Unit* who)
            {
                if (instance)
                {
                    if (!CheckPullPlayerPos(who))
                    {
                        EnterEvadeMode();
                        return;
                    }
                }
                _EnterCombat();
                events.ScheduleEvent(EVENT_CHECK_VICTIM, 2000);
                events.ScheduleEvent(EVENT_SPECIAL_EVENT, 30000);
                if (IsHeroic())
                {
                    DoCast(me, SPELL_SCARY_FOG, true);
                    events.ScheduleEvent(EVENT_BERSERK, 7 * MINUTE * IN_MILLISECONDS);
                }
                else
                    events.ScheduleEvent(EVENT_BERSERK, 10 * MINUTE * IN_MILLISECONDS);
            }

            bool CheckPullPlayerPos(Unit* who)
            {
                if (!who->ToPlayer() || who->GetPositionY() < minpullpos || who->GetPositionY() > maxpullpos)
                    return false;

                return true;
            }

            void DamageTaken(Unit* attacker, uint32 &damage)
            {
                if (me->HasAura(SPELL_PROTECT))
                    damage = 0;

                if (HealthBelowPct(health))
                {
                    health -= 20;
                    events.ScheduleEvent(EVENT_PROTECTION, 500);
                }
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_1: // End phase - Get Away!
                        specEvent = false;
                        break;
                    case ACTION_REMOVE_PROTECT:
                    {
                        if (me->HasAura(SPELL_PROTECT))
                        {
                            me->RemoveAurasDueToSpell(SPELL_PROTECT);
                            summons.DespawnAll();
                            specEvent = false;
                        }
                        break;
                    }
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                me->RemoveAreaObject(SPELL_GETAWAY);
                if (instance)
                {
                    _JustDied();
                    if (Creature* sha = me->GetCreature(*me, instance->GetData64(NPC_SHA_OF_FEAR)))
                    {
                        sha->SetVisible(true);
                        sha->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    }
                }
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                if (!me->isInCombat())
                    return;

                if (summon->GetEntry() == NPC_LEI_SHI_CLONE)
                {
                    me->RemoveAurasDueToSpell(SPELL_HIDE);
                    specEvent = false;
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (specEvent)
                {
                    if (me->HasAura(SPELL_PROTECT))
                        DoSpellAttackIfReady(SPELL_SPRAY);
                    return;
                }

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHECK_VICTIM:
                        {
                            if (me->getVictim() && !CheckPullPlayerPos(me->getVictim()))
                            {
                                me->AttackStop();
                                me->SetReactState(REACT_PASSIVE);
                                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                                EnterEvadeMode();
                            }
                            events.ScheduleEvent(EVENT_CHECK_VICTIM, 2000);
                            break;
                        }
                        case EVENT_PROTECTION:
                        {
                            specEvent = true;
                            uint8 raidMode = Is25ManRaid() ? 5 : 3;
                            me->AddAura(SPELL_PROTECT, me);
                            for (uint8 n = 0; n < raidMode; n++)
                            {
                                if (Creature* pr = me->SummonCreature(NPC_ANIMATED_PROTECTOR, sumprpos[n]))
                                    pr->AI()->DoZoneInCombat(pr, 100.0f);
                            }
                            break;
                        }
                        case EVENT_SPECIAL_EVENT:
                        {
                            specEvent = true;
                            if (specPhaseId == PHASE_HIDE)
                            {
                                float x = 0.0f, y = 0.0f, z = 19.8f;
                                GetRandPosFromCenterInDist(-1017.79f, -2911.37f, frand(20.0f, 35.0f), x, y);
                                DoCast(SPELL_HIDE);
                                me->SummonCreature(NPC_LEI_SHI_CLONE, x, y, z, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 30000);
                                specPhaseId = PHASE_GETAWAY;
                            }
                            else if (specPhaseId == PHASE_GETAWAY)
                            {
                                DoStopAttack();
                                DoCast(me, SPELL_GETAWAY_TELEPORT, true);
                                DoCast(SPELL_GETAWAY);
                                specPhaseId = PHASE_HIDE;
                            }
                            events.ScheduleEvent(EVENT_SPECIAL_EVENT, 50 * IN_MILLISECONDS); //50sec
                            break;
                        }
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK, true);
                            break;
                    }
                }
                DoSpellAttackIfReady(SPELL_SPRAY);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_lei_shiAI(creature);
        }
};

//63099
class npc_lei_shi_clone : public CreatureScript
{
public:
    npc_lei_shi_clone() : CreatureScript("npc_lei_shi_clone") { }

    struct npc_lei_shi_cloneAI : public ScriptedAI
    {
        npc_lei_shi_cloneAI(Creature* creature) : ScriptedAI(creature) 
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
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_IMMUNE_TO_NPC);
            SetCombatMovement(false);
        }

        EventMap events;
        bool despawn;

        void Reset() {}
        
        void IsSummonedBy(Unit* summoner)
        {
            despawn = false;
            DoZoneInCombat(me, 60.0f);

            if (summoner->getVictim())
                AttackStart(summoner->getVictim());

            DoCast(me, SPELL_HIDE_PROC, true);
            events.ScheduleEvent(EVENT_1, 2000);
        }

        void DamageTaken(Unit* attacker, uint32 &damage)
        {
            damage = 0;
            
            if (!me->HasAura(SPELL_HIDE_PROC) && !despawn)
            {
                despawn = true;
                me->DespawnOrUnsummon(500);
            }
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
                    case EVENT_1:
                        if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                            summoner->CastSpell(me, SPELL_HIDE_TELEPORT, true);
                        break;
                }
            }
            DoSpellAttackIfReady(SPELL_SPRAY);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_lei_shi_cloneAI(creature);
    }
};

//123181
class spell_leishi_afraid : public SpellScriptLoader
{
    public:
        spell_leishi_afraid() : SpellScriptLoader("spell_leishi_afraid") { }
 
        class spell_leishi_afraid_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_leishi_afraid_AuraScript)

            float amount;
            float maxHealthPct;
            float getHealthPct;

            void OnPeriodic(AuraEffect const* aurEff)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                maxHealthPct = 100.0f;
                getHealthPct = caster->GetHealthPct();
                amount = maxHealthPct - getHealthPct;

                if (AuraEffect* effect = GetAura()->GetEffect(EFFECT_0))
                    effect->ChangeAmount(amount);
            }
 
            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_leishi_afraid_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };
 
        AuraScript* GetAuraScript() const
        {
            return new spell_leishi_afraid_AuraScript();
        }
};

//123233
class spell_leishi_hide_proc : public SpellScriptLoader
{
    public:
        spell_leishi_hide_proc() : SpellScriptLoader("spell_leishi_hide_proc") { }

        class spell_leishi_hide_proc_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_leishi_hide_proc_AuraScript);

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (!GetCaster())
                    return;

                GetCaster()->CastSpell(GetCaster(), 132363, true);
            }

            void Register()
            {
                OnEffectProc += AuraEffectProcFn(spell_leishi_hide_proc_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_leishi_hide_proc_AuraScript();
        }
};

//123461
class spell_leishi_get_away : public SpellScriptLoader
{
    public:
        spell_leishi_get_away() : SpellScriptLoader("spell_leishi_get_away") { }
 
        class spell_leishi_get_away_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_leishi_get_away_AuraScript)

            float HealthPct;

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                HealthPct = caster->GetHealthPct() - 4.0f;
            }
            
            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Creature* caster = GetCaster()->ToCreature();
                if (!caster)
                    return;

                caster->ToCreature()->SetReactState(REACT_AGGRESSIVE);
                caster->RemoveAreaObject(SPELL_GETAWAY);
                caster->AI()->DoAction(ACTION_1);
            }

            void OnPeriodic(AuraEffect const* aurEff)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                if (caster->GetHealthPct() < HealthPct)
                    GetAura()->Remove();
            }
 
            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_leishi_get_away_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
                OnEffectApply += AuraEffectApplyFn(spell_leishi_get_away_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectApplyFn(spell_leishi_get_away_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };
 
        AuraScript* GetAuraScript() const
        {
            return new spell_leishi_get_away_AuraScript();
        }
};

//123705
class spell_leishi_scary_fog : public SpellScriptLoader
{
    public:
        spell_leishi_scary_fog() : SpellScriptLoader("spell_leishi_scary_fog") { }
 
        class spell_leishi_scary_fog_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_leishi_scary_fog_AuraScript)

            void OnPeriodic(AuraEffect const* aurEff)
            {
                Unit* target = GetTarget();
                if (!target)
                    return;

                target->CastSpell(target, 123712, true); //mod dmg
            }
 
            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_leishi_scary_fog_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };
 
        AuraScript* GetAuraScript() const
        {
            return new spell_leishi_scary_fog_AuraScript();
        }
};

void AddSC_boss_lei_shi()
{
    new boss_lei_shi();
    new npc_lei_shi_clone();
    new spell_leishi_afraid();
    new spell_leishi_hide_proc();
    new spell_leishi_get_away();
    new spell_leishi_scary_fog();
}
