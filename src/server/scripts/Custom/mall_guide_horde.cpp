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
     
    class mall_guide_horde : public CreatureScript
    {
            public:
          mall_guide_horde() : CreatureScript("mall_guide_horde") { }
     
                    bool OnGossipHello(Player * player, Creature * creature)
                    {
						player->ADD_GOSSIP_ITEM(4, "Class Trainers", GOSSIP_SENDER_MAIN, 1);
						player->ADD_GOSSIP_ITEM(4, "Main Set (Starting Gear)", GOSSIP_SENDER_MAIN, 2);						
						player->ADD_GOSSIP_ITEM(4, "Gems & Enchants", GOSSIP_SENDER_MAIN, 3);
						player->ADD_GOSSIP_ITEM(4, "Mounts", GOSSIP_SENDER_MAIN, 4);
						player->ADD_GOSSIP_ITEM(4, "Legendary Weapons", GOSSIP_SENDER_MAIN, 5);                                
						player->ADD_GOSSIP_ITEM(4, "Vote & Donation NPC", GOSSIP_SENDER_MAIN, 6);
						player->ADD_GOSSIP_ITEM(4, "Arena Spectator NPC", GOSSIP_SENDER_MAIN, 7);
						player->ADD_GOSSIP_ITEM(4, "Season-End Rewarder NPC", GOSSIP_SENDER_MAIN, 8);
						player->ADD_GOSSIP_ITEM(4, "Weapons Master", GOSSIP_SENDER_MAIN, 9);  
						player->ADD_GOSSIP_ITEM(4, "Guild Master", GOSSIP_SENDER_MAIN, 10);
						player->ADD_GOSSIP_ITEM(4, "Arena Organizer & Battlemaster", GOSSIP_SENDER_MAIN, 11);
						player->ADD_GOSSIP_ITEM(4, "Arena Ladder NPC", GOSSIP_SENDER_MAIN, 12);
						player->ADD_GOSSIP_ITEM(4, "Transmogrification NPC", GOSSIP_SENDER_MAIN, 13);
						player->ADD_GOSSIP_ITEM(4, "Teleporter", GOSSIP_SENDER_MAIN, 14);
						player->PlayerTalkClass->SendGossipMenu(60024, creature->GetGUID());
						return true;
					}
					
					bool OnGossipSelect(Player* player, Creature* creature, uint32 uiSender, uint32 uiAction)
					{
						player->PlayerTalkClass->ClearMenus();
               
						switch(uiAction)
						{
							// Class Trainers
						       case 1:
							player->TeleportTo(564, 950.369995f, 269.109222f, 86.160728f, 6.261520f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
						       // Main Set (Starting Gear)
						       case 2:
							player->TeleportTo(564, 906.616455f, 290.514526f, 86.160744f, 3.116306f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
							// Gems & Enchants
							case 3:
							player->TeleportTo(564, 906.987915f, 263.143677f, 86.160713f,  3.142154f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
							// Mounts
							case 4:
							player->TeleportTo(564, 950.008911f, 289.002502f, 86.160675f, 1.165132f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
							// Legendary Weapons
							case 5:
							player->TeleportTo(564, 934.197021f, 226.524994f, 85.641296f, 1.632190f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
							// Vote & Donation NPC
							case 6:
							player->TeleportTo(564, 954.783020f, 236.684006f,  86.160797f, 2.169400f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
							// Arena Spectator NPC
							case 7:
							player->TeleportTo(564, 937.158569f, 299.728180f, 86.16066f, 1.049940f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
							// Season-End Rewarder NPC
					              case 8: 
							player->TeleportTo(564, 951.695007f, 234.578003f, 86.160797f, 2.169400f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
							/* // Weapons Master
							case 9:
							player->TeleportTo(564, 1310.123901f, 284.520752f, -63.679115f, 1.905769f);
							player->PlayerTalkClass->SendCloseGossip();
							break; */
							// Guild Master
						       case 10:
							player->TeleportTo(564, 942.415039f,  296.032349f, 86.160675f, 1.258596f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
							// Arena Organizer & Battlemaster
						       case 11:
							player->TeleportTo(564, 927.955627f, 298.752563f, 86.194626f, 1.547622f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
							// Arena Ladder NPC
							case 12:
							player->TeleportTo(564, 917.565979f, 304.085999f, 86.124100f, 5.192800f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
							// Transmogrification NPC
							case 13:
							player->TeleportTo(564, 927.212524f, 232.424362f, 85.641174f, 4.663166f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
							// Teleporter
							case 14:
							player->TeleportTo(564, 910.304993f, 293.335236f, 85.641251f, 2.212724f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
						}
						return true;
					}
};

void AddSC_mall_guide_horde()
{
	new mall_guide_horde();
}