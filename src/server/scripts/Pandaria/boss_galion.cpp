#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "Vehicle.h"

enum eBosses
{
    BOSS_GALION,
};

enum eActions
{
    ACTION_INIT_COMBAT,
};

enum eSpells
{
    SPELL_STOMP                 = 121787,
    SPELL_CANNON_BARRAGE        = 121577,
    SPELL_FIRE_SHOT             = 121673,
    SPELL_EMPALLING_PULL        = 121747,
    SPELL_BERSERK               = 47008,
};

enum eEvents
{
    EVENT_STOMP                 = 1,
    EVENT_CANNON                = 2,
    EVENT_FIRE_SHOT             = 3,
    EVENT_EMPALLING             = 4,
    EVENT_SPAWN                 = 6,
    EVENT_BERSERK               = 7,
    EVENT_INIT_VEHICLE          = 8,
    EVENT_INIT_COMBAT           = 9,
};

enum eCreatures
{
    NPC_GALLEON                 = 62346,
    NPC_GALLEON_CANNON          = 62355,
    NPC_SALYIN_WARMONGER        = 62351, // temp summon
    NPC_SALYIN_SKRIMISHER       = 62350,
    NPC_CHIEF_SALYIS            = 62352,
};

void HandleInitCombat(uint64 ownerGUID)
{
    Unit* owner = ObjectAccessor::FindUnit(ownerGUID);

    if (!owner)
        return;

    std::list<Player*> pList;
    GetPlayerListInGrid(pList, owner, 200.0f);

    if (pList.empty())
        return;

    if (pList.size() > 1)
    {
        Trinity::Containers::RandomResizeList(pList, 1);

        Player* target = *pList.begin();
        owner->GetMotionMaster()->MoveChase(target);
        owner->Attack(target, true);
    }
}
class boss_galion : public CreatureScript
{
    public:
        boss_galion() : CreatureScript("boss_galion") { }

        struct boss_galion_AI : public BossAI
        {
            boss_galion_AI(Creature* creature) : BossAI(creature, BOSS_GALION) { }

            EventMap vEvents;
            int32 m_bp;

            void Reset() override
            {
                events.Reset();
                summons.DespawnAll();
                m_bp = 0;

                vEvents.ScheduleEvent(EVENT_INIT_VEHICLE, 0.5 * IN_MILLISECONDS);
            }

            void KilledUnit(Unit* /*victim*/) override { }

            void EnterEvadeMode() override
            {
                summons.DespawnAll();
                _DespawnAtEvade();
                me->GetMotionMaster()->MoveTargetedHome();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_STOMP, 50000);
                events.ScheduleEvent(EVENT_CANNON,25000);
                events.ScheduleEvent(EVENT_SPAWN,60000);
                events.ScheduleEvent(EVENT_BERSERK,900000);
                events.ScheduleEvent(EVENT_INIT_COMBAT, 1.5 * IN_MILLISECONDS);
            }

