/*
 * Copyright (C) 2008-2013 MoltenCore <http://www.molten-wow.com/>
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

#include "Spell.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "GridNotifiers.h"

/*
*************************************
********* Anniversary 2014 **********
*************************************
*/


class npc_new_year_event_teleporter : public CreatureScript
{
    enum
    {
        OPTION_TELE_TO_MAZE = GOSSIP_ACTION_INFO_DEF + 30,
        OPTION_TELE_TO_STAIRS,
        OPTION_TELE_TO_BOB,
        OPTION_MORPH
    };

public:
    npc_new_year_event_teleporter() : CreatureScript("npc_new_year_event_teleporter") {}

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Teleport to |cFF9482C9Maze Event|r.", GOSSIP_SENDER_MAIN, OPTION_TELE_TO_MAZE);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Teleport to |cFF9482C9Stairs Event|r.", GOSSIP_SENDER_MAIN, OPTION_TELE_TO_STAIRS);
        //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Teleport to |cFF9482C9Bob's Place|r.", GOSSIP_SENDER_MAIN, OPTION_TELE_TO_BOB);
        //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Morph me!", GOSSIP_SENDER_MAIN, OPTION_MORPH);
        player->SEND_GOSSIP_MENU(800001, creature->GetGUID());

        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*sender*/, uint32 action)
    {
        static uint32 const morphs[20] =
        {
            8669,
            13342,
            13344,
            13346,
            13345,
            13348,
            13347,
            13349,
            13350,
            13356,
            13730,
            15094,
            15095,
            15096,
            15097,
            15660,
            15904,
            15698,
            15698,
            15750,
        };

        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
            case OPTION_TELE_TO_MAZE:
                player->TeleportTo(0, 4199.866699f, -4286.674316f, 277.070160f, 1.578420f);
                break;
            case OPTION_TELE_TO_STAIRS:
                player->TeleportTo(530, -3470.788574f, -14100.294922f, 16.186245f, 2.761339f);
                break;
            case OPTION_TELE_TO_BOB:
                player->TeleportTo(37, -210.602325f, 335.650421f, 303.182831f, 6.195761f);
                break;
            case OPTION_MORPH:
                player->SetDisplayId(morphs[urand(0, 19)]);
                break;
        }

        return true;
    }
};

class npc_winter_snowman : public CreatureScript
{
    enum
    {
        NPC_ANGRY_SNOWMAN = 500002,
        NPC_PALACE_GUARD
    };

public:
    npc_winter_snowman() : CreatureScript("npc_winter_snowman") {}

    struct npc_winter_snowmanAI : public ScriptedAI
    {
        npc_winter_snowmanAI(Creature* c) : ScriptedAI(c) {}

        uint32 castTimer;

        void Reset()
        {
            castTimer = urand(5000, 10000);
        }

        void JustDied(Unit * killer)
        {
            if (me->GetEntry() == NPC_ANGRY_SNOWMAN) // Points only from Angry Snowman
                if (Player * player = killer->GetCharmerOrOwnerPlayerOrPlayerItself())
                {
                // Justice Points
                if (roll_chance_i(20))
                    player->ModifyCurrency(395, 3 * CURRENCY_PRECISION);
                // Valor Points
                else if (roll_chance_i(50))
                    player->ModifyCurrency(396, 1 * CURRENCY_PRECISION);
                }
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (castTimer <= diff)
            {
                me->CastSpell(me->GetVictim(), (me->GetEntry() == NPC_ANGRY_SNOWMAN) ? 65807 : 72905, true);
                castTimer = urand(10000, 20000);
            } else castTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_winter_snowmanAI(creature);
    }
};

enum Spells
{
        SPELL_DEFILING_HORROR           = 72435,
        SPELL_WELL_OF_CORRUPTION        = 72362,
        SPELL_SHARED_SUFFERING          = 72368,
        // P2
        SPELL_FORCEFUL_SMASH            = 69155,
        SPELL_FLAME_BREATH              = 74525,
        SPELL_BLAST_NOVA                = 30613,
        // P3
        SPELL_CLEAVE                    = 68868,
        SPELL_BELLOWING_ROAR            = 18431,
        SPELL_FIREBALL                  = 18392,
        SPELL_TAIL_SWEEP                = 68867,
        SPELL_WING_BUFFET               = 18500,
        // P4
        SPELL_ELEMENTAL_FIRE_DOT        = 20564,
        SPELL_ELEMENTAL_FIRE_INSTAKILL  = 19773,
        SPELL_MAGMA_BLAST               = 20565,
        SPELL_WRATH_OF_RAGNAROS         = 20566,
        SPELL_HAND_OF_RAGNAROS          = 19780,
        SPELL_LAVA_BURST                = 21158

};

struct DamageRange
{
    uint32 minDamage;
    uint32 maxDamage;

