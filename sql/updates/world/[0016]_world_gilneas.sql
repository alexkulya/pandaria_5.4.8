/*
 Вороны не взлетают
 35112 - не запускается скипт при взятии квеста
 Скрипт энрейджа для воргенов - квест на крыше с волнами
 Скрипт для сцены с пушкой
 Текст после квеста спасение Аранаса
*/

UPDATE `creature` SET `position_x` = -1494.238, `position_y` = 1336.437, `position_z` = 58.767, `orientation` = 1.931 WHERE `guid` = 219545 AND `id` = 34867;
UPDATE `creature` SET `position_x` = -1486.67, `position_y` = 1440.716, `position_z` = 59.125, `orientation` = 4.659 WHERE `guid` = 219546 AND `id` = 34867;
UPDATE `creature` SET `position_x` = -1446.26, `position_y` = 1450.723, `position_z` = 71.052, `orientation` = 3.149093 WHERE `guid` = 219547 AND `id` = 34867;
UPDATE `creature` SET `position_x` = -1509.6, `position_y` = 1370.527, `position_z` = 73.233, `orientation` = 3.149093 WHERE `guid` = 219548 AND `id` = 34867;
UPDATE `creature` SET `position_x` = -1507.03, `position_y` = 1321.1, `position_z` = 73.285, `orientation` = 3.377 WHERE `guid` = 219549 AND `id` = 34867;
UPDATE `creature` SET `position_x` = -1460.46, `position_y` = 1370.69, `position_z` = 64.475, `orientation` = 6.209 WHERE `guid` = 219550 AND `id` = 34867;
UPDATE `creature` SET `position_x` = -1421.93, `position_y` = 1401.452, `position_z` = 71.819, `orientation` = 4.755233 WHERE `guid` = 219551 AND `id` = 34867;
UPDATE `creature` SET `position_x` = -1409.69, `position_y` = 1429.24, `position_z` = 59.063, `orientation` = 6.205 WHERE `guid` = 219552 AND `id` = 34867;
UPDATE `creature` SET `position_x` = -1562.106, `position_y` = 1409.314, `position_z` = 71.721, `orientation` = 1.582226 WHERE `guid` = 219553 AND `id` = 34867;
UPDATE `creature` SET `position_x` = -1430.04, `position_y` = 1429.107, `position_z` = 59.057, `orientation` = 3.169 WHERE `guid` = 219554 AND `id` = 34867;

UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (219545, 219546, 219547, 219548, 219549, 219550, 219551, 219552, 219553, 219554);

DELETE FROM `creature_addon` WHERE `guid` IN (219545, 219546, 219547, 219548, 219549, 219550, 219551, 219552, 219553, 219554);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(219545, 0, 8, 1, 0, "39662"),
(219546, 0, 8, 1, 0, "39662"),
(219547, 0, 0, 1, 0, "39662"),
(219548, 0, 0, 1, 0, "39662"),
(219549, 0, 0, 1, 0, "39662"),
(219550, 0, 8, 1, 0, "39662"),
(219551, 0, 0, 1, 0, "39662"),
(219552, 0, 8, 1, 0, "39662"),
(219553, 0, 0, 1, 0, "39662"),
(219554, 0, 8, 1, 0, "39662");

DELETE FROM `waypoint_data` WHERE `id` = 219545;
DELETE FROM `waypoints` WHERE `entry` IN (348670, 348671, 348672, 348673, 348674);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(348670, 1, -1446.26, 1450.723, 71.052, "Shadowy Figure"),
(348670, 2, -1442.63, 1450.802, 71.116, "Shadowy Figure"),
(348670, 3, -1440.51, 1450.681, 71.129, "Shadowy Figure"),
(348670, 4, -1420.51, 1451.143, 71.531, "Shadowy Figure"),
(348670, 5, -1420.19, 1426.869, 72.786, "Shadowy Figure"),
(348670, 6, -1420.51, 1451.143, 71.531, "Shadowy Figure"),
(348670, 7, -1409.75, 1451.397, 72.759, "Shadowy Figure"),
(348670, 8, -1387.74, 1393.781, 73.008, "Shadowy Figure"),
(348670, 9, -1387.15, 1461.186, 73.155, "Shadowy Figure"),
(348670, 10, -1386.907, 1452.008, 72.38, "Shadowy Figure"),
(348670, 11, -1439.54, 1450.702, 71.146, "Shadowy Figure"),
(348670, 12, -1442.58, 1450.784, 71.117, "Shadowy Figure"),
(348670, 13, -1473.61, 1451.046, 72.529, "Shadowy Figure"),
(348670, 14, -1513.61, 1450.771, 71.138, "Shadowy Figure"),
(348670, 15, -1516.12, 1450.739, 71.117, "Shadowy Figure"),
(348670, 16, -1542.02, 1450.936, 71.166, "Shadowy Figure"),
(348670, 17, -1546.29, 1450.326, 71.221, "Shadowy Figure"),
(348670, 18, -1549.32, 1449.374, 71.223, "Shadowy Figure"),
(348670, 19, -1553.46, 1447.001, 71.131, "Shadowy Figure"),
(348670, 20, -1557.25, 1442.885, 71.026, "Shadowy Figure"),
(348670, 21, -1560.56, 1437.244, 70.992, "Shadowy Figure"),
(348670, 22, -1562.48, 1430.272, 70.922, "Shadowy Figure"),
(348670, 23, -1562.16, 1409.398, 71.713, "Shadowy Figure"),
(348670, 24, -1594.14, 1408.106, 72.883, "Shadowy Figure"),
(348670, 25, -1562.22, 1409.616, 71.692, "Shadowy Figure"),
(348670, 26, -1562.39, 1431.084, 70.912, "Shadowy Figure"),
(348670, 27, -1560.53, 1437.465, 70.994, "Shadowy Figure"),
(348670, 28, -1556.66, 1443.712, 71.037, "Shadowy Figure"),
(348670, 29, -1553.18, 1447.33, 71.141, "Shadowy Figure"),
(348670, 30, -1549.11, 1449.37, 71.228, "Shadowy Figure"),
(348670, 31, -1546.61, 1450.35, 71.225, "Shadowy Figure"),
(348670, 32, -1515.92, 1450.72, 71.117, "Shadowy Figure"),
(348670, 33, -1513.99, 1450.71, 71.13, "Shadowy Figure"),
(348670, 34, -1483.33, 1451.37, 72.75, "Shadowy Figure"),
(348670, 35, -1462.11, 1450.82, 71.27, "Shadowy Figure"),

(348671, 1, -1509.6, 1370.527, 73.233, "Shadowy Figure"),
(348671, 2, -1475.03, 1370.223, 71.843, "Shadowy Figure"),
(348671, 3, -1497.173, 1370.632, 73.18, "Shadowy Figure"),
(348671, 4, -1531.706, 1370.083, 71.79, "Shadowy Figure"),

(348672, 1, -1564.72, 1305.238, 73.726, "Shadowy Figure"),
(348672, 2, -1503.081, 1322.301, 73.691, "Shadowy Figure"),
(348672, 3, -1475.027, 1330.954, 71.224, "Shadowy Figure"),
(348672, 4, -1472.984, 1331.376, 70.75, "Shadowy Figure"),
(348672, 5, -1453.404, 1336.731, 70.541, "Shadowy Figure"),
(348672, 6, -1472.984, 1331.376, 70.75, "Shadowy Figure"),
(348672, 7, -1475.027, 1330.954, 71.224, "Shadowy Figure"),
(348672, 8, -1494.097, 1325.942, 71.425, "Shadowy Figure"),
(348672, 9, -1509.355, 1320.472, 73.064, "Shadowy Figure"),

(348673, 1, -1421.93, 1401.452, 71.819, "Shadowy Figure"),
(348673, 2, -1421.27, 1416.098, 64.517, "Shadowy Figure"),
(348673, 3, -1421.18, 1411.319, 63.666, "Shadowy Figure"),
(348673, 4, -1421.408, 1378.319, 73.281, "Shadowy Figure"),
(348673, 5, -1421.539, 1386.362, 71.882, "Shadowy Figure"),

