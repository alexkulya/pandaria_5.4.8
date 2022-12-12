#include "NewScriptPCH.h"
#include "blackrock_caverns.h"

//todo: реализовать призыв о помощи
//todo: реализовать комбо цепи+аое

enum ScriptTexts
{
	SAY_AGGRO	= 0,
	SAY_KILL	= 1,
	SAY_CHAINS	= 2,
	SAY_DEATH	= 3,
};

enum Spells
{
    SPELL_CALL_FOR_HELP                         = 82137,
    SPELL_CHAINS_OF_WOE                         = 75539,
    SPELL_WOUNDING_STRIKE                       = 75571,
    SPELL_WOUNDING_STRIKE_H                     = 93452,
    SPELL_THE_SKULLCRACKER                      = 75543,
    SPELL_THE_SKULLCRACKER_H                    = 93453,
    SPELL_QUAKE                                 = 75272,
    SPELL_SKULLCRACKER                          = 95326,
	SPELL_CHAINS_OF_WOE_0                       = 75441,
	SPELL_CHAINS_OF_WOE_1						= 82189,
	SPELL_CHAINS_OF_WOE_ROOT					= 82189,
	SPELL_CHAINS_OF_WOE_TELE					= 75437,
	SPELL_CHAINS_OF_WOE_TELE_0					= 75464,
};
 
enum Adds
{
	NPC_QUAKE									= 40401,
    NPC_CHAINS_OF_WOE                           = 40447,
    NPC_ANGERED_EARTH                           = 50376,
}; 

enum Events
{
	EVENT_WOUNDING_STRIKE	= 1,
	EVENT_QUAKE				= 2,
	EVENT_CHAINS_OF_WOE		= 3,
	EVENT_SKULLCRACKER		= 4,
};
 
class boss_romogg_bonecrusher : public CreatureScript
{
    public:
        boss_romogg_bonecrusher() : CreatureScript("boss_romogg_bonecrusher") { }
     
        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_romogg_bonecrusherAI (pCreature);
        }
     
        struct boss_romogg_bonecrusherAI : public ScriptedAI
        {
            boss_romogg_bonecrusherAI(Creature* c) : ScriptedAI(c), summons(me)
            {
			    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
			    me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);   
			    pInstance = (InstanceScript*)c->GetInstanceScript();
            }
     
            InstanceScript* pInstance;
		    EventMap events;
            SummonList summons;
		    uint8 stage;

            void Reset()
            {
			    stage = 0;
			    events.Reset();
                summons.DespawnAll();
                if (pInstance)
                    pInstance->SetData(DATA_ROMOGG, NOT_STARTED);
            }
     
            void JustSummoned(Creature* summon)
            {

			    summons.Summon(summon);
			    switch (summon->GetEntry())
			    {
			    case NPC_ANGERED_EARTH:
				    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
				    {
					    summon->AddThreat(target, 10.0f);
					    summon->Attack(target, true);
					    summon->GetMotionMaster()->MoveChase(target);
				    }
				    break;
			    }        
            }

            void EnterCombat(Unit* /*who*/) 
            {
			    DoCast(me, SPELL_CALL_FOR_HELP);
			    Talk(SAY_AGGRO);
			    events.ScheduleEvent(EVENT_WOUNDING_STRIKE, urand(5000, 7000));
			    events.ScheduleEvent(EVENT_QUAKE, urand(18000, 20000));
                DoZoneInCombat();
                if (pInstance)
                    pInstance->SetData(DATA_ROMOGG, IN_PROGRESS);
                
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

			    /*if (me->GetHealthPct() <= 66 && stage == 0)
			    {
				    events.Reset();
				    stage = 1;
				    DoCast(SPELL_CHAINS_OF_WOE);
				    events.ScheduleEvent(EVENT_SKULLCRACKER, 2100);
			    }

			    if (me->GetHealthPct() <= 33 && stage == 1)
			    {
				    events.Reset();
				    stage = 2;
				    DoCast(SPELL_CHAINS_OF_WOE);
				    events.ScheduleEvent(EVENT_SKULLCRACKER, 2100);
			    }*/

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
    			
			    while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
				    case EVENT_WOUNDING_STRIKE:
					    DoCast(me->getVictim(), DUNGEON_MODE(SPELL_WOUNDING_STRIKE, SPELL_WOUNDING_STRIKE_H));
					    events.ScheduleEvent(EVENT_WOUNDING_STRIKE, urand(6000, 7000));
					    break;
				    case EVENT_QUAKE:
					    DoCast(me, SPELL_QUAKE);
					    if (IsHeroic())
					    {
						    Map::PlayerList const& players = me->GetMap()->GetPlayers();
						    if (me->GetMap()->IsDungeon() && !players.isEmpty())
						    {
							    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
							    {
								    Player* pPlayer = itr->getSource();
								     me->SummonCreature(NPC_ANGERED_EARTH, pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(),0.0f, TEMPSUMMON_CORPSE_DESPAWN, 0);
							    }
      					    }  
					    }
					    events.ScheduleEvent(EVENT_QUAKE, urand(18000, 20000));
					    break;
				    }
			    }

			    DoMeleeAttackIfReady();  
            }
     
            void JustDied(Unit* /*killer*/)
            {
			    Talk(SAY_DEATH);
                summons.DespawnAll();
                if (pInstance)
                    pInstance->SetData(DATA_ROMOGG, DONE);
            }
     
            void KilledUnit(Unit * victim)
            {
			    Talk(SAY_KILL);
            }
        };
};
 
