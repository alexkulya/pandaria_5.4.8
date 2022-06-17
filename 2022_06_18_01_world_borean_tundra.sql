UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 95761;

DELETE FROM `creature_addon` WHERE `guid` = 95761;
INSERT INTO `creature_addon` (`guid`, `path_id`) VALUES
(95761, 95761);

DELETE FROM `waypoint_data` WHERE `id` = 95761;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `entry`) VALUES
(95761, 1, 3214.44, 5288.57, 47.3736, 0, 0, 0, 25812),
(95761, 2, 3221.93, 5276.38, 47.1691, 0, 0, 0, 25812),
(95761, 3, 3212.27, 5268.29, 47.552, 0, 0, 0, 25812),
(95761, 4, 3201.68, 5270, 47.6342, 0, 0, 0, 25812),
(95761, 5, 3195.56, 5278.42, 47.8828, 0, 0, 0, 25812),
(95761, 6, 3200.25, 5292.06, 47.6622, 0, 0, 0, 25812);
