////////////////////////////////////////////////////////////////////////
//      ___                         ___       __  __  __              //
//     / _ | _______ ___  ___ _____/ _ )___ _/ /_/ /_/ /__ ___        //
//    / __ |/ __/ -_) _ \/ _ `/___/ _  / _ `/ __/ __/ / -_|_-<        //
//   /_/ |_/_/  \__/_//_/\_,_/   /____/\_,_/\__/\__/_/\__/___/.com    //
//                                                                    //
//         Developed by Natureknight Patrick and Scott.               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "ScriptMgr.h"
#include "ArenaTeamMgr.h"
#include "Common.h"
#include "DisableMgr.h"
#include "BattlegroundMgr.h"
#include "Battleground.h"
#include "ArenaTeam.h"
#include "Language.h"
#include "npc_arena1v1.h"

class npc_1v1arena : public CreatureScript
{
public:
	npc_1v1arena() : CreatureScript("npc_1v1arena") { }

	bool JoinQueueArena(Player* player, Creature* me, bool isRated)
	{
		if(!player || !me)
			return false;

		if(sWorld->getIntConfig(CONFIG_ARENA_1V1_MIN_LEVEL) > player->getLevel())
			return false;

		uint64 guid = player->GetGUID();
		uint8 arenaslot = ArenaTeam::GetSlotByType(ARENA_TYPE_10v10);
		uint8 arenatype = ARENA_TYPE_10v10;
		uint32 arenaRating = 0;
		uint32 matchmakerRating = 0;

		// ignore if we already in BG or BG queue
		if (player->InBattleground())
			return false;

		//check existance
		Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BATTLEGROUND_AA);
		if (!bg)
		{
			sLog->outError("Battleground: template bg (all arenas) not found");
			return false;
		}

		if (DisableMgr::IsDisabledFor(DISABLE_TYPE_BATTLEGROUND, BATTLEGROUND_AA, NULL))
		{
			ChatHandler(player->GetSession()).PSendSysMessage(LANG_ARENA_DISABLED);
			return false;
		}

		BattlegroundTypeId bgTypeId = bg->GetTypeID();
		BattlegroundQueueTypeId bgQueueTypeId = BattlegroundMgr::BGQueueTypeId(bgTypeId, arenatype);
		PvPDifficultyEntry const* bracketEntry = GetBattlegroundBracketByLevel(bg->GetMapId(), player->getLevel());
		if (!bracketEntry)
			return false;

		GroupJoinBattlegroundResult err = ERR_GROUP_JOIN_BATTLEGROUND_FAIL;

		// check if already in queue
        if (player->GetBattlegroundQueueIndex(bgQueueTypeId) < PLAYER_MAX_BATTLEGROUND_QUEUES)
            //player is already in this queue
            return false;
        // check if has free queue slots
        if (!player->HasFreeBattlegroundQueueId())
            return false;

		uint32 ateamId = 0;

		if(isRated)
		{
			ateamId = player->GetArenaTeamId(arenaslot);
			ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(ateamId);
			if (!at)
			{
				player->GetSession()->SendNotInArenaTeamPacket(arenatype);
				return false;
			}

			// get the team rating for queueing
			arenaRating = at->GetRating();
			matchmakerRating = arenaRating;
			// the arenateam id must match for everyone in the group

			if (arenaRating <= 0)
				arenaRating = 1;
		}

		BattlegroundQueue &bgQueue = sBattlegroundMgr->m_BattlegroundQueues[bgQueueTypeId];
		bg->SetRated(isRated);

		GroupQueueInfo* ginfo = bgQueue.AddGroup(player, NULL, bgTypeId, bracketEntry, arenatype, isRated, false, arenaRating, matchmakerRating, ateamId);
        uint32 avgTime = bgQueue.GetAverageQueueWaitTime(ginfo, bracketEntry->GetBracketId());
        uint32 queueSlot = player->AddBattlegroundQueueId(bgQueueTypeId);

