UPDATE `creature` SET `position_x` = -9009.53, `position_y` = -63.4485, `position_z` = 87.0312, `orientation` = 1.70431, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 177929;
UPDATE `creature` SET `position_x` = -9010.16, `position_y` = -58.7008, `position_z` = 87.1778, `orientation` = 1.61399, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 177930;
UPDATE `creature` SET `position_x` = -9009.79, `position_y` = -67.2748, `position_z` = 86.9223, `orientation` = 1.61399, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 177931;
UPDATE `creature` SET `position_x` = -9009.96, `position_y` = -63.2326, `position_z` = 87.066, `orientation` = 1.61399, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 177932;

DELETE FROM `creature_template_addon` WHERE `entry` = 42218;
DELETE FROM `creature_addon` WHERE `guid` IN (177929, 177930, 177931, 177932, 177933, 177934);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(177929, 177929, 28912, 0, 1, 0, ""),
(177930, 0, 28912, 0, 1, 0, ""),
(177931, 0, 28912, 0, 1, 0, ""),
(177932, 0, 28912, 0, 1, 0, ""),

(177933, 0, 0, 0, 257, 0, ""),
(177934, 0, 0, 0, 257, 0, "");

DELETE FROM `waypoint_data` WHERE `id` IN (177929, 177930, 177931, 177932);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `entry`) VALUES
(177929, 1, -9008.93, -62.0718, 87.0293, 0, 0, 0, 42218),
(177929, 2, -9009.66, -43.0235, 87.5544, 0, 0, 0, 42218),
(177929, 3, -9014.83, -5.4108, 88.6349, 0, 0, 0, 42218),
(177929, 4, -9020.41, 3.4639, 88.4009, 0, 0, 0, 42218),
(177929, 5, -9028.99, 5.15317, 88.1821, 0, 0, 0, 42218),
(177929, 6, -9036.13, -0.0671551, 88.303, 0, 0, 0, 42218),
(177929, 7, -9041.14, -31.097, 88.2439, 0, 0, 0, 42218),
(177929, 8, -9048.33, -44.2447, 88.3092, 0, 0, 0, 42218),
(177929, 9, -9064.06, -42.1227, 88.0401, 0, 0, 0, 42218),
(177929, 10, -9076.32, -46.98, 87.5662, 0, 0, 0, 42218),
(177929, 11, -9119.51, -80.3331, 79.7431, 0, 0, 0, 42218),
(177929, 12, -9161.44, -108.258, 72.6388, 0, 0, 0, 42218),
(177929, 13, -9178.46, -113.038, 71.0649, 0, 0, 0, 42218),
(177929, 14, -9198.04, -113.459, 71.0567, 0, 0, 0, 42218),
(177929, 15, -9215.31, -109.018, 71.1478, 0, 0, 0, 42218),
(177929, 16, -9241.91, -99.1684, 70.5371, 0, 0, 0, 42218),
(177929, 17, -9265.26, -81.1538, 68.8238, 0, 0, 0, 42218),
(177929, 18, -9285.91, -64.945, 67.9513, 0, 0, 0, 42218),
(177929, 19, -9301.52, -58.4047, 66.9757, 0, 0, 0, 42218),
(177929, 20, -9315.32, -55.3839, 66.6466, 0, 0, 0, 42218),
(177929, 21, -9338.27, -50.3918, 65.5935, 0, 0, 0, 42218),
(177929, 22, -9350.55, -42.4498, 64.9096, 0, 0, 0, 42218),
(177929, 23, -9360.87, -32.225, 63.8498, 0, 0, 0, 42218),
(177929, 24, -9389.23, -2.19453, 60.7995, 0, 0, 0, 42218),
(177929, 25, -9433.95, 48.662, 56.5678, 0, 0, 0, 42218),
(177929, 26, -9447.02, 60.0515, 56.0078, 0, 0, 0, 42218),
(177929, 27, -9463.83, 64.1504, 55.869, 0, 0, 0, 42218),
(177929, 28, -9474.33, 64.6031, 56.1456, 0, 0, 0, 42218),
(177929, 29, -9473.84, 63.9308, 56.1005, 0, 0, 0, 42218),
(177929, 30, -9452.96, 61.7088, 55.8902, 0, 0, 0, 42218),
(177929, 31, -9441.44, 56.8974, 55.9855, 0, 0, 0, 42218),
(177929, 32, -9424.74, 39.5222, 57.0996, 0, 0, 0, 42218),
(177929, 33, -9394.29, 4.31402, 60.1032, 0, 0, 0, 42218),
(177929, 34, -9355.13, -37.6422, 64.4623, 0, 0, 0, 42218),
(177929, 35, -9344.59, -46.9465, 65.2829, 0, 0, 0, 42218),
(177929, 36, -9329.58, -52.6687, 66.0623, 0, 0, 0, 42218),
(177929, 37, -9311.08, -56.4848, 66.8229, 0, 0, 0, 42218),
(177929, 38, -9285.09, -65.3491, 67.947, 0, 0, 0, 42218),
(177929, 39, -9259.91, -84.8358, 69.3582, 0, 0, 0, 42218),
(177929, 40, -9234.31, -101.795, 70.8775, 0, 0, 0, 42218),
(177929, 41, -9204.2, -111.411, 71.0834, 0, 0, 0, 42218),
(177929, 42, -9173.54, -112.249, 71.5008, 0, 0, 0, 42218),
(177929, 43, -9159.76, -107.577, 72.8737, 0, 0, 0, 42218),
(177929, 44, -9133.37, -90.478, 76.5183, 0, 0, 0, 42218),
(177929, 45, -9097.92, -64.54, 84.2097, 0, 0, 0, 42218),
(177929, 46, -9071.38, -43.1063, 87.9831, 0, 0, 0, 42218),
(177929, 47, -9050.94, -44.4244, 88.2899, 0, 0, 0, 42218),
(177929, 48, -9045.82, -54.3558, 88.111, 0, 0, 0, 42218),
(177929, 49, -9046.37, -67.5953, 88.1579, 0, 0, 0, 42218),
(177929, 50, -9051.11, -85.4033, 88.0125, 0, 0, 0, 42218),
(177929, 51, -9045.93, -95.2949, 88.0497, 0, 0, 0, 42218),
(177929, 52, -9035.29, -101.639, 87.686, 0, 0, 0, 42218),
(177929, 53, -9030.59, -101.587, 87.6319, 0, 0, 0, 42218),
(177929, 54, -9017.4, -92.0667, 86.8234, 0, 0, 0, 42218),
(177929, 55, -9006.6, -84.9445, 86.267, 0, 0, 0, 42218);

