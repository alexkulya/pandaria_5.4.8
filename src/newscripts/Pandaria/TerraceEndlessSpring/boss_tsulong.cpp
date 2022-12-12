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
    //Tsulong
    //Night phase
    SPELL_SHA_ACTIVE            = 122438,
    SPELL_DREAD_SHADOWS         = 122767,
    SPELL_DREAD_SHADOWS_TR_EF   = 122768,
    SPELL_NIGHTMARES            = 122770,
    SPELL_SHADOW_BREATH         = 122752,
    SPELL_SUNBEAM               = 122782,
    SPELL_SUNBEAM_TR_EF         = 122789,
    //Day phase
    SPELL_SUN_BREATH            = 122855,
    SPELL_BATHED_INLIGHT        = 122858,
    SPELL_SUM_EMBODIED_TERROR   = 122995,
    SPELL_SUM_UNSTABLE_SHA      = 122953,

    SPELL_BERSERK               = 130008,
    //
    //Sha Summons
    SPELL_TERRORIZE             = 123011,
    SPELL_SUM_TINY_TERROR       = 123508,
    SPELL_FRIGHT                = 123036,

    SPELL_UNSTABLE_BOLT         = 122881,
    SPELL_INSTABILITY           = 123697,
};

enum eSummons
{
    NPC_SUNBEAM                 = 90740,
};

enum eEvents
{
    EVENT_SHADOW_BREATH         = 1,
    EVENT_NIGHTMARE             = 2,
    EVENT_SUNBEAM               = 3,
    EVENT_SUN_BREATH            = 4,
    EVENT_SUM_EMBODIED_TERROR   = 5,
    EVENT_SUM_UNSTABLE_SHA      = 6,
    EVENT_BERSERK               = 7,
};

enum Phase
{
    PHASE_NULL           = 0, 
    PHASE_NIGHT          = 1,
    PHASE_DAY            = 2,
};

enum Action
{
    ACTION_INTRO_DAY     = 1,
    ACTION_INTRO_NIGHT   = 2,
};

Position const sunbeampos[4] = 
{
    {-1017.82f, -3078.43f, 12.5717f},
    {-1017.74f, -3023.0f,  12.5803f},
    {-992.80f,  -3049.35f, 12.5840f},
    {-1044.39f, -3049.58f, 12.5793f},
};

Position const centrPos = {-1017.61f, -3049.10f, 12.82f};

enum DisplayId
{
    NIGHT_ID = 42532,
    DAY_ID   = 42533,
};

bool CheckProtectors(InstanceScript* instance, Creature* caller)
{
    if (instance && caller)
    {
        if (Creature* pr = caller->GetCreature(*caller, instance->GetData64(NPC_PROTECTOR_KAOLAN)))
        {
            if (pr->IsAlive())
                return true;
        }
    }
    return false;
}

class boss_tsulong : public CreatureScript
{
    public:
        boss_tsulong() : CreatureScript("boss_tsulong") {}

        struct boss_tsulongAI : public BossAI
        {
            boss_tsulongAI(Creature* creature) : BossAI(creature, DATA_TSULONG)
            {
                instance = creature->GetInstanceScript();
                if (instance)
                {
                    if (CheckProtectors(instance, me))
                    {
                        me->SetVisible(false);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    }
                }
            }

            InstanceScript* instance;
            uint32 checkpower, lowpower;
            bool done;
            Phase phase;

