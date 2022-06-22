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
#include "shadopan_monastery.h"

enum eSpells
{
    SPELL_CORRUPTED                 = 131530,

    SPELL_RISING_HATE               = 107356,
    SPELL_RING_OF_MALICE            = 131521,
    SPELL_SHA_BLAST                 = 114999,
    SPELL_SUMMON_GRIPPING_HATRED    = 115002,

    // Gripping Hatred
    SPELL_GRIP_OF_HATE              = 115010,
    SPELL_POOL_OF_SHADOWS           = 112929,
    
    SPELL_ACHIEV_CREDIT             = 123095,
};

enum eEvents
{
    EVENT_RISING_HATE               = 1,
    EVENT_RING_OF_MALICE            = 2,
    EVENT_SHA_BLAST                 = 3,
    EVENT_SUMMON_GRIPPING_HATRED    = 4,

    EVENT_GRIP_OF_HATE              = 5,
};

//56884
class boss_taran_zhu : public CreatureScript
{
    public:
        boss_taran_zhu() : CreatureScript("boss_taran_zhu") {}

        struct boss_taran_zhuAI : public BossAI
        {
            boss_taran_zhuAI(Creature* creature) : BossAI(creature, DATA_TARAN_ZHU)
            {
                pInstance = creature->GetInstanceScript();
                me->AddAura(SPELL_CORRUPTED, me);
            }

            InstanceScript* pInstance;
            bool done;
            std::set<uint64>hatredpllist;

            void Reset()
            {
                _Reset();
                done = false;
                summons.DespawnAll();
                hatredpllist.clear();
            }

            void EnterCombat(Unit*who)
            {
                if (instance)
                    instance->SetBossState(DATA_TARAN_ZHU, IN_PROGRESS);

                events.ScheduleEvent(EVENT_RISING_HATE,             urand(25000, 35000));
                events.ScheduleEvent(EVENT_RING_OF_MALICE,          urand(7500,  12500));
                events.ScheduleEvent(EVENT_SHA_BLAST,               urand(2500,  5000));
                events.ScheduleEvent(EVENT_SUMMON_GRIPPING_HATRED,  urand(10000, 15000));
            }

            void SetGUID(uint64 guid, int32 Id)
            {
                hatredpllist.insert(guid);
            }

            void DamageDealt(Unit* target, uint32& damage, DamageEffectType damageType)
            {
                if (Player* player = target->ToPlayer())
                {
                    uint32 newPower = player->GetPower(POWER_ALTERNATE_POWER) + urand(1, 2);
                    player->SetPower(POWER_ALTERNATE_POWER, newPower >= 60 ? 60 : newPower);
                }
            }

            void HateLeadstoSuffering()
            {
                if (!me->GetMap()->IsHeroic())
                    return;

                if (hatredpllist.empty())
                    return;

                std::list<Player*>pllist;
                GetPlayerListInGrid(pllist, me, 100.0f);

                if (pllist.empty())
                    return;

                for (std::list<Player*>::const_iterator Itr = pllist.begin(); Itr != pllist.end(); ++Itr)
                    for (std::set<uint64>::const_iterator itr = hatredpllist.begin(); itr != hatredpllist.end(); ++itr)
                        if (Player* hplr = me->GetPlayer(*me, *itr))
                            if (hplr->GetGUID() != (*Itr)->GetGUID())
                                return;

                for (std::list<Player*>::const_iterator _Itr = pllist.begin(); _Itr != pllist.end(); ++_Itr)
                    if (AchievementEntry const* achievementEntry = sAchievementStore.LookupEntry(6471))
                        if (!(*_Itr)->HasAchieved(6471))
                            (*_Itr)->CompletedAchievement(achievementEntry);
            }

