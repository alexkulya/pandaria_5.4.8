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

#ifndef DIRE_MAUL_H_
#define DIRE_MAUL_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

const Position ironbarkPath[4]
{
    { -42.31f, -267.44f, -57.32f, 6.05f },
    {   7.69f, -288.92f, -52.41f, 5.89f },
    {  63.08f, -269.52f, -53.95f, 0.33f },
    { 127.53f, -278.66f, -55.88f, 6.16f },
};

enum eCreatures
{
    NPC_OLD_IRONBARK = 11491,
};

enum eGameObjects
{
    GO_CONSERVATORY_DOOR = 176907,
};

#endif // DIRE_MAUL_H_