            void Reset()
            {              
                _Reset();
                phase = PHASE_NULL;
                done = false;
                lowpower = 0;
                checkpower = 0;
                me->RemoveAurasDueToSpell(SPELL_DREAD_SHADOWS);
                me->RemoveAurasDueToSpell(SPELL_SHA_ACTIVE);
                me->setFaction(16);
                me->SetDisplayId(NIGHT_ID);
                me->SetReactState(REACT_DEFENSIVE);
                me->setPowerType(POWER_ENERGY);
                me->SetPower(POWER_ENERGY, 0);
                me->SetHealth(me->GetMaxHealth());
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_INTRO_DAY:
                        summons.DespawnEntry(NPC_SUNBEAM);
                        me->RemoveAurasDueToSpell(SPELL_DREAD_SHADOWS);
                        me->RemoveAurasDueToSpell(SPELL_SHA_ACTIVE);
                        me->setFaction(35);
                        me->SetDisplayId(DAY_ID);
                        me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE);
                        me->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                        me->RemoveAurasByType(SPELL_AURA_PERIODIC_LEECH);
                        DoStopAttack();
                        me->GetMotionMaster()->MoveTargetedHome();
                        me->SetHealth(me->GetMaxHealth() - me->GetHealth());
                        lowpower = 1000;
                        events.ScheduleEvent(EVENT_SUN_BREATH, 20000);
                        events.ScheduleEvent(EVENT_SUM_EMBODIED_TERROR, 5000);
                        events.ScheduleEvent(EVENT_SUM_UNSTABLE_SHA, 18000);
                        break;
                    case ACTION_INTRO_NIGHT:
                        summons.DespawnAll();
                        me->SetHealth(me->GetMaxHealth() - me->GetHealth());
                        me->setFaction(16);
                        me->SetDisplayId(NIGHT_ID);
                        me->SetReactState(REACT_AGGRESSIVE);
                        if (!checkpower)
                            checkpower = 1000;
                        DoZoneInCombat(me, 150.0f);
                        if (me->getVictim())
                            me->GetMotionMaster()->MoveChase(me->getVictim());
                        me->AddAura(SPELL_DREAD_SHADOWS, me);
                        me->RemoveAurasDueToSpell(123012);
                        DoCast(me, SPELL_SHA_ACTIVE, true);
                        events.ScheduleEvent(EVENT_SHADOW_BREATH, urand(25000, 35000));
                        events.ScheduleEvent(EVENT_NIGHTMARE,     urand(15000, 25000));
                        events.ScheduleEvent(EVENT_SUNBEAM,       urand(15000, 20000));
                        break;
                }
            }

            void EnterCombat(Unit* who)
            {
                _EnterCombat();
                events.SetPhase(PHASE_NIGHT);
                phase = PHASE_NIGHT;
                checkpower = 1000; 
                me->AddAura(SPELL_DREAD_SHADOWS, me);
                DoCast(me, SPELL_SHA_ACTIVE, true);
                events.ScheduleEvent(EVENT_SHADOW_BREATH, urand(25000, 35000));
                events.ScheduleEvent(EVENT_NIGHTMARE,     urand(15000, 25000));
                events.ScheduleEvent(EVENT_SUNBEAM,       urand(15000, 20000));
                events.ScheduleEvent(EVENT_BERSERK, 8 * MINUTE * IN_MILLISECONDS);
            }

            void DamageTaken(Unit* attacker, uint32 &damage)
            {
                if (damage >= me->GetHealth())
                {
                    switch (phase)
                    {
                        case PHASE_NIGHT:
                            if (!done)
                            {
                                done = true;
                                SendDone();
                            }
                            break;
                        case PHASE_DAY:
                            if (me->isInCombat())
                            {
                                me->RemoveAllAuras();
                                EnterEvadeMode();
                            }
                            break;
                        default:
                            break;
                    }
                    damage = 0;
                }
            }

            void SendDone()
            {
                summons.DespawnAll();
                me->SetVisible(false);
                me->Kill(me, true);
                if (instance)
                {
                    instance->SetBossState(DATA_TSULONG, DONE);
                    if (Creature* leishi = me->GetCreature(*me, instance->GetData64(NPC_LEI_SHI)))
                    {
                        leishi->SetVisible(true);
                        leishi->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    }
                }
                if(!me->GetMap()->IsLfr())
                    me->SummonGameObject(212922, me->GetPositionX() + 6, me->GetPositionY(), me->GetPositionZ(), 0, 0, 0, 0, 0, 604800);
            }

            void JustDied(Unit* killer)
            {
                me->RemoveFlag(OBJECT_FIELD_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (checkpower)
                {
                    if (checkpower <= diff)
                    {
                        if (me->GetPower(POWER_ENERGY) == 100 && phase == PHASE_NIGHT)
                        {
                            phase = PHASE_DAY;
                            checkpower = 0; 
                            events.Reset();
                            DoAction(ACTION_INTRO_DAY);
                        }
                    }
                    else 
                        checkpower -= diff;
                }

                if (lowpower && phase == PHASE_DAY)
                {
                    if (lowpower <= diff)
                    {
                        if (instance)
                        {
                            if (instance->IsWipe())
                            {
                                EnterEvadeMode();
                                return;
                            }
                        }

                        if (me->GetHealth() == me->GetMaxHealth() && !done)
                        {
                            done = true;
                            SendDone();
                            return;
                        }

                        if (me->GetPower(POWER_ENERGY) >= 1)
                            me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) - 1);

                        if (me->GetPower(POWER_ENERGY) == 0 && phase == PHASE_DAY)
                        {
                            phase = PHASE_NIGHT;
                            lowpower = 0;
                            events.Reset();
                            DoAction(ACTION_INTRO_NIGHT);
                        }
                        else
                            lowpower = 1000;
                    }
                    else
                        lowpower -= diff;
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHADOW_BREATH:
                            if (me->getVictim())
                                DoCast(me->getVictim(), SPELL_SHADOW_BREATH);
                            events.ScheduleEvent(EVENT_SHADOW_BREATH, urand(25000, 35000));
                            break;
                        case EVENT_NIGHTMARE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 40.0f, true))
                                DoCast(target, SPELL_NIGHTMARES);
                            events.ScheduleEvent(EVENT_NIGHTMARE, urand(15000, 25000));
                            break;
                        case EVENT_SUNBEAM:
                            summons.DespawnEntry(NPC_SUNBEAM);
                            me->SummonCreature(NPC_SUNBEAM, sunbeampos[urand(0, 3)]);
                            events.ScheduleEvent(EVENT_SUNBEAM, urand(15000, 20000));                      
                            break;
                        case EVENT_SUN_BREATH:
                            me->SetFacingTo(urand(0, 5));
                            DoCastAOE(SPELL_SUN_BREATH);
                            events.ScheduleEvent(EVENT_SUN_BREATH, 28000);
                            break;
                        case EVENT_SUM_EMBODIED_TERROR:
                            DoCast(SPELL_SUM_EMBODIED_TERROR);
                            events.ScheduleEvent(EVENT_SUM_EMBODIED_TERROR, 40000);
                            break;
                        case EVENT_SUM_UNSTABLE_SHA:
                        {
                            std::list<Creature*> creatures;
                            GetCreatureListWithEntryInGrid(creatures, me, 62962, 100.0f);
                            Trinity::Containers::RandomResizeList(creatures, 3);
                            if (!creatures.empty())
                                for (std::list<Creature*>::iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                                    DoCast((*itr), SPELL_SUM_UNSTABLE_SHA, true);
                            events.ScheduleEvent(EVENT_SUM_UNSTABLE_SHA, 16000);
                            break;
                        }
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK, true);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_tsulongAI(creature);
        }
};

