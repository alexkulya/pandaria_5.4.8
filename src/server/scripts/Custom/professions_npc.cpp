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

class Professions_NPC : public CreatureScript
{
public:
	Professions_NPC () : CreatureScript("Professions_NPC") {}

	bool OnGossipHello(Player *pPlayer, Creature* _creature)
	{
		pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Primary Professions", GOSSIP_SENDER_MAIN, 1);
		pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Secondary Professions", GOSSIP_SENDER_MAIN, 2);
		pPlayer->PlayerTalkClass->SendGossipMenu(60030, _creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* pPlayer, Creature* _creature, uint32 uiSender, uint32 SKILL)
	{ 
		pPlayer->PlayerTalkClass->ClearMenus();

		if (uiSender == GOSSIP_SENDER_MAIN)
		{
			switch (SKILL)
			{
			case 1: // Primary Proffs
				/*if (pPlayer->HasItemCount(40752, 5)) // Emblem of Wrathful
				{
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Alchemy (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_ALCHEMY);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Blacksmithing (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_BLACKSMITHING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Enchanting (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_ENCHANTING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Engineering (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_ENGINEERING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Herbalism (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_HERBALISM);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Inscription (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_INSCRIPTION);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Jewelcrafting (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_JEWELCRAFTING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Leatherworking (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_LEATHERWORKING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Mining (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_MINING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Skinning (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_SKINNING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Tailoring (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_TAILORING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Back to Main Page", GOSSIP_SENDER_MAIN, 5);
				pPlayer->PlayerTalkClass->SendGossipMenu(60030, _creature->GetGUID());
				}
				else
				{
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Alchemy (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Blacksmithing (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Enchanting (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Engineering (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Herbalism (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Inscription (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Jewelcrafting (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Leatherworking (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Mining (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Skinning (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Tailoring (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Back to Main Page", GOSSIP_SENDER_MAIN, 5);
				pPlayer->PlayerTalkClass->SendGossipMenu(60030, _creature->GetGUID());
				}
				else
				{*/
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Alchemy", GOSSIP_SENDER_MAIN, SKILL_ALCHEMY);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Blacksmithing", GOSSIP_SENDER_MAIN, SKILL_BLACKSMITHING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Enchanting", GOSSIP_SENDER_MAIN, SKILL_ENCHANTING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Engineering", GOSSIP_SENDER_MAIN, SKILL_ENGINEERING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Herbalism", GOSSIP_SENDER_MAIN, SKILL_HERBALISM);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Inscription", GOSSIP_SENDER_MAIN, SKILL_INSCRIPTION);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Jewelcrafting", GOSSIP_SENDER_MAIN, SKILL_JEWELCRAFTING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Leatherworking", GOSSIP_SENDER_MAIN, SKILL_LEATHERWORKING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Mining", GOSSIP_SENDER_MAIN, SKILL_MINING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Skinning", GOSSIP_SENDER_MAIN, SKILL_SKINNING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Tailoring", GOSSIP_SENDER_MAIN, SKILL_TAILORING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Back to Main Page", GOSSIP_SENDER_MAIN, 5);
				pPlayer->PlayerTalkClass->SendGossipMenu(60030, _creature->GetGUID());
				/*}*/
				break;
			case 2: // Secondary Proffs
				/*if (pPlayer->HasItemCount(40752, 5))
				{
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Cooking (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_COOKING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "First Aid (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_FIRST_AID);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Fishing (|cff00FF66Unlocked|r)", GOSSIP_SENDER_MAIN, SKILL_FISHING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Back to Main Page", GOSSIP_SENDER_MAIN, 5);
				pPlayer->PlayerTalkClass->SendGossipMenu(60030, _creature->GetGUID());
				}
				else
				{
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Cooking (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "First Aid (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Fishing (5 EoW - |cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 3);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Back to Main Page", GOSSIP_SENDER_MAIN, 5);
				pPlayer->PlayerTalkClass->SendGossipMenu(60030, _creature->GetGUID());
				}
				}
				else
				{*/
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Cooking", GOSSIP_SENDER_MAIN, SKILL_COOKING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "First Aid", GOSSIP_SENDER_MAIN, SKILL_FIRST_AID);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Fishing", GOSSIP_SENDER_MAIN, SKILL_FISHING);
				pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, "Back to Main Page", GOSSIP_SENDER_MAIN, 5);
				pPlayer->PlayerTalkClass->SendGossipMenu(60030, _creature->GetGUID());
				/*}*/
				break;
				/*case 3: // No enought EoW
				pPlayer->GetSession()->SendAreaTriggerMessage("You need at least 5 Emblems of Wrathful to purchase a profession.");
				pPlayer->CLOSE_GOSSIP_MENU();
				break;*/
			case 5: // Main Page
				OnGossipHello(pPlayer, _creature);
				break;
			default:
				{
					if (pPlayer->HasSkill(SKILL))
						pPlayer->GetSession()->SendNotification("You already have that skill");
					else
					{
						CompleteLearnProfession(pPlayer, (SkillType)SKILL);
						/*if (sWorld->getBoolConfig(REALM_IS_TOURNAMENT_ENABLED))
						    pPlayer->DestroyItemCount(40752, 5, true); // Emblem of Wrathful*/
						pPlayer->CLOSE_GOSSIP_MENU();
					}
				}
			}
		}
		return true;
	}

	bool IsSecondarySkill(SkillType skill) const
	{
		return skill == SKILL_COOKING || skill == SKILL_FIRST_AID;
	}

	void CompleteLearnProfession(Player *pPlayer, SkillType skill)
	{
		if (PlayerAlreadyHasTwoProfessions(pPlayer) && !IsSecondarySkill(skill))
			pPlayer->GetSession()->SendNotification("You already know two professions!");
		else
		{
			if (!LearnAllRecipesInProfession(pPlayer, skill))
				pPlayer->GetSession()->SendNotification("Internal error occured!");
		}
	}

	bool LearnAllRecipesInProfession(Player* pPlayer, SkillType skill)
	{
		const char* skill_name;
		SkillLineEntry const *SkillInfo = sSkillLineStore.LookupEntry(skill);
		skill_name = SkillInfo->name[ChatHandler(pPlayer).GetSessionDbcLocale()];

		if (!SkillInfo)
		{
			sLog->outError("Profession NPC: received non-valid skill ID (LearnAllRecipesInProfession)");
			return false;
		}       

		LearnSkillRecipesHelper(pPlayer, SkillInfo->id);

		pPlayer->SetSkill(SkillInfo->id, pPlayer->GetSkillStep(SkillInfo->id), 450, 450);
		ChatHandler(pPlayer).PSendSysMessage(LANG_COMMAND_LEARN_ALL_RECIPES, skill_name);

		return true;
	}

	bool PlayerAlreadyHasTwoProfessions(Player *pPlayer)
	{
		uint32 skillCount = 0;

		if (pPlayer->HasSkill(SKILL_MINING))
			skillCount++;
		if (pPlayer->HasSkill(SKILL_SKINNING))
			skillCount++;
		if (pPlayer->HasSkill(SKILL_HERBALISM))
			skillCount++;

		if (skillCount >= 2)
			return true;

		for (uint32 i = 1; i < sSkillLineStore.GetNumRows(); ++i)
		{
			SkillLineEntry const *SkillInfo = sSkillLineStore.LookupEntry(i);
			if (!SkillInfo)
				continue;

			if (SkillInfo->categoryId == SKILL_CATEGORY_SECONDARY)
				continue;

			if ((SkillInfo->categoryId != SKILL_CATEGORY_PROFESSION) || !SkillInfo->canLink)
				continue;

			const uint32 skillID = SkillInfo->id;
			if (pPlayer->HasSkill(skillID))
				skillCount++;

			if (skillCount >= 2)
				return true;
		}
		return false;
	}

	void LearnSkillRecipesHelper(Player *player, uint32 skill_id)
	{
		uint32 classmask = player->getClassMask();

		for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j)
		{
			SkillLineAbilityEntry const *skillLine = sSkillLineAbilityStore.LookupEntry(j);
			if (!skillLine)
				continue;

			// wrong skill
			if (skillLine->skillId != skill_id)
				continue;

			// not high rank
			if (skillLine->forward_spellid)
				continue;

			// skip racial skills
			if (skillLine->racemask != 0)
				continue;

			// skip wrong class skills
			if (skillLine->classmask && (skillLine->classmask & classmask) == 0)
				continue;

			SpellInfo const * spellInfo = sSpellMgr->GetSpellInfo(skillLine->spellId);
			if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, player, false))
				continue;

			player->learnSpell(skillLine->spellId, false);
		}
	}
};

void AddSC_Professions_NPC()
{
	new Professions_NPC();
}