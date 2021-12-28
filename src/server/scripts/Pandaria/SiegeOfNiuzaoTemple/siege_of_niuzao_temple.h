#ifndef SIEGE_OF_NIUZAO_H
#define SIEGE_OF_NIUZAO_H

const Position AmberWingSpawnPos = { 1639.88f, 5402.80f, 171.47f, 3.08f };
const Position PATH_AMBERWING[3] =
{
    { 1518.50f, 5418.21f, 195.18f, 3.26f },
    { 1528.25f, 5317.22f, 189.86f, 4.82f }, // Bombard pos
    { 1615.87f, 5261.91f, 218.84f, 5.80f }  // port from there to home pos
};

enum Bosses
{
    BOSS_JINBAK,
    BOSS_VOJAK,
    BOSS_PAVALAK,
    BOSS_NERONOK,
    TOTAL_ENCOUNTERS,

    DATA_VOJAK_DOOR
};

enum Creatures
{
    /* BOSSES */
    NPC_JINBAK          = 61567,
    NPC_VOJAK           = 61634,
    NPC_PAVALAK         = 61485,
    NPC_NERONOK         = 62205,

    /* TRASH */
    NPC_MANTID_CATAPULT = 63565,
    NPC_SAP_PUDDLE_2    = 61965,
};

enum GameObjects
{
    GO_HARDENED_RESIN       = 213174, // after jinbak
    GO_DOOR                 = 212921, // after vojak

    GO_TEMPLE_INVIS_DOOR    = 213251, // before neronok bridge
    GO_WIND_WALL            = 214548, // before neronok bridge
    GO_FIRE_WALL            = 210097, // door vojak
    GO_CHALLENGE_DOOR       = 211989,
};

enum WMOAreaEntries
{
    WMO_REAR_STAGING_AREA       = 59479
};

enum Worldstates
{
    WORLDSTATE_WHERE_IS_MY_AIR_SUPPORT = 11982,
};

enum InstanceScenarioData
{
    SCENARIO_ID      = 49,
    // Bosses datas
    CRITERIA_JINBAK  = 19249,
    CRITERIA_VOJAK   = 19250,
    CRITERIA_PAVALAK = 19251,
    CRITERIA_NERONOK = 19252,
    CRITERIA_ENEMIES = 20023,
    ENEMIES_COUNT    = 65,
};

#endif