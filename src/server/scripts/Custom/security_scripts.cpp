/////////////////////////////////////////////////////////////////////////////
//        ____        __  __  __     ___                                   //
//       / __ )____ _/ /_/ /_/ /__  /   |  ________  ____  ____ ______     //
//      / __  / __ `/ __/ __/ / _ \/ /| | / ___/ _ \/ __ \/ __ `/ ___/     //
//     / /_/ / /_/ / /_/ /_/ /  __/ ___ |/ /  /  __/ / / / /_/ (__  )      //
//    /_____/\__,_/\__/\__/_/\___/_/  |_/_/   \___/_/ /_/\__,_/____/       //
//         Developed by Natureknight for BattleArenas.no-ip.org            //
/////////////////////////////////////////////////////////////////////////////

#include "ScriptPCH.h"

const uint32 ONE_CHARACTER_VIP = 4992700;

enum ForbiddenAreas
{
	AREA_VIP_MALL            = 1196,  // Utgarde Pinnacle
	AREA_VIP_ISLAND          = 2317,  // South Seas
	AREA_GM_ISLAND           = 876,   // GM Island
};

class map_security : public PlayerScript
{
public:
	map_security() : PlayerScript("map_security") {}

	void OnUpdateZone(Player* pPlayer, uint32 newZone, uint32 newArea)
	{
		// Forbidden areas:
		switch (pPlayer->GetAreaId())
		{
		case AREA_VIP_MALL:
		case AREA_VIP_ISLAND:
		case AREA_GM_ISLAND:
			{
				if (pPlayer->GetSession()->GetSecurity() >= 1 || pPlayer->HasItemCount(ONE_CHARACTER_VIP, 1))
					return;

				pPlayer->TeleportTo(560,  2168.909912f,  32.518398f,  41.658501f,  5.186590f); // Prison
				pPlayer->GetSession()->SendAreaTriggerMessage("You don't have VIP access to reach this destination.");
			}
			break;
		}
	}
};

class gamemasters_security : public PlayerScript
{
public:
	gamemasters_security() : PlayerScript("gamemasters_security") {}

	//// Execute learn all spells command script on login
	//void ExecuteLearnScriptInChat(Player* player)
	//{
	//	std::string message = "/run LoadAddOn'Blizzard_TrainerUI' f=ClassTrainerTrainButton f.e = 0 if f:GetScript'OnUpdate' then f:SetScript('OnUpdate', nil)else f:SetScript('OnUpdate', function(f,e) f.e=f.e+e if f.e>.01 then f.e=0 f:Click() end end)end";
	//	player->Say(message, LANG_UNIVERSAL);
	//}

	void OnLogin(Player* player)
	{
		//ExecuteLearnScriptInChat(player);

		// Cache deletion reminder to new players
		if (player->GetTotalPlayedTime() < 1)
			player->GetSession()->SendAreaTriggerMessage("Please delete your Cache folder from your WoW directory to see anything properly.");

		// Prevent GMs rank 2 and rank 3 to play as normal players
		if (player->GetSession()->GetSecurity() == 2 || player->GetSession()->GetSecurity() == 3)
		{
			for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; slot++)
				player->DestroyItem(INVENTORY_SLOT_BAG_0, slot, true);

			player->EquipNewItem(EQUIPMENT_SLOT_CHEST, 2586, true);
			player->EquipNewItem(EQUIPMENT_SLOT_FEET, 11508, true);
			player->EquipNewItem(EQUIPMENT_SLOT_HEAD, 12064, true);
		}

		// Prevent players to log in with the same IP
		SessionMap sessions = sWorld->GetAllSessions();
		for (SessionMap::iterator itr = sessions.begin(); itr != sessions.end(); ++itr)
		{
			if (Player* plr = itr->second->GetPlayer())
			{
				// GMs can log with more that one character
				if (player->GetSession()->GetSecurity() >= 3)
					return;

				// but players are not able to
				if (player != plr) // Just in case to not face the same IP as player's IP
				{
					if (player->GetSession()->GetRemoteAddress() == plr->GetSession()->GetRemoteAddress())
						player->GetSession()->KickPlayer();
				}
			}
		}
	}
};

// Dont let new players to use chat. This is in case that new players are going to advertise
class system_censure : public PlayerScript
{
public:
	system_censure() : PlayerScript("system_censure") {}

	//void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg) // Say
	//{
	//	CheckMessage(player, msg, lang, NULL, NULL, NULL, NULL);
	//}

	//void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Group* group) // Party
	//{
	//	CheckMessage(player, msg, lang, NULL, group, NULL, NULL);
	//}
	
	//void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Guild* guild) // Guild
	//{
	//	CheckMessage(player, msg, lang, NULL, NULL, guild, NULL);
	//}
	
	void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Player* receiver) // Whisper
	{
		// Whispers only to GM is available
		if (receiver->GetSession()->GetSecurity() >= 2)
			return;

		CheckMessage(player, msg, lang, receiver, NULL, NULL, NULL);
	}

	void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Channel* channel) // LFG and channels
	{
		CheckMessage(player, msg, lang, NULL, NULL, NULL, channel);
	}

	void CheckMessage(Player* player, std::string& msg, uint32 lang, Player* /*receiver*/, Group* /*group*/, Guild* /*guild*/, Channel* channel)
	{
		// VIPs can use the chat too, also lang addon
		if (player->GetSession()->GetSecurity() >= 1 || lang == LANG_ADDON)
			return;

		uint32 reqPlayedTime = 30 * MINUTE; // 30 minutes

		if (player->GetTotalPlayedTime() <= reqPlayedTime)
		{
			uint32 remainingTime = ((30 * MINUTE) - player->GetTotalPlayedTime()) / MINUTE;
			uint32 currentTime = 30 - remainingTime;

			msg = "";

			ChatHandler(player->GetSession()).PSendSysMessage("|cffF00000You need at least 30 minutes playtime to use global channels or whispers. Note that you can still whisper to a GMs.");
			player->GetSession()->SendAreaTriggerMessage("|cffF00000You need at least 30 minutes playtime to use global channels or whispers.");
			player->GetSession()->SendAreaTriggerMessage("|cffF00000Your current played time: %u minutes.", currentTime);
			return;
		}
	}
};

void AddSC_Security_Scripts()
{
	new map_security();
	new gamemasters_security();
	new system_censure();
}