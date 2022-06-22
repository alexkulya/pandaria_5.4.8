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
#include "shadopan_monastery.h"

enum eSay
{
    SAY_INTRO_1     = 0,
    SAY_INTRO_2     = 1,
    SAY_MOVE_HOME   = 8,
    SAY_READY_FIGHT = 9,
    SAY_AGGRO       = 11,
};

enum eSpells
{
    // Snowdrift

    SPELL_CHASE_DOWN            = 118961,
    SPELL_FIST_OF_FURY          = 106853,
    SPELL_PARRY_STANCE          = 106454,
    SPELL_QUIVERING_PALM        = 106422,
    SPELL_TORNADO_KICK          = 106434,

    SPELL_SMOKE_BOMB            = 110444,

    // Novices
    SPELL_ACHIEV_RESPECT        = 118918,

    // Flagrant Lotus
    SPELL_BALL_OF_FIRE          = 113760,
    SPELL_BALL_OF_FIRE_DAMAGE   = 106470,
    SPELL_FLYING_KICK           = 106439,

    SPELL_CALL_STAFF            = 106681,
    SPELL_RELEASE_STAFF         = 106680,

    // Flying Snow
    SPELL_WHIRLING_STEEL_FOCUS  = 106699,
    SPELL_WHIRLING_STEEL_DAMAGE = 106646,

    // Both
    SPELL_FLARE                 = 132951,
    
    SPELL_ENCOUNTER_CREDIT      = 123096,
};

enum eEvents
{
    // Snowdrift
    EVENT_FIRST_EVENT           = 1,
    EVENT_CHECK_WIPE            = 2,

    EVENT_CHASE_DOWN            = 3,
    EVENT_FIST_OF_FURY          = 4,
    EVENT_PARRY_STANCE          = 5,
    EVENT_QUIVERING_PALM        = 6,
    EVENT_TORNADO_KICK          = 7,
    EVENT_FIREBALL              = 8,
    EVENT_PHASE_3               = 9,

    EVENT_DISAPPEAR             = 10,
    EVENT_DISAPPEAR_TWO         = 11,

    // Miniboss
    EVENT_BALL_OF_FIRE          = 12,
    EVENT_FLYING_KICK           = 13,
    EVENT_CALL_STAFF            = 14,
    EVENT_RELEASE_STAFF         = 15,
    
    EVENT_WHIRLING_STEEL_FOCUS  = 16,
    EVENT_WHIRLING_STEEL_CHANGE = 17,
    EVENT_WHIRLING_STEEL_STOP   = 18,
    
    EVENT_FORFEIT_JUMP          = 19,
    
    EVENT_INTRO                 = 20,
};

enum ePhases
{
    PHASE_FIRST_EVENT   = 1,
    PHASE_FIGHT_1       = 2,
    PHASE_FIGHT_2       = 3,
    PHASE_FIGHT_3       = 4
};

enum ePoints
{
    POINT_BEGIN_EVENT               = 1,
    POINT_PHASE_FIGHT               = 2,

    POINT_NOVICE_JUMP               = 3,
    POINT_NOVICE_DEFEATED           = 4,
    POINT_NOVICE_DEFEATED_SECOND    = 5,

    POINT_MINIBOSS_JUMP             = 6,
    POINT_MINIBOSS_DEFEATED         = 7
};

Position InitiateSpawnPos[5] =
{
    {3708.56f, 3039.60f, 816.28f},
    {3699.19f, 3049.62f, 816.28f},
    {3688.03f, 3055.68f, 816.28f},
    {3675.10f, 3066.98f, 816.28f},
    {3668.95f, 3070.81f, 816.28f}
};

Position MinibossSpawnPos[2] =
{
    {3683.72f, 3053.94f, 816.28f},
    {3687.77f, 3051.30f, 816.28f}
};

Position ClonePos[3] =
{
    {3683.37f, 3087.65f, 815.70f, 0.0f},
    {3719.41f, 3062.31f, 815.70f, 1.88f},
    {3718.04f, 3097.97f, 817.40f, 4.06f}
};

#define defaultrand urand(1000, 10000)

class boss_master_snowdrift : public CreatureScript
{
    public:
        boss_master_snowdrift() : CreatureScript("boss_master_snowdrift") {}

