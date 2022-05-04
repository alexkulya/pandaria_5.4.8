////////////////////////////////////////////////////////////
//                                                        //
//          Developed by @JessiqueBA (ac-web.org)         //
//                                                        //
////////////////////////////////////////////////////////////

#include "ScriptPCH.h"
#include "TemplateNPC.h"

class TemplateNPC_Commands : public CommandScript
{
public:
	TemplateNPC_Commands() : CommandScript("TemplateNPC_Commands") { }

	ChatCommand* GetCommands() const
	{
		static ChatCommand createDeathKnightItemSetTable[] =
		{
			{ "blood",             SEC_ADMINISTRATOR,         false,          &HandleCreateDeathKnightBloodItemSetCommand,       "", NULL },
			{ "frost",             SEC_ADMINISTRATOR,         false,          &HandleCreateDeathKnightFrostItemSetCommand,       "", NULL },
			{ "unholy",            SEC_ADMINISTRATOR,         false,          &HandleCreateDeathKnightUnholyItemSetCommand,      "", NULL },
			{ NULL,                0,                         false,          NULL,                                              "", NULL }
		};
		static ChatCommand createRogueItemSetTable[] =
		{
			{ "assassination",     SEC_ADMINISTRATOR,         false,          &HandleCreateRogueAssassinationItemSetCommand,     "", NULL },
			{ "combat",            SEC_ADMINISTRATOR,         false,          &HandleCreateRogueCombatItemSetCommand,            "", NULL },
			{ "subtlety",          SEC_ADMINISTRATOR,         false,          &HandleCreateRogueSubtletyItemSetCommand,          "", NULL },
			{ NULL,                0,                         false,          NULL,                                              "", NULL }
		};
		static ChatCommand createHunterItemSetTable[] =
		{
			{ "marksmanship",      SEC_ADMINISTRATOR,         false,          &HandleCreateHunterMarksmanshipItemSetCommand,     "", NULL },
			{ "beastmastery",      SEC_ADMINISTRATOR,         false,          &HandleCreateHunterBeastmasteryItemSetCommand,     "", NULL },
			{ "survival",          SEC_ADMINISTRATOR,         false,          &HandleCreateHunterSurvivalItemSetCommand,         "", NULL },
			{ NULL,                0,                         false,          NULL,                                              "", NULL }
		};
		static ChatCommand createDruidItemSetTable[] =
		{
			{ "ballance",          SEC_ADMINISTRATOR,         false,          &HandleCreateDruidBallanceItemSetCommand,          "", NULL },
			{ "feral",             SEC_ADMINISTRATOR,         false,          &HandleCreateDruidFeralItemSetCommand,             "", NULL },
			{ "restoration",       SEC_ADMINISTRATOR,         false,          &HandleCreateDruidRestorationItemSetCommand,       "", NULL },
			{ NULL,                0,                         false,          NULL,                                              "", NULL }
		};
		static ChatCommand createShamanItemSetTable[] =
		{
			{ "elemental",         SEC_ADMINISTRATOR,         false,          &HandleCreateShamanElementalItemSetCommand,        "", NULL },
			{ "enhancement",       SEC_ADMINISTRATOR,         false,          &HandleCreateShamanEnhancementItemSetCommand,      "", NULL },
			{ "restoration",       SEC_ADMINISTRATOR,         false,          &HandleCreateShamanRestorationItemSetCommand,      "", NULL },
			{ NULL,                0,                         false,          NULL,                                              "", NULL }
		};
		static ChatCommand createWarlockItemSetTable[] =
		{
			{ "affliction",        SEC_ADMINISTRATOR,         false,          &HandleCreateWarlockAfflictionItemSetCommand,      "", NULL },
			{ "demonology",        SEC_ADMINISTRATOR,         false,          &HandleCreateWarlockDemonologyItemSetCommand,      "", NULL },
			{ "destruction",       SEC_ADMINISTRATOR,         false,          &HandleCreateWarlockDestructionItemSetCommand,     "", NULL },
			{ NULL,                0,                         false,          NULL,                                              "", NULL }
		};
		static ChatCommand createMageItemSetTable[] =
		{
			{ "frost",             SEC_ADMINISTRATOR,         false,          &HandleCreateMageFrostItemSetCommand,              "", NULL },
			{ "fire",              SEC_ADMINISTRATOR,         false,          &HandleCreateMageFireItemSetCommand,               "", NULL },
			{ "arcane",            SEC_ADMINISTRATOR,         false,          &HandleCreateMageArcaneItemSetCommand,             "", NULL },
			{ NULL,                0,                         false,          NULL,                                              "", NULL }
		};
		static ChatCommand createWarriorItemSetTable[] =
		{
			{ "arms",              SEC_ADMINISTRATOR,         false,          &HandleCreateWarriorArmsItemSetCommand,            "", NULL },
			{ "fury",              SEC_ADMINISTRATOR,         false,          &HandleCreateWarriorFuryItemSetCommand,            "", NULL },
			{ "protection",        SEC_ADMINISTRATOR,         false,          &HandleCreateWarriorProtectionItemSetCommand,      "", NULL },
			{ NULL,                0,                         false,          NULL,                                              "", NULL }
		};
		static ChatCommand createPaladinItemSetTable[] =
		{
			{ "holy",              SEC_ADMINISTRATOR,         false,          &HandleCreatePaladinHolyItemSetCommand,            "", NULL },
			{ "protection",        SEC_ADMINISTRATOR,         false,          &HandleCreatePaladinProtectionItemSetCommand,      "", NULL },
			{ "retribution",       SEC_ADMINISTRATOR,         false,          &HandleCreatePaladinRetributionItemSetCommand,     "", NULL },
			{ NULL,                0,                         false,          NULL,                                              "", NULL }
		};

		static ChatCommand createPriestItemSetTable[] =
		{
			{ "discipline",        SEC_ADMINISTRATOR,         false,          &HandleCreatePriestDisciplineItemSetCommand,       "", NULL },
			{ "shadow",            SEC_ADMINISTRATOR,         false,          &HandleCreatePriestShadowItemSetCommand,           "", NULL },
			{ "holy",              SEC_ADMINISTRATOR,         false,          &HandleCreatePriestHolyItemSetCommand,             "", NULL },
			{ NULL,                0,                         false,          NULL,                                              "", NULL }
		};
		static ChatCommand createItemSetCommandTable[] =
		{
			{ "priest",            SEC_ADMINISTRATOR,          true,            NULL,         "", createPriestItemSetTable },
			{ "paladin",           SEC_ADMINISTRATOR,          true,            NULL,         "", createPaladinItemSetTable },
			{ "warrior",           SEC_ADMINISTRATOR,          true,            NULL,         "", createWarriorItemSetTable },
			{ "mage",              SEC_ADMINISTRATOR,          true,            NULL,         "", createMageItemSetTable },
			{ "warlock",           SEC_ADMINISTRATOR,          true,            NULL,         "", createWarlockItemSetTable },
			{ "shaman",            SEC_ADMINISTRATOR,          true,            NULL,         "", createShamanItemSetTable },
			{ "druid",             SEC_ADMINISTRATOR,          true,            NULL,         "", createDruidItemSetTable },
			{ "hunter",            SEC_ADMINISTRATOR,          true,            NULL,         "", createHunterItemSetTable },
			{ "rogue",             SEC_ADMINISTRATOR,          true,            NULL,         "", createRogueItemSetTable },
			{ "deathknight",       SEC_ADMINISTRATOR,          true,            NULL,         "", createDeathKnightItemSetTable },
			{ NULL,                0,                          false,           NULL,         "", NULL }
		};
		static ChatCommand commandTable[] =
		{
			{ "create",            SEC_ADMINISTRATOR,         true, NULL,                 "", createItemSetCommandTable },
			{ NULL,                0,                         false, NULL,                "", NULL }
		};
		return commandTable;
	}