class npc_sunbeam : public CreatureScript
{
    public:
        npc_sunbeam() : CreatureScript("npc_sunbeam") {}

        struct npc_sunbeamAI : public ScriptedAI
        {
            npc_sunbeamAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE);
            }
            InstanceScript* instance;
            uint8 hitval;
            uint8 maxhitval;

            void Reset()
            {
                hitval = 0;
                maxhitval = 0;
                SetMaxHitVal();
                me->SetFloatValue(OBJECT_FIELD_SCALE_X, 2.0f);
                me->AddAura(SPELL_SUNBEAM, me);
            }

            void SetMaxHitVal()
            {
                switch (me->GetMap()->GetDifficulty())
                {
                case MAN10_DIFFICULTY :
                case MAN10_HEROIC_DIFFICULTY:
                    maxhitval = 20;
                    break;
                case MAN25_DIFFICULTY:
                case MAN25_HEROIC_DIFFICULTY:
                    maxhitval = 50;
                    break;
                }
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell)
            {
                if (maxhitval)
                {
                    if (spell->Id == SPELL_SUNBEAM_TR_EF && target->GetTypeId() == TYPEID_PLAYER && hitval < maxhitval)
                        hitval++;
                    
                    if (hitval == maxhitval)
                    {
                        maxhitval = 0;
                        me->DespawnOrUnsummon();
                    }
                }
            }

            void EnterEvadeMode(){}

            void EnterCombat(Unit* who){}

            void UpdateAI(uint32 diff){}
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sunbeamAI(creature);
        }
};

//62969
class npc_tsulong_embodied_terror : public CreatureScript
{
    public:
        npc_tsulong_embodied_terror() : CreatureScript("npc_tsulong_embodied_terror") { }

        struct npc_tsulong_embodied_terrorAI : public ScriptedAI
        {
            npc_tsulong_embodied_terrorAI(Creature* creature) : ScriptedAI(creature) 
            {
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

            void Reset() {}

            void IsSummonedBy(Unit* summoner)
            {
                if (summoner->getFaction() == 16 || !summoner->isInCombat())
                {
                    me->DespawnOrUnsummon();
                    return;
                }
                DoZoneInCombat(me, 100.0f);
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_1, 2000);
            }

            void JustDied(Unit* /*killer*/)
            {
                for (uint8 i = 0; i < 5; i++)
                    DoCast(me, SPELL_SUM_TINY_TERROR, true);
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
                            DoCast(SPELL_TERRORIZE);
                            events.ScheduleEvent(EVENT_1, 20000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_tsulong_embodied_terrorAI (creature);
        }
};

//62977
class npc_tsulong_fright_spawn : public CreatureScript
{
    public:
        npc_tsulong_fright_spawn() : CreatureScript("npc_tsulong_fright_spawn") { }

