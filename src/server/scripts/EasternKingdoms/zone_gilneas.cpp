#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Unit.h"
#include "ScriptedEscortAI.h"
#include "Vehicle.h"

enum CreatureIds
{
    NPC_PRINCE_LIAM_GREYMANE                          = 34913,
    NPC_GILNEAS_CITY_GUARD                            = 34916,
    NPC_RAMPAGING_WORGEN_1                            = 34884,
    NPC_RAMPAGING_WORGEN_2                            = 35660,
    NPC_BLOODFANG_WORGEN                              = 35118,
    NPC_SERGEANT_CLEESE                               = 35839,
    NPC_MYRIAM_SPELLWALKER                            = 35872,
    NPC_GILNEAN_ROYAL_GUARD                           = 35232,
    NPC_FRIGHTENED_CITIZEN_1                          = 34981,
    NPC_FRIGHTENED_CITIZEN_2                          = 35836,
    NPC_DARIUS_CROWLEY                                = 35230,
    NPC_NORTHGATE_REBEL_1                             = 36057, // phase 8 outside cathedral
    NPC_NORTHGATE_REBEL_2                             = 41015, // phase 1024 inside cathedral
    NPC_BLOODFANG_STALKER_C1                          = 35229, // Main spawns
    NPC_BLOODFANG_STALKER_C2                          = 51277,
    NPC_BLOODFANG_STALKER_CREDIT                      = 35582,
    NPC_CROWLEY_HORSE                                 = 35231,
    NPC_LORD_DARIUS_CROWLEY_C1                        = 35077, // Quest - By the skin of his teeth start/stop
    NPC_WORGEN_ALPHA_C1                               = 35170, // Quest - By the skin of his teeth spawns
    NPC_WORGEN_ALPHA_C2                               = 35167, // Quest - By the skin of his teeth spawns
    NPC_WORGEN_RUNT_C1                                = 35188, // Quest - By the skin of his teeth spawns
    NPC_WORGEN_RUNT_C2                                = 35456, // Quest - By the skin of his teeth spawns
    NPC_SEAN_DEMPSEY                                  = 35081, // Quest - By the skin of his teeth controller= 35370,
    NPC_JOSIAH_AVERY_P4                               = 35370, // NPC for worgen bite
    NPC_JOSIAH_AVERY_TRIGGER                          = 50415, // Controller for Worgen Bite
    NPC_LORNA_CROWLEY_P4                              = 35378, // Quest - From the Shadows
    NPC_BLOODFANG_RIPPER_P4                           = 35505, // General AI spawns
    NPC_GILNEAN_MASTIFF                               = 35631,
    NPC_GILNEAS_CITY_GUARD_P8                         = 50474,
    NPC_AFFLICTED_GILNEAN_P8                          = 50471,
    NPC_COMMANDEERED_CANNON                           = 35914,
    NPC_KRENNAN_ARANAS_TREE                           = 35753,
    NPC_GREYMANE_HORSE_P4                             = 35905,
    NPC_MOUNTAICE_HOURCE_CREDIT                       = 36560,
};

enum QuestIds
{
    QUEST_LOCKDOWN                                     = 14078,
    QUEST_EVAC_MERC_SQUA                               = 14098,
    QUEST_SOMETHINGS_AMISS                             = 14091,
    QUEST_ALL_HELL_BREAKS_LOOSE                        = 14093,
    QUEST_ROYAL_ORDERS                                 = 14099,
    QUEST_BY_THE_SKIN_ON_HIS_TEETH                     = 14154,
    QUEST_SAVE_KRENNAN_ARANAS                          = 14293,
    QUEST_SACRIFICES                                   = 14212,
    QUEST_THE_REBEL_LORDS_ARSENAL                      = 14159,
    QUEST_FROM_THE_SHADOWS                             = 14204
};

enum SpellIds
{
    SPELL_ENRAGE                                       = 8599,
    SPELL_FROSTBOLT_VISUAL_ONLY                        = 74277, // Dummy spell, visual only
    SPELL_SUMMON_CROWLEY                               = 67004,
    SPELL_RIDE_HORSE                                   = 43671,
    SPELL_THROW_TORCH                                  = 67063,
    SPELL_RIDE_VEHICLE_HARDCODED                       = 46598,
    SPELL_LEFT_HOOK                                    = 67825,
    SPELL_DEMORALIZING_SHOUT                           = 61044,
    SPELL_SNAP_KICK                                    = 67827,
    SPELL_BY_THE_SKIN_ON_HIS_TEETH                     = 66914,
    SPELL_SHOOT                                        = 6660,
    SPELL_WORGEN_BITE                                  = 72870,
    SPELL_INFECTED_BITE                                = 72872,
    SPELL_CANNON_FIRE                                  = 68235,
    SPELL_GILNEAS_CANNON_CAMERA                        = 93555,
    SPELL_SUMMON_JOSIAH_AVERY                          = 67350,
    SPELL_GET_SHOT                                     = 67349,
    SPELL_SUMMON_JOSIAH                                = 67350,
    SPELL_PULL_TO                                      = 67357,
    SPELL_PHASE_QUEST_2                                = 59073,
    SPELL_SUMMON_GILNEAN_MASTIFF                       = 67807,
    SPELL_DISMISS_GILNEAN_MASTIFF                      = 43511,
    SPELL_ATTACK_LURKER                                = 67805,
    SPELL_SHADOWSTALKER_STEALTH                        = 5916,
    SPELL_PING_GILNEAN_CROW                            = 93275
};

