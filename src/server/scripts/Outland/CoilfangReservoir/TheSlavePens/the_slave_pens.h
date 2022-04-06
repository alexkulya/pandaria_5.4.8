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

#ifndef THE_SLAVE_PENS_H_
#define THE_SLAVE_PENS_H_

uint32 const EncounterCount = 3;

enum eData
{
    DATA_MENNU_THE_BETRAYER = 0,
    DATA_ROKMAR             = 1,
    DATA_QUAGMIRRAN         = 2,
    MAX_DATA,
};

enum eCreatures
{
    NPC_MENNU_THE_BETRAYER    = 17941,
    NPC_ROKMAR_THE_CRACKLER   = 17991,
    NPC_QUAGMIRRAN            = 17942,
    NPC_GREATER_BOGSTROK      = 17817,
    NPC_BOGSTROK              = 17816,
    NPC_COILFANG_SLAVEHANDLER = 17959,
    NPC_WASTEWALKER_WORKER    = 17964,
    NPC_WASTEWALKER_CAPTIVE   = 18206,
    NPC_COILFANG_OBSERVER     = 17938,
    NPC_COILFANG_ENCHANTRESS  = 17961,
    NPC_COILFANG_DEFENDER     = 17958,
    NPC_COILFANG_TECHNICIAN   = 17940,
    NPC_COILFANG_COLLABORATOR = 17962,
    NPC_COILFANG_SCALE_HEALER = 21126,
    NPC_COILFANG_SOOTHSAYER   = 17960,
    NPC_COILFANG_TEMPEST      = 21127,

    /*Mennu Totems*/
    NPC_EARTHGRAB_TOTEM       = 18176,
    NPC_NOVA_TOTEM            = 18179,
    NPC_STONESKIN_TOTEM       = 18177,
    NPC_HEALING_WARD          = 20208,
};

#endif // THE_SLAVE_PENS_H_