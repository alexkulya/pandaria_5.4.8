/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
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

#include "PathGenerator.h"
#include "Map.h"
#include "Creature.h"
#include "GameObject.h"
#include "Transport.h"
#include "MMapFactory.h"
#include "MMapManager.h"
#include "Log.h"
#include "World.h"

#include "DetourCommon.h"
#include "DetourNavMeshQuery.h"

////////////////// PathGenerator //////////////////
PathGenerator::PathGenerator(const Unit* owner) :
    _polyLength(0), _type(PATHFIND_BLANK), _useStraightPath(false),
    _forceDestination(false), _pointPathLimit(MAX_POINT_PATH_LENGTH),
    _endPosition(G3D::Vector3::zero()), _sourceUnit(owner), _navMesh(NULL),
    _navMeshQuery(NULL), _straightLine(false)
{
    memset(_pathPolyRefs, 0, sizeof(_pathPolyRefs));

    TC_LOG_DEBUG("maps", "++ PathGenerator::PathGenerator for %u \n", _sourceUnit->GetGUIDLow());

    UpdateNavMesh();
    CreateFilter();
}

PathGenerator::~PathGenerator()
{
    TC_LOG_DEBUG("maps", "++ PathGenerator::~PathGenerator() for %u \n", _sourceUnit->GetGUIDLow());
    delete visualizePathWaypointGUIDs;
    delete visualizeNavmeshWaypointGUIDs;
}

bool PathGenerator::CalculatePath(float destX, float destY, float destZ, bool forceDest, bool straightLine, bool assumeSourceOnGround)
{
    float x, y, z;
    _sourceUnit->GetPosition(x, y, z);

    if (assumeSourceOnGround)
        _sourceUnit->UpdateAllowedPositionZ(x, y, z);

    if (Transport* transport = _sourceUnit->GetTransport())
    {
        transport->CalculatePassengerOffset(x, y, z);
        transport->CalculatePassengerOffset(destX, destY, destZ);
    }

    if (!Trinity::IsValidMapCoord(destX, destY, destZ) || !Trinity::IsValidMapCoord(x, y, z))
        return false;

    G3D::Vector3 dest(destX, destY, destZ);
    SetEndPosition(dest);

    G3D::Vector3 start(x, y, z);
    SetStartPosition(start);

    _forceDestination = forceDest;
    _straightLine = straightLine;

    TC_LOG_DEBUG("maps", "++ PathGenerator::CalculatePath() for %u \n", _sourceUnit->GetGUIDLow());

    bool skip = false;

    // FIXME
    if (_sourceUnit->GetMapId() == 1098 && (z > 54.0f || destZ > 54.0f)) // Throne of Thunder
    {
        // Primordius room
        Position center{ 5592.51f, 4655.91f, 55,78 };
        if (center.GetExactDist2d(x, y) < 70.0f || center.GetExactDist2d(destX, destY))
            skip = true;
    }

    // make sure navMesh works - we can run on map w/o mmap
    // check if the start and end point have a .mmtile loaded (can we pass via not loaded tile on the way?)
    if (!_navMesh || !_navMeshQuery || _sourceUnit->HasUnitState(UNIT_STATE_IGNORE_PATHFINDING) ||
        !HaveTile(start) || !HaveTile(dest) || skip)
    {
        BuildShortcut();
        _type = PathType(PATHFIND_NORMAL | PATHFIND_NOT_USING_PATH);

        if (Transport* transport = _sourceUnit->GetTransport())
            for (auto&& point : _pathPoints)
                transport->CalculatePassengerPosition(point.x, point.y, point.z);

        return true;
    }

    UpdateFilter();

    BuildPolyPath(start, dest);

    if (Transport* transport = _sourceUnit->GetTransport())
        for (auto&& point : _pathPoints)
            transport->CalculatePassengerPosition(point.x, point.y, point.z);

    if (_sourceUnit->VisualizePathfinding)
    {
        VisualizePath(2500);
        VisualizeNavmesh(2500);
    }

    return true;
}

dtPolyRef PathGenerator::GetPathPolyByPosition(dtPolyRef const* polyPath, uint32 polyPathSize, float const* point, float* distance) const
{
    if (!polyPath || !polyPathSize)
        return INVALID_POLYREF;

    dtPolyRef nearestPoly = INVALID_POLYREF;
    float minDist = FLT_MAX;

    for (uint32 i = 0; i < polyPathSize; ++i)
    {
        float closestPoint[VERTEX_SIZE];
        if (dtStatusFailed(_navMeshQuery->closestPointOnPoly(polyPath[i], point, closestPoint, nullptr)))
            continue;

        float d = dtVdistSqr(point, closestPoint);
        if (d < minDist)
        {
            minDist = d;
            nearestPoly = polyPath[i];

            if (minDist < 1.0f) // shortcut out - close enough for us
                break;
        }
    }

    if (distance)
        *distance = dtMathSqrtf(minDist);

    return (minDist < 3.0f) ? nearestPoly : INVALID_POLYREF;
}

dtPolyRef PathGenerator::GetPolyByLocation(float const* point, float* distance) const
{
    // first we check the current path
    // if the current path doesn't contain the current poly,
    // we need to use the expensive navMesh.findNearestPoly
    dtPolyRef polyRef = GetPathPolyByPosition(_pathPolyRefs, _polyLength, point, distance);
    if (polyRef != INVALID_POLYREF)
        return polyRef;

    // we don't have it in our old path
    // try to get it by findNearestPoly()
    // first try with low search box
    float extents[VERTEX_SIZE] = {3.0f, 5.0f, 3.0f};    // bounds of poly search area
    float closestPoint[VERTEX_SIZE] = {0.0f, 0.0f, 0.0f};
    if (dtStatusSucceed(_navMeshQuery->findNearestPoly(point, extents, &_filter, &polyRef, closestPoint)) && polyRef != INVALID_POLYREF)
    {
        *distance = dtVdist(closestPoint, point);
        return polyRef;
    }

    // still nothing ..
    // try with bigger search box
    // Note that the extent should not overlap more than 128 polygons in the navmesh (see dtNavMeshQuery::findNearestPoly)
    extents[1] = 50.0f;

    if (dtStatusSucceed(_navMeshQuery->findNearestPoly(point, extents, &_filter, &polyRef, closestPoint)) && polyRef != INVALID_POLYREF)
    {
        *distance = dtVdist(closestPoint, point);
        return polyRef;
    }

    return INVALID_POLYREF;
}

