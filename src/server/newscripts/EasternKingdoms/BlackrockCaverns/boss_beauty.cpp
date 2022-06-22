
#include "NewScriptPCH.h"
#include "blackrock_caverns.h"

//todo: реализовать касты щенков, берсерк при убийстве ранти, взрыв magma split
enum Spells
{
	SPELL_BERSERK				= 82395,
	SPELL_BERSERKER_CHARGE		= 76030,
	SPELL_BERSERKER_CHARGE_H	= 93580,
	SPELL_FLAMEBREAK			= 76032,
	SPELL_FLAMEBREAK_H			= 93583,
	SPELL_MAGMA_SPLIT			= 76031,
	SPELL_TERRIFYING_ROAR		= 76028,
	SPELL_TERRIFYING_ROAR_H		= 93586,
};

enum events
{
	EVENT_MAGMA_SPLIT		= 1,
	EVENT_TERRIFYING_ROAR	= 2,
	EVENT_FLAMEBREAK		= 3,
	EVENT_BERSERKER_CHARGE	= 4,
};

enum Adds
{
	NPC_SPOT	= 40011,
	NPC_BUSTER	= 40013,
	NPC_LUCKY	= 40008,
	NPC_RUNTY	= 40015,
};

const Position pupsPos[2] = 
{
	{116.70f, 572.05f, 76.45f, 0.04f},
	{119.81f, 588.90f, 76.35f, 6.22f}
};

class boss_beauty : public CreatureScript
{
 
public:
    boss_beauty() : CreatureScript("boss_beauty") { }
 
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_beautyAI (pCreature);
    }
 
    struct boss_beautyAI : public ScriptedAI
    {
        boss_beautyAI(Creature* c) : ScriptedAI(c), summons(me)
        {
			me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
			pInstance = (InstanceScript*)c->GetInstanceScript();
        }
 
        InstanceScript* pInstance;
		EventMap events;
		SummonList summons;
		//Creature* pups[2];

        void Reset()
        {
			summons.DespawnAll();
			//pups[0] = me->SummonCreature(NPC_SPOT, pupsPos[0]);
			//pups[1] = me->SummonCreature(NPC_BUSTER, pupsPos[1]);
			events.Reset();
            pInstance->SetData(DATA_BEAUTY, NOT_STARTED);
        }
 

        void EnterCombat(Unit* /*who*/) 
        {
			events.ScheduleEvent(EVENT_BERSERKER_CHARGE, 1000);
			events.ScheduleEvent(EVENT_FLAMEBREAK, 15000);
			events.ScheduleEvent(EVENT_MAGMA_SPLIT, 18000);
			events.ScheduleEvent(EVENT_TERRIFYING_ROAR, 30000);
            DoZoneInCombat();
            if (pInstance)
                pInstance->SetData(DATA_BEAUTY, IN_PROGRESS);
        }
 
        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

			if (me->GetDistance(me->GetHomePosition()) > 60.0f)
            {
                EnterEvadeMode();
                return;
            }

			events.Update(diff);

			if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
			
			while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
				{
				case EVENT_BERSERKER_CHARGE:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
						DoCast(target, DUNGEON_MODE(SPELL_BERSERKER_CHARGE, SPELL_BERSERKER_CHARGE_H));
					events.ScheduleEvent(EVENT_BERSERKER_CHARGE, 10000);
					break;
				case EVENT_FLAMEBREAK:
					DoCast(me, DUNGEON_MODE(SPELL_FLAMEBREAK, SPELL_FLAMEBREAK_H));
					events.ScheduleEvent(EVENT_FLAMEBREAK, 15000);
					break;
				case EVENT_MAGMA_SPLIT:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
						DoCast(target, SPELL_MAGMA_SPLIT);
					events.ScheduleEvent(EVENT_MAGMA_SPLIT, 18000);
					break;
				case EVENT_TERRIFYING_ROAR:
					DoCast(DUNGEON_MODE(SPELL_TERRIFYING_ROAR, SPELL_TERRIFYING_ROAR_H));
					events.ScheduleEvent(EVENT_TERRIFYING_ROAR, 30000);
					break;
				}
			}

            DoMeleeAttackIfReady();
        }
 
		void JustSummoned(Creature* summon)
		{
			summons.Summon(summon);
		}

		void SummonedCreatureDespawn(Creature* summon)
		{
			summons.Despawn(summon);
		}

        void JustDied(Unit* /*killer*/)
        {
			summons.DespawnAll();
            if (pInstance)
                pInstance->SetData(DATA_BEAUTY, DONE);
        }
    };
 
};
 
void AddSC_boss_beauty()
{
    new boss_beauty();
}
