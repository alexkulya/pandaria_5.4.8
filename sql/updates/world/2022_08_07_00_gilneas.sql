UPDATE `gameobject` SET `phaseMask` = 16384 WHERE `guid` IN (166783, 166784);
UPDATE `quest_template` SET `Flags` = 8 WHERE `Id` = 14465;

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (36452, 38765, 36606);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (36452, 38765, 36606) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(36452,0,0,0,19,0,100,0,14465,0,0,0,85,72772,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Gwen Armstead - On Quest Accept - Summon Horse"),

(38765,0,0,0,27,0,100,0,0,0,0,0,53,1,38765,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Stout Mountain Horse - On Passenger Boarded - Start WP"),
(38765,0,1,0,40,0,100,0,15,0,0,0,28,46598,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Stout Mountain Horse - On WP Reached 15 - Remove Passenger"),
(38765,0,2,0,40,0,100,0,3,0,0,0,54,1000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Stout Mountain Horse - On WP Reached 3 - WP Pause (1000 ms)"),
(38765,0,3,0,40,0,100,0,3,0,0,0,9,0,0,0,0,0,0,14,166783,196863,0,0.0,0.0,0.0,0.0,"Stout Mountain Horse - On WP Reached 3 - Open Gate"),
(38765,0,5,0,40,0,100,0,13,0,0,0,54,1000,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Stout Mountain Horse - On WP Reached 13 - WP Pause (1000 ms)"),
(38765,0,6,0,40,0,100,0,13,0,0,0,9,0,0,0,0,0,0,14,166784,196864,0,0.0,0.0,0.0,0.0,"Stout Mountain Horse - On WP Reached 13 - Open Gate"),

(36606,0,0,0,20,0,100,0,14465,0,0,0,85,68709,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Queen Mia Greymane - On Quest Rewarded - Cataclysm");

DELETE FROM `waypoints` WHERE `entry` = 38765;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(38765, 1, -1870.36, 2282.73, 42.32, "Stout Mountain Horse"),
(38765, 2, -1852.05, 2302.51, 41.83, "Stout Mountain Horse"),
(38765, 3, -1829.29, 2323.74, 37.55, "Stout Mountain Horse"),
(38765, 4, -1818.32, 2332.80, 36.37, "Stout Mountain Horse"),
(38765, 5, -1801.58, 2344.71, 35.77, "Stout Mountain Horse"),
(38765, 6, -1792.48, 2352.44, 36.52, "Stout Mountain Horse"),
(38765, 7, -1787.74, 2359.60, 38.00, "Stout Mountain Horse"),
(38765, 8, -1781.81, 2383.18, 43.27, "Stout Mountain Horse"),
(38765, 9, -1777.55, 2423.56, 55.68, "Stout Mountain Horse"),
(38765, 10, -1770.01, 2447.47, 62.25, "Stout Mountain Horse"),
(38765, 11, -1754.47, 2464.13, 69.36, "Stout Mountain Horse"),
(38765, 12, -1710.82, 2466.15, 82.81, "Stout Mountain Horse"),
(38765, 13, -1691.46, 2493.66, 95.20, "Stout Mountain Horse"),
(38765, 14, -1682.62, 2507.22, 97.79, "Stout Mountain Horse"),
(38765, 15, -1669.61, 2519.56, 97.89, "Stout Mountain Horse");

UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (220120, 220336, 220373, 219888, 220260, 220122, 220335,
                                                                                  219889, 220334, 220261, 220258, 219429, 220118, 220121);

DELETE FROM `spell_script_names` WHERE `spell_id` = 69257;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(69257, "spell_gilneas_test_telescope");

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "" WHERE `entry` = 36743;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 36743 AND `source_type` = 0;

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (43336, 44928);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(43336, 43338, 0, 1, "Stagecoach Harness - Horse", 8, 0),
(43336, 43338, 1, 1, "Stagecoach Harness - Horse", 8, 0),
(43336, 44928, 2, 1, "Stagecoach Harness - Caravan", 8, 0),

(44928, 38853, 0, 1, "Stagecoach Carriage", 8, 0),
(44928, 44460, 2, 1, "Stagecoach Carriage", 8, 0),
(44928, 36138, 3, 1, "Stagecoach Carriage", 8, 0),
(44928, 43907, 4, 1, "Stagecoach Carriage", 8, 0),
(44928, 43907, 5, 1, "Stagecoach Carriage", 8, 0),
(44928, 51409, 6, 1, "Stagecoach Carriage", 8, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (43336, 44928);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES
(43336, 46598, 0),

(44928, 46598, 0);

UPDATE `creature` SET `spawnMask` = 1, `phaseMask` = 180224, `position_x` = -1670.155, `position_y` = 2532.311, `position_z` = 97.848, `orientation` = 4.387 WHERE `guid` = 219210;
UPDATE `creature` SET `spawnMask` = 1, `phaseMask` = 180224, `position_x` = -1669.974, `position_y` = 2532.950, `position_z` = 97.848, `orientation` = 4.367 WHERE `guid` = 219213;
DELETE FROM `creature` WHERE `guid` IN (219214, 219215, 219216, 219219);
DELETE FROM `creature_addon` WHERE `guid` IN (219214, 219215, 219216, 219219);

UPDATE `creature_template` SET `npcflag` = 1, `AIName` = "", `ScriptName` = "npc_stagecoach_carriage_exodus" WHERE `entry` = 44928;

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_stagecoach_harness" WHERE `entry` = 43336;

DELETE FROM `script_waypoint` WHERE `entry` = 43336;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES
(43336, 1, -1681.45, 2508.27, 97.84, "Stagecoach Harness"),
(43336, 2, -1695.46, 2486.82, 92.64, "Stagecoach Harness"),
(43336, 3, -1704.99, 2468.26, 84.84, "Stagecoach Harness"),
(43336, 4, -1698.38, 2447.65, 80.77, "Stagecoach Harness"),
(43336, 5, -1698.42, 2432.73, 76.52, "Stagecoach Harness"),
(43336, 6, -1725.88, 2390.50, 60.80, "Stagecoach Harness"),
(43336, 7, -1735.64, 2362.27, 63.15, "Stagecoach Harness"),
(43336, 8, -1745.18, 2343.69, 67.34, "Stagecoach Harness"),
(43336, 9, -1746.53, 2329.92, 69.60, "Stagecoach Harness"),
(43336, 10, -1757.21, 2300.38, 75.77, "Stagecoach Harness"),
(43336, 11, -1776.38, 2271.80, 82.11, "Stagecoach Harness"),
(43336, 12, -1799.38, 2251.48, 87.64, "Stagecoach Harness"),
(43336, 13, -1826.19, 2238.05, 89.31, "Stagecoach Harness"),
(43336, 14, -1868.50, 2174.60, 89.31, "Stagecoach Harness"),
(43336, 15, -1872.45, 2135.71, 89.31, "Stagecoach Harness"),
(43336, 16, -1872.96, 2075.18, 89.31, "Stagecoach Harness"),
(43336, 17, -1881.14, 2046.58, 89.31, "Stagecoach Harness"),
(43336, 18, -1885.72, 2019.56, 89.31, "Stagecoach Harness"),
(43336, 19, -1876.85, 1970.16, 89.17, "Stagecoach Harness"),
(43336, 20, -1878.35, 1921.33, 89.13, "Stagecoach Harness"),
(43336, 21, -1890.52, 1904.26, 89.15, "Stagecoach Harness"),
(43336, 22, -1990.23, 1901.42, 89.28, "Stagecoach Harness"),
(43336, 23, -2036.81, 1914.56, 83.23, "Stagecoach Harness"),
(43336, 24, -2061.07, 1905.41, 73.95, "Stagecoach Harness"),
(43336, 25, -2093.23, 1881.99, 53.77, "Stagecoach Harness"),
(43336, 26, -2103.06, 1870.42, 46.52, "Stagecoach Harness"),
(43336, 27, -2122.61, 1831.95, 29.18, "Stagecoach Harness"),
(43336, 28, -2146.32, 1814.97, 19.03, "Stagecoach Harness"),
(43336, 29, -2186.33, 1808.11, 12.11, "Stagecoach Harness"),
(43336, 30, -2217.77, 1809.60, 11.78, "Stagecoach Harness"),
(43336, 31, -2239.38, 1805.10, 11.94, "Stagecoach Harness"),
(43336, 32, -2310.30, 1774.33, 11.05, "Stagecoach Harness"),
(43336, 33, -2376.50, 1704.52, 11.15, "Stagecoach Harness");

DELETE FROM `creature_text` WHERE `entry` = 51409;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(51409,0,0,"","Look out! We're under attack!",14,0,100,0,0,0,"Lorna Crowley");

UPDATE `creature_equip_template` SET `itemEntry1` = 15460 WHERE `entry` = 51409 AND `id` = 1;

DELETE FROM `creature` WHERE `guid` IN (421640, 421641) AND `id` = 43338;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `movement_type`) VALUES
(421640, 43338, 654, 1, 180224, 0, -1671.675, 2530.066, 97.848, 4.391, 300, 0, 0),
(421641, 43338, 654, 1, 180224, 0, -1670.333, 2529.619, 97.848, 4.391, 300, 0, 0);
