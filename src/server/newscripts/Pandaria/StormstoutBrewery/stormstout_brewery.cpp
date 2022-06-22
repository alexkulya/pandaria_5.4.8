/*
    Dungeon : Stormstout Brewery 85-87
    Instance General Script
*/

#include "NewScriptPCH.h"
#include "stormstout_brewery.h"

enum eEvents
{
    EVENT_WP_1      = 1,
    EVENT_WP_2      = 2,
    EVENT_WP_3      = 3,
    EVENT_WP_4      = 4,
};

const Position ePos[6] =
{
    {-717.66f, 1308.82f, 163.0f},
    {-748.75f, 1321.84f, 163.0f},
    {-770.68f, 1281.18f, 163.0f},
    {-761.24f, 1247.89f, 163.0f},
    {-758.56f, 1237.43f, 163.0f},
    {-775.34f, 1215.79f, 169.0f},
};

class npc_hopling : public CreatureScript
{
    public:
        npc_hopling() : CreatureScript("npc_hopling") {}

        struct npc_hoplingAI : public ScriptedAI
        {
            npc_hoplingAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                move = false;
            }

            InstanceScript* instance;
            EventMap events;
            bool move;

            void IsSummonedBy(Unit* owner)
            {
                if (owner->GetEntry() == NPC_TRIGGER_SUMMONER)
                {
                    move = true;
                    me->setFaction(14);
                    me->GetMotionMaster()->MovePoint(1, ePos[0]);
                }
            }

            void EnterEvadeMode()
            {
                me->DespawnOrUnsummon();
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
                            me->GetMotionMaster()->MoveJump(ePos[5].GetPositionX() + irand(-10, 10), ePos[5].GetPositionY() + irand(-10, 10), ePos[5].GetPositionZ(), 15, 15);
                            me->DespawnOrUnsummon(1000);
                            break;
                    }
                }
            }

            void SpellHit(Unit* caster, SpellInfo const* spell)
            {
                if (instance)
                {
                    if (spell->Id == SPELL_SMASH_DMG)
                    {
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->GetMotionMaster()->MoveJump(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 20, 10, 18);    

                        uint32 HoplingCount = instance->GetData(DATA_HOPLING) + 1;
                        instance->SetData(DATA_HOPLING, HoplingCount);
                        if (HoplingCount == 100)
                            DoCast(SPELL_SMASH_ACHIEV);
                        TC_LOG_ERROR("server", "HoplingCount %u", HoplingCount);
                        me->DespawnOrUnsummon(1000);
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim() && !move)
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
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_hoplingAI(creature);
        }
};

class npc_golden_hopling : public CreatureScript
{
    public:
        npc_golden_hopling() : CreatureScript("npc_golden_hopling") {}

        struct npc_golden_hoplingAI : public Scripted_NoMovementAI
        {
            npc_golden_hoplingAI(Creature* creature) : Scripted_NoMovementAI(creature)
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
                    uint32 GoldenHoplingCount = instance->GetData(DATA_GOLDEN_HOPLING) + 1;
                    instance->SetData(DATA_GOLDEN_HOPLING, GoldenHoplingCount);
                    if (GoldenHoplingCount >= 30)
                        DoCast(SPELL_GOLDEN_VERMING_ACHIEV);
                    me->DespawnOrUnsummon();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_golden_hoplingAI(creature);
        }
};

class npc_big_ol_hammer : public CreatureScript
{
    public:
        npc_big_ol_hammer() : CreatureScript("npc_big_ol_hammer") {}

        struct npc_big_ol_hammerAI : public Scripted_NoMovementAI
        {
            npc_big_ol_hammerAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                instance = creature->GetInstanceScript();
                OneClick = false;
            }

            InstanceScript* instance;
            bool OneClick;
            
            void OnSpellClick(Unit* clicker)
            {
                if (instance && !OneClick)
                {
                    OneClick = true;

                    for (uint8 i = 0; i < 3; ++i)
                        clicker->CastSpell(clicker, SPELL_SMASH_OVERRIDE);

                    me->DespawnOrUnsummon();
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_big_ol_hammerAI(creature);
        }
};

class spell_stormstout_brewery_habanero_beer : public SpellScriptLoader
{
    public:
        spell_stormstout_brewery_habanero_beer() : SpellScriptLoader("spell_stormstout_brewery_habanero_beer") { }

        class spell_stormstout_brewery_habanero_beer_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_stormstout_brewery_habanero_beer_SpellScript);

            void HandleInstaKill(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster())
                    return;

                std::list<Creature*> creatureList;

                GetCreatureListWithEntryInGrid(creatureList, GetCaster(), NPC_BARREL, 10.0f);

                GetCaster()->RemoveAurasDueToSpell(SPELL_PROC_EXPLOSION);

                for (std::list<Creature*>::const_iterator itr = creatureList.begin(); itr != creatureList.end(); ++itr)
                {
                    if ((*itr)->HasAura(SPELL_PROC_EXPLOSION))
                    {
                        (*itr)->RemoveAurasDueToSpell(SPELL_PROC_EXPLOSION);
                        (*itr)->CastSpell(*itr, GetSpellInfo()->Id, true);
                    }
                }
            }

            void HandleAfterCast()
            {
                if (Unit* caster = GetCaster())
                    if (caster->ToCreature())
                        caster->ToCreature()->ForcedDespawn(1000);
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_stormstout_brewery_habanero_beer_SpellScript::HandleInstaKill, EFFECT_1, SPELL_EFFECT_INSTAKILL);
                AfterCast += SpellCastFn(spell_stormstout_brewery_habanero_beer_SpellScript::HandleAfterCast);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_stormstout_brewery_habanero_beer_SpellScript();
        }
};

class spell_hopling_summoner : public SpellScriptLoader
{
    public:
        spell_hopling_summoner() : SpellScriptLoader("spell_hopling_summoner") { }
 
        class spell_hopling_summoner_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_hopling_summoner_AuraScript)

            void OnPeriodic(AuraEffect const* aurEff)
            {
                if (!GetCaster())
                    return;

                GetCaster()->CastSpell(GetCaster(), SPELL_HOPLING_SUMM_3);
            }
 
            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_hopling_summoner_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };
 
        AuraScript* GetAuraScript() const
        {
            return new spell_hopling_summoner_AuraScript();
        }
};

void AddSC_stormstout_brewery()
{
    new npc_hopling();
    new npc_golden_hopling();
    new npc_big_ol_hammer();
    new spell_stormstout_brewery_habanero_beer();
    new spell_hopling_summoner();
}