UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` IN (30, 113);
UPDATE `creature_template` SET `unit_flags` = 32768, `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 44016;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 44016 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(44016, 0, 0, 0, 2, 0, 100, 0, 0, 45, 31000, 31000, 11, 84868, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Coalpelt Bear - At 45% - Cast Spell 'Hibernate'"),
(44016, 0, 1, 0, 0, 0, 100, 0, 4000, 5000, 6000, 6000, 11, 31279, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Coalpelt Bear - In Combat - Cast Spell 'Swipe'");

DELETE FROM `creature` WHERE `guid` IN (171439, 171500, 171512, 171529, 171601, 171602, 171603, 171604, 172109, 172110,
                                        172231, 172221, 172220, 172219, 172217, 172215, 172203, 172180, 172222, 172177,
                                        172162, 172111, 172142, 172145, 172157, 172158, 214985, 172223, 172234, 214992,
                                        172236, 172244, 171797, 172470, 172468, 172467) AND `id` = 44016;

UPDATE `creature` SET `position_x` = -10749.2, `position_y` = 578.261, `position_z` = 28.2365, `orientation` = 3.23728, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 171220;
UPDATE `creature` SET `position_x` = -11066, `position_y` = 306.54, `position_z` = 28.0845, `orientation` = 3.29068, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 171605;
UPDATE `creature` SET `position_x` = -10256.5, `position_y` = 294.781, `position_z` = 42.1415, `orientation` = 0.88126, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 171606;
UPDATE `creature` SET `position_x` = -10144, `position_y` = 313.165, `position_z` = 25.3086, `orientation` = 1.80194, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 171607;
UPDATE `creature` SET `position_x` = -10177.9, `position_y` = 222.771, `position_z` = 23.2057, `orientation` = 3.89604, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 171785;
UPDATE `creature` SET `position_x` = -11164.5, `position_y` = 271.864, `position_z` = 36.3499, `orientation` = 0.901757, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 171801;
UPDATE `creature` SET `position_x` = -10381.6, `position_y` = 624.12, `position_z` = 30.4572, `orientation` = 1.26135, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 171804;
UPDATE `creature` SET `position_x` = -10365.7, `position_y` = 681.789, `position_z` = 24.1778, `orientation` = 2.37553, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 171806;
UPDATE `creature` SET `position_x` = -10541.2, `position_y` = 623.57, `position_z` = 24.1149, `orientation` = 1.78312, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 171810;
UPDATE `creature` SET `position_x` = -10506.3, `position_y` = 559.224, `position_z` = 24.3816, `orientation` = 1.14627, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 171908;
UPDATE `creature` SET `position_x` = -10439, `position_y` = 490.883, `position_z` = 32.7908, `orientation` = 5.44915, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172108;
UPDATE `creature` SET `position_x` = -10426.5, `position_y` = 622.256, `position_z` = 24.9865, `orientation` = 4.39064, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172232;
UPDATE `creature` SET `position_x` = -10409.7, `position_y` = 568.857, `position_z` = 31.0173, `orientation` = 3.5442, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172235;
UPDATE `creature` SET `position_x` = -10758.4, `position_y` = 399.865, `position_z` = 38.1991, `orientation` = 5.48398, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172237;
UPDATE `creature` SET `position_x` = -10894.5, `position_y` = 397.866, `position_z` = 44.3213, `orientation` = 1.43553, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172238;
UPDATE `creature` SET `position_x` = -11002, `position_y` = 421.507, `position_z` = 37.5008, `orientation` = 0.138255, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172240;
UPDATE `creature` SET `position_x` = -10963.8, `position_y` = 379.322, `position_z` = 39.6928, `orientation` = 2.86209, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172241;
UPDATE `creature` SET `position_x` = -10177.5, `position_y` = 404.323, `position_z` = 35.2134, `orientation` = 1.30266, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172242;
UPDATE `creature` SET `position_x` = -11087.2, `position_y` = 387.17, `position_z` = 24.568, `orientation` = 3.34544, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172243;
UPDATE `creature` SET `position_x` = -10307.3, `position_y` = 558.12, `position_z` = 44.4986, `orientation` = 5.87156, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172245;
UPDATE `creature` SET `position_x` = -10238.8, `position_y` = 587.273, `position_z` = 21.9886, `orientation` = 2.39209, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172246;
UPDATE `creature` SET `position_x` = -10264.8, `position_y` = 636.977, `position_z` = 26.0427, `orientation` = 3.99717, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172247;
UPDATE `creature` SET `position_x` = -10543.3, `position_y` = 494.483, `position_z` = 30.4535, `orientation` = 1.83379, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172248;
UPDATE `creature` SET `position_x` = -10561.6, `position_y` = 582.028, `position_z` = 30.067, `orientation` = 1.8277, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172249;
UPDATE `creature` SET `position_x` = -10658.5, `position_y` = 589.504, `position_z` = 23.366, `orientation` = 4.6518, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172250;
UPDATE `creature` SET `position_x` = -10655, `position_y` = 539.321, `position_z` = 27.1639, `orientation` = 4.95715, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172251;
UPDATE `creature` SET `position_x` = -10705.1, `position_y` = 515.205, `position_z` = 32.7354, `orientation` = 4.86781, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172252;
UPDATE `creature` SET `position_x` = -10681.7, `position_y` = 459.373, `position_z` = 38.7668, `orientation` = 2.80133, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172254;
UPDATE `creature` SET `position_x` = -10745.1, `position_y` = 579.244, `position_z` = 28.0139, `orientation` = 3.24268, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172289;
UPDATE `creature` SET `position_x` = -10805.2, `position_y` = 496.406, `position_z` = 33.4325, `orientation` = 5.83254, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172469;
UPDATE `creature` SET `position_x` = -10882.3, `position_y` = 519.373, `position_z` = 35.3935, `orientation` = 1.79971, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172472;
UPDATE `creature` SET `position_x` = -10979.7, `position_y` = 515.994, `position_z` = 28.3482, `orientation` = 3.90581, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172473;
UPDATE `creature` SET `position_x` = -10926.7, `position_y` = 508.487, `position_z` = 38.0037, `orientation` = 6.24768, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172474;
UPDATE `creature` SET `position_x` = -10940.7, `position_y` = 540.998, `position_z` = 31.0958, `orientation` = 4.59643, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 172475;
UPDATE `creature` SET `position_x` = -10952.4, `position_y` = 467.112, `position_z` = 43.4551, `orientation` = 5.49743, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 177712;
UPDATE `creature` SET `position_x` = -10881.2, `position_y` = 435.431, `position_z` = 45.342, `orientation` = 2.10262, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 177713;
UPDATE `creature` SET `position_x` = -10622.2, `position_y` = 441.148, `position_z` = 34.5614, `orientation` = 6.26179, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 177758;
UPDATE `creature` SET `position_x` = -10424.2, `position_y` = 476.354, `position_z` = 38.2472, `orientation` = 3.93528, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 179616;
UPDATE `creature` SET `position_x` = -10331.2, `position_y` = 443.506, `position_z` = 58.2217, `orientation` = 5.94476, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 179972;
UPDATE `creature` SET `position_x` = -10294, `position_y` = 451.869, `position_z` = 49.523, `orientation` = 4.77502, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 180156;
UPDATE `creature` SET `position_x` = -10246.2, `position_y` = 459.783, `position_z` = 40.5084, `orientation` = 2.76011, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 180325;
UPDATE `creature` SET `position_x` = -10225.5, `position_y` = 502.251, `position_z` = 26.8212, `orientation` = 4.71338, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 180326;
UPDATE `creature` SET `position_x` = -10869.9, `position_y` = 348.04, `position_z` = 41.6147, `orientation` = 1.60789, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 180335;
UPDATE `creature` SET `position_x` = -10150.5, `position_y` = 419.527, `position_z` = 28.5655, `orientation` = 4.90481, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 180341;
UPDATE `creature` SET `position_x` = -10215.4, `position_y` = 315.33, `position_z` = 35.7168, `orientation` = 2.29679, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 214951;
UPDATE `creature` SET `position_x` = -10262.8, `position_y` = 188.342, `position_z` = 34.9351, `orientation` = 3.70143, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 214953;
UPDATE `creature` SET `position_x` = -10229.9, `position_y` = 161.549, `position_z` = 30.9711, `orientation` = 3.40836, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 214983;
UPDATE `creature` SET `position_x` = -10198.7, `position_y` = 115.645, `position_z` = 30.11, `orientation` = 5.41335, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 215916;
UPDATE `creature` SET `position_x` = -10241.2, `position_y` = 91.4789, `position_z` = 36.5695, `orientation` = 1.99483, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 215917;
UPDATE `creature` SET `position_x` = -10211.2, `position_y` = 35.4103, `position_z` = 33.519, `orientation` = 5.09652, `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 215920;

DELETE FROM `creature_addon` WHERE `guid` IN (171220, 171439, 171500, 171512, 171529, 171601, 171602, 171603, 171604, 171605, 171606, 171607,
                                              171785, 171797, 171801, 171804, 171806, 171810, 171908, 172108, 172109, 172110, 172111, 172142,
                                              172145, 172157, 172158, 172162, 172177, 172180, 172203, 172215, 172217, 172219, 172220, 172221,
                                              172222, 172223, 172231, 172232, 172234, 172235, 172236, 172237, 172238, 172240, 172241, 172242,
                                              172243, 172244, 172245, 172246, 172247, 172248, 172249, 172250, 172251, 172252, 172254, 172289,
                                              172467, 172468, 172469, 172470, 172472, 172473, 172474, 172475, 177712, 177713, 177758, 179616,
                                              179972, 180156, 180325, 180326, 180335, 180341, 214951, 214953, 214983, 214985, 214992, 215916,
                                              215917, 215920);
DELETE FROM `waypoint_data` WHERE `id` IN (214985, 172223, 172234, 214992, 172236, 172244, 171797, 172470, 172468, 172467);
