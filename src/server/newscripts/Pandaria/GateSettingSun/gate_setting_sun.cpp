/*
    Dungeon : Gate of the Setting Sun 90 Heroic
    Instance General Script
*/

#include "gate_setting_sun.h"
#include "NewScriptPCH.h"

enum spells
{
    SPELL_MANTID_MUNITION_EXPLOSION     = 107153,
    SPELL_EXPLOSE_GATE                  = 115456,

    SPELL_BOMB_CAST_VISUAL              = 106729,
    SPELL_BOMB_AURA                     = 106875,
    
    SPELL_RESIN_RESIDUE                 = 118795,
    SPELL_ACHIEVEMENT_COMPLETE          = 118797,
};


class npc_krikthik_bombarder : public CreatureScript
{
public:
    npc_krikthik_bombarder() : CreatureScript("npc_krikthik_bombarder") { }

    struct npc_krikthik_bombarderAI : public ScriptedAI
    {
        npc_krikthik_bombarderAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;
        uint32 bombTimer;

        void Reset()
        {
            me->GetMotionMaster()->MoveRandom(5.0f);
            bombTimer = urand(1000, 7500);
        }

        // Called when spell hits a target
        void SpellHitTarget(Unit* target, SpellInfo const* /*spell*/)
        {
            if (target->GetEntry() == NPC_BOMB_STALKER)
                me->AddAura(SPELL_BOMB_AURA, target);
        }

        void UpdateAI(uint32 diff)
        {
            if (bombTimer <= diff)
            {
                if (Unit* stalker = pInstance->instance->GetCreature(pInstance->GetData64(DATA_RANDOM_BOMB_STALKER)))
                    if (!stalker->HasAura(SPELL_BOMB_AURA))
                        me->CastSpell(stalker, SPELL_BOMB_CAST_VISUAL, true);

                bombTimer = urand(1000, 5000);
            }
            else bombTimer -= diff;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_krikthik_bombarderAI (creature);
    }
};

class npc_krikthik_conscript : public CreatureScript
{
public:
    npc_krikthik_conscript() : CreatureScript("npc_krikthik_conscript") { }

    struct npc_krikthik_conscriptAI : public ScriptedAI
    {
        npc_krikthik_conscriptAI(Creature* creature) : ScriptedAI(creature)
        {
            pInstance = creature->GetInstanceScript();
        }

        InstanceScript* pInstance;

        void Reset()
        {
        }
        
        void JustDied(Unit* killer)
        {
            me->CastSpell(killer, SPELL_RESIN_RESIDUE, true);
        }
        
        void DamageTaken(Unit* attacker, uint32 &damage)
        {
            if (attacker->ToCreature() && me->HealthBelowPct(85))
                damage = 0;
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_krikthik_conscriptAI (creature);
    }
};

class spell_resin_residue : public SpellScriptLoader
{
    public:
        spell_resin_residue() : SpellScriptLoader("spell_resin_residue") { }

        class spell_resin_residue_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_resin_residue_AuraScript);

            void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if(!target)
                    return;
                
                if (Aura* aura = target->GetAura(SPELL_RESIN_RESIDUE))
                    if (aura->GetStackAmount() > 2)
                        target->CastSpell(target, SPELL_ACHIEVEMENT_COMPLETE, true);
            }

            void Register()
            {
                OnEffectApply += AuraEffectApplyFn(spell_resin_residue_AuraScript::OnApply, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAPPLY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_resin_residue_AuraScript();
        }
};

//8359
class AreaTrigger_at_first_door : public AreaTriggerScript
{
    public:
        AreaTrigger_at_first_door() : AreaTriggerScript("at_first_door") {}

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/, bool apply)
        {
            if (player->GetInstanceScript())
                player->GetInstanceScript()->SetData(DATA_OPEN_FIRST_DOOR, DONE);

            return false;
        }
};

class go_setting_sun_brasier : public GameObjectScript
{
public:
    go_setting_sun_brasier() : GameObjectScript("go_setting_sun_brasier") { }

    bool OnGossipHello(Player* player, GameObject* /*go*/)
    {
        if (player->GetInstanceScript())
            player->GetInstanceScript()->SetData(DATA_BRASIER_CLICKED, DONE);

        return false;
    }
};

class go_setting_sun_temp_portal : public GameObjectScript
{
public:
    go_setting_sun_temp_portal() : GameObjectScript("go_setting_sun_temp_portal") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        switch (go->GetEntry())
        {
            case 400001:
                player->NearTeleportTo(1078.96f, 2305.48f, 381.55f, 0.01f);
                break;
            case 400002:
                if (go->GetPositionZ() < 400.0f)
                    player->NearTeleportTo(go->GetPositionX(), go->GetPositionY(), 431.0f, go->GetOrientation());
                else
                    player->NearTeleportTo(go->GetPositionX(), go->GetPositionY(), 388.5f, go->GetOrientation());
                break;
        }

        return false;
    }
};

void AddSC_gate_setting_sun()
{
    new npc_krikthik_bombarder();
    new npc_krikthik_conscript();
    new spell_resin_residue();
    new AreaTrigger_at_first_door();
    new go_setting_sun_brasier();
    new go_setting_sun_temp_portal();
}
