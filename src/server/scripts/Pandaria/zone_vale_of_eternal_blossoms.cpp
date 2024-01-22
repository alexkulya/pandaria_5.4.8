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
#include "ObjectMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "ScriptedEscortAI.h"
#include "Group.h"

enum ValeOfEternalBlossomsSpellData
{
    SPELL_THUNDER_BREATH                    = 125787,
    SPELL_DISARM                            = 8379,
    SPELL_NIMBUS_SHROUD                     = 126188,
    SPELL_OVERPOWERING_STRENGTH             = 126181,
    SPELL_DOMINATING_STRIKE_1               = 126177,
    SPELL_DOMINATING_STRIKE_2               = 126189,
    SPELL_IRON_FIST                         = 126307,
    SPELL_IMPERION_WARCRY                   = 126353,
    SPELL_CALL_SWARMERS                     = 126652,
    SPELL_VENOMOUS_SPIT                     = 126669,
    SPELL_CRUSHING_BLOW_1                   = 127492,
    SPELL_CRUSHING_BLOW_2                   = 126235,
    SPELL_CRUSHING_STRIKE                   = 127189,
    SPELL_IMPACT                            = 126378,
    SPELL_BLUE_GRANIT                       = 126405,
    SPELL_GREEN_GRANIT                      = 126401,
    SPELL_RED_GRANIT                        = 126384,
    SPELL_FIRE_PAWS                         = 126414,
    SPELL_MIST                              = 126429,
    SPELL_MIST_EFF                          = 126430,
    SPELL_FRAGMENT                          = 126417,
    SPELL_LIGHTNING_SWEEP                   = 127253,
    SPELL_LIGHTNING_BREATH                  = 127255,
    SPELL_LIGHTNING_POOL                    = 128142,
    SPELL_CRUSHING_BLOW                     = 126356,
    SPELL_IMPALE                            = 126360,
    SPELL_ELECTROCUTE                       = 126350,
    SPELL_THUNDER                           = 128999,
    SPELL_THUNDERS_CALL_AURA                = 126915,
    SPELL_THUNDERS_CALL                     = 126913,
    SPELL_MOLTEN_FISTS                      = 126908,
    SPELL_MOLTEN_FISTS_AURA                 = 126909,
    SPELL_SHADOWS_FURY                      = 126911,
    SPELL_SHADOWS_FURY_AURA                 = 126914,
    SPELL_DEVASTATING_LEAP                  = 126903,
    SPELL_DEVASTATING_LEAP_EFF              = 126902,
    SPELL_ICY_DESTRUCTION_EFF               = 127465,
    SPELL_ICY_DESTRUCTION                   = 127463,
    SPELL_ANCIENT_MAGIC                     = 127466,
    SPELL_SHADOW_BOLT                       = 125212,
    SPELL_VOIDCLOUD                         = 125241,
    SPELL_REND_SOUL                         = 126202,
    SPELL_SHADOW_STRIKES                    = 126209,
    SPELL_SUMMON_KAMU                       = 115872,
    SPELL_QUILEN_FLURRY                     = 125124,
    SPELL_POUNCE                            = 125094,
    SPELL_CLAW_SWIPE                        = 36996,
    SPELL_SUMMON_VISAGES                    = 133797,
    SPELL_HARDEN_SKIN                       = 133794,
    SPELL_GUO_LAI_CACHE_REP                 = 127172,
    SPELL_TRAINEE_DEFEAT_CREDIT             = 143259,
    SPELL_WHY_DO_WE_FIGHT                   = 147165,
    SPELL_TORNADO                           = 126015,
    SPELL_WINDSONG                          = 126014,
    SPELL_AETHA_CREDIT                      = 129950,
    SPELL_HYDRO_LANCE                       = 125988,
    SPELL_WATER_BLOSSOM                     = 125980,
    SPELL_WATER_BOLT                        = 125995,
    SPELL_QUID_CREDIT                       = 129949,
    SPELL_STORYTIME                         = 120589,
    SPELL_STORYTIME_OVER                    = 126250,
    SPELL_BELLOWING_RAGE                    = 124297,
    SPELL_RUSHING_CHARGE                    = 124302,
    SPELL_YAUNGOL_STOMP                     = 124289,
    SPELL_WELL_OF_SOULS_SOUL_VISUAL         = 126262
};