            void UpdateAI(uint32 diff) override
            {
                vEvents.Update(diff);

                while (uint32 eventId = vEvents.ExecuteEvent())
                {
                    if (eventId == EVENT_INIT_VEHICLE)
                    {
                        // Init vehicles, only cosmetic or passive
                        if (const SpellInfo* m_spell = sSpellMgr->GetSpellInfo(VEHICLE_SPELL_RIDE_HARDCODED))
                        {
                            for (uint32 i = 1; i < 3; i++)
                            {
                                m_bp = m_spell->Effects[EFFECT_0].BasePoints + (int32)i;

                                if (Creature* cannon = me->SummonCreature(NPC_GALLEON_CANNON, *me, TEMPSUMMON_MANUAL_DESPAWN))
                                {
                                    cannon->CastCustomSpell(me, VEHICLE_SPELL_RIDE_HARDCODED, &m_bp, 0, 0, true);
                                    cannon->SetFacingTo(Position::NormalizeOrientation(me->GetOrientation() + M_PI / 2));
                                }
                            }

                            for (uint32 i = 3; i < 7; i++)
                            {
                                m_bp = m_spell->Effects[EFFECT_0].BasePoints + (int32)i;

                                if (Creature* skirmisher = me->SummonCreature(NPC_SALYIN_SKRIMISHER, *me, TEMPSUMMON_MANUAL_DESPAWN))
                                    skirmisher->CastCustomSpell(me, VEHICLE_SPELL_RIDE_HARDCODED, &m_bp, 0, 0, true);
                            }

                            m_bp = m_spell->Effects[EFFECT_0].BasePoints + 7;

                            if (Creature* chief = me->SummonCreature(NPC_CHIEF_SALYIS, *me, TEMPSUMMON_MANUAL_DESPAWN))
                                chief->CastCustomSpell(me, VEHICLE_SPELL_RIDE_HARDCODED, &m_bp, 0, 0, true);
                        }
                    }
                    break;
                }

                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STOMP:
                        {
                            me->CastSpell(me,SPELL_STOMP,true);
                            events.ScheduleEvent(EVENT_STOMP, 60000);
                            break;
                        }
                        case EVENT_CANNON:
                        {
                            DoCast(me, SPELL_CANNON_BARRAGE);
                            events.ScheduleEvent(EVENT_CANNON, 60000);
                            break;
                        }
                        case EVENT_SPAWN:
                        {
                            for (uint8 i = 0; i < 6; ++i)
                                me->SummonCreature(NPC_SALYIN_WARMONGER, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());

                            events.ScheduleEvent(EVENT_SPAWN, 60000);
                            break;
                        }
                        case EVENT_BERSERK:
                        {
                            me->CastSpell(me,SPELL_BERSERK,false);
                            break;
                        }
                        case EVENT_INIT_COMBAT:
                        {
                            if (Vehicle* veh = me->GetVehicleKit())
                            {
                                for (auto&& seat : veh->Seats)
                                    if (Creature* passenger = ObjectAccessor::GetCreature(*veh->GetBase(), seat.second.Passenger.Guid))
                                        if (passenger->AI())
                                            passenger->AI()->DoAction(ACTION_INIT_COMBAT);
                            }
                            break;
                        }
                    }
                }

                DoMeleeAttackIfReady();
                EnterEvadeIfOutOfCombatArea(diff, 125.0f);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_galion_AI(creature);
        }
};

// Salyin Skrimisher 62350
class npc_salyin_skrimisher : public CreatureScript
{
    public:
        npc_salyin_skrimisher() : CreatureScript("npc_salyin_skrimisher") { }

        struct npc_salyin_skrimisherAI : public ScriptedAI
        {
            npc_salyin_skrimisherAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;
            uint64 ownerGUID;

            void IsSummonedBy(Unit* summoner) override
            {
                ownerGUID = summoner->GetGUID();
            }

            void DoAction(int32 actionId) override
            {
                if (actionId == ACTION_INIT_COMBAT)
                {
                    HandleInitCombat(me->GetGUID());
                    events.ScheduleEvent(EVENT_FIRE_SHOT, urand(3 * IN_MILLISECONDS, 16 * IN_MILLISECONDS));
                }
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_FIRE_SHOT)
                    {
                        DoCast(me, SPELL_FIRE_SHOT);
                        events.ScheduleEvent(EVENT_FIRE_SHOT, urand(3 * IN_MILLISECONDS, 16 * IN_MILLISECONDS));
                    }
                    break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_salyin_skrimisherAI(creature);
        }
};

class npc_salyin_warmonger : public CreatureScript
{
    public:
        npc_salyin_warmonger() : CreatureScript("npc_salyin_warmonger") { }

        struct npc_salyin_warmongerAI : public ScriptedAI
        {
            npc_salyin_warmongerAI(Creature* creature) : ScriptedAI(creature) { }

            EventMap events;

            void IsSummonedBy(Unit* summoner) override
            {
                HandleInitCombat(me->GetGUID());
            }

            void Reset() override
            {
                events.Reset();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_EMPALLING, 50000);
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
                        case EVENT_EMPALLING:
                        {
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                me->CastSpell(target, SPELL_EMPALLING_PULL, true);

                            events.ScheduleEvent(EVENT_EMPALLING, 60000);
                            break;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_salyin_warmongerAI(creature);
        }
};

// Fire Shot 121673
class spell_galleon_fire_shot : public SpellScript
{
    PrepareSpellScript(spell_galleon_fire_shot);

    void CheckTargets(std::list<WorldObject*>& targets)
    {
        if (targets.size() > 3)
            Trinity::Containers::RandomResizeList(targets, (int)(targets.size() / 2));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_galleon_fire_shot::CheckTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

void AddSC_boss_galion()
{
    new boss_galion();
    new npc_salyin_skrimisher();
    new npc_salyin_warmonger();
    new spell_script<spell_galleon_fire_shot>("spell_galleon_fire_shot");
}
