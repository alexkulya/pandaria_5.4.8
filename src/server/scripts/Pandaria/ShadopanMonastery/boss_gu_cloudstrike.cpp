/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
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
#include "MoveSplineInit.h"
#include "shadopan_monastery.h"

enum GuCloudstrikeSpellData
{
    SPELL_KILL_GUARDIANS                    = 114927,
    SPELL_INVOKE_LIGHTNING                  = 106984,
    SPELL_CHARGING_SOUL                     = 110945,
    SPELL_OVERCHARGED_SOUL                  = 110852,
    SPELL_ARC_LIGHTNING                     = 111205,
    SPELL_OVERCHARGED                       = 111007,
    SPELL_STATIC_FIELD                      = 106923,
    SPELL_MAGNETIC_SHROUD_OVERLOAD          = 107174,
    SPELL_STATIC_FIELD_DUMMY_AURA           = 106945,

    // Azure Serpent
    SPELL_LIGHTNING_SHIELD                  = 123496,
    SPELL_LIGHTNING_BREATH                  = 102573,
    SPELL_MAGNETIC_SHROUD                   = 107140,

    // Static Field Stalker
    SPELL_STATIC_FIELD_PROC                 = 106941
};

enum GuCloudstrikeEvents
{
    EVENT_INVOKE_LIGHTNING                  = 1,
    EVENT_OVERCHARGED_SOUL                  = 2,
    EVENT_TALK_CALLDRAGON                   = 3,
    EVENT_STATIC_FIELD                      = 4,
    EVENT_TALK_INTRO_2                      = 5,

    // Azure Serpent
    EVENT_STATIC_FIELD_AS                   = 1,
    EVENT_LIGHTNING_BREATH                  = 2,
    EVENT_MAGNETIC_SHROUD                   = 3,
    EVENT_SWITCH_PHASE                      = 4
};

enum GuCloudstrikeTexts
{
    TALK_AGGRO                              = 0,
    TALK_SERPENT_COME                       = 1,
    TALK_DEATH                              = 2,
    TALK_INTRO_1                            = 5,
    TALK_INTRO_2                            = 6,
    TALK_PHASE_2                            = 7,
    TALK_SLAY                               = 8,
    TALK_PHASE_3                            = 9,
    TALK_SERPENT                            = 10,

    // Azure Serpent
    TALK_PHASE_2_AS                         = 1,
    TALK_MAGNETIC                           = 2,
    TALK_HALF_HEALTH                        = 3,
    TALK_QUARTER_HEALTH                     = 4
};

enum GuCloudstrikeActions
{
    ACTION_INTRO                            = 1,
    ACTION_GU_P_3                           = 2,
    ACTION_AZURE_SERPENT_P_2                = 3,
    ACTION_STATIC_FIELD                     = 4
};

Position AzureSerpentSpawnPos = {3829.19f, 2927.29f, 705.71f, 0.0f};

const float AzureSerpentWPPath[4][3] =
{
    {3835.01f, 2906.63f, 753.33f},
    {3850.37f, 2738.14f, 814.84f},
    {3758.79f, 2692.08f, 778.60f},
    {3736.37f, 2680.89f, 768.60f}
};

class boss_gu_cloudstrike : public CreatureScript
{
    public:
        boss_gu_cloudstrike() : CreatureScript("boss_gu_cloudstrike") { }

        struct boss_gu_cloudstrikeAI : public BossAI
        {
            boss_gu_cloudstrikeAI(Creature* creature) : BossAI(creature, DATA_GU_CLOUDSTRIKE) { }

            bool introDone, azurePhase;
            EventMap nonCombatEvents;

            void InitializeAI() override
            {
                me->setActive(true);
                introDone = false;

                Reset();
            }

            void Reset() override
            {
                _Reset();
                azurePhase = false;
                events.Reset();
                nonCombatEvents.Reset();
                me->setRegeneratingHealth(true);
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveAurasDueToSpell(SPELL_CHARGING_SOUL);           

                if (instance)
                    instance->SetData(DATA_GU_CLOUDSTRIKE, NOT_STARTED);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (me->HealthBelowPctDamaged(50, damage) && !azurePhase)
                {
                    azurePhase = true;
                    events.Reset();
                    me->SetReactState(REACT_PASSIVE);
                    me->CombatStop(true);
                    me->setRegeneratingHealth(false);
                    float speed = me->GetExactDist(3722.58f, 2674.1f, 768.042f) / 1 * IN_MILLISECONDS;
                    Movement::MoveSplineInit init(me);
                    init.MoveTo(3722.58f, 2674.1f, 768.042f);
                    init.SetVelocity(speed);
                    init.Launch();

                    nonCombatEvents.ScheduleEvent(EVENT_OVERCHARGED_SOUL, me->GetSplineDuration());
                }
            }