        struct boss_master_snowdriftAI : public BossAI
        {
            boss_master_snowdriftAI(Creature* creature) : BossAI(creature, DATA_MASTER_SNOWDRIFT)
            {
                pInstance = creature->GetInstanceScript();
                EncounterFinish = false;
            }

            InstanceScript* pInstance;
            EventMap events;

            bool introStarted;
            bool miniboss;
            bool EncounterFinish;

            uint8 phase;
            uint8 eventPhase;

            void Reset()
            {
                events.Reset();
                _Reset();
                introStarted = false;
                miniboss = true;
                phase = PHASE_FIRST_EVENT;
                eventPhase = 0;
                if (!EncounterFinish)
                {
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MovePoint(POINT_BEGIN_EVENT, 3680.56f, 3045.27f, 816.20f);
                }
                me->setFaction(35);
                me->SetReactState(REACT_PASSIVE);
                SetCanSeeEvenInPassiveMode(true);
            }

            void EnterCombat(Unit* /*who*/)
            {
                pInstance->SetBossState(DATA_MASTER_SNOWDRIFT, IN_PROGRESS);
                initDefaultEventsForPhase();
                Talk(SAY_AGGRO);
            }

            void initDefaultEventsForPhase()
            {
                events.CancelEventGroup(PHASE_FIGHT_1);
                events.CancelEventGroup(PHASE_FIGHT_2);
                events.CancelEventGroup(PHASE_FIGHT_3);

                switch (phase)
                {
                    case PHASE_FIGHT_1:
                        events.ScheduleEvent(EVENT_TORNADO_KICK, urand(7500, 12500), PHASE_FIGHT_1);
                        events.ScheduleEvent(EVENT_FIST_OF_FURY, urand(5000, 10000), PHASE_FIGHT_1);
                        events.ScheduleEvent(EVENT_CHASE_DOWN, defaultrand, PHASE_FIGHT_1);
                        break;
                    case PHASE_FIGHT_2:
                        events.ScheduleEvent(EVENT_FIREBALL, urand(2500, 5000), PHASE_FIGHT_2);
                        events.ScheduleEvent(EVENT_PHASE_3, urand(10000, 15000), PHASE_FIGHT_2);
                        break;
                    case PHASE_FIGHT_3:
                        events.ScheduleEvent(EVENT_PARRY_STANCE, urand(10000, 15000), PHASE_FIGHT_3);
                        events.ScheduleEvent(EVENT_QUIVERING_PALM, urand(5000, 10000), PHASE_FIGHT_3);
                        break;
                }
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->ToPlayer() && !introStarted && !EncounterFinish)
                {
                    if (who->ToPlayer()->isGameMaster())
                        return;

                    if (me->GetDistance(who) < 45.0f)
                    {
                        introStarted = true;
                        Talk(SAY_INTRO_1);
                        pInstance->SetBossState(DATA_MASTER_SNOWDRIFT, SPECIAL);
                        events.ScheduleEvent(EVENT_FIRST_EVENT, 1000);
                        events.ScheduleEvent(EVENT_CHECK_WIPE, 1000);
                        events.ScheduleEvent(EVENT_INTRO, 5000);
                        if (GameObject* endoor = me->FindNearestGameObject(213194, 80.0f))
                            endoor->SetGoState(GO_STATE_READY);
                    }
                }
            }

            void JustDied(Unit* killer)
            {
                _JustDied();
            }

            void EnterEvadeMode()
            {
                if (!EncounterFinish)
                {
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MovePoint(POINT_BEGIN_EVENT, 3680.56f, 3045.27f, 816.20f);//Events pos

                    if (pInstance)
                        pInstance->SetBossState(DATA_MASTER_SNOWDRIFT, FAIL);
                }
                summons.DespawnAll();
            }

