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

#ifndef SF_LFGGROUPDATA_H
#define SF_LFGGROUPDATA_H

#include "LFGDataOwner.h"

namespace lfg
{

struct GroupQueueData
{
    LfgState State = LFG_STATE_NONE;
    LfgState OldState = LFG_STATE_NONE;
};

typedef std::map<uint32, GroupQueueData> GroupQueueDataMap;

enum LfgGroupEnum
{
    LFG_GROUP_MAX_KICKS                           = 3,
    LFG_RAID_MAX_KICKS = 15,
};

/**
    Stores all lfg data needed about a group.
*/
class LfgGroupData : public LfgDataOwner<GroupQueueData>
{
    public:
        // General
        void AddPlayer(uint64 guid);
        uint8 RemovePlayer(uint64 guid);
        void RemoveAllPlayers();
        void SetLeader(uint64 guid);

        // Dungeon
        void SetDungeon(uint32 dungeon);

        // VoteKick
        void SetKicksLeft(uint8 kicksLeft);
        void DecreaseKicksLeft();

        // General
        LfgGuidSet const& GetPlayers() const;
        uint8 GetPlayerCount() const;
        uint64 GetLeader() const;

        // Dungeon
        uint32 GetDungeon(bool asId = true) const;

        // VoteKick
        uint8 GetKicksLeft() const;

        // Solo Join
        void SetSoloJoinedPlayersCount(uint8 count);
        uint8 GetSoloJoinedPlayersCount() const;

        void AddQueue(uint32 queueId);

    private:
        // General
        uint64 m_leader = 0;                               ///< Leader GUID
        LfgGuidSet m_players;                              ///< Players in group
        // Dungeon
        uint32 m_dungeon = 0;                              ///< Dungeon entry
        // Vote Kick
        uint8 m_kicksLeft = 0;                             ///< Number of kicks left
        // Solo Join
        uint8 m_soloJoinedPlayersCount = 0;
};

} // namespace lfg

#endif
