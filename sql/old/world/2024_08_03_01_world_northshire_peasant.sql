-- Northshire Peasant
DELETE FROM `creature` WHERE `guid` IN (10954, 43766, 177908, 177909, 177910) AND `id` = 11260;
UPDATE `creature` SET `position_x` = -8840.36, `position_y` = -271.29, `position_z` = 80.9749, `orientation` = 1.13804, `wander_distance` = 0, `movement_type` = 0, `equipment_id` = 1 WHERE `guid` = 10373;
UPDATE `creature` SET `position_x` = -8856.89, `position_y` = -252.401, `position_z` = 81.078, `orientation` = 5.37848, `equipment_id` = 1 WHERE `guid` = 5881;
UPDATE `creature` SET `position_x` = -8891.61, `position_y` = -275.477, `position_z` = 80.0948, `orientation` = 4.86014, `equipment_id` = 1 WHERE `guid` = 6028;
UPDATE `creature` SET `position_x` = -8932.22, `position_y` = -240.487, `position_z` = 79.3923, `orientation` = 2.99685, `equipment_id` = 1 WHERE `guid` = 6364;
UPDATE `creature` SET `position_x` = -8967.41, `position_y` = -203.362, `position_z` = 75.5193, `orientation` = 2.50597, `equipment_id` = 1 WHERE `guid` = 6366;

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 11260;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-5881, -6028, -6364, -6366) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (11260*100, 11260*100+01, 11260*100+02, 11260*100+03, 11260*100+04, 11260*100+05) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-5881, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 11260*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - MI 1 - Start Script (0)"),
(-5881, 0, 1, 0, 34, 0, 100, 0, 2, 4, 0, 0, 80, 11260*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - MI 4 - Start Script (1)"),
(-5881, 0, 2, 0, 34, 0, 100, 0, 2, 7, 0, 0, 80, 11260*100+02, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - MI 7 - Start Script (2)"),

(-6028, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 11260*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - MI 1 - Start Script (0)"),
(-6028, 0, 1, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 11260*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - MI 3 - Start Script (1)"),
(-6028, 0, 2, 0, 34, 0, 100, 0, 2, 5, 0, 0, 80, 11260*100+03, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - MI 5 - Start Script (3)"),

(-6364, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 11260*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - MI 1 - Start Script (1)"),
(-6364, 0, 1, 0, 34, 0, 100, 0, 2, 5, 0, 0, 80, 11260*100+04, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - MI 5 - Start Script (4)"),

(-6366, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 11260*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - MI 1 - Start Script (0)"),
(-6366, 0, 1, 0, 34, 0, 100, 0, 2, 5, 0, 0, 80, 11260*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - MI 5 - Start Script (1)"),
(-6366, 0, 2, 0, 34, 0, 100, 0, 2, 9, 0, 0, 80, 11260*100+05, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - MI 9 - Start Script (5)"),

(11260*100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 3, 0, 89, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - On Script - Morph To Model (89)"),

(11260*100+01, 9, 0, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 3, 0, 11354, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - On Script - Morph To Model (11354)"),

(11260*100+02, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - On Script - Set Emote State (234)"),
(11260*100+02, 9, 1, 0, 0, 0, 100, 0, 37000, 37000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - On Script - Set Emote State (0)"),

(11260*100+03, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - On Script - Set Emote State (234)"),
(11260*100+03, 9, 1, 0, 0, 0, 100, 0, 32000, 32000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - On Script - Set Emote State (0)"),

(11260*100+04, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - On Script - Set Emote State (234)"),
(11260*100+04, 9, 1, 0, 0, 0, 100, 0, 24000, 24000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - On Script - Set Emote State (0)"),
(11260*100+04, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 3, 0, 89, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - On Script - Morph To Model (89)"),

(11260*100+05, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - On Script - Set Emote State (234)"),
(11260*100+05, 9, 1, 0, 0, 0, 100, 0, 52000, 52000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Northshire Peasant - On Script - Set Emote State (0)");

DELETE FROM `creature_template_addon` WHERE `entry` = 11260;
DELETE FROM `creature_addon` WHERE `guid` IN (10373, 10954, 43766, 5881, 6028, 6364, 6366);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `emote`) VALUES
(10373, 0, 4097, 234),
(5881, 5881, 4097, 0),
(6028, 6028, 4097, 0),
(6364, 6364, 4097, 0),
(6366, 6366, 4097, 0);

DELETE FROM `waypoint_data` WHERE `id` IN (10373, 10954, 43766, 5881, 6028, 6364, 6366);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`) VALUES
(5881, 1, -8856.68, -252.485, 81.0927, 0, 1000, 0),
(5881, 2, -8856.68, -252.485, 81.0927, 5.758079, 4000, 0),
(5881, 3, -8868.69, -238.245, 81.9439, 0, 0, 0),
(5881, 4, -8887.17, -214.797, 81.193, 0, 0, 0),
(5881, 5, -8900.61, -224.923, 80.3514, 2.750005, 10000, 0),
(5881, 6, -8887.17, -214.797, 81.193, 0, 450, 0),
(5881, 7, -8868.69, -238.245, 81.9439, 0, 0, 0),
(5881, 8, -8856.68, -252.485, 81.0927, 5.758079, 40000, 0),

(6028, 1, -8886.84, -274.351, 80.4733, 0, 1000, 0),
(6028, 2, -8886.84, -274.351, 80.4733, 4.917707, 4000, 0),
(6028, 3, -8893.11, -250.483, 80.7111, 0, 0, 0),
(6028, 4, -8901.84, -228.345, 80.3575, 2.765718, 10000, 0),
(6028, 5, -8893.11, -250.483, 80.7111, 0, 0, 0),
(6028, 6, -8886.84, -274.351, 80.4733, 4.917707, 35000, 0),

(6364, 1, -8902.59, -231.7, 80.4142, 0, 0, 0),
(6364, 2, -8900.49, -225.852, 80.344, 2.671471, 10000, 0),
(6364, 3, -8902.59, -231.7, 80.4142, 0, 500, 0),
(6364, 4, -8915.03, -236.165, 81.5361, 0, 0, 0),
(6364, 5, -8921.63, -236.229, 81.0027, 0, 0, 0),
(6364, 6, -8932.17, -240.639, 79.3944, 2.903163, 30000, 0),
(6364, 7, -8915.03, -236.165, 81.5361, 0, 1000, 0),

(6366, 1, -8967.16, -203.139, 75.4001, 0, 1000, 0),
(6366, 2, -8967.16, -203.139, 75.4001, 2.565442, 4000, 0),
(6366, 3, -8949.57, -217.038, 79.1346, 0, 0, 0),
(6366, 4, -8920.34, -234.824, 81.3477, 0, 0, 0),
(6366, 5, -8900.9, -230.734, 80.3199, 0, 0, 0),
(6366, 6, -8901.7, -228.566, 80.3573, 2.773573, 5000, 0),
(6366, 7, -8900.9, -230.734, 80.3199, 0, 1000, 0),
(6366, 8, -8920.34, -234.824, 81.3477, 0, 0, 0),
(6366, 9, -8949.57, -217.038, 79.1346, 0, 0, 0),
(6366, 10, -8967.16, -203.139, 75.4001, 2.565442, 55000, 0);

DELETE FROM `waypoint_scripts` WHERE `id` IN (96, 97, 98, 99, 141, 142, 143, 144, 157, 158, 159, 160, 209, 210);
