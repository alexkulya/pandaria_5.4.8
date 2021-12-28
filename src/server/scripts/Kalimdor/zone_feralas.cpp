/*
 * Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2006-2014 ScriptDev2 <https://github.com/scriptdev2/scriptdev2/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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

enum ForceOfNatureTypes
{
    NPC_TREANT_CREDIT           = 40090,
    NPC_GIANT_CREDIT            = 43347,
    NPC_WANDERING_FOREST_WALKER = 7584,
    NPC_MOUNTAIN_GIANT          = 40026,

    ACTION_GIANT_CALLED = 0,
};

// Mountain Giant 40026
struct npc_feralas_mountain_giant : public CreatureAI
{
    npc_feralas_mountain_giant(Creature* creature) : CreatureAI(creature) { }

    TaskScheduler scheduler;
    bool hasCredit;

    void Reset() override
    {
        hasCredit = false;
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_GIANT_CALLED && !hasCredit)
        {
            hasCredit = true;

            scheduler
                .Schedule(Seconds(3), [this](TaskContext context)
            {
                // Move away!
                Position pos;
                me->GetNearPosition(pos, 10.0f, frand(0.0f, 2 * M_PI));
                me->SetWalk(true);
                me->GetMotionMaster()->MovePoint(0, pos);
                me->DespawnOrUnsummon(me->GetSplineDuration());
            });
        }
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

// Rally Wild Treant 74756
class spell_feralas_rally_wild_treant : public SpellScript
{
    PrepareSpellScript(spell_feralas_rally_wild_treant);

    void HandleEffectHit(SpellEffIndex /*effIndex*/)
    {
        if (Player* caster = GetCaster()->ToPlayer())
            if (Creature* target = GetHitCreature())
                if (target->GetEntry() == NPC_WANDERING_FOREST_WALKER)
                    caster->KilledMonsterCredit(NPC_TREANT_CREDIT);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_feralas_rally_wild_treant::HandleEffectHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Rally Wild Mountain Giant 80995
class spell_feralas_rally_wild_mountain_giant : public SpellScript
{
    PrepareSpellScript(spell_feralas_rally_wild_mountain_giant);

    void HandleEffectHit(SpellEffIndex /*effIndex*/)
    {
        if (Player* caster = GetCaster()->ToPlayer())
        {
            if (Creature* target = GetHitCreature())
            {
                target->AI()->DoAction(ACTION_GIANT_CALLED);

                if (target->GetEntry() == NPC_MOUNTAIN_GIANT)
                    caster->KilledMonsterCredit(NPC_GIANT_CREDIT);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_feralas_rally_wild_mountain_giant::HandleEffectHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_feralas()
{
    new creature_script<npc_feralas_mountain_giant>("npc_feralas_mountain_giant");
    new spell_script<spell_feralas_rally_wild_treant>("spell_feralas_rally_wild_treant");
    new spell_script<spell_feralas_rally_wild_mountain_giant>("spell_feralas_rally_wild_mountain_giant");
}