void PathGenerator::BuildPolyPath(G3D::Vector3 const& startPos, G3D::Vector3 const& endPos)
{
    // *** getting start/end poly logic ***

    float distToStartPoly, distToEndPoly;
    float startPoint[VERTEX_SIZE] = {startPos.y, startPos.z, startPos.x};
    float endPoint[VERTEX_SIZE] = {endPos.y, endPos.z, endPos.x};

    dtPolyRef startPoly = GetPolyByLocation(startPoint, &distToStartPoly);
    dtPolyRef endPoly = GetPolyByLocation(endPoint, &distToEndPoly);

    // we have a hole in our mesh
    // make shortcut path and mark it as NOPATH ( with flying and swimming exception )
    // its up to caller how he will use this info
    if (startPoly == INVALID_POLYREF || endPoly == INVALID_POLYREF)
    {
        TC_LOG_DEBUG("maps", "++ BuildPolyPath :: (startPoly == 0 || endPoly == 0)\n");
        BuildShortcut();
        bool path = _sourceUnit->GetTypeId() == TYPEID_UNIT && _sourceUnit->ToCreature()->CanFly();

        bool waterPath = _sourceUnit->GetTypeId() == TYPEID_UNIT && _sourceUnit->ToCreature()->CanSwim() && !_sourceUnit->GetTransport();
        if (waterPath)
        {
            // Check both start and end points, if they're both in water, then we can *safely* let the creature move
            for (uint32 i = 0; i < _pathPoints.size(); ++i)
            {
                ZLiquidStatus status = _sourceUnit->GetBaseMap()->getLiquidStatus(_pathPoints[i].x, _pathPoints[i].y, _pathPoints[i].z, MAP_ALL_LIQUIDS, NULL);
                // One of the points is not in the water, cancel movement.
                if (status == LIQUID_MAP_NO_WATER)
                {
                    waterPath = false;
                    break;
                }
            }
        }

        _type = (path || waterPath) ? PathType(PATHFIND_NORMAL | PATHFIND_NOT_USING_PATH) : PATHFIND_NOPATH;
        return;
    }

    // we may need a better number here
    bool farFromPoly = (distToStartPoly > 7.0f || distToEndPoly > 7.0f);
    if (farFromPoly)
    {
        TC_LOG_DEBUG("maps", "++ BuildPolyPath :: farFromPoly distToStartPoly=%.3f distToEndPoly=%.3f\n", distToStartPoly, distToEndPoly);

        bool buildShotrcut = false;
        if (_sourceUnit->GetTypeId() == TYPEID_UNIT)
        {
            Creature* owner = (Creature*)_sourceUnit;

            G3D::Vector3 const& p = (distToStartPoly > 7.0f) ? startPos : endPos;
            if (!_sourceUnit->GetTransport() && _sourceUnit->GetBaseMap()->IsInWater(p.x, p.y, p.z))
            {
                TC_LOG_DEBUG("maps", "++ BuildPolyPath :: underWater case\n");
                if (owner->CanSwim())
                    buildShotrcut = true;
            }
            else
            {
                TC_LOG_DEBUG("maps", "++ BuildPolyPath :: flying case\n");
                if (owner->CanFly())
                    buildShotrcut = true;
            }
        }

        if (buildShotrcut)
        {
            BuildShortcut();
            _type = PathType(PATHFIND_NORMAL | PATHFIND_NOT_USING_PATH);
            return;
        }
        else
        {
            float closestPoint[VERTEX_SIZE];
            // we may want to use closestPointOnPolyBoundary instead
            if (dtStatusSucceed(_navMeshQuery->closestPointOnPoly(endPoly, endPoint, closestPoint, nullptr)))
            {
                dtVcopy(endPoint, closestPoint);
                SetActualEndPosition(G3D::Vector3(endPoint[2], endPoint[0], endPoint[1]));
            }

            _type = PATHFIND_INCOMPLETE;
        }
    }

    // *** poly path generating logic ***

    // start and end are on same polygon
    // just need to move in straight line
    if (startPoly == endPoly)
    {
        TC_LOG_DEBUG("maps", "++ BuildPolyPath :: (startPoly == endPoly)\n");

        BuildShortcut();

        _pathPolyRefs[0] = startPoly;
        _polyLength = 1;

        _type = farFromPoly ? PATHFIND_INCOMPLETE : PATHFIND_NORMAL;
        TC_LOG_DEBUG("maps", "++ BuildPolyPath :: path type %d\n", _type);
        return;
    }

    // look for startPoly/endPoly in current path
    /// @todo we can merge it with getPathPolyByPosition() loop
    bool startPolyFound = false;
    bool endPolyFound = false;
    uint32 pathStartIndex = 0;
    uint32 pathEndIndex = 0;

    if (_polyLength)
    {
        for (; pathStartIndex < _polyLength; ++pathStartIndex)
        {
            // here to carch few bugs
            ASSERT(_pathPolyRefs[pathStartIndex] != INVALID_POLYREF);

            if (_pathPolyRefs[pathStartIndex] == startPoly)
            {
                startPolyFound = true;
                break;
            }
        }

        for (pathEndIndex = _polyLength-1; pathEndIndex > pathStartIndex; --pathEndIndex)
            if (_pathPolyRefs[pathEndIndex] == endPoly)
            {
                endPolyFound = true;
                break;
            }
    }

    if (startPolyFound && endPolyFound)
    {
        TC_LOG_DEBUG("maps", "++ BuildPolyPath :: (startPolyFound && endPolyFound)\n");

        // we moved along the path and the target did not move out of our old poly-path
        // our path is a simple subpath case, we have all the data we need
        // just "cut" it out

        _polyLength = pathEndIndex - pathStartIndex + 1;
        memmove(_pathPolyRefs, _pathPolyRefs + pathStartIndex, _polyLength * sizeof(dtPolyRef));
    }
    else if (startPolyFound && !endPolyFound && sWorld->getBoolConfig(CONFIG_MMAP_ALLOW_REUSE_OF_PREVIOUS_PATH_SEGMENTS))
    {
        TC_LOG_DEBUG("maps", "++ BuildPolyPath :: (startPolyFound && !endPolyFound)\n");

        // we are moving on the old path but target moved out
        // so we have atleast part of poly-path ready

        _polyLength -= pathStartIndex;

        // try to adjust the suffix of the path instead of recalculating entire length
        // at given interval the target cannot get too far from its last location
        // thus we have less poly to cover
        // sub-path of optimal path is optimal

        // take ~80% of the original length
        /// @todo play with the values here
        uint32 prefixPolyLength = uint32(_polyLength * 0.8f + 0.5f);
        memmove(_pathPolyRefs, _pathPolyRefs+pathStartIndex, prefixPolyLength * sizeof(dtPolyRef));

        dtPolyRef suffixStartPoly = _pathPolyRefs[prefixPolyLength-1];

        // we need any point on our suffix start poly to generate poly-path, so we need last poly in prefix data
        float suffixEndPoint[VERTEX_SIZE];
        if (dtStatusFailed(_navMeshQuery->closestPointOnPoly(suffixStartPoly, endPoint, suffixEndPoint, nullptr)))
        {
            // we can hit offmesh connection as last poly - closestPointOnPoly() don't like that
            // try to recover by using prev polyref
            --prefixPolyLength;
            suffixStartPoly = _pathPolyRefs[prefixPolyLength-1];
            if (dtStatusFailed(_navMeshQuery->closestPointOnPoly(suffixStartPoly, endPoint, suffixEndPoint, nullptr)))
            {
                // suffixStartPoly is still invalid, error state
                BuildShortcut();
                _type = PATHFIND_NOPATH;
                return;
            }
        }

        // generate suffix
        uint32 suffixPolyLength = 0;
        dtStatus dtResult;
        if (_straightLine)
        {
            float hit = 0;
            float hitNormal[3];
            memset(hitNormal, 0, sizeof(hitNormal));

            dtResult = _navMeshQuery->raycast(
                suffixStartPoly,
                suffixEndPoint,
                endPoint,
                &_filter,
                &hit,
                hitNormal,
                _pathPolyRefs + prefixPolyLength - 1,
                (int*)&suffixPolyLength,
                MAX_PATH_LENGTH - prefixPolyLength);

            // raycast() sets hit to FLT_MAX if there is a ray between start and end
            if (hit != FLT_MAX)
            {
                // the ray hit something, return no path instead of the incomplete one
                _type = PATHFIND_NOPATH;
                return;
            }
        }
        else
        {
            dtResult = _navMeshQuery->findPath(
                suffixStartPoly,    // start polygon
                endPoly,            // end polygon
                suffixEndPoint,     // start position
                endPoint,           // end position
                &_filter,            // polygon search filter
                _pathPolyRefs + prefixPolyLength - 1,    // [out] path
                (int*)&suffixPolyLength,
                MAX_PATH_LENGTH - prefixPolyLength);   // max number of polygons in output path
        }

        if (!suffixPolyLength || dtStatusFailed(dtResult))
        {
            // this is probably an error state, but we'll leave it
            // and hopefully recover on the next Update
            // we still need to copy our preffix
            TC_LOG_ERROR("maps", "%u's Path Build failed: 0 length path", _sourceUnit->GetGUIDLow());
        }

        TC_LOG_DEBUG("maps", "++  m_polyLength=%u prefixPolyLength=%u suffixPolyLength=%u \n", _polyLength, prefixPolyLength, suffixPolyLength);

        // new path = prefix + suffix - overlap
        _polyLength = prefixPolyLength + suffixPolyLength - 1;
    }
    else
    {
        TC_LOG_DEBUG("maps", "++ BuildPolyPath :: (!startPolyFound && !endPolyFound)\n");

        // either we have no path at all -> first run
        // or something went really wrong -> we aren't moving along the path to the target
        // just generate new path

        // free and invalidate old path data
        Clear();

        dtStatus dtResult;
        if (_straightLine)
        {
            float hit = 0;
            float hitNormal[3];
            memset(hitNormal, 0, sizeof(hitNormal));

            dtResult = _navMeshQuery->raycast(
                startPoly,
                startPoint,
                endPoint,
                &_filter,
                &hit,
                hitNormal,
                _pathPolyRefs,
                (int*)&_polyLength,
                MAX_PATH_LENGTH);

            // raycast() sets hit to FLT_MAX if there is a ray between start and end
            if (hit != FLT_MAX)
            {
                // the ray hit something, return no path instead of the incomplete one
                _type = PATHFIND_NOPATH;
                return;
            }
        }
        else
        {
            dtResult = _navMeshQuery->findPath(
                startPoly,          // start polygon
                endPoly,            // end polygon
                startPoint,         // start position
                endPoint,           // end position
                &_filter,           // polygon search filter
                _pathPolyRefs,     // [out] path
                (int*)&_polyLength,
                MAX_PATH_LENGTH);   // max number of polygons in output path
        }

        if (!_polyLength || dtStatusFailed(dtResult))
        {
            // only happens if we passed bad data to findPath(), or navmesh is messed up
            TC_LOG_ERROR("maps", "%u's Path Build failed: 0 length path", _sourceUnit->GetGUIDLow());
            BuildShortcut();
            _type = PATHFIND_NOPATH;
            return;
        }
    }

    // by now we know what type of path we can get
    if (_pathPolyRefs[_polyLength - 1] == endPoly && !(_type & PATHFIND_INCOMPLETE))
        _type = PATHFIND_NORMAL;
    else
        _type = PATHFIND_INCOMPLETE;

    // generate the point-path out of our up-to-date poly-path
    BuildPointPath(startPoint, endPoint);
}

