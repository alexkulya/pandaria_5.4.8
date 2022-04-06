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

#include "ScriptMgr.h"
#include "GridNotifiersImpl.h"
#include "DatabaseEnv.h"
#include "Chat.h"

#define GetText(a, b, c) a->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU ? b : c

namespace BattlePay
{
    enum Type:int64
    {
        Coins_1                             = 10000,
        Coins_2                             = 20000,
        Coins_5                             = 50000,
        Coins_10                            = 100000
    };
}

template<int64 Coins>
class battle_pay_token : public ItemScript
{
public:
    battle_pay_token(const char *ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (!sWorld->getBoolConfig(CONFIG_WOW_TOKEN))
        {
            player->GetSession()->SendNotification(GetText(player, "Жетоны отключены.", "Coins disabled."));
            player->CastSpell(player, 27880, true);
        }
        else
        {
            if (player->HasItemCount(item->GetEntry(), 1, true))
            {
                player->AddDonateTokenCount(Coins);
                player->DestroyItemCount(item->GetEntry(), 1, true);

                std::ostringstream coins_amount_message_ru, coins_amount_message_en;
                coins_amount_message_ru << "Спасибо за помощь проекту Pandaria 5.4.8, вы только что получили очков пожертвования: " << Coins/10000;
                coins_amount_message_en << "Thanks for helping the Pandaria 5.4.8 project, you just received donate coins: " << Coins/10000;
                ChatHandler(player->GetSession()).SendSysMessage(GetText(player, coins_amount_message_ru.str().c_str(), coins_amount_message_en.str().c_str()));
                player->SaveToDB();
            }
            else
            {
                ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "У вас нет необходимого жетона.", "You do not have the necessary token."));
            }
        }
        return true;
    }
};

void AddSC_wow_token()
{
    new battle_pay_token<BattlePay::Coins_1>("wow_token_1");
    new battle_pay_token<BattlePay::Coins_2>("wow_token_2");
    new battle_pay_token<BattlePay::Coins_5>("wow_token_5");
    new battle_pay_token<BattlePay::Coins_10>("wow_token_10");
}
