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
    //All
    SPELL_SHA_CORRUPTION                = 117052,
    //Kaolan
    SPELL_TOUCH_OF_SHA                  = 117519,
    SPELL_DEFILED_GROUND                = 117986,
    SPELL_EXPEL_CORRUPTION              = 117975,
    //Regail
    SPELL_LIGHTNING_BOLT                = 117187,
    SPELL_OVERWHELMING_CORRUPTION       = 117351,
    SPELL_OVERWHELMING_CORRUPTION_TR_EF = 117353,
    SPELL_LIGHTNING_PRISON              = 111850,
    SPELL_LIGHTNING_STORM               = 118077,
    //Asani
    SPELL_WATER_BOLT                    = 118312,
    SPELL_CLEANSING_WATERS              = 117309,
    SPELL_CORRUPTED_WATERS              = 117227,
    
    //Asani - Cleansing Waters
    SPELL_CLEANSING_WATERS_VISUAL_1     = 117250,
    SPELL_CLEANSING_WATERS_VISUAL_2     = 117268,
    SPELL_CLEANSING_WATERS_HEAL         = 117283,
    
    //Asani - Corrupted Waters
    SPELL_CORRUPTED_WATERS_NEG_BUFF     = 117217,
    SPELL_PURIFIED                      = 117235,
};

enum eEvents
{
    //Kaolan
    EVENT_TOUCH_OF_SHA                  = 1,
    EVENT_DEFILED_GROUND                = 2,
    EVENT_EXPEL_CORRUPTION              = 3,
    //Regail
    EVENT_LIGHTNING_BOLT                = 4,
    EVENT_LIGHTNING_PRISON              = 5,
    EVENT_LIGHTNING_STORM               = 6,
    EVENT_LIGHTNING_STORM_2             = 7,
    //Asani
    EVENT_WATER_BOLT                    = 8,
    EVENT_CLEANSING_WATERS              = 9,
    EVENT_CORRUPTED_WATERS              = 10,
};

uint32 protectorsEntry[3] =
{
    NPC_PROTECTOR_KAOLAN,
    NPC_ELDER_REGAIL,
    NPC_ELDER_ASANI,
};

struct generic_boss_protectorsAI : ScriptedAI
{
    generic_boss_protectorsAI(Creature* creature) : ScriptedAI(creature){}

    void ResetBosses(InstanceScript* instance, Creature* caller, uint32 callerEntry)
    {
        if (caller && instance)
        {
            for (uint8 n = 0; n < 3; n++)
            {
                if (Creature* protector = caller->GetCreature(*caller, instance->GetData64(protectorsEntry[n])))
                {
                    if (protector->GetEntry() != callerEntry)
                    {
                        if (!protector->IsAlive())
                        {
                            protector->Respawn();
                            protector->GetMotionMaster()->MoveTargetedHome();
                        }
                        else if (protector->IsAlive() && protector->isInCombat())
                            protector->AI()->EnterEvadeMode();
                    }
                }
            }
        }
    }

    void CallBosses(InstanceScript* instance, Creature* caller, uint32 callerEntry)
    {
        if (caller && instance)
        {
            for (uint8 n = 0; n < 3; n++)
            {
                if (Creature* protector = caller->GetCreature(*caller, instance->GetData64(protectorsEntry[n])))
                {
                    if (protector->GetEntry() != callerEntry)
                    {
                        if (protector->IsAlive() && !protector->isInCombat())
                            protector->AI()->DoZoneInCombat(protector, 150.0f);
                    }
                }
            }
        }
    }

    void CallDieControl(InstanceScript* instance, Creature* caller, uint32 callerEntry)
    {
        if (caller && instance)
        {
            for (uint8 n = 0; n < 3; n++)
            {
                if (Creature* protector = caller->GetCreature(*caller, instance->GetData64(protectorsEntry[n])))
                {
                    if (protector->GetEntry() != callerEntry)
                    {
                        if (protector->IsAlive())
                        {
                            protector->SetFullHealth();
                            protector->CastSpell(protector, SPELL_SHA_CORRUPTION);
                        }
                    }
                }
            }
            if (callerEntry == NPC_PROTECTOR_KAOLAN)
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_SHA);
        }
    }

    uint8 CalcAliveBosses(InstanceScript* instance, Creature* caller)
    {
        uint8 abossval = 0;

        if (caller && instance)
        {
            for (uint8 n = 0; n < 3; n++)
            {
                if (Creature* protector = caller->GetCreature(*caller, instance->GetData64(protectorsEntry[n])))
                {
                    if (protector->IsAlive())
                        abossval++;
                }
            }
        }
        return abossval;
    }
};

