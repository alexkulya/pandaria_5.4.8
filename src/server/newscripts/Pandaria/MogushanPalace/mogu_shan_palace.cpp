#include "NewScriptPCH.h"
#include "mogu_shan_palace.h"

enum otherEvents
{
    EVENT_RUN_FOREST_RUN = 1,
    EVENT_GEM_LIMIT_TIME = 2,
};

class npc_jade_quilen : public CreatureScript
{
    public:
        npc_jade_quilen() : CreatureScript("npc_jade_quilen") {}

        struct npc_jade_quilenAI : public Scripted_NoMovementAI
        {
            npc_jade_quilenAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                instance = creature->GetInstanceScript();
                OneClick = false;
            }

            InstanceScript* instance;
            bool OneClick;
            
            void OnSpellClick(Unit* /*clicker*/)
            {
                if (instance && !OneClick)
                {
                    OneClick = true;
                    uint32 JadeCount = instance->GetData(TYPE_JADECOUNT) + 1;
                    instance->SetData(TYPE_JADECOUNT, JadeCount);
                    me->DespawnOrUnsummon();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_jade_quilenAI(creature);
        }
};

class npc_glintrok_scout : public CreatureScript
{
    public:
        npc_glintrok_scout() : CreatureScript("npc_glintrok_scout") {}

        struct npc_glintrok_scoutAI : public ScriptedAI
        {
            npc_glintrok_scoutAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            
            void Reset()
            {
                me->SetReactState(REACT_AGGRESSIVE);
            }
            
            void EnterCombat(Unit* /*who*/)
            {
                if (instance)
                {
                    Talk(0); //Enemy Found
                    DoCast(SPELL_GLINTROK_SCOUT_WARNING);
                    events.ScheduleEvent(EVENT_RUN_FOREST_RUN, 500);
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RUN_FOREST_RUN:
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MovePoint(1, otherPos[1]);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == POINT_MOTION_TYPE)
                {
                    if (id == 1)
                        me->DespawnOrUnsummon();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_glintrok_scoutAI(creature);
        }
};

class npc_faintly_glowing_gem : public CreatureScript
{
    public:
        npc_faintly_glowing_gem() : CreatureScript("npc_faintly_glowing_gem") {}

        struct npc_faintly_glowing_gemAI : public Scripted_NoMovementAI
        {
            npc_faintly_glowing_gemAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                instance = creature->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
                OneClick = false;
            }

            InstanceScript* instance;
            EventMap events;
            bool OneClick;

            void OnSpellClick(Unit* /*clicker*/)
            {
                if (instance && !OneClick)
                {
                    OneClick = true;
                    DoCast(SPELL_TURN_OFF_BLADES);
                    uint32 GemCount = instance->GetData(TYPE_GEMCOUNT) + 1;
                    instance->SetData(TYPE_GEMCOUNT, GemCount);
                    events.ScheduleEvent(EVENT_GEM_LIMIT_TIME, 5000);
                    if (GemCount == 2)
                    {
                        DoCast(SPELL_SECRET_DEFENSE_MECHANISM);
                        events.CancelEvent(EVENT_GEM_LIMIT_TIME);
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GEM_LIMIT_TIME:
                            uint32 GemCount = instance->GetData(TYPE_GEMCOUNT) - 1;
                            instance->SetData(TYPE_GEMCOUNT, GemCount);
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_faintly_glowing_gemAI(creature);
        }
};

void AddSC_mogu_shan_palace()
{
    new npc_jade_quilen();
    new npc_glintrok_scout();
    new npc_faintly_glowing_gem();
}