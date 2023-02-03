-- Instructor Mossthorn
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 563434 AND `id` = 57754;

DELETE FROM `creature_template_addon` WHERE `entry` = 57754;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(57754, 563434, 0, 0, 1, 0, "");

DELETE FROM `waypoint_data` WHERE `id` = 563434;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `entry`) VALUES
(563434, 1, 1456.097, 3400.327, 171.1617, 0, 30000, 0, 57754),
(563434, 2, 1449.597, 3404.077, 171.1617, 2.186576, 10000, 0, 57754),
(563434, 3, 1451.847, 3416.077, 171.4117, 0, 0, 0, 57754),
(563434, 4, 1442.097, 3421.827, 171.4117, 4.621339, 15000, 0, 57754),
(563434, 5, 1439.097, 3431.827, 171.4117, 0, 0, 0, 57754),
(563434, 6, 1442.597, 3439.577, 171.4117, 2.51673, 28000, 0, 57754),
(563434, 7, 1452.847, 3438.327, 171.4117, 0.8980953, 12000, 0, 57754),
(563434, 8, 1465.597, 3434.077, 171.4117, 2.505686, 10000, 0, 57754),
(563434, 9, 1473.347, 3433.077, 171.4117, 4.309892, 15000, 0, 57754),
(563434, 10, 1480.347, 3439.327, 171.4117, 0.4008824, 10000, 0, 57754),
(563434, 11, 1487.597, 3437.327, 171.4117, 1.280082, 10000, 0, 57754),
(563434, 12, 1486.097, 3423.827, 171.4117, 0.3201315, 15000, 0, 57754),
(563434, 13, 1482.597, 3413.827, 171.4117, 0, 12000, 0, 57754),
(563434, 14, 1473.347, 3414.327, 171.4117, 1.860022, 10000, 0, 57754),
(563434, 15, 1466.847, 3413.327, 171.4117, 1.157754, 10000, 0, 57754),
(563434, 16, 1463.097, 3405.827, 171.4117, 0, 0, 0, 57754);

-- Lamplighter Deng
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 561949 AND `id` = 64929;

UPDATE `creature_template` SET `gossip_menu_id` = 14616 WHERE `entry` = 64929;

DELETE FROM `gossip_menu` WHERE `entry` = 14616 AND `text_id` = 20677;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(14616, 20677);

DELETE FROM `npc_text` WHERE `ID` = 20677;
INSERT INTO `npc_text` (`ID`, `text0_0`, `prob0`, `em0_0`) VALUES
(20677, "Whoever said they'd rather light a candle than curse the darkness...$b$bWell, they probably haven't lit as many candles as me.", 1, 6);

DELETE FROM `creature_template_addon` WHERE `entry` = 64929;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(64929, 561949, 0, 0, 1, 0, "126968");

