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

const uint32 DONOR_TOKEN = 49927;
const uint32 ONE_CHARACTER_VIP = 4992700;

class Donation_NPC : public CreatureScript
{
public:
	Donation_NPC() : CreatureScript("Donation_NPC"){}

	bool OnGossipHello(Player * pPlayer, Creature * pCreature)
	{
		pPlayer->ADD_GOSSIP_ITEM(4, "Exchange Donation Points.", GOSSIP_SENDER_MAIN, 0);
		pPlayer->ADD_GOSSIP_ITEM(4, "Exchange Voting Points.", GOSSIP_SENDER_MAIN, 1);
		pPlayer->ADD_GOSSIP_ITEM(4, "Show my Donation and Vote Points.", GOSSIP_SENDER_MAIN, 7);
		pPlayer->SEND_GOSSIP_MENU(60010, pCreature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 sender, uint32 uiAction)
	{
		QueryResult select = LoginDatabase.PQuery("SELECT dp, vp FROM fusioncms_new.account_data WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());

		pPlayer->PlayerTalkClass->ClearMenus();

		if (!select)
		{
			pPlayer->GetSession()->SendAreaTriggerMessage("You don't have any vote or donation points. Please vote/donate first at: http://battlearenas.no-ip.org");
			pPlayer->CLOSE_GOSSIP_MENU();
			return false;
		}

		Field* fields = select->Fetch();
		uint32 dp = fields[0].GetUInt32();
		uint32 vp = fields[1].GetUInt32();

		// If player is not owner and donate points are higher than 25...
		if (pPlayer->GetSession()->GetSecurity() < 5 && dp > 25)
		{
			pPlayer->GetSession()->SendAreaTriggerMessage("You have large amount of Donation points: %u. This is probably a website related problem, please immediately contact the administrator via ticket about this issue.", dp);
			pPlayer->CLOSE_GOSSIP_MENU();
			return false;
		}

		switch(uiAction)
		{
		case 0:
			if (dp < 1)
				pPlayer->ADD_GOSSIP_ITEM(4, "Purchase one Donation Token (1 DP - |cffD80000Locked|r).", GOSSIP_SENDER_MAIN, 31);
			else if (dp >= 1)
				pPlayer->ADD_GOSSIP_ITEM(4, "Purchase one Donation Token (1 DP - |cff009900Unlocked|r).", GOSSIP_SENDER_MAIN, 2);

			if (dp < 5)
				pPlayer->ADD_GOSSIP_ITEM(4, "Purchase VIP only for this character (5 DP - |cffD80000Locked|r).", GOSSIP_SENDER_MAIN, 31);
			else if (dp >= 5)
				pPlayer->ADD_GOSSIP_ITEM(4, "Purchase VIP only for this character (5 DP - |cff009900Unlocked|r).", GOSSIP_SENDER_MAIN, 25);

			if (dp < 20)
				pPlayer->ADD_GOSSIP_ITEM(4, "Purchase VIP Account upgrade (20 DP - |cffD80000Locked|r).", GOSSIP_SENDER_MAIN, 31);
			else if (dp >= 20)
				pPlayer->ADD_GOSSIP_ITEM(4, "Purchase VIP Account upgrade (20 DP - |cff009900Unlocked|r).", GOSSIP_SENDER_MAIN, 4);

			pPlayer->ADD_GOSSIP_ITEM(4, "Exchange Donation Points for Titles..", GOSSIP_SENDER_MAIN, 8);
			pPlayer->ADD_GOSSIP_ITEM(4, "Back to Main Page", GOSSIP_SENDER_MAIN, 26);
			pPlayer->SEND_GOSSIP_MENU(60011, pCreature->GetGUID());
			break;

		case 1:
			if (vp < 50)
				pPlayer->ADD_GOSSIP_ITEM(4, "BattleArenas Donation Pack I (50 VP - |cffD80000Locked|r).", GOSSIP_SENDER_MAIN, 31);
			else if (vp >= 50)
				pPlayer->ADD_GOSSIP_ITEM(4, "BattleArenas Donation Pack I (50 VP - |cff009900Unlocked|r).", GOSSIP_SENDER_MAIN, 29);

			if (vp < 100)
				pPlayer->ADD_GOSSIP_ITEM(4, "BattleArenas Donation Pack II (100 VP - |cffD80000Locked|r).", GOSSIP_SENDER_MAIN, 31);
			else if (vp >= 100)
				pPlayer->ADD_GOSSIP_ITEM(4, "BattleArenas Donation Pack II (100 VP - |cff009900Unlocked|r).", GOSSIP_SENDER_MAIN, 30);

			if (vp < 150)
				pPlayer->ADD_GOSSIP_ITEM(4, "Wrathful Gladiator's Tabard (150 VP - |cffD80000Locked|r).", GOSSIP_SENDER_MAIN, 31);
			else if (vp >= 150)
				pPlayer->ADD_GOSSIP_ITEM(4, "Wrathful Gladiator's Tabard (150 VP - |cff009900Unlocked|r).", GOSSIP_SENDER_MAIN, 3);

			if (vp < 100)
				pPlayer->ADD_GOSSIP_ITEM(4, "Relentless Gladiator's Tabard (100 VP - |cffD80000Locked|r).", GOSSIP_SENDER_MAIN, 31);
			else if (vp >= 100)
				pPlayer->ADD_GOSSIP_ITEM(4, "Relentless Gladiator's Tabard (100 VP - |cff009900Unlocked|r).", GOSSIP_SENDER_MAIN, 5);

			if (vp < 50)
				pPlayer->ADD_GOSSIP_ITEM(4, "Furious Gladiator's Tabard (50 VP - |cffD80000Locked|r).", GOSSIP_SENDER_MAIN, 31);
			else if (vp >= 50)
				pPlayer->ADD_GOSSIP_ITEM(4, "Furious Gladiator's Tabard (50 VP - |cff009900Unlocked|r).", GOSSIP_SENDER_MAIN, 6);

			pPlayer->ADD_GOSSIP_ITEM(4, "Back to Main Page", GOSSIP_SENDER_MAIN, 26);
			pPlayer->SEND_GOSSIP_MENU(60012, pCreature->GetGUID());
			break;

		case 2: // Purchase donation token
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned 1 Donation Token. Use donation tokens to buy items from Donation Vendor behind me! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->AddItem(DONOR_TOKEN, 1);
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 3:
			if (vp < 150)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Vote Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET vp = '%u' -150 WHERE id = '%u'", vp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Wrathful Gladiator's Tabard! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->AddItem(51534, 1); // Wrathful Gladiator's Tabard
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 4: // 20 donation points for VIP account
			if (pPlayer->GetSession()->GetSecurity() >= 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You're already VIP or GM.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (dp < 20)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You dont have enought Donation Points");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -20 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PExecute("INSERT INTO `account_access` (`id`, `gmlevel`, `RealmID`) VALUES (%u, 1, -1);", pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully upgraded your account to VIP. Quit the game and log in again for changes to take effect! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 5:
			if (vp < 100)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Vote Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET vp = '%u' -100 WHERE id = '%u'", vp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Relentless Gladiator's Tabard! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->AddItem(49086, 1); // Relentless Gladiator's Tabard
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 6:
			if (vp < 50)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Vote Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET vp = '%u' -50 WHERE id = '%u'", vp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Furios Gladiator's Tabard! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->AddItem(45983, 1); // Furious Gladiator's Tabard
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 7:// Show My Points
			pPlayer->GetSession()->SendAreaTriggerMessage("Donate Points: %u", dp);
			pPlayer->GetSession()->SendAreaTriggerMessage("Vote Points: %u", vp);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 8: // Exhange Donation Points for Titles
			pPlayer->ADD_GOSSIP_ITEM(4, "Conqueror (1 DP).", GOSSIP_SENDER_MAIN, 9);
			pPlayer->ADD_GOSSIP_ITEM(4, "Justicar (1 DP).", GOSSIP_SENDER_MAIN, 10);
			pPlayer->ADD_GOSSIP_ITEM(4, "Battlemaster (1 DP).", GOSSIP_SENDER_MAIN, 11);
			pPlayer->ADD_GOSSIP_ITEM(4, "Scarab Lord (1 DP).", GOSSIP_SENDER_MAIN, 12);
			pPlayer->ADD_GOSSIP_ITEM(4, "Brewmaster (1 DP).", GOSSIP_SENDER_MAIN, 13);
			pPlayer->ADD_GOSSIP_ITEM(4, "The Love Fool (1 DP).", GOSSIP_SENDER_MAIN, 14);
			pPlayer->ADD_GOSSIP_ITEM(4, "Matron (1 DP).", GOSSIP_SENDER_MAIN, 15);
			pPlayer->ADD_GOSSIP_ITEM(4, "Patron (1 DP).", GOSSIP_SENDER_MAIN, 16);
			pPlayer->ADD_GOSSIP_ITEM(4, "The Hallowed (1 DP).", GOSSIP_SENDER_MAIN, 17);
			pPlayer->ADD_GOSSIP_ITEM(4, "Merrymaker (1 DP).", GOSSIP_SENDER_MAIN, 18);
			pPlayer->ADD_GOSSIP_ITEM(4, "The Noble (1 DP).", GOSSIP_SENDER_MAIN, 19);
			pPlayer->ADD_GOSSIP_ITEM(4, "The Pilgrim (1 DP).", GOSSIP_SENDER_MAIN, 20);
			pPlayer->ADD_GOSSIP_ITEM(4, "Flame Keeper (1 DP).", GOSSIP_SENDER_MAIN, 21);
			pPlayer->ADD_GOSSIP_ITEM(4, "Flame Warden (1 DP).", GOSSIP_SENDER_MAIN, 22);
			pPlayer->ADD_GOSSIP_ITEM(4, "Elder (1 DP).", GOSSIP_SENDER_MAIN, 23);
			pPlayer->ADD_GOSSIP_ITEM(4, "Jenkins (1 DP).", GOSSIP_SENDER_MAIN, 24);
			pPlayer->ADD_GOSSIP_ITEM(4, "Back to Main Page", GOSSIP_SENDER_MAIN, 26);
			pPlayer->SEND_GOSSIP_MENU(60013, pCreature->GetGUID());
			break;

		case 9: // Conqueror
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(47)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Conqueror title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(47));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 10: // Justicar
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(48)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Justicar title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(48));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 11: // Battlemaster
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(72)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Battlemaster title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(72));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 12: // Scarab Lord
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(46)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Scarab Lord title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(46));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 13: // Brewmaster
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(133)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Brewmaster title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(133));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 14: // the Love Fool
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(135)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned The Love Fool title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(135));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 15: // Matron
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(137)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Matron title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(137));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 16: // Patron
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(138)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Patron title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(138));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 17: // The Hallowed
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(124)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned The Hallowed title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(124));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 18: // Merrymaker
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(134)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Merrymaker title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(134));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 19: // The Noble
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(155)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned The Noble title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(155));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 20: // The Pilgrim
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(168)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned The Pilgrim title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(168));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 21: // Flame Keeper
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(76)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Flame Keeper title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(76));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 22: // Flame Warden
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(75)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Flame Warden title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(75));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 23: // Elder
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(74)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Elder title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(74));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 24: // Jenkins
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Donation Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(143)))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You already has this title.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned Jenkins title! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->SetTitle(sCharTitlesStore.LookupEntry(143));
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 25: // VIP only for this character
			if (pPlayer->GetSession()->GetSecurity() >= 1 || pPlayer->HasItemCount(ONE_CHARACTER_VIP, 1))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You're already VIP or GM.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else if (dp < 5)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You dont have enought Donation Points");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -5 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully upgraded this character to VIP! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->AddItem(ONE_CHARACTER_VIP, 1);
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 27: // 10000 Honor
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You dont have enought Donation Points");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully gained 10000 Honor Points! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->ModifyHonorPoints(10000);
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 28: // 500 Arena Points
			if (dp < 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You dont have enought Donation Points");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully gained 500 Arena Points! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->ModifyArenaPoints(500);
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 29:
			if (vp < 50)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Vote Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET vp = '%u' -50 WHERE id = '%u'", vp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned BattleArenas Donation Pack I! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->AddItem(43575, 1); // BattleArenas Donation Pack I
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 30:
			if (vp < 100)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have the required Vote Points.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET vp = '%u' -100 WHERE id = '%u'", vp, pPlayer->GetSession()->GetAccountId());
				pCreature->MonsterWhisper("Successfully earned BattleArenas Donation Pack II! Thanks for the support!", pPlayer->GetGUID());
				pPlayer->AddItem(29569, 1); // BattleArenas Donation Pack II
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 26: // Back to Main Menu..
			OnGossipHello(pPlayer, pCreature);
			break;

		case 31: // Back to Main Menu / not enought points
			pPlayer->GetSession()->SendAreaTriggerMessage("Not enought points.");
			OnGossipHello(pPlayer, pCreature);
			break;
		}
		return true;
	}
};

