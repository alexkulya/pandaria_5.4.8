#include "ScriptPCH.h"
#include "deadmines.h"

#define MAX_ENCOUNTER 6

static std::vector<DoorData> const doordata =
{
    {GO_FACTORY_DOOR,   DATA_GLUBTOK,   DOOR_TYPE_PASSAGE,    BOUNDARY_NONE},
    {GO_MAST_ROOM_DOOR, DATA_HELIX,     DOOR_TYPE_PASSAGE,    BOUNDARY_NONE},
    {GO_HEAVY_DOOR,     DATA_HELIX,     DOOR_TYPE_ROOM,       BOUNDARY_NONE},
    {GO_FOUNDRY_DOOR,   DATA_FOEREAPER, DOOR_TYPE_PASSAGE,    BOUNDARY_NONE},
    {GO_HEAVY_DOOR_2,   DATA_FOEREAPER, DOOR_TYPE_ROOM,       BOUNDARY_NONE},
};

class instance_deadmines : public InstanceMapScript
{
    public:
        instance_deadmines() : InstanceMapScript("instance_deadmines", 36) { }

        struct instance_deadmines_InstanceMapScript : public InstanceScript
        {
            instance_deadmines_InstanceMapScript(Map* map) : InstanceScript(map) 
            {
                SetBossNumber(MAX_ENCOUNTER);
                LoadDoorData(doordata);
                
                uiGlubtokGUID        = 0;
                uiHelixGUID          = 0;
                uiOafGUID            = 0;
                uiFoereaperGUID      = 0;
                uiAdmiralGUID        = 0;
                uiCaptainGUID        = 0;

                GoblinTeleporterGUID = 0;
                HeavyDoorGUID        = 0;
                HeavyDoor2GUID       = 0;
                IronCladDoorGUID     = 0;
                DefiasCannonGUID     = 0;
                DoorLeverGUID        = 0;
                TeamInInstance       = 0;
                uiVanessaEvent       = 0;
                OverchargeCount      = 0;
                State                = CANNON_NOT_USED;
                instance->SetWorldState(WORLDSTATE_PROTOTYPE_PRODIGY, 1);
            };

            void OnPlayerEnter(Player* player) override
            {
                if (!TeamInInstance)
                    TeamInInstance = player->GetTeam();
            }

            void OnCreatureCreate(Creature* creature) override
            {
                if (!TeamInInstance)
                {
                    Map::PlayerList const &players = instance->GetPlayers();
                    if (!players.isEmpty())
                        if (Player* player = players.begin()->GetSource())
                            TeamInInstance = player->GetTeam();
                }

                switch (creature->GetEntry())
                {
                    case NPC_GLUBTOK:
                        uiGlubtokGUID = creature->GetGUID();
                        break;
                    case NPC_HELIX_GEARBREAKER:
                        uiHelixGUID = creature->GetGUID();
                        break;
                    case NPC_LUMBERING_OAF:
                        uiOafGUID = creature->GetGUID();
                        break;
                    case NPC_FOE_REAPER_5000:
                        uiFoereaperGUID = creature->GetGUID();
                        break;
                    case NPC_ADMIRAL_RIPSNARL:
                        uiAdmiralGUID = creature->GetGUID();
                        break;
                    case NPC_CAPTAIN_COOKIE:
                        uiCaptainGUID = creature->GetGUID();
                        break;
                    case NPC_KAGTHA:
                        if (TeamInInstance == ALLIANCE)
                            creature->SetVisible(false);
                        break;
                    case NPC_SLINKY_SHARPSHIV:
                        if (TeamInInstance == ALLIANCE)
                            creature->SetVisible(false);
                        break;
                    case NPC_MISS_MAYHEM:
                        if (TeamInInstance == ALLIANCE)
                            creature->SetVisible(false);
                        break;
                    case NPC_MAYHEM_REAPER:
                        if (TeamInInstance == ALLIANCE)
                            creature->SetVisible(false);
                        break;
                    case NPC_HAND_ASSASIN:
                        if (TeamInInstance == ALLIANCE)
                            creature->SetVisible(false);
                        break;
                    case NPC_HORATIO_LAINE:
                        if (TeamInInstance == HORDE)
                            creature->SetVisible(false);
                        break;
                    case NPC_DEFENDER:
                        if (TeamInInstance == HORDE)
                            creature->SetVisible(false);
                        break;
                    case NPC_INVESTIGATOR:
                        if (TeamInInstance == HORDE)
                            creature->SetVisible(false);
                        break;
                    case NPC_CRIME_SCENE_BOT:
                        if (TeamInInstance == HORDE)
                            creature->SetVisible(false);
                        break;
                }
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (unit->ToCreature())
                {
                    switch (unit->GetEntry())
                    {
                        case NPC_MINING_POWDER:
                            unit->CastSpell(unit, SPELL_EXPLODE_MINE, false);
                            break;
                        case NPC_DEFIAS_WATCHER:
                        case NPC_DEFIAS_REAPER:
                            OverchargeCount++;

                            if (OverchargeCount >= 4)
                                if (Creature* FoeReaper = instance->GetCreature(GetData64(DATA_FOEREAPER)))
                                    FoeReaper->RemoveAurasDueToSpell(SPELL_OFF_LINE);
                            break;
                    }
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_HEAVY_DOOR:
                        HeavyDoorGUID = go->GetGUID();
                        AddDoor(go, true);
                        break;
                    case GO_HEAVY_DOOR_2:
                        HeavyDoor2GUID = go->GetGUID();
                        AddDoor(go, true);
                        break;
                    case GO_FACTORY_DOOR:
                    case GO_MAST_ROOM_DOOR:
                    case GO_FOUNDRY_DOOR:
                        AddDoor(go, true);
                        break;
                    case GO_GOBLIN_TELEPORTER:
                        GoblinTeleporterGUID = go->GetGUID();
                        break;
                    case GO_IRONCLAD_DOOR:
                        IronCladDoorGUID = go->GetGUID();
                        break;
                    case GO_DEFIAS_CANNON:
                        DefiasCannonGUID = go->GetGUID();
                        break;
                    case GO_DOOR_LEVER:
                        DoorLeverGUID = go->GetGUID();
                        break;
                }
            }

