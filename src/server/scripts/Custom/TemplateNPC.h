////////////////////////////////////////////////////////////
//                                                        //
//          Developed by @JessiqueBA (ac-web.org)         //
//                                                        //
////////////////////////////////////////////////////////////

#ifndef TALENT_FUNCTIONS_H
#define TALENT_FUNCTIONS_H

std::string spec;

enum templateSpells
{
	PLATE_MAIL = 750,
	MAIL       = 8737
};

enum WeaponProficiencies
{
	BLOCK           = 107,
	BOWS            = 264,
	CROSSBOWS       = 5011,
	DAGGERS         = 1180,
	FIST_WEAPONS    = 15590,
	GUNS            = 266,
	ONE_H_AXES      = 196,
	ONE_H_MACES     = 198,
	ONE_H_SWORDS    = 201,
	POLEARMS        = 200,
	SHOOT           = 5019,
	STAVES          = 227,
	TWO_H_AXES      = 197,
	TWO_H_MACES     = 199,
	TWO_H_SWORDS    = 202,
	WANDS           = 5009
};

static void LearnWeaponSkills(Player* player)
{
	WeaponProficiencies wepSkills[] = {
		BLOCK, BOWS, CROSSBOWS, DAGGERS, FIST_WEAPONS, GUNS, ONE_H_AXES, ONE_H_MACES,
		ONE_H_SWORDS, POLEARMS, SHOOT, STAVES, TWO_H_AXES, TWO_H_MACES, TWO_H_SWORDS, WANDS
	};

	uint32 size = 16;

	for (uint32 i = 0; i < size; ++i)
		if (player->HasSpell(wepSkills[i]))
			continue;

	switch (player->getClass())
	{
	case CLASS_WARRIOR:
		player->learnSpell(TWO_H_SWORDS, false);
		player->learnSpell(TWO_H_MACES, false);
		player->learnSpell(TWO_H_AXES, false);
		player->learnSpell(STAVES, false);
		player->learnSpell(POLEARMS, false);
		player->learnSpell(ONE_H_SWORDS, false);
		player->learnSpell(ONE_H_MACES, false);
		player->learnSpell(ONE_H_AXES, false);
		player->learnSpell(GUNS, false);
		player->learnSpell(FIST_WEAPONS, false);
		player->learnSpell(DAGGERS, false);
		player->learnSpell(CROSSBOWS, false);
		player->learnSpell(BOWS, false);
		player->learnSpell(BLOCK, false);
		break;
	case CLASS_PRIEST:
		player->learnSpell(WANDS, false);
		player->learnSpell(STAVES, false);
		player->learnSpell(SHOOT, false);
		player->learnSpell(ONE_H_MACES, false);
		player->learnSpell(DAGGERS, false);
		break;
	case CLASS_PALADIN:
		player->learnSpell(TWO_H_SWORDS, false);
		player->learnSpell(TWO_H_MACES, false);
		player->learnSpell(TWO_H_AXES, false);
		player->learnSpell(POLEARMS, false);
		player->learnSpell(ONE_H_SWORDS, false);
		player->learnSpell(ONE_H_MACES, false);
		player->learnSpell(ONE_H_AXES, false);
		player->learnSpell(BLOCK, false);
		break;
	case CLASS_ROGUE:
		player->learnSpell(ONE_H_SWORDS, false);
		player->learnSpell(ONE_H_MACES, false);
		player->learnSpell(ONE_H_AXES, false);
		player->learnSpell(GUNS, false);
		player->learnSpell(FIST_WEAPONS, false);
		player->learnSpell(DAGGERS, false);
		player->learnSpell(CROSSBOWS, false);
		player->learnSpell(BOWS, false);
		break;
	case CLASS_DEATH_KNIGHT:
		player->learnSpell(TWO_H_SWORDS, false);
		player->learnSpell(TWO_H_MACES, false);
		player->learnSpell(TWO_H_AXES, false);
		player->learnSpell(POLEARMS, false);
		player->learnSpell(ONE_H_SWORDS, false);
		player->learnSpell(ONE_H_MACES, false);
		player->learnSpell(ONE_H_AXES, false);
		break;
	case CLASS_MAGE:
		player->learnSpell(WANDS, false);
		player->learnSpell(STAVES, false);
		player->learnSpell(SHOOT, false);
		player->learnSpell(ONE_H_SWORDS, false);
		player->learnSpell(DAGGERS, false);
		break;
	case CLASS_SHAMAN:
		player->learnSpell(TWO_H_MACES, false);
		player->learnSpell(TWO_H_AXES, false);
		player->learnSpell(STAVES, false);
		player->learnSpell(ONE_H_MACES, false);
		player->learnSpell(ONE_H_AXES, false);
		player->learnSpell(FIST_WEAPONS, false);
		player->learnSpell(DAGGERS, false);
		player->learnSpell(BLOCK, false);
		break;
	case CLASS_HUNTER:
		player->learnSpell(TWO_H_SWORDS, false);
		player->learnSpell(TWO_H_AXES, false);
		player->learnSpell(STAVES, false);
		player->learnSpell(POLEARMS, false);
		player->learnSpell(ONE_H_SWORDS, false);
		player->learnSpell(ONE_H_AXES, false);
		player->learnSpell(GUNS, false);
		player->learnSpell(FIST_WEAPONS, false);
		player->learnSpell(DAGGERS, false);
		player->learnSpell(CROSSBOWS, false);
		player->learnSpell(BOWS, false);
		break;
	case CLASS_DRUID:
		player->learnSpell(TWO_H_MACES, false);
		player->learnSpell(STAVES, false);
		player->learnSpell(POLEARMS, false);
		player->learnSpell(ONE_H_MACES, false);
		player->learnSpell(FIST_WEAPONS, false);
		player->learnSpell(DAGGERS, false);
		break;
	case CLASS_WARLOCK:
		player->learnSpell(WANDS, false);
		player->learnSpell(STAVES, false);
		player->learnSpell(SHOOT, false);
		player->learnSpell(ONE_H_SWORDS, false);
		player->learnSpell(DAGGERS, false);
		break;
	default:
		break;
	}
}