enum NpcTextIds
{
    SAY_PRINCE_LIAM_GREYMANE_1                         = -1638000,
    SAY_PRINCE_LIAM_GREYMANE_2                         = -1638001,
    SAY_PRINCE_LIAM_GREYMANE_3                         = -1638002,
    DELAY_SAY_PRINCE_LIAM_GREYMANE                     = 20000, // 20 seconds repetition time

    YELL_PRINCE_LIAM_GREYMANE_1                        = -1638025,
    YELL_PRINCE_LIAM_GREYMANE_2                        = -1638026,
    YELL_PRINCE_LIAM_GREYMANE_3                        = -1638027,
    YELL_PRINCE_LIAM_GREYMANE_4                        = -1638028,
    YELL_PRINCE_LIAM_GREYMANE_5                        = -1638029,
    DELAY_YELL_PRINCE_LIAM_GREYMANE                    = 2000,

    SAY_PANICKED_CITIZEN_1                             = -1638016,
    SAY_PANICKED_CITIZEN_2                             = -1638017,
    SAY_PANICKED_CITIZEN_3                             = -1638018,
    SAY_PANICKED_CITIZEN_4                             = -1638019,

    SAY_GILNEAS_CITY_GUARD_GATE_1                      = -1638022,
    SAY_GILNEAS_CITY_GUARD_GATE_2                      = -1638023,
    SAY_GILNEAS_CITY_GUARD_GATE_3                      = -1638024,

    SAY_CITIZEN_1                                      = -1638003,
    SAY_CITIZEN_2                                      = -1638004,
    SAY_CITIZEN_3                                      = -1638005,
    SAY_CITIZEN_4                                      = -1638006,
    SAY_CITIZEN_5                                      = -1638007,
    SAY_CITIZEN_6                                      = -1638008,
    SAY_CITIZEN_7                                      = -1638009,
    SAY_CITIZEN_8                                      = -1638010,
    SAY_CITIZEN_1b                                     = -1638011,
    SAY_CITIZEN_2b                                     = -1638012,
    SAY_CITIZEN_3b                                     = -1638013,
    SAY_CITIZEN_4b                                     = -1638014,
    SAY_CITIZEN_5b                                     = -1638015,

    SAY_KRENNAN_C2                                     = 0,
    SAY_GREYMANE_HORSE                                 = 0,
    SAY_CROWLEY_HORSE_1                                = 0,    // Let''s round up as many of them as we can.  Every worgen chasing us is one less worgen chasing the survivors!
    SAY_CROWLEY_HORSE_2                                = 1,    // You'll never catch us, you blasted mongrels! || Come and get us, you motherless beasts! || Over here, you flea bags!
    SAY_JOSIAH_AVERY_P2                                = 1,
    SAY_JOSAIH_AVERY_P4                                = 1,
    SAY_JOSAIH_AVERY_TRIGGER                           = 1,
    SAY_LORNA_CROWLEY_P4                               = 0,
    SAY_KING_GENN_GREYMANE_P4                          = 1,
    SAY_GILNEAS_CITY_GUARD_P8                          = 1,
    SAY_LORD_GODFREY_P4                                = 0,
    SAY_NPC_KRENNAN_ARANAS_TREE                        = 0
};

enum SoundIds
{
    SOUND_SWORD_FLESH                                 = 143,
    SOUND_SWORD_PLATE                                 = 147,
    SOUND_WORGEN_ATTACK                               = 558,
    DELAY_SOUND                                       = 500,
    DELAY_ANIMATE                                     = 2000
};

struct Waypoint
{
    float X, Y, Z;
};

Waypoint NW_WAYPOINT_LOC1[2]=
{
    { -1630.62f, 1480.55f, 70.40f }, // Worgen Runt 1 top edge of Roof Waypoint
    { -1636.01f, 1475.81f, 64.51f }  // Worgen Runt 1 Edge of Roof Waypoint
};

