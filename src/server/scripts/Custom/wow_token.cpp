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
#include "DatabaseEnv.h" // borrar si no necesitas base de datos
#include "Chat.h"

enum coins
{
    coins_1 = 10000,
    coins_2 = 20000,
    coins_5 = 50000,
    coins_10 = 100000,
};

class wow_token_1 : public ItemScript
{
public:
    wow_token_1() : ItemScript("wow_token_1") {}

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground()) //Item is not usable in combat, arenas and battlegrounds. This can be modified to your taste.
        {
            player->GetSession()->SendNotification("You may not use this token whilst you are in combat or present in an arena or battleground.");
        }
        else if (!sWorld->getBoolConfig(CONFIG_WOW_TOKEN))
        {
            player->GetSession()->SendNotification("Coins disabled.");
            player->CastSpell(player, 27880, true);
        }
        else
        {
            if(player->HasItemCount(item->GetEntry(), 1, true)) //verify that the characters have the item
            {
                // add and log the wow token
                player->AddDonateTokenCount(coins_1);
                ChatHandler(player->GetSession()).PSendSysMessage("Thanks for helping the WoW project, you just received %i Coins.", (coins_1 / 10000));

                //Item is destroyed on useage.
                player->DestroyItemCount(item->GetEntry(), 1, true);

                //save pj
                player->SaveToDB();
            }
            else
            {
                ChatHandler(player->GetSession()).PSendSysMessage("You do not have the necessary token.");
            }          
        }
        return true;
    }
};

class wow_token_2 : public ItemScript
{
public:
    wow_token_2() : ItemScript("wow_token_2") {}

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground()) //Item is not usable in combat, arenas and battlegrounds. This can be modified to your taste.
        {
            player->GetSession()->SendNotification("You may not use this token whilst you are in combat or present in an arena or battleground.");
        }
        else if (!sWorld->getBoolConfig(CONFIG_WOW_TOKEN))
        {
            player->GetSession()->SendNotification("Coins disabled.");
            player->CastSpell(player, 27880, true);
        }
        else
        {
            if(player->HasItemCount(item->GetEntry(), 1, true)) //verify that the characters have the item
            {
                // add and log the wow token
                player->AddDonateTokenCount(coins_2);
                ChatHandler(player->GetSession()).PSendSysMessage("Thanks for helping the WoW project, you just received %i Coins.", (coins_2 / 10000));

                //Item is destroyed on useage.
                player->DestroyItemCount(item->GetEntry(), 1, true);

                //save pj
                player->SaveToDB();
            }
            else
            {
                ChatHandler(player->GetSession()).PSendSysMessage("You do not have the necessary token.");
            }
        }
        return true;
    }
};

class wow_token_5 : public ItemScript
{
public:
    wow_token_5() : ItemScript("wow_token_5") {}

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground()) //Item is not usable in combat, arenas and battlegrounds. This can be modified to your taste.
        {
            player->GetSession()->SendNotification("You may not use this token whilst you are in combat or present in an arena or battleground.");
        }
        else if (!sWorld->getBoolConfig(CONFIG_WOW_TOKEN))
        {
            player->GetSession()->SendNotification("Coins disabled.");
            player->CastSpell(player, 27880, true);
        }
        else
        {
            if(player->HasItemCount(item->GetEntry(), 1, true)) //verify that the characters have the item
            {
                // add and log the wow token
                player->AddDonateTokenCount(coins_5);
                ChatHandler(player->GetSession()).PSendSysMessage("Thanks for helping the WoW project, you just received %i Coins.", (coins_5 / 10000));

                //Item is destroyed on useage.
                player->DestroyItemCount(item->GetEntry(), 1, true);

                //save pj
                player->SaveToDB();
            }
            else
            {
                ChatHandler(player->GetSession()).PSendSysMessage("You do not have the necessary token.");
            }
        }
        return true;
    }
};

class wow_token_10 : public ItemScript
{
public:
    wow_token_10() : ItemScript("wow_token_10") {}

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground()) //Item is not usable in combat, arenas and battlegrounds. This can be modified to your taste.
        {
            player->GetSession()->SendNotification("You may not use this token whilst you are in combat or present in an arena or battleground.");
        }
        else if (!sWorld->getBoolConfig(CONFIG_WOW_TOKEN))
        {
            player->GetSession()->SendNotification("Coins disabled.");
            player->CastSpell(player, 27880, true);
        }
        else
        {
            if(player->HasItemCount(item->GetEntry(), 1, true)) //verify that the characters have the item
            {
                // add and log the wow token
                player->AddDonateTokenCount(coins_10);
                ChatHandler(player->GetSession()).PSendSysMessage("Thanks for helping the WoW project, you just received %i Coins.", (coins_10 / 10000));

                //Item is destroyed on useage.
                player->DestroyItemCount(item->GetEntry(), 1, true);

                //save pj
                player->SaveToDB();
            }
            else
            {
                ChatHandler(player->GetSession()).PSendSysMessage("You do not have the necessary token.");
            }
        }
        return true;
    }
};

void AddSC_wow_token() // Add to scriptloader normally
{
    new wow_token_1();
    new wow_token_2();
    new wow_token_5();
    new wow_token_10();
}
