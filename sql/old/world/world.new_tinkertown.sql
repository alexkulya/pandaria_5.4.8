UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` IN (43092, 42329);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (43092, 42329) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (42329*100, 42329*100+01, 42329*100+02) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(43092, 0, 0, 0, 0, 0, 100, 0, 1000, 4000, 5000, 8000, 11, 85756, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Gnomeregan Recruit - In Combat - Cast Spell 'Shoot'"),

(42329, 0, 0, 0, 1, 0, 100, 0, 1000, 5000, 5000, 5000, 87, 42329*100, 42329*100+01, 42329*100+02, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gnomeregan Trainee - OOC - Start Random Script"),

(42329*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 42880, 0, 0, 0, 0, 0, 9, 42328, 0, 2, 0, 0, 0, 0, "Gnomeregan Trainee - On Script - Cast Spell 'Cosmetic - Combat Attack 1H'"),
(42329*100+01, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 44079, 0, 0, 0, 0, 0, 9, 42328, 0, 2, 0, 0, 0, 0, "Gnomeregan Trainee - On Script - Cast Spell 'Cosmetic - Combat Special Attack 1H'"),
(42329*100+02, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 78959, 0, 0, 0, 0, 0, 9, 42328, 0, 2, 0, 0, 0, 0, "Gnomeregan Trainee - On Script - Cast Spell 'Cosmetic - Combat Attack 1H (Thrust)'");

DELETE FROM `creature_template_addon` WHERE `entry` = 43092;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES
(43092, 2, "78174");

DELETE FROM `creature_addon` WHERE `guid` IN (167687, 167847, 167855, 167990, 167463, 167457, 167690, 167688, 167522, 167716, 167718, 167720);

DELETE FROM `creature` WHERE `guid` IN (167689, 168951, 168952, 169007, 169008, 168993);

DELETE FROM `creature_addon` WHERE `guid` IN (169008, 168993);

DELETE FROM `waypoint_data` WHERE `id` IN (169008, 168993);

UPDATE `creature` SET `modelid` = 0, `position_x` = -5095.03, `position_y` = 463.377, `position_z` = 404.373, `orientation` = 0.378309, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 167850;
UPDATE `creature` SET `modelid` = 0, `position_x` = -5095.03, `position_y` = 463.377, `position_z` = 404.373, `orientation` = 0.376152, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 167851;
UPDATE `creature` SET `modelid` = 0, `position_x` = -5183.05, `position_y` = 460.938, `position_z` = 388.587, `orientation` = 0.274843, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 167987;
UPDATE `creature` SET `modelid` = 0, `position_x` = -5183.05, `position_y` = 460.938, `position_z` = 388.587, `orientation` = 0.266332, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 167988;
UPDATE `creature` SET `modelid` = 0, `position_x` = -5125.31, `position_y` = 440.295, `position_z` = 396.395, `orientation` = 1.64124, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 168992;
UPDATE `creature` SET `modelid` = 0, `position_x` = -5420.24, `position_y` = -126.13, `position_z` = 395.937, `orientation` = 4.50435, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 167460;
UPDATE `creature` SET `modelid` = 0, `position_x` = -5420.24, `position_y` = -126.13, `position_z` = 395.937, `orientation` = 4.49771, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 167461;

DELETE FROM `creature_template_addon` WHERE `entry` = 42319;

DELETE FROM `creature_addon` WHERE `guid` IN (167850, 167851, 167987, 167988, 168992, 167460, 167461);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes2`) VALUES
(167850, 167850, 6569, 1),
(167851, 0, 6569, 1),
(167987, 167987, 6569, 1),
(167988, 0, 6569, 1),
(168992, 168992, 6569, 1),
(167460, 167460, 6569, 1),
(167461, 0, 6569, 1);

