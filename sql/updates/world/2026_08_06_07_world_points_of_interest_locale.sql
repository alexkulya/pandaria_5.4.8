-- locales_points_of_interest -> points_of_interest_locale.
--
-- Smallest of the tables, migrated first to settle the pattern. Shape follows
-- the tables this database already migrated, not the upstream patch.

DROP TABLE IF EXISTS `points_of_interest_locale`;

CREATE TABLE `points_of_interest_locale` (
    `ID`     MEDIUMINT UNSIGNED NOT NULL DEFAULT 0,
    `Locale` VARCHAR(4)         NOT NULL,
    `Name`   TEXT,
    PRIMARY KEY (`ID`, `Locale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

INSERT INTO `points_of_interest_locale` (`ID`, `Locale`, `Name`)
SELECT `entry`, 'koKR', `icon_name_loc1`  FROM `locales_points_of_interest` WHERE `icon_name_loc1`  <> '' UNION ALL
SELECT `entry`, 'frFR', `icon_name_loc2`  FROM `locales_points_of_interest` WHERE `icon_name_loc2`  <> '' UNION ALL
SELECT `entry`, 'deDE', `icon_name_loc3`  FROM `locales_points_of_interest` WHERE `icon_name_loc3`  <> '' UNION ALL
SELECT `entry`, 'zhCN', `icon_name_loc4`  FROM `locales_points_of_interest` WHERE `icon_name_loc4`  <> '' UNION ALL
SELECT `entry`, 'zhTW', `icon_name_loc5`  FROM `locales_points_of_interest` WHERE `icon_name_loc5`  <> '' UNION ALL
SELECT `entry`, 'esES', `icon_name_loc6`  FROM `locales_points_of_interest` WHERE `icon_name_loc6`  <> '' UNION ALL
SELECT `entry`, 'esMX', `icon_name_loc7`  FROM `locales_points_of_interest` WHERE `icon_name_loc7`  <> '' UNION ALL
SELECT `entry`, 'ruRU', `icon_name_loc8`  FROM `locales_points_of_interest` WHERE `icon_name_loc8`  <> '' UNION ALL
SELECT `entry`, 'itIT', `icon_name_loc9`   FROM `locales_points_of_interest` WHERE `icon_name_loc9`  <> '' UNION ALL
SELECT `entry`, 'ptBR', `icon_name_loc10` FROM `locales_points_of_interest` WHERE `icon_name_loc10` <> '' UNION ALL
SELECT `entry`, 'ptPT', `icon_name_loc11` FROM `locales_points_of_interest` WHERE `icon_name_loc11` <> '';

-- Old table `locales_points_of_interest` is dropped in _17, once the
-- replacement is confirmed in game.
