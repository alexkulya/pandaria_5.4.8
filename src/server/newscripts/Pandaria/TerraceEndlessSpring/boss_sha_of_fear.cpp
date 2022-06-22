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
    //Sha
    SPELL_PLR_TELEPORT          = 119787,
    SPELL_ZERO_REGEN            = 72242,
    SPELL_CUSTOM_REGEN          = 119417,
    SPELL_BREATH_OF_FEAR        = 119414,
    SPELL_EERIE_SKULL           = 119519,
    SPELL_REACHING_ATTACK       = 119775,
    SPELL_THRASH_PROC           = 131993,
    SPELL_OMINOUS_CACKLE_P_1    = 119593, //Platform 1
    SPELL_OMINOUS_CACKLE_P_2    = 119692, //Platform 2
    SPELL_OMINOUS_CACKLE_P_3    = 119693, //Platform 3

    //Terror spawn
    SPELL_PENETRATING_BOLT      = 129075,
    SPELL_DARK_BULWARK          = 119083,
    
    //Defenders
    SPELL_SHA_CORRUPTION_VIS    = 120000,
    SPELL_SHOOT                 = 119862,
    SPELL_SHA_GLOBE             = 129178,
    SPELL_DREAD_SPRAY           = 120047,
    SPELL_DEATH_BLOSSOM         = 119888,
};

enum eEvents
{
    //Sha
    EVENT_CHECKPOWER            = 1,
    EVENT_SKULL                 = 2,
    EVENT_R_ATTACK              = 3, //Use if no target for melee attack
    EVENT_DREAD_SPAWN           = 4,
    EVENT_OMINOUS_CACKLE        = 5,

    //Summons
    EVENT_BOLT                  = 1,
};

enum sSummons
{
    NPC_PURE_LIGHT_TERRACE      = 60788,
    NPC_TERROR_SPAWN            = 61034,
    NPC_YANG_GUOSHI             = 61038,
    NPC_CHENG_KANG              = 61042,
    NPC_JINLUN_KUN              = 61046,
    NPC_RETURN_TERRACE          = 65736,

    NPC_DREAD_SPAWN             = 61003, //Heroic
};

enum ShaPlatform
{
    SHA_PLATFORM_1              = 6099900,
    SHA_PLATFORM_2_1            = 6099901,
    SHA_PLATFORM_2_2            = 6099902,
    SHA_PLATFORM_3              = 6099903
};

uint32 platformSpell[3] =
{
    SPELL_OMINOUS_CACKLE_P_1,
    SPELL_OMINOUS_CACKLE_P_2,
    SPELL_OMINOUS_CACKLE_P_3
};

uint32 platformNpc[3] =
{
    NPC_YANG_GUOSHI,
    NPC_CHENG_KANG,
    NPC_JINLUN_KUN
};

Position const centrPos = {-1017.83f, -2771.98f, 38.65f, 4.70f};

Position const dspos[2] = 
{
    {-1054.36f, -2783.48f, 38.2692f},
    {-981.31f,  -2782.95f, 38.2682f},
};

Position const platNpcPos[3] =
{
    {-1214.79f, -2824.82f, 41.24f, 3.50f},
    {-1075.20f, -2577.82f, 15.85f, 1.74f},
    {-832.07f,  -2745.41f, 31.67f, 0.15f}
};

float const minpullpos = -2847.0258f;

bool CheckLeiShi(InstanceScript* instance, Creature* caller)
{
    if (instance && caller)
    {
        if (Creature* ls = caller->GetCreature(*caller, instance->GetData64(NPC_LEI_SHI)))
        {
            if (ls->IsAlive())
                return true;
        }
    }
    return false;
}

class boss_sha_of_fear : public CreatureScript
{
    public:
        boss_sha_of_fear() : CreatureScript("boss_sha_of_fear") {}

        struct boss_sha_of_fearAI : public BossAI
        {
            boss_sha_of_fearAI(Creature* creature) : BossAI(creature, DATA_SHA_OF_FEAR)
            {
                instance = creature->GetInstanceScript();
                if (instance)
                {
                    if (CheckLeiShi(instance, me))
                    {
                        me->SetVisible(false);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                    }
                }
                SetCombatMovement(false);
            }

            InstanceScript* instance;
            uint32 checkvictim;
            uint8 currentPlatform;