DELETE FROM `creature_formations` WHERE `leaderGUID` = 177929;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(177929, 177929, 4, 90, 2),
(177929, 177930, 4, 30, 2),
(177929, 177931, 4, 330, 2),
(177929, 177932, 4, 360, 2);

DELETE FROM `creature` WHERE `guid` IN (179870, 179872, 179875, 178447) AND `id` = 42218;
DELETE FROM `creature_addon` WHERE `guid` IN (179870, 179872, 179875, 178447);
DELETE FROM `waypoint_data` WHERE `id` IN (179870, 179872, 179875, 178447);

UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2, `position_x` = -9599.69, `position_y` = -850.821, `position_z` = 43.5444 WHERE `guid` = 178787 AND `id` = 42218;
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2, `position_x` = -9383.01, `position_y` = 104.414, `position_z` = 59.8336 WHERE `guid` = 178448 AND `id` = 42218;

UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0, `position_x` = -9599.69, `position_y` = -850.821, `position_z` = 43.5444 WHERE `guid` IN (178789, 178792, 178795, 178791, 178794, 178788, 178790, 178793) AND `id` = 42218;
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0, `position_x` = -9383.01, `position_y` = 104.414, `position_z` = 59.8336 WHERE `guid` IN (178445, 179869, 178449, 179871, 179874, 179873, 179877, 179876) AND `id` = 42218;

DELETE FROM `creature_addon` WHERE `guid` IN (178787, 178789, 178792, 178795, 178791, 178794, 178788, 178790, 178793,
                                              178448, 178445, 179869, 178449, 179871, 179874, 179873, 179877, 179876);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(178787, 178787, 29284, 0, 1, 0, "78855"),
(178789, 0, 29284, 0, 1, 0, "78855"),
(178792, 0, 29284, 0, 1, 0, "78855"),
(178795, 0, 29284, 0, 1, 0, "78855"),
(178791, 0, 29284, 0, 1, 0, "78855"),
(178794, 0, 29284, 0, 1, 0, "78855"),
(178788, 0, 29284, 0, 1, 0, "78855"),
(178790, 0, 29284, 0, 1, 0, "78855"),
(178793, 0, 29284, 0, 1, 0, "78855"),