Waypoint NW_WAYPOINT_LOC2[2]=
{
    { -1637.26f, 1488.86f, 69.95f }, // Worgen Runt 1 top edge of Roof Waypoint
    { -1642.45f, 1482.23f, 64.30f }  // Worgen Runt 1 Edge of Roof Waypoint
};

Waypoint SW_WAYPOINT_LOC1[2]=
{
    { -1718.31f, 1526.62f, 55.91f }, // Worgen Runt 2 Corner where we turn
    { -1717.86f, 1490.77f, 56.61f }  // Worgen Runt 2 Edge of Roof Waypoint
};

Waypoint SW_WAYPOINT_LOC2[2]=
{
    { -1718.31f, 1526.62f, 55.91f }, // Worgen Alpha 1 Corner where we turn
    { -1717.86f, 1487.00f, 57.07f }  // Worgen Alpha 1 Edge of Roof Waypoint
};

Waypoint N_WAYPOINT_LOC[1]=
{
    { -1593.38f, 1408.02f, 72.64f } // Worgen Runt 2 Edge of Roof Waypoint
};

#define DELAY_EMOTE_PANICKED_CITIZEN                  urand(5000, 15000)   // 5-15 second time
#define DELAY_SAY_PANICKED_CITIZEN                    urand(30000, 120000) // 30sec - 1.5min
#define DELAY_SAY_GILNEAS_CITY_GUARD_GATE             urand(30000, 120000) // 30sec - 1.5min
#define PATHS_COUNT_PANICKED_CITIZEN                  8
#define CD_ENRAGE                                     30000
#define SUMMON1_TTL                                   300000
#define PATHS_COUNT                                   2
#define DOOR_TIMER                                    30*IN_MILLISECONDS
#define KRENNAN_END_X                                 -1772.4172f
#define KRENNAN_END_Y                                 1430.6125f
#define KRENNAN_END_Z                                 19.79f
#define KRENNAN_END_O                                 2.79f
#define CROWLEY_SPEED                                 1.85f // if set much lower than this, the horse automatically despawns before reaching the end of his waypoints
#define AI_MIN_HP                                     85
#define Event_Time                                    118500
#define WORGEN_EVENT_SPAWNTIME                        20000 // Default Despawn Timer
#define NW_ROOF_SPAWN_LOC_1                           -1618.86f, 1505.68f, 70.24f, 3.91f
#define NW_ROOF_SPAWN_LOC_2                           -1611.40f, 1498.49f, 69.82f, 3.79f
#define SW_ROOF_SPAWN_LOC_1                           -1732.81f, 1526.34f, 55.39f, 0.01f
#define SW_ROOF_SPAWN_LOC_2                           -1737.49f, 1526.11f, 55.51f, 0.01f
#define N_ROOF_SPAWN_LOC                              -1562.59f, 1409.35f, 71.66f, 3.16f
#define PLATFORM_Z                                    52.29f

