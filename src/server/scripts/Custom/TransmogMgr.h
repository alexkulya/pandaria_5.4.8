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

#ifndef TRANSMOG_MGR_H
#define TRANSMOG_MGR_H

#include "ScriptPCH.h"

struct CharacterTransmog
{
	CharacterTransmog(uint32 _playerGUID, uint32 _itemGUID, uint32 _itemENTRY) 
	{ playerGUID = _playerGUID; itemGUID = _itemGUID; itemENTRY = _itemENTRY; }

	uint32 playerGUID;
	uint32 itemGUID;
	uint32 itemENTRY;
};

typedef std::list<CharacterTransmog*> CharacterTransmogList;

class TransmogMgr
{
public: // Methods
	 static void AddTransmog(uint32 playerGUID, uint32 itemGUID, uint32 itemENTRY);
     static void RemoveTransmogPlayer(uint32 playerGUID);
	 static void RemoveTransmogItem(uint32 itemGUID);

	 static void LoadCharacterTransmog();
	 static void UpdateTransmog(uint32 playerGUID, uint32 itemGUID, uint32 itemENTRY);

public: // Helpers
	 static uint32 GetEntry(uint32 itemGUID);
	 static uint32 GetTransmogsCount(uint32 playerGUID);

public: // Checkers
	 static bool IsTransmogedPlayer(uint32 playerGUID) { return (GetTransmogsCount(playerGUID) > 0); }
	 static bool IsTransmogedItem(uint32 itemGUID);

	 static bool IsEmpty() { return (characterTransmogList.size() == 0); }
     static bool IsLoaded() { return loaded; }

private: // Values
	 static bool loaded;
	 static CharacterTransmogList characterTransmogList;
};
#endif