/*class npc_chains_of_woe : public CreatureScript
{
    public:
        npc_chains_of_woe() : CreatureScript("npc_chains_of_woe") { }
     
        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new npc_chains_of_woeAI (pCreature);
        }
     
        struct npc_chains_of_woeAI : public ScriptedAI
        {
            npc_chains_of_woeAI(Creature *c) : ScriptedAI(c) 
		    {
			    pInstance = c->GetInstanceScript();
		    }
     
		    InstanceScript* pInstance;

            void Reset()
            {
			    DoCast(me, SPELL_CHAINS_OF_WOE_TELE);
			    DoCast(me, SPELL_CHAINS_OF_WOE);

            }
     
            void UpdateAI(uint32 diff)
            {
                if (!pInstance || !UpdateVictim())
                    return;
		    }
        };
 
};*/

/*class spell_romoogg_chains_of_woe : public SpellScriptLoader
{
    public:
        spell_romoogg_chains_of_woe : SpellScriptLoader("spell_romoogg_chains_of_woe") { }

        class spell_romoogg_chains_of_woe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_romoogg_chains_of_woe_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
				if (GetHitUnit())
					GetHitUnit()->CastSpell(GetHitUnit(), SPELL_CHAINS_OF_WOE_ROOT);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_romoogg_chains_of_woe_rootSpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_romoogg_chains_of_woe_SpellScript();
        }
};*/

/*class spell_romoogg_chains_of_woe_tele : public SpellScriptLoader
{
    public:
        spell_romoogg_chains_of_woe_tele : SpellScriptLoader("spell_romoogg_chains_of_woe_tele") { }

        class spell_romoogg_chains_of_woe_tele_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_romoogg_chains_of_woe_tele_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
				if (GetHitUnit() && GetCaster())
				{
					if (GetHitUnit()->GetTypeId() != TYPEID_PLAYER)
						return;
					GetHitUnit()->ToPlayer()->TeleportTo(645,
						GetCaster()->GetPositionX(),
						GetCaster()->GetPositionY(),
						GetCaster()->GetPositionZ(),
						0.0f);
				}
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_romoogg_chains_of_woe_tele_rootSpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_romoogg_chains_of_woe_tele_SpellScript();
        }
};*/

void AddSC_boss_romogg_bonecrusher()
{
    new boss_romogg_bonecrusher();
    //new npc_chains_of_woe();
	//new spell_romoogg_chains_of_woe();
	//new spell_romoogg_chains_of_woe_tele();
}