            void DoAction(int32 actionId) override
            {
                switch (actionId)
                {
                    case ACTION_INTRO:
                        if (!introDone)
                        {
                            introDone = true;
                            Talk(TALK_INTRO_1);
                            me->CastSpell(me, SPELL_KILL_GUARDIANS);
                            nonCombatEvents.ScheduleEvent(EVENT_TALK_INTRO_2, 6s + 400ms);
                        }
                        break;
                    case ACTION_GU_P_3:
                        Talk(TALK_PHASE_3);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->CastSpell(me, SPELL_ARC_LIGHTNING, true);
                        me->CastSpell(me, SPELL_OVERCHARGED, false);
                        me->RemoveAurasDueToSpell(SPELL_CHARGING_SOUL);
                        break;
                    case ACTION_STATIC_FIELD:
                        events.ScheduleEvent(EVENT_STATIC_FIELD, 5s);
                        break;
                }
            }

            void JustDied(Unit* killer) override
            {
                _JustDied();
                Talk(TALK_DEATH);

                if (instance)
                {
                    instance->SetData(DATA_GU_CLOUDSTRIKE, DONE);
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                }
            }

            void JustSummoned(Creature* summoned) override
            {
                summons.Summon(summoned);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(TALK_SLAY);
            }

            void EnterEvadeMode() override
            {
                BossAI::EnterEvadeMode();

                if (instance)
                {
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                    instance->SetData(DATA_GU_CLOUDSTRIKE, FAIL);
                }
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (!azurePhase)
                {
                    _EnterCombat();
                    Talk(TALK_AGGRO);

                    if (instance)
                    {
                        instance->SetData(DATA_GU_CLOUDSTRIKE, IN_PROGRESS);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                    }

                    events.ScheduleEvent(EVENT_TALK_CALLDRAGON, 4s);
                    events.ScheduleEvent(EVENT_INVOKE_LIGHTNING, randtime(5s, 10s));
                }
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);
                nonCombatEvents.Update(diff);

                if (uint32 eventId = nonCombatEvents.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_OVERCHARGED_SOUL:
                            DoZoneInCombat();
                            Talk(TALK_PHASE_2);
                            me->CastSpell(me, SPELL_OVERCHARGED_SOUL, false);
                            me->CastSpell(me, SPELL_CHARGING_SOUL, false);

                            if (auto const azureSerpent = Unit::GetCreature(*me, instance->GetData64(DATA_AZURE_SERPENT)))
                               if (azureSerpent->IsAIEnabled)
                                   azureSerpent->AI()->DoAction(ACTION_AZURE_SERPENT_P_2);
                            break;
                        case EVENT_TALK_INTRO_2:
                            Talk(TALK_INTRO_2);
                            break;
                    }
                }

                if (!UpdateVictim())
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_INVOKE_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                                me->CastSpell(target, SPELL_INVOKE_LIGHTNING, false);
                            events.ScheduleEvent(EVENT_INVOKE_LIGHTNING, randtime(5s, 10s));
                            break;
                        case EVENT_TALK_CALLDRAGON:
                            Talk(TALK_SERPENT);
                            Talk(TALK_SERPENT_COME);
                            me->SummonCreature(NPC_AZURE_SERPENT, AzureSerpentSpawnPos);
                            break;
                        case EVENT_STATIC_FIELD:
                            if (auto const target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            {
                                if (auto const azureSerpent = Unit::GetCreature(*me, instance->GetData64(DATA_AZURE_SERPENT)))
                                    azureSerpent->CastSpell(target, SPELL_STATIC_FIELD, false);
                            }
                            events.ScheduleEvent(EVENT_STATIC_FIELD, randtime(13s, 16s));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_gu_cloudstrikeAI(creature);
        }
};

struct npc_azure_serpent : public ScriptedAI
{
    npc_azure_serpent(Creature* creature) : ScriptedAI(creature) { }

    bool halfHealth, quarterHealth;
    InstanceScript* instance;
    EventMap events;

