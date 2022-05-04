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

//////////////////////////////////////////////////////////////
//********************* Variables **************************//
//////////////////////////////////////////////////////////////

std::list<CharacterTransmog*> TransmogMgr::characterTransmogList;
bool TransmogMgr::loaded;

//////////////////////////////////////////////////////////////
//********************* Transmog Load **********************//
//////////////////////////////////////////////////////////////

void TransmogMgr::LoadCharacterTransmog()
{
	loaded = true;

	QueryResult result = CharacterDatabase.Query("SELECT * FROM character_transmog ORDER BY player_guid");
	if(!result)
		 return;

	do
    {
		Field* fields = result->Fetch();

		CharacterTransmog* characterTransmog = new CharacterTransmog(fields[0].GetUInt32(), fields[1].GetUInt32(), fields[2].GetUInt32());
		characterTransmogList.push_back(characterTransmog);

	} while(result->NextRow());
}

//////////////////////////////////////////////////////////////
//******************* Transmog Remove **********************//
//////////////////////////////////////////////////////////////

void TransmogMgr::RemoveTransmogItem(uint32 itemGUID)
{
	if(IsEmpty())
		return;

	for(CharacterTransmogList::iterator itrBegin = characterTransmogList.begin(), itrEnd = characterTransmogList.end(); itrBegin != itrEnd; itrBegin++)
	{
		CharacterTransmog* characterTransmog = *itrBegin;
		if(!characterTransmog)
			continue;

		if(characterTransmog->itemGUID == itemGUID)
		{
			characterTransmogList.remove(characterTransmog);
			return;
		}
	}
}

void TransmogMgr::RemoveTransmogPlayer(uint32 playerGUID)
{
	if(IsEmpty())
		return;

	for(CharacterTransmogList::iterator itrBegin = characterTransmogList.begin(), itrEnd = characterTransmogList.end(); itrBegin != itrEnd; itrBegin++)
	{
		CharacterTransmog* characterTransmog = *itrBegin;
		if(!characterTransmog)
			continue;

		if(characterTransmog->playerGUID == playerGUID)
		{
			characterTransmogList.remove(characterTransmog);
			return;
		}
	}
}

//////////////////////////////////////////////////////////////
//********************* Transmog Add ***********************//
//////////////////////////////////////////////////////////////

void TransmogMgr::AddTransmog(uint32 playerGUID, uint32 itemGUID, uint32 itemENTRY)
{
	if(!TransmogMgr::IsTransmogedItem(itemGUID))
	{
		CharacterTransmog* characterTransmog = new CharacterTransmog(playerGUID, itemGUID, itemENTRY);
		characterTransmogList.push_back(characterTransmog);
	}
}

void TransmogMgr::UpdateTransmog(uint32 playerGUID, uint32 itemGUID, uint32 itemENTRY)
{
	for(CharacterTransmogList::iterator itrBegin = characterTransmogList.begin(), itrEnd = characterTransmogList.end(); itrBegin != itrEnd; itrBegin++)
	{
		CharacterTransmog* characterTransmog = *itrBegin;
		if(!characterTransmog)
			continue;

		if(characterTransmog->itemGUID == itemGUID)
		{
			characterTransmog->playerGUID = playerGUID;
			characterTransmog->itemENTRY = itemENTRY;
			return;
		}
	}

	TransmogMgr::AddTransmog(playerGUID, itemGUID, itemENTRY);
}

//////////////////////////////////////////////////////////////
//********************** Helpers ***************************//
//////////////////////////////////////////////////////////////

uint32 TransmogMgr::GetTransmogsCount(uint32 playerGUID)
{
	uint32 counter = 0;

	if(IsEmpty())
		return counter;

	for(CharacterTransmogList::iterator itrBegin = characterTransmogList.begin(), itrEnd = characterTransmogList.end(); itrBegin != itrEnd; itrBegin++)
	{
		CharacterTransmog* characterTransmog = *itrBegin;
		if(!characterTransmog)
			continue;

		if(characterTransmog->playerGUID == playerGUID)
			counter++;
	}

	return counter;
}

uint32 TransmogMgr::GetEntry(uint32 itemGUID)
{
	if(IsEmpty())
		return PROBLEM;

	for(CharacterTransmogList::iterator itrBegin = characterTransmogList.begin(), itrEnd = characterTransmogList.end(); itrBegin != itrEnd; itrBegin++)
	{
		CharacterTransmog* characterTransmog = *itrBegin;
		if(!characterTransmog)
			continue;

		if(characterTransmog->itemGUID == itemGUID)
			return characterTransmog->itemENTRY;
	}

	return PROBLEM;
}

//////////////////////////////////////////////////////////////
//********************** Checkers **************************//
//////////////////////////////////////////////////////////////

bool TransmogMgr::IsTransmogedItem(uint32 itemGUID)
{
	if(IsEmpty())
		return false;

	for(CharacterTransmogList::iterator itrBegin = characterTransmogList.begin(), itrEnd = characterTransmogList.end(); itrBegin != itrEnd; itrBegin++)
	{
		CharacterTransmog* characterTransmog = *itrBegin;
		if(!characterTransmog)
			continue;

		if(characterTransmog->itemGUID == itemGUID)
			return true;
		
	}

	return false;
}

//////////////////////////////////////////////////////////////
//********************* WorldScript ************************//
//////////////////////////////////////////////////////////////

class StartUpTransmog : public WorldScript
{
public:
    StartUpTransmog() : WorldScript("StartUpTransmog") { }

	void OnStartup() 
	{
		TransmogMgr::LoadCharacterTransmog();
	}
};

void AddSC_StartUpTransmog()
{
	new StartUpTransmog();
};