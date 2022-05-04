////////////////////////////////////////////////////////////////////////
//      ___                         ___       __  __  __              //
//     / _ | _______ ___  ___ _____/ _ )___ _/ /_/ /_/ /__ ___        //
//    / __ |/ __/ -_) _ \/ _ `/___/ _  / _ `/ __/ __/ / -_|_-<        //
//   /_/ |_/_/  \__/_//_/\_,_/   /____/\_,_/\__/\__/_/\__/___/.com    //
//                                                                    //
//         Developed by Natureknight Patrick and Scott.               //
//                                                                    //
////////////////////////////////////////////////////////////////////////

#include "ScriptPCH.h"

// Teleport data

struct Eric
{
	uint32 menu_id, next_menu_id;
	uint8 icon;
	std::string name;
	uint32 cost;
	uint8 level, faction; // 0 Both, 1 Horde, 2 Ally
	uint32 map;
	float x, y, z, o;
};
typedef struct Eric Rochet2;

//	{menu_id, next_menu_id, icon, name, cost, level, faction, map, x, y, z, o}
Rochet2 TeLe [] = // key = i & Key
{
	//========================================Teleporter Locations:====================================================//
	{1,	0,	4,	"Darnassus - Mall",	0,	0,	2,	1,	9949.658203f,	 2374.083252f,	 1330.001345f,	  4.731387f},
	{1,	0,	4,	"Stormwind - Mall",	0,	0,	2,	0,	-8850.778320f,	 649.876648f,	96.325790f,	  5.354052f},
	{1,	0,	4,	"Ironforge - Mall",	0,	0,	2,	0,	-4935.559570f,	 -937.766174f,	 502.960754f,	  5.400695f},
	{1,	0,	4,	"Desolace - Mall",	        0,	0,	2,	1,	170.343735f,	 1206.189819f,	 166.235794f,	  2.639121f},
	{1,	0,	4,	"Silvermoon - Mall",	0,	0,	1,	530,	9490.633789f,	-7277.810059f,	 14.296535f,   5.896964f},
	{1,	0,	4,	"Orgrimmar - Mall",	0,	0,	1,	1,	1501.500000f,	-4415.439941f,	 22.078300f,   0.104575f},
	{1,	0,	4,	"Thunder Bluff - Mall",	0,	0,	1,	1,	-1208.136597f,	-96.185158f,	 162.373642f,   1.586078f},
	{1,	0,	4,	"Undercity - Mall",	0,	0,	1,	0,	1805.549927f,	280.896027f,	 70.399773f,   4.657905f},
	{1,	0,	4,	"Jaguero Isle - PVP Zone",	0,	0,	2,	0,	-14686.293945f,	 -159.953079f,	 8.765150f,	  3.606193f},
	{1,	0,	4,	"Jaguero Isle - PVP Zone",	0,	0,	1,	0,	-14557.030273f,	  -397.481293f,	   6.148164f,   1.917565f},
	{1,	0,	4,	"Dueling Zone",	 0,	 0,	 0,	 1,	 6566.661133f,	 -4047.084473f,	  658.646118f,   2.083416f},
	//{1,	0,	4,	"Stranglethorn Vale",	0,	0,	0,	0,	-13265.961914f,	  156.842224f,	  35.670128f,	 4.207355f},
	//{1,	0,	4,	"Dueling Zone",	0,	0,	0,	0,	-4262.941895f,	  -3357.522461f,	  230.574600f,	 6.048925f},
	{1,	0,	4,	"Transmogrify Place",	0,	0,	0,	571,	5773.749512f,	  641.840881f,	  562.136536f,	 4.794876f},
	{1,	0,	4,	"Professions Place",	0,	0,	0,	571,	5831.356445f,	  -3099.036133f,	  300.452850f,	 5.150246f},
	/*{1,	0,	2,	"Shattrath Mall",	0,	0,	0,	530,	-1900.645386f,	 5413.789063f,	-12.427900f,	0.412779f},*/
	/*{1,	0,	2,	"Dueling Zone - Quel'thalas",	 0,	 0,	 0,	 0,	 4296.476563f,	 -2763.762695f,	  16.313412f,   3.673983f},*/
	/*{1,	0,	2,	"Dueling Zone - Raven's Wood",	 0,	 0,	 0,	 530,	3197.549316f,	7113.105469f,	 175.654465f,   0.268489f},*/
	/*{1,	0,	2,	"Dueling Zone - Azuremyst isle",	 0,	 0,	 0,	 530,	-3610.331299f,	  -12499.073242f,	 9.533518f,    1.966641f},*/
	/*{1,	0,	2,	"Dueling Zone - Mulgore",	 0,	 0,	 0,	 1,	-1605.296875f,	  145.156677f,	 -0.628560f,    0.358055f},*/
	{1,	0,	4,	"Custom Jump Event",	0,	0,	0,	1,	-6933.268066f,	-4905.634766f,	 0.714660f,   4.703444f},
	//=========================================World Locations==========================================================//
	//{1, 3,  4,  "World Locations..",   0,  0,  0,  0,  0,  0,  0,  0},
	//{1,	0,	4,	"Hunter Pets Area",	  0,	0,	0,	0,	-11196.299805f,	  -2196.830078f,	  20.282400f,	 6.186680f},
	{1,	0,	4,	"Custom Boss Event",	0,	0,	0,	0,	-8071.164551f,	 -766.644043f,	  131.932709f,	2.807233f},
	/*{1,	0,	2,	"Dire Maul Challenge",	0,	0,	0,	1,	-3684.743652f,	 1090.700195f,	  131.969330f,	3.102332f},*/
	/*{1,	0,	2,	"Donation Shop Preview",	0,	0,	0,	530,	384.891998f,	 3304.424805f,	  74.540146f,	5.007527f},*/
	{1,	0,	4,	"Emerald Dream (Just for Preview)",	0,	0,	0,	169,	3100.375977f,	 -3106.14917f,	  98.641663f,	3.231204f},
	//===================================================================================================================//
	{1, 12,  4,  "Arena-Queue Places",  0,  0,  0,  0,  0,  0,  0,  0},
	{12, 0,  4,  "Moonglade",  0,  0,  0,  1,   7565.310059f,   -2931.850098f,   466.323090f,   4.646120f},
	{12, 0,  4,  "Nagrand",  0,  0,  0,  530,   -632.664978f,   8638.459961f,   312.444000f,   2.385210f},
	{12, 0,  4,  "Old Ironforge",  0,  0,  0,  0,   -4821.729980f,   -976.239014f,   464.709991f,   0.659974f},
	{12, 0,  4,  "Ashenvale",  0,  0,  0,  1,   1786.410034f,   -1240.949951f,   147.964996f,   1.537370f},
	{12, 0,  4,  "The Barrens",  0,  0,  0,  1,   -1677.339966f,   -4331.270020f,   2.787450f,   2.379600f},
	{12, 0,  4,  "Forge Camp",  0,  0,  0,  530,   -1376.510010f,   9030.580078f,   53.928398f,   4.707840f},
	{12, 0,  4,  "Telaar",  0,  0,  0,  530,   -2718.120117f,   7300.051270f,   88.628456f,   5.855799f},
	{12, 1,  9,  "Back..",  0,  0,  0,  0,  0,  0,  0,  0},
	//===========================================World Locations menus====================================================//
	    {3,     6,      10,      "Eastern Kingdoms",     0,      0,      0,      0,      0,      0,      0,      0}, 
        {3,     7,      10,      "Kalimdor",     0,      0,      0,      0,      0,      0,      0,      0}, 
		{3,     8,      10,      "Outland",      0,      58,     0,      0,      0,      0,      0,      0}, 
		{3,     9,      10,      "Northrend",    0,      68,     0,      0,      0,      0,      0,      0}, 
		{3,     2,      9,      "Classic Dungeons",     0,      15,     0,      0,      0,      0,      0,      0},  
		{3,     4,      9,      "BC/Wrath Dungeons",       0,      69,     0,      0,      0,      0,      0,      0}, 
		{3,     5,      9,      "Raid Teleports",       0,      57,     0,      0,      0,      0,      0,      0},
		{3,     1,      9,      "Back..",       0,      57,     0,      0,      0,      0,      0,      0}, 
	//==============================================Eastern Kingdoms=======================================================//
	    {6,     0,      2,      "Elwynn Forest",        0,      0,      2,      0,      -9449.06f,      64.8392f,       56.3581f,       3.07047f},
        {6,     0,      2,      "Eversong Woods",       0,      0,      1,      530,    9024.37f,       -6682.55f,      16.8973f,       3.14131f},
        {6,     0,      2,      "Dun Morogh",   0,      0,      2,      0,      -5603.76f,      -482.704f,      396.98f,        5.23499f},
        {6,     0,      2,      "Tirisfal Glades",      0,      0,      1,      0,      2274.95f,       323.918f,       34.1137f,       4.24367f},
        {6,     0,      2,      "Ghostlands",   0,      10,     1,      530,    7595.73f,       -6819.6f,       84.3718f,       2.56561f},
        {6,     0,      2,      "Loch modan",   0,      10,     2,      0,      -5405.85f,      -2894.15f,      341.972f,       5.48238f},
        {6,     0,      2,      "Silverpine Forest",    0,      10,     1,      0,      505.126f,       1504.63f,       124.808f,       1.77987f},
        {6,     0,      2,      "Westfall",     0,      10,     2,      0,      -10684.9f,      1033.63f,       32.5389f,       6.07384f},
        {6,     0,      2,      "Redridge mountains",   0,      15,     2,      0,      -9447.8f,       -2270.85f,      71.8224f,       0.283853f},
        {6,     0,      2,      "Duskwood",     0,      18,     2,      0,      -10531.7f,      -1281.91f,      38.8647f,       1.56959f},
        {6,     0,      2,      "Hillsbrad Foothills",  0,      20,     0,      0,      -385.805f,      -787.954f,      54.6655f,       1.03926f},
        {6,     0,      2,      "Wetlands",     0,      20,     2,      0,      -3517.75f,      -913.401f,      8.86625f,       2.60705f},
        {6,     0,      2,      "Alterac Mountains",    0,      30,     0,      0,      275.049f,       -652.044f,      130.296f,       0.502032f},
        {6,     0,      2,      "Arathi Highlands",     0,      30,     0,      0,      -1581.45f,      -2704.06f,      35.4168f,       0.490373f},
        {6,     0,      2,      "Stranglethorn Vale",   0,      30,     0,      0,      -11921.7f,      -59.544f,       39.7262f,       3.73574f},
        {6,     0,      2,      "Badlands",     0,      35,     0,      0,      -6782.56f,      -3128.14f,      240.48f,        5.65912f},
        {6,     0,      2,      "Swamp of Sorrows",     0,      35,     0,      0,      -10368.6f,      -2731.3f,       21.6537f,       5.29238f},
        {6,     0,      2,      "The Hinterlands",      0,      40,     0,      0,      112.406f,       -3929.74f,      136.358f,       0.981903f},
        {6,     0,      2,      "Searing Gorge",        0,      43,     0,      0,      -6686.33f,      -1198.55f,      240.027f,       0.916887f},
        {6,     0,      2,      "The Blasted Lands",    0,      45,     0,      0,      -11184.7f,      -3019.31f,      7.29238f,       3.20542f},
        {6,     0,      2,      "Burning Steppes",      0,      50,     0,      0,      -7979.78f,      -2105.72f,      127.919f,       5.10148f},
        {6,     0,      2,      "Western Plaguelands",  0,      51,     0,      0,      1743.69f,       -1723.86f,      59.6648f,       5.23722f},
        {6,     0,      2,      "Eastern Plaguelands",  0,      53,     0,      0,      2280.64f,       -5275.05f,      82.0166f,       4.7479f},
        {6,     0,      2,      "Isle of Quel'Danas",   0,      70,     0,      530,    12806.5f,       -6911.11f,      41.1156f,       2.22935f},
        {6,     3,      7,      "Back..",       0,      0,      0,      0,      0,      0,      0,      0},
     //====================================================================Kalimdor=================================================================//
		{7,     0,      2,      "Azuremyst Isle",       0,      0,      2,      530,    -4192.62f,      -12576.7f,      36.7598f,       1.62813f},
        {7,     0,      2,      "Teldrassil",   0,      0,      2,      1,      9889.03f,       915.869f,       1307.43f,       1.9336f},
        {7,     0,      2,      "Durotar",      0,      0,      1,      1,      228.978f,       -4741.87f,      10.1027f,       0.416883f},
        {7,     0,      2,      "Mulgore",      0,      0,      1,      1,      -2473.87f,      -501.225f,      -9.42465f,      0.6525f},
        {7,     0,      2,      "Bloodmyst Isle",       0,      15,     2,      530,    -2095.7f,       -11841.1f,      51.1557f,       6.19288f},
        {7,     0,      2,      "Darkshore",    0,      10,     2,      1,      6463.25f,       683.986f,       8.92792f,       4.33534f},
        {7,     0,      2,      "The Barrens",  0,      10,     1,      1,      -575.772f,      -2652.45f,      95.6384f,       0.006469f},
        {7,     0,      2,      "Stonetalon Mountains", 0,      15,     0,      1,      1574.89f,       1031.57f,       137.442f,       3.8013f},
        {7,     0,      2,      "Ashenvale Forest",     0,      18,     0,      1,      1919.77f,       -2169.68f,      94.6729f,       6.14177f},
        {7,     0,      2,      "Thousand Needles",     0,      25,     1,      1,      -5375.53f,      -2509.2f,       -40.432f,       2.41885f},
        {7,     0,      2,      "Desolace",     0,      30,     0,      1,      -656.056f,      1510.12f,       88.3746f,       3.29553f},
        {7,     0,      2,      "Dustwallow Marsh",     0,      35,     0,      1,      -3350.12f,      -3064.85f,      33.0364f,       5.12666f},
        {7,     0,      2,      "Feralas",      0,      40,     0,      1,      -4808.31f,      1040.51f,       103.769f,       2.90655f},
        {7,     0,      2,      "Tanaris Desert",       0,      40,     0,      1,      -6940.91f,      -3725.7f,       48.9381f,       3.11174f},
        {7,     0,      2,      "Azshara",      0,      45,     0,      1,      3117.12f,       -4387.97f,      91.9059f,       5.49897f},
        {7,     0,      2,      "Felwood",      0,      48,     0,      1,      3898.8f,        -1283.33f,      220.519f,       6.24307f},
        {7,     0,      2,      "Un'Goro Crater",       0,      48,     0,      1,      -6291.55f,      -1158.62f,      -258.138f,      0.457099f},
        {7,     0,      2,      "Silithus",     0,      55,     0,      1,      -6815.25f,      730.015f,       40.9483f,       2.39066f},
        {7,     0,      2,      "Winterspring", 0,      55,     0,      1,      6658.57f,       -4553.48f,      718.019f,       5.18088f},
        {7,     3,      7,      "Back..",       0,      0,      0,      0,      0,      0,      0,      0},
		//Outland
		{8,     0,      2,      "Hellfire Peninsula",   0,      58,     0,      530,    -207.335f,      2035.92f,       96.464f,        1.59676f},
        {8,     0,      2,      "Zangarmarsh",  0,      60,     0,      530,    -220.297f,      5378.58f,       23.3223f,       1.61718f},
        {8,     0,      2,      "Terokkar Forest",      0,      62,     0,      530,    -2266.23f,      4244.73f,       1.47728f,       3.68426f},
        {8,     0,      2,      "Nagrand",      0,      64,     0,      530,    -1610.85f,      7733.62f,       -17.2773f,      1.33522f},
        {8,     0,      2,      "Blade's Edge Mountains",       0,      65,     0,      530,    2029.75f,       6232.07f,       133.495f,       1.30395f},
        {8,     0,      2,      "Netherstorm",  0,      67,     0,      530,    3271.2f,        3811.61f,       143.153f,       3.44101f},
        {8,     0,      2,      "Shadowmoon Valley",    0,      67,     0,      530,    -3681.01f,      2350.76f,       76.587f,        4.25995f},
        {8,     3,      7,      "Back..",       0,      0,      0,      0,      0,      0,      0,      0},
		//Northrend
		{9,     0,      2,      "Borean Tundra",        0,      68,     0,      571,    2954.24f,       5379.13f,       60.4538f,       2.55544f},
        {9,     0,      2,      "Howling Fjord",        0,      68,     0,      571,    682.848f,       -3978.3f,       230.161f,       1.54207f},
        {9,     0,      2,      "Dragonblight", 0,      71,     0,      571,    2678.17f,       891.826f,       4.37494f,       0.101121f},
        {9,     0,      2,      "Grizzly Hills",        0,      73,     0,      571,    4017.35f,       -3403.85f,      290.0f, 5.35431f},
        {9,     0,      2,      "Zul'Drak",     0,      74,     0,      571,    5560.23f,       -3211.66f,      371.709f,       5.55055f},
        {9,     0,      2,      "Sholazar Basin",       0,      76,     0,      571,    5614.67f,       5818.86f,       -69.722f,       3.60807f},
        {9,     0,      2,      "Crystalsong Forest",   0,      77,     0,      571,    5411.17f,       -966.37f,       167.082f,       1.57167f},
        {9,     0,      2,      "Storm Peaks",  0,      77,     0,      571,    6120.46f,       -1013.89f,      408.39f,        5.12322f},
        {9,     0,      2,      "Icecrown",     0,      77,     0,      571,    8323.28f,       2763.5f,        655.093f,       2.87223f},
        {9,     0,      2,      "Wintergrasp",  0,      77,     0,      571,    4522.23f,       2828.01f,       389.975f,       0.215009f},
		{9,     0,      2,      "Dalaran",  0,      0,     0,      571,    5804.149902f,       624.770996f,       647.767029f,       1.640000f},
        {9,     3,      7,      "Back..",       0,      0,      0,      0,      0,      0,      0,      0},
		//Classic Dungeons
		{2,     0,      2,      "Gnomeregan",   0,      25,     2,      0,      -5163.54f,      925.423f,       257.181f,       1.57423f},
        {2,     0,      2,      "The Deadmines",        0,      17,     2,      0,      -11209.6f,      1666.54f,       24.6974f,       1.42053f},
        {2,     0,      2,      "The Stockade", 0,      22,     2,      0,      -8799.15f,      832.718f,       97.6348f,       6.04085f},
        {2,     0,      2,      "Ragefire Chasm",       0,      15,     1,      1,      1811.78f,       -4410.5f,       -18.4704f,      5.20165f},
        {2,     0,      2,      "Razorfen Downs",       0,      34,     1,      1,      -4657.3f,       -2519.35f,      81.0529f,       4.54808f},
        {2,     0,      2,      "Razorfen Kraul",       0,      24,     1,      1,      -4470.28f,      -1677.77f,      81.3925f,       1.16302f},
        {2,     0,      2,      "Scarlet Monastery",    0,      32,     1,      0,      2873.15f,       -764.523f,      160.332f,       5.10447f},
        {2,     0,      2,      "Shadowfang Keep",      0,      18,     1,      0,      -234.675f,      1561.63f,       76.8921f,       1.24031f},
        {2,     0,      2,      "Wailing Caverns",      0,      17,     1,      1,      -731.607f,      -2218.39f,      17.0281f,       2.78486f},
        {2,     0,      2,      "Blackfathom Deeps",    0,      21,     0,      1,      4249.99f,       740.102f,       -25.671f,       1.34062f},
        {2,     0,      2,      "Blackrock Depths",     0,      53,     0,      0,      -7179.34f,      -921.212f,      165.821f,       5.09599f},
        {2,     0,      2,      "Blackrock Spire",      0,      57,     0,      0,      -7527.05f,      -1226.77f,      285.732f,       5.29626f},
        {2,     0,      2,      "Dire Maul",    0,      55,     0,      1,      -3520.14f,      1119.38f,       161.025f,       4.70454f},
        {2,     0,      2,      "Maraudon",     0,      45,     0,      1,      -1421.42f,      2907.83f,       137.415f,       1.70718f},
        {2,     0,      2,      "Scholomance",  0,      55,     0,      0,      1269.64f,       -2556.21f,      93.6088f,       0.620623f},
        {2,     0,      2,      "Stratholme",   0,      55,     0,      0,      3352.92f,       -3379.03f,      144.782f,       6.25978f},
        {2,     0,      2,      "Sunken Temple",        0,      47,     0,      0,      -10177.9f,      -3994.9f,       -111.239f,      6.01885f},
        {2,     0,      2,      "Uldaman",      0,      37,     0,      0,      -6071.37f,      -2955.16f,      209.782f,       0.015708f},
        {2,     0,      2,      "Zul'Farrak",   0,      35,     0,      1,      -6801.19f,      -2893.02f,      9.00388f,       0.158639f},
        {2,     3,      7,      "Back..",       0,      0,      0,      0,      0,      0,      0,      0},
		//Burning Crusade Dungeons
		{4,     0,      2,      "Auchindoun",   0,      64,     0,      530,    -3324.49f,      4943.45f,       -101.239f,      4.63901f},
        {4,     0,      2,      "Caverns of Time",      0,      66,     0,      1,      -8369.65f,      -4253.11f,      -204.272f,      -2.70526f},
        {4,     0,      2,      "Coilfang Reservoir",   0,      62,     0,      530,    738.865f,       6865.77f,       -69.4659f,      6.27655f},
        {4,     0,      2,      "Hellfire Citadel",     0,      59,     0,      530,    -347.29f,       3089.82f,       21.394f,        5.68114f},
        {4,     0,      2,      "Magisters' Terrace",   0,      70,     0,      530,    12884.6f,       -7317.69f,      65.5023f,       4.799f},
        {4,     0,      2,      "Tempest Keep", 0,      70,     0,      530,    3100.48f,       1536.49f,       190.3f, 4.62226f},
        //Wrath Dungeons
        {4,     0,      2,      "Azjol-Nerub",  0,      73,     0,      571,    3707.86f,       2150.23f,       36.76f, 3.22f},
        {4,     0,      2,      "The Culling of Stratholme",    0,      79,     0,      1,      -8756.39f,      -4440.68f,      -199.489f,      4.66289f},
        {4,     0,      2,      "Trial of the Champion",        0,      79,     0,      571,    8590.95f,       791.792f,       558.235f,       3.13127f},
        {4,     0,      2,      "Drak'Tharon Keep",     0,      74,     0,      571,    4765.59f,       -2038.24f,      229.363f,       0.887627f},
        {4,     0,      2,      "Gundrak",      0,      71,     0,      571,    6722.44f,       -4640.67f,      450.632f,       3.91123f},
        {4,     0,      2,      "Icecrown Citadel Dungeons",    0,      79,     0,      571,    5643.16f,       2028.81f,       798.274f,       4.60242f},
        {4,     0,      2,      "The Nexus Dungeons",   0,      71,     0,      571,    3782.89f,       6965.23f,       105.088f,       6.14194f},
        {4,     0,      2,      "The Violet Hold",      0,      75,     0,      571,    5693.08f,       502.588f,       652.672f,       4.0229f},
        {4,     0,      2,      "Halls of Lightning",   0,      79,     0,      571,    9136.52f,       -1311.81f,      1066.29f,       5.19113f},
        {4,     0,      2,      "Halls of Stone",       0,      77,     0,      571,    8922.12f,       -1009.16f,      1039.56f,       1.57044f},
        {4,     0,      2,      "Utgarde Keep", 0,      69,     0,      571,    1203.41f,       -4868.59f,      41.2486f,       0.283237f},
        {4,     0,      2,      "Utgarde Pinnacle",     0,      75,     0,      571,    1267.24f,       -4857.3f,       215.764f,       3.22768f},
        {4,     3,      7,      "Back..",       0,      0,      0,      0,      0,      0,      0,      0},
        //Raid Teleports
        {5,     0,      2,      "Black Temple", 0,      70,     0,      530,    -3649.92f,      317.469f,       35.2827f,       2.94285f},
        {5,     0,      2,      "Blackwing Lair",       0,      60,     0,      229,    152.451f,       -474.881f,      116.84f,        0.001073f},
        {5,     0,      2,      "Hyjal Summit", 0,      70,     0,      1,      -8177.89f,      -4181.23f,      -167.552f,      0.913338f},
        {5,     0,      2,      "Serpentshrine Cavern", 0,      70,     0,      530,    797.855f,       6865.77f,       -65.4165f,      0.005938f},
        {5,     0,      2,      "Trial of the Crusader",        0,      80,     0,      571,    8515.61f,       714.153f,       558.248f,       1.57753f},
        {5,     0,      2,      "Gruul's Lair", 0,      70,     0,      530,    3530.06f,       5104.08f,       3.50861f,       5.51117f},
        {5,     0,      2,      "Magtheridon's Lair",   0,      70,     0,      530,    -336.411f,      3130.46f,       -102.928f,      5.20322f},
        {5,     0,      2,      "Icecrown Citadel",     0,      80,     0,      571,    5855.22f,       2102.03f,       635.991f,       3.57899f},
        {5,     0,      2,      "Karazhan",     0,      70,     0,      0,      -11118.9f,      -2010.33f,      47.0819f,       0.649895f},
        {5,     0,      2,      "Molten Core",  0,      60,     0,      230,    1126.64f,       -459.94f,       -102.535f,      3.46095f},
        {5,     0,      2,      "Naxxramas",    0,      80,     0,      571,    3668.72f,       -1262.46f,      243.622f,       4.785f},
        {5,     0,      2,      "Onyxia's Lair",        0,      80,     0,      1,      -4708.27f,      -3727.64f,      54.5589f,       3.72786f},
        {5,     0,      2,      "Ruins of Ahn'Qiraj",   0,      60,     0,      1,      -8409.82f,      1499.06f,       27.7179f,       2.51868f},
        {5,     0,      2,      "Sunwell Plateau",      0,      70,     0,      530,    12574.1f,       -6774.81f,      15.0904f,       3.13788f},
        {5,     0,      2,      "The Eye",      0,      67,     0,      530,    3088.49f,       1381.57f,       184.863f,       4.61973f},
        {5,     0,      2,      "Temple of Ahn'Qiraj",  0,      60,     0,      1,      -8240.09f,      1991.32f,       129.072f,       0.941603f},
        {5,     0,      2,      "The Eye of Eternity",  0,      80,     0,      571,    3784.17f,       7028.84f,       161.258f,       5.79993f},
        {5,     0,      2,      "The Obsidian Sanctum", 0,      80,     0,      571,    3472.43f,       264.923f,       -120.146f,      3.27923f},
        {5,     0,      2,      "Ulduar",       0,      80,     0,      571,    9222.88f,       -1113.59f,      1216.12f,       6.27549f},
        {5,     0,      2,      "Vault of Archavon",    0,      80,     0,      571,    5453.72f,       2840.79f,       421.28f,        0.0f},
        {5,     0,      2,      "Zul'Gurub",    0,      57,     0,      0,      -11916.7f,      -1215.72f,      92.289f,        4.72454f},
        {5,     0,      2,      "Zul'Aman",     0,      70,     1,      530,    6851.78f,       -7972.57f,      179.242f,       4.64691f},
        {5,     3,      7,      "Back..",       0,      0,      0,      0,      0,      0,      0,      0},
 

//	{10,	0,	2,	"Teleport",	0,	0,	0,	map,	xf,	yf,	zf,	of},
//	{10,	1,	7,	"Back..",	0,	0,	0,	0,	0,	0,	0,	0},
};

