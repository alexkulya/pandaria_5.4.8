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

#ifndef DEF_GUNDRAK_H
#define DEF_GUNDRAK_H

enum Data
{
    DATA_SLAD_RAN_EVENT,
    DATA_MOORABI_EVENT,
    DATA_DRAKKARI_COLOSSUS_EVENT,
    DATA_GAL_DARAH_EVENT,
    DATA_ECK_THE_FEROCIOUS_EVENT,
    DATA_ALIVE_RUIN_DWELLERS
};

enum Data64
{
    DATA_SLAD_RAN_ALTAR,
    DATA_MOORABI_ALTAR,
    DATA_DRAKKARI_COLOSSUS_ALTAR,
    DATA_SLAD_RAN_STATUE,
    DATA_MOORABI_STATUE,
    DATA_DRAKKARI_COLOSSUS_STATUE,
    DATA_DRAKKARI_COLOSSUS,
    DATA_RUIN_DWELLER_DIED
};

enum mainCreatures
{
    NPC_RUIN_DWELLER                              = 29920,
    NPC_SLAD_RAN                                  = 29304,
    NPC_MOORABI                                   = 29305,
    NPC_GALDARAH                                  = 29306,
    NPC_DRAKKARICOLOSSUS                          = 29307,
    NPC_ECK                                       = 29932,
    NPC_LIVING_MOJO                               = 29830,
    NPC_DRAKKARI_ELEMENTAL                        = 29573,
    NPC_DRAKKARI_LANCER                           = 29819,
    NPC_DRAKKARI_GOD_HUNTER                       = 29820,
    NPC_DRAKKARI_FIRE_WEAVER                      = 29822,
    NPC_DRAKKARI_MEDICINE_MAN                     = 29826,
    NPC_DRAKKARI_EARTHSHAKER                      = 29829,
    NPC_DRAKKARI_RHINO                            = 29838,
    NPC_DRAKKARI_RHINO_2                          = 29931,
};

enum GameObjects
{
    GO_ALTAR_OF_SLADRAN                           = 192518,
    GO_ALTAR_OF_MOORABI                           = 192519,
    GO_ALTAR_OF_DRAKKARI_COLOSSUS                 = 192520,
    GO_SLADRAN_STATUE                             = 192564,
    GO_MOORABI_STATUE                             = 192565,
    GO_GALDARAH_STATUE                            = 192566,
    GO_DRAKKARI_COLOSSUS_STATUE                   = 192567,
    GO_ECK_DOOR                                   = 192632,
    GO_ECK_DOOR_BEHIND                            = 192569,
    GO_GALDARAH_DOOR                              = 192568,
    GO_GALDARAH_DOOR_1                            = 193208,
    GO_GALDARAH_DOOR_2                            = 193209,
    GO_BRIDGE                                     = 193188,
    GO_COLLISION                                  = 192633,
};

enum Worldstates
{
    WORLDSTATE_LESS_RABI      = 8794,
    WORLDSTATE_SHARE_THE_LOVE = 6423,
};

#endif