            void JustReachedHome()
            {
                if (EncounterFinish)
                {
                    me->GetMap()->UpdateEncounterState(ENCOUNTER_CREDIT_CAST_SPELL, SPELL_ENCOUNTER_CREDIT, me);
                    me->HandleEmoteCommand(EMOTE_STATE_SIT);
                }
            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_NOVICE_DONE)
                {
                    std::list<Creature*> noviceList;
                    GetCreatureListWithEntryInGrid(noviceList, me, NPC_NOVICE, 100.0f);

                    for (std::list<Creature*>::const_iterator itr = noviceList.begin(); itr != noviceList.end(); ++itr)
                        if (Creature* position = pInstance->instance->GetCreature(pInstance->GetData64(DATA_RANDOM_SECOND_POS)))
                        {
                            (*itr)->GetMotionMaster()->Clear();
                            (*itr)->GetMotionMaster()->MoveJump(position->GetPositionX(), position->GetPositionY(), position->GetPositionZ(), 20.0f, 30.0f, POINT_NOVICE_DEFEATED_SECOND);
                        }

                    ++eventPhase;
                    events.ScheduleEvent(EVENT_FIRST_EVENT, urand(1000, 2000));
                }
                else if (action == ACTION_MINIBOSS_DONE)
                {
                    ++eventPhase;
                    events.ScheduleEvent(EVENT_FIRST_EVENT, urand(1000, 2000));
                }
            }

            void MovementInform(uint32 uiType, uint32 id)
            {
                if (uiType != POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_PHASE_FIGHT:
                        me->setFaction(14);
                        me->SetReactState(REACT_AGGRESSIVE);
                        Talk(SAY_READY_FIGHT);
                        // No Break
                    case POINT_BEGIN_EVENT:
                        me->SetFacingTo(me->GetAngle(3659.08f, 3015.38f));
                        break;
                    default:
                        break;
                }
            }

            void DoEvent()
            {
                switch (eventPhase)
                {
                    case 0:
                    case 1:
                    case 2:
                        ++eventPhase;
                        events.ScheduleEvent(EVENT_FIRST_EVENT, 5000);
                        break;
                    // There is five novices waves
                    case 3:
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                    {
                        // Last wave have 4 initiates (for a total of 24)
                        uint8 maxInitiateByWave = eventPhase == 7 ? 4: 5;

                        for (uint8 i = 0; i < maxInitiateByWave; ++i)
                            me->SummonCreature(NPC_NOVICE, InitiateSpawnPos[i].GetPositionX(), InitiateSpawnPos[i].GetPositionY(), InitiateSpawnPos[i].GetPositionZ());

                        // When last wave, we wait for all initiate to be defeated
                        if (eventPhase != 7)
                        {
                            ++eventPhase;
                            events.ScheduleEvent(EVENT_FIRST_EVENT, urand(12500, 17500));
                        }
                        break;
                    }
                    case 8:
                    {
                        if (miniboss)
                        {
                            miniboss = false;
                            me->SummonCreature(NPC_FLAGRANT_LOTUS, MinibossSpawnPos[0].GetPositionX(), MinibossSpawnPos[0].GetPositionY(), MinibossSpawnPos[0].GetPositionZ());
                            me->SummonCreature(NPC_FLYING_SNOW,    MinibossSpawnPos[1].GetPositionX(), MinibossSpawnPos[1].GetPositionY(), MinibossSpawnPos[1].GetPositionZ());
                        }
                        break;
                    }
                    case 9:
                    {
                        me->GetMotionMaster()->MovePoint(POINT_PHASE_FIGHT, 3713.60f, 3091.87f, 817.31f);//Pos in DoJo
                        phase = PHASE_FIGHT_1;
                        Talk(SAY_MOVE_HOME);
                        break;
                    }
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                /*if (phase == PHASE_FIGHT_1)
                {
                    if (me->HealthBelowPctDamaged(70, damage))
                    {
                        me->CombatStop();
                        me->SetReactState(REACT_PASSIVE);

                        me->CastSpell(me, SPELL_SMOKE_BOMB, true);
                        me->SetVisible(false); // We set this for two seconds, time to let client erase players' focus from the boss

                        phase = PHASE_FIGHT_2;
                        events.Reset();
                        events.ScheduleEvent(EVENT_DISAPPEAR, 2000);
                    }
                }*/
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    if (!EncounterFinish)
                    {
                        EncounterFinish = true;
                        me->setFaction(35);
                        me->AttackStop();
                        me->RemoveAllAuras();
                        instance->SetBossState(DATA_MASTER_SNOWDRIFT, DONE);
                        DoCast(SPELL_ENCOUNTER_CREDIT);
                        me->CombatStop();
                        EnterEvadeMode();
                        me->GetMotionMaster()->MoveTargetedHome();
                        me->DespawnOrUnsummon(10000);
                    }
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (EncounterFinish)
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        // Event Script
                        case EVENT_FIRST_EVENT:
                            DoEvent(); 
                            break;
                        case EVENT_CHECK_WIPE:
                            if (pInstance->IsWipe())
                                Reset();
                            events.ScheduleEvent(EVENT_CHECK_WIPE, defaultrand);
                            break;
                        case EVENT_INTRO:
                            Talk(SAY_INTRO_2);
                            break;
                        // Combat Script
                        /// Phase 1
                        case EVENT_TORNADO_KICK:
                            me->CastSpell(me, SPELL_TORNADO_KICK, false);
                            events.ScheduleEvent(EVENT_TORNADO_KICK, urand(7500, 12500));
                            break;
                        case EVENT_FIST_OF_FURY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                                me->CastSpell(target, SPELL_FIST_OF_FURY, false);
                            events.ScheduleEvent(EVENT_FIST_OF_FURY, urand(5000, 10000));
                            break;
                        case EVENT_CHASE_DOWN:
                            // Todo
                            events.ScheduleEvent(eventId, defaultrand);
                            break;
                        /// Phase 2
                        case EVENT_DISAPPEAR:
                        {
                            std::vector<uint8> randomIndex;
                            for (int i = 0; i < 3; ++i) randomIndex.push_back(i); // 0 1 2
                            std::random_shuffle(randomIndex.begin(), randomIndex.end());
    
                            bool isBoss = true;
    
                            for (std::vector<uint8>::const_iterator index = randomIndex.begin(); index != randomIndex.end(); ++index)
                            {
                                // The first random pos is for the boss, the two others are for his clones
                                if (isBoss)
                                {
                                    me->NearTeleportTo(ClonePos[*index].GetPositionX(), ClonePos[*index].GetPositionY(), ClonePos[*index].GetPositionZ(), ClonePos[*index].GetOrientation());
                                    me->SetVisible(true);
                                    me->CastSpell(me, SPELL_SMOKE_BOMB, true);
                                    isBoss = false;
                                }
                                else
                                    if (Creature* clone = me->SummonCreature(NPC_SNOWDRIFT_CLONE, ClonePos[*index].GetPositionX(), ClonePos[*index].GetPositionY(), ClonePos[*index].GetPositionZ(), ClonePos[*index].GetOrientation()))
                                        clone->CastSpell(clone, SPELL_SMOKE_BOMB, true);
                            }
                            initDefaultEventsForPhase();
                            break;
                        }
                        case EVENT_FIREBALL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_BALL_OF_FIRE, false);
                            events.ScheduleEvent(EVENT_FIREBALL, urand(2500, 5000));
                            break;
                        /// Phase 3
                        case EVENT_PHASE_3:
                            me->SetReactState(REACT_AGGRESSIVE);
                            phase = PHASE_FIGHT_3;
                            initDefaultEventsForPhase();
                            break;
                        case EVENT_PARRY_STANCE:
                            me->CastSpell(me, SPELL_PARRY_STANCE, false);
                            events.ScheduleEvent(EVENT_PARRY_STANCE, urand(10000, 15000));
                            break;
                        case EVENT_QUIVERING_PALM:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                                me->CastSpell(target, SPELL_QUIVERING_PALM, false);
                            events.ScheduleEvent(EVENT_QUIVERING_PALM, urand(5000, 10000));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_master_snowdriftAI(creature);
        }
};

