SET FOREIGN_KEY_CHECKS=0;

DROP TABLE IF EXISTS `currency_transactions`;
CREATE TABLE `currency_transactions` (
  `realmid` tinyint(3) unsigned NOT NULL DEFAULT '1',
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `guid` int(10) unsigned NOT NULL,
  `unix_time` int(10) unsigned NOT NULL,
  `operation` enum('LOOT_MOB','LOOT_ITEM','MAIL','QUEST_REWARD','TRADE','SELL_ITEM','GUILD_BANK','AUCTION','TRANSMOGRIFICATION') NOT NULL,
  `param` int(10) unsigned DEFAULT NULL,
  `attachments` text NOT NULL,
  `amount_before` int(10) unsigned DEFAULT NULL,
  `amount_after` int(10) unsigned DEFAULT NULL,
  PRIMARY KEY (`id`),
  KEY `idx_guid` (`guid`),
  KEY `idx_operation` (`operation`),
  KEY `idx_unix_time` (`unix_time`),
  KEY `idx_param` (`param`)
) ENGINE=InnoDB AUTO_INCREMENT=93 DEFAULT CHARSET=utf8;
