/*
 * Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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

#ifndef SF_LFGMGR_H
#define SF_LFGMGR_H

#include <ace/Singleton.h>
#include "DBCStructure.h"
#include "Field.h"
#include "LFG.h"
#include "LFGQueue.h"
#include "LFGGroupData.h"
#include "LFGPlayerData.h"
#include "BattlegroundQueue.h"
#include <numeric>

class Group;
class Player;
class Quest;

namespace lfg
{
struct QueueAnnounceContextLFG
{
    using Show = QueueAnnounceContext::Show;

    uint32 DungeonId;
    LfgRolesMap const& Queuers;

    static bool IsEnabled();
    void Announce() const;
};

enum LfgOptions
{
    LFG_OPTION_ENABLE_DUNGEON_FINDER             = 0x01,
    LFG_OPTION_ENABLE_RAID_BROWSER               = 0x02,
};

enum LFGMgrEnum
{
    LFG_TIME_ROLECHECK                           = 40,
    LFG_TIME_BOOT                                = 120,
    LFG_TIME_PROPOSAL                            = 40,
    LFG_QUEUEUPDATE_INTERVAL                     = 15 * IN_MILLISECONDS,
    LFG_SPELL_DUNGEON_COOLDOWN                   = 71328,
    LFG_SPELL_DUNGEON_DESERTER                   = 71041,
    LFG_SPELL_LUCK_OF_THE_DRAW                   = 72221,
    LFG_GROUP_KICK_VOTES_NEEDED                  = 3,
    LFG_RAID_KICK_VOTES_NEEDED                   = 15
};

enum LfgFlags
{
    LFG_FLAG_UNK1                                = 0x1,
    LFG_FLAG_UNK2                                = 0x2,
    LFG_FLAG_SEASONAL                            = 0x4,
    LFG_FLAG_UNK3                                = 0x8
};

/// Determines the type of instance
enum LfgType
{
    LFG_TYPE_NONE                                = 0,
    LFG_TYPE_DUNGEON                             = 1,
    LFG_TYPE_RAID                                = 2,
    LFG_TYPE_HEROIC                              = 5,
    LFG_TYPE_RANDOM                              = 6
};

/// Proposal states
enum LfgProposalState
{
    LFG_PROPOSAL_INITIATING                      = 0,
    LFG_PROPOSAL_FAILED                          = 1,
    LFG_PROPOSAL_SUCCESS                         = 2
};

/// Teleport errors
enum LfgTeleportError
{
    // 7 = "You can't do that right now" | 5 = No client reaction
    LFG_TELEPORTERROR_OK                         = 0,      // Internal use
    LFG_TELEPORTERROR_PLAYER_DEAD                = 1,
    LFG_TELEPORTERROR_FALLING                    = 2,
    LFG_TELEPORTERROR_IN_VEHICLE                 = 3,
    LFG_TELEPORTERROR_FATIGUE                    = 4,
    LFG_TELEPORTERROR_INVALID_LOCATION           = 6,
    LFG_TELEPORTERROR_CHARMING                   = 8       // FIXME - It can be 7 or 8 (Need proper data)
};

/// Queue join results
enum LfgJoinResult
{
    LFG_JOIN_OK                                  = 0,    // Joined (no client msg)
    LFG_JOIN_FAILED                              = 28,   // RoleCheck Failed
    LFG_JOIN_GROUPFULL                           = 29,   // Your group is full
    LFG_JOIN_INTERNAL_ERROR                      = 31,   // Internal LFG Error
    LFG_JOIN_NOT_MEET_REQS                       = 32,   // You do not meet the requirements for the chosen dungeons
    LFG_JOIN_MIXED_RAID_DUNGEON                  = 33,   // You cannot mix dungeons, raids, and random when picking dungeons
    LFG_JOIN_MULTI_REALM                         = 34,   // The dungeon you chose does not support players from multiple realms
    LFG_JOIN_DISCONNECTED                        = 35,   // One or more party members are pending invites or disconnected
    LFG_JOIN_PARTY_INFO_FAILED                   = 36,   // Could not retrieve information about some party members
    LFG_JOIN_DUNGEON_INVALID                     = 37,   // One or more dungeons was not valid
    LFG_JOIN_DESERTER                            = 38,   // You can not queue for dungeons until your deserter debuff wears off
    LFG_JOIN_PARTY_DESERTER                      = 39,   // One or more party members has a deserter debuff
    LFG_JOIN_RANDOM_COOLDOWN                     = 40,   // You can not queue for random dungeons while on random dungeon cooldown
    LFG_JOIN_PARTY_RANDOM_COOLDOWN               = 41,   // One or more party members are on random dungeon cooldown
    LFG_JOIN_TOO_MUCH_MEMBERS                    = 42,   // You can not enter dungeons with more that 5 party members
    LFG_JOIN_USING_BG_SYSTEM                     = 43,   // You can not use the dungeon system while in BG or arenas
    LFG_JOIN_ROLE_CHECK_FAILED                   = 44,   // Role check failed, client shows special error
    LFG_JOIN_NOT_ENOUGH_GROUP_MEMEBERS           = 50,   // You do not have enough group members to queue for that
    LFG_JOIN_TOO_MANY_QUEUES                     = 51,   // You are queued for too many instances
    LFG_JOIN_MIX_REALM_ONLY_AND_X_REALM          = 53,   // You cannot mix realm-only and x-realm entries then listing your name in other raids
};

/// Role check states
enum LfgRoleCheckState
{
    LFG_ROLECHECK_DEFAULT                        = 0,      // Internal use = Not initialized.
    LFG_ROLECHECK_FINISHED                       = 1,      // Role check finished
    LFG_ROLECHECK_INITIALITING                   = 2,      // Role check begins
    LFG_ROLECHECK_MISSING_ROLE                   = 3,      // Someone didn't selected a role after 2 mins
    LFG_ROLECHECK_WRONG_ROLES                    = 4,      // Can't form a group with that role selection
    LFG_ROLECHECK_ABORTED                        = 5,      // Someone leave the group
    LFG_ROLECHECK_NO_ROLE                        = 6       // Someone selected no role
};

// Forward declaration (just to have all typedef together)
struct LFGDungeonData;
struct LfgReward;
struct LfgQueueInfo;
struct LfgRoleCheck;
struct LfgProposal;
struct LfgProposalPlayer;
struct LfgPlayerBoot;
class QueueTests;

typedef std::map<uint8, QueueManager> LfgQueueManagerContainer;
typedef std::multimap<uint32, LfgReward const*> LfgRewardContainer;
typedef std::pair<LfgRewardContainer::const_iterator, LfgRewardContainer::const_iterator> LfgRewardContainerBounds;
typedef std::map<uint8, LfgDungeonSet> LfgCachedDungeonContainer;
typedef std::map<uint64, LfgAnswer> LfgAnswerContainer;
typedef std::map<uint64, LfgRoleCheck> LfgRoleCheckContainer;
typedef std::map<uint32, LfgProposal> LfgProposalContainer;
typedef std::map<uint64, LfgProposalPlayer> LfgProposalPlayerContainer;
typedef std::map<uint64, LfgPlayerBoot> LfgPlayerBootContainer;
typedef std::map<uint64, LfgGroupData> LfgGroupDataContainer;
typedef std::map<uint64, LfgPlayerData> LfgPlayerDataContainer;
typedef std::unordered_map<uint32, LFGDungeonData> LFGDungeonContainer;

// Data needed by SMSG_LFG_JOIN_RESULT
struct LfgJoinResultData
{
    LfgJoinResultData(LfgJoinResult _result = LFG_JOIN_OK, LfgRoleCheckState _state = LFG_ROLECHECK_DEFAULT):
        result(_result), state(_state) { }
    LfgJoinResult result;
    LfgRoleCheckState state;
    LfgLockPartyMap lockmap;
};

// Data needed by SMSG_LFG_QUEUE_STATUS
struct LfgQueueStatusData
{
    LfgQueueStatusData(uint32 queueId = 0, uint32 dungeonId = 0, time_t joinTime = 0, int32 waitTime = -1, int32 waitTimeAvg = -1, int32 waitTimeTank = -1, int32 waitTimeHealer = -1,
        int32 waitTimeDps = -1, uint32 queuedTime = 0, uint8 tanks = 0, uint8 healers = 0, uint8 dps = 0) :
        queueId(queueId), dungeonId(dungeonId), joinTime(joinTime), waitTime(waitTime), waitTimeAvg(waitTimeAvg), waitTimeTank(waitTimeTank),
        waitTimeHealer(waitTimeHealer), waitTimeDps(waitTimeDps), queuedTime(queuedTime), tanks(tanks), healers(healers), dps(dps) { }

    uint32 queueId;
    uint32 dungeonId;
    time_t joinTime;
    int32 waitTime;
    int32 waitTimeAvg;
    int32 waitTimeTank;
    int32 waitTimeHealer;
    int32 waitTimeDps;
    uint32 queuedTime;
    uint8 tanks;
    uint8 healers;
    uint8 dps;
};

struct LfgPlayerRewardData
{
    LfgPlayerRewardData(uint32 random, uint32 current, bool _done, Quest const* _quest, Quest const* _ctaQuest):
        rdungeonEntry(random), sdungeonEntry(current), done(_done), quest(_quest), ctaQuest(_ctaQuest) { }
    uint32 rdungeonEntry;
    uint32 sdungeonEntry;
    bool done;
    Quest const* quest;
    Quest const* ctaQuest;
};

/// Reward info
struct LfgReward
{
    LfgReward(uint32 _maxLevel = 0, uint32 _firstQuest = 0, uint32 _otherQuest = 0):
        maxLevel(_maxLevel), firstQuest(_firstQuest), otherQuest(_otherQuest) { }

    uint32 maxLevel;
    uint32 firstQuest;
    uint32 otherQuest;
};

/// Stores player data related to proposal to join
struct LfgProposalPlayer
{
    LfgProposalPlayer(): role(0), accept(LFG_ANSWER_PENDING), group(0) { }
    uint32 queueId = 0;
    uint8 role;                                            ///< Proposed role
    LfgAnswer accept;                                      ///< Accept status (-1 not answer | 0 Not agree | 1 agree)
    uint64 group;                                          ///< Original group guid. 0 if no original group
};

/// Stores group data related to proposal to join
struct LfgProposal
{
    LfgProposal(bool raid = false, uint32 dungeon = 0): id(0), raid(raid), dungeonId(dungeon), state(LFG_PROPOSAL_INITIATING),
        group(0), leader(0), cancelTime(0), encounters(0), isNew(true)
        { }

    uint32 id;                                             ///< Proposal Id
    bool raid;
    uint32 dungeonId;                                      ///< Dungeon to join
    LfgProposalState state;                                ///< State of the proposal
    uint64 group;                                          ///< Proposal group (0 if new)
    uint64 leader;                                         ///< Leader guid.
    time_t cancelTime;                                     ///< Time when we will cancel this proposal
    uint32 encounters;                                     ///< Dungeon Encounters
    bool isNew;                                            ///< Determines if it's new group or not
    std::list<Queuer> queuers;                             ///< Queue Ids to remove/readd
    LfgGuidList showorder;                                 ///< Show order in update window
    LfgProposalPlayerContainer players;                    ///< Players data
    uint32 weight = 0;
};

/// Stores all rolecheck info of a group that wants to join
struct LfgRoleCheck
{
    time_t cancelTime;                                     ///< Time when the rolecheck will fail
    LfgRolesMap roles;                                     ///< Player selected roles
    LfgRoleCheckState state;                               ///< State of the rolecheck
    bool raid;                                             ///< Whether the queue is for a raid dungeon
    LfgDungeonSet dungeons;                                ///< Dungeons group is applying for (expanded random dungeons)
    uint32 rDungeonId;                                     ///< Random Dungeon Id.
    uint64 leader;                                         ///< Leader of the group
    uint8 neededTanks, neededHealers, neededDamage;
    bool isContinue;
};

/// Stores information of a current vote to kick someone from a group
struct LfgPlayerBoot
{
    time_t cancelTime;                                     ///< Time left to vote
    bool inProgress;                                       ///< Vote in progress
    LfgAnswerContainer votes;                              ///< Player votes (-1 not answer | 0 Not agree | 1 agree)
    uint64 victim;                                         ///< Player guid to be kicked (can't vote)
    std::string reason;                                    ///< kick reason
};

struct LFGDungeonData
{
    LFGDungeonData(): id(0), name(""), map(0), type(0), expansion(0), group(0), minlevel(0),
        maxlevel(0), difficulty(REGULAR_DIFFICULTY), seasonal(false), x(0.0f), y(0.0f), z(0.0f), o(0.0f),
        requiredItemLevel(0), tanksNeeded(0), healersNeeded(0), dpsNeeded(0), faction(0)
        { }
    LFGDungeonData(LFGDungeonEntry const* dbc): id(dbc->ID), name(dbc->name[DEFAULT_LOCALE]), map(dbc->map),
        type(dbc->type), expansion(dbc->expansion), group(dbc->grouptype),
        minlevel(dbc->minlevel), maxlevel(dbc->maxlevel), difficulty(Difficulty(dbc->difficulty)),
        seasonal(dbc->flags & LFG_FLAG_SEASONAL), x(0.0f), y(0.0f), z(0.0f), o(0.0f),
        requiredItemLevel(0), tanksNeeded(dbc->tankNeeded), healersNeeded(dbc->healerNeeded), dpsNeeded(dbc->dpsNeeded),
        faction(dbc->faction), category(LfgCategory(dbc->category))
        { }

    uint32 id;
    std::string name;
    uint16 map;
    uint8 type;
    uint8 expansion;
    uint8 group;
    uint8 minlevel;
    uint8 maxlevel;
    Difficulty difficulty;
    LfgCategory category = LFG_CATEGORY_NONE;
    bool seasonal;
    float x, y, z, o;
    uint16 requiredItemLevel;
    uint8 tanksNeeded, healersNeeded, dpsNeeded;
    int8 faction;

    // Helpers
    uint32 Entry() const { return id + (type << 24); }
};

class LFGMgr
{
    private:
        LFGMgr();
        ~LFGMgr();

    public:
        static LFGMgr* instance()
        {
            static LFGMgr _instance;
            return &_instance;
        }
        // Functions used outside lfg namespace
        void Update(uint32 diff);

        // World.cpp
        /// Finish the dungeon for the given group. All check are performed using internal lfg data
        void FinishDungeon(uint64 gguid, uint32 dungeonId, Map* map);
        /// Loads rewards for random dungeons
        void LoadRewards();
        /// Loads dungeons from dbc and adds teleport coords
        void LoadLFGDungeons(bool reload = false);

        // Multiple files
        /// Check if given guid applied for random dungeon
        bool IsSelectedRandomLfgDungeon(uint64 guid);
        /// Check if given guid applied for given map and difficulty. Used to know
        bool InLfgDungeonMap(uint64 guid, uint32 map, Difficulty difficulty);
        // Inital creation of queue data for player
        void AddQueue(uint64 guid, uint32 queueId, uint64 originalGroup = 0);
        // Removes queue data for specified player/group
        // If group has no more queues - group data will be removed
        void RemoveQueue(uint64 guid, uint32 queueId);
        // Queue id for dungeon that currently is in progress
        uint32 GetActiveQueueId(uint64 guid) const;
        // State for active queue
        LfgState GetActiveState(uint64 gguid) const;
        /// Get selected dungeons
        LfgDungeonSet const& GetSelectedDungeons(uint64 guid, uint32 queueId);
        /// Get current lfg state
        LfgState GetState(uint64 guid, uint32 queueId) const;
        /// Get current dungeon
        uint32 GetDungeon(uint64 guid, bool asId = true);
        /// Get the map id of the current dungeon
        uint32 GetDungeonMapId(uint64 guid);
        /// Get kicks left in current group
        uint8 GetKicksLeft(uint64 gguid);
        /// Load Lfg group info from DB
        void LoadFromDB(Field* fields, uint64 guid);
        /// Initializes player data after loading group data from DB
        void SetupGroupMember(uint64 guid, uint64 gguid);
        /// Return Lfg dungeon entry for given dungeon id
        uint32 GetLFGDungeonEntry(uint32 id);
        /// Sets the number of players who joined the LFG while not being in a group
        void SetSoloJoinedPlayersCount(uint64 gguid, uint8 count);
        /// Gets the number of players who joined the LFG while not being in a group
        uint8 GetSoloJoinedPlayersCount(uint64 gguid);

        bool HasQueueId(uint64 guid, uint32 queueId);
        PlayerQueueData const& GetPlayerQueueData(uint64 guid, uint32 queueId) const;
        GroupQueueData const& GetGroupQueueData(uint64 guid, uint32 queueId) const;
        PlayerQueueDataMap const* GetPlayerQueues(uint64 guid) const;
        GroupQueueDataMap const* GetGroupQueues(uint64 guid) const;

        // cs_lfg
        /// Get current player roles
        uint8 GetRoles(uint64 guid, uint32 queueId);
        /// Gets current lfg options
        uint32 GetOptions();
        /// Sets new lfg options
        void SetOptions(uint32 options);
        /// Checks if given lfg option is enabled
        bool isOptionEnabled(uint32 option);
        /// Clears queue - Only for internal testing
        void Clean();
        /// Dumps the state of the queue - Only for internal testing
        std::string DumpQueueInfo(uint32 dungeonID, bool client);

        // LFGScripts
        /// Get leader of the group (using internal data)
        uint64 GetLeader(uint64 guid);
        /// Initializes locked dungeons for given player (called at login or level change)
        void InitializeLockedDungeons(Player* player, uint8 level = 0);
        /// Sets player team
        void SetTeam(uint64 guid, uint8 team);
        /// Sets player group
        void SetGroup(uint64 guid, uint32 queueId, uint64 group);
        /// Gets player group
        uint64 GetGroup(uint64 guid, uint32 queueId);
        /// Sets the leader of the group
        void SetLeader(uint64 gguid, uint64 leader);
        /// Removes saved group data
        void RemoveGroupData(uint64 guid);
        // Useless by itself. Needed for debug purposes currently
        int32 RemovePlayerFromGroup(uint64 gguid, uint32 queueId, uint64 guid);
        // This is the function that complete remove player from the group. (I.e. on uninvite or removing group from all queues)
        void RemovePlayerFromGroup(uint64 gguid, uint64 guid);
        /// Adds player to group
        void AddPlayerToGroup(uint64 gguid, uint32 queueId, uint64 guid);
        /// Returns a list of all players in a group
        LfgGuidSet const& GetPlayers(uint64 guid);

        // LFGHandler
        /// Get locked dungeons
        LfgLockMap const& GetLockedDungeons(uint64 guid);
        /// Checks if Seasonal dungeon is active
        bool IsSeasonActive(uint32 dungeonId);
        /// Gets the random dungeon reward corresponding to given dungeon and player level
        LfgReward const* GetRandomDungeonReward(uint32 dungeon, uint8 level);
        /// Returns all random and seasonal dungeons for given level and expansion
        LfgDungeonSet GetRandomAndSeasonalDungeons(uint8 level, uint8 expansion);
        /// Teleport a player to/from selected dungeon
        void TeleportPlayer(Player* player, bool out, bool fromOpcode = false, bool forceChangeInstance = false);
        /// Returns whether a player can boot a player. If not the cooldown time is returned
        PartyResult CanBoot(uint64 kguid, uint64 vguid, uint32& timeLeft);
        /// Returns the number of boot votes needed for a specific group to boot a player
        uint8 GetBootVotesNeeded(uint64 gguid);
        /// Inits new proposal to boot a player
        void InitBoot(uint64 gguid, uint64 kguid, uint64 vguid, std::string const& reason);
        /// Updates player boot proposal with new player answer
        void UpdateBoot(uint64 guid, bool accept);
        /// Updates proposal to join dungeon with player answer
        void UpdateProposal(uint32 proposalId, uint64 guid, bool accept);
        /// Updates the role check with player answer
        void UpdateRoleCheck(uint64 gguid, uint64 guid = 0, uint8 roles = PLAYER_ROLE_NONE);
        /// Sets player lfg roles
        void SetRoles(uint64 guid, uint32 queueId, LfgRoles roles);
        /// Sets player join time
        void SetJoinTime(uint64 guid, uint32 queueId, time_t time);
        /// Join Lfg with selected roles, dungeons and comment
        void JoinLfg(Player* player, LfgRoles roles, LfgDungeonSet& dungeons, std::string const& comment);
        // Primary used on player's logout
        void RemovePlayerQueues(uint64 guid);
        void RemovePlayerQueuesOnPartyFound(uint64 guid, uint32 except = 0);
        void RemoveGroupQueues(uint64 guid);
        // Leaves lfg
        void LeaveLfg(uint64 guid, uint32 queuId);

        // LfgQueue
        LfgQueueManagerContainer const& GetQueueManagers() const { return QueueManagers; }
        QueueManager& GetQueueManager(uint64 guid);
        // Get last lfg state (NONE, DUNGEON or FINISHED_DUNGEON)
        LfgState GetOldState(uint64 guid, uint32 queueId);
        /// Check if given group guid is lfg
        bool IsLfgGroup(uint64 guid);
        /// Gets the player count of given group
        uint8 GetPlayerCount(uint64 guid);
        // Add a new Proposal. If false returned - somebody already has proposal in other queue
        bool AddProposal(LfgProposal& proposal);
        /// Checks if given roles match, modifies given roles map with new roles
        static bool CheckGroupRoles(LfgRolesMap &groles, uint8 neededTanks, uint8 neededHealers, uint8 neededDamage);
        static bool CheckRaidRoles(LfgRolesMap& groles, uint8 neededTanks, uint8 neededHealers, uint8 neededDamage);
        static bool CheckDpsOnly(LfgRolesMap& groles, uint8 neededTanks, uint8 neededHealers, uint8 neededDamage);
        /// Sends queue status to player
        static void SendLfgQueueStatus(uint64 guid, LfgQueueStatusData const& data);
        LFGDungeonData const* GetLFGDungeon(uint32 id);
        LfgRoles GetShortageRolesForQueue(uint64 guid, uint32 dungeonId);
        LfgRoles GetEligibleRolesForCTA(uint64 guid, uint32 dungeonId);
        void SetState(uint64 guid, uint32 queueId, LfgState state);

        LfgDungeonSet const& GetDungeonsByRandom(uint32 randomdungeon);
        LfgType GetDungeonType(uint32 dungeon);

        uint32 ConvertToServerQueueId(uint64 guid, uint32 clientQueueId) const;

    private:
        uint8 GetTeam(uint64 guid);
        void RestoreState(uint64 guid, uint32 queueId, char const* debugMsg);
        void SetDungeon(uint64 guid, uint32 dungeon);
        void SetSelectedDungeons(uint64 guid, uint32 queueId, LfgDungeonSet const& dungeons);
    public:
        uint32 GetRandomDungeon(uint64 guid, uint32 queueId) const;
    private:
        void SetRandomDungeon(uint64 guid, uint32 queueId, uint32 dungeon);
        void SetLockedDungeons(uint64 guid, LfgLockMap const& lock);
        void SetKicksLeft(uint64 guid, uint8 kicksLeft);
        void DecreaseKicksLeft(uint64 guid);
        void SetRolesForCTAReward(uint64 guid, uint32 queueId, LfgRoles roles);
        void RemovePlayerData(uint64 guid);
        void ReformQueue(uint64 guid, uint32 oldQueueId, uint32 newQueueId);
        void RemoveFinishedDungeons(uint64 guid);
        void GetCompatibleDungeons(LfgDungeonSet& dungeons, LfgGuidSet const& players, LfgLockPartyMap& lockMap, bool randomDungeon = false);
        void SaveToDB(uint64 guid, uint32 dbGuid);

        // Proposals
        void RemoveProposal(LfgProposalContainer::iterator itProposal, LfgUpdateType type);
        void MakeNewGroup(LfgProposal const& proposal);

        // Generic
        void SendLfgBootProposalUpdate(uint64 guid, LfgPlayerBoot const& boot);
        void SendLfgJoinResult(uint64 guid, uint32 queueId, LfgJoinResultData const& data);
        void SendLfgRoleChosen(uint64 guid, uint64 pguid, uint8 roles);
        void SendLfgRoleCheckUpdate(uint64 guid, LfgRoleCheck const& roleCheck);
        void SendLfgUpdateStatus(LfgUpdateType updateType, uint64 guid, uint32 queueId);
        void SendLfgUpdateProposal(uint64 guid, LfgProposal const& proposal);

        uint64 GetGuidForLog(uint64 guid) const;
        uint32 GenerateNewQueueId() { return ++m_queueId; }

        // General variables
        uint32 m_QueueTimer;                               ///< used to check interval of update
        uint32 m_ShortageCheckTimer;                       ///< used to check interval of shortage check
        uint32 m_lfgProposalId;                            ///< used as internal counter for proposals
        uint32 m_options;                                  ///< Stores config options
        uint32 m_queueId = 0;

        LfgQueueManagerContainer QueueManagers;            ///< Queues
        LfgCachedDungeonContainer CachedDungeonMapStore;   ///< Stores all dungeons by groupType
        // Reward System
        LfgRewardContainer RewardMapStore;                 ///< Stores rewards for random dungeons
        LFGDungeonContainer  LfgDungeonStore;
        // Rolecheck - Proposal - Vote Kicks
        LfgRoleCheckContainer RoleChecksStore;             ///< Current Role checks
        LfgProposalContainer ProposalsStore;               ///< Current Proposals
        LfgPlayerBootContainer BootsStore;                 ///< Current player kicks
        LfgPlayerDataContainer PlayersStore;               ///< Player data
        LfgGroupDataContainer GroupsStore;                 ///< Group data

        friend class QueueTests;
};

} // namespace lfg

#define sLFGMgr lfg::LFGMgr::instance()
#endif
