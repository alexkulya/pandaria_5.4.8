#include "NewScriptPCH.h"
#include "throne_of_the_tides.h"
#include "Group.h"

#define GOSSIP_READY "We are ready!"

enum ScriptTexts
{
    SAY_INTRO_1     = 0,
    SAY_INTRO_2     = 1,
    SAY_INTRO_3_1   = 2,
    SAY_PHASE_2_1   = 3,
    SAY_50          = 4,
    SAY_25          = 5,
    SAY_INTRO_3_2   = 6,
    SAY_PHASE_2_2   = 7,
    SAY_PHASE_3_1   = 8,
    SAY_PHASE_3_2   = 9,
    SAY_DEATH       = 10,
    SAY_KILL        = 11,
};

enum Spells
{
    SPELL_BLIGHT_OF_OZUMAT_SELF         = 83585,
    SPELL_BLIGHT_OF_OZUMAT_TRIGGER      = 83518,
    SPELL_BLIGHT_OF_OZUMAT_MISSILE      = 83506,
    SPELL_BLIGHT_OF_OZUMAT_SUMMON_1     = 83524,
    SPELL_BLIGHT_OF_OZUMAT_SUMMON_2     = 83606,
    SPELL_BLIGHT_OF_OZUMAT_DUMMY        = 83672,
    SPELL_BLIGHT_OF_OZUMAT_AURA         = 83525,
    SPELL_BLIGHT_OF_OZUMAT_DMG          = 83561,
    SPELL_BLIGHT_OF_OZUMAT_AOE          = 83607,
    SPELL_BLIGHT_OF_OZUMAT_AOE_DMG      = 83608,
    SPELL_TIDAL_SURGE                   = 76133,
    SPELL_REMOVE_TIDAL_SURGE            = 83909,
        
    // Vicious Mindslasher
    SPELL_BRAIN_SPIKE                   = 83915,
    SPELL_VEIL_OF_SHADOW                = 83926,
    SPELL_SHADOW_BOLT                   = 83914,

    // Unyielding Behemoth
    SPELL_BLIGHT_SPRAY                  = 83985,

    // Faceless Sapper
    SPELL_ENTANGLING_GRASP              = 83463,

    SPELL_ENCOUNTER_COMPLETE            = 95673,
}; 

enum Events
{
    EVENT_INTRO_2               = 1,
    EVENT_INTRO_3_2             = 2,
    EVENT_SUMMON_MURLOC         = 3,
    EVENT_SUMMON_BEHEMOTH       = 4,
    EVENT_SUMMON_MINDLASHER     = 5,
    EVENT_SUMMON_SAPPER         = 6,
    EVENT_SUMMON_BEAST          = 7,
    EVENT_BLIGHT_OF_OZUMAT      = 8,
    EVENT_PLAYER_CHECK          = 9,
    EVENT_SHADOW_BOLT           = 10,
    EVENT_BRAIN_SPIKE           = 11,
    EVENT_VEIL_OF_SHADOW        = 12,
    EVENT_BLIGHT_SPRAY          = 13,
    EVENT_PHASE_2_2             = 14,
    EVENT_SUMMON_OZUMAT         = 15,
};

enum Adds
{
    NPC_BOSS_OZUMAT             = 44566,
    NPC_DEEP_MURLOC_INVADER     = 44658,
    NPC_VICIOUS_MINDLASHER      = 44715,
    NPC_UNYIELDING_BEHEMOTH     = 44648,
    NPC_FACELESS_SAPPER         = 44752,
    NPC_BLIGHT_BEAST            = 44841,
    NPC_BLIGHT_OF_OZUMAT_1      = 44801,
    NPC_BLIGHT_OF_OZUMAT_2      = 44834,
};

enum Actions
{
    ACTION_NEPTULON_START_EVENT = 1,
    ACTION_NEPTULON_START       = 2,
};

enum Achievement
{
    SPELL_KILL_OZUMAT   = 95673,
};

const Position spawnPos[5] = 
{
    {-142.48f, 950.78f, 231.05f, 1.88f},
    {-126.62f, 1015.55f, 230.37f, 4.48f},
    {-171.65f, 1006.13f, 230.67f, 5.90f},
    {-162.53f, 966.55f, 229.43f, 0.65f},
    {-110.35f, 981.47f, 229.90f, 2.83f},
};