class npc_snowdrift_novice : public CreatureScript
{
    public:
        npc_snowdrift_novice() :  CreatureScript("npc_snowdrift_novice") { }

        struct npc_snowdrift_noviceAI : public ScriptedAI
        {
            npc_snowdrift_noviceAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
                jumpDone = false;
                stillInFight = true;
            }

            InstanceScript* pInstance;
            EventMap events;
            bool jumpDone;
            bool stillInFight;
            bool eventEmote;

            void Reset()
            {
                //events.Reset();
                if (!jumpDone)
                {
                    float x, y;
                    GetPositionWithDistInOrientation(me, 40.0f, 4.0f, x, y);
                    me->GetMotionMaster()->MoveJump(x, y, me->GetMap()->GetHeight(x, y, me->GetPositionZ()), 20, 10, POINT_NOVICE_JUMP);
                    jumpDone = true;
                }
            }

            void MovementInform(uint32 uiType, uint32 id)
            {
                if (uiType != EFFECT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_NOVICE_JUMP:
                        if (Player* target = me->SelectNearestPlayerNotGM(100.0f))
                            AttackStart(target);
                        break;
                    case POINT_NOVICE_DEFEATED:
                        break;
                    case POINT_NOVICE_DEFEATED_SECOND:
                        me->SetFacingTo(me->GetAngle(3659.08f, 3015.38f));
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->setFaction(35);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_BOW);
                    eventEmote = true;
                    me->RemoveAllAuras();
                    if (pInstance && stillInFight)
                    {
                        stillInFight = false;
                        pInstance->SetData(DATA_DEFEATED_NOVICE, 1);
                    }
                    events.ScheduleEvent(EVENT_FORFEIT_JUMP, 2000);
                }
            }
            
            void JustReachedHome()
            {
                if (Creature* target = me->FindNearestCreature(56505, 30.0f))
                {
                    eventEmote = false;
                    me->SetFacingToObject(target);
                }
            }

            void ReceiveEmote(Player* player, uint32 emote)
            {
                if (emote == TEXT_EMOTE_BOW && eventEmote)
                {
                    eventEmote = false;
                    DoCast(player, SPELL_ACHIEV_RESPECT, true);
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_FORFEIT_JUMP:
                        if (Creature* position = pInstance->instance->GetCreature(pInstance->GetData64(DATA_RANDOM_FIRST_POS)))
                        {
                            EnterEvadeMode();
                            me->CombatStop();
                            me->SetHomePosition(position->GetPositionX(), position->GetPositionY(), position->GetPositionZ(), position->GetOrientation());
                            me->GetMotionMaster()->MoveJump(position->GetPositionX(), position->GetPositionY(), position->GetPositionZ(), 20.0f, 10.0f, POINT_NOVICE_DEFEATED);
                        }
                        break;
                    }
                }
                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_snowdrift_noviceAI(creature);
        }
};