class npc_sean_dempsey : public CreatureScript
{
public:
    npc_sean_dempsey() : CreatureScript("npc_sean_dempsey") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_sean_dempseyAI (creature);
    }

    struct npc_sean_dempseyAI : public ScriptedAI
    {
        npc_sean_dempseyAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 tSummon, tEvent_Timer, tWave_Time;
        bool EventActive, RunOnce;
        Player* player;

        void Reset()
        {
            EventActive      = false;
            RunOnce          = true;
            tSummon          = 0;
            tEvent_Timer     = 0;
            tWave_Time       = urand(9000, 15000); // How often we spawn
        }

        void SummonNextWave()
        {
            if (!EventActive)
                return;
            else
            {
                if (RunOnce) // Our inital spawn should always be the same
                {
                    me->SummonCreature(NPC_WORGEN_ALPHA_C2, SW_ROOF_SPAWN_LOC_1, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, WORGEN_EVENT_SPAWNTIME);
                    me->SummonCreature(NPC_WORGEN_ALPHA_C1, NW_ROOF_SPAWN_LOC_1, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, WORGEN_EVENT_SPAWNTIME);
                    RunOnce = false;
                }
                else
                {
                    switch (urand (1,5)) // After intial wave, wave spawns should be random
                    {
                        case 1: // One Alpha on SW Roof and One Alpha on NW Roof
                            me->SummonCreature(NPC_WORGEN_ALPHA_C2, SW_ROOF_SPAWN_LOC_1, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, WORGEN_EVENT_SPAWNTIME);
                            me->SummonCreature(NPC_WORGEN_ALPHA_C1, NW_ROOF_SPAWN_LOC_1, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, WORGEN_EVENT_SPAWNTIME);
                            break;

                        case 2: // 8 Runts on NW Roof
                            for (int i = 0; i < 5; i++)
                                me->SummonCreature(NPC_WORGEN_RUNT_C1, NW_ROOF_SPAWN_LOC_1, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, WORGEN_EVENT_SPAWNTIME);
                                me->SummonCreature(NPC_WORGEN_RUNT_C1, NW_ROOF_SPAWN_LOC_2, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, WORGEN_EVENT_SPAWNTIME);
                            break;

                        case 3: // 8 Runts on SW Roof
                            for (int i = 0; i < 5; i++)
                                me->SummonCreature(NPC_WORGEN_RUNT_C2, SW_ROOF_SPAWN_LOC_1, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, WORGEN_EVENT_SPAWNTIME);
                                me->SummonCreature(NPC_WORGEN_RUNT_C2, SW_ROOF_SPAWN_LOC_2, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, WORGEN_EVENT_SPAWNTIME);
                            break;

                        case 4: // One Alpha on SW Roof and One Alpha on N Roof
                            me->SummonCreature(NPC_WORGEN_ALPHA_C2, SW_ROOF_SPAWN_LOC_1, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, WORGEN_EVENT_SPAWNTIME);
                            me->SummonCreature(NPC_WORGEN_ALPHA_C1, N_ROOF_SPAWN_LOC, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, WORGEN_EVENT_SPAWNTIME);
                            break;
                        case 5: // 8 Runts - Half NW and Half SW
                            for (int i = 0; i < 5; i++)
                                me->SummonCreature(NPC_WORGEN_RUNT_C2, SW_ROOF_SPAWN_LOC_1, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, WORGEN_EVENT_SPAWNTIME);
                                me->SummonCreature(NPC_WORGEN_RUNT_C1, NW_ROOF_SPAWN_LOC_2, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, WORGEN_EVENT_SPAWNTIME);
                            break;
                    }
                }
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (!EventActive)
                return;
            else
            {
                if (tEvent_Timer <= diff)
                {
                    EventActive = false;
                    tEvent_Timer = false;
                    return;
                }
                else // Event is still active
                {
                    tEvent_Timer -= diff;
                    if (tSummon <= diff) // Time for next spawn wave
                    {
                        SummonNextWave(); // Activate next spawn wave
                        tSummon = tWave_Time; // Reset our spawn timer
                    }
                    else
                        tSummon -= diff;
                }
            }
        }
    };
};

/*######
## npc_lord_darius_crowley_c1
######*/

class npc_lord_darius_crowley_c1 : public CreatureScript
{
public:
    npc_lord_darius_crowley_c1() : CreatureScript("npc_lord_darius_crowley_c1") {}

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_BY_THE_SKIN_ON_HIS_TEETH)
        {
            creature->CastSpell(player, SPELL_BY_THE_SKIN_ON_HIS_TEETH, true);
            if (Creature* dempsey = GetClosestCreatureWithEntry(creature, NPC_SEAN_DEMPSEY, 100.0f))
            {
                CAST_AI(npc_sean_dempsey::npc_sean_dempseyAI, dempsey->AI())->EventActive = true; // Start Event
                CAST_AI(npc_sean_dempsey::npc_sean_dempseyAI, dempsey->AI())->tEvent_Timer = Event_Time; // Event lasts for 2 minutes - We'll stop spawning a few seconds short (Blizz-like)
            }
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_lord_darius_crowley_c1AI (creature);
    }

    struct npc_lord_darius_crowley_c1AI : public ScriptedAI
    {
        npc_lord_darius_crowley_c1AI(Creature* creature) : ScriptedAI(creature) {}

        uint32 tAttack;

        void Reset()
        {
            tAttack = urand(1700, 2400);
        }

        void UpdateAI(uint32 diff)
        {
        if (!UpdateVictim())
            {
                // Reset home if no target
                me->GetMotionMaster()->MoveCharge(me->GetHomePosition().GetPositionX(),me->GetHomePosition().GetPositionY(),me->GetHomePosition().GetPositionZ(),8.0f);
                me->SetOrientation(me->GetHomePosition().GetOrientation()); // Reset to my original orientation
                return;
            }

            if (tAttack <= diff) // If we have a target, and it is time for our attack
            {
                if (me->IsWithinMeleeRange(me->GetVictim()))
                {
                    switch (urand(0, 2)) // Perform one of 3 random attacks
                    {
                        case 0: // Do Left Hook
                            if (me->GetOrientation() > 2.0f && me->GetOrientation() < 3.0f || me->GetOrientation() > 5.0f && me->GetOrientation() < 6.0f) 
                                // If Orientation is outside of these ranges, there is a possibility the knockback could knock worgens off the platform
                                // After which, Crowley would chase
                            {
                                DoCast(me->GetVictim(), SPELL_LEFT_HOOK, true);
                            }
                                tAttack = urand(1700, 2400);
                            break;

                        case 1: // Do Demoralizing Shout
                            DoCast(me->GetVictim(), SPELL_DEMORALIZING_SHOUT, true);
                            tAttack = urand(1700, 2400);
                            break;

                        case 2: // Do Snap Kick
                            DoCast(me->GetVictim(), SPELL_SNAP_KICK, true);
                            tAttack = urand(1700, 2400);
                            break;
                    }
                }
                else
                    me->GetMotionMaster()->MoveChase(me->GetVictim());
            }
            else // If we have a target but our attack timer is still not ready, do regular attack
            {
                tAttack -= diff;
                DoMeleeAttackIfReady();
            }
        }
    };
};