            void ShootCannon()
            {
                if (GameObject* pDefiasCannon = instance->GetGameObject(DefiasCannonGUID))
                {
                    pDefiasCannon->SetGoState(GO_STATE_ACTIVE);
                    pDefiasCannon->PlayDirectSound(SOUND_CANNONFIRE);
                }
            }

            void BlastOutDoor()
            {
                if (GameObject* pIronCladDoor = instance->GetGameObject(IronCladDoorGUID))
                {
                    pIronCladDoor->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                    pIronCladDoor->PlayDirectSound(SOUND_DESTROYDOOR);
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_CANNON_EVENT:
                        State = data;
                        if (data == CANNON_BLAST_INITIATED)
                        {
                            ShootCannon();
                            BlastOutDoor();
                        }    
                        break;
                    case DATA_VANESSA_EVENT:
                        uiVanessaEvent = data;
                        if (data == DONE)
                            SaveToDB();
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_VANESSA_EVENT)
                    return uiVanessaEvent;
                return 0;
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_GLUBTOK:
                        return uiGlubtokGUID;
                    case DATA_HELIX:
                        return uiHelixGUID;
                    case DATA_OAF:
                        return uiOafGUID;
                    case DATA_FOEREAPER:
                        return uiFoereaperGUID;
                    case DATA_ADMIRAL:
                        return uiAdmiralGUID;
                    case DATA_TEAM_IN_INSTANCE:     
                        return TeamInInstance;
                }
                return 0;
            }
            
            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;
                    
                switch (type)
                {
                    case DATA_HELIX:
                        if (state == IN_PROGRESS)
                        {
                            if (GameObject* go = instance->GetGameObject(HeavyDoorGUID))
                                go->SetFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        else if (state == DONE)
                            if (GameObject* go = instance->GetGameObject(HeavyDoorGUID))
                                go->RemoveFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case DATA_FOEREAPER:
                        if (state == IN_PROGRESS)
                        {
                            if (GameObject* go = instance->GetGameObject(HeavyDoor2GUID))
                                go->SetFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        else if (state == DONE)
                            if (GameObject* go = instance->GetGameObject(HeavyDoor2GUID))
                                go->RemoveFlag(GAMEOBJECT_FIELD_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                }

                return true;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::string str_data;
                std::ostringstream saveStream;
                saveStream << "D M " << GetBossSaveData() << State << " " << uiVanessaEvent << " ";
                str_data = saveStream.str();

                OUT_SAVE_INST_DATA_COMPLETE;
                return str_data;
            }

            void Load(const char* in) override
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(in);

                char dataHead1, dataHead2;

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'D' && dataHead2 == 'M')
                {

                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }

                    loadStream >> State;

                    if (State == CANNON_BLAST_INITIATED)
                        if (GameObject *pIronCladDoor = instance->GetGameObject(IronCladDoorGUID))
                            pIronCladDoor->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);

                    loadStream >> uiVanessaEvent;
                    if (uiVanessaEvent != DONE)
                        uiVanessaEvent = NOT_STARTED;

                }
                else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        private:
            uint64 uiGlubtokGUID;
            uint64 uiHelixGUID;
            uint64 uiOafGUID;
            uint64 uiFoereaperGUID;
            uint64 uiAdmiralGUID;
            uint64 uiCaptainGUID;

            uint64 FactoryDoorGUID;
            uint64 FoundryDoorGUID;
            uint64 MastRoomDoorGUID;
            uint64 GoblinTeleporterGUID;
            uint64 HeavyDoorGUID;
            uint64 HeavyDoor2GUID;
            uint64 IronCladDoorGUID;
            uint64 DefiasCannonGUID;
            uint64 DoorLeverGUID;
            uint64 DefiasPirate1GUID;
            uint64 DefiasPirate2GUID;
            uint64 DefiasCompanionGUID;

            uint32 State;
            uint32 uiVanessaEvent;
            uint32 OverchargeCount;

            uint32 TeamInInstance;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_deadmines_InstanceMapScript(map);
        }
};

void AddSC_instance_deadmines()
{
    new instance_deadmines();
}