    void InitializeAI() override
    {
        instance = me->GetInstanceScript();
        halfHealth = false;
        quarterHealth = false;
        me->setActive(true);
        me->SetReactState(REACT_PASSIVE);
        me->CastSpell(me, SPELL_LIGHTNING_SHIELD, false);
        Movement::MoveSplineInit init(me);

        for (uint8 i = 0; i < 3; ++i)
        {
            G3D::Vector3 path(AzureSerpentWPPath[i][0], AzureSerpentWPPath[i][1], AzureSerpentWPPath[i][2]);
            init.Path().push_back(path);
        }
        init.SetSmooth();
        init.SetFly();
        init.SetUncompressed();
        init.SetVelocity(32.0f);
        init.Launch();

        events.ScheduleEvent(EVENT_STATIC_FIELD_AS, me->GetSplineDuration());
    }

    void AttackStart(Unit* target) override
    {
        if (!target)
            return;

        if (me->Attack(target, true))
            DoStartNoMovement(target);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (auto const gu = Unit::GetCreature(*me, instance->GetData64(DATA_GU_CLOUDSTRIKE)))
           if (gu->IsAIEnabled)
               gu->AI()->DoAction(ACTION_GU_P_3);
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(50, damage) && !halfHealth)
        {
            halfHealth = true;

            if (auto const gu = Unit::GetCreature(*me, instance->GetData64(DATA_GU_CLOUDSTRIKE)))
               if (gu->IsAIEnabled)
                   gu->AI()->Talk(TALK_HALF_HEALTH);
        }