std::string GetClassString(Player* player)
{
	switch (player->getClass())
	{
	case CLASS_PRIEST:
		return "Priest";
		break;
	case CLASS_PALADIN:
		return "Paladin";
		break;
	case CLASS_WARRIOR:
		return "Warrior";
		break;
	case CLASS_MAGE:
		return "Mage";
		break;
	case CLASS_WARLOCK:
		return "Warlock";
		break;
	case CLASS_SHAMAN:
		return "Shaman";
		break;
	case CLASS_DRUID:
		return "Druid";
		break;
	case CLASS_HUNTER:
		return "Hunter";
		break;
	case CLASS_ROGUE:
		return "Rogue";
		break;
	case CLASS_DEATH_KNIGHT:
		return "DeathKnight";
		break;
	default:
		break;
	}
	return ""; // Fix warning, this should never happen
}

static bool OverwriteTemplate(Player* player, std::string& playerSpecStr)
{
	// Delete old talent and glyph templates before extracting new ones
	CharacterDatabase.PExecute("DELETE FROM template_npc_talents WHERE playerClass = '%s' AND playerSpec = '%s';", GetClassString(player).c_str(), playerSpecStr.c_str());
	CharacterDatabase.PExecute("DELETE FROM template_npc_glyphs WHERE playerClass = '%s' AND playerSpec = '%s';", GetClassString(player).c_str(), playerSpecStr.c_str());

	// Delete old gear templates before extracting new ones
	if (player->getRace() == RACE_HUMAN)
	{
		CharacterDatabase.PExecute("DELETE FROM template_npc_human WHERE playerClass = '%s' AND playerSpec = '%s';", GetClassString(player).c_str(), playerSpecStr.c_str());
		player->GetSession()->SendAreaTriggerMessage("Template successfuly created!");
		return false;
	}
	else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
	{
		CharacterDatabase.PExecute("DELETE FROM template_npc_alliance WHERE playerClass = '%s' AND playerSpec = '%s';", GetClassString(player).c_str(), playerSpecStr.c_str());
		player->GetSession()->SendAreaTriggerMessage("Template successfuly created!");
		return false;
	}
	else if (player->GetTeam() == HORDE)
	{
		CharacterDatabase.PExecute("DELETE FROM template_npc_horde WHERE playerClass = '%s' AND playerSpec = '%s';", GetClassString(player).c_str(), playerSpecStr.c_str());
		player->GetSession()->SendAreaTriggerMessage("Template successfuly created!");
		return false;
	}
	return true;
}

