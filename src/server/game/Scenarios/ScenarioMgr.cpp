/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
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

#include "ScenarioMgr.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "Map.h"
#include "Player.h"

uint32 ScenarioMgr::GetCriteriaIdForScenarioStep(uint32 map, uint32 step)
{
    for (uint32 i = 0; i < sScenarioStepStore.GetNumRows(); ++i)
    {
        if (auto scenarioStep = sScenarioStepStore.LookupEntry(i))
            if (scenarioStep->ScenarioID == GetScenarioIdForMap(map) && scenarioStep->Step == step)
                return scenarioStep->CriteriaTreeID;
    }
    return 0;
}

uint32 ScenarioMgr::GetScenarioIdForMap(uint32 map)
{
    for (uint32 i = 0; i < sLFGDungeonStore.GetNumRows(); ++i)
    {
        if (auto dungeon = sLFGDungeonStore.LookupEntry(i))
            if (dungeon->map == map)
                return dungeon->scenario;
    }
    return 0;
}

void ScenarioMgr::SendScenarioState(Player* player, uint32 map, int32 step, uint32 StartTime, uint32 miscCriteriaTreeId, uint32 scenarioId, uint32 bonusData, ScenarioChallenge* challengeData)
{
    if (!player)
        return;

    if (step == 0) // when scenario not started packet should be sended twice
        SendScenarioState(player, map, -1, 0, miscCriteriaTreeId, scenarioId);

    uint32 criteriaTreeId = GetCriteriaIdForScenarioStep(map, step);

    // isle of thunder scenarios map will return first founded element for current map, but it`s wrong
    if (miscCriteriaTreeId)
        criteriaTreeId = miscCriteriaTreeId;

    ObjectGuid playerGuid = player->GetGUID();
    ObjectGuid unkGuid = 0;

    ByteBuffer bytesData;

    WorldPacket data(SMSG_SCENARIO_STATE);
    data << uint32(challengeData ? challengeData->MaxWave : 0);
    data << uint32(challengeData ? challengeData->Timer : 0);
    data << uint32(challengeData ? challengeData->Medal : MedalTypeNone);
    data << uint32(scenarioId ? scenarioId : GetScenarioIdForMap(map));
    data << uint32(challengeData ? challengeData->CurWave : 0);
    data << uint32(bonusData);
    data << uint32(step);
    data.WriteBits(criteriaTreeId ? 1 : 0, 19);
    data.WriteBit(false);

    if (criteriaTreeId)
    {
        data.WriteGuidMask(playerGuid, 3, 5);
        data.WriteGuidMask(unkGuid, 2);
        data.WriteGuidMask(playerGuid, 6);
        data.WriteGuidMask(unkGuid, 7);
        data.WriteGuidMask(playerGuid, 1, 7, 0);
        data.WriteGuidMask(unkGuid, 3);
        data.WriteGuidMask(playerGuid, 4);
        data.WriteGuidMask(unkGuid, 0, 5, 1, 4);
        data.WriteGuidMask(playerGuid, 2);
        data.WriteGuidMask(unkGuid, 6);
        data.WriteBits(0, 4); // some flag... & 1 -> delete

        bytesData.WriteByteSeq(unkGuid[3]);
        bytesData.WriteByteSeq(unkGuid[7]);
        bytesData.WriteByteSeq(unkGuid[5]);
        bytesData << uint32(StartTime);
        bytesData.WriteByteSeq(unkGuid[2]);
        bytesData << uint32(StartTime);
        bytesData.WriteByteSeq(unkGuid[6]);
        bytesData.WriteByteSeq(unkGuid[4]);
        bytesData.AppendPackedTime(time(NULL));
        bytesData.WriteByteSeq(unkGuid[1]);
        bytesData.WriteByteSeq(playerGuid[3]);
        bytesData.WriteByteSeq(playerGuid[2]);
        bytesData.WriteByteSeq(playerGuid[1]);
        bytesData.WriteByteSeq(playerGuid[5]);
        bytesData.WriteByteSeq(playerGuid[4]);
        bytesData.WriteByteSeq(playerGuid[7]);
        bytesData.WriteByteSeq(unkGuid[0]);
        bytesData.WriteByteSeq(playerGuid[6]);
        bytesData.WriteByteSeq(playerGuid[0]);
        bytesData << uint32(criteriaTreeId);
    }

    data.WriteBit(false);

    data.FlushBits();

    if (criteriaTreeId)
        data.append(bytesData);

    player->SendDirectMessage(&data);

    if (challengeData && challengeData->Timer && player->GetInstanceScript())
        player->GetInstanceScript()->SendChallengeStartElapsedTimer(TIMER_SCENARIO, 0);

    if (step > 0 && criteriaTreeId)
    {
        WorldPacket data(SMSG_SCENARIO_PROGRESS_UPDATE);

        data.WriteGuidMask(unkGuid, 6, 4, 5);
        data.WriteGuidMask(playerGuid, 1, 5, 6, 7, 4);
        data.WriteGuidMask(unkGuid, 1);
        data.WriteGuidMask(playerGuid, 0);
        data.WriteGuidMask(unkGuid, 2, 3);
        data.WriteGuidMask(playerGuid, 2, 3);
        data.WriteGuidMask(unkGuid, 0);
        data.WriteBits(0, 4); // some flag... & 1 -> delete
        data.WriteGuidMask(unkGuid, 7);

        data.WriteGuidBytes(playerGuid, 5, 2);
        data.WriteGuidBytes(unkGuid, 7, 4);
        data.WriteGuidBytes(playerGuid, 4, 0);
        data.WriteGuidBytes(unkGuid, 1, 2);
        data << uint32(StartTime);
        data.WriteGuidBytes(playerGuid, 3);
        data << uint32(criteriaTreeId);
        data.WriteGuidBytes(playerGuid, 1);
        data.AppendPackedTime(time(NULL));
        data << uint32(StartTime);
        data.WriteGuidBytes(unkGuid, 0, 3, 6);
        data.WriteGuidBytes(playerGuid, 7, 6);
        data.WriteGuidBytes(unkGuid, 5);

        player->SendDirectMessage(&data);
    }
}