// TextIDs from npc_text
enum eEnums
{
	TEXT_MAIN_H		=	300000,			//Horde main menu text
	TEXT_MAIN_A		=	300001,			//Alliance main menu text
	TEXT_DUNGEON	=	300002,			//Dungeon teleport menu texts
	TEXT_RAID		=	300003,			//Raid teleport menu text
	TEXT_AREA		=	300004,			//Area teleport location menu texts
	
	TELEPORT_COUNT	=	sizeof TeLe/sizeof(*TeLe),
};

#define ARE_YOU_SURE	"Are you sure, that you want to go to "
#define ERROR_COMBAT	"|cffff0000You are in combat|r"

bool Custom_FactCheck (uint32 Fact, unsigned char Key)
{
	bool Show = false;
	switch (TeLe[Key].faction)
	{
	case 0:
		Show = true;
		break;
	case 1:
		if (Fact == HORDE)
			Show = true;
		break;
	case 2:
		if (Fact == ALLIANCE)
			Show = true;
		break;
	}
	return (Show);
}

uint32 Custom_GetText (unsigned int menu, Player* pPlayer)
{
	uint32 TEXT = TEXT_AREA;
	switch (menu)
	{
	case 0:
		switch (pPlayer->GetTeam())
		{
		case ALLIANCE:
			TEXT = TEXT_MAIN_A;
			break;
		case HORDE:
			TEXT = TEXT_MAIN_H;
			break;
		}
	case 1:
	case 2:
	case 3:
		TEXT = TEXT_DUNGEON;
		break;
	case 4:
		TEXT = TEXT_RAID;
		break;
	}
	return (TEXT);
}

