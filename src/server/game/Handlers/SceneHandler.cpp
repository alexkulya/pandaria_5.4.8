/*
* Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "Common.h"
#include "WorldSession.h"
#include "Player.h"

void WorldSession::HandleSceneTriggerEvent(WorldPacket& recvData)
{
    recvData.ReadBit();
    uint32 len = recvData.ReadBits(6);
    std::string event = recvData.ReadString(len);
    uint32 sceneInstanceID = recvData.read<uint32>();
    GetPlayer()->GetSceneMgr().OnSceneTrigger(sceneInstanceID, event);
}

void WorldSession::HandleScenePlaybackComplete(WorldPacket& recvData)
{
    uint32 sceneInstanceID = 0;
    if (!recvData.ReadBit())
        recvData >> sceneInstanceID;
    GetPlayer()->GetSceneMgr().OnSceneComplete(sceneInstanceID);
}

void WorldSession::HandleScenePlaybackCanceled(WorldPacket& recvData)
{
    uint32 sceneInstanceID = 0;
    if (!recvData.ReadBit())
        recvData >> sceneInstanceID;
    GetPlayer()->GetSceneMgr().OnSceneCancel(sceneInstanceID);
}
