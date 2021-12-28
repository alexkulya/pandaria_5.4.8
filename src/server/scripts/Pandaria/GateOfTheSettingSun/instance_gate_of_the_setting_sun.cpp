#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "gate_of_the_setting_sun.h"

static std::vector<DoorData> const doorData =
{
    { GO_KIPTILAK_WALLS,      DATA_KIPTILAK, DOOR_TYPE_ROOM,    BOUNDARY_E    },
    { GO_KIPTILAK_WALLS,      DATA_KIPTILAK, DOOR_TYPE_ROOM,    BOUNDARY_N    },
    { GO_KIPTILAK_WALLS,      DATA_KIPTILAK, DOOR_TYPE_ROOM,    BOUNDARY_S    },
    { GO_KIPTILAK_WALLS,      DATA_KIPTILAK, DOOR_TYPE_ROOM,    BOUNDARY_W    },
    { GO_KIPTILAK_EXIT_DOOR,  DATA_KIPTILAK, DOOR_TYPE_PASSAGE, BOUNDARY_N    },
    { GO_RIMAK_AFTER_DOOR,    DATA_RIMOK,    DOOR_TYPE_ROOM,    BOUNDARY_S    },
    { GO_RAIGONN_DOOR,        DATA_RAIGONN,  DOOR_TYPE_ROOM,    BOUNDARY_NE   },
    { GO_RAIGONN_AFTER_DOOR,  DATA_RAIGONN,  DOOR_TYPE_PASSAGE, BOUNDARY_E    },
};

static std::vector<ScenarioBosses> const scenarioBosses =
{
    { DATA_KIPTILAK, CRITERIA_KIPTILAK },
    { DATA_GADOK,    CRITERIA_GADOK    },
    { DATA_RIMOK,    CRITERIA_RIMOK    },
    { DATA_RAIGONN,  CRITERIA_RAIGONN  },
};

class instance_gate_of_the_setting_sun : public InstanceMapScript
{
    public:
        instance_gate_of_the_setting_sun() : InstanceMapScript("instance_gate_of_the_setting_sun", 962) { }

        enum eEvents
        {
            EVENT_ACTIVATE_SPAWNER   = 1
        };

        enum eSpells
        {
            SPELL_SPAWNER = 115141
        };

        struct instance_gate_of_the_setting_sun_InstanceMapScript : public InstanceScript
        {
            instance_gate_of_the_setting_sun_InstanceMapScript(Map* map) : InstanceScript(map) { }

            void Initialize() override
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                memset(dataStorage, 0, MAX_DATA * sizeof(uint32));

                cornerAstate          = NOT_STARTED;
                cornerBstate          = NOT_STARTED;
                cornerCstate          = NOT_STARTED;
                firstDoorstate        = NOT_STARTED;
                braiserState          = NOT_STARTED;
                fallEvent             = false;
                playersInInstanceCnt  = 0;
                kiptilakGuid          = 0;
                gadokGuid             = 0;
                rimokGuid             = 0;
                raigonnGuid           = 0;
                raigonWeakGuid        = 0;
                explosionTarget1GUID  = 0;
                explosionTarget2GUID  = 0;
                explosionTarget3GUID  = 0;
                firstDoorGuid         = 0;
                wallCGuid             = 0;
                wallAGUID             = 0;
                wallBGUID             = 0;
                defenderAGUID         = 0;
                defenderBGUID         = 0;
                traineeGUID           = 0;
                fireSignalGuid        = 0;
                greatDoorGUID         = 0;
                greatDoor2GUID        = 0;

                bombarderGuids.clear();
                fallDefendersGUIDS.clear();
                bombStalkerGuids.clear();
                mantidBombsGUIDs.clear();
                rimokAddGenetarorsGUIDs.clear();
                artilleryGUIDs.clear();
                artilleryToWallGUIDs.clear();
                ropeGUIDs.clear();
                spawnerTargetGUIDs.clear();

                if (instance->IsChallengeDungeon())
                    LoadScenarioInfo(scenarioBosses, CRITERIA_ENEMIES);
            }

            void OnPlayerEnter(Player* player) override
            {
                if (instance->IsChallengeDungeon())
                    SendChallengeInfo(player, SCENARIO_ID);

                if (playersInInstanceCnt == 0)
                    events.ScheduleEvent(EVENT_ACTIVATE_SPAWNER, 1 * IN_MILLISECONDS);

                ++playersInInstanceCnt;
            }

