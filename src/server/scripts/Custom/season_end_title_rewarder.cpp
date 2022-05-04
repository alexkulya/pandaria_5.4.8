////////////////////////////////////////////////////////////////////////
//      ___                         ___       __  __  __              //
//     / _ | _______ ___  ___ _____/ _ )___ _/ /_/ /_/ /__ ___        //
//    / __ |/ __/ -_) _ \/ _ `/___/ _  / _ `/ __/ __/ / -_|_-<        //
//   /_/ |_/_/  \__/_//_/\_,_/   /____/\_,_/\__/\__/_/\__/___/.com    //
//                                                                    //
//         Developed by Natureknight Patrick and Scott.               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

//Working NPC:

//INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`) VALUES (19951, 0, 0, 0, 0, 0, 19279, 0, 0, 0, 'Event Rewards NPC', 'BattleArenas', NULL, 0, 80, 80, 1, 35, 35, 1, 1, 1.14286, 0.4, 1, 252, 357, 0, 304, 4.6, 2000, 0, 1, 768, 8, 0, 0, 0, 0, 0, 215, 320, 44, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1400, 0, 2, 'Events', 12340);
//INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES (60005, 'Welcome $N. Choose a type of event reward you want to get\r\nfor Emblem of Conquest (Event Token):', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 1);
//INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES (60004, 'Welcome $N. I can exchange your Emblem of Conquest for one of these titles. \r\n\r\nYou can get Emblem of Conquest by winning a 1v1 or HnS / Survival / Boss event.\r\n\r\nChoose a title:', NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 1);
//INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES (60006, 'Welcome $N. I can exchange your Emblem of Conquest for\r\none of these items.\r\n\r\nYou can get Emblem of Conquest by winning a 1v1 or HnS / Survival / Boss event.\r\n\r\nChoose item:', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 1);
//INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (60004, 60004);
//INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (60005, 60005);
//INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES (60006, 60006);

// commands:
//.send items natureknight "rank 1 title token (2v2)" "rank 1 title token (2v2)" 40752      - WRATHFUL GLADIATOR
//.send items natureknight "top 3 title token" "top 3 title token" 40753                    - GLADIATOR
//.send items natureknight "rival title token" "rival title token" 47241                    - RIVAL
//.send items natureknight "rank 1 (3v3)" "rank 1 (3v3)" 40753                              - GLADIATOR (3v3)

#include "ScriptPCH.h"

//Event token is Emblem of Conquest:
const uint32 WFGLD_TOKEN = 40752;  // Emblem of Heroism
const uint32 GLADI_TOKEN = 40753;  // Emblem of Valor
const uint32 RIVAL_TOKEN = 47241;  // Emblem of Triumph

class Event_Vendor : public CreatureScript
{
	public:
		Event_Vendor() : CreatureScript("Events"){}

