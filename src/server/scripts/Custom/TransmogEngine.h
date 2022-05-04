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

#ifndef TRANSMOG_ENGINE_H
#define TRANSMOG_ENGINE_H

#include "ScriptPCH.h"

#define PROBLEM		-255
#define MENU_TEXT	100

#define BAG			255
#define ENTRY		100002


#define TransmogableItemsCount 12


enum MenuText
{
    TEXT_MAIN					= 1,
	TEXT_INFORMATION		    = 2
};

enum Spells
{
	VANISH_VISUAL = 24222,
	SEAL_OF_LIGHT = 132
};

enum ItemSlotTypes
{
    HEAD             = 0,
    SHOULDERS        = 2,
    CHEST            = 4,
    WAIST			 = 5,
    LEGS             = 6,
    FEET             = 7,
    WRIST            = 8,
    HANDS            = 9,
	BACK			 = 14,
	MAIN_HAND		 = 15,
	OFF_HAND		 = 16,
	RANGED			 = 17
};

enum ColorCode
{
	COLOR_BLACK			= 7,
	COLOR_DARK_GREY		= 6,
	COLOR_GOLD			= 5,
	COLOR_PURPLE		= 4,
	COLOR_BLUE			= 3,
	COLOR_GREEN			= 2,
	COLOR_GREY			= 1
};

const std::string colorCodes[7] = 
{ 
	"454545", "00ff00", "0000cd", "8a2be2", "ff8c00", "1e1e1e", "000000"
};

const int32 itemSlotTypes[TransmogableItemsCount] = 
{ 
	HEAD, SHOULDERS, CHEST, WAIST, LEGS, FEET, WRIST, HANDS, BACK, MAIN_HAND, OFF_HAND, RANGED
};

class TransmogEngine
{
public: // DB Helper Methods
	static void SetTransmogItem(Player* player, uint32 itemENTRY, uint32 slotID);
	static void RemoveAllTransmog(Player* player);	
	static void RemoveTransmog(Player* player, uint32 slotID);

public: // DB Methods: Private
	static void ReplaceTransmogDB(uint32 playerGUID, uint32 itemGUID, uint32 itemENTRY);
	static void RemoveTransmogDB(uint32 itemGUID);

public: // DB Methods: Public
	static void RemoveAllTransmogDB(uint32 playerGUID);

public: // Display Methods: Public
	static bool SetAllTransmogDisplay(Player* player);
	static bool SetTransmogDisplay(Player* player, uint32 slotID);
	static bool RemoveAllTransmogDisplay(Player* player);
	static bool RemoveTransmogDisplay(Player* player, uint32 slotID);

private: // Checker Methods: Private
	static bool CheckItem(Player* itemOwner, Item* oldItem, const ItemTemplate* newItemTemplate);
	static bool TransmogDisplay(Player* player, int32 itemENTRY, int32 slotID);
	static bool IsInList(Loot* loot, LootStoreItem storeitem);
	static bool IsInList(uint32 value, uint32 subClassTwoHand[4], uint8 length);

public: // Checker Methods: Public
	static bool IsActiveInterface(uint64 creatureGUID);

private: // Helper Methods: Private
	static std::string GetString(int32 value);
	static std::string GetSlotName(uint32 slotID);
	static int32 GetVisualId(uint32 slotID) { return slotID * 2 + 283; }

public: // Helper Methods: Public
	static std::string CreateColorString(uint32 color, std::string text);

public: // Interface Methods: Public
	static void AddInterfacePreparation(Player* player, Creature* creature, Loot* loot, uint8 slotID);
	static void RemoveInterfacePreparation(Player* player);
	static void HandleInterfaceSelect(Player* player, Creature* creature, Loot* loot, uint8 lootSLOT);
	static void SendInterfaceOpen(Player* player, Creature* creature, Loot* loot);
	static void SendInterfaceClose(Player* player, uint64 creatureGUID);
	static Loot* CreateInterface(Player* player, Item* oldItem);

public: // TransmogHandler: Public
	static void GossipHelloMainMenu(Player* player, Creature* creature);
};
#endif