    uint32 CalcRandom() const { return minDamage ? urand(minDamage, maxDamage) : maxDamage; };
};

struct SpellCustomDamage
{
    uint32 spellId;
    DamageRange damage10;
    DamageRange damage25;
    DamageEffectType damageType;
};


// We partially use spells from Vanilla Wow here,
// so the damage needs to be adjusted for the encounter to be challenging
// This container holds damage values for each spell
static const std::vector<SpellCustomDamage> WOTLK_DMG_RANGE = 
{
    //P1
    { SPELL_DEFILING_HORROR,            {0, 39000},         {0, 16250},              DOT },
    { SPELL_SHARED_SUFFERING,           {0, 93600},         {0, 36000},              DOT },
    //P2
    { SPELL_FORCEFUL_SMASH,             {336941, 378059},   {73514, 82486},         SPELL_DIRECT_DAMAGE },
    { SPELL_FLAME_BREATH,               {138600, 178200},     {18900, 24300},         SPELL_DIRECT_DAMAGE },
    { SPELL_BLAST_NOVA,                 {36758, 47242},     {3282, 3937},           SPELL_DIRECT_DAMAGE },
    //P3
    //{ SPELL_CLEAVE,                     {0, 0},             {0,0},                  SPELL_DIRECT_DAMAGE }, // ?
    { SPELL_FIREBALL,                   {61854, 69396},      {8483, 9517},           SPELL_DIRECT_DAMAGE },
    { SPELL_TAIL_SWEEP,                 {168350, 195650},     {14430, 16770},         SPELL_DIRECT_DAMAGE },
    { SPELL_WING_BUFFET,                {225451, 252949},     {27098, 30403},         SPELL_DIRECT_DAMAGE },
    //P4
    { SPELL_ELEMENTAL_FIRE_DOT,         {125000, 175000},     {15000, 21000},         SPELL_DIRECT_DAMAGE },
    { SPELL_ELEMENTAL_FIRE_DOT,         {0, 61600},         {0, 9200},              DOT },
    { SPELL_MAGMA_BLAST,                {0, 300000},         {0, 22000},             SPELL_DIRECT_DAMAGE },
    { SPELL_WRATH_OF_RAGNAROS,          {1008000, 1008000},   {0, 82500},             SPELL_DIRECT_DAMAGE },
    { SPELL_HAND_OF_RAGNAROS,           {60000, 90000},     {0, 82500},             SPELL_DIRECT_DAMAGE },
    { SPELL_LAVA_BURST,                 {40000, 80000},     {0, 82500},             SPELL_DIRECT_DAMAGE },
};

// Raggy - 500020
class npc_boss_raggy : public CreatureScript
{



    enum Events
    {
        EVENT_DEFILING_HORROR = 1,
        EVENT_WELL_OF_CORRUPTION,
        EVENT_SHARED_SUFFERING,
        EVENT_SPEECH,
        // P2
        EVENT_FORCEFUL_SMASH,
        EVENT_FLAME_BREATH,
        EVENT_BLAST_NOVA,
        // P3
        EVENT_CLEAVE,
        EVENT_BELLOWING_ROAR,
        EVENT_FIREBALL,
        EVENT_TAIL_SWEEP,
        EVENT_WING_BUFFET,
        // P4
        EVENT_ELEMENTAL_FIRE,
        EVENT_ELEMENTAL_FIRE_INSTAKILL,
        EVENT_HAND_OF_RAGNAROS,
        EVENT_WRATH_OF_RAGNAROS,
        EVENT_MAGMA_BLAST,
        EVENT_RANDOM_CAST_P4,
        EVENT_LAVA_BURST
    };

    enum Misc
    {
        PHASE_ONE = 1,
        PHASE_TWO,
        PHASE_THREE,
        PHASE_FOUR,
        NPC_KAER = 500019,
    };

