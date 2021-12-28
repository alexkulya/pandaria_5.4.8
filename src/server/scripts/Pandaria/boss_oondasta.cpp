#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"

enum Spells
{
    SPELL_CRUSH           = 137504,
    SPELL_ALPHA_MALE      = 138391,
    SPELL_ALPHA_MALE_EFF  = 138390, // set increased threat for tanks
    SPELL_FRILL_BLAST     = 137505, // channeled 
    SPELL_GROWING_FURY    = 137502,
    SPELL_PIERCING_ROAR   = 137457,
    SPELL_SPIRITFIRE_BEAM = 137508, // 99 chains lol

    // Misc
    SPELL_KILL_DOHAMAN    = 138859,
};

enum Events
{
    EVENT_CRUSH = 1,
    EVENT_FRILL_BLAST,
    EVENT_GROWING_FURY,
    EVENT_PIERCING_ROAR,
    EVENT_SPIRITFIRE_BEAM,
    EVENT_SPIRITFIRE_BEAM_2,
};

enum Yells
{
    TALK_INTRO,
    TALK_DEATH,
};

enum Creatures
{
    NPC_DOHAMAN_THE_BEAST_LORD = 69926, // init combat event (BITE!)
    NPC_OONDASTA               = 69161,
};

const Position DohamanSummPos = { 6039.462f, 1111.173f, 55.538712f, 0.0f };

class boss_oondasta : public CreatureScript
{
    public:
        boss_oondasta() : CreatureScript("boss_oondasta") { }

        struct boss_oondastaAI : public ScriptedAI
        {
            boss_oondastaAI(Creature* creature) : ScriptedAI(creature), summons(me)
            {
                // Boss immune to any taunt spells - see alpha male
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
            }

            SummonList summons;
            TaskScheduler scheduler;
            EventMap events;
            uint64 targetGUID;
            uint32 spiritFireCount;

