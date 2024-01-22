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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "timeless_isle.h"

enum XuenSpellData
{
    SPELL_AGILITY                           = 144631,
    SPELL_CHI_BARRAGE_MISSLE                = 144643,
    SPELL_CHI_BARRAGE                       = 144642,
    SPELL_CHI_BARRAGE_EFF                   = 144644,
    SPELL_CRACKLING_LIGHTNING               = 144635,
    SPELL_CRACKLING_LIGHTNING_SELECTOR      = 144634,
    SPELL_CRACKLING_LIGHTNING_EFF           = 144633,
    SPELL_LEAP                              = 144640,
    SPELL_SPECTRAL_SWIPE_TRIGGER            = 144652,
    SPELL_SPECTRAL_SWIPE                    = 144638
};

enum XuenEvents
{
    EVENT_SPECTRAL_SWIPES                   = 1,
    EVENT_CHI_BARRAGE_AOE,
    EVENT_CRACKLING_LIGHTNING,
    EVENT_AGILITY_SELF_BUFF,
    EVENT_LEAP,
    EVENT_DEFEATED,
    EVENT_DEATH ,
    EVENT_SHAO_DO_INTRO,
    EVENT_SHAO_DO_INTRO_ATTACKABLE,
    EVENT_SHAO_DO_OUTRO,
    EVENT_TIMER_HEALTH_POOL
};

enum XuenTexts
{
    SAY_AGGRO,
    SAY_INTRO,
    SAY_DEATH,
    SAY_KILL,
    SAY_AGILITY,
    SAY_CHI,
    SAY_CRACKLING
};

enum XuenTimers
{
    TIMER_SPECTRAL_SWIPES                   = 5000,
    TIMER_CHI_BARRAGE_AOE                   = 20000,
    TIMER_CRACKLING_LIGHTNING               = 30000,
    TIMER_AGILITY_SELF_BUFF                 = 40000,
    TIMER_LEAP                              = 30000,
    TIMER_DEFEATED                          = 1000
};

enum XuenActions
{
    ACTION_DEFEATED = 0,
};

struct boss_xuen : public ScriptedAI
{
    boss_xuen(Creature* creature) : ScriptedAI(creature), summons(me) 
    {
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }

    bool death = false;
    SummonList summons;
    EventMap events, nonCombatEvents;

    void Reset() override
    {
        events.Reset();

        me->SetCombatDistance(500.0f);

        if (me->GetFaction() == FACTION_HOSTILE_NEUTRAL)
            me->SetFacingTo(MIDDLE_FACING_ANGLE);

        me->SetWalk(true);
        me->setActive(true);

        me->ResetPlayerDamageReq();
        me->SetLootRecipient(nullptr);

        HandleDoor(me, GO_CELESTIAL_DOOR, true);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        UpdateHealth(me);
        me->SetWalk(false);
        death = false;
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_TIMER_HEALTH_POOL, 1s);
        events.ScheduleEvent(EVENT_CHI_BARRAGE_AOE, 28s);
        events.ScheduleEvent(EVENT_AGILITY_SELF_BUFF, 39s);
        events.ScheduleEvent(EVENT_CRACKLING_LIGHTNING, 42s);
        events.ScheduleEvent(EVENT_SPECTRAL_SWIPES, randtime(5s, 15s));
        events.ScheduleEvent(EVENT_LEAP, 16s);
        HandleDoor(me, GO_CELESTIAL_DOOR, false);
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        if (death)
            damage = 0;

        if (!me->HasLootRecipient())
            me->SetLootRecipient(attacker);

        if (damage >= me->GetHealth() && !death)
        {
            death = true;

            damage = 0;
            Talk(SAY_DEATH);

            RewardPlayers(me);

            me->SetFaction(FACTION_FRIENDLY);

            me->StopMoving();
            me->RemoveAllAuras();
            me->GetMotionMaster()->Clear();
            me->CombatStop(true);
            me->SetHealth(391000000/*me->GetMaxHealth()*/);

            me->SetFacingTo(MIDDLE_FACING_ANGLE);
            me->DeleteThreatList();

            events.Reset();
            nonCombatEvents.ScheduleEvent(EVENT_SHAO_DO_OUTRO, 10s);
            nonCombatEvents.ScheduleEvent(EVENT_DEATH, 13s);
            death = true;

            HandleDoor(me, GO_CELESTIAL_DOOR, true);
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (pointId == EVENT_JUMP)
            DoCast(me, SPELL_SPECTRAL_SWIPE_TRIGGER);

        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == 1)
        {
            nonCombatEvents.ScheduleEvent(EVENT_SHAO_DO_INTRO, CELESTIAL_COURT_BOSS_INTRO_TIMER_1);
            me->SetFacingTo(MIDDLE_FACING_ANGLE);
            me->SetFaction(FACTION_HOSTILE_NEUTRAL);
            me->SetHomePosition(_timelessIsleMiddle);
        }
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
        {
            Talk(SAY_KILL);
            return;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
    }

    void EnterEvadeMode() override
    {
        me->AddUnitState(UNIT_STATE_EVADE);

        ScriptedAI::EnterEvadeMode();
        summons.DespawnAll();
        events.Reset();
        me->RemoveAllAreasTrigger();
        me->GetMotionMaster()->MoveTargetedHome();
        me->SetLootRecipient(nullptr);
        HandleDoor(me, GO_CELESTIAL_DOOR, true);
    }

