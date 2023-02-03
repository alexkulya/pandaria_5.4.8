ALTER TABLE `gossip_menu_option` DROP COLUMN `OptionBroadcastTextID`;
ALTER TABLE `gossip_menu_option` DROP COLUMN `BoxBroadcastTextID`;
ALTER TABLE `npc_text` DROP COLUMN `BroadcastTextID0`;
ALTER TABLE `npc_text` DROP COLUMN `BroadcastTextID1`;
ALTER TABLE `npc_text` DROP COLUMN `BroadcastTextID2`;
ALTER TABLE `npc_text` DROP COLUMN `BroadcastTextID3`;
ALTER TABLE `npc_text` DROP COLUMN `BroadcastTextID4`;
ALTER TABLE `npc_text` DROP COLUMN `BroadcastTextID5`;
ALTER TABLE `npc_text` DROP COLUMN `BroadcastTextID6`;
ALTER TABLE `npc_text` DROP COLUMN `BroadcastTextID7`;
ALTER TABLE `creature_text` DROP COLUMN `BroadcastTextId`;
ALTER TABLE `trinity_string` DROP COLUMN `BroadcastTextID`;

ALTER TABLE `creature` CHANGE COLUMN `spawndist` `wander_distance` FLOAT NOT NULL DEFAULT "0" AFTER `spawntimesecs_max`;
ALTER TABLE `creature` CHANGE COLUMN `MovementType` `movement_type` TINYINT(3) unsigned NOT NULL DEFAULT "0" AFTER `curmana`;
ALTER TABLE `creature_text` CHANGE COLUMN `groupid` `text_group` TINYINT(3) unsigned NOT NULL DEFAULT "0" AFTER `entry`;
ALTER TABLE `creature_text` CHANGE COLUMN `TextRange` `text_range` TINYINT(3) unsigned NOT NULL DEFAULT "0" AFTER `text_female`;
ALTER TABLE `locales_creature_text` CHANGE COLUMN `groupid` `text_group` TINYINT(3) unsigned NOT NULL DEFAULT "0" AFTER `entry`;

DELETE FROM `command` WHERE `name` IN ("npc set spawndist", "npc set wanderdistance");
INSERT INTO `command` (`name`, `security`, `help`) VALUES
("npc set wanderdistance", 5, "Syntax: .npc set wanderdistance #dist\r\n\r\nAdjust wander distance of selected creature to dist.");

UPDATE `trinity_string` SET `content_default` = "Wander distance changed to: %f", `content_loc8` = "Дистанция брождения изменена на: %f" WHERE `entry` = 297;

DROP TABLE IF EXISTS `creature_sparring_template`;
CREATE TABLE `creature_sparring_template` (
  `creature_id` mediumint(8) unsigned NOT NULL,
  `health_limit_pct` float DEFAULT "0",
  `comment` varchar(255) DEFAULT "",
  PRIMARY KEY (`creature_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE `creature` ADD COLUMN `walk_mode` FLOAT unsigned NOT NULL DEFAULT "0";

ALTER TABLE `creature` ADD COLUMN `ScriptName` CHAR(64) NULL DEFAULT "" AFTER `dynamicflags`;
ALTER TABLE `gameobject` ADD COLUMN `ScriptName` CHAR(64) NULL DEFAULT "" AFTER `state`;

ALTER TABLE `creature_addon`
  ADD `ai_anim_kit` SMALLINT NOT NULL DEFAULT 0 AFTER `emote`,
  ADD `movement_anim_kit` SMALLINT NOT NULL DEFAULT 0 AFTER `ai_anim_kit`,
  ADD `melee_anim_kit` SMALLINT NOT NULL DEFAULT 0 AFTER `movement_anim_kit`;
ALTER TABLE `creature_template_addon`
  ADD `ai_anim_kit` SMALLINT NOT NULL DEFAULT 0 AFTER `emote`,
  ADD `movement_anim_kit` SMALLINT NOT NULL DEFAULT 0 AFTER `ai_anim_kit`,
  ADD `melee_anim_kit` SMALLINT NOT NULL DEFAULT 0 AFTER `movement_anim_kit`;

DROP TABLE IF EXISTS `world_map_template`;
CREATE TABLE `world_map_template`(
    `mapID` INT(11) UNSIGNED NOT NULL DEFAULT "0",
    `ScriptName` TEXT,
    PRIMARY KEY (`mapID`));

DROP TABLE IF EXISTS `holiday_dates`;
CREATE TABLE `holiday_dates` (
  `id` INT UNSIGNED NOT NULL,
  `date_id` TINYINT UNSIGNED NOT NULL,
  `date_value` INT UNSIGNED NOT NULL,
  `holiday_duration` INT(10) UNSIGNED NOT NULL,
  PRIMARY KEY (`id`, `date_id`)
);

ALTER TABLE `game_event` ADD COLUMN `holidayStage` TINYINT UNSIGNED NOT NULL DEFAULT "0" AFTER `holiday`;

ALTER TABLE `creature_template`
CHANGE COLUMN `name` `name` CHAR(100) NOT NULL DEFAULT "",
CHANGE COLUMN `femaleName` `femaleName` CHAR(100) NOT NULL DEFAULT "";
UPDATE `creature_template` SET `femaleName` = "" WHERE `femaleName` = 0;