            void Reset() override
            {
                scheduler.CancelAll();
                summons.DespawnAll();
                events.Reset();
                me->SetReactState(REACT_DEFENSIVE);
                targetGUID      = 0;
                spiritFireCount = 0;

                scheduler
                    .Schedule(Seconds(1), [this](TaskContext context)
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_NON_ATTACKABLE);
                    me->SummonCreature(NPC_DOHAMAN_THE_BEAST_LORD, DohamanSummPos, TEMPSUMMON_MANUAL_DESPAWN);
                });
            }

            void EnterCombat(Unit* /*who*/) override 
            {
                if (Creature* dohaman = me->FindNearestCreature(NPC_DOHAMAN_THE_BEAST_LORD, 150.0f, true))
                    dohaman->AI()->Talk(TALK_INTRO);

                scheduler
                    .Schedule(Seconds(7), [this](TaskContext context)
                {
                    if (Creature* dohaman = me->FindNearestCreature(NPC_DOHAMAN_THE_BEAST_LORD, 150.0f, true))
                        dohaman->AI()->Talk(TALK_DEATH);

                    DoCast(me, SPELL_KILL_DOHAMAN, true);
                });

                DoCast(me, SPELL_ALPHA_MALE);

                events.ScheduleEvent(EVENT_CRUSH, 3 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_FRILL_BLAST, 40 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_PIERCING_ROAR, 20 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SPIRITFIRE_BEAM, 5 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SPIRITFIRE_BEAM_2, urand(35 * IN_MILLISECONDS, 60 * IN_MILLISECONDS)); // additional spirit fire, not in chain
                events.ScheduleEvent(EVENT_GROWING_FURY, 18.5 * IN_MILLISECONDS);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    //Talk(TALK_SLAY);
                        return;
            }

            void JustDied(Unit* killer) override
            {
                summons.DespawnAll();
            }

            void EnterEvadeMode() override
            {
                ScriptedAI::EnterEvadeMode();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_NON_ATTACKABLE);
                summons.DespawnAll();

                uint32 corpseDelay = me->GetCorpseDelay();
                uint32 respawnDelay = me->GetRespawnDelay();

                me->SetCorpseDelay(1);
                me->SetRespawnDelay(29);

                me->DespawnOrUnsummon();

                me->SetCorpseDelay(corpseDelay);
                me->SetRespawnDelay(respawnDelay);
            }

            void UpdateAI(uint32 diff) override
            {
                scheduler.Update(diff);

                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CRUSH:
                            if (Unit* vict = me->GetVictim())
                                DoCast(vict, SPELL_CRUSH);
                        
                            events.ScheduleEvent(EVENT_CRUSH, 30 * IN_MILLISECONDS);
                            break;
                        case EVENT_FRILL_BLAST:
                            if (Unit* target = me->GetVictim())
                                targetGUID = target->GetGUID();
                        
                            me->PrepareChanneledCast(me->GetOrientation(), SPELL_FRILL_BLAST);
                        
                            me->m_Events.Schedule(2500, [this]()
                            {
                                me->RemoveChanneledCast(targetGUID);
                            });
                        
                            events.ScheduleEvent(EVENT_FRILL_BLAST, urand(25 * IN_MILLISECONDS, 30 * IN_MILLISECONDS));
                            break;
                        case EVENT_PIERCING_ROAR:
                            DoCast(me, SPELL_PIERCING_ROAR);
                            events.ScheduleEvent(EVENT_PIERCING_ROAR, urand(26 * IN_MILLISECONDS, 60 * IN_MILLISECONDS));
                            break;
                        case EVENT_SPIRITFIRE_BEAM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, CasterSpecTargetSelector()))
                                DoCast(target, SPELL_SPIRITFIRE_BEAM);
                            else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankSpecTargetSelector()))
                                DoCast(target, SPELL_SPIRITFIRE_BEAM);
                            else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                DoCast(target, SPELL_SPIRITFIRE_BEAM);

                            // Cast twice in chain
                            if (++spiritFireCount >= 2)
                                spiritFireCount = 0;

                            events.ScheduleEvent(EVENT_SPIRITFIRE_BEAM, spiritFireCount == 0 ? 45 * IN_MILLISECONDS : 5 * IN_MILLISECONDS);
                            break;
                        case EVENT_SPIRITFIRE_BEAM_2:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, CasterSpecTargetSelector()))
                                DoCast(target, SPELL_SPIRITFIRE_BEAM);
                            else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankSpecTargetSelector()))
                                DoCast(target, SPELL_SPIRITFIRE_BEAM);
                            else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                                DoCast(target, SPELL_SPIRITFIRE_BEAM);

                            events.ScheduleEvent(EVENT_SPIRITFIRE_BEAM_2, urand(35 * IN_MILLISECONDS, 60 * IN_MILLISECONDS));
                            break;
                        case EVENT_GROWING_FURY:
                            DoCast(me, SPELL_GROWING_FURY);
                            events.ScheduleEvent(EVENT_GROWING_FURY, 30 * IN_MILLISECONDS);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_oondastaAI(creature);
        }
};

// Alpha Male Eff 138390
class spell_alpha_male_eff : public SpellScript
{
    PrepareSpellScript(spell_alpha_male_eff)

    void HandleSelectTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(NonTankSpecTargetSelector());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_alpha_male_eff::HandleSelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// Kill Dohaman 138859
class spell_kill_dohaman : public SpellScript
{
    PrepareSpellScript(spell_kill_dohaman);

    void HandleEffectHitTarget(SpellEffIndex /*eff_idx*/)
    {
        if (Creature* target = GetHitCreature())
            target->DespawnOrUnsummon(10 * IN_MILLISECONDS);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_kill_dohaman::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_INSTAKILL);
    }
};

void AddSC_boss_oondasta()
{
    new boss_oondasta();
    new spell_script<spell_alpha_male_eff>("spell_alpha_male_eff");
    new spell_script<spell_kill_dohaman>("spell_kill_dohaman");
}