void PathGenerator::BuildPointPath(const float *startPoint, const float *endPoint)
{
    float pathPoints[MAX_POINT_PATH_LENGTH*VERTEX_SIZE];
    uint32 pointCount = 0;
    dtStatus dtResult = DT_FAILURE;
    if (_straightLine)
    {
        dtResult = DT_SUCCESS;
        pointCount = 1;
        memcpy(&pathPoints[VERTEX_SIZE * 0], startPoint, sizeof(float) * 3); // first point

                                                                             // path has to be split into polygons with dist SMOOTH_PATH_STEP_SIZE between them
        G3D::Vector3 startVec = G3D::Vector3(startPoint[0], startPoint[1], startPoint[2]);
        G3D::Vector3 endVec = G3D::Vector3(endPoint[0], endPoint[1], endPoint[2]);
        G3D::Vector3 diffVec = (endVec - startVec);
        G3D::Vector3 prevVec = startVec;
        float len = diffVec.length();
        diffVec *= SMOOTH_PATH_STEP_SIZE / 2 / len;
        while (len > SMOOTH_PATH_STEP_SIZE / 2)
        {
            if (pointCount >= MAX_POINT_PATH_LENGTH)
            {
                BuildShortcut();
                _type = PATHFIND_SHORT;
                return;
            }

            len -= SMOOTH_PATH_STEP_SIZE / 2;
            prevVec += diffVec;
            pathPoints[VERTEX_SIZE * pointCount + 0] = prevVec.x;
            pathPoints[VERTEX_SIZE * pointCount + 1] = prevVec.y;
            pathPoints[VERTEX_SIZE * pointCount + 2] = prevVec.z;
            ++pointCount;
        }

        memcpy(&pathPoints[VERTEX_SIZE * pointCount], endPoint, sizeof(float) * 3); // last point
        ++pointCount;
    }
    else if (_useStraightPath)
    {
        dtResult = _navMeshQuery->findStraightPath(
                startPoint,         // start position
                endPoint,           // end position
                _pathPolyRefs,     // current path
                _polyLength,       // lenth of current path
                pathPoints,         // [out] path corner points
                NULL,               // [out] flags
                NULL,               // [out] shortened path
                (int*)&pointCount,
                _pointPathLimit);   // maximum number of points/polygons to use
    }
    else
    {
        dtResult = FindSmoothPath(
                startPoint,         // start position
                endPoint,           // end position
                _pathPolyRefs,     // current path
                _polyLength,       // length of current path
                pathPoints,         // [out] path corner points
                (int*)&pointCount,
                _pointPathLimit);    // maximum number of points
    }

    if (pointCount < 2 || dtStatusFailed(dtResult))
    {
        // only happens if pass bad data to findStraightPath or navmesh is broken
        // single point paths can be generated here
        /// @todo check the exact cases
        TC_LOG_DEBUG("maps", "++ PathGenerator::BuildPointPath FAILED! path sized %d returned\n", pointCount);
        BuildShortcut();
        _type = PATHFIND_NOPATH;
        return;
    }
    else if (pointCount == _pointPathLimit && !_straightLine) // _straightLine assumes the path is already of a valid length
    {
        TC_LOG_DEBUG("maps", "++ PathGenerator::BuildPointPath FAILED! path sized %d returned, lower than limit set to %d\n", pointCount, _pointPathLimit);
        BuildShortcut();
        _type = PATHFIND_SHORT;
        return;
    }

    _pathPoints.resize(pointCount);
    for (uint32 i = 0; i < pointCount; ++i)
        _pathPoints[i] = G3D::Vector3(pathPoints[i*VERTEX_SIZE+2], pathPoints[i*VERTEX_SIZE], pathPoints[i*VERTEX_SIZE+1]);

    NormalizePath(false);

    // first point is always our current location - we need the next one
    SetActualEndPosition(_pathPoints[pointCount-1]);

    // force the given destination, if needed
    if (_forceDestination &&
        (!(_type & PATHFIND_NORMAL) || !InRange(GetEndPosition(), GetActualEndPosition(), 1.0f, 1.0f)))
    {
        // we may want to keep partial subpath
        if (Dist3DSqr(GetActualEndPosition(), GetEndPosition()) < 0.3f * Dist3DSqr(GetStartPosition(), GetEndPosition()))
        {
            SetActualEndPosition(GetEndPosition());
            _pathPoints[_pathPoints.size()-1] = GetEndPosition();
        }
        else
        {
            SetActualEndPosition(GetEndPosition());
            BuildShortcut();
        }

        _type = PathType(PATHFIND_NORMAL | PATHFIND_NOT_USING_PATH);
    }

    TC_LOG_DEBUG("maps", "++ PathGenerator::BuildPointPath path type %d size %d poly-size %d\n", _type, pointCount, _polyLength);
}