/*######
## npc_worgen_runt_c1
######*/

class npc_worgen_runt_c1 : public CreatureScript
{
public:
    npc_worgen_runt_c1() : CreatureScript("npc_worgen_runt_c1") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_worgen_runt_c1AI (creature);
    }

    struct npc_worgen_runt_c1AI : public ScriptedAI
    {
        npc_worgen_runt_c1AI(Creature* creature) : ScriptedAI(creature) {}

        uint32 WaypointId, willCastEnrage, tEnrage, CommonWPCount;
        bool Run, Loc1, Loc2, Jump, Combat;

        void Reset()
        {
            Run = Loc1 = Loc2 = Combat= Jump = false;
            WaypointId          = 0;
            tEnrage             = 0;
            willCastEnrage      = urand(0, 1);
        }

        void UpdateAI(uint32 diff)
        {
            if (me->GetPositionX() == -1611.40f && me->GetPositionY() == 1498.49f) // I was spawned in location 1
            {
                Run = true; // Start running across roof
                Loc1 = true;
            }
            else if (me->GetPositionX() == -1618.86f && me->GetPositionY() == 1505.68f) // I was spawned in location 2
            {
                Run = true; // Start running across roof
                Loc2 = true;
            }

            if (Run && !Jump && !Combat)
            {
                if (Loc1) // If I was spawned in Location 1
                {
                    if (WaypointId < 2)
                        me->GetMotionMaster()->MovePoint(WaypointId,NW_WAYPOINT_LOC1[WaypointId].X, NW_WAYPOINT_LOC1[WaypointId].Y, NW_WAYPOINT_LOC1[WaypointId].Z);
                }
                else if (Loc2)// If I was spawned in Location 2
                {
                    if (WaypointId < 2)
                        me->GetMotionMaster()->MovePoint(WaypointId,NW_WAYPOINT_LOC2[WaypointId].X, NW_WAYPOINT_LOC2[WaypointId].Y, NW_WAYPOINT_LOC2[WaypointId].Z);
                }
            }

            if (!Run && Jump && !Combat) // After Jump
            {
                if (me->GetPositionZ() == PLATFORM_Z) // Check that we made it to the platform
                {
                    me->GetMotionMaster()->Clear(); // Stop Movement
                    // Set our new home position so we don't try and run back to the rooftop on reset
                    me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                    Combat = true; // Start Combat
                    Jump = false; // We have already Jumped
                }
            }

            if (Combat && !Run && !Jump) // Our Combat AI
            {
                if (Player* player = me->SelectNearestPlayer(40.0f)) // Try to attack nearest player 1st (Blizz-Like)
                    AttackStart(player);
                else
                    AttackStart(me->FindNearestCreature(NPC_LORD_DARIUS_CROWLEY_C1, 40.0f)); // Attack Darius 2nd - After that, doesn't matter

                if (!UpdateVictim())
                    return;

                if (tEnrage <= diff) // Our Enrage trigger
                {
                    if (me->GetHealthPct() <= 30 && willCastEnrage)
                    {
                        me->MonsterTextEmote(-106, 0);
                        DoCast(me, SPELL_ENRAGE);
                        tEnrage = CD_ENRAGE;
                    }
                }
                else
                    tEnrage -= diff;

                DoMeleeAttackIfReady();
            }
        }

        void MovementInform(uint32 Type, uint32 PointId)
        {
            if (Type != POINT_MOTION_TYPE)
                return;

            if (Loc1)
            {
                CommonWPCount = sizeof(NW_WAYPOINT_LOC1)/sizeof(Waypoint); // Count our waypoints
            }
            else if (Loc2)
            {
                CommonWPCount = sizeof(NW_WAYPOINT_LOC2)/sizeof(Waypoint); // Count our waypoints
            }

            WaypointId = PointId+1; // Increase to next waypoint

            if (WaypointId >= CommonWPCount) // If we have reached the last waypoint
            {
                if (Loc1)
                {
                    me->GetMotionMaster()->MoveJump(-1668.52f + irand(-3, 3), 1439.69f + irand(-3, 3), PLATFORM_Z, 20.0f, 22.0f);
                    Loc1 = false;
                }
                else if (Loc2)
                {
                    me->GetMotionMaster()->MoveJump(-1678.04f + irand(-3, 3), 1450.88f + irand(-3, 3), PLATFORM_Z, 20.0f, 22.0f);
                    Loc2 = false;
                }

                Run = false; // Stop running - Regardless of spawn location
                Jump = true; // Time to Jump - Regardless of spawn location
            }
        }
    };
};

