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

#ifndef DEF_TOC_H
#define DEF_TOC_H

enum Data
{
    BOSS_GRAND_CHAMPIONS,
    BOSS_ARGENT_CHALLENGE_E,
    BOSS_ARGENT_CHALLENGE_P,
    BOSS_BLACK_KNIGHT,
    DATA_MOVEMENT_DONE,
    DATA_LESSER_CHAMPIONS_DEFEATED,
    DATA_GRAND_CHAMPIONS_DEFEATED,
    DATA_START,
    DATA_IN_POSITION,
    DATA_ARGENT_SOLDIER_DEFEATED,
    DATA_GRAND_CHAMPION_ENTRY,
    DATA_MEMORY_ENTRY,
    DATA_TEAM_IN_INSTANCE
};

enum Data64
{
    DATA_ANNOUNCER,
    DATA_MAIN_GATE,
    DATA_PORTCULLIS,

    DATA_GRAND_CHAMPION_1,
    DATA_GRAND_CHAMPION_2,
    DATA_GRAND_CHAMPION_3,

    DATA_BLACK_KNIGHT,
    DATA_KNIGHT
};

enum Npcs
{
    // Horde Champions
    NPC_MOKRA                   = 35572,
    NPC_ERESSEA                 = 35569,
    NPC_RUNOK                   = 35571,
    NPC_ZULTORE                 = 35570,
    NPC_VISCERI                 = 35617,

    // Alliance Champions
    NPC_JACOB                   = 34705,
    NPC_AMBROSE                 = 34702,
    NPC_COLOSOS                 = 34701,
    NPC_JAELYNE                 = 34657,
    NPC_LANA                    = 34703,

    // Faction champions horde
    NPC_ORGRIMMAR_CHAMPION      = 35314,
    NPC_SILVERMOON_CHAMPION     = 35326,
    NPC_THUNDER_CHAMPION        = 35325,
    NPC_TROLL_CHAMPION          = 35323,
    NPC_UNDERCITY_CHAMPION      = 35327,

    // Faction champions alliance
    NPC_STORMWIND_CHAMPION      = 35328,
    NPC_GNOMEREGAN_CHAMPION     = 35331,
    NPC_EXODAR_CHAMPION         = 35330,
    NPC_DARNASSUS_CHAMPION      = 35332,
    NPC_IRONFORGE_CHAMPION      = 35329,

    NPC_EADRIC                  = 35119,
    NPC_PALETRESS               = 34928,

    NPC_ARGENT_LIGHWIELDER      = 35309,
    NPC_ARGENT_MONK             = 35305,
    NPC_PRIESTESS               = 35307,

    NPC_BLACK_KNIGHT            = 35451,

    NPC_RISEN_JAEREN            = 35545,
    NPC_RISEN_ARELAS            = 35564,

    // Announcer Start Event
    NPC_JAEREN                  = 35004,
    NPC_ARELAS                  = 35005,

    // Announcer
    NPC_JAEREN_AN               = 35591,
    NPC_ARELAS_AN               = 35592,

    NPC_MEMORY_HOGGER           = 34942,
    NPC_MEMORY_VANCLEEF         = 35028,
    NPC_MEMORY_MUTANUS          = 35029,
    NPC_MEMORY_HEROD            = 35030,
    NPC_MEMORY_LUCIFROM         = 35031,
    NPC_MEMORY_THUNDERAAN       = 35032,
    NPC_MEMORY_CHROMAGGUS       = 35033,
    NPC_MEMORY_HAKKAR           = 35034,
    NPC_MEMORY_VEKNILASH        = 35036,
    NPC_MEMORY_KALITHRESH       = 35037,
    NPC_MEMORY_MALCHEZAAR       = 35038,
    NPC_MEMORY_GRUUL            = 35039,
    NPC_MEMORY_VASHJ            = 35040,
    NPC_MEMORY_ARCHIMONDE       = 35041,
    NPC_MEMORY_ILLIDAN          = 35042,
    NPC_MEMORY_DELRISSA         = 35043,
    NPC_MEMORY_MURU             = 35044,
    NPC_MEMORY_INGVAR           = 35045,
    NPC_MEMORY_CYANIGOSA        = 35046,
    NPC_MEMORY_ECK              = 35047,
    NPC_MEMORY_ONYXIA           = 35048,
    NPC_MEMORY_HEIGAN           = 35049,
    NPC_MEMORY_IGNIS            = 35050,
    NPC_MEMORY_VEZAX            = 35051,
    NPC_MEMORY_ALGALON          = 35052
};

enum AchievementCriteria
{
    CRITERIA_CHAMPION_JACOB     = 11420,
    CRITERIA_CHAMPION_LANA      = 12298,
    CRITERIA_CHAMPION_COLOSOS   = 12299,
    CRITERIA_CHAMPION_AMBROSE   = 12300,
    CRITERIA_CHAMPION_JAELYNE   = 12301,

    CRITERIA_CHAMPION_MOKRA     = 12302,
    CRITERIA_CHAMPION_VISCERI   = 12303,
    CRITERIA_CHAMPION_RUNOK     = 12304,
    CRITERIA_CHAMPION_ERESSEA   = 12305,
    CRITERIA_CHAMPION_ZULTORE   = 12306,

    CRITERIA_CHAMPION_JACOB_H   = 12310,
    CRITERIA_CHAMPION_LANA_H    = 12311,
    CRITERIA_CHAMPION_COLOSOS_H = 12312,
    CRITERIA_CHAMPION_AMBROSE_H = 12313,
    CRITERIA_CHAMPION_JAELYNE_H = 12314,