void Custom_GetMenu (Player* pPlayer, Creature* pCreature, uint32 Key)
{
	bool ENDMENU = false;
	for(uint32 i = 0; i < TELEPORT_COUNT; i++)
	{
		if (ENDMENU && TeLe[i].menu_id != Key)
			break;
		if (TeLe[i].menu_id == Key && pPlayer->getLevel() >= TeLe[i].level && Custom_FactCheck(pPlayer->GetTeam(), i))
		{
			if (TeLe[i].next_menu_id != 0)
				pPlayer->ADD_GOSSIP_ITEM_EXTENDED(TeLe[i].icon, TeLe[i].name, GOSSIP_SENDER_MAIN, i, "", TeLe[i].cost, false);
			else
				pPlayer->ADD_GOSSIP_ITEM_EXTENDED(TeLe[i].icon, TeLe[i].name, GOSSIP_SENDER_MAIN, i, ARE_YOU_SURE+TeLe[i].name, TeLe[i].cost, false);
			ENDMENU = true;
		}
	}
	pPlayer->PlayerTalkClass->SendGossipMenu(Custom_GetText(Key, pPlayer), pCreature->GetGUID());
}

class TeLe_gossip_codebox : public CreatureScript
{
	public:
	TeLe_gossip_codebox()
	: CreatureScript("TeLe_gossip_codebox")
	{
	}

	bool OnGossipHello(Player* pPlayer, Creature* pCreature)
	{
		Custom_GetMenu(pPlayer, pCreature, 1);
		return true;
	}

	bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
	{
		pPlayer->PlayerTalkClass->ClearMenus(); // clear the menu

		pPlayer->ModifyMoney(-1 * TeLe[uiAction].cost); // take cash
		uint32 Key = TeLe[uiAction].next_menu_id;
		if (Key == 0) // if no next_menu_id, then teleport to coords
		{
			if (!pPlayer->isInCombat())
			{
				pPlayer->CLOSE_GOSSIP_MENU();
				pPlayer->TeleportTo(TeLe[uiAction].map, TeLe[uiAction].x, TeLe[uiAction].y, TeLe[uiAction].z, TeLe[uiAction].o);
				return true;
			}
			pPlayer->GetSession()->SendAreaTriggerMessage(ERROR_COMBAT);
			Key = TeLe[uiAction].menu_id;
		}

		Custom_GetMenu(pPlayer, pCreature, Key);
		return true;
	}
};

void AddSC_TeLe_gossip_codebox()
{
    new TeLe_gossip_codebox();
}
