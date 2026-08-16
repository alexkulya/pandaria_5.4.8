UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 276680;
UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` IN (1995, 1998, 2032, 2042);