	// DISCIPLINE PRIEST
	static bool HandleCreatePriestDisciplineItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();

		if (player->getClass() != CLASS_PRIEST)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a priest!");
			return false;
		}
		spec = "Discipline";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// SHADOW PRIEST
	static bool HandleCreatePriestShadowItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_PRIEST)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a priest!");
			return false;
		}
		spec = "Shadow";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// HOLY PRIEST
	static bool HandleCreatePriestHolyItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_PRIEST)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a priest!");
			return false;
		}
		spec = "Holy";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// HOLY PALADIN
	static bool HandleCreatePaladinHolyItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_PALADIN)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}
		spec = "Holy";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// PROTECTION PALADIN
	static bool HandleCreatePaladinProtectionItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_PALADIN)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}
		spec = "Protection";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// RETRIBUTION PALADIN
	static bool HandleCreatePaladinRetributionItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_PALADIN)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a paladin!");
			return false;
		}
		spec = "Retribution";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// FURY WARRIOR
	static bool HandleCreateWarriorFuryItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_WARRIOR)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a warrior!");
			return false;
		}
		spec = "Fury";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// ARMS WARRIOR
	static bool HandleCreateWarriorArmsItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_WARRIOR)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a warrior!");
			return false;
		}
		spec = "Arms";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// PROTECTION WARRIOR
	static bool HandleCreateWarriorProtectionItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_WARRIOR)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a warrior!");
			return false;
		}
		spec = "Protection";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// ARCANE MAGE
	static bool HandleCreateMageArcaneItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_MAGE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a mage!");
			return false;
		}
		spec = "Arcane";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// FIRE MAGE
	static bool HandleCreateMageFireItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_MAGE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a mage!");
			return false;
		}
		spec = "Fire";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// FROST MAGE
	static bool HandleCreateMageFrostItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_MAGE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a mage!");
			return false;
		}
		spec = "Frost";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// AFFLICTION WARLOCK
	static bool HandleCreateWarlockAfflictionItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_WARLOCK)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a warlock!");
			return false;
		}
		spec = "Affliction";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// DEMONOLOGY WARLOCK
	static bool HandleCreateWarlockDemonologyItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_WARLOCK)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a warlock!");
			return false;
		}
		spec = "Demonology";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// DESTRUCTION WARLOCK
	static bool HandleCreateWarlockDestructionItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_WARLOCK)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a warlock!");
			return false;
		}
		spec = "Destruction";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// ELEMENTAL SHAMAN
	static bool HandleCreateShamanElementalItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_SHAMAN)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a shaman!");
			return false;
		}
		spec = "Elemental";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// ENHANCEMENT SHAMAN
	static bool HandleCreateShamanEnhancementItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_SHAMAN)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a shaman!");
			return false;
		}
		spec = "Enhancement";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// RESTORATION SHAMAN
	static bool HandleCreateShamanRestorationItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_SHAMAN)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a shaman!");
			return false;
		}
		spec = "Restoration";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// BALLANCE DRUID
	static bool HandleCreateDruidBallanceItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_DRUID)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a druid!");
			return false;
		}
		spec = "Ballance";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// FERAL DRUID
	static bool HandleCreateDruidFeralItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_DRUID)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a druid!");
			return false;
		}
		spec = "Feral";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// RESTORATION DRUID
	static bool HandleCreateDruidRestorationItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_DRUID)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a druid!");
			return false;
		}
		spec = "Restoration";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// MARKSMANSHIP HUNTER
	static bool HandleCreateHunterMarksmanshipItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_HUNTER)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a hunter!");
			return false;
		}
		spec = "Marksmanship";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// BEASTMASTERY HUNTER
	static bool HandleCreateHunterBeastmasteryItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_HUNTER)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a hunter!");
			return false;
		}
		spec = "Beastmastery";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// SURVIVAL HUNTER
	static bool HandleCreateHunterSurvivalItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_HUNTER)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a hunter!");
			return false;
		}
		spec = "Survival";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// ASSASSINATION ROGUE
	static bool HandleCreateRogueAssassinationItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_ROGUE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a rogue!");
			return false;
		}
		spec = "Assassination";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// COMBAT ROGUE
	static bool HandleCreateRogueCombatItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_ROGUE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a rogue!");
			return false;
		}
		spec = "Combat";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// SUBTLETY ROGUE
	static bool HandleCreateRogueSubtletyItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_ROGUE)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a rogue!");
			return false;
		}
		spec = "Subtlety";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// BLOOD DEATHKNIGHT
	static bool HandleCreateDeathKnightBloodItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_DEATH_KNIGHT)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a death knight!");
			return false;
		}
		spec = "Blood";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// FROST DEATHKNIGHT
	static bool HandleCreateDeathKnightFrostItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_DEATH_KNIGHT)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a death knight!");
			return false;
		}
		spec = "Frost";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}

	// UNHOLY DEATHKNIGHT
	static bool HandleCreateDeathKnightUnholyItemSetCommand(ChatHandler* handler, const char* args)
	{
		Player* player = handler->GetSession()->GetPlayer();
		if (player->getClass() != CLASS_DEATH_KNIGHT)
		{
			player->GetSession()->SendAreaTriggerMessage("You're not a death knight!");
			return false;
		}
		spec = "Unholy";
		player->SaveToDB();
		OverwriteTemplate(player, spec);
		ExtractGearTemplateToDB(player, spec);
		ExtractTalentTemplateToDB(player, spec);
		ExtractGlyphsTemplateToDB(player, spec);
		return true;
	}
};

