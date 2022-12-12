//UWoWCore
//Heart of Fear

#include "NewScriptPCH.h"
#include "VMapFactory.h"
#include "heart_of_fear.h"

const DoorData doorData[] =
{
    {GO_VIZIER_EX_DOOR,   DATA_VIZIER_ZORLOK, DOOR_TYPE_PASSAGE, 0},
    {GO_TAYAK_EX_DOOR,    DATA_LORD_TAYAK,    DOOR_TYPE_PASSAGE, 0},
    {GO_GARALON_ENT_DOOR, DATA_LORD_TAYAK,    DOOR_TYPE_PASSAGE, 0},
    {GO_GARALON_EX_DOOR,  DATA_GARALON,       DOOR_TYPE_PASSAGE, 0},
    {GO_MELJARAK_EX_DOOR, DATA_MELJARAK,      DOOR_TYPE_PASSAGE, 0},
    {GO_UNSOK_EN_DOOR,    DATA_MELJARAK,      DOOR_TYPE_PASSAGE, 0},
    {GO_UNSOK_EX_DOOR,    DATA_UNSOK,         DOOR_TYPE_PASSAGE, 0},
    {0,                   0,                  DOOR_TYPE_PASSAGE, 0}
};

class instance_heart_of_fear : public InstanceMapScript
{
public:
    instance_heart_of_fear() : InstanceMapScript("instance_heart_of_fear", 1009) { }


    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_heart_of_fear_InstanceMapScript(map);
    }

    struct instance_heart_of_fear_InstanceMapScript : public InstanceScript
    {
        instance_heart_of_fear_InstanceMapScript(Map* map) : InstanceScript(map) {}

        //GameObjects
        uint64 vizierentdoorGuid;
        uint64 vizierexdoorGuid;
        uint64 tayakexdoorGuid;
        uint64 garalonentdoorGuid;
        uint64 meljarakexdoorGuid;
        uint64 unsokendoorGuid;
        uint64 unsokexdoorGuid;
        uint64 empresscocoonGuid;

        std::vector<uint64> vizierarenadoorGuids;
        std::vector<uint64> garaloncdoorGuids;
        std::vector<uint64> garalonexdoorGuids;
        std::vector<uint64> meljarakWeaponRackGUID;

        //Creature
        uint64 zorlokGuid;
        uint64 gascontrollerGuid;
        uint64 tayakGuid;
        uint64 garalonGuid;
        uint64 meljarakGuid;
        uint64 unsokGuid;
        uint64 ambermonsterGuid;
        uint64 shekzeerGuid;

        uint64 srathik[3];
        uint64 zarthik[3];
        uint64 korthik[3];
        std::vector<uint64> meljaraksoldiersGuids;
        
        //other
        uint8 stormUnleashed;
        
        void Initialize()
        {
            SetBossNumber(7);
            LoadDoorData(doorData);

            //GameObject
            vizierentdoorGuid       = 0;
            vizierexdoorGuid        = 0;
            tayakexdoorGuid         = 0;
            garalonentdoorGuid      = 0;
            meljarakexdoorGuid      = 0;
            unsokendoorGuid         = 0;
            unsokexdoorGuid         = 0;
            empresscocoonGuid       = 0;

            vizierarenadoorGuids.clear();
            garaloncdoorGuids.clear();
            garalonexdoorGuids.clear();
            meljarakWeaponRackGUID.clear();

            //Creature
            zorlokGuid              = 0;
            gascontrollerGuid       = 0;
            tayakGuid               = 0;
            garalonGuid             = 0;
            meljarakGuid            = 0;
            unsokGuid               = 0;
            ambermonsterGuid        = 0;
            shekzeerGuid            = 0;

            for (uint8 n = 0; n < 3; n++)
            {
                srathik[n] = 0;
                zarthik[n] = 0;
                korthik[n] = 0;
            }
            //Other
            stormUnleashed = 0;
        }

        void OnPlayerLeave(Player* player)
        {
            DoRemoveAurasDueToSpellOnPlayers(126159);
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            { 
            case NPC_VIZIER_ZORLOK:
                zorlokGuid = creature->GetGUID();
                break;
            case NPC_GAS_CONTROLLER:
                gascontrollerGuid = creature->GetGUID();
                break;
            case NPC_LORD_TAYAK:
                tayakGuid = creature->GetGUID();
                break;
            case NPC_GARALON:
                garalonGuid = creature->GetGUID();
                break;
            case NPC_MELJARAK:
                meljarakGuid = creature->GetGUID();
                break;
            case NPC_SRATHIK:
                for (uint8 n = 0; n < 3; n++)
                {
                    if (srathik[n] == 0)
                    {
                        srathik[n] = creature->GetGUID();
                        meljaraksoldiersGuids.push_back(srathik[n]);
                        break;
                    }
                }
                break;
            case NPC_ZARTHIK:
                for (uint8 n = 0; n < 3; n++)
                {
                    if (zarthik[n] == 0)
                    {
                        zarthik[n] = creature->GetGUID();
                        meljaraksoldiersGuids.push_back(zarthik[n]);
                        break;
                    }
                }
                break;
            case NPC_KORTHIK:
                for (uint8 n = 0; n < 3; n++)
                {
                    if (korthik[n] == 0)
                    {
                        korthik[n] = creature->GetGUID();
                        meljaraksoldiersGuids.push_back(korthik[n]);
                        break;
                    }
                }
                break;
            case NPC_UNSOK:
                unsokGuid = creature->GetGUID();
                break;
            case NPC_AMBER_MONSTER:
                ambermonsterGuid = creature->GetGUID();
                break;
            case NPC_SHEKZEER:
                shekzeerGuid = creature->GetGUID();
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
            case GO_VIZIER_ENT_DOOR:
                vizierentdoorGuid = go->GetGUID();
                break;
            case GO_VIZIER_ARENA_DOOR:
                vizierarenadoorGuids.push_back(go->GetGUID());
                break;
            case GO_VIZIER_EX_DOOR:
                AddDoor(go, true);
                vizierexdoorGuid = go->GetGUID();
                break;
            case GO_TAYAK_EX_DOOR:
                AddDoor(go, true);
                tayakexdoorGuid = go->GetGUID();
                break;
            case GO_GARALON_ENT_DOOR:
                AddDoor(go, true);
                garalonentdoorGuid = go->GetGUID();
                break;
            case GO_GARALON_COMBAT_DOOR:
                garaloncdoorGuids.push_back(go->GetGUID());
                break;
            case GO_GARALON_EX_DOOR:
                AddDoor(go, true);
                garalonexdoorGuids.push_back(go->GetGUID());
                break;
            case GO_MELJARAK_EX_DOOR:
                AddDoor(go, true);
                meljarakexdoorGuid = go->GetGUID();
                break;
            case GO_MELJARAK_WEAPON_RACK:
                meljarakWeaponRackGUID.push_back(go->GetGUID());
                break;
            case GO_UNSOK_EN_DOOR:
                AddDoor(go, true);
                unsokendoorGuid = go->GetGUID();
                break;
            case GO_UNSOK_EX_DOOR:
                AddDoor(go, true);
                unsokexdoorGuid = go->GetGUID();
                break;
            case GO_EMPRESS_COCOON:
                empresscocoonGuid = go->GetGUID();
                break;
            }
        }

        bool SetBossState(uint32 id, EncounterState state)
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;
            
            switch (id)
            {
            case DATA_VIZIER_ZORLOK:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        HandleGameObject(vizierentdoorGuid, true);
                        for (std::vector<uint64>::const_iterator guid = vizierarenadoorGuids.begin(); guid != vizierarenadoorGuids.end(); guid++)
                            HandleGameObject(*guid, true);
                        break;
                    case DONE:
                        HandleGameObject(vizierentdoorGuid, true);
                        HandleGameObject(vizierexdoorGuid, true); 
                        for (std::vector<uint64>::const_iterator guid = vizierarenadoorGuids.begin(); guid != vizierarenadoorGuids.end(); guid++)
                            HandleGameObject(*guid, true);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(vizierentdoorGuid, false);
                        for (std::vector<uint64>::const_iterator guid = vizierarenadoorGuids.begin(); guid != vizierarenadoorGuids.end(); guid++)
                            HandleGameObject(*guid, false);
                        break;
                    }
                    break;
                }
            case DATA_LORD_TAYAK:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        HandleGameObject(vizierexdoorGuid, true);
                        break;
                    case DONE:
                        HandleGameObject(vizierexdoorGuid, true);
                        HandleGameObject(tayakexdoorGuid, true);
                        HandleGameObject(garalonentdoorGuid, true);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(vizierexdoorGuid, false);
                        break;
                    }
                    break;
                }
            case DATA_GARALON:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        for (std::vector<uint64>::const_iterator guid = garaloncdoorGuids.begin(); guid != garaloncdoorGuids.end(); guid++)
                            HandleGameObject(*guid, true);
                        break;
                    case DONE:
                        for (std::vector<uint64>::const_iterator guid = garaloncdoorGuids.begin(); guid != garaloncdoorGuids.end(); guid++)
                            HandleGameObject(*guid, true);
                        
                        for (std::vector<uint64>::const_iterator guids = garalonexdoorGuids.begin(); guids != garalonexdoorGuids.end(); guids++)
                            HandleGameObject(*guids, true);
                        break;
                    case IN_PROGRESS:
                        for (std::vector<uint64>::const_iterator guid = garaloncdoorGuids.begin(); guid != garaloncdoorGuids.end(); guid++)
                            HandleGameObject(*guid, false);
                        break;
                    }
                    break;
                }
            case DATA_MELJARAK:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        for (std::vector<uint64>::const_iterator guids = garalonexdoorGuids.begin(); guids != garalonexdoorGuids.end(); guids++)
                            HandleGameObject(*guids, true);
                        for (std::vector<uint64>::const_iterator itr = meljarakWeaponRackGUID.begin(); itr != meljarakWeaponRackGUID.end(); itr++)
                            if (GameObject* obj = instance->GetGameObject(*itr))
                                obj->Respawn();
                        DoRemoveAurasDueToSpellOnPlayers(122220);
                        break;
                    case IN_PROGRESS:
                        for (std::vector<uint64>::const_iterator guids = garalonexdoorGuids.begin(); guids != garalonexdoorGuids.end(); guids++)
                            HandleGameObject(*guids, false);

                        for (std::vector<uint64>::const_iterator guid = meljaraksoldiersGuids.begin(); guid != meljaraksoldiersGuids.end(); guid++)
                        {
                            if (Creature* soldier = instance->GetCreature(*guid))
                            {
                                if (soldier->IsAlive() && !soldier->isInCombat())
                                    soldier->AI()->DoZoneInCombat(soldier, 100.0f);
                            }
                        }
                        break;
                    case DONE:
                        DoRemoveAurasDueToSpellOnPlayers(122220);
                        HandleGameObject(meljarakexdoorGuid, true);
                        HandleGameObject(unsokendoorGuid, true);
                        for (std::vector<uint64>::const_iterator guids = garalonexdoorGuids.begin(); guids != garalonexdoorGuids.end(); guids++)
                            HandleGameObject(*guids, true);
                        break;
                    }
                    break;
                }
            case DATA_UNSOK:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        DoRemoveAurasDueToSpellOnPlayers(122370);
                        DoRemoveAurasDueToSpellOnPlayers(122516);
                        HandleGameObject(unsokendoorGuid, true);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(unsokendoorGuid, false);
                        break;
                    case DONE:
                        DoRemoveAurasDueToSpellOnPlayers(122370);
                        DoRemoveAurasDueToSpellOnPlayers(122516);
                        HandleGameObject(unsokendoorGuid, true);
                        HandleGameObject(unsokexdoorGuid, true);
                        break;
                    }
                    break;
                }
            case DATA_SHEKZEER:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                    case DONE:
                        HandleGameObject(unsokexdoorGuid, true);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(unsokexdoorGuid, false);
                        break;
                    }
                    break;
                }
            }
            return true;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case DATA_STORM_UNLEASHED:
                    stormUnleashed = data;
                    if (data == NOT_STARTED)
                        DoRemoveAurasDueToSpellOnPlayers(126159);
                    break;
            }
        }

        uint32 GetData(uint32 type)
        {
            switch (type)
            {
                case DATA_STORM_UNLEASHED:
                    return stormUnleashed;
            }
            return 0;
        }

        uint64 GetData64(uint32 type)
        {
            switch (type)
            {
                case NPC_VIZIER_ZORLOK:
                    return zorlokGuid;
                case NPC_GAS_CONTROLLER:
                    return gascontrollerGuid;
                case NPC_LORD_TAYAK:
                    return tayakGuid;
                case NPC_GARALON:
                    return garalonGuid;
                case NPC_MELJARAK:
                    return meljarakGuid;
                //Meljarak Soldiers
                case NPC_SRATHIK_1:
                    return srathik[0];
                case NPC_SRATHIK_2:
                    return srathik[1];
                case NPC_SRATHIK_3:
                    return srathik[2];
                case NPC_ZARTHIK_1:
                    return zarthik[0];
                case NPC_ZARTHIK_2:
                    return zarthik[1];
                case NPC_ZARTHIK_3:
                    return zarthik[2];
                case NPC_KORTHIK_1:
                    return korthik[0];
                case NPC_KORTHIK_2:
                    return korthik[1];
                case NPC_KORTHIK_3:
                    return korthik[2];
                //
                case NPC_UNSOK:
                    return unsokGuid;
                case NPC_SHEKZEER:
                    return shekzeerGuid;
                case GO_EMPRESS_COCOON:
                    return empresscocoonGuid;
            }
            return 0;
        }

        void CreatureDies(Creature* cre, Unit* /*killer*/)
        {
            switch (cre->GetEntry())
            {
                case NPC_SRATHIK:
                    for (uint8 n = 0; n < 3; n++)
                        if (srathik[n] == cre->GetGUID())
                            srathik[n] = 0;
                    break;
                case NPC_ZARTHIK:
                    for (uint8 n = 0; n < 3; n++)
                        if (zarthik[n] == cre->GetGUID())
                            zarthik[n] = 0;
                    break;
                case NPC_KORTHIK:
                    for (uint8 n = 0; n < 3; n++)
                        if (korthik[n] == cre->GetGUID())
                            korthik[n] = 0;
                    break;
            }
        }

        void OnCreatureRemove(Creature* cre)
        {
            switch (cre->GetEntry())
            {
                case NPC_SRATHIK:
                    for (uint8 n = 0; n < 3; n++)
                        if (srathik[n] == cre->GetGUID())
                            srathik[n] = 0;
                    break;
                case NPC_ZARTHIK:
                    for (uint8 n = 0; n < 3; n++)
                        if (zarthik[n] == cre->GetGUID())
                            zarthik[n] = 0;
                    break;
                case NPC_KORTHIK:
                    for (uint8 n = 0; n < 3; n++)
                        if (korthik[n] == cre->GetGUID())
                            korthik[n] = 0;
                    break;
            }
        }

        bool IsWipe()
        {
            Map::PlayerList const& PlayerList = instance->GetPlayers();

            if (PlayerList.isEmpty())
                return true;

            for (Map::PlayerList::const_iterator Itr = PlayerList.begin(); Itr != PlayerList.end(); ++Itr)
            {
                Player* player = Itr->getSource();

                if (!player)
                    continue;

                if (player->IsAlive() && !player->isGameMaster() && !player->HasAura(115877)) // Aura 115877 = Totaly Petrified
                    return false;
            }

            return true;
        }

        std::string GetSaveData()
        {
            std::ostringstream saveStream;
            saveStream << GetBossSaveData() << " ";
            return saveStream.str();
        }

        void Load(const char* data)
        {
            std::istringstream loadStream(LoadBossState(data));
            uint32 buff;
            for (uint32 i = 0; i < 7; ++i)
                loadStream >> buff;
        }
    };
};

void AddSC_instance_heart_of_fear()
{
    new instance_heart_of_fear();
}