void PathGenerator::NormalizePath(bool worldSpace)
{
    // VMAP is still working in world-space, so we need to transform coordinates to world-space and back
    //if (!worldSpace)
    //    if (Transport* transport = _sourceUnit->GetTransport())
    //        for (auto&& point : _pathPoints)
    //            transport->CalculatePassengerPosition(point.x, point.y, point.z);

    // Turns out WorldObject::UpdateAllowedPositionZ is skipped if object is on transport, and fixing that causes various new issues, so we might just as well skip path normalization entirely...
    if (_sourceUnit->GetTransGUID())
        return;

    for (uint32 i = 0; i < _pathPoints.size(); ++i)
        _sourceUnit->UpdateAllowedPositionZ(_pathPoints[i].x, _pathPoints[i].y, _pathPoints[i].z/*, std::max(_pathPoints[i ? i - 1 : i].z - _pathPoints[i].z, 0.0f)*/); // Offset z to be at least at the same height as the previous point (fixes charge on uneven terrain)

    //if (!worldSpace)
    //    if (Transport* transport = _sourceUnit->GetTransport())
    //        for (auto&& point : _pathPoints)
    //            transport->CalculatePassengerOffset(point.x, point.y, point.z);
}


void PathGenerator::BuildShortcut()
{
    TC_LOG_DEBUG("maps", "++ BuildShortcut :: making shortcut\n");

    Clear();

    // make two point path, our curr pos is the start, and dest is the end
    _pathPoints.resize(2);

    // set start and a default next position
    _pathPoints[0] = GetStartPosition();
    _pathPoints[1] = GetActualEndPosition();

    NormalizePath(false);

    _type = PATHFIND_SHORTCUT;
}

