/*
SQLyog Ultimate v13.1.1 (64 bit)
MySQL - 10.5.8-MariaDB : Database - ofi_characters
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
/*Table structure for table `account_achievement` */

DROP TABLE IF EXISTS `account_achievement`;

CREATE TABLE `account_achievement` (
  `account` int(10) unsigned NOT NULL,
  `guid` int(10) unsigned NOT NULL,
  `achievement` smallint(5) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`account`,`achievement`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_achievement` */

/*Table structure for table `account_achievement_progress` */

DROP TABLE IF EXISTS `account_achievement_progress`;

CREATE TABLE `account_achievement_progress` (
  `account` int(10) unsigned NOT NULL,
  `criteria` smallint(5) unsigned NOT NULL,
  `counter` bigint(20) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`account`,`criteria`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_achievement_progress` */

/*Table structure for table `account_battle_pet` */

DROP TABLE IF EXISTS `account_battle_pet`;

CREATE TABLE `account_battle_pet` (
  `id` bigint(20) unsigned NOT NULL DEFAULT 0,
  `accountId` int(10) unsigned NOT NULL DEFAULT 0,
  `species` smallint(5) unsigned NOT NULL DEFAULT 0,
  `nickname` varchar(16) NOT NULL DEFAULT '',
  `timestamp` int(10) unsigned NOT NULL DEFAULT 0,
  `level` tinyint(3) unsigned NOT NULL DEFAULT 1,
  `xp` smallint(5) unsigned NOT NULL DEFAULT 0,
  `health` smallint(5) unsigned NOT NULL DEFAULT 0,
  `maxHealth` smallint(5) unsigned NOT NULL DEFAULT 0,
  `power` smallint(5) unsigned NOT NULL DEFAULT 0,
  `speed` smallint(5) unsigned NOT NULL DEFAULT 0,
  `quality` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `breed` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `flags` smallint(5) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_battle_pet` */

/*Table structure for table `account_battle_pet_slots` */

DROP TABLE IF EXISTS `account_battle_pet_slots`;

CREATE TABLE `account_battle_pet_slots` (
  `accountId` int(10) unsigned NOT NULL DEFAULT 0,
  `slot1` bigint(20) unsigned NOT NULL DEFAULT 0,
  `slot2` bigint(20) unsigned NOT NULL DEFAULT 0,
  `slot3` bigint(20) unsigned NOT NULL DEFAULT 0,
  `flags` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`accountId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_battle_pet_slots` */

/*Table structure for table `account_data` */

DROP TABLE IF EXISTS `account_data`;

CREATE TABLE `account_data` (
  `accountId` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Account Identifier',
  `type` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `time` int(10) unsigned NOT NULL DEFAULT 0,
  `data` blob NOT NULL,
  PRIMARY KEY (`accountId`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_data` */

/*Table structure for table `account_instance_times` */

DROP TABLE IF EXISTS `account_instance_times`;

CREATE TABLE `account_instance_times` (
  `accountId` int(10) unsigned NOT NULL,
  `instanceId` int(10) unsigned NOT NULL DEFAULT 0,
  `releaseTime` bigint(20) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`accountId`,`instanceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_instance_times` */

/*Table structure for table `account_spell` */

DROP TABLE IF EXISTS `account_spell`;

CREATE TABLE `account_spell` (
  `account` int(10) unsigned NOT NULL DEFAULT 0,
  `spell` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `active` tinyint(3) unsigned NOT NULL DEFAULT 1,
  `disabled` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`account`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_spell` */

/*Table structure for table `account_tutorial` */

DROP TABLE IF EXISTS `account_tutorial`;

CREATE TABLE `account_tutorial` (
  `accountId` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Account Identifier',
  `tut0` int(10) unsigned NOT NULL DEFAULT 0,
  `tut1` int(10) unsigned NOT NULL DEFAULT 0,
  `tut2` int(10) unsigned NOT NULL DEFAULT 0,
  `tut3` int(10) unsigned NOT NULL DEFAULT 0,
  `tut4` int(10) unsigned NOT NULL DEFAULT 0,
  `tut5` int(10) unsigned NOT NULL DEFAULT 0,
  `tut6` int(10) unsigned NOT NULL DEFAULT 0,
  `tut7` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`accountId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_tutorial` */

/*Table structure for table `addons` */

DROP TABLE IF EXISTS `addons`;

CREATE TABLE `addons` (
  `name` varchar(120) NOT NULL DEFAULT '',
  `crc` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Addons';

/*Data for the table `addons` */

/*Table structure for table `armory_character_stats` */

DROP TABLE IF EXISTS `armory_character_stats`;

CREATE TABLE `armory_character_stats` (
  `guid` int(11) NOT NULL,
  `data` longtext NOT NULL,
  `item_level` smallint(5) unsigned DEFAULT NULL,
  `gear_score` smallint(5) unsigned DEFAULT NULL,
  `achievement_points` smallint(5) unsigned DEFAULT NULL,
  `save_date` int(11) DEFAULT NULL,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='World of Warcraft Armory table';

/*Data for the table `armory_character_stats` */

/*Table structure for table `auctionhouse` */

DROP TABLE IF EXISTS `auctionhouse`;

CREATE TABLE `auctionhouse` (
  `id` int(10) unsigned NOT NULL DEFAULT 0,
  `auctioneerguid` int(10) unsigned NOT NULL DEFAULT 0,
  `itemguid` int(10) unsigned NOT NULL DEFAULT 0,
  `itemowner` int(10) unsigned NOT NULL DEFAULT 0,
  `buyoutprice` int(10) unsigned NOT NULL DEFAULT 0,
  `time` int(10) unsigned NOT NULL DEFAULT 0,
  `buyguid` int(10) unsigned NOT NULL DEFAULT 0,
  `lastbid` int(10) unsigned NOT NULL DEFAULT 0,
  `startbid` int(10) unsigned NOT NULL DEFAULT 0,
  `deposit` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  UNIQUE KEY `item_guid` (`itemguid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `auctionhouse` */

/*Table structure for table `banned_addons` */

DROP TABLE IF EXISTS `banned_addons`;

CREATE TABLE `banned_addons` (
  `Id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `Name` varchar(255) NOT NULL,
  `Version` varchar(255) NOT NULL DEFAULT '',
  `Timestamp` timestamp NOT NULL DEFAULT current_timestamp() ON UPDATE current_timestamp(),
  PRIMARY KEY (`Id`),
  UNIQUE KEY `idx_name_ver` (`Name`,`Version`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `banned_addons` */

/*Table structure for table `blackmarket_auctions` */

DROP TABLE IF EXISTS `blackmarket_auctions`;

CREATE TABLE `blackmarket_auctions` (
  `auctionId` int(10) unsigned NOT NULL DEFAULT 0,
  `templateId` int(10) unsigned NOT NULL DEFAULT 0,
  `startTime` int(10) unsigned NOT NULL DEFAULT 0,
  `endTime` int(10) unsigned NOT NULL DEFAULT 0,
  `currentBidder` int(10) unsigned NOT NULL DEFAULT 0,
  `currentBid` bigint(10) unsigned NOT NULL DEFAULT 0,
  `minIncrement` bigint(10) unsigned NOT NULL DEFAULT 0,
  `numBids` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`auctionId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `blackmarket_auctions` */

/*Table structure for table `bugreport` */

DROP TABLE IF EXISTS `bugreport`;

CREATE TABLE `bugreport` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Identifier',
  `type` longtext NOT NULL,
  `content` longtext NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Debug System';

/*Data for the table `bugreport` */

/*Table structure for table `calendar_events` */

DROP TABLE IF EXISTS `calendar_events`;

CREATE TABLE `calendar_events` (
  `id` bigint(20) unsigned NOT NULL DEFAULT 0,
  `creator` int(10) unsigned NOT NULL DEFAULT 0,
  `title` varchar(255) NOT NULL DEFAULT '',
  `description` varchar(255) NOT NULL DEFAULT '',
  `type` tinyint(1) unsigned NOT NULL DEFAULT 4,
  `dungeon` int(10) NOT NULL DEFAULT -1,
  `eventtime` int(10) unsigned NOT NULL DEFAULT 0,
  `flags` int(10) unsigned NOT NULL DEFAULT 0,
  `time2` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `calendar_events` */

/*Table structure for table `calendar_invites` */

DROP TABLE IF EXISTS `calendar_invites`;

CREATE TABLE `calendar_invites` (
  `id` bigint(20) unsigned NOT NULL DEFAULT 0,
  `event` bigint(20) unsigned NOT NULL DEFAULT 0,
  `invitee` int(10) unsigned NOT NULL DEFAULT 0,
  `sender` int(10) unsigned NOT NULL DEFAULT 0,
  `status` tinyint(1) unsigned NOT NULL DEFAULT 0,
  `statustime` int(10) unsigned NOT NULL DEFAULT 0,
  `rank` tinyint(1) unsigned NOT NULL DEFAULT 0,
  `text` varchar(255) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `calendar_invites` */

/*Table structure for table `channels` */

DROP TABLE IF EXISTS `channels`;

CREATE TABLE `channels` (
  `name` varchar(128) NOT NULL,
  `team` int(10) unsigned NOT NULL,
  `announce` tinyint(3) unsigned NOT NULL DEFAULT 1,
  `ownership` tinyint(3) unsigned NOT NULL DEFAULT 1,
  `password` varchar(32) DEFAULT NULL,
  `bannedList` text DEFAULT NULL,
  `lastUsed` int(10) unsigned NOT NULL,
  PRIMARY KEY (`name`,`team`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Channel System';

/*Data for the table `channels` */

/*Table structure for table `character_account_data` */

DROP TABLE IF EXISTS `character_account_data`;

CREATE TABLE `character_account_data` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `type` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `time` int(10) unsigned NOT NULL DEFAULT 0,
  `data` blob NOT NULL,
  PRIMARY KEY (`guid`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_account_data` */

/*Table structure for table `character_achievement` */

DROP TABLE IF EXISTS `character_achievement`;

CREATE TABLE `character_achievement` (
  `guid` int(10) unsigned NOT NULL,
  `achievement` smallint(5) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`achievement`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_achievement` */

/*Table structure for table `character_achievement_progress` */

DROP TABLE IF EXISTS `character_achievement_progress`;

CREATE TABLE `character_achievement_progress` (
  `guid` int(10) unsigned NOT NULL,
  `criteria` smallint(5) unsigned NOT NULL,
  `counter` bigint(20) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`criteria`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_achievement_progress` */

/*Table structure for table `character_action` */

DROP TABLE IF EXISTS `character_action`;

CREATE TABLE `character_action` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `spec` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `button` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `action` int(10) unsigned NOT NULL DEFAULT 0,
  `type` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`spec`,`button`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_action` */

/*Table structure for table `character_arena_stats` */

DROP TABLE IF EXISTS `character_arena_stats`;

CREATE TABLE `character_arena_stats` (
  `guid` int(10) NOT NULL,
  `slot` tinyint(3) NOT NULL,
  `matchMakerRating` smallint(5) NOT NULL,
  PRIMARY KEY (`guid`,`slot`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_arena_stats` */

/*Table structure for table `character_aura` */

DROP TABLE IF EXISTS `character_aura`;

CREATE TABLE `character_aura` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `slot` tinyint(3) unsigned NOT NULL,
  `caster_guid` bigint(20) unsigned NOT NULL DEFAULT 0 COMMENT 'Full Global Unique Identifier',
  `item_guid` bigint(20) unsigned NOT NULL DEFAULT 0,
  `spell` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `effect_mask` int(10) unsigned NOT NULL DEFAULT 0,
  `recalculate_mask` int(10) unsigned DEFAULT 0,
  `stackcount` tinyint(3) unsigned NOT NULL DEFAULT 1,
  `maxduration` int(11) NOT NULL DEFAULT 0,
  `remaintime` int(11) NOT NULL DEFAULT 0,
  `remaincharges` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`caster_guid`,`item_guid`,`spell`,`effect_mask`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_aura` */

/*Table structure for table `character_aura_effect` */

DROP TABLE IF EXISTS `character_aura_effect`;

CREATE TABLE `character_aura_effect` (
  `guid` int(10) unsigned NOT NULL,
  `slot` tinyint(3) unsigned NOT NULL,
  `effect` tinyint(3) unsigned NOT NULL,
  `base_amount` int(10) NOT NULL DEFAULT 0,
  `amount` int(10) NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`slot`,`effect`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_aura_effect` */

/*Table structure for table `character_banned` */

DROP TABLE IF EXISTS `character_banned`;

CREATE TABLE `character_banned` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `bandate` int(10) unsigned NOT NULL DEFAULT 0,
  `unbandate` int(10) unsigned NOT NULL DEFAULT 0,
  `bannedby` varchar(50) NOT NULL,
  `banreason` varchar(255) NOT NULL,
  `active` tinyint(3) unsigned NOT NULL DEFAULT 1,
  PRIMARY KEY (`guid`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Ban List';

/*Data for the table `character_banned` */

/*Table structure for table `character_battleground_data` */

DROP TABLE IF EXISTS `character_battleground_data`;

CREATE TABLE `character_battleground_data` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `instanceId` int(10) unsigned NOT NULL COMMENT 'Instance Identifier',
  `team` smallint(5) unsigned NOT NULL,
  `joinX` float NOT NULL DEFAULT 0,
  `joinY` float NOT NULL DEFAULT 0,
  `joinZ` float NOT NULL DEFAULT 0,
  `joinO` float NOT NULL DEFAULT 0,
  `joinMapId` smallint(5) unsigned NOT NULL DEFAULT 0 COMMENT 'Map Identifier',
  `taxiStart` int(10) unsigned NOT NULL DEFAULT 0,
  `taxiEnd` int(10) unsigned NOT NULL DEFAULT 0,
  `taxiPathPoint` smallint(5) unsigned NOT NULL,
  `mountSpell` mediumint(8) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_battleground_data` */

/*Table structure for table `character_battleground_random` */

DROP TABLE IF EXISTS `character_battleground_random`;

CREATE TABLE `character_battleground_random` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_battleground_random` */

/*Table structure for table `character_battleground_stats` */

DROP TABLE IF EXISTS `character_battleground_stats`;

CREATE TABLE `character_battleground_stats` (
  `guid` int(10) unsigned NOT NULL,
  `total_count` int(10) unsigned NOT NULL DEFAULT 0,
  `total_wins` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_battleground_stats` */

/*Table structure for table `character_battleground_weekend` */

DROP TABLE IF EXISTS `character_battleground_weekend`;

CREATE TABLE `character_battleground_weekend` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_battleground_weekend` */

/*Table structure for table `character_bonus_roll` */

DROP TABLE IF EXISTS `character_bonus_roll`;

CREATE TABLE `character_bonus_roll` (
  `guid` int(10) unsigned NOT NULL,
  `bonus_chance` float DEFAULT NULL,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_bonus_roll` */

/*Table structure for table `character_completed_challenges` */

DROP TABLE IF EXISTS `character_completed_challenges`;

CREATE TABLE `character_completed_challenges` (
  `guid` int(10) unsigned NOT NULL,
  `map` int(10) unsigned NOT NULL DEFAULT 0,
  `best_time` int(10) unsigned NOT NULL DEFAULT 0,
  `last_time` int(10) unsigned NOT NULL DEFAULT 0,
  `best_medal` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `best_medal_date` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`map`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_completed_challenges` */

/*Table structure for table `character_cuf_profiles` */

DROP TABLE IF EXISTS `character_cuf_profiles`;

CREATE TABLE `character_cuf_profiles` (
  `guid` int(10) unsigned NOT NULL COMMENT 'Character Guid',
  `id` tinyint(3) unsigned NOT NULL COMMENT 'Profile Id (0-4)',
  `name` varchar(12) NOT NULL COMMENT 'Profile Name',
  `frameHeight` smallint(5) unsigned NOT NULL DEFAULT 0 COMMENT 'Profile Frame Height',
  `frameWidth` smallint(5) unsigned NOT NULL DEFAULT 0 COMMENT 'Profile Frame Width',
  `sortBy` tinyint(3) unsigned NOT NULL DEFAULT 0 COMMENT 'Frame Sort By',
  `healthText` tinyint(3) unsigned NOT NULL DEFAULT 0 COMMENT 'Frame Health Text',
  `boolOptions` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Many Configurable Bool Options',
  `unk146` tinyint(3) unsigned NOT NULL DEFAULT 0 COMMENT 'Profile Unk Int8',
  `unk147` tinyint(3) unsigned NOT NULL DEFAULT 0 COMMENT 'Profile Unk Int8',
  `unk148` tinyint(3) unsigned NOT NULL DEFAULT 0 COMMENT 'Profile Unk Int8',
  `unk150` smallint(5) unsigned NOT NULL DEFAULT 0 COMMENT 'Profile Unk Int16',
  `unk152` smallint(5) unsigned NOT NULL DEFAULT 0 COMMENT 'Profile Unk Int16',
  `unk154` smallint(5) unsigned NOT NULL DEFAULT 0 COMMENT 'Profile Unk Int16',
  PRIMARY KEY (`guid`,`id`),
  KEY `index` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_cuf_profiles` */

/*Table structure for table `character_currency` */

DROP TABLE IF EXISTS `character_currency`;

CREATE TABLE `character_currency` (
  `guid` int(10) unsigned NOT NULL,
  `currency` smallint(5) unsigned NOT NULL,
  `total_count` int(10) unsigned NOT NULL,
  `week_count` int(10) unsigned NOT NULL,
  `season_count` int(10) unsigned NOT NULL,
  `flags` int(5) unsigned NOT NULL,
  PRIMARY KEY (`guid`,`currency`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_currency` */

/*Table structure for table `character_declinedname` */

DROP TABLE IF EXISTS `character_declinedname`;

CREATE TABLE `character_declinedname` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `genitive` varchar(15) NOT NULL DEFAULT '',
  `dative` varchar(15) NOT NULL DEFAULT '',
  `accusative` varchar(15) NOT NULL DEFAULT '',
  `instrumental` varchar(15) NOT NULL DEFAULT '',
  `prepositional` varchar(15) NOT NULL DEFAULT '',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_declinedname` */

/*Table structure for table `character_deserter` */

DROP TABLE IF EXISTS `character_deserter`;

CREATE TABLE `character_deserter` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `deserter_mod` tinyint(1) unsigned NOT NULL DEFAULT 0,
  `last_deserter_time` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_deserter` */

/*Table structure for table `character_equipmentsets` */

DROP TABLE IF EXISTS `character_equipmentsets`;

CREATE TABLE `character_equipmentsets` (
  `guid` int(10) NOT NULL DEFAULT 0,
  `setguid` bigint(20) NOT NULL AUTO_INCREMENT,
  `setindex` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `name` varchar(31) NOT NULL,
  `iconname` varchar(100) NOT NULL,
  `ignore_mask` int(11) unsigned NOT NULL DEFAULT 0,
  `item0` int(11) unsigned NOT NULL DEFAULT 0,
  `item1` int(11) unsigned NOT NULL DEFAULT 0,
  `item2` int(11) unsigned NOT NULL DEFAULT 0,
  `item3` int(11) unsigned NOT NULL DEFAULT 0,
  `item4` int(11) unsigned NOT NULL DEFAULT 0,
  `item5` int(11) unsigned NOT NULL DEFAULT 0,
  `item6` int(11) unsigned NOT NULL DEFAULT 0,
  `item7` int(11) unsigned NOT NULL DEFAULT 0,
  `item8` int(11) unsigned NOT NULL DEFAULT 0,
  `item9` int(11) unsigned NOT NULL DEFAULT 0,
  `item10` int(11) unsigned NOT NULL DEFAULT 0,
  `item11` int(11) unsigned NOT NULL DEFAULT 0,
  `item12` int(11) unsigned NOT NULL DEFAULT 0,
  `item13` int(11) unsigned NOT NULL DEFAULT 0,
  `item14` int(11) unsigned NOT NULL DEFAULT 0,
  `item15` int(11) unsigned NOT NULL DEFAULT 0,
  `item16` int(11) unsigned NOT NULL DEFAULT 0,
  `item17` int(11) unsigned NOT NULL DEFAULT 0,
  `item18` int(11) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`setguid`),
  UNIQUE KEY `idx_set` (`guid`,`setguid`,`setindex`),
  KEY `Idx_setindex` (`setindex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_equipmentsets` */

/*Table structure for table `character_gifts` */

DROP TABLE IF EXISTS `character_gifts`;

CREATE TABLE `character_gifts` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `item_guid` int(10) unsigned NOT NULL DEFAULT 0,
  `entry` int(10) unsigned NOT NULL DEFAULT 0,
  `flags` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`item_guid`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_gifts` */

/*Table structure for table `character_glyphs` */

DROP TABLE IF EXISTS `character_glyphs`;

CREATE TABLE `character_glyphs` (
  `guid` int(10) unsigned NOT NULL,
  `spec` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `glyph1` smallint(5) unsigned DEFAULT 0,
  `glyph2` smallint(5) unsigned DEFAULT 0,
  `glyph3` smallint(5) unsigned DEFAULT 0,
  `glyph4` smallint(5) unsigned DEFAULT 0,
  `glyph5` smallint(5) unsigned DEFAULT 0,
  `glyph6` smallint(5) unsigned DEFAULT 0,
  PRIMARY KEY (`guid`,`spec`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_glyphs` */

/*Table structure for table `character_homebind` */

DROP TABLE IF EXISTS `character_homebind`;

CREATE TABLE `character_homebind` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `mapId` smallint(5) unsigned NOT NULL DEFAULT 0 COMMENT 'Map Identifier',
  `zoneId` smallint(5) unsigned NOT NULL DEFAULT 0 COMMENT 'Zone Identifier',
  `posX` float NOT NULL DEFAULT 0,
  `posY` float NOT NULL DEFAULT 0,
  `posZ` float NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_homebind` */

/*Table structure for table `character_instance` */

DROP TABLE IF EXISTS `character_instance`;

CREATE TABLE `character_instance` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `instance` int(10) unsigned NOT NULL DEFAULT 0,
  `permanent` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`instance`),
  KEY `instance` (`instance`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_instance` */

/*Table structure for table `character_inventory` */

DROP TABLE IF EXISTS `character_inventory`;

CREATE TABLE `character_inventory` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `bag` int(10) unsigned NOT NULL DEFAULT 0,
  `slot` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `item` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Item Global Unique Identifier',
  PRIMARY KEY (`item`),
  UNIQUE KEY `guid` (`guid`,`bag`,`slot`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_inventory` */

/*Table structure for table `character_loot_lockout` */

DROP TABLE IF EXISTS `character_loot_lockout`;

CREATE TABLE `character_loot_lockout` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Character GUID',
  `entry` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Looted object entry',
  `difficulty` int(10) unsigned NOT NULL DEFAULT 7,
  `type` int(10) unsigned NOT NULL DEFAULT 0
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

/*Data for the table `character_loot_lockout` */

/*Table structure for table `character_pet` */

DROP TABLE IF EXISTS `character_pet`;

CREATE TABLE `character_pet` (
  `id` int(10) unsigned NOT NULL DEFAULT 0,
  `entry` int(10) unsigned NOT NULL DEFAULT 0,
  `owner` int(10) unsigned NOT NULL DEFAULT 0,
  `modelid` int(10) unsigned DEFAULT 0,
  `CreatedBySpell` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `PetType` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `level` smallint(5) unsigned NOT NULL DEFAULT 1,
  `exp` int(10) unsigned NOT NULL DEFAULT 0,
  `Reactstate` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `name` varchar(21) NOT NULL DEFAULT 'Pet',
  `renamed` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `slot` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `curhealth` int(10) unsigned NOT NULL DEFAULT 1,
  `curmana` int(10) unsigned NOT NULL DEFAULT 0,
  `savetime` int(10) unsigned NOT NULL DEFAULT 0,
  `abdata` text DEFAULT NULL,
  `specialization` smallint(3) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `owner` (`owner`),
  KEY `idx_slot` (`slot`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Pet System';

/*Data for the table `character_pet` */

/*Table structure for table `character_pet_current` */

DROP TABLE IF EXISTS `character_pet_current`;

CREATE TABLE `character_pet_current` (
  `owner` int(10) unsigned NOT NULL,
  `pet_id` int(10) unsigned NOT NULL,
  PRIMARY KEY (`owner`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_pet_current` */

/*Table structure for table `character_pet_declinedname` */

DROP TABLE IF EXISTS `character_pet_declinedname`;

CREATE TABLE `character_pet_declinedname` (
  `id` int(10) unsigned NOT NULL DEFAULT 0,
  `owner` int(10) unsigned NOT NULL DEFAULT 0,
  `genitive` varchar(12) NOT NULL DEFAULT '',
  `dative` varchar(12) NOT NULL DEFAULT '',
  `accusative` varchar(12) NOT NULL DEFAULT '',
  `instrumental` varchar(12) NOT NULL DEFAULT '',
  `prepositional` varchar(12) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`),
  KEY `owner_key` (`owner`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_pet_declinedname` */

/*Table structure for table `character_queststatus` */

DROP TABLE IF EXISTS `character_queststatus`;

CREATE TABLE `character_queststatus` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `quest` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Quest Identifier',
  `status` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `explored` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `timer` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`quest`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus` */

/*Table structure for table `character_queststatus_daily` */

DROP TABLE IF EXISTS `character_queststatus_daily`;

CREATE TABLE `character_queststatus_daily` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `quest` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Quest Identifier',
  `time` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`quest`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus_daily` */

/*Table structure for table `character_queststatus_monthly` */

DROP TABLE IF EXISTS `character_queststatus_monthly`;

CREATE TABLE `character_queststatus_monthly` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `quest` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Quest Identifier',
  PRIMARY KEY (`guid`,`quest`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus_monthly` */

/*Table structure for table `character_queststatus_objective` */

DROP TABLE IF EXISTS `character_queststatus_objective`;

CREATE TABLE `character_queststatus_objective` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `objectiveId` int(10) unsigned NOT NULL DEFAULT 0,
  `amount` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`objectiveId`,`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_queststatus_objective` */

/*Table structure for table `character_queststatus_rewarded` */

DROP TABLE IF EXISTS `character_queststatus_rewarded`;

CREATE TABLE `character_queststatus_rewarded` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `quest` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Quest Identifier',
  `active` tinyint(10) unsigned NOT NULL DEFAULT 1,
  PRIMARY KEY (`guid`,`quest`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus_rewarded` */

/*Table structure for table `character_queststatus_seasonal` */

DROP TABLE IF EXISTS `character_queststatus_seasonal`;

CREATE TABLE `character_queststatus_seasonal` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `quest` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Quest Identifier',
  `event` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Event Identifier',
  PRIMARY KEY (`guid`,`quest`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus_seasonal` */

/*Table structure for table `character_queststatus_weekly` */

DROP TABLE IF EXISTS `character_queststatus_weekly`;

CREATE TABLE `character_queststatus_weekly` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `quest` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Quest Identifier',
  PRIMARY KEY (`guid`,`quest`),
  KEY `idx_guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_queststatus_weekly` */

/*Table structure for table `character_reputation` */

DROP TABLE IF EXISTS `character_reputation`;

CREATE TABLE `character_reputation` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `faction` smallint(5) unsigned NOT NULL DEFAULT 0,
  `standing` float NOT NULL DEFAULT 0,
  `flags` smallint(5) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`faction`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_reputation` */

/*Table structure for table `character_research_digsites` */

DROP TABLE IF EXISTS `character_research_digsites`;

CREATE TABLE `character_research_digsites` (
  `guid` int(11) NOT NULL COMMENT 'Global Unique Identifier',
  `digsiteId` int(11) NOT NULL,
  `currentFindGUID` int(11) NOT NULL DEFAULT 0,
  `remainingFindCount` tinyint(3) NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`digsiteId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `character_research_digsites` */

/*Table structure for table `character_research_history` */

DROP TABLE IF EXISTS `character_research_history`;

CREATE TABLE `character_research_history` (
  `guid` int(11) NOT NULL COMMENT 'Global Unique Identifier',
  `projectId` int(11) NOT NULL,
  `researchCount` int(11) NOT NULL,
  `firstResearchTimestamp` int(11) NOT NULL,
  PRIMARY KEY (`guid`,`projectId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `character_research_history` */

/*Table structure for table `character_research_projects` */

DROP TABLE IF EXISTS `character_research_projects`;

CREATE TABLE `character_research_projects` (
  `guid` int(11) NOT NULL COMMENT 'Global Unique Identifier',
  `projectId` int(11) NOT NULL,
  PRIMARY KEY (`guid`,`projectId`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `character_research_projects` */

/*Table structure for table `character_service` */

DROP TABLE IF EXISTS `character_service`;

CREATE TABLE `character_service` (
  `id` int(11) unsigned NOT NULL,
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `service` int(10) unsigned NOT NULL DEFAULT 0,
  `data1` int(10) unsigned NOT NULL DEFAULT 0,
  `data2` int(10) unsigned NOT NULL DEFAULT 0,
  `data3` int(10) unsigned NOT NULL DEFAULT 0,
  `data4` text DEFAULT NULL,
  `creation_date` int(11) unsigned NOT NULL,
  `execution_date` int(11) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_service` */

/*Table structure for table `character_skills` */

DROP TABLE IF EXISTS `character_skills`;

CREATE TABLE `character_skills` (
  `guid` int(10) unsigned NOT NULL COMMENT 'Global Unique Identifier',
  `skill` smallint(5) unsigned NOT NULL,
  `value` smallint(5) unsigned NOT NULL,
  `max` smallint(5) unsigned NOT NULL,
  PRIMARY KEY (`guid`,`skill`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_skills` */

/*Table structure for table `character_social` */

DROP TABLE IF EXISTS `character_social`;

CREATE TABLE `character_social` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Character Global Unique Identifier',
  `friend` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Friend Global Unique Identifier',
  `flags` tinyint(3) unsigned NOT NULL DEFAULT 0 COMMENT 'Friend Flags',
  `note` varchar(48) NOT NULL DEFAULT '' COMMENT 'Friend Note',
  PRIMARY KEY (`guid`,`friend`,`flags`),
  KEY `friend` (`friend`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_social` */

/*Table structure for table `character_spell` */

DROP TABLE IF EXISTS `character_spell`;

CREATE TABLE `character_spell` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `spell` mediumint(8) unsigned NOT NULL DEFAULT 0 COMMENT 'Spell Identifier',
  `active` tinyint(3) unsigned NOT NULL DEFAULT 1,
  `disabled` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `character_spell` */

/*Table structure for table `character_spell_charges` */

DROP TABLE IF EXISTS `character_spell_charges`;

CREATE TABLE `character_spell_charges` (
  `guid` int(11) unsigned NOT NULL,
  `category` int(11) unsigned NOT NULL,
  `reset_time` bigint(20) unsigned NOT NULL,
  `used_charges` int(11) unsigned NOT NULL,
  PRIMARY KEY (`guid`,`category`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_spell_charges` */

/*Table structure for table `character_spell_cooldown` */

DROP TABLE IF EXISTS `character_spell_cooldown`;

CREATE TABLE `character_spell_cooldown` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier, Low part',
  `spell` mediumint(8) unsigned NOT NULL DEFAULT 0 COMMENT 'Spell Identifier',
  `item` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Item Identifier',
  `time` bigint(20) unsigned NOT NULL DEFAULT 0,
  `category_end` bigint(20) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_spell_cooldown` */

/*Table structure for table `character_stats` */

DROP TABLE IF EXISTS `character_stats`;

CREATE TABLE `character_stats` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier, Low part',
  `maxhealth` int(10) unsigned NOT NULL DEFAULT 0,
  `maxpower1` int(10) unsigned NOT NULL DEFAULT 0,
  `maxpower2` int(10) unsigned NOT NULL DEFAULT 0,
  `maxpower3` int(10) unsigned NOT NULL DEFAULT 0,
  `maxpower4` int(10) unsigned NOT NULL DEFAULT 0,
  `maxpower5` int(10) unsigned NOT NULL DEFAULT 0,
  `strength` int(10) unsigned NOT NULL DEFAULT 0,
  `agility` int(10) unsigned NOT NULL DEFAULT 0,
  `stamina` int(10) unsigned NOT NULL DEFAULT 0,
  `intellect` int(10) unsigned NOT NULL DEFAULT 0,
  `spirit` int(10) unsigned NOT NULL DEFAULT 0,
  `armor` int(10) unsigned NOT NULL DEFAULT 0,
  `resHoly` int(10) unsigned NOT NULL DEFAULT 0,
  `resFire` int(10) unsigned NOT NULL DEFAULT 0,
  `resNature` int(10) unsigned NOT NULL DEFAULT 0,
  `resFrost` int(10) unsigned NOT NULL DEFAULT 0,
  `resShadow` int(10) unsigned NOT NULL DEFAULT 0,
  `resArcane` int(10) unsigned NOT NULL DEFAULT 0,
  `blockPct` float unsigned NOT NULL DEFAULT 0,
  `dodgePct` float unsigned NOT NULL DEFAULT 0,
  `parryPct` float unsigned NOT NULL DEFAULT 0,
  `critPct` float unsigned NOT NULL DEFAULT 0,
  `rangedCritPct` float unsigned NOT NULL DEFAULT 0,
  `spellCritPct` float unsigned NOT NULL DEFAULT 0,
  `attackPower` int(10) unsigned NOT NULL DEFAULT 0,
  `rangedAttackPower` int(10) unsigned NOT NULL DEFAULT 0,
  `spellPower` int(10) unsigned NOT NULL DEFAULT 0,
  `resilience` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_stats` */

/*Table structure for table `character_talent` */

DROP TABLE IF EXISTS `character_talent`;

CREATE TABLE `character_talent` (
  `guid` int(10) unsigned NOT NULL,
  `spell` mediumint(8) unsigned NOT NULL,
  `spec` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`spell`,`spec`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_talent` */

/*Table structure for table `character_void_storage` */

DROP TABLE IF EXISTS `character_void_storage`;

CREATE TABLE `character_void_storage` (
  `itemId` bigint(20) unsigned NOT NULL,
  `playerGuid` int(10) unsigned NOT NULL,
  `itemEntry` mediumint(8) unsigned NOT NULL,
  `slot` tinyint(3) unsigned NOT NULL,
  `creatorGuid` int(10) unsigned NOT NULL DEFAULT 0,
  `randomProperty` int(10) unsigned NOT NULL DEFAULT 0,
  `suffixFactor` int(10) unsigned NOT NULL DEFAULT 0,
  `upgradeId` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`itemId`),
  UNIQUE KEY `idx_player_slot` (`playerGuid`,`slot`),
  KEY `idx_player` (`playerGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `character_void_storage` */

/*Table structure for table `characters` */

DROP TABLE IF EXISTS `characters`;

CREATE TABLE `characters` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `account` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Account Identifier',
  `name` varchar(12) DEFAULT NULL,
  `slot` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `race` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `class` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `gender` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `level` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `xp` int(10) unsigned NOT NULL DEFAULT 0,
  `money` bigint(20) unsigned NOT NULL DEFAULT 0,
  `playerBytes` int(10) unsigned NOT NULL DEFAULT 0,
  `playerBytes2` int(10) unsigned NOT NULL DEFAULT 0,
  `playerFlags` int(10) unsigned NOT NULL DEFAULT 0,
  `position_x` float NOT NULL DEFAULT 0,
  `position_y` float NOT NULL DEFAULT 0,
  `position_z` float NOT NULL DEFAULT 0,
  `map` smallint(5) unsigned NOT NULL DEFAULT 0 COMMENT 'Map Identifier',
  `instance_id` int(10) unsigned NOT NULL DEFAULT 0,
  `instance_mode_mask` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `orientation` float NOT NULL DEFAULT 0,
  `taximask` text NOT NULL,
  `online` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `cinematic` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `totaltime` int(10) unsigned NOT NULL DEFAULT 0,
  `leveltime` int(10) unsigned NOT NULL DEFAULT 0,
  `logout_time` int(10) unsigned NOT NULL DEFAULT 0,
  `is_logout_resting` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `rest_bonus` float NOT NULL DEFAULT 0,
  `resettalents_cost` int(10) unsigned NOT NULL DEFAULT 0,
  `resettalents_time` int(10) unsigned NOT NULL DEFAULT 0,
  `talentTree` varchar(10) NOT NULL DEFAULT '0 0',
  `trans_x` float NOT NULL DEFAULT 0,
  `trans_y` float NOT NULL DEFAULT 0,
  `trans_z` float NOT NULL DEFAULT 0,
  `trans_o` float NOT NULL DEFAULT 0,
  `transguid` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `extra_flags` smallint(5) unsigned NOT NULL DEFAULT 0,
  `stable_slots` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `at_login` smallint(5) unsigned NOT NULL DEFAULT 0,
  `zone` smallint(5) unsigned NOT NULL DEFAULT 0,
  `death_expire_time` int(10) unsigned NOT NULL DEFAULT 0,
  `taxi_path` text DEFAULT NULL,
  `totalKills` int(10) unsigned NOT NULL DEFAULT 0,
  `todayKills` smallint(5) unsigned NOT NULL DEFAULT 0,
  `yesterdayKills` smallint(5) unsigned NOT NULL DEFAULT 0,
  `chosenTitle` int(10) unsigned NOT NULL DEFAULT 0,
  `watchedFaction` int(10) unsigned NOT NULL DEFAULT 0,
  `drunk` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `health` int(10) unsigned NOT NULL DEFAULT 0,
  `power1` int(10) unsigned NOT NULL DEFAULT 0,
  `power2` int(10) unsigned NOT NULL DEFAULT 0,
  `power3` int(10) unsigned NOT NULL DEFAULT 0,
  `power4` int(10) unsigned NOT NULL DEFAULT 0,
  `power5` int(10) unsigned NOT NULL DEFAULT 0,
  `latency` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `speccount` tinyint(3) unsigned NOT NULL DEFAULT 1,
  `activespec` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `exploredZones` longtext DEFAULT NULL,
  `equipmentCache` longtext DEFAULT NULL,
  `knownTitles` longtext DEFAULT NULL,
  `actionBars` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `grantableLevels` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `deleteInfos_Account` int(10) unsigned DEFAULT NULL,
  `deleteInfos_Name` varchar(12) DEFAULT NULL,
  `deleteDate` int(10) unsigned DEFAULT NULL,
  `lootspec` int(10) unsigned NOT NULL DEFAULT 0,
  `project_transfer` int(10) unsigned DEFAULT NULL,
  `project_original_cloned` int(10) unsigned DEFAULT NULL,
  `project_original_migrated` int(10) unsigned DEFAULT NULL,
  `project_original_realm_id` int(10) unsigned DEFAULT NULL,
  `project_original_guid` int(10) unsigned DEFAULT NULL,
  `project_clone_created` int(10) unsigned DEFAULT NULL,
  `project_clone_realm_id` int(10) unsigned DEFAULT NULL,
  `project_clone_guid` int(10) unsigned DEFAULT NULL,
  `project_migrant_created` int(10) unsigned DEFAULT NULL,
  `project_migrant_realm_id` int(10) unsigned DEFAULT NULL,
  `project_migrant_guid` int(10) unsigned DEFAULT NULL,
  `last_login` int(11) unsigned NOT NULL DEFAULT 0,
  `taxi_path_point` smallint(5) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`),
  KEY `idx_account` (`account`),
  KEY `idx_online` (`online`),
  KEY `idx_name` (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `characters` */

/*Table structure for table `corpse` */

DROP TABLE IF EXISTS `corpse`;

CREATE TABLE `corpse` (
  `corpseGuid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Character Global Unique Identifier',
  `posX` float NOT NULL DEFAULT 0,
  `posY` float NOT NULL DEFAULT 0,
  `posZ` float NOT NULL DEFAULT 0,
  `orientation` float NOT NULL DEFAULT 0,
  `mapId` smallint(5) unsigned NOT NULL DEFAULT 0 COMMENT 'Map Identifier',
  `phaseMask` int(10) unsigned NOT NULL DEFAULT 1,
  `displayId` int(10) unsigned NOT NULL DEFAULT 0,
  `itemCache` text NOT NULL,
  `bytes1` int(10) unsigned NOT NULL DEFAULT 0,
  `bytes2` int(10) unsigned NOT NULL DEFAULT 0,
  `flags` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `dynFlags` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `time` int(10) unsigned NOT NULL DEFAULT 0,
  `corpseType` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `instanceId` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Instance Identifier',
  PRIMARY KEY (`corpseGuid`),
  KEY `idx_type` (`corpseType`),
  KEY `idx_instance` (`instanceId`),
  KEY `idx_player` (`guid`),
  KEY `idx_time` (`time`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Death System';

/*Data for the table `corpse` */

/*Table structure for table `creature_respawn` */

DROP TABLE IF EXISTS `creature_respawn`;

CREATE TABLE `creature_respawn` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `respawnTime` int(10) unsigned NOT NULL DEFAULT 0,
  `mapId` smallint(10) unsigned NOT NULL DEFAULT 0,
  `instanceId` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Instance Identifier',
  PRIMARY KEY (`guid`,`instanceId`),
  KEY `idx_instance` (`instanceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Grid Loading System';

/*Data for the table `creature_respawn` */

/*Table structure for table `custom_transmogrification` */

DROP TABLE IF EXISTS `custom_transmogrification`;

CREATE TABLE `custom_transmogrification` (
  `GUID` int(10) unsigned NOT NULL COMMENT 'Item guidLow',
  `FakeEntry` int(10) unsigned NOT NULL COMMENT 'Item entry',
  `Owner` int(10) unsigned NOT NULL COMMENT 'Player guidLow',
  PRIMARY KEY (`GUID`),
  KEY `Owner` (`Owner`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='don''t work just yet.';

/*Data for the table `custom_transmogrification` */

/*Table structure for table `custom_transmogrification_sets` */

DROP TABLE IF EXISTS `custom_transmogrification_sets`;

CREATE TABLE `custom_transmogrification_sets` (
  `Owner` int(10) unsigned NOT NULL COMMENT 'Player guidlow',
  `PresetID` tinyint(3) unsigned NOT NULL COMMENT 'Preset identifier',
  `SetName` text DEFAULT NULL COMMENT 'SetName',
  `SetData` text DEFAULT NULL COMMENT 'Slot1 Entry1 Slot2 Entry2',
  PRIMARY KEY (`Owner`,`PresetID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='6_1';

/*Data for the table `custom_transmogrification_sets` */

/*Table structure for table `daily_players_reports` */

DROP TABLE IF EXISTS `daily_players_reports`;

CREATE TABLE `daily_players_reports` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `creation_time` int(10) unsigned NOT NULL DEFAULT 0,
  `average` float NOT NULL DEFAULT 0,
  `total_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  `speed_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  `fly_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  `jump_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  `waterwalk_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  `teleportplane_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  `climb_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `daily_players_reports` */

/*Table structure for table `executed_services` */

DROP TABLE IF EXISTS `executed_services`;

CREATE TABLE `executed_services` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `type` enum('rename','change_acc','customize','change_race','change_class','change_prof','char_restore','guild_rename','unban','level_down','marketplace','transfer','boost','item_restore') NOT NULL,
  `guid` int(11) unsigned NOT NULL DEFAULT 0 COMMENT '(player or guild)',
  `old_data` text NOT NULL,
  `new_data` text NOT NULL,
  `execute_date` text NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `executed_services` */

/*Table structure for table `fake_items` */

DROP TABLE IF EXISTS `fake_items`;

CREATE TABLE `fake_items` (
  `guid` int(11) NOT NULL,
  `fakeEntry` int(11) NOT NULL,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `fake_items` */

/*Table structure for table `game_event_condition_save` */

DROP TABLE IF EXISTS `game_event_condition_save`;

CREATE TABLE `game_event_condition_save` (
  `eventEntry` tinyint(3) unsigned NOT NULL,
  `condition_id` int(10) unsigned NOT NULL DEFAULT 0,
  `done` float DEFAULT 0,
  PRIMARY KEY (`eventEntry`,`condition_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `game_event_condition_save` */

/*Table structure for table `game_event_save` */

DROP TABLE IF EXISTS `game_event_save`;

CREATE TABLE `game_event_save` (
  `eventEntry` tinyint(3) unsigned NOT NULL,
  `state` tinyint(3) unsigned NOT NULL DEFAULT 1,
  `next_start` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`eventEntry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `game_event_save` */

/*Table structure for table `gameobject_respawn` */

DROP TABLE IF EXISTS `gameobject_respawn`;

CREATE TABLE `gameobject_respawn` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `respawnTime` int(10) unsigned NOT NULL DEFAULT 0,
  `mapId` smallint(10) unsigned NOT NULL DEFAULT 0,
  `instanceId` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Instance Identifier',
  PRIMARY KEY (`guid`,`instanceId`),
  KEY `idx_instance` (`instanceId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Grid Loading System';

/*Data for the table `gameobject_respawn` */

/*Table structure for table `gm_subsurveys` */

DROP TABLE IF EXISTS `gm_subsurveys`;

CREATE TABLE `gm_subsurveys` (
  `surveyId` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `subsurveyId` int(10) unsigned NOT NULL DEFAULT 0,
  `rank` int(10) unsigned NOT NULL DEFAULT 0,
  `comment` text NOT NULL,
  PRIMARY KEY (`surveyId`,`subsurveyId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `gm_subsurveys` */

/*Table structure for table `gm_surveys` */

DROP TABLE IF EXISTS `gm_surveys`;

CREATE TABLE `gm_surveys` (
  `surveyId` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `mainSurvey` int(10) unsigned NOT NULL DEFAULT 0,
  `overallComment` longtext NOT NULL,
  `createTime` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`surveyId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `gm_surveys` */

/*Table structure for table `gm_tickets` */

DROP TABLE IF EXISTS `gm_tickets`;

CREATE TABLE `gm_tickets` (
  `ticketId` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier of ticket creator',
  `name` varchar(12) NOT NULL COMMENT 'Name of ticket creator',
  `message` text NOT NULL,
  `createTime` int(10) unsigned NOT NULL DEFAULT 0,
  `mapId` smallint(5) unsigned NOT NULL DEFAULT 0,
  `posX` float NOT NULL DEFAULT 0,
  `posY` float NOT NULL DEFAULT 0,
  `posZ` float NOT NULL DEFAULT 0,
  `lastModifiedTime` int(10) unsigned NOT NULL DEFAULT 0,
  `closedBy` int(10) NOT NULL DEFAULT 0,
  `assignedTo` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'GUID of admin to whom ticket is assigned',
  `comment` text NOT NULL,
  `response` text NOT NULL,
  `completed` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `escalated` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `viewed` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `haveTicket` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`ticketId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `gm_tickets` */

/*Table structure for table `group_completed_challenges` */

DROP TABLE IF EXISTS `group_completed_challenges`;

CREATE TABLE `group_completed_challenges` (
  `map` int(10) unsigned NOT NULL,
  `attemptId` int(10) unsigned NOT NULL DEFAULT 0,
  `completion_time` int(10) unsigned NOT NULL DEFAULT 0,
  `completion_date` int(10) unsigned NOT NULL DEFAULT 0,
  `medal_earned` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `group_members` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `member_1_guid` int(10) unsigned NOT NULL DEFAULT 0,
  `member_1_spec` int(10) unsigned NOT NULL DEFAULT 0,
  `member_2_guid` int(10) unsigned NOT NULL DEFAULT 0,
  `member_2_spec` int(10) unsigned NOT NULL DEFAULT 0,
  `member_3_guid` int(10) unsigned NOT NULL DEFAULT 0,
  `member_3_spec` int(10) unsigned NOT NULL DEFAULT 0,
  `member_4_guid` int(10) unsigned NOT NULL DEFAULT 0,
  `member_4_spec` int(10) unsigned NOT NULL DEFAULT 0,
  `member_5_guid` int(10) unsigned NOT NULL DEFAULT 0,
  `member_5_spec` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`map`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `group_completed_challenges` */

/*Table structure for table `group_instance` */

DROP TABLE IF EXISTS `group_instance`;

CREATE TABLE `group_instance` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `instance` int(10) unsigned NOT NULL DEFAULT 0,
  `permanent` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`instance`),
  KEY `instance` (`instance`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `group_instance` */

/*Table structure for table `group_member` */

DROP TABLE IF EXISTS `group_member`;

CREATE TABLE `group_member` (
  `guid` int(10) unsigned NOT NULL,
  `memberGuid` int(10) unsigned NOT NULL,
  `memberFlags` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `subgroup` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `roles` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`memberGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Groups';

/*Data for the table `group_member` */

/*Table structure for table `groups` */

DROP TABLE IF EXISTS `groups`;

CREATE TABLE `groups` (
  `guid` int(10) unsigned NOT NULL,
  `leaderGuid` int(10) unsigned NOT NULL,
  `lootMethod` tinyint(3) unsigned NOT NULL,
  `looterGuid` int(10) unsigned NOT NULL,
  `lootThreshold` tinyint(3) unsigned NOT NULL,
  `icon1` int(10) unsigned NOT NULL,
  `icon2` int(10) unsigned NOT NULL,
  `icon3` int(10) unsigned NOT NULL,
  `icon4` int(10) unsigned NOT NULL,
  `icon5` int(10) unsigned NOT NULL,
  `icon6` int(10) unsigned NOT NULL,
  `icon7` int(10) unsigned NOT NULL,
  `icon8` int(10) unsigned NOT NULL,
  `groupType` tinyint(3) unsigned NOT NULL,
  `difficulty` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `raiddifficulty` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `slot` tinyint(3) unsigned NOT NULL,
  PRIMARY KEY (`guid`),
  KEY `leaderGuid` (`leaderGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Groups';

/*Data for the table `groups` */

/*Table structure for table `guild` */

DROP TABLE IF EXISTS `guild`;

CREATE TABLE `guild` (
  `guildid` int(10) unsigned NOT NULL DEFAULT 0,
  `name` varchar(24) NOT NULL DEFAULT '',
  `leaderguid` int(10) unsigned NOT NULL DEFAULT 0,
  `EmblemStyle` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `EmblemColor` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `BorderStyle` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `BorderColor` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `BackgroundColor` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `info` text NOT NULL,
  `motd` varchar(128) NOT NULL DEFAULT '',
  `createdate` int(10) unsigned NOT NULL DEFAULT 0,
  `BankMoney` bigint(20) unsigned NOT NULL DEFAULT 0,
  `level` int(10) unsigned DEFAULT 1,
  `experience` bigint(20) unsigned DEFAULT 0,
  PRIMARY KEY (`guildid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild System';

/*Data for the table `guild` */

/*Table structure for table `guild_achievement` */

DROP TABLE IF EXISTS `guild_achievement`;

CREATE TABLE `guild_achievement` (
  `guildId` int(10) unsigned NOT NULL,
  `achievement` smallint(5) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT 0,
  `guids` text NOT NULL,
  PRIMARY KEY (`guildId`,`achievement`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_achievement` */

/*Table structure for table `guild_achievement_progress` */

DROP TABLE IF EXISTS `guild_achievement_progress`;

CREATE TABLE `guild_achievement_progress` (
  `guildId` int(10) unsigned NOT NULL,
  `criteria` smallint(5) unsigned NOT NULL,
  `counter` bigint(20) unsigned NOT NULL,
  `date` int(10) unsigned NOT NULL DEFAULT 0,
  `completedGuid` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guildId`,`criteria`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_achievement_progress` */

/*Table structure for table `guild_bank_eventlog` */

DROP TABLE IF EXISTS `guild_bank_eventlog`;

CREATE TABLE `guild_bank_eventlog` (
  `guildid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Guild Identificator',
  `LogGuid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Log record identificator - auxiliary column',
  `TabId` tinyint(3) unsigned NOT NULL DEFAULT 0 COMMENT 'Guild bank TabId',
  `EventType` tinyint(3) unsigned NOT NULL DEFAULT 0 COMMENT 'Event type',
  `PlayerGuid` int(10) unsigned NOT NULL DEFAULT 0,
  `ItemOrMoney` int(10) unsigned NOT NULL DEFAULT 0,
  `ItemStackCount` smallint(5) unsigned NOT NULL DEFAULT 0,
  `DestTabId` tinyint(3) unsigned NOT NULL DEFAULT 0 COMMENT 'Destination Tab Id',
  `TimeStamp` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Event UNIX time',
  PRIMARY KEY (`guildid`,`LogGuid`,`TabId`),
  KEY `guildid_key` (`guildid`),
  KEY `Idx_PlayerGuid` (`PlayerGuid`),
  KEY `Idx_LogGuid` (`LogGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_bank_eventlog` */

/*Table structure for table `guild_bank_item` */

DROP TABLE IF EXISTS `guild_bank_item`;

CREATE TABLE `guild_bank_item` (
  `guildid` int(10) unsigned NOT NULL DEFAULT 0,
  `TabId` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `SlotId` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `item_guid` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guildid`,`TabId`,`SlotId`),
  KEY `guildid_key` (`guildid`),
  KEY `Idx_item_guid` (`item_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_bank_item` */

/*Table structure for table `guild_bank_right` */

DROP TABLE IF EXISTS `guild_bank_right`;

CREATE TABLE `guild_bank_right` (
  `guildid` int(10) unsigned NOT NULL DEFAULT 0,
  `TabId` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `rid` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `gbright` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `SlotPerDay` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guildid`,`TabId`,`rid`),
  KEY `guildid_key` (`guildid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_bank_right` */

/*Table structure for table `guild_bank_tab` */

DROP TABLE IF EXISTS `guild_bank_tab`;

CREATE TABLE `guild_bank_tab` (
  `guildid` int(10) unsigned NOT NULL DEFAULT 0,
  `TabId` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `TabName` varchar(16) NOT NULL DEFAULT '',
  `TabIcon` varchar(100) NOT NULL DEFAULT '',
  `TabText` varchar(500) DEFAULT NULL,
  PRIMARY KEY (`guildid`,`TabId`),
  KEY `guildid_key` (`guildid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_bank_tab` */

/*Table structure for table `guild_challenges` */

DROP TABLE IF EXISTS `guild_challenges`;

CREATE TABLE `guild_challenges` (
  `guild_id` int(11) unsigned NOT NULL,
  `dungeon` smallint(3) unsigned NOT NULL DEFAULT 0,
  `raid` smallint(3) unsigned NOT NULL DEFAULT 0,
  `rated_bg` smallint(3) unsigned NOT NULL DEFAULT 0,
  `scenario` smallint(3) unsigned NOT NULL DEFAULT 0,
  `dungeon_challenge` smallint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guild_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_challenges` */

/*Table structure for table `guild_completed_challenges` */

DROP TABLE IF EXISTS `guild_completed_challenges`;

CREATE TABLE `guild_completed_challenges` (
  `map` int(10) unsigned NOT NULL,
  `guildId` int(10) unsigned NOT NULL,
  `attemptId` int(10) unsigned NOT NULL DEFAULT 0,
  `completion_time` int(10) unsigned NOT NULL DEFAULT 0,
  `completion_date` int(10) unsigned NOT NULL DEFAULT 0,
  `medal_earned` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `guild_members` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `member_1_guid` int(10) unsigned NOT NULL DEFAULT 0,
  `member_1_spec` int(10) unsigned NOT NULL DEFAULT 0,
  `member_2_guid` int(10) unsigned NOT NULL DEFAULT 0,
  `member_2_spec` int(10) unsigned NOT NULL DEFAULT 0,
  `member_3_guid` int(10) unsigned NOT NULL DEFAULT 0,
  `member_3_spec` int(10) unsigned NOT NULL DEFAULT 0,
  `member_4_guid` int(10) unsigned NOT NULL DEFAULT 0,
  `member_4_spec` int(10) unsigned NOT NULL DEFAULT 0,
  `member_5_guid` int(10) unsigned NOT NULL DEFAULT 0,
  `member_5_spec` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`map`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_completed_challenges` */

/*Table structure for table `guild_eventlog` */

DROP TABLE IF EXISTS `guild_eventlog`;

CREATE TABLE `guild_eventlog` (
  `guildid` int(10) unsigned NOT NULL COMMENT 'Guild Identificator',
  `LogGuid` int(10) unsigned NOT NULL COMMENT 'Log record identificator - auxiliary column',
  `EventType` tinyint(3) unsigned NOT NULL COMMENT 'Event type',
  `PlayerGuid1` int(10) unsigned NOT NULL COMMENT 'Player 1',
  `PlayerGuid2` int(10) unsigned NOT NULL COMMENT 'Player 2',
  `NewRank` tinyint(3) unsigned NOT NULL COMMENT 'New rank(in case promotion/demotion)',
  `TimeStamp` int(10) unsigned NOT NULL COMMENT 'Event UNIX time',
  PRIMARY KEY (`guildid`,`LogGuid`),
  KEY `Idx_PlayerGuid1` (`PlayerGuid1`),
  KEY `Idx_PlayerGuid2` (`PlayerGuid2`),
  KEY `Idx_LogGuid` (`LogGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild Eventlog';

/*Data for the table `guild_eventlog` */

/*Table structure for table `guild_finder_applicant` */

DROP TABLE IF EXISTS `guild_finder_applicant`;

CREATE TABLE `guild_finder_applicant` (
  `guildId` int(10) unsigned DEFAULT NULL,
  `playerGuid` int(10) unsigned DEFAULT NULL,
  `availability` tinyint(3) unsigned DEFAULT 0,
  `classRole` tinyint(3) unsigned DEFAULT 0,
  `interests` tinyint(3) unsigned DEFAULT 0,
  `comment` varchar(255) DEFAULT NULL,
  `submitTime` int(10) unsigned DEFAULT NULL,
  UNIQUE KEY `guildId` (`guildId`,`playerGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_finder_applicant` */

/*Table structure for table `guild_finder_guild_settings` */

DROP TABLE IF EXISTS `guild_finder_guild_settings`;

CREATE TABLE `guild_finder_guild_settings` (
  `guildId` int(10) unsigned NOT NULL,
  `availability` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `classRoles` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `interests` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `level` tinyint(3) unsigned NOT NULL DEFAULT 1,
  `listed` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `comment` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`guildId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_finder_guild_settings` */

/*Table structure for table `guild_member` */

DROP TABLE IF EXISTS `guild_member`;

CREATE TABLE `guild_member` (
  `guildid` int(10) unsigned NOT NULL COMMENT 'Guild Identificator',
  `guid` int(10) unsigned NOT NULL,
  `rank` tinyint(3) unsigned NOT NULL,
  `pnote` varchar(31) NOT NULL DEFAULT '',
  `offnote` varchar(31) NOT NULL DEFAULT '',
  `achievement_points` smallint(5) unsigned NOT NULL DEFAULT 0,
  `first_prof_skill` smallint(5) unsigned NOT NULL DEFAULT 0,
  `first_prof_value` smallint(5) unsigned NOT NULL DEFAULT 0,
  `first_prof_rank` smallint(5) unsigned NOT NULL DEFAULT 0,
  `first_prof_recipes` text DEFAULT NULL,
  `second_prof_skill` smallint(5) unsigned NOT NULL DEFAULT 0,
  `second_prof_value` smallint(5) unsigned NOT NULL DEFAULT 0,
  `second_prof_rank` smallint(5) unsigned NOT NULL DEFAULT 0,
  `second_prof_recipes` text DEFAULT NULL,
  UNIQUE KEY `guid_key` (`guid`),
  KEY `guildid_key` (`guildid`),
  KEY `guildid_rank_key` (`guildid`,`rank`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild System';

/*Data for the table `guild_member` */

/*Table structure for table `guild_member_withdraw` */

DROP TABLE IF EXISTS `guild_member_withdraw`;

CREATE TABLE `guild_member_withdraw` (
  `guid` int(10) unsigned NOT NULL,
  `tab0` int(10) unsigned NOT NULL DEFAULT 0,
  `tab1` int(10) unsigned NOT NULL DEFAULT 0,
  `tab2` int(10) unsigned NOT NULL DEFAULT 0,
  `tab3` int(10) unsigned NOT NULL DEFAULT 0,
  `tab4` int(10) unsigned NOT NULL DEFAULT 0,
  `tab5` int(10) unsigned NOT NULL DEFAULT 0,
  `tab6` int(10) unsigned NOT NULL DEFAULT 0,
  `tab7` int(10) unsigned NOT NULL DEFAULT 0,
  `money` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild Member Daily Withdraws';

/*Data for the table `guild_member_withdraw` */

/*Table structure for table `guild_newslog` */

DROP TABLE IF EXISTS `guild_newslog`;

CREATE TABLE `guild_newslog` (
  `guildid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Guild Identificator',
  `LogGuid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Log record identificator - auxiliary column',
  `EventType` tinyint(3) unsigned NOT NULL DEFAULT 0 COMMENT 'Event type',
  `PlayerGuid` int(10) unsigned NOT NULL DEFAULT 0,
  `Flags` int(10) unsigned NOT NULL DEFAULT 0,
  `Value` int(10) unsigned NOT NULL DEFAULT 0,
  `TimeStamp` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Event UNIX time',
  PRIMARY KEY (`guildid`,`LogGuid`),
  KEY `guildid_key` (`guildid`),
  KEY `Idx_PlayerGuid` (`PlayerGuid`),
  KEY `Idx_LogGuid` (`LogGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_newslog` */

/*Table structure for table `guild_rank` */

DROP TABLE IF EXISTS `guild_rank`;

CREATE TABLE `guild_rank` (
  `guildid` int(10) unsigned NOT NULL DEFAULT 0,
  `rindex` tinyint(3) unsigned NOT NULL,
  `rid` tinyint(3) unsigned NOT NULL,
  `rname` varchar(20) NOT NULL DEFAULT '',
  `rights` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `BankMoneyPerDay` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guildid`,`rid`),
  KEY `Idx_rid` (`rid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild System';

/*Data for the table `guild_rank` */

/*Table structure for table `guild_reputation` */

DROP TABLE IF EXISTS `guild_reputation`;

CREATE TABLE `guild_reputation` (
  `guid` int(10) unsigned NOT NULL,
  `guild` int(10) unsigned NOT NULL,
  `reputation` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `guild_reputation` */

/*Table structure for table `instance` */

DROP TABLE IF EXISTS `instance`;

CREATE TABLE `instance` (
  `id` int(10) unsigned NOT NULL DEFAULT 0,
  `map` smallint(5) unsigned NOT NULL DEFAULT 0,
  `resettime` int(10) unsigned NOT NULL DEFAULT 0,
  `difficulty` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `lfg` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `completedEncounters` int(10) unsigned NOT NULL DEFAULT 0,
  `data` tinytext NOT NULL,
  PRIMARY KEY (`id`),
  KEY `map` (`map`),
  KEY `resettime` (`resettime`),
  KEY `difficulty` (`difficulty`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `instance` */

/*Table structure for table `instance_reset` */

DROP TABLE IF EXISTS `instance_reset`;

CREATE TABLE `instance_reset` (
  `mapid` smallint(5) unsigned NOT NULL DEFAULT 0,
  `difficulty` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `resettime` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`mapid`,`difficulty`),
  KEY `difficulty` (`difficulty`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `instance_reset` */

/*Table structure for table `item_deleted` */

DROP TABLE IF EXISTS `item_deleted`;

CREATE TABLE `item_deleted` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `owner_guid` int(11) NOT NULL,
  `old_item_guid` int(11) NOT NULL,
  `item_entry` int(11) NOT NULL,
  `item_count` int(11) NOT NULL,
  `delete_date` int(11) NOT NULL,
  `delete_type` int(11) NOT NULL,
  `restored` tinyint(1) NOT NULL DEFAULT 0,
  `restore_date` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `owner_guid_old_item_guid` (`owner_guid`,`old_item_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `item_deleted` */

/*Table structure for table `item_instance` */

DROP TABLE IF EXISTS `item_instance`;

CREATE TABLE `item_instance` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `itemEntry` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `owner_guid` int(10) unsigned NOT NULL DEFAULT 0,
  `creatorGuid` int(10) unsigned NOT NULL DEFAULT 0,
  `giftCreatorGuid` int(10) unsigned NOT NULL DEFAULT 0,
  `count` int(10) unsigned NOT NULL DEFAULT 1,
  `duration` int(10) NOT NULL DEFAULT 0,
  `charges` tinytext DEFAULT NULL,
  `flags` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `enchantments` text NOT NULL,
  `randomPropertyId` smallint(5) NOT NULL DEFAULT 0,
  `reforgeID` int(10) NOT NULL DEFAULT 0,
  `transmogrifyId` int(10) NOT NULL DEFAULT 0,
  `upgradeID` int(10) NOT NULL DEFAULT 0,
  `durability` smallint(5) unsigned NOT NULL DEFAULT 0,
  `playedTime` int(10) unsigned NOT NULL DEFAULT 0,
  `text` text DEFAULT NULL,
  `pet_species` int(11) unsigned NOT NULL,
  `pet_breed` int(11) unsigned NOT NULL,
  `pet_quality` int(11) unsigned NOT NULL,
  `pet_level` int(11) unsigned NOT NULL,
  PRIMARY KEY (`guid`),
  KEY `idx_owner_guid` (`owner_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Item System';

/*Data for the table `item_instance` */

/*Table structure for table `item_loot_items` */

DROP TABLE IF EXISTS `item_loot_items`;

CREATE TABLE `item_loot_items` (
  `container_id` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'guid of container (item_instance.guid)',
  `item_id` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'loot item entry (item_instance.itemEntry)',
  `item_count` int(10) NOT NULL DEFAULT 0 COMMENT 'stack size',
  `follow_rules` tinyint(1) NOT NULL DEFAULT 0 COMMENT 'follow loot rules',
  `ffa` tinyint(1) NOT NULL DEFAULT 0 COMMENT 'free-for-all',
  `blocked` tinyint(1) NOT NULL DEFAULT 0,
  `counted` tinyint(1) NOT NULL DEFAULT 0,
  `under_threshold` tinyint(1) NOT NULL DEFAULT 0,
  `needs_quest` tinyint(1) NOT NULL DEFAULT 0 COMMENT 'quest drop',
  `rnd_prop` int(10) NOT NULL DEFAULT 0 COMMENT 'random enchantment added when originally rolled',
  `rnd_suffix` int(10) NOT NULL DEFAULT 0 COMMENT 'random suffix added when originally rolled'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `item_loot_items` */

/*Table structure for table `item_loot_money` */

DROP TABLE IF EXISTS `item_loot_money`;

CREATE TABLE `item_loot_money` (
  `container_id` int(10) NOT NULL DEFAULT 0 COMMENT 'guid of container (item_instance.guid)',
  `money` int(10) NOT NULL DEFAULT 0 COMMENT 'money loot (in copper)'
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

/*Data for the table `item_loot_money` */

/*Table structure for table `item_refund_instance` */

DROP TABLE IF EXISTS `item_refund_instance`;

CREATE TABLE `item_refund_instance` (
  `item_guid` int(10) unsigned NOT NULL COMMENT 'Item GUID',
  `player_guid` int(10) unsigned NOT NULL COMMENT 'Player GUID',
  `paidMoney` int(10) unsigned NOT NULL DEFAULT 0,
  `paidExtendedCost` smallint(5) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`item_guid`,`player_guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Item Refund System';

/*Data for the table `item_refund_instance` */

/*Table structure for table `item_soulbound_trade_data` */

DROP TABLE IF EXISTS `item_soulbound_trade_data`;

CREATE TABLE `item_soulbound_trade_data` (
  `itemGuid` int(10) unsigned NOT NULL COMMENT 'Item GUID',
  `allowedPlayers` text NOT NULL COMMENT 'Space separated GUID list of players who can receive this item in trade',
  PRIMARY KEY (`itemGuid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Item Refund System';

/*Data for the table `item_soulbound_trade_data` */

/*Table structure for table `lag_reports` */

DROP TABLE IF EXISTS `lag_reports`;

CREATE TABLE `lag_reports` (
  `reportId` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `lagType` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `mapId` smallint(5) unsigned NOT NULL DEFAULT 0,
  `posX` float NOT NULL DEFAULT 0,
  `posY` float NOT NULL DEFAULT 0,
  `posZ` float NOT NULL DEFAULT 0,
  `latency` int(10) unsigned NOT NULL DEFAULT 0,
  `createTime` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`reportId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player System';

/*Data for the table `lag_reports` */

/*Table structure for table `lfg_data` */

DROP TABLE IF EXISTS `lfg_data`;

CREATE TABLE `lfg_data` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `dungeon` int(10) unsigned NOT NULL DEFAULT 0,
  `state` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='LFG Data';

/*Data for the table `lfg_data` */

/*Table structure for table `mail` */

DROP TABLE IF EXISTS `mail`;

CREATE TABLE `mail` (
  `id` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Identifier',
  `messageType` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `stationery` tinyint(3) NOT NULL DEFAULT 41,
  `mailTemplateId` smallint(5) unsigned NOT NULL DEFAULT 0,
  `sender` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Character Global Unique Identifier',
  `receiver` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Character Global Unique Identifier',
  `subject` longtext DEFAULT NULL,
  `body` longtext DEFAULT NULL,
  `has_items` tinyint(3) unsigned NOT NULL DEFAULT 0,
  `expire_time` int(10) unsigned NOT NULL DEFAULT 0,
  `deliver_time` int(10) unsigned NOT NULL DEFAULT 0,
  `money` bigint(20) unsigned NOT NULL DEFAULT 0,
  `cod` bigint(20) unsigned NOT NULL DEFAULT 0,
  `checked` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`),
  KEY `idx_receiver` (`receiver`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Mail System';

/*Data for the table `mail` */

/*Table structure for table `mail_items` */

DROP TABLE IF EXISTS `mail_items`;

CREATE TABLE `mail_items` (
  `mail_id` int(10) unsigned NOT NULL DEFAULT 0,
  `item_guid` int(10) unsigned NOT NULL DEFAULT 0,
  `receiver` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Character Global Unique Identifier',
  PRIMARY KEY (`item_guid`),
  KEY `idx_receiver` (`receiver`),
  KEY `idx_mail_id` (`mail_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC;

/*Data for the table `mail_items` */

/*Table structure for table `pet_aura` */

DROP TABLE IF EXISTS `pet_aura`;

CREATE TABLE `pet_aura` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `slot` tinyint(3) unsigned NOT NULL,
  `caster_guid` bigint(20) unsigned NOT NULL DEFAULT 0,
  `item_guid` bigint(20) unsigned NOT NULL DEFAULT 0,
  `spell` mediumint(8) unsigned NOT NULL DEFAULT 0,
  `effect_mask` int(10) unsigned NOT NULL DEFAULT 0,
  `recalculate_mask` int(10) unsigned DEFAULT 0,
  `stackcount` tinyint(3) unsigned NOT NULL DEFAULT 1,
  `maxduration` int(11) NOT NULL DEFAULT 0,
  `remaintime` int(11) NOT NULL DEFAULT 0,
  `remaincharges` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`caster_guid`,`item_guid`,`spell`,`effect_mask`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `pet_aura` */

/*Table structure for table `pet_aura_effect` */

DROP TABLE IF EXISTS `pet_aura_effect`;

CREATE TABLE `pet_aura_effect` (
  `guid` int(10) unsigned NOT NULL,
  `slot` tinyint(3) unsigned NOT NULL,
  `effect` tinyint(3) unsigned NOT NULL,
  `base_amount` int(10) NOT NULL DEFAULT 0,
  `amount` int(10) NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`slot`,`effect`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `pet_aura_effect` */

/*Table structure for table `pet_spell` */

DROP TABLE IF EXISTS `pet_spell`;

CREATE TABLE `pet_spell` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier',
  `spell` mediumint(8) unsigned NOT NULL DEFAULT 0 COMMENT 'Spell Identifier',
  `active` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Pet System';

/*Data for the table `pet_spell` */

/*Table structure for table `pet_spell_cooldown` */

DROP TABLE IF EXISTS `pet_spell_cooldown`;

CREATE TABLE `pet_spell_cooldown` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0 COMMENT 'Global Unique Identifier, Low part',
  `spell` mediumint(8) unsigned NOT NULL DEFAULT 0 COMMENT 'Spell Identifier',
  `time` bigint(20) unsigned NOT NULL DEFAULT 0,
  `category_end` bigint(20) unsigned DEFAULT 0,
  PRIMARY KEY (`guid`,`spell`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `pet_spell_cooldown` */

/*Table structure for table `petition` */

DROP TABLE IF EXISTS `petition`;

CREATE TABLE `petition` (
  `ownerguid` int(10) unsigned NOT NULL,
  `petitionguid` int(10) unsigned DEFAULT 0,
  `name` varchar(24) NOT NULL,
  `type` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`ownerguid`,`type`),
  UNIQUE KEY `index_ownerguid_petitionguid` (`ownerguid`,`petitionguid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild System';

/*Data for the table `petition` */

/*Table structure for table `petition_sign` */

DROP TABLE IF EXISTS `petition_sign`;

CREATE TABLE `petition_sign` (
  `ownerguid` int(10) unsigned NOT NULL,
  `petitionguid` int(10) unsigned NOT NULL DEFAULT 0,
  `playerguid` int(10) unsigned NOT NULL DEFAULT 0,
  `player_account` int(10) unsigned NOT NULL DEFAULT 0,
  `type` tinyint(3) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`petitionguid`,`playerguid`),
  KEY `Idx_playerguid` (`playerguid`),
  KEY `Idx_ownerguid` (`ownerguid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Guild System';

/*Data for the table `petition_sign` */

/*Table structure for table `players_reports_status` */

DROP TABLE IF EXISTS `players_reports_status`;

CREATE TABLE `players_reports_status` (
  `guid` int(10) unsigned NOT NULL DEFAULT 0,
  `creation_time` int(10) unsigned NOT NULL DEFAULT 0,
  `average` float NOT NULL DEFAULT 0,
  `total_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  `speed_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  `fly_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  `jump_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  `waterwalk_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  `teleportplane_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  `climb_reports` bigint(20) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `players_reports_status` */

/*Table structure for table `pool_quest_save` */

DROP TABLE IF EXISTS `pool_quest_save`;

CREATE TABLE `pool_quest_save` (
  `pool_id` int(10) unsigned NOT NULL DEFAULT 0,
  `quest_id` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`pool_id`,`quest_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `pool_quest_save` */

insert  into `pool_quest_save`(`pool_id`,`quest_id`) values 
(349,14104),
(350,13904),
(351,13914),
(352,11379),
(353,11665),
(354,13422),
(356,11372),
(357,11387),
(358,25159),
(359,25154),
(360,29364),
(361,26235),
(362,29332),
(363,26192),
(364,29355),
(365,29313),
(366,26543),
(367,29348),
(368,29361),
(369,26414),
(370,29347),
(371,29323),
(372,28063),
(372,28130),
(373,27949),
(373,28046),
(374,27975),
(374,27978),
(375,27944),
(375,27972),
(376,28687),
(376,28721),
(377,28678),
(377,28683),
(378,28698),
(378,28700),
(379,28690),
(379,28692),
(380,12726),
(381,12762),
(382,12741),
(383,12760),
(5662,13673),
(5663,13762),
(5664,13769),
(5665,13774),
(5666,13779),
(5667,13783),
(5668,13669),
(5669,13600),
(5670,13741),
(5671,13746),
(5672,13759),
(5673,13752),
(5674,13101),
(5675,13112),
(5676,13834),
(5677,12962),
(5678,24584),
(12001,31523),
(12002,31706),
(12003,31271);

/*Table structure for table `rated_pvp_info` */

DROP TABLE IF EXISTS `rated_pvp_info`;

CREATE TABLE `rated_pvp_info` (
  `guid` int(10) unsigned NOT NULL,
  `slot` tinyint(3) unsigned NOT NULL,
  `season` smallint(5) unsigned NOT NULL,
  `rank` smallint(5) unsigned DEFAULT 0,
  `rating` smallint(5) unsigned DEFAULT 0,
  `matchmaker_rating` smallint(5) unsigned DEFAULT 0,
  `week_best` smallint(5) unsigned DEFAULT 0,
  `week_games` smallint(5) unsigned DEFAULT 0,
  `week_wins` smallint(5) unsigned DEFAULT 0,
  `season_best` smallint(5) unsigned DEFAULT 0,
  `season_games` smallint(5) unsigned DEFAULT 0,
  `season_wins` smallint(5) unsigned DEFAULT 0,
  `last_week_best` smallint(5) unsigned DEFAULT 0,
  `bonus_reward` tinyint(1) NOT NULL DEFAULT 0,
  `win_streak` int(10) unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`,`slot`,`season`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `rated_pvp_info` */

/*Table structure for table `reserved_name` */

DROP TABLE IF EXISTS `reserved_name`;

CREATE TABLE `reserved_name` (
  `name` varchar(12) NOT NULL DEFAULT '',
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Player Reserved Names';

/*Data for the table `reserved_name` */

/*Table structure for table `ticket_bug` */

DROP TABLE IF EXISTS `ticket_bug`;

CREATE TABLE `ticket_bug` (
  `ticketId` int(10) unsigned NOT NULL,
  `playerGuid` bigint(20) unsigned NOT NULL,
  `bugNote` text NOT NULL,
  `ticketCreateTime` int(10) unsigned NOT NULL DEFAULT 0,
  `mapId` smallint(5) unsigned NOT NULL DEFAULT 0,
  `posX` float NOT NULL DEFAULT 0,
  `posY` float NOT NULL DEFAULT 0,
  `posZ` float NOT NULL DEFAULT 0,
  `orientation` float NOT NULL DEFAULT 0,
  `closedBy` bigint(20) NOT NULL DEFAULT 0,
  `assignedTo` bigint(20) unsigned NOT NULL DEFAULT 0 COMMENT 'GUID of admin to whom ticket is assigned',
  `comment` text NOT NULL,
  PRIMARY KEY (`ticketId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `ticket_bug` */

/*Table structure for table `warden_action` */

DROP TABLE IF EXISTS `warden_action`;

CREATE TABLE `warden_action` (
  `wardenId` smallint(5) unsigned NOT NULL,
  `action` tinyint(3) unsigned DEFAULT NULL,
  PRIMARY KEY (`wardenId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `warden_action` */

/*Table structure for table `worldstates` */

DROP TABLE IF EXISTS `worldstates`;

CREATE TABLE `worldstates` (
  `entry` int(10) unsigned NOT NULL DEFAULT 0,
  `value` int(10) unsigned NOT NULL DEFAULT 0,
  `comment` tinytext DEFAULT NULL,
  PRIMARY KEY (`entry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Variable Saves';

/*Data for the table `worldstates` */

insert  into `worldstates`(`entry`,`value`,`comment`) values 
(3781,9000000,NULL),
(3801,0,NULL),
(3802,1,NULL),
(20001,1460199600,'NextArenaPointDistributionTime'),
(20002,1460242155,'NextWeeklyQuestResetTime'),
(20003,1459681200,'NextBGRandomDailyResetTime'),
(20004,0,'cleaning_flags'),
(20006,1459681200,NULL),
(20007,1462078800,NULL),
(20050,1,NULL);

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