            void OnPlayerLeave(Player* /*player*/)
            {
                if (--playersInInstanceCnt == 0)
                {
                    for (auto&& spawner : spawnerTargetGUIDs)
                         if (auto cSpawner = instance->GetCreature(spawner))
                              cSpawner->RemoveAura(SPELL_SPAWNER);
                }
            }

            void Update(uint32 diff) override
            {
                events.Update(diff);

                if (events.ExecuteEvent() == EVENT_ACTIVATE_SPAWNER)
                {
                    for (auto&& spawner : spawnerTargetGUIDs)
                         if (auto cSpawner = instance->GetCreature(spawner))
                             if (!cSpawner->HasAura(SPELL_SPAWNER))
                                   cSpawner->CastSpell(cSpawner, SPELL_SPAWNER, false);
                }

                ScheduleBeginningTimeUpdate(diff);
                ScheduleChallengeStartup(diff);
                ScheduleChallengeTimeUpdate(diff);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                if (instance->IsChallengeDungeon() && creature->isDead())
                    creature->Respawn();

                switch (creature->GetEntry())
                {
                    case NPC_EXPLOSION_TARGET_2:
                        explosionTarget2GUID = creature->GetGUID();
                        break;
                    case NPC_KIPTILAK:
                        kiptilakGuid = creature->GetGUID();
                        break;
                    case NPC_GADOK:
                        gadokGuid = creature->GetGUID();
                        break;
                    case NPC_RIMOK:
                        rimokGuid = creature->GetGUID();
                        break;
                    case NPC_RAIGONN:
                        raigonnGuid = creature->GetGUID();
                        break;
                    case NPC_KRITHUK_BOMBARDER:
                        bombarderGuids.push_back(creature->GetGUID());
                        break;
                    case NPC_FALL_DEFENDER:
                        fallDefendersGUIDS.push_back(creature->GetGUID());
                        break;
                    case NPC_BOMB_STALKER:
                        bombStalkerGuids.push_back(creature->GetGUID());
                        break;
                    case NPC_ADD_GENERATOR:
                        rimokAddGenetarorsGUIDs.push_back(creature->GetGUID());
                        break;
                    case NPC_ARTILLERY:
                        artilleryGUIDs.push_back(creature->GetGUID());
                        break;
                    case NPC_ARTILLERY_TO_WALL:
                        artilleryToWallGUIDs.push_back(creature->GetGUID());
                        break;
                    case NPC_EXPLOSION_TARGET_1:
                        explosionTarget1GUID = creature->GetGUID();
                        break;
                    case NPC_EXPLOSION_TARGET_3:
                        explosionTarget3GUID = creature->GetGUID();
                        break;
                    case NPC_SERPENTS_SPINE_DEF_A:
                        defenderAGUID = creature->GetGUID();
                        break;
                    case NPC_SERPENTS_SPINE_DEF_B:
                        defenderBGUID = creature->GetGUID();
                        break;
                    case NPC_SERPENTS_SPINE_TRAINEE:
                        traineeGUID = creature->GetGUID();
                        break;
                    case NPC_ARCHER_TARGET_SPAWNER:
                        spawnerTargetGUIDs.push_back(creature->GetGUID());
                        creature->setActive(true);
                        break;
                    case NPC_ROPE:
                        ropeGUIDs.push_back(creature->GetGUID());
                        creature->SetDisplayId(43636);
                        break;
                    case NPC_ROPE_SEAT:
                        creature->SetDisplayId(39633);
                        break;
                    case NPC_EXPLOSION_BUNNY_N_M:
                    case NPC_EXPLOSION_BUNNY_S_M:
                    case NPC_EXPLOSION_BUNNY_E_M:
                    case NPC_EXPLOSION_BUNNY_W_M:
                    case NPC_EXPLOSION_BUNNY_N_P:
                    case NPC_EXPLOSION_BUNNY_S_P:
                    case NPC_EXPLOSION_BUNNY_E_P:
                    case NPC_EXPLOSION_BUNNY_W_P:
                        creature->SetDisplayId(38615); // invisible
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        break;
                }
            }

