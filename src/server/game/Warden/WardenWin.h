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

#ifndef SF_WARDEN_WIN_H
#define SF_WARDEN_WIN_H

#include <map>
#include "Cryptography/ARC4.h"
#include "Cryptography/BigNumber.h"
#include "ByteBuffer.h"
#include "Warden.h"

class WorldSession;

class WardenWin : public Warden
{
    enum class State
    {
        Normal,
        EndSceneRequestStep1,
        EndSceneRequestStep2,
        EndSceneRequestStep3,
        EndSceneRequestStep4,
    };

    public:
        WardenWin();
        ~WardenWin();

        void Init(WorldSession* session, BigNumber* K);
        void RequestHash();
        void HandleHashResult(ByteBuffer &buff);
        void RequestData(WardenRequestContext* context = NULL);
        void HandleData(ByteBuffer &buff);

        void Disable() override;

        bool GetEndSceneAddress(int32& addr);
        void DoCustomMemCheck(uint32 addr, uint32 len, uint64 guid = 0);
        void HandleEndSceneResult(ByteBuffer& buff, WardenCheck* check);
        void ContinueCheck();

    private:
        uint32 _serverTicks;
        std::list<uint16> _otherChecksTodo;
        std::list<uint16> _memChecksTodo;
        std::list<std::pair<WardenCheck, WardenCheckResult>> _currentChecks;

        State _state = State::Normal;
        bool _endSceneCaptured = false;
        int32 _endSceneAddress = 0;
};

#endif