DELETE FROM `waypoint_data` WHERE `id` IN (167850, 167987, 168992, 167460, 167461);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`) VALUES
(167850, 1, -5095.03, 463.377, 404.373, 0, 0, 0),
(167850, 2, -5106.81, 458.717, 402.26, 0, 0, 0),
(167850, 3, -5119.04, 451.991, 398.003, 0, 0, 0),
(167850, 4, -5130.81, 449.031, 395.01, 0, 0, 0),
(167850, 5, -5159.51, 475.056, 390.59, 0, 0, 0),
(167850, 6, -5175.92, 486.882, 388.312, 0, 0, 0),
(167850, 7, -5186.39, 502.389, 387.883, 0, 0, 0),
(167850, 8, -5187.96, 516.509, 388.016, 0, 0, 0),
(167850, 9, -5188.75, 536.052, 389.804, 0, 0, 0),
(167850, 10, -5188.02, 553.053, 394.652, 0, 0, 0),
(167850, 11, -5185.13, 568.205, 398.956, 0, 0, 0),
(167850, 12, -5183.82, 589.148, 405.496, 0, 0, 0),
(167850, 13, -5185.13, 568.205, 398.956, 0, 0, 0),
(167850, 14, -5188.01, 553.278, 394.894, 0, 0, 0),
(167850, 15, -5188.75, 536.052, 389.804, 0, 0, 0),
(167850, 16, -5187.96, 516.509, 388.016, 0, 0, 0),
(167850, 17, -5186.39, 502.389, 387.883, 0, 0, 0),
(167850, 18, -5175.92, 486.882, 388.312, 0, 0, 0),
(167850, 19, -5159.51, 475.056, 390.59, 0, 0, 0),
(167850, 20, -5130.81, 449.031, 395.01, 0, 0, 0),
(167850, 21, -5119.04, 451.991, 398.003, 0, 0, 0),
(167850, 22, -5106.81, 458.717, 402.26, 0, 0, 0),

(167987, 1, -5183.05, 460.938, 388.587, 0, 0, 0),
(167987, 2, -5189.89, 449.413, 388.72, 0, 0, 0),
(167987, 3, -5220.47, 420.922, 390.668, 0, 0, 0),
(167987, 4, -5251.05, 400.807, 392.185, 0, 0, 0),
(167987, 5, -5283.85, 384.036, 392.773, 0, 0, 0),
(167987, 6, -5317.19, 376.028, 393.336, 0, 0, 0),
(167987, 7, -5342, 369.031, 394.049, 0, 0, 0),
(167987, 8, -5361.65, 339.328, 394.7, 0, 0, 0),
(167987, 9, -5342, 369.031, 394.049, 0, 0, 0),
(167987, 10, -5317.19, 376.028, 393.336, 0, 0, 0),
(167987, 11, -5283.85, 384.036, 392.773, 0, 0, 0),
(167987, 12, -5251.05, 400.807, 392.185, 0, 0, 0),
(167987, 13, -5220.47, 420.922, 390.668, 0, 0, 0),
(167987, 14, -5189.89, 449.413, 388.72, 0, 0, 0),

(168992, 1, -5125.31, 440.295, 396.395, 0, 0, 0),
(168992, 2, -5122.31, 430.474, 396.718, 0, 0, 0),
(168992, 3, -5121.23, 416.439, 396.718, 0, 0, 0),
(168992, 4, -5125.21, 401.132, 396.718, 0, 0, 0),
(168992, 5, -5124.19, 377.036, 396.678, 0, 0, 0),
(168992, 6, -5122.13, 347.938, 395.863, 0, 0, 0),
(168992, 7, -5114.43, 323.962, 394.264, 0, 0, 0),
(168992, 8, -5099.18, 306.385, 394.264, 0, 0, 0),
(168992, 9, -5090.41, 298.01, 394.323, 0, 0, 0),
(168992, 10, -5087.61, 279.717, 393.702, 0, 0, 0),
(168992, 11, -5090.41, 298.01, 394.323, 0, 0, 0),
(168992, 12, -5099.18, 306.385, 394.264, 0, 0, 0),
(168992, 13, -5114.43, 323.962, 394.264, 0, 0, 0),
(168992, 14, -5122.13, 347.938, 395.863, 0, 0, 0),
(168992, 15, -5124.19, 377.036, 396.678, 0, 0, 0),
(168992, 16, -5125.21, 401.132, 396.718, 0, 0, 0),
(168992, 17, -5121.23, 416.439, 396.718, 0, 0, 0),
(168992, 18, -5122.31, 430.474, 396.718, 0, 0, 0),

(167460, 1, -5420.24, -126.13, 395.937, 0, 0, 0),
(167460, 2, -5411.44, -94.6146, 393.492, 0, 0, 0),
(167460, 3, -5395.21, -79.4375, 391.828, 0, 0, 0),
(167460, 4, -5388.51, -48.7743, 391.177, 0, 0, 0),
(167460, 5, -5386.53, 0.211806, 391.154, 0, 0, 0),
(167460, 6, -5389.17, 32.9879, 391.154, 0, 0, 0),
(167460, 7, -5407.37, 58.6875, 393.505, 0, 0, 0),
(167460, 8, -5414.39, 86.5625, 393.421, 0, 0, 0),
(167460, 9, -5424.37, 129.601, 393.482, 0, 0, 0),
(167460, 10, -5440.77, 156.531, 394.367, 0, 0, 0),
(167460, 11, -5443.15, 201.856, 394.353, 0, 0, 0),
(167460, 12, -5439.89, 232.078, 394.853, 0, 0, 0),
(167460, 13, -5422.26, 255.029, 394.7, 0, 0, 0),
(167460, 14, -5419.85, 279.627, 394.714, 0, 0, 0),
(167460, 15, -5414.64, 301.733, 394.704, 0, 0, 0),
(167460, 16, -5419.85, 279.627, 394.714, 0, 0, 0),
(167460, 17, -5422.26, 255.029, 394.7, 0, 0, 0),
(167460, 18, -5439.89, 232.078, 394.853, 0, 0, 0),
(167460, 19, -5443.15, 201.856, 394.353, 0, 0, 0),
(167460, 20, -5440.77, 156.531, 394.367, 0, 0, 0),
(167460, 21, -5424.37, 129.601, 393.482, 0, 0, 0),
(167460, 22, -5414.39, 86.5625, 393.421, 0, 0, 0),
(167460, 23, -5407.37, 58.6875, 393.505, 0, 0, 0),
(167460, 24, -5389.17, 32.9879, 391.154, 0, 0, 0),
(167460, 25, -5386.53, 0.211806, 391.154, 0, 0, 0),
(167460, 26, -5388.51, -48.7743, 391.177, 0, 0, 0),
(167460, 27, -5395.21, -79.4375, 391.828, 0, 0, 0),
(167460, 28, -5411.44, -94.6146, 393.492, 0, 0, 0);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (167850, 167987, 167460);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`)VALUES
(167850, 167850, 0, 0, 2),
(167850, 167851, 2, 90, 2),