/*######
## npc_worgen_runt_c2
######*/

class npc_worgen_runt_c2 : public CreatureScript
{
public:
    npc_worgen_runt_c2() : CreatureScript("npc_worgen_runt_c2") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_worgen_runt_c2AI (creature);
    }

    struct npc_worgen_runt_c2AI : public ScriptedAI
    {
        npc_worgen_runt_c2AI(Creature* creature) : ScriptedAI(creature) {}

        uint32 WaypointId, willCastEnrage, tEnrage, CommonWPCount;
        bool Run, Loc1, Loc2, Jump, Combat;

        void Reset()
        {
            Run = Loc1 = Loc2 = Combat= Jump = false;
            WaypointId          = 0;
            tEnrage             = 0;
            willCastEnrage      = urand(0, 1);
        }

        void UpdateAI(uint32 diff)
        {
            if (me->GetPositionX() == -1732.81f && me->GetPositionY() == 1526.34f) // I was spawned in location 1
            {
                Run = true; // Start running across roof
                Loc1 = true;
            }
            else if (me->GetPositionX() == -1737.49f && me->GetPositionY() == 1526.11f) // I was spawned in location 2
            {
                Run = true; // Start running across roof
                Loc2 = true;
            }

            if (Run && !Jump && !Combat)
            {
                if (Loc1) // If I was spawned in Location 1
                {
                    if (WaypointId < 2)
                        me->GetMotionMaster()->MovePoint(WaypointId,SW_WAYPOINT_LOC1[WaypointId].X, SW_WAYPOINT_LOC1[WaypointId].Y, SW_WAYPOINT_LOC1[WaypointId].Z);
                }
                else if (Loc2)// If I was spawned in Location 2
                {
                    if (WaypointId < 2)
                        me->GetMotionMaster()->MovePoint(WaypointId,SW_WAYPOINT_LOC2[WaypointId].X, SW_WAYPOINT_LOC2[WaypointId].Y, SW_WAYPOINT_LOC2[WaypointId].Z);
                }
            }

            if (!Run && Jump && !Combat) // After Jump
            {
                if (me->GetPositionZ() == PLATFORM_Z) // Check that we made it to the platform
                {
                    me->GetMotionMaster()->Clear(); // Stop Movement
                    // Set our new home position so we don't try and run back to the rooftop on reset
                    me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                    Combat = true; // Start Combat
                    Jump = false; // We have already Jumped
                }
            }

            if (Combat && !Run && !Jump) // Our Combat AI
            {
                if (Player* player = me->SelectNearestPlayer(50.0f)) // Try to attack nearest player 1st (Blizz-Like)
                    AttackStart(player);
                else
                    AttackStart(me->FindNearestCreature(NPC_LORD_DARIUS_CROWLEY_C1, 50.0f)); // Attack Darius 2nd - After that, doesn't matter

                if (!UpdateVictim())
                    return;

                if (tEnrage <= diff) // Our Enrage trigger
                {
                    if (me->GetHealthPct() <= 30 && willCastEnrage)
                    {
                        me->MonsterTextEmote(-106, 0);
                        DoCast(me, SPELL_ENRAGE);
                        tEnrage = CD_ENRAGE;
                    }
                }
                else
                    tEnrage -= diff;

                DoMeleeAttackIfReady();
            }
        }

        void MovementInform(uint32 Type, uint32 PointId)
        {
            if (Type != POINT_MOTION_TYPE)
                return;

            if (Loc1)
            {
                CommonWPCount = sizeof(SW_WAYPOINT_LOC1)/sizeof(Waypoint); // Count our waypoints
            }
            else if (Loc2)
            {
                CommonWPCount = sizeof(SW_WAYPOINT_LOC2)/sizeof(Waypoint); // Count our waypoints
            }

            WaypointId = PointId+1; // Increase to next waypoint

            if (WaypointId >= CommonWPCount) // If we have reached the last waypoint
            {
                if (Loc1)
                {
                    me->GetMotionMaster()->MoveJump(-1685.521f + irand(-3, 3), 1458.48f + irand(-3, 3), PLATFORM_Z, 20.0f, 22.0f);
                    Loc1 = false;
                }
                else if (Loc2)
                {
                    me->GetMotionMaster()->MoveJump(-1681.81f + irand(-3, 3), 1445.54f + irand(-3, 3), PLATFORM_Z, 20.0f, 22.0f);
                    Loc2 = false;
                }

                Run = false; // Stop running - Regardless of spawn location
                Jump = true; // Time to Jump - Regardless of spawn location
            }
        }
    };
};

