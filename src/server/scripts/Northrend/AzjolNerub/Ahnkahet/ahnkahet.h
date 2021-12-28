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

#ifndef DEF_AHNKAHET_H
#define DEF_AHNKAHET_H

enum Data64
{
    DATA_ELDER_NADOX,
    DATA_PRINCE_TALDARAM,
    DATA_JEDOGA_SHADOWSEEKER,
    DATA_HERALD_VOLAZJ,
    DATA_AMANITAR,
    DATA_SPHERE1,
    DATA_SPHERE2,
    DATA_PRINCE_TALDARAM_PLATFORM,
    DATA_PL_JEDOGA_TARGET,
    DATA_ADD_JEDOGA_OPFER,
    DATA_ADD_JEDOGA_INITIAND
};

enum Data
{
    DATA_ELDER_NADOX_EVENT,
    DATA_PRINCE_TALDARAM_EVENT,
    DATA_JEDOGA_SHADOWSEEKER_EVENT,
    DATA_HERALD_VOLAZJ_EVENT,
    DATA_AMANITAR_EVENT,
    DATA_SPHERE1_EVENT,
    DATA_SPHERE2_EVENT,
    DATA_JEDOGA_TRIGGER_SWITCH,
    DATA_JEDOGA_RESET_INITIANDS,
    DATA_ALL_INITIAND_DEAD
};

enum Creatures
{
    NPC_ELDER_NADOX             = 29309,
    NPC_PRINCE_TALDARAM         = 29308,
    NPC_JEDOGA_SHADOWSEEKER     = 29310,
    NPC_HERALD_VOLAZJ           = 29311,
    NPC_AMANITAR                = 30258,
    NPC_TWILIGHT_INITIATE       = 30114,

    NPC_SEER_IXIT               = 55658,
    NPC_AZJOL_ANAK_SORCERER     = 55661,
    NPC_AZJOL_ANAK_WARRIROR     = 55566,
};

enum GameObjects
{
    GO_PRINCE_TALDARAM_PLATFORM = 193564,
    GO_PRINCE_TALDARAM_SPHERE_1 = 193093,
    GO_PRINCE_TALDARAM_SPHERE_2 = 193094,
    GO_PRINCE_TALDARAM_GATE     = 192236,
};

#endif