(167987, 167987, 0, 0, 2),
(167987, 167988, 2, 90, 2),

(167460, 167460, 0, 0, 2),
(167460, 167461, 2, 90, 2);

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 42324;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 42324 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 42324*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(42324, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, 42324, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drill Sergeant Steamcrank - On Respawn - Start WP"),
(42324, 0, 1, 0, 64, 0, 100, 0, 0, 0, 0, 0, 54, 30000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drill Sergeant Steamcrank - On Gossip Hello - Pause WP (30000 ms)"),
(42324, 0, 2, 3, 40, 0, 100, 0, 2, 42324, 0, 0, 54, 6000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drill Sergeant Steamcrank - On Reached WP2 - Pause WP (6000 ms)"),
(42324, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 42324*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drill Sergeant Steamcrank - On Reached WP2 (Link) - Start Script"),
(42324, 0, 4, 5, 40, 0, 100, 0, 3, 42324, 0, 0, 54, 9000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drill Sergeant Steamcrank - On Reached WP3 - Pause WP (9000 ms)"),
(42324, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 42324*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drill Sergeant Steamcrank - On Reached WP3 (Link) - Start Script"),
(42324, 0, 6, 7, 40, 0, 100, 0, 5, 42324, 0, 0, 54, 7000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drill Sergeant Steamcrank - On Reached WP5 - Pause WP (7000 ms)"),
(42324, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 42324*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drill Sergeant Steamcrank - On Reached WP5 (Link) - Start Script"),
(42324, 0, 8, 9, 40, 0, 100, 0, 6, 42324, 0, 0, 54, 8000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drill Sergeant Steamcrank - On Reached WP6 - Pause WP (8000 ms)"),
(42324, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 42324*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drill Sergeant Steamcrank - On Reached WP6 (Link) - Start Script"),

(42324*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 42329, 5, 0, 0, 0, 0, 0, "Drill Sergeant Steamcrank - On Script - Set Orientation To Trainee"),
(42324*100, 9, 1, 0, 0, 0, 100, 0, 500, 500, 0, 0, 10, 5, 25, 273, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Drill Sergeant Steamcrank - On Script - Play Random Emote (5, 25, 273)");

DELETE FROM `waypoints` WHERE `entry` = 42324;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(42324, 1, -5173.22, 454.167, 390.576, "Drill Sergeant Steamcrank"),
(42324, 2, -5173.53, 453.476, 390.586, "Drill Sergeant Steamcrank"),
(42324, 3, -5158.39, 456.637, 392.405, "Drill Sergeant Steamcrank"),
(42324, 4, -5162.46, 455.573, 392.245, "Drill Sergeant Steamcrank"),
(42324, 5, -5163.07, 454.227, 392.314, "Drill Sergeant Steamcrank"),
(42324, 6, -5167.78, 453.701, 391.813, "Drill Sergeant Steamcrank");