enum ValeOfEternalBlossomsEvents
{
    EVENT_OVERPOWER_STRENGTH                = 1,
    EVENT_DOMINATING_STRIKE,
    EVENT_THUNDER_BREATH,
    EVENT_DISARM,
    EVENT_IRONFIST,
    EVENT_WARCRY,
    EVENT_CALL_SWARMERS,
    EVENT_VENOM_SPIT,
    EVENT_CRUSHING_BLOW,
    EVENT_SWITCH_GRANIT,
    EVENT_IMPACT,
    EVENT_MIST,
    EVENT_LIGHTNING_BREATH,
    EVENT_LIGHTNING_POOL,
    EVENT_IMPALE,
    EVENT_ELECTROCUTE,
    EVENT_THUNDER,
    EVENT_ELEMENTAL_CALL,
    EVENT_DEVASTATING_LEAP,
    EVENT_ICY_DESTRUCTION,
    EVENT_ANCIENT_MAGIC,
    EVENT_SHADOW_BOLT,
    EVENT_VOID_CLOUD,
    EVENT_REND_SOUL,
    EVENT_SHADOW_STRIKES,
    EVENT_QUILEN_FLURRY,
    EVENT_POUNCE,
    EVENT_CLAW_SWIPE,
    EVENT_TORNADO,
    EVENT_WINDSONG,
    EVENT_HYDRO_LANCE,
    EVENT_WATER_BLOSSOM,
    EVENT_WATER_BOLT,
    EVENT_BELLOWING_RAGE,
    EVENT_RUSHING_CHARGE,
    EVENT_YAUNGOL_STOMP
};

enum ValeOfEternalBlossomsTexts
{
    NPC_MERCURIAL_GUARDIAN_TEXT_01          = 0,
    NPC_MERCURIAL_GUARDIAN_TEXT_02          = 1,
    NPC_FANLYR_SILVERHORN_01                = 0,
    SAY_YORIK_AGGRO                         = 0
};

enum ValeOfEternalBlossomsCreatures
{
    NPC_ALANI                               = 64403,
    NPC_MIST                                = 64690,
    NPC_THUNDERS_CALL                       = 64915,
    NPC_MOLTEN_FISTS                        = 64913,
    NPC_SHADOWS_FURY                        = 64914,
    NPC_ECHO_OF_PANDAREN_MONK               = 58669,
    NPC_MERCURIAL_GUARDIAN                  = 67833,
    NPC_INVESTIGATE_GUARDIAN                = 63852,
    NPC_DOMINATED_SCALELORD                 = 63045
};

enum ValeOfEternalBlossomsQuests
{
    QUEST_VOICE_OF_THE_GODS                 = 32257
};

enum ValeOfEternalBlossomsFactions
{
    FACTION_FRIEND                          = 35,
    FACTION_ENEMY                           = 14
};

