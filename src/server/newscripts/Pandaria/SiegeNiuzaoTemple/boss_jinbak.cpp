/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "NewScriptPCH.h"
#include "siege_of_the_niuzoa_temple.h"

enum eSpells
{
    SPELL_SUMMON_GLOBULE    = 119990,
    SPELL_DETONATE          = 120001,

    SPELL_SAP_PUDDLE        = 119939,
    SPELL_VISUAL_SHIELD     = 131628,
    SPELL_SAP_RESIDUE       = 119941, // DOT
    SPELL_GROW              = 120865,
};

enum eEvents
{
    EVENT_GROW              = 1,
};

enum Actions
{
    ACTION_COMBAT  = 0,
    ACTION_EVADE   = 1,
    ACTION_EXPLOSE = 2,
    ACTION_DONE    = 3,
};

class boss_jinbak : public CreatureScript
{
    public:
        boss_jinbak() : CreatureScript("boss_jinbak") {}

        struct boss_jinbakAI : public BossAI
        {
            boss_jinbakAI(Creature* creature) : BossAI(creature, DATA_JINBAK)
            {
                me->ApplySpellImmune(119941, 0, 0, true);
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            uint32 ExploseTimer;

            void Reset()
            {
                _Reset();
                me->GetMotionMaster()->MovePoint(0, 1536.54f, 5170.002f, 158.89f);
                if (Creature* puddle = me->GetCreature(*me, instance->GetData64(NPC_PUDDLE)))
                    puddle->AI()->DoAction(ACTION_EVADE);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                if (Creature* puddle = me->GetCreature(*me, instance->GetData64(NPC_PUDDLE)))
                    puddle->AI()->DoAction(ACTION_COMBAT);
                ExploseTimer = 60000;
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (ExploseTimer <= diff)
                {
                    if (Creature* puddle = me->GetCreature(*me, instance->GetData64(NPC_PUDDLE)))
                        puddle->AI()->DoAction(ACTION_EXPLOSE);
                    ExploseTimer = 60000;
                }
                else
                    ExploseTimer -= diff;

                DoMeleeAttackIfReady();
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                if (Creature* puddle = me->GetCreature(*me, instance->GetData64(NPC_PUDDLE)))
                    puddle->AI()->DoAction(ACTION_DONE);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_jinbakAI(creature);
        }
};

class npc_puddle : public CreatureScript
{
    public:
        npc_puddle() : CreatureScript("npc_puddle") {}

        struct npc_puddleAI : public ScriptedAI
        {
            npc_puddleAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_DISABLE_MOVE);
            }

            InstanceScript* instance;
            uint32 modradius;

            void Reset()
            {
                me->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.4f); //Base Scale 0.4f
                me->AddAura(119939, me);
                modradius = 0;
            }

            void SpellHitTarget(Unit* target, SpellInfo const* spell)
            {
                if (spell->Id == 119941 && target->GetTypeId() == TYPEID_PLAYER)
                {
                    if (me->GetFloatValue(OBJECT_FIELD_SCALE_X) >= 0.7f)
                        me->SetFloatValue(OBJECT_FIELD_SCALE_X, me->GetFloatValue(OBJECT_FIELD_SCALE_X) - 0.3f);
                    else
                        me->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.4f);

                    me->CastSpell(target, 120593);
                }
            }

            void DoAction(const int32 action)
            {
                switch(action)
                {
                case ACTION_COMBAT:
                    modradius = 5000;
                    break;
                case ACTION_EVADE:
                    modradius = 0;
                    me->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.4f);
                    break;
                case ACTION_EXPLOSE:
                    {
                        int32 dmg = 0; 
                        if (me->GetFloatValue(OBJECT_FIELD_SCALE_X) == 0.4f)
                            dmg = 40000;
                        else if (me->GetFloatValue(OBJECT_FIELD_SCALE_X) > 0.4f)
                            dmg = (me->GetFloatValue(OBJECT_FIELD_SCALE_X) - 0.4f)*10*40000;
                        
                        if (dmg)
                            me->CastCustomSpell(120002, SPELLVALUE_BASE_POINT0, dmg);
                    }
                    break;
                case ACTION_DONE:
                    me->RemoveAura(119939);
                    me->DespawnOrUnsummon(1000);
                    break;
                }
            }

            void EnterEvadeMode(){}

            void EnterCombat(Unit* who){}

            void UpdateAI(uint32 diff)
            {
                if (modradius)
                {
                    if (modradius <= diff)
                    { 
                        me->SetFloatValue(OBJECT_FIELD_SCALE_X, me->GetFloatValue(OBJECT_FIELD_SCALE_X) + 0.1f);
                        modradius = 5000;
                    }
                    else 
                        modradius -= diff;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_puddleAI(creature);
        }
};

class ExactDistanceCheck
{
    public:
        ExactDistanceCheck(WorldObject* source, float dist) : _source(source), _dist(dist) {}

        bool operator()(WorldObject* unit)
        {
            return _source->GetExactDist2d(unit) > _dist;
        }

    private:
        WorldObject* _source;
        float _dist;
};

class spell_sap_puddle : public SpellScriptLoader
{
    public:
        spell_sap_puddle() : SpellScriptLoader("spell_sap_puddle") { }

        class spell_sap_puddle_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sap_puddle_SpellScript);

            void ScaleRange(std::list<WorldObject*>&targets)
            {
                targets.remove_if(ExactDistanceCheck(GetCaster(), 16.0f * GetCaster()->GetFloatValue(OBJECT_FIELD_SCALE_X)));
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sap_puddle_SpellScript::ScaleRange, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_sap_puddle_SpellScript();
        }
};


void AddSC_boss_jinbak()
{
    new boss_jinbak();
    new npc_puddle();
    new spell_sap_puddle();
}