(348674, 1, -1562.106, 1409.314, 71.721, "Shadowy Figure"),
(348674, 2, -1562.505, 1424.309, 71.087, "Shadowy Figure"),
(348674, 3, -1550.897, 1424.948, 67.934, "Shadowy Figure"),
(348674, 4, -1554.607, 1424.859, 67.016, "Shadowy Figure"),
(348674, 5, -1562.159, 1409.213, 71.714, "Shadowy Figure"),
(348674, 6, -1583.951, 1408.604, 71.773, "Shadowy Figure"),
(348674, 7, -1583.977, 1406.82, 70.702, "Shadowy Figure"),
(348674, 8, -1583.578, 1388.626, 70.268, "Shadowy Figure"),
(348674, 9, -1583.587, 1386.165, 70.406, "Shadowy Figure"),
(348674, 10, -1583.345, 1378.357, 71.797, "Shadowy Figure"),
(348674, 11, -1593.268, 1378.017, 72.829, "Shadowy Figure"),
(348674, 12, -1560.139, 1377.728, 72.973, "Shadowy Figure"),
(348674, 13, -1536.4, 1370.865, 62.997, "Shadowy Figure"),
(348674, 14, -1536.334, 1383.368, 61.117, "Shadowy Figure"),
(348674, 15, -1536.364, 1381.037, 60.534, "Shadowy Figure"),
(348674, 16, -1546.873, 1370.736, 64.512, "Shadowy Figure"),
(348674, 17, -1583.402, 1378.333, 71.796, "Shadowy Figure"),
(348674, 18, -1583.493, 1386.039, 70.43, "Shadowy Figure"),
(348674, 19, -1583.528, 1388.739, 70.256, "Shadowy Figure"),
(348674, 20, -1583.938, 1408.432, 71.775, "Shadowy Figure"),
(348674, 21, -1567.825, 1409.405, 71.127, "Shadowy Figure");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 34867;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34867, -219547, -219548, -219549, -219551, -219553) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34867*100, 34867*100+01, 34867*100+02, 34867*100+03, 34867*100+04, 34867*100+05, 34867*100+06, 34867*100+07, 34867*100+08, 34867*100+09, 34867*100+10) AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34867*100+11, 34867*100+12, 34867*100+13, 34867*100+14, 34867*100+15, 34867*100+16, 34867*100+17, 34867*100+18, 34867*100+19) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-219547,0,0,0,25,0,100,0,0,0,0,0,53,1,348670,1,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Reset - Start Waypoint"),
(-219547,0,1,2,40,0,100,0,7,348670,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 7 Reached - Pause Waypoint (2700 ms)"),
(-219547,0,2,0,61,0,100,0,0,0,0,0,80,34867*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 7 Reached (Link) - Start Script"),
(-219547,0,3,4,40,0,100,0,10,348670,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 10 Reached - Pause Waypoint (2700 ms)"),
(-219547,0,4,0,61,0,100,0,0,0,0,0,80,34867*100+01,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 10 Reached (Link) - Start Script"),
(-219547,0,5,6,40,0,100,0,13,348670,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 13 Reached - Pause Waypoint (2700 ms)"),
(-219547,0,6,0,61,0,100,0,0,0,0,0,80,34867*100+02,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 13 Reached (Link) - Start Script"),
(-219547,0,7,8,40,0,100,0,34,348670,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 34 Reached - Pause Waypoint (2700 ms)"),
(-219547,0,8,0,61,0,100,0,0,0,0,0,80,34867*100+03,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 34 Reached (Link) - Start Script"),

(-219548,0,0,0,25,0,100,0,0,0,0,0,53,1,348671,1,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Reset - Start Waypoint"),
(-219548,0,1,2,40,0,100,0,1,348671,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 1 Reached - Pause Waypoint (2700 ms)"),
(-219548,0,2,0,61,0,100,0,0,0,0,0,80,34867*100+04,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 1 Reached (Link) - Start Script"),
(-219548,0,3,4,40,0,100,0,3,348671,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 3 Reached - Pause Waypoint (2700 ms)"),
(-219548,0,4,0,61,0,100,0,0,0,0,0,80,34867*100+05,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 3 Reached (Link) - Start Script"),

(-219549,0,0,0,25,0,100,0,0,0,0,0,53,1,348672,1,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Reset - Start Waypoint"),
(-219549,0,1,2,40,0,100,0,2,348672,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 2 Reached - Pause Waypoint (2700 ms)"),
(-219549,0,2,0,61,0,100,0,0,0,0,0,80,34867*100+06,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 2 Reached (Link) - Start Script"),
(-219549,0,3,4,40,0,100,0,8,348672,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 8 Reached - Pause Waypoint (2700 ms)"),
(-219549,0,4,0,61,0,100,0,0,0,0,0,80,34867*100+07,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 8 Reached (Link) - Start Script"),

(-219551,0,0,0,25,0,100,0,0,0,0,0,53,0,348673,1,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Reset - Start Waypoint"),
(-219551,0,1,2,40,0,100,0,1,348673,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 1 Reached - Pause Waypoint (2700 ms)"),
(-219551,0,2,0,61,0,100,0,0,0,0,0,80,34867*100+08,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 1 Reached (Link) - Start Script"),
(-219551,0,3,4,40,0,100,0,2,348673,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 2 Reached - Pause Waypoint (6000 ms)"),
(-219551,0,4,0,61,0,100,0,0,0,0,0,80,34867*100+09,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 2 Reached (Link) - Start Script"),
(-219551,0,5,6,40,0,100,0,3,348673,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 3 Reached - Pause Waypoint (2700 ms)"),
(-219551,0,6,0,61,0,100,0,0,0,0,0,80,34867*100+10,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 3 Reached (Link) - Start Script"),
(-219551,0,7,8,40,0,100,0,4,348673,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 4 Reached - Pause Waypoint (6000 ms)"),
(-219551,0,8,0,61,0,100,0,0,0,0,0,80,34867*100+11,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 4 Reached (Link) - Start Script"),

(-219553,0,0,0,25,0,100,0,0,0,0,0,53,0,348674,1,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Reset - Start Waypoint"),
(-219553,0,1,2,40,0,100,0,2,348674,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 2 Reached - Pause Waypoint (2700 ms)"),
(-219553,0,2,0,61,0,100,0,0,0,0,0,80,34867*100+12,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 2 Reached (Link) - Start Script"),
(-219553,0,3,4,40,0,100,0,3,348674,0,0,54,14000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 3 Reached - Pause Waypoint (14000 ms)"),
(-219553,0,4,0,61,0,100,0,0,0,0,0,80,34867*100+13,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 3 Reached (Link) - Start Script"),
(-219553,0,5,6,40,0,100,0,4,348674,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 4 Reached - Pause Waypoint (2700 ms)"),
(-219553,0,6,0,61,0,100,0,0,0,0,0,80,34867*100+14,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 4 Reached (Link) - Start Script"),
(-219553,0,7,8,40,0,100,0,11,348674,0,0,54,14000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 11 Reached - Pause Waypoint (14000 ms)"),
(-219553,0,8,0,61,0,100,0,0,0,0,0,80,34867*100+15,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 11 Reached (Link) - Start Script"),
(-219553,0,9,10,40,0,100,0,12,348674,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 12 Reached - Pause Waypoint (2700 ms)"),
(-219553,0,10,0,61,0,100,0,0,0,0,0,80,34867*100+16,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 12 Reached (Link) - Start Script"),
(-219553,0,11,12,40,0,100,0,14,348674,0,0,54,14000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 14 Reached - Pause Waypoint (14000 ms)"),
(-219553,0,12,0,61,0,100,0,0,0,0,0,80,34867*100+17,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 14 Reached (Link) - Start Script"),
(-219553,0,13,14,40,0,100,0,15,348674,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 15 Reached - Pause Waypoint (2700 ms)"),
(-219553,0,14,0,61,0,100,0,0,0,0,0,80,34867*100+18,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 15 Reached (Link) - Start Script"),
(-219553,0,15,16,40,0,100,0,16,348674,0,0,54,2700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 16 Reached - Pause Waypoint (2700 ms)"),
(-219553,0,16,0,61,0,100,0,0,0,0,0,80,34867*100+19,2,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Waypoint 16 Reached (Link) - Start Script"),

(34867*100,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100,9,1,0,0,0,100,0,0,0,0,0,97,20,20,0,0,0,0,1,0,0,0,-1387.127,1452.005,72.38,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+01,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+01,9,1,0,0,0,100,0,0,0,0,0,97,20,20,0,0,0,0,1,0,0,0,-1409.852,1451.495,72.74,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+01,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+02,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+02,9,1,0,0,0,100,0,0,0,0,0,97,20,10,0,0,0,0,1,0,0,0,-1483.831,1451.561,72.65,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+02,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+03,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+03,9,1,0,0,0,100,0,0,0,0,0,97,20,10,0,0,0,0,1,0,0,0,-1473.696,1451.069,72.56,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+03,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+04,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+04,9,1,0,0,0,100,0,0,0,0,0,97,20,10,0,0,0,0,1,0,0,0,-1497.173,1370.632,73.18,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+04,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+05,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+05,9,1,0,0,0,100,0,0,0,0,0,97,20,10,0,0,0,0,1,0,0,0,-1509.436,1370.704,73.279,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+05,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+06,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+06,9,1,0,0,0,100,0,0,0,0,0,97,20,10,0,0,0,0,1,0,0,0,-1494.099,1325.924,71.427,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+06,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+07,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+07,9,1,0,0,0,100,0,0,0,0,0,97,20,10,0,0,0,0,1,0,0,0,-1502.94,1322.25,73.7,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+07,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+08,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+08,9,1,0,0,0,100,0,0,0,0,0,97,20,15,0,0,0,0,1,0,0,0,-1421.19,1409.8,63.4,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+08,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+09,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.559,"Shadowy Figure - On Script - Set Orientation (1.559)"),

(34867*100+10,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+10,9,1,0,0,0,100,0,0,0,0,0,97,20,15,0,0,0,0,1,0,0,0,-1421.94,1401.76,71.81,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+10,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+11,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.783,"Shadowy Figure - On Script - Set Orientation (4.783)"),

(34867*100+12,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+12,9,1,0,0,0,100,0,0,0,0,0,97,20,10,0,0,0,0,1,0,0,0,-1557.18,1424.72,67.07,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+12,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+13,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.0431,"Shadowy Figure - On Script - Set Orientation (0.0431)"),

(34867*100+14,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+14,9,1,0,0,0,100,0,0,0,0,0,97,20,10,0,0,0,0,1,0,0,0,-1562.2,1424.838,71.068,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+14,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+15,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.1415,"Shadowy Figure - On Script - Set Orientation (3.1415)"),

(34867*100+16,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+16,9,1,0,0,0,100,0,0,0,0,0,97,20,10,0,0,0,0,1,0,0,0,-1546.94,1370.72,64.519,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+16,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+17,9,0,0,0,0,100,0,1000,1000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.4868,"Shadowy Figure - On Script - Set Orientation (0.4868)"),

(34867*100+18,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+18,9,1,0,0,0,100,0,0,0,0,0,97,20,15,0,0,0,0,1,0,0,0,-1536.37,1370.77,62.998,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+18,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off"),

(34867*100+19,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active On"),
(34867*100+19,9,1,0,0,0,100,0,0,0,0,0,97,20,15,0,0,0,0,1,0,0,0,-1559.48,1377.65,73.239,0,"Shadowy Figure - On Script - Jump To Position"),
(34867*100+19,9,2,0,0,0,100,0,2500,2500,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowy Figure - On Script - Set Active Off");

DELETE FROM `disables` WHERE `entry` = 34867 AND `sourceType` = 10;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(10, 34867, 1, "", "", "Shadowy Figure - MMAP");

UPDATE `creature_template` SET `ScriptName` = "npc_gilneas_city_guard_gate" WHERE `entry` = 34864;
UPDATE `creature_template` SET `ScriptName` = "npc_gilneas_crow", `InhabitType` = 4 WHERE `entry` = 50260;

DELETE FROM `creature_text` WHERE `entry` IN (34864, 44086);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34864, 0, 0, "No one's allowed to leave. Prince Liam's orders.", "", 12, 0, 100, 1, 0, 0, "Gilneas City Guard"),
(34864, 0, 1, "It isn't safe to leave, there's something lurking out there in the woods.", "", 12, 0, 100, 1, 0, 0, "Gilneas City Guard"),
(34864, 0, 2, "Stay calm. We have everything under control.", "", 12, 0, 100, 25, 0, 0, "Gilneas City Guard"),

(44086, 0, 0, "You can't do this to us!", "You can't do this to us!", 12, 0, 33, 5, 0, 0, "Panicked Citizen"),
(44086, 0, 1, "My children are in Stormglen alone! I have to get to them!", "My children are in Stormglen alone! I have to get to them!", 12, 0, 33, 5, 0, 0, "Panicked Citizen"),
(44086, 0, 2, "What's going on? I thought I saw something on the rooftops.", "What's going on? I thought I saw something on the rooftops.", 12, 0, 33, 6, 0, 0, "Panicked Citizen"),
(44086, 0, 3, "We have to get out of here! The howling gets louder every night.", "We have to get out of here! The howling gets louder every night.", 12, 0, 33, 5, 0, 0, "Panicked Citizen"),
(44086, 0, 4, "They told us Gilneas City was safe...", "They told us Gilneas City was safe...", 12, 0, 33, 1, 0, 0, "Panicked Citizen");

DELETE FROM `creature` WHERE `guid` IN (219638, 219632, 219630, 219629);
DELETE FROM `creature_addon` WHERE `guid` IN (219638, 219632, 219630, 219629);
DELETE FROM `waypoint_data` WHERE `id` IN (219638, 219632, 219630, 219629);

UPDATE `creature` SET `position_x` = -1532.569702, `position_y` = 1324.009521, `position_z` = 35.861324, `orientation` = 0.838399, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 219640 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1482.562988, `position_y` = 1337.003784, `position_z` = 35.871769, `orientation` = 3.595148, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 219639 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1538.670299, `position_y` = 1381.714233, `position_z` = 36.004162, `orientation` = 6.104491, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 219633 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1559.391602, `position_y` = 1409.633057, `position_z` = 35.955856, `orientation` = 0.015523, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 221448 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1397.222900, `position_y` = 1402.700439, `position_z` = 35.960724, `orientation` = 1.985302, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 221447 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1396.093384, `position_y` = 1361.986572, `position_z` = 35.556969, `orientation` = 2.679593, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 221444 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1581.99939, `position_y` = 1361.849854, `position_z` = 35.99939, `orientation` = 2.079495, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 221441 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1510.293457, `position_y` = 1371.880249, `position_z` = 35.998672, `orientation` = 4.001499, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 221440 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1477.174072, `position_y` = 1379.595459, `position_z` = 36.0047, `orientation` = 2.410171, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 221439 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1524.065918, `position_y` = 1406.494263, `position_z` = 35.555931, `orientation` = 5.669565, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 221438 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1539.934204, `position_y` = 1440.324463, `position_z` = 35.976925, `orientation` = 3.941693, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 221437 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1515.657471, `position_y` = 1412.916016, `position_z` = 35.556549, `orientation` = 0.339493, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 221432 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1476.542114, `position_y` = 1439.608276, `position_z` = 35.961662, `orientation` = 4.066211, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 220188 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1429.768921, `position_y` = 1439.704102, `position_z` = 35.968613, `orientation` = 2.530758, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 220185 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1449.906982, `position_y` = 1369.512817, `position_z` = 35.603382, `orientation` = 5.28279, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 220183 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1471.026123, `position_y` = 1412.337646, `position_z` = 35.556248, `orientation` = 2.424378, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 220006 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1472.311523, `position_y` = 1407.288452, `position_z` = 35.566099, `orientation` = 3.574259, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 220005 AND `id` = 34851;

UPDATE `creature` SET `position_x` = -1502.160034, `position_y` = 1372.489990, `position_z` = 35.556000, `orientation` = 1.561972, `spawntimesecs` = 30, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 219989 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1421.198730, `position_y` = 1414.781616, `position_z` = 36.004940, `orientation` = 1.629003, `spawntimesecs` = 30, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 219986 AND `id` = 34851;
UPDATE `creature` SET `position_x` = -1529.618408, `position_y` = 1325.179199, `position_z` = 35.847145, `orientation` = 1.748103, `spawntimesecs` = 30, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 219985 AND `id` = 34851;
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` IN (221442, 221445) AND `id` = 34851;

DELETE FROM `creature_template_addon` WHERE `entry` = 34851;
DELETE FROM `creature_addon` WHERE `guid` IN (219989, 219986, 219985, 221442, 221445, 221448, 221447, 221444, 221441, 221440, 221439, 221438);
DELETE FROM `creature_addon` WHERE `guid` IN (221437, 221432, 220188, 220185, 220183, 220006, 219982, 219589, 219640, 219639, 219633, 220005);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(219989, 219989, 0, 1, 0, "52385"),
(219986, 219986, 0, 1, 0, "52385"),
(219985, 219985, 0, 1, 0, "52385"),
(221442, 221442, 0, 1, 0, "52385"),
(221445, 221445, 0, 1, 0, "52385"),

(221448, 0, 0, 1, 431, ""),
(221447, 0, 0, 1, 431, ""),
(221444, 0, 0, 1, 431, ""),
(221441, 0, 0, 1, 431, ""),
(221440, 0, 0, 1, 431, ""),
(221439, 0, 0, 1, 431, ""),
(221438, 0, 0, 1, 431, ""),
(221437, 0, 0, 1, 431, ""),
(221432, 0, 0, 1, 431, ""),
(220188, 0, 0, 1, 431, ""),
(220185, 0, 0, 1, 431, ""),
(220183, 0, 0, 1, 431, ""),
(220006, 0, 0, 1, 431, ""),
(219982, 0, 0, 1, 431, ""),
(219589, 0, 0, 1, 431, ""),
(219640, 0, 0, 1, 431, ""),
(219639, 0, 0, 1, 431, ""),
(219633, 0, 0, 1, 431, ""),
(220005, 0, 0, 1, 431, "");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 34851;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34851, -219989, -219986, -219985, -221448, -221447, -221444, -221441, -221440, -221439, -221438) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-221437, -221432, -220188, -220185, -220183, -220006, -219982, -219589, -219640, -219639, -219633, -220005) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-219989, 0, 0, 0, 34, 0, 100, 0, 2, 10, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Reach Point 10 - Despawn (2000 ms)"),
(-219989, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-219986, 0, 0, 0, 34, 0, 100, 0, 2, 6, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Reach Point 6 - Despawn (2000 ms)"),
(-219986, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-219985, 0, 0, 0, 34, 0, 100, 0, 2, 10, 0, 0, 41, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Reach Point 10 - Despawn (2000 ms)"),
(-219985, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-221448, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-221448, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-221447, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-221447, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-221444, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-221444, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-221441, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-221441, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-221440, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-221440, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-221439, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-221439, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-221438, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-221438, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-221437, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-221437, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-221432, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-221432, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-220188, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-220188, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-220185, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-220185, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-220183, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-220183, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-220006, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-220006, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-219982, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-219982, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-219589, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-219589, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-219640, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-219640, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-219639, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-219639, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-219633, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-219633, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1"),

(-220005, 0, 0, 0, 1, 0, 60, 0, 10000, 120000, 60000, 240000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Update - Say Text Line 0"),
(-220005, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Panicked Citizen - On Aggro - Say Text Line 1");

DELETE FROM `waypoint_data` WHERE `id` IN (219989, 219986, 219985, 221442, 221445);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `entry`) VALUES
(219989, 1, -1502.16, 1372.49, 35.556, 1.508, 0, 1, 34851),
(219989, 2, -1502.47, 1391.86, 35.556, 1.586, 0, 1, 34851),
(219989, 3, -1508.6, 1395.27, 35.556, 2.635, 0, 1, 34851),
(219989, 4, -1548.69, 1396.63, 35.556, 3.114, 0, 1, 34851),
(219989, 5, -1552.45, 1403.35, 35.556, 2.081, 0, 1, 34851),
(219989, 6, -1552.08, 1420.15, 35.556, 1.559, 0, 1, 34851),
(219989, 7, -1545.65, 1426.27, 35.556, 0.754, 0, 1, 34851),
(219989, 8, -1444.34, 1425.76, 35.556, 6.244, 0, 1, 34851),
(219989, 9, -1432.26, 1420.81, 35.556, 5.894, 0, 1, 34851),
(219989, 10, -1421.06, 1420.63, 35.556, 6.267, 0, 1, 34851),
(219989, 11, -1420.76, 1413.39, 36.519, 4.775, 4000, 1, 34851),

(219986, 1, -1441.17, 1427.62, 35.556, 3.228, 0, 1, 34851),
(219986, 2, -1544.72, 1426.79, 35.556, 3.142, 0, 1, 34851),
(219986, 3, -1551.93, 1422.04, 35.556, 3.754, 0, 1, 34851),
(219986, 4, -1553.96, 1369.56, 35.628, 4.701, 0, 1, 34851),
(219986, 5, -1556.84, 1365.27, 35.623, 4.049, 0, 1, 34851),
(219986, 6, -1583.88, 1364.09, 35.699, 3.22, 0, 1, 34851),
(219986, 7, -1583.53, 1359.91, 36.168, 4.795, 4000, 1, 34851),

(219985, 1, -1528.82, 1334.27, 35.557, 0.357, 0, 1, 34851),
(219985, 2, -1505.82, 1341.25, 35.557, 0.306, 0, 1, 34851),
(219985, 3, -1502.35, 1347.33, 35.557, 1.052, 0, 1, 34851),
(219985, 4, -1504.18, 1423.11, 35.557, 1.567, 0, 1, 34851),
(219985, 5, -1510.72, 1427.18, 35.557, 2.584, 0, 1, 34851),
(219985, 6, -1549.44, 1427.19, 35.557, 3.142, 0, 1, 34851),
(219985, 7, -1553.56, 1420.96, 35.557, 4.127, 0, 1, 34851),
(219985, 8, -1554.42, 1393.65, 35.576, 4.681, 0, 1, 34851),
(219985, 9, -1560.49, 1390.59, 35.758, 3.609, 0, 1, 34851),
(219985, 10, -1568.86, 1391.21, 36.199, 3.067, 0, 1, 34851),
(219985, 11, -1569.41, 1385.65, 36.578, 4.642, 4000, 1, 34851),

(221442, 1, -1557.69, 1332.67, 35.5567, 0, 0, 1, 34851),
(221442, 2, -1511.86, 1343.79, 35.5567, 0, 0, 1, 34851),
(221442, 3, -1502.91, 1353.88, 35.5567, 0, 0, 1, 34851),
(221442, 4, -1503.16, 1382.47, 35.5567, 0, 0, 1, 34851),
(221442, 5, -1497.24, 1393.37, 35.5567, 0, 0, 1, 34851),
(221442, 6, -1438.17, 1394.41, 35.5567, 0, 0, 1, 34851),
(221442, 7, -1435.39, 1419.84, 35.5567, 0, 0, 1, 34851),
(221442, 8, -1405.91, 1418.12, 35.5567, 0, 0, 1, 34851),
(221442, 9, -1402.8, 1390.08, 35.5567, 0, 0, 1, 34851),
(221442, 10, -1424.8, 1365.57, 35.5567, 0, 0, 1, 34851),
(221442, 11, -1517.5, 1337.497, 35.5567, 0, 0, 1, 34851),
(221442, 12, -1566.1, 1320.586, 35.5567, 0, 0, 1, 34851),

(221445, 1, -1553.72, 1391.36, 35.5714, 0, 0, 1, 34851),
(221445, 2, -1540.54, 1393.87, 35.5563, 0, 0, 1, 34851),
(221445, 3, -1522.59, 1394.47, 35.5563, 0, 0, 1, 34851),
(221445, 4, -1507.78, 1394.14, 35.5563, 0, 0, 1, 34851),
(221445, 5, -1501.33, 1401.19, 35.5563, 0, 0, 1, 34851),
(221445, 6, -1500.24, 1413.15, 35.5563, 0, 0, 1, 34851),
(221445, 7, -1495.03, 1424.15, 35.5563, 0, 0, 1, 34851),
(221445, 8, -1485.34, 1426.21, 35.5563, 0, 0, 1, 34851),
(221445, 9, -1457.24, 1426.59, 35.5563, 0, 0, 1, 34851),
(221445, 10, -1443.77, 1424.88, 35.5563, 0, 0, 1, 34851),
(221445, 11, -1437.21, 1418.57, 35.5563, 0, 0, 1, 34851),
(221445, 12, -1437.1, 1397.73, 35.5563, 0, 0, 1, 34851),
(221445, 13, -1442.47, 1373, 35.5563, 0, 0, 1, 34851),
(221445, 14, -1449.17, 1363.34, 35.5563, 0, 0, 1, 34851),
(221445, 15, -1474.46, 1350.9, 35.5563, 0, 0, 1, 34851),
(221445, 16, -1485.1, 1353.39, 35.5671, 0, 0, 1, 34851),
(221445, 17, -1498.15, 1349.15, 35.5563, 0, 0, 1, 34851),
(221445, 18, -1502.75, 1355.02, 35.5563, 0, 0, 1, 34851),
(221445, 19, -1503.81, 1385.74, 35.5563, 0, 0, 1, 34851),
(221445, 20, -1504.02, 1406.74, 35.5563, 0, 0, 1, 34851),
(221445, 21, -1509.41, 1418.46, 35.5563, 0, 0, 1, 34851),
(221445, 22, -1521.87, 1426.38, 35.5563, 0, 0, 1, 34851),
(221445, 23, -1542.9, 1426.84, 35.5563, 0, 0, 1, 34851),
(221445, 24, -1552.11, 1418.9, 35.5563, 0, 0, 1, 34851),
(221445, 25, -1553.31, 1390.12, 35.5692, 0, 0, 1, 34851),
(221445, 26, -1554.03, 1365.39, 35.5678, 0, 0, 1, 34851),
(221445, 27, -1554.34, 1343.59, 35.5567, 0, 0, 1, 34851),
(221445, 28, -1542.8, 1332.8, 35.5567, 0, 0, 1, 34851),
(221445, 29, -1513.19, 1337.98, 35.5567, 0, 0, 1, 34851),
(221445, 30, -1445.78, 1358.5, 35.5567, 0, 0, 1, 34851),
(221445, 31, -1415.59, 1365.53, 35.5567, 0, 0, 1, 34851),
(221445, 32, -1404.28, 1377.33, 35.5567, 0, 0, 1, 34851),
(221445, 33, -1403.22, 1405.88, 35.5567, 0, 0, 1, 34851),
(221445, 34, -1407.56, 1418.01, 35.5567, 0, 0, 1, 34851),
(221445, 35, -1436.94, 1421.79, 35.5567, 0, 0, 1, 34851),
(221445, 36, -1471.4, 1424.21, 35.5567, 0, 0, 1, 34851),
(221445, 37, -1511.17, 1424.79, 35.5567, 0, 0, 1, 34851),
(221445, 38, -1542.08, 1424.6, 35.5567, 0, 0, 1, 34851),
(221445, 39, -1550.87, 1418.47, 35.5567, 0, 0, 1, 34851),
(221445, 40, -1554.48, 1394.58, 35.5781, 0, 0, 1, 34851),
(221445, 41, -1572.96, 1393.06, 36.4174, 0, 0, 1, 34851),
(221445, 42, -1567.68, 1390.9, 36.1181, 0, 0, 1, 34851);

DELETE FROM `creature_text` WHERE `entry` = 34851;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34851, 0, 0, "What... what are those things on the rooftops?", "What... what are those things on the rooftops?", 12, 0, 50, 6, 0, 0, "Panicked Citizen"),
(34851, 0, 1, "Somebody save me!", "Somebody save me!", 12, 0, 50, 22, 0, 0, "Panicked Citizen"),
(34851, 0, 2, "Spare my life! I will leave this place forever! Please!", "Spare my life! I will leave this place forever! Please!", 12, 0, 50, 22, 0, 0, "Panicked Citizen"),
(34851, 0, 3, "You make my children orphans on this day, friend!", "You make my children orphans on this day, friend!", 12, 0, 50, 22, 0, 0, "Panicked Citizen"),
(34851, 0, 4, "The... They promised that we'd be safe...", "The... They promised that we'd be safe...", 12, 0, 50, 1, 0, 0, "Panicked Citizen"),
(34851, 0, 5, "I'm too young to die!", "I'm too young to die!", 12, 0, 50, 22, 0, 0, "Panicked Citizen"),
(34851, 0, 6, "Ask for anything and you shall have it! Just spare my life!", "Ask for anything and you shall have it! Just spare my life!", 12, 0, 50, 22, 0, 0, "Panicked Citizen"),
(34851, 0, 7, "HELP! HELP!", "HELP! HELP!", 12, 0, 50, 22, 0, 0, "Panicked Citizen"),
(34851, 1, 0, "I won't go down that easy!", "I won't go down that easy!", 12, 0, 50, 0, 0, 0, "Panicked Citizen"),
(34851, 1, 1, "Die Scourge dog! DIE!", "Die Scourge dog! DIE!", 12, 0, 50, 0, 0, 0, "Panicked Citizen"),
(34851, 1, 2, "Is this the best the Scourge can do?", "Is this the best the Scourge can do?", 12, 0, 50, 0, 0, 0, "Panicked Citizen"),
(34851, 1, 3, "You may take my life, but you won't take my freedom!", "You may take my life, but you won't take my freedom!", 12, 0, 50, 0, 0, 0, "Panicked Citizen"),
(34851, 1, 4, "DIE!", "DIE!", 12, 0, 50, 0, 0, 0, "Panicked Citizen"),
(34851, 1, 5, "You're not taking me without a fight!", "You're not taking me without a fight!", 12, 0, 50, 0, 0, 0, "Panicked Citizen");

UPDATE `creature_template` SET `ScriptName` = "npc_prince_liam_greymane" WHERE `entry` = 34850;

DELETE FROM `creature_text` WHERE `entry` = 34850;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(34850, 0, 0, "Stand ready, guards! We don't know how many intruders we're dealing with, but the Headlands are overrun and we're cut off from the harbor towns. Expect to be outnumbered.", "", 12, 0, 100, 0, 0, 19614, "Prince Liam Greymane"),
(34850, 1, 0, "I want the perimeter secured and the gates manned by two guards at all times. No one gets in, no one gets out.", "", 12, 0, 100, 0, 0, 19615, "Prince Liam Greymane"),
(34850, 2, 0, "We protected Gilneas from the Scourge. We protected Gilneas during the Northgate rebellion. We will protect Gilneas from whatever this new threat may be.", "", 12, 0, 100, 0, 0, 19616, "Prince Liam Greymane");

UPDATE `creature` SET `movement_type` = 1, `wander_distance` = 35, `walk_mode` = 2 WHERE `id` = 4075 AND `map` = 654;
DELETE FROM `creature_addon` WHERE `guid` IN (220889, 219624, 219825, 219675);
DELETE FROM `waypoint_data` WHERE `id` IN (220889, 219624, 219825, 219675);

UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` = 35383;
DELETE FROM `creature_template_addon` WHERE `entry` IN (35383, 44105);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, auras) VALUES
(35383, 8, 1, ""),
(44105, 0, 1, "29266");

UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (219625, 220183, 220188, 219589, 219982, 220185, 221422, 221415,
                                                                                  221417, 220867, 221418, 221416, 221421, 221419, 221420, 219626,
                                                                                  220577, 220576, 220886, 220575, 219704, 219701, 219705, 219702,
                                                                                  220887, 220473, 219703, 221459, 221452, 221454, 221453, 221458,
                                                                                  221456, 221457, 221460, 221455, 221217, 221210, 221215, 220534,
                                                                                  221211, 220537, 221209, 221213, 220530, 220532, 220535, 221212,
                                                                                  220531, 221214, 220529, 220536, 220533, 371594, 371595);

UPDATE `creature` SET `position_z` = 41.023338 WHERE `guid` = 219626;
UPDATE `creature` SET `position_x` = -1534.185547, `position_y` = 1381.463623, `position_z` = 37.730263, `orientation` = 5.899164 WHERE `guid` = 220575;
UPDATE `creature` SET `position_z` = 36.7 WHERE `guid` = 219702;
UPDATE `creature` SET `position_z` = 36.8 WHERE `guid` = 219704;
UPDATE `creature` SET `position_z` = 36.7 WHERE `guid` = 219703;

UPDATE `creature` SET `phaseMask` = 262144 WHERE `guid` IN (222878, 222875, 222290, 222275, 222858, 222331, 222323, 222325, 222333, 222326,
                                                            222334, 222332, 222320, 222319, 222344, 222293, 222350, 222292, 222353, 222297,
                                                            222349, 222356, 222295, 222296, 222298, 222808, 222810, 222805, 222889, 222895,
                                                            222893, 222896, 222891, 222903, 222907, 222899, 222886, 222908, 222892, 222336,
                                                            222961, 222957, 222956, 222972, 222978, 222975, 222977, 222971, 222976, 222965,
                                                            222964);
UPDATE `creature` SET `phaseMask` = 4 WHERE `guid` IN (371579, 221541, 221544, 221542, 221539, 221536, 221537, 221195);
UPDATE `creature` SET `phaseMask` = 8 WHERE `guid` IN (221591, 221584, 221586, 221577, 371594, 371595);

DELETE FROM `creature` WHERE `guid` = 220012;
DELETE FROM `creature_addon` WHERE `guid` = 220012;
DELETE FROM `waypoint_data` WHERE `id` = 220012;

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 34884;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 34884 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(34884, 0, 0, 1, 2, 0, 100, 1, 0, 10, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Rampaging Worgen - At 10% HP - Cast Spell 'Enrage'"),
(34884, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Rampaging Worgen - At 10% HP (Link) - Say Text Line 0");

UPDATE `creature` SET `movement_type` = 1, `wander_distance` = 25, `walk_mode` = 2 WHERE `id` = 34884 AND NOT `guid` IN (221068, 221483, 221435, 221424, 221472);
UPDATE `creature` SET `movement_type` = 1, `wander_distance` = 10 WHERE `id` = 34916;
UPDATE `creature` SET `movement_type` = 1, `wander_distance` = 3 WHERE `guid` = 221472;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 195327 AND `source_type` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (34981, 35836, 35660) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1953270, 1953271, 3566000) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(195327, 1, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 87, 1953270, 1953271, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Merchant Square Door - Start Random Script"),

(34981, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frightened Citizen - On Just Summoned - Set Run On"),
(34981, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 19, 35830, 10, 0, 0, 0, 0, 0, "Frightened Citizen - On Just Summoned (Link) - Move To Position (1)"),
(34981, 0, 2, 0, 34, 0, 100, 0, 0, 1, 0, 0, 1, 0, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frightened Citizen - MI 1 - Say Text Line 0 (2000 ms duration)"),
(34981, 0, 3, 0, 52, 0, 100, 0, 0, 34981, 0, 0, 69, 2, 0, 0, 0, 0, 0, 19, 35010, 20, 0, 0, 0, 0, 0, "Frightened Citizen - On Text 0 Over - Move To Position (2)"),
(34981, 0, 4, 0, 34, 0, 100, 0, 0, 2, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frightened Citizen - MI 2 - Despawn (1000 ms)"),

(35836, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frightened Citizen - On Just Summoned - Set Run On"),
(35836, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 19, 35830, 10, 0, 0, 0, 0, 0, "Frightened Citizen - On Just Summoned (Link) - Move To Position (1)"),
(35836, 0, 2, 0, 34, 0, 100, 0, 0, 1, 0, 0, 1, 0, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frightened Citizen - MI 1 - Say Text Line 0 (2000 ms duration)"),
(35836, 0, 3, 0, 52, 0, 100, 0, 0, 35836, 0, 0, 69, 2, 0, 0, 0, 0, 0, 19, 35010, 20, 0, 0, 0, 0, 0, "Frightened Citizen - On Text 0 Over - Move To Position (2)"),
(35836, 0, 4, 0, 34, 0, 100, 0, 0, 2, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Frightened Citizen - MI 2 - Despawn (1000 ms)"),

(35660, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 3566000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Rampaging Worgen - On Just Summoned - Start Script"),

(1953270, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 85, 68087, 64, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Merchant Square Door - Summon Frightened Citizen"),
(1953270, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 33, 35830, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Merchant Square Door - Add Kill Credit"),

(1953271, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 85, 68070, 64, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Merchant Square Door - Summon Frightened Citizen and Rampaging Worgen"),
(1953271, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 33, 35830, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Merchant Square Door - Add Kill Credit"),

(3566000, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Rampaging Worgen - On Script - Start Attack Invoker");

UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` IN (35872, 35839);
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` IN (35840, 35872, 35873, 35869);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35840, 35872, 35873, 35869) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(35840, 0, 0, 0, 1, 0, 100, 0, 5000, 5000, 60000, 60000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gwen Armstead - OOC - Say Text Line 0"),

(35872, 0, 0, 0, 0, 0, 100, 0, 1000, 5000, 1000, 5000, 11, 11538, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, "Myriam Spellwaker - In Combat  - Cast Spell 'Frostbolt'"),
(35872, 0, 1, 0, 0, 0, 100, 0, 22000, 22000, 22000, 22000, 11, 81165, 1, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, "Myriam Spellwaker - In Combat - Cast Spell 'Blizzard'"),

(35873, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 0, 0, 11, 13236, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Celestine of the Harvest - OOC - Cast Spell 'Nature Channeling'"),

(35869, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 0, 0, 11, 44163, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vitus Darkwalker - OOC - Cast Spell 'Summon Imp'"),
(35869, 0, 1, 0, 1, 0, 100, 0, 25000, 25000, 0, 0, 11, 45104, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vitus Darkwalker - OOC - Cast Spell 'Shadow Channelling'");

DELETE FROM `creature_text` WHERE `entry` = 35840;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `text_range`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35840, 0, 0, "", "We must stick together to survive. Move around in groups.", 0, 12, 0, 100, 1, 0, 0, "Gwen Armstead"),
(35840, 0, 1, "", "The plan is to keep moving south. We can't go back to the Merchant Square. It's not safe.", 0, 12, 0, 100, 1, 0, 0, "Gwen Armstead"),
(35840, 0, 2, "", "The king's men will protect us. We're almost there.", 0, 12, 0, 100, 1, 0, 0, "Gwen Armstead");

UPDATE `creature_template` SET `RegenHealth` = 0 WHERE `entry` IN (47091, 35912);
UPDATE `creature` SET `curhealth` = 950 WHERE `id` = 47091;
UPDATE `creature` SET `curhealth` = 58 WHERE `id` = 35912;
UPDATE `creature` SET `wander_distance` = 10, `movement_type` = 1, `walk_mode` = 2 WHERE `id` = 35118;
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (220052, 219748, 219745, 220051, 220049, 220046, 220206, 220210, 220203, 220299,
                                                                                  220053, 219753, 220211);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 35118 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(35118, 0, 0, 1, 2, 0, 100, 1, 0, 30, 0, 0, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodfang Worgen - At 30% HP - Cast Spell 'Enrage'"),
(35118, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bloodfang Worgen - At 30% HP (Link) - Say Text Line 0"),
(35118, 0, 2, 0, 8, 0, 100, 1, 100, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Bloodfang Worgen - On Spellhit - Give Quest Credit"),
(35118, 0, 3, 0, 8, 0, 100, 1, 56641, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Bloodfang Worgen - On Spellhit - Give Quest Credit"),
(35118, 0, 4, 0, 8, 0, 100, 1, 2098, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Bloodfang Worgen - On Spellhit - Give Quest Credit"),
(35118, 0, 5, 0, 8, 0, 100, 1, 122, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Bloodfang Worgen - On Spellhit - Give Quest Credit"),
(35118, 0, 6, 0, 8, 0, 100, 1, 172, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Bloodfang Worgen - On Spellhit - Give Quest Credit"),
(35118, 0, 7, 0, 8, 0, 100, 1, 589, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Bloodfang Worgen - On Spellhit - Give Quest Credit"),
(35118, 0, 8, 0, 8, 0, 100, 1, 8921, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Bloodfang Worgen - On Spellhit - Give Quest Credit"),
(35118, 0, 9, 0, 25, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 35232, 35, 0, 0, 0, 0, 0, "Bloodfang Worgen - On Reset - Start Attack (Creature ID: 35232, 35 Yards)"),
(35118, 0, 10, 0, 1, 0, 100, 0, 10000, 10000, 10000, 10000, 49, 0, 0, 0, 0, 0, 0, 19, 35232, 35, 0, 0, 0, 0, 0, "Bloodfang Worgen - OOC (10000 - 10000) - Start Attack (Creature ID: 35232, 35 Yards)");

DELETE FROM `creature` WHERE `guid` = 221517;
DELETE FROM `creature_addon` WHERE `guid` = 221517;

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (35112, 35115);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35112 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35112*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(35112, 0, 0, 0, 19, 0, 100, 0, 14157, 0, 0, 0, 80, 35112*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "King Genn Greymane - On Quest (14157) Accept - Start Script"),

(35112*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "King Genn Greymane - On Script - Remove Npc Flag Quest Giver"),
(35112*100, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 35115, 30, 0, 0, 0, 0, 0, "King Genn Greymane - On Script - Say Text Line 0 (Creature ID: 35115, 30 Yards)"),
(35112*100, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "King Genn Greymane - On Script - Say Text Line 0"),
(35112*100, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "King Genn Greymane - On Script - Add Npc Flag Quest Giver");

DELETE FROM `creature_text` WHERE `entry` IN (35112, 35115);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `text_range`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35112, 0, 0, "Enough! I've made up my mind. We need Crowley on our side.", "", 0, 12, 0, 100, 0, 0, 0, ""),

(35115, 0, 0, "We ought to leave Crowley in prison with those beasts!", "", 0, 12, 0, 100, 0, 0, 0, "");

DELETE FROM `creature_template` WHERE `entry` = 3871204;

DELETE FROM `disables` WHERE `entry` IN (35170, 35167, 35456, 35188) AND `sourceType` = 10;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(10, 35170, 1, "", "", "Worgen Alpha - MMAP"),
(10, 35167, 1, "", "", "Worgen Alpha - MMAP"),
(10, 35456, 1, "", "", "Worgen Runt - MMAP"),
(10, 35188, 1, "", "", "Worgen Runt - MMAP");

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "", `mindmg` = 28, `maxdmg` = 46, `attackpower` = 12, `dmg_multiplier` = 1 WHERE `entry` = 35077;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "" WHERE `entry` = 35081;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35077, 3871204, 35170, 35188, 35456, 35167) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3507700, 3507701, 3507702, 1415400, 1415402) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(35077, 0, 0, 0, 19, 0, 100, 0, 14154, 0, 0, 0, 11, 66914, 2, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lord Darius Crowley - On Quest (14154) Accept - Cast Spell 'Gilneas - Quest - Gilneas Prison Periodic Forcecast'"),
(35077, 0, 1, 0, 37, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Lord Darius Crowley - On AI Init - Disable Combat Movement"),
(35077, 0, 2, 0, 0, 0, 100, 0, 6000, 6000, 15000, 17000, 207, 67825, 61044, 67827, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Lord Darius Crowley - In Combat - Cast Random Spell (Left Hook, Demoralizing Shout, Snap Kick)");

DELETE FROM `waypoints` WHERE `entry` IN (3517000, 3516700);

DELETE FROM `spell_script_names` WHERE `spell_id` = 66853;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(66853, "spell_gen_gilneas_prison_periodic_dummy");

DELETE FROM `spell_target_position` WHERE `id` IN (66925, 66836);
INSERT INTO `spell_target_position` (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`) VALUES
(66925, 0, 654, -1636.292, 1481.836, 70.94804),
(66836, 0, 654, -1620.981, 1509.193, 67.10413);

UPDATE `creature_template` SET `AIName` = "", `ScriptName`= "npc_worgen_runt", `flags_extra` = 64, `MovementType` = 0 WHERE `entry` IN (35456, 35188, 35167, 35170);

UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (219662, 219664);
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_josiah_avery" WHERE `entry` = 35369;
UPDATE `creature_template` SET `unit_flags` = 33024, `AIName` = "", `ScriptName` = "npc_josiah_avery_worgen_form" WHERE `entry` = 35370;

UPDATE `creature_template` SET `AIName` = "SmartAI", `flags_extra` = 128 WHERE `entry` = 50415;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 50415 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(50415, 0, 1, 0, 1, 0, 100, 1, 800, 800, 0, 0, 1, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Josiah Event Trigger - OOC - Say Text Line 0 (No Repeat)");

DELETE FROM `creature_text` WHERE `entry` IN (50415, 35369);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(50415, 0, 0, "You've been bitten by a worgen. It's probably nothing, but it sure stings a little.$B$B|TInterface\\Icons\\INV_Misc_monsterfang_02.blp:32|t", "You've been bitten by a worgen. It's probably nothing, but it sure stings a little.$B$B|TInterface\\Icons\\INV_Misc_monsterfang_02.blp:32|t", 42, 0, 100, 0, 0, 0, "Josiah Event Trigger"),

(35369, 0, 0, "What's wrong with me??!", "", 14, 0, 100, 0, 0, 0, "Josiah Avery"),
(35369, 1, 0, "My face! What's wrong with my face!", "", 14, 0, 100, 0, 0, 0, "Josiah Avery"),
(35369, 2, 0, "My hands... don't look at my hands!", "", 14, 0, 100, 0, 0, 0, "Josiah Avery"),
(35369, 3, 0, "The pain is unbearable!", "", 14, 0, 100, 0, 0, 0, "Josiah Avery"),
(35369, 4, 0, "Make it stop!", "", 14, 0, 100, 0, 0, 0, "Josiah Avery"),
(35369, 5, 0, "I can't fight it!", "", 14, 0, 100, 0, 0, 0, "Josiah Avery");

DELETE FROM `conditions` WHERE `SourceEntry`= 67350 AND `SourceTypeOrReferenceId`= 13;
INSERT INTO conditions (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 67350, 0, 0, 31, 0, 3, 35374, 0, 0, 0, "", "Summon Josiah - Target Lab Trigger"),
(13, 4, 67350, 0, 0, 31, 0, 3, 35374, 0, 0, 0, "", "Summon Josiah - Target Lab Trigger");

DELETE FROM `spell_script_names` WHERE `spell_id` = 67357;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(67357, "spell_gilneas_pull_to");

DELETE FROM `world_map_template` WHERE `mapID` = 654;
INSERT INTO `world_map_template` (`mapID`, `ScriptName`) VALUES
(654, "world_map_gilneas");

UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (221134, 221132, 221131, 221135, 221133, 220259, 220570, 220571, 220569, 220568,
                                                                                  220488, 220490, 220489, 220492, 220491);

UPDATE `creature` SET `wander_distance` = 15, `movement_type` = 1 WHERE `id` = 35463;
DELETE FROM `creature_template_addon` WHERE `entry` = 35463;
DELETE FROM `creature_addon` WHERE `guid` IN (221071, 221163, 221305, 221314, 221318, 221319, 221326, 221339);
DELETE FROM `waypoint_data` WHERE `id` IN (221163, 221326);

UPDATE `quest_template` SET `flags` = 0 WHERE `Id` = 14204;

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_lorna_crowley_basement" WHERE `entry` = 35378;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_gilnean_mastiff" WHERE `entry` = 35631;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_bloodfang_lurker" WHERE `entry` = 35463;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35378, 35631, 35463) AND `source_type` = 0;

UPDATE `creature` SET `spawntimesecs` = 50 WHERE `id` = 35463;

DELETE FROM `spell_script_names` WHERE `spell_id` = 67805;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(67805, "spell_attack_lurker");

DELETE FROM `creature_text` WHERE `entry` = 35378;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(35378,0,0,"","This mastiff will help you find the hidden worgen.",12,0,100,0,0,19696,"Lorna Crowley");

UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (221718, 221717, 221348, 221716, 221352, 219776, 221137, 221141, 221139, 221140, 221138,
                                                                                  219357, 219356, 219360, 219359, 219358, 219362);
DELETE FROM `creature_addon` WHERE `guid` IN (221718, 221717, 221348, 221716, 221352);

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_james" WHERE `entry` = 36289;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_ashley" WHERE `entry` = 36288;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_cynthia" WHERE `entry` = 36287;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (36287, 36288, 36289) AND `source_type` = 0;

DELETE FROM `creature_text` WHERE `entry` IN (36287, 36288, 36289);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36287, 0, 0, "", "You are scary! I just want my mommy!", 12, 0, 100, 0, 0, 0, "Cynthia"),

(36288, 0, 0, "", "Are you one of the good worgen, $gmister:miss;? Did you see Cynthia hiding in the sheds outside?", 12, 0, 100, 0, 0, 0, "Ashley"),

(36289, 0, 0, "Don't hurt me! I was just looking for my sisters! I think Ashley's inside that house!", "", 12, 0, 100, 0, 0, 0, "James");

UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (221337, 221334, 221338, 221335, 221336);
UPDATE `creature` SET `phaseMask` = 4096 WHERE `guid` IN (219834, 219266, 220087, 220956, 220611, 219827, 219830);

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_chance_the_cat" WHERE `entry` = 36459;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 36459 AND `source_type` = 0;

DELETE FROM `creature` WHERE `guid` = 221857 AND `id` = 36461;
DELETE FROM `creature_addon` WHERE `guid` = 221857;
DELETE FROM `waypoint_data` WHERE `id` = 221857;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_lucius_the_cruel" WHERE `entry` = 36461;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_wahl" WHERE `entry` = 36458;

DELETE FROM `creature_text` WHERE `entry` IN (36458, 36461);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36458, 0, 0, "", "You do not mess with my kitty you son of a mongrel!", 14, 0, 100, 0, 0, 0, "Grandma Wahl"),

(36461, 0, 0, "I'll be taking this cat. It seems to work as the perfect bait. Prepare to die now, fool!", "", 12, 0, 100, 0, 0, 0, "Lucius the Cruel");

UPDATE `npc_spellclick_spells` SET `spell_id` = 68743 WHERE `npc_entry` = 36459;

DELETE FROM `conditions` WHERE `SourceGroup` = 36459 AND `SourceEntry` = 68743 AND `SourceTypeOrReferenceId` = 18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 36459, 68743, 0, 0, 9, 0, 14401, 0, 0, 0, 0, 0, "", "Requires Grandma's Cat (14401) to enable spellclick");

UPDATE `creature` SET `position_x` = -1946.13, `position_y` = 2319.27, `position_z` = 34.764, `orientation` = 0.779048 WHERE `guid` = 219258;
UPDATE `creature` SET `position_x` = -2194.74, `position_y` = 2291.96, `position_z` = 7.86472, `orientation` = 5.22015, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 219259;
UPDATE `creature` SET `position_x` = -1946.13, `position_y` = 2319.27, `position_z` = 34.764, `orientation` = 0.779048 WHERE `guid` = 219261;
UPDATE `creature` SET `position_x` = -1934.46, `position_y` = 2199.65, `position_z` = 29.0159, `orientation` = 1.60207, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 219260;

DELETE FROM `creature_addon` WHERE `guid` IN (219259, 219260);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(219259, 219259, 1),
(219260, 219260, 1);

DELETE FROM `waypoint_data` WHERE `id` IN (219258, 219259, 219261, 219260);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `entry`) VALUES
(219258, 1, -1946.13, 2319.27, 34.764, 0, 0, 0, 36602),
(219258, 2, -1943.36, 2333.33, 34.2645, 0, 0, 0, 36602),
(219258, 3, -1937.3, 2351.05, 32.6701, 0, 0, 0, 36602),
(219258, 4, -1946.13, 2319.27, 34.764, 0, 0, 0, 36602),
(219258, 5, -1947.47, 2314.47, 34.9573, 0, 0, 0, 36602),
(219258, 6, -1953.24, 2308.77, 34.6878, 0, 0, 0, 36602),
(219258, 7, -1970.98, 2317.91, 31.417, 0, 0, 0, 36602),
(219258, 8, -1988.58, 2321.61, 28.8536, 0, 0, 0, 36602),
(219258, 9, -1976.99, 2319.98, 30.4746, 0, 0, 0, 36602),
(219258, 10, -1953.94, 2308.57, 34.6036, 0, 0, 0, 36602),
(219258, 11, -1951.42, 2302.77, 35.6365, 0, 0, 0, 36602),
(219258, 12, -1947.42, 2291.99, 37.5909, 0, 0, 0, 36602),
(219258, 13, -1939.96, 2282.71, 40.2249, 0, 0, 0, 36602),
(219258, 14, -1947.42, 2291.99, 37.5909, 0, 0, 0, 36602),
(219258, 15, -1951.42, 2302.77, 35.6365, 0, 0, 0, 36602),
(219258, 16, -1953.94, 2308.57, 34.6036, 0, 0, 0, 36602),
(219258, 17, -1970.98, 2317.91, 31.417, 0, 0, 0, 36602),
(219258, 18, -1988.58, 2321.61, 28.8536, 0, 0, 0, 36602),
(219258, 19, -1976.99, 2319.98, 30.4746, 0, 0, 0, 36602),
(219258, 20, -1953.94, 2308.57, 34.6036, 0, 0, 0, 36602),
(219258, 21, -1947.47, 2314.47, 34.9573, 0, 0, 0, 36602),

(219259, 1, -2194.74, 2291.96, 7.86472, 0, 0, 0, 36602),
(219259, 2, -2225, 2293.23, 7.51818, 0, 0, 0, 36602),
(219259, 3, -2232.03, 2295.97, 6.48644, 0, 0, 0, 36602),
(219259, 4, -2245.83, 2301.55, 5.61336, 0, 0, 0, 36602),
(219259, 5, -2257.27, 2307.66, 5.42611, 0, 0, 0, 36602),
(219259, 6, -2278.81, 2327.27, 5.52903, 0, 0, 0, 36602),
(219259, 7, -2290.64, 2331.92, 4.69442, 0, 0, 0, 36602),
(219259, 8, -2301.13, 2326.5, 2.86899, 0, 0, 0, 36602),
(219259, 9, -2309.08, 2318.42, 1.04832, 0, 0, 0, 36602),
(219259, 10, -2301.13, 2326.5, 2.86899, 0, 0, 0, 36602),
(219259, 11, -2290.64, 2331.92, 4.69442, 0, 0, 0, 36602),
(219259, 12, -2279.01, 2327.25, 5.52866, 0, 0, 0, 36602),
(219259, 13, -2257.27, 2307.66, 5.42611, 0, 0, 0, 36602),
(219259, 14, -2245.83, 2301.55, 5.61336, 0, 0, 0, 36602),
(219259, 15, -2232.03, 2295.97, 6.48644, 0, 0, 0, 36602),
(219259, 16, -2225.65, 2293.5, 7.47082, 0, 0, 0, 36602),
(219259, 17, -2194.74, 2291.96, 7.86472, 0, 0, 0, 36602),
(219259, 18, -2184.19, 2289.77, 8.69968, 0, 0, 0, 36602),
(219259, 19, -2175.34, 2287.26, 9.31882, 0, 0, 0, 36602),
(219259, 20, -2169.41, 2287.52, 9.78354, 0, 0, 0, 36602),
(219259, 21, -2165.29, 2288.32, 10.1982, 0, 0, 0, 36602),
(219259, 22, -2165.4, 2294.28, 9.74281, 0, 0, 0, 36602),
(219259, 23, -2173.53, 2309.68, 7.47034, 0, 0, 0, 36602),
(219259, 24, -2184.58, 2325.38, 4.58081, 0, 0, 0, 36602),
(219259, 25, -2193.46, 2341.36, 2.92241, 0, 0, 0, 36602),
(219259, 26, -2195.5, 2358.37, 1.42241, 0, 0, 0, 36602),
(219259, 27, -2193.56, 2379.19, 1.99852, 0, 0, 0, 36602),
(219259, 28, -2182.62, 2393.88, 5.18236, 0, 0, 0, 36602),
(219259, 29, -2168.69, 2405.68, 10.5982, 0, 0, 0, 36602),
(219259, 30, -2182.62, 2393.88, 5.18236, 0, 0, 0, 36602),
(219259, 31, -2193.56, 2379.19, 1.99852, 0, 0, 0, 36602),
(219259, 32, -2195.5, 2358.37, 1.42241, 0, 0, 0, 36602),
(219259, 33, -2193.46, 2341.36, 2.92241, 0, 0, 0, 36602),
(219259, 34, -2184.58, 2325.38, 4.58081, 0, 0, 0, 36602),
(219259, 35, -2173.53, 2309.68, 7.47034, 0, 0, 0, 36602),
(219259, 36, -2165.4, 2294.28, 9.74281, 0, 0, 0, 36602),
(219259, 37, -2165.29, 2288.32, 10.1982, 0, 0, 0, 36602),
(219259, 38, -2169.41, 2287.52, 9.78354, 0, 0, 0, 36602),
(219259, 39, -2175.34, 2287.26, 9.31882, 0, 0, 0, 36602),
(219259, 40, -2184.19, 2289.77, 8.69968, 0, 0, 0, 36602),

(219261, 1, -2091.12, 2395.45, 9.13009, 0, 0, 0, 36602),
(219261, 2, -2101.68, 2395.78, 9.61884, 0, 0, 0, 36602),
(219261, 3, -2113.67, 2397.95, 11.1188, 0, 0, 0, 36602),
(219261, 4, -2101.68, 2395.78, 9.61884, 0, 0, 0, 36602),
(219261, 5, -2091.12, 2395.45, 9.13009, 0, 0, 0, 36602),
(219261, 6, -2079.68, 2398.89, 9.38009, 0, 0, 0, 36602),
(219261, 7, -2066.56, 2403.74, 10.715, 0, 0, 0, 36602),
(219261, 8, -2053.12, 2405.69, 12.2026, 0, 0, 0, 36602),
(219261, 9, -2038.36, 2405.06, 13.8047, 0, 0, 0, 36602),
(219261, 10, -2027.08, 2403, 15.0313, 0, 0, 0, 36602),
(219261, 11, -2010.54, 2395.88, 18.1813, 0, 0, 0, 36602),
(219261, 12, -1996.84, 2393.72, 20.5438, 0, 0, 0, 36602),
(219261, 13, -1982.08, 2389.58, 23.7782, 0, 0, 0, 36602),
(219261, 14, -1996.84, 2393.72, 20.5438, 0, 0, 0, 36602),
(219261, 15, -2010.54, 2395.88, 18.1813, 0, 0, 0, 36602),
(219261, 16, -2027.08, 2403, 15.0313, 0, 0, 0, 36602),
(219261, 17, -2038.36, 2405.06, 13.8047, 0, 0, 0, 36602),
(219261, 18, -2053.12, 2405.69, 12.2026, 0, 0, 0, 36602),
(219261, 19, -2066.56, 2403.74, 10.715, 0, 0, 0, 36602),
(219261, 20, -2079.68, 2398.89, 9.38009, 0, 0, 0, 36602),

(219260, 1, -1934.46, 2199.65, 29.0159, 0, 0, 0, 36602),
(219260, 2, -1935.22, 2212.2, 32.5693, 0, 0, 0, 36602),
(219260, 3, -1931.17, 2222.35, 35.4786, 0, 0, 0, 36602),
(219260, 4, -1920.16, 2233.92, 39.2201, 0, 0, 0, 36602),
(219260, 5, -1911.75, 2242.19, 41.9652, 0, 0, 0, 36602),
(219260, 6, -1920.16, 2233.92, 39.2201, 0, 0, 0, 36602),
(219260, 7, -1931.17, 2222.35, 35.4786, 0, 0, 0, 36602),
(219260, 8, -1935.22, 2212.2, 32.5693, 0, 0, 0, 36602);

UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (221827, 221824, 221825, 221822, 221826, 221820, 221821, 221828, 221823);
DELETE FROM `creature` WHERE `guid` IN (371554, 371564, 371569, 371573, 371581, 371583, 371592, 371593, 371604, 371615, 371618, 371639) AND `id` = 36555;
DELETE FROM `creature_addon` WHERE `guid` IN (371554, 371564, 371569, 371573, 371581, 371583, 371592, 371593, 371604, 371615, 371618, 371639);
UPDATE `creature` SET `phaseMask` = 16384, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 219766 AND `id` = 36528;

DELETE FROM `creature_addon` WHERE `guid` = 219766;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(219766, 219766, 4097);

DELETE FROM `waypoint_data` WHERE `id` = 219766;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `entry`) VALUES
(219766, 1, -2191.43, 2210.01, 16.8541, 0, 0, 0, 36528),
(219766, 2, -2192.77, 2240.55, 10.3578, 0, 0, 0, 36528),
(219766, 3, -2191.43, 2210.01, 16.8541, 0, 0, 0, 36528),
(219766, 4, -2180.43, 2185.91, 17.1765, 0, 0, 0, 36528),
(219766, 5, -2143.8, 2179.52, 21.9216, 0, 0, 0, 36528),
(219766, 6, -2180.43, 2185.91, 17.1765, 0, 0, 0, 36528);

UPDATE `creature_template` SET `npcflag` = 1, `spell1` = 68903, `AIName` = "", `ScriptName` = "npc_mountain_horse" WHERE `entry` = 36540;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 36540 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 36540*100 AND `source_type` = 9;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.71429, `AIName` = "", `ScriptName` = "npc_mountain_horse_summoned" WHERE `entry` = 36555;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 36540;

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

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_king_genn_greymane" WHERE `entry` = 35550;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35550 AND `source_type` = 0;

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_vehicle_genn_horse" WHERE `entry` = 35905;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35905 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35905*100 AND `source_type` = 9;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 35905;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(35905, 63151, 1, 0);

DELETE FROM `waypoints` WHERE `entry` = 35905;

DELETE FROM `creature` WHERE `guid` = 371579;
DELETE FROM `creature_addon` WHERE `guid` = 371579;

DELETE FROM `creature_text` WHERE `entry` IN (35550, 35753, 35907, 35905);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35550, 0, 0, "Fire!", "", 14, 0, 100, 0, 0, 19710, "King Genn Greymane"),
(35550, 0, 1, "Hold the barricades!  Do not give them an inch!", "", 14, 0, 100, 0, 0, 19709, "King Genn Greymane"),
(35550, 0, 2, "Keep them back!", "", 14, 0, 100, 0, 0, 19712, "King Genn Greymane"),

(35753, 0, 0, "Help! Up here!", "", 14, 0, 100, 1, 0, 20921, "Krennan Aranas"),

(35907, 0, 0, "Keep them back!", "", 12, 0, 100, 1, 0, 20922, "Krennan Aranas"),

(35905, 0, 0, "Rescue Krennan Aranas by using your vehicle's ability.$B|TInterface\Icons\inv_misc_groupneedmore.blp:64|t", "Rescue Krennan Aranas by using your vehicle's ability.$B|TInterface\Icons\inv_misc_groupneedmore.blp:64|t", 41, 0, 100, 0, 0, 0, "King Greymane's Horse");

UPDATE `creature_template` SET `InhabitType` = 4, `AIName` = "", `ScriptName` = "" WHERE `entry` = 35753;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_saved_aranas" WHERE `entry` = 35907;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35753, 35907) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35907*100 AND `source_type` = 9;

DELETE FROM `creature_template_addon` WHERE `entry` = 35753;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES
(35753, 1, "78037");

DELETE FROM `creature` WHERE `guid` IN (371594, 371595);
DELETE FROM `creature_addon` WHERE `guid` IN (371594, 371595);

UPDATE `creature_template` SET `ScriptName` = "npc_forsaken_invader" WHERE `entry` = 34511;
UPDATE `creature_template` SET `ScriptName` = "npc_duskhaven_watchman" WHERE `entry` = 36211;

UPDATE `creature_template` SET `ScriptName` = "npc_forsaken_catapult" WHERE `entry` = 36283;
UPDATE `creature` SET `spawntimesecs` = 120 WHERE `id` = 36283;

DELETE FROM `conditions` WHERE `SourceEntry` = 68591 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 68591, 0, 0, 31, 0, 3, 36286, 0, 0, 0, "", "Spell 'Catapult Boulder' target Catapult Triggers");

DELETE FROM `spell_script_names` WHERE `spell_id` = 68591;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(68591, "spell_catapult_boulder");

DELETE FROM `creature` WHERE `id` = 37078;
DELETE FROM `creature_addon` WHERE `guid` IN (221468, 221486, 221848, 221850, 221852, 221854, 221868, 221870, 221874, 221878,
                                              221882, 221919, 221920, 221923, 221924);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (37067, 37078, );
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (37067, 37078) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(37067, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 69854, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Crash Survivor - On Respawn - Cast Spell 'Summon Swamp Crocolisk'"),
(37067, 0, 1, 0, 38, 0, 100, 0, 1, 1, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Crash Survivor - On Data Set 1 1 - Despawn Self (1000 ms)"),

(37078, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Swamp Crocolisk - On Just Summoned - Start Attack Summoner"),
(37078, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Swamp Crocolisk - On Death - Set Data 1 1 To Summoner");

DELETE FROM `creature` WHERE `guid` IN (221936, 221930, 221926, 221937);
DELETE FROM `creature_addon` WHERE `guid` IN (221936, 221930, 221926, 221937);
UPDATE `creature` SET `position_x` = -2339.306396, `position_y` = 1930.966919, `position_z` = 74.015625, `orientation` = 5.139883, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 221856;
UPDATE `creature` SET `position_x` = -2286.466553, `position_y` = 1884.088257, `position_z` = 55.521866, `orientation` = 2.803326, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 221897;
UPDATE `creature` SET `position_x` = -2395.204590, `position_y` = 1779.870361, `position_z` = 7.679942 WHERE `guid` = 221862;

UPDATE `creature` SET `wander_distance` = 10, `movement_type` = 1 WHERE `guid` IN (221503, 221929, 221928, 221890, 221883, 221862, 221860, 221859);

UPDATE `creature_template` SET `ScriptName` = "", `AIName` = "SmartAI" WHERE `entry` = 36293;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 36293 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(36293, 0, 0, 0, 0, 0, 100, 0, 1000, 1000, 22000, 22000, 11, 75436, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Ogre Minion - In Combat - Cast Spell 'Clubbed'");

DELETE FROM `waypoint_data` WHERE `id` IN (221894, 221931);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `entry`) VALUES
(221894, 1, -2308.86, 1908.56, 65.4409, 0, 0, 0, 36293),
(221894, 2, -2314.25, 1910.11, 67.799, 0, 0, 0, 36293),
(221894, 3, -2321.66, 1912.95, 70.396, 0, 0, 0, 36293),
(221894, 4, -2327.66, 1915.25, 71.8246, 0, 0, 0, 36293),
(221894, 5, -2323.28, 1913.63, 70.808, 0, 0, 0, 36293),
(221894, 6, -2315.6, 1910.85, 68.4194, 0, 0, 0, 36293),
(221894, 7, -2309.13, 1908.51, 65.5213, 0, 0, 0, 36293),
(221894, 8, -2305.96, 1906.76, 63.9355, 0, 0, 0, 36293),
(221894, 9, -2302.31, 1902.21, 61.4081, 0, 0, 0, 36293),
(221894, 10, -2300.41, 1897.44, 59.2782, 0, 0, 0, 36293),
(221894, 11, -2300.81, 1892.9, 57.2984, 0, 0, 0, 36293),
(221894, 12, -2303.89, 1887.14, 54.1629, 0, 0, 0, 36293),
(221894, 13, -2307.43, 1880.97, 50.422, 0, 0, 0, 36293),
(221894, 14, -2310.5, 1876.28, 47.4981, 0, 0, 0, 36293),
(221894, 15, -2313.97, 1871.02, 44.3631, 0, 0, 0, 36293),
(221894, 16, -2317.35, 1864.75, 41.2313, 0, 0, 0, 36293),
(221894, 17, -2314.36, 1870.3, 43.9829, 0, 0, 0, 36293),
(221894, 18, -2310.46, 1876.81, 47.7428, 0, 0, 0, 36293),
(221894, 19, -2306.67, 1883.38, 51.7263, 0, 0, 0, 36293),
(221894, 20, -2303.57, 1889.67, 55.4044, 0, 0, 0, 36293),
(221894, 21, -2301.26, 1894.37, 57.859, 0, 0, 0, 36293),
(221894, 22, -2301.48, 1898.8, 59.8318, 0, 0, 0, 36293),

(221931, 1, -2362.76, 1945.55, 70.5878, 0, 0, 0, 36293),
(221931, 2, -2357.93, 1938.96, 71.4194, 0, 0, 0, 36293),
(221931, 3, -2353.2, 1934.47, 72.1952, 0, 0, 0, 36293),
(221931, 4, -2347.79, 1928.82, 72.694, 0, 0, 0, 36293),
(221931, 5, -2341.27, 1924.45, 72.9031, 0, 0, 0, 36293),
(221931, 6, -2333.41, 1918.77, 72.6257, 0, 0, 0, 36293),
(221931, 7, -2338.73, 1921.92, 72.8214, 0, 0, 0, 36293),
(221931, 8, -2345.86, 1927.71, 72.7615, 0, 0, 0, 36293),
(221931, 9, -2353.54, 1934.35, 72.1783, 0, 0, 0, 36293),
(221931, 10, -2359.1, 1939.34, 71.3042, 0, 0, 0, 36293),
(221931, 11, -2364.15, 1945.92, 70.4688, 0, 0, 0, 36293),
(221931, 12, -2367.79, 1950.92, 70.1898, 0, 0, 0, 36293),
(221931, 13, -2370.44, 1958.15, 70.3021, 0, 0, 0, 36293),
(221931, 14, -2371.21, 1965.58, 70.4445, 0, 0, 0, 36293),
(221931, 15, -2372.09, 1975.92, 71.1363, 0, 0, 0, 36293),
(221931, 16, -2372.9, 1981.7, 71.5089, 0, 0, 0, 36293),
(221931, 17, -2372.02, 1975.93, 71.1434, 0, 0, 0, 36293),
(221931, 18, -2370.64, 1966.22, 70.4738, 0, 0, 0, 36293),
(221931, 19, -2369.98, 1961.61, 70.3646, 0, 0, 0, 36293),
(221931, 20, -2368.81, 1956.61, 70.3314, 0, 0, 0, 36293);

UPDATE `gameobject_template` SET `ScriptName` = "go_koroth_banner" WHERE `entry` = 201594;
UPDATE `creature_template` SET `ScriptName` = "npc_koroth_the_hillbreaker" WHERE `entry` = 36294;

DELETE FROM `creature_text` WHERE `entry` = 36294;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36294, 0, 0, "Who dares to touch Koroth's banner!?", "", 14, 0, 100, 0, 0, 0, "Koroth the Hillbreaker"),
(36294, 1, 0, "You puny thief! Koroth find you! Koroth smash your face in!", "", 14, 0, 100, 0, 0, 0, "Koroth the Hillbreaker");
