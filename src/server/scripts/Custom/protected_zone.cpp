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

enum ForbiddenAreas
{
    // AREA_TIMELESS_ISLE                          = 6757, // Timeless Isle
    // AREA_ISLE_OF_GIANT                          = 6661, // IsleofGiants
    // AREA_ISLE_OF_THUNDER                        = 6507  // IsleofThunder
};

class protected_zone : public PlayerScript
{
public:
    protected_zone() : PlayerScript("protected_zone") { }

    void OnUpdateZone(Player* player, uint32 newZone, uint32 newArea)
    {
        switch (newZone)
        {
            // case AREA_TIMELESS_ISLE:
            // case AREA_ISLE_OF_GIANT:
            // case AREA_ISLE_OF_THUNDER:
                // if (player->GetSession()->GetSecurity() >= 1)
                    // return;
                // player->TeleportTo(0, 278.867340f, 348.756195f, 141.279770f, 4.510715f); // teleport to dalaran crater
                // break;
        }
    }
};

void AddSC_protected_zone()
{
    new protected_zone();
}