static void ExtractGearTemplateToDB(Player* player, std::string& playerSpecStr)
{
	for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
	{
		Item* equippedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);

		if (equippedItem)
		{
			if (player->getRace() == RACE_HUMAN)
			{
				CharacterDatabase.PExecute("INSERT INTO template_npc_human (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('%s', '%s', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
					, GetClassString(player).c_str(), playerSpecStr.c_str(), equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), 
					equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
					equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
			}
			else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
			{
				CharacterDatabase.PExecute("INSERT INTO template_npc_alliance (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('%s', '%s', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
					, GetClassString(player).c_str(), playerSpecStr.c_str(), equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), 
					equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
					equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
			}
			else if (player->GetTeam() == HORDE)
			{
				CharacterDatabase.PExecute("INSERT INTO template_npc_horde (`playerClass`, `playerSpec`, `pos`, `itemEntry`, `enchant`, `socket1`, `socket2`, `socket3`, `bonusEnchant`, `prismaticEnchant`) VALUES ('%s', '%s', '%u', '%u', '%u', '%u', '%u', '%u', '%u', '%u');"
					, GetClassString(player).c_str(), playerSpecStr.c_str(), equippedItem->GetSlot(), equippedItem->GetEntry(), equippedItem->GetEnchantmentId(PERM_ENCHANTMENT_SLOT), 
					equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_2), equippedItem->GetEnchantmentId(SOCK_ENCHANTMENT_SLOT_3),
					equippedItem->GetEnchantmentId(BONUS_ENCHANTMENT_SLOT), equippedItem->GetEnchantmentId(PRISMATIC_ENCHANTMENT_SLOT));
			}
		}
	}
}

static void ExtractTalentTemplateToDB(Player* player, std::string& playerSpecStr)
{
	QueryResult result = CharacterDatabase.PQuery("SELECT spell FROM character_talent WHERE guid = '%u' "
		"AND spec = '%u';", player->GetGUID(), player->GetActiveSpec());

	if (!result)
	{
		return;
	}
	else if (player->GetFreeTalentPoints() > 0)
	{
		player->GetSession()->SendAreaTriggerMessage("You have unspend talent points. Please spend all your talent points and re-extract the template.");
		return;
	}
	else
	{
		do
		{
			Field* fields = result->Fetch(); 
			uint32 spell = fields[0].GetUInt32();

			CharacterDatabase.PExecute("INSERT INTO template_npc_talents (playerClass, playerSpec, talentId) "
				"VALUES ('%s', '%s', '%u');", GetClassString(player).c_str(), playerSpecStr.c_str(), spell);
		}
		while (result->NextRow());
	}
}

static void ExtractGlyphsTemplateToDB(Player* player, std::string& playerSpecStr)
{
	for (uint8 slot = 0; slot < MAX_GLYPH_SLOT_INDEX; ++slot)
	{
		QueryResult result = CharacterDatabase.PQuery("SELECT glyph1, glyph2, glyph3, glyph4, glyph5, glyph6 "
			"FROM character_glyphs WHERE guid = '%u' AND spec = '%u';", player->GetGUID(), player->GetActiveSpec());

		if (!result)
		{ 
			player->GetSession()->SendAreaTriggerMessage("Get glyphs and re-extract the template!");
			continue;
		}

		Field* fields = result->Fetch();
		uint32 glyph1 = fields[0].GetUInt32();
		uint32 glyph2 = fields[1].GetUInt32();
		uint32 glyph3 = fields[2].GetUInt32();
		uint32 glyph4 = fields[3].GetUInt32();
		uint32 glyph5 = fields[4].GetUInt32();
		uint32 glyph6 = fields[5].GetUInt32();

		uint32 storedGlyph;

		switch (slot)
		{
		case 0:
			storedGlyph = glyph1;
			break;
		case 1:
			storedGlyph = glyph2;
			break;
		case 2:
			storedGlyph = glyph3;
			break;
		case 3:
			storedGlyph = glyph4;
			break;
		case 4:
			storedGlyph = glyph5;
			break;
		case 5:
			storedGlyph = glyph6;
			break;
		default:
			break;
		}

		CharacterDatabase.PExecute("INSERT INTO template_npc_glyphs (playerClass, playerSpec, slot, glyph) "
			"VALUES ('%s', '%s', '%u', '%u');", GetClassString(player).c_str(), playerSpecStr.c_str(), slot, storedGlyph);
	}
}

static bool CanEquipTemplate(Player* player, std::string& playerSpecStr)
{
	if (player->getRace() == RACE_HUMAN)
	{
		QueryResult result = CharacterDatabase.PQuery("SELECT playerClass, playerSpec FROM template_npc_human "
			"WHERE playerClass = '%s' AND playerSpec = '%s';", GetClassString(player).c_str(), playerSpecStr.c_str());

		if (!result)
			return false;
	}
	else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
	{
		QueryResult result = CharacterDatabase.PQuery("SELECT playerClass, playerSpec FROM template_npc_alliance "
			"WHERE playerClass = '%s' AND playerSpec = '%s';", GetClassString(player).c_str(), playerSpecStr.c_str());

		if (!result)
			return false;
	}
	else if (player->GetTeam() == HORDE)
	{
		QueryResult result = CharacterDatabase.PQuery("SELECT playerClass, playerSpec FROM template_npc_horde "
			"WHERE playerClass = '%s' AND playerSpec = '%s';", GetClassString(player).c_str(), playerSpecStr.c_str());

		if (!result)
			return false;
	}
	return true;
}

#endif