////////////////////////////////////////////////////////////////////////
//      ___                         ___       __  __  __              //
//     / _ | _______ ___  ___ _____/ _ )___ _/ /_/ /_/ /__ ___        //
//    / __ |/ __/ -_) _ \/ _ `/___/ _  / _ `/ __/ __/ / -_|_-<        //
//   /_/ |_/_/  \__/_//_/\_,_/   /____/\_,_/\__/\__/_/\__/___/.com    //
//                                                                    //
//         Developed by Natureknight Patrick and Scott.               //
//                                                                    //
////////////////////////////////////////////////////////////////////////
/*
This is class-restricted non-saveable transmogrification system which allow players to change
their appereance to various sets. Also different itemsets are restricted by MaxPersonalRating

DEVELOPED BY: Natureknight

---- NPC SQL EXAMPLE
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`)
VALUES('190002','0','0','0','0','0','736','0','0','0','Transmogriefer','TEST','','0','80','80','1','35','35','1','1','1.14286','2','0','5000','5000','0','35000','10','1','0','1','512','0','0','0','0','0','0','10000','10000','68','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','20','20','20','0','0','0','0','0','0','0','0','255','0','0','0','transmogriefer','0');
*/

#include "ScriptPCH.h"

class transmogriefer : public CreatureScript
{
public:
	transmogriefer() : CreatureScript("transmogriefer") { }

