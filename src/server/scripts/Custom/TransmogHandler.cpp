///////////////////////////////
//**** Created By EroniX ****//
///////////////////////////////
//
// #Files: - TransmogHandler.cpp
//
//		   - TransmogEngine.cpp 
//		   - TransmogEngine.h
//
//		   - TransmogMgr.cpp
//		   - TransmogMgr.h
//
//
// #Core Mods: - Player.cpp:
//					- #include "TransmogEngine.h"
//					- EquipItem: 
//						- TransmogEngine::SetTransmogDisplay(this, slot);
//
//				    - RemoveItem: 
//						- TransmogEngine::RemoveTransmog(this, slot);
//
//			   - Player.h: 
//				    - uint32 selectedSlotID;
//					- Loot* selectedInterface;
//
//			   - LootHandler.cpp:
//					- #include "TransmogEngine.h"
//					- HandleAutostoreLootItemOpcode:
//						if(TransmogEngine::IsActiveInterface(lguid) && player)
//						{
//							if(Creature* creature = player->GetMap()->GetCreature(lguid))
//								TransmogEngine::HandleInterfaceSelect(player, creature, player->selectedInterface, lootSlot);
//
//							return;
//						}
//
//					- HandleLootReleaseOpcode:
//						if(Player* player = GetPlayer())
//							if(TransmogEngine::IsActiveInterface(guid))
//							{
//								if(Creature* creature = GetPlayer()->GetMap()->GetCreature(guid))
//									TransmogEngine::SendInterfaceClose(player, guid);
//
//								return;
//							}

#include "TransmogEngine.h"
#include "TransmogMgr.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LootMgr.h"

class npc_transmog : CreatureScript
{
public:
    npc_transmog() : CreatureScript("npc_transmog") { }

	bool OnGossipHello(Player* player, Creature* creature)
	{
	    TransmogEngine::GossipHelloMainMenu(player, creature);
		return true;
	}
	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
	{
		if(GossipSelectMenu(player, creature, action) == false)
			if(GossipSelectTransmog(player, creature, action) == false) { }

		return true;
	}
	bool GossipSelectMenu(Player* player, Creature* creature, uint32 action)
	{
		if((MENU_TEXT + 0) == action)
		{
			if(TransmogMgr::IsTransmogedPlayer(player->GetGUIDLow()))
			{
				TransmogEngine::RemoveAllTransmog(player);
				creature->MonsterWhisper("All of your active transmogrifications have been removed succesfully", player->GetGUID(), true);
			}
			else
				creature->MonsterWhisper("You don't have any active transmogrifications", player->GetGUID(), true);

			TransmogEngine::GossipHelloMainMenu(player, creature);
			return true;
		}

		if((MENU_TEXT + 1) == action)
		{
			player->PlayerTalkClass->SendCloseGossip();
			return true;
		}

		if((MENU_TEXT + 2) == action)
		{
			TransmogEngine::GossipHelloMainMenu(player, creature);
			return true;
		}

		if((MENU_TEXT + 3) == action)
		{
			GossipHelloInformationMenu(player, creature);
			return true;
		}

		return false;
	}

	bool GossipSelectTransmog(Player* player, Creature* creature, uint32 slotID)
	{
		Item* item = player->GetItemByPos(BAG, slotID);
		if(!item)
		{
			creature->MonsterWhisper("You don't have any items at the slot that you selected", player->GetGUID(), true);
			TransmogEngine::GossipHelloMainMenu(player, creature);
			return true;
		}

		if(TransmogMgr::IsTransmogedItem(item->GetGUIDLow()))
		{
			creature->MonsterWhisper("Transmogrification has been removed succesfully", player->GetGUID(), true);
			TransmogEngine::RemoveTransmog(player, slotID);
			TransmogEngine::GossipHelloMainMenu(player, creature);
			return true;
		}

		Loot* loot = TransmogEngine::CreateInterface(player, item);

		if(loot->items.size() > 0)
		{
			TransmogEngine::AddInterfacePreparation(player, creature, loot, slotID);
			TransmogEngine::SendInterfaceOpen(player, creature, loot);
		}
		else
			creature->MonsterWhisper("You don't have any items at the slot that you selected", player->GetGUID(), true);

		TransmogEngine::GossipHelloMainMenu(player, creature);
		return false;
	}

	void GossipHelloInformationMenu(Player* player, Creature* creature)
	{
		player->PlayerTalkClass->ClearMenus();

		std::string menuOutPut = "<< " + TransmogEngine::CreateColorString(COLOR_DARK_GREY, "Menu");
		std::string nevermindOutPut = TransmogEngine::CreateColorString(COLOR_DARK_GREY, " Nevermind") + "...";

		player->ADD_GOSSIP_ITEM(5, menuOutPut, GOSSIP_SENDER_MAIN, MENU_TEXT + 2);
		player->ADD_GOSSIP_ITEM(5, nevermindOutPut, GOSSIP_SENDER_MAIN, MENU_TEXT + 1);

		player->SEND_GOSSIP_MENU(TEXT_INFORMATION, creature->GetGUID());
	}
};

class player_transmog : public PlayerScript
{
    public:
		player_transmog() : PlayerScript("player_transmog") { }

	void OnLogin(Player* player)
	{
		if(player)
			TransmogEngine::SetAllTransmogDisplay(player);
	}

	void OnDelete(uint64 guid)
	{
		TransmogEngine::RemoveAllTransmogDB(guid);
	}
};

void AddSC_transmog()
{
	new npc_transmog();
	new player_transmog();
}