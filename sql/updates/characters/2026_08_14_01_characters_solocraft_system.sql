DROP TABLE IF EXISTS `custom_solocraft_character_stats`;
CREATE TABLE IF NOT EXISTS `custom_solocraft_character_stats` (
  `guid` tinyint(3) unsigned NOT NULL,
  `difficulty` float NOT NULL,
  `group_size` int(11) NOT NULL,
  `spell_power` int(10) unsigned NOT NULL DEFAULT "0",
  `stats` float NOT NULL DEFAULT "100",
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