void PathGenerator::CreateFilter()
{
    uint16 includeFlags = 0;
    uint16 excludeFlags = 0;

    if (_sourceUnit->GetTypeId() == TYPEID_UNIT)
    {
        Creature* creature = (Creature*)_sourceUnit;
        if (creature->CanWalk())
            includeFlags |= NAV_GROUND;          // walk

        // creatures don't take environmental damage
        if (creature->CanSwim())
            includeFlags |= (NAV_WATER | NAV_MAGMA | NAV_SLIME);           // swim
    }
    else // assume Player
    {
        // perfect support not possible, just stay 'safe'
        includeFlags |= (NAV_GROUND | NAV_WATER | NAV_MAGMA | NAV_SLIME);
    }

    _filter.setIncludeFlags(includeFlags);
    _filter.setExcludeFlags(excludeFlags);

    UpdateFilter();
}

void PathGenerator::UpdateFilter()
{
    // allow creatures to cheat and use different movement types if they are moved
    // forcefully into terrain they can't normally move in
    if (_sourceUnit->IsInWater()/* || _sourceUnit->IsUnderWater()*/) // InWater already accounts for Underwater
    {
        uint16 includedFlags = _filter.getIncludeFlags();
        includedFlags |= GetNavTerrain(_sourceUnit->GetPositionX(),
                                       _sourceUnit->GetPositionY(),
                                       _sourceUnit->GetPositionZ());

        _filter.setIncludeFlags(includedFlags);
    }
}

NavTerrain PathGenerator::GetNavTerrain(float x, float y, float z)
{
    LiquidData data;
    ZLiquidStatus liquidStatus = _sourceUnit->GetBaseMap()->getLiquidStatus(x, y, z, MAP_ALL_LIQUIDS, &data);
    if (liquidStatus == LIQUID_MAP_NO_WATER)
        return NAV_GROUND;

    switch (data.type_flags)
    {
        case MAP_LIQUID_TYPE_WATER:
        case MAP_LIQUID_TYPE_OCEAN:
            return NAV_WATER;
        case MAP_LIQUID_TYPE_MAGMA:
            return NAV_MAGMA;
        case MAP_LIQUID_TYPE_SLIME:
            return NAV_SLIME;
        default:
            return NAV_GROUND;
    }
}

bool PathGenerator::HaveTile(const G3D::Vector3& p) const
{
    int tx = -1, ty = -1;
    float point[VERTEX_SIZE] = {p.y, p.z, p.x};

    _navMesh->calcTileLoc(point, &tx, &ty);

    /// Workaround
    /// For some reason, often the tx and ty variables wont get a valid value
    /// Use this check to prevent getting negative tile coords and crashing on getTileAt
    if (tx < 0 || ty < 0)
        return false;

    return (_navMesh->getTileAt(tx, ty, 0) != NULL);
}

uint32 PathGenerator::FixupCorridor(dtPolyRef* path, uint32 npath, uint32 maxPath, dtPolyRef const* visited, uint32 nvisited)
{
    int32 furthestPath = -1;
    int32 furthestVisited = -1;

    // Find furthest common polygon.
    for (int32 i = npath-1; i >= 0; --i)
    {
        bool found = false;
        for (int32 j = nvisited-1; j >= 0; --j)
        {
            if (path[i] == visited[j])
            {
                furthestPath = i;
                furthestVisited = j;
                found = true;
            }
        }
        if (found)
            break;
    }

    // If no intersection found just return current path.
    if (furthestPath == -1 || furthestVisited == -1)
        return npath;

    // Concatenate paths.

    // Adjust beginning of the buffer to include the visited.
    uint32 req = nvisited - furthestVisited;
    uint32 orig = uint32(furthestPath + 1) < npath ? furthestPath + 1 : npath;
    uint32 size = npath > orig ? npath - orig : 0;
    if (req + size > maxPath)
        size = maxPath-req;

    if (size)
        memmove(path + req, path + orig, size * sizeof(dtPolyRef));

    // Store visited
    for (uint32 i = 0; i < req; ++i)
        path[i] = visited[(nvisited - 1) - i];

    return req+size;
}

// This function checks if the path has a small U-turn, that is,
// a polygon further in the path is adjacent to the first polygon
// in the path. If that happens, a shortcut is taken.
// This can happen if the target (T) location is at tile boundary,
// and we're (S) approaching it parallel to the tile edge.
// The choice at the vertex can be arbitrary, 
//  +---+---+
//  |:::|:::|
//  +-S-+-T-+
//  |:::|   | <-- the step can end up in here, resulting U-turn path.
//  +---+---+
uint32 PathGenerator::FixupShortcuts(dtPolyRef* path, int npath)
{
    if (npath < 3)
        return npath;

    // Get connected polygons
    static const int maxNeis = 16;
    dtPolyRef neis[maxNeis];
    int nneis = 0;

    const dtMeshTile* tile = 0;
    const dtPoly* poly = 0;
    if (dtStatusFailed(_navMeshQuery->getAttachedNavMesh()->getTileAndPolyByRef(path[0], &tile, &poly)))
        return npath;

    for (unsigned int k = poly->firstLink; k != DT_NULL_LINK; k = tile->links[k].next)
    {
        const dtLink* link = &tile->links[k];
        if (link->ref != 0)
        {
            if (nneis < maxNeis)
                neis[nneis++] = link->ref;
        }
    }

    // If any of the neighbour polygons is within the next few polygons
    // in the path, short cut to that polygon directly.
    static const int maxLookAhead = 6;
    int cut = 0;
    for (int i = dtMin(maxLookAhead, npath) - 1; i > 1 && cut == 0; i--) {
        for (int j = 0; j < nneis; j++)
        {
            if (path[i] == neis[j]) {
                cut = i;
                break;
            }
        }
    }
    if (cut > 1)
    {
        int offset = cut - 1;
        npath -= offset;
        for (int i = 1; i < npath; i++)
            path[i] = path[i + offset];
    }

    return npath;
}