DELETE FROM `waypoint_data` WHERE `id` = 561949;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(561949, 1, 1360.582, 3339.856, 128.2271, 0, 0, 0, 0, 100, 0, 64929),
(561949, 2, 1357.241, 3342.743, 127.9493, 0, 7000, 0, 0, 100, 0, 64929),
(561949, 3, 1360.535, 3351.983, 127.2741, 0, 0, 0, 0, 100, 0, 64929),
(561949, 4, 1357.108, 3358.502, 126.8627, 0, 0, 0, 0, 100, 0, 64929),
(561949, 5, 1353.688, 3365.59, 126.3223, 0, 0, 0, 0, 100, 0, 64929),
(561949, 6, 1351.611, 3371.378, 125.9597, 0, 0, 0, 0, 100, 0, 64929),
(561949, 7, 1350.67, 3378.942, 125.4627, 0, 0, 0, 0, 100, 0, 64929),
(561949, 8, 1349.865, 3385.296, 125.2127, 0, 7000, 0, 0, 100, 0, 64929),
(561949, 9, 1342.198, 3395.269, 124.7178, 0, 0, 0, 0, 100, 0, 64929),
(561949, 10, 1339.592, 3404.035, 124.4632, 0, 0, 0, 0, 100, 0, 64929),
(561949, 11, 1335.146, 3413.649, 123.4176, 0, 0, 0, 0, 100, 0, 64929),
(561949, 12, 1329.754, 3418.934, 122.2499, 0, 0, 0, 0, 100, 0, 64929),
(561949, 13, 1323.12, 3423.364, 121.0395, 0, 0, 0, 0, 100, 0, 64929),
(561949, 14, 1318.514, 3425.088, 120.4955, 0, 0, 0, 0, 100, 0, 64929),
(561949, 15, 1313.938, 3426.073, 120.4435, 0, 7000, 0, 0, 100, 0, 64929),
(561949, 16, 1310.609, 3438.904, 116.816, 0, 0, 0, 0, 100, 0, 64929),
(561949, 17, 1304.125, 3446.715, 114.2256, 0, 0, 0, 0, 100, 0, 64929),
(561949, 18, 1298.807, 3449.3, 112.8712, 0, 0, 0, 0, 100, 0, 64929),
(561949, 19, 1293.134, 3453.627, 110.9211, 0, 0, 0, 0, 100, 0, 64929),
(561949, 20, 1289.141, 3459.107, 108.7542, 0, 0, 0, 0, 100, 0, 64929),
(561949, 21, 1287.535, 3464.891, 106.9646, 0, 7000, 0, 0, 100, 0, 64929),
(561949, 22, 1271.95, 3460.984, 105.7406, 0, 0, 0, 0, 100, 0, 64929),
(561949, 23, 1264.576, 3456.448, 105.4586, 0, 0, 0, 0, 100, 0, 64929),
(561949, 24, 1254.865, 3454.894, 104.3583, 0, 0, 0, 0, 100, 0, 64929),
(561949, 25, 1248.146, 3456.349, 103.4482, 0, 0, 0, 0, 100, 0, 64929),
(561949, 26, 1240.311, 3458.163, 102.7581, 0, 7000, 0, 0, 100, 0, 64929),
(561949, 27, 1249.127, 3454.832, 103.6737, 0, 0, 0, 0, 100, 0, 64929),
(561949, 28, 1256.859, 3455.244, 104.5521, 0, 0, 0, 0, 100, 0, 64929),
(561949, 29, 1264.509, 3458.412, 105.2869, 0, 0, 0, 0, 100, 0, 64929),
(561949, 30, 1272.019, 3462.195, 105.4585, 0, 0, 0, 0, 100, 0, 64929),
(561949, 31, 1278.932, 3467.925, 104.8682, 0, 0, 0, 0, 100, 0, 64929),
(561949, 32, 1281.521, 3473.01, 104.0294, 0, 0, 0, 0, 100, 0, 64929),
(561949, 33, 1281.641, 3478.479, 103.2267, 0, 0, 0, 0, 100, 0, 64929),
(561949, 34, 1279.991, 3489.906, 101.2307, 0, 0, 0, 0, 100, 0, 64929),
(561949, 35, 1277.778, 3500.26, 98.66097, 0, 0, 0, 0, 100, 0, 64929),
(561949, 36, 1273.719, 3503.588, 97.96664, 0, 7000, 0, 0, 100, 0, 64929),
(561949, 37, 1276.958, 3516.68, 95.31112, 0, 0, 0, 0, 100, 0, 64929),
(561949, 38, 1276.556, 3522.365, 94.5815, 0, 0, 0, 0, 100, 0, 64929),
(561949, 39, 1277.517, 3529.936, 93.70272, 0, 0, 0, 0, 100, 0, 64929),
(561949, 40, 1280.082, 3538.131, 93.59853, 0, 0, 0, 0, 100, 0, 64929),
(561949, 41, 1281.16, 3542.923, 93.85292, 0, 0, 0, 0, 100, 0, 64929),
(561949, 42, 1283.165, 3546.595, 93.86806, 0, 7000, 0, 0, 100, 0, 64929),
(561949, 43, 1280.934, 3554.821, 92.91847, 0, 0, 0, 0, 100, 0, 64929),
(561949, 44, 1283.958, 3561.626, 92.80116, 0, 0, 0, 0, 100, 0, 64929),
(561949, 45, 1288.576, 3567.834, 91.9909, 0, 0, 0, 0, 100, 0, 64929),
(561949, 46, 1293.58, 3576.056, 91.11822, 0, 0, 0, 0, 100, 0, 64929),
(561949, 47, 1300.774, 3585.501, 90.00536, 0, 0, 0, 0, 100, 0, 64929),
(561949, 48, 1305.979, 3590.016, 89.57677, 0, 0, 0, 0, 100, 0, 64929),
(561949, 49, 1307.564, 3594.753, 89.31615, 0, 0, 0, 0, 100, 0, 64929),
(561949, 50, 1303.825, 3596.184, 89.58666, 0, 7000, 0, 0, 100, 0, 64929),
(561949, 51, 1300.563, 3586.429, 90.05614, 0, 0, 0, 0, 100, 0, 64929),
(561949, 52, 1295.785, 3580.472, 90.62579, 0, 0, 0, 0, 100, 0, 64929),
(561949, 53, 1287.363, 3569.259, 92.05901, 0, 0, 0, 0, 100, 0, 64929),
(561949, 54, 1283.476, 3561.002, 92.80116, 0, 0, 0, 0, 100, 0, 64929),
(561949, 55, 1279.932, 3553.407, 93.17616, 0, 0, 0, 0, 100, 0, 64929),
(561949, 56, 1278.7, 3544.609, 93.67616, 0, 0, 0, 0, 100, 0, 64929),
(561949, 57, 1277.158, 3533.575, 93.67616, 0, 0, 0, 0, 100, 0, 64929),
(561949, 58, 1275.061, 3523.377, 94.27975, 0, 0, 0, 0, 100, 0, 64929),
(561949, 59, 1276.441, 3510.941, 96.07723, 0, 0, 0, 0, 100, 0, 64929),
(561949, 60, 1278.505, 3498.188, 99.14166, 0, 0, 0, 0, 100, 0, 64929),
(561949, 61, 1280.545, 3488.463, 101.5287, 0, 0, 0, 0, 100, 0, 64929),
(561949, 62, 1281.075, 3477.09, 103.3935, 0, 0, 0, 0, 100, 0, 64929),
(561949, 63, 1281.365, 3467.771, 105.2131, 0, 0, 0, 0, 100, 0, 64929),
(561949, 64, 1284.563, 3461.186, 107.261, 0, 0, 0, 0, 100, 0, 64929),
(561949, 65, 1291.941, 3453.174, 110.9187, 0, 0, 0, 0, 100, 0, 64929),
(561949, 66, 1299.094, 3447.649, 113.2287, 0, 0, 0, 0, 100, 0, 64929),
(561949, 67, 1306.16, 3444.22, 115.0709, 0, 0, 0, 0, 100, 0, 64929),
(561949, 68, 1313.5, 3435.571, 117.8568, 0, 0, 0, 0, 100, 0, 64929),
(561949, 69, 1320.306, 3426.353, 120.4679, 0, 0, 0, 0, 100, 0, 64929),
(561949, 70, 1325.852, 3419.412, 121.8415, 0, 0, 0, 0, 100, 0, 64929),
(561949, 71, 1334.443, 3413.726, 123.3382, 0, 0, 0, 0, 100, 0, 64929),
(561949, 72, 1340.349, 3403.408, 124.4632, 0, 0, 0, 0, 100, 0, 64929),
(561949, 73, 1343.701, 3387.74, 125.2465, 0, 0, 0, 0, 100, 0, 64929),
(561949, 74, 1349.908, 3377.522, 125.5362, 0, 0, 0, 0, 100, 0, 64929),
(561949, 75, 1352.247, 3365.307, 126.1973, 0, 0, 0, 0, 100, 0, 64929),
(561949, 76, 1356.806, 3355.382, 126.989, 0, 0, 0, 0, 100, 0, 64929),
(561949, 77, 1360.295, 3342.948, 127.856, 0, 0, 0, 0, 100, 0, 64929),
(561949, 78, 1360.443, 3327.919, 129.2744, 0, 0, 0, 0, 100, 0, 64929),
(561949, 79, 1357.802, 3315.531, 129.8994, 0, 0, 0, 0, 100, 0, 64929),
(561949, 80, 1354.33, 3306.154, 130.1806, 0, 0, 0, 0, 100, 0, 64929),
(561949, 81, 1353.304, 3295.28, 130.9628, 0, 0, 0, 0, 100, 0, 64929),
(561949, 82, 1354.693, 3287.229, 131.0954, 0, 0, 0, 0, 100, 0, 64929),
(561949, 83, 1361.361, 3277.022, 131.4489, 0, 0, 0, 0, 100, 0, 64929),
(561949, 84, 1368.481, 3274.202, 131.6809, 0, 0, 0, 0, 100, 0, 64929),
(561949, 85, 1375.958, 3271.815, 132.3121, 0, 2000, 0, 0, 100, 0, 64929),
(561949, 86, 1370.845, 3273.609, 131.8065, 0, 0, 0, 0, 100, 0, 64929),
(561949, 87, 1366.512, 3276.056, 131.3748, 0, 0, 0, 0, 100, 0, 64929),
(561949, 88, 1360.337, 3280.271, 131.3748, 0, 0, 0, 0, 100, 0, 64929),
(561949, 89, 1356.106, 3285.41, 131.3748, 0, 0, 0, 0, 100, 0, 64929),
(561949, 90, 1355.467, 3292.224, 131.2139, 0, 0, 0, 0, 100, 0, 64929),
(561949, 91, 1357.085, 3297.611, 130.7616, 0, 7000, 0, 0, 100, 0, 64929),
(561949, 92, 1353.778, 3304.517, 130.2744, 0, 0, 0, 0, 100, 0, 64929),
(561949, 93, 1355.337, 3310.563, 130.1494, 0, 0, 0, 0, 100, 0, 64929),
(561949, 94, 1357.983, 3317.83, 129.8222, 0, 0, 0, 0, 100, 0, 64929),
(561949, 95, 1360.304, 3324.479, 129.5733, 0, 0, 0, 0, 100, 0, 64929),
(561949, 96, 1361.196, 3331.475, 129.1494, 0, 0, 0, 0, 100, 0, 64929);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 64929;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 64929 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (64929*100, 64929*100+01) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(64929, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 64929*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Deng - MI 1 - Start Script"),
(64929, 0, 1, 0, 34, 0, 100, 0, 2, 7, 0, 0, 80, 64929*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Deng - MI 7 - Start Script"),
(64929, 0, 2, 0, 34, 0, 100, 0, 2, 14, 0, 0, 80, 64929*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Deng - MI 14 - Start Script"),
(64929, 0, 3, 0, 34, 0, 100, 0, 2, 20, 0, 0, 80, 64929*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Deng - MI 20 - Start Script"),
(64929, 0, 4, 0, 34, 0, 100, 0, 2, 25, 0, 0, 80, 64929*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Deng - MI 25 - Start Script"),
(64929, 0, 5, 0, 34, 0, 100, 0, 2, 35, 0, 0, 80, 64929*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Deng - MI 35 - Start Script"),
(64929, 0, 6, 0, 34, 0, 100, 0, 2, 41, 0, 0, 80, 64929*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Deng - MI 41 - Start Script"),
(64929, 0, 7, 0, 34, 0, 100, 0, 2, 49, 0, 0, 80, 64929*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Deng - MI 49 - Start Script"),
(64929, 0, 8, 0, 34, 0, 100, 0, 2, 90, 0, 0, 80, 64929*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Deng - MI 90 - Start Script"),

(64929*100, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 128, 2704, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Deng - On Script - Play Anim Kit"),

(64929*100+01, 9, 0, 0, 0, 0, 100, 0, 200, 200, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Deng - On Script - Play Emote"),
(64929*100+01, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 128, 2704, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Deng - On Script - Play Anim Kit");

-- Instructor Qun
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 57748;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 57748 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (5774800, 5774801, 5774802, 5774803) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(57748, 0, 0, 0, 1, 0, 100, 0, 0, 0, 5000, 5000, 87, 5774800, 5774801, 5774802, 5774803, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Qun - OOC - Start Random Script"),

(5774800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 10, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Qun - Play Emote (507)"),
(5774800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Qun - Play Random Sound (33643, 33645, 33646)"),
(5774800, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 1, 0, 0, 0, 0, 11, 0, 15, 0, 0, 0, 0, 0, "Instructor Qun - Set Data 3 1"),
(5774801, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 10, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Qun - Play Emote"),
(5774801, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Qun - Play Random Sound (33643, 33645, 33646)"),
(5774801, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 2, 0, 0, 0, 0, 11, 0, 15, 0, 0, 0, 0, 0, "Instructor Qun - Set Data 3 2"),
(5774802, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 10, 511, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Qun - Play Emote"),
(5774802, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Qun - Play Random Sound (33643, 33645, 33646)"),
(5774802, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 11, 0, 15, 0, 0, 0, 0, 0, "Instructor Qun - Set Data 3 3"),
(5774803, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 10, 543, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Qun - Play Emote"),
(5774803, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, "Instructor Qun - Play Random Sound (33643, 33645, 33646)"),
(5774803, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 4, 0, 0, 0, 0, 11, 0, 15, 0, 0, 0, 0, 0, "Instructor Qun - Set Data 3 4");

-- Aspiring Trainee
UPDATE `creature` SET `position_x` = 1491.057129, `position_y` = 3439.181152, `position_z` = 171.162048, `orientation` = 6.186045 WHERE `guid` = 563357;

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` IN (53565, 65469);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (53565, 65469, -563382, -563383) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (5356500, 5356501, 5356502, 5356503, 5356504) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(53565, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 1 1 - Set Phase 1"),
(53565, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 510, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 1 1 (Link) - Set Emote State (510)"),
(53565, 0, 2, 3, 60, 1, 100, 0, 1000, 1000, 5000, 5000, 11, 108967, 0, 0, 0, 0, 0, 11, 0, 4, 0, 0, 0, 0, 0, "Aspiring Trainee - On Update - Cast Spell 'Jab'"),
(53565, 0, 3, 4, 61, 1, 100, 0, 0, 0, 0, 0, 10, 507, 509, 511, 543, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Update (Link) - Play Random Emote (507, 509, 511, 543)"),
(53565, 0, 4, 0, 61, 1, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Update (Link) - Play Random Sound (33643, 33645, 33646)"),
(53565, 0, 5, 6, 38, 0, 100, 0, 2, 2, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 2 2 - Set Phase 2"),
(53565, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 17, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 2 2 (Link) - Clear Emote"),
(53565, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 2 2 (Link) - Say Text Line 0"),
(53565, 0, 8, 0, 38, 0, 100, 0, 3, 1, 0, 0, 80, 5356500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 3 1 - Start Script"),
(53565, 0, 9, 0, 38, 0, 100, 0, 3, 2, 0, 0, 80, 5356502, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 3 2 - Start Script"),
(53565, 0, 10, 0, 38, 0, 100, 0, 3, 3, 0, 0, 80, 5356503, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 3 3 - Start Script"),
(53565, 0, 11, 0, 38, 0, 100, 0, 3, 4, 0, 0, 80, 5356504, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 3 4 - Start Script"),

(5356500, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - Play Emote (507)"),
(5356500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - Play Random Sound (33643, 33645, 33646)"),

(5356501, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - Play Emote (508)"),
(5356501, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - Play Random Sound (33643, 33645, 33646)"),

(5356502, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - Play Emote (509)"),
(5356502, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - Play Random Sound (33643, 33645, 33646)"),

(5356503, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 511, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - Play Emote (511)"),
(5356503, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - Play Random Sound (33643, 33645, 33646)"),

(5356504, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 543, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - Play Emote (543)"),
(5356504, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - Play Random Sound (33643, 33645, 33646)"),

(65469, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 1 1 - Set Phase 1"),
(65469, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 17, 510, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 1 1 (Link) - Set Emote State (510)"),
(65469, 0, 2, 3, 60, 1, 100, 0, 1000, 1000, 5000, 5000, 11, 108967, 0, 0, 0, 0, 0, 11, 0, 4, 0, 0, 0, 0, 0, "Aspiring Trainee - On Update - Cast Spell 'Jab'"),
(65469, 0, 3, 4, 61, 1, 100, 0, 0, 0, 0, 0, 10, 507, 509, 511, 543, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Update (Link) - Play Random Emote (507, 509, 511, 543)"),
(65469, 0, 4, 0, 61, 1, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Update (Link) - Play Random Sound (33643, 33645, 33646)"),
(65469, 0, 5, 6, 38, 0, 100, 0, 2, 2, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 2 2 - Set Phase 2"),
(65469, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 17, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 2 2 (Link) - Clear Emote"),
(65469, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 2 2 (Link) - Say Text Line 0"),
(65469, 0, 8, 0, 38, 0, 100, 0, 3, 1, 0, 0, 80, 5356500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 3 1 - Start Script"),
(65469, 0, 9, 0, 38, 0, 100, 0, 3, 2, 0, 0, 80, 5356502, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 3 2 - Start Script"),
(65469, 0, 10, 0, 38, 0, 100, 0, 3, 3, 0, 0, 80, 5356503, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 3 3 - Start Script"),
(65469, 0, 11, 0, 38, 0, 100, 0, 3, 4, 0, 0, 80, 5356504, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Data Set 3 4 - Start Script"),

(-563382, 0, 0, 0, 1, 0, 100, 0, 20000, 20000, 120000, 120000, 1, 1, 16000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - OOC - Say Text Line 1"),
(-563382, 0, 1, 0, 52, 0, 100, 0, 1, 53565, 0, 0, 1, 2, 6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Text Line 1 Over - Say Text Line 2"),
(-563382, 0, 2, 0, 52, 0, 100, 0, 2, 53565, 0, 0, 1, 3, 11000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Text Line 2 Over - Say Text Line 3"),
(-563382, 0, 3, 0, 52, 0, 100, 0, 3, 53565, 0, 0, 1, 4, 6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Text Line 3 Over - Say Text Line 4"),
(-563382, 0, 4, 0, 52, 0, 100, 0, 4, 53565, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 53565, 3, 0, 0, 0, 0, 0, "Aspiring Trainee - On Text Line 4 Over - Set Data 1 1"),

(-563383, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 1, 5, 6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Text Line 1 Over - Say Text Line 5"),
(-563383, 0, 1, 0, 52, 0, 100, 0, 5, 53565, 0, 0, 1, 6, 15000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Text Line 5 Over - Say Text Line 6"),
(-563383, 0, 2, 0, 52, 0, 100, 0, 6, 53565, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Aspiring Trainee - On Text Line 6 Over - Say Text Line 7");

DELETE FROM `creature_addon` WHERE `guid` IN (563382, 563383);
INSERT INTO `creature_addon` (`guid`, `bytes2`) VALUES
(563382, 1),
(563383, 1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 108967;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 108967, 0, 0, 31, 0, 3, 53714, 0, 0, 0, 0, "", "Jab target only Training Target"),
(13, 1, 108967, 0, 1, 31, 0, 3, 57873, 0, 0, 0, 0, "", "Jab target only Training Target");

DELETE FROM `creature_text` WHERE `entry` = 53565;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(53565, 0, 0, "Such skill for a new trainee.", "Such skill for a new trainee.", 12, 0, 100, 511, 0, 0, "Aspiring Trainee"),
(53565, 0, 1, "That target didn't stand a chance.", "That target didn't stand a chance.", 12, 0, 100, 511, 0, 0, "Aspiring Trainee"),
(53565, 0, 2, "One day you will have to teach me your secrets.", "One day you will have to teach me your secrets.", 12, 0, 100, 509, 0, 0, "Aspiring Trainee"),
(53565, 0, 3, "You are bound for a great things, trainee.", "You are bound for a great things, trainee.", 12, 0, 100, 508, 0, 0, "Aspiring Trainee"),
(53565, 0, 4, "I must train harder so I can be like you.", "I must train harder so I can be like you.", 12, 0, 100, 1, 0, 0, "Aspiring Trainee"),
(53565, 0, 5, "I hope the instructors saw that!", "I hope the instructors saw that!", 12, 0, 100, 1, 0, 0, "Aspiring Trainee"),
(53565, 0, 6, "I must work as hard as you.", "I must work as hard as you.", 12, 0, 100, 1, 0, 0, "Aspiring Trainee"),
(53565, 0, 7, "Your form is impeccable.", "Your form is impeccable.", 12, 0, 100, 1, 0, 0, "Aspiring Trainee"),
(53565, 1, 0, "My money's on Lam. Did you see him take down Chu during training last week?", "", 12, 0, 100, 1, 0, 0, "Aspiring Trainee"),
(53565, 2, 0, "His stamina is nothing against Lam's strength.", "", 12, 0, 100, 0, 0, 0, "Aspiring Trainee"),
(53565, 3, 0, "He has the legs of an ox! Have you ever been kicked by him in training?", "", 12, 0, 100, 1, 0, 0, "Aspiring Trainee"),
(53565, 4, 0, "Raise you a keg of Stormshout Gold. It'll be your loss.", "", 12, 0, 100, 1, 0, 0, "Aspiring Trainee"),
(53565, 5, 0, "That's where you're mistaken, friend. Zhou is as sturdy as an oak.", "", 12, 0, 100, 1, 0, 0, "Aspiring Trainee"),
(53565, 6, 0, "Zhou has the stamina of three men, so he can out-stay most opponents.", "", 12, 0, 100, 0, 0, 0, "Aspiring Trainee"),
(53565, 7, 0, "Four coppers on Zhou.", "", 12, 0, 100, 0, 0, 0, "Aspiring Trainee");

-- Quiet Lam
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 57752;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 57752 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(57752, 0, 0, 1, 1, 0, 100, 0, 0, 0, 5000, 5000, 10, 507, 509, 511, 543, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Quiet Lam - OOC - Play Random Emote (507, 509, 511, 543)"),
(57752, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, "Quiet Lam - Play Random Sound (33643, 33645, 33646)");

-- Ironfist Zhou
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 57753;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 57753 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(57753, 0, 0, 1, 1, 0, 100, 0, 0, 0, 5000, 5000, 10, 507, 509, 511, 543, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Ironfist Zhou - OOC - Play Random Emote (507, 509, 511, 543)"),
(57753, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, "Ironfist Zhou - Play Random Sound (33643, 33645, 33646)");

UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` = 54567;
UPDATE `creature_template` SET `minlevel` = 2, `maxlevel` = 2, `faction_A` = 2102, `faction_H` = 2102, `npcflag` = 0, `speed_walk` = 1, `speed_run` = 1.142857, `baseattacktime` = 2000, `rangeattacktime` = 2000, `unit_class` = 0, `unit_flags` = 32768, `unit_flags2` = 2048, `dynamicflags` = 0, `VehicleId` = 0, `HoverHeight` = 1 WHERE `entry` = 59637;

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 55694;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 55694 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(55694,0,0,0,54,0,100,0,0,0,0,0,62,860,0,0,0,0,0,1,0,0,0,909.137,3610.38,252.175,0,"Ji Firepaw - On Summoned - Teleport Creature"),
(55694,0,1,0,10,0,100,0,1,10,12000,12000,1,0,2000,0,0,0,0,21,10,0,0,0,0,0,0,"Ji Firepaw - OOC LoS - Say Text Line 0"),
(55694,0,2,0,52,0,100,0,0,55694,0,0,53,1,55694,0,0,0,0,1,0,0,0,0,0,0,0,"Ji Firepaw - On Text Over 0 - Waypoint Start"),
(55694,0,3,0,58,0,100,0,41,55694,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ji Firepaw - On Waypoint Ended - Despawn Self");

DELETE FROM `waypoints` WHERE `pointid` IN (35, 36, 37, 38, 39, 40, 41) AND `entry` = 55694;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(55694, 35, 1008.55, 4153.77, 202.52, "Ji Firepaw"),
(55694, 36, 1035.22, 4153.14, 205.30, "Ji Firepaw"),
(55694, 37, 1048.20, 4176.42, 204.94, "Ji Firepaw"),
(55694, 38, 1078.19, 4169.25, 205.67, "Ji Firepaw"),
(55694, 39, 1103.67, 4172.46, 197.90, "Ji Firepaw"),
(55694, 40, 1104.01, 4173.42, 197.73, "Ji Firepaw"),
(55694, 41, 1131.81, 4151.84, 190.62, "Ji Firepaw");

UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` = 55633 AND `zoneId` = 5736; 
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` = 57466 AND `zoneId` = 5736; 
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `id` = 55632 AND `zoneId` = 5736;

UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 56663; 
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 56660; 
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 56661; 
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 56676; 
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 55918; 
UPDATE `creature_template` SET `AIName` = "" WHERE `entry` = 57769;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (56663, 56660, 56661, 56676, 55918, 57769) AND `source_type` = 0;

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "mob_aisa_pre_balon_event" WHERE `entry` = 56662; 
DELETE FROM `smart_scripts` WHERE `entryorguid` = 56662 AND `source_type` = 0;

UPDATE `creature_template` SET `IconName` = "vehichleCursor", `unit_flags` = 33536, `npcflag` = 16777216, `VehicleId` = 1887 WHERE `entry` = 55918;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 55649;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(55649, 46598, 1, 0);

UPDATE `creature_template_addon` SET `auras` = 49414 WHERE `entry` = 56663;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 55918;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(55918, 46598, 1, 0),
(55918, 128815, 1, 0),
(55918, 95247, 1, 0);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (95247, 128815);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(95247, "spell_grab_air_balloon"), 
(128815, "spell_grab_air_balloon"); 

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceGroup` = 55918;
REPLACE INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`, `ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`)VALUES 
(18, 55918, 128815, 9, 0, 29791, 0, 0, "Required quest active for spellclick"),
(18, 55918, 128815, 31, 0, 4, 0, 0, "Spellclick for player"),
(18, 55918, 46598, 31, 0, 3, 0, 0, "Spellclick for npc");

UPDATE `creature_template` SET `VehicleId` = 1820, `InhabitType` = 4, `AIName` = "", `ScriptName` = "mop_air_balloon" WHERE `entry` = 55649;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 55649 AND `source_type` = 0;

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (56739, 57464, 57690, 55918, 65476, 65477, 55649, 56661, 56662);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(56739, 54131, 0, 0, "Fe-Feng Hozen", 7, 0),
(57464, 57465, 0, 0, "Fe-Feng Ruffian", 7, 0),
(57690, 57691, 0, 1, "Tiger Pillar", 8, 0),
(55918, 56662, 0, 1, "Aysa", 8, 0),
(55918, 56663, 1, 1, "Ji Firepaw", 8, 0),
(55918, 65476, 2, 1, "Balloon Air Spirit Bunny", 8, 0),
(55918, 65477, 3, 1, "Balloon Fire Spirit Bunny", 8, 0),
(65476, 65102, 0, 1, "Dafeng", 8, 0),
(65477, 65107, 0, 1, "Huo", 8, 0),
(55649, 56661, 1, 1, "Aysa", 8, 0),
(55649, 56660, 2, 1, "Ji Firepaw", 8, 0),
(55649, 65476, 3, 1, "Balloon Air Spirit Bunny", 8, 0),
(55649, 65477, 4, 1, "Balloon Fire Spirit Bunny", 8, 0);

UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` IN (56676, 57769);

DELETE FROM `conditions` WHERE SourceEntry IN (114888, 114898, 106759, 118571, 118572);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 114888, 0, 0, 31, 0, 3, 57769, 0, 0, 0, "", "Cast - ON - 57769"),
(13, 3, 114898, 0, 0, 31, 0, 3, 57769, 0, 0, 0, "", "Cast - ON - 57769"),
(13, 1, 106759, 0, 0, 31, 0, 3, 56676, 0, 0, 0, "", "Cast - ON - 56676"),
(13, 1, 118571, 0, 0, 31, 0, 3, 57769, 0, 0, 0, "", "Cast - ON - 57769"),
(13, 1, 118572, 0, 0, 31, 0, 3, 57769, 0, 0, 0, "", "Cast - ON - 57769");

DELETE FROM `spell_target_position` WHERE `id` = 105002 AND `target_map` = 860;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(105002, 860, 915.559, 4563.667, 231.0833, 2.298086);

UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 56676;

DELETE FROM `script_waypoint` WHERE `entry` = 55649;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES
(55649, 1, 934.2396, 4571.044, 233.6516, "Shang Xi's Hot Air Balloon"),
(55649, 2, 1015.715, 4604.329, 216.5495, "Shang Xi's Hot Air Balloon"),
(55649, 3, 1056.448, 4658.655, 187.7374, "Shang Xi's Hot Air Balloon"),
(55649, 4, 1081.418, 4796.375, 157.6622, "Shang Xi's Hot Air Balloon"),
(55649, 5, 1091.849, 4926.616, 137.9268, "Shang Xi's Hot Air Balloon"),
(55649, 6, 1026.328, 5137.097, 138.0555, "Shang Xi's Hot Air Balloon"),
(55649, 7, 818.2934, 5216.31, 134.6396, "Shang Xi's Hot Air Balloon"),
(55649, 8, 621.7153, 5132.557, 142.15, "Shang Xi's Hot Air Balloon"),
(55649, 9, 547.2552, 5035.906, 130.4939, "Shang Xi's Hot Air Balloon"),
(55649, 10, 440.7517, 4867.261, 117.5795, "Shang Xi's Hot Air Balloon"),
(55649, 11, 403.5208, 4650.163, 81.13639, "Shang Xi's Hot Air Balloon"),
(55649, 12, 341.3038, 4475.935, 75.50136, "Shang Xi's Hot Air Balloon"),
(55649, 13, 222.5573, 4369.272, 93.21405, "Shang Xi's Hot Air Balloon"),
(55649, 14, 164.7587, 4297.126, 112.2426, "Shang Xi's Hot Air Balloon"),
(55649, 15, 131.7517, 4156.708, 124.6377, "Shang Xi's Hot Air Balloon"), -- Quest Credit
(55649, 16, 123.9514, 4109.052, 124.6377, "Shang Xi's Hot Air Balloon"),
(55649, 17, 112.0469, 3931.905, 128.3417, "Shang Xi's Hot Air Balloon"),
(55649, 18, 218.5, 3824.769, 137.5752, "Shang Xi's Hot Air Balloon"),
(55649, 19, 388.9236, 3765.605, 159.4655, "Shang Xi's Hot Air Balloon"),
(55649, 20, 596.5712, 3689.253, 183.0423, "Shang Xi's Hot Air Balloon"),
(55649, 21, 745.1858, 3664.532, 194.0496, "Shang Xi's Hot Air Balloon"); -- Despawn

DELETE FROM `vehicle_accessory` WHERE `guid` = 562981 AND `accessory_entry` = 55649;
INSERT INTO `vehicle_accessory` (`guid`,`accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(562981, 55649, 0, 0, "", 8, 0);

-- Priestess of the Dawn
DELETE FROM `creature` WHERE `guid` = 582638 AND `id` = 65094;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawntimesecs_max`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `movement_type`, `npcflag`, `npcflag2`, `unit_flags`, `unit_flags2`, `dynamicflags`, `ScriptName`, `walk_mode`) VALUES
(582638, 65094, 860, 5736, 5820, 1, 1, 44024, 0, 950.0712, 3730.257, 189.1213, 1.41757, 600, 0, 0, 0, 393941, 0, 0, 0, 0, 0, 0, 0, "", 0);

UPDATE `creature` SET `position_x` = 959.7421, `position_y` = 3588.922, `position_z` = 224.6128, `orientation` = 4.129789, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 561720;
UPDATE `creature` SET `position_x` = 969.6996, `position_y` = 3552.865, `position_z` = 192.738, `orientation` = 3.765826, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 561722;
UPDATE `creature` SET `position_x` = 935.7398, `position_y` = 3564.389, `position_z` = 224.876, `orientation` = 2.956123, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 561727;
UPDATE `creature` SET `position_x` = 953.1593, `position_y` = 3592.287, `position_z` = 251.9661, `orientation` = 4.003345, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 561729;
UPDATE `creature` SET `position_x` = 960.2695, `position_y` = 3633.337, `position_z` = 251.9946, `orientation` = 2.536073, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 561738;
UPDATE `creature` SET `position_x` = 1126.918, `position_y` = 3577.957, `position_z` = 140.7979, `orientation` = 0.8851961, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 561743;
UPDATE `creature` SET `position_x` = 894.638, `position_y` = 3604.732, `position_z` = 193.3881, `orientation` = 0.2774797, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 563542;
UPDATE `creature` SET `position_x` = 944.0429, `position_y` = 3637.804, `position_z` = 193.2151, `orientation` = 4.676368, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 563691;

DELETE FROM `creature_addon` WHERE `guid` IN (582638, 561720, 561722, 561727, 561729, 561738, 561743, 563542, 563691);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`) VALUES
(582638, 0, 8, 1),
(561720, 561720, 0, 1),
(561722, 561722, 0, 1),
(561727, 561727, 0, 1),
(561729, 561729, 0, 1),
(561738, 561738, 0, 1),
(561743, 561743, 0, 1),
(563542, 563542, 0, 1),
(563691, 563691, 0, 1);

DELETE FROM `waypoint_data` WHERE `id` IN (561720, 561722, 561727, 561729, 561738, 561743, 563542, 563691);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(561720, 1, 951.3993, 3584.561, 224.582, 0, 0, 0, 0, 100, 0, 65094),
(561720, 2, 946.6563, 3581.222, 224.6816, 0, 0, 0, 0, 100, 0, 65094),
(561720, 3, 937.2969, 3581.216, 224.6555, 0, 0, 0, 0, 100, 0, 65094),
(561720, 4, 930.7604, 3586.769, 224.5915, 0, 0, 0, 0, 100, 0, 65094),
(561720, 5, 924.1354, 3589.425, 224.5553, 0, 0, 0, 0, 100, 0, 65094),
(561720, 6, 920.9913, 3596.517, 224.6049, 0, 0, 0, 0, 100, 0, 65094),
(561720, 7, 920.132, 3602.132, 224.7671, 0, 0, 0, 0, 100, 0, 65094),
(561720, 8, 920.3958, 3606.727, 224.7565, 0, 0, 0, 0, 100, 0, 65094),
(561720, 9, 923.0695, 3615.164, 224.6592, 0, 0, 0, 0, 100, 0, 65094),
(561720, 10, 930.3663, 3622.535, 224.6062, 0, 0, 0, 0, 100, 0, 65094),
(561720, 11, 938.0541, 3625.819, 224.7615, 0, 0, 0, 0, 100, 0, 65094),
(561720, 12, 946.3246, 3626.218, 224.7388, 0, 0, 0, 0, 100, 0, 65094),
(561720, 13, 954.1371, 3621.345, 224.6244, 0, 0, 0, 0, 100, 0, 65094),
(561720, 14, 959.6719, 3618.629, 224.6219, 0, 0, 0, 0, 100, 0, 65094),
(561720, 15, 963.7726, 3612.553, 224.6174, 0, 0, 0, 0, 100, 0, 65094),
(561720, 16, 965.1805, 3604.576, 224.7364, 0, 0, 0, 0, 100, 0, 65094),
(561720, 17, 963.6354, 3594.831, 224.6205, 0, 0, 0, 0, 100, 0, 65094),
(561720, 18, 958.6354, 3587.242, 224.5457, 0, 0, 0, 0, 100, 0, 65094),

(561722, 1, 959.5938, 3550.595, 192.7396, 0, 15000, 0, 0, 100, 0, 65094),
(561722, 2, 969.6996, 3552.865, 192.738, 0, 0, 0, 0, 100, 0, 65094),
(561722, 3, 980.625, 3560.734, 192.7361, 0, 0, 0, 0, 100, 0, 65094),
(561722, 4, 993.2327, 3574.031, 192.7399, 0, 0, 0, 0, 100, 0, 65094),
(561722, 5, 998.7609, 3589.688, 192.7368, 0, 0, 0, 0, 100, 0, 65094),
(561722, 6, 999.8715, 3612.465, 192.2928, 0, 0, 0, 0, 100, 0, 65094),
(561722, 7, 996.8108, 3626.431, 192.7368, 0, 0, 0, 0, 100, 0, 65094),
(561722, 8, 987.2795, 3642.421, 192.7375, 0, 0, 0, 0, 100, 0, 65094),
(561722, 9, 975.8663, 3652.265, 192.7354, 0, 0, 0, 0, 100, 0, 65094),
(561722, 10, 965.0035, 3656.824, 192.7371, 0, 15000, 0, 0, 100, 0, 65094),
(561722, 11, 975.8663, 3652.265, 192.7354, 0, 0, 0, 0, 100, 0, 65094),
(561722, 12, 987.2795, 3642.421, 192.7375, 0, 0, 0, 0, 100, 0, 65094),
(561722, 13, 996.8108, 3626.431, 192.7368, 0, 0, 0, 0, 100, 0, 65094),
(561722, 14, 999.8715, 3612.465, 192.2928, 0, 0, 0, 0, 100, 0, 65094),
(561722, 15, 998.8264, 3589.874, 192.6871, 0, 0, 0, 0, 100, 0, 65094),
(561722, 16, 993.2327, 3574.031, 192.7399, 0, 0, 0, 0, 100, 0, 65094),
(561722, 17, 980.625, 3560.734, 192.7361, 0, 0, 0, 0, 100, 0, 65094),
(561722, 18, 969.6996, 3552.865, 192.738, 0, 0, 0, 0, 100, 0, 65094),

(561727, 1, 931.5226, 3565.181, 224.8194, 0, 0, 0, 0, 100, 0, 65094),
(561727, 2, 941.7014, 3563.271, 224.8653, 0, 15000, 0, 0, 100, 0, 65094),
(561727, 3, 931.5226, 3565.181, 224.8194, 0, 0, 0, 0, 100, 0, 65094),
(561727, 4, 920.4618, 3569.397, 224.7515, 0, 0, 0, 0, 100, 0, 65094),
(561727, 5, 913.743, 3575.342, 224.7991, 0, 0, 0, 0, 100, 0, 65094),
(561727, 6, 906.8316, 3583.507, 224.859, 0, 0, 0, 0, 100, 0, 65094),
(561727, 7, 903.9288, 3593.484, 224.7262, 0, 0, 0, 0, 100, 0, 65094),
(561727, 8, 902.632, 3603.128, 224.8899, 0, 0, 0, 0, 100, 0, 65094),
(561727, 9, 903.2118, 3614.566, 224.7708, 0, 0, 0, 0, 100, 0, 65094),
(561727, 10, 903.8055, 3621.547, 224.8133, 0, 0, 0, 0, 100, 0, 65094),
(561727, 11, 907.7761, 3629.228, 224.8866, 0, 0, 0, 0, 100, 0, 65094),
(561727, 12, 913.9653, 3636.435, 224.8732, 0, 0, 0, 0, 100, 0, 65094),
(561727, 13, 922.3646, 3641.333, 224.8962, 0, 15000, 0, 0, 100, 0, 65094),
(561727, 14, 913.9653, 3636.435, 224.8732, 0, 0, 0, 0, 100, 0, 65094),
(561727, 15, 907.7761, 3629.228, 224.8866, 0, 0, 0, 0, 100, 0, 65094),
(561727, 16, 903.8055, 3621.547, 224.8133, 0, 0, 0, 0, 100, 0, 65094),
(561727, 17, 903.2118, 3614.566, 224.7708, 0, 0, 0, 0, 100, 0, 65094),
(561727, 18, 902.632, 3603.128, 224.8899, 0, 0, 0, 0, 100, 0, 65094),
(561727, 19, 903.9136, 3593.598, 224.7554, 0, 0, 0, 0, 100, 0, 65094),
(561727, 20, 906.8316, 3583.507, 224.859, 0, 0, 0, 0, 100, 0, 65094),
(561727, 21, 913.743, 3575.342, 224.7991, 0, 0, 0, 0, 100, 0, 65094),
(561727, 22, 920.4618, 3569.397, 224.7515, 0, 0, 0, 0, 100, 0, 65094),

(561729, 1, 943.8733, 3588.163, 252.0874, 0, 0, 0, 0, 100, 0, 65094),
(561729, 2, 934.8134, 3590.201, 252.0842, 0, 0, 0, 0, 100, 0, 65094),
(561729, 3, 928.7604, 3596.856, 251.861, 0, 15000, 0, 0, 100, 0, 65094),
(561729, 4, 934.7917, 3590.206, 252.0865, 0, 0, 0, 0, 100, 0, 65094),
(561729, 5, 943.8733, 3588.163, 252.0874, 0, 0, 0, 0, 100, 0, 65094),
(561729, 6, 951.8299, 3590.737, 251.9887, 0, 0, 0, 0, 100, 0, 65094),
(561729, 7, 957.7726, 3597.665, 251.8194, 0, 0, 0, 0, 100, 0, 65094),
(561729, 8, 959.6476, 3607.23, 251.6821, 0, 0, 0, 0, 100, 0, 65094),
(561729, 9, 956.5764, 3614.496, 251.9105, 0, 0, 0, 0, 100, 0, 65094),
(561729, 10, 949.2327, 3621.306, 252.1031, 0, 0, 0, 0, 100, 0, 65094),
(561729, 11, 941.3812, 3622.256, 252.0825, 0, 0, 0, 0, 100, 0, 65094),
(561729, 12, 933.7795, 3619.047, 252.0469, 0, 15000, 0, 0, 100, 0, 65094),
(561729, 13, 941.2257, 3622.275, 252.0814, 0, 0, 0, 0, 100, 0, 65094),
(561729, 14, 949.2327, 3621.306, 252.1031, 0, 0, 0, 0, 100, 0, 65094),
(561729, 15, 956.5764, 3614.496, 251.9105, 0, 0, 0, 0, 100, 0, 65094),
(561729, 16, 959.6476, 3607.23, 251.6821, 0, 0, 0, 0, 100, 0, 65094),
(561729, 17, 957.7726, 3597.665, 251.8194, 0, 0, 0, 0, 100, 0, 65094),
(561729, 18, 951.8299, 3590.737, 251.9887, 0, 0, 0, 0, 100, 0, 65094),

(561738, 1, 950.493, 3637.799, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 2, 938.0886, 3638.292, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 3, 925.6511, 3632.493, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 4, 919.2847, 3626.129, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 5, 914.2701, 3618.316, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 6, 913.118, 3612.096, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 7, 912.5243, 3600.902, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 8, 913.4549, 3591.735, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 9, 917.6337, 3584.184, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 10, 923.0695, 3578.277, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 11, 930.7212, 3573.316, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 12, 939.2483, 3571.685, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 13, 949.7639, 3571.073, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 14, 960.8455, 3575.478, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 15, 968.8507, 3582.236, 251.9926, 0, 0, 0, 0, 100, 0, 65094),
(561738, 16, 972.9757, 3589.625, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 17, 975.0851, 3598.333, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 18, 975.2882, 3611.063, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 19, 973.7274, 3619.188, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 20, 966.0886, 3629.308, 251.9946, 0, 0, 0, 0, 100, 0, 65094),
(561738, 21, 957.3125, 3635.384, 251.9946, 0, 0, 0, 0, 100, 0, 65094),

(561743, 1, 1127.858, 3580.385, 139.4909, 0, 0, 0, 0, 100, 0, 65094),
(561743, 2, 1128.276, 3581.997, 140.1788, 0, 0, 0, 0, 100, 0, 65094),
(561743, 3, 1129.799, 3585.117, 140.0705, 0, 15000, 0, 0, 100, 0, 65094),
(561743, 4, 1128.09, 3578.431, 140.0381, 0, 0, 0, 0, 100, 0, 65094),
(561743, 5, 1122.161, 3572.295, 144.5681, 0, 0, 0, 0, 100, 0, 65094),
(561743, 6, 1115.529, 3568.052, 148.6517, 0, 0, 0, 0, 100, 0, 65094),
(561743, 7, 1107.684, 3564.857, 153.849, 0, 0, 0, 0, 100, 0, 65094),
(561743, 8, 1100.651, 3564.161, 158.685, 0, 0, 0, 0, 100, 0, 65094),
(561743, 9, 1094.583, 3565.996, 163.6753, 0, 0, 0, 0, 100, 0, 65094),
(561743, 10, 1091.75, 3567.918, 166.1934, 0, 0, 0, 0, 100, 0, 65094),
(561743, 11, 1087.514, 3574.361, 166.2984, 0, 0, 0, 0, 100, 0, 65094),
(561743, 12, 1080.291, 3584.101, 166.2984, 0, 0, 0, 0, 100, 0, 65094),
(561743, 13, 1079.22, 3585.556, 167.6713, 0, 0, 0, 0, 100, 0, 65094),
(561743, 14, 1073.236, 3591.805, 167.4664, 0.1047198, 15000, 0, 0, 100, 0, 65094),
(561743, 15, 1079.158, 3585.241, 167.6736, 0, 0, 0, 0, 100, 0, 65094),
(561743, 16, 1082.514, 3578.884, 166.2984, 0, 0, 0, 0, 100, 0, 65094),
(561743, 17, 1085.639, 3573.808, 166.2984, 0, 0, 0, 0, 100, 0, 65094),
(561743, 18, 1091.481, 3568.26, 166.2947, 0, 0, 0, 0, 100, 0, 65094),
(561743, 19, 1096.953, 3565.714, 161.8288, 0, 0, 0, 0, 100, 0, 65094),
(561743, 20, 1108.299, 3565.136, 153.3571, 0, 0, 0, 0, 100, 0, 65094),
(561743, 21, 1116.525, 3568.691, 148.1021, 0, 0, 0, 0, 100, 0, 65094),
(561743, 22, 1123.29, 3573.521, 143.6728, 0, 0, 0, 0, 100, 0, 65094),
(561743, 23, 1126.918, 3577.957, 140.7979, 0, 0, 0, 0, 100, 0, 65094),

(563542, 1, 897.2587, 3603.547, 193.0444, 0, 0, 0, 0, 100, 0, 65094),
(563542, 2, 905.7621, 3602.891, 193.0961, 0, 0, 0, 0, 100, 0, 65094),
(563542, 3, 912.3524, 3601.498, 195.6407, 0, 0, 0, 0, 100, 0, 65094),
(563542, 4, 918.0261, 3598.911, 196.5228, 0, 0, 0, 0, 100, 0, 65094),
(563542, 5, 925.9332, 3592.558, 196.6235, 0, 0, 0, 0, 100, 0, 65094),
(563542, 6, 929.9514, 3588.909, 196.415, 0, 0, 0, 0, 100, 0, 65094),
(563542, 7, 936.2552, 3581.5, 196.3451, 0, 0, 0, 0, 100, 0, 65094),
(563542, 8, 938.7691, 3575.904, 194.8538, 0, 0, 0, 0, 100, 0, 65094),
(563542, 9, 938.9879, 3571.325, 193.0317, 0, 0, 0, 0, 100, 0, 65094),
(563542, 10, 939.75, 3559.238, 193.4328, 0, 0, 0, 0, 100, 0, 65094),
(563542, 11, 939.6146, 3554.624, 193.605, 0, 0, 0, 0, 100, 0, 65094),
(563542, 12, 939.434, 3543.031, 192.9737, 0, 0, 0, 0, 100, 0, 65094),
(563542, 13, 938.1667, 3535.869, 193.7601, 0, 3000, 0, 0, 100, 0, 65094),
(563542, 14, 939.632, 3555.035, 193.5967, 0, 0, 0, 0, 100, 0, 65094),
(563542, 15, 939.5938, 3559.74, 193.4339, 0, 0, 0, 0, 100, 0, 65094),
(563542, 16, 938.9531, 3571.805, 193.0315, 0, 0, 0, 0, 100, 0, 65094),
(563542, 17, 938.8246, 3576.292, 195.0673, 0, 0, 0, 0, 100, 0, 65094),
(563542, 18, 936.2899, 3581.331, 196.3224, 0, 0, 0, 0, 100, 0, 65094),
(563542, 19, 930.0469, 3588.829, 196.5396, 0, 0, 0, 0, 100, 0, 65094),
(563542, 20, 925.9774, 3592.47, 196.6099, 0, 0, 0, 0, 100, 0, 65094),
(563542, 21, 918.3611, 3598.658, 196.5486, 0, 0, 0, 0, 100, 0, 65094),
(563542, 22, 912.3177, 3601.447, 195.6266, 0, 0, 0, 0, 100, 0, 65094),
(563542, 23, 905.4114, 3602.789, 193.0971, 0, 0, 0, 0, 100, 0, 65094),
(563542, 24, 896.8038, 3603.559, 193.0402, 0, 0, 0, 0, 100, 0, 65094),
(563542, 25, 892.0815, 3603.665, 192.9481, 0, 0, 0, 0, 100, 0, 65094),
(563542, 26, 880.8452, 3604.09, 192.2138, 0, 0, 0, 0, 100, 0, 65094),
(563542, 27, 872.6632, 3604.306, 186.3784, 0, 0, 0, 0, 100, 0, 65094),
(563542, 28, 864.3507, 3604.464, 179.9518, 0, 0, 0, 0, 100, 0, 65094),
(563542, 29, 855.7952, 3604.771, 173.9375, 0, 0, 0, 0, 100, 0, 65094),
(563542, 30, 842.4983, 3605.719, 175.1503, 0, 0, 0, 0, 100, 0, 65094),
(563542, 31, 831.6441, 3606.068, 175.6706, 0, 0, 0, 0, 100, 0, 65094),
(563542, 32, 826.1893, 3606.186, 174.0028, 0, 0, 0, 0, 100, 0, 65094),
(563542, 33, 817.8646, 3606.239, 173.9988, 0, 3000, 0, 0, 100, 0, 65094),
(563542, 34, 831.4615, 3606.104, 175.687, 0, 0, 0, 0, 100, 0, 65094),
(563542, 35, 840.8438, 3605.762, 175.2293, 0, 0, 0, 0, 100, 0, 65094),
(563542, 36, 843.6996, 3605.823, 175.0175, 0, 0, 0, 0, 100, 0, 65094),
(563542, 37, 855.7295, 3604.688, 173.9153, 0, 0, 0, 0, 100, 0, 65094),
(563542, 38, 864.5486, 3604.5, 180.1131, 0, 0, 0, 0, 100, 0, 65094),
(563542, 39, 872.533, 3604.466, 186.272, 0, 0, 0, 0, 100, 0, 65094),
(563542, 40, 880.6354, 3604.159, 192.2187, 0, 0, 0, 0, 100, 0, 65094),
(563542, 41, 891.6962, 3603.894, 192.9396, 0, 0, 0, 0, 100, 0, 65094),

(563691, 1, 943.9896, 3636.325, 193.2813, 0, 0, 0, 0, 100, 0, 65094),
(563691, 2, 947.3837, 3627.359, 196.2978, 0, 0, 0, 0, 100, 0, 65094),
(563691, 3, 952.1424, 3622.79, 196.5403, 0, 0, 0, 0, 100, 0, 65094),
(563691, 4, 959.1024, 3616.575, 196.6137, 0, 0, 0, 0, 100, 0, 65094),
(563691, 5, 963.3386, 3612.076, 196.5711, 0, 3000, 0, 0, 100, 0, 65094),
(563691, 6, 954.7222, 3620.604, 196.6087, 0, 0, 0, 0, 100, 0, 65094),
(563691, 7, 948.618, 3627.277, 196.2688, 0, 0, 0, 0, 100, 0, 65094),
(563691, 8, 945.6077, 3636.783, 193.0307, 0, 0, 0, 0, 100, 0, 65094),
(563691, 9, 943.9045, 3643.669, 193.0337, 0, 0, 0, 0, 100, 0, 65094),
(563691, 10, 944.1371, 3648.949, 193.4054, 0, 0, 0, 0, 100, 0, 65094),
(563691, 11, 944.5764, 3654.38, 193.6169, 0, 0, 0, 0, 100, 0, 65094),
(563691, 12, 944.7986, 3664.668, 192.8571, 0, 0, 0, 0, 100, 0, 65094),
(563691, 13, 945.2257, 3674.629, 193.7462, 0, 0, 0, 0, 100, 0, 65094),
(563691, 14, 945.0191, 3680.828, 193.0319, 0, 0, 0, 0, 100, 0, 65094),
(563691, 15, 944.9288, 3690.043, 190.5973, 0, 0, 0, 0, 100, 0, 65094),
(563691, 16, 944.7743, 3700.635, 188.59, 0, 0, 0, 0, 100, 0, 65094),
(563691, 17, 946.2101, 3710.638, 189.127, 0, 0, 0, 0, 100, 0, 65094),
(563691, 18, 946.7222, 3717.799, 189.127, 0, 0, 0, 0, 100, 0, 65094),
(563691, 19, 947.5643, 3726.601, 189.127, 0, 3000, 0, 0, 100, 0, 65094),
(563691, 20, 944.408, 3710.384, 189.127, 0, 0, 0, 0, 100, 0, 65094),
(563691, 21, 944.5295, 3700.247, 188.5735, 0, 0, 0, 0, 100, 0, 65094),
(563691, 22, 944.3802, 3690.218, 190.555, 0, 0, 0, 0, 100, 0, 65094),
(563691, 23, 943.8143, 3681.181, 192.9471, 0, 0, 0, 0, 100, 0, 65094),
(563691, 24, 943.5816, 3672.675, 193.778, 0, 0, 0, 0, 100, 0, 65094),
(563691, 25, 943.9601, 3659.383, 192.7376, 0, 0, 0, 0, 100, 0, 65094),
(563691, 26, 943.6441, 3653.943, 193.6028, 0, 0, 0, 0, 100, 0, 65094),
(563691, 27, 944.1893, 3641.866, 193.0332, 0, 0, 0, 0, 100, 0, 65094);

-- Lamplighter Mu
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562775 AND `id` = 66690;

UPDATE `creature_template` SET `gossip_menu_id` = 15040 WHERE `entry` = 66690;

DELETE FROM `gossip_menu` WHERE `entry` = 15040 AND `text_id` = 21274;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(15040, 21274);

DELETE FROM `npc_text` WHERE `ID` = 21274;
INSERT INTO `npc_text` (`ID`, `text0_0`, `prob0`, `em0_0`) VALUES
(21274, "It is said that \"Wisdom lights the path.\"$b$b...But wisdom never kept me from stubbing my toe at night.", 1, 6);

DELETE FROM `creature_template_addon` WHERE `entry` = 66690;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(66690, 562775, 0, 0, 1, 0, "126968");

DELETE FROM `waypoint_data` WHERE `id` = 562775;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562775, 1, 682.3698, 3497.403, 119.1996, 0, 0, 0, 0, 100, 0, 66690),
(562775, 2, 682.8698, 3490.403, 119.1996, 0, 0, 0, 0, 100, 0, 66690),
(562775, 3, 687.3698, 3486.403, 119.1996, 0, 0, 0, 0, 100, 0, 66690),
(562775, 4, 692.6198, 3483.403, 119.1996, 0, 0, 0, 0, 100, 0, 66690),
(562775, 5, 695.3698, 3481.153, 118.9496, 0, 0, 0, 0, 100, 0, 66690),
(562775, 6, 699.3698, 3480.903, 118.9496, 0, 0, 0, 0, 100, 0, 66690),
(562775, 7, 705.2222, 3483.655, 119.3931, 1.518436, 7000, 0, 0, 100, 0, 66690),
(562775, 8, 709.625, 3483.516, 120.6, 0, 0, 0, 0, 100, 0, 66690),
(562775, 9, 715.625, 3485.516, 122.85, 0, 0, 0, 0, 100, 0, 66690),
(562775, 10, 719.875, 3488.016, 125.35, 0, 0, 0, 0, 100, 0, 66690),
(562775, 11, 727.125, 3490.516, 128.6, 0, 0, 0, 0, 100, 0, 66690),
(562775, 12, 732.125, 3492.516, 130.85, 0, 0, 0, 0, 100, 0, 66690),
(562775, 13, 738.125, 3494.516, 133.1, 0, 0, 0, 0, 100, 0, 66690),
(562775, 14, 744.125, 3493.266, 134.85, 0, 0, 0, 0, 100, 0, 66690),
(562775, 15, 751.0278, 3493.377, 136.8069, 0.7504916, 7000, 0, 0, 100, 0, 66690),
(562775, 16, 751.3611, 3497.576, 137.2814, 0, 0, 0, 0, 100, 0, 66690),
(562775, 17, 752.8611, 3502.326, 138.0314, 0, 0, 0, 0, 100, 0, 66690),
(562775, 18, 758.3611, 3505.826, 139.0314, 0, 0, 0, 0, 100, 0, 66690),
(562775, 19, 761.3611, 3509.826, 140.0314, 0, 0, 0, 0, 100, 0, 66690),
(562775, 20, 762.1945, 3515.276, 139.756, 2.076942, 7000, 0, 0, 100, 0, 66690),
(562775, 21, 766.9245, 3514.109, 140.4967, 0, 0, 0, 0, 100, 0, 66690),
(562775, 22, 768.1745, 3519.359, 140.4967, 0, 0, 0, 0, 100, 0, 66690),
(562775, 23, 761.6745, 3525.609, 139.9967, 0, 0, 0, 0, 100, 0, 66690),
(562775, 24, 755.6745, 3533.359, 139.7467, 0, 0, 0, 0, 100, 0, 66690),
(562775, 25, 747.6745, 3548.359, 140.2467, 0, 0, 0, 0, 100, 0, 66690),
(562775, 26, 743.6745, 3552.109, 140.4967, 0, 0, 0, 0, 100, 0, 66690),
(562775, 27, 737.6745, 3555.859, 141.2467, 0, 0, 0, 0, 100, 0, 66690),
(562775, 28, 734.9245, 3557.359, 141.7467, 0, 0, 0, 0, 100, 0, 66690),
(562775, 29, 732.6545, 3560.943, 141.2375, 0, 7000, 0, 0, 100, 0, 66690),
(562775, 30, 734.3472, 3558.056, 141.6904, 0, 0, 0, 0, 100, 0, 66690),
(562775, 31, 737.5972, 3557.056, 140.9404, 0, 0, 0, 0, 100, 0, 66690),
(562775, 32, 743.5972, 3554.056, 140.4404, 0, 0, 0, 0, 100, 0, 66690),
(562775, 33, 746.3472, 3551.056, 140.1904, 0, 0, 0, 0, 100, 0, 66690),
(562775, 34, 749.8472, 3544.306, 139.6904, 0, 0, 0, 0, 100, 0, 66690),
(562775, 35, 752.5972, 3539.556, 139.6904, 0, 0, 0, 0, 100, 0, 66690),
(562775, 36, 756.8472, 3532.306, 139.6904, 0, 0, 0, 0, 100, 0, 66690),
(562775, 37, 758.0972, 3524.556, 139.4404, 0, 0, 0, 0, 100, 0, 66690),
(562775, 38, 757.5972, 3515.306, 138.9404, 0, 0, 0, 0, 100, 0, 66690),
(562775, 39, 756.3472, 3507.806, 138.4404, 0, 0, 0, 0, 100, 0, 66690),
(562775, 40, 752.3472, 3498.556, 137.4404, 0, 0, 0, 0, 100, 0, 66690),
(562775, 41, 746.3472, 3492.056, 135.4404, 0, 0, 0, 0, 100, 0, 66690),
(562775, 42, 738.3472, 3488.306, 131.9404, 0, 0, 0, 0, 100, 0, 66690),
(562775, 43, 729.3472, 3484.306, 127.6904, 0, 0, 0, 0, 100, 0, 66690),
(562775, 44, 720.0972, 3480.306, 123.4404, 0, 0, 0, 0, 100, 0, 66690),
(562775, 45, 709.5972, 3474.806, 120.1904, 0, 0, 0, 0, 100, 0, 66690),
(562775, 46, 700.5972, 3468.306, 118.6904, 0, 0, 0, 0, 100, 0, 66690),
(562775, 47, 695.8472, 3464.556, 117.9404, 0, 0, 0, 0, 100, 0, 66690),
(562775, 48, 692.3472, 3459.306, 116.6904, 0, 0, 0, 0, 100, 0, 66690),
(562775, 49, 690.0972, 3453.056, 114.9404, 0, 0, 0, 0, 100, 0, 66690),
(562775, 50, 688.8472, 3446.306, 113.4404, 0, 0, 0, 0, 100, 0, 66690),
(562775, 51, 686.5972, 3440.806, 111.6904, 0, 0, 0, 0, 100, 0, 66690),
(562775, 52, 685.0399, 3437.169, 110.1432, 0, 7000, 0, 0, 100, 0, 66690),
(562775, 53, 686.3932, 3441.04, 111.6765, 0, 0, 0, 0, 100, 0, 66690),
(562775, 54, 689.3932, 3448.29, 113.9265, 0, 0, 0, 0, 100, 0, 66690),
(562775, 55, 691.6432, 3455.29, 115.6765, 0, 0, 0, 0, 100, 0, 66690),
(562775, 56, 694.3932, 3462.04, 117.4265, 0, 0, 0, 0, 100, 0, 66690),
(562775, 57, 697.6432, 3470.29, 118.1765, 0, 0, 0, 0, 100, 0, 66690),
(562775, 58, 696.1432, 3477.04, 118.6765, 0, 0, 0, 0, 100, 0, 66690),
(562775, 59, 691.8932, 3482.79, 118.9265, 0, 0, 0, 0, 100, 0, 66690),
(562775, 60, 685.2465, 3484.911, 118.7098, 0, 0, 0, 0, 100, 0, 66690),
(562775, 61, 679.1511, 3493.214, 118.7684, 0, 0, 0, 0, 100, 0, 66690),
(562775, 62, 677.5261, 3498.067, 118.7684, 0, 15000, 0, 0, 100, 0, 66690),
(562775, 63, 681.2717, 3500.109, 118.8873, 0, 0, 0, 0, 100, 0, 66690),
(562775, 64, 682.5217, 3501.859, 118.8873, 0, 0, 0, 0, 100, 0, 66690),
(562775, 65, 683.0174, 3504.151, 119.0062, 4.677482, 82000, 0, 0, 100, 0, 66690);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 66690;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 66690 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (66690*100, 66690*100+01) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(66690, 0, 0, 0, 34, 0, 100, 0, 2, 6, 0, 0, 80, 66690*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Mu - MI 6 - Start Script"),
(66690, 0, 1, 0, 34, 0, 100, 0, 2, 14, 0, 0, 80, 66690*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Mu - MI 14 - Start Script"),
(66690, 0, 2, 0, 34, 0, 100, 0, 2, 19, 0, 0, 80, 66690*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Mu - MI 19 - Start Script"),
(66690, 0, 3, 0, 34, 0, 100, 0, 2, 28, 0, 0, 80, 66690*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Mu - MI 28 - Start Script"),
(66690, 0, 4, 0, 34, 0, 100, 0, 2, 51, 0, 0, 80, 66690*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Mu - MI 51 - Start Script"),
(66690, 0, 5, 0, 34, 0, 100, 0, 2, 61, 0, 0, 80, 66690*100+02, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Mu - MI 61 - Start Script"),

(66690*100, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 128, 2704, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Mu - On Script - Play Anim Kit"),

(66690*100+01, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Mu - On Script - Play Emote"),
(66690*100+01, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Mu - On Script - Play Emote");

-- Trader Feng
UPDATE `creature` SET `position_x` = 685.9648, `position_y` = 3457.286, `position_z` = 115.2643, `orientation` = 4.438516, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562782;

DELETE FROM `creature_template_addon` WHERE `entry` = 65087;
DELETE FROM `creature_addon` WHERE `guid` = 562782;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(562782, 562782, 1);

DELETE FROM `waypoint_data` WHERE `id` = 562782;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562782, 1, 682.5261, 3445.052, 111.3957, 0, 0, 0, 0, 100, 0, 65087),
(562782, 2, 677.9879, 3435.248, 108.3949, 0, 0, 0, 0, 100, 0, 65087),
(562782, 3, 672.0121, 3428.091, 105.7101, 0, 0, 0, 0, 100, 0, 65087),
(562782, 4, 665.7396, 3421.781, 103.6911, 0, 0, 0, 0, 100, 0, 65087),
(562782, 5, 672.0121, 3428.091, 105.7101, 0, 0, 0, 0, 100, 0, 65087),
(562782, 6, 677.9879, 3435.248, 108.3949, 0, 0, 0, 0, 100, 0, 65087),
(562782, 7, 682.5261, 3445.052, 111.3957, 0, 0, 0, 0, 100, 0, 65087),
(562782, 8, 685.9618, 3457.276, 115.4463, 0, 0, 0, 0, 100, 0, 65087),
(562782, 9, 688.4932, 3464.862, 117.3893, 0, 0, 0, 0, 100, 0, 65087),
(562782, 10, 695.3524, 3474.267, 118.2684, 0, 0, 0, 0, 100, 0, 65087),
(562782, 11, 707.7864, 3480.49, 119.6443, 0, 0, 0, 0, 100, 0, 65087),
(562782, 12, 718.7917, 3484.793, 123.47, 0, 0, 0, 0, 100, 0, 65087),
(562782, 13, 729.8662, 3489.422, 128.9295, 0, 0, 0, 0, 100, 0, 65087),
(562782, 14, 736.9288, 3492.556, 131.9822, 0, 0, 0, 0, 100, 0, 65087),
(562782, 15, 744.9202, 3499.066, 135.8553, 0, 0, 0, 0, 100, 0, 65087),
(562782, 16, 748.9774, 3506.485, 137.2696, 0, 0, 0, 0, 100, 0, 65087),
(562782, 17, 752.2049, 3515.733, 138.4052, 0, 0, 0, 0, 100, 0, 65087),
(562782, 18, 752.684, 3525.537, 138.9453, 0, 0, 0, 0, 100, 0, 65087),
(562782, 19, 750.6389, 3533.383, 139.3126, 0, 0, 0, 0, 100, 0, 65087),
(562782, 20, 746.3143, 3539.372, 139.5674, 0, 0, 0, 0, 100, 0, 65087),
(562782, 21, 741.3802, 3548.038, 140.4095, 0, 0, 0, 0, 100, 0, 65087),
(562782, 22, 739.0538, 3557.195, 140.6876, 0, 0, 0, 0, 100, 0, 65087),
(562782, 23, 737.0833, 3565.836, 140.6876, 0, 0, 0, 0, 100, 0, 65087),
(562782, 24, 735.7222, 3575.628, 140.6348, 0, 0, 0, 0, 100, 0, 65087),
(562782, 25, 735.6476, 3587.222, 140.6348, 0, 0, 0, 0, 100, 0, 65087),
(562782, 26, 734.0833, 3597.866, 140.6348, 0, 0, 0, 0, 100, 0, 65087),
(562782, 27, 731.5486, 3610.281, 140.7456, 0, 0, 0, 0, 100, 0, 65087),
(562782, 28, 734.8965, 3622.396, 140.6299, 0, 0, 0, 0, 100, 0, 65087),
(562782, 29, 734.934, 3627.23, 142.631, 0, 0, 0, 0, 100, 0, 65087),
(562782, 30, 736.5643, 3634.82, 142.6308, 0, 0, 0, 0, 100, 0, 65087),
(562782, 31, 737.8351, 3642.159, 142.6355, 0, 0, 0, 0, 100, 0, 65087),
(562782, 32, 736.5643, 3634.82, 142.6308, 0, 0, 0, 0, 100, 0, 65087),
(562782, 33, 734.934, 3627.23, 142.631, 0, 0, 0, 0, 100, 0, 65087),
(562782, 34, 734.375, 3621.875, 140.6299, 0, 0, 0, 0, 100, 0, 65087),
(562782, 35, 731.5486, 3610.281, 140.7456, 0, 0, 0, 0, 100, 0, 65087),
(562782, 36, 734.0833, 3597.866, 140.6348, 0, 0, 0, 0, 100, 0, 65087),
(562782, 37, 735.6476, 3587.222, 140.6348, 0, 0, 0, 0, 100, 0, 65087),
(562782, 38, 735.7222, 3575.628, 140.6348, 0, 0, 0, 0, 100, 0, 65087),
(562782, 39, 737.0833, 3565.836, 140.6876, 0, 0, 0, 0, 100, 0, 65087),
(562782, 40, 739.0538, 3557.195, 140.6876, 0, 0, 0, 0, 100, 0, 65087),
(562782, 41, 741.3802, 3548.038, 140.4095, 0, 0, 0, 0, 100, 0, 65087),
(562782, 42, 746.3143, 3539.372, 139.5674, 0, 0, 0, 0, 100, 0, 65087),
(562782, 43, 750.6389, 3533.383, 139.3126, 0, 0, 0, 0, 100, 0, 65087),
(562782, 44, 752.684, 3525.537, 138.9453, 0, 0, 0, 0, 100, 0, 65087),
(562782, 45, 752.2049, 3515.733, 138.4052, 0, 0, 0, 0, 100, 0, 65087),
(562782, 46, 748.9774, 3506.485, 137.2696, 0, 0, 0, 0, 100, 0, 65087),
(562782, 47, 744.9202, 3499.066, 135.8553, 0, 0, 0, 0, 100, 0, 65087),
(562782, 48, 736.9288, 3492.556, 131.9822, 0, 0, 0, 0, 100, 0, 65087),
(562782, 49, 730.1268, 3489.528, 129.2023, 0, 0, 0, 0, 100, 0, 65087),
(562782, 50, 718.7917, 3484.793, 123.47, 0, 0, 0, 0, 100, 0, 65087),
(562782, 51, 707.7864, 3480.49, 119.6443, 0, 0, 0, 0, 100, 0, 65087),
(562782, 52, 695.3524, 3474.267, 118.2684, 0, 0, 0, 0, 100, 0, 65087),
(562782, 53, 688.4965, 3464.872, 117.3337, 0, 0, 0, 0, 100, 0, 65087),
(562782, 54, 685.9648, 3457.286, 115.2643, 0, 0, 0, 0, 100, 0, 65087);

-- Groundskeeper Amalia
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562783;

DELETE FROM `creature_template_addon` WHERE `entry` = 65077;
DELETE FROM `creature_addon` WHERE `guid` = 562783;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(562783, 562783, 1);

DELETE FROM `waypoint_data` WHERE `id` = 562783;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562783, 1, 720.3629, 3517.311, 141.2257, 0, 0, 0, 0, 100, 0, 65077),
(562783, 2, 720.3629, 3517.311, 141.2257, 0, 4000, 0, 0, 100, 0, 65077),
(562783, 3, 735.2761, 3517.652, 140.2504, 0, 0, 0, 0, 100, 0, 65077),
(562783, 4, 739.3906, 3522.052, 140.4548, 0, 0, 0, 0, 100, 0, 65077),
(562783, 5, 739.8472, 3527.497, 140.6105, 0, 0, 0, 0, 100, 0, 65077),
(562783, 6, 736.4809, 3530.385, 140.7048, 0, 4000, 0, 0, 100, 0, 65077),
(562783, 7, 736.6268, 3537.718, 140.6876, 0, 0, 0, 0, 100, 0, 65077),
(562783, 8, 730.2899, 3540.156, 140.9006, 0, 5000, 0, 0, 100, 0, 65077),
(562783, 9, 722.0608, 3544.668, 141.283, 0, 0, 0, 0, 100, 0, 65077),
(562783, 10, 719.0677, 3543.64, 141.4743, 0, 4000, 0, 0, 100, 0, 65077),
(562783, 11, 716.3507, 3532.825, 141.6007, 0, 0, 0, 0, 100, 0, 65077),
(562783, 12, 713.0677, 3527.756, 141.1189, 0, 4000, 0, 0, 100, 0, 65077);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 65077;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 65077 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 65077*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(65077, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 65077*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Groundskeeper Amalia - MI 1 - Start Script"),
(65077, 0, 1, 0, 34, 0, 100, 0, 2, 5, 0, 0, 80, 65077*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Groundskeeper Amalia - MI 5 - Start Script"),
(65077, 0, 2, 0, 34, 0, 100, 0, 2, 7, 0, 0, 80, 65077*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Groundskeeper Amalia - MI 7 - Start Script"),
(65077, 0, 3, 0, 34, 0, 100, 0, 2, 9, 0, 0, 80, 65077*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Groundskeeper Amalia - MI 9 - Start Script"),
(65077, 0, 4, 0, 34, 0, 100, 0, 2, 11, 0, 0, 80, 65077*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Groundskeeper Amalia - MI 11 - Start Script"),

(65077*100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 381, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Groundskeeper Amalia - On Script - Play Emote");

-- Jin
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 65085;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 65085 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(65085, 0, 0, 0, 1, 0, 100, 0, 0, 0, 3000, 10000, 10, 5, 273, 396, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jin - Update OOC - Play Random Emote (5, 273, 396)");

-- Da Na
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 65086;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 65086 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(65086, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 3000, 10000, 10, 5, 273, 396, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Da Na - Update OOC - Play Random Emote (5, 273, 396)");

-- Gan Darkcask
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 65044;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 65044 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(65044, 0, 0, 0, 1, 0, 100, 0, 0, 0, 3000, 10000, 10, 5, 273, 396, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gan Darkcask - Update OOC - Play Random Emote (5, 273, 396)");

-- Gao Longwagon
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 65045;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 65045 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(65045, 0, 0, 0, 1, 0, 100, 0, 3000, 5000, 3000, 10000, 10, 5, 273, 396, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Gao Longwagon - Update OOC - Play Random Emote (5, 273, 396)");

-- Lorewalker Amai
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (64875, 64881, 64880, 64879, 64876);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (64875, 64881, 64880, 64879, 64876) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6487500, 6487600) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(64875, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 326000, 326000, 80, 6487500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Update OOC - Start Script"),

(6487500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 4, 1, 0, 0, 0, 0, 10, 562813, 64876, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 4 1"),
(6487500, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 0"),
(6487500, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 562807, 64881, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 1 1"),
(6487500, 9, 3, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 1"),
(6487500, 9, 4, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 2, 1, 0, 0, 0, 0, 10, 562815, 64880, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 2 1"),
(6487500, 9, 5, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 2"),
(6487500, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 3"),
(6487500, 9, 7, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 4"),
(6487500, 9, 8, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 3, 1, 0, 0, 0, 0, 10, 562810, 64879, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 3 1"),
(6487500, 9, 9, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 5"),
(6487500, 9, 10, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 6"),
(6487500, 9, 11, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 7"),
(6487500, 9, 12, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 1, 2, 0, 0, 0, 0, 10, 562807, 64881, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 1 2"),
(6487500, 9, 13, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Play Emote (11)"),
(6487500, 9, 14, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 8"),
(6487500, 9, 15, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 562815, 64880, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 2 2"),
(6487500, 9, 16, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 1, 3, 0, 0, 0, 0, 10, 562807, 64881, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 1 3"),
(6487500, 9, 17, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 9"),
(6487500, 9, 18, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 1, 4, 0, 0, 0, 0, 10, 562807, 64881, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 1 4"),
(6487500, 9, 19, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 10"),
(6487500, 9, 20, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 11"),
(6487500, 9, 21, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 2, 3, 0, 0, 0, 0, 10, 562815, 64880, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 2 3"),
(6487500, 9, 22, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 45, 1, 5, 0, 0, 0, 0, 10, 562807, 64881, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 1 5"),
(6487500, 9, 23, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 1, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 12"),
(6487500, 9, 24, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 13"),
(6487500, 9, 25, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 1, 6, 0, 0, 0, 0, 10, 562807, 64881, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 1 6"),
(6487500, 9, 26, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 45, 2, 4, 0, 0, 0, 0, 10, 562815, 64880, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 2 4"),
(6487500, 9, 27, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 1, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 14"),
(6487500, 9, 28, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 15"),
(6487500, 9, 29, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 3, 2, 0, 0, 0, 0, 10, 562810, 64879, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 3 2"),
(6487500, 9, 30, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 16"),
(6487500, 9, 31, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 17"),
(6487500, 9, 32, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, 562810, 64879, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 3 3"),
(6487500, 9, 33, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 18"),
(6487500, 9, 34, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 19, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 19"),
(6487500, 9, 35, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 2, 5, 0, 0, 0, 0, 10, 562815, 64880, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 2 5"),
(6487500, 9, 36, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 20"),
(6487500, 9, 37, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 1, 7, 0, 0, 0, 0, 10, 562807, 64881, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 1 7"),
(6487500, 9, 38, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 21"),
(6487500, 9, 39, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 3, 4, 0, 0, 0, 0, 10, 562810, 64879, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 3 4"),
(6487500, 9, 40, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 22"),
(6487500, 9, 41, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 2, 6, 0, 0, 0, 0, 10, 562815, 64880, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 2 6"),
(6487500, 9, 42, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 23"),
(6487500, 9, 43, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 1, 8, 0, 0, 0, 0, 10, 562807, 64881, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 1 8"),
(6487500, 9, 44, 0, 0, 0, 100, 0, 3500, 3500, 0, 0, 45, 2, 7, 0, 0, 0, 0, 10, 562815, 64880, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 2 7"),
(6487500, 9, 45, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 45, 1, 9, 0, 0, 0, 0, 10, 562807, 64881, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 1 9"),
(6487500, 9, 46, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 45, 3, 5, 0, 0, 0, 0, 10, 562810, 64879, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 3 5"),
(6487500, 9, 47, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 24"),
(6487500, 9, 48, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 25"),
(6487500, 9, 49, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 26"),
(6487500, 9, 50, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 27, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 27"),
(6487500, 9, 51, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 28"),
(6487500, 9, 52, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 29, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 29"),
(6487500, 9, 53, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 4, 2, 0, 0, 0, 0, 10, 562813, 64876, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 4 2"),
(6487500, 9, 54, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 30"),
(6487500, 9, 55, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 31, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 31"),
(6487500, 9, 56, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 1, 10, 0, 0, 0, 0, 10, 562807, 64881, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 1 10"),
(6487500, 9, 57, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 2, 8, 0, 0, 0, 0, 10, 562815, 64880, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 2 8"),
(6487500, 9, 58, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 32"),
(6487500, 9, 59, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 45, 1, 11, 0, 0, 0, 0, 10, 562807, 64881, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 1 11"),
(6487500, 9, 60, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 33, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 33"),
(6487500, 9, 61, 0, 0, 0, 100, 0, 4500, 4500, 0, 0, 1, 34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 34"),
(6487500, 9, 62, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 45, 3, 6, 0, 0, 0, 0, 10, 562810, 64879, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 3 6"),
(6487500, 9, 63, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 35"),
(6487500, 9, 64, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 36"),
(6487500, 9, 65, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 37, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 37"),
(6487500, 9, 66, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.380776, "Lorewalker Amai - Set Orientation (4.380776)"),
(6487500, 9, 67, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 38, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 38"),
(6487500, 9, 68, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 39, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Amai - Say Text Line 39"),
(6487500, 9, 69, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 4, 3, 0, 0, 0, 0, 10, 562813, 64876, 0, 0, 0, 0, 0, "Lorewalker Amai - Set Data 4 3"),
(6487500, 9, 70, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.821526, "Lorewalker Amai - Set Orientation (5.821526)"),
-- Hao
(64881, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hao - On Data Set 1 1 - Say Text Line 0"),
(64881, 0, 1, 0, 38, 0, 100, 0, 1, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hao - On Data Set 1 2 - Say Text Line 1"),
(64881, 0, 2, 0, 38, 0, 100, 0, 1, 3, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hao - On Data Set 1 3 - Say Text Line 2"),
(64881, 0, 3, 0, 38, 0, 100, 0, 1, 4, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hao - On Data Set 1 4 - Say Text Line 3"),
(64881, 0, 4, 0, 38, 0, 100, 0, 1, 5, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hao - On Data Set 1 5 - Say Text Line 4"),
(64881, 0, 5, 0, 38, 0, 100, 0, 1, 6, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hao - On Data Set 1 6 - Say Text Line 5"),
(64881, 0, 6, 0, 38, 0, 100, 0, 1, 7, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hao - On Data Set 1 7 - Say Text Line 6"),
(64881, 0, 7, 0, 38, 0, 100, 0, 1, 8, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hao - On Data Set 1 8 - Say Text Line 7"),
(64881, 0, 8, 0, 38, 0, 100, 0, 1, 9, 0, 0, 1, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hao - On Data Set 1 9 - Say Text Line 8"),
(64881, 0, 9, 0, 38, 0, 100, 0, 1, 10, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hao - On Data Set 1 10 - Say Text Line 9"),
(64881, 0, 10, 0, 38, 0, 100, 0, 1, 11, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Hao - On Data Set 1 11 - Say Text Line 10"),
-- Nan
(64880, 0, 0, 0, 38, 0, 100, 0, 2, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nan - On Data Set 2 1 - Say Text Line 0"),
(64880, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nan - On Data Set 2 2 - Say Text Line 1"),
(64880, 0, 2, 0, 38, 0, 100, 0, 2, 3, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nan - On Data Set 2 3 - Say Text Line 2"),
(64880, 0, 3, 0, 38, 0, 100, 0, 2, 4, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nan - On Data Set 2 4 - Say Text Line 3"),
(64880, 0, 4, 0, 38, 0, 100, 0, 2, 5, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nan - On Data Set 2 5 - Say Text Line 4"),
(64880, 0, 5, 0, 38, 0, 100, 0, 2, 6, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nan - On Data Set 2 6 - Say Text Line 5"),
(64880, 0, 6, 0, 38, 0, 100, 0, 2, 7, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nan - On Data Set 2 7 - Say Text Line 6"),
(64880, 0, 7, 0, 38, 0, 100, 0, 2, 8, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Nan - On Data Set 2 8 - Say Text Line 7"),
-- Yin
(64879, 0, 0, 0, 38, 0, 100, 0, 3, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Yin - On Data Set 3 1 - Say Text Line 0"),
(64879, 0, 1, 0, 38, 0, 100, 0, 3, 2, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Yin - On Data Set 3 2 - Say Text Line 1"),
(64879, 0, 2, 0, 38, 0, 100, 0, 3, 3, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Yin - On Data Set 3 3 - Say Text Line 2"),
(64879, 0, 3, 0, 38, 0, 100, 0, 3, 4, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Yin - On Data Set 3 4 - Say Text Line 3"),
(64879, 0, 4, 0, 38, 0, 100, 0, 3, 5, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Yin - On Data Set 3 5 - Say Text Line 4"),
(64879, 0, 5, 0, 38, 0, 100, 0, 3, 6, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Yin - On Data Set 3 6 - Say Text Line 5"),
-- Lorewalker Ruolin
(64876, 0, 0, 1, 38, 0, 100, 0, 4, 1, 0, 0, 11, 126804, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Ruolin - On Data Set 4 1 - Cast Spell 'Singing'"),
(64876, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 6487600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Ruolin - On Data Set 4 1 (Link) - Start Script"),
(64876, 0, 2, 0, 38, 0, 100, 0, 4, 2, 0, 0, 28, 126804, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Ruolin - On Data Set 4 2 - Remove Aura"),
(64876, 0, 3, 0, 38, 0, 100, 0, 4, 3, 0, 0, 5, 273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Ruolin - On Data Set 4 3 - Play Emote (273)"),

(6487600, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 4, 30627, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lorewalker Ruolin - Play Sound (30627)");

DELETE FROM `creature_text` WHERE `entry` IN (64875, 64881, 64880, 64879);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(64875, 0, 0, "", "This is the Song of Liu Lang, the first pandaren explorer.", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 1, 0, "", "The song is written in the old tongue, the language of emperors and scholars. Hardly anyone speaks it anymore.", 12, 0, 100, 6, 0, 0, "Lorewalker Amai"),
(64875, 2, 0, "", "It is all about his adventures.", 12, 0, 100, 273, 0, 0, "Lorewalker Amai"),
(64875, 3, 0, "", "Brave Liu Lang set out to explore the world on the back of a sea turtle.", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 4, 0, "", "Does anyone remember the turtle's name? Yin?", 12, 0, 100, 25, 0, 0, "Lorewalker Amai"),
(64875, 5, 0, "", "That's right, the turtle was called Shen-zin Su. At first, he was only big enough for Liu Lang to sit on.", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 6, 0, "", "He grew and grew and grew, SO big, that now some people call him \"The Wandering Isle.\"", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 7, 0, "", "Question, Hao?", 12, 0, 100, 25, 0, 0, "Lorewalker Amai"),
(64875, 8, 0, "", "Yes, Hao - our home is on Shen-zin Su's back.", 12, 0, 100, 273, 0, 0, "Lorewalker Amai"),
(64875, 9, 0, "", "Liu Lang discovered many things as he explored the world - oh - yes, Hao?", 12, 0, 100, 6, 0, 0, "Lorewalker Amai"),
(64875, 10, 0, "", "That's a good question. Nobody has spoken to Shen-zin Su for many generations. He only ever spoke to Liu Lang.", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 11, 0, "", "But I am certain that Shen-zin Su knows we are here. And he cares for every one of us!", 12, 0, 100, 66, 0, 0, "Lorewalker Amai"),
(64875, 12, 0, "", "Especially Hao! Liu Lang once said, \"Noble is he who always asks questions.\"", 12, 0, 100, 6, 0, 0, "Lorewalker Amai"),
(64875, 13, 0, "", "\"We should all be like children, for the world is our elder, and has many things to teach us.\"", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 14, 0, "", "Students! Students! Pay attention now.", 12, 0, 100, 22, 0, 0, "Lorewalker Amai"),
(64875, 15, 0, "", "Does anyone know how often Liu Lang went back to Pandaria?", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 16, 0, "", "Haha, no Yin. Liu Lang would eat wherever he explored.", 12, 0, 100, 11, 0, 0, "Lorewalker Amai"),
(64875, 17, 0, "", "He returned to the main continent of Pandaria once every five years.", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 18, 0, "", "You are right, Yin. It IS hidden away, behind a cloak of mists.", 12, 0, 100, 274, 0, 0, "Lorewalker Amai"),
(64875, 19, 0, "", "Does anyone remember how Liu Lang was always able to find it? Nan?", 12, 0, 100, 6, 0, 0, "Lorewalker Amai"),
(64875, 20, 0, "", "That's right! Liu Lang always had a way back home. Every five years, he would return, to pick up more explorers.", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 21, 0, "", "Yes Hao! Only the BRAVEST pandaren joined Liu Lang on his turtle to explore the world.", 12, 0, 100, 273, 0, 0, "Lorewalker Amai"),
(64875, 22, 0, "", "Shen-zin Su hasn't made landfall for a long time. But that hasn't stopped some pandaren from exploring, anyway.", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 23, 0, "", "Yes, like Chen and Li Li! They're out, exploring the world. Maybe someday you will, too.", 12, 0, 100, 21, 0, 0, "Lorewalker Amai"),
(64875, 24, 0, "", "I'm glad you asked, Yin. Liu Lang explored the world his entire life, and raised many children here on the Wandering Isle.", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 25, 0, "", "Eventually he grew very old, and visited Pandaria one final time.", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 26, 0, "", "But nobody else wanted to go exploring with him. So he left.", 12, 0, 100, 6, 0, 0, "Lorewalker Amai"),
(64875, 27, 0, "", "Shen-zin Su has never returned to Pandaria.", 12, 0, 100, 274, 0, 0, "Lorewalker Amai"),
(64875, 28, 0, "", "Tired now, Liu Lang said goodbye to Shen-zin Su, his oldest friend.", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 29, 0, "", "Then, Liu Lang went up to the Wood of Staves, carrying with him a bamboo umbrella that he always took on his adventures.", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 30, 0, "", "He opened his umbrella, planted it in the ground, and sat underneath its cool shade.", 12, 0, 100, 6, 0, 0, "Lorewalker Amai"),
(64875, 31, 0, "", "He closed his eyes, and became one with the land. And then - do you know what happened?", 12, 0, 100, 2, 0, 0, "Lorewalker Amai"),
(64875, 32, 0, "", "His umbrella... sprouted! It grew roots, flowered, and became a tree!", 12, 0, 100, 5, 0, 0, "Lorewalker Amai"),
(64875, 33, 0, "", "Well, it's true. If you ever go to the Wood of Staves, you can see it.", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 34, 0, "", "Along with the budding staves of all the elders who came before us, growing now into giant trees.", 12, 0, 100, 274, 0, 0, "Lorewalker Amai"),
(64875, 35, 0, "", "It's not a sad story! Liu Lang himself said, \"Never mourn a life well-lived.\"", 12, 0, 100, 1, 0, 0, "Lorewalker Amai"),
(64875, 36, 0, "", "And I think he lived a very very good life. We owe everything we have to Liu Lang, the first pandaren explorer.", 12, 0, 100, 273, 0, 0, "Lorewalker Amai"),
(64875, 37, 0, "", "We tell his story, so that he will always be remembered.", 12, 0, 100, 2, 0, 0, "Lorewalker Amai"),
(64875, 38, 0, "", "Thank you, Ruolin! That was beautiful.", 12, 0, 100, 21, 0, 0, "Lorewalker Amai"),
(64875, 39, 0, "", "Could you sing it once more, for the students who just arrived?", 12, 0, 100, 6, 0, 0, "Lorewalker Amai"),

(64881, 0, 0, "Why can't I understand any of the words?", "", 12, 0, 100, 1, 0, 0, "Hao"),
(64881, 1, 0, "We live on the back of a big turtle?!", "", 12, 0, 100, 5, 0, 0, "Hao"),
(64881, 2, 0, "I just thought it was weird that the mountains had flippers!", "", 12, 0, 100, 1, 0, 0, "Hao"),
(64881, 3, 0, "Does the turtle know we're here?", "", 12, 0, 100, 1, 0, 0, "Hao"),
(64881, 4, 0, "Hey!", "", 12, 0, 100, 1, 0, 0, "Hao"),
(64881, 5, 0, "Yeah, you should all be more like me.", "", 12, 0, 100, 1, 0, 0, "Hao"),
(64881, 6, 0, "Does that mean our moms and dads and grandparents were all explorers, too?", "", 12, 0, 100, 1, 0, 0, "Hao"),
(64881, 7, 0, "I want to explore the world!", "", 12, 0, 100, 1, 0, 0, "Hao"),
(64881, 8, 0, "Oh. Well, forget it then.", "", 12, 0, 100, 1, 0, 0, "Hao"),
(64881, 9, 0, "What?", "", 12, 0, 100, 1, 0, 0, "Hao"),
(64881, 10, 0, "That's un-possible!", "", 12, 0, 100, 1, 0, 0, "Hao"),

(64880, 0, 0, "", "What is the song about?", 12, 0, 100, 1, 0, 0, "Nan"),
(64880, 1, 0, "", "Sheesh, Hao. Haven't you ever paid attention?", 12, 0, 100, 1, 0, 0, "Nan"),
(64880, 2, 0, "", "Even Hao?", 12, 0, 100, 6, 0, 0, "Nan"),
(64880, 3, 0, "", "Blerch! I'd rather jump off this bridge.", 12, 0, 100, 1, 0, 0, "Nan"),
(64880, 4, 0, "", "Because sea turtles always return to the beach where they were born!", 12, 0, 100, 1, 0, 0, "Nan"),
(64880, 5, 0, "", "Like Chen and Li Li Stormstout!", 12, 0, 100, 1, 0, 0, "Nan"),
(64880, 6, 0, "", "No you don't. It's full of trolls.", 12, 0, 100, 1, 0, 0, "Nan"),
(64880, 7, 0, "", "What? What?", 12, 0, 100, 1, 0, 0, "Nan"),

(64879, 0, 0, "", "Shen-zin Su!", 12, 0, 100, 1, 0, 0, "Yin"),
(64879, 1, 0, "", "...Whenever he got hungry?", 12, 0, 100, 1, 0, 0, "Yin"),
(64879, 2, 0, "", "But isn't Pandaria hidden somewhere? Nobody can find it!", 12, 0, 100, 1, 0, 0, "Yin"),
(64879, 3, 0, "", "But we don't explore very much anymore, do we?", 12, 0, 100, 1, 0, 0, "Yin"),
(64879, 4, 0, "", "Lorewalker! What ever happened to Liu Lang?", 12, 0, 100, 1, 0, 0, "Yin"),
(64879, 5, 0, "", "That's a sad story!", 12, 0, 100, 1, 0, 0, "Yin");

-- Vision of Dafeng & Vision of Zhao-Ren
UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` IN (65559, 65560);
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 563687;

DELETE FROM `creature_template_addon` WHERE `entry` IN (65559, 65560);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `bytes1`, `bytes2`) VALUES
(65559, 563687, 50331648, 1),
(65560, 0, 50331648, 1);

DELETE FROM `waypoint_data` WHERE `id` = 563687;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(563687, 1, 1163.323, 4094.89, 196.7238, 0, 0, 1, 0, 100, 0, 65560),
(563687, 2, 1160.189, 4088.899, 196.8717, 0, 0, 1, 0, 100, 0, 65560),
(563687, 3, 1156.356, 4080.826, 199.6824, 0, 0, 1, 0, 100, 0, 65560),
(563687, 4, 1157.795, 4074.997, 201.5452, 0, 0, 1, 0, 100, 0, 65560),
(563687, 5, 1162.868, 4072.484, 203.9529, 0, 0, 1, 0, 100, 0, 65560),
(563687, 6, 1170.455, 4076.58, 206.3303, 0, 0, 1, 0, 100, 0, 65560),
(563687, 7, 1173.443, 4088.29, 209.1731, 0, 0, 1, 0, 100, 0, 65560),
(563687, 8, 1171.333, 4097.327, 209.1731, 0, 0, 1, 0, 100, 0, 65560),
(563687, 9, 1170.729, 4107.088, 208.22, 0, 0, 1, 0, 100, 0, 65560),
(563687, 10, 1177.141, 4113.896, 207.1179, 0, 0, 1, 0, 100, 0, 65560),
(563687, 11, 1185.208, 4111.542, 205.3374, 0, 0, 1, 0, 100, 0, 65560),
(563687, 12, 1186.818, 4103.221, 202.7245, 0, 0, 1, 0, 100, 0, 65560),
(563687, 13, 1177.809, 4099.19, 202.0769, 0, 0, 1, 0, 100, 0, 65560),
(563687, 14, 1169.811, 4098.712, 199.5409, 0, 0, 1, 0, 100, 0, 65560);

DELETE FROM `creature_formations` WHERE `leaderGUID` = 563687;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(563687, 563687, 0, 0, 2, 0, 0),
(563687, 563683, 10, 0, 2, 0, 0);

-- Dai-Lo Farmer
DELETE FROM `creature` WHERE `guid` = 582639 AND `id` = 65473;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawntimesecs_max`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `movement_type`, `npcflag`, `npcflag2`, `unit_flags`, `unit_flags2`, `dynamicflags`, `ScriptName`, `walk_mode`) VALUES
(582639, 65473, 860, 5736, 5827, 1, 1, 0, 0, 667.6077, 3279.477, 74.97147, 2.781728, 600, 0, 0, 0, 274, 0, 2, 0, 0, 0, 0, 0, "", 0);

DELETE FROM `creature_equip_template` WHERE `entry` IN (65473, 56241);
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(65473, 1, 82351, 0, 0),
(65473, 2, 82352, 0, 0),

(56241, 1, 82351, 0, 0),
(56241, 2, 82352, 0, 0);

UPDATE `creature` SET `modelid` = 0 WHERE `id` IN (65473, 56241);
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0, `equipment_id` = -1 WHERE `guid` IN (562649, 562635, 562646);
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` IN (562679, 562588, 562568, 562599, 562611);
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (562570, 562682, 562613, 563629, 563657, 562571, 563636, 562627, 563624);
UPDATE `creature` SET `position_x` = 594.2813, `position_y` = 3014.282, `position_z` = 80.04757, `orientation` = 2.844887, `wander_distance` = 0, `movement_type` = 0, `equipment_id` = -1 WHERE `guid` = 562648;
UPDATE `creature` SET `id` = 56241, `position_x` = 603.4427, `position_y` = 3031.141, `position_z` = 80.02945, `orientation` = 3.438299, `wander_distance` = 0, `movement_type` = 0, `equipment_id` = -1 WHERE `guid` = 562647;
UPDATE `creature` SET `id` = 56241, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (562722, 563602, 562630, 562580, 562612, 563633, 563634);
UPDATE `creature` SET `id` = 56241, `wander_distance` = 0, `movement_type` = 0, `equipment_id` = -1 WHERE `guid` IN (562705, 562723);
UPDATE `creature` SET `id` = 56241, `position_x` = 604.842, `position_y` = 3112.358, `position_z` = 88.93097, `orientation` = 3.961897, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 563637;
UPDATE `creature` SET `id` = 56241, `position_x` = 606.1146, `position_y` = 3110.345, `position_z` = 88.80035, `orientation` = 3.263766, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 563635;
UPDATE `creature` SET `position_x` = 602.5358, `position_y` = 3109.837, `position_z` = 89.06949, `orientation` = 0.05235988, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 563627;
UPDATE `creature` SET `id` = 65473, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (563603, 562582, 562691);
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0, `equipment_id` = -1 WHERE `guid` IN (562694, 562652, 562581, 562584, 562629, 562677, 562614);
UPDATE `creature` SET `id` = 56241, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 563620;
UPDATE `creature` SET `position_x` = 563.0283, `position_y` = 3253.611, `position_z` = 72.07218, `orientation` = 4.881193, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562574;
UPDATE `creature` SET `id` = 65473, `wander_distance` = 0, `movement_type` = 0, `equipment_id` = -1 WHERE `guid` IN (562667, 562625, 562696, 562585, 562616);
UPDATE `creature` SET `id` = 65473, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562692;

DELETE FROM `creature_addon` WHERE `guid` IN (562649, 562635, 562570, 562679, 562588, 562568, 562599, 562646, 562648, 563657, 562571, 562647,
                                              562722, 562705, 562723, 562694, 562652, 562581, 562584, 563620, 562611, 562574, 563633, 563634,
                                              562667, 562625, 562629, 562677, 562696, 562585, 562616, 562614, 562692, 582639);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`, `emote`, `ai_anim_kit`) VALUES
(562649, 0, 0, 1, 425, 0),
(562635, 0, 0, 1, 425, 0),
(562570, 0, 1, 1, 0, 0),
(562679, 562679, 0, 1, 0, 0),
(562588, 562588, 0, 1, 0, 0),
(562568, 562568, 0, 1, 0, 0),
(562599, 562599, 0, 1, 0, 0),
(562646, 0, 0, 1, 425, 0),
(562648, 0, 0, 1, 425, 0),
(563657, 0, 1, 1, 0, 0),
(562571, 0, 1, 1, 0, 0),
(562647, 0, 0, 1, 425, 0),
(562722, 0, 1, 1, 0, 0),
(562705, 0, 0, 1, 425, 0),
(562723, 0, 0, 1, 425, 0),
(562694, 0, 0, 1, 425, 0),
(562652, 0, 0, 1, 425, 0),
(562581, 0, 0, 1, 425, 0),
(562584, 0, 0, 1, 425, 0),
(563620, 563620, 0, 1, 0, 0),
(562611, 562611, 0, 1, 0, 0),
(562574, 562574, 0, 1, 0, 0),
(563633, 0, 0, 1, 0, 1904),
(563634, 0, 0, 1, 0, 1904),
(562667, 0, 0, 1, 425, 0),
(562625, 0, 0, 1, 425, 0),
(562629, 0, 0, 1, 425, 0),
(562677, 0, 0, 1, 425, 0),
(562696, 0, 0, 1, 425, 0),
(562585, 0, 0, 1, 425, 0),
(562616, 0, 0, 1, 425, 0),
(562614, 0, 0, 1, 425, 0),
(562692, 562692, 0, 1, 0, 0),
(582639, 582639, 0, 1, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` IN (562679, 562588, 562568, 562599, 563620, 562611, 562574, 562692, 582639);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562679, 1, 731.9149, 2876.208, 75.91635, 0, 0, 0, 0, 100, 0, 65473),
(562679, 2, 733.6754, 2857.747, 76.87671, 0, 0, 0, 0, 100, 0, 65473),
(562679, 3, 723.7864, 2844.651, 79.83271, 0, 0, 0, 0, 100, 0, 65473),
(562679, 4, 717.7639, 2821.993, 84.28377, 0, 0, 0, 0, 100, 0, 65473),
(562679, 5, 717.9861, 2810.523, 86.28767, 0, 0, 0, 0, 100, 0, 65473),
(562679, 6, 717.7639, 2821.993, 84.28377, 0, 0, 0, 0, 100, 0, 65473),
(562679, 7, 723.7864, 2844.651, 79.83271, 0, 0, 0, 0, 100, 0, 65473),
(562679, 8, 733.6754, 2857.747, 76.87671, 0, 0, 0, 0, 100, 0, 65473),
(562679, 9, 731.9149, 2876.208, 75.91635, 0, 0, 0, 0, 100, 0, 65473),
(562679, 10, 734.5261, 2893.189, 76.58323, 0, 0, 0, 0, 100, 0, 65473),
(562679, 11, 736.4358, 2910.071, 74.45855, 0, 0, 0, 0, 100, 0, 65473),
(562679, 12, 733.2535, 2932.018, 76.23833, 0, 0, 0, 0, 100, 0, 65473),
(562679, 13, 719.6406, 2946.005, 75.88178, 0, 0, 0, 0, 100, 0, 65473),
(562679, 14, 711.1268, 2958.993, 76.98823, 0, 0, 0, 0, 100, 0, 65473),
(562679, 15, 701.9583, 2970.714, 76.45962, 0, 0, 0, 0, 100, 0, 65473),
(562679, 16, 689.5417, 2980.998, 74.38884, 0, 0, 0, 0, 100, 0, 65473),
(562679, 17, 701.9583, 2970.714, 76.45962, 0, 0, 0, 0, 100, 0, 65473),
(562679, 18, 711.1268, 2958.993, 76.98823, 0, 0, 0, 0, 100, 0, 65473),
(562679, 19, 719.6406, 2946.005, 75.88178, 0, 0, 0, 0, 100, 0, 65473),
(562679, 20, 732.8125, 2932.292, 76.20855, 0, 0, 0, 0, 100, 0, 65473),
(562679, 21, 736.4358, 2910.071, 74.45855, 0, 0, 0, 0, 100, 0, 65473),
(562679, 22, 734.5261, 2893.189, 76.58323, 0, 0, 0, 0, 100, 0, 65473),

(562588, 1, 653.6371, 3013.091, 74.46384, 0, 0, 0, 0, 100, 0, 56241),
(562588, 2, 642.0035, 3020.547, 76.32822, 0, 0, 0, 0, 100, 0, 56241),
(562588, 3, 627.9271, 3030.978, 76.12308, 0, 0, 0, 0, 100, 0, 56241),
(562588, 4, 622.9305, 3045.205, 78.56755, 0, 0, 0, 0, 100, 0, 56241),
(562588, 5, 622.4727, 3063.205, 81.20549, 0, 0, 0, 0, 100, 0, 56241),
(562588, 6, 622.9297, 3045.205, 78.58049, 0, 0, 0, 0, 100, 0, 56241),
(562588, 7, 627.9271, 3030.978, 76.12308, 0, 0, 0, 0, 100, 0, 56241),
(562588, 8, 642.0035, 3020.547, 76.32822, 0, 0, 0, 0, 100, 0, 56241),

(562568, 1, 688.2708, 3331.74, 82.82485, 0, 0, 0, 0, 100, 0, 65473),
(562568, 2, 670.4011, 3334.08, 83.80865, 0, 0, 0, 0, 100, 0, 65473),
(562568, 3, 653.507, 3334.294, 83.32875, 0, 0, 0, 0, 100, 0, 65473),
(562568, 4, 638.875, 3333.825, 83.11488, 0, 0, 0, 0, 100, 0, 65473),
(562568, 5, 623.5469, 3333.338, 82.94126, 0, 0, 0, 0, 100, 0, 65473),
(562568, 6, 638.875, 3333.825, 83.11488, 0, 0, 0, 0, 100, 0, 65473),
(562568, 7, 653.507, 3334.294, 83.32875, 0, 0, 0, 0, 100, 0, 65473),
(562568, 8, 670.4011, 3334.08, 83.80865, 0, 0, 0, 0, 100, 0, 65473),
(562568, 9, 688.2708, 3331.74, 82.82485, 0, 0, 0, 0, 100, 0, 65473),
(562568, 10, 702.8455, 3320.042, 83.67236, 0, 0, 0, 0, 100, 0, 65473),
(562568, 11, 712.0504, 3308.684, 82.83349, 0, 0, 0, 0, 100, 0, 65473),
(562568, 12, 717.618, 3298.913, 83.44096, 0, 0, 0, 0, 100, 0, 65473),
(562568, 13, 727.9792, 3283.182, 83.3538, 0, 0, 0, 0, 100, 0, 65473),
(562568, 14, 717.618, 3298.913, 83.44096, 0, 0, 0, 0, 100, 0, 65473),
(562568, 15, 712.0504, 3308.684, 82.83349, 0, 0, 0, 0, 100, 0, 65473),
(562568, 16, 702.8455, 3320.042, 83.67236, 0, 0, 0, 0, 100, 0, 65473),

(562599, 1, 633.4913, 3219.733, 73.62489, 0.009695, 6000, 0, 0, 100, 0, 65473),
(562599, 2, 637.0035, 3228.357, 73.52113, 5.399536, 6000, 0, 0, 100, 0, 65473),
(562599, 3, 643.9375, 3232.019, 73.44325, 0, 0, 0, 0, 100, 0, 65473),
(562599, 4, 651.7726, 3229.538, 73.20778, 5.23039, 6000, 0, 0, 100, 0, 65473),
(562599, 5, 665.4566, 3223.562, 73.62318, 4.408109, 6000, 0, 0, 100, 0, 65473),
(562599, 6, 676.4636, 3222.035, 73.60612, 4.095041, 6000, 0, 0, 100, 0, 65473),
(562599, 7, 684.6528, 3215.806, 73.81145, 4.10258, 6000, 0, 0, 100, 0, 65473),
(562599, 8, 676.4636, 3222.035, 73.60612, 0, 0, 0, 0, 100, 0, 65473),
(562599, 9, 665.4566, 3223.562, 73.62318, 4.476159, 6000, 0, 0, 100, 0, 65473),
(562599, 10, 651.7726, 3229.538, 73.20778, 3.708533, 6000, 0, 0, 100, 0, 65473),
(562599, 11, 643.9375, 3232.019, 73.44325, 0, 0, 0, 0, 100, 0, 65473),
(562599, 12, 637.0035, 3228.357, 73.52113, 0, 0, 0, 0, 100, 0, 65473),

(563620, 1, 664.6371, 3180.71, 88.85957, 1.686017, 4000, 0, 0, 100, 0, 56241),
(563620, 2, 665.2083, 3185.997, 88.92049, 0, 0, 0, 0, 100, 0, 56241),
(563620, 3, 670.6493, 3185.821, 88.94962, 3.94901, 5000, 0, 0, 100, 0, 56241),
(563620, 4, 665.2083, 3185.997, 88.92049, 0, 0, 0, 0, 100, 0, 56241),
(563620, 5, 664.6371, 3180.71, 88.85957, 0, 0, 0, 0, 100, 0, 56241),
(563620, 6, 659.3785, 3176.658, 88.66341, 2.252547, 4000, 0, 0, 100, 0, 56241),
(563620, 7, 654.4028, 3177.364, 88.78841, 0, 0, 0, 0, 100, 0, 56241),
(563620, 8, 655.566, 3183.093, 88.48518, 0.2490902, 5000, 0, 0, 100, 0, 56241),
(563620, 9, 659.2952, 3187.774, 88.94295, 0, 0, 0, 0, 100, 0, 56241),
(563620, 10, 665.0972, 3185.281, 88.83455, 1.484407, 4000, 0, 0, 100, 0, 56241),
(563620, 11, 665.408, 3180.6, 88.91341, 0, 0, 0, 0, 100, 0, 56241),
(563620, 12, 661.066, 3180.368, 88.78841, 0, 0, 0, 0, 100, 0, 56241),
(563620, 13, 656.8941, 3181.771, 88.78841, 1.055669, 5000, 0, 0, 100, 0, 56241),
(563620, 14, 656.2743, 3184.964, 88.79659, 0, 0, 0, 0, 100, 0, 56241),
(563620, 15, 660.1563, 3189.143, 88.77864, 0, 0, 0, 0, 100, 0, 56241),
(563620, 16, 663.8055, 3190.796, 88.78841, 2.695387, 4000, 0, 0, 100, 0, 56241),
(563620, 17, 656.2743, 3184.964, 88.79659, 5.848103, 5000, 0, 0, 100, 0, 56241),
(563620, 18, 656.8941, 3181.771, 88.78841, 0, 0, 0, 0, 100, 0, 56241),
(563620, 19, 661.066, 3180.368, 88.78841, 3.359177, 4000, 0, 0, 100, 0, 56241),
(563620, 20, 665.408, 3180.6, 88.91341, 0, 0, 0, 0, 100, 0, 56241),
(563620, 21, 665.0972, 3185.281, 88.83455, 2.217199, 5000, 0, 0, 100, 0, 56241),
(563620, 22, 659.2952, 3187.774, 88.94295, 0, 0, 0, 0, 100, 0, 56241),
(563620, 23, 655.566, 3183.093, 88.48518, 3.137688, 4000, 0, 0, 100, 0, 56241),
(563620, 24, 654.4028, 3177.364, 88.78841, 0, 0, 0, 0, 100, 0, 56241),
(563620, 25, 659.3785, 3176.658, 88.66341, 0, 0, 0, 0, 100, 0, 56241),

(562611, 1, 554.8906, 3205.137, 75.73812, 0, 0, 0, 0, 100, 0, 56241),
(562611, 2, 545.967, 3217.532, 76.31661, 0, 0, 0, 0, 100, 0, 56241),
(562611, 3, 528.8768, 3230.528, 74.9197, 0, 0, 0, 0, 100, 0, 56241),
(562611, 4, 521.6858, 3239.978, 76.71917, 0, 0, 0, 0, 100, 0, 56241),
(562611, 5, 519.7361, 3254.197, 78.27581, 0, 0, 0, 0, 100, 0, 56241),
(562611, 6, 520.1667, 3274.041, 76.94918, 0, 0, 0, 0, 100, 0, 56241),
(562611, 7, 523.217, 3287.648, 75.73617, 0, 0, 0, 0, 100, 0, 56241),
(562611, 8, 525.1667, 3305.447, 74.24305, 0, 0, 0, 0, 100, 0, 56241),
(562611, 9, 523.217, 3287.648, 75.73617, 0, 0, 0, 0, 100, 0, 56241),
(562611, 10, 520.1667, 3274.041, 76.94918, 0, 0, 0, 0, 100, 0, 56241),
(562611, 11, 519.7361, 3254.197, 78.27581, 0, 0, 0, 0, 100, 0, 56241),
(562611, 12, 521.6858, 3239.978, 76.71917, 0, 0, 0, 0, 100, 0, 56241),
(562611, 13, 528.8768, 3230.528, 74.9197, 0, 0, 0, 0, 100, 0, 56241),
(562611, 14, 545.967, 3217.532, 76.31661, 0, 0, 0, 0, 100, 0, 56241),
(562611, 15, 554.9063, 3205.352, 75.68563, 0, 0, 0, 0, 100, 0, 56241),
(562611, 16, 553.8507, 3191.178, 76.97068, 0, 0, 0, 0, 100, 0, 56241),
(562611, 17, 555.1649, 3180.038, 76.92857, 0, 0, 0, 0, 100, 0, 56241),
(562611, 18, 553.8507, 3191.178, 76.97068, 0, 0, 0, 0, 100, 0, 56241),

(562574, 1, 564.4202, 3245.445, 71.22196, 0, 0, 0, 0, 100, 0, 56241),
(562574, 2, 562.8577, 3254.613, 72.05033, 0, 0, 0, 0, 100, 0, 56241),
(562574, 3, 565.1528, 3265.788, 71.96818, 0, 0, 0, 0, 100, 0, 56241),
(562574, 4, 575.4861, 3272.353, 71.72819, 0, 0, 0, 0, 100, 0, 56241),
(562574, 5, 586.4705, 3268.001, 70.91251, 4.239508, 6000, 0, 0, 100, 0, 56241),
(562574, 6, 597.7621, 3258.443, 70.7143, 4.596083, 6000, 0, 0, 100, 0, 56241),
(562574, 7, 610.1702, 3251.502, 70.61047, 3.673268, 6000, 0, 0, 100, 0, 56241),
(562574, 8, 621.6979, 3247.539, 70.61926, 4.133361, 6000, 0, 0, 100, 0, 56241),
(562574, 9, 629.5677, 3241.524, 71.00475, 3.800597, 6000, 0, 0, 100, 0, 56241),
(562574, 10, 631.8351, 3234.189, 71.53551, 0, 0, 0, 0, 100, 0, 56241),
(562574, 11, 625.4358, 3224.241, 72.75375, 2.009007, 6000, 0, 0, 100, 0, 56241),
(562574, 12, 631.8351, 3234.189, 71.53551, 2.322014, 6000, 0, 0, 100, 0, 56241),
(562574, 13, 629.5677, 3241.524, 71.00475, 0, 0, 0, 0, 100, 0, 56241),
(562574, 14, 621.6979, 3247.539, 70.61926, 4.240922, 6000, 0, 0, 100, 0, 56241),
(562574, 15, 610.1702, 3251.502, 70.61047, 4.486835, 6000, 0, 0, 100, 0, 56241),
(562574, 16, 597.7621, 3258.443, 70.7143, 4.591609, 6000, 0, 0, 100, 0, 56241),
(562574, 17, 586.4705, 3268.001, 70.91251, 4.218854, 6000, 0, 0, 100, 0, 56241),
(562574, 18, 575.4861, 3272.353, 71.72819, 0, 0, 0, 0, 100, 0, 56241),
(562574, 19, 565.1528, 3265.788, 71.96818, 0, 0, 0, 0, 100, 0, 56241),
(562574, 20, 562.8577, 3254.613, 72.05033, 0, 0, 0, 0, 100, 0, 56241),

(562692, 1, 348.6597, 3204.003, 75.79278, 0, 0, 0, 0, 100, 0, 65473),
(562692, 2, 363.2604, 3206.627, 75.65826, 0, 0, 0, 0, 100, 0, 65473),
(562692, 3, 376.6267, 3209, 75.7812, 0, 0, 0, 0, 100, 0, 65473),
(562692, 4, 389.7326, 3209.544, 75.61396, 0, 0, 0, 0, 100, 0, 65473),
(562692, 5, 404.4566, 3207.759, 75.54282, 0, 0, 0, 0, 100, 0, 65473),
(562692, 6, 389.7326, 3209.544, 75.61396, 0, 0, 0, 0, 100, 0, 65473),
(562692, 7, 376.6267, 3209, 75.7812, 0, 0, 0, 0, 100, 0, 65473),
(562692, 8, 363.2604, 3206.627, 75.65826, 0, 0, 0, 0, 100, 0, 65473),
(562692, 9, 348.6597, 3204.003, 75.79278, 0, 0, 0, 0, 100, 0, 65473),
(562692, 10, 333.224, 3203.298, 75.64104, 0, 0, 0, 0, 100, 0, 65473),
(562692, 11, 318.651, 3200.352, 75.64104, 0, 0, 0, 0, 100, 0, 65473),
(562692, 12, 306.6738, 3200.902, 78.39104, 0, 0, 0, 0, 100, 0, 65473),
(562692, 13, 296.2135, 3210.329, 87.71879, 0, 0, 0, 0, 100, 0, 65473),
(562692, 14, 285.3576, 3222.429, 88.02482, 0, 0, 0, 0, 100, 0, 65473),
(562692, 15, 296.2135, 3210.329, 87.71879, 0, 0, 0, 0, 100, 0, 65473),
(562692, 16, 306.4653, 3200.906, 78.75982, 0, 0, 0, 0, 100, 0, 65473),
(562692, 17, 318.651, 3200.352, 75.64104, 0, 0, 0, 0, 100, 0, 65473),
(562692, 18, 333.224, 3203.298, 75.64104, 0, 0, 0, 0, 100, 0, 65473),

(582639, 1, 658.882, 3282.76, 74.94882, 0.9163052, 6000, 0, 0, 100, 0, 65473),
(582639, 2, 640.7344, 3288.796, 75.43369, 0, 0, 0, 0, 100, 0, 65473),
(582639, 3, 624.3386, 3296.394, 75.56493, 0, 0, 0, 0, 100, 0, 65473),
(582639, 4, 614.4913, 3303.629, 75.32628, 0, 0, 0, 0, 100, 0, 65473),
(582639, 5, 601.2518, 3315.688, 75.50926, 1.07544, 6000, 0, 0, 100, 0, 65473),
(582639, 6, 614.4913, 3303.629, 75.32628, 0.9221497, 6000, 0, 0, 100, 0, 65473),
(582639, 7, 624.3386, 3296.394, 75.56493, 0, 0, 0, 0, 100, 0, 65473),
(582639, 8, 640.7344, 3288.796, 75.43369, 0, 0, 0, 0, 100, 0, 65473),
(582639, 9, 658.882, 3282.76, 74.94882, 0, 0, 0, 0, 100, 0, 65473),
(582639, 10, 678.9653, 3275.203, 74.72111, 0.9806032, 6000, 0, 0, 100, 0, 65473),
(582639, 11, 694.0573, 3269.936, 74.96232, 1.158776, 6000, 0, 0, 100, 0, 65473),
(582639, 12, 711.9896, 3264.898, 75.03799, 1.544937, 6000, 0, 0, 100, 0, 65473),
(582639, 13, 694.0573, 3269.936, 74.96232, 1.55273, 6000, 0, 0, 100, 0, 65473),
(582639, 14, 678.9653, 3275.203, 74.72111, 0, 0, 0, 0, 100, 0, 65473);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (562679, 562588, 562611, 562692);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(562679, 562679, 0, 0, 2, 0, 0),
(562679, 562682, 3, 270, 2, 5, 16),

(562588, 562588, 0, 0, 2, 0, 0),
(562588, 562613, 3, 90, 2, 1, 5),

(562611, 562611, 0, 0, 2, 0, 0),
(562611, 562612, 3, 270, 2, 8, 17),

(562692, 562692, 0, 0, 2, 0, 0),
(562692, 562691, 3, 90, 2, 5, 14);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-563629, -563637, -563636, -563635, -563627, -563603, -563602, -562627, -562630, -562580, -562582) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-563629, 0, 0, 0, 1, 0, 100, 0, 0, 0, 1000, 12000, 10, 1, 6, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - Update OOC - Play Random Emote (1, 6, 273, 273)"),
(-563629, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 12000, 20000, 11, 128435, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Palm Strike"),
(-563629, 0, 2, 0, 0, 0, 100, 0, 8000, 10000, 20000, 25000, 11, 128436, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Round Kick"),

(-563637, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 1000, 12000, 10, 1, 6, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - Update OOC - Play Random Emote (1, 6, 273, 273)"),
(-563637, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 12000, 20000, 11, 128435, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Palm Strike"),
(-563637, 0, 2, 0, 0, 0, 100, 0, 8000, 10000, 20000, 25000, 11, 128436, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Round Kick"),

(-563636, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 1000, 12000, 10, 1, 6, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - Update OOC - Play Random Emote (1, 6, 273, 273)"),
(-563636, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 12000, 20000, 11, 128435, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Palm Strike"),
(-563636, 0, 2, 0, 0, 0, 100, 0, 8000, 10000, 20000, 25000, 11, 128436, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Round Kick"),

(-563635, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 1000, 12000, 10, 1, 6, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - Update OOC - Play Random Emote (1, 6, 273, 273)"),
(-563635, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 12000, 20000, 11, 128435, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Palm Strike"),
(-563635, 0, 2, 0, 0, 0, 100, 0, 8000, 10000, 20000, 25000, 11, 128436, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Round Kick"),

(-563627, 0, 0, 0, 1, 0, 100, 0, 0, 0, 1000, 12000, 10, 1, 6, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - Update OOC - Play Random Emote (1, 6, 273, 273)"),
(-563627, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 12000, 20000, 11, 128435, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Palm Strike"),
(-563627, 0, 2, 0, 0, 0, 100, 0, 8000, 10000, 20000, 25000, 11, 128436, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Round Kick"),

(-563603, 0, 0, 0, 1, 0, 100, 0, 0, 0, 1000, 12000, 10, 1, 6, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - Update OOC - Play Random Emote (1, 6, 273, 273)"),
(-563603, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 12000, 20000, 11, 128435, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Palm Strike"),
(-563603, 0, 2, 0, 0, 0, 100, 0, 8000, 10000, 20000, 25000, 11, 128436, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Round Kick"),

(-563602, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 1000, 12000, 10, 1, 6, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - Update OOC - Play Random Emote (1, 6, 273, 273)"),
(-563602, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 12000, 20000, 11, 128435, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Palm Strike"),
(-563602, 0, 2, 0, 0, 0, 100, 0, 8000, 10000, 20000, 25000, 11, 128436, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Round Kick"),

(-562627, 0, 0, 0, 1, 0, 100, 0, 0, 0, 1000, 12000, 10, 1, 6, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - Update OOC - Play Random Emote (1, 6, 273, 273)"),
(-562627, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 12000, 20000, 11, 128435, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Palm Strike"),
(-562627, 0, 2, 0, 0, 0, 100, 0, 8000, 10000, 20000, 25000, 11, 128436, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Round Kick"),

(-562630, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 1000, 12000, 10, 1, 6, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - Update OOC - Play Random Emote (1, 6, 273, 273)"),
(-562630, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 12000, 20000, 11, 128435, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Palm Strike"),
(-562630, 0, 2, 0, 0, 0, 100, 0, 8000, 10000, 20000, 25000, 11, 128436, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Round Kick"),

(-562580, 0, 0, 0, 1, 0, 100, 0, 0, 0, 1000, 12000, 10, 1, 6, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - Update OOC - Play Random Emote (1, 6, 273, 273)"),
(-562580, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 12000, 20000, 11, 128435, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Palm Strike"),
(-562580, 0, 2, 0, 0, 0, 100, 0, 8000, 10000, 20000, 25000, 11, 128436, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Round Kick"),

(-562582, 0, 0, 0, 1, 0, 100, 0, 2000, 5000, 1000, 12000, 10, 1, 6, 273, 274, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - Update OOC - Play Random Emote (1, 6, 273, 273)"),
(-562582, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 12000, 20000, 11, 128435, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Palm Strike"),
(-562582, 0, 2, 0, 0, 0, 100, 0, 8000, 10000, 20000, 25000, 11, 128436, 1, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, "Dai-Lo Farmer - On Combat - Cast Round Kick");

-- Lamplighter Sunny
UPDATE `creature` SET `position_x` = 613.9249, `position_y` = 3098.377, `position_z` = 86.7071, `orientation` = 4.262364, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562598 AND `id` = 64939;

DELETE FROM `creature_template_addon` WHERE `entry` = 64939;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(64939, 562598, 0, 0, 1, 0, "126986");

DELETE FROM `waypoint_data` WHERE `id` = 562598;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562598, 1, 612.9818, 3096.648, 86.61667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 2, 612.4818, 3088.148, 85.36667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 3, 610.9818, 3079.898, 84.11667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 4, 611.2318, 3067.148, 81.61667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 5, 611.4818, 3050.648, 78.11667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 6, 612.7318, 3041.148, 76.86667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 7, 619.2318, 3025.398, 75.86667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 8, 624.7101, 3015.89, 75.1487, 0, 7000, 0, 0, 100, 0, 64939),
(562598, 9, 622.4419, 3021.025, 75.54419, 0, 0, 0, 0, 100, 0, 64939),
(562598, 10, 617.6919, 3028.025, 76.04419, 0, 0, 0, 0, 100, 0, 64939),
(562598, 11, 613.9419, 3037.025, 76.79419, 0, 0, 0, 0, 100, 0, 64939),
(562598, 12, 611.6919, 3045.275, 77.54419, 0, 0, 0, 0, 100, 0, 64939),
(562598, 13, 611.4419, 3053.525, 79.04419, 0, 0, 0, 0, 100, 0, 64939),
(562598, 14, 611.6919, 3062.275, 80.54419, 0, 0, 0, 0, 100, 0, 64939),
(562598, 15, 611.9419, 3071.025, 82.29419, 0, 0, 0, 0, 100, 0, 64939),
(562598, 16, 614.6919, 3080.275, 84.04419, 0, 0, 0, 0, 100, 0, 64939),
(562598, 17, 620.6736, 3085.16, 85.93968, 0, 7000, 0, 0, 100, 0, 64939),
(562598, 18, 619.2544, 3091.475, 86.64915, 0, 0, 0, 0, 100, 0, 64939),
(562598, 19, 618.0044, 3101.975, 87.14915, 0, 0, 0, 0, 100, 0, 64939),
(562598, 20, 616.5044, 3112.475, 87.64915, 0, 0, 0, 0, 100, 0, 64939),
(562598, 21, 615.0044, 3123.225, 87.89915, 0, 0, 0, 0, 100, 0, 64939),
(562598, 22, 617.0044, 3137.725, 87.89915, 0, 0, 0, 0, 100, 0, 64939),
(562598, 23, 618.3351, 3147.791, 87.85862, 0, 7000, 0, 0, 100, 0, 64939),
(562598, 24, 611.1537, 3148.099, 88.10101, 0, 0, 0, 0, 100, 0, 64939),
(562598, 25, 601.9037, 3149.349, 87.85101, 0, 0, 0, 0, 100, 0, 64939),
(562598, 26, 597.1537, 3148.849, 87.85101, 0, 0, 0, 0, 100, 0, 64939),
(562598, 27, 592.4722, 3143.408, 87.8434, 0, 7000, 0, 0, 100, 0, 64939),
(562598, 28, 587.6754, 3146.72, 88.03531, 0, 0, 0, 0, 100, 0, 64939),
(562598, 29, 580.9254, 3146.47, 87.78531, 0, 0, 0, 0, 100, 0, 64939),
(562598, 30, 572.1754, 3147.72, 86.53531, 0, 0, 0, 0, 100, 0, 64939),
(562598, 31, 564.1754, 3150.47, 83.03531, 0, 0, 0, 0, 100, 0, 64939),
(562598, 32, 555.9254, 3155.72, 78.78531, 0, 0, 0, 0, 100, 0, 64939),
(562598, 33, 549.1754, 3161.97, 77.53531, 0, 0, 0, 0, 100, 0, 64939),
(562598, 34, 545.6754, 3169.72, 77.28531, 0, 0, 0, 0, 100, 0, 64939),
(562598, 35, 544.4254, 3177.97, 77.28531, 0, 0, 0, 0, 100, 0, 64939),
(562598, 36, 543.1754, 3186.72, 77.28531, 0, 0, 0, 0, 100, 0, 64939),
(562598, 37, 542.4254, 3194.22, 77.53531, 0, 0, 0, 0, 100, 0, 64939),
(562598, 38, 539.6754, 3202.47, 77.03531, 0, 0, 0, 0, 100, 0, 64939),
(562598, 39, 535.8785, 3207.532, 76.22721, 0, 7000, 0, 0, 100, 0, 64939),
(562598, 40, 522.1597, 3220.362, 74.46206, 0, 0, 0, 0, 100, 0, 64939),
(562598, 41, 514.9149, 3231.209, 74.09304, 0, 0, 0, 0, 100, 0, 64939),
(562598, 42, 512.8489, 3240.094, 75.08343, 0, 0, 0, 0, 100, 0, 64939),
(562598, 43, 511.0156, 3248.966, 76.84576, 0, 0, 0, 0, 100, 0, 64939),
(562598, 44, 511.7535, 3261.906, 77.58465, 2.984513, 12000, 0, 0, 100, 0, 64939),
(562598, 45, 508.4818, 3259.148, 77.61667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 46, 505.2318, 3251.148, 77.36667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 47, 504.9818, 3244.648, 76.36667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 48, 507.2318, 3236.648, 75.11667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 49, 511.2318, 3228.648, 74.36667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 50, 518.4818, 3220.398, 74.61667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 51, 528.9818, 3213.648, 75.86667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 52, 536.2318, 3209.398, 76.36667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 53, 540.4818, 3201.398, 76.86667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 54, 543.7318, 3190.148, 77.11667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 55, 544.7318, 3177.398, 77.11667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 56, 547.9818, 3165.398, 77.11667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 57, 554.2318, 3157.148, 77.86667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 58, 561.4818, 3152.648, 81.11667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 59, 567.2318, 3149.398, 84.36667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 60, 574.7318, 3147.148, 87.36667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 61, 583.9818, 3145.648, 87.86667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 62, 593.2318, 3144.398, 87.86667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 63, 599.9818, 3142.898, 88.11667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 64, 606.4818, 3141.398, 87.86667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 65, 615.2318, 3137.398, 87.86667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 66, 619.9818, 3130.398, 87.86667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 67, 621.4818, 3123.398, 87.86667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 68, 619.7318, 3112.398, 87.86667, 0, 0, 0, 0, 100, 0, 64939),
(562598, 69, 616.9818, 3104.648, 87.36667, 0, 0, 0, 0, 100, 0, 64939);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 64939;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 64939 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 64939*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(64939, 0, 0, 0, 34, 0, 100, 0, 2, 7, 0, 0, 80, 64939*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Sunny - MI 7 - Start Script"),
(64939, 0, 1, 0, 34, 0, 100, 0, 2, 16, 0, 0, 80, 64939*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Sunny - MI 16 - Start Script"),
(64939, 0, 2, 0, 34, 0, 100, 0, 2, 22, 0, 0, 80, 64939*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Sunny - MI 22 - Start Script"),
(64939, 0, 3, 0, 34, 0, 100, 0, 2, 26, 0, 0, 80, 64939*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Sunny - MI 26 - Start Script"),
(64939, 0, 4, 0, 34, 0, 100, 0, 2, 38, 0, 0, 80, 64939*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Sunny - MI 38 - Start Script"),

(64939*100, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 128, 3143, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lamplighter Sunny - On Script - Play Anim Kit");

-- Field Yak
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562713;

DELETE FROM `creature_addon` WHERE `guid` = 562713;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(562713, 562713, 1);

DELETE FROM `waypoint_data` WHERE `id` = 562713;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562713, 1, 493.6406, 3130.748, 75.6916, 0, 0, 0, 0, 100, 0, 57258),
(562713, 2, 502.0417, 3139.999, 75.57745, 0, 0, 0, 0, 100, 0, 57258),
(562713, 3, 512.2448, 3146.775, 75.57745, 0, 1000, 0, 0, 100, 0, 57258),
(562713, 4, 502.0417, 3139.999, 75.57745, 0, 0, 0, 0, 100, 0, 57258),
(562713, 5, 493.6406, 3130.748, 75.6916, 0, 0, 0, 0, 100, 0, 57258),
(562713, 6, 486.6215, 3122.684, 75.6916, 0, 0, 0, 0, 100, 0, 57258),
(562713, 7, 483.4653, 3109.196, 75.6916, 0, 0, 0, 0, 100, 0, 57258),
(562713, 8, 480.441, 3098.122, 75.5666, 0, 0, 0, 0, 100, 0, 57258),
(562713, 9, 475.9271, 3090.249, 75.5666, 0, 0, 0, 0, 100, 0, 57258),
(562713, 10, 476.2326, 3079.183, 75.5666, 0, 0, 0, 0, 100, 0, 57258),
(562713, 11, 477.9288, 3068.703, 75.6916, 0, 1000, 0, 0, 100, 0, 57258),
(562713, 12, 476.2326, 3079.183, 75.5666, 0, 0, 0, 0, 100, 0, 57258),
(562713, 13, 475.9271, 3090.249, 75.5666, 0, 0, 0, 0, 100, 0, 57258),
(562713, 14, 480.441, 3098.122, 75.5666, 0, 0, 0, 0, 100, 0, 57258),
(562713, 15, 483.4653, 3109.196, 75.6916, 0, 0, 0, 0, 100, 0, 57258),
(562713, 16, 486.6215, 3122.684, 75.6916, 0, 0, 0, 0, 100, 0, 57258);

-- Plump Virmen
UPDATE `creature` SET `spawntimesecs` = 120 WHERE `id` = 55483;
UPDATE `creature` SET `position_x` = 410.6007, `position_y` = 3280.669, `position_z` = 73.51308, `orientation` = 4.258604, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 563648;
UPDATE `creature` SET `position_x` = 367.1932, `position_y` = 3327.363, `position_z` = 71.80902, `orientation` = 1.213338, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 563644;
UPDATE `creature` SET `position_x` = 323.066, `position_y` = 3286.309, `position_z` = 73.87307, `orientation` = 4.769159, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562695;
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` IN (562595, 562703, 562701, 562702, 562673, 562608, 562577, 562592, 562640, 563645, 562605, 562727, 562586, 562618,
                                                                                  562724, 562674, 562661, 562663, 562730, 563646, 563647, 563630, 562655);

DELETE FROM `creature_addon` WHERE `guid` IN (562595, 562703, 562701, 562702, 563648, 562673, 562608, 562577, 562592, 562640, 563645, 562605, 562727, 562586, 562618,
                                              562724, 562674, 562661, 562663, 562730, 563646, 563647, 563630, 562655, 563644, 562695);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(562595, 562595, 1),
(562703, 562703, 1),
(562701, 562701, 1),
(562702, 562702, 1),
(563648, 563648, 1),
(562673, 562673, 1),
(562608, 562608, 1),
(562577, 562577, 1),
(562592, 562592, 1),
(562640, 562640, 1),
(563645, 563645, 1),
(562605, 562605, 1),
(562727, 562727, 1),
(562586, 562586, 1),
(562618, 562618, 1),
(562724, 562724, 1),
(562674, 562674, 1),
(562661, 562661, 1),
(562663, 562663, 1),
(562730, 562730, 1),
(563646, 563646, 1),
(563647, 563647, 1),
(563630, 563630, 1),
(562655, 562655, 1),
(563644, 563644, 1),
(562695, 562695, 1);

DELETE FROM `waypoint_data` WHERE `id` IN (562595, 562703, 562701, 562702, 563648, 562673, 562608, 562577, 562592, 562640, 563645, 562605, 562727, 562586, 562618,
                                           562724, 562674, 562661, 562663, 562730, 563646, 563647, 563630, 562655, 563644, 562695);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562595, 1, 500.9167, 3112.524, 79.83317, 0, 0, 0, 0, 100, 0, 55483),
(562595, 2, 506.3889, 3122.113, 79.83317, 0, 0, 0, 0, 100, 0, 55483),
(562595, 3, 515.125, 3132.822, 79.95817, 0, 1000, 0, 0, 100, 0, 55483),
(562595, 4, 506.3889, 3122.113, 79.83317, 0, 0, 0, 0, 100, 0, 55483),
(562595, 5, 500.9167, 3112.524, 79.83317, 0, 0, 0, 0, 100, 0, 55483),
(562595, 6, 498.7865, 3098.034, 79.9416, 0, 0, 0, 0, 100, 0, 55483),
(562595, 7, 494.0226, 3085.781, 80.0666, 0, 0, 0, 0, 100, 0, 55483),
(562595, 8, 493.2778, 3077.617, 80.1916, 0, 1000, 0, 0, 100, 0, 55483),
(562595, 9, 494.0226, 3085.781, 80.0666, 0, 0, 0, 0, 100, 0, 55483),
(562595, 10, 498.7865, 3098.034, 79.9416, 0, 0, 0, 0, 100, 0, 55483),

(562703, 1, 473.059, 3106.315, 75.27119, 0, 0, 0, 0, 100, 0, 55483),
(562703, 2, 464.809, 3107.2, 75.09504, 0, 0, 0, 0, 100, 0, 55483),
(562703, 3, 459.974, 3107.348, 75.11286, 0, 0, 0, 0, 100, 0, 55483),
(562703, 4, 457.9115, 3100.873, 75.03168, 0, 0, 0, 0, 100, 0, 55483),
(562703, 5, 458.559, 3093.456, 74.91865, 0, 0, 0, 0, 100, 0, 55483),
(562703, 6, 464.6945, 3092.472, 74.9604, 0, 0, 0, 0, 100, 0, 55483),
(562703, 7, 469.191, 3094.324, 75.18208, 0, 0, 0, 0, 100, 0, 55483),
(562703, 8, 473.6042, 3101.397, 75.3166, 0, 0, 0, 0, 100, 0, 55483),

(562701, 1, 449.6979, 3174.228, 75.67666, 0, 0, 0, 0, 100, 0, 55483),
(562701, 2, 448.0174, 3175.792, 75.80166, 0, 0, 0, 0, 100, 0, 55483),
(562701, 3, 444.566, 3173.079, 75.67666, 0, 0, 0, 0, 100, 0, 55483),
(562701, 4, 442.1945, 3169.615, 75.67666, 0, 0, 0, 0, 100, 0, 55483),
(562701, 5, 442.092, 3163.523, 75.58191, 0, 0, 0, 0, 100, 0, 55483),
(562701, 6, 444.1615, 3158.99, 75.58191, 0, 0, 0, 0, 100, 0, 55483),
(562701, 7, 447.4948, 3158.328, 75.52002, 0, 0, 0, 0, 100, 0, 55483),
(562701, 8, 447.0243, 3164.887, 75.58191, 0, 0, 0, 0, 100, 0, 55483),
(562701, 9, 447.9896, 3169.04, 75.67666, 0, 0, 0, 0, 100, 0, 55483),

(562702, 1, 440.526, 3094.747, 77.47565, 0, 0, 0, 0, 100, 0, 55483),
(562702, 2, 429.6979, 3096.997, 77.18699, 0, 0, 0, 0, 100, 0, 55483),
(562702, 3, 429.8333, 3103.462, 77.27752, 0, 0, 0, 0, 100, 0, 55483),
(562702, 4, 435.4601, 3108.276, 77.30585, 0, 0, 0, 0, 100, 0, 55483),
(562702, 5, 444.3871, 3107.135, 77.40473, 0, 0, 0, 0, 100, 0, 55483),
(562702, 6, 447.0469, 3103.543, 77.09785, 0, 0, 0, 0, 100, 0, 55483),
(562702, 7, 445.4965, 3095.542, 77.14668, 0, 0, 0, 0, 100, 0, 55483),

(563648, 1, 387.5642, 3281.917, 73.29337, 0, 0, 1, 0, 100, 0, 55483),
(563648, 2, 380.882, 3286.484, 73.22781, 0.9424778, 4000, 1, 0, 100, 0, 55483),
(563648, 3, 385.4844, 3268.638, 74.68997, 0, 0, 1, 0, 100, 0, 55483),
(563648, 4, 389.3073, 3263.391, 75.29433, 5.846853, 4000, 1, 0, 100, 0, 55483),
(563648, 5, 396.3368, 3282.665, 73.18607, 0, 0, 1, 0, 100, 0, 55483),
(563648, 6, 405.2986, 3284.184, 73.29616, 0, 0, 1, 0, 100, 0, 55483),
(563648, 7, 410.6007, 3280.669, 73.51308, 4.258604, 4000, 1, 0, 100, 0, 55483),

(562673, 1, 388.8125, 3157.27, 70.95338, 0, 0, 0, 0, 100, 0, 55483),
(562673, 2, 384.9132, 3162.079, 70.594, 0, 0, 0, 0, 100, 0, 55483),
(562673, 3, 377.9722, 3163.26, 70.37366, 0, 0, 0, 0, 100, 0, 55483),
(562673, 4, 373.3715, 3157.539, 70.35023, 0, 0, 0, 0, 100, 0, 55483),
(562673, 5, 372.651, 3150.938, 70.1692, 0, 0, 0, 0, 100, 0, 55483),
(562673, 6, 374.4392, 3143.266, 70.10303, 0, 0, 0, 0, 100, 0, 55483),
(562673, 7, 381.3229, 3146.277, 71.09901, 0, 0, 0, 0, 100, 0, 55483),
(562673, 8, 387.4375, 3151.354, 71.30311, 0, 0, 0, 0, 100, 0, 55483),

(562608, 1, 464.1806, 3069.09, 75.66865, 0, 1000, 0, 0, 100, 0, 55483),
(562608, 2, 452.559, 3068.431, 75.66865, 0, 0, 0, 0, 100, 0, 55483),
(562608, 3, 439.7257, 3069.273, 75.62312, 0, 0, 0, 0, 100, 0, 55483),
(562608, 4, 426.6059, 3071.281, 75.56077, 0, 0, 0, 0, 100, 0, 55483),
(562608, 5, 415.9306, 3071.176, 75.56077, 0, 1000, 0, 0, 100, 0, 55483),
(562608, 6, 426.6059, 3071.281, 75.56077, 0, 0, 0, 0, 100, 0, 55483),
(562608, 7, 439.7257, 3069.273, 75.62312, 0, 0, 0, 0, 100, 0, 55483),
(562608, 8, 452.559, 3068.431, 75.66865, 0, 0, 0, 0, 100, 0, 55483),

(562577, 1, 472.4323, 3043.867, 69.84633, 0, 0, 0, 0, 100, 0, 55483),
(562577, 2, 473.934, 3038.083, 69.9883, 4.101524, 4000, 0, 0, 100, 0, 55483),
(562577, 3, 469.691, 3047.639, 69.96828, 0, 0, 0, 0, 100, 0, 55483),
(562577, 4, 464.6458, 3049.901, 69.87754, 3.228859, 4000, 0, 0, 100, 0, 55483),

(562592, 1, 558.2743, 3054.667, 80.44264, 0, 0, 0, 0, 100, 0, 55483),
(562592, 2, 551.6563, 3056.492, 80.31764, 0, 0, 0, 0, 100, 0, 55483),
(562592, 3, 545.6077, 3052.431, 80.19264, 0, 0, 0, 0, 100, 0, 55483),
(562592, 4, 543.8055, 3045.939, 80.19264, 0, 0, 0, 0, 100, 0, 55483),
(562592, 5, 548.4722, 3040.293, 80.06764, 0, 0, 0, 0, 100, 0, 55483),
(562592, 6, 555.2309, 3037.478, 80.19264, 0, 0, 0, 0, 100, 0, 55483),
(562592, 7, 562.118, 3040.674, 80.31764, 0, 0, 0, 0, 100, 0, 55483),
(562592, 8, 564.3958, 3045.758, 80.49611, 0, 0, 0, 0, 100, 0, 55483),
(562592, 9, 563.1163, 3050.092, 80.51613, 0, 0, 0, 0, 100, 0, 55483),

(562640, 1, 469.526, 2994.882, 70.60343, 0, 0, 0, 0, 100, 0, 55483),
(562640, 2, 467.1528, 2999.224, 70.68107, 0, 0, 0, 0, 100, 0, 55483),
(562640, 3, 464.4288, 3003.859, 70.45284, 0, 0, 0, 0, 100, 0, 55483),
(562640, 4, 456.9479, 3001.788, 70.46981, 0, 0, 0, 0, 100, 0, 55483),
(562640, 5, 457.1406, 2995.359, 70.91563, 0, 0, 0, 0, 100, 0, 55483),
(562640, 6, 457.8246, 2984.767, 71.00181, 0, 0, 0, 0, 100, 0, 55483),
(562640, 7, 459.8438, 2980.103, 70.68284, 0, 0, 0, 0, 100, 0, 55483),
(562640, 8, 469.007, 2982.2, 70.3848, 0, 0, 0, 0, 100, 0, 55483),
(562640, 9, 472.4445, 2989.56, 70.4268, 0, 0, 0, 0, 100, 0, 55483),

(563645, 1, 509.757, 2897.378, 76.69012, 2.129302, 0, 0, 0, 100, 0, 55483),
(563645, 2, 509.757, 2897.378, 76.69012, 2.129302, 4000, 1, 0, 100, 0, 55483),
(563645, 3, 495.2986, 2895.148, 75.69424, 2.879793, 5000, 1, 0, 100, 0, 55483),
(563645, 4, 508.1719, 2906.806, 76.54586, 0, 0, 1, 0, 100, 0, 55483),
(563645, 5, 514.9323, 2904.929, 76.2629, 3.839724, 5000, 1, 0, 100, 0, 55483),

(562605, 1, 398.9896, 2985.709, 64.09676, 0, 0, 0, 0, 100, 0, 55483),
(562605, 2, 397.7691, 2979.278, 64.79182, 0, 0, 0, 0, 100, 0, 55483),
(562605, 3, 396.2257, 2973.277, 64.77266, 0, 0, 0, 0, 100, 0, 55483),
(562605, 4, 392.0625, 2971.245, 64.13875, 0, 0, 0, 0, 100, 0, 55483),
(562605, 5, 388.3629, 2974.976, 63.74911, 0, 0, 0, 0, 100, 0, 55483),
(562605, 6, 388.9931, 2980.297, 64.1584, 0, 0, 0, 0, 100, 0, 55483),
(562605, 7, 392.2066, 2983.156, 64.25301, 0, 0, 0, 0, 100, 0, 55483),
(562605, 8, 395.5573, 2990.332, 63.51448, 0, 0, 0, 0, 100, 0, 55483),
(562605, 9, 398.875, 2990.142, 63.41219, 0, 0, 0, 0, 100, 0, 55483),

(562727, 1, 390.3316, 3024.064, 63.18226, 0, 0, 0, 0, 100, 0, 55483),
(562727, 2, 384.7743, 3027.293, 63.24256, 0, 0, 0, 0, 100, 0, 55483),
(562727, 3, 377.3073, 3027.199, 62.99427, 0, 0, 0, 0, 100, 0, 55483),
(562727, 4, 376.9132, 3023.445, 62.36634, 0, 0, 0, 0, 100, 0, 55483),
(562727, 5, 381.9688, 3017.562, 62.54237, 0, 0, 0, 0, 100, 0, 55483),
(562727, 6, 385.6806, 3016.193, 62.90491, 0, 0, 0, 0, 100, 0, 55483),
(562727, 7, 391.8889, 3017.825, 63.02991, 0, 0, 0, 0, 100, 0, 55483),
(562727, 8, 391.9757, 3021.008, 63.15491, 0, 0, 0, 0, 100, 0, 55483),

(562586, 1, 530.0104, 3099.78, 79.69037, 0, 0, 0, 0, 100, 0, 55483),
(562586, 2, 535.6545, 3100.235, 79.70892, 0, 0, 0, 0, 100, 0, 55483),
(562586, 3, 543.8524, 3104.133, 79.95892, 0, 0, 0, 0, 100, 0, 55483),
(562586, 4, 545.6511, 3110.635, 79.95892, 0, 0, 0, 0, 100, 0, 55483),
(562586, 5, 543.4896, 3115.697, 79.95892, 0, 0, 0, 0, 100, 0, 55483),
(562586, 6, 537.8577, 3118.82, 79.81427, 0, 0, 0, 0, 100, 0, 55483),
(562586, 7, 528.5469, 3117.728, 79.52299, 0, 0, 0, 0, 100, 0, 55483),
(562586, 8, 525.1614, 3111.839, 79.45817, 0, 0, 0, 0, 100, 0, 55483),
(562586, 9, 521.2899, 3107.647, 79.58317, 0, 0, 0, 0, 100, 0, 55483),
(562586, 10, 521.9167, 3099.906, 79.76422, 0, 0, 0, 0, 100, 0, 55483),

(562618, 1, 518.1302, 3011.305, 74.72034, 0, 0, 0, 0, 100, 0, 55483),
(562618, 2, 515.5955, 3008.221, 74.48548, 0, 0, 0, 0, 100, 0, 55483),
(562618, 3, 516.309, 3001.037, 74.10084, 0, 0, 0, 0, 100, 0, 55483),
(562618, 4, 515.3489, 2992.095, 74.70626, 0, 0, 0, 0, 100, 0, 55483),
(562618, 5, 519.0886, 2988.883, 74.97469, 0, 0, 0, 0, 100, 0, 55483),
(562618, 6, 524.6007, 2990.772, 74.90926, 0, 0, 0, 0, 100, 0, 55483),
(562618, 7, 528.2239, 2995.833, 74.61166, 0, 0, 0, 0, 100, 0, 55483),
(562618, 8, 533.3958, 3000.993, 74.60734, 0, 0, 0, 0, 100, 0, 55483),
(562618, 9, 534.8212, 3008.246, 74.95524, 0, 0, 0, 0, 100, 0, 55483),
(562618, 10, 530.842, 3013.438, 75.04542, 0, 0, 0, 0, 100, 0, 55483),
(562618, 11, 526.2934, 3013.661, 74.82227, 0, 0, 0, 0, 100, 0, 55483),

(562724, 1, 376.9045, 3078.674, 69.58212, 0, 0, 0, 0, 100, 0, 55483),
(562724, 2, 376.9045, 3078.674, 69.58212, 0.4712389, 5000, 0, 0, 100, 0, 55483),
(562724, 3, 363.0781, 3078.563, 69.58601, 0, 0, 0, 0, 100, 0, 55483),
(562724, 4, 358.1111, 3082.212, 69.21101, 1.867502, 5000, 0, 0, 100, 0, 55483),
(562724, 5, 371.566, 3076.871, 69.82064, 0, 0, 0, 0, 100, 0, 55483),

(562674, 1, 332.9097, 3083.4, 62.74874, 0, 0, 0, 0, 100, 0, 55483),
(562674, 2, 330.6493, 3076.489, 62.49874, 0, 0, 0, 0, 100, 0, 55483),
(562674, 3, 324.6285, 3075.667, 62.51668, 0, 0, 0, 0, 100, 0, 55483),
(562674, 4, 319.0538, 3079.105, 62.29268, 0, 0, 0, 0, 100, 0, 55483),
(562674, 5, 315.1545, 3083.75, 62.10482, 0, 1000, 0, 0, 100, 0, 55483),
(562674, 6, 319.0538, 3079.105, 62.29268, 0, 0, 0, 0, 100, 0, 55483),
(562674, 7, 324.6285, 3075.667, 62.51668, 0, 0, 0, 0, 100, 0, 55483),
(562674, 8, 330.6493, 3076.489, 62.49874, 0, 0, 0, 0, 100, 0, 55483),
(562674, 9, 332.9097, 3083.4, 62.74874, 0, 0, 0, 0, 100, 0, 55483),
(562674, 10, 331.8542, 3093.378, 63.20089, 0, 1000, 0, 0, 100, 0, 55483),

(562661, 1, 349.0347, 3159.946, 63.12917, 0, 0, 0, 0, 100, 0, 55483),
(562661, 2, 342.1163, 3155.566, 63.57595, 0, 0, 0, 0, 100, 0, 55483),
(562661, 3, 340.4618, 3152.135, 63.70095, 0, 0, 0, 0, 100, 0, 55483),
(562661, 4, 343.4705, 3148.309, 63.42202, 0, 0, 0, 0, 100, 0, 55483),
(562661, 5, 348.4913, 3147.458, 62.94436, 0, 0, 0, 0, 100, 0, 55483),
(562661, 6, 349.4549, 3153.365, 62.82888, 0, 0, 0, 0, 100, 0, 55483),

(562663, 1, 341.6788, 3175.441, 62.83428, 0, 0, 0, 0, 100, 0, 55483),
(562663, 2, 335.7778, 3173.89, 62.57476, 2.129302, 4000, 0, 0, 100, 0, 55483),
(562663, 3, 347.4045, 3179.364, 62.7387, 0, 0, 0, 0, 100, 0, 55483),
(562663, 4, 353.4236, 3180.273, 62.75445, 4.729842, 4000, 0, 0, 100, 0, 55483),

(562730, 1, 500.1076, 3161.371, 74.35088, 0, 0, 0, 0, 100, 0, 55483),
(562730, 2, 501.7917, 3166.227, 74.60491, 0, 0, 0, 0, 100, 0, 55483),
(562730, 3, 498.2049, 3171.723, 74.50964, 0, 0, 0, 0, 100, 0, 55483),
(562730, 4, 488.908, 3171.497, 73.98266, 0, 0, 0, 0, 100, 0, 55483),
(562730, 5, 479.1458, 3171.595, 74.6195, 0, 0, 0, 0, 100, 0, 55483),
(562730, 6, 475.1719, 3161.497, 74.28428, 0, 0, 0, 0, 100, 0, 55483),
(562730, 7, 474.4549, 3149.972, 74.56113, 0, 0, 0, 0, 100, 0, 55483),
(562730, 8, 477.8316, 3145.616, 74.70591, 0, 0, 0, 0, 100, 0, 55483),
(562730, 9, 484.5781, 3146.231, 74.3823, 0, 0, 0, 0, 100, 0, 55483),
(562730, 10, 488.2604, 3152.07, 73.86741, 0, 0, 0, 0, 100, 0, 55483),
(562730, 11, 492.7413, 3156.657, 73.82261, 0, 0, 0, 0, 100, 0, 55483),

(563646, 1, 557.0364, 2898.634, 78.01105, 0, 0, 0, 0, 100, 0, 55483),
(563646, 2, 557.0364, 2898.634, 78.01105, 0.2792527, 5000, 1, 0, 100, 0, 55483),
(563646, 3, 556.8785, 2882.924, 77.16058, 0, 0, 1, 0, 100, 0, 55483),
(563646, 4, 554.3351, 2878.627, 77.71576, 0, 4000, 1, 0, 100, 0, 55483),
(563646, 5, 545.3125, 2888.021, 77.04828, 3.543018, 4000, 1, 0, 100, 0, 55483),

(563647, 1, 524.1389, 2874.271, 79.91058, 0, 0, 0, 0, 100, 0, 55483),
(563647, 2, 524.1389, 2874.271, 79.91058, 5.5676, 4000, 1, 0, 100, 0, 55483),
(563647, 3, 541.2674, 2881.359, 77.06317, 0, 5000, 1, 0, 100, 0, 55483),
(563647, 4, 531.9219, 2870.245, 79.65813, 2.373648, 4000, 1, 0, 100, 0, 55483),
(563647, 5, 520.2031, 2870.776, 79.67913, 0, 0, 1, 0, 100, 0, 55483),

(563630, 1, 584.6424, 3069.675, 80.12199, 0, 0, 0, 0, 100, 0, 55483),
(563630, 2, 578.566, 3071.234, 80.1038, 0, 0, 0, 0, 100, 0, 55483),
(563630, 3, 573.2813, 3068.853, 80.3538, 3.804818, 5000, 0, 0, 100, 0, 55483),
(563630, 4, 585.6441, 3069.095, 80.17265, 0, 0, 0, 0, 100, 0, 55483),
(563630, 5, 589.0712, 3064.247, 80.06686, 0, 0, 0, 0, 100, 0, 55483),
(563630, 6, 590.0677, 3059.398, 80.19284, 3.996804, 5000, 0, 0, 100, 0, 55483),

(562655, 1, 353.7743, 3290.809, 72.70367, 0, 0, 1, 0, 100, 0, 55483),
(562655, 2, 362.2604, 3290.896, 73.11126, 0, 0, 1, 0, 100, 0, 55483),
(562655, 3, 370.2222, 3286.266, 74.10025, 0, 0, 1, 0, 100, 0, 55483),
(562655, 4, 368.5781, 3280.94, 75.2261, 2.949606, 5000, 1, 0, 100, 0, 55483),
(562655, 5, 370.5278, 3259.163, 75.44081, 0, 4000, 1, 0, 100, 0, 55483),
(562655, 6, 351.4983, 3254.48, 75.36993, 0, 5000, 1, 0, 100, 0, 55483),
(562655, 7, 348.0017, 3275.332, 73.9052, 0, 0, 1, 0, 100, 0, 55483),
(562655, 8, 347.8038, 3285.818, 73.58245, 0, 0, 1, 0, 100, 0, 55483),

(563644, 1, 379.7951, 3327.565, 74.79167, 0, 0, 0, 0, 100, 0, 55483),
(563644, 2, 379.7951, 3327.565, 74.79167, 0.6108652, 5000, 1, 0, 100, 0, 55483),
(563644, 3, 364.2168, 3318.475, 70.68683, 0, 0, 1, 0, 100, 0, 55483),
(563644, 4, 352.651, 3317.564, 70.21743, 0, 0, 1, 0, 100, 0, 55483),
(563644, 5, 347.1354, 3319.556, 70.53812, 0, 0, 1, 0, 100, 0, 55483),
(563644, 6, 341.9358, 3317.97, 70.66581, 3.630285, 4000, 1, 0, 100, 0, 55483),
(563644, 7, 363.9266, 3318.617, 70.65099, 0, 0, 1, 0, 100, 0, 55483),
(563644, 8, 367.1932, 3327.363, 71.80902, 0, 4000, 1, 0, 100, 0, 55483),

(562695, 1, 323.6181, 3276.677, 75.07351, 0, 0, 0, 0, 100, 0, 55483),
(562695, 2, 323.6181, 3276.677, 75.07351, 0, 5000, 1, 0, 100, 0, 55483),
(562695, 3, 303.9722, 3277.998, 73.45412, 0, 0, 1, 0, 100, 0, 55483),
(562695, 4, 297.4028, 3283.854, 72.55679, 0, 0, 1, 0, 100, 0, 55483),
(562695, 5, 297.1701, 3288.018, 73.37563, 0, 4000, 1, 0, 100, 0, 55483),
(562695, 6, 310.9132, 3287.49, 74.02627, 0, 0, 1, 0, 100, 0, 55483),
(562695, 7, 306.9045, 3292.75, 74.76369, 0, 4000, 1, 0, 100, 0, 55483),
(562695, 8, 323.066, 3286.309, 73.87307, 0, 0, 1, 0, 100, 0, 55483);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (55483, -563648, -562577, -563645, -562724, -562663, -563646, -563647, -563630, -562655, -563644, -562695) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (55483*100, 55483*100+01) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(55483, 0, 0, 0, 4, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Say Text Line 0"),
(55483, 0, 1, 0, 4, 0, 100, 0, 0, 0, 0, 0, 30, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Set Random Phase"),
(55483, 0, 2, 0, 0, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 107936, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Back Kick'"),
(55483, 0, 3, 0, 0, 1, 100, 0, 5000, 8000, 8000, 12000, 11, 107938, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Tail Thrash' (Phase 1)"),
(55483, 0, 4, 0, 0, 2, 100, 0, 5000, 8000, 15000, 20000, 11, 107944, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Carrot Breath' (Phase 2)"),

(-563648, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 1 - Start Script"),
(-563648, 0, 1, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 3 - Start Script"),
(-563648, 0, 2, 0, 34, 0, 100, 0, 2, 6, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 6 - Start Script"),
(-563648, 0, 3, 0, 4, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Say Text Line 0"),
(-563648, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 30, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Set Random Phase"),
(-563648, 0, 5, 0, 0, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 107936, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Back Kick'"),
(-563648, 0, 6, 0, 0, 1, 100, 0, 5000, 8000, 8000, 12000, 11, 107938, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Tail Thrash' (Phase 1)"),
(-563648, 0, 7, 0, 0, 2, 100, 0, 5000, 8000, 15000, 20000, 11, 107944, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Carrot Breath' (Phase 2)"),

(-562577, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 1 - Start Script"),
(-562577, 0, 1, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 3 - Start Script"),
(-562577, 0, 2, 0, 4, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Say Text Line 0"),
(-562577, 0, 3, 0, 4, 0, 100, 0, 0, 0, 0, 0, 30, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Set Random Phase"),
(-562577, 0, 4, 0, 0, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 107936, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Back Kick'"),
(-562577, 0, 5, 0, 0, 1, 100, 0, 5000, 8000, 8000, 12000, 11, 107938, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Tail Thrash' (Phase 1)"),
(-562577, 0, 6, 0, 0, 2, 100, 0, 5000, 8000, 15000, 20000, 11, 107944, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Carrot Breath' (Phase 2)"),

(-563645, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 1 - Start Script"),
(-563645, 0, 1, 0, 34, 0, 100, 0, 2, 2, 0, 0, 80, 55483*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 2 - Start Script"),
(-563645, 0, 2, 0, 34, 0, 100, 0, 2, 4, 0, 0, 80, 55483*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 4 - Start Script"),
(-563645, 0, 3, 0, 4, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Say Text Line 0"),
(-563645, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 30, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Set Random Phase"),
(-563645, 0, 5, 0, 0, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 107936, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Back Kick'"),
(-563645, 0, 6, 0, 0, 1, 100, 0, 5000, 8000, 8000, 12000, 11, 107938, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Tail Thrash' (Phase 1)"),
(-563645, 0, 7, 0, 0, 2, 100, 0, 5000, 8000, 15000, 20000, 11, 107944, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Carrot Breath' (Phase 2)"),

(-562724, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 55483*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 1 - Start Script"),
(-562724, 0, 1, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 55483*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 3 - Start Script"),
(-562724, 0, 2, 0, 4, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Say Text Line 0"),
(-562724, 0, 3, 0, 4, 0, 100, 0, 0, 0, 0, 0, 30, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Set Random Phase"),
(-562724, 0, 4, 0, 0, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 107936, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Back Kick'"),
(-562724, 0, 5, 0, 0, 1, 100, 0, 5000, 8000, 8000, 12000, 11, 107938, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Tail Thrash' (Phase 1)"),
(-562724, 0, 6, 0, 0, 2, 100, 0, 5000, 8000, 15000, 20000, 11, 107944, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Carrot Breath' (Phase 2)"),

(-562663, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 1 - Start Script"),
(-562663, 0, 1, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 3 - Start Script"),
(-562663, 0, 2, 0, 4, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Say Text Line 0"),
(-562663, 0, 3, 0, 4, 0, 100, 0, 0, 0, 0, 0, 30, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Set Random Phase"),
(-562663, 0, 4, 0, 0, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 107936, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Back Kick'"),
(-562663, 0, 5, 0, 0, 1, 100, 0, 5000, 8000, 8000, 12000, 11, 107938, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Tail Thrash' (Phase 1)"),
(-562663, 0, 6, 0, 0, 2, 100, 0, 5000, 8000, 15000, 20000, 11, 107944, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Carrot Breath' (Phase 2)"),

(-563646, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 55483*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 1 - Start Script"),
(-563646, 0, 1, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 3 - Start Script"),
(-563646, 0, 2, 0, 34, 0, 100, 0, 2, 4, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 4 - Start Script"),
(-563646, 0, 3, 0, 4, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Say Text Line 0"),
(-563646, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 30, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Set Random Phase"),
(-563646, 0, 5, 0, 0, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 107936, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Back Kick'"),
(-563646, 0, 6, 0, 0, 1, 100, 0, 5000, 8000, 8000, 12000, 11, 107938, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Tail Thrash' (Phase 1)"),
(-563646, 0, 7, 0, 0, 2, 100, 0, 5000, 8000, 15000, 20000, 11, 107944, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Carrot Breath' (Phase 2)"),

(-563647, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 1 - Start Script"),
(-563647, 0, 1, 0, 34, 0, 100, 0, 2, 2, 0, 0, 80, 55483*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 2 - Start Script"),
(-563647, 0, 2, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 3 - Start Script"),
(-563647, 0, 3, 0, 4, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Say Text Line 0"),
(-563647, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 30, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Set Random Phase"),
(-563647, 0, 5, 0, 0, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 107936, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Back Kick'"),
(-563647, 0, 6, 0, 0, 1, 100, 0, 5000, 8000, 8000, 12000, 11, 107938, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Tail Thrash' (Phase 1)"),
(-563647, 0, 7, 0, 0, 2, 100, 0, 5000, 8000, 15000, 20000, 11, 107944, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Carrot Breath' (Phase 2)"),

(-563630, 0, 0, 0, 34, 0, 100, 0, 2, 2, 0, 0, 80, 55483*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 2 - Start Script"),
(-563630, 0, 1, 0, 34, 0, 100, 0, 2, 5, 0, 0, 80, 55483*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 5 - Start Script"),
(-563630, 0, 2, 0, 4, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Say Text Line 0"),
(-563630, 0, 3, 0, 4, 0, 100, 0, 0, 0, 0, 0, 30, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Set Random Phase"),
(-563630, 0, 4, 0, 0, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 107936, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Back Kick'"),
(-563630, 0, 5, 0, 0, 1, 100, 0, 5000, 8000, 8000, 12000, 11, 107938, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Tail Thrash' (Phase 1)"),
(-563630, 0, 6, 0, 0, 2, 100, 0, 5000, 8000, 15000, 20000, 11, 107944, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Carrot Breath' (Phase 2)"),

(-562655, 0, 0, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 55483*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 3 - Start Script"),
(-562655, 0, 1, 0, 34, 0, 100, 0, 2, 4, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 4 - Start Script"),
(-562655, 0, 2, 0, 34, 0, 100, 0, 2, 5, 0, 0, 80, 55483*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 5 - Start Script"),
(-562655, 0, 3, 0, 4, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Say Text Line 0"),
(-562655, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 30, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Set Random Phase"),
(-562655, 0, 5, 0, 0, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 107936, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Back Kick'"),
(-562655, 0, 6, 0, 0, 1, 100, 0, 5000, 8000, 8000, 12000, 11, 107938, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Tail Thrash' (Phase 1)"),
(-562655, 0, 7, 0, 0, 2, 100, 0, 5000, 8000, 15000, 20000, 11, 107944, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Carrot Breath' (Phase 2)"),

(-563644, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 55483*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 1 - Start Script"),
(-563644, 0, 1, 0, 34, 0, 100, 0, 2, 5, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 5 - Start Script"),
(-563644, 0, 2, 0, 34, 0, 100, 0, 2, 7, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 7 - Start Script"),
(-563644, 0, 3, 0, 4, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Say Text Line 0"),
(-563644, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 30, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Set Random Phase"),
(-563644, 0, 5, 0, 0, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 107936, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Back Kick'"),
(-563644, 0, 6, 0, 0, 1, 100, 0, 5000, 8000, 8000, 12000, 11, 107938, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Tail Thrash' (Phase 1)"),
(-563644, 0, 7, 0, 0, 2, 100, 0, 5000, 8000, 15000, 20000, 11, 107944, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Carrot Breath' (Phase 2)"),

(-562695, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 55483*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 1 - Start Script"),
(-562695, 0, 1, 0, 34, 0, 100, 0, 2, 4, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 4 - Start Script"),
(-562695, 0, 2, 0, 34, 0, 100, 0, 2, 6, 0, 0, 80, 55483*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - MI 6 - Start Script"),
(-562695, 0, 3, 0, 4, 0, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Say Text Line 0"),
(-562695, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 30, 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Aggro - Set Random Phase"),
(-562695, 0, 5, 0, 0, 0, 100, 0, 2000, 5000, 5000, 8000, 11, 107936, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Back Kick'"),
(-562695, 0, 6, 0, 0, 1, 100, 0, 5000, 8000, 8000, 12000, 11, 107938, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Tail Thrash' (Phase 1)"),
(-562695, 0, 7, 0, 0, 2, 100, 0, 5000, 8000, 15000, 20000, 11, 107944, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - In Combat - Cast Spell 'Carrot Breath' (Phase 2)"),

(55483*100, 9, 0, 0, 0, 0, 100, 0, 400, 400, 0, 0, 17, 173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Script - Set Emote State (173)"),
(55483*100, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 17, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Script - Clear Emote"),

(55483*100+01, 9, 0, 0, 0, 0, 100, 0, 400, 400, 0, 0, 17, 173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Script - Set Emote State (173)"),
(55483*100+01, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 17, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Plump Virmen - On Script - Clear Emote");

DELETE FROM `creature_text` WHERE `entry` = 55483;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(55483, 0, 0, "Gimme all your vegetables!", "", 12, 0, 100, 0, 0, 0, "Plump Virmen"),
(55483, 0, 1, "AIIIIEEEEEEE!", "", 12, 0, 100, 0, 0, 0, "Plump Virmen"),
(55483, 0, 2, "This virmen land!", "", 12, 0, 100, 0, 0, 0, "Plump Virmen"),
(55483, 0, 3, "You no take carrot! You take turnip instead!", "", 12, 0, 100, 0, 0, 0, "Plump Virmen");

-- Jie & Kong
UPDATE `creature` SET `position_x` = 724.2811, `position_y` = 3561.543, `position_z` = 140.9771, `orientation` = 4.237815, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562780;
UPDATE `creature` SET `position_x` = 727.3837, `position_y` = 3573.647, `position_z` = 141.1417, `orientation` = 4.532227, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 562779;

UPDATE `creature_template_addon` SET `path_id` = 562780 WHERE `entry` = 60260;

DELETE FROM `waypoint_data` WHERE `id` = 562780;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562780, 1, 719.3698, 3551.976, 141.839, 0, 0, 1, 0, 100, 0, 60260),
(562780, 2, 714.7708, 3540.35, 141.8156, 0, 0, 1, 0, 100, 0, 60260),
(562780, 3, 717.1129, 3526.411, 140.9664, 0, 0, 1, 0, 100, 0, 60260),
(562780, 4, 725.6129, 3517.175, 140.6007, 0, 0, 1, 0, 100, 0, 60260),
(562780, 5, 739.9618, 3513.656, 139.6242, 0, 0, 1, 0, 100, 0, 60260),
(562780, 6, 744.5278, 3501.899, 136.5356, 0, 0, 1, 0, 100, 0, 60260),
(562780, 7, 735.4445, 3493.202, 131.5683, 0, 0, 1, 0, 100, 0, 60260),
(562780, 8, 717.0573, 3485.473, 123.0903, 0, 0, 1, 0, 100, 0, 60260),
(562780, 9, 703.3524, 3480.11, 118.9842, 0, 0, 1, 0, 100, 0, 60260),
(562780, 10, 694.3507, 3481.931, 118.7684, 0, 0, 1, 0, 100, 0, 60260),
(562780, 11, 683.1458, 3490.439, 118.7684, 0, 0, 1, 0, 100, 0, 60260),
(562780, 12, 669.5538, 3495.06, 119.2952, 0, 0, 1, 0, 100, 0, 60260),
(562780, 13, 660.3229, 3497.813, 119.6263, 0, 0, 1, 0, 100, 0, 60260),
(562780, 14, 652.6424, 3492.679, 118.9615, 0, 0, 1, 0, 100, 0, 60260),
(562780, 15, 652.5052, 3481.914, 119.9906, 0, 0, 1, 0, 100, 0, 60260),
(562780, 16, 661.092, 3476.622, 119.1243, 0, 0, 1, 0, 100, 0, 60260),
(562780, 17, 676.1597, 3481.171, 119.4125, 0, 0, 1, 0, 100, 0, 60260),
(562780, 18, 688.5347, 3483.036, 118.7684, 0, 0, 1, 0, 100, 0, 60260),
(562780, 19, 700.8021, 3477.887, 118.5882, 0, 0, 1, 0, 100, 0, 60260),
(562780, 20, 712.8906, 3476.139, 120.2223, 0, 0, 1, 0, 100, 0, 60260),
(562780, 21, 727.3438, 3482.998, 126.5545, 0, 0, 1, 0, 100, 0, 60260),
(562780, 22, 741.9601, 3488.964, 133.4052, 0, 0, 1, 0, 100, 0, 60260),
(562780, 23, 750.382, 3496.025, 136.6762, 0, 0, 1, 0, 100, 0, 60260),
(562780, 24, 759.6337, 3507.681, 139.2196, 0, 0, 1, 0, 100, 0, 60260),
(562780, 25, 772.1371, 3518.106, 140.2978, 0, 0, 1, 0, 100, 0, 60260),
(562780, 26, 775.7969, 3532.225, 141.2039, 0, 0, 1, 0, 100, 0, 60260),
(562780, 27, 773.2379, 3542.181, 140.6984, 0, 0, 1, 0, 100, 0, 60260),
(562780, 28, 768.066, 3545.694, 141.0734, 0, 0, 1, 0, 100, 0, 60260),
(562780, 29, 760.2761, 3547.443, 141.4889, 0, 0, 1, 0, 100, 0, 60260),
(562780, 30, 756.1077, 3555.059, 141.6072, 0, 0, 1, 0, 100, 0, 60260),
(562780, 31, 756.0555, 3562.875, 141.3301, 0, 0, 1, 0, 100, 0, 60260),
(562780, 32, 758.158, 3587.756, 140.8848, 0, 0, 1, 0, 100, 0, 60260),
(562780, 33, 757.6337, 3605.651, 140.6299, 0, 0, 1, 0, 100, 0, 60260),
(562780, 34, 758.3906, 3617.568, 140.9813, 0, 0, 1, 0, 100, 0, 60260),
(562780, 35, 750.7726, 3621.224, 141.5206, 0, 0, 1, 0, 100, 0, 60260),
(562780, 36, 739.0417, 3627.223, 142.631, 0, 0, 1, 0, 100, 0, 60260),
(562780, 37, 733.1111, 3628.654, 142.631, 0, 0, 1, 0, 100, 0, 60260),
(562780, 38, 718.8507, 3634.047, 141.5711, 0, 0, 1, 0, 100, 0, 60260),
(562780, 39, 711.9566, 3632.925, 140.9794, 0, 0, 1, 0, 100, 0, 60260),
(562780, 40, 708.2188, 3620.637, 142.1206, 0, 0, 1, 0, 100, 0, 60260),
(562780, 41, 711.7327, 3613.663, 142.0727, 0, 0, 1, 0, 100, 0, 60260),
(562780, 42, 716.5989, 3611.516, 141.58, 0, 0, 1, 0, 100, 0, 60260),
(562780, 43, 724.5208, 3612.868, 140.7406, 0, 0, 1, 0, 100, 0, 60260),
(562780, 44, 731.75, 3604.134, 140.7456, 0, 0, 1, 0, 100, 0, 60260),
(562780, 45, 731.2726, 3592.069, 140.7415, 0, 0, 1, 0, 100, 0, 60260),
(562780, 46, 728.8108, 3580.431, 141.3467, 0, 0, 1, 0, 100, 0, 60260),
(562780, 47, 725.632, 3564.173, 140.7756, 0, 0, 1, 0, 100, 0, 60260);

DELETE FROM `creature_formations` WHERE `leaderGUID` = 562780;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(562780, 562780, 0, 0, 2, 0, 0),
(562780, 562779, 10, 0, 2, 0, 0);

-- Mei Chele, Azrael & Samus
DELETE FROM `creature` WHERE `guid` IN (562743, 562744, 562746) AND `id` = 66691;
DELETE FROM `creature_addon` WHERE `guid` IN (562743, 562744, 562746);
UPDATE `creature` SET `position_x` = 685.1371, `position_y` = 3497.615, `position_z` = 119.1661, `orientation` = 1.149085, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 562778;
UPDATE `creature` SET `position_x` = 678.8613, `position_y` = 3495.583, `position_z` = 118.7113, `orientation` = 3.76045, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 562774;
DELETE FROM `creature_template_addon` WHERE `entry` IN (66691, 66692);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (66689, 66691, 66692);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (66689, 66691, 66692) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6668900, 6668901, 6669100, 6669101, 6669200, 6669201) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(66689, 0, 0, 0, 1, 0, 100, 1, 20000, 20000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mei Chele - OOC - Set Data 1 1 (No Repeat)"),
(66689, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 17, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mei Chele - On Data Set 1 1 - Set Emote State (30)"),
(66689, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 66689, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mei Chele - On Data Set 1 1 (Link) - Start WP"),
(66689, 0, 3, 4, 40, 0, 100, 0, 4, 66689, 0, 0, 54, 3500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mei Chele - WP Reached 4 - Pause WP (3500 ms)"),
(66689, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mei Chele - WP Reached 4 (Link) - Play Emote (4)"),
(66689, 0, 5, 6, 40, 0, 100, 0, 5, 66689, 0, 0, 54, 19000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mei Chele - WP Reached 5 - Pause WP (19000 ms)"),
(66689, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 5, 17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mei Chele - WP Reached 5 (Link) - Play Emote (17)"),
(66689, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 6668900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mei Chele - WP Reached 5 (Link) - Start Script"),
(66689, 0, 8, 9, 58, 0, 100, 0, 11, 66689, 0, 0, 54, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mei Chele - WP Reached 11 - Pause WP (60000 ms)"),
(66689, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 6668901, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mei Chele - WP Reached 11 (Link) - Start Script"),

(6668900, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 52148, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mei Chele - On Script - Cast Cosmetic - Love"),
(6668900, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mei Chele - On Script - Play Emote (24)"),

(6668901, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.253441, "Mei Chele - On Script - Set Orientation (5.253441)"),
(6668901, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 860, 0, 0, 0, 0, 0, 1, 0, 0, 0, 675.2795, 3514.17, 119.6324, 5.694905, "Mei Chele - On Script - Teleport"),
(6668901, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 415, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Mei Chele - On Script - Set Emote State (415)"),

(66691, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, 66691, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Azrael - On Respawn - Start WP"),
(66691, 0, 1, 2, 40, 0, 100, 0, 11, 66691, 0, 0, 54, 100000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Azrael - WP Reached 11 - Pause WP (100000 ms)"),
(66691, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 6669100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Azrael - WP Reached 11 (Link) - Start Script"),
(66691, 0, 3, 4, 40, 0, 100, 0, 12, 66691, 0, 0, 54, 23000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Azrael - WP Reached 12 - Pause WP (23000 ms)"),
(66691, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 6669101, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Azrael - WP Reached 12 (Link) - Start Script"),
(66691, 0, 5, 6, 40, 0, 100, 0, 34, 66691, 0, 0, 54, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Azrael - WP Reached 34 - Pause WP (2000 ms)"),
(66691, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Azrael - WP Reached 34 (Link) - Set Run Off"),

(6669100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.8028514, "Azrael - On Script - Set Orientation (0.8028514)"),
(6669100, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 97, 10, 5, 0, 0, 0, 0, 1, 0, 0, 0, 673.705, 3510.5, 120.99, 0, "Azrael - On Script - Jump To Position"),
(6669100, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.380776, "Azrael - On Script - Set Orientation (4.380776)"),
(6669100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Azrael - On Script - Set Unit Field Bytes 1 (1)"),
(6669100, 9, 4, 0, 0, 0, 100, 0, 91000, 91000, 0, 0, 91, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Azrael - On Script - Remove Unit Field Bytes 1 (1)"),
(6669100, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 97, 10, 5, 0, 0, 0, 0, 1, 0, 0, 0, 672.771, 3509.4, 119.632, 0, "Azrael - On Script - Jump To Position"),

(6669101, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.707227, "Azrael - On Script - Set Orientation (5.707227)"),
(6669101, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 90, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Azrael - On Script - Set Unit Field Bytes 1 (1)"),
(6669101, 9, 2, 0, 0, 0, 100, 0, 16000, 16000, 0, 0, 91, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Azrael - On Script - Remove Unit Field Bytes 1 (1)"),
(6669101, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Azrael - On Script - Set Run On"),

(66692, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 53, 0, 66692, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - On Respawn - Start WP"),
(66692, 0, 1, 0, 40, 0, 100, 0, 5, 66692, 0, 0, 54, 4000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - WP Reached 5 - Pause WP (4000 ms)"),
(66692, 0, 2, 3, 40, 0, 100, 0, 16, 66692, 0, 0, 54, 74000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - WP Reached 16 - Pause WP (74000 ms)"),
(66692, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 6669200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - WP Reached 16 (Link) - Start Script"),
(66692, 0, 4, 5, 40, 0, 100, 0, 34, 66692, 0, 0, 54, 54000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - WP Reached 34 - Pause WP (54000 ms)"),
(66692, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 6669201, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - WP Reached 34 (Link) - Start Script"),

(6669200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 97, 10, 5, 0, 0, 0, 0, 1, 0, 0, 0, 689.229, 3506.4, 120.349, 0, "Samus - On Script - Jump To Position"),
(6669200, 9, 1, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 97, 10, 5, 0, 0, 0, 0, 1, 0, 0, 0, 688.398, 3505.23, 120.639, 0, "Samus - On Script - Jump To Position"),
(6669200, 9, 2, 0, 0, 0, 100, 0, 500, 500, 0, 0, 90, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - On Script - Set Unit Field Bytes 1 (1)"),
(6669200, 9, 3, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 91, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - On Script - Remove Unit Field Bytes 1 (1)"),
(6669200, 9, 4, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 90, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - On Script - Set Unit Field Bytes 1 (3)"),
(6669200, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 125567, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - On Script - Cast Cosmetic - Sleep Zzz"),
(6669200, 9, 6, 0, 0, 0, 100, 0, 60000, 60000, 0, 0, 28, 125567, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - On Script - Unaura Cosmetic - Sleep Zzz"),
(6669200, 9, 7, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 91, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - On Script - Remove Unit Field Bytes 1 (3)"),
(6669200, 9, 8, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.064651, "Samus - On Script - Set Orientation (1.064651)"),
(6669200, 9, 9, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 97, 10, 5, 0, 0, 0, 0, 1, 0, 0, 0, 688.66, 3507.96, 119.347, 0, "Samus - On Script - Jump To Position"),

(6669201, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.3490658, "Samus - On Script - Set Orientation (0.3490658)"),
(6669201, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 97, 10, 5, 0, 0, 0, 0, 1, 0, 0, 0, 681.036, 3513.87, 120.556, 0, "Samus - On Script - Jump To Position"),
(6669201, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.508112, "Samus - On Script - Set Orientation (3.508112)"),
(6669201, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - On Script - Set Unit Field Bytes 1 (1)"),
(6669201, 9, 4, 0, 0, 0, 100, 0, 38000, 38000, 0, 0, 91, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Samus - On Script - Remove Unit Field Bytes 1 (1)"),
(6669201, 9, 5, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 97, 10, 5, 0, 0, 0, 0, 1, 0, 0, 0, 678.356, 3512.9, 119.632, 0, "Samus - On Script - Jump To Position");

DELETE FROM `waypoints` WHERE `entry` IN (66689, 66691, 66692);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(66689, 1, 676.3923, 3511.828, 119.8905, "Mei Chele"),
(66689, 2, 676.1423, 3509.578, 119.8905, "Mei Chele"),
(66689, 3, 675.6423, 3508.078, 119.8905, "Mei Chele"),
(66689, 4, 676.0052, 3505.986, 119.6485, "Mei Chele"),
(66689, 5, 677.0139, 3502.88, 118.7052, "Mei Chele"),
(66689, 6, 676.1832, 3506.306, 119.9188, "Mei Chele"),
(66689, 7, 675.6832, 3508.306, 119.9188, "Mei Chele"),
(66689, 8, 676.6832, 3509.806, 119.9188, "Mei Chele"),
(66689, 9, 676.9332, 3511.306, 119.9188, "Mei Chele"),
(66689, 10, 676.4332, 3512.556, 119.9188, "Mei Chele"),
(66689, 11, 675.8524, 3513.733, 119.6324, "Mei Chele"),

(66691, 1, 684.2465, 3495.969, 119.3992, "Azrael"),
(66691, 2, 682.2465, 3493.219, 119.1492, "Azrael"),
(66691, 3, 678.4965, 3491.969, 119.1492, "Azrael"),
(66691, 4, 675.9965, 3493.469, 119.1492, "Azrael"),
(66691, 5, 675.2465, 3496.469, 119.1492, "Azrael"),
(66691, 6, 676.2465, 3499.719, 119.1492, "Azrael"),
(66691, 7, 676.7465, 3502.969, 119.1492, "Azrael"),
(66691, 8, 676.2465, 3504.969, 119.3992, "Azrael"),
(66691, 9, 675.2465, 3507.219, 119.8992, "Azrael"),
(66691, 10, 673.7465, 3508.219, 119.8992, "Azrael"),
(66691, 11, 671.8559, 3509.823, 119.6324, "Azrael"),
(66691, 12, 669.592, 3511.491, 119.6324, "Azrael"),
(66691, 13, 671.3646, 3512.053, 119.8992, "Azrael"),
(66691, 14, 672.8646, 3512.803, 119.8992, "Azrael"),
(66691, 15, 674.8646, 3513.303, 119.8992, "Azrael"),
(66691, 16, 676.8646, 3512.553, 119.8992, "Azrael"),
(66691, 17, 677.3646, 3511.053, 119.8992, "Azrael"),
(66691, 18, 676.3646, 3508.803, 119.8992, "Azrael"),
(66691, 19, 675.8646, 3507.303, 119.8992, "Azrael"),
(66691, 20, 676.3646, 3505.803, 119.8992, "Azrael"),
(66691, 21, 677.1146, 3503.553, 119.1492, "Azrael"),
(66691, 22, 678.1146, 3500.303, 119.1492, "Azrael"),
(66691, 23, 680.1146, 3499.303, 119.1492, "Azrael"),
(66691, 24, 682.8646, 3499.553, 119.1492, "Azrael"),
(66691, 25, 684.6146, 3500.053, 119.3992, "Azrael"),
(66691, 26, 686.8646, 3499.803, 119.8992, "Azrael"),
(66691, 27, 688.8646, 3499.053, 120.1492, "Azrael"),
(66691, 28, 689.6146, 3496.803, 120.3992, "Azrael"),
(66691, 29, 689.1146, 3494.553, 120.3992, "Azrael"),
(66691, 30, 688.1146, 3492.803, 119.8992, "Azrael"),
(66691, 31, 686.1146, 3492.053, 119.3992, "Azrael"),
(66691, 32, 684.3646, 3493.053, 119.3992, "Azrael"),
(66691, 33, 684.1146, 3495.303, 119.3992, "Azrael"),
(66691, 34, 685.1371, 3497.615, 119.1661, "Azrael"),

(66692, 1, 677.7275, 3495.108, 119.1741, "Samus"),
(66692, 2, 672.4775, 3494.358, 119.1741, "Samus"),
(66692, 3, 667.7275, 3495.108, 119.6741, "Samus"),
(66692, 4, 665.4775, 3500.108, 119.4241, "Samus"),
(66692, 5, 664.5989, 3507.317, 118.7162, "Samus"),
(66692, 6, 663.1788, 3504.819, 119.0325, "Samus"),
(66692, 7, 663.1788, 3498.569, 119.7825, "Samus"),
(66692, 8, 666.4288, 3493.819, 120.0325, "Samus"),
(66692, 9, 670.4288, 3492.819, 119.5325, "Samus"),
(66692, 10, 678.1788, 3496.319, 119.0325, "Samus"),
(66692, 11, 683.9288, 3502.069, 119.2825, "Samus"),
(66692, 12, 685.4288, 3504.569, 119.7825, "Samus"),
(66692, 13, 686.1788, 3507.819, 119.2825, "Samus"),
(66692, 14, 687.4288, 3509.069, 119.2825, "Samus"),
(66692, 15, 688.6788, 3509.069, 119.2825, "Samus"),
(66692, 16, 689.7587, 3507.822, 119.3489, "Samus"),
(66692, 17, 686.9368, 3512.142, 119.2397, "Samus"),
(66692, 18, 685.6868, 3517.142, 119.2397, "Samus"),
(66692, 19, 683.4368, 3521.142, 119.2397, "Samus"),
(66692, 20, 680.1868, 3522.392, 119.2397, "Samus"),
(66692, 21, 673.6868, 3520.892, 119.2397, "Samus"),
(66692, 22, 665.9368, 3519.642, 119.7397, "Samus"),
(66692, 23, 661.4368, 3517.392, 120.2397, "Samus"),
(66692, 24, 658.4368, 3511.142, 119.2397, "Samus"),
(66692, 25, 659.9368, 3506.642, 119.2397, "Samus"),
(66692, 26, 664.4368, 3497.892, 119.7397, "Samus"),
(66692, 27, 669.9368, 3495.392, 119.4897, "Samus"),
(66692, 28, 672.9368, 3496.392, 119.2397, "Samus"),
(66692, 29, 675.6868, 3499.392, 119.2397, "Samus"),
(66692, 30, 676.6868, 3502.642, 119.2397, "Samus"),
(66692, 31, 676.4368, 3505.392, 119.4897, "Samus"),
(66692, 32, 676.1868, 3508.142, 119.7397, "Samus"),
(66692, 33, 677.1868, 3510.642, 119.7397, "Samus"),
(66692, 34, 678.2136, 3512.823, 119.6324, "Samus"),
(66692, 35, 677.2275, 3512.108, 119.9241, "Samus"),
(66692, 36, 676.9775, 3510.358, 119.9241, "Samus"),
(66692, 37, 675.9775, 3508.608, 119.9241, "Samus"),
(66692, 38, 675.7275, 3506.858, 119.9241, "Samus"),
(66692, 39, 676.9775, 3504.108, 119.1741, "Samus"),
(66692, 40, 678.4775, 3502.358, 119.1741, "Samus"),
(66692, 41, 680.2275, 3501.358, 119.1741, "Samus"),
(66692, 42, 680.9775, 3497.358, 119.1741, "Samus");

-- Treesharper Shu
UPDATE `creature` SET `position_x` = 689.2361, `position_y` = 3503.391, `position_z` = 119.9525, `orientation` = 1.53589, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562777;

UPDATE `creature_template_addon` SET `path_id` = 562777 WHERE `entry` = 65037;

DELETE FROM `waypoint_data` WHERE `id` = 562777;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562777, 1, 686.5746, 3504.63, 119.7522, 0, 0, 0, 0, 100, 0, 65037),
(562777, 2, 686.5746, 3504.63, 119.7522, 0.5061455, 37000, 0, 0, 100, 0, 65037),
(562777, 3, 689.2361, 3503.391, 119.9525, 0, 0, 0, 0, 100, 0, 65037),
(562777, 4, 689.2361, 3503.391, 119.9525, 1.53589, 21000, 0, 0, 100, 0, 65037);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 65037;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 65037 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6503700, 6503701) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(65037, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 6503700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Treesharper Shu - MI 1 - Start Script"),
(65037, 0, 1, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 6503701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Treesharper Shu - MI 3 - Start Script"),

(6503700, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Treesharper Shu - On Script - Set Emote State (69)"),
(6503700, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 17, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Treesharper Shu - On Script - Clear Emote"),
(6503700, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Treesharper Shu - On Script - Play Emote (25)"),
(6503700, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 5, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Treesharper Shu - On Script - Play Emote (11)"),
(6503700, 9, 4, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 5, 404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Treesharper Shu - On Script - Play Emote (404)"),

(6503701, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Treesharper Shu - On Script - Play Emote (25)"),
(6503701, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Treesharper Shu - On Script - Set Emote State (69)"),
(6503701, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 17, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Treesharper Shu - On Script - Clear Emote");

-- Groundkeeper Shen
UPDATE `creature` SET `position_x` = 801.0035, `position_y` = 3632.609, `position_z` = 160.5113, `orientation` = 1.797689, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562753;

UPDATE `creature_template_addon` SET `path_id` = 562753 WHERE `entry` = 65088;

DELETE FROM `waypoint_data` WHERE `id` = 562753;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562753, 1, 793.4775, 3634.164, 160.5113, 0, 0, 0, 0, 100, 0, 65088),
(562753, 2, 790.5261, 3638.889, 160.5113, 0, 0, 0, 0, 100, 0, 65088),
(562753, 3, 790.6962, 3643.549, 160.5113, 0, 0, 0, 0, 100, 0, 65088),
(562753, 4, 792.6233, 3647.6, 160.5113, 5.585053, 20000, 0, 0, 100, 0, 65088),
(562753, 5, 801.6996, 3650.888, 160.5113, 0, 0, 0, 0, 100, 0, 65088),
(562753, 6, 805.7153, 3648.389, 160.5172, 3.839724, 17000, 0, 0, 100, 0, 65088),
(562753, 7, 800.2031, 3650.989, 160.5113, 0, 0, 0, 0, 100, 0, 65088),
(562753, 8, 794.257, 3649.206, 160.5113, 0, 0, 0, 0, 100, 0, 65088),
(562753, 9, 791.4861, 3645.849, 160.5113, 0, 0, 0, 0, 100, 0, 65088),
(562753, 10, 790.7587, 3641.228, 160.5113, 6.213372, 12000, 0, 0, 100, 0, 65088),
(562753, 11, 793.658, 3634.673, 160.5113, 0, 0, 0, 0, 100, 0, 65088),
(562753, 12, 796.7413, 3632.884, 160.5113, 0, 0, 0, 0, 100, 0, 65088),
(562753, 13, 801.0035, 3632.609, 160.5113, 1.797689, 16000, 0, 0, 100, 0, 65088);

-- Bai Hua
DELETE FROM `creature` WHERE `guid` = 562771 AND `id` = 65053;
DELETE FROM `creature_addon` WHERE `guid` = 562771;
UPDATE `creature` SET `position_x` = 740.3411, `position_y` = 3660.361, `position_z` = 154.1399, `orientation` = 4.331117, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562745;

UPDATE `creature_template_addon` SET `path_id` = 562745 WHERE `entry` = 65053;

DELETE FROM `waypoint_data` WHERE `id` = 562745;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562745, 1, 738.8229, 3656.574, 154.135, 0, 0, 0, 0, 100, 0, 65053),
(562745, 2, 738.0156, 3653.259, 154.134, 0, 0, 0, 0, 100, 0, 65053),
(562745, 3, 741.1893, 3651.445, 154.1361, 0, 0, 0, 0, 100, 0, 65053),
(562745, 4, 745.1597, 3650.274, 154.1321, 0, 0, 0, 0, 100, 0, 65053),
(562745, 5, 748.743, 3651.259, 154.137, 0, 0, 0, 0, 100, 0, 65053),
(562745, 6, 749.0729, 3653.79, 154.137, 0, 0, 0, 0, 100, 0, 65053),
(562745, 7, 747.6545, 3656.969, 154.137, 0, 0, 0, 0, 100, 0, 65053),
(562745, 8, 746.8368, 3660.22, 154.137, 0, 0, 0, 0, 100, 0, 65053),
(562745, 9, 746.6441, 3663.448, 154.137, 0, 0, 0, 0, 100, 0, 65053),
(562745, 10, 747.7535, 3668.372, 154.137, 0, 0, 0, 0, 100, 0, 65053),
(562745, 11, 748.5452, 3671.731, 154.137, 0, 6000, 0, 0, 100, 0, 65053),
(562745, 12, 747.408, 3666.984, 154.137, 0, 0, 0, 0, 100, 0, 65053),
(562745, 13, 749.0452, 3663.945, 154.137, 0, 0, 0, 0, 100, 0, 65053),
(562745, 14, 752.3577, 3662.122, 154.137, 0, 7000, 0, 0, 100, 0, 65053),
(562745, 15, 748.8958, 3667.003, 154.137, 0, 0, 0, 0, 100, 0, 65053),
(562745, 16, 747.6441, 3669.635, 154.137, 0, 0, 0, 0, 100, 0, 65053),
(562745, 17, 748.4688, 3672.794, 154.1367, 0, 6000, 0, 0, 100, 0, 65053),
(562745, 18, 741.9184, 3669.666, 154.137, 0, 0, 0, 0, 100, 0, 65053),
(562745, 19, 739.6614, 3665.217, 154.1382, 0, 0, 0, 0, 100, 0, 65053),
(562745, 20, 740.6823, 3661.212, 154.1402, 0, 0, 0, 0, 100, 0, 65053);

-- Yi
UPDATE `creature` SET `position_x` = 759.5868, `position_y` = 3661.885, `position_z` = 143.4947, `orientation` = 6.083785, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562767;

UPDATE `creature_template_addon` SET `path_id` = 562767 WHERE `entry` = 65047;

DELETE FROM `waypoint_data` WHERE `id` = 562767;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562767, 1, 755.9149, 3666.141, 143.4947, 0, 0, 0, 0, 100, 0, 65047),
(562767, 2, 754.533, 3668.841, 143.4959, 0, 0, 0, 0, 100, 0, 65047),
(562767, 3, 751.4566, 3671.986, 143.4925, 0, 8000, 0, 0, 100, 0, 65047),
(562767, 4, 753.7882, 3666.726, 143.3318, 0, 0, 0, 0, 100, 0, 65047),
(562767, 5, 753.1684, 3663.182, 143.3811, 3.089233, 8000, 0, 0, 100, 0, 65047),
(562767, 6, 759.5868, 3661.885, 143.4947, 0, 8000, 0, 0, 100, 0, 65047);

-- Er
UPDATE `creature` SET `position_x` = 737.5174, `position_y` = 3667.997, `position_z` = 143.3558, `orientation` = 2.70526, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562770;

UPDATE `creature_template_addon` SET `path_id` = 562770 WHERE `entry` = 65049;

DELETE FROM `waypoint_data` WHERE `id` = 562770;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562770, 1, 742.1788, 3667.747, 143.2641, 0, 0, 0, 0, 100, 0, 65049),
(562770, 2, 743.0903, 3666.567, 143.2641, 4.29351, 5500, 0, 0, 100, 0, 65049),
(562770, 3, 744.8993, 3670.722, 143.2641, 0, 8000, 0, 0, 100, 0, 65049),
(562770, 4, 737.6493, 3667.642, 143.2793, 0, 0, 0, 0, 100, 0, 65049),
(562770, 5, 736.5364, 3664.528, 143.4456, 0, 0, 0, 0, 100, 0, 65049),
(562770, 6, 737.9271, 3660.398, 143.2641, 0.7504916, 7000, 0, 0, 100, 0, 65049),
(562770, 7, 736.8559, 3665.128, 143.3748, 0, 0, 0, 0, 100, 0, 65049),
(562770, 8, 737.5174, 3667.997, 143.3558, 2.70526, 7500, 0, 0, 100, 0, 65049);

UPDATE `gameobject` SET `position_x` = 747.483, `position_y` = 3675.645, `position_z` = 143.2588, `orientation` = 1.361356, `rotation0` = 0, `rotation1` = 0, `rotation2` = 0.6293201, `rotation3` = 0.7771462 WHERE `guid` = 540335;
UPDATE `gameobject` SET `position_x` = 761.499, `position_y` = 3661.257, `position_z` = 142.6234, `orientation` = 1.361356, `rotation0` = 0, `rotation1` = 0, `rotation2` = 0.6293201, `rotation3` = 0.7771462 WHERE `guid` = 540372;

UPDATE `creature_template_addon` SET `auras` = "110846" WHERE `entry` IN (65248, 65070, 65059);
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (562763, 562789);
DELETE FROM `creature` WHERE `guid` = 562740 AND `id` = 65147;
DELETE FROM `creature_addon` WHERE `guid` = 562740;

-- Summer Lily
UPDATE `creature` SET `position_x` = 724.8507, `position_y` = 3576.906, `position_z` = 141.4816, `orientation` = 5.550147, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 562790;

UPDATE `creature_template_addon` SET `path_id` = 562790 WHERE `entry` = 65035;

DELETE FROM `waypoint_data` WHERE `id` = 562790;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(562790, 1, 728.8872, 3571.717, 141.2709, 0, 0, 0, 0, 100, 0, 65035),
(562790, 2, 733.8872, 3570.467, 141.0209, 0, 0, 0, 0, 100, 0, 65035),
(562790, 3, 741.6372, 3566.967, 141.0209, 0, 0, 0, 0, 100, 0, 65035),
(562790, 4, 743.1372, 3562.967, 141.0209, 0, 0, 0, 0, 100, 0, 65035),
(562790, 5, 744.3872, 3557.467, 140.7709, 0, 0, 0, 0, 100, 0, 65035),
(562790, 6, 745.8872, 3552.967, 140.7709, 0, 0, 0, 0, 100, 0, 65035),
(562790, 7, 749.3872, 3550.967, 140.5209, 0, 0, 0, 0, 100, 0, 65035),
(562790, 8, 753.1372, 3551.967, 141.2709, 0, 0, 0, 0, 100, 0, 65035),
(562790, 9, 759.4236, 3551.028, 141.5601, 0.9773844, 74000, 0, 0, 100, 0, 65035),
(562790, 10, 757.3872, 3550.217, 141.5209, 0, 0, 0, 0, 100, 0, 65035),
(562790, 11, 752.1372, 3551.717, 141.0209, 0, 0, 0, 0, 100, 0, 65035),
(562790, 12, 747.8872, 3552.467, 140.7709, 0, 0, 0, 0, 100, 0, 65035),
(562790, 13, 745.6372, 3554.967, 140.7709, 0, 0, 0, 0, 100, 0, 65035),
(562790, 14, 743.8872, 3560.967, 141.0209, 0, 0, 0, 0, 100, 0, 65035),
(562790, 15, 742.1372, 3565.967, 141.0209, 0, 0, 0, 0, 100, 0, 65035),
(562790, 16, 736.3872, 3569.717, 141.0209, 0, 0, 0, 0, 100, 0, 65035),
(562790, 17, 732.1372, 3571.717, 141.0209, 0, 0, 0, 0, 100, 0, 65035),
(562790, 18, 728.1372, 3574.217, 141.5209, 0, 0, 0, 0, 100, 0, 65035),
(562790, 19, 724.8507, 3576.906, 141.4816, 5.550147, 20000, 0, 0, 100, 0, 65035);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 65035;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 65035 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 6503500 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(65035, 0, 0, 0, 34, 0, 100, 0, 2, 8, 0, 0, 80, 6503500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Summer Lily - On MI 8 - Start Script"),

(6503500, 9, 0, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Summer Lily - On Script - Set Unit Field Bytes 1 (8)"),
(6503500, 9, 1, 0, 0, 0, 100, 0, 60000, 60000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Summer Lily - On Script - Set Unit Field Bytes 1 (0)"),
(6503500, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 5, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Summer Lily - On Script - Play Emote (2)");

UPDATE `creature_template_addon` SET `auras` = "99385" WHERE `entry` = 55685;

-- Shu
UPDATE `creature` SET `position_x` = 928.6078, `position_y` = 3602.659, `position_z` = 195.2873, `orientation` = 4.867653, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` IN (561812, 561707);

DELETE FROM `creature_addon` WHERE `guid` IN (561812, 561707, 561706, 561795, 561708, 561817);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`, `auras`) VALUES
(561812, 561812, 0, 1, "60921"),
(561707, 561707, 0, 1, "49415"),
(561706, 0, 50397184, 1, "49415"),
(561795, 0, 50397184, 1, "60921"),
(561708, 0, 3, 1, "49415"),
(561817, 0, 3, 1, "60921");

DELETE FROM `waypoint_data` WHERE `id` IN (561812, 561707);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(561812, 1, 929.0764, 3599.665, 195.4497, 0, 0, 1, 0, 100, 0, 60918),
(561812, 2, 928.6511, 3606.639, 195.3147, 0, 0, 1, 0, 100, 0, 60918),
(561812, 3, 929.3073, 3609.622, 195.3814, 0, 0, 1, 0, 100, 0, 60918),

(561707, 1, 929.0764, 3599.665, 195.4497, 0, 0, 1, 0, 100, 0, 60918),
(561707, 2, 928.6511, 3606.639, 195.3147, 0, 0, 1, 0, 100, 0, 60918),
(561707, 3, 929.3073, 3609.622, 195.3814, 0, 0, 1, 0, 100, 0, 60918);

-- Big Bertha
DELETE FROM `creature` WHERE `guid` IN (563641, 563642) AND `id` = 57853;
DELETE FROM `creature_addon` WHERE `guid` IN (563641, 563642);
UPDATE `creature` SET `position_x` = 582.2813, `position_y` = 3123.172, `position_z` = 89.2438, `orientation` = 2.268393 WHERE `guid` = 563622;

-- Nourished Yak & Delivery Cart
DELETE FROM `conditions` WHERE `SourceEntry` IN (108877, 108878) AND `SourceGroup` = 1 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 108877, 0, 1, 31, 0, 3, 59499, 0, 0, 0, 0, "", "Ox Cart Rope Left target Nourished Yak"),
(13, 1, 108877, 0, 0, 31, 0, 3, 57709, 0, 0, 0, 0, "", "Ox Cart Rope Left target Nourished Yak"),
(13, 1, 108878, 0, 0, 31, 0, 3, 57710, 0, 0, 0, 0, "", "Ox Cart Rope Right target Delivery Cart"),
(13, 1, 108878, 0, 1, 31, 0, 3, 59497, 0, 0, 0, 0, "", "Ox Cart Rope Right target Delivery Cart");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (59497, 57710);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (59497, 57710) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (5949700, 5771000) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(59497, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, 5949700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Delivery Cart - On Respawn - Start Script"),
(59497, 0, 1, 0, 31, 0, 100, 0, 108877, 0, 0, 0, 85, 108878, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Delivery Cart - On Spellhit Target - Invoker Cast Ox Cart Rope Right"),
(5949700, 9, 0, 0, 0, 0, 100, 0, 500, 500, 0, 0, 11, 108877, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Delivery Cart - Cast Ox Cart Rope Left"),

(57710, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 80, 5771000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Delivery Cart - On Respawn - Start Script"),
(57710, 0, 1, 0, 31, 0, 100, 0, 108877, 0, 0, 0, 85, 108878, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Delivery Cart - On Spellhit Target - Invoker Cast Ox Cart Rope Right"),
(5771000, 9, 0, 0, 0, 0, 100, 0, 500, 500, 0, 0, 11, 108877, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Delivery Cart - Cast Ox Cart Rope Left");

UPDATE `creature` SET `wander_distance` = 50, `walk_mode` = 1 WHERE `id` = 64442;

-- Water Pincer
UPDATE `creature_template_addon` SET `auras` = "116552" WHERE `entry` = 60411;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 60411 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(60411, 0, 0, 0, 0, 0, 100, 0, 2700, 3600, 18000, 18000, 11, 128448, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Water Pincer - In Combat - Cast Phlogiston"),
(60411, 0, 1, 0, 1, 0, 100, 0, 2000, 10000, 8000, 10000, 128, 2354, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Water Pincer - OOC - Play Anim Kit");

UPDATE `creature_template` SET `health_mod` = 272, `mana_mod` = 1 WHERE `entry` = 56007;
UPDATE `creature_template` SET `health_mod` = 1 WHERE `entry` = 56008;