(178448, 178448, 29284, 0, 1, 0, "78855"),
(178445, 0, 29284, 0, 1, 0, "78855"),
(179869, 0, 29284, 0, 1, 0, "78855"),
(178449, 0, 29284, 0, 1, 0, "78855"),
(179871, 0, 29284, 0, 1, 0, "78855"),
(179874, 0, 29284, 0, 1, 0, "78855"),
(179873, 0, 29284, 0, 1, 0, "78855"),
(179877, 0, 29284, 0, 1, 0, "78855"),
(179876, 0, 29284, 0, 1, 0, "78855");

DELETE FROM `waypoint_data` WHERE `id` IN (178787, 178789, 178792, 178795, 178791, 178794, 178788, 178790, 178793,
                                           178448, 178445, 179869, 178449, 179871, 179874, 179873, 179877, 179876);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `entry`) VALUES
(178787, 1, -9599.69, -850.821, 43.5444, 0, 0, 0, 0, 100, 42218),
(178787, 2, -9588.24, -864.942, 43.7228, 0, 0, 0, 0, 100, 42218),
(178787, 3, -9582.6, -883.82, 43.8299, 0, 0, 0, 0, 100, 42218),
(178787, 4, -9581.03, -902.532, 43.6936, 0, 0, 0, 0, 100, 42218),
(178787, 5, -9583.35, -918.922, 43.7452, 0, 0, 0, 0, 100, 42218),
(178787, 6, -9588.3, -932.881, 43.4867, 0, 0, 0, 0, 100, 42218),
(178787, 7, -9603.29, -951.21, 43.8373, 0, 0, 0, 0, 100, 42218),
(178787, 8, -9615.51, -970.789, 43.569, 0, 0, 0, 0, 100, 42218),
(178787, 9, -9620.19, -988.721, 43.1439, 0, 0, 0, 0, 100, 42218),
(178787, 10, -9620.95, -999.542, 42.2882, 0, 0, 0, 0, 100, 42218),
(178787, 11, -9619.82, -982.894, 43.5259, 0, 0, 0, 0, 100, 42218),
(178787, 12, -9615.19, -968.207, 43.6481, 0, 0, 0, 0, 100, 42218),
(178787, 13, -9609.2, -957.915, 43.6405, 0, 0, 0, 0, 100, 42218),
(178787, 14, -9594.76, -939.444, 43.78, 0, 0, 0, 0, 100, 42218),
(178787, 15, -9587.18, -926.721, 43.3948, 0, 0, 0, 0, 100, 42218),
(178787, 16, -9582.71, -912.978, 43.7226, 0, 0, 0, 0, 100, 42218),
(178787, 17, -9581.16, -893.448, 43.423, 0, 0, 0, 0, 100, 42218),
(178787, 18, -9584.19, -876.811, 43.8177, 0, 0, 0, 0, 100, 42218),
(178787, 19, -9590.09, -863.866, 43.7094, 0, 0, 0, 0, 100, 42218),
(178787, 20, -9599.96, -850.428, 43.5915, 0, 0, 0, 0, 100, 42218),
(178787, 21, -9629.99, -818.932, 43.8425, 0, 0, 0, 0, 100, 42218),
(178787, 22, -9646.04, -799.35, 43.4826, 0, 0, 0, 0, 100, 42218),
(178787, 23, -9649.72, -790.901, 43.6229, 0, 0, 0, 0, 100, 42218),
(178787, 24, -9652, -770.971, 44.0047, 0, 0, 0, 0, 100, 42218),
(178787, 25, -9652.45, -759.318, 44.4417, 0, 0, 0, 0, 100, 42218),
(178787, 26, -9656.07, -740.056, 44.5474, 0, 0, 0, 0, 100, 42218),
(178787, 27, -9654.37, -721.701, 44.5719, 0, 0, 0, 0, 100, 42218),
(178787, 28, -9646.76, -690.187, 47.0927, 0, 0, 0, 0, 100, 42218),
(178787, 29, -9642.34, -664.429, 49.2252, 0, 0, 0, 0, 100, 42218),
(178787, 30, -9633.85, -649.793, 49.7451, 0, 0, 0, 0, 100, 42218),
(178787, 31, -9624.54, -633.222, 51.4311, 0, 0, 0, 0, 100, 42218),
(178787, 32, -9621.56, -618.349, 52.0303, 0, 0, 0, 0, 100, 42218),
(178787, 33, -9618.98, -570.205, 54.3546, 0, 0, 0, 0, 100, 42218),
(178787, 34, -9614.93, -542.839, 54.3399, 0, 0, 0, 0, 100, 42218),
(178787, 35, -9605.82, -524.117, 55.7588, 0, 0, 0, 0, 100, 42218),
(178787, 36, -9594.49, -505.6, 57.421, 0, 0, 0, 0, 100, 42218),
(178787, 37, -9588.86, -485.568, 57.7277, 0, 0, 0, 0, 100, 42218),
(178787, 38, -9590.32, -471.729, 57.7572, 0, 0, 0, 0, 100, 42218),
(178787, 39, -9611.19, -428.135, 57.3888, 0, 0, 0, 0, 100, 42218),
(178787, 40, -9618.03, -399.727, 57.8593, 0, 0, 0, 0, 100, 42218),
(178787, 41, -9619.88, -375.817, 57.6191, 0, 0, 0, 0, 100, 42218),
(178787, 42, -9620.29, -317.664, 57.5491, 0, 0, 0, 0, 100, 42218),
(178787, 43, -9615.45, -280.3, 57.8475, 0, 0, 0, 0, 100, 42218),
(178787, 44, -9605.82, -244.049, 57.2141, 0, 0, 0, 0, 100, 42218),
(178787, 45, -9588.13, -200.957, 57.6191, 0, 0, 0, 0, 100, 42218),
(178787, 46, -9575.05, -161.134, 57.5732, 0, 0, 0, 0, 100, 42218),
(178787, 47, -9552.48, -133.648, 57.3999, 0, 0, 0, 0, 100, 42218),
(178787, 48, -9548.82, -114.38, 57.6067, 0, 0, 0, 0, 100, 42218),
(178787, 49, -9548.03, -69.6535, 57.3625, 0, 0, 0, 0, 100, 42218),
(178787, 50, -9539.99, -35.3127, 56.4262, 0, 0, 0, 0, 100, 42218),
(178787, 51, -9497.92, 49.2135, 55.914, 0, 0, 0, 0, 100, 42218),
(178787, 52, -9506.98, 28.7376, 56.4141, 0, 0, 0, 0, 100, 42218),
(178787, 53, -9536.67, -29.7596, 55.7819, 0, 0, 0, 0, 100, 42218),
(178787, 54, -9542.28, -41.8712, 56.5395, 0, 0, 0, 0, 100, 42218),
(178787, 55, -9546.89, -63.4407, 57.0751, 0, 0, 0, 0, 100, 42218),
(178787, 56, -9549.25, -91.5616, 57.6199, 0, 0, 0, 0, 100, 42218),
(178787, 57, -9550.29, -126.391, 57.4935, 0, 0, 0, 0, 100, 42218),
(178787, 58, -9556.88, -140.982, 57.3447, 0, 0, 0, 0, 100, 42218),
(178787, 59, -9572.89, -156.212, 57.3732, 0, 0, 0, 0, 100, 42218),
(178787, 60, -9582.26, -182.315, 57.5975, 0, 0, 0, 0, 100, 42218),
(178787, 61, -9587.26, -199.332, 57.5504, 0, 0, 0, 0, 100, 42218),
(178787, 62, -9607.07, -248.701, 57.2221, 0, 0, 0, 0, 100, 42218),
(178787, 63, -9615.86, -281.367, 57.8163, 0, 0, 0, 0, 100, 42218),
(178787, 64, -9620.34, -319.485, 57.5662, 0, 0, 0, 0, 100, 42218),
(178787, 65, -9620.85, -366.85, 57.3349, 0, 0, 0, 0, 100, 42218),
(178787, 66, -9617.54, -405.323, 57.3193, 0, 0, 0, 0, 100, 42218),
(178787, 67, -9610.85, -430.099, 57.3968, 0, 0, 0, 0, 100, 42218),
(178787, 68, -9591.9, -467.184, 57.761, 0, 0, 0, 0, 100, 42218),
(178787, 69, -9589.38, -486.818, 57.7368, 0, 0, 0, 0, 100, 42218),
(178787, 70, -9595.13, -506.407, 57.4069, 0, 0, 0, 0, 100, 42218),
(178787, 71, -9611.46, -531.539, 54.7528, 0, 0, 0, 0, 100, 42218),
(178787, 72, -9615.86, -547.487, 54.3732, 0, 0, 0, 0, 100, 42218),
(178787, 73, -9621.22, -594.189, 53.3917, 0, 0, 0, 0, 100, 42218),
(178787, 74, -9623.18, -627.03, 51.6469, 0, 0, 0, 0, 100, 42218),
(178787, 75, -9630.86, -645.813, 50.4042, 0, 0, 0, 0, 100, 42218),
(178787, 76, -9642.42, -664.445, 49.2229, 0, 0, 0, 0, 100, 42218),
(178787, 77, -9649.59, -700.208, 46.1331, 0, 0, 0, 0, 100, 42218),
(178787, 78, -9655.82, -723.051, 44.5423, 0, 0, 0, 0, 100, 42218),
(178787, 79, -9656.38, -740.183, 44.5549, 0, 0, 0, 0, 100, 42218),
(178787, 80, -9651.36, -766.415, 44.1197, 0, 0, 0, 0, 100, 42218),
(178787, 81, -9650.83, -788.338, 43.8092, 0, 0, 0, 0, 100, 42218),
(178787, 82, -9641.23, -807.485, 43.6331, 0, 0, 0, 0, 100, 42218),
(178787, 83, -9633.3, -816.971, 43.8162, 0, 0, 0, 0, 100, 42218),
(178787, 84, -9621.53, -828.625, 43.6619, 0, 0, 0, 0, 100, 42218),