class boss_protectors : public CreatureScript
{
    public:
        boss_protectors() : CreatureScript("boss_protectors") {}

        struct boss_protectorsAI : public generic_boss_protectorsAI
        {
            boss_protectorsAI(Creature* creature) : generic_boss_protectorsAI(creature), summons(me)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            SummonList summons;
            EventMap events;

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
                me->SetReactState(REACT_DEFENSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->RemoveAurasDueToSpell(SPELL_SHA_CORRUPTION);
                me->RemoveAurasDueToSpell(SPELL_OVERWHELMING_CORRUPTION);
                if (instance)
                {
                    ResetBosses(instance, me, me->GetEntry());
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOUCH_OF_SHA);
                    instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_OVERWHELMING_CORRUPTION_TR_EF);
                }
            }

            void EnterCombat(Unit* who)
            {
                if (instance)
                    CallBosses(instance, me, me->GetEntry());

                switch (me->GetEntry())
                {
                    case NPC_PROTECTOR_KAOLAN:
                        events.ScheduleEvent(EVENT_TOUCH_OF_SHA, 30000);
                        break;
                    case NPC_ELDER_REGAIL:
                        events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 2000);
                        events.ScheduleEvent(EVENT_LIGHTNING_PRISON, 25000);
                        break;
                    case NPC_ELDER_ASANI:
                        events.ScheduleEvent(EVENT_WATER_BOLT, 2000);
                        events.ScheduleEvent(EVENT_CLEANSING_WATERS, 30000);
                        break;
                }
            }

            void SpellHit(Unit* caster, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_SHA_CORRUPTION)
                {
                    if (me->HasAura(SPELL_SHA_CORRUPTION))//for safe
                    {
                        if (uint8 stack = me->GetAura(SPELL_SHA_CORRUPTION)->GetStackAmount())
                        {
                            switch (me->GetEntry())
                            {
                            case NPC_PROTECTOR_KAOLAN:
                                {
                                    switch (stack)
                                    {
                                        case 1:
                                            events.ScheduleEvent(EVENT_DEFILED_GROUND, 4000);
                                            break;
                                        case 2:
                                            events.ScheduleEvent(EVENT_EXPEL_CORRUPTION, 6000);
                                            break;
                                        default:
                                            break;
                                    }
                                }
                                break;
                            case NPC_ELDER_REGAIL:
                                {
                                    switch (stack)
                                    {
                                        case 1:
                                            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 30000);
                                            break;
                                        case 2:
                                            me->AddAura(SPELL_OVERWHELMING_CORRUPTION, me);
                                            break;
                                        default:
                                            break;
                                    }
                                }
                                break;
                            case NPC_ELDER_ASANI:
                                {
                                    switch (stack)
                                    {
                                        case 1:
                                            events.ScheduleEvent(EVENT_CORRUPTED_WATERS, 14000);
                                            break;
                                        case 2:
                                            me->AddAura(SPELL_OVERWHELMING_CORRUPTION, me);
                                            break;
                                        default:
                                            break;
                                    }
                                }
                                break;
                            }
                        }
                    }
                }
            }

            void SetProtectorsDone()
            {
                  Map::PlayerList const& players = me->GetMap()->GetPlayers();
                  if (!players.isEmpty())
                  {
                      for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                      {
                          if (Player* pPlayer = itr->getSource())
                              me->GetMap()->ToInstanceMap()->PermBindAllPlayers(pPlayer);
                      }
                  }
                  
                  if (Creature* tsulong = me->GetCreature(*me, instance->GetData64(NPC_TSULONG)))
                  {
                      tsulong->SetVisible(true);
                      tsulong->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                  }
            }

            void DamageTaken(Unit* attacker, uint32 &damage)
            {
                if (instance)
                {
                    if (damage >= me->GetHealth())
                    {
                        CallDieControl(instance, me, me->GetEntry());
                        if (CalcAliveBosses(instance, me) > 1) //Only last boss must be looted
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        else if (CalcAliveBosses(instance, me) == 1) //last boss died - active tsulong
                            SetProtectorsDone();
                    }
                }
            }

            void JustDied(Unit* killer)
            {
                summons.DespawnAll();

                if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE))
                    me->RemoveFlag(OBJECT_FIELD_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);

                switch (summon->GetEntry())
                {
                    case 60906:
                        summon->SetReactState(REACT_PASSIVE);
                        summon->CastSpell(summon, 117989, true); //AOE dmg
                        break;
                    case 60886:
                        summon->SetReactState(REACT_PASSIVE);
                        summon->CastSpell(summon, 117943, true); //AOE dmg
                        break;
                }
            }

            void CheckFriendlyLowHp()
            {
                Creature* targetA = instance->instance->GetCreature(instance->GetData64(NPC_PROTECTOR_KAOLAN));
                Creature* targetB = instance->instance->GetCreature(instance->GetData64(NPC_ELDER_REGAIL));
                if (!targetA || !targetB)
                    return;

                Unit* target = NULL;
                if (targetA->IsAlive() && targetB->IsAlive())
                    target = targetA->GetHealthPct() < targetB->GetHealthPct() ? targetA : targetB;

                else if (!targetA->IsAlive() && !targetB->IsAlive())
                    target = me;
                else if (!targetA->IsAlive() || !targetB->IsAlive())
                    target = targetA->IsAlive() ? targetA : targetB;

                if (target)
                    DoCast(target, SPELL_CLEANSING_WATERS);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventid = events.ExecuteEvent())
                {
                    switch (eventid)
                    {
                        case EVENT_TOUCH_OF_SHA:
                            {
                                Map* pMap = me->GetMap();
                                if (pMap && pMap->IsDungeon())
                                {
                                    Map::PlayerList const &players = pMap->GetPlayers();
                                    for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
                                    {
                                        if (Player* pPlayer = i->getSource())
                                        {
                                            if (pPlayer->IsAlive() && !pPlayer->HasAura(SPELL_TOUCH_OF_SHA))
                                            {
                                                DoCast(pPlayer, SPELL_TOUCH_OF_SHA);
                                                break;
                                            }
                                        }
                                    }
                                }
                                events.ScheduleEvent(EVENT_TOUCH_OF_SHA, 28000);
                                break;
                            }
                        case EVENT_LIGHTNING_BOLT:
                            if (me->getVictim())
                                DoCast(me->getVictim(), SPELL_LIGHTNING_BOLT);
                            events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 20000);
                            break;
                        case EVENT_WATER_BOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                                DoCast(target, SPELL_WATER_BOLT);
                            events.ScheduleEvent(EVENT_WATER_BOLT, 2000);
                            break;
                        case EVENT_LIGHTNING_PRISON:
                            DoCast(SPELL_LIGHTNING_PRISON);
                            events.ScheduleEvent(EVENT_LIGHTNING_PRISON, 25000);
                            break;
                        case EVENT_LIGHTNING_STORM:
                            DoStopAttack();
                            DoCast(SPELL_LIGHTNING_STORM);
                            events.ScheduleEvent(EVENT_LIGHTNING_STORM, 40000);
                            events.ScheduleEvent(EVENT_LIGHTNING_STORM_2, 12000);
                            break;
                        case EVENT_LIGHTNING_STORM_2:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        case EVENT_CLEANSING_WATERS:
                            CheckFriendlyLowHp();
                            events.ScheduleEvent(EVENT_CLEANSING_WATERS, 30000);
                            break;
                        case EVENT_CORRUPTED_WATERS:
                            DoCast(SPELL_CORRUPTED_WATERS);
                            events.ScheduleEvent(EVENT_CORRUPTED_WATERS, 40000);
                            break;
                        case EVENT_DEFILED_GROUND:
                            if (me->getVictim())
                                DoCast(me->getVictim(), SPELL_DEFILED_GROUND);
                            events.ScheduleEvent(EVENT_DEFILED_GROUND, 16000);
                            break;
                        case EVENT_EXPEL_CORRUPTION:
                            DoCast(SPELL_EXPEL_CORRUPTION);
                            events.ScheduleEvent(EVENT_EXPEL_CORRUPTION, 40000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_protectorsAI(creature);
        }
};