class TemplateNPC : public CreatureScript
{
public:
	TemplateNPC() : CreatureScript("TemplateNPC") { }

	void ApplyGlyph(Player* player, uint8 slot, uint32 glyphID)
	{
		if (GlyphPropertiesEntry const* gp = sGlyphPropertiesStore.LookupEntry(glyphID))
		{
			if (uint32 oldGlyph = player->GetGlyph(slot))
			{
				player->RemoveAurasDueToSpell(sGlyphPropertiesStore.LookupEntry(oldGlyph)->SpellId);
				player->SetGlyph(slot, 0);
			}

			player->CastSpell(player, gp->SpellId, true);
			player->SetGlyph(slot, glyphID);
		}
	}

	void SetTemplateGlyphs(Player* player, std::string& playerSpecStr)
	{
		for (uint8 slot = 0; slot < MAX_GLYPH_SLOT_INDEX; ++slot)
		{
			QueryResult result = CharacterDatabase.PQuery("SELECT glyph FROM template_npc_glyphs "
				"WHERE playerClass = '%s' AND playerSpec = '%s' AND slot = '%u';", GetClassString(player).c_str(), playerSpecStr.c_str(), slot);

			if (!result)
				continue;

			Field* fields = result->Fetch();
			uint32 glyph = fields[0].GetUInt32();

			ApplyGlyph(player, slot, glyph);
		}
		player->SendTalentsInfoData(false);
	}