    void UpdateAI(uint32 diff) override
    {
        nonCombatEvents.Update(diff);

        while (uint32 eventId = nonCombatEvents.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHAO_DO_INTRO:
                {
                    Talk(SAY_INTRO);
                    nonCombatEvents.ScheduleEvent(EVENT_SHAO_DO_INTRO_ATTACKABLE, CELESTIAL_COURT_BOSS_INTRO_TIMER_2);
                    break;
                }
                case EVENT_SHAO_DO_INTRO_ATTACKABLE:
                {
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->SetHealth(391000000/*me->GetMaxHealth()*/);
                    break;
                }
                case EVENT_SHAO_DO_OUTRO:
                {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE); // prisma

                    if (Creature* shao = me->FindNearestCreature(NPC_EMPEROR_SHAOHAO_TI, 300.0f, true))
                        shao->AI()->Talk(EMPEROR_TALK_OUTRO_XUEN);
                    break;
                }
                case EVENT_DEATH:
                {
                    if (Creature* shao = me->FindNearestCreature(NPC_EMPEROR_SHAOHAO_TI, 500.0f, true))
                        shao->AI()->DoAction(0);

                    uint32 corpseDelay = me->GetCorpseDelay();
                    uint32 respawnDelay = me->GetRespawnDelay();

                    me->SetCorpseDelay(1);
                    me->SetRespawnDelay(4);

                    death = false;
                    me->DespawnOrUnsummon();

                    me->SetCorpseDelay(corpseDelay);
                    me->SetRespawnDelay(respawnDelay);
                    break;
                }
            }
        }

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SPECTRAL_SWIPES:
                {
                    DoCast(SPELL_SPECTRAL_SWIPE);
                    events.ScheduleEvent(EVENT_SPECTRAL_SWIPES, randtime(10s, 15s)); 
                    break;
                }
                case EVENT_AGILITY_SELF_BUFF:
                {
                    Talk(SAY_AGILITY);
                    DoCast(me, SPELL_AGILITY);
                    events.ScheduleEvent(EVENT_AGILITY_SELF_BUFF, 40s);
                    break;
                }
                case EVENT_LEAP:
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, CasterSpecTargetSelector()))
                        DoCast(target, SPELL_LEAP);
                    else if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                        DoCast(target, SPELL_LEAP);
                    break;
                }
                case EVENT_CRACKLING_LIGHTNING:
                {
                    DoCast(me, SPELL_CRACKLING_LIGHTNING);
                    events.ScheduleEvent(EVENT_CRACKLING_LIGHTNING, 42s);
                    events.ScheduleEvent(EVENT_LEAP, 30s);
                    break;
                }
                case EVENT_CHI_BARRAGE_AOE:
                {
                    Talk(SAY_CHI);
                    DoCast(me, SPELL_CHI_BARRAGE);
                    events.ScheduleEvent(EVENT_CHI_BARRAGE_AOE, randtime(20s, 25s));
                    break;
                }
                case EVENT_TIMER_HEALTH_POOL:
                {
                    UpdateHealth(me);
                    events.ScheduleEvent(EVENT_TIMER_HEALTH_POOL, 5s);
                    break;
                }
            }
        }

        EnterEvadeIfOutOfCombatArea(diff);
        DoMeleeAttackIfReady();
    }
};

class spell_xuen_ti_chi_barrage : public SpellScript
{
    PrepareSpellScript(spell_xuen_ti_chi_barrage);

    std::list<WorldObject*> m_targets;

    void HandleDummy(SpellEffIndex effIndex)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        m_targets = targets;
        targets.remove_if(TankSpecTargetSelector());
        targets.remove_if(MeeleSpecTargetSelector());

        uint8 minCount = 8;

        if (targets.size() < minCount)
        {
            targets.clear();

            for (auto&& itr : m_targets)
                targets.push_back(itr);

            if (targets.size() > minCount)
                Trinity::Containers::RandomResizeList(targets, minCount);

            return;
        }

        if (targets.size() > minCount)
            Trinity::Containers::RandomResizeList(targets, minCount);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_xuen_ti_chi_barrage::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xuen_ti_chi_barrage::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_xuen_ti_crackling_lightning : public SpellScript
{
    PrepareSpellScript(spell_xuen_ti_crackling_lightning);

    std::list<WorldObject*> m_targets;

    void HandleChain(SpellEffIndex effIndex)
    {
        if (Unit* target = GetHitUnit())
            GetCaster()->CastSpell(target, GetSpellInfo()->Effects[effIndex].BasePoints, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        m_targets = targets;
        targets.remove_if(TankSpecTargetSelector());
        targets.remove_if(MeeleSpecTargetSelector());

        uint8 minCount = 8;

        if (targets.size() < minCount)
        {
            targets.clear();

            for (auto&& itr : m_targets)
                targets.push_back(itr);

            if (targets.size() > minCount)
                Trinity::Containers::RandomResizeList(targets, minCount);

            return;
        }

        if (targets.size() > minCount)
            Trinity::Containers::RandomResizeList(targets, minCount);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_xuen_ti_crackling_lightning::HandleChain, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_xuen_ti_crackling_lightning::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

void AddSC_boss_xuen()
{
    register_creature_script(boss_xuen);
    register_spell_script(spell_xuen_ti_chi_barrage);
    register_spell_script(spell_xuen_ti_crackling_lightning);
}