(178448, 1, -9383.01, 104.414, 59.8336, 0, 0, 0, 0, 100, 42218),
(178448, 2, -9368.5, 108.266, 60.847, 0, 0, 0, 0, 100, 42218),
(178448, 3, -9349.11, 116.921, 62.5884, 0, 0, 0, 0, 100, 42218),
(178448, 4, -9325.23, 131.598, 64.1205, 0, 0, 0, 0, 100, 42218),
(178448, 5, -9310.44, 140.783, 65.4548, 0, 0, 0, 0, 100, 42218),
(178448, 6, -9290.87, 149.02, 66.4885, 0, 0, 0, 0, 100, 42218),
(178448, 7, -9270.26, 151.894, 67.0837, 0, 0, 0, 0, 100, 42218),
(178448, 8, -9256.19, 157.498, 67.6996, 0, 0, 0, 0, 100, 42218),
(178448, 9, -9246.62, 165.255, 67.9183, 0, 0, 0, 0, 100, 42218),
(178448, 10, -9233.35, 184.822, 67.6321, 0, 0, 0, 0, 100, 42218),
(178448, 11, -9219.51, 202.75, 68.8622, 0, 0, 0, 0, 100, 42218),
(178448, 12, -9192.92, 229.029, 71.7499, 0, 0, 0, 0, 100, 42218),
(178448, 13, -9184.31, 246.544, 73.1934, 0, 0, 0, 0, 100, 42218),
(178448, 14, -9180.71, 263.004, 74.4242, 0, 0, 0, 0, 100, 42218),
(178448, 15, -9179.52, 281.933, 75.9409, 0, 0, 0, 0, 100, 42218),
(178448, 16, -9180.79, 313.479, 79.2692, 0, 0, 0, 0, 100, 42218),
(178448, 17, -9178.27, 330.988, 82.0722, 0, 0, 0, 0, 100, 42218),
(178448, 18, -9171.33, 344.613, 85.3042, 0, 0, 0, 0, 100, 42218),
(178448, 19, -9159.41, 358.652, 89.0692, 0, 0, 0, 0, 100, 42218),
(178448, 20, -9140.27, 378.555, 90.6682, 0, 0, 0, 0, 100, 42218),
(178448, 21, -9125.48, 390.891, 91.5189, 0, 0, 0, 0, 100, 42218),
(178448, 22, -9109.93, 402.471, 92.6044, 0, 0, 0, 0, 100, 42218),
(178448, 23, -9123.98, 392.407, 91.7277, 0, 0, 0, 0, 100, 42218),
(178448, 24, -9143.37, 375.207, 90.6907, 0, 0, 0, 0, 100, 42218),
(178448, 25, -9165.3, 350.741, 87.2025, 0, 0, 0, 0, 100, 42218),
(178448, 26, -9176.93, 333.816, 82.8446, 0, 0, 0, 0, 100, 42218),
(178448, 27, -9180.21, 319.028, 79.9468, 0, 0, 0, 0, 100, 42218),
(178448, 28, -9181.04, 302.769, 78.4457, 0, 0, 0, 0, 100, 42218),
(178448, 29, -9179.68, 269.244, 74.9092, 0, 0, 0, 0, 100, 42218),
(178448, 30, -9183.16, 250.743, 73.4896, 0, 0, 0, 0, 100, 42218),
(178448, 31, -9189.66, 233.375, 71.9653, 0, 0, 0, 0, 100, 42218),
(178448, 32, -9196.51, 224.529, 71.5633, 0, 0, 0, 0, 100, 42218),
(178448, 33, -9208.71, 213.096, 70.4991, 0, 0, 0, 0, 100, 42218),
(178448, 34, -9230.81, 188.217, 67.7736, 0, 0, 0, 0, 100, 42218),
(178448, 35, -9246.16, 165.613, 67.9092, 0, 0, 0, 0, 100, 42218),
(178448, 36, -9258.37, 155.716, 67.6081, 0, 0, 0, 0, 100, 42218),
(178448, 37, -9270.76, 151.579, 67.0683, 0, 0, 0, 0, 100, 42218),
(178448, 38, -9291.52, 148.527, 66.4542, 0, 0, 0, 0, 100, 42218),
(178448, 39, -9305.09, 143.073, 65.763, 0, 0, 0, 0, 100, 42218),
(178448, 40, -9341.06, 122.068, 63.2984, 0, 0, 0, 0, 100, 42218),
(178448, 41, -9353.72, 113.916, 62.0959, 0, 0, 0, 0, 100, 42218),
(178448, 42, -9372.01, 106.995, 60.6684, 0, 0, 0, 0, 100, 42218),
(178448, 43, -9396.75, 99.7925, 58.7783, 0, 0, 0, 0, 100, 42218),
(178448, 44, -9416.34, 86.9031, 56.9933, 0, 0, 0, 0, 100, 42218),
(178448, 45, -9435.53, 72.0034, 56.0894, 0, 0, 0, 0, 100, 42218),
(178448, 46, -9420.2, 83.8999, 56.6448, 0, 0, 0, 0, 100, 42218),
(178448, 47, -9401.91, 96.6638, 58.4878, 0, 0, 0, 0, 100, 42218);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (178787, 178448);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(178787, 178787, 0, 0, 2),
(178787, 178789, 3, 90, 2),
(178787, 178792, 5, 45, 2),
(178787, 178795, 8, 20, 2),
(178787, 178791, 4, 360, 2),
(178787, 178794, 8, 360, 2),
(178787, 178788, 3, 270, 2),
(178787, 178790, 5, 315, 2),
(178787, 178793, 8, 340, 2),

