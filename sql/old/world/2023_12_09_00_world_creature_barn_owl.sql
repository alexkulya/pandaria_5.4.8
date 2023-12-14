UPDATE `creature_template` SET `unit_flags` = 32768, `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 44020;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 44020 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(44020, 0, 0, 0, 0, 0, 100, 0, 18000, 19000, 20000, 21000, 11, 49865, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Barn Owl - In Combat - Cast Spell 'Eye Peck'"),
(44020, 0, 1, 0, 0, 0, 100, 0, 25000, 26000, 20000, 21000, 11, 81680, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Barn Owl - In Combat - Cast Spell 'Howling Screech'");

DELETE FROM `creature` WHERE `guid` IN (171931, 171937, 171938, 171939, 171940, 171941, 171942, 171943, 171949, 171950,
                                        171951, 171952, 171953, 171954, 171955, 171956, 171959, 171960, 171961, 171962,
                                        171963, 171964, 172128, 172140, 172156, 172173, 172174, 172182, 172183, 172214,
                                        172496, 177610, 177627, 179586, 179965, 180309, 180316, 180332, 214478, 214576,
                                        214604, 214605, 214634, 214800, 214823, 214824, 215522, 215615, 216010) AND `id` = 44020;

UPDATE `creature` SET `position_x` = -11092.1, `position_y` = 327.147, `position_z` = 30.9983, `orientation` = 4.86667, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 170932;
UPDATE `creature` SET `position_x` = -10836.5, `position_y` = 243.523, `position_z` = 37.4252, `orientation` = 2.34496, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 170933;
UPDATE `creature` SET `position_x` = -10260.9, `position_y` = 256.517, `position_z` = 35.7884, `orientation` = 3.53249, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 170939;
UPDATE `creature` SET `position_x` = -10203.1, `position_y` = 277.432, `position_z` = 25.2267, `orientation` = 5.01807, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171178;
UPDATE `creature` SET `position_x` = -10225.1, `position_y` = 217.867, `position_z` = 23.112, `orientation` = 1.62358, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171179;
UPDATE `creature` SET `position_x` = -11145.7, `position_y` = 287.519, `position_z` = 38.9817, `orientation` = 4.58511, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171180;
UPDATE `creature` SET `position_x` = -11092.9, `position_y` = 270.095, `position_z` = 30.1158, `orientation` = 2.22174, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171181;
UPDATE `creature` SET `position_x` = -11156.8, `position_y` = 231.748, `position_z` = 35.3839, `orientation` = 5.20888, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171182;
UPDATE `creature` SET `position_x` = -11069.7, `position_y` = 212.959, `position_z` = 26.9307, `orientation` = 3.11305, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171194;
UPDATE `creature` SET `position_x` = -10420.4, `position_y` = 671.064, `position_z` = 26.59, `orientation` = 0.0527885, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171195;
UPDATE `creature` SET `position_x` = -10493.8, `position_y` = 524.102, `position_z` = 27.7739, `orientation` = 4.48208, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171203;
UPDATE `creature` SET `position_x` = -10478.6, `position_y` = 608.81, `position_z` = 23.227, `orientation` = 1.40019, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171204;
UPDATE `creature` SET `position_x` = -10451.5, `position_y` = 545.599, `position_z` = 26.4782, `orientation` = 3.98352, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171205;
UPDATE `creature` SET `position_x` = -10351.8, `position_y` = 497.321, `position_z` = 39.4612, `orientation` = 6.27928, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171206;
UPDATE `creature` SET `position_x` = -10704.5, `position_y` = 408.63, `position_z` = 36.1994, `orientation` = 1.69999, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171221;
UPDATE `creature` SET `position_x` = -10736.2, `position_y` = 423.721, `position_z` = 42.9241, `orientation` = 2.32063, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171222;
UPDATE `creature` SET `position_x` = -10855, `position_y` = 381.238, `position_z` = 39.7532, `orientation` = 2.9745, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171223;
UPDATE `creature` SET `position_x` = -10655.2, `position_y` = 371.754, `position_z` = 37.3132, `orientation` = 1.33472, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171224;
UPDATE `creature` SET `position_x` = -10176.8, `position_y` = 460.894, `position_z` = 27.8758, `orientation` = 3.27178, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171232;
UPDATE `creature` SET `position_x` = -10213.2, `position_y` = 377.401, `position_z` = 44.8311, `orientation` = 5.59869, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171233;
UPDATE `creature` SET `position_x` = -11042.6, `position_y` = 370.268, `position_z` = 32.7852, `orientation` = 3.40128, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171234;
UPDATE `creature` SET `position_x` = -10396.2, `position_y` = 513.394, `position_z` = 36.043, `orientation` = 5.77565, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171242;
UPDATE `creature` SET `position_x` = -10316.1, `position_y` = 519.208, `position_z` = 38.8129, `orientation` = 5.69598, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171243;
UPDATE `creature` SET `position_x` = -10252.6, `position_y` = 540.51 , `position_z` = 29.9742, `orientation` = 4.12861, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171244;
UPDATE `creature` SET `position_x` = -10308.9, `position_y` = 672.858, `position_z` = 24.0616, `orientation` = 1.97427, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171245;
UPDATE `creature` SET `position_x` = -10276.5, `position_y` = 492.319, `position_z` = 34.3685, `orientation` = 2.77663, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171246;
UPDATE `creature` SET `position_x` = -10598.9, `position_y` = 542.694, `position_z` = 30.3755, `orientation` = 2.35619, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171251;
UPDATE `creature` SET `position_x` = -10640.5, `position_y` = 491.567, `position_z` = 36.1411, `orientation` = 1.42942, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171252;
UPDATE `creature` SET `position_x` = -10589.6, `position_y` = 458.616, `position_z` = 36.7467, `orientation` = 4.97036, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171253;
UPDATE `creature` SET `position_x` = -10597.4, `position_y` = 596.219, `position_z` = 28.9258, `orientation` = 5.58492, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171254;
UPDATE `creature` SET `position_x` = -10737.9, `position_y` = 496.141, `position_z` = 35.7057, `orientation` = 4.19979, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171255;
UPDATE `creature` SET `position_x` = -10693.5, `position_y` = 556.163, `position_z` = 30.2817, `orientation` = 2.81421, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171492;
UPDATE `creature` SET `position_x` = -10784.3, `position_y` = 540.193, `position_z` = 32.1682, `orientation` = 4.10431, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171528;
UPDATE `creature` SET `position_x` = -10768.6, `position_y` = 469.163, `position_z` = 34.9075, `orientation` = 6.26952, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171600;
UPDATE `creature` SET `position_x` = -10823.7, `position_y` = 572.226, `position_z` = 32.1548, `orientation` = 1.35306, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171884;
UPDATE `creature` SET `position_x` = -10895.6, `position_y` = 569.981, `position_z` = 30.1, `orientation` = 2.24263, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171885;
UPDATE `creature` SET `position_x` = -10876.3, `position_y` = 473.113, `position_z` = 39.6325, `orientation` = 3.41794, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171886;
UPDATE `creature` SET `position_x` = -11024.8, `position_y` = 475.149, `position_z` = 24.3342, `orientation` = 3.69184, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171887;
UPDATE `creature` SET `position_x` = -10946.2, `position_y` = 436.397, `position_z` = 46.8241, `orientation` = 4.94683, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171888;
UPDATE `creature` SET `position_x` = -10918.7, `position_y` = 457.107, `position_z` = 45.0014, `orientation` = 3.70417, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171889;
UPDATE `creature` SET `position_x` = -10918.8, `position_y` = 431.366, `position_z` = 44.4238, `orientation` = 1.8212, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171890;
UPDATE `creature` SET `position_x` = -10352.9, `position_y` = 571.308, `position_z` = 37.3389, `orientation` = 4.71021, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171891;
UPDATE `creature` SET `position_x` = -10373.8, `position_y` = 458.52, `position_z` = 51.7931, `orientation` = 4.47593, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171892;
UPDATE `creature` SET `position_x` = -10276.3, `position_y` = 409.374, `position_z` = 59.0395, `orientation` = 1.90761, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171899;
UPDATE `creature` SET `position_x` = -10219.2, `position_y` = 423.649, `position_z` = 42.4366, `orientation` = 4.13847, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171900;
UPDATE `creature` SET `position_x` = -11053.7, `position_y` = 435.479, `position_z` = 25.9636, `orientation` = 0.125324, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171901;
UPDATE `creature` SET `position_x` = -10178, `position_y` = 356.935, `position_z` = 34.0344, `orientation` = 4.87722, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171902;
UPDATE `creature` SET `position_x` = -10129.7, `position_y` = 372.014, `position_z` = 30.3331, `orientation` = 3.43062, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171903;
UPDATE `creature` SET `position_x` = -10851.6, `position_y` = 156.496, `position_z` = 42.0976, `orientation` = 6.21675, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171904;
UPDATE `creature` SET `position_x` = -10187.2, `position_y` = 163.189, `position_z` = 25.9815, `orientation` = 2.31255, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171905;
UPDATE `creature` SET `position_x` = -10255.7, `position_y` = 127.83, `position_z` = 35.5204, `orientation` = 4.97844, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171909;
UPDATE `creature` SET `position_x` = -10908.5, `position_y` = 131.669, `position_z` = 36.9115, `orientation` = 6.27147, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171910;
UPDATE `creature` SET `position_x` = -10795.5, `position_y` = 118.032, `position_z` = 46.6111, `orientation` = 2.44204, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171911;
UPDATE `creature` SET `position_x` = -10175.8, `position_y` = 74.9904, `position_z` = 24.5154, `orientation` = 5.87446, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171912;
UPDATE `creature` SET `position_x` = -10244.5, `position_y` = 22.9415, `position_z` = 44.1283, `orientation` = 4.79616, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171913;
UPDATE `creature` SET `position_x` = -10866.4, `position_y` = 67.7287, `position_z` = 43.3778, `orientation` = 6.06732, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171914;
UPDATE `creature` SET `position_x` = -10789, `position_y` = 36.4656, `position_z` = 32.5121, `orientation` = 3.90211, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171915;
UPDATE `creature` SET `position_x` = -10917.4, `position_y` = 45.3161, `position_z` = 51.6215, `orientation` = 3.24729, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171922;
UPDATE `creature` SET `position_x` = -10806, `position_y` = -2.32227, `position_z` = 32.4222, `orientation` = 0.446182, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171923;
UPDATE `creature` SET `position_x` = -10830.6, `position_y` = -78.263, `position_z` = 41.0458, `orientation` = 3.9726, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171924;
UPDATE `creature` SET `position_x` = -10845.4, `position_y` = -137.437, `position_z` = 34.6752, `orientation` = 3.33024, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171925;
UPDATE `creature` SET `position_x` = -10802.8, `position_y` = -139.411, `position_z` = 30.6557, `orientation` = 0.013671, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171926;
UPDATE `creature` SET `position_x` = -10873.4, `position_y` = -197.87, `position_z` = 37.6833, `orientation` = 2.93747, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171927;
UPDATE `creature` SET `position_x` = -10900.6, `position_y` = -271.183, `position_z` = 41.1659, `orientation` = 6.2539, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171928;
UPDATE `creature` SET `position_x` = -11029.1, `position_y` = -337.654, `position_z` = 42.9916, `orientation` = 0.90617, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171929;
UPDATE `creature` SET `position_x` = -10989, `position_y` = -326.005, `position_z` = 38.5141, `orientation` = 0.00991157, `wander_distance` = 7, `movement_type` = 1 WHERE `guid` = 171930;

DELETE FROM `creature_addon` WHERE `guid` IN (171912, 171939, 171940, 171942, 171943, 171949, 171950, 171951, 171953, 171954, 171955, 171956,
                                              171938, 171937, 171913, 171914, 171915, 171922, 171923, 171925, 171926, 171927, 171928, 171929,
                                              171931, 171959, 171960, 171962, 180309, 180316, 180332, 214478, 214576, 214604, 214634, 214800,
                                              214823, 215522, 215615, 179965, 179586, 171963, 171964, 172128, 172140, 172156, 172173, 172174,
                                              172182, 172496, 177610, 177627, 216010, 170933, 171224, 171232, 171234, 171242, 171243, 171244,
                                              171245, 171246, 170932, 171251, 171252, 171223, 171222, 171221, 170939, 171178, 171179, 171180,
                                              171181, 171182, 171195, 171203, 171204, 171205, 171206, 171253, 171254, 171903, 171909, 171905,
                                              171890, 171891, 171904, 171892, 171941, 171900, 171901, 171902, 171889, 171888, 171492, 171233,
                                              171528, 171600, 171884, 171885, 171886, 171911, 171910, 214824, 171961, 171255, 171924, 171194,
                                              171930, 172214, 172183, 171952, 171887, 171899, 214605);
DELETE FROM `waypoint_data` WHERE `id` IN (214824, 171961, 171255, 171924, 171194, 171930, 172214, 172183, 171952, 171887, 171899, 214605);