////////////////////////////////////////////////////////////////////////
//      ___                         ___       __  __  __              //
//     / _ | _______ ___  ___ _____/ _ )___ _/ /_/ /_/ /__ ___        //
//    / __ |/ __/ -_) _ \/ _ `/___/ _  / _ `/ __/ __/ / -_|_-<        //
//   /_/ |_/_/  \__/_//_/\_,_/   /____/\_,_/\__/\__/_/\__/___/.com    //
//                                                                    //
//         Developed by Natureknight Patrick and Scott.               //
//                      AT like donation NPC                          //
////////////////////////////////////////////////////////////////////////

class Donation_NPC_AT : public CreatureScript
{
public:
	Donation_NPC_AT() : CreatureScript("Donation_NPC_AT"){}

	uint32 SelectDPoints(Player* pPlayer)
	{
		QueryResult select = LoginDatabase.PQuery("SELECT dp FROM fusioncms_new.account_data WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());

		if (!select) // Just in case, but should not happen
		{
			//pPlayer->GetSession()->SendAreaTriggerMessage("Something went wrong, please contact the administrator about your issue!");
			pPlayer->CLOSE_GOSSIP_MENU();
			return 0;
		}

		Field* fields = select->Fetch();
		uint32 dp = fields[0].GetUInt32();

		return dp;
	}

	uint32 SelectVPoints(Player* pPlayer)
	{
		QueryResult select = LoginDatabase.PQuery("SELECT vp FROM fusioncms_new.account_data WHERE id = '%u'", pPlayer->GetSession()->GetAccountId());

		if (!select) // Just in case, but should not happen
		{
			//pPlayer->GetSession()->SendAreaTriggerMessage("Something went wrong, please contact the administrator about your issue!");
			pPlayer->CLOSE_GOSSIP_MENU();
			return 0;
		}

		Field* fields = select->Fetch();
		uint32 vp = fields[0].GetUInt32();

		return vp;
	}

	void RewardTitle(Player* pPlayer, uint32 entry)
	{
		if (pPlayer->HasTitle(sCharTitlesStore.LookupEntry(entry)))
		{
			pPlayer->GetSession()->SendAreaTriggerMessage("You already have this title.");
			pPlayer->CLOSE_GOSSIP_MENU();
		}
		else
		{
			LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", SelectDPoints(pPlayer), pPlayer->GetSession()->GetAccountId());
			pPlayer->GetSession()->SendAreaTriggerMessage("Successfully earned a title! Thanks for the support!");
			pPlayer->SetTitle(sCharTitlesStore.LookupEntry(entry));
			pPlayer->SaveToDB();
		}
	}

	bool OnGossipHello(Player * pPlayer, Creature * pCreature)
	{
		// TODO: Prevent exploiting the FusionCMS donate points
		if (pPlayer->GetSession()->GetSecurity() < 5 && SelectDPoints(pPlayer) > 50)
		{
			pPlayer->GetSession()->SendAreaTriggerMessage("You have large amount of Donation points: %u. This is probably a website related problem, please immediately contact the administrator via ticket about this issue.", SelectDPoints(pPlayer));
			pPlayer->CLOSE_GOSSIP_MENU();
			return false;
		}

		// VIP Account
		if (SelectDPoints(pPlayer) < 30)
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Purchase VIP Account (|cffD80000Locked|r / Click for Information)", GOSSIP_SENDER_MAIN, 1);
		else if (SelectDPoints(pPlayer) >= 30)
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Purchase VIP Account (|cff009900Unlocked|r / Click to use)", GOSSIP_SENDER_MAIN, 2);

		// VIP only for current char
		if (SelectDPoints(pPlayer) < 7)
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "VIP only for current character (|cffD80000Locked|r / Click for Information)", GOSSIP_SENDER_MAIN, 3);
		else if (SelectDPoints(pPlayer) >= 7)
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "VIP only for current character (|cff009900Unlocked|r / Click to use)", GOSSIP_SENDER_MAIN, 4);


