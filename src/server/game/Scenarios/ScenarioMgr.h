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

#ifndef ScenarioMgr_h__
#define ScenarioMgr_h__

#include "Common.h"
#include "InstanceScript.h"
#include "SharedDefines.h"

#define MAX_ALLOWED_SCENARIO_POI_QUERY_SIZE 35

class InstanceScenario;
class Map;
struct ScenarioEntry;
struct ScenarioStepEntry;

struct ScenarioDataObs
{
    ScenarioEntry const* Entry;
    std::map<uint8, ScenarioStepEntry const*> Steps;
};

/*
Scenario data should be loaded on demand.
The server will get data from the database which scenario ids is linked with which map id/difficulty/player team.
The first time a scenario is loaded, the map loads and stores the scenario data for future scenario instance launches.
*/

struct ScenarioDBData
{
    uint32 MapID;
    uint8 DifficultyID;
    uint32 Scenario_A;
    uint32 Scenario_H;
};

typedef std::map<uint32, ScenarioDataObs> ScenarioDataContainer;

enum ScenarioType
{
    SCENARIO_TYPE_SCENARIO       = 0,
    SCENARIO_TYPE_CHALLENGE_MODE = 1,
    SCENARIO_TYPE_SOLO           = 2,
    SCENARIO_TYPE_DUNGEON        = 10,
};

struct ScenarioPOIPoint
{
    int32 X;
    int32 Y;

    ScenarioPOIPoint() : X(0), Y(0) { }
    ScenarioPOIPoint(int32 _X, int32 _Y) : X(_X), Y(_Y) { }
};

struct ScenarioPOI
{
    int32 BlobIndex;
    int32 MapID;
    int32 WorldMapAreaID;
    int32 Floor;
    int32 Priority;
    int32 Flags;
    int32 WorldEffectID;
    int32 PlayerConditionID;
    std::vector<ScenarioPOIPoint> Points;

    ScenarioPOI() : BlobIndex(0), MapID(0), WorldMapAreaID(0), Floor(0), Priority(0), Flags(0), WorldEffectID(0), PlayerConditionID(0) { }

    ScenarioPOI(int32 _BlobIndex, int32 _MapID, int32 _WorldMapAreaID, int32 _Floor, int32 _Priority, int32 _Flags, int32 _WorldEffectID,
        int32 _PlayerConditionID, std::vector<ScenarioPOIPoint> points) :
        BlobIndex(_BlobIndex), MapID(_MapID), WorldMapAreaID(_WorldMapAreaID), Floor(_Floor), Priority(_Priority), Flags(_Flags), WorldEffectID(_WorldEffectID),
        PlayerConditionID(_PlayerConditionID), Points(std::move(points)) { }

    ScenarioPOI(ScenarioPOI&& scenarioPOI) :
        BlobIndex(scenarioPOI.BlobIndex), MapID(scenarioPOI.MapID), WorldMapAreaID(scenarioPOI.WorldMapAreaID), Floor(scenarioPOI.Floor), Priority(scenarioPOI.Priority),
        Flags(scenarioPOI.Flags), WorldEffectID(scenarioPOI.WorldEffectID), PlayerConditionID(scenarioPOI.PlayerConditionID), Points(std::move(scenarioPOI.Points)) { }
};

typedef std::vector<ScenarioPOI> ScenarioPOIVector;
typedef std::unordered_map<uint32, ScenarioPOIVector> ScenarioPOIContainer;

struct ScenarioChallenge
{
    uint32 CurWave;
    uint32 MaxWave;
    ChallengeMedals Medal;
    uint32 Timer; // in seconds

    ScenarioChallenge(uint32 curWave, uint32 maxWave, ChallengeMedals medal, uint32 timer) : CurWave(curWave), MaxWave(maxWave), Medal(medal), Timer(timer) { }
};

class ScenarioMgr
{
    private:
        ScenarioMgr() { }
        ~ScenarioMgr() { }

    public:
        static ScenarioMgr* Instance()
        {
            static ScenarioMgr _instance;
            return &_instance;
        }

        void LoadDB2Data();
        void LoadScenarioPOI();

        uint32 GetMaxStepsForScenario(uint32 map) { return _scenarioData[GetScenarioIdForMap(map)].Steps.crbegin()->second->Step; }
        uint32 GetScenarioIdForMap(uint32 map);
        uint32 GetCriteriaIdForScenarioStep(uint32 map, uint32 step);

        ScenarioPOIVector const* GetScenarioPOIs(int32 criteriaTreeID) const;

        void SendScenarioState(Player* player, uint32 map, int32 step, uint32 StartTime, uint32 miscCriteriaTreeId = 0, uint32 scenarioId = 0, uint32 bonusData = 0, ScenarioChallenge* challengeData = nullptr);

    private:
        ScenarioDataContainer _scenarioData;
        ScenarioPOIContainer _scenarioPOIStore;
};

#define sScenarioMgr ScenarioMgr::Instance()

#endif // ScenarioMgr_h__