        if (me->HealthBelowPctDamaged(15, damage) && !quarterHealth)
        {
            quarterHealth = true;

            if (auto const gu = Unit::GetCreature(*me, instance->GetData64(DATA_GU_CLOUDSTRIKE)))
               if (gu->IsAIEnabled)
                   gu->AI()->Talk(TALK_QUARTER_HEALTH);
        }
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_AZURE_SERPENT_P_2)
        {
            events.Reset();
            Talk(TALK_PHASE_2_AS);
            Movement::MoveSplineInit init(me);
            init.MoveTo(AzureSerpentWPPath[3][0], AzureSerpentWPPath[3][1], AzureSerpentWPPath[3][2]);
            init.SetSmooth();
            init.SetFly();
            init.SetVelocity(13.0f);
            init.Launch(); 

            events.ScheduleEvent(EVENT_SWITCH_PHASE, me->GetSplineDuration());
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);            

        switch (events.ExecuteEvent())
        {
            case EVENT_STATIC_FIELD_AS:
                if (Creature* gu = Unit::GetCreature(*me, instance->GetData64(DATA_GU_CLOUDSTRIKE)))
                   if (gu->IsAIEnabled)
                       gu->AI()->DoAction(ACTION_STATIC_FIELD);
                break;
            case EVENT_MAGNETIC_SHROUD:
                Talk(TALK_MAGNETIC);
                me->CastSpell(me, SPELL_MAGNETIC_SHROUD, TRIGGERED_FULL_MASK);
                events.ScheduleEvent(EVENT_MAGNETIC_SHROUD, randtime(12s, 16s));
                break;
            case EVENT_LIGHTNING_BREATH:
                if (me->GetVictim())
                {
                    me->SetFacingToObject(me->GetVictim());
                    me->SetOrientation(me->GetAngle(me->GetVictim()));
                }
                me->CastSpell(me, SPELL_LIGHTNING_BREATH, TRIGGERED_FULL_MASK);
                events.ScheduleEvent(EVENT_LIGHTNING_BREATH, randtime(8s, 12s));
                break;
            case EVENT_SWITCH_PHASE:
                DoZoneInCombat();
                me->SetReactState(REACT_AGGRESSIVE);
                me->OverrideInhabitType(INHABIT_GROUND);
                me->UpdateMovementFlags();
                me->SetFacingTo(me->GetAngle(3722.58f, 2674.1f));

                if (Player* itr = me->FindNearestPlayer(50.0f))
                    me->Attack(itr, true);

                me->RemoveAurasDueToSpell(SPELL_LIGHTNING_SHIELD);
                events.ScheduleEvent(EVENT_MAGNETIC_SHROUD, randtime(8s, 12s));
                events.ScheduleEvent(EVENT_LIGHTNING_BREATH, randtime(2s + 500ms, 7s + 500ms));
                break;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_spm_static_field : public ScriptedAI
{
    npc_spm_static_field(Creature* creature) : ScriptedAI(creature) { }

    InstanceScript* instance;
    EventMap events;

    void InitializeAI() override
    {
        instance = me->GetInstanceScript();
        me->DespawnOrUnsummon(65000);
        me->CastSpell(me, SPELL_STATIC_FIELD_PROC, false);
    }

    void JustDied(Unit* /*killer*/) override { }

    void UpdateAI(uint32 /*diff*/) override { }
};

class OnlyGuardianPredicate
{
public:
    OnlyGuardianPredicate() { }

    bool operator()(WorldObject* target)
    {
        return target->GetEntry() != NPC_GUARDIAN;
    }
};

class spell_kill_guardians : public SpellScript
{
    PrepareSpellScript(spell_kill_guardians);

    void SelectTarget(std::list<WorldObject*>& targetList)
    {
        targetList.remove_if (OnlyGuardianPredicate());
    }

    void KillTarget(std::list<WorldObject*>& targetList)
    {
        targetList.remove_if (OnlyGuardianPredicate());

        for (auto&& itr : targetList)
        {
            if (auto const target = itr->ToCreature())
            {
                target->Kill(target);
                target->DespawnOrUnsummon(2 * IN_MILLISECONDS);
            }
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kill_guardians::SelectTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_kill_guardians::KillTarget, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_spm_arc_lightning : public AuraScript
{
    PrepareAuraScript(spell_spm_arc_lightning)

    void OnPeriodic(AuraEffect const* aurEff)
    {
        auto const caster = GetCaster();

        if (!caster)
            return;

        if (auto const aura = caster->GetAuraEffect(aurEff->GetId(), EFFECT_0))
            aura->SetAmplitude(caster->GetHealthPct() * 100);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_spm_arc_lightning::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_spm_magnetic_shroud : public AuraScript
{
    PrepareAuraScript(spell_spm_magnetic_shroud);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        auto const owner = GetOwner()->ToPlayer();

        if (!owner)
            return;

        owner->CastSpell(owner, SPELL_MAGNETIC_SHROUD_OVERLOAD, false);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_spm_magnetic_shroud::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_spm_charging_soul : public AuraScript
{
    PrepareAuraScript(spell_spm_charging_soul);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        auto const owner = GetOwner()->ToCreature();

        if (!owner)
            return;

        owner->ApplySpellImmune(0, IMMUNITY_SCHOOL, (SPELL_SCHOOL_MASK_NORMAL | SPELL_SCHOOL_MASK_HOLY), true);
        owner->ApplySpellImmune(0, IMMUNITY_ID, 35395, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        auto const owner = GetOwner()->ToCreature();

        if (!owner)
            return;

        owner->ApplySpellImmune(0, IMMUNITY_SCHOOL, (SPELL_SCHOOL_MASK_NORMAL | SPELL_SCHOOL_MASK_HOLY), false);
        owner->ApplySpellImmune(0, IMMUNITY_ID, 35395, false);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_spm_charging_soul::OnApply, EFFECT_0, SPELL_AURA_SCHOOL_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_spm_charging_soul::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_spm_static_field : public AuraScript
{
    PrepareAuraScript(spell_spm_static_field)

    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (Unit* owner = GetOwner()->ToUnit())
            if (!owner->HasAura(SPELL_STATIC_FIELD_DUMMY_AURA))
                owner->CastSpell(owner, SPELL_STATIC_FIELD_DUMMY_AURA, false);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_spm_static_field::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class AreaTrigger_at_gu_intro : public AreaTriggerScript
{
    public:
        AreaTrigger_at_gu_intro() : AreaTriggerScript("at_gu_intro") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/) override
        {
            if (auto const instance = player->GetInstanceScript())
                if (auto const gu = instance->instance->GetCreature(instance->GetData64(DATA_GU_CLOUDSTRIKE)))
                    if (gu->IsAIEnabled)
                        gu->AI()->DoAction(ACTION_INTRO);

            return false;
        }
};

void AddSC_boss_gu_cloudstrike()
{
    new boss_gu_cloudstrike();
    register_creature_script(npc_azure_serpent);
    register_creature_script(npc_spm_static_field);
    register_spell_script(spell_kill_guardians);
    register_aura_script(spell_spm_arc_lightning);
    register_aura_script(spell_spm_magnetic_shroud);
    register_aura_script(spell_spm_charging_soul);
    register_aura_script(spell_spm_static_field);
    new AreaTrigger_at_gu_intro();
}
