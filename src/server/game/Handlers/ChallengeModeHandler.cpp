#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Player.h"
#include "Group.h"
#include "LFGMgr.h"
#include "SpellHistory.h"

void WorldSession::HandleGetChallengeModeRewards(WorldPacket& /*recvData*/)
{
    ByteBuffer buffer;
    WorldPacket data(SMSG_CHALLENGE_MODE_REWARDS);
    ChallengeRewardsMap challengeRewards = sObjectMgr->GetChallengeRewards();

    data.WriteBits(challengeRewards.size(), 21); // RewardsCount

    for (auto&& reward : challengeRewards)
    {
        uint32 rewardsPerMedalCount = 4;
        data.WriteBits(rewardsPerMedalCount, 20);

        ChallengeReward challengeReward = reward.second;
        for (uint32 i = 0; i < rewardsPerMedalCount; i++)
        {
            uint32 itemRewards = 0;
            uint32 currencyRewards = 0;

            data.WriteBits(itemRewards, 21);
            data.WriteBits(currencyRewards, 20);

            buffer << uint32(challengeReward.MoneyReward[i]);
        }
        buffer << uint32(challengeReward.MapId);
    }

    data.WriteBits(0, 20); // TierRewards

    data.FlushBits();

    if (buffer.size())
        data.append(buffer);

    // Anything else is needed to be sent
    SendPacket(&data);
}

void WorldSession::HandleChallengeModeRequestLeaders(WorldPacket& recvData)
{
    uint32 mapId = recvData.read<uint32>();
    recvData.read_skip<uint32>(); // Last Guild update
    recvData.read_skip<uint32>(); // Last Realm update

    RealmCompletedChallenge* groupChallenge = sObjectMgr->GetGroupCompletedChallengeForMap(mapId);
    RealmCompletedChallenge* guildChallenge = sObjectMgr->GetGuildCompletedChallengeForMap(mapId);

    ByteBuffer realmBuffer, guildBuffer;
    WorldPacket data(SMSG_CHALLENGE_MODE_REQUEST_LEADERS_RESULT);

    data << uint32(time(nullptr));
    data << uint32(time(nullptr));
    data << uint32(mapId);

    uint32 realmLeaders = groupChallenge != nullptr;
    uint32 guildLeaders = 0;

    if (guildChallenge && guildChallenge->GuildId == _player->GetGuildId())
        guildLeaders = 1;

    if (guildChallenge && !groupChallenge)
        groupChallenge = guildChallenge;

    data.WriteBits(guildLeaders, 19);

    for (uint32 i = 0; i < guildLeaders; i++)
    {
        uint32 members = guildChallenge->MembersCount;
        data.WriteBits(members, 20);

        for (uint32 j = 0; j < members; j++)
        {
            ObjectGuid guid = guildChallenge->Members[j].Guid;

            data.WriteGuidMask(guid, 5, 2, 3, 0, 7, 1, 4, 6);

            guildBuffer.WriteGuidBytes(guid, 3);
            guildBuffer << uint32(guildChallenge->Members[j].SpecId);
            guildBuffer << uint32(realmID);
            guildBuffer.WriteGuidBytes(guid, 1, 5, 0);
            guildBuffer << uint32(realmID);
            guildBuffer.WriteGuidBytes(guid, 4, 7, 6, 2);
        }

        guildBuffer << uint32(guildChallenge->AttemptId);
        guildBuffer << uint32(guildChallenge->MedalEarned);
        guildBuffer << uint32(realmID);
        guildBuffer << uint32(guildChallenge->CompletionTime);
        guildBuffer << uint32(guildChallenge->CompletionDate);
    }

    data.WriteBits(realmLeaders, 19);

    for (uint32 i = 0; i < realmLeaders; i++)
    {
        uint32 members = groupChallenge->MembersCount;
        data.WriteBits(members, 20);

        for (uint32 j = 0; j < members; j++)
        {
            ObjectGuid guid = groupChallenge->Members[j].Guid;

            data.WriteGuidMask(guid, 5, 3, 0, 1, 2, 4, 6, 7);

            realmBuffer.WriteGuidBytes(guid, 4, 3, 6, 7, 2, 1);
            realmBuffer << uint32(realmID);
            realmBuffer << uint32(groupChallenge->Members[j].SpecId);
            realmBuffer << uint32(realmID);
            realmBuffer.WriteGuidBytes(guid, 0, 5);
        }

        realmBuffer << uint32(groupChallenge->CompletionDate);
        realmBuffer << uint32(realmID);
        realmBuffer << uint32(groupChallenge->AttemptId);
        realmBuffer << uint32(groupChallenge->CompletionTime);
        realmBuffer << uint32(groupChallenge->MedalEarned);
    }

    data.FlushBits();

    if (realmBuffer.size())
        data.append(realmBuffer);

    if (guildBuffer.size())
        data.append(guildBuffer);

    SendPacket(&data);
}