    enum Texts
    {
        SAY_RANDOM = 0,
        SAY_WRATH = 10
    };

    struct npc_boss_raggyAI : public ScriptedAI
    {
        npc_boss_raggyAI(Creature * creature) : ScriptedAI(creature) {}

        void Reset() override
        {
            me->SetReactState(REACT_DEFENSIVE);
            events.Reset();
            phase = PHASE_ONE;
            speechCounter = 0;
            wrathCasted = false;
        }

        void DamageDealt(Unit*, uint32& damage, DamageEffectType damageType, const SpellInfo * spell)
        {
            // Damage adjustments (varying for each expansion / mode)
            if (!spell)
                return;
            for (auto itr : WOTLK_DMG_RANGE)
            {
                if (itr.spellId == spell->Id && itr.damageType == damageType)
                {
                    damage = itr.damage10.CalcRandom();
                    break;
                }
            }
        }

        void EnterCombat(Unit*)
        {
            SetPhase(PHASE_ONE);
        }

        void DamageTaken(Unit*, uint32& damage)
        {
            static const uint32 phaseThresholds[5] = { 100, 90, 80, 40, 0 };

            if (phaseThresholds[phase] && me->HealthBelowPctDamaged(phaseThresholds[phase], damage))
            {
                SetPhase(++phase);
            }

            if (!wrathCasted && me->HealthBelowPctDamaged(3, damage))
            {
                wrathCasted = true;
                DoCast(me, SPELL_WRATH_OF_RAGNAROS, true);
                Talk(SAY_WRATH);
            }

            if (damage > me->GetHealth())
                me->SummonCreature(NPC_KAER, 754.77f, 1336.87f, 267.235f, 3.81367f, TEMPSUMMON_TIMED_DESPAWN, 30 * MINUTE * IN_MILLISECONDS);
        }

        void JustDied(Unit*)
        {
        }

        void SetPhase(uint8 newPhase)
        {
            events.SetPhase(newPhase);
            phase = newPhase;

            switch (newPhase)
            {
                case PHASE_ONE:
                    speechCounter = 0;
                    events.ScheduleEvent(EVENT_SPEECH, 5000, 0, PHASE_ONE);
                    events.ScheduleEvent(EVENT_SPEECH, 25000, 0, PHASE_ONE);
                    events.ScheduleEvent(EVENT_SPEECH, 46000, 0, PHASE_ONE);
                    events.ScheduleEvent(EVENT_SPEECH, 65000, 0, PHASE_ONE);
                    events.ScheduleEvent(EVENT_DEFILING_HORROR, 10000, 0, PHASE_ONE);
                    events.ScheduleEvent(EVENT_WELL_OF_CORRUPTION, 16000, 0, PHASE_ONE);
                    events.ScheduleEvent(EVENT_SHARED_SUFFERING, 5000, 0, PHASE_ONE);
                    break;
                case PHASE_TWO:
                    speechCounter = 4;
                    events.ScheduleEvent(EVENT_SPEECH, 0, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_SPEECH, 20000, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_SPEECH, 32000, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_SPEECH, 50000, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_SPEECH, 74000, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_FORCEFUL_SMASH, 6000, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_FLAME_BREATH, 0, 0, PHASE_TWO);
                    events.ScheduleEvent(EVENT_BLAST_NOVA, 4000, 0, PHASE_TWO);
                    break;
                case PHASE_THREE:
                    speechCounter = 9;
                    events.ScheduleEvent(EVENT_SPEECH, 0, 0, PHASE_THREE);
                    events.ScheduleEvent(EVENT_CLEAVE, 3000, 0, PHASE_THREE);
                    events.ScheduleEvent(EVENT_BELLOWING_ROAR, 0, 0, PHASE_THREE);
                    events.ScheduleEvent(EVENT_FIREBALL, 5000, 0, PHASE_THREE);
                    events.ScheduleEvent(EVENT_TAIL_SWEEP, 8000, 0, PHASE_THREE);
                    events.ScheduleEvent(EVENT_WING_BUFFET, 13000, 0, PHASE_THREE);
                    break;
                case PHASE_FOUR:
                    events.ScheduleEvent(EVENT_ELEMENTAL_FIRE, 8000, 0, PHASE_FOUR);
                    events.ScheduleEvent(EVENT_MAGMA_BLAST, 10000, 0, PHASE_FOUR);
                    events.ScheduleEvent(EVENT_HAND_OF_RAGNAROS, 25000, 0, PHASE_FOUR);
                    events.ScheduleEvent(EVENT_WRATH_OF_RAGNAROS, 30000, 0, PHASE_FOUR);
                    events.ScheduleEvent(EVENT_LAVA_BURST, 10000, 0, PHASE_FOUR);
                    //events.ScheduleEvent(EVENT_RANDOM_CAST_P4, 10000, 0, PHASE_FOUR);
                    break;
                default:
                    break;
            }
        }

