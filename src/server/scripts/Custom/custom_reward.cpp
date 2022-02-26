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

#include "Chat.h"
#include "Config.h"

class Played_Time_Reward : public PlayerScript
{
public:
    Played_Time_Reward() : PlayerScript("Played_Time_Reward") { }
    uint32 timeInterval = 0;

    void OnUpdate(Player* player, uint32 diff)
    {
        timeInterval += diff;

        if (timeInterval >= player->ptr_Interval)
        {
            timeInterval -= player->ptr_Interval;

            if (player->IsInWorld() && sWorld->getBoolConfig(CONFIG_BONUS_TIME_REWARD))
            {
                ChatHandler(player->GetSession()).PSendSysMessage("Bonus for played time.");

                PreparedStatement* stmt = FusionCMSDatabase.GetPreparedStatement(FUSION_UPD_BATTLEPAY_VP_COINS);
                stmt->setUInt32(0, sConfigMgr->GetIntDefault("PlayedTimeReward.vp", 0));
                stmt->setUInt32(1, player->GetSession()->GetAccountId());
                FusionCMSDatabase.Query(stmt);                
            }
        }
    }
};

void AddSC_custom_reward()
{
	new Played_Time_Reward();
}
