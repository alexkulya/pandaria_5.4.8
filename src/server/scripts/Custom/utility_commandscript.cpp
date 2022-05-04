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
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Chat.h"
#include "Group.h"
#include "ArenaTeam.h"
#include "ArenaTeamMgr.h"

//This script is made by Blex and was orginally posted on www.ac-web.org
//This script was created after being inspired by Arena-Tournament's player commands. www.arena-tournament.com

class utility_commandscript : public CommandScript
{
public:
    utility_commandscript() : CommandScript("utility_commandscript") { }

    ChatCommand* GetCommands() const
    {
		static ChatCommand mmrCommandTable[] =
		{
			{ "3v3solo",		   SEC_PLAYER,      false, &HandleMmr3v3SoloCommand,		     "", NULL },
			{ "2v2",			   SEC_PLAYER,      false, &HandleMmr2v2Command,		         "", NULL },
			{ "3v3",			   SEC_PLAYER,      false, &HandleMmr3v3Command,		         "", NULL },
			{ NULL,             0,                  false, NULL,                                 "", NULL }
		};
        static ChatCommand utilityCommandTable[] =
        {
            { "changerace",            SEC_PLAYER,  false, &HandleChangeRaceCommand,             "", NULL },
			{ "changefaction",		   SEC_PLAYER,  false, &HandleChangeFactionCommand,		     "", NULL },
			{ "maxskills",			   SEC_PLAYER,  false, &HandleMaxSkillsCommand,		         "", NULL },
			{ "customize",			   SEC_PLAYER,  false, &HandleCustomizeCommand,		         "", NULL },
			{ "removeplayers",	       SEC_OWNER,   false, &HandleRemoveFakePlayersCommand,		 "", NULL },
			{ "addplayers",		       SEC_OWNER,   false, &HandleAddFakePlayersCommand,		 "", NULL },
			{ "mmr",                   SEC_PLAYER,  true, NULL,                                  "", mmrCommandTable },
            { NULL,             0,                  false, NULL,                                 "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "utility",           SEC_PLAYER,      true, NULL,                              "", utilityCommandTable },
			{ "online",            SEC_OWNER,       false, &HandleOnlinePlayersCommand,      "", NULL },
            { NULL,                0,               false, NULL,                             "", NULL }
        };
        return commandTable;
    }

	    static bool HandleOnlinePlayersCommand(ChatHandler* handler, const char* args)
    {
		// Shows the actual online players if the fake online players script is turned on
		QueryResult select = CharacterDatabase.PQuery("SELECT COUNT(*) FROM characters WHERE online = '1';");

		if (!select) // Just in case
		{
			handler->PSendSysMessage("Something went wrong!");
			return false;
		}

		Field* fields = select->Fetch();
        uint32 onPlayers = fields[0].GetUInt32(); // counter
		handler->PSendSysMessage("Online Players: %u", onPlayers);
		return true;
    }

	    static bool HandleRemoveFakePlayersCommand(ChatHandler* handler, const char* args)
    {
		CharacterDatabase.PExecute("UPDATE characters SET online = '0' WHERE online = '2';");
		handler->PSendSysMessage("Fake players removed from the realm.");
		return true;
    }

	    static bool HandleAddFakePlayersCommand(ChatHandler* handler, const char* args)
    {
		uint8 randomizer = urand(1, 3);

		switch (randomizer)
		{
		case 1:
			CharacterDatabase.PExecute("UPDATE characters SET online = '2' WHERE guid > '31000' and guid < '31200';");
		    handler->PSendSysMessage("Fake players (31000 - 31200) inserted to the realm.");
			break;
		case 2:
			CharacterDatabase.PExecute("UPDATE characters SET online = '2' WHERE guid > '32000' and guid < '32200';");
		    handler->PSendSysMessage("Fake players (32000 - 32200) inserted to the realm.");
			break;
		case 3:
			CharacterDatabase.PExecute("UPDATE characters SET online = '2' WHERE guid > '33000' and guid < '33200';");
		    handler->PSendSysMessage("Fake players (33000 - 33200) inserted to the realm.");
			break;
		}
        return true;
    }

		static bool HandleChangeRaceCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
		handler->PSendSysMessage("Relog to change race of your character.");
        return true;
    }

		static bool HandleChangeFactionCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
		handler->PSendSysMessage("Relog to change faction of your character.");
        return true;
    }

		static bool HandleMaxSkillsCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->UpdateSkillsForLevel();
		handler->PSendSysMessage("Your weapon skills are now maximized.");
        return true;
    }

	    static bool HandleCustomizeCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
		handler->PSendSysMessage("Relog to customize your character.");
        return true;
    }

		static bool HandleMmr3v3SoloCommand(ChatHandler* handler, const char* args)
    {
		Player* pPlayer = handler->GetSession()->GetPlayer();
		QueryResult select3v3Solommr = CharacterDatabase.PQuery("SELECT matchMakerRating FROM character_arena_stats WHERE guid = '%u' AND slot = '2'", pPlayer->GetGUID());

		if (!select3v3Solommr)
		{
			handler->PSendSysMessage("Your MMR in 3vs3 Solo bracket is: 1500.");
		    return true;
		}

	    Field* fields = select3v3Solommr->Fetch(); 
		uint32 mmr3v3Solo = fields[0].GetUInt32();

		handler->PSendSysMessage("Your MMR in 3vs3 Solo bracket is: %u.", mmr3v3Solo);
		return true;
    }

		static bool HandleMmr2v2Command(ChatHandler* handler, const char* args)
    {
		Player* pPlayer = handler->GetSession()->GetPlayer();
		QueryResult select2v2mmr = CharacterDatabase.PQuery("SELECT matchMakerRating FROM character_arena_stats WHERE guid = '%u' AND slot = '0'", pPlayer->GetGUID());

		if (!select2v2mmr)
		{
			handler->PSendSysMessage("Your MMR in 2vs2 bracket is: 1500.");
		    return true;
		}

	    Field* fields = select2v2mmr->Fetch(); 
		uint32 mmr2v2 = fields[0].GetUInt32();

		handler->PSendSysMessage("Your MMR in 2vs2 bracket is: %u.", mmr2v2);
		return true;
    }

		static bool HandleMmr3v3Command(ChatHandler* handler, const char* args)
    {
		Player* pPlayer = handler->GetSession()->GetPlayer();
		QueryResult select3v3mmr = CharacterDatabase.PQuery("SELECT matchMakerRating FROM character_arena_stats WHERE guid = '%u' AND slot = '1'", pPlayer->GetGUID());

		if (!select3v3mmr)
		{
			handler->PSendSysMessage("Your MMR in 3vs3 bracket is: 1500.");
		    return true;
		}

	    Field* fields = select3v3mmr->Fetch(); 
		uint32 mmr3v3 = fields[0].GetUInt32();

		handler->PSendSysMessage("Your MMR in 3vs3 bracket is: %u.", mmr3v3);
		return true;
    }
};

void AddSC_utility_commandscript()
{
    new utility_commandscript();
}