//60646
class npc_asani_cleansing_waters : public CreatureScript
{
    public:
        npc_asani_cleansing_waters() : CreatureScript("npc_asani_cleansing_waters") { }

        struct npc_asani_cleansing_watersAI : public ScriptedAI
        {
            npc_asani_cleansing_watersAI(Creature* creature) : ScriptedAI(creature) 
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetSpeed(MOVE_FLIGHT, 0.5f, true);
            }

            EventMap events;

            void Reset() {}

            void IsSummonedBy(Unit* summoner)
            {
                DoCast(me, SPELL_CLEANSING_WATERS_VISUAL_1, true);
                me->CastSpell(me, SPELL_CLEANSING_WATERS_VISUAL_2);
                events.ScheduleEvent(EVENT_1, 2000);
            }

            void UpdateAI(uint32 diff) 
            {
                events.Update(diff);

                while (uint32 eventid = events.ExecuteEvent())
                {
                    switch (eventid)
                    {
                        case EVENT_1:
                            DoCast(SPELL_CLEANSING_WATERS_HEAL);
                            me->DespawnOrUnsummon(1000);
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_asani_cleansing_watersAI (creature);
        }
};

//60621
class npc_asani_corrupted_waters : public CreatureScript
{
    public:
        npc_asani_corrupted_waters() : CreatureScript("npc_asani_corrupted_waters") { }

        struct npc_asani_corrupted_watersAI : public ScriptedAI
        {
            npc_asani_corrupted_watersAI(Creature* creature) : ScriptedAI(creature) 
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

            bool stateDied;

            void Reset() {}

            void IsSummonedBy(Unit* summoner)
            {
                stateDied = false;
                DoCast(me, SPELL_CORRUPTED_WATERS_NEG_BUFF, true);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage)
            {
                if (damage >= me->GetHealth())
                {
                    if (!stateDied)
                    {
                        stateDied = true;
                        DoCast(me, SPELL_PURIFIED, true);
                        me->DespawnOrUnsummon(500);
                    }
                    damage = 0;
                }
            }

            void UpdateAI(uint32 diff) {}
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_asani_corrupted_watersAI (creature);
        }
};

//118077
class spell_regail_lightning_storm : public SpellScriptLoader
{
    public:
        spell_regail_lightning_storm() : SpellScriptLoader("spell_regail_lightning_storm") { }

        class spell_regail_lightning_storm_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_regail_lightning_storm_AuraScript);

            uint32 m_checkTimer;

            bool Load()
            {
                m_checkTimer = 0;
                return true;
            }

            void OnUpdate(uint32 diff, AuraEffect* /*aurEff*/)
            {
                Unit* caster = GetCaster();
                if (!caster || m_checkTimer > 12000)
                    return;

                m_checkTimer += diff;

                switch (m_checkTimer)
                {
                    case 1000:
                        caster->CastSpell(caster, 118064, true); //10 yard Visual
                        break;
                    case 3000:
                        caster->CastSpell(caster, 118003, true); //10 yard Dmg
                        caster->CastSpell(caster, 118040, true); //30 yard Visual
                        break;
                    case 5000:
                        caster->CastSpell(caster, 118004, true); //30 yard Dmg
                        caster->CastSpell(caster, 118053, true); //50 yard Visual
                        break;
                    case 7000:
                        caster->CastSpell(caster, 118005, true); //50 yard Dmg
                        caster->CastSpell(caster, 118054, true); //70 yard Visual
                        break;
                    case 9000:
                        caster->CastSpell(caster, 118007, true); //70 yard Dmg
                        caster->CastSpell(caster, 118055, true); //90 yard Visual
                        break;
                    case 12000:
                        caster->CastSpell(caster, 118008, true); //90 yard Dmg
                        break;
                    default:
                        break;
                }
            }

            void Register()
            {
                OnEffectUpdate += AuraEffectUpdateFn(spell_regail_lightning_storm_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_regail_lightning_storm_AuraScript();
        }
};

//117955
class spell_kaolan_expelled_corruption : public SpellScriptLoader
{
    public:
        spell_kaolan_expelled_corruption() : SpellScriptLoader("spell_kaolan_expelled_corruption") { }

        class spell_kaolan_expelled_corruption_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_kaolan_expelled_corruption_SpellScript);

            void HandleScript()
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                float distance = GetHitUnit()->GetExactDist2d(GetCaster());

                SetHitDamage(int32(GetHitDamage() / distance));
            }

            void Register()
            {
                BeforeHit += SpellHitFn(spell_kaolan_expelled_corruption_SpellScript::HandleScript);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_kaolan_expelled_corruption_SpellScript();
        }
};

void AddSC_boss_protectors()
{
    new boss_protectors();
    new npc_asani_cleansing_waters();
    new npc_asani_corrupted_waters();
    new spell_regail_lightning_storm();
    new spell_kaolan_expelled_corruption();
}