            void OnCreatureRemove(Creature* creature) override
            {
                if (creature->GetEntry() == NPC_KRITHUK_BOMBARDER)
                {
                    for (std::list<uint64>::iterator it = bombarderGuids.begin(); it != bombarderGuids.end(); ++it)
                    {
                        if (*it == creature->GetGUID())
                        {
                            bombarderGuids.erase(it);
                            break;
                        }
                    }
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_KIPTILAK_ENTRANCE_DOOR:
                        firstDoorGuid = go->GetGUID();
                        break;
                    case GO_SIGNAL_FIRE:
                        fireSignalGuid = go->GetGUID();
                        break;
                    case GO_KIPTILAK_WALLS:
                    case GO_RIMAK_AFTER_DOOR:
                    case GO_RAIGONN_AFTER_DOOR:
                    case GO_KIPTILAK_EXIT_DOOR:
                        AddDoor(go, true);
                        return;
                    case GO_KIPTILAK_MANTID_BOMBS:
                        mantidBombsGUIDs.push_back(go->GetGUID());
                        return;
                    case GO_WALL_C:
                        wallCGuid = go->GetGUID();
                        return;
                    case GO_WALL_A:
                        wallAGUID = go->GetGUID();
                        break;
                    case GO_WALL_B:
                        wallBGUID = go->GetGUID();
                        break;
                    case GO_GREAT_DOOR_PHASE_1:
                        greatDoorGUID = go->GetGUID();
                        break;
                    case GO_GREAT_DOOR_PHASE_2:
                        greatDoor2GUID = go->GetGUID();
                        break;
                    case GO_CHALLENGE_DOOR:
                        SetChallengeDoorGuid(go->GetGUID());
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_KIPTILAK:
                        {
                            if (state == DONE)
                            {
                                for (auto&& itr : mantidBombsGUIDs)
                                    if (GameObject* bomb = instance->GetGameObject(itr))
                                        bomb->RemoveFromWorld(); // Set Invisible
                            }
                        }
                        break;
                    case DATA_RIMOK:
                        {
                            uint8 generatorsCount = 0;

                            for (auto&& itr : rimokAddGenetarorsGUIDs)
                            {
                                 if (Creature* generator = instance->GetCreature(itr))
                                 {
                                     if (generator->AI())
                                     {
                                         // There is 7 add generators, the middle one spawn saboteur
                                         if (state == IN_PROGRESS && (++generatorsCount == 4))
                                            generator->AI()->DoAction(SPECIAL);
                                         else
                                            generator->AI()->DoAction(state);
                                     }
                                 }
                            }

                            if (state == DONE)
                            {
                                if (GameObject* go = instance->GetGameObject(wallCGuid))
                                     go->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);

                                if (Creature* deffender = instance->GetCreature(defenderAGUID))
                                   if (deffender->IsAIEnabled)
                                       deffender->AI()->DoAction(2);

                                for (auto&& ropeGUID: ropeGUIDs)
                                    if (Creature* rope = instance->GetCreature(ropeGUID))
                                         if (rope->IsAIEnabled)
                                             rope->AI()->DoAction(1);

                                if (GameObject* go = instance->GetGameObject(greatDoorGUID))
                                    go->RemoveFromWorld();

                                if (GameObject* go = instance->GetGameObject(greatDoor2GUID))
                                    go->RemoveFromWorld();
                             }
                        }
                        break;
                }

