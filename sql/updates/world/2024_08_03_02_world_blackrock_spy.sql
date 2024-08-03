-- Blackrock Spy
UPDATE `creature_template` SET `ScriptName` = "", `AIName` = "SmartAI" WHERE `entry` = 49874;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 49874 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(49874, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Blackrock Spy - On Aggro - Say Text Line 0");

DELETE FROM `creature` WHERE `guid` IN (178460, 178475, 178482, 178483, 178484) AND `id` = 49874;
UPDATE `creature` SET `position_x` = -8794.68, `position_y` = -45.3715, `position_z` = 95.1974, `orientation` = 3.89208, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178184;
UPDATE `creature` SET `position_x` = -8827.63, `position_y` = -39.1406, `position_z` = 89.5429, `orientation` = 4.29351, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178185;
UPDATE `creature` SET `position_x` = -8784.36, `position_y` = -78.684, `position_z` = 89.6413, `orientation` = 6.22259, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 178204;
UPDATE `creature` SET `position_x` = -8790.72, `position_y` = -87.0955, `position_z` = 87.3718, `orientation` = 4.2586, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178205;
UPDATE `creature` SET `position_x` = -8937.44, `position_y` = -246.769, `position_z` = 79.0622, `orientation` = 3.16881, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 178233;
UPDATE `creature` SET `position_x` = -8949.17, `position_y` = -242.229, `position_z` = 77.7663, `orientation` = 1.58825, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178238;
UPDATE `creature` SET `position_x` = -8816.06, `position_y` = -106.075, `position_z` = 83.2249, `orientation` = 4.53786, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178240;
UPDATE `creature` SET `position_x` = -8832.97, `position_y` = -120.335, `position_z` = 80.8506, `orientation` = 5.95673, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 178242;
UPDATE `creature` SET `position_x` = -8831.76, `position_y` = -76.1684, `position_z` = 85.8966, `orientation` = 3.83972, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178248;
UPDATE `creature` SET `position_x` = -8839.67, `position_y` = -119.245, `position_z` = 80.5284, `orientation` = 3.40339, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178249;
UPDATE `creature` SET `position_x` = -8845.08, `position_y` = -78.0642, `position_z` = 84.7144, `orientation` = 4.34587, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178250;
UPDATE `creature` SET `position_x` = -8878.37, `position_y` = -92.2378, `position_z` = 83.897, `orientation` = 5.63078, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 178254;
UPDATE `creature` SET `position_x` = -8859.49, `position_y` = -68.7153, `position_z` = 85.6182, `orientation` = 4.53786, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178271;
UPDATE `creature` SET `position_x` = -8841.07, `position_y` = -35.6042, `position_z` = 88.1633, `orientation` = 3.87463, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178276;
UPDATE `creature` SET `position_x` = -8897.18, `position_y` = -53.3351, `position_z` = 87.4536, `orientation` = 4.62512, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178280;
UPDATE `creature` SET `position_x` = -8926.37, `position_y` = -68.809, `position_z` = 89.7558, `orientation` = 5.59872, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 178340;
UPDATE `creature` SET `position_x` = -8906.61, `position_y` = -39.1701, `position_z` = 89.1446, `orientation` = 0.272417, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 178341;
UPDATE `creature` SET `position_x` = -8975.59, `position_y` = -210.868, `position_z` = 74.3862, `orientation` = 5.96423, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 178342;
UPDATE `creature` SET `position_x` = -8967.54, `position_y` = -204.846, `position_z` = 75.43, `orientation` = 0.820305, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178345;
UPDATE `creature` SET `position_x` = -8966.63, `position_y` = -181.887, `position_z` = 81.0374, `orientation` = 0.733038, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178347;
UPDATE `creature` SET `position_x` = -9017.05, `position_y` = -186.177, `position_z` = 76.9911, `orientation` = 1.82138, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 178355;
UPDATE `creature` SET `position_x` = -8959.65, `position_y` = -62.3316, `position_z` = 92.4678, `orientation` = 3.14574, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 178359;
UPDATE `creature` SET `position_x` = -8977.66, `position_y` = -39.2257, `position_z` = 91.482, `orientation` = 4.76475, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178432;
UPDATE `creature` SET `modelid` = 0, `spawntimesecs` = 300 WHERE `id` = 49874;

DELETE FROM `creature_template_addon` WHERE `entry` = 49874;
DELETE FROM `creature_addon` WHERE `guid` IN (178184, 178185, 178204, 178205, 178233, 178238, 178240, 178242, 178248, 178249, 178250, 178254,
                                              178271, 178276, 178280, 178340, 178341, 178342, 178345, 178347, 178355, 178359, 178432, 178460,
                                              178475, 178482, 178483, 178484);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(178184, 0, 4097, "80676"),
(178185, 0, 4097, "80676"),
(178204, 178204, 4097, "92857"),
(178205, 0, 4097, "80676"),
(178233, 178233, 4097, "92857"),
(178238, 0, 4097, "80676"),
(178240, 0, 4097, "80676"),
(178242, 178242, 4097, "92857"),
(178248, 0, 4097, "80676"),
(178249, 0, 4097, "80676"),
(178250, 0, 4097, "80676"),
(178254, 178254, 4097, "92857"),
(178271, 0, 4097, "80676"),
(178276, 0, 4097, "80676"),
(178280, 0, 4097, "80676"),
(178340, 178340, 4097, "92857"),
(178341, 178341, 4097, "92857"),
(178342, 178342, 4097, "92857"),
(178345, 0, 4097, "80676"),
(178347, 0, 4097, "80676"),
(178355, 178355, 4097, "92857"),
(178359, 178359, 4097, "92857"),
(178432, 0, 4097, "80676");

DELETE FROM `waypoint_data` WHERE `id` IN (178204, 178233, 178240, 178242, 178254, 178276, 178280, 178340, 178341, 178342, 178355, 178359, 178460, 178482, 178483);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`) VALUES
(178204, 1, -8784.36, -78.684, 89.6413, 0, 0, 0),
(178204, 2, -8776.55, -79.158, 89.339, 0, 0, 0),
(178204, 3, -8772.43, -83.7865, 88.6623, 0, 0, 0),
(178204, 4, -8776.55, -79.158, 89.339, 0, 0, 0),

(178233, 1, -8937.44, -246.769, 79.0622, 0, 0, 0),
(178233, 2, -8930.79, -241.477, 79.4993, 0, 0, 0),
(178233, 3, -8933.1, -246.651, 78.9288, 0, 0, 0),

(178242, 1, -8832.97, -120.335, 80.8506, 0, 0, 0),
(178242, 2, -8831.47, -124.04, 80.7979, 0, 0, 0),
(178242, 3, -8837.33, -118.861, 80.5976, 0, 0, 0),

(178254, 1, -8878.37, -92.2378, 83.897, 0, 0, 0),
(178254, 2, -8873.4, -91.309, 83.177, 0, 0, 0),
(178254, 3, -8870.21, -93.7413, 82.5498, 0, 0, 0),

(178340, 1, -8926.37, -68.809, 89.7558, 0, 0, 0),
(178340, 2, -8929.81, -68.9167, 89.9731, 0, 0, 0),
(178340, 3, -8922.82, -71.7083, 89.1572, 0, 0, 0),

(178341, 1, -8906.61, -39.1701, 89.1446, 0, 0, 0),
(178341, 2, -8900.66, -43.309, 86.9744, 0, 0, 0),
(178341, 3, -8906.4, -39.3164, 89.2081, 0, 0, 0),
(178341, 4, -8911.56, -40.5469, 89.5723, 0, 0, 0),

(178342, 1, -8975.59, -210.868, 74.3862, 0, 0, 0),
(178342, 2, -8982.35, -208.635, 73.9499, 0, 0, 0),
(178342, 3, -8983, -201.585, 74.6443, 0, 0, 0),
(178342, 4, -8982.35, -208.635, 73.9499, 0, 0, 0),

(178355, 1, -9017.05, -186.177, 76.9911, 0, 0, 0),
(178355, 2, -9022.96, -180.92, 76.686, 0, 0, 0),
(178355, 3, -9025.42, -177.948, 76.5336, 0, 0, 0),
(178355, 4, -9026.48, -173.778, 77.3378, 0, 0, 0),
(178355, 5, -9024.31, -167.119, 78.7536, 0, 0, 0),
(178355, 6, -9026.48, -173.777, 77.3786, 0, 0, 0),
(178355, 7, -9025.42, -177.948, 76.5336, 0, 0, 0),
(178355, 8, -9022.96, -180.92, 76.686, 0, 0, 0),

(178359, 1, -8959.65, -62.3316, 92.4678, 0, 0, 0),
(178359, 2, -8962.09, -58.0573, 92.4385, 0, 0, 0),
(178359, 3, -8966.28, -58.0746, 92.1885, 0, 0, 0),
(178359, 4, -8966.95, -59.7587, 91.9726, 0, 0, 0),
(178359, 5, -8962.49, -59.9462, 92.2525, 0, 0, 0),
(178359, 6, -8966.28, -58.0746, 92.1885, 0, 0, 0),
(178359, 7, -8962.09, -58.0573, 92.4385, 0, 0, 0),
(178359, 8, -8958.91, -60.7708, 92.4385, 0, 0, 0);