		// WF weapons 1H
		if (SelectDPoints(pPlayer) < 1)
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Wrathful Offpiece/1H Weapon/Exotic Mount (|cffD80000Locked|r / Min 1 Donation Point needed)", GOSSIP_SENDER_MAIN, 998);
		else if (SelectDPoints(pPlayer) >= 1)
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Wrathful Offpiece/1H Weapon/Exotic Mount (|cff009900Unlocked|r / Click to use)", GOSSIP_SENDER_MAIN, 5);

		// WF weapon 2H
		if (SelectDPoints(pPlayer) < 2)
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Wrathful Main Piece/2H Weapon (|cffD80000Locked|r / Min 2 Donation Points needed)", GOSSIP_SENDER_MAIN, 998);
		else if (SelectDPoints(pPlayer) >= 2)
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Wrathful Main Piece/2H Weapon (|cff009900Unlocked|r / Click to use)", GOSSIP_SENDER_MAIN, 6);

		// Custom Legendary Weapon
		if (SelectDPoints(pPlayer) < 5)
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Custom Legendary Weapon (|cffD80000Locked|r / Min 5 Donation Points)", GOSSIP_SENDER_MAIN, 998);
		else if (SelectDPoints(pPlayer) >= 5)
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Custom Legendary Weapon (|cff009900Unlocked|r / Click to use)", GOSSIP_SENDER_MAIN, 7);


