/*
 * Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2006-2014 ScriptDev2 <https://github.com/scriptdev2/scriptdev2/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"

class at_daryl_riknussun : public AreaTriggerScript
{
    public:
        at_daryl_riknussun() : AreaTriggerScript("at_daryl_riknussun") { }
    
        bool OnTrigger(Player* player, const AreaTriggerEntry* /*trigger*/) override
        {
            if (player->HasAura(99491))
            {
                if (Creature* daryl_riknussun = player->FindNearestCreature(5159, 10.0f))
                {
                    daryl_riknussun->AI()->Talk(0, player);
                    daryl_riknussun->CastSpell(player, 99493);
                    player->KilledMonsterCredit(53574);
                    return true;
                }
            }
            return false;
        }
};

void AddSC_ironforge()
{
    new at_daryl_riknussun();
}
