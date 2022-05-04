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

class Reset_OnDuelEnd : public PlayerScript
{
public:
	Reset_OnDuelEnd() : PlayerScript("Reset_OnDuelEnd") {}

	// Call the script after the 3s countdown
	void OnDuelStart(Player * player, Player * plTarget)
	{
		// Clear both players cooldowns
		player->RemoveAllSpellCooldown();
		plTarget->RemoveAllSpellCooldown();
		player->RemoveAura(10278);             // Hand of Protection
		plTarget->RemoveAura(10278);
		player->RemoveAura(498);               // Divine Protection
		plTarget->RemoveAura(498);
		player->RemoveAura(642);               // Divine Shield
		plTarget->RemoveAura(642);
		player->RemoveAura(41425);             // Remove Hypothermia Debuff
		plTarget->RemoveAura(41425);
		player->RemoveAura(25771);             // Remove Forbearance Debuff
		plTarget->RemoveAura(25771);
		player->RemoveAura(57724);             // Remove Sated Debuff
		plTarget->RemoveAura(57724);
		player->RemoveAura(57723);             // Remove Exhaustion Debuff
		plTarget->RemoveAura(57723);
		player->RemoveAura(66233);             // Remove Ardent Defender Debuff
		plTarget->RemoveAura(66233);
		player->RemoveAura(61987);             // Avenging Wrath Marker
		plTarget->RemoveAura(61987);
		player->RemoveAura(11196);             // Remove Recently Bandaged Debuff
		plTarget->RemoveAura(11196);
		player->SetHealth(player->GetMaxHealth());
		player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
		plTarget->SetHealth(plTarget->GetMaxHealth());
		plTarget->SetPower(POWER_MANA,  plTarget->GetMaxPower(POWER_MANA));
		player->SetPower(POWER_RAGE, 0);       // Remove Rage and Runic Power
		plTarget->SetPower(POWER_RAGE, 0);
		player->SetPower(POWER_RUNIC_POWER, 0);
		plTarget->SetPower(POWER_RUNIC_POWER, 0);
		//player->CastSpell(player, 46705, true);     // Honorless Target
		//plTarget->CastSpell(plTarget, 46705, true); // Honorless Target
	}

	void OnDuelEnd(Player * pWinner, Player * pLooser, DuelCompleteType type)
	{   
		// Scrubs are not allowed to spam the announcer
		if (type != DUEL_WON)
			return;

		pWinner->SetHealth(pWinner->GetMaxHealth());
		pWinner->SetPower(POWER_MANA, pWinner->GetMaxPower(POWER_MANA));
		pLooser->SetHealth(pLooser->GetMaxHealth());
		pLooser->SetPower(POWER_MANA, pLooser->GetMaxPower(POWER_MANA));
		sWorld->SendWorldText(12006, pWinner->GetName(), pLooser->GetName());
		//
		//// Scrubs are not allowed to farm players with low hp
		//if (pLooser->GetHealth() <= 22500) // Low HP
		//{
		//	sLog->outError("Player %s is trying to wintrade duels against %s who is naked! CHECK!", pWinner->GetName(), pLooser->GetName());
		//	ChatHandler(pWinner).PSendSysMessage("You have been reported to the staff for this farm attempt!");
		//	return;
		//}
		//
		//if (pWinner->GetSession()->GetRemoteAddress() == pLooser->GetSession()->GetRemoteAddress())
		//{
		//	if (pWinner->GetSession()->GetSecurity() >= 2 || pLooser->GetSession()->GetSecurity() >= 2)
		//	{
		//		ChatHandler(pLooser).PSendSysMessage("You just lose against your alternative player. This is farm attempt but you won't be kicked because you're a GM.");
		//		ChatHandler(pWinner).PSendSysMessage("You just won against your alternative player. This is farm attempt but you won't be kicked because you're a GM.");
		//		return;
		//	}
		//	sWorld->SendWorldText(12007, pWinner->GetName(), pLooser->GetName());
		//	sLog->outError("Player %s is trying to wintrade duels against his alternative player %s.", pWinner->GetName(), pLooser->GetName());
		//	pWinner->GetSession()->KickPlayer();
		//	return;
		//}
		//
		// Custom Duel System
		//ChatHandler(pLooser).PSendSysMessage("%s received Badge of Justice from this duel.", pWinner->GetName());
		//ChatHandler(pWinner).PSendSysMessage("You received Badge of Justice from this duel.");
		//pWinner->AddItem(29434, 1); // Add Badge of Justice
	}
};

void AddSC_Reset()
{
	new Reset_OnDuelEnd;
}