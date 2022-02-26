
#include <map>
#include "Config.h"
#include "Chat.h"
#include "Log.h"
#include "ScriptMgr.h"
#include "Unit.h"
#include "Player.h"
#include "Pet.h"
#include "Map.h"
#include "Group.h"
#include "InstanceScript.h"

class solocraft : public PlayerScript
{
public:
    solocraft() : PlayerScript("solocraft") { }

private:
    const float D5 = sConfigMgr->GetFloatDefault("Solocraft.Dungeon", 5.0);
    const float D5H = sConfigMgr->GetFloatDefault("Solocraft.Heroic", 10.0);
    const float D5M = sConfigMgr->GetFloatDefault("Solocraft.Mythic", 15.0);
    const float D10 = sConfigMgr->GetFloatDefault("Solocraft.Raid10", 10.0);
    const float D25 = sConfigMgr->GetFloatDefault("Solocraft.Raid25", 25.0);
    const float D30 = sConfigMgr->GetFloatDefault("Solocraft.Raid30", 30.0);
    const float D40 = sConfigMgr->GetFloatDefault("Solocraft.Raid30", 40.0);
    float _unitDifficulty = 0;

    void OnMapChanged(Player* player) override
    {
        if (sConfigMgr->GetBoolDefault("Solocraft.Enable", false))
        {
            if (Map* map = player->GetMap())
            {
                if (map->IsDungeon() || map->IsRaid())
                {
                    float difficulty = CalculateDifficulty(map, player);
                    int groupSize = GetNumInGroup(player);
                    IncreaseStats(player, map, difficulty, groupSize);
                }
                else
                    DecreaseStats(player, map);
            }
        }
    }

    float CalculateDifficulty(Map* map, Player* player)
    {
        float difficulty = 1.0;
        if (map)
        {
            if (map->IsRaid())
            {
                switch (map->GetMapDifficulty()->maxPlayers)
                {
                case 10:
                    difficulty = D10;
                    break;
                case 25:
                    difficulty = D25;
                    break;
                case 30:
                    difficulty = D30;
                    break;
                case 40:
                    difficulty = D40;
                    break;
                default:
                    TC_LOG_WARN("server.worldserver", "[SoloCraft] Unrecognized max players %d, defaulting to 10 man difficulty",
                        map->GetMapDifficulty()->maxPlayers);
                    difficulty = D10;
                }
            }
            else if (map->IsDungeon())
            {
                if (map->IsHeroic())
                    difficulty = D5H;
                else
                    difficulty = D5;
            }
        }
        return difficulty - 1.0;
    }

    int GetNumInGroup(Player* player)
    {
        int groupSize = 1;
        if (InstanceScript* instance = player->GetInstanceScript())
        {
            Map::PlayerList const& playerList = instance->instance->GetPlayers();
            if (playerList.isEmpty())
                return groupSize = 0;
            else
                groupSize = playerList.getSize();
        }
        return groupSize;
    }

    void IncreaseStats(Player* player, Map* map, float difficulty, int numInGroup)
    {
        if (!player || !map)
            return;

        DecreaseStats(player, map);

        if (difficulty > 1)
        {
            std::ostringstream ss;
            ss << "|cffFF0000[SoloCraft] |cffFF8000" << player->GetName() << " entered %s - # of Players: %d - Difficulty Offset: %0.2f.";
            ChatHandler(player->GetSession()).PSendSysMessage(ss.str().c_str(), map->GetMapName(), numInGroup, difficulty + 1.0);

            _unitDifficulty = difficulty;
            for (int32 stats = STAT_STRENGTH; stats < MAX_STATS; ++stats)
            {
                player->HandleStatModifier(UnitMods(UNIT_MOD_STAT_START + stats), TOTAL_PCT, float(difficulty * 100.0), true);
            }

            player->SetFullHealth();
            if (player->GetPowerType() == POWER_MANA)
                player->SetMaxPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
        }
    }

    void DecreaseStats(Player* player, Map* map)
    {
        if (!player || !map)
            return;

        std::ostringstream ss;
        ss << "|cffFF0000[SoloCraft] |cffFF8000" << player->GetName() << " exited to %s - Reverting Difficulty Offset: %0.2f.";
        for (int32 stats = STAT_STRENGTH; stats < MAX_STATS; ++stats)
        {
            player->HandleStatModifier(UnitMods(UNIT_MOD_STAT_START + stats), TOTAL_PCT, float(_unitDifficulty * 100.0), false);
        }
    }
};

void AddSC_solocraft()
{
    new solocraft();
}