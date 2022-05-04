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

enum OnKillItemRewards
{
	BADGE_OF_JUSTICE         = 29434 // Badge of Justice
};

enum CheckAurasOnKilled
{
	HONORLESS_TARGET         = 46705 // Honorless Target
};

class Arena_Scripts : public PlayerScript
{
public:
	Arena_Scripts() : PlayerScript("Arena_Scripts") {  }

	// Spawn objects for Mages and Warlocks in arena preparation
	void OnUpdateZone(Player* player, uint32 zone, uint32 area)
	{
		if (area == 3738)
		{
			if (player->IsFlying() || player->IsFalling())
			{
				player->AddAura(79404, player);
				{
					if (player->IsMounted())
					{
						player->Dismount();
						player->RemoveAurasByType(SPELL_AURA_MOUNTED);
					}
				}
			}
		}

		float x = player->GetPositionX();
		float y = player->GetPositionY();
		float z = player->GetPositionZ();
		float ang = player->GetOrientation();
		float rot2 = std::sin(ang/2);
		float rot3 = std::cos(ang/2);

		switch (player->getClass())
		{
		case CLASS_MAGE:
			{
				if (Battleground *bg = player->GetBattleground())
					if (bg->isArena() && player->HasAura(SPELL_ARENA_PREPARATION))
						player->SummonGameObject(193061, x+2, y+2, z, ang, 0, 0, rot2, rot3, 30);
			}
			break;

		case CLASS_WARLOCK:
			{
				if (Battleground *bg = player->GetBattleground())
					if (bg->isArena() && player->HasAura(SPELL_ARENA_PREPARATION))
						player->SummonGameObject(193169, x-2, y-2, z, ang, 0, 0, rot2, rot3, 30);
			}
			break;
		}
	}

	// Reward players tokens 
	void OnPVPKill(Player* pKiller, Player* pKilled)
	{
		// do not run the script for self
		if (pKiller == pKilled)
			return;

		// Not available only for GMs
		if (pKiller->GetSession()->GetSecurity() >= 2 || pKiller->GetSession()->GetSecurity() >= 2)
			return;

		// Preventing farming attempts from same IPs
		if (pKiller->GetSession()->GetRemoteAddress() == pKilled->GetSession()->GetRemoteAddress())
			return;

		// Don't reward BoJ if player is in arena or is with HT aura present
		if (pKiller->InArena() || pKilled->InArena() || pKilled->HasAura(HONORLESS_TARGET))
			return;

		// Reward BoJ only in Battlegrounds
		if (pKiller->InBattleground() && pKilled->InBattleground())
			pKiller->AddItem(BADGE_OF_JUSTICE, 1);
	}
};

void AddSC_Arena_Scripts()
{
	new Arena_Scripts;
}