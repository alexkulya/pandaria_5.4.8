#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum eBosses
{
    BOSS_SHA_OF_ANGER,
};

enum eSpells
{
    SPELL_SHADOW_BOLT_ANGER     = 119487,
    SPELL_OVERCOME_BY_ANGER     = 129356,
    SPELL_ENDLESS_RAGE          = 119446,
    SPELL_BITTER_THOUGHTS       = 119601,
    SPELL_BERSERK               = 47008,
    SPELL_DOMINATE_MIND_WARNING = 119622,
    SPELL_DOMINATE_MIND         = 119626,
    SPELL_SEETHE_AURA           = 119487,
    SPELL_BITTER_THOUGHTS_EFF   = 119610,
    SPELL_UNLEASHED_WRATH       = 119488,
};

enum eEvents
{
    EVENT_GROWING_ANGER_WARNING = 1,
    EVENT_GROWING_ANGER         = 2,
    EVENT_UNLEASHED_WRATH       = 3,
    EVENT_BERSERK               = 4,
    EVENT_DESPAWN               = 5,
    EVENT_SPAWN                 = 6,
    EVENT_UPDATE_RAGE           = 7,
    EVENT_RANGE_ATTACK          = 8,
};

enum eCreatures
{
    NPC_SHA_OF_ANGER         = 56439,
    NPC_SHA_OF_ANGER_TRIGGER = 61523,
};

enum eTalk
{
    TALK_INTRO = 0,
    TALK_ANGER = 1,
    TALK_SPAWN = 2,
    TALK_RESET = 3,
    TALK_SLAY  = 4,
    TALK_AGGRO = 5,
};

class boss_sha_of_anger : public CreatureScript
{
    public:
        boss_sha_of_anger() : CreatureScript("boss_sha_of_anger") { }

        struct boss_sha_of_anger_AI : public ScriptedAI
        {
            boss_sha_of_anger_AI(Creature* creature) : ScriptedAI(creature), summons(me) { }

            int _targetCount;
            int _cloudCount;
            int _maxTargetCount;
            uint8 _dominateMindCount;
            uint32 timer;
            bool phase1;
            bool range;
            std::list<uint64> targetedDominationPlayerGuids;
            EventMap events;
            SummonList summons;

            void Reset() override
            {
                SetCombatMovement(false);
                me->SetPowerType(POWER_RAGE);
                me->SetPower(POWER_RAGE, 0);

                me->SetFloatValue(UNIT_FIELD_BOUNDING_RADIUS, 37.0f);
                me->SetFloatValue(UNIT_FIELD_COMBAT_REACH, 37.0f);

                summons.DespawnAll();

                phase1             = true;
                range              = false;
                _dominateMindCount = 2;
                _cloudCount        = 3;
                _targetCount       = 0;
                _maxTargetCount    = 5;
                timer              = 0;

                Talk(TALK_RESET);

                events.Reset();
                events.ScheduleEvent(EVENT_GROWING_ANGER_WARNING, 19000);
                events.ScheduleEvent(EVENT_SPAWN, 8000);
                events.ScheduleEvent(EVENT_UNLEASHED_WRATH, 72000);
                events.ScheduleEvent(EVENT_BERSERK, 900000);
                events.ScheduleEvent(EVENT_UPDATE_RAGE, 4000);

                targetedDominationPlayerGuids.clear();

                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 100.0f);

                for (auto&& itr : playerList)
                    itr->RemoveAura(SPELL_DOMINATE_MIND);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(TALK_SLAY);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                Talk(TALK_AGGRO);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);

                // Clouds
                if (summon->GetEntry() == NPC_SHA_OF_ANGER_TRIGGER)
                {
                    summon->CastSpell(summon, SPELL_BITTER_THOUGHTS, true);
                    summon->DespawnOrUnsummon(60000);
                }
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GROWING_ANGER_WARNING:
                        {
                            Talk(TALK_ANGER);

                            for (uint8 i = 0; i < _dominateMindCount; ++i)
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                {
                                    targetedDominationPlayerGuids.push_back(target->GetGUID());
                                    me->CastSpell(target, SPELL_DOMINATE_MIND_WARNING, true);
                                }
                            }

