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
#include "ObjectDefines.h"
#include "ObjectMgr.h"

//////////////////////////////////////////////////////////////
//******************* Interface Helpers ********************//
//////////////////////////////////////////////////////////////

void TransmogEngine::AddInterfacePreparation(Player* player, Creature* creature, Loot* loot, uint8 slotID)
{
	if(!player || !creature)
		return;

	player->SetLootGUID(creature->GetGUID());

	loot->loot_type = LOOT_PICKPOCKETING;
	loot->AddLooter(player->GetGUID());

	player->selectedSlotID = slotID;
	player->selectedInterface = loot;
}

void TransmogEngine::RemoveInterfacePreparation(Player* player)
{
	if(!player)
		return;

	player->SetLootGUID(0);
	player->selectedSlotID = 0;
	player->selectedInterface = NULL;
}

void TransmogEngine::SendInterfaceClose(Player* player, uint64 creatureGUID)
{
	if(player)
	{
		player->SendLootRelease(creatureGUID);
		TransmogEngine::RemoveInterfacePreparation(player);
	}
}

void TransmogEngine::SendInterfaceOpen(Player* player, Creature* creature, Loot* loot)
{
	if(!player)
		return;

	WorldPacket data(SMSG_LOOT_RESPONSE, (9+50));
	data << uint64(creature->GetGUID());
	data << uint8(LOOT_PICKPOCKETING);
    data << LootView(*loot, player, OWNER_PERMISSION);

    player->SendDirectMessage(&data);
}

//////////////////////////////////////////////////////////////
//********************** Checkers **************************//
//////////////////////////////////////////////////////////////

bool TransmogEngine::IsInList(uint32 value, uint32 subClassTwoHand[4], uint8 length)
{
	for(uint8 i = 0; i < length; i++)
		if(value == subClassTwoHand[i])
			return true;

	return false;
}

bool TransmogEngine::IsInList(Loot* loot, LootStoreItem storeitem)
{
	if(!loot)
		return false;

	for (std::vector<LootItem>::iterator i = loot->items.begin(); i != loot->items.end(); ++i)
	{
		LootItem itemsElement = *i;
		if(itemsElement.itemid == storeitem.itemid)
			return true;
	}

	return false;
}

bool TransmogEngine::IsActiveInterface(uint64 creatureGUID)
{
	if(!IS_CREATURE_GUID(creatureGUID))
		return false;

	if(Creature* creature = ObjectAccessor::FindUnit(creatureGUID)->ToCreature())
		return (creature->GetEntry() == ENTRY);

	return false;
}

//////////////////////////////////////////////////////////////
//********************* Set Display ************************//
//////////////////////////////////////////////////////////////

bool TransmogEngine::RemoveAllTransmogDisplay(Player* player)
{
	if(!player)
		return false;

	for(uint8 i = 0; i < TransmogableItemsCount; i++)
		TransmogEngine::RemoveTransmogDisplay(player, itemSlotTypes[i]);

	return true;
}

bool TransmogEngine::RemoveTransmogDisplay(Player* player, uint32 slotID)
{
	if(!player)
		return false;

	if(Item* item = player->GetItemByPos(BAG, slotID))
	{
		TransmogEngine::TransmogDisplay(player, slotID, item->GetEntry());
		return true;
	}

	return false;
}

bool TransmogEngine::SetTransmogDisplay(Player* player, uint32 slotID)
{
	if(!player)
		return false;

	if(Item* item = player->GetItemByPos(BAG, slotID))
	{
		uint32 itemEntry = TransmogMgr::GetEntry(item->GetGUIDLow());
		if(itemEntry == PROBLEM)
			return false;

		TransmogDisplay(player, slotID, itemEntry);
		return true;
	}

	return false;
}

bool TransmogEngine::SetAllTransmogDisplay(Player* player)
{
	if(!player)
		return false;

	for(uint8 i = 0; i < TransmogableItemsCount; i++)
		SetTransmogDisplay(player, itemSlotTypes[i]);

	return true;
}

bool TransmogEngine::TransmogDisplay(Player* player, int32 slotID, int32 itemENTRY)
{
	if(!player)
		return false;

	player->SetUInt32Value(GetVisualId(slotID), itemENTRY);
	return true;
}

//////////////////////////////////////////////////////////////
//*********************** Set DB ***************************//
//////////////////////////////////////////////////////////////

