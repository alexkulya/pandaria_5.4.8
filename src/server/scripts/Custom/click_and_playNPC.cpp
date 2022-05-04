////////////////////////////////////////////////////////////////////////
//      ___                         ___       __  __  __              //
//     / _ | _______ ___  ___ _____/ _ )___ _/ /_/ /_/ /__ ___        //
//    / __ |/ __/ -_) _ \/ _ `/___/ _  / _ `/ __/ __/ / -_|_-<        //
//   /_/ |_/_/  \__/_//_/\_,_/   /____/\_,_/\__/\__/_/\__/___/.com    //
//                                                                    //
//         Developed by Natureknight Patrick and Scott.               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "ScriptPCH.h"
#include "click_and_playNPC.h"

void SocketSlot(Player* player, Item* item, EnchantmentSlot slot, uint32 socketGem)
{
	if (!item)
    {
        player->GetSession()->SendNotification("You must first equip the item you are trying to enchant in order to enchant it!");
        return;
    }
	
    if (!socketGem)
    {
        player->GetSession()->SendNotification("Something went wrong in the code. It has been logged for developers and will be looked into, sorry for the inconvenience.");
        return;
    }

	player->ApplyEnchantment(item, slot, false);
    item->SetEnchantment(slot, socketGem, 0, 0);
    player->ApplyEnchantment(item, slot, true);
}

void EnchantItem(Player* player, Item* item, uint32 itemEnchantId)
{
	if (!item)
    {
        player->GetSession()->SendNotification("Something went wrong.");
        return;
    }
	
    if (!itemEnchantId)
    {
        player->GetSession()->SendNotification("Something went wrong.");
        return;
    }
		
    player->ApplyEnchantment(item, PERM_ENCHANTMENT_SLOT, false);
    item->SetEnchantment(PERM_ENCHANTMENT_SLOT, itemEnchantId, 0, 0);
    player->ApplyEnchantment(item, PERM_ENCHANTMENT_SLOT, true);
}

class ClickAndPlay_NPC : public CreatureScript
{
public:
    ClickAndPlay_NPC() : CreatureScript("ClickAndPlay_NPC") { }

    bool OnGossipHello(Player *player, Creature * creature)
	{
		if (player->isInCombat())
        {
            player->CLOSE_GOSSIP_MENU();
            creature->MonsterWhisper("You are in combat!", player->GetGUID());
            return true;
        }
		
		if (player->getClass() == CLASS_MAGE)
		{
            player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Arcane build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Fire build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Frost build", GOSSIP_SENDER_MAIN, 1, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
		}
		if (player->getClass() == CLASS_PRIEST)
		{
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Discipline build", GOSSIP_SENDER_MAIN, 2, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Holy build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Shadow build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
		}
		if (player->getClass() == CLASS_DRUID)
		{
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Ballance build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Feral build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Restoration build", GOSSIP_SENDER_MAIN, 5, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
		}
		if (player->getClass() == CLASS_WARLOCK)
		{
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Affliction build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Demonology build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Destruction build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
		}
		if (player->getClass() == CLASS_WARRIOR)
		{
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Arms build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Fury build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Protection build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
		}
		if (player->getClass() == CLASS_ROGUE)
		{
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Assasination build", GOSSIP_SENDER_MAIN, 3, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Combat build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Sublety build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
		}
		if (player->getClass() == CLASS_PALADIN)
		{
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Holy build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Protection build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Retribution build", GOSSIP_SENDER_MAIN, 4, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
		}
		if (player->getClass() == CLASS_HUNTER)
		{
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Beast Mastery build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Markmanship build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Survival build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
		}
		if (player->getClass() == CLASS_SHAMAN)
		{
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Elemental build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Enhancement build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Restoration build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
		}
		if (player->getClass() == CLASS_DEATH_KNIGHT)
		{
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Blood build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Frost build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
			player->ADD_GOSSIP_ITEM_EXTENDED(5, "Use Recommended Unholy build", GOSSIP_SENDER_MAIN, 101, "Are you sure you want to obtain Frost recommended talents and gear?", 0, false);
		}
		player->ADD_GOSSIP_ITEM_EXTENDED(5, "Reset my talent points", GOSSIP_SENDER_MAIN, 100, "Are you sure you want to reset your talent points?", 0, false);
        player->SEND_GOSSIP_MENU(80000, creature->GetGUID());         
        return true;
    }

