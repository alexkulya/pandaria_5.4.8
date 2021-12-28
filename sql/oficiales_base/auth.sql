/*
SQLyog Ultimate v11.11 (64 bit)
MySQL - 5.6.26-log : Database - auth
*********************************************************************
*/

/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;
CREATE DATABASE /*!32312 IF NOT EXISTS*/`auth` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `auth`;

/*Table structure for table `account` */

DROP TABLE IF EXISTS `account`;

CREATE TABLE `account` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Identifier',
  `username` varchar(32) NOT NULL DEFAULT '',
  `battlenet_account` varchar(32) NOT NULL DEFAULT '',
  `sha_pass_hash` varchar(40) NOT NULL DEFAULT '',
  `sessionkey` varchar(80) NOT NULL DEFAULT '',
  `v` varchar(64) NOT NULL DEFAULT '',
  `s` varchar(64) NOT NULL DEFAULT '',
  `token_key` varchar(100) NOT NULL DEFAULT '',
  `email` varchar(255) NOT NULL DEFAULT '',
  `reg_mail` varchar(255) NOT NULL DEFAULT '',
  `joindate` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_ip` varchar(15) NOT NULL DEFAULT '127.0.0.1',
  `failed_logins` int(10) unsigned NOT NULL DEFAULT '0',
  `locked` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `last_login` timestamp NULL DEFAULT NULL,
  `online` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `expansion` tinyint(3) unsigned NOT NULL DEFAULT '4',
  `mutetime` bigint(20) NOT NULL DEFAULT '0',
  `mutereason` varchar(255) NOT NULL DEFAULT '',
  `muteby` varchar(50) NOT NULL DEFAULT '',
  `locale` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `os` varchar(4) NOT NULL DEFAULT '',
  `recruiter` int(10) unsigned NOT NULL DEFAULT '0',
  `project_member_id` int(30) unsigned NOT NULL DEFAULT '0',
  `rank` int(5) DEFAULT NULL,
  `staff_id` int(5) DEFAULT NULL,
  `vp` int(5) DEFAULT NULL,
  `dp` int(10) NOT NULL DEFAULT '0',
  `isactive` varchar(50) DEFAULT NULL,
  `activation` varchar(256) DEFAULT NULL,
  `invited_by` varchar(32) NOT NULL DEFAULT '',
  `inv_friend_acc` varchar(32) NOT NULL DEFAULT '',
  `rewarded` int(4) NOT NULL DEFAULT '0',
  `flags` int(5) NOT NULL DEFAULT '0',
  `gmlevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `active_realm_id` int(11) unsigned NOT NULL DEFAULT '0',
  `online_mute_timer` bigint(20) unsigned NOT NULL DEFAULT '0',
  `active_mute_id` int(11) unsigned NOT NULL DEFAULT '0',
  `project_verified` tinyint(1) NOT NULL DEFAULT '0',
  `cash` int(10) NOT NULL DEFAULT '0',
  `project_is_free` tinyint(1) NOT NULL DEFAULT '0',
  `project_is_temp` tinyint(1) NOT NULL DEFAULT '0',
  `project_unban_count` tinyint(4) NOT NULL DEFAULT '0',
  `project_antierror` int(10) unsigned DEFAULT NULL,
  `project_attached` int(10) unsigned DEFAULT NULL,
  `project_passchange` int(10) unsigned NOT NULL DEFAULT '0',
  `project_vote_time` bigint(20) NOT NULL DEFAULT '0',
  `project_hwid` varchar(40) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_username` (`username`),
  KEY `idx_id` (`id`) USING BTREE,
  KEY `idx_sha` (`sha_pass_hash`) USING BTREE,
  KEY `idx_session` (`sessionkey`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 COMMENT='Account System';

/*Data for the table `account` */

insert  into `account`(`id`,`username`,`battlenet_account`,`sha_pass_hash`,`sessionkey`,`v`,`s`,`token_key`,`email`,`reg_mail`,`joindate`,`last_ip`,`failed_logins`,`locked`,`last_login`,`online`,`expansion`,`mutetime`,`mutereason`,`muteby`,`locale`,`os`,`recruiter`,`project_member_id`,`rank`,`staff_id`,`vp`,`dp`,`isactive`,`activation`,`invited_by`,`inv_friend_acc`,`rewarded`,`flags`,`gmlevel`,`active_realm_id`,`online_mute_timer`,`active_mute_id`,`project_verified`,`cash`,`project_is_free`,`project_is_temp`,`project_unban_count`,`project_antierror`,`project_attached`,`project_passchange`,`project_vote_time`,`project_hwid`) values (1,'TEST','','3D0D99423E31FCC67A6745EC89D70D700344BC76','A4BEAD4BBD62A0C1F5C1BA3CE857C7E587B1AFD1EBF2543F4EAFFC87EC09DE8EF51AA142D04ED259','77733268AF0D167253BC9097A6BDDAA4E55B66EBFBC5432350DF549084F29D75','CC28EADCB56862623B8211A43B96F5FD1B8667464349816AE225487CC0425AB1','','','','2021-11-03 17:57:54','25.90.193.232',0,0,'2021-11-04 20:22:34',0,4,0,'','',6,'Win',0,0,NULL,NULL,NULL,0,NULL,NULL,'','',0,0,0,0,0,0,0,0,0,0,0,NULL,NULL,0,0,''),(2,'TEST1','','313262BAA8B8DFB82560FD58042EC344A357CAA7','75F3AE12338B032C8660A64E1635105578CD62FC3D89C594EBD98488F3F093E673BCEA40EC192124','3DD16E9E1162FAF647FAE01723410DA6EA2CB8172A2A69AE53500C4CD5892CD3','EEA92B1355C099AEC89918A1F73F1CF9568F910ABF986AF4DA9B2D1D94E99229','','','','2021-11-04 19:30:35','25.90.193.232',0,0,'2021-11-04 19:31:00',0,4,0,'','',6,'Win',0,0,NULL,NULL,NULL,0,NULL,NULL,'','',0,0,0,0,0,0,0,0,0,0,0,NULL,NULL,0,0,'');

/*Table structure for table `account_access` */

DROP TABLE IF EXISTS `account_access`;

CREATE TABLE `account_access` (
  `id` int(10) unsigned NOT NULL,
  `gmlevel` tinyint(3) unsigned NOT NULL,
  `RealmID` int(11) NOT NULL DEFAULT '-1',
  `name` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`,`RealmID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_access` */