void TransmogEngine::RemoveAllTransmogDB(uint32 playerGUID)
{
	CharacterDatabase.PExecute
	(
		"DELETE FROM character_transmog WHERE player_guid = %u", playerGUID
	);
}
void TransmogEngine::RemoveTransmogDB(uint32 itemGUID)
{
	CharacterDatabase.PExecute
	(
		"DELETE FROM character_transmog WHERE item_guid = %u", itemGUID
	);
}

void TransmogEngine::ReplaceTransmogDB(uint32 playerGUID, uint32 itemGUID, uint32 itemENTRY)
{
	CharacterDatabase.PExecute
    (
        "REPLACE INTO character_transmog VALUES (%u, %u, %u)", playerGUID, itemGUID, itemENTRY
    );
}

//////////////////////////////////////////////////////////////
//******************** Interface ***************************//
//////////////////////////////////////////////////////////////

void TransmogEngine::HandleInterfaceSelect(Player* player, Creature* creature, Loot* loot, uint8 lootSLOT)
{
	if(!player || !creature || !loot)
		return;

	QuestItem* qItem = NULL; QuestItem* ffaItem = NULL; QuestItem* condItem = NULL;

    LootItem* lootITEM = loot->LootItemInSlot(lootSLOT, player, &qItem, &ffaItem, &condItem);
	if(!lootITEM)
	{
		creature->MonsterWhisper("You don't have any items at the slot that you selected", player->GetGUID(), true);
		TransmogEngine::SendInterfaceClose(player, player->GetLootGUID());
		TransmogEngine::GossipHelloMainMenu(player, creature);
		return;
	}

	uint32 itemENTRY = lootITEM->itemid;
	const ItemTemplate* itemTemplate = sObjectMgr->GetItemTemplate(itemENTRY);

	uint32 slotID = player->selectedSlotID;
	if(slotID > EQUIPMENT_SLOT_END)
	{
		TransmogEngine::SendInterfaceClose(player, player->GetLootGUID());
		player->PlayerTalkClass->SendCloseGossip();
		return;
	}

	Item* item = player->GetItemByPos(BAG, slotID);
	if(!item)
	{
		creature->MonsterWhisper("You should equip an item before use this feature", player->GetGUID(), true);
		TransmogEngine::SendInterfaceClose(player, player->GetLootGUID());
		TransmogEngine::GossipHelloMainMenu(player, creature);
		return;
	}

	if(!TransmogEngine::CheckItem(player, item, itemTemplate))
	{
		creature->MonsterWhisper("Your item is not compatible with the selected item", player->GetGUID(), true);
		TransmogEngine::SendInterfaceClose(player, player->GetLootGUID());
		TransmogEngine::GossipHelloMainMenu(player, creature);
		return;
	}

	creature->MonsterWhisper("Transmogrification has been added succesfully", player->GetGUID(), true);
	TransmogEngine::SetTransmogItem(player, itemENTRY, slotID);
	TransmogEngine::GossipHelloMainMenu(player, creature);
}

Loot* TransmogEngine::CreateInterface(Player* player, Item* oldItem)
{
	uint32 addedCount = 0;

	Loot* loot = new Loot();
	loot->clear();
	loot->items.reserve(MAX_NR_LOOT_ITEMS);

	if(!player || !oldItem)
		return loot;

	bool isFirst = false;
    for (uint8 i = INVENTORY_SLOT_BAG_START; (i < INVENTORY_SLOT_BAG_END) || (isFirst = (i == INVENTORY_SLOT_BAG_END)); i++)
	{
		Bag* bag = player->GetBagByPos(i);
		if(!bag && !isFirst) // If we don't have bag and that's not the first
			continue;

		for (uint32 j = isFirst ? INVENTORY_SLOT_ITEM_START : 0; isFirst ? (j < INVENTORY_SLOT_ITEM_END) : (j < bag->GetBagSize()); j++)
		{
			if ((addedCount + 1) >= MAX_NR_LOOT_ITEMS)
				return loot;

			Item* newItem = player->GetItemByPos(isFirst ? INVENTORY_SLOT_BAG_0 : i, j);
			if(!newItem)
				continue;

			const ItemTemplate* newItemTemplate = newItem->GetTemplate();
			if(!newItemTemplate)
				continue;

			if (!TransmogEngine::CheckItem(player, oldItem, newItemTemplate))
				continue;

			LootStoreItem storeItem = LootStoreItem(newItem->GetEntry(), 100.0f, LOOT_MODE_DEFAULT, 0, 1, 1);
			if(!IsInList(loot, storeItem))
			{
				loot->items.push_back(LootItem(storeItem));
				addedCount++;
			}
        }
	}

	return loot;
}