    bool OnGossipSelect(Player * player, Creature * creature, uint32 sender, uint32 uiAction)
    {
        if (sender == GOSSIP_SENDER_MAIN)
        {
            player->PlayerTalkClass->ClearMenus();

			// Randomize tabards (only low ones)
			uint32 randTabard[8] = {35279, 35280, 43348, 46874, 38313, 23709, 45582, 36941};

            switch(uiAction)
            {                                              
			    case 1: // Frost Mage recommented talent tree
					{
					    if (player->GetFreeTalentPoints() < 71)
		                {
			                player->GetSession()->SendAreaTriggerMessage("You have already spent some talent points. You need to reset your talents first!");
		                    player->CLOSE_GOSSIP_MENU();
		                    return true;
	                    }
					    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
		                {
                            if (Item* haveItemEquipped = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
			                {
				                if (haveItemEquipped)
				                {
					                player->GetSession()->SendAreaTriggerMessage("You need to remove all your equipped items in order to use this feature!");
		                            player->CLOSE_GOSSIP_MENU();
		                            return true;
				                }
		                    }
		                }

						// HEAD
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanHead'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HEAD, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHead'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HEAD, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// NECK
					    if (player->getRace() == RACE_HUMAN)
						{
						    QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanNeck'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_NECK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
					    }
					    else if (player->getRace() != RACE_HUMAN)
					    {
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageNeck'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_NECK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
							if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// SHOULDERS
					    if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanShoulders'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
						else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageShoulders'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// BACK
					    if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanBack'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_BACK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
					    }
						else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageBack'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_BACK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// CHEST
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanChest'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_CHEST, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageChest'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_CHEST, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), Enchant);
						    if (SocketOne > 0)
				                    SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// WRISTS
					    if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanWrists'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
					    }
						else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageWrists'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// HANDS
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanHands'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HANDS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHands'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HANDS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// WAIST
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanWaist'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WAIST, Item, true);
				            SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), PRISMATIC_ENCHANTMENT_SLOT, 3729); // Socket Belt
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageWaist'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WAIST, Item, true);
				            SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), PRISMATIC_ENCHANTMENT_SLOT, 3729); // Socket Belt
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// LEGS
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanLegs'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_LEGS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageLegs'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_LEGS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FEET
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanFeet'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FEET, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageFeet'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FEET, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FINGER1
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanRingOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageRingOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FINGER2
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanRingTwo'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageRingTwo'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// TRINKET1
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanTrinketOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageTrinketOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// TRINKET2
						if (player->GetTeam() == ALLIANCE && player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanTrinketTwo'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, Item, true);
				        }
					    else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
						{
						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 51377, true); // Medallion of the Alliance
						}

						else if (player->GetTeam() == HORDE)
						{
						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 51378, true); // Medallion of the Horde
						}

						// MAINHAND
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanMainHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageMainHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// OFFHAND
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanOffHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
								return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageOffHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
								return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// RANGED
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageHumanRanged'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_RANGED, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'FrostMageRanged'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_RANGED, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

				        // Frost Talents
				        player->learnSpell(12497, false); player->AddTalent(12497, player->GetActiveSpec(), true);
				        player->learnSpell(16766, false); player->AddTalent(16766, player->GetActiveSpec(), true);
				        player->learnSpell(55094, false); player->AddTalent(55094, player->GetActiveSpec(), true);
				        player->learnSpell(15047, false); player->AddTalent(15047, player->GetActiveSpec(), true);
				        player->learnSpell(28332, false); player->AddTalent(28332, player->GetActiveSpec(), true);
				        player->learnSpell(12571, false); player->AddTalent(12571, player->GetActiveSpec(), true);
				        player->learnSpell(12953, false); player->AddTalent(12953, player->GetActiveSpec(), true);
				        player->learnSpell(12472, false); player->AddTalent(12472, player->GetActiveSpec(), true);
				        player->learnSpell(16758, false); player->AddTalent(16758, player->GetActiveSpec(), true);
				        player->learnSpell(12983, false); player->AddTalent(12983, player->GetActiveSpec(), true);
				        player->learnSpell(11958, false); player->AddTalent(11958, player->GetActiveSpec(), true);
				        player->learnSpell(55092, false); player->AddTalent(55092, player->GetActiveSpec(), true);
				        player->learnSpell(28593, false); player->AddTalent(28593, player->GetActiveSpec(), true);
				        player->learnSpell(11426, false); player->AddTalent(11426, player->GetActiveSpec(), true);
				        player->learnSpell(54787, false); player->AddTalent(54787, player->GetActiveSpec(), true);
				        player->learnSpell(31683, false); player->AddTalent(31683, player->GetActiveSpec(), true);
				        player->learnSpell(44545, false); player->AddTalent(44545, player->GetActiveSpec(), true);
				        player->learnSpell(31687, false); player->AddTalent(31687, player->GetActiveSpec(), true);
				        player->learnSpell(44549, false); player->AddTalent(44549, player->GetActiveSpec(), true);
				        player->learnSpell(44571, false); player->AddTalent(44571, player->GetActiveSpec(), true);
				        player->learnSpell(44572, false); player->AddTalent(44572, player->GetActiveSpec(), true);
				        player->learnSpell(12592, false); player->AddTalent(12592, player->GetActiveSpec(), true);
				        player->learnSpell(12840, false); player->AddTalent(12840, player->GetActiveSpec(), true);
				        player->learnSpell(54659, false); player->AddTalent(54659, player->GetActiveSpec(), true);
				        player->learnSpell(29444, false); player->AddTalent(29444, player->GetActiveSpec(), true);
				        player->learnSpell(12606, false); player->AddTalent(12606, player->GetActiveSpec(), true);
				        player->learnSpell(12467, false); player->AddTalent(12467, player->GetActiveSpec(), true);
				        player->learnSpell(54646, false); player->AddTalent(54646, player->GetActiveSpec(), true);
				        player->learnSpell(12598, false); player->AddTalent(12598, player->GetActiveSpec(), true);
				        player->learnSpell(55340, false); player->AddTalent(55340, player->GetActiveSpec(), true);

					    // Add Glyphs in Bags
					    player->AddItem(45740, 1); // glyph of ice barrier
					    player->AddItem(42738, 1); // glyph of evocation
					    player->AddItem(42752, 1); // glyph of polymorph

					    player->AddItem(43357, 1); // glyph of fire ward
					    player->AddItem(43360, 1); // glyph of frost ward
					    player->AddItem(43364, 1); // glyph of slow fall

				        player->SetFreeTalentPoints(0);
				        player->SendTalentsInfoData(false);
			            player->GetSession()->SendAreaTriggerMessage("You're now Frost Mage!");
				        player->CastSpell(player, 24222, true); // Vanish Viusal spell
				        player->CLOSE_GOSSIP_MENU();
					}
                break;

                case 2: // Discipline Priest
					{
					    if (player->GetFreeTalentPoints() < 71)
		                {
			                player->GetSession()->SendAreaTriggerMessage("You have already spent some talent points. You need to reset your talents first!");
		                    player->CLOSE_GOSSIP_MENU();
		                    return true;
	                    }
					    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
		                {
                            if (Item* haveItemEquipped = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
			                {
				                if (haveItemEquipped)
				                {
					                player->GetSession()->SendAreaTriggerMessage("You need to remove all your equipped items in order to use this feature!");
		                            player->CLOSE_GOSSIP_MENU();
		                            return true;
				                }
		                    }
		                }

						// HEAD
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanHead'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HEAD, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHead'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HEAD, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
						// NECK
					    if (player->getRace() == RACE_HUMAN)
						{
						    QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanNeck'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_NECK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
					    }
					    else if (player->getRace() != RACE_HUMAN)
					    {
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestNeck'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_NECK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
							if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
						// SHOULDERS
					    if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanShoulders'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
						else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestShoulders'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
						// BACK
					    if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanBack'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_BACK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
					    }
						else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestBack'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_BACK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// CHEST
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanChest'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_CHEST, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestChest'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_CHEST, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), Enchant);
						    if (SocketOne > 0)
				                    SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// WRISTS
					    if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanWrists'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
					    }
						else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestWrists'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// HANDS
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanHands'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HANDS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHands'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HANDS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// WAIST
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanWaist'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WAIST, Item, true);
				            SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), PRISMATIC_ENCHANTMENT_SLOT, 3729); // Socket Belt
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestWaist'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WAIST, Item, true);
				            SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), PRISMATIC_ENCHANTMENT_SLOT, 3729); // Socket Belt
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// LEGS
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanLegs'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_LEGS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestLegs'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_LEGS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FEET
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanFeet'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FEET, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestFeet'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FEET, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FINGER1
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanRingOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestRingOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FINGER2
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanRingTwo'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestRingTwo'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// TRINKET1
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanTrinketOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestTrinketOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// TRINKET2
						if (player->GetTeam() == ALLIANCE && player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanTrinketTwo'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, Item, true);
				        }
					    else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
						{
						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 51377, true); // Medallion of the Alliance
						}

						else if (player->GetTeam() == HORDE)
						{
						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 51378, true); // Medallion of the Horde
						}

						// MAINHAND
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanMainHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestMainHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// OFFHAND
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanOffHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestOffHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// RANGED
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanRanged'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_RANGED, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'DisciplinePriestRanged'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_RANGED, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

					    // Discipline Talents
				        player->learnSpell(14791, false); player->AddTalent(14791, player->GetActiveSpec(), true);
                        player->learnSpell(14785, false); player->AddTalent(14785, player->GetActiveSpec(), true);
                        player->learnSpell(14771, false); player->AddTalent(14771, player->GetActiveSpec(), true);
                        player->learnSpell(14777, false); player->AddTalent(14777, player->GetActiveSpec(), true);
                        player->learnSpell(14751, false); player->AddTalent(14751, player->GetActiveSpec(), true);
                        player->learnSpell(14769, false); player->AddTalent(14769, player->GetActiveSpec(), true);
                        player->learnSpell(33171, false); player->AddTalent(33171, player->GetActiveSpec(), true);
                        player->learnSpell(14781, false); player->AddTalent(14781, player->GetActiveSpec(), true);
                        player->learnSpell(14772, false); player->AddTalent(14772, player->GetActiveSpec(), true);
                        player->learnSpell(18555, false); player->AddTalent(18555, player->GetActiveSpec(), true);
                        player->learnSpell(63574, false); player->AddTalent(63574, player->GetActiveSpec(), true);
                        player->learnSpell(33190, false); player->AddTalent(33190, player->GetActiveSpec(), true);
                        player->learnSpell(34910, false); player->AddTalent(34910, player->GetActiveSpec(), true);
                        player->learnSpell(45244, false); player->AddTalent(45244, player->GetActiveSpec(), true);
                        player->learnSpell(10060, false); player->AddTalent(10060, player->GetActiveSpec(), true);
                        player->learnSpell(57472, false); player->AddTalent(57472, player->GetActiveSpec(), true);
                        player->learnSpell(47537, false); player->AddTalent(47537, player->GetActiveSpec(), true);
                        player->learnSpell(47508, false); player->AddTalent(47508, player->GetActiveSpec(), true);
                        player->learnSpell(47511, false); player->AddTalent(47511, player->GetActiveSpec(), true);
                        player->learnSpell(33206, false); player->AddTalent(33206, player->GetActiveSpec(), true);
                        player->learnSpell(47516, false); player->AddTalent(47516, player->GetActiveSpec(), true);
                        player->learnSpell(52800, false); player->AddTalent(52800, player->GetActiveSpec(), true);
                        player->learnSpell(47540, false); player->AddTalent(47540, player->GetActiveSpec(), true);
                        player->learnSpell(15012, false); player->AddTalent(15012, player->GetActiveSpec(), true);
                        player->learnSpell(15009, false); player->AddTalent(15009, player->GetActiveSpec(), true);
                        player->learnSpell(18535, false); player->AddTalent(18535, player->GetActiveSpec(), true);
                        player->learnSpell(19236, false); player->AddTalent(19236, player->GetActiveSpec(), true);
                        player->learnSpell(15363, false); player->AddTalent(15363, player->GetActiveSpec(), true);
					    // Add Glyphs (Major)
					    player->AddItem(45756, 1); // glyph of penance
					    player->AddItem(42408, 1); // glyph of power word: shield
					    player->AddItem(45760, 1); // glyph of pain suppression
				        // Add Glyphs (Minor)
					    player->AddItem(43370, 1); // glyph of levitate
					    player->AddItem(43372, 1); // glyph of shadow protection
					    player->AddItem(43374, 1); // glyph of shadowfiend
				        // Update Talent Points and Close Gossip Menu
				        player->SetFreeTalentPoints(0);
				        player->SendTalentsInfoData(false);
			            player->GetSession()->SendAreaTriggerMessage("You're now Discipline Priest!");
				        player->CastSpell(player, 24222, true); // Vanish Viusal spell
				        player->CLOSE_GOSSIP_MENU();
					}
				break;

				case 3: // Assassination Rogue recommented talent tree
					{
					    if (player->GetFreeTalentPoints() < 71)
		                {
			                player->GetSession()->SendAreaTriggerMessage("You have already spent some talent points. You need to reset your talents first!");
		                    player->CLOSE_GOSSIP_MENU();
		                    return true;
	                    }
					    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
		                {
                            if (Item* haveItemEquipped = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
			                {
				                if (haveItemEquipped)
				                {
					                player->GetSession()->SendAreaTriggerMessage("You need to remove all your equipped items in order to use this feature!");
		                            player->CLOSE_GOSSIP_MENU();
		                            return true;
				                }
		                    }
		                }

						// HEAD
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanHead'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HEAD, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHead'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HEAD, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
						// NECK
					    if (player->getRace() == RACE_HUMAN)
						{
						    QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanNeck'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_NECK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
					    }
					    else if (player->getRace() != RACE_HUMAN)
					    {
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueNeck'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_NECK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
							if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
						// SHOULDERS
					    if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanShoulders'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
						else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueShoulders'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
						// BACK
					    if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanBack'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_BACK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
					    }
						else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueBack'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_BACK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// CHEST
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanChest'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_CHEST, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueChest'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_CHEST, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), Enchant);
						    if (SocketOne > 0)
				                    SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// WRISTS
					    if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanWrists'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
					    }
						else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueWrists'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// HANDS
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanHands'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HANDS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHands'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HANDS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// WAIST
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanWaist'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WAIST, Item, true);
				            SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), PRISMATIC_ENCHANTMENT_SLOT, 3729); // Socket Belt
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueWaist'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WAIST, Item, true);
				            SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), PRISMATIC_ENCHANTMENT_SLOT, 3729); // Socket Belt
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// LEGS
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanLegs'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_LEGS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueLegs'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_LEGS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FEET
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanFeet'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FEET, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueFeet'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FEET, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FINGER1
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanRingOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueRingOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FINGER2
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanRingTwo'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueRingTwo'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// TRINKET1
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanTrinketOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueTrinketOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// TRINKET2
						if (player->GetTeam() == ALLIANCE && player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanTrinketTwo'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, Item, true);
				        }
					    else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
						{
						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 51377, true); // Medallion of the Alliance
						}

						else if (player->GetTeam() == HORDE)
						{
						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 51378, true); // Medallion of the Horde
						}

						// MAINHAND
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanMainHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueMainHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// OFFHAND
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanOffHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
								return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueOffHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
								return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// RANGED
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanRanged'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_RANGED, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'AssassinationRogueRanged'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_RANGED, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

				        // Rogue Assasination Talents
				        player->learnSpell(14142, false); player->AddTalent(14142, player->GetActiveSpec(), true);
				        player->learnSpell(14161, false); player->AddTalent(14161, player->GetActiveSpec(), true);
				        player->learnSpell(13866, false); player->AddTalent(13866, player->GetActiveSpec(), true);
				        player->learnSpell(14983, false); player->AddTalent(14983, player->GetActiveSpec(), true);
				        player->learnSpell(14135, false); player->AddTalent(14135, player->GetActiveSpec(), true);
				        player->learnSpell(16515, false); player->AddTalent(16515, player->GetActiveSpec(), true);
				        player->learnSpell(14115, false); player->AddTalent(14115, player->GetActiveSpec(), true);
				        player->learnSpell(31209, false); player->AddTalent(31209, player->GetActiveSpec(), true);
				        player->learnSpell(14177, false); player->AddTalent(14177, player->GetActiveSpec(), true);
				        player->learnSpell(31245, false); player->AddTalent(31245, player->GetActiveSpec(), true);
				        player->learnSpell(14195, false); player->AddTalent(14195, player->GetActiveSpec(), true);
				        player->learnSpell(14159, false); player->AddTalent(14159, player->GetActiveSpec(), true);
				        player->learnSpell(51626, false); player->AddTalent(51626, player->GetActiveSpec(), true);
				        player->learnSpell(58426, false); player->AddTalent(58426, player->GetActiveSpec(), true);
				        player->learnSpell(51636, false); player->AddTalent(51636, player->GetActiveSpec(), true);
					    player->learnSpell(58410, false); player->AddTalent(58410, player->GetActiveSpec(), true);
				        player->learnSpell(31234, false); player->AddTalent(31234, player->GetActiveSpec(), true);
				        player->learnSpell(1329, false); player->AddTalent(1329, player->GetActiveSpec(), true);
				        player->learnSpell(13848, false); player->AddTalent(13848, player->GetActiveSpec(), true);
				        player->learnSpell(58425, false); player->AddTalent(58425, player->GetActiveSpec(), true);
				        player->learnSpell(13971, false); player->AddTalent(13971, player->GetActiveSpec(), true);
				        player->learnSpell(14072, false); player->AddTalent(14072, player->GetActiveSpec(), true);
				        player->learnSpell(14094, false); player->AddTalent(14094, player->GetActiveSpec(), true);
				        player->learnSpell(14063, false); player->AddTalent(14063, player->GetActiveSpec(), true);
				        player->learnSpell(14066, false); player->AddTalent(14066, player->GetActiveSpec(), true);
				        player->learnSpell(14173, false); player->AddTalent(14173, player->GetActiveSpec(), true);
				        player->learnSpell(30895, false); player->AddTalent(30895, player->GetActiveSpec(), true);
				        player->learnSpell(14185, false); player->AddTalent(14185, player->GetActiveSpec(), true);
				        player->learnSpell(14083, false); player->AddTalent(14083, player->GetActiveSpec(), true);

					    // Add Glyphs in Bags
					    player->AddItem(42971, 1); // glyph of vigor
					    player->AddItem(42968, 1); // glyph of preparation
					    player->AddItem(45768, 1); // glyph of mutilate

					    player->AddItem(43380, 1); // glyph of vanish
					    player->AddItem(43379, 1); // glyph of blurred speed
					    player->AddItem(43376, 1); // glyph of distract

				        player->SetFreeTalentPoints(0);
				        player->SendTalentsInfoData(false);
			            player->GetSession()->SendAreaTriggerMessage("You are now geared and talented for the optimum Assasination Rogue specialisation!");
				        player->CastSpell(player, 24222, true); // Vanish Viusal spell
				        player->CLOSE_GOSSIP_MENU();
					}
			    break;

			    case 4: // Retribution recommented talent tree
					{
					    if (player->GetFreeTalentPoints() < 71)
		                {
			                player->GetSession()->SendAreaTriggerMessage("You have already spent some talent points. You need to reset your talents first!");
		                    player->CLOSE_GOSSIP_MENU();
		                    return true;
	                    }
					    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
		                {
                            if (Item* haveItemEquipped = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
			                {
				                if (haveItemEquipped)
				                {
					                player->GetSession()->SendAreaTriggerMessage("You need to remove all your equipped items in order to use this feature!");
		                            player->CLOSE_GOSSIP_MENU();
		                            return true;
				                }
		                    }
		                }

						// HEAD
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanHead'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HEAD, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHead'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HEAD, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
						// NECK
					    if (player->getRace() == RACE_HUMAN)
						{
						    QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanNeck'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_NECK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
					    }
					    else if (player->getRace() != RACE_HUMAN)
					    {
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaNeck'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_NECK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
							if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
						// SHOULDERS
					    if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanShoulders'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
						else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaShoulders'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
						// BACK
					    if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanBack'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_BACK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
					    }
						else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaBack'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_BACK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// CHEST
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanChest'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_CHEST, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaChest'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_CHEST, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), Enchant);
						    if (SocketOne > 0)
				                    SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// WRISTS
					    if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanWrists'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
					    }
						else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaWrists'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// HANDS
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanHands'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HANDS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHands'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HANDS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// WAIST
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanWaist'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WAIST, Item, true);
				            SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), PRISMATIC_ENCHANTMENT_SLOT, 3729); // Socket Belt
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaWaist'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WAIST, Item, true);
				            SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), PRISMATIC_ENCHANTMENT_SLOT, 3729); // Socket Belt
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// LEGS
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanLegs'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_LEGS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaLegs'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_LEGS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FEET
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanFeet'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FEET, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaFeet'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FEET, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FINGER1
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanRingOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaRingOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FINGER2
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanRingTwo'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaRingTwo'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// TRINKET1
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanTrinketOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaTrinketOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// TRINKET2
						if (player->GetTeam() == ALLIANCE && player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanTrinketTwo'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, Item, true);
				        }
					    else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
						{
						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 51377, true); // Medallion of the Alliance
						}

						else if (player->GetTeam() == HORDE)
						{
						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 51378, true); // Medallion of the Horde
						}

						// MAINHAND
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanMainHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaMainHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// RANGED
						if (player->getRace() == RACE_HUMAN)
						{
							QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanRanged'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_RANGED, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
				        }
					    else if (player->getRace() != RACE_HUMAN)
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RetributionPalaRanged'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_RANGED, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
				        // Paladin Retribution Talents
					    player->learnSpell(20105, false); player->AddTalent(20105, player->GetActiveSpec(), true);
				        player->learnSpell(20332, false); player->AddTalent(20332, player->GetActiveSpec(), true);
				        player->learnSpell(25836, false); player->AddTalent(25836, player->GetActiveSpec(), true);
				        player->learnSpell(20266, false); player->AddTalent(20266, player->GetActiveSpec(), true);
				        player->learnSpell(53519, false); player->AddTalent(53519, player->GetActiveSpec(), true);
				        player->learnSpell(20175, false); player->AddTalent(20175, player->GetActiveSpec(), true);
				        player->learnSpell(64205, false); player->AddTalent(64205, player->GetActiveSpec(), true);
				        player->learnSpell(25957, false); player->AddTalent(25957, player->GetActiveSpec(), true);
				        player->learnSpell(20337, false); player->AddTalent(20337, player->GetActiveSpec(), true);
				        player->learnSpell(20045, false); player->AddTalent(20045, player->GetActiveSpec(), true);
				        player->learnSpell(20121, false); player->AddTalent(20121, player->GetActiveSpec(), true);
				        player->learnSpell(26023, false); player->AddTalent(26023, player->GetActiveSpec(), true);
				        player->learnSpell(35397, false); player->AddTalent(35397, player->GetActiveSpec(), true);
				        player->learnSpell(31868, false); player->AddTalent(31868, player->GetActiveSpec(), true);
				        player->learnSpell(20113, false); player->AddTalent(20113, player->GetActiveSpec(), true);
				        player->learnSpell(31869, false); player->AddTalent(31869, player->GetActiveSpec(), true);
				        player->learnSpell(20057, false); player->AddTalent(20057, player->GetActiveSpec(), true);
				        player->learnSpell(31872, false); player->AddTalent(31872, player->GetActiveSpec(), true);
				        player->learnSpell(53488, false); player->AddTalent(53488, player->GetActiveSpec(), true);
				        player->learnSpell(20066, false); player->AddTalent(20066, player->GetActiveSpec(), true);
				        player->learnSpell(31878, false); player->AddTalent(31878, player->GetActiveSpec(), true);
				        player->learnSpell(31881, false); player->AddTalent(31881, player->GetActiveSpec(), true);
				        player->learnSpell(53376, false); player->AddTalent(53376, player->GetActiveSpec(), true);
				        player->learnSpell(35395, false); player->AddTalent(35395, player->GetActiveSpec(), true);
				        player->learnSpell(53503, false); player->AddTalent(53503, player->GetActiveSpec(), true);
				        player->learnSpell(53382, false); player->AddTalent(53382, player->GetActiveSpec(), true);
				        player->learnSpell(53385, false); player->AddTalent(53385, player->GetActiveSpec(), true);

					    // Add Glyphs in Bags
					    player->AddItem(41103, 1); // glyph of excorcism
					    player->AddItem(41092, 1); // glyph of judgement
					    player->AddItem(43868, 1); // glyph of seal of righteousness

				 	    player->AddItem(43340, 1); // glyph of blessing of might
					    player->AddItem(43365, 1); // glyph of blessing of kings
					    player->AddItem(43369, 1); // glyph of the wise

				        player->SetFreeTalentPoints(0);
				        player->SendTalentsInfoData(false);
			            player->GetSession()->SendAreaTriggerMessage("You are now geared and talented for the optimum Retribution Paladin specialisation!");
				        player->CastSpell(player, 24222, true); // Vanish Viusal spell
				        player->CLOSE_GOSSIP_MENU();
					}
			    break;

				case 5: // Restoration Druid
					{
					    if (player->GetFreeTalentPoints() < 71)
		                {
			                player->GetSession()->SendAreaTriggerMessage("You have already spent some talent points. You need to reset your talents first!");
		                    player->CLOSE_GOSSIP_MENU();
		                    return true;
	                    }
					    for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; i++)
		                {
                            if (Item* haveItemEquipped = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
			                {
				                if (haveItemEquipped)
				                {
					                player->GetSession()->SendAreaTriggerMessage("You need to remove all your equipped items in order to use this feature!");
		                            player->CLOSE_GOSSIP_MENU();
		                            return true;
				                }
		                    }
		                }

						// HEAD
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidHead'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HEAD, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
								
						// NECK
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidNeck'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_NECK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
							if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}
								
						// SHOULDERS
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidShoulders'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_SHOULDERS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// BACK
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidBack'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_BACK, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// CHEST
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidChest'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_CHEST, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), Enchant);
						    if (SocketOne > 0)
				                    SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// WRISTS
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidWrists'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WRISTS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// HANDS
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidHands'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_HANDS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// WAIST
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidWaist'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_WAIST, Item, true);
				            SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), PRISMATIC_ENCHANTMENT_SLOT, 3729); // Socket Belt
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// LEGS
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidLegs'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_LEGS, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FEET
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidFeet'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FEET, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FINGER1
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidRingOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// FINGER2
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidRingTwo'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_FINGER2, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// TRINKET1
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidTrinketOne'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_TRINKET1, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// TRINKET2
						{
                            if (player->GetTeam() == ALLIANCE)
						    {
						        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 51377, true); // Medallion of the Alliance
						    }
						    else if (player->GetTeam() == HORDE)
						    {
						        player->EquipNewItem(EQUIPMENT_SLOT_TRINKET2, 51378, true); // Medallion of the Horde
						    }
						}

						// MAINHAND
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidMainHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_MAINHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// OFFHAND
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidOffHand'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
								return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_OFFHAND, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// RANGED
						{
					        QueryResult select = CharacterDatabase.PQuery("SELECT Slot, Item, Enchant, SocketOne, SocketTwo, SocketThree FROM clickandplay_templates WHERE Description = 'RestorationDruidRanged'");
						    if (!select)
						    {
							    player->GetSession()->SendAreaTriggerMessage("No records yet.");
							    return true;
						    }
					        Field* fields = select->Fetch();
			                uint32 Slot = fields[0].GetUInt32(); uint32 Item = fields[1].GetUInt32();
						    uint32 Enchant = fields[2].GetUInt32(); uint32 SocketOne = fields[3].GetUInt32(); 
						    uint32 SocketTwo = fields[4].GetUInt32(); uint32 SocketThree = fields[5].GetUInt32();

						    player->EquipNewItem(EQUIPMENT_SLOT_RANGED, Item, true);
						    if (Enchant > 0)
				                EnchantItem(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), Enchant);
						    if (SocketOne > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT, SocketOne);
						    if (SocketTwo > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_2, SocketTwo);
						    if (SocketThree > 0)
				                SocketSlot(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), SOCK_ENCHANTMENT_SLOT_3, SocketThree);
						}

						// Restoration Druid Talents
						player->learnSpell(17051, false); player->AddTalent(17051, player->GetActiveSpec(), true);
						player->learnSpell(17066, false); player->AddTalent(17066, player->GetActiveSpec(), true);
						player->learnSpell(17120, false); player->AddTalent(17120, player->GetActiveSpec(), true);
						player->learnSpell(16835, false); player->AddTalent(16835, player->GetActiveSpec(), true);
						player->learnSpell(17108, false); player->AddTalent(17108, player->GetActiveSpec(), true);
						player->learnSpell(16864, false); player->AddTalent(16864, player->GetActiveSpec(), true);
						player->learnSpell(17051, false); player->AddTalent(17051, player->GetActiveSpec(), true);
						player->learnSpell(48412, false); player->AddTalent(48412, player->GetActiveSpec(), true);
						player->learnSpell(17113, false); player->AddTalent(17113, player->GetActiveSpec(), true);
						player->learnSpell(17116, false); player->AddTalent(17116, player->GetActiveSpec(), true);
						player->learnSpell(24946, false); player->AddTalent(24946, player->GetActiveSpec(), true);
						player->learnSpell(33880, false); player->AddTalent(33880, player->GetActiveSpec(), true);
						player->learnSpell(17075, false); player->AddTalent(17075, player->GetActiveSpec(), true);
						player->learnSpell(34153, false); player->AddTalent(34153, player->GetActiveSpec(), true);
						player->learnSpell(18562, false); player->AddTalent(18562, player->GetActiveSpec(), true);
						player->learnSpell(33883, false); player->AddTalent(33883, player->GetActiveSpec(), true);
						player->learnSpell(33890, false); player->AddTalent(33890, player->GetActiveSpec(), true);
						player->learnSpell(65139, false); player->AddTalent(65139, player->GetActiveSpec(), true);
						player->learnSpell(48536, false); player->AddTalent(48536, player->GetActiveSpec(), true);
						player->learnSpell(63411, false); player->AddTalent(63411, player->GetActiveSpec(), true);
						player->learnSpell(51181, false); player->AddTalent(51181, player->GetActiveSpec(), true);
						player->learnSpell(16817, false); player->AddTalent(16817, player->GetActiveSpec(), true);
						player->learnSpell(57814, false); player->AddTalent(57814, player->GetActiveSpec(), true);
						player->learnSpell(16847, false); player->AddTalent(16847, player->GetActiveSpec(), true);
						player->learnSpell(35364, false); player->AddTalent(35364, player->GetActiveSpec(), true);
						player->learnSpell(57865, false); player->AddTalent(57865, player->GetActiveSpec(), true);
						player->learnSpell(16820, false); player->AddTalent(16820, player->GetActiveSpec(), true);
						player->learnSpell(16924, false); player->AddTalent(16924, player->GetActiveSpec(), true);
						player->learnSpell(5570, false); player->AddTalent(5570, player->GetActiveSpec(), true);

						// Add Glyphs in Bags
					    player->AddItem(45623, 1); // glyph of barkskin
					    player->AddItem(40906, 1); // glyph of swiftmend
					    player->AddItem(40908, 1); // glyph of innervate

				 	    player->AddItem(43674, 1); // glyph of dash
					    player->AddItem(43332, 1); // glyph of thorns
					    player->AddItem(43335, 1); // glyph of the wild

				        player->SetFreeTalentPoints(0);
				        player->SendTalentsInfoData(false);
			            player->GetSession()->SendAreaTriggerMessage("You are now geared and talented for the optimum Retribution Paladin specialisation!");
				        player->CastSpell(player, 24222, true); // Vanish Viusal spell
				        player->CLOSE_GOSSIP_MENU();
					}
				break;

			    case 100: // Reset talents
					if (player->GetFreeTalentPoints() == 71)
		            {
			            player->GetSession()->SendAreaTriggerMessage("You dont have spent any talent points yet.");
		                player->CLOSE_GOSSIP_MENU();
		                return true;
	                }
				    player->resetTalents(true);
				    player->SendTalentsInfoData(false);
				    player->GetSession()->SendAreaTriggerMessage("Your talents has been reset.");
					player->CastSpell(player, 24222, true); // Vanish Viusal spell
				    player->CLOSE_GOSSIP_MENU();
			    break;

			    case 101: // Under Construction
				    player->GetSession()->SendAreaTriggerMessage("This build is not ready yet.");
				    player->CLOSE_GOSSIP_MENU();
			    break;
                }
        } 
    return true;
    } 
};

void AddSC_ClickAndPlay_NPC()
{
    new ClickAndPlay_NPC();
}