class npc_snowdrift_miniboss : public CreatureScript
{
    public:
        npc_snowdrift_miniboss() :  CreatureScript("npc_snowdrift_miniboss") { }

        struct npc_snowdrift_minibossAI : public ScriptedAI
        {
            npc_snowdrift_minibossAI(Creature* creature) : ScriptedAI(creature)
            {
                pInstance = creature->GetInstanceScript();
                jumpDone = false;
                stillInFight = true;
            }

            InstanceScript* pInstance;
            EventMap events;
            bool jumpDone;
            bool stillInFight;
            uint8 whirlwindProgress;

            void Reset()
            {
                events.Reset();
                whirlwindProgress = 0;

                if (!jumpDone)
                {
                    float x, y;
                    GetPositionWithDistInOrientation(me, 30.0f, 4.23f, x, y);
                    me->GetMotionMaster()->MoveJump(x, y, me->GetMap()->GetHeight(x, y, me->GetPositionZ()), 20, 10, POINT_MINIBOSS_JUMP);
                    jumpDone = true;

                    if (me->GetEntry() == NPC_FLAGRANT_LOTUS)
                    {
                        events.ScheduleEvent(EVENT_BALL_OF_FIRE,    1000);
                        events.ScheduleEvent(EVENT_FLYING_KICK,     1000);
                        events.ScheduleEvent(EVENT_CALL_STAFF,      1000);
                        events.ScheduleEvent(EVENT_RELEASE_STAFF,   1000);
                    }
                    else
                    {
                        events.ScheduleEvent(EVENT_WHIRLING_STEEL_FOCUS,  1000);
                    }
                }
            }

            void MovementInform(uint32 uiType, uint32 id)
            {
                if (uiType != POINT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_MINIBOSS_DEFEATED:
                        me->SetFacingTo(me->GetAngle(3659.08f, 3015.38f));
                        break;
                    default:
                        break;
                }
            }

            void DamageTaken(Unit* attacker, uint32& damage)
            {
                if (!stillInFight)
                    return;

                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    EnterEvadeMode();
                    me->setFaction(35);
                    me->SetReactState(REACT_PASSIVE);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE|UNIT_FLAG_NOT_SELECTABLE);
                    stillInFight = false;
                    pInstance->SetData(DATA_DEFEATED_MINIBOSS, 1);