void ScenarioMgr::LoadDB2Data()
{
    _scenarioData.clear();

    std::unordered_map<uint32, std::map<uint8, ScenarioStepEntry const*>> scenarioSteps;
    uint32 deepestCriteriaTreeSize = 0;

    for (uint32 i = 0; i < sScenarioStepStore.GetNumRows(); ++i)
    {
        if (ScenarioStepEntry const* step = sScenarioStepStore.LookupEntry(i))
            scenarioSteps[step->ScenarioID][step->Step] = step;
    }

    ASSERT(deepestCriteriaTreeSize < MAX_ALLOWED_SCENARIO_POI_QUERY_SIZE /*,"MAX_ALLOWED_SCENARIO_POI_QUERY_SIZE must be at least %u", deepestCriteriaTreeSize + 1*/);

    for (uint32 i = 0; i < sScenarioStore.GetNumRows(); ++i)
    {
        if (ScenarioEntry const* scenario = sScenarioStore.LookupEntry(i))
        {
            ScenarioDataObs& data = _scenarioData[scenario->ID];
            data.Entry = scenario;
            data.Steps = std::move(scenarioSteps[scenario->ID]);
        }
    }
}

void ScenarioMgr::LoadScenarioPOI()
{
    uint32 oldMSTime = getMSTime();

    _scenarioPOIStore.clear(); // need for reload case

    uint32 count = 0;

    //                                                      0            1        2     6          7           8       9       10         11               12
    QueryResult result = WorldDatabase.Query("SELECT CriteriaTreeID, BlobIndex, Idx1, MapID, WorldMapAreaId, Floor, Priority, Flags, WorldEffectID, PlayerConditionID FROM scenario_poi ORDER BY CriteriaTreeID, Idx1");
    if (!result)
    {
        TC_LOG_ERROR("server.loading", ">> Loaded 0 scenario POI definitions. DB table `scenario_poi` is empty.");
        return;
    }

    //                                                       0        1    2  3
    QueryResult points = WorldDatabase.Query("SELECT CriteriaTreeID, Idx1, X, Y FROM scenario_poi_points ORDER BY CriteriaTreeID DESC, Idx1, Idx2");

    std::vector<std::vector<std::vector<ScenarioPOIPoint>>> POIs;

    if (points)
    {
        // The first result should have the highest criteriaTreeId
        Field* fields = points->Fetch();
        uint32 criteriaTreeIdMax = fields[0].GetInt32();
        POIs.resize(criteriaTreeIdMax + 1);

        do
        {
            fields = points->Fetch();

            int32 CriteriaTreeID = fields[0].GetInt32();
            int32 Idx1 = fields[1].GetInt32();
            int32 X = fields[2].GetInt32();
            int32 Y = fields[3].GetInt32();

            if (int32(POIs[CriteriaTreeID].size()) <= Idx1 + 1)
                POIs[CriteriaTreeID].resize(Idx1 + 10);

            ScenarioPOIPoint point(X, Y);
            POIs[CriteriaTreeID][Idx1].push_back(point);
        } while (points->NextRow());
    }

    do
    {
        Field* fields = result->Fetch();

        int32 CriteriaTreeID = fields[0].GetInt32();
        int32 BlobIndex = fields[1].GetInt32();
        int32 Idx1 = fields[2].GetInt32();
        int32 MapID = fields[3].GetInt32();
        int32 WorldMapAreaId = fields[4].GetInt32();
        int32 Floor = fields[5].GetInt32();
        int32 Priority = fields[6].GetInt32();
        int32 Flags = fields[7].GetInt32();
        int32 WorldEffectID = fields[8].GetInt32();
        int32 PlayerConditionID = fields[9].GetInt32();

        if (!sCriteriaTreeStore.LookupEntry(CriteriaTreeID))
            TC_LOG_ERROR("sql.sql", "`scenario_poi` CriteriaTreeID (%u) Idx1 (%u) does not correspond to a valid criteria tree", CriteriaTreeID, Idx1);

        if (CriteriaTreeID < int32(POIs.size()) && Idx1 < int32(POIs[CriteriaTreeID].size()))
            _scenarioPOIStore[CriteriaTreeID].emplace_back(BlobIndex, MapID, WorldMapAreaId, Floor, Priority, Flags, WorldEffectID, PlayerConditionID, POIs[CriteriaTreeID][Idx1]);
        else
            TC_LOG_ERROR("server.loading", "Table scenario_poi references unknown scenario poi points for criteria tree id %i POI id %i", CriteriaTreeID, BlobIndex);

        ++count;
    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u scenario POI definitions in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

ScenarioPOIVector const* ScenarioMgr::GetScenarioPOIs(int32 criteriaTreeID) const
{
    auto itr = _scenarioPOIStore.find(criteriaTreeID);
    if (itr != _scenarioPOIStore.end())
        return &itr->second;

    return nullptr;
}
