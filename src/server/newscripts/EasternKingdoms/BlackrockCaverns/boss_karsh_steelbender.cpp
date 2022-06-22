#include "NewScriptPCH.h"
#include "blackrock_caverns.h"

//todo: сделать скалирование дамага от стаков брони
enum ScriptTexts
{
	SAY_AGGRO	= 0,
	SAY_KILL	= 1,
	SAY_BURN	= 2,
	SAY_DEATH	= 3,
};
enum Spells
{
	SPELL_CLEAVE							= 15284,
	SPELL_QUICKSILVER_ARMOR					= 75842,
	SPELL_HEAT_WAVE							= 75851,
	SPELL_SUPERHEATED_QUICKSILVER_ARMOR		= 75846,
	SPELL_SUPERHEATED_QUICKSILVER_ARMOR_0	= 76015,

    SPELL_BURNING                           = 77490,
};

enum Events
{
	EVENT_CLEAVE		= 1,
	EVENT_HEAT_ARMOR	= 2,
};

enum Adds
{
    NPC_BOUND_FLAMES    = 50417,
};

const Position centerkarshPos = {237.84f, 784.76f, 95.67f, 1.95f};

class boss_karsh_steelbender : public CreatureScript
{
    public:
        boss_karsh_steelbender() : CreatureScript("boss_karsh_steelbender") { }
     
        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_karsh_steelbenderAI (pCreature);
        }
     
        struct boss_karsh_steelbenderAI : public ScriptedAI
        {
            boss_karsh_steelbenderAI(Creature* c) : ScriptedAI(c)
            {
			    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
			    pInstance = c->GetInstanceScript();
            }
     
            InstanceScript* pInstance;
		    EventMap events;
		    bool bHeat;


            void Reset()
            {
			    events.Reset();
			    DoCast(me, SPELL_QUICKSILVER_ARMOR);
			    bHeat = false;
                if (pInstance)
                    pInstance->SetData(DATA_KARSH, NOT_STARTED);
            }


            void EnterCombat(Unit* /*who*/) 
            {
			    events.ScheduleEvent(EVENT_CLEAVE, urand(5000, 7000));
			    events.ScheduleEvent(EVENT_HEAT_ARMOR, 1000);
			    Talk(SAY_AGGRO);
                DoZoneInCombat();
                if (pInstance)
                    pInstance->SetData(DATA_KARSH, IN_PROGRESS);
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
     
			    if (me->GetDistance(centerkarshPos) <= 6.0f)
				    bHeat = true;
			    else
				    bHeat = false;

			    if (!me->HasAura(SPELL_QUICKSILVER_ARMOR) && !me->HasAura(SPELL_SUPERHEATED_QUICKSILVER_ARMOR))
				    DoCast(me, SPELL_QUICKSILVER_ARMOR);
			    if (me->HasAura(SPELL_SUPERHEATED_QUICKSILVER_ARMOR))
				    me->RemoveAurasDueToSpell(SPELL_QUICKSILVER_ARMOR);

                events.Update(diff);

			    if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
    			
			    while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
				    case EVENT_CLEAVE:
					    DoCast(me->getVictim(), SPELL_CLEAVE);
					    events.ScheduleEvent(EVENT_CLEAVE, urand(5000, 7000));
					    break;
				    case EVENT_HEAT_ARMOR:
					    if (bHeat)
					    {
						    DoCast(me, SPELL_HEAT_WAVE);
						    DoCast(me, SPELL_SUPERHEATED_QUICKSILVER_ARMOR);
					    }
					    events.ScheduleEvent(EVENT_HEAT_ARMOR, 1000);
					    break;
				    }
			    }
      
                DoMeleeAttackIfReady();
            }
     
            void JustDied(Unit* /*killer*/)
            {
			    Talk(SAY_DEATH);
                if (pInstance)
                    pInstance->SetData(DATA_KARSH, DONE);
            }
     
            void KilledUnit(Unit * victim)
            {
			    Talk(SAY_KILL);
            }
        };
};

class achievement_too_hot_to_handle : public AchievementCriteriaScript
{
    public:
        achievement_too_hot_to_handle() : AchievementCriteriaScript("achievement_too_hot_to_handle") { }

        bool OnCheck(Player* source, Unit* creature)
        {
            if (creature)
                if (Aura* aura = creature->GetAura(SPELL_SUPERHEATED_QUICKSILVER_ARMOR))
                    if (aura->GetStackAmount() >= 15)
                        return true;

            return false;
        }
};

void AddSC_boss_karsh_steelbender()
{
    new boss_karsh_steelbender();
    new achievement_too_hot_to_handle();
}
