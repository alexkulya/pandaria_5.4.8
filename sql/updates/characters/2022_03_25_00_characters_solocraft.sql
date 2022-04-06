CREATE TABLE IF NOT EXISTS `custom_solocraft_character_stats` (
  `GUID` tinyint unsigned NOT NULL,
  `Difficulty` float NOT NULL,
  `GroupSize` int NOT NULL,
  `SpellPower` int unsigned NOT NULL DEFAULT "0",
  `Stats` float NOT NULL DEFAULT "100",
  PRIMARY KEY (`GUID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
