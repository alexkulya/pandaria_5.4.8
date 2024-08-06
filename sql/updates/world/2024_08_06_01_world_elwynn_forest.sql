UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178007;

UPDATE `creature` SET `position_x` = -9946.83, `position_y` = 408.503, `position_z` = 34.8925, `orientation` = 2.41407 WHERE `guid` = 180100;

UPDATE `creature_addon` SET `auras` = "87519" WHERE `guid` = 180100;

DELETE FROM `waypoint_data` WHERE `id` = 180100;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`) VALUES
(180100, 1, -9946.83, 408.503, 34.8925, 0, 0, 0),
(180100, 2, -9934.89, 375.823, 35.16, 0, 0, 0),
(180100, 3, -9905.29, 378.352, 35.2861, 0, 0, 0),
(180100, 4, -9889.87, 404.354, 35.3951, 0, 0, 0),
(180100, 5, -9911.25, 423.392, 35.3978, 0, 0, 0);

UPDATE `creature` SET `wander_distance` = 10, `movement_type` = 1 WHERE `id` = 822;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 822);
DELETE FROM `waypoint_data` WHERE `id` IN (179695, 179986, 180006, 180473, 179471, 180181);

DELETE FROM `creature` WHERE `guid` IN (4413, 127222);
