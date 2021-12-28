#ifndef RATED_PVP_H
#define RATED_PVP_H

#include "Common.h"

enum ArenaType : uint32;

struct RatedPvpInfo
{
    uint64 Guid = 0;
    uint32 Slot = 0;
    uint32 Rank = 0;
    uint32 Rating = 0;
    uint32 MatchmakerRating = 0;
    uint32 WeekBest = 0;
    uint32 WeekGames = 0;
    uint32 WeekWins = 0;
    uint32 SeasonBest = 0;
    uint32 SeasonGames = 0;
    uint32 SeasonWins = 0;
    uint32 LastWeekBest = 0;
    uint32 WinStreak = 0;
};

enum RatedPvpSlot
{
    PVP_SLOT_ARENA_2v2,
    PVP_SLOT_ARENA_3v3,
    PVP_SLOT_ARENA_5v5,
    PVP_SLOT_RATED_BG,
    PVP_SLOT_MAX,
};

class RatedPvpMgr
{
    RatedPvpMgr() { }
    ~RatedPvpMgr() { }

    typedef std::unordered_map<uint64, std::shared_ptr<RatedPvpInfo>> RatedPvpInfoMap;

public:
    static RatedPvpMgr* Instance()
    {
        static RatedPvpMgr _instance;
        return &_instance;
    }

    void LoadFromDB();

    RatedPvpInfo* GetOrCreateInfo(RatedPvpSlot slot, uint64 guid);

    RatedPvpInfo* GetInfo(RatedPvpSlot slot, uint64 guid) const
    {
        ASSERT(slot < PVP_SLOT_MAX);
        auto it = m_store[slot].find(guid);
        return it != m_store[slot].end() ? it->second.get() : nullptr;
    }

    void UpdateCap();
    void OnConfigLoad();

    void RecalcuateRank(RatedPvpSlot slot);

    static void SaveToDB(RatedPvpInfo const* info);
    static void SendBonusRewardIfNeed(RatedPvpInfo* info);

    void PrintSeasonResults(std::ostream& out);

private:
    struct PlayerRewards
    {
        std::set<CharTitlesEntry const*>  Titles;
        std::set<AchievementEntry const*> Achievs;
        std::vector<ItemTemplate const*>  Items;     // If player was awarded in more than one bracket - we send him all items
    };
    typedef std::map<uint32, PlayerRewards> RewardMap;

    struct BonusReward
    {
        uint32 GamesCount;
        uint32 ItemId;
        std::string MailTitle;
        std::string MailText;
    };

private:
    void LoadPvpInfoStore(uint32 season);
    void RecalcuateRank(RatedPvpInfoMap const& map);
    void GetSeasonPrizewinners(std::vector<RatedPvpInfo*>& two, std::vector<RatedPvpInfo*>& three, std::vector<RatedPvpInfo*>& five);
    bool RewardTeams(std::ostream& log, RewardMap& map, std::vector<RatedPvpInfo*> const& teams, ArenaType type, uint32 season);
    bool SendRewards(std::ostream& log, RewardMap& map, SQLTransaction& trans);
    void SeasonCleanup(SQLTransaction& trans);
    void CheckSeasonEnd();
    void RewardSeason();

private:
    RatedPvpInfoMap m_store[PVP_SLOT_MAX];
    std::vector<BonusReward> m_bonusRewards;
};

#define sRatedPvpMgr RatedPvpMgr::Instance()

#endif