                            events.ScheduleEvent(EVENT_GROWING_ANGER, 6000);
                            break;
                        }
                        case EVENT_GROWING_ANGER:
                        {
                            for (auto&& guid : targetedDominationPlayerGuids)
                                if (Player* target = ObjectAccessor::GetPlayer(*me, guid))
                                    if (me->GetVictim() || target != me->GetVictim())
                                        me->CastSpell(target, SPELL_DOMINATE_MIND, false);

                            events.ScheduleEvent(EVENT_GROWING_ANGER_WARNING, 19000);
                            break;
                        }
                        case EVENT_SPAWN:
                        {
                            Talk(TALK_SPAWN);

                            for (uint8 i = 0; i < _cloudCount; ++i)
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                    me->CastSpell(target, SPELL_ENDLESS_RAGE, false);

                            events.ScheduleEvent(EVENT_SPAWN, 15000);
                            break;
                        }
                        case EVENT_UPDATE_RAGE:
                        {
                            if (phase1)
                                timer += 20;
                            else
                                timer -= 20;

                            switch (me->GetPower(POWER_RAGE))
                            {
                                case 0:
                                    phase1 = true;
                                    break;
                                case 1000:
                                    if (!phase1)
                                        break;

                                    phase1 = false;
                                    DoCast(me, SPELL_UNLEASHED_WRATH);
                                    break;
                            }

                            me->SetPower(POWER_RAGE, timer > 100 ? 100 : timer < 0 ? 0 : timer);
                            events.ScheduleEvent(EVENT_UPDATE_RAGE, 1000);
                            break;
                        }
                        case EVENT_BERSERK:
                        {
                            me->CastSpell(me, SPELL_BERSERK, false);
                            break;
                        }
                        case EVENT_RANGE_ATTACK:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                            {
                                me->CastSpell(target, SPELL_SHADOW_BOLT_ANGER, false);
                                me->AddAura(SPELL_SEETHE_AURA, target);
                            }

                            range = false;
                            break;
                        }
                        default:
                            break;
                    }
                }

                if (me->GetVictim() && !me->IsWithinMeleeRange(me->GetVictim(), 37.5f) && !range)
                {
                    range = true;
                    events.ScheduleEvent(EVENT_RANGE_ATTACK, 2000);
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_sha_of_anger_AI(creature);
        }
};

class npc_sha_of_anger_bunny : public CreatureScript
{
    public:
        npc_sha_of_anger_bunny() : CreatureScript("npc_sha_of_anger_bunny") { }

        struct npc_sha_of_anger_bunnyAI : public ScriptedAI
        {
            npc_sha_of_anger_bunnyAI(Creature* creature) : ScriptedAI(creature)
            {
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                creature->GetMotionMaster()->Clear();
            }

            void Reset() override
            {
                me->GetMotionMaster()->Clear();
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

                if (me->AI())
                    me->AI()->SetCanSeeEvenInPassiveMode(true);
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (who->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (!who->IsWithinDist(me, 50.0f))
                    return;

                if (who->IsWithinDist(me, 30.0f))
                    who->AddAura(SPELL_OVERCOME_BY_ANGER, who);
                else if (who->HasAura(SPELL_OVERCOME_BY_ANGER))
                    who->RemoveAura(SPELL_OVERCOME_BY_ANGER);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (me->AI() && !me->AI()->CanSeeEvenInPassiveMode())
                    me->AI()->SetCanSeeEvenInPassiveMode(true);

                if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE))
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

                if (me->isMoving())
                    me->StopMoving();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_sha_of_anger_bunnyAI(creature);
        }
};

class spell_sha_of_anger_aggressive_behaviour : public SpellScriptLoader
{
    public:
        spell_sha_of_anger_aggressive_behaviour() : SpellScriptLoader("spell_sha_of_anger_aggressive_behaviour") { }

        class spell_sha_of_anger_aggressive_behaviour_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_of_anger_aggressive_behaviour_AuraScript);

            void HandlePeriodicTick(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (Unit* target = GetTarget())
                    if (target->GetHealthPct() < 50.0f)
                        this->Remove(AURA_REMOVE_BY_DEFAULT);
            }

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                {
                    if (!target->ToPlayer())
                        return;

                    target->SetPvP(true);
                    target->setFaction(16);
                    target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
                }

            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* target = GetTarget())
                {
                    target->RestoreFaction();
                    target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_of_anger_aggressive_behaviour_AuraScript::HandlePeriodicTick, EFFECT_5, SPELL_AURA_PERIODIC_DUMMY);
                OnEffectApply += AuraEffectApplyFn(spell_sha_of_anger_aggressive_behaviour_AuraScript::OnApply, EFFECT_5, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_sha_of_anger_aggressive_behaviour_AuraScript::OnRemove, EFFECT_5, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_of_anger_aggressive_behaviour_AuraScript();
        }
};

// Overcome by Anger - 129356
class spell_sha_of_anger_overcome_by_anger : public SpellScriptLoader
{
    public:
        spell_sha_of_anger_overcome_by_anger() : SpellScriptLoader("spell_sha_of_anger_overcome_by_anger") { }

        class spell_sha_of_anger_overcome_by_anger_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_of_anger_overcome_by_anger_AuraScript);

            void OnUpdate(uint32 /*diff*/)
            {
                if (Unit* target = GetTarget())
                {
                    if (Unit* caster = GetCaster())
                    {
                        if (target->GetMapId() != caster->GetMapId() || !target->IsWithinDist(caster, 30.0f))
                            target->RemoveAura(SPELL_OVERCOME_BY_ANGER);
                    }
                }
            }

            void Register() override
            {
                OnAuraUpdate += AuraUpdateFn(spell_sha_of_anger_overcome_by_anger_AuraScript::OnUpdate);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_of_anger_overcome_by_anger_AuraScript();
        }
};

void AddSC_boss_sha_of_anger()
{
    new boss_sha_of_anger();
    new npc_sha_of_anger_bunny();
    new spell_sha_of_anger_aggressive_behaviour();
    new spell_sha_of_anger_overcome_by_anger();   
}