class npc_neptulon : public CreatureScript
{
    public:
        npc_neptulon() : CreatureScript("npc_neptulon") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetInstanceAI<npc_neptulonAI>(pCreature);
        }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature)
        {
            if (InstanceScript* pInstance = pCreature->GetInstanceScript())
            {
                if (pInstance->GetBossState(DATA_COMMANDER_ULTHOK) != DONE
                    || pInstance->GetBossState(DATA_OZUMAT) == IN_PROGRESS
                    || pInstance->GetBossState(DATA_OZUMAT) == DONE)
                    return false;

                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_READY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                pPlayer->SEND_GOSSIP_MENU(1, pCreature->GetGUID());
            }
            return true;
        }

        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
        {
            if (InstanceScript* pInstance = pCreature->GetInstanceScript())
            {
                if (pInstance->GetBossState(DATA_COMMANDER_ULTHOK) != DONE
                    || pInstance->GetBossState(DATA_OZUMAT) == IN_PROGRESS
                    || pInstance->GetBossState(DATA_OZUMAT) == DONE)
                    return false;

                pPlayer->PlayerTalkClass->ClearMenus();
                pPlayer->CLOSE_GOSSIP_MENU();
                pCreature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                pInstance->SetBossState(DATA_OZUMAT, IN_PROGRESS);
                pCreature->AI()->DoAction(ACTION_NEPTULON_START);
            }
            return true;
        }

        struct npc_neptulonAI : public ScriptedAI
        {
            npc_neptulonAI(Creature* pCreature) : ScriptedAI(pCreature), summons(me)
            {
                pInstance = pCreature->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
            }

            InstanceScript* pInstance;
            EventMap events;
            SummonList summons;
            uint32 uiMindLasherCount;
            uint32 uiSapperCount;
            bool bActive;
            bool b50;
            bool b25;

            void Reset()
            {
                bActive = false;
                b50 = false;
                b25 = false;
                uiMindLasherCount = 0;
                uiSapperCount = 0;
                me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                events.Reset();
                summons.DespawnAll();
                me->SetHealth(me->GetMaxHealth());
                if (pInstance)
                    if (pInstance->GetBossState(DATA_OZUMAT) != DONE)
                        pInstance->SetBossState(DATA_OZUMAT, NOT_STARTED);
            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_NEPTULON_START_EVENT)
                {
                    me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    bActive = true;
                    Talk(SAY_INTRO_1);
                    events.ScheduleEvent(EVENT_INTRO_2, 7000);
                }
                else if (action == ACTION_NEPTULON_START)
                {
                    bActive = true;
                    Talk(SAY_INTRO_3_1);
                    events.ScheduleEvent(EVENT_INTRO_3_2, 30000);
                    events.ScheduleEvent(EVENT_SUMMON_MURLOC, urand(5000, 8000));
                    events.ScheduleEvent(EVENT_SUMMON_MINDLASHER, 10000);
                    events.ScheduleEvent(EVENT_SUMMON_BEHEMOTH, 20000);
                }
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
            }

            void SummonedCreatureDies(Creature* pCreature, Unit* pKiller)
            {
                summons.Despawn(pCreature);
                if (pCreature->GetEntry() == NPC_VICIOUS_MINDLASHER)
                {
                    uiMindLasherCount++;
                    if (uiMindLasherCount > 2)
                    {
                        Talk(SAY_PHASE_2_2);
                        events.CancelEvent(EVENT_SUMMON_MURLOC);
                        events.ScheduleEvent(EVENT_PHASE_2_2, 10000);
                        events.ScheduleEvent(EVENT_SUMMON_SAPPER, 8000);
                        events.ScheduleEvent(EVENT_SUMMON_BEAST, 14000);
                        events.ScheduleEvent(EVENT_BLIGHT_OF_OZUMAT, urand(9000, 11000));
                    }
                    else
                        events.ScheduleEvent(EVENT_SUMMON_MINDLASHER, urand(10000, 15000));
                }
                else if (pCreature->GetEntry() == NPC_FACELESS_SAPPER)
                {
                    uiSapperCount++;
                    if (uiSapperCount > 2)
                        events.ScheduleEvent(EVENT_SUMMON_OZUMAT, 10000);
                }
                if (pCreature->GetEntry() == NPC_BOSS_OZUMAT)
                {
                    CompleteEncounter();
                    Talk(SAY_PHASE_3_1);
                }
            }

            void CompleteEncounter()
            {
                if (pInstance)
                {
                    // Achievement
                    pInstance->DoUpdateAchievementCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_KILL_OZUMAT, 0, 0, me); 
                    
                    // Guild Achievement
                    Map::PlayerList const &PlayerList = pInstance->instance->GetPlayers();
                    if (!PlayerList.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            if (Player* pPlayer = i->getSource())
                                if (Group* pGroup = pPlayer->GetGroup())
                                    if (pPlayer->GetGuildId() && pGroup->IsGuildGroup(pPlayer->GetGuildId(), true, true))
                                    {
                                        pGroup->UpdateGuildAchievementCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_KILL_OZUMAT, 0, 0, NULL, me);
                                        break;
                                    }
                        }
                    }
                    me->GetMap()->UpdateEncounterState(ENCOUNTER_CREDIT_CAST_SPELL, SPELL_ENCOUNTER_COMPLETE, me); 
                    pInstance->SetBossState(DATA_OZUMAT, DONE);
                }
                DoCast(SPELL_REMOVE_TIDAL_SURGE);
                EnterEvadeMode();
            }

            void DamageTaken(Unit* pAttacker, uint32 &damage)
            {
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    Talk(SAY_DEATH);
                    EnterEvadeMode();
                }
            }

            void UpdateAI(uint32 diff)
            {
                if (!bActive)
                    return;

                if (me->HealthBelowPct(50) && !b50)
                {
                    b50 = true;
                    Talk(SAY_50);
                }
                if (me->HealthBelowPct(25) && !b25)
                {
                    b25 = true;
                    Talk(SAY_25);
                }

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_INTRO_2:
                        Talk(SAY_INTRO_2);
                        bActive = false;
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        break;
                    case EVENT_INTRO_3_2:
                        Talk(SAY_INTRO_3_2);
                        break;
                    case EVENT_PHASE_2_2:
                        Talk(SAY_PHASE_2_1);
                        break;
                    case EVENT_SUMMON_MINDLASHER:
                        if (Creature* pMindlasher = me->SummonCreature(NPC_VICIOUS_MINDLASHER, spawnPos[urand(0, 1)]))
                        {
                            pMindlasher->AddThreat(me, 1.0f);
                            pMindlasher->AI()->AttackStart(me);
                        }
                        break;
                    case EVENT_SUMMON_BEHEMOTH:
                        if (Creature* pBehemoth = me->SummonCreature(NPC_UNYIELDING_BEHEMOTH, spawnPos[urand(0, 1)]))
                        {
                            pBehemoth->AddThreat(me, 1.0f);
                            pBehemoth->AI()->AttackStart(me);
                        }
                        break;
                    case EVENT_SUMMON_SAPPER:
                        for (uint8 i = 2; i < 5; i++)
                            if (Creature* pSapper = me->SummonCreature(NPC_FACELESS_SAPPER, spawnPos[i]))
                                pSapper->CastSpell(me, SPELL_ENTANGLING_GRASP, false);
                        break;
                    case EVENT_SUMMON_BEAST:
                        if (Creature* pBeast = me->SummonCreature(NPC_BLIGHT_BEAST,
                            me->GetPositionX(),
                            me->GetPositionY(),
                            me->GetPositionZ(),
                            me->GetOrientation()))
                            if (Player* pTarget = GetRandomPlayer())
                                pBeast->AI()->AttackStart(pTarget);
                        events.ScheduleEvent(EVENT_SUMMON_BEAST, urand(15000, 24000));
                        break;
                    case EVENT_SUMMON_MURLOC:
                        for (uint8 i = 0; i < 5; i++)
                        {
                            if (Creature* pMurloc = me->SummonCreature(NPC_DEEP_MURLOC_INVADER, spawnPos[urand(0, 1)]))
                            {
                                pMurloc->AddThreat(me, 1.0f);
                                pMurloc->AI()->AttackStart(me);
                            }
                        }
                        events.ScheduleEvent(EVENT_SUMMON_MURLOC, urand(10000, 17000));
                        break;
                    case EVENT_BLIGHT_OF_OZUMAT:
                        if (Player* pTarget = GetRandomPlayer())
                            DoCast(pTarget, SPELL_BLIGHT_OF_OZUMAT_MISSILE);
                        events.ScheduleEvent(EVENT_BLIGHT_OF_OZUMAT, urand(10000, 18000));
                        break;
                    case EVENT_SUMMON_OZUMAT:
                        DoCast(SPELL_BLIGHT_OF_OZUMAT_SUMMON_2);
                        DoCast(SPELL_TIDAL_SURGE);
                        me->SummonCreature(NPC_BOSS_OZUMAT, -92.70f, 916.18f, 273.14f, 2.23f);
                        break;
                    }
                }
            }         

            Player* GetRandomPlayer()
            {
                std::list<Player*> pAliveList;
                Map::PlayerList const &pPlayerList = me->GetMap()->GetPlayers();
                if (!pPlayerList.isEmpty())
                    for (Map::PlayerList::const_iterator itr = pPlayerList.begin(); itr != pPlayerList.end(); ++itr)
                        if (itr->getSource()->IsAlive())
                            pAliveList.push_back(itr->getSource());

                if (!pAliveList.empty())
                {
                    std::list<Player*>::const_iterator itr = pAliveList.begin();
                    std::advance(itr, rand() % pAliveList.size());
                    return (*itr);
                }
                return NULL;
            }

            bool isPlayerAlive()
            {
                Map::PlayerList const &pPlayerList = me->GetMap()->GetPlayers();

                if (!pPlayerList.isEmpty())
                    for (Map::PlayerList::const_iterator itr = pPlayerList.begin(); itr != pPlayerList.end(); ++itr)
                        if (itr->getSource()->IsAlive())
                            return true;
                return false;
            };
        };        
};