bool PathGenerator::GetSteerTarget(float const* startPos, float const* endPos,
                              float minTargetDist, dtPolyRef const* path, uint32 pathSize,
                              float* steerPos, unsigned char& steerPosFlag, dtPolyRef& steerPosRef)
{
    // Find steer target.
    static const uint32 MAX_STEER_POINTS = 3;
    float steerPath[MAX_STEER_POINTS*VERTEX_SIZE];
    unsigned char steerPathFlags[MAX_STEER_POINTS];
    dtPolyRef steerPathPolys[MAX_STEER_POINTS];
    uint32 nsteerPath = 0;
    dtStatus dtResult = _navMeshQuery->findStraightPath(startPos, endPos, path, pathSize,
                                                steerPath, steerPathFlags, steerPathPolys, (int*)&nsteerPath, MAX_STEER_POINTS);
    if (!nsteerPath || dtStatusFailed(dtResult))
        return false;

    // Find vertex far enough to steer to.
    uint32 ns = 0;
    while (ns < nsteerPath)
    {
        // Stop at Off-Mesh link or when point is further than slop away.
        if ((steerPathFlags[ns] & DT_STRAIGHTPATH_OFFMESH_CONNECTION) ||
            !InRangeYZX(&steerPath[ns*VERTEX_SIZE], startPos, minTargetDist, 1000.0f))
            break;
        ns++;
    }
    // Failed to find good point to steer to.
    if (ns >= nsteerPath)
        return false;

    dtVcopy(steerPos, &steerPath[ns*VERTEX_SIZE]);
    steerPos[1] = startPos[1];  // keep Z value
    steerPosFlag = steerPathFlags[ns];
    steerPosRef = steerPathPolys[ns];

    return true;
}

dtStatus PathGenerator::FindSmoothPath(float const* startPos, float const* endPos,
                                     dtPolyRef const* polyPath, uint32 polyPathSize,
                                     float* smoothPath, int* smoothPathSize, uint32 maxSmoothPathSize)
{
    *smoothPathSize = 0;
    uint32 nsmoothPath = 0;

    dtPolyRef polys[MAX_PATH_LENGTH];
    memcpy(polys, polyPath, sizeof(dtPolyRef)*polyPathSize);
    uint32 npolys = polyPathSize;

    float iterPos[VERTEX_SIZE], targetPos[VERTEX_SIZE];
    if (dtStatusFailed(_navMeshQuery->closestPointOnPoly(polys[0], startPos, iterPos, NULL)))
        return DT_FAILURE;

    if (dtStatusFailed(_navMeshQuery->closestPointOnPoly(polys[npolys - 1], endPos, targetPos, NULL)))
        return DT_FAILURE;

    dtVcopy(&smoothPath[nsmoothPath*VERTEX_SIZE], iterPos);
    nsmoothPath++;

    // Move towards target a small advancement at a time until target reached or
    // when ran out of memory to store the path.
    while (npolys && nsmoothPath < maxSmoothPathSize)
    {
        // Find location to steer towards.
        float steerPos[VERTEX_SIZE];
        unsigned char steerPosFlag;
        dtPolyRef steerPosRef = INVALID_POLYREF;

        if (!GetSteerTarget(iterPos, targetPos, SMOOTH_PATH_SLOP, polys, npolys, steerPos, steerPosFlag, steerPosRef))
            break;

        bool endOfPath = (steerPosFlag & DT_STRAIGHTPATH_END);
        bool offMeshConnection = (steerPosFlag & DT_STRAIGHTPATH_OFFMESH_CONNECTION);

        // Find movement delta.
        float delta[VERTEX_SIZE];
        dtVsub(delta, steerPos, iterPos);
        float len = dtMathSqrtf(dtVdot(delta, delta));
        // If the steer target is end of path or off-mesh link, do not move past the location.
        if ((endOfPath || offMeshConnection) && len < SMOOTH_PATH_STEP_SIZE)
            len = 1.0f;
        else
            len = SMOOTH_PATH_STEP_SIZE / len;

        float moveTgt[VERTEX_SIZE];
        dtVmad(moveTgt, iterPos, delta, len);

        // Move
        float result[VERTEX_SIZE];
        const static uint32 MAX_VISIT_POLY = 16;
        dtPolyRef visited[MAX_VISIT_POLY];

        uint32 nvisited = 0;
        _navMeshQuery->moveAlongSurface(polys[0], iterPos, moveTgt, &_filter, result, visited, (int*)&nvisited, MAX_VISIT_POLY);
        npolys = FixupCorridor(polys, npolys, MAX_PATH_LENGTH, visited, nvisited);
        npolys = FixupShortcuts(polys, npolys);

        _navMeshQuery->getPolyHeight(polys[0], result, &result[1]);
        result[1] += 0.5f;
        dtVcopy(iterPos, result);

        // Handle end of path and off-mesh links when close enough.
        if (endOfPath && InRangeYZX(iterPos, steerPos, SMOOTH_PATH_SLOP, 1.0f))
        {
            // Reached end of path.
            dtVcopy(iterPos, targetPos);
            if (nsmoothPath < maxSmoothPathSize)
            {
                dtVcopy(&smoothPath[nsmoothPath*VERTEX_SIZE], iterPos);
                nsmoothPath++;
            }
            break;
        }
        else if (offMeshConnection && InRangeYZX(iterPos, steerPos, SMOOTH_PATH_SLOP, 1.0f))
        {
            // Advance the path up to and over the off-mesh connection.
            dtPolyRef prevRef = INVALID_POLYREF;
            dtPolyRef polyRef = polys[0];
            uint32 npos = 0;
            while (npos < npolys && polyRef != steerPosRef)
            {
                prevRef = polyRef;
                polyRef = polys[npos];
                npos++;
            }

            for (uint32 i = npos; i < npolys; ++i)
                polys[i-npos] = polys[i];

            npolys -= npos;

            // Handle the connection.
            float startPos[VERTEX_SIZE], endPos[VERTEX_SIZE];
            if (dtStatusSucceed(_navMesh->getOffMeshConnectionPolyEndPoints(prevRef, polyRef, startPos, endPos)))
            {
                if (nsmoothPath < maxSmoothPathSize)
                {
                    dtVcopy(&smoothPath[nsmoothPath*VERTEX_SIZE], startPos);
                    nsmoothPath++;
                }
                // Move position at the other side of the off-mesh link.
                dtVcopy(iterPos, endPos);
                _navMeshQuery->getPolyHeight(polys[0], iterPos, &iterPos[1]);
                iterPos[1] += 0.5f;
            }
        }

        // Store results.
        if (nsmoothPath < maxSmoothPathSize)
        {
            dtVcopy(&smoothPath[nsmoothPath*VERTEX_SIZE], iterPos);
            nsmoothPath++;
        }
    }

    *smoothPathSize = nsmoothPath;

    // this is most likely a loop
    return nsmoothPath < MAX_POINT_PATH_LENGTH ? DT_SUCCESS : DT_FAILURE;
}

