//UWoWCore
//Terrace of Endless Spring

#include "NewScriptPCH.h"
#include "VMapFactory.h"
#include "terrace_of_endless_spring.h"

class instance_terrace_of_endless_spring : public InstanceMapScript
{
public:
    instance_terrace_of_endless_spring() : InstanceMapScript("instance_terrace_of_endless_spring", 996) { }


    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_terrace_of_endless_spring_InstanceMapScript(map);
    }

    struct instance_terrace_of_endless_spring_InstanceMapScript : public InstanceScript
    {
        instance_terrace_of_endless_spring_InstanceMapScript(Map* map) : InstanceScript(map) {}

        //GameObjects
        std::vector<uint64> leishientdoorGuids;
        std::vector<uint64> leishiexdoorGuids;

        //Creature
        uint64 kaolanGuid;
        uint64 regailGuid;
        uint64 asaniGuid;
        uint64 tsulongGuid;
        uint64 leishiGuid;
        uint64 shaGuid;

        //special timer for load door state
        uint32 door_state_timer;
        
        void Initialize()
        {
            SetBossNumber(5);

            //GameObject
            leishientdoorGuids.clear();
            leishiexdoorGuids.clear();
           
            //Creature
            kaolanGuid    = 0;
            regailGuid    = 0;
            asaniGuid     = 0;
            tsulongGuid   = 0;
            leishiGuid    = 0;
            shaGuid       = 0;

            door_state_timer = 5000;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            { 
            case NPC_PROTECTOR_KAOLAN:
                kaolanGuid = creature->GetGUID();
                break;
            case NPC_ELDER_REGAIL:
                regailGuid = creature->GetGUID();
                break;
            case NPC_ELDER_ASANI:
                asaniGuid = creature->GetGUID();
                break;
            case NPC_TSULONG:
                tsulongGuid = creature->GetGUID();
                break;
            case NPC_LEI_SHI:
                leishiGuid = creature->GetGUID();
                break;
            case NPC_SHA_OF_FEAR:
                shaGuid = creature->GetGUID();
                break;
            }
        }

        void OnUnitDeath(Unit* who)
        {
            if (who->ToCreature())
            {
                if (who->GetEntry() == 62995) //Animated protector
                {
                    if (Creature* leishi = instance->GetCreature(leishiGuid))
                    {
                        if (leishi->IsAlive())
                            leishi->AI()->DoAction(ACTION_REMOVE_PROTECT);
                    }
                }
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
            case GO_LEI_SHI_ENT_DOOR:
                leishientdoorGuids.push_back(go->GetGUID());
                break;
            case GO_LEI_SHI_EX_DOOR:
                leishiexdoorGuids.push_back(go->GetGUID());
                break;
            } 
        }

        //SpecialLoadGOStateSystem (SLGSS)
        void Update(uint32 diff)
        {
            if (door_state_timer)
            {
                if (door_state_timer <= diff) 
                { //Call after initialize + special time(once)
                    door_state_timer = 0;
                    CheckBosses();
                }
                else
                    door_state_timer -= diff;
            }
        }

        void CheckBosses()
        {
            for (uint8 n = DATA_TSULONG; n <= DATA_LEI_SHI; n++)
            {
                if (Creature* boss = instance->GetCreature(GetData64(n)))
                {
                    if (!boss->IsAlive())
                        SetDoorState(n);
                }
            }
        }
        
        void SetDoorState(uint8 bossId)
        {
            switch (bossId)
            {
            case DATA_TSULONG:
                for (std::vector<uint64>::const_iterator guid = leishientdoorGuids.begin(); guid != leishientdoorGuids.end(); guid++)
                    HandleGameObject(*guid, true);
                break;
            case DATA_LEI_SHI:
                for (std::vector<uint64>::const_iterator guid = leishientdoorGuids.begin(); guid != leishientdoorGuids.end(); guid++)
                    HandleGameObject(*guid, true);
                
                for (std::vector<uint64>::const_iterator guid = leishiexdoorGuids.begin(); guid != leishiexdoorGuids.end(); guid++)
                    HandleGameObject(*guid, true);
                break;
            default:
                break;
            }
        }
        //

        bool SetBossState(uint32 id, EncounterState state)
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
            case DATA_TSULONG:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                    case IN_PROGRESS:
                        break;
                    case DONE:
                        for (std::vector<uint64>::const_iterator guid = leishientdoorGuids.begin(); guid != leishientdoorGuids.end(); guid++)
                            HandleGameObject(*guid, true);
                        break;
                    }
                    break;
                }
            case DATA_LEI_SHI:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                        for (std::vector<uint64>::const_iterator guid = leishientdoorGuids.begin(); guid != leishientdoorGuids.end(); guid++)
                            HandleGameObject(*guid, true);
                        break;
                    case IN_PROGRESS:
                        for (std::vector<uint64>::const_iterator guid = leishientdoorGuids.begin(); guid != leishientdoorGuids.end(); guid++)
                            HandleGameObject(*guid, false);
                        break;
                    case DONE:
                        for (std::vector<uint64>::const_iterator guid = leishientdoorGuids.begin(); guid != leishientdoorGuids.end(); guid++)
                            HandleGameObject(*guid, true);

                        for (std::vector<uint64>::const_iterator guid = leishiexdoorGuids.begin(); guid != leishiexdoorGuids.end(); guid++)
                            HandleGameObject(*guid, true);
                        break;
                    }
                    break;
                }
            case DATA_SHA_OF_FEAR:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                    case DONE:
                        for (std::vector<uint64>::const_iterator guid = leishiexdoorGuids.begin(); guid != leishiexdoorGuids.end(); guid++)
                            HandleGameObject(*guid, true);
                        break;
                    case IN_PROGRESS:
                        for (std::vector<uint64>::const_iterator guid = leishiexdoorGuids.begin(); guid != leishiexdoorGuids.end(); guid++)
                            HandleGameObject(*guid, false);
                        break;
                    }
                }
            }
            return true;
        }

        void SetData(uint32 type, uint32 data){}

        uint32 GetData(uint32 type)
        {
            return 0;
        }

        uint64 GetData64(uint32 type)
        {
            switch (type)
            {
            //Protectors
            case NPC_PROTECTOR_KAOLAN:
                return kaolanGuid;
            case NPC_ELDER_REGAIL:
                return regailGuid;
            case NPC_ELDER_ASANI:
                return asaniGuid;
            //
            case NPC_TSULONG:
            case DATA_TSULONG:
                return tsulongGuid;
            case NPC_LEI_SHI:
            case DATA_LEI_SHI:
                return leishiGuid;
            case NPC_SHA_OF_FEAR:
                return shaGuid;
            }
            return 0;
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

void AddSC_instance_terrace_of_endless_spring()
{
    new instance_terrace_of_endless_spring();
}