                    if (Creature* position = pInstance->instance->GetCreature(pInstance->GetData64(DATA_RANDOM_MINIBOSS_POS)))
                    {
                        me->GetMotionMaster()->MovePoint(POINT_MINIBOSS_DEFEATED, position->GetPositionX(), position->GetPositionY(), position->GetPositionZ());
                        me->SetHomePosition(position->GetPositionX(), position->GetPositionY(), position->GetPositionZ(), position->GetOrientation());
                    }
                    me->DespawnOrUnsummon();

                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!stillInFight)
                    return;

                events.Update(diff);

                switch(events.ExecuteEvent())
                {
                    case EVENT_BALL_OF_FIRE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_BALL_OF_FIRE, false);

                        events.ScheduleEvent(EVENT_BALL_OF_FIRE, 10000);
                        break;
                    case EVENT_FLYING_KICK:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            me->CastSpell(target, SPELL_FLYING_KICK, false);

                        events.ScheduleEvent(EVENT_FLYING_KICK, 10000);
                        break;
                    case EVENT_CALL_STAFF:
                        //me->CastSpell(me, SPELL_CALL_STAFF, false);
                        events.ScheduleEvent(EVENT_CALL_STAFF, 10000);
                        break;
                    case EVENT_RELEASE_STAFF:
                        if (me->GetVehicleKit())
                            if (me->GetVehicleKit()->GetPassenger(0))
                                me->GetVehicleKit()->GetPassenger(0)->ExitVehicle();
                        events.ScheduleEvent(EVENT_CALL_STAFF, 10000);
                        break;
                    case EVENT_WHIRLING_STEEL_FOCUS:
                        me->AddAura(SPELL_WHIRLING_STEEL_DAMAGE, me);
                        me->SetReactState(REACT_PASSIVE);
                        // no break
                    case EVENT_WHIRLING_STEEL_CHANGE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                        {
                            me->AddAura(SPELL_WHIRLING_STEEL_FOCUS, target);
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveChase(target);
                        }
                        if (++whirlwindProgress >= 5)
                            events.ScheduleEvent(EVENT_WHIRLING_STEEL_CHANGE, 2000);
                        else
                            events.ScheduleEvent(EVENT_WHIRLING_STEEL_STOP, 2000);
                        break;
                    case EVENT_WHIRLING_STEEL_STOP:
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->GetMotionMaster()->Clear();
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            AttackStart(target);
                        events.ScheduleEvent(EVENT_WHIRLING_STEEL_FOCUS, 10000);
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_snowdrift_minibossAI(creature);
        }
};

class npc_snowdrift_clone : public CreatureScript
{
    public:
        npc_snowdrift_clone() :  CreatureScript("npc_snowdrift_clone") { }

        struct npc_snowdrift_cloneAI : public ScriptedAI
        {
            npc_snowdrift_cloneAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 fireBallTimer;

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->setFaction(14);
                DoZoneInCombat();

                fireBallTimer = 500;
            }

            void UpdateAI(uint32 diff)
            {
                if (fireBallTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        me->CastSpell(target, SPELL_BALL_OF_FIRE, true);

                    fireBallTimer = 500;
                }
                else fireBallTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_snowdrift_cloneAI(creature);
        }
};

class npc_snowdrift_fireball : public CreatureScript
{
    public:
        npc_snowdrift_fireball() :  CreatureScript("npc_snowdrift_fireball") { }

        struct npc_snowdrift_fireballAI : public ScriptedAI
        {
            npc_snowdrift_fireballAI(Creature* creature) : ScriptedAI(creature) {}

            uint32 damageTimer;

            void Reset()
            {
                float x, y;
                GetPositionWithDistInOrientation(me, 100.0f, me->GetOrientation(), x, y);
                me->GetMotionMaster()->MovePoint(0, x, y, me->GetPositionZ());

                me->SetReactState(REACT_PASSIVE);
                me->setFaction(14);

                damageTimer = 500;
            }

            void UpdateAI(uint32 diff)
            {
                if (damageTimer <= diff)
                {
                    if (Unit* target = me->SelectNearestTarget())
                        if (me->GetDistance(target) <= 1.0f)
                            me->CastSpell(target, SPELL_BALL_OF_FIRE_DAMAGE, true);

                    damageTimer = 500;
                }
                else damageTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_snowdrift_fireballAI(creature);
        }
};

void AddSC_boss_master_snowdrift()
{
    new boss_master_snowdrift();
    new npc_snowdrift_novice();
    new npc_snowdrift_miniboss();
    new npc_snowdrift_clone();
    new npc_snowdrift_fireball();
}