bool PathGenerator::InRangeYZX(const float* v1, const float* v2, float r, float h) const
{
    const float dx = v2[0] - v1[0];
    const float dy = v2[1] - v1[1]; // elevation
    const float dz = v2[2] - v1[2];
    return (dx * dx + dz * dz) < r * r && fabsf(dy) < h;
}

bool PathGenerator::InRange(G3D::Vector3 const& p1, G3D::Vector3 const& p2, float r, float h) const
{
    G3D::Vector3 d = p1 - p2;
    return (d.x * d.x + d.y * d.y) < r * r && fabsf(d.z) < h;
}

float PathGenerator::Dist3DSqr(G3D::Vector3 const& p1, G3D::Vector3 const& p2) const
{
    return (p1 - p2).squaredLength();
}

void PathGenerator::ReducePathLenghtByDist(float dist)
{
    if (GetPathType() == PATHFIND_BLANK)
    {
        TC_LOG_DEBUG("maps", "PathGenerator::ReducePathLenghtByDist called before path was built");
        return;
    }

    if (_pathPoints.size() < 2) // path building failure
        return;

    uint32 i = _pathPoints.size();
    G3D::Vector3 nextVec = _pathPoints[--i];
    while (i > 0)
    {
        G3D::Vector3 currVec = _pathPoints[--i];
        G3D::Vector3 diffVec = (nextVec - currVec);
        float len = diffVec.length();
        if (len > dist)
        {
            float step = dist / len;
            // same as nextVec
            _pathPoints[i + 1] -= diffVec * step;
            _pathPoints.resize(i + 2);
            break;
        }
        else if (i == 0) // at second point
        {
            _pathPoints[1] = _pathPoints[0];
            _pathPoints.resize(2);
            break;
        }

        dist -= len;
        nextVec = currVec; // we're going backwards
    }

    NormalizePath(true);
}

void PathGenerator::UpdateNavMesh()
{
    uint64 guid = 0;

    uint32 mapId = _sourceUnit->GetMapId();
    if (Transport* transport = _sourceUnit->GetTransport())
    {
        guid = transport->GetGUID();
        if (transport->GetGoType() == GAMEOBJECT_TYPE_TRANSPORT)
            ASSERT(_sourceUnit->HasUnitState(UNIT_STATE_IGNORE_PATHFINDING));
        else if (uint32 transportMapID = transport->GetGOInfo()->moTransport.mapID)
            mapId = transportMapID;
    }

    if (_transportGUID == guid)
        return;

    _transportGUID = guid;

    uint32 zoneId, areaId;
    _sourceUnit->GetZoneAndAreaId(zoneId, areaId);
    if (MMAP::MMapFactory::IsPathfindingEnabled(mapId, zoneId, areaId, _sourceUnit->GetEntry()))
    {
        MMAP::MMapManager* mmap = MMAP::MMapFactory::createOrGetMMapManager();
        _navMesh = mmap->GetNavMesh(mapId);
        _navMeshQuery = mmap->GetNavMeshQuery(mapId, _sourceUnit->GetInstanceId());
    }
}

float PathGenerator::GetLinearPathLength() const
{
    if (_pathPoints.size() < 2)
        return 0.0f;

    float length = 0.0f;

    auto prev = _pathPoints.begin();
    auto next = _pathPoints.begin() + 1;
    for (; next != _pathPoints.end(); prev = next, ++next)
        length += (*next - *prev).length();

    return length;
}

void PathGenerator::VisualizePath(uint32 duration)
{
    static auto const DespawnWaypoint = [](Unit const* source, uint64& guid)
    {
        if (Creature* waypoint = ObjectAccessor::GetCreature(*source, guid))
        {
            waypoint->SetUInt32Value(UNIT_FIELD_CHANNEL_SPELL, 0);
            waypoint->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
            waypoint->SetDisplayId(11686);
            waypoint->DespawnOrUnsummon(500);
        }
        guid = 0;
    };
    static auto const SpawnWaypoint = [](Unit const* source, uint64 prevGUID, G3D::Vector3 const& pos, uint32 duration) -> uint64
    {
        if (TempSummon* waypoint = new TempSummon(nullptr, nullptr, false))
        {
            if (!waypoint->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_UNIT), source->GetMap(), source->GetPhaseMask(), 190012, 0, 0, pos.x, pos.y, pos.z, 0))
            {
                delete waypoint;
                return 0;
            }

            waypoint->SetHomePosition(waypoint->GetPosition());
            waypoint->InitStats(duration);
            waypoint->SetDisableGravity(true);
            waypoint->SetFlag(UNIT_FIELD_FLAGS2, UNIT_FLAG2_INSTANTLY_APPEAR_MODEL);
            if (prevGUID)
            {
                waypoint->SetUInt32Value(UNIT_FIELD_CHANNEL_SPELL, 54491);
                waypoint->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, prevGUID);
            }
            source->GetMap()->AddToMap(waypoint->ToCreature());
            waypoint->InitSummon();
            waypoint->SetTempSummonType(TEMPSUMMON_TIMED_DESPAWN);
            return waypoint->GetGUID();
        }
        return 0;
    };
    static auto const UpdateWaypoint = [](Unit const* source, uint64 prevGUID, G3D::Vector3 const& pos, uint32 duration, uint64& guid)
    {
        if (Creature* waypoint = ObjectAccessor::GetCreature(*source, guid))
        {
            waypoint->ToTempSummon()->InitStats(duration);
            waypoint->NearTeleportTo(pos.x, pos.y, pos.z, waypoint->GetOrientation());
        }
        else
            guid = SpawnWaypoint(source, prevGUID, pos, duration);
    };

    if (!visualizePathWaypointGUIDs)
        visualizePathWaypointGUIDs = new std::vector<uint64>();

    if (visualizePathMap != _sourceUnit->GetMap())
        visualizePathWaypointGUIDs->clear();

    visualizePathWaypointGUIDs->resize(MAX_PATH_LENGTH);

    visualizePathMap = _sourceUnit->GetMap();

    for (uint32 i = 0; i < MAX_PATH_LENGTH; ++i)
    {
        if (i < GetPath().size())
            UpdateWaypoint(_sourceUnit, i ? (*visualizePathWaypointGUIDs)[i - 1] : (uint64)0, GetPath()[i], duration, (*visualizePathWaypointGUIDs)[i]);
        else
            DespawnWaypoint(_sourceUnit, (*visualizePathWaypointGUIDs)[i]);
    }
}