		bool OnGossipHello(Player * pPlayer, Creature * pCreature)
		{
			pPlayer->ADD_GOSSIP_ITEM(4, "I finished as rank one (2v2)", GOSSIP_SENDER_MAIN, 0);
            pPlayer->ADD_GOSSIP_ITEM(4, "I finished as rank one (3v3)", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(4, "I finished in top 3 (2v2)", GOSSIP_SENDER_MAIN, 1);
			pPlayer->ADD_GOSSIP_ITEM(4, "I finished in top 10 (2v2)", GOSSIP_SENDER_MAIN, 2);
			pPlayer->SEND_GOSSIP_MENU(60005, pCreature->GetGUID());
			return true;
		}

		bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 sender, uint32 uiAction)
		{
			pPlayer->PlayerTalkClass->ClearMenus();
			std::string name;			
			switch(uiAction)
			{
			    case 0:
					name = pPlayer->GetName();
				    pPlayer->ADD_GOSSIP_ITEM(4, "Wrathful Gladiator "+name, GOSSIP_SENDER_MAIN, 3);
				    pPlayer->ADD_GOSSIP_ITEM(4, "Relentless Gladiator "+name, GOSSIP_SENDER_MAIN, 4);
				    pPlayer->ADD_GOSSIP_ITEM(4, "Furious Gladiator "+name, GOSSIP_SENDER_MAIN, 5);
				    pPlayer->ADD_GOSSIP_ITEM(4, "Deadly Gladiator "+name, GOSSIP_SENDER_MAIN, 6);
				    pPlayer->ADD_GOSSIP_ITEM(4, "Brutal Gladiator "+name, GOSSIP_SENDER_MAIN, 7);
				    pPlayer->ADD_GOSSIP_ITEM(4, "Vengeful Gladiator "+name, GOSSIP_SENDER_MAIN, 8);
				    pPlayer->ADD_GOSSIP_ITEM(4, "Merciless Gladiator "+name, GOSSIP_SENDER_MAIN, 9);
					pPlayer->SEND_GOSSIP_MENU(60004, pCreature->GetGUID());
				    break;

			    case 1:
					name = pPlayer->GetName();
				    pPlayer->ADD_GOSSIP_ITEM(4, "Gladiator "+name, GOSSIP_SENDER_MAIN, 10);
					pPlayer->SEND_GOSSIP_MENU(60004, pCreature->GetGUID());
				    break;

			    case 2:
					name = pPlayer->GetName();
				    pPlayer->ADD_GOSSIP_ITEM(4, "Rival "+name, GOSSIP_SENDER_MAIN, 11);
					pPlayer->SEND_GOSSIP_MENU(60004, pCreature->GetGUID());
				    break;


				case 3: // wf glad
                   if (pPlayer->HasItemCount(WFGLD_TOKEN, 1))
                   {
                       pPlayer->DestroyItemCount(WFGLD_TOKEN, 1, true);
                       CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(177);
                       pPlayer->SetTitle(titleInfo, false);
                       pCreature->MonsterWhisper("Enjoy your Wrathful Gladiator title!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   else
                   {
                       pCreature->MonsterWhisper("Check your mailbox for title token!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   break;

			    case 4: // rele glad
                   if (pPlayer->HasItemCount(WFGLD_TOKEN, 1))
                   {
                       pPlayer->DestroyItemCount(WFGLD_TOKEN, 1, true);
                       CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(169);
                       pPlayer->SetTitle(titleInfo, false);
                       pCreature->MonsterWhisper("Enjoy your Relentless Gladiator title!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   else
                   {
                       pCreature->MonsterWhisper("Check your mailbox for title token!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   break;

				case 5: // furious glad
                   if (pPlayer->HasItemCount(WFGLD_TOKEN, 1))
                   {
                       pPlayer->DestroyItemCount(WFGLD_TOKEN, 1, true);
                       CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(167);
                       pPlayer->SetTitle(titleInfo, false);
                       pCreature->MonsterWhisper("Enjoy your Furious Gladiator title!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   else
                   {
                       pCreature->MonsterWhisper("Check your mailbox for title token!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   break;

				case 6: // deadly glad
                   if (pPlayer->HasItemCount(WFGLD_TOKEN, 1))
                   {
                       pPlayer->DestroyItemCount(WFGLD_TOKEN, 1, true);
                       CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(157);
                       pPlayer->SetTitle(titleInfo, false);
                       pCreature->MonsterWhisper("Enjoy your Deadly Gladiator title!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   else
                   {
                       pCreature->MonsterWhisper("Check your mailbox for title token!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   break;

				case 7: // brutal glad
                   if (pPlayer->HasItemCount(WFGLD_TOKEN, 1))
                   {
                       pPlayer->DestroyItemCount(WFGLD_TOKEN, 1, true);
                       CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(80);
                       pPlayer->SetTitle(titleInfo, false);
                       pCreature->MonsterWhisper("Enjoy your Brutal Gladiator title!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   else
                   {
                       pCreature->MonsterWhisper("Check your mailbox for title token!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   break;

				case 8: // vengeful glad
                   if (pPlayer->HasItemCount(WFGLD_TOKEN, 1))
                   {
                       pPlayer->DestroyItemCount(WFGLD_TOKEN, 1, true);
                       CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(71);
                       pPlayer->SetTitle(titleInfo, false);
                       pCreature->MonsterWhisper("Enjoy your Vengeful Gladiator title!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   else
                   {
                       pCreature->MonsterWhisper("Check your mailbox for title token!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   break;

				case 9: // merciless glad
                   if (pPlayer->HasItemCount(WFGLD_TOKEN, 1))
                   {
                       pPlayer->DestroyItemCount(WFGLD_TOKEN, 1, true);
                       CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(62);
                       pPlayer->SetTitle(titleInfo, false);
                       pCreature->MonsterWhisper("Enjoy your Merciless Gladiator title!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   else
                   {
                       pCreature->MonsterWhisper("Check your mailbox for title token!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   break;

				case 10: // glad title
                   if (pPlayer->HasItemCount(GLADI_TOKEN, 1))
                   {
                       pPlayer->DestroyItemCount(GLADI_TOKEN, 1, true);
                       CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(42);
                       pPlayer->SetTitle(titleInfo, false);
                       pCreature->MonsterWhisper("Enjoy your Gladiator title!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   else
                   {
                       pCreature->MonsterWhisper("Check your mailbox for title token!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   break;

				case 11: // rival title
                   if (pPlayer->HasItemCount(RIVAL_TOKEN, 1))
                   {
                       pPlayer->DestroyItemCount(RIVAL_TOKEN, 1, true);
                       CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(44);
                       pPlayer->SetTitle(titleInfo, false);
                       pCreature->MonsterWhisper("Enjoy your Gladiator title!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   else
                   {
                       pCreature->MonsterWhisper("Check your mailbox for title token!", pPlayer->GetGUID());
                       pPlayer->CLOSE_GOSSIP_MENU();
                   }
                   break;
			}
			return true;
		}
};

void AddSC_Event_Vendor()
{
	new Event_Vendor();
}