void WorldSession::HandleChallengeModeRequestMapStats(WorldPacket& /*recvData*/)
{
    uint32 mapsCount = _player->GetCompletedChallenges().size();

    ByteBuffer dataBuffer;
    WorldPacket data(SMSG_CHALLENGE_MODE_ALL_MAP_STATS);

    data.WriteBits(mapsCount, 19);

    // MapData
    if (mapsCount > 0)
    {
        for (auto&& challengeData : _player->GetCompletedChallenges())
        {
            CompletedChallenge completedChallenge = challengeData.second;

            uint32 specCount = 0;
            data.WriteBits(specCount, 23);

            dataBuffer.AppendPackedTime(completedChallenge.BestMedalDate);

            dataBuffer << int32(completedChallenge.BestMedal);
            dataBuffer << int32(challengeData.first);
            dataBuffer << int32(completedChallenge.LastTime);

            // BestSpecs - Useless part ?
            for (uint32 i = 0; i < specCount; ++i)
                dataBuffer << uint16(0); //< SpecId

            dataBuffer << int32(completedChallenge.BestTime);
        }
    }

    data.FlushBits();

    if (dataBuffer.size())
        data.append(dataBuffer);

    SendPacket(&data);
}

void WorldSession::SendChallengeModeMapStatsUpdate(uint32 mapId)
{
    WorldPacket data(SMSG_CHALLENGE_MODE_MAP_STATS_UPDATE);

    uint32 specCount = 0;
    data.WriteBits(specCount, 23);

    // BestSpecs - Useless part ?
    for (uint32 i = 0; i < specCount; ++i)
        data << uint16(0); // SpecId

    auto completedChallenges = _player->GetCompletedChallenges();
    auto challengeData = completedChallenges.find(mapId);
    if (challengeData != completedChallenges.end())
    {
        CompletedChallenge completedChallenge = challengeData->second;

        data << int32(completedChallenge.LastTime);
        data.AppendPackedTime(completedChallenge.BestMedalDate);
        data << int32(challengeData->first);
        data << int32(completedChallenge.BestTime);
        data << int32(completedChallenge.BestMedal);
    }

    SendPacket(&data);
}

struct CooldownResetPredicate
{
    bool operator()(SpellHistory::CooldownEntry const& cooldownEntry)
    {
        SpellInfo const* entry = sSpellMgr->GetSpellInfo(cooldownEntry.SpellId);
        if (!entry)
            return false;
        if (entry->RecoveryTime < 5 * MINUTE * IN_MILLISECONDS || entry->CategoryRecoveryTime < 5 * MINUTE * IN_MILLISECONDS)
            return false;
        if (entry->CategoryEntry && entry->CategoryEntry->Flags & SPELL_CATEGORY_FLAG_COOLDOWN_EXPIRES_AT_MIDNIGHT)
            return false;
        return true;
    }
};

void WorldSession::HandleResetChallengeMode(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: CMSG_RESET_CHALLENGE_MODE");

    if (_player->GetGroup() && !_player->GetGroup()->IsLeader(_player->GetGUID()))
    {
        _player->SendGameError(GameError::ERR_NOT_LEADER);
        return;
    }

    if (_player->IsInCombat())
    {
        _player->SendGameError(GameError::ERR_NOT_IN_COMBAT);
        return;
    }

    Map* map = _player->GetMap();
    if (map->IsChallengeDungeon())
    {
        for (auto&& itr : map->GetPlayers())
        {
            if (Player* player = itr.GetSource())
            {
                player->GetSpellHistory()->RemoveCooldowns(CooldownResetPredicate{});

                for (auto&& bind : player->GetBoundInstances(DUNGEON_DIFFICULTY_CHALLENGE))
                    if (map->GetEntry()->MapID == bind.first && _player->GetInstanceId() == player->GetInstanceId())
                        player->UnbindInstance(bind.first, DUNGEON_DIFFICULTY_CHALLENGE, true);

                if (Group* group = _player->GetGroup())
                    group->UnbindInstance(map->GetEntry()->MapID, DUNGEON_DIFFICULTY_CHALLENGE, true);

                player->SetForcedTeleportFar(true);
                if (AreaTriggerStruct const* at = sObjectMgr->GetMapEntranceTrigger(map->GetEntry()->MapID))
                    player->TeleportTo(at->target_mapId, at->target_X, at->target_Y, at->target_Z, at->target_Orientation);
                player->SetForcedTeleportFar(false);
            }
        }
        if (_player->GetGroup())
            _player->GetGroup()->SendUpdate();
    }
}
