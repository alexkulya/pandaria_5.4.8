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

#include "Define.h"
#include "GossipDef.h"
#include "Player.h"
#include "ScriptedGossip.h"
#include "ScriptMgr.h"

#define MENU_ID 123 // Our menuID used to match the sent menu to select hook (playerscript)

class example_PlayerGossip : public PlayerScript
{
public: 
    example_PlayerGossip() : PlayerScript("example_PlayerGossip") {}

    void OnLevelChanged(Player* player, uint8 /*oldlevel*/) override            // Any hook here
    {
        player->PlayerTalkClass->ClearMenus();// Clears old options
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Morph", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Demorph", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                                                                            // SetMenuId must be after clear menu and before send menu!!
        player->PlayerTalkClass->GetGossipMenu().SetMenuId(MENU_ID);        // Sets menu ID so we can identify our menu in Select hook. Needs unique number for the menu
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, player->GetGUID());
    }

    void OnGossipSelect(Player* player, uint32 menu_id, uint32 /*sender*/, uint32 action) override
    {
        if (menu_id != MENU_ID) // Not the menu coded here? stop.
            return;
        player->PlayerTalkClass->ClearMenus();

        switch(action)
        {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->SetDisplayId(999);
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->DeMorph();
            break;
        }
        player->CLOSE_GOSSIP_MENU();
    }
};

void AddSC_example_PlayerGossip() // Add to scriptloader normally
{
    new example_PlayerGossip();
}