//////////////////////////////////////////////////////////////
//******************** Transmog Helpers ********************//
//////////////////////////////////////////////////////////////

void TransmogEngine::SetTransmogItem(Player* player, uint32 itemENTRY, uint32 slotID)
{
	if(!player)
		return;

	if(Item* item = player->GetItemByPos(BAG, slotID))
	{
		uint32 playerGUID = player->GetGUIDLow();
		uint32 itemGUID = item->GetGUIDLow();

		TransmogMgr::UpdateTransmog(playerGUID, itemGUID, itemENTRY);
		TransmogEngine::ReplaceTransmogDB(playerGUID, itemGUID, itemENTRY);
		TransmogEngine::TransmogDisplay(player, slotID, itemENTRY);

		player->CastSpell(player, VANISH_VISUAL, true);
	}
}

void TransmogEngine::RemoveTransmog(Player* player, uint32 slotID)
{
	if(!player)
		return;

	if(Item* item = player->GetItemByPos(BAG, slotID))
	{
		uint32 itemGUID = item->GetGUIDLow();

		TransmogMgr::RemoveTransmogItem(itemGUID);
		TransmogEngine::RemoveTransmogDB(itemGUID);
		TransmogEngine::RemoveTransmogDisplay(player, slotID);

		player->CastSpell(player, VANISH_VISUAL, true);
	}
}

void TransmogEngine::RemoveAllTransmog(Player* player)
{
	if(!player)
		return;

	for(int32 i = 0; i < TransmogableItemsCount; i++)
	{
		uint32 slotID = itemSlotTypes[i];

		if(Item* item = player->GetItemByPos(BAG, slotID))
		{
			uint32 playerGUID = player->GetGUIDLow();

			TransmogMgr::RemoveTransmogPlayer(playerGUID);
			TransmogEngine::RemoveAllTransmogDB(playerGUID);
			TransmogEngine::RemoveAllTransmogDisplay(player);

			player->CastSpell(player, VANISH_VISUAL, true);
		}
	}
}

//////////////////////////////////////////////////////////////
//******************** Handler Helpers ********************//
//////////////////////////////////////////////////////////////

void TransmogEngine::GossipHelloMainMenu(Player* player, Creature* creature)
{
	player->PlayerTalkClass->ClearMenus();
	uint32 playerGUID = player->GetGUIDLow();

	for(int32 i = 0; i < TransmogableItemsCount; i++)
	{
		uint32 slotID = itemSlotTypes[i];

		Item* item = player->GetItemByPos(BAG, slotID);
		if(!item)
			continue;

		const ItemTemplate* itemTemplate = item->GetTemplate();
		if(!itemTemplate)
			continue;

		std::string slotName = CreateColorString(COLOR_DARK_GREY, GetSlotName(slotID) + "\n");
		std::string itemName = CreateColorString(COLOR_GREY, item->GetTemplate()->Name1);

		if(TransmogMgr::IsTransmogedItem(item->GetGUIDLow()))
			player->ADD_GOSSIP_ITEM(5, "[Remove]: " + slotName + itemName, GOSSIP_SENDER_MAIN, slotID);
		else
			player->ADD_GOSSIP_ITEM(5, "[Create]: " + slotName + itemName, GOSSIP_SENDER_MAIN, slotID);
	}

	uint32 transmogsCount = TransmogMgr::GetTransmogsCount(playerGUID);

	std::string removeOutPut = CreateColorString(COLOR_GREY, GetString(transmogsCount) + CreateColorString(COLOR_DARK_GREY, " Items"));
	std::string learnOutPut = CreateColorString(COLOR_DARK_GREY, "...");

	player->ADD_GOSSIP_ITEM(5, "[Remove All]: " + removeOutPut, GOSSIP_SENDER_MAIN, MENU_TEXT + 0);
	player->ADD_GOSSIP_ITEM(5, "Learn More" + learnOutPut, GOSSIP_SENDER_MAIN, MENU_TEXT + 3);

	player->SEND_GOSSIP_MENU(TEXT_MAIN, creature->GetGUID());
}

std::string TransmogEngine::GetSlotName(uint32 slotID)
{
	switch(slotID)
	{
		case HEAD:			return "Head";
		case SHOULDERS:	    return "Shoulders";
		case CHEST:		    return "Chest";
		case WAIST:			return "Waist";
		case LEGS:		    return "Legs";
		case FEET:		    return "Feet";
		case WRIST:			return "Wrist";
		case HANDS:			return "Hands";
		case BACK:			return "Back";
		case MAIN_HAND:		return "MainHand";
		case OFF_HAND:		return "OffHand";
		default:			return "Ranged";
	}
}