              return true;
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (instance->IsChallengeDungeon() && !IsChallengeModeCompleted())
                    if (Creature* creature = unit->ToCreature())
                        if (creature->GetEntry() != NPC_KRITHIK_GLIDER && creature->GetEntry() != NPC_SERPENTS_SPINE_DEFENDER)
                            UpdateConditionInfo(creature, ENEMIES_COUNT);
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_OPEN_FIRST_DOOR:
                    {
                        firstDoorstate = data;
                        HandleGameObject(firstDoorGuid, true);

                        if (GameObject* firstDoor = instance->GetGameObject(firstDoorGuid))
                        {

                            if (Creature* trigger = firstDoor->SummonTrigger(firstDoor->GetPositionX(), firstDoor->GetPositionY(), firstDoor->GetPositionZ(), 0, 500))
                            {
                                std::list<Creature*> defensorList;
                                GetCreatureListWithEntryInGrid(defensorList, trigger, NPC_SERPENTS_SPINE_DEFENDER, 20.0f);

                                trigger->CastSpell(trigger, 115456); // Explosion

                                for (auto&& itr : defensorList)
                                {
                                    uint8 random = rand() % 2;

                                    float posX = random ? 814.0f : 640.0f;
                                    float posY = random ? 2102.0f : 2112.0f;
                                    itr->KnockbackFrom(posX, posY, 25.0f, 20.0f);
                                    itr->DespawnOrUnsummon(1000);
                                }
                            }
                        }
                        break;
                    }
                    case DATA_CORNER_A:
                        cornerAstate = data;
                        if (data == DONE)
                        {
                            if (GameObject* cornerA = instance->GetGameObject(wallAGUID))
                                cornerA->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                        }
                        break;
                    case DATA_CORNER_B:
                        cornerBstate = data;
                        if (data == DONE)
                        {
                            if (GameObject* cornerB = instance->GetGameObject(wallBGUID))
                                cornerB->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                        }
                        break;
                    case DATA_CORNER_C:
                        cornerCstate = data;
                        if (data == DONE)
                        {
                            if (GameObject* cornerC = instance->GetGameObject(wallCGuid))
                                cornerC->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);
                        }
                        break;
                    case DATA_FALL_DEFENDERS:
                        if (data == DONE)
                        {
                            if (!fallEvent)
                            {
                                fallEvent = true;
                                for (auto&& itr : fallDefendersGUIDS)
                                {
                                    if (Creature* defender = instance->GetCreature(itr))
                                    {
                                        if (defender->IsAIEnabled)
                                            defender->AI()->Talk(0);

                                        defender->GetMotionMaster()->MoveJump(848.846f, 2309.806f, 323.225f, 20.0f, 25.0f);
                                        defender->DespawnOrUnsummon(defender->GetSplineDuration());
                                    }
                                }

                                for (int i = 0; i < 3; ++i)
                                {
                                    if (Creature* krithik = instance->SummonCreature(NPC_KRITHIK_INFILTRATOR, SummonPositionsFallEvent[i]))
                                    {
                                        krithik->GetMotionMaster()->MoveJump(JumpPositionsFallEvent[i][0], JumpPositionsFallEvent[i][1], JumpPositionsFallEvent[i][2], 60.0f, 41.0f);
                                        krithik->SetHomePosition(JumpPositionsFallEvent[i][0], JumpPositionsFallEvent[i][1], JumpPositionsFallEvent[i][2], krithik->GetOrientation());
                                    }
                                }

                                if (Creature* krithik = instance->SummonCreature(NPC_KRITHIK_WND_SHAPER, SummonPositionsFallEvent[3]))
                                {
                                    krithik->GetMotionMaster()->MoveJump(JumpPositionsFallEvent[3][0], JumpPositionsFallEvent[3][1], JumpPositionsFallEvent[3][2], 60.0f, 41.0f);
                                    krithik->SetHomePosition(JumpPositionsFallEvent[3][0], JumpPositionsFallEvent[3][1], JumpPositionsFallEvent[3][2], krithik->GetOrientation());
                                }
                            }
                        }
                        break;
                    case DATA_ARTILLERY_STATE:
                        dataStorage[type] = data;
                        switch (data)
                        {
                            case NOT_STARTED:
                                for (auto&& itr : artilleryGUIDs)
                                {
                                    if (Creature* artillery = instance->GetCreature(itr))
                                    {
                                        artillery->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE, true);
                                        artillery->ApplyModFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK, false);
                                    }
                                }

                                for (auto&& itr : artilleryToWallGUIDs)
                                {
                                    if (Creature* artillery = instance->GetCreature(itr))
                                    {
                                        artillery->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE, false);
                                        artillery->ApplyModFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK, true);
                                    }
                                }
                                break;
                            case SPECIAL:
                                for (auto&& itr : artilleryGUIDs)
                                {
                                    if (Creature* artillery = instance->GetCreature(itr))
                                    {
                                        artillery->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE, true);
                                        artillery->ApplyModFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK, false);
                                    }
                                }
                                break;
                            case IN_PROGRESS:
                                for (auto&& itr : artilleryGUIDs)
                                {
                                    if (Creature* artillery = instance->GetCreature(itr))
                                    {
                                        artillery->ApplyModFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK, true);
                                        artillery->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE, false);
                                    }
                                }

                                for (auto&& itr : artilleryToWallGUIDs)
                                {
                                    if (Creature* artillery = instance->GetCreature(itr))
                                    {
                                        artillery->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE, true);
                                        artillery->ApplyModFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK, false);
                                    }
                                }
                                break;
                        }
                        break;
                    case DATA_BRASIER_CLICKED:
                        braiserState = data;
                        break;
                    default:
                        if (type < MAX_DATA)
                            dataStorage[type] = data;
                        break;
                }

                if (data == DONE)
                    SaveToDB();
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_OPEN_FIRST_DOOR:
                        return firstDoorstate;
                    case DATA_CORNER_A:
                        return cornerAstate;
                    case DATA_CORNER_B:
                        return cornerBstate;
                    case DATA_CORNER_C:
                        return cornerCstate;
                    case DATA_BRASIER_CLICKED:
                        return braiserState;
                    default:
                        if (type < MAX_DATA)
                            return dataStorage[type];
                        break;
                }

                return 0;
            }

            void SetData64(uint32 type, uint64 data) override
            {
                switch (type)
                {
                    case NPC_WEAK_SPOT:
                        raigonWeakGuid = data;
                        break;
                }
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_KIPTILAK:
                        return kiptilakGuid;
                    case DATA_GADOK:
                        return gadokGuid;
                    case DATA_RIMOK:
                        return rimokGuid;
                    case DATA_RAIGONN:
                        return raigonnGuid;
                    case NPC_WEAK_SPOT:
                        return raigonWeakGuid;
                    case DATA_RANDOM_BOMBARDER:
                        return Trinity::Containers::SelectRandomContainerElement(bombarderGuids);
                    case DATA_RANDOM_BOMB_STALKER:
                        return Trinity::Containers::SelectRandomContainerElement(bombStalkerGuids);
                    case DATA_CORNER_A:
                        return explosionTarget1GUID;
                    case DATA_CORNER_B:
                        return explosionTarget2GUID;
                    case DATA_CORNER_C:
                        return explosionTarget3GUID;
                    case DATA_DEFENDER_A:
                        return defenderAGUID;
                    case DATA_DEFENDER_B:
                        return defenderBGUID;
                    case DATA_TRAINEE:
                        return traineeGUID;
                    case DATA_SIGNAL_FIRE:
                        return fireSignalGuid;
                    case DATA_ROPE:
                        for (auto&& guid : ropeGUIDs)
                             return guid;
                }

                return 0;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "G S S " << GetBossSaveData() << firstDoorstate << " " << cornerAstate << " " << cornerBstate << " " << cornerCstate << " " << braiserState;

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* in) override
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(in);

                char dataHead1, dataHead2, dataHead3;

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2 >> dataHead3;

                if (dataHead1 == 'G' && dataHead2 == 'S' && dataHead3 == 'S')
                {
                    for (uint8 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;

                        SetBossState(i, EncounterState(tmpState));
                    }

                    uint32 temp = 0;
                    loadStream >> temp;
                    firstDoorstate = temp ? DONE : NOT_STARTED;

                    loadStream >> temp;
                    cornerAstate = temp ? DONE : NOT_STARTED;

                    loadStream >> temp;
                    cornerBstate = temp ? DONE : NOT_STARTED;

                    loadStream >> temp;
                    cornerCstate = temp ? DONE : NOT_STARTED;

                    loadStream >> temp;
                    braiserState = temp ? DONE : NOT_STARTED;
                }
                else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            EventMap events;
            bool fallEvent;
            uint8 playersInInstanceCnt;
            uint32 cornerAstate;
            uint32 cornerBstate;
            uint32 cornerCstate;
            uint32 firstDoorstate;
            uint32 braiserState;
            uint64 kiptilakGuid;
            uint64 gadokGuid;
            uint64 rimokGuid;
            uint64 raigonnGuid;
            uint64 raigonWeakGuid;
            uint64 explosionTarget1GUID;
            uint64 explosionTarget2GUID;
            uint64 explosionTarget3GUID;
            uint64 firstDoorGuid;
            uint64 fireSignalGuid;
            uint64 wallAGUID;
            uint64 wallBGUID;
            uint64 wallCGuid;
            uint64 traineeGUID;
            uint64 defenderAGUID;
            uint64 defenderBGUID;
            uint64 greatDoorGUID;
            uint64 greatDoor2GUID;
            uint64 elevatorGUID;
            uint32 dataStorage[MAX_DATA];
            std::list<uint64> bombarderGuids;
            std::list<uint64> fallDefendersGUIDS;
            std::list<uint64> bombStalkerGuids;
            std::list<uint64> mantidBombsGUIDs;
            std::list<uint64> rimokAddGenetarorsGUIDs;
            std::list<uint64> artilleryGUIDs;
            std::list<uint64> artilleryToWallGUIDs;
            std::list<uint64> ropeGUIDs;
            std::list<uint64> spawnerTargetGUIDs;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_gate_of_the_setting_sun_InstanceMapScript(map);
        }
};

void AddSC_instance_gate_of_the_setting_sun()
{
    new instance_gate_of_the_setting_sun();
}

