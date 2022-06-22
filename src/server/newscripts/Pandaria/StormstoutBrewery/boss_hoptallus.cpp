/*
    Dungeon : Template of the Jade Serpent 85-87
    Wise mari first boss
    Jade servers
*/

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stormstout_brewery.h"

enum Spells
{
    SPELL_CARROT_BREATH             = 112944,
    SPELL_FURL_WIND                 = 112992, 
    SPELL_EXPLOSIVE_BREW            = 114291,
    SPELL_EXPLOSIVE_BREW_JUMP_DMG   = 116027,
};

enum eEvents
{
    EVENT_WP_1      = 1,
    EVENT_WP_2      = 2,
    EVENT_WP_3      = 3,
    EVENT_WP_4      = 4,
};

const Position ePos[6] =
{
    {-711.41f, 1314.26f, 163.0f},
    {-752.30f, 1326.73f, 163.0f},
    {-769.08f, 1298.62f, 163.0f},
    {-768.20f, 1273.40f, 163.0f},
    {-758.04f, 1236.80f, 163.0f},
    {-775.34f, 1215.79f, 169.0f},
};

class boss_hoptallus : public CreatureScript
{
    public:
        boss_hoptallus() : CreatureScript("boss_hoptallus") { }
        
        struct boss_hoptallus_AI : public BossAI
        {
            boss_hoptallus_AI(Creature* creature) : BossAI(creature, DATA_HOPTALLUS)
            {
                InstanceScript* instance = creature->GetInstanceScript();
            }

            uint32 breathtimer;
            uint32 windtimer;
            uint32 summonadd;
         
            void Reset()
            {
                _Reset();
                breathtimer = 0;
                windtimer = 0;
                summonadd = 0;
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                breathtimer = 13000;
                windtimer = 8000;
                summonadd = 10000;
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;
                
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (breathtimer <= diff)
                {
                    DoCast(me, SPELL_CARROT_BREATH);
                    breathtimer = 13000;
                }
                else
                    breathtimer -= diff;

                if (windtimer <= diff)
                {
                    DoCast(me, SPELL_FURL_WIND);
                    windtimer = 8000;
                }
                else
                    windtimer -= diff;

                if (summonadd <= diff)
                {
                    for (uint8 i = 0; i < 3; i++) 
                       if (Creature* hopper =  me->SummonCreature(59464, me->GetPositionX() +5, me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN))
                           hopper->SetInCombatWithZone();
                       summonadd = 10000;
                }
                else
                    summonadd -= diff;

                DoMeleeAttackIfReady();
            }
        };
        
        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_hoptallus_AI(creature);
        }
};

class npc_hopper : public CreatureScript
{
    public:
        npc_hopper() : CreatureScript("npc_hopper") {}

        struct npc_hopperAI : public ScriptedAI
        {
            npc_hopperAI(Creature* creature) : ScriptedAI(creature)
            {
                move = false;
            }

            bool explose;
            bool move;
            EventMap events;

            void Reset()
            {
                explose = false;
                me->SetReactState(REACT_AGGRESSIVE);
            }

            void EnterEvadeMode()
            {
                me->DespawnOrUnsummon();
            }

            void IsSummonedBy(Unit* owner)
            {
                if (owner->GetEntry() == NPC_TRIGGER_SUMMONER)
                {
                    move = true;
                    me->setFaction(14);
                    me->SetWalk(true);
                    me->GetMotionMaster()->MovePoint(1, ePos[0]);
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == POINT_MOTION_TYPE)
                {
                    switch (id)
                    {
                        case 1:
                            events.ScheduleEvent(EVENT_WP_1, 0);
                            break;
                        case 2:
                            events.ScheduleEvent(EVENT_WP_2, 0);
                            break;
                        case 3:
                            events.ScheduleEvent(EVENT_WP_3, 0);
                            break;
                        case 4:
                            events.ScheduleEvent(EVENT_WP_4, 0);
                            break;
                        case 5:
                            me->GetMotionMaster()->MoveJump(ePos[5].GetPositionX() + irand(-5, 5), ePos[5].GetPositionY() + irand(-5, 5), ePos[5].GetPositionZ(), 15, 15);
                            me->DespawnOrUnsummon();
                            break;
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim() && !move)
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);
                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WP_1:
                            me->GetMotionMaster()->MovePoint(2, ePos[1]);
                            break;
                        case EVENT_WP_2:
                            me->GetMotionMaster()->MovePoint(3, ePos[2]);
                            break;
                        case EVENT_WP_3:
                            me->GetMotionMaster()->MovePoint(4, ePos[3]);
                            break;
                        case EVENT_WP_4:
                            me->GetMotionMaster()->MovePoint(5, ePos[4]);
                            break;
                    }
                }

                if (me->getVictim())
                {
                    if (me->IsWithinMeleeRange(me->getVictim()))
                    {
                        if (me->GetDistance(me->getVictim()) <= 0.5f && !explose)
                        {
                            explose = true;
                            DoCast(me->getVictim(), SPELL_EXPLOSIVE_BREW);
                        }
                    }
                }
            }

            void SpellHit(Unit* caster, SpellInfo const* spell)
            {
                if (spell->Id == SPELL_SMASH_DMG)
                {
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->InterruptSpell(CURRENT_GENERIC_SPELL);
                    me->GetMotionMaster()->MoveJump(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 20, 10, 18);
                    DoCast(SPELL_EXPLOSIVE_BREW_JUMP_DMG);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_hopperAI(creature);
        }
};

void AddSC_boss_hoptallus()
{
    new boss_hoptallus();
    new npc_hopper();
}