        // This is a hack method for casting single-target spells as if they were an AoE spell
        void DoCastFakeAoE(uint32 spellId, uint32 targetsCnt, SelectAggroTarget targetType)
        {
            UnitList targets;
            targets = SelectTargetList(targetsCnt, targetType, 0.0f, true);

            if (targets.empty())
                return;

            for (auto itr : targets)
            {
                DoCast(itr, spellId, true);
                if (!--targetsCnt)
                    break;
            }
        }

        void UpdateAI(uint32 const diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SPEECH:
                        Talk(SAY_RANDOM + speechCounter++);
                        break;
                        // P1
                    case EVENT_DEFILING_HORROR:
                        DoCast(me, SPELL_DEFILING_HORROR, false);
                        events.ScheduleEvent(EVENT_DEFILING_HORROR, 15000, 0, PHASE_ONE);
                        break;
                    case EVENT_WELL_OF_CORRUPTION:
                        DoCastFakeAoE(SPELL_WELL_OF_CORRUPTION, RAID_MODE(3, 6), SELECT_TARGET_RANDOM);
                        events.ScheduleEvent(EVENT_WELL_OF_CORRUPTION, 10000, 0, PHASE_ONE);
                        break;
                    case EVENT_SHARED_SUFFERING:
                        DoCastFakeAoE(SPELL_SHARED_SUFFERING, RAID_MODE(2, 5), SELECT_TARGET_RANDOM);
                        events.ScheduleEvent(EVENT_SHARED_SUFFERING, 15000, 0, PHASE_ONE);
                        break;
                        // P2
                    case EVENT_FORCEFUL_SMASH:
                        DoCastVictim(SPELL_FORCEFUL_SMASH, false);
                        events.ScheduleEvent(EVENT_FORCEFUL_SMASH, 16000, 0, PHASE_TWO);
                        break;
                    case EVENT_FLAME_BREATH:
                        DoCast(me, SPELL_FLAME_BREATH);
                        events.ScheduleEvent(EVENT_FLAME_BREATH, 8000, 0, PHASE_TWO);
                        break;
                    case EVENT_BLAST_NOVA:
                        DoCast(me, SPELL_BLAST_NOVA);
                        events.ScheduleEvent(EVENT_BLAST_NOVA, 5000, 0, PHASE_TWO);
                        break;
                        // P3
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 10000, 0, PHASE_THREE);
                        break;
                    case EVENT_BELLOWING_ROAR:
                        DoCast(me, SPELL_BELLOWING_ROAR);
                        events.ScheduleEvent(EVENT_BELLOWING_ROAR, 17500, 0, PHASE_THREE);
                        break;
                    case EVENT_FIREBALL:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(target, SPELL_FIREBALL, false);
                        events.ScheduleEvent(EVENT_FIREBALL, 8000, 0, PHASE_THREE);
                        break;
                    case EVENT_TAIL_SWEEP:
                        DoCast(me, SPELL_TAIL_SWEEP);
                        events.ScheduleEvent(EVENT_TAIL_SWEEP, 10000, 0, PHASE_THREE);
                        break;
                    case EVENT_WING_BUFFET:
                        DoCast(me, SPELL_WING_BUFFET);
                        events.ScheduleEvent(EVENT_WING_BUFFET, 15000, 0, PHASE_THREE);
                        break;
                        // P4
                    case EVENT_ELEMENTAL_FIRE_INSTAKILL:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(target, SPELL_ELEMENTAL_FIRE_INSTAKILL);
                        break;
                    case EVENT_ELEMENTAL_FIRE:
                        DoCastVictim(SPELL_ELEMENTAL_FIRE_DOT);
                        events.ScheduleEvent(EVENT_ELEMENTAL_FIRE, 10000, 0, PHASE_FOUR);
                        break;
                    case EVENT_MAGMA_BLAST:
                        if (Unit * target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(target, SPELL_MAGMA_BLAST, false);
                        events.ScheduleEvent(EVENT_MAGMA_BLAST, 10000, 0, PHASE_FOUR);
                        break;
                    case EVENT_HAND_OF_RAGNAROS:
                        DoCast(me, SPELL_HAND_OF_RAGNAROS);
                        events.ScheduleEvent(EVENT_HAND_OF_RAGNAROS, 20000, 0, PHASE_FOUR);
                        break;
                    case EVENT_WRATH_OF_RAGNAROS:
                        DoCastVictim(SPELL_WRATH_OF_RAGNAROS);
                        events.ScheduleEvent(EVENT_WRATH_OF_RAGNAROS, 25000, 0, PHASE_FOUR);
                        break;
                    case EVENT_LAVA_BURST:
                        DoCast(me, SPELL_LAVA_BURST);
                        events.ScheduleEvent(EVENT_LAVA_BURST, 10000, 0, PHASE_FOUR);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
        uint32 phase;
        uint8 speechCounter;
        bool wrathCasted;
    };

public:
    npc_boss_raggy() : CreatureScript("npc_boss_raggy") {}

