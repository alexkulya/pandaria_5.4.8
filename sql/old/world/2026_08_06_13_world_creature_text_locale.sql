-- locales_creature_text -> creature_text_locale.
--
-- Two departures from the reference schema. Locale is part of the primary key:
-- the reference leaves it out, which can only hold one language per line of
-- dialogue, and its table is empty so the mistake was never hit. And TextFemale
-- is kept: newer TrinityCore moved gendered speech to broadcast_text but this
-- fork has not, and there are 38232 non-empty female strings to lose.


CREATE TABLE IF NOT EXISTS `creature_text_locale` (
    `CreatureID` MEDIUMINT UNSIGNED NOT NULL DEFAULT 0,
    `GroupID`    TINYINT   UNSIGNED NOT NULL DEFAULT 0,
    `ID`         TINYINT   UNSIGNED NOT NULL DEFAULT 0,
    `Locale`     VARCHAR(4)         NOT NULL,
    `Text`       TEXT,
    `TextFemale` TEXT,
    PRIMARY KEY (`CreatureID`, `GroupID`, `ID`, `Locale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- A database that has already been migrated no longer has `locales_creature_text`, and
-- `INSERT ... SELECT` from a missing table aborts the rest of the file. Run the
-- copy only when the old table is actually there, so a fresh install carries its
-- data over and an up-to-date one is left untouched.
SET @copy_creature_text_locale := IF(
    (SELECT COUNT(*) FROM information_schema.TABLES
      WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'locales_creature_text') > 0,
    "
INSERT IGNORE INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`, `TextFemale`)
SELECT `entry`,`text_group`,`id`,'koKR',`text_loc1`, `text_female_loc1`  FROM `locales_creature_text` WHERE COALESCE(`text_loc1`,'')  <> '' OR COALESCE(`text_female_loc1`,'')  <> '' UNION ALL
SELECT `entry`,`text_group`,`id`,'frFR',`text_loc2`, `text_female_loc2`  FROM `locales_creature_text` WHERE COALESCE(`text_loc2`,'')  <> '' OR COALESCE(`text_female_loc2`,'')  <> '' UNION ALL
SELECT `entry`,`text_group`,`id`,'deDE',`text_loc3`, `text_female_loc3`  FROM `locales_creature_text` WHERE COALESCE(`text_loc3`,'')  <> '' OR COALESCE(`text_female_loc3`,'')  <> '' UNION ALL
SELECT `entry`,`text_group`,`id`,'zhCN',`text_loc4`, `text_female_loc4`  FROM `locales_creature_text` WHERE COALESCE(`text_loc4`,'')  <> '' OR COALESCE(`text_female_loc4`,'')  <> '' UNION ALL
SELECT `entry`,`text_group`,`id`,'zhTW',`text_loc5`, `text_female_loc5`  FROM `locales_creature_text` WHERE COALESCE(`text_loc5`,'')  <> '' OR COALESCE(`text_female_loc5`,'')  <> '' UNION ALL
SELECT `entry`,`text_group`,`id`,'esES',`text_loc6`, `text_female_loc6`  FROM `locales_creature_text` WHERE COALESCE(`text_loc6`,'')  <> '' OR COALESCE(`text_female_loc6`,'')  <> '' UNION ALL
SELECT `entry`,`text_group`,`id`,'esMX',`text_loc7`, `text_female_loc7`  FROM `locales_creature_text` WHERE COALESCE(`text_loc7`,'')  <> '' OR COALESCE(`text_female_loc7`,'')  <> '' UNION ALL
SELECT `entry`,`text_group`,`id`,'ruRU',`text_loc8`, `text_female_loc8`  FROM `locales_creature_text` WHERE COALESCE(`text_loc8`,'')  <> '' OR COALESCE(`text_female_loc8`,'')  <> '' UNION ALL
SELECT `entry`,`text_group`,`id`,'itIT',`text_loc9`, `text_female_loc9`  FROM `locales_creature_text` WHERE COALESCE(`text_loc9`,'')  <> '' OR COALESCE(`text_female_loc9`,'')  <> '' UNION ALL
SELECT `entry`,`text_group`,`id`,'ptBR',`text_loc10`,`text_female_loc10` FROM `locales_creature_text` WHERE COALESCE(`text_loc10`,'') <> '' OR COALESCE(`text_female_loc10`,'') <> '' UNION ALL
SELECT `entry`,`text_group`,`id`,'ptPT',`text_loc11`,`text_female_loc11` FROM `locales_creature_text` WHERE COALESCE(`text_loc11`,'') <> '' OR COALESCE(`text_female_loc11`,'') <> ''
",
    'DO 0');
PREPARE _copy_creature_text_locale FROM @copy_creature_text_locale;
EXECUTE _copy_creature_text_locale;
DEALLOCATE PREPARE _copy_creature_text_locale;

-- Old table `locales_creature_text` is dropped in _17, once the replacement is confirmed in game.
