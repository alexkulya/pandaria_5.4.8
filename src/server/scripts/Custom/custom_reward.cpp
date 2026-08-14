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
#include "Player.h"

#define GetText(a, b, c) a->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU ? b : c

#define ptr_Announce_Msg_RU "|cff00FF00[Сообщение системы]:|r\n  Вам начислены бонусы за проведенное на сервере игровое время: |cffFF009E%s|r"
#define ptr_Announce_Msg_EN "|cff00FF00[System message]:|r\n  You have been awarded bonuses for the playing time spent on the server: |cffFF009E%s|r"

#define ptr_Enabled sWorld->getBoolConfig(CONFIG_PLAYED_TIME_REWARD_ENABLED)
#define ptr_Update_Interval sWorld->getIntConfig(CONFIG_PLAYED_TIME_REWARD_INTERVAL)
#define ptr_Bonuses_Count sWorld->getIntConfig(CONFIG_PLAYED_TIME_REWARD_BONUSES_COUNT)

class played_time_reward : public PlayerScript
{
public:
    played_time_reward() : PlayerScript("played_time_reward") { }

    uint32 timeInterval = 0;

    void OnUpdate(Player* player, uint32 diff)
    {
        timeInterval += diff;

        if (timeInterval >= player->ptr_Interval)
        {
            timeInterval -= player->ptr_Interval;

            if (player->IsInWorld() && ptr_Enabled)
            {
                PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_BATTLEPAY_INCREMENT_DONATE_POINTS);
                stmt->setUInt32(0, ptr_Bonuses_Count * 1000);
                stmt->setUInt32(1, player->GetSession()->GetAccountId());
                LoginDatabase.Query(stmt);
                ChatHandler(player->GetSession()).PSendSysMessage(GetText(player, ptr_Announce_Msg_RU, ptr_Announce_Msg_EN), secsToTimeString(uint64(ptr_Update_Interval)).c_str());
            }
        }
    }
};

void AddSC_custom_reward()
{
    new played_time_reward();
}