void PathGenerator::VisualizeNavmesh(uint32 duration)
{
    static auto const DespawnWaypoint = [](Unit const* source, uint64& guid)
    {
        if (Creature* waypoint = ObjectAccessor::GetCreature(*source, guid))
        {
            waypoint->SetUInt32Value(UNIT_FIELD_CHANNEL_SPELL, 0);
            waypoint->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, 0);
            waypoint->SetDisplayId(11686);
            waypoint->DespawnOrUnsummon(500);
        }
        guid = 0;
    };
    static auto const SpawnWaypoint = [](Unit const* source, uint64 prevGUID, G3D::Vector3 const& pos, uint32 duration) -> uint64
    {
        if (TempSummon* waypoint = new TempSummon(nullptr, nullptr, false))
        {
            G3D::Vector3 wpos{ pos };
            if (Transport* transport = source->GetTransport())
                transport->CalculatePassengerPosition(wpos.x, wpos.y, wpos.z);
            if (!waypoint->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_UNIT), source->GetMap(), source->GetPhaseMask(), 190012, 0, 0, wpos.x, wpos.y, wpos.z, 0))
            {
                delete waypoint;
                return 0;
            }

            waypoint->SetHomePosition(waypoint->GetPosition());
            waypoint->InitStats(duration);
            waypoint->SetDisableGravity(true);
            waypoint->SetFlag(UNIT_FIELD_FLAGS2, UNIT_FLAG2_INSTANTLY_APPEAR_MODEL);
            if (prevGUID)
            {
                waypoint->SetUInt32Value(UNIT_FIELD_CHANNEL_SPELL, 56223);
                waypoint->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, prevGUID);
            }
            waypoint->SetObjectScale(1);
            source->GetMap()->AddToMap(waypoint->ToCreature());
            waypoint->InitSummon();
            waypoint->SetTempSummonType(TEMPSUMMON_TIMED_DESPAWN);
            return waypoint->GetGUID();
        }
        return 0;
    };
    static auto const UpdateWaypoint = [](Unit const* source, uint64 prevGUID, G3D::Vector3 const& pos, uint32 duration, uint64& guid)
    {
        if (Creature* waypoint = ObjectAccessor::GetCreature(*source, guid))
        {
            waypoint->ToTempSummon()->InitStats(duration);
            G3D::Vector3 wpos{ pos };
            if (Transport* transport = source->GetTransport())
                transport->CalculatePassengerPosition(wpos.x, wpos.y, wpos.z);
            waypoint->NearTeleportTo(wpos.x, wpos.y, wpos.z, waypoint->GetOrientation());
            if (prevGUID)
            {
                waypoint->SetUInt32Value(UNIT_FIELD_CHANNEL_SPELL, 56223);
                waypoint->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, prevGUID);
            }
        }
        else
            guid = SpawnWaypoint(source, prevGUID, pos, duration);
    };

    if (!visualizeNavmeshWaypointGUIDs)
        visualizeNavmeshWaypointGUIDs = new std::vector<uint64>();

    if (visualizePathMap != _sourceUnit->GetMap())
        visualizeNavmeshWaypointGUIDs->clear();

    visualizeNavmeshWaypointGUIDs->resize(MAX_PATH_LENGTH * (DT_VERTS_PER_POLYGON + 1));

    visualizePathMap = _sourceUnit->GetMap();

    auto at = [this](uint32 polygon, uint32 vertex) -> uint64& { return (*visualizeNavmeshWaypointGUIDs)[polygon * (DT_VERTS_PER_POLYGON + 1) + vertex]; };
    auto vec = [this](float* verts, uint32 count, uint32 index) -> G3D::Vector3 { return G3D::Vector3{ verts[(index * 3 + 2) % (count * 3)], verts[(index * 3 + 0) % (count * 3)], verts[(index * 3 + 1) % (count * 3)] }; };

    for (uint32 i = 0; i < MAX_PATH_LENGTH; ++i)
    {
        auto&& ref = _pathPolyRefs[i];
        dtMeshTile const* tile;
        dtPoly const* poly;
        if (i < _polyLength && ref && dtStatusSucceed(_navMesh->getTileAndPolyByRef(ref, &tile, &poly)))
        {
            float verts[DT_VERTS_PER_POLYGON * 3];
            for (int j = 0; j < (int)poly->vertCount; ++j)
                dtVcopy(&verts[j * 3], &tile->verts[poly->verts[j] * 3]);

            for (uint32 j = 0; j <= poly->vertCount; ++j)
                UpdateWaypoint(_sourceUnit, j ? at(i, j - 1) : (uint64)0, vec(verts, poly->vertCount, j), duration, at(i, j));

            for (uint32 j = poly->vertCount + 1; j <= DT_VERTS_PER_POLYGON; ++j)
                DespawnWaypoint(_sourceUnit, at(i, j));
        }
        else
        {
            for (uint32 j = 0; j <= DT_VERTS_PER_POLYGON; ++j)
                DespawnWaypoint(_sourceUnit, at(i, j));
        }
    }
}