struct npc_alani : public ScriptedAI
{
    npc_alani(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;

    void Reset() override
    {
        events.Reset();
        me->SetCombatDistance(225.0f);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        me->SetHomePosition(*me);
        events.ScheduleEvent(EVENT_THUNDER_BREATH, randtime(9s + 500ms, 12s + 500ms));
        events.ScheduleEvent(EVENT_DISARM, 20s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_THUNDER_BREATH:
                    if (Unit* vict = me->GetVictim())
                        DoCast(vict, SPELL_THUNDER_BREATH);

                    events.ScheduleEvent(EVENT_THUNDER_BREATH, randtime(12s + 500ms, 17s + 500ms));
                    break;
                case EVENT_DISARM:
                    if (Unit* vict = me->GetVictim())
                        DoCast(vict, SPELL_DISARM);

                    events.ScheduleEvent(EVENT_DISARM, 20s);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_shao_tien_dominator : public ScriptedAI
{
    npc_shao_tien_dominator(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_OVERPOWER_STRENGTH, randtime(10s, 20s));
        events.ScheduleEvent(EVENT_DOMINATING_STRIKE, randtime(4s + 500ms, 12s));
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
                case EVENT_OVERPOWER_STRENGTH:
                    DoCast(me, SPELL_OVERPOWERING_STRENGTH);
                    events.ScheduleEvent(EVENT_OVERPOWER_STRENGTH, randtime(10s, 20s));
                    break;
                case EVENT_DOMINATING_STRIKE:
                    if (Unit* target = me->GetVictim())
                        DoCast(target, urand(0, 1) ? SPELL_DOMINATING_STRIKE_1 : SPELL_DOMINATING_STRIKE_2, true);

                    events.ScheduleEvent(EVENT_DOMINATING_STRIKE, randtime(7s, 16s));
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_gochao_the_iron_fist : public ScriptedAI
{
    npc_gochao_the_iron_fist(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;
    uint32 delay;
    uint64 targetGUID;

    void Reset() override
    {
        events.Reset();
        delay = 0;
        targetGUID = 0;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_IRONFIST, randtime(5s, 8s));
        events.ScheduleEvent(EVENT_WARCRY, 10s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_IRONFIST:
                    if (Unit* target = me->GetVictim())
                    {
                        targetGUID = target->GetGUID();
                        me->PrepareChanneledCast(me->GetAngle(target), SPELL_IRON_FIST);

                        delay = 0;
                        me->m_Events.Schedule(delay += 2100, 3, [this]()
                        {
                            me->RemoveChanneledCast(targetGUID);
                        });
                    }
                    events.ScheduleEvent(EVENT_IRONFIST, randtime(9s, 20s));
                    break;
                case EVENT_WARCRY:
                    if (Unit* target = me->GetVictim())
                    {
                        targetGUID = target->GetGUID();
                        me->PrepareChanneledCast(me->GetAngle(target), SPELL_IMPERION_WARCRY);

                        delay = 0;
                        me->m_Events.Schedule(delay += 2500, 4, [this]()
                        {
                            me->RemoveChanneledCast(targetGUID);
                        });
                    }
                    events.ScheduleEvent(EVENT_WARCRY, 15s);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_bloodtip : public ScriptedAI
{
    npc_bloodtip(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        DoCast(me, SPELL_CALL_SWARMERS);
        events.ScheduleEvent(EVENT_VENOM_SPIT, randtime(3s + 500ms, 9s));
        events.ScheduleEvent(EVENT_CALL_SWARMERS, 20s);
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
                case EVENT_VENOM_SPIT:
                    if (Unit* target = me->GetVictim())
                        DoCast(target, SPELL_VENOMOUS_SPIT);

                    events.ScheduleEvent(EVENT_VENOM_SPIT, randtime(15s + 500ms, 25s));
                    break;
                case EVENT_CALL_SWARMERS:
                    DoCast(me, SPELL_CALL_SWARMERS);
                    events.ScheduleEvent(EVENT_CALL_SWARMERS, 20s);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_mogu_jade_guardian : public ScriptedAI
{
    npc_mogu_jade_guardian(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;
    uint32 prevSpellId;
    uint32 delay;
    uint64 targetGUID;

    void Reset() override
    {
        events.Reset();
        prevSpellId = 0;
        delay = 0;
        targetGUID  = 0;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_CRUSHING_BLOW, 6s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            if (eventId == EVENT_CRUSHING_BLOW)
            {
                std::vector<uint32> SpellStorage = { SPELL_CRUSHING_BLOW_1, SPELL_CRUSHING_BLOW_2, SPELL_CRUSHING_STRIKE };

                if (prevSpellId)
                    SpellStorage.erase(std::find(SpellStorage.begin(), SpellStorage.end(), prevSpellId));

                // Select new spell from updated container
                prevSpellId = Trinity::Containers::SelectRandomContainerElement(SpellStorage);

                if (Unit* target = me->GetVictim())
                {
                    targetGUID = target->GetGUID();
                    me->PrepareChanneledCast(me->GetAngle(target), prevSpellId);

                    delay = 0;
                    me->m_Events.Schedule(delay += 3000, 2, [this]()
                    {
                        me->RemoveChanneledCast(targetGUID);
                    });
                }

                events.ScheduleEvent(EVENT_CRUSHING_BLOW, randtime(10s, 15s));
            }
            break;
        }

        DoMeleeAttackIfReady();
    }
};

const std::map<uint32, uint32> invMatchType =
{
    { SPELL_RED_GRANIT,  SPELL_FIRE_PAWS },
    { SPELL_BLUE_GRANIT, SPELL_MIST },
    { SPELL_GREEN_GRANIT, SPELL_FRAGMENT },
};

struct npc_wulon : public ScriptedAI
{
    npc_wulon(Creature* creature) : ScriptedAI(creature), summons(me) { }

    EventMap events;
    SummonList summons;
    uint32 prevSpellId;

    void Reset() override
    {
        events.Reset();
        summons.DespawnAll();
        prevSpellId = 0;
    }

    void JustReachedHome() override
    {
        me->SetStandState(UNIT_STAND_STATE_SIT);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_SWITCH_GRANIT, 1s);
        events.ScheduleEvent(EVENT_IMPACT, randtime(4s + 500ms, 12s));
        me->SetStandState(UNIT_STAND_STATE_STAND);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        if (summon->GetEntry() == NPC_MIST)
        {
            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
            summon->CastSpell(summon, SPELL_MIST_EFF, true);
        }
        else if (Unit* target = me->GetVictim())
            summon->AI()->AttackStart(target);
    }

    void JustDied(Unit* killer) override
    {
        summons.DespawnAll();

        if (Player* player = killer->ToPlayer()) // because fuck you?
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_KILL_CREATURE, 63509);
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
                case EVENT_SWITCH_GRANIT:
                {
                    events.CancelEvent(EVENT_MIST);
                    std::vector<uint32> SpellStorage = { SPELL_RED_GRANIT, SPELL_GREEN_GRANIT, SPELL_BLUE_GRANIT };

                    if (prevSpellId)
                        SpellStorage.erase(std::find(SpellStorage.begin(), SpellStorage.end(), prevSpellId));

                    // Select new spell from updated container
                    prevSpellId = Trinity::Containers::SelectRandomContainerElement(SpellStorage);

                    if (prevSpellId == SPELL_BLUE_GRANIT)
                        events.ScheduleEvent(EVENT_MIST, 1s + 500ms);
                    else if (uint32 matchSpell = invMatchType.find(prevSpellId)->second)
                        DoCast(me, matchSpell);

                    events.ScheduleEvent(EVENT_SWITCH_GRANIT, randtime(17s, 25s));
                    break;
                }
                case EVENT_IMPACT:
                    DoCastVictim(SPELL_IMPACT);
                    events.ScheduleEvent(EVENT_IMPACT, randtime(6s, 14s + 500ms));
                    break;
                case EVENT_MIST:
                    DoCastVictim(SPELL_MIST);
                    events.ScheduleEvent(EVENT_MIST, randtime(5s, 7s));
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_milau : public ScriptedAI
{
    npc_milau(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;
    uint32 pctHealth;

    void Reset() override
    {
        events.Reset();
        me->OverrideInhabitType(INHABIT_AIR);
        me->UpdateMovementFlags();
        pctHealth = 66;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        me->OverrideInhabitType(INHABIT_GROUND);
        me->UpdateMovementFlags();
        events.ScheduleEvent(EVENT_LIGHTNING_BREATH, 4s);
        //events.ScheduleEvent(EVENT_LIGHTNING_POOL, randtime(9s, 19s + 500ms));
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        if (HealthBelowPct(pctHealth) && pctHealth > 0)
        {
            pctHealth -= 33;
            me->InterruptNonMeleeSpells(true);
            DoCast(me, SPELL_LIGHTNING_SWEEP);
        }
    }

    void EnterEvadeMode() override
    {
        me->CombatStop();
        me->GetMotionMaster()->MoveTargetedHome();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LIGHTNING_BREATH:
                    if (Unit* target = me->GetVictim())
                        DoCast(target, SPELL_LIGHTNING_BREATH);

                    events.ScheduleEvent(EVENT_LIGHTNING_BREATH, randtime(11s, 19s));
                    break;
                case EVENT_LIGHTNING_POOL:
                    if (Unit* target = me->GetVictim())
                        DoCast(target, SPELL_LIGHTNING_POOL);

                    events.ScheduleEvent(EVENT_LIGHTNING_POOL, randtime(17s, 32s));
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_ancient_mogu_spirit : public ScriptedAI
{
    npc_ancient_mogu_spirit(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_IMPALE, randtime(3s, 15s));
        events.ScheduleEvent(EVENT_ELECTROCUTE, 6s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_IMPALE:
                    if (Unit* target = me->GetVictim())
                        DoCast(target, urand(0, 1) ? SPELL_CRUSHING_BLOW : SPELL_IMPALE);

                    events.ScheduleEvent(EVENT_IMPALE, randtime(6s + 500ms, 15s));
                    break;
                case EVENT_ELECTROCUTE:
                    if (Unit* target = me->GetVictim())
                        DoCast(target, SPELL_ELECTROCUTE);

                    events.ScheduleEvent(EVENT_ELECTROCUTE, randtime(8s, 19s + 500ms));
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_aetha_tornado : public ScriptedAI
{
    npc_aetha_tornado(Creature* creature) : ScriptedAI(creature) { }

    float x, y;
    bool m_bCounterClockwise, m_bFirstPoint;

    void IsSummonedBy(Unit* summoner) override
    {
        me->SetDisplayId(45494);
        m_bCounterClockwise = urand(0, 1);
        m_bFirstPoint = false;
        x = me->GetPositionX();
        y = me->GetPositionY();

        Movement::MoveSplineInit init(me);

        for (uint8 i = 1; i < 13; ++i)
        {
            float newX = x + 2.0f * cos(i * M_PI / 6);
            float newY = m_bCounterClockwise ? y - 2.0f * sin(i * M_PI / 6) : y + 2.0f * sin(i * M_PI / 6);
            init.Path().push_back(G3D::Vector3(newX, newY, me->GetPositionZ()));
        }

        init.SetUncompressed();
        init.SetCyclic();
        init.Launch();
    }

    void EnterEvadeMode() override { }
};

struct npc_thundermaw : public ScriptedAI
{
    npc_thundermaw(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_THUNDER, randtime(4s, 18s));
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            if (eventId == EVENT_THUNDER)
            {
                if (Unit* target = me->GetVictim())
                    DoCast(target, SPELL_THUNDER);

                events.ScheduleEvent(EVENT_THUNDER, randtime(4s, 18s));
            }
            break;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_shao_tien_fist : public ScriptedAI
{
    npc_shao_tien_fist(Creature* creature) : ScriptedAI(creature), summons(me) { }

    EventMap events;
    SummonList summons;
    uint32 prevSpellId;

    void Reset() override
    {
        events.Reset();
        summons.DespawnAll();
        prevSpellId = 0;
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_ELEMENTAL_CALL, randtime(5s, 15s));
        events.ScheduleEvent(EVENT_DEVASTATING_LEAP, 8s);
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
        summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);

        switch (summon->GetEntry())
        {
            case NPC_THUNDERS_CALL:
                summon->CastSpell(summon, SPELL_THUNDERS_CALL_AURA, true);
                break;
            case NPC_MOLTEN_FISTS:
                summon->CastSpell(summon, SPELL_MOLTEN_FISTS_AURA, true);
                break;
            case NPC_SHADOWS_FURY:
                summon->CastSpell(summon, SPELL_SHADOWS_FURY_AURA, true);
                break;
        }
    }

    void JustDied(Unit* killer) override
    {
        summons.DespawnAll();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DEVASTATING_LEAP:
                    if (Unit* target = me->GetVictim())
                        DoCast(target, SPELL_DEVASTATING_LEAP);

                    events.ScheduleEvent(EVENT_DEVASTATING_LEAP, 15s + 500ms);
                    break;
                case EVENT_ELEMENTAL_CALL:
                    std::vector<uint32> SpellStorage = { SPELL_THUNDERS_CALL, SPELL_MOLTEN_FISTS, SPELL_SHADOWS_FURY };

                    if (prevSpellId)
                        SpellStorage.erase(std::find(SpellStorage.begin(), SpellStorage.end(), prevSpellId));

                    // Select new spell from updated container
                    prevSpellId = Trinity::Containers::SelectRandomContainerElement(SpellStorage);

                    if (Unit* target = me->GetVictim())
                        DoCast(target, prevSpellId);

                    events.ScheduleEvent(EVENT_ELEMENTAL_CALL, randtime(8s, 22s + 500ms));
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_shao_tien_antiquator : public ScriptedAI
{
    npc_shao_tien_antiquator(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_ANCIENT_MAGIC, 1s);
        events.ScheduleEvent(EVENT_ICY_DESTRUCTION, 8s);
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
                case EVENT_ANCIENT_MAGIC:
                    DoCast(me, SPELL_ANCIENT_MAGIC);
                    events.ScheduleEvent(EVENT_ANCIENT_MAGIC, randtime(13s, 23s));
                    break;
                case EVENT_ICY_DESTRUCTION:
                    if (Unit* target = me->GetVictim())
                        DoCast(target, SPELL_ICY_DESTRUCTION);

                    events.ScheduleEvent(EVENT_ICY_DESTRUCTION, randtime(15s + 500ms, 25s));
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_kang_the_soul_thief : public ScriptedAI
{
    npc_kang_the_soul_thief(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_SHADOW_BOLT, randtime(4s + 500ms, 12s));
        events.ScheduleEvent(EVENT_VOID_CLOUD, 8s + 500ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHADOW_BOLT:
                    if (Unit* target = me->GetVictim())
                        DoCast(target, SPELL_SHADOW_BOLT);

                    events.ScheduleEvent(EVENT_SHADOW_BOLT, randtime(6s, 13s + 500ms));
                    break;
                case EVENT_VOID_CLOUD:
                    if (Unit* target = me->GetVictim())
                        DoCast(target, SPELL_VOIDCLOUD);

                    events.ScheduleEvent(EVENT_VOID_CLOUD, randtime(9s + 500ms, 18s));
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_shao_tien_soul_caller : public ScriptedAI
{
    npc_shao_tien_soul_caller(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_SHADOW_STRIKES, randtime(3s, 5s));
        events.ScheduleEvent(EVENT_REND_SOUL, randtime(5s + 500ms, 15s));
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SHADOW_STRIKES:
                    DoCast(me, SPELL_SHADOW_STRIKES);
                    events.ScheduleEvent(EVENT_SHADOW_STRIKES, 15s);
                    break;
                case EVENT_REND_SOUL:
                    if (Unit* target = me->GetVictim())
                        DoCast(target, SPELL_REND_SOUL);

                    events.ScheduleEvent(EVENT_REND_SOUL, randtime(6s, 15s + 500ms));
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_dagou : public customCreatureAI
{
    npc_dagou(Creature* creature) : customCreatureAI(creature) { }

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        DoCast(me, SPELL_SUMMON_KAMU);

        events.ScheduleEvent(EVENT_POUNCE, randtime(3s + 500ms, 8s));
        events.ScheduleEvent(EVENT_QUILEN_FLURRY, randtime(10s, 13s));
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);
    }

    void EnterEvadeMode() override
    {
        summons.DespawnAll();
    }

    void JustDied(Unit* /*killer*/) override
    {
        summons.DespawnAll();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteTargetEvent(SPELL_POUNCE, urand(10 * IN_MILLISECONDS, 15 * IN_MILLISECONDS), EVENT_POUNCE, eventId, PRIORITY_NOT_VICTIM);
            ExecuteTargetEvent(SPELL_QUILEN_FLURRY, 15 * IN_MILLISECONDS, EVENT_QUILEN_FLURRY, eventId, PRIORITY_SELF);
            break;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_mercurial_guardian : public customCreatureAI
{
    npc_mercurial_guardian(Creature* creature) : customCreatureAI(creature) { }

    TaskScheduler scheduler;
    uint64 targetGUID;
    bool hasTriggered;
    uint8 counter;

    void Reset() override
    {
        events.Reset();
        me->SetFaction(FACTION_FRIEND);
        me->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        targetGUID = 0;
        hasTriggered = false;
        counter = 0;
    }

    void OnSpellClick(Unit* clicker, bool& /*result*/) override
    {
        me->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        targetGUID = clicker->GetGUID();
        Talk(NPC_MERCURIAL_GUARDIAN_TEXT_01);

        if (clicker->ToPlayer())
            clicker->ToPlayer()->KilledMonsterCredit(NPC_INVESTIGATE_GUARDIAN);

        scheduler
            .Schedule(Milliseconds(2000), [this](TaskContext context)
        {
            me->SetFaction(FACTION_ENEMY);

            if (Unit* target = ObjectAccessor::GetUnit(*me, targetGUID))
                AttackStart(target);
        });
    }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        if (HealthBelowPct(30) && !hasTriggered)
        {
            hasTriggered = true;
            DoCast(me, SPELL_HARDEN_SKIN);
            Talk(NPC_MERCURIAL_GUARDIAN_TEXT_02);

            // Summon Guardians
            for (uint8 i = 0; i < 6; i++)
                DoCast(me, SPELL_SUMMON_VISAGES, true);
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_CLAW_SWIPE, 3s + 500ms);
    }

    void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/)
    {
        if (++counter >= 6)
            me->RemoveAurasDueToSpell(SPELL_HARDEN_SKIN);
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            ExecuteTargetEvent(SPELL_CLAW_SWIPE, urand(5.5 * IN_MILLISECONDS, 10 * IN_MILLISECONDS), EVENT_CLAW_SWIPE, eventId);
            break;
        }

        DoMeleeAttackIfReady();
    }
};

class npc_fanlyr_silverhorn : public CreatureScript
{
public:
    npc_fanlyr_silverhorn() : CreatureScript("npc_fanlyr_silverhorn") { }

    bool OnQuestReward(Player* player, Creature* creature, const Quest *_Quest, uint32 /*slot*/) override
    {
        if (_Quest->GetQuestId() == QUEST_VOICE_OF_THE_GODS)
            creature->AI()->Talk(NPC_FANLYR_SILVERHORN_01, player);

        return true;
    }

    struct npc_fanlyr_silverhornAI : public ScriptedAI
    {
        npc_fanlyr_silverhornAI(Creature* creature) : ScriptedAI(creature) { }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_fanlyr_silverhornAI(creature);
    }
};

struct npc_aetha : public ScriptedAI
{
    npc_aetha(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_TORNADO, 10s);
        events.ScheduleEvent(EVENT_WINDSONG, 3s);
    }

    void JustDied(Unit* killer) override
    {
        me->CastSpell(me, SPELL_AETHA_CREDIT, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TORNADO:
                    DoCastVictim(SPELL_TORNADO);
                    events.ScheduleEvent(EVENT_TORNADO, 10s);
                    break;
                case EVENT_WINDSONG:
                    DoCast(me, SPELL_WINDSONG);
                    events.ScheduleEvent(EVENT_WINDSONG, 30s);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_quid : public ScriptedAI
{
    npc_quid(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_HYDRO_LANCE, 15s);
        events.ScheduleEvent(EVENT_WATER_BLOSSOM, 1min);
        events.ScheduleEvent(EVENT_WATER_BOLT, 5s);
    }

    void JustDied(Unit* killer) override
    {
        me->CastSpell(me, SPELL_QUID_CREDIT, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HYDRO_LANCE:
                    DoCastVictim(SPELL_HYDRO_LANCE);
                    events.ScheduleEvent(EVENT_HYDRO_LANCE, 20s);
                    break;
                case EVENT_WATER_BLOSSOM:
                    DoCast(me, SPELL_WATER_BLOSSOM);
                    events.ScheduleEvent(EVENT_WATER_BLOSSOM, 1min);
                    break;
                case EVENT_WATER_BOLT:
                    DoCastVictim(SPELL_WATER_BOLT);
                    events.ScheduleEvent(EVENT_WATER_BOLT, 7s);
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

class spell_nimbus_shroud : public AuraScript
{
    PrepareAuraScript(spell_nimbus_shroud);

    void OnAuraEffectRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
    {
        if (Creature* owner = GetOwner()->ToCreature())
            owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_NON_ATTACKABLE);
    }

    void OnAuraEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
    {
        if (Creature* owner = GetOwner()->ToCreature())
            owner->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_NON_ATTACKABLE);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_nimbus_shroud::OnAuraEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectApply += AuraEffectApplyFn(spell_nimbus_shroud::OnAuraEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

class spell_alani_remove_protections : public SpellScript
{
    PrepareSpellScript(spell_alani_remove_protections);

    SpellCastResult CheckCast()
    {
        if (Unit* caster = GetCaster())
            if (Unit* target = ObjectAccessor::GetUnit(*caster, caster->GetTarget()))
                if (target->GetEntry() == NPC_ALANI)
                    return SPELL_CAST_OK;

        return SPELL_FAILED_SPELL_UNAVAILABLE;
    }

    void HandleEffectHit(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
        {
            if (Unit* target = GetHitUnit())
            {
                target->RemoveAurasDueToSpell(SPELL_NIMBUS_SHROUD);

                target->GetMotionMaster()->MoveChase(caster);
                target->Attack(caster, true);
            }
        }
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_alani_remove_protections::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_alani_remove_protections::HandleEffectHit, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_devastating_leap : public SpellScript
{
    PrepareSpellScript(spell_devastating_leap);

    void HandlePosition(SpellEffIndex effIndex)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_DEVASTATING_LEAP_EFF, false);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_devastating_leap::HandlePosition, EFFECT_0, SPELL_EFFECT_JUMP_DEST);
    }
};

class spell_icy_destruction : public AuraScript
{
    PrepareAuraScript(spell_icy_destruction);

    void PeriodicTick(AuraEffect const* /*aurEff*/)
    {
        if (Unit* owner = GetOwner()->ToUnit())
        {
            // Check target moving.
            if (owner->isMoving())
            {
                // Check the aura.
                if (Aura* icyAura = owner->GetAura(SPELL_ICY_DESTRUCTION_EFF))
                {
                    // Remove the stacks.
                    if (icyAura->GetStackAmount() > 1)
                        icyAura->SetStackAmount(icyAura->GetStackAmount() - 1);
                    else
                        owner->RemoveAurasDueToSpell(SPELL_ICY_DESTRUCTION_EFF);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_icy_destruction::PeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_crush_uprising : public SpellScript
{
    PrepareSpellScript(spell_crush_uprising);

    void SelectTargets(std::list<WorldObject*>&targets)
    {
        targets.remove_if([=](WorldObject* target) { return target->GetEntry() != NPC_ECHO_OF_PANDAREN_MONK; });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_crush_uprising::SelectTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class scene_lorewalker_stories : public SceneScript
{
public:
    scene_lorewalker_stories() : SceneScript("scene_lorewalker_stories") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        if (player->HasAura(SPELL_STORYTIME))
            player->CastSpell(player, SPELL_STORYTIME_OVER);
    }
};

struct npc_yorik_sharpeye : public ScriptedAI
{
    npc_yorik_sharpeye(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void EnterCombat(Unit* /*victim*/) override
    {
        Talk(SAY_YORIK_AGGRO);

        events.ScheduleEvent(EVENT_BELLOWING_RAGE, 5s);
        events.ScheduleEvent(EVENT_RUSHING_CHARGE, 25s);
        events.ScheduleEvent(EVENT_YAUNGOL_STOMP, 15s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        switch (events.ExecuteEvent())
        {
            case EVENT_BELLOWING_RAGE:
                DoCastVictim(SPELL_BELLOWING_RAGE, false);
                events.ScheduleEvent(EVENT_BELLOWING_RAGE, 30s);
                break;
            case EVENT_RUSHING_CHARGE:
                DoCastVictim(SPELL_RUSHING_CHARGE, false);
                events.ScheduleEvent(EVENT_RUSHING_CHARGE, 30s);
                break;
            case EVENT_YAUNGOL_STOMP:
                DoCastVictim(SPELL_YAUNGOL_STOMP, false);
                events.ScheduleEvent(EVENT_YAUNGOL_STOMP, 30s);
                break;
            default:
                break;
        }

        DoMeleeAttackIfReady();
    }
};

struct npc_general_temuja : public ScriptedAI
{
    npc_general_temuja(Creature* creature) : ScriptedAI(creature) { }

    EventMap events;
    std::vector<uint64> minions;

    void Reset() override
    {
        events.Reset();

        for (auto&& guid : minions)
            if (Creature* minion = sObjectAccessor->GetCreature(*me, guid))
                minion->DespawnOrUnsummon();
        minions.clear();

        Position sumPos = me->GetPosition();

        for (uint32 i = 0; i < 2; i++)
        {
            sumPos.RelocateOffset(i == 0 ? 2.6f : 3.7f, 3.0f);

            if (Creature* summon = me->SummonCreature(NPC_DOMINATED_SCALELORD, sumPos))
            {
                summon->GetMotionMaster()->MoveFollow(me, 3.0f, i == 0 ? 2.6f : 3.7f);
                minions.push_back(summon->GetGUID());
            }
        }
    }

    void EnterCombat(Unit* who) override
    {
        for (auto&& guid : minions)
            if (Creature* minion = sObjectAccessor->GetCreature(*me, guid))
                minion->AI()->AttackStart(who);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCast(SPELL_WELL_OF_SOULS_SOUL_VISUAL);

        for (auto&& guid : minions)
            if (Creature* minion = sObjectAccessor->GetCreature(*me, guid))
                minion->DespawnOrUnsummon();
        minions.clear();
    }
};

struct npc_veb_shado_pan_trainee : public ScriptedAI
{
    npc_veb_shado_pan_trainee(Creature* creature) : ScriptedAI(creature) { }

    void JustDied(Unit* killer) override
    {
        if (Player* player = killer->ToPlayer())
            player->StartCriteria(CRITERIA_START_TYPE_CREATURE, me->GetEntry());

        DoCast(me, SPELL_TRAINEE_DEFEAT_CREDIT);
    }
};

class go_guo_lai_treasure_cache : public GameObjectScript
{
public:
    go_guo_lai_treasure_cache() : GameObjectScript("go_guo_lai_treasure_cache") { }

    void OnLootStateChanged(GameObject* go, uint32 state, Unit* unit) override
    {
        if (state == GO_ACTIVATED)
            unit->CastSpell(unit, SPELL_GUO_LAI_CACHE_REP, true);
    }
};

class scene_why_do_we_fight : public SceneScript
{
public:
    scene_why_do_we_fight() : SceneScript("scene_why_do_we_fight") { }

    void OnSceneCancel(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->RemoveAurasDueToSpell(SPELL_WHY_DO_WE_FIGHT);
    }
};

void AddSC_vale_of_eternal_blossoms()
{
    register_creature_script(npc_alani);
    register_creature_script(npc_shao_tien_dominator);
    register_creature_script(npc_gochao_the_iron_fist);
    register_creature_script(npc_bloodtip);
    register_creature_script(npc_mogu_jade_guardian);
    register_creature_script(npc_wulon);
    register_creature_script(npc_milau);
    register_creature_script(npc_ancient_mogu_spirit);
    register_creature_script(npc_aetha_tornado);
    register_creature_script(npc_thundermaw);
    register_creature_script(npc_shao_tien_fist);
    register_creature_script(npc_shao_tien_antiquator);
    register_creature_script(npc_kang_the_soul_thief);
    register_creature_script(npc_shao_tien_soul_caller);
    register_creature_script(npc_dagou);
    register_creature_script(npc_mercurial_guardian);
    new npc_fanlyr_silverhorn();
    register_creature_script(npc_aetha);
    register_creature_script(npc_quid);
    register_aura_script(spell_nimbus_shroud);
    register_spell_script(spell_alani_remove_protections);
    register_spell_script(spell_devastating_leap);
    register_aura_script(spell_icy_destruction);
    register_spell_script(spell_crush_uprising);
    new scene_lorewalker_stories();
    register_creature_script(npc_yorik_sharpeye);
    register_creature_script(npc_general_temuja);
    register_creature_script(npc_veb_shado_pan_trainee);
    new go_guo_lai_treasure_cache();
    new scene_why_do_we_fight();
}
