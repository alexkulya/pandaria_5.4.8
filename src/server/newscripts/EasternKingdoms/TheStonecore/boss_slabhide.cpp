#include "NewScriptPCH.h"
#include "the_stonecore.h"

enum Spells
{
    SPELL_SAND_BLAST        = 80807,
    SPELL_SAND_BLAST_H      = 92656,
    SPELL_LAVA_FISSURE_DUM  = 80798,
    SPELL_ERUPTION          = 80800,
    SPELL_ERUPTION_AURA     = 80801,
    SPELL_ERUPTION_H        = 92657,
};

enum Events
{
    EVENT_SAND_BLAST    = 1,
    EVENT_LAVA_FISSURE  = 2,
    EVENT_FLY           = 3,
    EVENT_GROUND        = 4,
    EVENT_ERUPTION      = 5,
};

enum Adds
{
    NPC_LAVA_FISSURE = 43242,
    NPC_STALACTITE_TRIGGER  = 43159,
    NPC_STALACTITE__GROUND_TRIGGER = 43357,
};

Position slabhidegroundPos = {1278.23f, 1212.27f, 247.28f, 0.0f};
Position slabhideflyPos = {1278.23f, 1212.27f, 257.28f, 0.0f};

class boss_slabhide : public CreatureScript
{
    public:
        boss_slabhide() : CreatureScript("boss_slabhide") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetStonecoreAI<boss_slabhideAI>(pCreature);
        }

        struct boss_slabhideAI : public BossAI
        {
            boss_slabhideAI(Creature* pCreature) : BossAI(pCreature, DATA_SLABHIDE)
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
            void Reset()
            {
                _Reset();

                me->SetCanFly(false);
                events.Reset();
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_FLY, 50000);
                events.ScheduleEvent(EVENT_SAND_BLAST, 10000);
                events.ScheduleEvent(EVENT_LAVA_FISSURE, urand(10000, 15000));
                instance->SetBossState(DATA_SLABHIDE, IN_PROGRESS);
            }

            void JustDied(Unit* killer)
            {
                _JustDied();
                me->SetCanFly(false);
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == POINT_MOTION_TYPE)
                {
                    switch (id)
                    {
                    case 1:
                        events.ScheduleEvent(EVENT_GROUND, 10000);
                        break;
                    case 2:
                        me->SetCanFly(false);
                        SetCombatMovement(true);
                        events.ScheduleEvent(EVENT_SAND_BLAST, 10000);
                        events.ScheduleEvent(EVENT_LAVA_FISSURE, urand(15000, 28000));
                        events.ScheduleEvent(EVENT_FLY, 50000);
                        AttackStart(me->getVictim());
                        break;
                    }
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
                        case EVENT_FLY:
                            events.Reset();
                            SetCombatMovement(false);
                            me->SetCanFly(true);
                            me->GetMotionMaster()->MovePoint(1, slabhideflyPos);
                            break;
                        case EVENT_GROUND:
                            events.Reset();
                            me->GetMotionMaster()->MovePoint(2, slabhidegroundPos);
                            break;
                        case EVENT_SAND_BLAST:
                            DoCast(SPELL_SAND_BLAST);
                            events.ScheduleEvent(EVENT_SAND_BLAST, 10000);
                            break;
                        case EVENT_LAVA_FISSURE:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                                me->SummonCreature(NPC_LAVA_FISSURE, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0.0f);
                            events.ScheduleEvent(EVENT_LAVA_FISSURE, urand(15000, 18000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

};

class npc_lava_fissure : public CreatureScript
{
    public:
        npc_lava_fissure() : CreatureScript("npc_lava_fissure") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_lava_fissureAI(pCreature);
        }

        struct npc_lava_fissureAI : public ScriptedAI
        {
            npc_lava_fissureAI(Creature *c) : ScriptedAI(c)
            {
            }

            EventMap events;
            uint32 uidespawnTimer;

            void Reset()
            {
                uidespawnTimer = DUNGEON_MODE(15000, 33000);
                events.ScheduleEvent(EVENT_ERUPTION, DUNGEON_MODE(5000, 3000));
                DoCast(SPELL_LAVA_FISSURE_DUM);
            }

            void UpdateAI(uint32 diff)
            {
                if (uidespawnTimer <= diff)
                    me->DespawnOrUnsummon();
                else
                    uidespawnTimer -= diff;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch(eventId)
                    {
                    case EVENT_ERUPTION:
                        me->RemoveAurasDueToSpell(SPELL_LAVA_FISSURE_DUM);
                        DoCast(DUNGEON_MODE(SPELL_ERUPTION, SPELL_ERUPTION_H));
                        break;
                    }
                }
            }
        };
};

void AddSC_boss_slabhide()
{
    new boss_slabhide();
    new npc_lava_fissure();
}