////////////////////////////////////////////////////////////////////////
//      ___                         ___       __  __  __              //
//     / _ | _______ ___  ___ _____/ _ )___ _/ /_/ /_/ /__ ___        //
//    / __ |/ __/ -_) _ \/ _ `/___/ _  / _ `/ __/ __/ / -_|_-<        //
//   /_/ |_/_/  \__/_//_/\_,_/   /____/\_,_/\__/\__/_/\__/___/.com    //
//                                                                    //
//         Developed by Natureknight Patrick and Scott.               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

/* -- NPC SQL EXAMPLE
REPLACE INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `faction_A`, `faction_H`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `dynamicflags`, `family`, `trainer_type`, `trainer_spell`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `Health_mod`, `Mana_mod`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `equipment_id`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `WDBVerified`)
VALUES('700005','0','0','0','0','0','736','0','0','0','VIP Transmog NPC','BattleArenas','','0','80','80','1','35','35','1','1','1.14286','2','0','5000','5000','0','35000','10','1','0','1','512','0','0','0','0','0','0','10000','10000','68','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','20','20','20','0','0','0','0','0','0','0','0','255','0','0','0','viptransmog','0');
*/

#include "ScriptPCH.h"

class viptransmog : public CreatureScript
{
public:
    viptransmog() : CreatureScript("viptransmog") { }

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
			if (player->getClass() == CLASS_ROGUE)  // Marm
			{
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFMarm's VIP Gear"                   , GOSSIP_SENDER_MAIN, 100);
			}
			if (player->getClass() == CLASS_PRIEST) // Mehhx, Soulrise
			{
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFMehh's VIP Gear"                   , GOSSIP_SENDER_MAIN, 101);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFSoulrise's VIP Gear"               , GOSSIP_SENDER_MAIN, 102);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFRival's VIP Gear"               , GOSSIP_SENDER_MAIN, 105);
			}
			if (player->getClass() == CLASS_WARRIOR) // Kosticka
			{
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFKosticka's VIP Gear"               , GOSSIP_SENDER_MAIN, 103);
			}
			if (player->getClass() == CLASS_DRUID) // Natureknight
			{
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFNatureknight's VIP Gear"           , GOSSIP_SENDER_MAIN, 104);
			}
			if (player->getClass() == CLASS_PALADIN) // Kaligolka
			{
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFNatureknight's VIP Gear"           , GOSSIP_SENDER_MAIN, 106);
			}
	    }

        player->SEND_GOSSIP_MENU(60007, _creature->GetGUID());         
        return true;
    }

    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
        if (sender == GOSSIP_SENDER_MAIN)
        {
            player->PlayerTalkClass->ClearMenus();
            switch(uiAction)
            {
			case 999:
			            player->CLOSE_GOSSIP_MENU();
            _creature->MonsterWhisper("Come again, friend!", player->GetGUID());
			break;
			
      case 100:// Marm's VIP Gear
          player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 34244); // helm
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 34195); // shoulder
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 34397); // chest
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_6_ENTRYID, 34558); // Waist
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 34188); // pants
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 34575); // feet
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_9_ENTRYID, 34448); // bracers
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 34234); // gloves
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 28524); // main hand
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 28524); // offhand
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 101: // Mehhx's VIP Gear
	      player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 12185); // helm
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 22742); // chest
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_6_ENTRYID, 22743); // Waist
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 22745); // pants
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 14174); // feet
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 14168); // gloves
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 5191); // main hand
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;

	  case 102: // Soulrise's Gear
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 1728); // main hand
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;

	  case 103: // Kosticka's Gear
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 32329); // helm
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 22419); // shoulder
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_7_ENTRYID, 22417); // pants
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 22421); // gloves
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 32837); // main hand
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;

	  case 104: // Natureknight
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 42322); // main hand
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;

	  case 105: // Rival
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID, 32329); // helm
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_3_ENTRYID, 32273); // shoulder
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_5_ENTRYID, 32340); // chest
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_8_ENTRYID, 34926); // feet
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_10_ENTRYID, 32353); // gloves
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 46017); // main hand
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;

	  case 106: // Kaligolka
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 7717); // main hand
	      player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;

	  default:
      break;                   
    }
   }
  return true;
 }
};

void AddSC_viptransmog()
{
    new viptransmog();
}