/*######
## npc_worgen_alpha_c1
######*/

class npc_worgen_alpha_c1 : public CreatureScript
{
public:
    npc_worgen_alpha_c1() : CreatureScript("npc_worgen_alpha_c1") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_worgen_alpha_c1AI (creature);
    }

    struct npc_worgen_alpha_c1AI : public ScriptedAI
    {
        npc_worgen_alpha_c1AI(Creature* creature) : ScriptedAI(creature) {}

        uint32 WaypointId, willCastEnrage, tEnrage, CommonWPCount;
        bool Run, Loc1, Loc2, Jump, Combat;

        void Reset()
        {
            Run = Loc1 = Loc2 = Combat= Jump = false;
            WaypointId          = 0;
            tEnrage             = 0;
            willCastEnrage      = urand(0, 1);
        }

        void UpdateAI(uint32 diff)
        {
            if (me->GetPositionX() == -1618.86f && me->GetPositionY() == 1505.68f) // I was spawned in location 1 on NW Rooftop
            {
                Run = true; // Start running across roof
                Loc1 = true;
            }
            else if (me->GetPositionX() == -1562.59f && me->GetPositionY() == 1409.35f) // I was spawned on the North Rooftop
            {
                Run = true; // Start running across roof
                Loc2 = true;
            }

            if (Run && !Jump && !Combat)
            {
                if (Loc1) // If I was spawned in Location 1
                {
                    if (WaypointId < 2)
                        me->GetMotionMaster()->MovePoint(WaypointId,NW_WAYPOINT_LOC1[WaypointId].X, NW_WAYPOINT_LOC1[WaypointId].Y, NW_WAYPOINT_LOC1[WaypointId].Z);
                }
                else if (Loc2)// If I was spawned in Location 2
                {
                    if (WaypointId < 2)
                        me->GetMotionMaster()->MovePoint(WaypointId,N_WAYPOINT_LOC[WaypointId].X, N_WAYPOINT_LOC[WaypointId].Y, N_WAYPOINT_LOC[WaypointId].Z);
                }
            }

            if (!Run && Jump && !Combat) // After Jump
            {
                if (me->GetPositionZ() == PLATFORM_Z) // Check that we made it to the platform
                {
                    me->GetMotionMaster()->Clear(); // Stop Movement
                    // Set our new home position so we don't try and run back to the rooftop on reset
                    me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                    Combat = true; // Start Combat
                    Jump = false; // We have already Jumped
                }
            }

            if (Combat && !Run && !Jump) // Our Combat AI
            {
                if (Player* player = me->SelectNearestPlayer(40.0f)) // Try to attack nearest player 1st (Blizz-Like)
                    AttackStart(player);
                else
                    AttackStart(me->FindNearestCreature(NPC_LORD_DARIUS_CROWLEY_C1, 40.0f)); // Attack Darius 2nd - After that, doesn't matter

                if (!UpdateVictim())
                    return;

                if (tEnrage <= diff) // Our Enrage trigger
                {
                    if (me->GetHealthPct() <= 30 && willCastEnrage)
                    {
                        me->MonsterTextEmote(-106, 0);
                        DoCast(me, SPELL_ENRAGE);
                        tEnrage = CD_ENRAGE;
                    }
                }
                else
                    tEnrage -= diff;

                DoMeleeAttackIfReady();
            }
        }

        void MovementInform(uint32 Type, uint32 PointId)
        {
            if (Type != POINT_MOTION_TYPE)
                return;

            if (Loc1)
            {
                CommonWPCount = sizeof(NW_WAYPOINT_LOC1)/sizeof(Waypoint); // Count our waypoints
            }
            else if (Loc2)
            {
                CommonWPCount = sizeof(N_WAYPOINT_LOC)/sizeof(Waypoint); // Count our waypoints
            }

            WaypointId = PointId+1; // Increase to next waypoint

            if (WaypointId >= CommonWPCount) // If we have reached the last waypoint
            {
                if (Loc1)
                {
                    me->GetMotionMaster()->MoveJump(-1668.52f + irand(-3, 3), 1439.69f + irand(-3, 3), PLATFORM_Z, 20.0f, 22.0f);
                    Loc1 = false;
                }
                else if (Loc2)
                {
                    me->GetMotionMaster()->MoveJump(-1660.17f + irand(-3, 3), 1429.55f + irand(-3, 3), PLATFORM_Z, 22.0f, 20.0f);
                    Loc2 = false;
                }

                Run = false; // Stop running - Regardless of spawn location
                Jump = true; // Time to Jump - Regardless of spawn location
            }
        }
    };
};

/*######
## npc_worgen_alpha_c2
######*/