class npc_vicious_mindslasher : public CreatureScript
{
    public:
        npc_vicious_mindslasher() : CreatureScript("npc_vicious_mindslasher") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetInstanceAI<npc_vicious_mindslasherAI>(pCreature);
        }

        struct npc_vicious_mindslasherAI : public ScriptedAI
        {
            npc_vicious_mindslasherAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;

            void Reset()
            {
                events.Reset();
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_BRAIN_SPIKE, urand(6000, 10000));
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_VEIL_OF_SHADOW, urand(10000, 15000));
                events.ScheduleEvent(EVENT_SHADOW_BOLT, 2000);
            }

            void KilledUnit(Unit* victim)
            {
                if (pInstance)
                    if (Creature* pNeptulon = ObjectAccessor::GetCreature(*me, pInstance->GetData64(DATA_NEPTULON)))
                        pNeptulon->AI()->Talk(SAY_KILL);
            }

            void UpdateAI(uint32 diff)
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
                    case EVENT_BRAIN_SPIKE:
                        DoCast(me, SPELL_BRAIN_SPIKE);
                        events.ScheduleEvent(EVENT_BRAIN_SPIKE, urand(15000, 20000));
                        break;
                    case EVENT_VEIL_OF_SHADOW:
                        DoCast(me->getVictim(), SPELL_VEIL_OF_SHADOW);
                        events.ScheduleEvent(EVENT_VEIL_OF_SHADOW, urand(13000, 20000));
                        break;
                    case EVENT_SHADOW_BOLT:
                        DoCast(me->getVictim(), SPELL_SHADOW_BOLT);
                        events.ScheduleEvent(EVENT_SHADOW_BOLT, 2000);
                        break;
                    }
                }            
                DoMeleeAttackIfReady();
            }
        };
};

