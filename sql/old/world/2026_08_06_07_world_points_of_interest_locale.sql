-- locales_points_of_interest -> points_of_interest_locale.
--
-- Smallest of the tables, migrated first to settle the pattern. Shape follows
-- the tables this database already migrated, not the upstream patch.


CREATE TABLE IF NOT EXISTS `points_of_interest_locale` (
    `ID`     MEDIUMINT UNSIGNED NOT NULL DEFAULT 0,
    `Locale` VARCHAR(4)         NOT NULL,
    `Name`   TEXT,
    PRIMARY KEY (`ID`, `Locale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- A database that has already been migrated no longer has `locales_points_of_interest`, and
-- `INSERT ... SELECT` from a missing table aborts the rest of the file. Run the
-- copy only when the old table is actually there, so a fresh install carries its
-- data over and an up-to-date one is left untouched.
SET @copy_points_of_interest_locale := IF(
    (SELECT COUNT(*) FROM information_schema.TABLES
      WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'locales_points_of_interest') > 0,
    "
INSERT IGNORE INTO `points_of_interest_locale` (`ID`, `Locale`, `Name`)
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
SELECT `entry`, 'ptPT', `icon_name_loc11` FROM `locales_points_of_interest` WHERE `icon_name_loc11` <> ''
",
    'DO 0');
PREPARE _copy_points_of_interest_locale FROM @copy_points_of_interest_locale;
EXECUTE _copy_points_of_interest_locale;
DEALLOCATE PREPARE _copy_points_of_interest_locale;

-- Old table `locales_points_of_interest` is dropped in _17, once the
-- replacement is confirmed in game.
