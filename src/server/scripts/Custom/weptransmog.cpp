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
VALUES('700010','0','0','0','0','0','736','0','0','0','Weapons Transmog NPC','BattleArenas','','0','80','80','1','35','35','1','1','1.14286','2','0','5000','5000','0','35000','10','1','0','1','512','0','0','0','0','0','0','10000','10000','68','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0','3','20','20','20','0','0','0','0','0','0','0','0','255','0','0','0','weptransmog','0');
*/

#include "ScriptPCH.h"

class weptransmog : public CreatureScript
{
public:
    weptransmog() : CreatureScript("weptransmog") { }

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
			if (player->getClass() == CLASS_ROGUE)  
			{
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFWarglaive of Azzinoth (Combat, Sublety)"     , GOSSIP_SENDER_MAIN, 100);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFWarblade of the Hakkari (Combat, Sublety)"   , GOSSIP_SENDER_MAIN, 101);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFGutgore Ripper (Assasin, Sublety)"           , GOSSIP_SENDER_MAIN, 102);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFFist of Molten Fury (Combat, Sublety)"       , GOSSIP_SENDER_MAIN, 103);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFThunderfury (Combat, Sublety)"               , GOSSIP_SENDER_MAIN, 104);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFJaded Crystal Dagger (All Spec)"             , GOSSIP_SENDER_MAIN, 113);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFStarshard Edge (All Spec)"                   , GOSSIP_SENDER_MAIN, 117);
			}
			if (player->getClass() == CLASS_PALADIN) 
			{
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFIce Spire Scepter (Holy)"                     , GOSSIP_SENDER_MAIN, 105);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFVal'anyr, Hammer of Ancient Kings (Holy)"     , GOSSIP_SENDER_MAIN, 106);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFZin'rokh, Destroyer of Worlds (Retri)"        , GOSSIP_SENDER_MAIN, 107);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFHigh Warlord's Greatsword (Retri)"            , GOSSIP_SENDER_MAIN, 108);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFGrand Marshal's Claymore (Retri)"             , GOSSIP_SENDER_MAIN, 109);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFSulfuras, Hand of Ragnaros (Retri)"           , GOSSIP_SENDER_MAIN, 110);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFWarglaive of Azzinoth (Prot)"                 , GOSSIP_SENDER_MAIN, 100);	
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFThunderfury (Prot)"                           , GOSSIP_SENDER_MAIN, 104);				
			}
			if (player->getClass() == CLASS_WARRIOR) 
			{
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFZin'rokh, Destroyer of Worlds(Arms/Fury)"        , GOSSIP_SENDER_MAIN, 107);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFHigh Warlord's Greatsword(Arms/Fury)"            , GOSSIP_SENDER_MAIN, 108);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFGrand Marshal's Claymore(Arms/Fury)"             , GOSSIP_SENDER_MAIN, 109);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFSulfuras, Hand of Ragnaros(Arms/Fury)"           , GOSSIP_SENDER_MAIN, 110);	
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFAshbringer(Arms/Fury)"                           , GOSSIP_SENDER_MAIN, 111);	
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFDraconic Avenger(Arms/Fury)"                     , GOSSIP_SENDER_MAIN, 112);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFWarglaive of Azzinoth (Prot)"                    , GOSSIP_SENDER_MAIN, 100);	
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFThunderfury (Prot)"                              , GOSSIP_SENDER_MAIN, 104);				
			}
			if (player->getClass() == CLASS_DEATH_KNIGHT) 
			{
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFZin'rokh, Destroyer of Worlds (Blood/Unholy)"        , GOSSIP_SENDER_MAIN, 107);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFHigh Warlord's Greatsword (Blood/Unholy)"            , GOSSIP_SENDER_MAIN, 108);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFGrand Marshal's Claymore (Blood/Unholy)"             , GOSSIP_SENDER_MAIN, 109);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFSulfuras, Hand of Ragnaros (Blood/Unholy)"           , GOSSIP_SENDER_MAIN, 110);	
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFAshbringer (Blood/Unholy)"                           , GOSSIP_SENDER_MAIN, 111);	
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFDraconic Avenger (Blood/Unholy)"                     , GOSSIP_SENDER_MAIN, 112);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFWarglaive of Azzinoth (Frost)"                       , GOSSIP_SENDER_MAIN, 100);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFThunderfury (Frost)"                                 , GOSSIP_SENDER_MAIN, 104);				
			}
			if (player->getClass() == CLASS_HUNTER) 
			{
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFSulfuras, Hand of Ragnaros (All Spec)"           , GOSSIP_SENDER_MAIN, 110);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFWarglaive of Azzinoth (All Spec)"               , GOSSIP_SENDER_MAIN, 100);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFThunderfury (All Spec)"                         , GOSSIP_SENDER_MAIN, 104);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFGolden Bow of Quel'Thalas (Bow)"                , GOSSIP_SENDER_MAIN, 114);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFArcanite Steam-Pistol (Gun)"                    , GOSSIP_SENDER_MAIN, 115);	
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFLegionkiller (Crossbow)"                        , GOSSIP_SENDER_MAIN, 116);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFHalberd of Smiting (All Spec)"                  , GOSSIP_SENDER_MAIN, 120);
			}
			if (player->getClass() == CLASS_PRIEST) 
			{
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFJaded Crystal Dagger (All Spec)"                 , GOSSIP_SENDER_MAIN, 113);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFStarshard Edge (All Spec)"                       , GOSSIP_SENDER_MAIN, 117);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFVal'anyr, Hammer of Ancient Kings (All Spec)"    , GOSSIP_SENDER_MAIN, 106);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFWarblade of the Hakkari (All Spec)"              , GOSSIP_SENDER_MAIN, 119);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFRoyal Scepter of Terenas (All Spec)"             , GOSSIP_SENDER_MAIN, 118);
			}
			if (player->getClass() == CLASS_MAGE) 
			{
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFJaded Crystal Dagger (All Spec)"                 , GOSSIP_SENDER_MAIN, 113);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFStarshard Edge (All Spec)"                       , GOSSIP_SENDER_MAIN, 117);	
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFVal'anyr, Hammer of Ancient Kings (All Spec)"    , GOSSIP_SENDER_MAIN, 106);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFWarblade of the Hakkari (All Spec)"              , GOSSIP_SENDER_MAIN, 119);				
			}
			if (player->getClass() == CLASS_WARLOCK) 
			{
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFJaded Crystal Dagger (All Spec)"                 , GOSSIP_SENDER_MAIN, 113);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFStarshard Edge (All Spec)"                       , GOSSIP_SENDER_MAIN, 117);	
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFVal'anyr, Hammer of Ancient Kings (All Spec)"    , GOSSIP_SENDER_MAIN, 106);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFRoyal Scepter of Terenas (All Spec)"             , GOSSIP_SENDER_MAIN, 118);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFWarblade of the Hakkari (All Spec)"              , GOSSIP_SENDER_MAIN, 119);				
			}
			if (player->getClass() == CLASS_DRUID) 
			{
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFRoyal Scepter of Terenas (Resto/Ballance)"         , GOSSIP_SENDER_MAIN, 118);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFJaded Crystal Dagger (Resto/Ballance)"             , GOSSIP_SENDER_MAIN, 113);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFSulfuras, Hand of Ragnaros (Feral)"                , GOSSIP_SENDER_MAIN, 110);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFStarshard Edge (Resto/Ballance)"                   , GOSSIP_SENDER_MAIN, 117);
                player->ADD_GOSSIP_ITEM( 3, "|cff3300FFWarblade of the Hakkari (Resto/Ballance)"          , GOSSIP_SENDER_MAIN, 119);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFHalberd of Smiting (Feral)"                        , GOSSIP_SENDER_MAIN, 120);
			}
			if (player->getClass() == CLASS_SHAMAN)
			{
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFRoyal Scepter of Terenas (Ele/Resto)"         , GOSSIP_SENDER_MAIN, 118);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFJaded Crystal Dagger (Ele/Resto)"             , GOSSIP_SENDER_MAIN, 113);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFStarshard Edge (Ele/Resto)"                   , GOSSIP_SENDER_MAIN, 117);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFVal'anyr, Hammer of Ancient Kings (Ele/Resto)" , GOSSIP_SENDER_MAIN, 106);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFZin'rokh, Destroyer of Worlds (Enhcant)"        , GOSSIP_SENDER_MAIN, 107);
				player->ADD_GOSSIP_ITEM( 3, "|cff3300FFDraconic Avenger (Enhcant)"                     , GOSSIP_SENDER_MAIN, 112);
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
			
      case 100: //Rogue
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 28524); // main hand*/
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 32838); // offhand
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 101:
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 5191); // main hand*/
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19866); // offhand
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 102:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 17071); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19866); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 103:
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 17071); // main hand*/
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 32945); // offhand
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 104:
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 17071); // main hand*/
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 105: // Paladin
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 40488); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 106:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 46017); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 107:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 19854); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 108:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 18877); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 109:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 18876); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 110:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 17182); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 111:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 13262); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 112:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 19354); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 113:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 34604); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 114:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_18_ENTRYID, 34196); // ranged
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 115:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_18_ENTRYID, 29949); // ranged
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 116:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_18_ENTRYID, 32253); // ranged
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 117:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 45620); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 118:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 50428); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;
	  
	  case 119:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 19866); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  player->CLOSE_GOSSIP_MENU();
		  _creature->MonsterWhisper("Your set has been Transformed!", player->GetGUID());
      break;

	  case 120:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 19874); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
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

void AddSC_weptransmog()
{
    new weptransmog();
}