/////////////////////////////////////////////////////////////////////////////
//        ____        __  __  __     ___                                   //
//       / __ )____ _/ /_/ /_/ /__  /   |  ________  ____  ____ ______     //
//      / __  / __ `/ __/ __/ / _ \/ /| | / ___/ _ \/ __ \/ __ `/ ___/     //
//     / /_/ / /_/ / /_/ /_/ /  __/ ___ |/ /  /  __/ / / / /_/ (__  )      //
//    /_____/\__,_/\__/\__/_/\___/_/  |_/_/   \___/_/ /_/\__,_/____/       //
//         Developed by Natureknight for BattleArenas.no-ip.org            //
/////////////////////////////////////////////////////////////////////////////

#include "ScriptPCH.h"
#include "Group.h"

const uint32 ONE_CHARACTER_VIP = 4992700;

class Teleporter_NPC : public CreatureScript
{
public:
	Teleporter_NPC() : CreatureScript("Teleporter_NPC"){}

	bool OnGossipHello(Player * pPlayer, Creature * pCreature)
	{
		// Check if VIP, One-Character-VIP or GM rights present on this account/character
		if (pPlayer->GetSession()->GetSecurity() >= 1 || pPlayer->HasItemCount(ONE_CHARACTER_VIP, 1))
			pPlayer->ADD_GOSSIP_ITEM(4, "Menu only for VIP players", GOSSIP_SENDER_MAIN, 0);

		switch (pPlayer->GetTeam())
		{
		case ALLIANCE:
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Stormwind - Mall", GOSSIP_SENDER_MAIN, 2, "Are you sure you want to go to Stormwind Mall?", 0, false);
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Ironforge - Mall", GOSSIP_SENDER_MAIN, 9, "Are you sure you want to go to Ironforge Mall?", 0, false);
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Stranglethorn Vale - PvP", GOSSIP_SENDER_MAIN, 17, "Are you sure you want to go to Stranglethorn Vale?", 0, false);
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Goldenmist Village - PvP", GOSSIP_SENDER_MAIN, 43, "Are you sure you want to go to Goldenmist Village?", 0, false);
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Elwynn Forest", GOSSIP_SENDER_MAIN, 47, "Are you sure you want to go to Elwynn Forest?", 0, false);
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Raid for Orgrimmar", GOSSIP_SENDER_MAIN, 49, "Are you sure you want to go to Durotar? (Need atleast 3 players)", 0, false);
			break;
		case HORDE:
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Orgrimmar - Mall", GOSSIP_SENDER_MAIN, 4, "Are you sure you want to go to Orgrimmar Mall?", 0, false);
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Silvermoon - Mall", GOSSIP_SENDER_MAIN, 3, "Are you sure you want to go to Silvermoon Mall?", 0, false);
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Stranglethorn Vale - PvP", GOSSIP_SENDER_MAIN, 17, "Are you sure you want to go to Stranglethorn Vale?", 0, false);
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Goldenmist Village - PvP", GOSSIP_SENDER_MAIN, 44, "Are you sure you want to go to Goldenmist Village?", 0, false);
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Durotar", GOSSIP_SENDER_MAIN, 48, "Are you sure you want to go to Durotar?", 0, false);
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Raid for Stormwind", GOSSIP_SENDER_MAIN, 50, "Are you sure you want to go to Durotar? (Need atleast 3 players)", 0, false);
			break;
		}
		pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Dueling Zone", GOSSIP_SENDER_MAIN, 45, "Are you sure you want to go to Dueling Zone?", 0, false);
		pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Ring of Trials (Nagrand Arena)", GOSSIP_SENDER_MAIN, 46, "Are you sure you want to go to Nagrand Arena?", 0, false);
		pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Transmogrification Place", GOSSIP_SENDER_MAIN, 18, "Are you sure you want to go to Transmogrification Place?", 0, false);
		pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Professions Place", GOSSIP_SENDER_MAIN, 5, "Are you sure you want to go to Professions Mall?", 0, false);
		pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Tanaris - Custom Jump Event", GOSSIP_SENDER_MAIN, 7, "Are you sure you want to go to Custom jump event?", 0, false);
		pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Random Queue Places", GOSSIP_SENDER_MAIN, 16, "Are you sure you want to do this?", 0, false);
		pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Random Queue Places (As Group)", GOSSIP_SENDER_MAIN, 8, "Are you sure you want to do this?", 0, false);
		if (pPlayer->getClass() == CLASS_HUNTER)
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, "Hunter's Tame Pet Zone", GOSSIP_SENDER_MAIN, 19, "Are you sure you want to go to pets zone?", 0, false);
		else if (pPlayer->getClass() != CLASS_HUNTER)
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, "Hunter's Tame Pet Zone", GOSSIP_SENDER_MAIN, 42, "Are you sure you want to go to pets zone?", 0, false);
		pPlayer->ADD_GOSSIP_ITEM(4, "Additional Features", GOSSIP_SENDER_MAIN, 20);
		pPlayer->SEND_GOSSIP_MENU(60020, pCreature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player * pPlayer, Creature * pCreature, uint32 sender, uint32 uiAction)
	{
		pPlayer->PlayerTalkClass->ClearMenus();
		Group * group = pPlayer->GetGroup();
		int randomPlace = urand(1, 8);

		// Dont let players use teleporter in combat
		if (pPlayer->isInCombat())
		{
			pCreature->MonsterWhisper("You should be out of combat!", pPlayer->GetGUID());
			pPlayer->CLOSE_GOSSIP_MENU();
			return false;
		}

		switch (uiAction)
		{
		case 0: // VIP mall
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, "Teleport to VIP mall", GOSSIP_SENDER_MAIN, 13, "Are you sure you want to go to VIP Mall?", 0, false);
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, "Teleport to VIP Island", GOSSIP_SENDER_MAIN, 14, "Are you sure you want to go to VIP Island?", 0, false);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 15);
			pPlayer->SEND_GOSSIP_MENU(60020, pCreature->GetGUID());
			break;

		case 1: // Darnassus Mall
			pPlayer->TeleportTo(1, 9949.658203f, 2374.083252f, 1330.001345f, 4.731387f);
			break;

		case 2: // Stormwind Mall
			pPlayer->TeleportTo(0, -8850.778320f, 649.876648f, 96.325790f, 5.354052f);
			break;

		case 3: // Silvermoon Mall
			pPlayer->TeleportTo(530, 9490.633789f, -7277.810059f, 14.296535f, 5.896964f);
			break;

		case 4: // Orgrimmar Mall
			pPlayer->TeleportTo(1, 1501.500000f, -4415.439941f, 22.078300f, 0.104575f);
			break;

		case 5: // Professions Place
			pPlayer->TeleportTo(571,	5831.356445f,	  -3099.036133f,	  300.452850f,	 5.150246f);
			break;

		case 6: // Dueling Zone
			pPlayer->TeleportTo(1,	 6562.940918f,	 -4048.786621f,	  658.326782f,   1.849663f);
			break;

		case 7: // Custom Jump Event
			pPlayer->TeleportTo(1,	-6933.268066f,	-4905.634766f,	 0.714660f,   4.703444f);
			break;

		case 8: // Random queue places as group
			if (!group) // If the player isn't in a group, then...
			{
				pPlayer->GetSession()->SendAreaTriggerMessage("You are not in group!");
				pPlayer->CLOSE_GOSSIP_MENU();
				return false;
			}

			switch (randomPlace)
			{
			case 1: // Moonglade
				pPlayer->TeleportTo(1,   7565.310059f,   -2931.850098f,   466.323090f,   4.646120f); 
				for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
				{

					Player * plr = itr->getSource();

					if (!plr || !plr->GetSession())
						continue;

					if (plr->GetGUID() == pPlayer->GetGUID())
						continue;

					if (plr->IsBeingTeleported()) // If is being teleported..
						continue;

					if (plr->isInFlight()) // Is the player in flight?
					{
						plr->GetMotionMaster()->MovementExpired();
						plr->CleanupAfterTaxiFlight();
					}
					else
						plr->SaveRecallPosition();

					plr->SetSummonPoint(1,   7565.310059f,   -2931.850098f,   466.323090f); 
					WorldPacket data(SMSG_SUMMON_REQUEST, 8+4+4);
					data << uint64(pPlayer->GetGUID());                                     // summoner guid
					data << uint32(493);                                                    // Moonglade
					data << uint32(MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS);                // auto decline after msecs
					plr->GetSession()->SendPacket(&data);
				}
				break;

			case 2: // Nagrand
				pPlayer->TeleportTo(530,   -632.664978f,   8638.459961f,   312.444000f,   2.385210f); 
				for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
				{

					Player * plr = itr->getSource();

					if (!plr || !plr->GetSession())
						continue;

					if (plr->GetGUID() == pPlayer->GetGUID())
						continue;

					if (plr->IsBeingTeleported()) // If is being teleported..
						continue;

					if (plr->isInFlight()) // Is the player in flight?
					{
						plr->GetMotionMaster()->MovementExpired();
						plr->CleanupAfterTaxiFlight();
					}
					else
						plr->SaveRecallPosition();

					plr->SetSummonPoint(530,   -632.664978f,   8638.459961f,   312.444000f); 
					WorldPacket data(SMSG_SUMMON_REQUEST, 8+4+4);
					data << uint64(pPlayer->GetGUID());                                      // summoner guid
					data << uint32(3518);                                                    // Nagrand
					data << uint32(MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS);                 // auto decline after msecs
					plr->GetSession()->SendPacket(&data);
				}
				break;

			case 3: // Old Ironforge
				pPlayer->TeleportTo(0,   -4821.729980f,   -976.239014f,   464.709991f,   0.659974f); 
				for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
				{

					Player * plr = itr->getSource();

					if (!plr || !plr->GetSession())
						continue;

					if (plr->GetGUID() == pPlayer->GetGUID())
						continue;

					if (plr->IsBeingTeleported()) // If is being teleported..
						continue;

					if (plr->isInFlight()) // Is the player in flight?
					{
						plr->GetMotionMaster()->MovementExpired();
						plr->CleanupAfterTaxiFlight();
					}
					else
						plr->SaveRecallPosition();

					plr->SetSummonPoint(0,   -4821.729980f,   -976.239014f,   464.709991f); 
					WorldPacket data(SMSG_SUMMON_REQUEST, 8+4+4);
					data << uint64(pPlayer->GetGUID());                                     // summoner guid
					data << uint32(1537);                                                   // summoner zone
					data << uint32(MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS);                // auto decline after msecs
					plr->GetSession()->SendPacket(&data);
				}
				break;

			case 4: // Ashenvale
				pPlayer->TeleportTo(1,   1786.410034f,   -1240.949951f,   147.964996f,   1.537370f); 
				for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
				{

					Player * plr = itr->getSource();

					if (!plr || !plr->GetSession())
						continue;

					if (plr->GetGUID() == pPlayer->GetGUID())
						continue;

					if (plr->IsBeingTeleported()) // If is being teleported..
						continue;

					if (plr->isInFlight()) // Is the player in flight?
					{
						plr->GetMotionMaster()->MovementExpired();
						plr->CleanupAfterTaxiFlight();
					}
					else
						plr->SaveRecallPosition();

					plr->SetSummonPoint(1,   1786.410034f,   -1240.949951f,   147.964996f); 
					WorldPacket data(SMSG_SUMMON_REQUEST, 8+4+4);
					data << uint64(pPlayer->GetGUID());                                     // summoner guid
					data << uint32(331);                                                    // summoner zone
					data << uint32(MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS);                // auto decline after msecs
					plr->GetSession()->SendPacket(&data);
				}
				break;

			case 5: // The Barrens
				pPlayer->TeleportTo(1,   -1677.339966f,   -4331.270020f,   2.787450f,   2.379600f);
				for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
				{

					Player * plr = itr->getSource();

					if (!plr || !plr->GetSession())
						continue;

					if (plr->GetGUID() == pPlayer->GetGUID())
						continue;

					if (plr->IsBeingTeleported()) // If is being teleported..
						continue;

					if (plr->isInFlight()) // Is the player in flight?
					{
						plr->GetMotionMaster()->MovementExpired();
						plr->CleanupAfterTaxiFlight();
					}
					else
						plr->SaveRecallPosition();

					plr->SetSummonPoint(1,   -1677.339966f,   -4331.270020f,   2.787450f); 
					WorldPacket data(SMSG_SUMMON_REQUEST, 8+4+4);
					data << uint64(pPlayer->GetGUID());                                    // summoner guid
					data << uint32(17);                                                    // summoner zone
					data << uint32(MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS);               // auto decline after msecs
					plr->GetSession()->SendPacket(&data);
				}
				break;

			case 6: // Forge Camp
				pPlayer->TeleportTo(530,   -1376.510010f,   9030.580078f,   53.928398f,   4.707840f); 
				for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
				{

					Player * plr = itr->getSource();

					if (!plr || !plr->GetSession())
						continue;

					if (plr->GetGUID() == pPlayer->GetGUID())
						continue;

					if (plr->IsBeingTeleported()) // If is being teleported..
						continue;

					if (plr->isInFlight()) // Is the player in flight?
					{
						plr->GetMotionMaster()->MovementExpired();
						plr->CleanupAfterTaxiFlight();
					}
					else
						plr->SaveRecallPosition();

					plr->SetSummonPoint(530,   -1376.510010f,   9030.580078f,   53.928398f);
					WorldPacket data(SMSG_SUMMON_REQUEST, 8+4+4);
					data << uint64(pPlayer->GetGUID());                                      // summoner guid
					data << uint32(3518);                                                    // summoner zone
					data << uint32(MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS);                 // auto decline after msecs
					plr->GetSession()->SendPacket(&data);
				}
				break;

			case 7: // Telaar
				pPlayer->TeleportTo(530,   -2718.120117f,   7300.051270f,   88.628456f,   5.855799f); 
				for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
				{

					Player * plr = itr->getSource();

					if (!plr || !plr->GetSession())
						continue;

					if (plr->GetGUID() == pPlayer->GetGUID())
						continue;

					if (plr->IsBeingTeleported()) // If is being teleported..
						continue;

					if (plr->isInFlight()) // Is the player in flight?
					{
						plr->GetMotionMaster()->MovementExpired();
						plr->CleanupAfterTaxiFlight();
					}
					else
						plr->SaveRecallPosition();

					plr->SetSummonPoint(530,   -2718.120117f,   7300.051270f,   88.628456f); 
					WorldPacket data(SMSG_SUMMON_REQUEST, 8+4+4);
					data << uint64(pPlayer->GetGUID());                                       // summoner guid
					data << uint32(3518);                                                     // summoner zone
					data << uint32(MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS);                  // auto decline after msecs
					plr->GetSession()->SendPacket(&data);
				}
				break;

			case 8: // Nagrand Arena
				pPlayer->TeleportTo(530,  -2104.031982f,  6564.698730f, 5.153860f, 3.481085f);
				for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
				{

					Player * plr = itr->getSource();

					if (!plr || !plr->GetSession())
						continue;

					if (plr->GetGUID() == pPlayer->GetGUID())
						continue;

					if (plr->IsBeingTeleported()) // If is being teleported..
						continue;

					if (plr->isInFlight()) // Is the player in flight?
					{
						plr->GetMotionMaster()->MovementExpired();
						plr->CleanupAfterTaxiFlight();
					}
					else
						plr->SaveRecallPosition();

					plr->SetSummonPoint(530,  -2104.031982f,  6564.698730f, 5.153860f);
					WorldPacket data(SMSG_SUMMON_REQUEST, 8+4+4);
					data << uint64(pPlayer->GetGUID());                                       // summoner guid
					data << uint32(3518);                                                     // summoner zone
					data << uint32(MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS);                  // auto decline after msecs
					plr->GetSession()->SendPacket(&data);
				}
				break;
			}
			return true;
			break;

		case 9: // Ironforge Mall
			pPlayer->TeleportTo(0,	-4935.559570f,	 -937.766174f,	 502.960754f,	  5.400695f);
			break;

		case 10: // Desolace Mall
			pPlayer->TeleportTo(1,	170.343735f,	 1206.189819f,	 166.235794f,	  2.639121f);
			break;

		case 11: // Thunder Bluff Mall
			pPlayer->TeleportTo(1,	-1208.136597f,	-96.185158f,	 162.373642f,   1.586078f);
			break;

		case 12: // Undercity Mall
			pPlayer->TeleportTo(0,	1289.703125f,	314.571381f,	 -57.320896f,   1.272796f);
			break;

		case 13: // VIP Mall 
			pPlayer->TeleportTo(575, 296.799896f, -330.603210f, 86.367546f,  4.712197f); // Utgarde Pinnacle
			break;

		case 14: // VIP Island
			pPlayer->TeleportTo(1, -11810.799805f, -4754.740234f, 6.293820f,  2.159030f);
			break;

		case 15: // Main Page
			OnGossipHello(pPlayer, pCreature);
			break;

		case 16: // Arena-Queue Places
			switch (randomPlace)
			{
			case 1: pPlayer->TeleportTo(1,   7565.310059f,   -2931.850098f,   466.323090f,   4.646120f); // Moonglade
				break;

			case 2: pPlayer->TeleportTo(530,   -632.664978f,   8638.459961f,   312.444000f,   2.385210f); // Nagrand
				break;

			case 3: pPlayer->TeleportTo(0,   -4821.729980f,   -976.239014f,   464.709991f,   0.659974f); // Old Ironforge
				break;

			case 4: pPlayer->TeleportTo(1,   1786.410034f,   -1240.949951f,   147.964996f,   1.537370f); // Ashenvale
				break;

			case 5: pPlayer->TeleportTo(1,   -1677.339966f,   -4331.270020f,   2.787450f,   2.379600f); // The Barrens
				break;

			case 6: pPlayer->TeleportTo(530,   -1376.510010f,   9030.580078f,   53.928398f,   4.707840f); // Forge Camp
				break;

			case 7: pPlayer->TeleportTo(530,   -2718.120117f,   7300.051270f,   88.628456f,   5.855799f); // Telaar
				break;

			case 8: pPlayer->TeleportTo(530,  -2104.031982f,  6564.698730f, 5.153860f, 3.481085f); // Nagrand Arena
				break;
			}
			return true;
			break;

		case 17: // Stranglethorn Vale
			pPlayer->TeleportTo(0,	-13265.961914f,	  156.842224f,	  35.670128f,	 4.207355f);
			break;

		case 33: // ICC Dungeons - Coming Soon
			pPlayer->GetSession()->SendAreaTriggerMessage("ICC Dungeons will be available soon!");
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 18: // Transmogrification Place
			pPlayer->TeleportTo(571,	5773.749512f,	  641.840881f,	  562.136536f,	 4.794876f);
			break;

		case 19: // Hunter's Tame Pet Zone
			pPlayer->TeleportTo(0, -11196.299805f, -2196.830078f, 20.282400f, 6.186680f);
			pPlayer->GetSession()->SendAreaTriggerMessage("Only hunters can see the menu Hunter's Tame Pet Zone in the teleporter.");
			break;

		case 20: // Buffs
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Native Morphs", GOSSIP_SENDER_MAIN, 21);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Give me buffs", GOSSIP_SENDER_MAIN, 22);
			pPlayer->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, "Reset my talents", GOSSIP_SENDER_MAIN, 31, "Are you sure you want to reset your talent points?", 0, false);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 15);
			pPlayer->SEND_GOSSIP_MENU(60022, pCreature->GetGUID());
			break;

		case 21: // Native morphs
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Tauren Female", GOSSIP_SENDER_MAIN, 23);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Tauren Male", GOSSIP_SENDER_MAIN, 24);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Gnome Female", GOSSIP_SENDER_MAIN, 25);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Gnome Male", GOSSIP_SENDER_MAIN, 26);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Blood Elf Female", GOSSIP_SENDER_MAIN, 27);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Blood Elf Male", GOSSIP_SENDER_MAIN, 28);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Human Female", GOSSIP_SENDER_MAIN, 29);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Human Male", GOSSIP_SENDER_MAIN, 30);
			pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Previous Page", GOSSIP_SENDER_MAIN, 20);
			pPlayer->SEND_GOSSIP_MENU(60021, pCreature->GetGUID());
			break;

		case 22: // Buffs
			pPlayer->CastSpell(pPlayer, 48102, true); // Stamina
			pPlayer->CastSpell(pPlayer, 48073, true); // Divine Spirit
			pPlayer->CastSpell(pPlayer, 48169, true); // Shadow Protection
			pPlayer->CastSpell(pPlayer, 48161, true); // PW:F
			pPlayer->CastSpell(pPlayer, 20217, true); // Blessing of Kings
			pPlayer->CastSpell(pPlayer, 42995, true); // Arcane Intellect
			pPlayer->CastSpell(pPlayer, 48469, true); // Mark of the Wild
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 23: // Tauren Female
			pCreature->CastSpell(pPlayer, 37811, true);
			pPlayer->CastSpell(pPlayer, 24222, true);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 24: // Tauren Male
			pCreature->CastSpell(pPlayer, 37810, true);
			pPlayer->CastSpell(pPlayer, 24222, true);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 25: // Gnome Female
			pCreature->CastSpell(pPlayer, 37809, true);
			pPlayer->CastSpell(pPlayer, 24222, true);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 26: // Gnome Male
			pCreature->CastSpell(pPlayer, 37808, true);
			pPlayer->CastSpell(pPlayer, 24222, true);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 27: // Blood Elf Female
			pCreature->CastSpell(pPlayer, 37806, true);
			pPlayer->CastSpell(pPlayer, 24222, true);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 28: // Blood Elf Male
			pCreature->CastSpell(pPlayer, 37807, true);
			pPlayer->CastSpell(pPlayer, 24222, true);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 29: // Human Female
			pCreature->CastSpell(pPlayer, 37805, true);
			pPlayer->CastSpell(pPlayer, 24222, true);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 30: // Human Male
			pCreature->CastSpell(pPlayer, 35466, true);
			pPlayer->CastSpell(pPlayer, 24222, true);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 31: // Reset talents
			pPlayer->resetTalents(true);
			pPlayer->SendTalentsInfoData(false);
			pPlayer->GetSession()->SendAreaTriggerMessage("Your talents has been reset.");
			pPlayer->CastSpell(pPlayer, 24222, true);
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 35: // Ravenholdt Manor Mall
			pPlayer->TeleportTo(0, 1.827456f, -1620.976807f, 196.651855f, 1.151698f);
			break;

		case 36: // Dueling Zone (Ravenholdt Manor Mall)
			pPlayer->TeleportTo(0, 70.579247f, -1506.760986f, 174.295914f, 4.210823f);
			break;

		case 40: // Already in zone
			pPlayer->GetSession()->SendAreaTriggerMessage("You're already in this zone!");
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 41: // Already in Dueling zone / Mall
			pPlayer->GetSession()->SendAreaTriggerMessage("You're already in Dueling Zone! It's just outside.");
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 42: // you're not a hunter
			pPlayer->GetSession()->SendAreaTriggerMessage("You're not a hunter!");
			pPlayer->CLOSE_GOSSIP_MENU();
			break;

		case 43: // Goldenmist Village - Alliance
			pPlayer->TeleportTo(530, 7739.864258f, -6075.500488f,  19.238945f,  6.100757f);
			break;

		case 44: // Goldenmist Village - Horde
			pPlayer->TeleportTo(530,  8001.195801f,  -6227.183105f,  22.003067f,  2.688986f);
			break;

		case 45: // Dueling Zone (AT)
			pPlayer->TeleportTo(1,  5210.732422f,  -4815.695313f,   701.046265f,  0.678023f);
			break;

		case 46: // Nagrand Arena
			pPlayer->TeleportTo(530,  -2104.031982f,  6564.698730f, 5.153860f, 3.481085f);
			break;

		case 47: // Elwynn Forest
			pPlayer->TeleportTo(0, -9103.945313f, 407.655640f, 92.646919f, 3.781690f);
			break;

		case 48: // Durotar
			pPlayer->TeleportTo(1, 1359.506348f, -4369.427246f, 26.164385f, 3.450796f);
			break;

		case 49: // Raid for Orgrimmar
			{
				if (!group) // If the player isn't in a group, then...
				{
					pPlayer->GetSession()->SendAreaTriggerMessage("You are not in group!");
					pPlayer->CLOSE_GOSSIP_MENU();
					return false;
				}

				pPlayer->TeleportTo(1,  1014.313416f,  -4449.859375f, 11.343950f, 0.458436f);
				for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
				{

					Player * plr = itr->getSource();

					if (!plr || !plr->GetSession())
						continue;

					if (plr->GetGUID() == pPlayer->GetGUID())
						continue;

					if (plr->IsBeingTeleported()) // If is being teleported..
						continue;

					if (plr->isInFlight()) // Is the player in flight?
					{
						plr->GetMotionMaster()->MovementExpired();
						plr->CleanupAfterTaxiFlight();
					}
					else
						plr->SaveRecallPosition();

					plr->SetSummonPoint(1,  1014.313416f,  -4449.859375f, 11.343950f);
					WorldPacket data(SMSG_SUMMON_REQUEST, 8+4+4);
					data << uint64(pPlayer->GetGUID());                                       // summoner guid
					data << uint32(14);                                                       // summoner zone
					data << uint32(MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS);                  // auto decline after msecs
					plr->GetSession()->SendPacket(&data);
				}
			}
			break;

		case 50: // Raid for Stormwind
			{
				if (!group) // If the player isn't in a group, then...
				{
					pPlayer->GetSession()->SendAreaTriggerMessage("You are not in group!");
					pPlayer->CLOSE_GOSSIP_MENU();
					return false;
				}

				pPlayer->TeleportTo(0,  -9459.583984f,  63.895885f, 55.876137f, 0.485727f);
				for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
				{

					Player * plr = itr->getSource();

					if (!plr || !plr->GetSession())
						continue;

					if (plr->GetGUID() == pPlayer->GetGUID())
						continue;

					if (plr->IsBeingTeleported()) // If is being teleported..
						continue;

					if (plr->isInFlight()) // Is the player in flight?
					{
						plr->GetMotionMaster()->MovementExpired();
						plr->CleanupAfterTaxiFlight();
					}
					else
						plr->SaveRecallPosition();

					plr->SetSummonPoint(0,  -9459.583984f,  63.895885f, 55.876137f);
					WorldPacket data(SMSG_SUMMON_REQUEST, 8+4+4);
					data << uint64(pPlayer->GetGUID());                                       // summoner guid
					data << uint32(12);                                                       // summoner zone
					data << uint32(MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS);                  // auto decline after msecs
					plr->GetSession()->SendPacket(&data);
				}
			}
			break;
		}
		return true;
	}
};

void AddSC_Teleporter_NPC()
{
	new Teleporter_NPC();
}