    CreatureAI * GetAI(Creature * creature) const
    {
        return new npc_boss_raggyAI(creature);
    }
};


static const std::vector<uint32> morphPool =
{
    25580, 25573, 25549, 25546, 25525, 25517, 25500, 25069, 25037, 25038,
    25039, 25040, 25041, 25042, 25043, 25044, 25045, 25046, 25047, 25048,
    25049, 25050, 25051, 25052, 25053, 25054, 25055, 25002, 24130, 24391,
    24789, 24949, 24978, 23773, 25286, 27538, 25329, 23362, 23321, 23348,
    25381, 21987, 21986, 26787, 25756, 1536, 397, 143, 8249, 8310, 16024,
    4956, 1120, 2075, 5488, 487, 13949, 24926, 23684, 24127, 25033, 25034,
    25035, 25036, 24992, 28213, 27744, 23749, 28127
};

class npc_reward_dude : public CreatureScript
{
    enum
    {
        GOSSIP_MORPH = GOSSIP_ACTION_INFO_DEF + 1,
        GOSSIP_DEMORPH,
        GOSSIP_TELE_SW,
        GOSSIP_TELE_ORG,
    };

public:
    npc_reward_dude() : CreatureScript("npc_reward_dude") {}

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->IsQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Morph me please!", GOSSIP_SENDER_MAIN, GOSSIP_MORPH);
        if (player->GetNativeDisplayId() != player->GetDisplayId())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Remove my morph please!", GOSSIP_SENDER_MAIN, GOSSIP_DEMORPH);

        if (player->GetTeam() == ALLIANCE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Teleport to Stormwind", GOSSIP_SENDER_MAIN, GOSSIP_TELE_SW);
        else
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TAXI, "Teleport to Orgrimmar", GOSSIP_SENDER_MAIN, GOSSIP_TELE_ORG);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();

        switch (uiAction)
        {
            case GOSSIP_MORPH:
            {
                uint32 morphId = Trinity::Containers::SelectRandomContainerElement(morphPool);
                player->SetDisplayId(morphId);
                player->CLOSE_GOSSIP_MENU();
                break;
            }
            case GOSSIP_DEMORPH:
                player->DeMorph();
                player->CLOSE_GOSSIP_MENU();
                break;
            case GOSSIP_TELE_SW:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(WorldLocation(0, -9065.756836f, 432.428864f, 93.056526f, 0.67f));
                break;
            case GOSSIP_TELE_ORG:
                player->CLOSE_GOSSIP_MENU();
                player->TeleportTo(WorldLocation(1, 1485.483521f, -4418.357422f, 25.340143f, 0.177814f));
                break;
            default:
                break;
        }

        return true;
    }
};

void AddSC_molten_anniversary()
{
    // 2014
    new npc_new_year_event_teleporter();
    new npc_winter_snowman();
    new npc_boss_raggy();
    new npc_reward_dude();
}