        WorldPacket data;
        // send status packet (in queue)
        sBattlegroundMgr->BuildBattlegroundStatusPacket(&data, bg, queueSlot, STATUS_WAIT_QUEUE, avgTime, 0, arenatype, 0);
		player->GetSession()->SendPacket(&data);

		sBattlegroundMgr->ScheduleQueueUpdate(matchmakerRating, arenatype, bgQueueTypeId, bgTypeId, bracketEntry->GetBracketId());

		return true;
	}

	bool CreateArenateam(Player* player, Creature* me)
	{
		if(!player || !me)
			return false;

		uint8 slot = ArenaTeam::GetSlotByType(ARENA_TEAM_5v5);
		if (slot >= MAX_ARENA_SLOT)
			return false;

		// Check if player is already in an arena team
		if (player->GetArenaTeamId(slot))
		{
			player->GetSession()->SendArenaTeamCommandResult(ERR_ARENA_TEAM_CREATE_S, player->GetName(), "", ERR_ALREADY_IN_ARENA_TEAM);
			return false;
		}


		// Teamname = playername
		// if teamname exist, we have to choose another name (playername + number)
		int i = 1;
		std::stringstream teamName;
		teamName << player->GetName();
		do
		{
			if(sArenaTeamMgr->GetArenaTeamByName(teamName.str()) != NULL) // teamname exist, so choose another name
			{
				teamName.str(std::string());
				teamName << player->GetName() << i;
			}
			else
				break;
		} while (i < 100); // should never happen

		// Create arena team
		ArenaTeam* arenaTeam = new ArenaTeam();

		if (!arenaTeam->Create(player->GetGUID(), ARENA_TEAM_5v5, teamName.str(), 4283124816, 45, 4294242303, 5, 4294705149))
		{
			delete arenaTeam;
			return false;
		}

		// Register arena team
		sArenaTeamMgr->AddArenaTeam(arenaTeam);
		arenaTeam->AddMember(player->GetGUID());

		ChatHandler(player->GetSession()).SendSysMessage("1v1 Arenateam successful created!");

		return true;
	}


	bool OnGossipHello(Player* player, Creature* me)
	{
		if(!player || !me)
			return true;

		if(sWorld->getBoolConfig(CONFIG_ARENA_1V1_ENABLE) == false)
		{
			ChatHandler(player->GetSession()).SendSysMessage("1v1 disabled!");
			return true;
		}

		if (player->InBattlegroundQueueForBattlegroundQueueType(BATTLEGROUND_QUEUE_10v10))
			player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, "Leave 10v10 Skirmish Queue", GOSSIP_SENDER_MAIN, 3, "Are you sure?", 0, false);
		else
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Join 10v10 Skirmish Arena", GOSSIP_SENDER_MAIN, 20);

		//if (player->GetArenaTeamId(ArenaTeam::GetSlotByType(ARENA_TEAM_5v5)) == NULL)
		//    player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, "Create new 1v1 Arena team", GOSSIP_SENDER_MAIN, 1, "Create 1v1 arenateam?", sWorld->getIntConfig(CONFIG_ARENA_1V1_COSTS), false);
		//else
		//{
		//	if (player->InBattlegroundQueueForBattlegroundQueueType(BATTLEGROUND_QUEUE_5v5) == false)
		//	{
		//		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Sign up 1v1 Arena (Rated)", GOSSIP_SENDER_MAIN, 2);
		//		player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_INTERACT_1, "Disband Arena Team", GOSSIP_SENDER_MAIN, 5, "Are you sure?", 0, false);
		//	}
		//	player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Show statistics", GOSSIP_SENDER_MAIN, 4);
		//}
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Script Information", GOSSIP_SENDER_MAIN, 8);
		player->SEND_GOSSIP_MENU(60014, me->GetGUID());
		return true;
	}



	bool OnGossipSelect(Player* player, Creature* me, uint32 /*uiSender*/, uint32 uiAction)
	{
		if(!player || !me)
			return true;

		player->PlayerTalkClass->ClearMenus();

		switch (uiAction)
        {
		case 1: // Create new Arenateam
			{
				if(sWorld->getIntConfig(CONFIG_ARENA_1V1_MIN_LEVEL) <= player->getLevel())
				{
					if(player->GetMoney() >= sWorld->getIntConfig(CONFIG_ARENA_1V1_COSTS) && CreateArenateam(player, me))
						player->ModifyMoney(sWorld->getIntConfig(CONFIG_ARENA_1V1_COSTS) * -1);
				}
				else
				{
					ChatHandler(player->GetSession()).PSendSysMessage("You need level %u+ to create an 1v1 arenateam.", sWorld->getIntConfig(CONFIG_ARENA_1V1_MIN_LEVEL));
					player->CLOSE_GOSSIP_MENU();
					return true;
				}
			}
			break;

		case 2: // Join Queue Arena (rated)
			{
				if(Arena1v1CheckTalents(player) && JoinQueueArena(player, me, true) == false)
					ChatHandler(player->GetSession()).SendSysMessage("Something went wrong while join queue.");
				
				player->CLOSE_GOSSIP_MENU();
				return true;
			}
			break;

		case 20: // Join Queue Arena (unrated)
			{
				// Remove the talents check for 10v10 only
				if(/*Arena1v1CheckTalents(player) && */JoinQueueArena(player, me, false) == false)
					ChatHandler(player->GetSession()).SendSysMessage("Something went wrong while join queue.");
				
				player->CLOSE_GOSSIP_MENU();
				return true;
			}
			break;

		case 3: // Leave Queue
			{
				uint8 arenaType = ARENA_TYPE_10v10;
				if (player->InBattlegroundQueueForBattlegroundQueueType(BATTLEGROUND_QUEUE_3v3_SOLO))
					arenaType = ARENA_TYPE_3v3_SOLO;

				WorldPacket Data;
				Data << arenaType << (uint8)0x0 << (uint32)BATTLEGROUND_AA << (uint16)0x0 << (uint8)0x0;
				player->GetSession()->HandleBattleFieldPortOpcode(Data);
				player->CLOSE_GOSSIP_MENU();
				return true;
			}
			break;

		case 4: // get statistics
			{
				ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(player->GetArenaTeamId(ArenaTeam::GetSlotByType(ARENA_TEAM_5v5)));
				if(at)
				{
					std::stringstream s;
					s << "Rating: " << at->GetStats().Rating;
					s << "\nRank: " << at->GetStats().Rank;
					s << "\nSeason Games: " << at->GetStats().SeasonGames;
					s << "\nSeason Wins: " << at->GetStats().SeasonWins;
					s << "\nWeek Games: " << at->GetStats().WeekGames;
					s << "\nWeek Wins: " << at->GetStats().WeekWins;

					ChatHandler(player->GetSession()).PSendSysMessage(s.str().c_str());
				}
			}
			break;


		case 5: // Disband arenateam
			{
				WorldPacket Data;
				Data << (uint32)player->GetArenaTeamId(ArenaTeam::GetSlotByType(ARENA_TEAM_5v5));
				player->GetSession()->HandleArenaTeamLeaveOpcode(Data);
				ChatHandler(player->GetSession()).SendSysMessage("Arenateam deleted!");
				player->CLOSE_GOSSIP_MENU();
				return true;
			}
			break;

		case 8: // Script Info
			{
				player->GetSession()->SendAreaTriggerMessage("Developer: Natureknight");
				player->GetSession()->SendAreaTriggerMessage("Website: battlearenas.no-ip.org");
				player->CLOSE_GOSSIP_MENU();
				return true;
			}
			break;

		}

		OnGossipHello(player, me);
		return true;
	}
};


void AddSC_npc_1v1arena()
{
    new npc_1v1arena();
}