            void Reset()
            {
                _Reset();
                DoCast(me, SPELL_ZERO_REGEN, true);
                DoCast(me, SPELL_PLR_TELEPORT, true);
                me->SetReactState(REACT_DEFENSIVE);
                me->setPowerType(POWER_ENERGY);
                me->SetPower(POWER_ENERGY, 0);
                checkvictim = 0;
                currentPlatform = 0;

                me->SummonCreature(NPC_PURE_LIGHT_TERRACE, centrPos);
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
                checkvictim = 1500;
                DoCast(me, SPELL_THRASH_PROC, true);
                DoCast(me, SPELL_CUSTOM_REGEN, true);
                DoCast(me, SPELL_PLR_TELEPORT, true);
                events.ScheduleEvent(EVENT_DREAD_SPAWN, 30000);
                events.ScheduleEvent(EVENT_SKULL, 8000);
                events.ScheduleEvent(EVENT_CHECKPOWER, 1000);
                events.ScheduleEvent(EVENT_OMINOUS_CACKLE, 40000);
            }

            bool CheckPullPlayerPos(Unit* who)
            {
                if (!who->ToPlayer() || who->GetPositionY() < minpullpos)
                    return false;

                return true;
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                DoCast(me, SPELL_PLR_TELEPORT, true);
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
            {
                switch (summon->GetEntry())
                {
                    case NPC_YANG_GUOSHI:
                    case NPC_CHENG_KANG:
                    case NPC_JINLUN_KUN:
                        me->SummonCreature(NPC_RETURN_TERRACE, summon->GetPositionX(), summon->GetPositionY(), summon->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN, 60000);
                        break;
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (checkvictim && instance)
                {
                    if (checkvictim <= diff)
                    {
                        if (me->getVictim())
                        {
                            if (!me->IsWithinMeleeRange(me->getVictim()))
                                if (Unit* pTarget = SelectTarget(SELECT_TARGET_FARTHEST, 0, 0.0f, true))
                                    DoCast(pTarget, SPELL_REACHING_ATTACK);

                            if (!CheckPullPlayerPos(me->getVictim()))
                            {
                                me->AttackStop();
                                me->SetReactState(REACT_PASSIVE);
                                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                                EnterEvadeMode();
                                checkvictim = 0;
                            }
                            else
                                checkvictim = 1500;
                        }
                    }
                    else
                        checkvictim -= diff;
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventid = events.ExecuteEvent())
                {
                    switch (eventid)
                    {
                        case EVENT_CHECKPOWER:
                            if (me->GetPower(POWER_ENERGY) == 100 && !me->HasAura(SPELL_BREATH_OF_FEAR))
                                DoCast(SPELL_BREATH_OF_FEAR);
                            events.ScheduleEvent(EVENT_CHECKPOWER, 1000);
                            break;
                        case EVENT_SKULL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                                DoCast(target, SPELL_EERIE_SKULL);
                            events.ScheduleEvent(EVENT_SKULL, 6000);
                            break;
                        case EVENT_DREAD_SPAWN:
                            for (uint8 n = 0; n < 2; n++)
                            {
                                if (Creature* ds = me->SummonCreature(NPC_TERROR_SPAWN, dspos[n]))
                                    ds->AI()->DoZoneInCombat(ds, 100.0f);
                            }
                            events.ScheduleEvent(EVENT_DREAD_SPAWN, 60000);
                            break;
                        case EVENT_OMINOUS_CACKLE:
                        {
                            summons.DespawnEntry(platformNpc[currentPlatform]);
                            me->SummonCreature(platformNpc[currentPlatform], platNpcPos[currentPlatform]);
                            DoCast(platformSpell[currentPlatform]);
                            currentPlatform++;
                            if (currentPlatform > 2)
                                currentPlatform = 0;
                            events.ScheduleEvent(EVENT_OMINOUS_CACKLE, 90000); //1.30
                            break;
                        }
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_sha_of_fearAI(creature);
        }
};

//60788
class npc_sha_of_fear_pure_light_terrace : public CreatureScript
{
    public:
        npc_sha_of_fear_pure_light_terrace() : CreatureScript("npc_sha_of_fear_pure_light_terrace") {}

        struct npc_sha_of_fear_pure_light_terraceAI : public ScriptedAI
        {
            npc_sha_of_fear_pure_light_terraceAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->setFaction(14);
            }

            EventMap events;

            void Reset(){}

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                damage = 0;
            }

            void IsSummonedBy(Unit* summoner)
            {
                DoCast(me, 117865, true); //Light Wall - Scale tank
                DoCast(me, 117770, true); //Light Wall - Visual?
                
                events.ScheduleEvent(EVENT_1, 1000);
            }

            void UpdateAI(uint32 diff) 
            {
                events.Update(diff);

                while (uint32 eventid = events.ExecuteEvent())
                {
                    switch (eventid)
                    {
                        case EVENT_1:
                            if (Unit* player = me->SelectNearestPlayer(5.0f))
                            {
                                if (player->HasAura(117866) && !me->HasAura(107141))
                                    DoCast(me, 107141, true); //Light Wall - Visual Wall + Damage mod raid
                            }
                            else
                                me->RemoveAurasDueToSpell(107141);
                            events.ScheduleEvent(EVENT_1, 1000);
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_fear_pure_light_terraceAI(creature);
        }
};

//61034
class npc_sha_of_fear_terror_spawn : public CreatureScript
{
    public:
        npc_sha_of_fear_terror_spawn() : CreatureScript("npc_sha_of_fear_terror_spawn") {}

        struct npc_sha_of_fear_terror_spawnAI : public ScriptedAI
        {
            npc_sha_of_fear_terror_spawnAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            }

            InstanceScript* pInstance;
            EventMap events;

            void Reset()
            {
                DoCast(me, SPELL_DARK_BULWARK, true);
            }

            void IsSummonedBy(Unit* summoner)
            {
                DoZoneInCombat(me, 100.0f);
            }

            void EnterCombat(Unit* attacker)
            {
                events.ScheduleEvent(EVENT_BOLT, 3000);
            }

            void DamageTaken(Unit* attacker, uint32 &damage)
            {
                if (me->isInFront(attacker))
                    damage = 0; 
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
                    if (eventId == EVENT_BOLT)
                    {
                        DoCast(SPELL_PENETRATING_BOLT);
                        events.ScheduleEvent(EVENT_BOLT, 3000);
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_fear_terror_spawnAI(creature);
        }
};

//61003 - Heroic
class npc_sha_of_fear_dread_spawn : public CreatureScript
{
    public:
        npc_sha_of_fear_dread_spawn() : CreatureScript("npc_sha_of_fear_dread_spawn") {}

        struct npc_sha_of_fear_dread_spawnAI : public ScriptedAI
        {
            npc_sha_of_fear_dread_spawnAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;

            void Reset(){}
            
            void EnterCombat(Unit* attacker) {}

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_fear_dread_spawnAI(creature);
        }
};

//61038, 61042, 61046
class npc_sha_of_fear_platform_defenders : public CreatureScript
{
    public:
        npc_sha_of_fear_platform_defenders() : CreatureScript("npc_sha_of_fear_platform_defenders") {}

        struct npc_sha_of_fear_platform_defendersAI : public ScriptedAI
        {
            npc_sha_of_fear_platform_defendersAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
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
                SetCombatMovement(false);
            }

            InstanceScript* pInstance;
            EventMap events;
            uint8 healthPct;

            void Reset()
            {
                DoCast(me, SPELL_SHA_CORRUPTION_VIS, true);
                healthPct = 96;
            }
            
            void EnterCombat(Unit* attacker) 
            {
                //events.ScheduleEvent(EVENT_1, 10000); //33:40
                events.ScheduleEvent(EVENT_2, 30000);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                if (me->HealthBelowPct(healthPct))
                {
                    healthPct -= 4;
                    DoCast(me, SPELL_SHA_GLOBE, true);
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
                            DoCast(me, SPELL_DREAD_SPRAY, true);
                            events.ScheduleEvent(EVENT_1, 10000);
                            break;
                        case EVENT_2:
                            DoCast(SPELL_DEATH_BLOSSOM);
                            events.ScheduleEvent(EVENT_2, 30000);
                            break;
                    }
                }
                DoSpellAttackIfReady(SPELL_SHOOT);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_fear_platform_defendersAI(creature);
        }
};

//65691
class npc_sha_of_fear_sha_globe : public CreatureScript
{
    public:
        npc_sha_of_fear_sha_globe() : CreatureScript("npc_sha_of_fear_sha_globe") {}

        struct npc_sha_of_fear_sha_globeAI : public ScriptedAI
        {
            npc_sha_of_fear_sha_globeAI(Creature* creature) : ScriptedAI(creature)
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
                me->SetReactState(REACT_PASSIVE);
            }

            EventMap events;
            uint8 healthPct;

            void Reset()
            {
                DoCast(me, 129187, true); //Sha Globe periodic
                events.ScheduleEvent(EVENT_1, 8000);
            }

            void SpellHitTarget(Unit* target, const SpellInfo* spell)
            {
                if (spell->Id == 129189)
                {
                    events.Reset();
                    me->RemoveAllAuras();
                    me->DespawnOrUnsummon(500);
                }
            }

            void UpdateAI(uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_1)
                    {
                        if (me->ToTempSummon())
                            if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                            {
                                DoCast(summoner, 129190, true);
                                me->RemoveAllAuras();
                                me->DespawnOrUnsummon(500);
                            }
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_sha_of_fear_sha_globeAI(creature);
        }
};

//117866
class ExactDistanceCheck
{
    public:
        ExactDistanceCheck(Unit* source, float dist) : _source(source), _dist(dist) {}

        bool operator()(WorldObject* unit)
        {
            return _source->GetExactDist2d(unit) > _dist;
        }

    private:
        Unit* _source;
        float _dist;
};

class spell_sha_of_fear_champion_light : public SpellScriptLoader
{
    public:
        spell_sha_of_fear_champion_light() : SpellScriptLoader("spell_sha_of_fear_champion_light") { }

        class spell_sha_of_fear_champion_light_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_fear_champion_light_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targetList)
            {
                targetList.remove_if(ExactDistanceCheck(GetCaster(), 5.0f * GetCaster()->GetFloatValue(OBJECT_FIELD_SCALE_X)));
                if (targetList.empty() || !GetCaster())
                    return;

                for (std::list<WorldObject*>::iterator itr = targetList.begin(); itr != targetList.end(); ++itr)
                    if (Player* plr = (*itr)->ToPlayer())
                        if (plr->HasAura(117866))
                            targetList.push_front(plr);

                if (targetList.size() > 1)
                    targetList.resize(1);
            }

            void HandleOnHit()
            {
                if (Unit* pTarget = GetHitUnit())
                    if (InstanceScript* pInstance = pTarget->GetInstanceScript())
                        if (Creature* sha = pInstance->instance->GetCreature(pInstance->GetData64(NPC_SHA_OF_FEAR)))
                        {
                            if (sha->getVictim())
                                if (pTarget == sha->getVictim())
                                    return;
                            sha->getThreatManager().resetAllAggro();
                            sha->TauntApply(pTarget);
                            sha->AddThreat(pTarget, 100000.0f);
                        }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_of_fear_champion_light_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnHit += SpellHitFn(spell_sha_of_fear_champion_light_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_fear_champion_light_SpellScript();
        }
};

//131993
class spell_sha_of_fear_thrash : public SpellScriptLoader
{
    public:
        spell_sha_of_fear_thrash() : SpellScriptLoader("spell_sha_of_fear_thrash") { }

        class spell_sha_of_fear_thrash_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_of_fear_thrash_AuraScript);

            uint8 procCount;

            bool Load()
            {
                procCount = 0;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                Unit* caster = GetCaster();
                if (!caster)
                    return;

                procCount++;

                switch (procCount)
                {
                    case 3:
                        caster->CastSpell(caster, 131996, true);  //THRASH_WARNING
                        break;
                    case 4:
                        caster->CastSpell(caster, 131994, true);  //THRASH_EXTRA
                        break;
                    case 5:
                        caster->RemoveAurasDueToSpell(131996);    //Remove THRASH_WARNING
                        break;
                }
                if (procCount > 5)
                    procCount = 0;
            }

            void Register()
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_of_fear_thrash_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_sha_of_fear_thrash_AuraScript();
        }
};

//119593, 119692, 119693
class spell_sha_of_fear_ominous_cackle : public SpellScriptLoader
{
    public:
        spell_sha_of_fear_ominous_cackle() : SpellScriptLoader("spell_sha_of_fear_ominous_cackle") { }

        class spell_sha_of_fear_ominous_cackleSpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_of_fear_ominous_cackleSpellScript);

            uint8 tankCount;
            uint8 healerCount;
            uint8 damagerCount;
            uint8 hitCount;
            
            bool Load()
            {
                tankCount = 0;
                healerCount = 0;
                damagerCount = 0;
                hitCount = 0;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targetList)
            {
                targetList.remove_if(ExactDistanceCheck(GetCaster(), 60.0f * GetCaster()->GetFloatValue(OBJECT_FIELD_SCALE_X)));
                if (targetList.empty())
                    return;

                Creature* sha = GetCaster()->ToCreature();
                if (!sha)
                    return;

                std::list<WorldObject*> tempPlr;
                for (std::list<WorldObject*>::iterator itr = targetList.begin(); itr != targetList.end(); ++itr)
                {
                    if (Player* plr = (*itr)->ToPlayer())
                    {
                        uint8 role = plr->GetRoleForGroup(plr->GetSpecializationId(plr->GetActiveSpec()));
                        switch (role)
                        {
                            case ROLES_TANK:
                                if (tankCount == 1)
                                {
                                    if (Unit* pTank = sha->AI()->SelectTarget(SELECT_TARGET_TOPAGGRO))
                                        if (sha->GetDistance(pTank) < 80.0f)
                                            tempPlr.push_front(pTank);
                                }
                                tankCount++;
                                break;
                            case ROLES_HEALER:
                                if (healerCount == 0)
                                    tempPlr.push_front(*itr);
                                healerCount++;
                                break;
                            case ROLES_DPS:
                                if (damagerCount < 3)
                                    tempPlr.push_front(*itr);
                                damagerCount++;
                                break;
                        }
                    }
                }
                targetList.clear();

                if (tempPlr.size() < 2)
                    tempPlr.clear();

                if (tempPlr.empty())
                    return;

                for (std::list<WorldObject*>::const_iterator itr = tempPlr.begin(); itr != tempPlr.end(); ++itr)
                    targetList.push_back((*itr));
            }

            void HandleOnHit()
            {
                return; // crashed http://pastebin.com/ZpyUb4WG

                Unit* target = GetHitUnit();
                if (!target || !target->IsAlive() || !target->IsInWorld())
                    return;

                target->CastSpell(target, 129147, true);

                switch (GetSpellInfo()->Id)
                {
                    case 119593:
                        target->GetMotionMaster()->MovePath(SHA_PLATFORM_1, false, false);
                        break;
                    case 119692:
                        target->GetMotionMaster()->MovePath(urand(SHA_PLATFORM_2_1, SHA_PLATFORM_2_2), false, false);
                        break;
                    case 119693:
                        target->GetMotionMaster()->MovePath(SHA_PLATFORM_3, false, false);
                        break;
                }
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_of_fear_ominous_cackleSpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnHit += SpellHitFn(spell_sha_of_fear_ominous_cackleSpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sha_of_fear_ominous_cackleSpellScript();
        }
};

//129147
class spell_sha_of_fear_ominous_cackle_controll : public SpellScriptLoader
{
    public:
        spell_sha_of_fear_ominous_cackle_controll() : SpellScriptLoader("spell_sha_of_fear_ominous_cackle_controll") { }

        class spell_sha_of_fear_ominous_cackle_controll_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_of_fear_ominous_cackle_controll_AuraScript);

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                if (GetTarget()->GetTypeId() == TYPEID_PLAYER)
                    GetTarget()->ToPlayer()->SetClientControl(GetTarget(), 0);
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (!GetTarget())
                    return;

                if (GetTarget()->GetTypeId() == TYPEID_PLAYER)
                    GetTarget()->ToPlayer()->SetClientControl(GetTarget(), 1);
            }
            
            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_sha_of_fear_ominous_cackle_controll_AuraScript::OnApply, EFFECT_3, SPELL_AURA_321, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_sha_of_fear_ominous_cackle_controll_AuraScript::OnRemove, EFFECT_3, SPELL_AURA_321, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_sha_of_fear_ominous_cackle_controll_AuraScript();
        }
};

void AddSC_boss_sha_of_fear()
{
    new boss_sha_of_fear();
    new npc_sha_of_fear_pure_light_terrace();
    new npc_sha_of_fear_terror_spawn();
    new npc_sha_of_fear_dread_spawn();
    new npc_sha_of_fear_platform_defenders();
    new npc_sha_of_fear_sha_globe();
    new spell_sha_of_fear_champion_light();
    new spell_sha_of_fear_thrash();
    new spell_sha_of_fear_ominous_cackle();
    new spell_sha_of_fear_ominous_cackle_controll();
}
