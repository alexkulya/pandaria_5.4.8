#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "arcatraz.h"

enum Spells
{
    SPELL_WHIRLWIND             = 36142,
    SPELL_HEAL                  = 36144,
    SPELL_GIFT_OF_THE_DOOMSAYER = 36173,
    SPELL_SHADOW_WAVE           = 39016,
    SPELL_DOUBLE_ATTACK         = 19818,
};

enum Events
{
    EVENT_WHIRLWIND         = 1,
    EVENT_SHADOW_WAVE       = 2,
    EVENT_GIFT_OF_DOOMSAYER = 3,
    EVENT_HEAL              = 4,
};

class boss_dalliah_the_doomsayer : public CreatureScript
{
    public:
        boss_dalliah_the_doomsayer() : CreatureScript("boss_dalliah_the_doomsayer") { }

        struct boss_dalliah_the_doomsayerAI : public BossAI
        {
            boss_dalliah_the_doomsayerAI(Creature* creature) : BossAI(creature, TYPE_DALLIAH) { }

            bool hasYell;

            void Reset() override
            {
                _Reset();
                events.Reset();
                me->RemoveAurasDueToSpell(SPELL_DOUBLE_ATTACK);
                hasYell = false;

                if (instance)
                    instance->SetData(TYPE_DALLIAH, NOT_STARTED);
            }

            Creature* Soccothrates()
            {
                if (Creature* sSoccothrates = ObjectAccessor::GetCreature(*me, instance->GetData64(TYPE_SOCCOTHRATES)))
                    return sSoccothrates;

                return 0;
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(TALK_SD_AGGRO);

                if (Creature* soccothrates = Soccothrates())
                    if (soccothrates->IsAlive())
                        soccothrates->AI()->Talk(TALK_DALLIAH_IN_COMBAT_AND_ME_ALIVE);

                DoCast(me, SPELL_DOUBLE_ATTACK);
                events.ScheduleEvent(EVENT_WHIRLWIND, 14 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_GIFT_OF_DOOMSAYER, 30 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SHADOW_WAVE, 25 * IN_MILLISECONDS);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(TALK_SD_SLAY);
            }

            void DoAction(int32 actionId) override
            {
                if (actionId == ACTION_REMOVE_WHIRLWIND)
                    events.ScheduleEvent(EVENT_HEAL, 2 * IN_MILLISECONDS);
            }

            void EnterEvadeMode() override
            {
                _EnterEvadeMode();

                if (instance)
                    instance->SetData(TYPE_DALLIAH, FAIL);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                Talk(TALK_DALIAH_DEATH);

                if (Creature* soccothrates = Soccothrates())
                    if (soccothrates->IsAlive())
                        soccothrates->AI()->Talk(TALK_DALLIAH_DIE);

                if (instance)
                    instance->SetData(TYPE_DALLIAH, DONE);
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (HealthBelowPct(25) && !hasYell)
                {
                    hasYell = true;

                    if (Creature* soccothrates = Soccothrates())
                        if (soccothrates->IsAlive())
                            soccothrates->AI()->Talk(TALK_DALLIAH_AT_LOW);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WHIRLWIND:
                            Talk(TALK_WHIRLWIND);
                            DoCast(me, SPELL_WHIRLWIND);
                            events.ScheduleEvent(EVENT_WHIRLWIND, urand(22 * IN_MILLISECONDS, 24 * IN_MILLISECONDS));
                            break;
                        case EVENT_SHADOW_WAVE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                DoCast(target, SPELL_SHADOW_WAVE);
                            else if (Unit* target = me->GetVictim())
                                DoCast(target, SPELL_SHADOW_WAVE);

                            events.ScheduleEvent(EVENT_SHADOW_WAVE, urand(20 * IN_MILLISECONDS, 25 * IN_MILLISECONDS));
                            break;
                        case EVENT_GIFT_OF_DOOMSAYER:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                DoCast(target, SPELL_GIFT_OF_THE_DOOMSAYER);
                            else if (Unit* target = me->GetVictim())
                                DoCast(target, SPELL_GIFT_OF_THE_DOOMSAYER);

                            events.ScheduleEvent(EVENT_GIFT_OF_DOOMSAYER, 30 * IN_MILLISECONDS);
                            break;
                        case EVENT_HEAL:
                            Talk(TALK_HEAL);
                            DoCast(me, SPELL_HEAL);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_dalliah_the_doomsayerAI(creature);
        }
};

// Whirlwind 36142
class spell_dalliah_whirlwind : public SpellScriptLoader
{
    public:
        spell_dalliah_whirlwind() : SpellScriptLoader("spell_dalliah_whirlwind") { }

        class spell_dalliah_whirlwind_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dalliah_whirlwind_AuraScript);

            void OnAuraEffectRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                if (Unit* owner = GetOwner()->ToUnit())
                    if (owner->ToCreature())
                        owner->ToCreature()->AI()->DoAction(ACTION_REMOVE_WHIRLWIND);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_dalliah_whirlwind_AuraScript::OnAuraEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dalliah_whirlwind_AuraScript();
        }
};

void AddSC_boss_dalliah_the_doomsayer()
{
    new boss_dalliah_the_doomsayer();
    new spell_dalliah_whirlwind();
}