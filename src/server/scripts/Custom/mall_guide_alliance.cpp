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
     
    class mall_guide_alliance : public CreatureScript
    {
            public:
          mall_guide_alliance() : CreatureScript("mall_guide_alliance") { }
     
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
						case 1: // Class Trainers
							player->TeleportTo(530, -3839.437744f, -11319.858398f, -126.568787f,  1.42050f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
						
						case 2: // Starter Gear
							player->TeleportTo(530, -3901.117676f, -11364.245117f, -127.461037f, 2.688920f);
							player->PlayerTalkClass->SendCloseGossip();
							break;

						case 3: // Gems & Enchants
							player->TeleportTo(530, -3907.636719f, -11377.231445f, -127.585175f,  3.547360f);
							player->PlayerTalkClass->SendCloseGossip();
							break;

						case 4: // Mounts
							player->TeleportTo(530, -3843.166260f, -11382.390625f, -126.846329f, 5.853386f);
							player->PlayerTalkClass->SendCloseGossip();
							break;

						case 5: // Legendary Weapons
							player->TeleportTo(530, -3829.321777f, -11359.865234f, -126.599297f, 5.751288f);
							player->PlayerTalkClass->SendCloseGossip();
							break;

						case 6: // Vote & Donation NPC
							player->TeleportTo(530, -3819.818115f, -11329.386719f, -126.373138f, 0.477338f);
							player->PlayerTalkClass->SendCloseGossip();
							break;

						case 7: // Arena Spectator NPC
							player->TeleportTo(530, -3898.600586f, -11352.673828f, -127.387123f, 2.621476f);
							player->PlayerTalkClass->SendCloseGossip();
							break;

					    case 8: // Season-End Rewarder NPC
							player->TeleportTo(530, -3834.148926f, -11364.698242f, -126.673103f, 6.002615f);
							player->PlayerTalkClass->SendCloseGossip();
							break;

					    case 9: // Weapons Master NPC
							player->TeleportTo(530, -3836.707520f, -11373.577148f, -126.737854f, 6.002615f);
							player->PlayerTalkClass->SendCloseGossip();
							break;

						case 10: // Guild Master 
							player->TeleportTo(530, -3902.531250f, -11387.898438f, -127.566139f, 3.897743f);
							player->PlayerTalkClass->SendCloseGossip();
							break;

						case 11: // Arena Organizer & Battlemaster
							player->TeleportTo(530, -3885.068848f, -11332.486328f, -126.277908f, 2.016714f);
							player->PlayerTalkClass->SendCloseGossip();
							break;

					    case 12: // Arena Ladder NPC
							player->TeleportTo(530, -3844.982666f, -11390.204102f, -126.897568f, 5.818044f);
							player->PlayerTalkClass->SendCloseGossip();
							break;

                                       case 13: // Transmogrification NPC
							player->TeleportTo(530, -3815.745361f, -11346.445312f, -126.388016f, 0.206264f);
							player->PlayerTalkClass->SendCloseGossip();
							break;


					    case 14: // Teleporter
							player->TeleportTo(530, -3888.955322f, -11323.371094f, -126.289673f, 1.989227f);
							player->PlayerTalkClass->SendCloseGossip();
							break;
						}
						return true;
					}
};

void AddSC_mall_guide_alliance()
{
	new mall_guide_alliance();
}