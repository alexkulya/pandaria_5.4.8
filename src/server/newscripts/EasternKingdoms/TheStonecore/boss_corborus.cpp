#include "NewScriptPCH.h"
#include "the_stonecore.h"

enum Spells
{
    SPELL_CRYSTAL_BARRAGE        = 86881,
    SPELL_CRYSTAL_BARRAGE_H        = 92648,
    SPELL_CRYSTAL_BARRAGE_SUM    = 92012,
    SPELL_CRYSTAL_SHARD_DMG        = 92122,
    SPELL_DUMPENING_WAVE        = 82415,
    SPELL_DUMPENING_WAVE_H        = 92650,
    SPELL_SUBMERGE                = 53421,
    SPELL_THRASHING_CHARGE_DMG    = 81828,
    SPELL_THRASHING_CHARGE_SUM    = 81816,
    SPELL_THRASHING_CHARGE_H    = 92651,
    SPELL_THRASHING_CHARGE_DUM    = 81801,
    SPELL_ROCK_BORE                = 80028,                
    SPELL_ROCK_BORE_H            = 92630,
};

enum Events
{
    EVENT_CRYSTAL_BARRAGE        = 1,
    EVENT_DUMPENING_WAVE        = 2,
    EVENT_MERGE                    = 3,
    EVENT_SUBMERGE                = 4,
    EVENT_CRYSTAL_BARRAGE_H        = 5,
    EVENT_THRASHING_CHARGE        = 6,
    EVENT_ROCK_BORER            = 7,
    EVENT_ROCK_BORE                = 8,
    EVENT_CRYSTAL_SHARD_MOVE    = 9,
};

enum Adds
{
    NPC_ROCK_BORER            = 43917,
    NPC_CRYSTAL_SHARD        = 49267,
    NPC_THRASHING_CHARGE    = 43743,
};

class boss_corborus : public CreatureScript
{
    public:
        boss_corborus() : CreatureScript("boss_corborus") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetStonecoreAI<boss_corborusAI>(pCreature);
        }

        struct boss_corborusAI : public BossAI
        {
            boss_corborusAI(Creature* pCreature) : BossAI(pCreature, DATA_CORBORUS), summons(me)
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
            }

            EventMap events;
            SummonList summons;
            uint8 stage;
            Position barragePos;

            void Reset()
            {
                _Reset();

                stage = 0;
                me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
                me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);    
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_DUMPENING_WAVE, 5000);
                events.ScheduleEvent(EVENT_CRYSTAL_BARRAGE, 7000);
                events.ScheduleEvent(EVENT_SUBMERGE, 30000);
                instance->SetBossState(DATA_CORBORUS, IN_PROGRESS);
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);

                switch (summon->GetEntry())
                {
                case NPC_THRASHING_CHARGE:
                    summon->CastSpell(summon, SPELL_THRASHING_CHARGE_DUM, false);
                    break;
                case NPC_ROCK_BORER:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        summon->AddThreat(target, 10.0f);
                        summon->Attack(target, true);
                        summon->GetMotionMaster()->MoveChase(target);
                    }
                    break;
                case NPC_CRYSTAL_SHARD:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                    {
                        summon->AddThreat(target, 10.0f);
                        summon->Attack(target, true);
                        summon->GetMotionMaster()->MoveChase(target);
                    }
                    break;
                }
            }

            void JustDied(Unit* killer)
            {
                _JustDied();
                summons.DespawnAll();
            }

            void SummonedCreatureDespawn(Creature* summon)
            {
                summons.Despawn(summon);
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
                    case EVENT_DUMPENING_WAVE:
                        DoCast(SPELL_DUMPENING_WAVE);
                        events.ScheduleEvent(EVENT_DUMPENING_WAVE, 10000);
                        break;
                    case EVENT_CRYSTAL_BARRAGE:
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            DoCast(pTarget, SPELL_CRYSTAL_BARRAGE);
                            if (IsHeroic())
                            {
                                pTarget->GetPosition(&barragePos);
                                events.ScheduleEvent(EVENT_CRYSTAL_BARRAGE_H, 4000);
                            }    
                        }
                        events.ScheduleEvent(EVENT_CRYSTAL_BARRAGE, 15000);
                        break;
                    case EVENT_CRYSTAL_BARRAGE_H:
                        for (uint8 i = 0; i < 5; i++)
                        {
                            me->CastSpell(
                                barragePos.GetPositionX(),
                                barragePos.GetPositionY(),
                                barragePos.GetPositionZ(),
                                SPELL_CRYSTAL_BARRAGE_SUM, true);
                        }  
                        break;
                    case EVENT_SUBMERGE:
                        me->RemoveAllAuras();
                        me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        DoCast(me, SPELL_SUBMERGE);
                        events.Reset();
                        events.ScheduleEvent(EVENT_THRASHING_CHARGE, 4000);
                        events.ScheduleEvent(EVENT_ROCK_BORER, 3000);
                        events.ScheduleEvent(EVENT_MERGE, 20000);
                        break;
                    case EVENT_MERGE:
                        me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        events.Reset();
                        events.ScheduleEvent(EVENT_DUMPENING_WAVE, 5000);
                        events.ScheduleEvent(EVENT_CRYSTAL_BARRAGE, 7000);
                        events.ScheduleEvent(EVENT_SUBMERGE, 30000);
                        break;
                    case EVENT_THRASHING_CHARGE:
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(pTarget, SPELL_THRASHING_CHARGE_SUM, true);
                        events.ScheduleEvent(EVENT_THRASHING_CHARGE, 4000);
                        break;
                    case EVENT_ROCK_BORER:
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                        {
                            me->SummonCreature(NPC_ROCK_BORER,
                                pTarget->GetPositionX()+urand(3, 5),
                                pTarget->GetPositionY()+urand(3, 5),
                                pTarget->GetPositionZ(), 0.0f);
                        }
                        events.ScheduleEvent(EVENT_ROCK_BORER, 3000);
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };
};

class npc_rock_borer : public CreatureScript
{
    public:
        npc_rock_borer() : CreatureScript("npc_rock_borer") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_rock_borerAI(pCreature);
        }

        struct npc_rock_borerAI : public ScriptedAI
        {
            npc_rock_borerAI(Creature *c) : ScriptedAI(c)
            {
            }

            EventMap events;

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                events.ScheduleEvent(EVENT_ROCK_BORE, 2000);
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
                    switch(eventId)
                    {
                        case EVENT_ROCK_BORE:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(pTarget, SPELL_ROCK_BORE);
                            events.ScheduleEvent(EVENT_ROCK_BORE, 5000);
                            return;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

void AddSC_boss_corborus()
{
    new boss_corborus();
    new npc_rock_borer();
}