insert  into `account_access`(`id`,`gmlevel`,`RealmID`,`name`) values (1,100,-1,NULL);

/*Table structure for table `account_banned` */

DROP TABLE IF EXISTS `account_banned`;

CREATE TABLE `account_banned` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Account id',
  `realm` int(11) NOT NULL,
  `bandate` int(10) unsigned NOT NULL DEFAULT '0',
  `unbandate` int(10) unsigned NOT NULL DEFAULT '0',
  `bannedby` varchar(50) NOT NULL,
  `banreason` varchar(255) NOT NULL,
  `active` tinyint(3) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Ban List';

/*Data for the table `account_banned` */

/*Table structure for table `account_boost` */

DROP TABLE IF EXISTS `account_boost`;

CREATE TABLE `account_boost` (
  `id` int(11) NOT NULL DEFAULT '0',
  `realmid` int(11) unsigned NOT NULL DEFAULT '1',
  `counter` int(1) unsigned NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_boost` */

/*Table structure for table `account_muted` */

DROP TABLE IF EXISTS `account_muted`;

CREATE TABLE `account_muted` (
  `id` int(10) NOT NULL,
  `realmid` int(3) NOT NULL DEFAULT '0',
  `acc_id` int(11) NOT NULL,
  `char_id` int(11) NOT NULL,
  `mute_acc` varchar(32) COLLATE utf8_bin NOT NULL,
  `mute_name` varchar(50) COLLATE utf8_bin NOT NULL,
  `mute_date` bigint(40) NOT NULL,
  `muted_by` varchar(50) COLLATE utf8_bin NOT NULL,
  `mute_time` bigint(20) NOT NULL,
  `mute_reason` varchar(255) COLLATE utf8_bin NOT NULL,
  `public_channels_only` tinyint(3) NOT NULL,
  PRIMARY KEY (`realmid`,`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;

/*Data for the table `account_muted` */

/*Table structure for table `account_premium` */

DROP TABLE IF EXISTS `account_premium`;

CREATE TABLE `account_premium` (
  `id` int(11) NOT NULL DEFAULT '0' COMMENT 'Account id',
  `setdate` bigint(40) NOT NULL DEFAULT '0',
  `unsetdate` bigint(40) NOT NULL DEFAULT '0',
  `active` tinyint(4) NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`,`setdate`),
  KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Premium Accounts';

/*Data for the table `account_premium` */

/*Table structure for table `account_premium_panda` */

DROP TABLE IF EXISTS `account_premium_panda`;

CREATE TABLE `account_premium_panda` (
  `id` int(11) NOT NULL DEFAULT '0',
  `pveMode` tinyint(1) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `account_premium_panda` */

/*Table structure for table `arena_game_id` */

DROP TABLE IF EXISTS `arena_game_id`;

CREATE TABLE `arena_game_id` (
  `game_id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `realm_id` tinyint(3) unsigned NOT NULL,
  PRIMARY KEY (`game_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `arena_game_id` */

/*Table structure for table `arena_games` */

DROP TABLE IF EXISTS `arena_games`;

CREATE TABLE `arena_games` (
  `gameid` bigint(20) NOT NULL DEFAULT '0',
  `teamid` bigint(20) NOT NULL DEFAULT '0',
  `guid` bigint(20) NOT NULL DEFAULT '0',
  `changeType` int(11) NOT NULL,
  `ratingChange` int(11) NOT NULL,
  `teamRating` int(11) NOT NULL,
  `matchMakerRating` smallint(5) unsigned DEFAULT NULL,
  `damageDone` int(11) NOT NULL,
  `deaths` int(11) NOT NULL,
  `healingDone` int(11) NOT NULL,
  `damageTaken` int(11) NOT NULL,
  `healingTaken` int(11) NOT NULL,
  `killingBlows` int(11) NOT NULL,
  `damageAbsorbed` int(11) unsigned NOT NULL,
  `timeControlled` int(11) unsigned NOT NULL,
  `aurasDispelled` int(11) unsigned NOT NULL,
  `aurasStolen` int(11) unsigned NOT NULL,
  `highLatencyTimes` int(11) unsigned NOT NULL,
  `spellsPrecast` int(11) unsigned NOT NULL,
  `mapId` int(11) NOT NULL,
  `start` int(11) NOT NULL,
  `end` int(11) NOT NULL,
  `class` tinyint(3) unsigned DEFAULT NULL,
  `season` smallint(5) unsigned DEFAULT NULL,
  `type` tinyint(3) unsigned DEFAULT NULL,
  `realmid` tinyint(3) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`gameid`,`teamid`,`guid`),
  KEY `idx__teamid` (`teamid`),
  KEY `idx__season__class__type` (`season`,`class`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='WoWArmory Game Chart';

/*Data for the table `arena_games` */

/*Table structure for table `arena_match_stat` */

DROP TABLE IF EXISTS `arena_match_stat`;

CREATE TABLE `arena_match_stat` (
  `realm` tinyint(3) unsigned NOT NULL,
  `teamGuid` int(10) unsigned NOT NULL,
  `teamName` text NOT NULL,
  `type` tinyint(3) unsigned NOT NULL,
  `teamRating` smallint(5) unsigned NOT NULL,
  `player` int(10) unsigned NOT NULL,
  `class` tinyint(3) unsigned NOT NULL,
  `name` text NOT NULL,
  `time` int(10) unsigned NOT NULL,
  `mapID` smallint(5) unsigned NOT NULL,
  `instanceID` int(10) unsigned NOT NULL,
  `status` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`teamGuid`,`realm`,`player`,`instanceID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `arena_match_stat` */

/*Table structure for table `arena_team` */

DROP TABLE IF EXISTS `arena_team`;

CREATE TABLE `arena_team` (
  `arenaTeamId` int(10) unsigned NOT NULL DEFAULT '0',
  `name` varchar(24) NOT NULL,
  `captainGuid` int(10) unsigned NOT NULL DEFAULT '0',
  `realmNumber` int(10) unsigned NOT NULL DEFAULT '1',
  `type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `rating` smallint(5) unsigned NOT NULL DEFAULT '0',
  `matchMakerRating` smallint(5) unsigned NOT NULL DEFAULT '1500',
  `seasonGames` smallint(5) unsigned NOT NULL DEFAULT '0',
  `seasonWins` smallint(5) unsigned NOT NULL DEFAULT '0',
  `weekGames` smallint(5) unsigned NOT NULL DEFAULT '0',
  `weekWins` smallint(5) unsigned NOT NULL DEFAULT '0',
  `rank` int(10) unsigned NOT NULL DEFAULT '0',
  `backgroundColor` int(10) unsigned NOT NULL DEFAULT '0',
  `emblemStyle` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `emblemColor` int(10) unsigned NOT NULL DEFAULT '0',
  `borderStyle` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `borderColor` int(10) unsigned NOT NULL DEFAULT '0',
  `season` int(10) unsigned NOT NULL DEFAULT '0',
  `created` int(10) unsigned NOT NULL DEFAULT '0',
  `deleted` int(10) unsigned NOT NULL DEFAULT '0',
  `realmid` tinyint(3) unsigned NOT NULL DEFAULT '1',
  PRIMARY KEY (`arenaTeamId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `arena_team` */

/*Table structure for table `arena_team_member` */

DROP TABLE IF EXISTS `arena_team_member`;

CREATE TABLE `arena_team_member` (
  `arenaTeamId` int(10) unsigned NOT NULL DEFAULT '0',
  `guid` int(10) unsigned NOT NULL DEFAULT '0',
  `realmid` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `personalRating` smallint(5) NOT NULL DEFAULT '0',
  `matchMakerRating` smallint(5) unsigned NOT NULL DEFAULT '1500',
  `weekGames` smallint(5) unsigned NOT NULL DEFAULT '0',
  `weekWins` smallint(5) unsigned NOT NULL DEFAULT '0',
  `seasonGames` smallint(5) unsigned NOT NULL DEFAULT '0',
  `seasonWins` smallint(5) unsigned NOT NULL DEFAULT '0',
  `name` varchar(12) NOT NULL,
  `class` tinyint(3) unsigned NOT NULL,
  `joined` int(10) unsigned NOT NULL DEFAULT '0',
  `removed` int(10) unsigned NOT NULL DEFAULT '0',
  `itemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `lastILvlCheck` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`arenaTeamId`,`guid`,`realmid`),
  KEY `guid` (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `arena_team_member` */

/*Table structure for table `armory_game_chart` */

DROP TABLE IF EXISTS `armory_game_chart`;

CREATE TABLE `armory_game_chart` (
  `gameid` int(11) NOT NULL,
  `realmid` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `teamid` int(11) NOT NULL,
  `guid` int(11) NOT NULL,
  `changeType` int(11) NOT NULL,
  `ratingChange` int(11) NOT NULL,
  `teamRating` int(11) NOT NULL,
  `damageDone` int(11) NOT NULL,
  `deaths` int(11) NOT NULL,
  `healingDone` int(11) NOT NULL,
  `damageTaken` int(11) NOT NULL,
  `healingTaken` int(11) NOT NULL,
  `killingBlows` int(11) NOT NULL,
  `mapId` int(11) NOT NULL,
  `start` int(11) NOT NULL,
  `end` int(11) NOT NULL,
  `class` tinyint(3) unsigned DEFAULT NULL,
  `season` smallint(5) unsigned DEFAULT NULL,
  `type` tinyint(3) unsigned DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `armory_game_chart` */

/*Table structure for table `autobroadcast` */

DROP TABLE IF EXISTS `autobroadcast`;

CREATE TABLE `autobroadcast` (
  `realmid` int(11) NOT NULL DEFAULT '-1',
  `id` tinyint(3) unsigned NOT NULL AUTO_INCREMENT,
  `weight` tinyint(3) unsigned DEFAULT '1',
  `text` longtext NOT NULL,
  PRIMARY KEY (`id`,`realmid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `autobroadcast` */

/*Table structure for table `battleground_games` */

DROP TABLE IF EXISTS `battleground_games`;

CREATE TABLE `battleground_games` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `season` int(10) unsigned NOT NULL,
  `realm_id` int(10) unsigned NOT NULL,
  `map_id` int(10) unsigned NOT NULL,
  `instance_id` int(10) unsigned NOT NULL,
  `is_random_bg` tinyint(3) unsigned NOT NULL,
  `winner` enum('H','A','N') NOT NULL,
  `start_time` int(10) unsigned NOT NULL,
  `duration` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `realm_id` (`realm_id`),
  KEY `map_id` (`map_id`),
  KEY `season` (`season`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `battleground_games` */

/*Table structure for table `battleground_ladder_criteria` */

DROP TABLE IF EXISTS `battleground_ladder_criteria`;

CREATE TABLE `battleground_ladder_criteria` (
  `criteria` enum('Win','Loss','FastWin','Kills','ObjectiveCaptures','ObjectiveDefenses','DailyWins','DailyKills','SeasonKills','SeasonWinsAV','SeasonWinsWG','SeasonWinsAB','SeasonWinsEotS','SeasonWinsSotA','SeasonWinsIoC','TotalWins','TotalDraws','TotalLosses','TotalKills','TotalLeavesBeforeGame','TotalLeavesDuringGame') NOT NULL COMMENT 'Name of the column in `battleground_ladder_progress` if `type` is ''Daily'', ''Season'' or ''Statistic''',
  `type` enum('Statistic','Season','Daily','Alterac Valley','Warsong Gulch','Arathi Basin','Eye of the Storm','Strand of the Ancients','Isle of Conquest') NOT NULL COMMENT 'If not set - affects all battlegrounds, if set - overrides global setting only for the specified battleground. Only valid for battleground-specific `type`s',
  `param` int(11) NOT NULL DEFAULT '0',
  `name` tinytext NOT NULL,
  `cap` int(10) unsigned NOT NULL COMMENT 'Maximum count of progress units a player can get',
  `ladder_points_per_progress` int(11) NOT NULL DEFAULT '0' COMMENT 'Repeatable ladder points reward for each unit of progress in this criteria',
  `ladder_points_for_cap` int(11) NOT NULL DEFAULT '0' COMMENT 'One-time ladder points reward for reaching progress cap in this criteria',
  `group_penalty_size` int(11) unsigned NOT NULL DEFAULT '3' COMMENT 'Count of group members at which ladder points penalty from `group_penalty_percent` kicks in',
  `group_penalty_percent` int(11) NOT NULL DEFAULT '0' COMMENT 'Percentage modifier of ladder points for each player in the group above or equal to `group_penalty_size`',
  PRIMARY KEY (`criteria`,`type`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `battleground_ladder_criteria` */

/*Table structure for table `battleground_ladder_rewards` */

DROP TABLE IF EXISTS `battleground_ladder_rewards`;

CREATE TABLE `battleground_ladder_rewards` (
  `season` int(10) unsigned NOT NULL COMMENT 'Battleground season ID',
  `id` int(10) unsigned NOT NULL COMMENT 'Incrementing number identifying this reward set',
  `top` float unsigned NOT NULL COMMENT 'How many players will receive the reward. Depends on `type`',
  `type` enum('Players','Percents') NOT NULL DEFAULT 'Players' COMMENT 'Determines whether the `top` number or `top` percentage of players will receive the reward',
  `money_reward` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Amount in copper',
  `item_reward` tinytext NOT NULL COMMENT 'Format: itemid:count itemid:count ...',
  `loyalty_reward` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Number of Orbs of Loyalty',
  `premium_reward` tinytext NOT NULL COMMENT 'Duration in timestring format (e.g. "30d5h42m10s")',
  `title_reward` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Title ID',
  `mail_subject` tinytext NOT NULL,
  `mail_text` text NOT NULL,
  PRIMARY KEY (`season`,`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `battleground_ladder_rewards` */

/*Table structure for table `battleground_scores` */

DROP TABLE IF EXISTS `battleground_scores`;

CREATE TABLE `battleground_scores` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Unique identifier for each player that participated in the battleground',
  `game_id` int(10) unsigned NOT NULL,
  `team` tinyint(3) unsigned NOT NULL,
  `guid` int(10) unsigned NOT NULL,
  `realm_id` int(10) unsigned NOT NULL,
  `group_index` int(10) unsigned NOT NULL,
  `ladder_points` int(10) NOT NULL,
  `killing_blows` int(10) unsigned NOT NULL,
  `deaths` int(10) unsigned NOT NULL,
  `honorable_kills` int(10) unsigned NOT NULL,
  `damage_done` int(10) unsigned NOT NULL,
  `healing_done` int(10) unsigned NOT NULL,
  `damage_taken` int(10) unsigned NOT NULL,
  `healing_taken` int(10) unsigned NOT NULL,
  `bonus_honor` int(10) unsigned NOT NULL,
  `graveyards_assaulted` int(10) unsigned DEFAULT NULL COMMENT 'Alterac Valley',
  `graveyards_defended` int(10) unsigned DEFAULT NULL COMMENT 'Alterac Valley',
  `towers_assaulted` int(10) unsigned DEFAULT NULL COMMENT 'Alterac Valley',
  `towers_defended` int(10) unsigned DEFAULT NULL COMMENT 'Alterac Valley',
  `mines_captured` int(10) unsigned DEFAULT NULL COMMENT 'Alterac Valley',
  `leaders_killed` int(10) unsigned DEFAULT NULL COMMENT 'Alterac Valley',
  `secondary_objective` int(10) unsigned DEFAULT NULL COMMENT 'Alterac Valley',
  `flag_captures` int(10) unsigned DEFAULT NULL COMMENT 'Warsong Gulch, Eye of the Storm',
  `flag_returns` int(10) unsigned DEFAULT NULL COMMENT 'Warsong Gulch',
  `bases_assaulted` int(10) unsigned DEFAULT NULL COMMENT 'Arathi Basin, Isle of Conquest',
  `bases_defended` int(10) unsigned DEFAULT NULL COMMENT 'Arathi Basin, Isle of Conquest',
  `demolishers_destroyed` int(10) unsigned DEFAULT NULL COMMENT 'Strand of the Ancients',
  `gates_destroyed` int(10) unsigned DEFAULT NULL COMMENT 'Strand of the Ancients',
  PRIMARY KEY (`id`),
  KEY `game_id` (`game_id`),
  KEY `guid` (`guid`),
  KEY `realm_id` (`realm_id`),
  CONSTRAINT `FK_battleground_scores_battleground_games` FOREIGN KEY (`game_id`) REFERENCES `battleground_games` (`id`) ON DELETE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `battleground_scores` */

/*Table structure for table `battleground_seasons` */

DROP TABLE IF EXISTS `battleground_seasons`;

CREATE TABLE `battleground_seasons` (
  `id` tinyint(4) NOT NULL AUTO_INCREMENT,
  `begin` int(10) unsigned NOT NULL,
  `end` int(10) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `battleground_seasons` */

/*Table structure for table `battlenet_account_bans` */

DROP TABLE IF EXISTS `battlenet_account_bans`;

CREATE TABLE `battlenet_account_bans` (
  `id` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Account id',
  `bandate` int(10) unsigned NOT NULL DEFAULT '0',
  `unbandate` int(10) unsigned NOT NULL DEFAULT '0',
  `bannedby` varchar(50) NOT NULL,
  `banreason` varchar(255) NOT NULL,
  PRIMARY KEY (`id`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Ban List';

/*Data for the table `battlenet_account_bans` */

/*Table structure for table `battlenet_accounts` */

DROP TABLE IF EXISTS `battlenet_accounts`;

CREATE TABLE `battlenet_accounts` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Identifier',
  `email` varchar(320) NOT NULL,
  `sha_pass_hash` varchar(64) NOT NULL DEFAULT '',
  `v` varchar(256) NOT NULL DEFAULT '',
  `s` varchar(64) NOT NULL DEFAULT '',
  `sessionKey` varchar(128) NOT NULL DEFAULT '',
  `locked` tinyint(1) unsigned NOT NULL DEFAULT '0',
  `last_login` timestamp NULL DEFAULT NULL,
  `online` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `last_ip` varchar(15) NOT NULL DEFAULT '127.0.0.1',
  `failed_logins` int(10) unsigned NOT NULL DEFAULT '0',
  `project_member_id` int(10) unsigned DEFAULT NULL,
  `project_is_temp` tinyint(1) DEFAULT '0' COMMENT 'nighthold',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Account System';

/*Data for the table `battlenet_accounts` */

/*Table structure for table `battlepay_log` */

DROP TABLE IF EXISTS `battlepay_log`;

CREATE TABLE `battlepay_log` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `accountId` int(11) unsigned NOT NULL,
  `characterGuid` int(10) NOT NULL DEFAULT '0',
  `realm` int(5) unsigned NOT NULL,
  `item` int(10) NOT NULL DEFAULT '0',
  `price` int(5) unsigned NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `battlepay_log` */

/*Table structure for table `bonus_rates` */

DROP TABLE IF EXISTS `bonus_rates`;

CREATE TABLE `bonus_rates` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT COMMENT 'Autoincrementable ID',
  `realmid` int(11) NOT NULL DEFAULT '-1' COMMENT 'RealmID for which the rates would be active. -1 for all realms',
  `active` tinyint(3) unsigned NOT NULL DEFAULT '1' COMMENT 'If set to 0 - this bonus would not be loaded',
  `schedule` varchar(50) NOT NULL DEFAULT '* * * * *' COMMENT 'Cron-style schedule defining the time for the bonus rates period. Multiple periods can be specified with a semicolon separated list',
  `multiplier` float NOT NULL DEFAULT '2' COMMENT 'Rate multiplier (i.e. 2 would change the rates to be twice their usual value during the bonus rates period)',
  `rates` text NOT NULL COMMENT 'Space separated list of rate names as used in config (i.e. "Rate.XP.Kill Rate.Honor")',
  `start_announcement` tinytext COMMENT 'Announcement displayed in chat for all online players when the bonus rate period starts',
  `end_announcement` tinytext COMMENT 'Announcement displayed in chat for all online players when the bonus rate period ends',
  `active_announcement` tinytext COMMENT 'Announcement displayed in chat for all players logging in whenever the bonus rate period is active',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `bonus_rates` */

/*Table structure for table `boost_promotion_executed` */

DROP TABLE IF EXISTS `boost_promotion_executed`;

CREATE TABLE `boost_promotion_executed` (
  `member_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `boost_promotion_executed` */

/*Table structure for table `broadcast_strings` */

DROP TABLE IF EXISTS `broadcast_strings`;

CREATE TABLE `broadcast_strings` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `text` text NOT NULL,
  `next` int(11) unsigned NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `broadcast_strings` */

/*Table structure for table `config` */

DROP TABLE IF EXISTS `config`;

CREATE TABLE `config` (
  `category` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `value` text,
  `default` text,
  `realmid` smallint(6) NOT NULL DEFAULT '-1',
  `description` text,
  `note` text,
  PRIMARY KEY (`name`,`realmid`),
  KEY `option` (`name`),
  KEY `category` (`category`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Here you can put the configs from the worldserver.conf file, so you can change without acessing the machine files.';

/*Data for the table `config` */

insert  into `config`(`category`,`name`,`value`,`default`,`realmid`,`description`,`note`) values ('Players','AllowTwoSide.Interaction.Auction','0','0',1,'Merge all auction houses for players from different teams\nDefault: 0 (Not allowed)\n         1 (Allowed)',NULL),('Players','AllowTwoSide.Interaction.Chat','0','0',-1,'Allow chat assembling between factions.\nDefault:     0',NULL),('AntiCheat','Anticheat.DetectionsEnabled','27','31',1,'Anticheat hack',NULL),('AntiCheat','Anticheat.ReportsForIngameWarnings','70','1',1,'Anticheat hack',NULL),('Rate','BonusRoll.LootChance','31','31',1,'Bonus Roll',NULL),('Dungeon Finder','DungeonFinder.CastDeserter','0','1',1,'Cast Deserter spell at players who leave DF-parties while the dungeons is in progress.\nDefault:     1',NULL),('Dungeon Finder','DungeonFinder.DPSNeeded','1','1',1,'Specifies how many players have to select dps role in order for the party to be eligible for a dungeon.\nDefault:     1',NULL),('Dungeon Finder','DungeonFinder.HealersNeeded','1','1',1,'Specifies how many players have to select healer role in order for the party to be eligible for a dungeon.\nDefault:     1',NULL),('Dungeon Finder','DungeonFinder.KeepQueuesInDungeon','true','1',1,'Specifies how many players have to select healer role in order for the party to be eligible for a dungeon.\nDefault:     1',NULL),('Dungeon Finder','DungeonFinder.OverrideRolesRequired','true','0',1,'If enabled all LFG role checks will use values from DungeonFinder.TanksNeeded, DungeonFinder.HealersNeeded and DungeonFinder.DPSNeeded to determine the number of players required in order for the party to be eligible for a dungeon. Overrides both group and raid dungeon values.\nDefault:     0',NULL),('Dungeon Finder','DungeonFinder.ShortageCheckInterval','60','60',1,'Specifies the interval in seconds at which shortage roles for a queue should be updated.\nDefault:     5',NULL),('Dungeon Finder','DungeonFinder.ShortagePercent','50','50',1,'Specifies at which percent of the ideal role representation ratio in a queue should it grant a Call to Arms reward\nDefault:     50',NULL),('Dungeon Finder','DungeonFinder.TanksNeeded','1','1',1,'Specifies how many players have to select tank role in order for the party to be eligible for a dungeon.\nDefault:     1',NULL),('LFR','LFR.LootChance','100','20',-1,'Chance to get personal loot from any boss',NULL),('Rate','TargetPosRecalculateRange','5','5',1,'Range attack ',NULL),('Misc','VengeanceMultipier','1','1',-1,NULL,NULL),('Performance','Visibility.AINotifyDelay','1000','1000',1,'Description: delay (in milliseconds) between action and nearby AI reaction. Lower values may have\n             performance impact.\nDefault:     1000',NULL),('Performance','Visibility.RelocationLowerLimit','10','20',1,'Description: distance in yards. unit should pass that distance to trigger visibility update.\nDefault:     10',NULL),('Rate','XP.Gather.Difference','10','0',1,'',NULL),('Rate','XP.Kill.Difference','10','0',1,'',NULL);

/*Table structure for table `icore_stat` */

DROP TABLE IF EXISTS `icore_stat`;

CREATE TABLE `icore_stat` (
  `online` smallint(5) unsigned NOT NULL DEFAULT '0',
  `diff` smallint(5) unsigned NOT NULL DEFAULT '0',
  `uptime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `revision` varchar(255) NOT NULL DEFAULT 'Skyfire',
  PRIMARY KEY (`online`,`diff`,`uptime`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `icore_stat` */

/*Table structure for table `ip_banned` */

DROP TABLE IF EXISTS `ip_banned`;

CREATE TABLE `ip_banned` (
  `ip` varchar(15) NOT NULL DEFAULT '127.0.0.1',
  `bandate` int(10) unsigned NOT NULL,
  `unbandate` int(10) unsigned NOT NULL,
  `bannedby` varchar(50) NOT NULL DEFAULT '[Console]',
  `banreason` varchar(255) NOT NULL DEFAULT 'no reason',
  PRIMARY KEY (`ip`,`bandate`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Banned IPs';

/*Data for the table `ip_banned` */

/*Table structure for table `logs` */

DROP TABLE IF EXISTS `logs`;

CREATE TABLE `logs` (
  `time` int(10) unsigned NOT NULL,
  `realm` int(10) unsigned NOT NULL,
  `type` tinyint(3) unsigned NOT NULL,
  `level` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `string` text CHARACTER SET latin1
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `logs` */

/*Table structure for table `mute_active` */

DROP TABLE IF EXISTS `mute_active`;

CREATE TABLE `mute_active` (
  `realmid` tinyint(3) NOT NULL,
  `account` int(11) NOT NULL,
  `mute_id` int(11) NOT NULL,
  `mute_timer` int(11) NOT NULL,
  PRIMARY KEY (`realmid`,`account`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `mute_active` */

/*Table structure for table `pay_history` */

DROP TABLE IF EXISTS `pay_history`;

CREATE TABLE `pay_history` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `orderNo` varchar(255) DEFAULT NULL,
  `synType` varchar(16) DEFAULT NULL,
  `status` varchar(64) DEFAULT NULL,
  `price` float(10,2) DEFAULT NULL,
  `time` varchar(32) DEFAULT NULL,
  `cpparam` varchar(256) DEFAULT NULL,
  `username` varchar(128) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 ROW_FORMAT=COMPACT COMMENT='not used, don''t know how to make payment work.';

/*Data for the table `pay_history` */

/*Table structure for table `project_betatesters` */

DROP TABLE IF EXISTS `project_betatesters`;

CREATE TABLE `project_betatesters` (
  `id` int(11) NOT NULL,
  `betatest_id` int(11) NOT NULL,
  `member_id` mediumint(8) NOT NULL,
  `account_id` int(11) unsigned NOT NULL,
  PRIMARY KEY (`id`),
  KEY `fk__project_betatesters__members1_idx` (`member_id`) USING BTREE,
  KEY `fk__project_betatesters__account1_idx` (`account_id`) USING BTREE,
  KEY `fk__project_betatesters__project_betatests1_idx` (`betatest_id`) USING BTREE,
  KEY `fk__project_betatesters__project_betatest_accounts1_idx` (`id`) USING BTREE
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT COMMENT='used for betatesting and allowing players with ids.';

/*Data for the table `project_betatesters` */

/*Table structure for table `project_member_premiums` */

DROP TABLE IF EXISTS `project_member_premiums`;

CREATE TABLE `project_member_premiums` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `member_id` mediumint(8) NOT NULL,
  `setdate` bigint(40) NOT NULL,
  `unsetdate` bigint(40) NOT NULL,
  `active` tinyint(1) NOT NULL DEFAULT '1',
  `card_id` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `fk__nighthold_member_premium__members1_idx` (`member_id`),
  KEY `fk__nighthold_member_premiums__nighthold_member_items1_idx` (`card_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Premium Members';

/*Data for the table `project_member_premiums` */

/*Table structure for table `project_member_rewards` */

DROP TABLE IF EXISTS `project_member_rewards`;

CREATE TABLE `project_member_rewards` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `member_id` int(10) unsigned NOT NULL,
  `character_guid` int(10) unsigned NOT NULL,
  `account_id` int(10) unsigned NOT NULL,
  `realmid` int(10) unsigned NOT NULL,
  `source_type` tinyint(3) unsigned NOT NULL,
  `source_id` int(10) unsigned NOT NULL,
  `reward_amount` int(10) unsigned NOT NULL,
  `reward_date` int(10) unsigned NOT NULL,
  `reward_day` int(10) unsigned NOT NULL COMMENT 'Used only for indexing purposes',
  `processed` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `process_date` int(10) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `member_id_reward_day_source_type` (`member_id`,`reward_day`,`source_type`),
  KEY `idx__member_id` (`member_id`),
  KEY `idx__processed` (`processed`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Member Rewards';

/*Data for the table `project_member_rewards` */

/*Table structure for table `project_member_settings` */

DROP TABLE IF EXISTS `project_member_settings`;

CREATE TABLE `project_member_settings` (
  `member_id` int(10) unsigned NOT NULL,
  `setting` int(10) unsigned NOT NULL COMMENT 'nightholdMemberInfo::Setting in core',
  `value` varchar(255) NOT NULL,
  PRIMARY KEY (`member_id`,`setting`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Member Settings';

/*Data for the table `project_member_settings` */

/*Table structure for table `promocodes` */

DROP TABLE IF EXISTS `promocodes`;

CREATE TABLE `promocodes` (
  `code` varchar(50) CHARACTER SET latin1 COLLATE latin1_general_ci NOT NULL COMMENT 'Latin letters, digits and dash symbol are allowed, case insensitive',
  `realmid` int(11) NOT NULL DEFAULT '-1' COMMENT 'Realm the code can be redeemed on or -1 for any realm',
  `start_time` int(10) unsigned NOT NULL COMMENT 'Activation UNIX timestamp, 0 if always active',
  `end_time` int(10) unsigned NOT NULL COMMENT 'Expiration UNIX timestamp, 0 if never expires',
  `money` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Copper',
  `items` tinytext NOT NULL COMMENT 'Format: itemid:count itemid:count ...',
  `premium` tinytext NOT NULL COMMENT 'Duration in timestring format (e.g. "30d5h42m10s")',
  `redeemed` tinyint(3) unsigned NOT NULL DEFAULT '0' COMMENT '1 if the code was redeemed, 0 otherwise',
  `redeemer_guid` int(10) unsigned NOT NULL COMMENT 'Character GUID that redeemed the code',
  `redeemer_realmid` int(10) unsigned NOT NULL COMMENT 'Character''s realm',
  `redeemer_account` int(10) unsigned NOT NULL COMMENT 'Character''s account',
  `redeemer_member` int(10) unsigned NOT NULL COMMENT 'Character''s nighthold member',
  PRIMARY KEY (`code`),
  KEY `realmid` (`realmid`),
  KEY `redeemed` (`redeemed`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='used for custom\r\ntodo: make this implement into blizzcms';

/*Data for the table `promocodes` */

/*Table structure for table `promotion_auras` */

DROP TABLE IF EXISTS `promotion_auras`;

CREATE TABLE `promotion_auras` (
  `entry` int(11) unsigned NOT NULL,
  `start_date` int(11) unsigned NOT NULL,
  `lenght` int(11) unsigned NOT NULL COMMENT 'Lenght in minutes',
  `active` tinyint(1) unsigned NOT NULL,
  `comment` text NOT NULL,
  PRIMARY KEY (`entry`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `promotion_auras` */

/*Table structure for table `rbac_account_groups` */

DROP TABLE IF EXISTS `rbac_account_groups`;

CREATE TABLE `rbac_account_groups` (
  `accountId` int(10) unsigned NOT NULL COMMENT 'Account id',
  `groupId` int(10) unsigned NOT NULL COMMENT 'Group id',
  `realmId` int(11) NOT NULL DEFAULT '-1' COMMENT 'Realm Id, -1 means all',
  PRIMARY KEY (`accountId`,`groupId`,`realmId`),
  KEY `fk__rbac_account_groups__rbac_groups` (`groupId`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Account-Group relation';

/*Data for the table `rbac_account_groups` */

/*Table structure for table `rbac_account_permissions` */

DROP TABLE IF EXISTS `rbac_account_permissions`;

CREATE TABLE `rbac_account_permissions` (
  `accountId` int(10) unsigned NOT NULL COMMENT 'Account id',
  `permissionId` int(10) unsigned NOT NULL COMMENT 'Permission id',
  `granted` tinyint(1) NOT NULL DEFAULT '1' COMMENT 'Granted = 1, Denied = 0',
  `realmId` int(11) NOT NULL DEFAULT '-1' COMMENT 'Realm Id, -1 means all',
  PRIMARY KEY (`accountId`,`permissionId`,`realmId`),
  KEY `fk__rbac_account_roles__rbac_permissions` (`permissionId`) USING BTREE
) ENGINE=MyISAM DEFAULT CHARSET=utf8 COMMENT='Account-Permission relation';

/*Data for the table `rbac_account_permissions` */

/*Table structure for table `realm_classes` */

DROP TABLE IF EXISTS `realm_classes`;

CREATE TABLE `realm_classes` (
  `realmId` int(11) NOT NULL,
  `class` tinyint(4) NOT NULL COMMENT 'Class Id',
  `expansion` tinyint(4) NOT NULL COMMENT 'Expansion for class activation',
  PRIMARY KEY (`realmId`,`class`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `realm_classes` */

insert  into `realm_classes`(`realmId`,`class`,`expansion`) values (1,1,0),(1,2,0),(1,3,0),(1,4,0),(1,5,0),(1,6,2),(1,7,0),(1,8,0),(1,9,0),(1,10,4),(1,11,0);

/*Table structure for table `realm_diff_stats` */

DROP TABLE IF EXISTS `realm_diff_stats`;

CREATE TABLE `realm_diff_stats` (
  `realm_id` tinyint(3) unsigned NOT NULL,
  `diff` mediumint(8) unsigned DEFAULT NULL,
  `min` mediumint(8) unsigned DEFAULT NULL,
  `max` mediumint(8) unsigned DEFAULT NULL,
  `unixtime` int(10) NOT NULL,
  PRIMARY KEY (`realm_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `realm_diff_stats` */

insert  into `realm_diff_stats`(`realm_id`,`diff`,`min`,`max`,`unixtime`) values (1,25,14,129,1636139221);

/*Table structure for table `realm_races` */

DROP TABLE IF EXISTS `realm_races`;

CREATE TABLE `realm_races` (
  `realmId` int(11) NOT NULL,
  `race` tinyint(4) NOT NULL COMMENT 'Race Id',
  `expansion` tinyint(4) NOT NULL COMMENT 'Expansion for race activation',
  PRIMARY KEY (`realmId`,`race`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `realm_races` */

insert  into `realm_races`(`realmId`,`race`,`expansion`) values (1,1,0),(1,2,0),(1,3,0),(1,4,0),(1,5,0),(1,6,0),(1,7,0),(1,8,0),(1,9,3),(1,10,1),(1,11,1),(1,22,3),(1,24,4),(1,25,4),(1,26,4);

/*Table structure for table `realmcharacters` */

DROP TABLE IF EXISTS `realmcharacters`;

CREATE TABLE `realmcharacters` (
  `realmid` int(10) unsigned NOT NULL DEFAULT '0',
  `acctid` int(10) unsigned NOT NULL,
  `numchars` tinyint(3) unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`realmid`,`acctid`),
  KEY `acctid` (`acctid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='How many characters accounts have';

/*Data for the table `realmcharacters` */

insert  into `realmcharacters`(`realmid`,`acctid`,`numchars`) values (1,1,4),(1,2,1),(2,1,0),(2,2,0);

/*Table structure for table `realmlist` */

DROP TABLE IF EXISTS `realmlist`;

CREATE TABLE `realmlist` (
  `id` int(11) unsigned NOT NULL AUTO_INCREMENT,
  `name` varchar(32) NOT NULL DEFAULT '',
  `project_shortname` varchar(32) NOT NULL,
  `address` varchar(32) NOT NULL DEFAULT '127.0.0.1',
  `port` int(11) NOT NULL DEFAULT '8085',
  `icon` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `color` tinyint(3) unsigned NOT NULL DEFAULT '2',
  `timezone` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `allowedSecurityLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `population` float unsigned NOT NULL DEFAULT '0',
  `gamebuild` int(11) unsigned NOT NULL DEFAULT '12340',
  `flag` int(11) DEFAULT NULL,
  `project_hidden` tinyint(1) NOT NULL DEFAULT '0',
  `project_enabled` tinyint(1) NOT NULL DEFAULT '1',
  `project_dbname` varchar(32) NOT NULL,
  `project_dbworld` varchar(32) NOT NULL,
  `project_dbarchive` varchar(32) NOT NULL,
  `project_rates_min` tinyint(4) NOT NULL COMMENT 'project',
  `project_rates_max` tinyint(4) NOT NULL COMMENT 'project',
  `project_transfer_level_max` tinyint(4) NOT NULL DEFAULT '80',
  `project_transfer_items` enum('IGNORE','IMPORT','REPLACE','SELECT') NOT NULL DEFAULT 'IGNORE',
  `project_transfer_skills_spells` enum('IGNORE','IMPORT','REPLACE','SELECT') NOT NULL DEFAULT 'IGNORE',
  `project_transfer_glyphs` enum('IGNORE','IMPORT') NOT NULL DEFAULT 'IGNORE',
  `project_transfer_achievements` enum('IGNORE','IMPORT') NOT NULL DEFAULT 'IGNORE',
  `project_server_same` tinyint(1) NOT NULL DEFAULT '0',
  `project_server_settings` varchar(32) NOT NULL,
  `project_server_remote_path` varchar(255) NOT NULL,
  `project_accounts_detach` tinyint(1) NOT NULL DEFAULT '1',
  `project_setskills_value_max` smallint(6) NOT NULL DEFAULT '0',
  `project_chat_enabled` tinyint(1) NOT NULL DEFAULT '0',
  `project_statistics_enabled` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx_name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8 ROW_FORMAT=DYNAMIC COMMENT='Realm System';

/*Data for the table `realmlist` */

insert  into `realmlist`(`id`,`name`,`project_shortname`,`address`,`port`,`icon`,`color`,`timezone`,`allowedSecurityLevel`,`population`,`gamebuild`,`flag`,`project_hidden`,`project_enabled`,`project_dbname`,`project_dbworld`,`project_dbarchive`,`project_rates_min`,`project_rates_max`,`project_transfer_level_max`,`project_transfer_items`,`project_transfer_skills_spells`,`project_transfer_glyphs`,`project_transfer_achievements`,`project_server_same`,`project_server_settings`,`project_server_remote_path`,`project_accounts_detach`,`project_setskills_value_max`,`project_chat_enabled`,`project_statistics_enabled`) values (1,'MoP','MoP','25.81.18.30',8085,0,2,1,0,0,18414,32,0,1,'ofi_characters','ofi_world','ofi_archive',0,0,80,'IGNORE','IGNORE','IGNORE','IGNORE',0,'0','0',1,0,0,0),(2,'Desarrollo','MoP','25.81.18.30',8086,1,2,1,0,0,18414,0,0,1,'ofi_characters','ofi_world','ofi_archive',0,0,80,'IGNORE','IGNORE','IGNORE','IGNORE',0,'0','0',1,0,0,0);

/*Table structure for table `realmlist_proxy` */

DROP TABLE IF EXISTS `realmlist_proxy`;

CREATE TABLE `realmlist_proxy` (
  `id` int(11) unsigned NOT NULL,
  `name` varchar(32) NOT NULL DEFAULT '' COMMENT 'Must be different from `realmlist`.`name`, otherwise will override original realm''s address and port',
  `address` varchar(32) NOT NULL DEFAULT '127.0.0.1',
  `port` int(11) NOT NULL DEFAULT '8085',
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=COMPACT;

/*Data for the table `realmlist_proxy` */

/*Table structure for table `sql_update` */

DROP TABLE IF EXISTS `sql_update`;

CREATE TABLE `sql_update` (
  `file` varchar(50) CHARACTER SET latin1 NOT NULL,
  `realmid` tinyint(4) NOT NULL DEFAULT '-1',
  `date` datetime DEFAULT NULL,
  `result` longtext,
  PRIMARY KEY (`file`,`realmid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `sql_update` */

/*Table structure for table `uptime` */

DROP TABLE IF EXISTS `uptime`;

CREATE TABLE `uptime` (
  `realmid` int(10) unsigned NOT NULL,
  `starttime` int(10) unsigned NOT NULL DEFAULT '0',
  `uptime` int(10) unsigned NOT NULL DEFAULT '0',
  `maxplayers` smallint(5) unsigned NOT NULL DEFAULT '0',
  `revision` varchar(255) NOT NULL DEFAULT 'SkyFire',
  PRIMARY KEY (`realmid`,`starttime`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COMMENT='Uptime system';

/*Data for the table `uptime` */

insert  into `uptime`(`realmid`,`starttime`,`uptime`,`maxplayers`,`revision`) values (1,1635979141,600,0,'SkyFire 5.x.xRev: 0 Release Hash: Archive (Win64, little-endian)'),(1,1635980112,0,0,'SkyFire 5.x.xRev: 0 Release Hash: Archive (Win64, little-endian)'),(1,1636049637,601,0,'SkyFire 5.x.xRev: 0 Release Hash: Archive (Win64, little-endian)'),(1,1636050723,1200,0,'SkyFire 5.x.xRev: 0 Release Hash: Archive (Win64, little-endian)'),(1,1636057343,4202,0,'SkyFire 5.x.xRev: 0 Release Hash: Archive (Win64, little-endian)'),(1,1636067032,603,1,'SkyFire 5.x.xRev: 0 Release Hash: Archive (Win64, little-endian)'),(1,1636067868,3000,1,'SkyFire 5.x.xRev: 0 Release Hash: Archive (Win64, little-endian)'),(1,1636071143,600,1,'SkyFire 5.x.xRev: 0 Release Hash: Archive (Win64, little-endian)'),(1,1636072221,601,1,'SkyFire 5.x.xRev: 0 Release Hash: Archive (Win64, little-endian)'),(1,1636073025,1200,1,'SkyFire 5.x.xRev: 0 Release Hash: Archive (Win64, little-endian)'),(1,1636074441,3600,1,'SkyFire 5.x.xRev: 0 Release Hash: Archive (Win64, little-endian)'),(1,1636138018,1203,0,'SkyFire 5.x.xRev: 0 Release Hash: Archive (Win64, little-endian)');

/*Table structure for table `wow_token` */

DROP TABLE IF EXISTS `wow_token`;

CREATE TABLE `wow_token` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `accountId` int(11) unsigned NOT NULL,
  `characterGuid` int(10) NOT NULL DEFAULT '0',
  `realm` int(5) unsigned NOT NULL,
  `coins` int(5) unsigned NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

/*Data for the table `wow_token` */

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