(178448, 178448, 0, 0, 2),
(178448, 178445, 3, 90, 2),
(178448, 179869, 5, 45, 2),
(178448, 179871, 8, 20, 2),
(178448, 179873, 4, 360, 2),
(178448, 179874, 8, 360, 2),
(178448, 178449, 3, 270, 2),
(178448, 179877, 5, 315, 2),
(178448, 179876, 8, 340, 2);

UPDATE `creature_template` SET `ScriptName` = "npc_brother_paxton" WHERE `entry` = 951;
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 177921 AND `id` = 951;
DELETE FROM `creature_template_addon` WHERE `entry` = 951;
DELETE FROM `creature_addon` WHERE `guid` = 177921;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(177921, 177921, 1);

DELETE FROM `waypoint_data` WHERE `id` = 177921;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`, `entry`) VALUES
(177921, 1, -8833.074, -152.085, 80.349, 0, 951),
(177921, 2, -8830.21, -146.632, 80.5787, 0, 951),
(177921, 3, -8826.04, -146.105, 80.6188, 0, 951),
(177921, 4, -8822.08, -146.456, 80.877, 0, 951),
(177921, 5, -8817.2, -150.924, 81.5878, 0, 951),
(177921, 6, -8813.55, -153.822, 82.0283, 8000, 951),
(177921, 7, -8811.99, -159.78, 81.614, 0, 951),
(177921, 8, -8810.78, -164.51, 81.306, 0, 951),
(177921, 9, -8813.96, -163.8, 81.108, 0, 951),
(177921, 10, -8816.21, -156.19, 81.452, 0, 951),
(177921, 11, -8823.21, -151.63, 80.539, 0, 951),
(177921, 12, -8833.074, -152.085, 80.349, 0, 951),
(177921, 13, -8830.21, -146.632, 80.5787, 0, 951),
(177921, 14, -8826.04, -146.105, 80.6188, 0, 951),
(177921, 15, -8822.08, -146.456, 80.877, 8000, 951),
(177921, 16, -8817.2, -150.924, 81.5878, 0, 951),
(177921, 17, -8813.55, -153.822, 82.0283, 0, 951),
(177921, 18, -8811.99, -159.78, 81.614, 0, 951),
(177921, 19, -8810.78, -164.51, 81.306, 0, 951),
(177921, 20, -8813.96, -163.8, 81.108, 0, 951),
(177921, 21, -8816.21, -156.19, 81.452, 0, 951),
(177921, 22, -8823.21, -151.63, 80.539, 0, 951),
(177921, 23, -8833.074, -152.085, 80.349, 8000, 951),
(177921, 24, -8830.21, -146.632, 80.5787, 0, 951),
(177921, 25, -8826.04, -146.105, 80.6188, 0, 951),
(177921, 26, -8822.08, -146.456, 80.877, 0, 951),
(177921, 27, -8817.2, -150.924, 81.5878, 0, 951),
(177921, 28, -8813.55, -153.822, 82.0283, 0, 951),
(177921, 29, -8811.99, -159.78, 81.614, 0, 951),
(177921, 30, -8810.78, -164.51, 81.306, 0, 951),
(177921, 31, -8813.96, -163.8, 81.108, 0, 951),
(177921, 32, -8816.21, -156.19, 81.452, 0, 951),
(177921, 33, -8823.21, -151.63, 80.539, 0, 951),
(177921, 34, -8833.074, -152.085, 80.349, 8000, 951),
(177921, 35, -8830.21, -146.632, 80.5787, 0, 951),
(177921, 36, -8826.04, -146.105, 80.6188, 0, 951),
(177921, 37, -8822.08, -146.456, 80.877, 0, 951),
(177921, 38, -8817.2, -150.924, 81.5878, 0, 951),
(177921, 39, -8813.55, -153.822, 82.0283, 0, 951),
(177921, 40, -8811.99, -159.78, 81.614, 0, 951),
(177921, 41, -8810.78, -164.51, 81.306, 8000, 951),
(177921, 42, -8813.96, -163.8, 81.108, 0, 951),
(177921, 43, -8816.21, -156.19, 81.452, 0, 951),
(177921, 44, -8823.21, -151.63, 80.539, 0, 951),
(177921, 45, -8833.074, -152.085, 80.349, 0, 951),
(177921, 46, -8830.21, -146.632, 80.5787, 0, 951),
(177921, 47, -8826.04, -146.105, 80.6188, 0, 951),
(177921, 48, -8822.08, -146.456, 80.877, 0, 951),
(177921, 49, -8817.2, -150.924, 81.5878, 0, 951),
(177921, 50, -8813.55, -153.822, 82.0283, 0, 951),
(177921, 51, -8811.99, -159.78, 81.614, 0, 951),
(177921, 52, -8810.78, -164.51, 81.306, 8000, 951),
(177921, 53, -8813.96, -163.8, 81.108, 0, 951),
(177921, 54, -8816.21, -156.19, 81.452, 0, 951),
(177921, 55, -8823.21, -151.63, 80.539, 0, 951),
(177921, 56, -8833.074, -152.085, 80.349, 0, 951),
(177921, 57, -8830.21, -146.632, 80.5787, 0, 951),
(177921, 58, -8826.04, -146.105, 80.6188, 0, 951),
(177921, 59, -8822.08, -146.456, 80.877, 0, 951),
(177921, 60, -8817.2, -150.924, 81.5878, 0, 951),
(177921, 61, -8813.55, -153.822, 82.0283, 8000, 951),
(177921, 62, -8811.99, -159.78, 81.614, 0, 951),
(177921, 63, -8810.78, -164.51, 81.306, 8000, 951),
(177921, 64, -8813.96, -163.8, 81.108, 0, 951),
(177921, 65, -8816.21, -156.19, 81.452, 0, 951),
(177921, 66, -8823.21, -151.63, 80.539, 0, 951);

DELETE FROM `creature_text` WHERE `entry` IN (951, 49869);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(951, 0, 0, "BY THE LIGHT BE RENEWED!", "", 12, 0, 100, 0, 0, 0, "Brother Paxton"),
(951, 0, 1, "AND I LAY MY HANDS UPON YOU!", "", 12, 0, 100, 0, 0, 0, "Brother Paxton"),
(951, 0, 2, "Let the Holy Light embrace you!", "", 12, 0, 100, 0, 0, 0, "Brother Paxton"),
(951, 1, 0, "Be healed, $gbrother:sister;!", "", 12, 0, 100, 0, 0, 0, "Brother Paxton"),
(951, 1, 1, "FIGHT ON, $GBROTHER:SISTER;!", "", 12, 0, 100, 0, 0, 0, "Brother Paxton"),

(49869, 0, 0, "HELP!", "", 12, 0, 100, 0, 0, 0, "Stormwind Infantry"),
(49869, 0, 1, "I need a heal!", "", 12, 0, 100, 0, 0, 0, "Stormwind Infantry"),
(49869, 0, 2, "I could use a heal, brother!", "", 12, 0, 100, 0, 0, 0, "Stormwind Infantry"),
(49869, 0, 3, "Make yourself useful and heal me, Paxton!", "", 12, 0, 100, 0, 0, 0, "Stormwind Infantry"),
(49869, 1, 0, "Come, monsters! We will crush you!", "", 14, 0, 15, 22, 0, 0, "Stormwind Infantry"),
(49869, 1, 1, "I'll kill a hundred more of your battle worgs!", "", 14, 0, 15, 22, 0, 0, "Stormwind Infantry"),
(49869, 1, 2, "Look alive, men! There are orcs and worgs about!", "", 14, 0, 15, 22, 0, 0, "Stormwind Infantry"),
(49869, 1, 3, "Your filthy dogs won't be enough!", "", 14, 0, 15, 22, 0, 0, "Stormwind Infantry"),
(49869, 1, 4, "Your worgs are no match for the might of Stormwind!", "", 14, 0, 15, 22, 0, 0, "Stormwind Infantry");

DELETE FROM `creature_text` WHERE `entry` = 49874;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(49874, 0, 0, "Orc KILL $r!", "Orc KILL $r!", 12, 0, 50, 0, 0, 0, "Blackrock Spy"),
(49874, 0, 1, "Blackrock take forest!", "Blackrock take forest!", 12, 0, 50, 0, 0, 0, "Blackrock Spy"),
(49874, 0, 2, "The grapes were VERY TASTY!", "The grapes were VERY TASTY!", 12, 0, 50, 0, 0, 0, "Blackrock Spy"),
(49874, 0, 3, "Beg for life!", "Beg for life!", 12, 0, 50, 0, 0, 0, "Blackrock Spy"),
(49874, 0, 4, "Eat you!", "Eat you!", 12, 0, 50, 0, 0, 0, "Blackrock Spy");

UPDATE `creature_template` SET `ScriptName` = "npc_blackrock_invader" WHERE `entry` = 42937;
DELETE FROM `creature_text` WHERE `entry` = 42937;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(42937, 0, 0, "Orc KILL $r!", "Orc KILL $r!", 12, 0, 50, 0, 0, 0, "Blackrock Invader"),
(42937, 0, 1, "Blackrock take forest!", "Blackrock take forest!", 12, 0, 50, 0, 0, 0, "Blackrock Invader"),
(42937, 0, 2, "The grapes were VERY TASTY!", "The grapes were VERY TASTY!", 12, 0, 50, 0, 0, 0, "Blackrock Invader"),
(42937, 0, 3, "Beg for life!", "Beg for life!", 12, 0, 50, 0, 0, 0, "Blackrock Invader"),
(42937, 0, 4, "Eat you!", "Eat you!", 12, 0, 50, 0, 0, 0, "Blackrock Invader");

UPDATE `creature_template` SET `ScriptName` = "npc_goblin_assassin" WHERE `entry` = 50039;
DELETE FROM `creature_text` WHERE `entry` = 50039;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(50039, 0, 0, "We'll kill anybody for the right price!", "We'll kill anybody for the right price!", 12, 0, 50, 0, 0, 0, "Goblin Assassin"),
(50039, 0, 1, "Time to join your friends, kissin' the dirt!", "Time to join your friends, kissin' the dirt!", 12, 0, 50, 0, 0, 0, "Goblin Assassin"),
(50039, 0, 2, "DIE!!!", "DIE!!!", 12, 0, 50, 0, 0, 0, "Goblin Assassin"),
(50039, 0, 3, "We're gonna burn this place to the ground!", "We're gonna burn this place to the ground!", 12, 0, 50, 0, 0, 0, "Goblin Assassin");