class npc_unyielding_behemoth : public CreatureScript
{
    public:
        npc_unyielding_behemoth() : CreatureScript("npc_unyielding_behemoth") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetInstanceAI<npc_unyielding_behemothAI>(pCreature);
        }

        struct npc_unyielding_behemothAI : public ScriptedAI
        {
            npc_unyielding_behemothAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                pInstance = pCreature->GetInstanceScript();
            }

            InstanceScript* pInstance;
            EventMap events;

            void Reset()
            {
                events.Reset();
            }

            void KilledUnit(Unit* victim)
            {
                if (pInstance)
                    if (Creature* pNeptulon = ObjectAccessor::GetCreature(*me, pInstance->GetData64(DATA_NEPTULON)))
                        pNeptulon->AI()->Talk(SAY_KILL);
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_BLIGHT_SPRAY, urand(8000, 12000));
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
                    case EVENT_BLIGHT_SPRAY:
                        DoCast(me, SPELL_BLIGHT_SPRAY);
                        events.ScheduleEvent(EVENT_BLIGHT_SPRAY, urand(15000, 23000));
                        break;
                    }
                }            
                DoMeleeAttackIfReady();
            }
        };
};

class npc_faceless_sapper : public CreatureScript
{
    public:
        npc_faceless_sapper() : CreatureScript("npc_faceless_sapper") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetInstanceAI<npc_faceless_sapperAI>(pCreature);
        }

        struct npc_faceless_sapperAI : public ScriptedAI
        {
            npc_faceless_sapperAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset()
            {

            }

            void UpdateAI(uint32 diff)
            {   
            }
        };
};

