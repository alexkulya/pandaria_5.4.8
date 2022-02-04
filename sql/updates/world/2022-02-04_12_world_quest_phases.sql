/*
Navicat MySQL Data Transfer

Source Server         : localhost_3306
Source Server Version : 50736
Source Host           : localhost:3306
Source Database       : test

Target Server Type    : MYSQL
Target Server Version : 50736
File Encoding         : 65001

Date: 2022-02-4 12:24:10
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for `world_quest_phases`
-- ----------------------------
DROP TABLE IF EXISTS `world_quest_phases`;
CREATE TABLE `world_quest_phases` (
  `QuestId` mediumint(8) NOT NULL,
  `Phase` int(10) unsigned NOT NULL DEFAULT '0',
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT '0 on quest fail 1 on quest accept 2 on quest reward 3 on quest complete',
  `MapId` int(5) unsigned DEFAULT '0' COMMENT 'Add correct MapID for phase switch',
  `ZoneId` int(5) unsigned DEFAULT '0' COMMENT 'Add correct ZoneID for phase switch',
  `AreaId` int(5) unsigned DEFAULT '0' COMMENT 'Add correct AreaID for phase switch',
  `Comment` text
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Achievment system';
