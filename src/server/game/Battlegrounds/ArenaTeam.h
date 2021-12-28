#ifndef ARENATEAM_H
#define ARENATEAM_H

#include "Common.h"
#include "RatedPvp.h"

class Player;
class Group;
struct GroupQueueInfo;
struct SoloGroup;

enum ArenaTeamTypes
{
    ARENA_TEAM_2v2      = 2,
    ARENA_TEAM_3v3      = 3,
    ARENA_TEAM_5v5      = 5,
};

class ArenaTeam
{
public:
    ArenaTeam(RatedPvpSlot slot, Group* group);
    ArenaTeam(GroupQueueInfo* group);
    ArenaTeam(SoloGroup* group);

    uint32 GetRating() const { return m_rating; }
    uint32 GetMatchmakerRating() const { return m_matchmakerRating; }

    RatedPvpInfo* GetMember(uint64 guid) const;

    static uint8 GetSlotByType(uint32 type);
    static uint8 GetTypeBySlot(uint8 slot);

    RatedPvpSlot GetSlot() const { return m_slot; }

    static int32 GetMatchmakerRatingMod(uint32 ownRating, uint32 opponentRating, bool won);
    static int32 GetRatingMod(uint32 ownRating, uint32 opponentRating, bool won);
    static float GetChanceAgainst(uint32 ownRating, uint32 opponentRating);

    int32 WonAgainst(uint32 ownMMRating, uint32 opponentMMRating, int32& rating_change);
    int32 LostAgainst(uint32 ownMMRating, uint32 opponentMMRating, int32& rating_change);

    void MemberWon(Player* player, uint32 againstMatchmakerRating, int32 matchmakerRatingChange = 16);
    void MemberLost(uint64 guid, uint32 againstMatchmakerRating, int32 matchmakerRatingChange = -16, bool gamePlayed = true);
    void MemberLost(Player* player, uint32 againstMatchmakerRating, int32 matchmakerRatingChange = -16);

    int32 GetRatingChanges(uint64 guid) const
    {
        auto itr = m_ratingChanges.find(guid);
        return itr != m_ratingChanges.end() ? itr->second : 0;
    }

    typedef std::vector<RatedPvpInfo*>::const_iterator iterator;

    iterator begin() const { return m_members.begin(); }
    iterator end() const { return m_members.end(); }

    bool IsPlayerHandled(uint64 guid) const { return m_handledPlayers.find(guid) != m_handledPlayers.end(); }
    void SetPlayerHandled(uint64 guid) { m_handledPlayers.insert(guid); }

    void WinSolo(uint64 guid, int32 against);
    void LoseSolo(uint64 guid, int32 against);
    void FinishSolo(uint64 guid, int32 ratingChange, int32 mmrChange, bool win);

private:
    std::vector<RatedPvpInfo*> m_members;
    uint32 m_rating = 0;
    uint32 m_matchmakerRating = 0;
    RatedPvpSlot m_slot = PVP_SLOT_MAX;
    std::map<uint64, int32> m_ratingChanges;
    std::set<uint64> m_handledPlayers;
};

#endif