    CRITERIA_CHAMPION_MOKRA_H   = 12318,
    CRITERIA_CHAMPION_VISCERI_H = 12319,
    CRITERIA_CHAMPION_RUNOK_H   = 12320,
    CRITERIA_CHAMPION_ERESSEA_H = 12321,
    CRITERIA_CHAMPION_ZULTORE_H = 12322,

    CRITERIA_MEMORY_HOGGER      = 11863,
    CRITERIA_MEMORY_VANCLEEF    = 11904,
    CRITERIA_MEMORY_MUTANUS     = 11905,
    CRITERIA_MEMORY_HEROD       = 11906,
    CRITERIA_MEMORY_LUCIFROM    = 11907,
    CRITERIA_MEMORY_THUNDERAAN  = 11908,
    CRITERIA_MEMORY_CHROMAGGUS  = 11909,
    CRITERIA_MEMORY_HAKKAR      = 11910,
    CRITERIA_MEMORY_VEKNILASH   = 11911,
    CRITERIA_MEMORY_KALITHRESH  = 11912,
    CRITERIA_MEMORY_MALCHEZAAR  = 11913,
    CRITERIA_MEMORY_GRUUL       = 11914,
    CRITERIA_MEMORY_VASHJ       = 11915,
    CRITERIA_MEMORY_ARCHIMONDE  = 11916,
    CRITERIA_MEMORY_ILLIDAN     = 11917,
    CRITERIA_MEMORY_DELRISSA    = 11918,
    CRITERIA_MEMORY_MURU        = 11919,
    CRITERIA_MEMORY_INGVAR      = 11920,
    CRITERIA_MEMORY_CYANIGOSA   = 11921,
    CRITERIA_MEMORY_ECK         = 11922,
    CRITERIA_MEMORY_ONYXIA      = 11923,
    CRITERIA_MEMORY_HEIGAN      = 11924,
    CRITERIA_MEMORY_IGNIS       = 11925,
    CRITERIA_MEMORY_VEZAX       = 11926,
    CRITERIA_MEMORY_ALGALON     = 11927,

    SPELL_GRAND_CHAMPION_CREDIT = 68572,
    SPELL_ARGENT_CREDIT         = 68573,
    SPELL_BLACK_KNIGHT_CREDIT   = 68663
};

enum GameObjects
{
    GO_MAIN_GATE                = 195647,
    GO_NORTH_PORTCULLIS         = 195650,

    GO_CHAMPIONS_LOOT           = 195709,
    GO_CHAMPIONS_LOOT_H         = 195710,

    GO_EADRIC_LOOT              = 195374,
    GO_EADRIC_LOOT_H            = 195375,

    GO_PALETRESS_LOOT           = 195323,
    GO_PALETRESS_LOOT_H         = 195324
};

enum Vehicles
{
    VEHICLE_ARGENT_WARHORSE     = 35644,
    VEHICLE_ARGENT_BATTLEWORG   = 36558,
    VEHICLE_BLACK_KNIGHT        = 35491,
    VEHICLE_GR                  = 35492
};

enum Worldstates
{
    WORLDSTATE_BOLTSPARK      = 7387,
    WORLDSTATE_COLOSOS        = 7386,
    WORLDSTATE_JACOB_ALERIUS  = 7384,
    WORLDSTATE_STOUTHAMMER    = 7385,
    WORLDSTATE_EVERSONG       = 7388,
    WORLDSTATE_CHROMAGGUS     = 7313,
    WORLDSTATE_ALGALON        = 7331,
    WORLDSTATE_GRUUL          = 7318,
    WORLDSTATE_THUNDERAAN     = 7312,
    WORLDSTATE_MURU           = 7323,
    WORLDSTATE_ONYXIA         = 7327,
    WORLDSTATE_MUTANUS        = 7309,
    WORLDSTATE_VANCLEEF       = 7308,
    WORLDSTATE_INGVAR         = 7324,
    WORLDSTATE_VEZAX          = 7330,
    WORLDSTATE_KALITHRASH     = 7316,
    WORLDSTATE_ECK            = 7326,
    WORLDSTATE_ILLIDAN        = 7321,
    WORLDSTATE_LUCIFRON       = 7311,
    WORLDSTATE_HAKKAR         = 7314,
    WORLDSTATE_VEKNILASH      = 7315,
    WORLDSTATE_MALCHEEZAR     = 7317,
    WORLDSTATE_ARCHIMONDE     = 7320,
    WORLDSTATE_DELRISSA       = 7322,
    WORLDSTATE_CYANIGOSA      = 7325,
    WORLDSTATE_HEIGAN         = 7328,
    WORLDSTATE_IGNIS          = 7329,
    WORLDSTATE_HOGGER         = 7307,
    WORLDSTATE_HEROD          = 7310,
    WORLDSTATE_VASHJ          = 7319,
    WORLDSTATE_I_VE_HAD_WORSE = 7291,
};

static void BindPlayersToInstance(Creature* creature)
{
    Map* map = creature->GetMap();

    if (map && map->IsDungeon() && map->IsRaidOrHeroicDungeon())
    {
        Map::PlayerList const& list = map->GetPlayers();
        if (!list.isEmpty() && list.begin()->GetSource())
            ((InstanceMap*)map)->PermBindAllPlayers(list.begin()->GetSource());
    }
};

#endif