        struct npc_tsulong_fright_spawnAI : public ScriptedAI
        {
            npc_tsulong_fright_spawnAI(Creature* creature) : ScriptedAI(creature) 
            {
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

            void Reset() {}

            void IsSummonedBy(Unit* summoner)
            {
                if (summoner->getFaction() == 16 || !summoner->isInCombat())
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                DoZoneInCombat(me, 100.0f);
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_1, urand(2000, 6000));
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
                            DoCast(SPELL_FRIGHT); //Fear
                            events.ScheduleEvent(EVENT_1, 10000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_tsulong_fright_spawnAI (creature);
        }
};

//62919
class npc_tsulong_unstable_sha : public CreatureScript
{
    public:
        npc_tsulong_unstable_sha() : CreatureScript("npc_tsulong_unstable_sha") { }

        struct npc_tsulong_unstable_shaAI : public ScriptedAI
        {
            npc_tsulong_unstable_shaAI(Creature* creature) : ScriptedAI(creature) 
            {
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->SetReactState(REACT_PASSIVE);
                me->SetSpeed(MOVE_RUN, 0.6f);
                me->SetSpeed(MOVE_WALK, 0.6f);
            }

            EventMap events;

            void Reset() {}

            void IsSummonedBy(Unit* summoner) 
            {
                if (summoner->getFaction() == 16 || !summoner->isInCombat())
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                DoZoneInCombat(me, 100.0f);
                me->GetMotionMaster()->MovePoint(1, centrPos);
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_1, urand(2000, 4000));
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (me->GetDistance(centrPos) > 3.0f)
                {
                    me->GetMotionMaster()->Clear();
                    events.ScheduleEvent(EVENT_2, 100);
                    return;
                }
                DoCast(me, SPELL_INSTABILITY, true);
                me->DespawnOrUnsummon(500);
            }

            void SpellHitTarget(Unit* target, const SpellInfo* spell)
            {
                if (spell->Id == SPELL_UNSTABLE_BOLT)
                    DoCast(me, 122907, true); // -15% hp
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_1:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(pTarget, SPELL_UNSTABLE_BOLT);
                            events.ScheduleEvent(EVENT_1, 4000);
                            break;
                        case EVENT_2:
                            me->GetMotionMaster()->MovePoint(1, centrPos);
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_tsulong_unstable_shaAI (creature);
        }
};

class spell_sunbeam : public SpellScriptLoader
{
    public:
        spell_sunbeam() : SpellScriptLoader("spell_sunbeam") { }

        class spell_sunbeam_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sunbeam_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget())
                {
                    if (GetTarget()->HasAura(SPELL_DREAD_SHADOWS_TR_EF))
                        GetTarget()->RemoveAurasDueToSpell(SPELL_DREAD_SHADOWS_TR_EF);
                    GetTarget()->ApplySpellImmune(SPELL_DREAD_SHADOWS_TR_EF, 0, 0, true);
                }
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (GetTarget())
                    GetTarget()->ApplySpellImmune(SPELL_DREAD_SHADOWS_TR_EF, 0, 0, false);
            }

            void Register()
            {
                OnEffectApply     += AuraEffectApplyFn(spell_sunbeam_AuraScript::OnApply,   EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                AfterEffectRemove += AuraEffectRemoveFn(spell_sunbeam_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_sunbeam_AuraScript();
        }
};

class spell_sun_breath : public SpellScriptLoader
{
    public:
        spell_sun_breath() : SpellScriptLoader("spell_sun_breath") { }

        class spell_sun_breath_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sun_breath_SpellScript);

            void DealDamage()
            {
                if (GetCaster() && GetHitUnit())
                {
                    if (GetHitUnit()->ToPlayer())
                    {
                        SetHitDamage(0);
                        GetCaster()->CastSpell(GetHitUnit(), SPELL_BATHED_INLIGHT);
                    }
                    if (GetHitUnit()->ToCreature())
                        if (GetHitUnit()->ToCreature()->GetEntry() == 62962)
                            SetHitDamage(0);
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_sun_breath_SpellScript::DealDamage);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sun_breath_SpellScript();
        }
};

void AddSC_boss_tsulong()
{
    new boss_tsulong();
    new npc_sunbeam();
    new npc_tsulong_embodied_terror();
    new npc_tsulong_fright_spawn();
    new npc_tsulong_unstable_sha();
    new spell_sunbeam();
    new spell_sun_breath();
}
