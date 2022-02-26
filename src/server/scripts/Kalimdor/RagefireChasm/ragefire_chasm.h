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

#ifndef RAGEFIRE_CHASM_N
#define RAGEFIRE_CHASM_N

const Position SlagMawPoints[3]
{
    { -256.643f, 172.957f, -16.253f, 5.383f },
    { -261.183f, 137.642f, -12.348f, 0.574f },
    { -225.866f, 164.639f, -15.437f, 3.885f }
};

enum eBosses
{
    BOSS_ADAROGG,
    BOSS_DARK_SHAMAN_CORANTHAL,
    BOSS_SLAGMAW,
    BOSS_GORDOTH,
    TOTAL_ENCOUNTERS,
};

enum eCreatures
{
    NPC_ADAROGG = 61408,
    NPC_DARK_SHAMAN_CORANTHAL = 61412,
    NPC_SLAGMAW = 61463,
    NPC_GORDOTH = 61528,
};

enum eTalks
{
    TALK_ANN = 1,
};

enum eType
{
    TYPE_TARGET_ID = 1,
};

#endif // RAGEFIRE_CHASM_N