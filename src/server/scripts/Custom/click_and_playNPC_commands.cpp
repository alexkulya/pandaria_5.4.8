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

class createItemSet_commandscript : public CommandScript
{
public:
    createItemSet_commandscript() : CommandScript("createItemSet_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand createItemSetCommandTable[] =
        {
			{ "disciplineitemset",            SEC_ADMINISTRATOR,        false,           &HandleCreateDisciplineItemSetCommand,             "", NULL },
			{ "retributionitemset",           SEC_ADMINISTRATOR,        false,           &HandleCreateRetributionItemSetCommand,            "", NULL },
			{ "restorationdruiditemset",      SEC_ADMINISTRATOR,        false,           &HandleCreateRestorationDruidItemSetCommand,       "", NULL },
			{ "frostmageitemset",             SEC_ADMINISTRATOR,        false,           &HandleCreateFrostMageItemSetCommand,              "", NULL },
			{ "assassinationitemset",         SEC_ADMINISTRATOR,        false,           &HandleCreateAssassinationRogueItemSetCommand,     "", NULL },
            { NULL,                           0,                        false,           NULL,                                              "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "create",         SEC_PLAYER,         true, NULL,                 "", createItemSetCommandTable },
            { NULL,             0,                  false, NULL,                              "", NULL }
        };
        return commandTable;
    }

		static bool HandleCreateDisciplineItemSetCommand(ChatHandler* handler, const char* args)
    {
        Player* player = handler->GetSession()->GetPlayer();

		if (player->getClass() != CLASS_PRIEST)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a Priest!");
			return false;
		}

		Item* Head = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD);
		Item* Neck = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK);
		Item* Shoulders = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS);
		Item* Back = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
		Item* Chest = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
		Item* Wrists = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
		Item* Hands = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
		Item* Waist = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST);
		Item* Legs = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS);
		Item* Feet = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
		Item* RingOne = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1);
		Item* RingTwo = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2);
		Item* TrinketOne = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1);
		Item* TrinketTwo = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET2);
		Item* MainHand = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
		Item* OffHand = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
		Item* Ranged = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);

		// HEAD
		if (Head)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanHead' AND Slot = 'Head';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanHead', 'Head', %u, %u, %u, %u, %u);"
			    , Head->GetEntry(), Head->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHead' AND Slot = 'Head';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHead', 'Head', %u, %u, %u, %u, %u);"
			    , Head->GetEntry(), Head->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Head)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Head slot.");
			return false;
		}

		// NECK
		if (Neck)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanNeck' AND Slot = 'Neck';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanNeck', 'Neck', %u, %u, %u, %u, %u);"
			    , Neck->GetEntry(), Neck->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestNeck' AND Slot = 'Neck';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestNeck', 'Neck', %u, %u, %u, %u, %u);"
			    , Neck->GetEntry(), Neck->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Neck)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Neck slot.");
			return false;
		}

		// SHOULDERS
		if (Shoulders)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanShoulders' AND Slot = 'Shoulders';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanShoulders', 'Shoulders', %u, %u, %u, %u, %u);"
			    , Shoulders->GetEntry(), Shoulders->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestShoulders' AND Slot = 'Shoulders';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestShoulders', 'Shoulders', %u, %u, %u, %u, %u);"
			    , Shoulders->GetEntry(), Shoulders->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Shoulders)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Shoulders slot.");
			return false;
		}

		// BACK
		if (Back)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanBack' AND Slot = 'Back';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanBack', 'Back', %u, %u, %u, %u, %u);"
			    , Back->GetEntry(), Back->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestBack' AND Slot = 'Back';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestBack', 'Back', %u, %u, %u, %u, %u);"
			    , Back->GetEntry(), Back->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Back)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Back slot.");
			return false;
		}

		// CHEST
		if (Chest)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanChest' AND Slot = 'Chest';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanChest', 'Chest', %u, %u, %u, %u, %u);"
			    , Chest->GetEntry(), Chest->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestChest' AND Slot = 'Chest';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestChest', 'Chest', %u, %u, %u, %u, %u);"
			    , Chest->GetEntry(), Chest->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Chest)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Chest slot.");
			return false;
		}

		// WRISTS
		if (Wrists)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanWrists' AND Slot = 'Wrists';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanWrists', 'Wrists', %u, %u, %u, %u, %u);"
			    , Wrists->GetEntry(), Wrists->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestWrists' AND Slot = 'Wrists';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestWrists', 'Wrists', %u, %u, %u, %u, %u);"
			    , Wrists->GetEntry(), Wrists->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Wrists)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Shoulders slot.");
			return false;
		}

		// HANDS
		if (Hands)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanHands' AND Slot = 'Hands';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanHands', 'Hands', %u, %u, %u, %u, %u);"
			    , Hands->GetEntry(), Hands->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHands' AND Slot = 'Hands';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHands', 'Hands', %u, %u, %u, %u, %u);"
			    , Hands->GetEntry(), Hands->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Hands)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Hands slot.");
			return false;
		}

		// WAIST
		if (Waist)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanWaist' AND Slot = 'Waist';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanWaist', 'Waist', %u, %u, %u, %u, %u);"
			    , Waist->GetEntry(), Waist->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestWaist' AND Slot = 'Waist';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestWaist', 'Waist', %u, %u, %u, %u, %u);"
			    , Waist->GetEntry(), Waist->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Waist)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Waist slot.");
			return false;
		}

		// LEGS
		if (Legs)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanLegs' AND Slot = 'Legs';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanLegs', 'Legs', %u, %u, %u, %u, %u);"
			    , Legs->GetEntry(), Legs->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestLegs' AND Slot = 'Legs';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestLegs', 'Legs', %u, %u, %u, %u, %u);"
			    , Legs->GetEntry(), Legs->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Legs)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Legs slot.");
			return false;
		}

		// FEET
		if (Feet)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanFeet' AND Slot = 'Feet';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanFeet', 'Feet', %u, %u, %u, %u, %u);"
			    , Feet->GetEntry(), Feet->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestFeet' AND Slot = 'Feet';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestFeet', 'Feet', %u, %u, %u, %u, %u);"
			    , Feet->GetEntry(), Feet->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Feet)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Feet slot.");
			return false;
		}

		// RING ONE
		if (RingOne)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanRingOne' AND Slot = 'RingOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanRingOne', 'RingOne', %u, %u, %u, %u, %u);"
			    , RingOne->GetEntry(), RingOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestRingOne' AND Slot = 'RingOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestRingOne', 'RingOne', %u, %u, %u, %u, %u);"
			    , RingOne->GetEntry(), RingOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!RingOne)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in RingOne slot.");
			return false;
		}

		// RING TWO
		if (RingTwo)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanRingTwo' AND Slot = 'RingTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanRingTwo', 'RingTwo', %u, %u, %u, %u, %u);"
			    , RingTwo->GetEntry(), RingTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestRingTwo' AND Slot = 'RingTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestRingTwo', 'RingTwo', %u, %u, %u, %u, %u);"
			    , RingTwo->GetEntry(), RingTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!RingTwo)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in RingTwo slot.");
			return false;
		}

		// TRINKET ONE
		if (TrinketOne)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanTrinketOne' AND Slot = 'TrinketOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanTrinketOne', 'TrinketOne', %u, %u, %u, %u, %u);"
			    , TrinketOne->GetEntry(), TrinketOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestTrinketOne' AND Slot = 'TrinketOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestTrinketOne', 'TrinketOne', %u, %u, %u, %u, %u);"
			    , TrinketOne->GetEntry(), TrinketOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!TrinketOne)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in TrinketOne slot.");
			return false;
		}

		// TRINKET TWO
		if (TrinketTwo)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanTrinketTwo' AND Slot = 'TrinketTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanTrinketTwo', 'TrinketTwo', %u, %u, %u, %u, %u);"
			    , TrinketTwo->GetEntry(), Wrists->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestTrinketTwo' AND Slot = 'TrinketTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestTrinketTwo', 'TrinketTwo', %u, %u, %u, %u, %u);"
			    , TrinketTwo->GetEntry(), TrinketTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!TrinketTwo)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in TrinketTwo slot.");
			return false;
		}

		// MAIN HAND
		if (MainHand)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanMainHand' AND Slot = 'MainHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanMainHand', 'MainHand', %u, %u, %u, %u, %u);"
			    , MainHand->GetEntry(), MainHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestMainHand' AND Slot = 'MainHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestMainHand', 'MainHand', %u, %u, %u, %u, %u);"
			    , MainHand->GetEntry(), MainHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!MainHand)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in MainHand slot.");
			return false;
		}

		// OFF HAND
		if (OffHand)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanOffHand' AND Slot = 'OffHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanOffHand', 'OffHand', %u, %u, %u, %u, %u);"
			    , OffHand->GetEntry(), OffHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestOffHand' AND Slot = 'OffHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestOffHand', 'OffHand', %u, %u, %u, %u, %u);"
			    , OffHand->GetEntry(), OffHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!OffHand)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in OffHand slot.");
			return false;
		}

		// RANGED
		if (Ranged)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestHumanRanged' AND Slot = 'Ranged';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestHumanRanged', 'Ranged', %u, %u, %u, %u, %u);"
			    , Ranged->GetEntry(), Ranged->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'DisciplinePriestRanged' AND Slot = 'Ranged';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('DisciplinePriestRanged', 'Ranged', %u, %u, %u, %u, %u);"
			    , Ranged->GetEntry(), Ranged->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Ranged)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Ranged slot.");
			return false;
		}
		player->GetSession()->SendAreaTriggerMessage("You have just created a new itemset for Discipline Priest.");
        return true;
    }

	static bool HandleCreateRetributionItemSetCommand(ChatHandler* handler, const char* args)
    {
        Player* player = handler->GetSession()->GetPlayer();

		if (player->getClass() != CLASS_PALADIN)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a Paladin!");
			return false;
		}

		Item* Head = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD);
		Item* Neck = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK);
		Item* Shoulders = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS);
		Item* Back = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
		Item* Chest = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
		Item* Wrists = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
		Item* Hands = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
		Item* Waist = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST);
		Item* Legs = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS);
		Item* Feet = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
		Item* RingOne = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1);
		Item* RingTwo = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2);
		Item* TrinketOne = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1);
		Item* TrinketTwo = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET2);
		Item* MainHand = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
		Item* OffHand = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
		Item* Ranged = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);

		// HEAD
		if (Head)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanHead' AND Slot = 'Head';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanHead', 'Head', %u, %u, %u, %u, %u);"
			    , Head->GetEntry(), Head->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHead' AND Slot = 'Head';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHead', 'Head', %u, %u, %u, %u, %u);"
			    , Head->GetEntry(), Head->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Head)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Head slot.");
		}

		// NECK
		if (Neck)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanNeck' AND Slot = 'Neck';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanNeck', 'Neck', %u, %u, %u, %u, %u);"
			    , Neck->GetEntry(), Neck->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaNeck' AND Slot = 'Neck';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaNeck', 'Neck', %u, %u, %u, %u, %u);"
			    , Neck->GetEntry(), Neck->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Neck)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Neck slot.");
		}

		// SHOULDERS
		if (Shoulders)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanShoulders' AND Slot = 'Shoulders';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanShoulders', 'Shoulders', %u, %u, %u, %u, %u);"
			    , Shoulders->GetEntry(), Shoulders->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaShoulders' AND Slot = 'Shoulders';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaShoulders', 'Shoulders', %u, %u, %u, %u, %u);"
			    , Shoulders->GetEntry(), Shoulders->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Shoulders)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Shoulders slot.");
		}

		// BACK
		if (Back)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanBack' AND Slot = 'Back';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanBack', 'Back', %u, %u, %u, %u, %u);"
			    , Back->GetEntry(), Back->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaBack' AND Slot = 'Back';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaBack', 'Back', %u, %u, %u, %u, %u);"
			    , Back->GetEntry(), Back->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Back)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Back slot.");
		}

		// CHEST
		if (Chest)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanChest' AND Slot = 'Chest';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanChest', 'Chest', %u, %u, %u, %u, %u);"
			    , Chest->GetEntry(), Chest->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaChest' AND Slot = 'Chest';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaChest', 'Chest', %u, %u, %u, %u, %u);"
			    , Chest->GetEntry(), Chest->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Chest)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Chest slot.");
		}

		// WRISTS
		if (Wrists)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanWrists' AND Slot = 'Wrists';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanWrists', 'Wrists', %u, %u, %u, %u, %u);"
			    , Wrists->GetEntry(), Wrists->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaWrists' AND Slot = 'Wrists';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaWrists', 'Wrists', %u, %u, %u, %u, %u);"
			    , Wrists->GetEntry(), Wrists->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Wrists)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Shoulders slot.");
		}

		// HANDS
		if (Hands)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanHands' AND Slot = 'Hands';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanHands', 'Hands', %u, %u, %u, %u, %u);"
			    , Hands->GetEntry(), Hands->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHands' AND Slot = 'Hands';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHands', 'Hands', %u, %u, %u, %u, %u);"
			    , Hands->GetEntry(), Hands->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Hands)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Hands slot.");
		}

		// WAIST
		if (Waist)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanWaist' AND Slot = 'Waist';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanWaist', 'Waist', %u, %u, %u, %u, %u);"
			    , Waist->GetEntry(), Waist->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaWaist' AND Slot = 'Waist';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaWaist', 'Waist', %u, %u, %u, %u, %u);"
			    , Waist->GetEntry(), Waist->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Waist)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Waist slot.");
		}

		// LEGS
		if (Legs)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanLegs' AND Slot = 'Legs';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanLegs', 'Legs', %u, %u, %u, %u, %u);"
			    , Legs->GetEntry(), Legs->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaLegs' AND Slot = 'Legs';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaLegs', 'Legs', %u, %u, %u, %u, %u);"
			    , Legs->GetEntry(), Legs->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Legs)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Legs slot.");
		}

		// FEET
		if (Feet)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanFeet' AND Slot = 'Feet';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanFeet', 'Feet', %u, %u, %u, %u, %u);"
			    , Feet->GetEntry(), Feet->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaFeet' AND Slot = 'Feet';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaFeet', 'Feet', %u, %u, %u, %u, %u);"
			    , Feet->GetEntry(), Feet->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Feet)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Feet slot.");
		}

		// RING ONE
		if (RingOne)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanRingOne' AND Slot = 'RingOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanRingOne', 'RingOne', %u, %u, %u, %u, %u);"
			    , RingOne->GetEntry(), RingOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaRingOne' AND Slot = 'RingOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaRingOne', 'RingOne', %u, %u, %u, %u, %u);"
			    , RingOne->GetEntry(), RingOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!RingOne)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in RingOne slot.");
		}

		// RING TWO
		if (RingTwo)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanRingTwo' AND Slot = 'RingTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanRingTwo', 'RingTwo', %u, %u, %u, %u, %u);"
			    , RingTwo->GetEntry(), RingTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaRingTwo' AND Slot = 'RingTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaRingTwo', 'RingTwo', %u, %u, %u, %u, %u);"
			    , RingTwo->GetEntry(), RingTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!RingTwo)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in RingTwo slot.");
		}

		// TRINKET ONE
		if (TrinketOne)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanTrinketOne' AND Slot = 'TrinketOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanTrinketOne', 'TrinketOne', %u, %u, %u, %u, %u);"
			    , TrinketOne->GetEntry(), TrinketOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaTrinketOne' AND Slot = 'TrinketOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaTrinketOne', 'TrinketOne', %u, %u, %u, %u, %u);"
			    , TrinketOne->GetEntry(), TrinketOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!TrinketOne)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in TrinketOne slot.");
		}

		// TRINKET TWO
		if (TrinketTwo)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanTrinketTwo' AND Slot = 'TrinketTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanTrinketTwo', 'TrinketTwo', %u, %u, %u, %u, %u);"
			    , TrinketTwo->GetEntry(), Wrists->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaTrinketTwo' AND Slot = 'TrinketTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaTrinketTwo', 'TrinketTwo', %u, %u, %u, %u, %u);"
			    , TrinketTwo->GetEntry(), TrinketTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!TrinketTwo)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in TrinketTwo slot.");
		}

		// MAIN HAND
		if (MainHand)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanMainHand' AND Slot = 'MainHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanMainHand', 'MainHand', %u, %u, %u, %u, %u);"
			    , MainHand->GetEntry(), MainHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaMainHand' AND Slot = 'MainHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaMainHand', 'MainHand', %u, %u, %u, %u, %u);"
			    , MainHand->GetEntry(), MainHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!MainHand)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in MainHand slot.");
		}

		// OFF HAND
		if (OffHand)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanOffHand' AND Slot = 'OffHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanOffHand', 'OffHand', %u, %u, %u, %u, %u);"
			    , OffHand->GetEntry(), OffHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaOffHand' AND Slot = 'OffHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaOffHand', 'OffHand', %u, %u, %u, %u, %u);"
			    , OffHand->GetEntry(), OffHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!OffHand)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in OffHand slot.");
		}

		// RANGED
		if (Ranged)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaHumanRanged' AND Slot = 'Ranged';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaHumanRanged', 'Ranged', %u, %u, %u, %u, %u);"
			    , Ranged->GetEntry(), Ranged->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RetributionPalaRanged' AND Slot = 'Ranged';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RetributionPalaRanged', 'Ranged', %u, %u, %u, %u, %u);"
			    , Ranged->GetEntry(), Ranged->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Ranged)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Ranged slot.");
		}
		player->GetSession()->SendAreaTriggerMessage("You have just created a new itemset for Retribution Paladin.");
        return true;
    }

	    static bool HandleCreateRestorationDruidItemSetCommand(ChatHandler* handler, const char* args)
    {
        Player* player = handler->GetSession()->GetPlayer();

		if (player->getClass() != CLASS_DRUID)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a Druid!");
			return false;
		}

		Item* Head = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD);
		Item* Neck = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK);
		Item* Shoulders = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS);
		Item* Back = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
		Item* Chest = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
		Item* Wrists = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
		Item* Hands = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
		Item* Waist = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST);
		Item* Legs = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS);
		Item* Feet = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
		Item* RingOne = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1);
		Item* RingTwo = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2);
		Item* TrinketOne = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1);
		Item* TrinketTwo = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET2);
		Item* MainHand = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
		Item* OffHand = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
		Item* Ranged = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);

		// HEAD
		if (Head)
		{
			CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidHead' AND Slot = 'Head';");
			CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidHead', 'Head', %u, %u, %u, %u, %u);"
			, Head->GetEntry(), Head->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!Head)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Head slot.");
		}

		// NECK
		if (Neck)
		{
			CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidNeck' AND Slot = 'Neck';");
			CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidNeck', 'Neck', %u, %u, %u, %u, %u);"
			, Neck->GetEntry(), Neck->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!Neck)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Neck slot.");
		}

		// SHOULDERS
		if (Shoulders)
		{
			CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidShoulders' AND Slot = 'Shoulders';");
			CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidShoulders', 'Shoulders', %u, %u, %u, %u, %u);"
			, Shoulders->GetEntry(), Shoulders->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!Shoulders)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Shoulders slot.");
		}

		// BACK
		if (Back)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidBack' AND Slot = 'Back';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidBack', 'Back', %u, %u, %u, %u, %u);"
			    , Back->GetEntry(), Back->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!Back)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Back slot.");
		}

		// CHEST
		if (Chest)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidChest' AND Slot = 'Chest';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidChest', 'Chest', %u, %u, %u, %u, %u);"
			    , Chest->GetEntry(), Chest->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!Chest)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Chest slot.");
		}

		// WRISTS
		if (Wrists)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidWrists' AND Slot = 'Wrists';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidWrists', 'Wrists', %u, %u, %u, %u, %u);"
			    , Wrists->GetEntry(), Wrists->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!Wrists)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Shoulders slot.");
		}

		// HANDS
		if (Hands)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidHands' AND Slot = 'Hands';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidHands', 'Hands', %u, %u, %u, %u, %u);"
			    , Hands->GetEntry(), Hands->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!Hands)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Hands slot.");
		}

		// WAIST
		if (Waist)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidWaist' AND Slot = 'Waist';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidWaist', 'Waist', %u, %u, %u, %u, %u);"
			    , Waist->GetEntry(), Waist->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!Waist)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Waist slot.");
		}

		// LEGS
		if (Legs)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidLegs' AND Slot = 'Legs';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidLegs', 'Legs', %u, %u, %u, %u, %u);"
			    , Legs->GetEntry(), Legs->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!Legs)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Legs slot.");
		}

		// FEET
		if (Feet)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidFeet' AND Slot = 'Feet';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidFeet', 'Feet', %u, %u, %u, %u, %u);"
			    , Feet->GetEntry(), Feet->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!Feet)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Feet slot.");
		}

		// RING ONE
		if (RingOne)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidRingOne' AND Slot = 'RingOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidRingOne', 'RingOne', %u, %u, %u, %u, %u);"
			    , RingOne->GetEntry(), RingOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!RingOne)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in RingOne slot.");
		}

		// RING TWO
		if (RingTwo)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidRingTwo' AND Slot = 'RingTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidRingTwo', 'RingTwo', %u, %u, %u, %u, %u);"
			    , RingTwo->GetEntry(), RingTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!RingTwo)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in RingTwo slot.");
		}

		// TRINKET ONE
		if (TrinketOne)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidTrinketOne' AND Slot = 'TrinketOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidTrinketOne', 'TrinketOne', %u, %u, %u, %u, %u);"
			    , TrinketOne->GetEntry(), TrinketOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!TrinketOne)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in TrinketOne slot.");
		}

		// TRINKET TWO
		if (TrinketTwo)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidTrinketTwo' AND Slot = 'TrinketTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidTrinketTwo', 'TrinketTwo', %u, %u, %u, %u, %u);"
			    , TrinketTwo->GetEntry(), TrinketTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!TrinketTwo)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in TrinketTwo slot.");
		}

		// MAIN HAND
		if (MainHand)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidMainHand' AND Slot = 'MainHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidMainHand', 'MainHand', %u, %u, %u, %u, %u);"
			    , MainHand->GetEntry(), MainHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!MainHand)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in MainHand slot.");
		}

		// OFF HAND
		if (OffHand)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidOffHand' AND Slot = 'OffHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidOffHand', 'OffHand', %u, %u, %u, %u, %u);"
			    , OffHand->GetEntry(), OffHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!OffHand)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in OffHand slot.");
		}

		// RANGED
		if (Ranged)
		{
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'RestorationDruidRanged' AND Slot = 'Ranged';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('RestorationDruidRanged', 'Ranged', %u, %u, %u, %u, %u);"
			    , Ranged->GetEntry(), Ranged->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		}
		if (!Ranged)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Ranged slot.");
		}
		player->GetSession()->SendAreaTriggerMessage("You have just created a new itemset for Restoration Druid.");
        return true;
    }

	    static bool HandleCreateFrostMageItemSetCommand(ChatHandler* handler, const char* args)
    {
        Player* player = handler->GetSession()->GetPlayer();

		if (player->getClass() != CLASS_MAGE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a Mage!");
			return false;
		}

		Item* Head = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD);
		Item* Neck = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK);
		Item* Shoulders = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS);
		Item* Back = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
		Item* Chest = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
		Item* Wrists = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
		Item* Hands = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
		Item* Waist = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST);
		Item* Legs = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS);
		Item* Feet = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
		Item* RingOne = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1);
		Item* RingTwo = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2);
		Item* TrinketOne = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1);
		Item* TrinketTwo = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET2);
		Item* MainHand = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
		Item* OffHand = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
		Item* Ranged = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);

		// HEAD
		if (Head)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanHead' AND Slot = 'Head';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanHead', 'Head', %u, %u, %u, %u, %u);"
			    , Head->GetEntry(), Head->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHead' AND Slot = 'Head';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHead', 'Head', %u, %u, %u, %u, %u);"
			    , Head->GetEntry(), Head->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Head)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Head slot.");
		}

		// NECK
		if (Neck)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanNeck' AND Slot = 'Neck';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanNeck', 'Neck', %u, %u, %u, %u, %u);"
			    , Neck->GetEntry(), Neck->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageNeck' AND Slot = 'Neck';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageNeck', 'Neck', %u, %u, %u, %u, %u);"
			    , Neck->GetEntry(), Neck->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Neck)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Neck slot.");
		}

		// SHOULDERS
		if (Shoulders)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanShoulders' AND Slot = 'Shoulders';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanShoulders', 'Shoulders', %u, %u, %u, %u, %u);"
			    , Shoulders->GetEntry(), Shoulders->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageShoulders' AND Slot = 'Shoulders';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageShoulders', 'Shoulders', %u, %u, %u, %u, %u);"
			    , Shoulders->GetEntry(), Shoulders->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Shoulders)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Shoulders slot.");
		}

		// BACK
		if (Back)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanBack' AND Slot = 'Back';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanBack', 'Back', %u, %u, %u, %u, %u);"
			    , Back->GetEntry(), Back->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageBack' AND Slot = 'Back';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageBack', 'Back', %u, %u, %u, %u, %u);"
			    , Back->GetEntry(), Back->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Back)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Back slot.");
		}

		// CHEST
		if (Chest)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanChest' AND Slot = 'Chest';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanChest', 'Chest', %u, %u, %u, %u, %u);"
			    , Chest->GetEntry(), Chest->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageChest' AND Slot = 'Chest';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageChest', 'Chest', %u, %u, %u, %u, %u);"
			    , Chest->GetEntry(), Chest->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Chest)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Chest slot.");
		}

		// WRISTS
		if (Wrists)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanWrists' AND Slot = 'Wrists';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanWrists', 'Wrists', %u, %u, %u, %u, %u);"
			    , Wrists->GetEntry(), Wrists->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageWrists' AND Slot = 'Wrists';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageWrists', 'Wrists', %u, %u, %u, %u, %u);"
			    , Wrists->GetEntry(), Wrists->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Wrists)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Shoulders slot.");
		}

		// HANDS
		if (Hands)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanHands' AND Slot = 'Hands';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanHands', 'Hands', %u, %u, %u, %u, %u);"
			    , Hands->GetEntry(), Hands->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHands' AND Slot = 'Hands';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHands', 'Hands', %u, %u, %u, %u, %u);"
			    , Hands->GetEntry(), Hands->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Hands)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Hands slot.");
		}

		// WAIST
		if (Waist)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanWaist' AND Slot = 'Waist';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanWaist', 'Waist', %u, %u, %u, %u, %u);"
			    , Waist->GetEntry(), Waist->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageWaist' AND Slot = 'Waist';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageWaist', 'Waist', %u, %u, %u, %u, %u);"
			    , Waist->GetEntry(), Waist->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Waist)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Waist slot.");
		}

		// LEGS
		if (Legs)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanLegs' AND Slot = 'Legs';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanLegs', 'Legs', %u, %u, %u, %u, %u);"
			    , Legs->GetEntry(), Legs->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageLegs' AND Slot = 'Legs';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageLegs', 'Legs', %u, %u, %u, %u, %u);"
			    , Legs->GetEntry(), Legs->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Legs)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Legs slot.");
		}

		// FEET
		if (Feet)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanFeet' AND Slot = 'Feet';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanFeet', 'Feet', %u, %u, %u, %u, %u);"
			    , Feet->GetEntry(), Feet->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageFeet' AND Slot = 'Feet';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageFeet', 'Feet', %u, %u, %u, %u, %u);"
			    , Feet->GetEntry(), Feet->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Feet)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Feet slot.");
		}

		// RING ONE
		if (RingOne)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanRingOne' AND Slot = 'RingOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanRingOne', 'RingOne', %u, %u, %u, %u, %u);"
			    , RingOne->GetEntry(), RingOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageRingOne' AND Slot = 'RingOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageRingOne', 'RingOne', %u, %u, %u, %u, %u);"
			    , RingOne->GetEntry(), RingOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!RingOne)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in RingOne slot.");
		}

		// RING TWO
		if (RingTwo)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanRingTwo' AND Slot = 'RingTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanRingTwo', 'RingTwo', %u, %u, %u, %u, %u);"
			    , RingTwo->GetEntry(), RingTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageRingTwo' AND Slot = 'RingTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageRingTwo', 'RingTwo', %u, %u, %u, %u, %u);"
			    , RingTwo->GetEntry(), RingTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!RingTwo)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in RingTwo slot.");
		}

		// TRINKET ONE
		if (TrinketOne)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanTrinketOne' AND Slot = 'TrinketOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanTrinketOne', 'TrinketOne', %u, %u, %u, %u, %u);"
			    , TrinketOne->GetEntry(), TrinketOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageTrinketOne' AND Slot = 'TrinketOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageTrinketOne', 'TrinketOne', %u, %u, %u, %u, %u);"
			    , TrinketOne->GetEntry(), TrinketOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!TrinketOne)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in TrinketOne slot.");
		}

		// TRINKET TWO
		if (TrinketTwo)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanTrinketTwo' AND Slot = 'TrinketTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanTrinketTwo', 'TrinketTwo', %u, %u, %u, %u, %u);"
			    , TrinketTwo->GetEntry(), Wrists->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageTrinketTwo' AND Slot = 'TrinketTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageTrinketTwo', 'TrinketTwo', %u, %u, %u, %u, %u);"
			    , TrinketTwo->GetEntry(), TrinketTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!TrinketTwo)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in TrinketTwo slot.");
		}

		// MAIN HAND
		if (MainHand)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanMainHand' AND Slot = 'MainHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanMainHand', 'MainHand', %u, %u, %u, %u, %u);"
			    , MainHand->GetEntry(), MainHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageMainHand' AND Slot = 'MainHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageMainHand', 'MainHand', %u, %u, %u, %u, %u);"
			    , MainHand->GetEntry(), MainHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!MainHand)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in MainHand slot.");
		}

		// OFF HAND
		if (OffHand)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanOffHand' AND Slot = 'OffHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanOffHand', 'OffHand', %u, %u, %u, %u, %u);"
			    , OffHand->GetEntry(), OffHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageOffHand' AND Slot = 'OffHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageOffHand', 'OffHand', %u, %u, %u, %u, %u);"
			    , OffHand->GetEntry(), OffHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!OffHand)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in OffHand slot.");
		}

		// RANGED
		if (Ranged)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageHumanRanged' AND Slot = 'Ranged';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageHumanRanged', 'Ranged', %u, %u, %u, %u, %u);"
			    , Ranged->GetEntry(), Ranged->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'FrostMageRanged' AND Slot = 'Ranged';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('FrostMageRanged', 'Ranged', %u, %u, %u, %u, %u);"
			    , Ranged->GetEntry(), Ranged->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Ranged)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Ranged slot.");
		}
		player->GetSession()->SendAreaTriggerMessage("You have just created a new itemset for Frost Mage.");
        return true;
    }

	    static bool HandleCreateAssassinationRogueItemSetCommand(ChatHandler* handler, const char* args)
    {
        Player* player = handler->GetSession()->GetPlayer();

		if (player->getClass() != CLASS_ROGUE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a Rogue!");
			return false;
		}

		Item* Head = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HEAD);
		Item* Neck = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_NECK);
		Item* Shoulders = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_SHOULDERS);
		Item* Back = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK);
		Item* Chest = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
		Item* Wrists = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS);
		Item* Hands = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS);
		Item* Waist = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WAIST);
		Item* Legs = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS);
		Item* Feet = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET);
		Item* RingOne = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER1);
		Item* RingTwo = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FINGER2);
		Item* TrinketOne = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET1);
		Item* TrinketTwo = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_TRINKET2);
		Item* MainHand = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
		Item* OffHand = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
		Item* Ranged = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);

		// HEAD
		if (Head)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanHead' AND Slot = 'Head';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanHead', 'Head', %u, %u, %u, %u, %u);"
			    , Head->GetEntry(), Head->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHead' AND Slot = 'Head';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHead', 'Head', %u, %u, %u, %u, %u);"
			    , Head->GetEntry(), Head->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Head->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Head)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Head slot.");
		}

		// NECK
		if (Neck)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanNeck' AND Slot = 'Neck';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanNeck', 'Neck', %u, %u, %u, %u, %u);"
			    , Neck->GetEntry(), Neck->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueNeck' AND Slot = 'Neck';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueNeck', 'Neck', %u, %u, %u, %u, %u);"
			    , Neck->GetEntry(), Neck->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Neck->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Neck)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Neck slot.");
		}

		// SHOULDERS
		if (Shoulders)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanShoulders' AND Slot = 'Shoulders';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanShoulders', 'Shoulders', %u, %u, %u, %u, %u);"
			    , Shoulders->GetEntry(), Shoulders->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueShoulders' AND Slot = 'Shoulders';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueShoulders', 'Shoulders', %u, %u, %u, %u, %u);"
			    , Shoulders->GetEntry(), Shoulders->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Shoulders->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Shoulders)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Shoulders slot.");
		}

		// BACK
		if (Back)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanBack' AND Slot = 'Back';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanBack', 'Back', %u, %u, %u, %u, %u);"
			    , Back->GetEntry(), Back->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueBack' AND Slot = 'Back';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueBack', 'Back', %u, %u, %u, %u, %u);"
			    , Back->GetEntry(), Back->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Back->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Back)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Back slot.");
		}

		// CHEST
		if (Chest)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanChest' AND Slot = 'Chest';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanChest', 'Chest', %u, %u, %u, %u, %u);"
			    , Chest->GetEntry(), Chest->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueChest' AND Slot = 'Chest';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueChest', 'Chest', %u, %u, %u, %u, %u);"
			    , Chest->GetEntry(), Chest->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Chest->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Chest)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Chest slot.");
		}

		// WRISTS
		if (Wrists)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanWrists' AND Slot = 'Wrists';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanWrists', 'Wrists', %u, %u, %u, %u, %u);"
			    , Wrists->GetEntry(), Wrists->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueWrists' AND Slot = 'Wrists';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueWrists', 'Wrists', %u, %u, %u, %u, %u);"
			    , Wrists->GetEntry(), Wrists->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Wrists->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Wrists)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Shoulders slot.");
		}

		// HANDS
		if (Hands)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanHands' AND Slot = 'Hands';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanHands', 'Hands', %u, %u, %u, %u, %u);"
			    , Hands->GetEntry(), Hands->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHands' AND Slot = 'Hands';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHands', 'Hands', %u, %u, %u, %u, %u);"
			    , Hands->GetEntry(), Hands->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Hands->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Hands)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Hands slot.");
		}

		// WAIST
		if (Waist)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanWaist' AND Slot = 'Waist';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanWaist', 'Waist', %u, %u, %u, %u, %u);"
			    , Waist->GetEntry(), Waist->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueWaist' AND Slot = 'Waist';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueWaist', 'Waist', %u, %u, %u, %u, %u);"
			    , Waist->GetEntry(), Waist->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Waist->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Waist)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Waist slot.");
		}

		// LEGS
		if (Legs)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanLegs' AND Slot = 'Legs';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanLegs', 'Legs', %u, %u, %u, %u, %u);"
			    , Legs->GetEntry(), Legs->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueLegs' AND Slot = 'Legs';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueLegs', 'Legs', %u, %u, %u, %u, %u);"
			    , Legs->GetEntry(), Legs->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Legs->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Legs)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Legs slot.");
		}

		// FEET
		if (Feet)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanFeet' AND Slot = 'Feet';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanFeet', 'Feet', %u, %u, %u, %u, %u);"
			    , Feet->GetEntry(), Feet->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueFeet' AND Slot = 'Feet';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueFeet', 'Feet', %u, %u, %u, %u, %u);"
			    , Feet->GetEntry(), Feet->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Feet->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Feet)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Feet slot.");
		}

		// RING ONE
		if (RingOne)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanRingOne' AND Slot = 'RingOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanRingOne', 'RingOne', %u, %u, %u, %u, %u);"
			    , RingOne->GetEntry(), RingOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueRingOne' AND Slot = 'RingOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueRingOne', 'RingOne', %u, %u, %u, %u, %u);"
			    , RingOne->GetEntry(), RingOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!RingOne)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in RingOne slot.");
		}

		// RING TWO
		if (RingTwo)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanRingTwo' AND Slot = 'RingTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanRingTwo', 'RingTwo', %u, %u, %u, %u, %u);"
			    , RingTwo->GetEntry(), RingTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueRingTwo' AND Slot = 'RingTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueRingTwo', 'RingTwo', %u, %u, %u, %u, %u);"
			    , RingTwo->GetEntry(), RingTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), RingTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!RingTwo)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in RingTwo slot.");
		}

		// TRINKET ONE
		if (TrinketOne)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanTrinketOne' AND Slot = 'TrinketOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanTrinketOne', 'TrinketOne', %u, %u, %u, %u, %u);"
			    , TrinketOne->GetEntry(), TrinketOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueTrinketOne' AND Slot = 'TrinketOne';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueTrinketOne', 'TrinketOne', %u, %u, %u, %u, %u);"
			    , TrinketOne->GetEntry(), TrinketOne->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketOne->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!TrinketOne)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in TrinketOne slot.");
		}

		// TRINKET TWO
		if (TrinketTwo)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanTrinketTwo' AND Slot = 'TrinketTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanTrinketTwo', 'TrinketTwo', %u, %u, %u, %u, %u);"
			    , TrinketTwo->GetEntry(), Wrists->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueTrinketTwo' AND Slot = 'TrinketTwo';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueTrinketTwo', 'TrinketTwo', %u, %u, %u, %u, %u);"
			    , TrinketTwo->GetEntry(), TrinketTwo->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), TrinketTwo->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!TrinketTwo)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in TrinketTwo slot.");
		}

		// MAIN HAND
		if (MainHand)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanMainHand' AND Slot = 'MainHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanMainHand', 'MainHand', %u, %u, %u, %u, %u);"
			    , MainHand->GetEntry(), MainHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueMainHand' AND Slot = 'MainHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueMainHand', 'MainHand', %u, %u, %u, %u, %u);"
			    , MainHand->GetEntry(), MainHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), MainHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!MainHand)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in MainHand slot.");
		}

		// OFF HAND
		if (OffHand)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanOffHand' AND Slot = 'OffHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanOffHand', 'OffHand', %u, %u, %u, %u, %u);"
			    , OffHand->GetEntry(), OffHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueOffHand' AND Slot = 'OffHand';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueOffHand', 'OffHand', %u, %u, %u, %u, %u);"
			    , OffHand->GetEntry(), OffHand->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), OffHand->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!OffHand)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in OffHand slot.");
		}

		// RANGED
		if (Ranged)
		{
		    if (player->getRace() == RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueHumanRanged' AND Slot = 'Ranged';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueHumanRanged', 'Ranged', %u, %u, %u, %u, %u);"
			    , Ranged->GetEntry(), Ranged->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		    if (player->getRace() != RACE_HUMAN)
		    {
			    CharacterDatabase.PExecute("DELETE FROM clickandplay_templates WHERE Description = 'AssassinationRogueRanged' AND Slot = 'Ranged';");
			    CharacterDatabase.PExecute("INSERT INTO `clickandplay_templates` (`Description`, `Slot`, `Item`, `Enchant`, `SocketOne`, `SocketTwo`, `SocketThree`) VALUES ('AssassinationRogueRanged', 'Ranged', %u, %u, %u, %u, %u);"
			    , Ranged->GetEntry(), Ranged->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), Ranged->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3));
		    }
		}
		if (!Ranged)
		{
		    player->GetSession()->SendAreaTriggerMessage("You dont have equipped item in Ranged slot.");
		}
		player->GetSession()->SendAreaTriggerMessage("You have just created a new itemset for Assassination Rogue.");
        return true;
    }
};

void AddSC_createItemSet_commandscript()
{
    new createItemSet_commandscript();
}