		// Titles
		if (SelectDPoints(pPlayer) < 1)
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Purchase Character Title (|cffD80000Locked|r / Min 1 Donation Point needed)", GOSSIP_SENDER_MAIN, 8);
		else if (SelectDPoints(pPlayer) >= 1)
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Purchase Character Title (|cff009900Unlocked|r / Click to use)", GOSSIP_SENDER_MAIN, 8);

		// Show Donate and Voting Points when GossipHello
		std::stringstream points;
		points << "My Donation Points: " << SelectDPoints(pPlayer) << "\n";
		points << "My Voting Points: " << SelectVPoints(pPlayer) << "\n";

		pPlayer->ADD_GOSSIP_ITEM(4, points.str().c_str(), GOSSIP_SENDER_MAIN, 999);
		pPlayer->SEND_GOSSIP_MENU(60031, pCreature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 sender, uint32 uiAction)
	{
		pPlayer->PlayerTalkClass->ClearMenus();

		if (sender != GOSSIP_SENDER_MAIN)
			return false;

		uint32 dp = SelectDPoints(pPlayer);
		uint32 vp = SelectVPoints(pPlayer);

		switch(uiAction)
		{
		case 1: // Vip account - locked
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back to Main Menu", GOSSIP_SENDER_MAIN, 1000);
			pPlayer->SEND_GOSSIP_MENU(60032, pCreature->GetGUID());
			break;

		case 2: // Vip account - unlocked
			if (pPlayer->GetSession()->GetSecurity() >= 1)
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You're already VIP or GM.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -30 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				LoginDatabase.PExecute("INSERT INTO `account_access` (`id`, `gmlevel`, `RealmID`) VALUES (%u, 1, -1);", pPlayer->GetSession()->GetAccountId());
				pPlayer->GetSession()->SendAreaTriggerMessage("Successfully upgraded your account to VIP. Quit the game and login again for changes to take effect! Thanks for the support!");
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 3: // VIP only character - locked
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Back to Main Menu", GOSSIP_SENDER_MAIN, 1000);
			pPlayer->SEND_GOSSIP_MENU(60033, pCreature->GetGUID());
			break;

		case 4: // VIP only character - unlocked
			if (pPlayer->GetSession()->GetSecurity() >= 1 || pPlayer->HasItemCount(ONE_CHARACTER_VIP, 1))
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You're already VIP or GM.");
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			else
			{
				LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -7 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
				pPlayer->GetSession()->SendAreaTriggerMessage("Successfully upgraded this character to VIP! Thanks for the support!");
				pPlayer->AddItem(ONE_CHARACTER_VIP, 1);
				pPlayer->SaveToDB();
				pPlayer->CLOSE_GOSSIP_MENU();
			}
			break;

		case 5: // Wrathful Offpiece / 1H Weapon / Mount - unlocked
			LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -1 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
			pPlayer->AddItem(44990, 25); // 25 Emblems of Relentless (Champion's Seal)
			pPlayer->SaveToDB();
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 6: // Wrathful Main Piece / 2H Weapon - unlocked
			LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -2 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
			pPlayer->AddItem(44990, 50); // 50 Emblems of Relentless (Champion's Seal)
			pPlayer->SaveToDB();
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 7: // Purchase Legendary Weapon - for Fun realm
			LoginDatabase.PExecute("UPDATE fusioncms_new.account_data SET dp = '%u' -5 WHERE id = '%u'", dp, pPlayer->GetSession()->GetAccountId());
			pPlayer->GetSession()->SendAreaTriggerMessage("Successfully purchased 15 Emblems of Legendary! Speak with Legendary Weapons NPC!");
			pPlayer->AddItem(40753, 15); // Emblem of Valor (Emblem of Legendary)
			pPlayer->SaveToDB();
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 8: // Donation titles
			if (dp >= 1)
			{
				pPlayer->ADD_GOSSIP_ITEM(4, "Conqueror (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 9);
				pPlayer->ADD_GOSSIP_ITEM(4, "Justicar (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 10);
				pPlayer->ADD_GOSSIP_ITEM(4, "Battlemaster (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 11);
				pPlayer->ADD_GOSSIP_ITEM(4, "Scarab Lord (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 12);
				pPlayer->ADD_GOSSIP_ITEM(4, "Brewmaster (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 13);
				pPlayer->ADD_GOSSIP_ITEM(4, "The Love Fool (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 14);
				pPlayer->ADD_GOSSIP_ITEM(4, "Matron (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 15);
				pPlayer->ADD_GOSSIP_ITEM(4, "Patron (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 16);
				pPlayer->ADD_GOSSIP_ITEM(4, "The Hallowed (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 17);
				pPlayer->ADD_GOSSIP_ITEM(4, "Merrymaker (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 18);
				pPlayer->ADD_GOSSIP_ITEM(4, "The Noble (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 19);
				pPlayer->ADD_GOSSIP_ITEM(4, "The Pilgrim (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 20);
				pPlayer->ADD_GOSSIP_ITEM(4, "Flame Keeper (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 21);
				pPlayer->ADD_GOSSIP_ITEM(4, "Flame Warden (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 22);
				pPlayer->ADD_GOSSIP_ITEM(4, "Elder (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 23);
				pPlayer->ADD_GOSSIP_ITEM(4, "Jenkins (|cff009900Unlocked|r)", GOSSIP_SENDER_MAIN, 24);
				pPlayer->ADD_GOSSIP_ITEM(4, "Back to Main Page", GOSSIP_SENDER_MAIN, 1000);
				pPlayer->SEND_GOSSIP_MENU(60013, pCreature->GetGUID());
			}
			else if (dp < 1)
			{
				pPlayer->ADD_GOSSIP_ITEM(4, "Conqueror (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "Justicar (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "Battlemaster (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "Scarab Lord (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "Brewmaster (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "The Love Fool (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "Matron (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "Patron (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "The Hallowed (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "Merrymaker (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "The Noble (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "The Pilgrim (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "Flame Keeper (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "Flame Warden (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "Elder (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "Jenkins (|cffD80000Locked|r)", GOSSIP_SENDER_MAIN, 998);
				pPlayer->ADD_GOSSIP_ITEM(4, "Back to Main Page", GOSSIP_SENDER_MAIN, 1000);
				pPlayer->SEND_GOSSIP_MENU(60013, pCreature->GetGUID());
			}
			break;

		case 9: // Conqueror
			RewardTitle(pPlayer, 47);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 10: // Justicar
			RewardTitle(pPlayer, 48);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 11: // Battlemaster
			RewardTitle(pPlayer, 72);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 12: // Scarab Lord
			RewardTitle(pPlayer, 46);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 13: // Brewmaster
			RewardTitle(pPlayer, 133);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 14: // the Love Fool
			RewardTitle(pPlayer, 135);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 15: // Matron
			RewardTitle(pPlayer, 137);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 16: // Patron
			RewardTitle(pPlayer, 138);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 17: // The Hallowed
			RewardTitle(pPlayer, 124);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 18: // Merrymaker
			RewardTitle(pPlayer, 134);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 19: // The Noble
			RewardTitle(pPlayer, 155);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 20: // The Pilgrim
			RewardTitle(pPlayer, 168);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 21: // Flame Keeper
			RewardTitle(pPlayer, 76);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 22: // Flame Warden
			RewardTitle(pPlayer, 75);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 23: // Elder
			RewardTitle(pPlayer, 74);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 24: // Jenkins
			RewardTitle(pPlayer, 143);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 998: // Not enought points
			pPlayer->GetSession()->SendAreaTriggerMessage("Not enought donation points.");
			OnGossipHello(pPlayer, pCreature);
			break;

		case 999: // Show donate points
			pPlayer->GetSession()->SendAreaTriggerMessage("Donation points: %u", dp);
			pPlayer->GetSession()->SendAreaTriggerMessage("Voting points: %u", vp);
			OnGossipHello(pPlayer, pCreature);
			break;

		case 1000: // Back to main menu
			OnGossipHello(pPlayer, pCreature);
			break;
		}
		return true;
	}
};

void AddSC_Donation_NPC()
{
	new Donation_NPC();
	new Donation_NPC_AT();
}