            void DamageTaken(Unit* who, uint32& damage)
            {
                if (damage >= me->GetHealth() && !done)
                {
                    done = true;
                    damage = 0;

                    HateLeadstoSuffering();

                    if (instance)
                        instance->SetBossState(DATA_TARAN_ZHU, DONE);

                    me->setFaction(35);
                    me->SetFullHealth();
                    me->RemoveAurasDueToSpell(SPELL_CORRUPTED);
                    DoCast(SPELL_ACHIEV_CREDIT);
                    me->GetMap()->UpdateEncounterState(ENCOUNTER_CREDIT_CAST_SPELL, SPELL_ACHIEV_CREDIT, me);
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch(events.ExecuteEvent())
                {
                    case EVENT_RISING_HATE:
                        me->CastSpell(me, SPELL_RISING_HATE, false);
                        events.ScheduleEvent(EVENT_RISING_HATE, urand(10000, 15000));
                        break;
                    case EVENT_RING_OF_MALICE:
                        me->CastSpell(me, SPELL_RING_OF_MALICE, true);
                        events.ScheduleEvent(EVENT_SHA_BLAST,  urand(2000, 4000));
                        events.ScheduleEvent(EVENT_RING_OF_MALICE, urand(27500, 32500));
                        break;
                    case EVENT_SHA_BLAST:
                        if (!me->HasAura(SPELL_RING_OF_MALICE))
                            break;

                        if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 0, true))
                            me->CastSpell(target, SPELL_SHA_BLAST, false);
                        
                        events.ScheduleEvent(EVENT_SHA_BLAST,  urand(2500, 5000));
                        break;
                    case EVENT_SUMMON_GRIPPING_HATRED:
                        me->CastSpell(me, SPELL_SUMMON_GRIPPING_HATRED, false);
                        events.ScheduleEvent(EVENT_SUMMON_GRIPPING_HATRED,  urand(20000, 30000));
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_taran_zhuAI(creature);
        }
};

class npc_gripping_hatred : public CreatureScript
{
public:
    npc_gripping_hatred() : CreatureScript("npc_gripping_hatred") { }

    struct npc_gripping_hatredAI : public ScriptedAI
    {
        npc_gripping_hatredAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset()
        {
            me->SetReactState(REACT_PASSIVE);
            me->CastSpell(me, SPELL_POOL_OF_SHADOWS, true);
        }

        void UpdateAI(uint32 diff)
        {
            if (!me->HasUnitState(UNIT_STATE_CASTING))
                me->CastSpell(me, SPELL_GRIP_OF_HATE, false);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_gripping_hatredAI (creature);
    }
};

class spell_taran_zhu_hate : public SpellScriptLoader
{
    public:
        spell_taran_zhu_hate() : SpellScriptLoader("spell_taran_zhu_hate") { }

        class spell_taran_zhu_hate_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_taran_zhu_hate_AuraScript);

            void HandlePeriodic(AuraEffect const* /*aurEff*/)
            {
                if (Unit* target = GetTarget())
                {
                    if (target->GetPower(POWER_ALTERNATE_POWER) >= 60)
                    {
                        if (!target->HasAura(SPELL_HAZE_OF_HATE))
                        {
                            target->CastSpell(target, SPELL_HAZE_OF_HATE, true);
                            target->CastSpell(target, SPELL_HAZE_OF_HATE_VISUAL, true);

                            if (InstanceScript* instance = target->GetInstanceScript())
                                if (Creature* TaranZhu = target->GetCreature(*target, instance->GetData64(NPC_TARAN_ZHU)))
                                    TaranZhu->AI()->SetGUID(target->GetGUID(), 1);
                        }
                    }
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_taran_zhu_hate_AuraScript::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_taran_zhu_hate_AuraScript();
        }
};

class spell_taran_zhu_meditation : public SpellScriptLoader
{
    public:
        spell_taran_zhu_meditation() : SpellScriptLoader("spell_taran_zhu_meditation") { }

        class spell_taran_zhu_meditation_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_taran_zhu_meditation_AuraScript);

            void OnRemove(AuraEffect const*, AuraEffectHandleModes)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                {
                    if (Unit* target = GetTarget())
                    {
                        target->SetPower(POWER_ALTERNATE_POWER, 0);
                        target->RemoveAurasDueToSpell(SPELL_HAZE_OF_HATE);
                        target->RemoveAurasDueToSpell(SPELL_HAZE_OF_HATE_VISUAL);
                    }
                }
            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_taran_zhu_meditation_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_taran_zhu_meditation_AuraScript();
        }
};

class spell_taran_zhu_grip_of_hate : public SpellScriptLoader
{
    public:
        spell_taran_zhu_grip_of_hate() : SpellScriptLoader("spell_taran_zhu_grip_of_hate") { }

        class spell_taran_zhu_grip_of_hate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_taran_zhu_grip_of_hate_SpellScript);

            void HandleScriptEffect(SpellEffIndex effIndex)
            {
                if (Unit* caster = GetCaster())
                    if (Unit* target = GetHitUnit())
                        target->CastSpell(caster, GetSpellInfo()->Effects[effIndex]->BasePoints, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_taran_zhu_grip_of_hate_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_taran_zhu_grip_of_hate_SpellScript();
        }
};

void AddSC_boss_taran_zhu()
{
    new boss_taran_zhu();
    new npc_gripping_hatred();
    new spell_taran_zhu_hate();
    new spell_taran_zhu_meditation();
    new spell_taran_zhu_grip_of_hate();
}