class npc_blight_of_ozumat : public CreatureScript
{
    public:
        npc_blight_of_ozumat() : CreatureScript("npc_blight_of_ozumat") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetInstanceAI<npc_blight_of_ozumatAI>(pCreature);
        }

        struct npc_blight_of_ozumatAI : public Scripted_NoMovementAI
        {
            npc_blight_of_ozumatAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset()
            {
                DoCast(me, SPELL_BLIGHT_OF_OZUMAT_AURA);
            }

            void UpdateAI(uint32 diff)
            {
            }
        };
};

class npc_ozumat : public CreatureScript
{
    public:
        npc_ozumat() : CreatureScript("npc_ozumat") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetInstanceAI<npc_ozumatAI>(pCreature);
        }

        struct npc_ozumatAI : public Scripted_NoMovementAI
        {
            npc_ozumatAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset()
            {
                DoCast(me, SPELL_BLIGHT_OF_OZUMAT_DUMMY);
            }
        };
};

class npc_blight_of_ozumat_final : public CreatureScript
{
    public:
        npc_blight_of_ozumat_final() : CreatureScript("npc_blight_of_ozumat_final") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetInstanceAI<npc_blight_of_ozumat_finalAI>(pCreature);
        }

        struct npc_blight_of_ozumat_finalAI : public Scripted_NoMovementAI
        {
            npc_blight_of_ozumat_finalAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->SetReactState(REACT_PASSIVE);
            }

            void Reset()
            {
                DoCast(me, SPELL_BLIGHT_OF_OZUMAT_AOE);
            }
        };
};

class at_tott_ozumat : public AreaTriggerScript
{
    public:
        at_tott_ozumat() : AreaTriggerScript("at_tott_ozumat") { }

        bool OnTrigger(Player* pPlayer, const AreaTriggerEntry* /*pAt*/, bool /*enter*/)
        {
            if (InstanceScript* pInstance = pPlayer->GetInstanceScript())
            {
                if (pInstance->GetData(DATA_NEPTULON_EVENT) != DONE
                    && pInstance->GetBossState(DATA_OZUMAT) != IN_PROGRESS
                    && pInstance->GetBossState(DATA_OZUMAT) != DONE)
                {
                    pInstance->SetData(DATA_NEPTULON_EVENT, DONE);
                    if (Creature* pNeptulon = ObjectAccessor::GetCreature(*pPlayer, pInstance->GetData64(DATA_NEPTULON)))
                    {
                        pNeptulon->AI()->DoAction(ACTION_NEPTULON_START_EVENT);
                    }
                }
            }
            return true;
        }
};

void AddSC_boss_ozumat()
{
    new npc_neptulon();
    new npc_vicious_mindslasher();
    new npc_unyielding_behemoth();
    new npc_faceless_sapper();
    new npc_blight_of_ozumat();
    new npc_ozumat();
    new npc_blight_of_ozumat_final();
    new at_tott_ozumat();
}