//////////////////////////////////////////////////////////////
//*********************** Helpers **************************//
//////////////////////////////////////////////////////////////

std::string TransmogEngine::CreateColorString(uint32 color, std::string text)
{
	std::stringstream ss;
	ss << "|cff";
	ss << colorCodes[color - 1];
	ss << text;
	ss << "|r";

	return ss.str();
}

std::string TransmogEngine::GetString(int32 value)
{
	std::stringstream ss;
    std::string s;
    ss << value;
    s = ss.str();

    return s;
}

bool TransmogEngine::CheckItem(Player* itemOwner, Item* oldItem, const ItemTemplate* newItemTemplate)
{
	if(!itemOwner || !oldItem || !newItemTemplate)
		return false;

	const ItemTemplate* oldItemTemplate = oldItem->GetTemplate();
	if(!oldItemTemplate)
		return false;

	uint32 oldItemGUID = oldItem->GetGUIDLow();
	const ItemTemplate* fakeItemTemplate = NULL;

	bool isTransmoged = TransmogMgr::IsTransmogedItem(oldItemGUID);
	if(isTransmoged)
		fakeItemTemplate = sObjectMgr->GetItemTemplate(TransmogMgr::GetEntry(oldItemGUID));

    uint32 newClass = newItemTemplate->Class;
	uint32 oldClass = oldItemTemplate->Class;

    uint32 newSubClass = newItemTemplate->SubClass;
	uint32 oldSubClass = oldItemTemplate->SubClass;

    uint32 newInventoryType = newItemTemplate->InventoryType;
	uint32 oldInventoryType = oldItemTemplate->InventoryType;

	if(oldItemTemplate->DisplayInfoID == newItemTemplate->DisplayInfoID)
		return false;

	if(isTransmoged)
		if(newItemTemplate->DisplayInfoID == fakeItemTemplate->DisplayInfoID)
			return false;

    if (newClass != oldClass)
        return false;

	// fix chest transmogs bug because of different inventory types (by Natureknight)
	if(oldInventoryType == INVTYPE_CHEST || oldInventoryType == INVTYPE_BODY || oldInventoryType == INVTYPE_ROBE)
		if(newInventoryType == INVTYPE_CHEST || newInventoryType == INVTYPE_BODY || newInventoryType == INVTYPE_ROBE)
		    return true;

	if(newInventoryType == INVTYPE_RELIC || oldInventoryType == INVTYPE_RELIC)
		return false;

    if (newClass == ITEM_CLASS_ARMOR)
		if(newSubClass == oldSubClass && newInventoryType == oldInventoryType)
			return true;

    if (newClass == ITEM_CLASS_WEAPON)
	{
		uint32 subClassTwoHand[4] =
			{ ITEM_SUBCLASS_WEAPON_AXE2, ITEM_SUBCLASS_WEAPON_MACE2, ITEM_SUBCLASS_WEAPON_SWORD2, ITEM_SUBCLASS_WEAPON_POLEARM };

		if(TransmogEngine::IsInList(newSubClass, subClassTwoHand, 4) && TransmogEngine::IsInList(oldSubClass, subClassTwoHand, 4))
			return true;

		uint32 subClassOneHand[4] =
			{ ITEM_SUBCLASS_WEAPON_AXE, ITEM_SUBCLASS_WEAPON_MACE, ITEM_SUBCLASS_WEAPON_SWORD, ITEM_SUBCLASS_WEAPON_DAGGER };

		if(TransmogEngine::IsInList(newSubClass, subClassOneHand, 4) && TransmogEngine::IsInList(oldSubClass, subClassOneHand, 4))
			return true;

		uint32 subClassRanged[4] =
			{ ITEM_SUBCLASS_WEAPON_BOW, ITEM_SUBCLASS_WEAPON_GUN, ITEM_SUBCLASS_WEAPON_CROSSBOW, 0 };

		if(TransmogEngine::IsInList(newSubClass, subClassRanged, 3) && TransmogEngine::IsInList(oldSubClass, subClassRanged, 3))
			return true;

		if(newSubClass == oldSubClass)
			if(newSubClass == ITEM_SUBCLASS_WEAPON_WAND || newSubClass == ITEM_SUBCLASS_WEAPON_THROWN || ITEM_SUBCLASS_WEAPON_STAFF)
				return true;
	}

	return false;
}