class npc_worgen_alpha_c2 : public CreatureScript
{
public:
    npc_worgen_alpha_c2() : CreatureScript("npc_worgen_alpha_c2") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_worgen_alpha_c2AI (creature);
    }

    struct npc_worgen_alpha_c2AI : public ScriptedAI
    {
        npc_worgen_alpha_c2AI(Creature* creature) : ScriptedAI(creature) {}

        uint32 WaypointId, willCastEnrage, tEnrage, CommonWPCount;
        bool Run, Jump, Combat;

        void Reset()
        {
            Run = Combat= Jump = false;
            WaypointId          = 0;
            tEnrage             = 0;
            willCastEnrage      = urand(0, 1);
        }

        void UpdateAI(uint32 diff)
        {
            if (me->GetPositionX() == -1732.81f && me->GetPositionY() == 1526.34f) // I was just spawned
            {
                Run = true; // Start running across roof
            }

            if (Run && !Jump && !Combat)
            {
                if (WaypointId < 2)
                    me->GetMotionMaster()->MovePoint(WaypointId,SW_WAYPOINT_LOC1[WaypointId].X, SW_WAYPOINT_LOC1[WaypointId].Y, SW_WAYPOINT_LOC1[WaypointId].Z);
            }

            if (!Run && Jump && !Combat) // After Jump
            {
                if (me->GetPositionZ() == PLATFORM_Z) // Check that we made it to the platform
                {
                    me->GetMotionMaster()->Clear(); // Stop Movement
                    // Set our new home position so we don't try and run back to the rooftop on reset
                    me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                    Combat = true; // Start Combat
                    Jump = false; // We have already Jumped
                }
            }

            if (Combat && !Run && !Jump) // Our Combat AI
            {
                if (Player* player = me->SelectNearestPlayer(40.0f)) // Try to attack nearest player 1st (Blizz-Like)
                    AttackStart(player);
                else
                    AttackStart(me->FindNearestCreature(NPC_LORD_DARIUS_CROWLEY_C1, 40.0f)); // Attack Darius 2nd - After that, doesn't matter

                if (!UpdateVictim())
                    return;

                if (tEnrage <= diff) // Our Enrage trigger
                {
                    if (me->GetHealthPct() <= 30 && willCastEnrage)
                    {
                        me->MonsterTextEmote(-106, 0);
                        DoCast(me, SPELL_ENRAGE);
                        tEnrage = CD_ENRAGE;
                    }
                }
                else
                    tEnrage -= diff;

                DoMeleeAttackIfReady();
            }
        }

        void MovementInform(uint32 Type, uint32 PointId)
        {
            if (Type != POINT_MOTION_TYPE)
                return;

            CommonWPCount = sizeof(SW_WAYPOINT_LOC1)/sizeof(Waypoint); // Count our waypoints

            WaypointId = PointId+1; // Increase to next waypoint

            if (WaypointId >= CommonWPCount) // If we have reached the last waypoint
            {
                me->GetMotionMaster()->MoveJump(-1685.52f + irand(-3, 3), 1458.48f + irand(-3, 3), PLATFORM_Z, 20.0f, 22.0f);
                Run = false; // Stop running
                Jump = true; // Time to Jump
            }
        }
    };
};

class npc_captured_riding_bat : public CreatureScript
{
public:
    npc_captured_riding_bat() : CreatureScript("npc_captured_riding_bat") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_captured_riding_batAI (creature);
    }

    struct npc_captured_riding_batAI : public npc_escortAI
    {
        npc_captured_riding_batAI(Creature* creature) : npc_escortAI(creature) {}

        bool PlayerOn;

        void AttackStart(Unit* /*who*/) {}
        void EnterCombat(Unit* /*who*/) {}
        void EnterEvadeMode() {}

        void Reset()
        {
             PlayerOn       = false;
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply)
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                PlayerOn = true;
                if (apply)
                    Start(false, true, who->GetGUID(), NULL, NULL, true);
            }
        }

        void WaypointReached(uint32 i)
        {
            Player* player = GetPlayerForEscort();
            switch(i)
            {
                case 35:
                    player->ExitVehicle();
                    player->SetClientControl(me, 1);
                    break;
                default:
                    break;
            }
        }

        void JustDied(Unit* /*killer*/)
        {

        }

        void OnCharmed(bool /*apply*/)
        {
        }

        void UpdateAI(uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);
            Player* player = GetPlayerForEscort();

            if (PlayerOn)
            {
                player->SetClientControl(me, 0);
                PlayerOn = false;
            }
        }
    };
};

void AddSC_gilneas()
{
    new npc_sean_dempsey();
    new npc_lord_darius_crowley_c1();
    new npc_worgen_runt_c1();
    new npc_worgen_alpha_c1();
    new npc_worgen_runt_c2();
    new npc_worgen_alpha_c2();
    new npc_captured_riding_bat();
}
