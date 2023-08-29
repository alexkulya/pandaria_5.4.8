SET FOREIGN_KEY_CHECKS=0;

DROP TABLE IF EXISTS `wow_token`;
DROP TABLE IF EXISTS `pandaria_token`;
CREATE TABLE `pandaria_token` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `account_id` int(11) unsigned NOT NULL,
  `character_guid` int(10) NOT NULL DEFAULT '0',
  `realm` int(5) unsigned NOT NULL,
  `vp_count` int(5) unsigned NOT NULL,
  `date` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=14 DEFAULT CHARSET=utf8;
