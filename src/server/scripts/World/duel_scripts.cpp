/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "ScriptPCH.h"

class on_duel : public PlayerScript
{
    public:
        on_duel() : PlayerScript("on_duel") { }

        bool CheckZone(uint32 zone)
        {
            switch (zone)
            {
                case 12: // Elwynn Forest
                case 14: // Durotar
                case 5840: // Vale of Eternal Blossoms
                    return true;
            }

            return false;
        }

        void OnDuelStart(Player* player1, Player* player2) override
        {
            if (!CheckZone(player1->GetZoneId()))
                return;

            for (auto&& player : { player1, player2 })
            {
                player->SetHealth(player->GetMaxHealth());

                if (player->GetPowerType() == POWER_MANA)
                    player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
            }
        }

        void OnDuelEnd(Player* winner, Player* looser, DuelCompleteType type) override
        {
            if (type == DUEL_WON)
            {
                if (!CheckZone(winner->GetZoneId()))
                    return;

                for (auto&& player : { winner, looser })
                {
                    player->RemoveArenaSpellCooldowns();
                    player->RemoveAurasDueToSpell(25771);

                    player->SetHealth(player->GetMaxHealth());

                    if (player->GetPowerType() == POWER_MANA)
                        player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
                }
            }
        }
};

void AddSC_on_duel()
{
    new on_duel;
}