	bool OnGossipHello(Player *player, Creature *_creature)
	{
		if (player->isInCombat())
		{
			player->CLOSE_GOSSIP_MENU();
			_creature->MonsterWhisper("You are in Combat!", player->GetGUID());
			return true;
		}
		else
		{
			//player->ADD_GOSSIP_ITEM( 10, "Show my Personal Rating (2v2)"                      , GOSSIP_SENDER_MAIN, 9999); 
			if (player->getClass() == CLASS_WARLOCK)
			{
				player->ADD_GOSSIP_ITEM( 4, "Warlock Season 1"                      , GOSSIP_SENDER_MAIN, 100); //S1
				player->ADD_GOSSIP_ITEM( 4, "Warlock Season 2"                      , GOSSIP_SENDER_MAIN, 200); //S2
				player->ADD_GOSSIP_ITEM( 4, "Warlock Season 3"                      , GOSSIP_SENDER_MAIN, 300); //S3
				player->ADD_GOSSIP_ITEM( 4, "Warlock Season 4"                      , GOSSIP_SENDER_MAIN, 400); //S4
				player->ADD_GOSSIP_ITEM( 4, "Warlock Season 5"                      , GOSSIP_SENDER_MAIN, 500); //S5
				player->ADD_GOSSIP_ITEM( 4, "Warlock Tier 2"                        , GOSSIP_SENDER_MAIN, 600);
				player->ADD_GOSSIP_ITEM( 4, "Warlock Tier 3"                        , GOSSIP_SENDER_MAIN, 700);
				player->ADD_GOSSIP_ITEM( 4, "Warlock Tier 4"                        , GOSSIP_SENDER_MAIN, 800);
				player->ADD_GOSSIP_ITEM( 4, "Warlock Tier 5"                        , GOSSIP_SENDER_MAIN, 900);
				player->ADD_GOSSIP_ITEM( 4, "Nemesis Raiment"                       , GOSSIP_SENDER_MAIN, 1009);
			}
			if (player->getClass() == CLASS_WARRIOR)
			{
				player->ADD_GOSSIP_ITEM( 4, "Warrior Season 1"                    , GOSSIP_SENDER_MAIN, 101);
				player->ADD_GOSSIP_ITEM( 4, "Warrior Season 2"                    , GOSSIP_SENDER_MAIN, 201);
				player->ADD_GOSSIP_ITEM( 4, "Warrior Season 3"                    , GOSSIP_SENDER_MAIN, 301);
				player->ADD_GOSSIP_ITEM( 4, "Warrior Season 4"                    , GOSSIP_SENDER_MAIN, 401);
				player->ADD_GOSSIP_ITEM( 4, "Warrior Season 5"                    , GOSSIP_SENDER_MAIN, 501);
				player->ADD_GOSSIP_ITEM( 4, "Warrior Tier 2"                      , GOSSIP_SENDER_MAIN, 601);
				player->ADD_GOSSIP_ITEM( 4, "Warrior Tier 3"                      , GOSSIP_SENDER_MAIN, 701);
				player->ADD_GOSSIP_ITEM( 4, "Warrior Tier 4"                      , GOSSIP_SENDER_MAIN, 801);
				player->ADD_GOSSIP_ITEM( 4, "Warrior Tier 5"                      , GOSSIP_SENDER_MAIN, 901);
				player->ADD_GOSSIP_ITEM( 4, "Hellscream's Battlegear"             , GOSSIP_SENDER_MAIN, 1010);
			}
			if (player->getClass() == CLASS_SHAMAN)
			{
				player->ADD_GOSSIP_ITEM( 4, "Shaman Season 1"                     , GOSSIP_SENDER_MAIN, 106);
				player->ADD_GOSSIP_ITEM( 4, "Shaman Season 2"                     , GOSSIP_SENDER_MAIN, 206);
				player->ADD_GOSSIP_ITEM( 4, "Shaman Season 3"                     , GOSSIP_SENDER_MAIN, 306);
				player->ADD_GOSSIP_ITEM( 4, "Shaman Season 4"                     , GOSSIP_SENDER_MAIN, 406);
				player->ADD_GOSSIP_ITEM( 4, "Shaman Season 5"                     , GOSSIP_SENDER_MAIN, 506);
				player->ADD_GOSSIP_ITEM( 4, "Shaman Tier 2"                       , GOSSIP_SENDER_MAIN, 606);
				player->ADD_GOSSIP_ITEM( 4, "Shaman Tier 3"                       , GOSSIP_SENDER_MAIN, 706);
				player->ADD_GOSSIP_ITEM( 4, "Shaman Tier 4"                       , GOSSIP_SENDER_MAIN, 806);
				player->ADD_GOSSIP_ITEM( 4, "Shaman Tier 5"                       , GOSSIP_SENDER_MAIN, 906);
				player->ADD_GOSSIP_ITEM( 4, "Conqueror's Worldbreaker Battlegear" , GOSSIP_SENDER_MAIN, 1008);
			}
			if (player->getClass() == CLASS_PALADIN)
			{
				player->ADD_GOSSIP_ITEM( 4, "Paladin Season 1"                      , GOSSIP_SENDER_MAIN, 103);
				player->ADD_GOSSIP_ITEM( 4, "Paladin Season 2"                      , GOSSIP_SENDER_MAIN, 203);
				player->ADD_GOSSIP_ITEM( 4, "Paladin Season 3"                      , GOSSIP_SENDER_MAIN, 303);
				player->ADD_GOSSIP_ITEM( 4, "Paladin Season 4"                      , GOSSIP_SENDER_MAIN, 403);
				player->ADD_GOSSIP_ITEM( 4, "Paladin Season 5"                      , GOSSIP_SENDER_MAIN, 503);
				player->ADD_GOSSIP_ITEM( 4, "Paladin Tier 2"                        , GOSSIP_SENDER_MAIN, 603);
				player->ADD_GOSSIP_ITEM( 4, "Paladin Tier 3"                        , GOSSIP_SENDER_MAIN, 703);
				player->ADD_GOSSIP_ITEM( 4, "Paladin Tier 4"                        , GOSSIP_SENDER_MAIN, 803);
				player->ADD_GOSSIP_ITEM( 4, "Paladin Tier 5"                        , GOSSIP_SENDER_MAIN, 903);
				player->ADD_GOSSIP_ITEM( 4, "Liadrin's Battlegear"                  , GOSSIP_SENDER_MAIN, 1005);
			}
			if (player->getClass() == CLASS_MAGE)
			{
				player->ADD_GOSSIP_ITEM( 4, "Mage Season 1"                    , GOSSIP_SENDER_MAIN, 104);
				player->ADD_GOSSIP_ITEM( 4, "Mage Season 2"                    , GOSSIP_SENDER_MAIN, 204);
				player->ADD_GOSSIP_ITEM( 4, "Mage Season 3"                    , GOSSIP_SENDER_MAIN, 304);
				player->ADD_GOSSIP_ITEM( 4, "Mage Season 4"                    , GOSSIP_SENDER_MAIN, 404);
				player->ADD_GOSSIP_ITEM( 4, "Mage Season 5"                    , GOSSIP_SENDER_MAIN, 504);
				player->ADD_GOSSIP_ITEM( 4, "Mage Tier 2"                      , GOSSIP_SENDER_MAIN, 604);
				player->ADD_GOSSIP_ITEM( 4, "Mage Tier 3"                      , GOSSIP_SENDER_MAIN, 704);
				player->ADD_GOSSIP_ITEM( 4, "Mage Tier 4"                      , GOSSIP_SENDER_MAIN, 804);
				player->ADD_GOSSIP_ITEM( 4, "Mage Tier 5"                      , GOSSIP_SENDER_MAIN, 904);
				player->ADD_GOSSIP_ITEM( 4, "Netherwind Regalia"               , GOSSIP_SENDER_MAIN, 1004);
			}
			if (player->getClass() == CLASS_ROGUE)
			{
				player->ADD_GOSSIP_ITEM( 4, "Rogue Season 1"                      , GOSSIP_SENDER_MAIN, 105);
				player->ADD_GOSSIP_ITEM( 4, "Rogue Season 2"                      , GOSSIP_SENDER_MAIN, 205);
				player->ADD_GOSSIP_ITEM( 4, "Rogue Season 3"                      , GOSSIP_SENDER_MAIN, 305);
				player->ADD_GOSSIP_ITEM( 4, "Rogue Season 4"                      , GOSSIP_SENDER_MAIN, 405);
				player->ADD_GOSSIP_ITEM( 4, "Rogue Season 5"                      , GOSSIP_SENDER_MAIN, 505);
				player->ADD_GOSSIP_ITEM( 4, "Rogue Tier 2"                        , GOSSIP_SENDER_MAIN, 605);
				player->ADD_GOSSIP_ITEM( 4, "Rogue Tier 3"                        , GOSSIP_SENDER_MAIN, 705);
				player->ADD_GOSSIP_ITEM( 4, "Rogue Tier 4"                        , GOSSIP_SENDER_MAIN, 805);
				player->ADD_GOSSIP_ITEM( 4, "Rogue Tier 5"                        , GOSSIP_SENDER_MAIN, 905);
				player->ADD_GOSSIP_ITEM( 4, "Garona's Battlegear"                 , GOSSIP_SENDER_MAIN, 1007);
			}
			if (player->getClass() == CLASS_DRUID)
			{
				player->ADD_GOSSIP_ITEM( 4, "Druid Season 1"                      , GOSSIP_SENDER_MAIN, 107);
				player->ADD_GOSSIP_ITEM( 4, "Druid Season 2"                      , GOSSIP_SENDER_MAIN, 207);
				player->ADD_GOSSIP_ITEM( 4, "Druid Season 3"                      , GOSSIP_SENDER_MAIN, 307);
				player->ADD_GOSSIP_ITEM( 4, "Druid Season 4"                      , GOSSIP_SENDER_MAIN, 407);
				player->ADD_GOSSIP_ITEM( 4, "Druid Season 5"                      , GOSSIP_SENDER_MAIN, 507);
				player->ADD_GOSSIP_ITEM( 4, "Druid Tier 2"                        , GOSSIP_SENDER_MAIN, 607);
				player->ADD_GOSSIP_ITEM( 4, "Druid Tier 3"                        , GOSSIP_SENDER_MAIN, 707);
				player->ADD_GOSSIP_ITEM( 4, "Druid Tier 4"                        , GOSSIP_SENDER_MAIN, 807);
				player->ADD_GOSSIP_ITEM( 4, "Druid Tier 5"                        , GOSSIP_SENDER_MAIN, 907);
				player->ADD_GOSSIP_ITEM( 4, "Choking Winter's Garb"               , GOSSIP_SENDER_MAIN, 1002);
			}
			if (player->getClass() == CLASS_PRIEST)
			{
				player->ADD_GOSSIP_ITEM( 4, "Priest Season 1"                      , GOSSIP_SENDER_MAIN, 102);
				player->ADD_GOSSIP_ITEM( 4, "Priest Season 2"                      , GOSSIP_SENDER_MAIN, 202);
				player->ADD_GOSSIP_ITEM( 4, "Priest Season 3"                      , GOSSIP_SENDER_MAIN, 302);
				player->ADD_GOSSIP_ITEM( 4, "Priest Season 4"                      , GOSSIP_SENDER_MAIN, 402);
				player->ADD_GOSSIP_ITEM( 4, "Priest Season 5"                      , GOSSIP_SENDER_MAIN, 502);
				player->ADD_GOSSIP_ITEM( 4, "Priest Tier 2"                        , GOSSIP_SENDER_MAIN, 602);
				player->ADD_GOSSIP_ITEM( 4, "Priest Tier 3"                        , GOSSIP_SENDER_MAIN, 702);
				player->ADD_GOSSIP_ITEM( 4, "Priest Tier 4"                        , GOSSIP_SENDER_MAIN, 802);
				player->ADD_GOSSIP_ITEM( 4, "Priest Tier 5"                        , GOSSIP_SENDER_MAIN, 902);
				player->ADD_GOSSIP_ITEM( 4, "Kirin Tor Garb"                       , GOSSIP_SENDER_MAIN, 1006);
			}
			if (player->getClass() == CLASS_HUNTER)
			{
				player->ADD_GOSSIP_ITEM( 4, "Hunter Season 1"                      , GOSSIP_SENDER_MAIN, 108);
				player->ADD_GOSSIP_ITEM( 4, "Hunter Season 2"                      , GOSSIP_SENDER_MAIN, 208);
				player->ADD_GOSSIP_ITEM( 4, "Hunter Season 3"                      , GOSSIP_SENDER_MAIN, 308);
				player->ADD_GOSSIP_ITEM( 4, "Hunter Season 4"                      , GOSSIP_SENDER_MAIN, 408);
				player->ADD_GOSSIP_ITEM( 4, "Hunter Season 5"                      , GOSSIP_SENDER_MAIN, 508);
				player->ADD_GOSSIP_ITEM( 4, "Hunter Tier 2"                        , GOSSIP_SENDER_MAIN, 608);
				player->ADD_GOSSIP_ITEM( 4, "Hunter Tier 3"                        , GOSSIP_SENDER_MAIN, 708);
				player->ADD_GOSSIP_ITEM( 4, "Hunter Tier 4"                        , GOSSIP_SENDER_MAIN, 808);
				player->ADD_GOSSIP_ITEM( 4, "Hunter Tier 5"                        , GOSSIP_SENDER_MAIN, 908);
				player->ADD_GOSSIP_ITEM( 4, "Beast Lord Armor"                     , GOSSIP_SENDER_MAIN, 1003);
			}
			if (player->getClass() == CLASS_DEATH_KNIGHT)
			{
				player->ADD_GOSSIP_ITEM( 4, "DK Season 1"                    , GOSSIP_SENDER_MAIN, 101);
				player->ADD_GOSSIP_ITEM( 4, "DK Season 2"                    , GOSSIP_SENDER_MAIN, 201);
				player->ADD_GOSSIP_ITEM( 4, "DK Season 3"                    , GOSSIP_SENDER_MAIN, 301);
				player->ADD_GOSSIP_ITEM( 4, "DK Season 4"                    , GOSSIP_SENDER_MAIN, 401);
				player->ADD_GOSSIP_ITEM( 4, "DK Season 5"                    , GOSSIP_SENDER_MAIN, 501);
				player->ADD_GOSSIP_ITEM( 4, "DK Tier 2"                      , GOSSIP_SENDER_MAIN, 601);
				player->ADD_GOSSIP_ITEM( 4, "DK Tier 3"                      , GOSSIP_SENDER_MAIN, 701);
				player->ADD_GOSSIP_ITEM( 4, "DK Tier 4"                      , GOSSIP_SENDER_MAIN, 801);
				player->ADD_GOSSIP_ITEM( 4, "DK Tier 5"                      , GOSSIP_SENDER_MAIN, 901);
				player->ADD_GOSSIP_ITEM( 4, "Heroes Scourgeborne Battlegear"           , GOSSIP_SENDER_MAIN, 1000);
				player->ADD_GOSSIP_ITEM( 4, "Darkruned Battlegear"                     , GOSSIP_SENDER_MAIN, 1001);
			}
		}

		player->SEND_GOSSIP_MENU(60001, _creature->GetGUID());         
		return true;
	}

	bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
	{
		// criteria 451 - max personal 2v2 rate
		// criteria 330 - max personal 3v3 rate // Not used for now

		/*QueryResult select = CharacterDatabase.PQuery("SELECT counter FROM character_achievement_progress WHERE criteria = '451' AND guid = '%u'", player->GetGUID());

		if (!select)
		{
			player->GetSession()->SendAreaTriggerMessage("You need to achieve 1750 personal rating in 2vs2 to use this.");
			player->CLOSE_GOSSIP_MENU();
			return false;
		}

		Field* fields = select->Fetch();
		uint32 personalRating = fields[0].GetUInt32(); // counter

		// Min achievement of 1750 rating (2v2) to use this feature
		if (personalRating <= 1750)
		{
			player->GetSession()->SendAreaTriggerMessage("You need to achieve 1750 personal rating in 2vs2 to use this.");
			player->CLOSE_GOSSIP_MENU();
			return false;
		}*/

		if (sender == GOSSIP_SENDER_MAIN)
		{
			player->PlayerTalkClass->ClearMenus();

			switch(uiAction)
			{
			case 999:
				player->CLOSE_GOSSIP_MENU();
				_creature->MonsterWhisper("Come again, friend!", player->GetGUID());
				break;

			case 100: //Season 1 Warlock
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 24553); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 24554); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 24552); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 24555); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 24556); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 101://Season 1 Warrior
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 24545); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 24546); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 24544); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 24547); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 24549); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 102://Season 1 Priest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 27708); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 27710); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 27711); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 27709); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 27707); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 103://Season 1 Paladin
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 27704); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 27706); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 27702); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 27705); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 27703); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 104://Season 1 Mage
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 25855); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 25854); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 25856); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 25858); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 25857); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 105://Season 1 Rogue
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 25830); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 25832); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 25831); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 25833); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 25834); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 106://Season 1 Shaman
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 25998); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 25999); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 25997); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 26001); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 26000); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 107://Season 1 Druid
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 31376); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 31378); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 31379); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_6_ENTRYID, 28443); //Belt
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 31377); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 28444); //Boots
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 31375); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 108://Season 1 Hunter
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 28331); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 28333); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 28334); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 28332); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 28335); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

				// Arena Season 2

			case 200://Season 2 Warlock
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 31974); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 31976); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 31977); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 31975); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 31973); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 201://Season 2 Warrior
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 30488); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 30490); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 30486); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 30489); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 30487); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 202://Season 2 Priest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 32016); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 32018); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 32019); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 32017); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 32015); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 203://Season 2 Paladin
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 31997); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 31996); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 31992); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 31995); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 31993); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 204://Season 2 Mage 
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 32048); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 32047); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 32050); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 32051); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 32049); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 205://Season 2 Rogue
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 31999); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 32001); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 32002); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 32000); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 31998); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 206://Season 2 Shaman
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 32006); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 32008); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 32004); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 32007); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 32005); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 207://Season 2 Druid
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 31998); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 31990); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 31991); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 31989); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 31987); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 208://Season 2 Hunter
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 31962); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 31964); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 31960); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 31963); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 31961); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

				// Arena Season 3

			case 300://Season 3 Warlock
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 33677); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 33679); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 33680); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 33678); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 33676); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 301://Season 3 Warrior
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 33730); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 33732); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 33728); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 33731); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 33729); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 302://Season 3 Priest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 33718); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 33720); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 33721); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 33719); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 33717); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 303://Season 3 Paladin
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 33697); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 33699); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 33695); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 33698); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 33696); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 304://Season 3 Mage
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 33758); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 33757); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 33760); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 33761); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 33759); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 305://Season 3 Rogue
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 33701); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 33703); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 33704); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 33702); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 33700); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 306://Season 3 Shaman
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 33708); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 33710); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 33706); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 33709); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 33707); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 307://Season 3 Druid
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 33691); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 33693); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 33694); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 33692); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 33690); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 308://Season 3 Hunter	
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 33666); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 33668); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 33664); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 33667); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 33665); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

				// Arena Season 4

			case 400: // Season 4 Warlock
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 35010); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 35009); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 35012); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 35013); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 35011); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 35138); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 401: // Season 4 Warrior
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 35068); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 35070); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 35066); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 35069); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 35067); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 35146); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 402: // Season 4 Priest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 35084); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 35086); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 35087); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 35085); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 35083); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 35144); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 403: // Season 4 Paladin
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 35090); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 35092); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 35088); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 35091); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 35089); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 35148); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 404: // Season 4 Mage
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 35097); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 35096); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 35099); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 35100); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 35098); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 35149); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 405: // Season 4 Rogue
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 35033); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 35035); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 35036); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 35034); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 35032); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 35141); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 406: // Season 4 Shaman
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 35079); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 35081); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 35077); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 35080); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 35078); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 35147); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 407: // Season 4 Druid
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 35112); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 35114); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 35115); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 35113); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 35111); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 35150); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 408: // Season 4 Hunter
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 34992); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 34994); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 34990); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 34993); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 34991); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 35136); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

				// Arena Season 5

			case 500: // Season 5 Warlock
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 41992); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 42010); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 41997); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 42004); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 42016); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 501: // Season 5 Warrior
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 40823); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 40862); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 40786); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 40844); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 40804); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 502: // Season 5 Priest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 41853); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 41868); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 41858); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 41863); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 41873); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 503: // Season 5 Paladin
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 40825); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 40864); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 40785); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 40846); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 40805); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 504: // Season 5 Mage
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 41945); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 41964); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 41951); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 41958); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 41970); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 505: // Season 5 Rogue
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 41671); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 41682); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 41649); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 41654); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 41766); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 506: // Season 5 Shaman
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 41150); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 41210); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 41080); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 41198); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 41136); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 507: // Season 5 Druid
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 41677); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 41714); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 41660); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 41666); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 41772); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 508: // Season 5 Hunter
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 41156); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 41216); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 41086); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 41204); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 41142); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 600://tier 2 Warlock
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 16929); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 16932); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 16931); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 16930); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 16928); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 16927); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 601://tier 2 Warrior
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 16963); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 16961); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 16966); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 16964); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 16964); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 16965); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 602://tier 2 Priest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 16921); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 16924); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 16923); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 16922); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 16920); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 16919); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 603://tier 2 Paladin
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 16955); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 16953); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 16958); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 16954); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 16956); // gloves	
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 16957); // Boots		  
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 604://tier 2 Mage
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 16914); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 16917); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 16916); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 16915); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 16913); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 16912); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 605://tier 2 Rogue
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 16908); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 16832); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 16905); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 16909); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 16907); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 16906); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 606://tier 2 Shaman
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 16947); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 16945); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 16950); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 16946); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 16948); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 16949); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 607://Tier 2 Druid
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 16900); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 16902); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 16897); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 16901); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 16899); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 16898); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 608://Tier 2 Hunter
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 16900); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 16902); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 16897); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 16901); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 16899); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 16898); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 700://tier 3 Warlock
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 22506); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 22507); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 22504); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 22505); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 22509); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 22508); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 701://tier 3 Warrior
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 22418); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 22419); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 22416); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 22417); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 22421); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 22420); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 702://tier 3 Priest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 22514); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 22515); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 22512); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 22513); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 22517); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 22516); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 703://tier 3 Paladin
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 22428); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 22429); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 22425); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 22427); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 22426); // gloves	
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 22430); // Boots		  
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 704://tier 3 Mage
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 22498); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 22499); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 22496); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 22497); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 22501); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 22500); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 705://tier 3 Rogue
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 22478); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 22479); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 22476); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 22477); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 22481); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 22480); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 706://tier 3 Shaman
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 22466); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 22467); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 22464); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 22465); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 22469); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 22468); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 707://Tier 3 Druid
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 22490); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 22491); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 22488); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 22489); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 22493); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 22492); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 708://Tier 3 Hunter -- trqbva vqrni idta
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 22490); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 22491); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 22488); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 22489); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 22493); // gloves
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 22492); // Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 800://tier 4 Warlock
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 28963); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 28967); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 28964); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 28966); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 28968); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 801://tier 4 Warrior
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 29021); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 29023); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 29019); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 29022); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 29020); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 802://tier 4 Priest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 29049); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 29054); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 29050); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 29053); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 29055); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 803://tier 4 Paladin
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 29073); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 29075); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 29071); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 29074); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 29072); // gloves		  
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 804://tier 4 Mage
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 29076); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 29079); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 29077); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 29078); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 29080); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 805://tier 4 Rogue
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 16908); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 16832); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 16905); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 16909); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 16907); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 806://tier 4 Shaman
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 29035); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 29037); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 29033); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 29036); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 29034); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 807://Tier 4 Druid
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 29086); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 29089); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 29087); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_6_ENTRYID, 28655); //Belt
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 29088); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 28752); //Boots
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 29090); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 808://Tier 4 hunter -- trqq prepravqne
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 29081); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 29084); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 29082); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 29083); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 29085); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 900://tier 5 Warlock
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 30115); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 30215); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 30113); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 30213); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 30211); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 901://tier 5 Warrior
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 30115); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 30122); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 30113); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 30116); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 30114); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 902://tier 5 Priest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 30152); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 30154); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 30150); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 30153); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 30151); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 903://tier 5 Paladin
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 30131); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 30133); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 30129); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 30132); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 30130); // gloves		  
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 904://tier 5 Mage
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 30206); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 30210); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 30196); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 30207); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 30205); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 905://tier 5 Rogue
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 30146); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 30149); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 30144); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 30148); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 30145); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 906://tier 5 Shaman
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 30190); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 30194); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 30185); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 30192); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 30189); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 907://Tier 5 Druid
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 30228); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 30230); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 30222); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 30229); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 30223); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 908://Tier 5 Druid -- trqq prepravqne
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 30228); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 30230); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 30222); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 30229); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 30223); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 1000://Heroes Scourgeborne Battlegear
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 39619); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 39621); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 39617); // chest		  
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 39620); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 39618); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 1001://Darkruned Battlegear
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 45472); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 45320); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 45225); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_6_ENTRYID, 45241); //Belt
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 45248); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 45599); //Boots
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 45481); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 1002://Choking Winter's Garb
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 50206); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 50293); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 50300); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 50269); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 50308); //Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 1003://Beast Lord Armor
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 28275); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 27801); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 28228); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_6_ENTRYID, 29261); //Belt
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 27874); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 29262); //Boots
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 27474); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 1004://Netherwind Regalia
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 16914); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 16917); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 16916); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_6_ENTRYID, 16818); //Belt
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 16915); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 16912); //Boots
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 16913); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 1005://Liadrin's Battlegear
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 47682); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 47699); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 47471); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_6_ENTRYID, 47484); //Belt
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 47440); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 47424); //Boots
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 1006://Kirin Tor Garb
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 45464); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 46344); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 45865); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_6_ENTRYID, 45306); //Belt
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 45894); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 46030); //Boots
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 46045); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 1007://Garona's Battlegear
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 48245); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 48247); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 48243); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_6_ENTRYID, 47460); //Belt
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 48246); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 47445); //Boots
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 48244); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 1008://Conqueror's Worldbreaker Battlegear
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 46201); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 46203); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 46198); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 46202); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 46199); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 1009://Nemesis Raiment 
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 27781); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 27994); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 27799); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_6_ENTRYID, 27795); //Belt
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 28338); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 27821); //Boots
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 27493); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

			case 1010:// Hellscream Battlegear
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 47678); // helm
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 48016); // shoulder
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 47415); // chest
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_6_ENTRYID, 47444); //Belt
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 47434); // pants
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 47473); //Boots
				player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 47492); // gloves
				player->CLOSE_GOSSIP_MENU();
				player->GetSession()->SendAreaTriggerMessage("Your set has been tranformed.");
				break;

				//case 9999: // Show my personal rating
				//          player->GetSession()->SendAreaTriggerMessage("Max Personal Rating: %u", personalRating);
				//          player->CLOSE_GOSSIP_MENU();
				//         break;
			default:
				break;                   
			}
		}
		return true;
	}
};

void AddSC_transmogriefer()
{
	new transmogriefer();
}