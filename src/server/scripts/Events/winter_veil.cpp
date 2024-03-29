/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
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

#include "SceneMgr.h"
#include "SpellScript.h"
#include "PassiveAI.h"

enum
{
    SPELL_RACER_SLAM_FIND_TARGET            = 49299,
    SPELL_RACER_SLAM_HIT_DESTINATION        = 49302,
    SPELL_RACER_SLAM_HIT_TIMING_MISSILE     = 49324,
    SPELL_RACER_SLAM_DEATH_ROOT_AND_PACIFY  = 49439,
    SPELL_RACER_SLAM_DEATH_SCENE_GET_DEST   = 49353,
    SPELL_RACER_SLAM_DEATH_SCENE_PARENT     = 49337,
    SPELL_RACER_KILL_COUNTER                = 49444,
    SPELL_CANNON_DUMMY                      = 92690,    // Probably wrong spell
    SPELL_CANNON_DAMGE                      = 92694,    // Probably wrong spell

    NPC_CRASHIN_THRASHIN_RACER_BLUE         = 40281,
    NPC_CRASHIN_THRASHIN_RACER_RED          = 27664,
    NPC_CRASHIN_THRASHIN_FLYER              = 73743,
    NPC_CRASHIN_THRASHIN_DUMMY              = 27674,
};

// 49297 - Racer Rocket Slam
class spell_racer_slam_slamming : public SpellScript
{
    PrepareSpellScript(spell_racer_slam_slamming);

    void HandleCast()
    {
        auto check = [=](Unit* target)
        {
            if (!GetCaster()->IsInDist(target, 30))
                return false;
            return GetCaster()->HasInArc(M_PI / 6, target);
        };
        UnitList targets;
        Trinity::UnitListSearcher<decltype(check)> searcher{ GetCaster(), targets, check };
        GetCaster()->VisitNearbyObject(30, searcher);

        Unit* target = nullptr;
        for (auto&& itr : targets)
        {
            if (itr == GetCaster())
                continue;

            if (itr->GetEntry() == NPC_CRASHIN_THRASHIN_RACER_BLUE || itr->GetEntry() == NPC_CRASHIN_THRASHIN_RACER_RED)
            {
                target = itr->ToUnit();
                break;
            }
            if (itr->GetEntry() == NPC_CRASHIN_THRASHIN_DUMMY)
                target = itr->ToUnit();
        }

        if (target)
        {
            GetCaster()->CastSpell(target, SPELL_RACER_SLAM_HIT_DESTINATION, true);
            GetCaster()->CastSpell(target, SPELL_RACER_SLAM_HIT_TIMING_MISSILE, true);
        }
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_racer_slam_slamming::HandleCast);
    }
};

// 49325 - Racer Slam, resolve
class spell_racer_slam_hit_resolve : public SpellScript
{
    PrepareSpellScript(spell_racer_slam_hit_resolve);

    void SelectTarget(std::list<WorldObject*>& targets)
    {
        targets.remove_if([=](WorldObject const* target)
        {
            if (target == GetCaster())
                return true;
            return target->GetEntry() != NPC_CRASHIN_THRASHIN_RACER_BLUE && target->GetEntry() != NPC_CRASHIN_THRASHIN_RACER_RED;
        });

        targets.sort(Trinity::DistanceCompareOrderPred{ GetCaster() });
        if (!targets.empty())
            targets.resize(1);
    }

    void HandleHit(SpellEffIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_RACER_SLAM_DEATH_ROOT_AND_PACIFY, true);
        GetCaster()->CastSpell(GetCaster(), SPELL_RACER_KILL_COUNTER, true);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_RACER_SLAM_DEATH_SCENE_GET_DEST, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_racer_slam_hit_resolve::SelectTarget, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_racer_slam_hit_resolve::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 49353 - Racer Slam, death scene: car flip Get Dest
class spell_racer_slam_death_scene_car_flip_get_dest : public SpellScript
{
    PrepareSpellScript(spell_racer_slam_death_scene_car_flip_get_dest);

    Position pos;

    void HandleDest(SpellEffIndex)
    {
        pos = GetHitDest()->GetPosition();
    }

    void HandleScript(SpellEffIndex)
    {
        GetHitUnit()->CastSpell(pos, SPELL_RACER_SLAM_DEATH_SCENE_PARENT, true);
        if (Unit* player = GetHitUnit()->GetOwner())
        {
            uint32 spellId = GetHitUnit()->GetUInt32Value(UNIT_FIELD_CREATED_BY_SPELL);
            player->Schedule(Seconds(2), [=]()
            {
                player->RemoveAurasDueToSpell(spellId);
            });
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_racer_slam_death_scene_car_flip_get_dest::HandleDest, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnEffectHitTarget += SpellEffectFn(spell_racer_slam_death_scene_car_flip_get_dest::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 148581 - Rocket Attack
class spell_rocket_attack : public SpellScript
{
    PrepareSpellScript(spell_rocket_attack);

    void SelectTarget(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            GetCaster()->CastSpell(GetCaster(), SPELL_CANNON_DUMMY, true);
        else
            GetCaster()->CastSpell(GetCaster(), SPELL_CANNON_DAMGE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_rocket_attack::SelectTarget, EFFECT_0, TARGET_UNIT_CONE_ENTRY);
    }
};

// 73743
struct npc_crashing_thrashin_flyer : public NullCreatureAI
{
    npc_crashing_thrashin_flyer(Creature* c) : NullCreatureAI(c)
    {
        me->AddUnitMovementFlag(MOVEMENTFLAG_FLYING);
        me->SetMaxHealth(100);
        me->SetHealth(100);
        me->setRegeneratingHealth(false);
    }

    void Unsummoned() override
    {
        if (Unit* player = me->GetOwner())
            player->RemoveAurasDueToSpell(me->GetUInt32Value(UNIT_FIELD_CREATED_BY_SPELL));
    }

    void JustDied(Unit* killer) override
    {
        if (Player* player = killer->GetAffectingPlayer())
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE, me->GetEntry(), 1, 0, me);
    }
};

void AddSC_event_winter_veil()
{
    register_spell_script(spell_racer_slam_slamming);
    register_spell_script(spell_racer_slam_hit_resolve);
    register_spell_script(spell_racer_slam_death_scene_car_flip_get_dest);
    register_spell_script(spell_rocket_attack);
    register_creature_script(npc_crashing_thrashin_flyer);
}
