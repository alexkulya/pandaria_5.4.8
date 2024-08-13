DELETE FROM `creature_equip_template` WHERE `entry` = 63327;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(63327, 1, 79721, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry` = 63327;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES
(63327, 4097, 118348);