	void SetTemplateTalents(Player* player, std::string& playerSpecStr)
	{
		QueryResult select = CharacterDatabase.PQuery("SELECT talentId FROM template_npc_talents WHERE playerClass = '%s' AND "
			"playerSpec = '%s';", GetClassString(player).c_str(), playerSpecStr.c_str());

		if (!select)
		{ 
			return;
		}
		else
		{
			do
			{
				Field* fields = select->Fetch(); 
				uint32 talentId = fields[0].GetUInt32(); 

				player->learnSpell(talentId, false);
				player->AddTalent(talentId, player->GetActiveSpec(), true);
			}
			while (select->NextRow());
			player->SetFreeTalentPoints(0);
			player->SendTalentsInfoData(false);
		}
	}

	void ApplyBonus(Player* player, Item* item, EnchantmentSlot slot, uint32 bonusEntry)
	{
		if (!item)
			return;

		if (!bonusEntry || bonusEntry == 0)
			return;

		player->ApplyEnchantment(item, slot, false);
		item->SetEnchantment(slot, bonusEntry, 0, 0);
		player->ApplyEnchantment(item, slot, true);
	}

	void EquipTmpGear(Player* player, std::string& playerSpecStr)
	{
		if (player->getRace() == RACE_HUMAN)
		{
			for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
			{
				QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
					"FROM template_npc_human WHERE playerClass = '%s' AND playerSpec = '%s' AND pos = '%u';", GetClassString(player).c_str(), playerSpecStr.c_str(), equipmentSlot);

				if (!result)
					continue;

				Field* fields = result->Fetch(); 
				uint32 itemEntry = fields[0].GetUInt32(); 
				uint32 enchant = fields[1].GetUInt32(); 
				uint32 socket1 = fields[2].GetUInt32(); 
				uint32 socket2 = fields[3].GetUInt32(); 
				uint32 socket3 = fields[4].GetUInt32(); 
				uint32 bonusEnchant = fields[5].GetUInt32(); 
				uint32 prismaticEnchant = fields[6].GetUInt32();

				// Equip Gear
				player->EquipNewItem(equipmentSlot, itemEntry, true);

				// Apply Enchants and Gems
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
			}
		}
		else if (player->GetTeam() == ALLIANCE && player->getRace() != RACE_HUMAN)
		{
			for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
			{
				QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
					"FROM template_npc_alliance WHERE playerClass = '%s' AND playerSpec = '%s' AND pos = '%u';", GetClassString(player).c_str(), playerSpecStr.c_str(), equipmentSlot);

				if (!result)
					continue;

				Field* fields = result->Fetch(); 
				uint32 itemEntry = fields[0].GetUInt32(); 
				uint32 enchant = fields[1].GetUInt32(); 
				uint32 socket1 = fields[2].GetUInt32(); 
				uint32 socket2 = fields[3].GetUInt32(); 
				uint32 socket3 = fields[4].GetUInt32(); 
				uint32 bonusEnchant = fields[5].GetUInt32(); 
				uint32 prismaticEnchant = fields[6].GetUInt32();

				// Equip Gear
				player->EquipNewItem(equipmentSlot, itemEntry, true);

				// Apply Enchants and Gems
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
			}
		}
		else if (player->GetTeam() == HORDE)
		{
			for (uint8 equipmentSlot = EQUIPMENT_SLOT_START; equipmentSlot < EQUIPMENT_SLOT_END; ++equipmentSlot)
			{
				QueryResult result = CharacterDatabase.PQuery("SELECT itemEntry, enchant, socket1, socket2, socket3, bonusEnchant, prismaticEnchant "
					"FROM template_npc_horde WHERE playerClass = '%s' AND playerSpec = '%s' AND pos = '%u';", GetClassString(player).c_str(), playerSpecStr.c_str(), equipmentSlot);

				if (!result)
					continue;

				Field* fields = result->Fetch(); 
				uint32 itemEntry = fields[0].GetUInt32(); 
				uint32 enchant = fields[1].GetUInt32(); 
				uint32 socket1 = fields[2].GetUInt32(); 
				uint32 socket2 = fields[3].GetUInt32(); 
				uint32 socket3 = fields[4].GetUInt32(); 
				uint32 bonusEnchant = fields[5].GetUInt32(); 
				uint32 prismaticEnchant = fields[6].GetUInt32();

				// Equip Gear
				player->EquipNewItem(equipmentSlot, itemEntry, true);

				// Apply Enchants and Gems
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PERM_ENCHANTMENT_SLOT, enchant);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT, socket1);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_2, socket2);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), SOCK_ENCHANTMENT_SLOT_3, socket3);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), BONUS_ENCHANTMENT_SLOT, bonusEnchant);
				ApplyBonus(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, equipmentSlot), PRISMATIC_ENCHANTMENT_SLOT, prismaticEnchant);
			}
		}
	}

	void LearnPlateMailSpells(Player* player)
	{
		switch (player->getClass())
		{
		case CLASS_WARRIOR:
		case CLASS_PALADIN:
		case CLASS_DEATH_KNIGHT:
			player->learnSpell(PLATE_MAIL, true);
			break;
		case CLASS_SHAMAN:
		case CLASS_HUNTER:
			player->learnSpell(MAIL, true);
			break;
		default:
			break;
		}
	}

	bool OnGossipHello(Player* player, Creature* creature)
	{
		// Icons:
		// |cff00ff00|TInterface\\icons\\ICON_NAME_HERE:30|t|r <text>

		switch (player->getClass())
		{
		case CLASS_PRIEST:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\spell_holy_penance:30|t|r Use Discipline Spec", GOSSIP_SENDER_MAIN, 0);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\spell_holy_surgeoflight:30|t|r Use Holy Spec", GOSSIP_SENDER_MAIN, 1);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\spell_shadow_psychichorrors:30|t|r Use Shadow Spec", GOSSIP_SENDER_MAIN, 2);
			}
			break;
		case CLASS_PALADIN:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\spell_holy_searinglight:30|t|r Use Holy Spec", GOSSIP_SENDER_MAIN, 3);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\spell_holy_blessingofprotection:30|t|r Use Protection Spec", GOSSIP_SENDER_MAIN, 4);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_paladin_divinestorm:30|t|r Use Retribution Spec", GOSSIP_SENDER_MAIN, 5);
			}
			break;
		case CLASS_WARRIOR:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_warrior_titansgrip:30|t|r Use Fury Spec", GOSSIP_SENDER_MAIN, 6);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_warrior_bladestorm:30|t|r Use Arms Spec", GOSSIP_SENDER_MAIN, 7);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_warrior_shieldreflection:30|t|r Use Protection Spec", GOSSIP_SENDER_MAIN, 8);
			}
			break;
		case CLASS_MAGE:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_mage_arcanebarrage:30|t|r Use Arcane Spec", GOSSIP_SENDER_MAIN, 9);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_mage_livingbomb:30|t|r Use Fire Spec", GOSSIP_SENDER_MAIN, 10);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_mage_deepfreeze:30|t|r Use Frost Spec", GOSSIP_SENDER_MAIN, 11);
			}
			break;
		case CLASS_WARLOCK:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_warlock_haunt:30|t|r Use Affliction Spec", GOSSIP_SENDER_MAIN, 12);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\spell_shadow_demonform:30|t|r Use Demonology Spec", GOSSIP_SENDER_MAIN, 13);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_warlock_chaosbolt:30|t|r Use Destruction Spec", GOSSIP_SENDER_MAIN, 14);
			}
			break;
		case CLASS_SHAMAN:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\spell_shaman_thunderstorm:30|t|r Use Elemental Spec", GOSSIP_SENDER_MAIN, 15);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\spell_shaman_feralspirit:30|t|r Use Enhancement Spec", GOSSIP_SENDER_MAIN, 16);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\spell_nature_healingwavelesser:30|t|r Use Restoration Spec", GOSSIP_SENDER_MAIN, 17);
			}
			break;
		case CLASS_DRUID:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\spell_arcane_starfire:30|t|r Use Ballance Spec", GOSSIP_SENDER_MAIN, 18);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_druid_berserk:30|t|r Use Feral Spec", GOSSIP_SENDER_MAIN, 19);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_druid_flourish:30|t|r Use Restoration Spec", GOSSIP_SENDER_MAIN, 20);
			}
			break;
		case CLASS_HUNTER:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_hunter_chimerashot2:30|t|r Use Markmanship Spec", GOSSIP_SENDER_MAIN, 21);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_hunter_animalhandler:30|t|r Use Beastmastery Spec", GOSSIP_SENDER_MAIN, 22);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_golemstormbolt:30|t|r Use Survival Spec", GOSSIP_SENDER_MAIN, 23);
			}
			break;
		case CLASS_ROGUE:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_rogue_disembowel:30|t|r Use Assasination Spec", GOSSIP_SENDER_MAIN, 24);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_rogue_murderspree:30|t|r Use Combat Spec", GOSSIP_SENDER_MAIN, 25);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_rogue_shadowdance:30|t|r Use Subtlety Spec", GOSSIP_SENDER_MAIN, 26);
			}
			break;
		case CLASS_DEATH_KNIGHT:
			{
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\spell_deathknight_butcher2:30|t|r Use Blood Spec", GOSSIP_SENDER_MAIN, 27);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\spell_deathknight_empowerruneblade2:30|t|r Use Frost Spec", GOSSIP_SENDER_MAIN, 28);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "|cff00ff00|TInterface\\icons\\ability_hunter_pet_bat:30|t|r Use Unholy Spec", GOSSIP_SENDER_MAIN, 29);
			}
			break;
		}
		player->SEND_GOSSIP_MENU(60025, creature->GetGUID());
		return true;
	}

	void EquipFullTemplateGear(Player* player, std::string& playerSpecStr) // Merge
	{
		if (CanEquipTemplate(player, playerSpecStr) == false)
		{
			player->GetSession()->SendAreaTriggerMessage("There's no templates for %s specialization yet.", playerSpecStr.c_str());
			return;
		}

		EquipTmpGear(player, playerSpecStr);
		SetTemplateTalents(player, playerSpecStr);
		SetTemplateGlyphs(player, playerSpecStr);

		LearnPlateMailSpells(player);
		LearnWeaponSkills(player);

		player->GetSession()->SendAreaTriggerMessage("Successfuly equipped %s %s template!", playerSpecStr.c_str(), GetClassString(player).c_str());
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
	{
		player->PlayerTalkClass->ClearMenus();

		if (!player || !creature)
			return true;

		// Don't let players to use Template feature while wearing some gear
		for (uint8 i = EQUIPMENT_SLOT_START; i < EQUIPMENT_SLOT_END; ++i)
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

		// Don't let players to use Template feature after spending some talent points
		if (player->GetFreeTalentPoints() < 71)
		{
			player->GetSession()->SendAreaTriggerMessage("You have already spent some talent points. You need to reset your talents first!");
			player->CLOSE_GOSSIP_MENU();
			return true;
		}

		switch (uiAction)
		{
		case 0: // Use Discipline Priest Spec
			spec = "Discipline";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 1: // Use Holy Priest Spec
			spec = "Holy";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 2: // Use Shadow Priest Spec
			spec = "Shadow";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 3: // Use Holy Paladin Spec
			spec = "Holy";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 4: // Use Protection Paladin Spec
			spec = "Protection";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 5: // Use Retribution Paladin Spec
			spec = "Retribution";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 6: // Use Fury Warrior Spec
			spec = "Fury";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 7: // Use Arms Warrior Spec
			spec = "Arms";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 8: // Use Protection Warrior Spec
			spec = "Protection";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 9: // Use Arcane Mage Spec
			spec = "Arcane";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 10: // Use Fire Mage Spec
			spec = "Fire";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 11: // Use Frost Mage Spec
			spec = "Frost";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 12: // Use Affliction Warlock Spec
			spec = "Affliction";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 13: // Use Demonology Warlock Spec
			spec = "Demonology";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 14: // Use Destruction Warlock Spec
			spec = "Destruction";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 15: // Use Elemental Shaman Spec
			spec = "Elemental";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 16: // Use Enhancement Shaman Spec
			spec = "Enhancement";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 17: // Use Restoration Shaman Spec
			spec = "Restoration";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 18: // Use Ballance Druid Spec
			spec = "Ballance";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 19: // Use Feral Druid Spec
			spec = "Feral";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 20: // Use Restoration Druid Spec
			spec = "Restoration";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 21: // Use Marksmanship Hunter Spec
			spec = "Marksmanship";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 22: // Use Beastmastery Hunter Spec
			spec = "Beastmastery";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 23: // Use Survival Hunter Spec
			spec = "Survival";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 24: // Use Assassination Rogue Spec
			spec = "Assassination";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 25: // Use Combat Rogue Spec
			spec = "Combat";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 26: // Use Subtlety Rogue Spec
			spec = "Subtlety";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 27: // Use Blood DK Spec
			spec = "Blood";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 28: // Use Frost DK Spec
			spec = "Frost";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;

		case 29: // Use Unholy DK Spec
			spec = "Unholy";
			EquipFullTemplateGear(player, spec);
			player->CLOSE_GOSSIP_MENU();
			break;
		default: // Just in case
			player->GetSession()->SendAreaTriggerMessage("Something went wrong in the code. Please contact the administrator.");
			break;
		}
		return true;
	}
};

void AddSC_TemplateNPC()
{
	new TemplateNPC_Commands();
	new TemplateNPC();
}