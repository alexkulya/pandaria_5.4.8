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

class Exchanger_NPC : public CreatureScript
{
public:
    Exchanger_NPC() : CreatureScript("Exchanger_NPC") { }

    bool OnGossipHello(Player *player, Creature * creature)
	{
		if (player->isInCombat())
        {
            player->CLOSE_GOSSIP_MENU();
            creature->MonsterWhisper("You are in combat!", player->GetGUID());
            return true;
        }
        else
    {
            player->ADD_GOSSIP_ITEM_EXTENDED(5, "200 Arena Points for 4000 Honor", GOSSIP_SENDER_MAIN, 1, "Are you sure you want to exchange 200 Arena Points for 4000 Honor?", 0, false); 
            player->ADD_GOSSIP_ITEM_EXTENDED(5, "4000 Honor for 200 Arena Points", GOSSIP_SENDER_MAIN, 2, "Are you sure you want to exchange 4000 Honor for 200 Arena Points?", 0, false);
    }

        player->SEND_GOSSIP_MENU(60040, creature->GetGUID());         
        return true;
    }

    bool OnGossipSelect(Player * player, Creature * creature, uint32 sender, uint32 uiAction)
    {
        if (sender == GOSSIP_SENDER_MAIN)
        {
            player->PlayerTalkClass->ClearMenus();
            switch(uiAction)
            {                                              
			case 1: 
                if (player->GetArenaPoints () >= 200)
                {
                    player->CLOSE_GOSSIP_MENU();
                    player->ModifyArenaPoints(-200);
                    player->ModifyHonorPoints(+4000);
                    creature->MonsterWhisper("|c00077766[Arena-Battles]|r You exchanged successfully!", player->GetGUID(), true);

                }
                else
                {
                    player->CLOSE_GOSSIP_MENU();
                    creature->MonsterWhisper("|c00077766[Arena-Battles]|r You don't have enough Arena Points!", player->GetGUID(), true);

                    return false;
                }
                break;
				
			case 2: 
                if (player->GetHonorPoints () >= 4000)
                {
                    player->CLOSE_GOSSIP_MENU();
                    player->ModifyArenaPoints(+200);
                    player->ModifyHonorPoints(-4000);
                    creature->MonsterWhisper("|c00077766[Arena-Battles]|r You exchanged successfully!", player->GetGUID(), true);                }
                else
                {
                    player->CLOSE_GOSSIP_MENU();
                    creature->MonsterWhisper("|c00077766[Arena-Battles]|r You don't have enough Honor Points!", player->GetGUID(), true);
                    return false;
                }
                break;
            } 
        } 
        return true;
    } 
};

void AddSC_Exchanger_NPC()
{
    new Exchanger_NPC();
}