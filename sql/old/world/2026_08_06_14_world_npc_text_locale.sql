-- locales_npc_text -> npc_text_locale: 177 columns collapse to 18.
--
-- This also fixes a bug the old shape was hiding. The loader's column list was
-- built by copying the loc1 line ten times, and one column was missed every
-- time: every locale from loc2 to loc11 asked for Text3_1_loc1, so the female
-- variant of gossip option 3 was read from the Korean column. The normalised
-- loader cannot reproduce it - there is one Text3_1 column and the locale is a
-- value in a row, not part of a column name.


CREATE TABLE IF NOT EXISTS `npc_text_locale` (
    `ID`     MEDIUMINT UNSIGNED NOT NULL DEFAULT 0,
    `Locale` VARCHAR(4)         NOT NULL,
    `Text0_0` TEXT,
    `Text0_1` TEXT,
    `Text1_0` TEXT,
    `Text1_1` TEXT,
    `Text2_0` TEXT,
    `Text2_1` TEXT,
    `Text3_0` TEXT,
    `Text3_1` TEXT,
    `Text4_0` TEXT,
    `Text4_1` TEXT,
    `Text5_0` TEXT,
    `Text5_1` TEXT,
    `Text6_0` TEXT,
    `Text6_1` TEXT,
    `Text7_0` TEXT,
    `Text7_1` TEXT,
    `VerifiedBuild` INT DEFAULT 0,
    PRIMARY KEY (`ID`, `Locale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- A row is carried over when any of its 16 strings is present, so an entry that
-- only translated one gossip option is not lost.
-- A database that has already been migrated no longer has `locales_npc_text`, and
-- `INSERT ... SELECT` from a missing table aborts the rest of the file. Run the
-- copy only when the old table is actually there, so a fresh install carries its
-- data over and an up-to-date one is left untouched.
SET @copy_npc_text_locale := IF(
    (SELECT COUNT(*) FROM information_schema.TABLES
      WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'locales_npc_text') > 0,
    "
INSERT IGNORE INTO `npc_text_locale` (`ID`, `Locale`, `Text0_0`, `Text0_1`, `Text1_0`, `Text1_1`, `Text2_0`, `Text2_1`, `Text3_0`, `Text3_1`, `Text4_0`, `Text4_1`, `Text5_0`, `Text5_1`, `Text6_0`, `Text6_1`, `Text7_0`, `Text7_1`)
SELECT `ID`,'koKR', `Text0_0_loc1`, `Text0_1_loc1`, `Text1_0_loc1`, `Text1_1_loc1`, `Text2_0_loc1`, `Text2_1_loc1`, `Text3_0_loc1`, `Text3_1_loc1`, `Text4_0_loc1`, `Text4_1_loc1`, `Text5_0_loc1`, `Text5_1_loc1`, `Text6_0_loc1`, `Text6_1_loc1`, `Text7_0_loc1`, `Text7_1_loc1` FROM `locales_npc_text` WHERE COALESCE(`Text0_0_loc1`,'') <> '' OR COALESCE(`Text0_1_loc1`,'') <> '' OR COALESCE(`Text1_0_loc1`,'') <> '' OR COALESCE(`Text1_1_loc1`,'') <> '' OR COALESCE(`Text2_0_loc1`,'') <> '' OR COALESCE(`Text2_1_loc1`,'') <> '' OR COALESCE(`Text3_0_loc1`,'') <> '' OR COALESCE(`Text3_1_loc1`,'') <> '' OR COALESCE(`Text4_0_loc1`,'') <> '' OR COALESCE(`Text4_1_loc1`,'') <> '' OR COALESCE(`Text5_0_loc1`,'') <> '' OR COALESCE(`Text5_1_loc1`,'') <> '' OR COALESCE(`Text6_0_loc1`,'') <> '' OR COALESCE(`Text6_1_loc1`,'') <> '' OR COALESCE(`Text7_0_loc1`,'') <> '' OR COALESCE(`Text7_1_loc1`,'') <> '' UNION ALL
SELECT `ID`,'frFR', `Text0_0_loc2`, `Text0_1_loc2`, `Text1_0_loc2`, `Text1_1_loc2`, `Text2_0_loc2`, `Text2_1_loc2`, `Text3_0_loc2`, `Text3_1_loc2`, `Text4_0_loc2`, `Text4_1_loc2`, `Text5_0_loc2`, `Text5_1_loc2`, `Text6_0_loc2`, `Text6_1_loc2`, `Text7_0_loc2`, `Text7_1_loc2` FROM `locales_npc_text` WHERE COALESCE(`Text0_0_loc2`,'') <> '' OR COALESCE(`Text0_1_loc2`,'') <> '' OR COALESCE(`Text1_0_loc2`,'') <> '' OR COALESCE(`Text1_1_loc2`,'') <> '' OR COALESCE(`Text2_0_loc2`,'') <> '' OR COALESCE(`Text2_1_loc2`,'') <> '' OR COALESCE(`Text3_0_loc2`,'') <> '' OR COALESCE(`Text3_1_loc2`,'') <> '' OR COALESCE(`Text4_0_loc2`,'') <> '' OR COALESCE(`Text4_1_loc2`,'') <> '' OR COALESCE(`Text5_0_loc2`,'') <> '' OR COALESCE(`Text5_1_loc2`,'') <> '' OR COALESCE(`Text6_0_loc2`,'') <> '' OR COALESCE(`Text6_1_loc2`,'') <> '' OR COALESCE(`Text7_0_loc2`,'') <> '' OR COALESCE(`Text7_1_loc2`,'') <> '' UNION ALL
SELECT `ID`,'deDE', `Text0_0_loc3`, `Text0_1_loc3`, `Text1_0_loc3`, `Text1_1_loc3`, `Text2_0_loc3`, `Text2_1_loc3`, `Text3_0_loc3`, `Text3_1_loc3`, `Text4_0_loc3`, `Text4_1_loc3`, `Text5_0_loc3`, `Text5_1_loc3`, `Text6_0_loc3`, `Text6_1_loc3`, `Text7_0_loc3`, `Text7_1_loc3` FROM `locales_npc_text` WHERE COALESCE(`Text0_0_loc3`,'') <> '' OR COALESCE(`Text0_1_loc3`,'') <> '' OR COALESCE(`Text1_0_loc3`,'') <> '' OR COALESCE(`Text1_1_loc3`,'') <> '' OR COALESCE(`Text2_0_loc3`,'') <> '' OR COALESCE(`Text2_1_loc3`,'') <> '' OR COALESCE(`Text3_0_loc3`,'') <> '' OR COALESCE(`Text3_1_loc3`,'') <> '' OR COALESCE(`Text4_0_loc3`,'') <> '' OR COALESCE(`Text4_1_loc3`,'') <> '' OR COALESCE(`Text5_0_loc3`,'') <> '' OR COALESCE(`Text5_1_loc3`,'') <> '' OR COALESCE(`Text6_0_loc3`,'') <> '' OR COALESCE(`Text6_1_loc3`,'') <> '' OR COALESCE(`Text7_0_loc3`,'') <> '' OR COALESCE(`Text7_1_loc3`,'') <> '' UNION ALL
SELECT `ID`,'zhCN', `Text0_0_loc4`, `Text0_1_loc4`, `Text1_0_loc4`, `Text1_1_loc4`, `Text2_0_loc4`, `Text2_1_loc4`, `Text3_0_loc4`, `Text3_1_loc4`, `Text4_0_loc4`, `Text4_1_loc4`, `Text5_0_loc4`, `Text5_1_loc4`, `Text6_0_loc4`, `Text6_1_loc4`, `Text7_0_loc4`, `Text7_1_loc4` FROM `locales_npc_text` WHERE COALESCE(`Text0_0_loc4`,'') <> '' OR COALESCE(`Text0_1_loc4`,'') <> '' OR COALESCE(`Text1_0_loc4`,'') <> '' OR COALESCE(`Text1_1_loc4`,'') <> '' OR COALESCE(`Text2_0_loc4`,'') <> '' OR COALESCE(`Text2_1_loc4`,'') <> '' OR COALESCE(`Text3_0_loc4`,'') <> '' OR COALESCE(`Text3_1_loc4`,'') <> '' OR COALESCE(`Text4_0_loc4`,'') <> '' OR COALESCE(`Text4_1_loc4`,'') <> '' OR COALESCE(`Text5_0_loc4`,'') <> '' OR COALESCE(`Text5_1_loc4`,'') <> '' OR COALESCE(`Text6_0_loc4`,'') <> '' OR COALESCE(`Text6_1_loc4`,'') <> '' OR COALESCE(`Text7_0_loc4`,'') <> '' OR COALESCE(`Text7_1_loc4`,'') <> '' UNION ALL
SELECT `ID`,'zhTW', `Text0_0_loc5`, `Text0_1_loc5`, `Text1_0_loc5`, `Text1_1_loc5`, `Text2_0_loc5`, `Text2_1_loc5`, `Text3_0_loc5`, `Text3_1_loc5`, `Text4_0_loc5`, `Text4_1_loc5`, `Text5_0_loc5`, `Text5_1_loc5`, `Text6_0_loc5`, `Text6_1_loc5`, `Text7_0_loc5`, `Text7_1_loc5` FROM `locales_npc_text` WHERE COALESCE(`Text0_0_loc5`,'') <> '' OR COALESCE(`Text0_1_loc5`,'') <> '' OR COALESCE(`Text1_0_loc5`,'') <> '' OR COALESCE(`Text1_1_loc5`,'') <> '' OR COALESCE(`Text2_0_loc5`,'') <> '' OR COALESCE(`Text2_1_loc5`,'') <> '' OR COALESCE(`Text3_0_loc5`,'') <> '' OR COALESCE(`Text3_1_loc5`,'') <> '' OR COALESCE(`Text4_0_loc5`,'') <> '' OR COALESCE(`Text4_1_loc5`,'') <> '' OR COALESCE(`Text5_0_loc5`,'') <> '' OR COALESCE(`Text5_1_loc5`,'') <> '' OR COALESCE(`Text6_0_loc5`,'') <> '' OR COALESCE(`Text6_1_loc5`,'') <> '' OR COALESCE(`Text7_0_loc5`,'') <> '' OR COALESCE(`Text7_1_loc5`,'') <> '' UNION ALL
SELECT `ID`,'esES', `Text0_0_loc6`, `Text0_1_loc6`, `Text1_0_loc6`, `Text1_1_loc6`, `Text2_0_loc6`, `Text2_1_loc6`, `Text3_0_loc6`, `Text3_1_loc6`, `Text4_0_loc6`, `Text4_1_loc6`, `Text5_0_loc6`, `Text5_1_loc6`, `Text6_0_loc6`, `Text6_1_loc6`, `Text7_0_loc6`, `Text7_1_loc6` FROM `locales_npc_text` WHERE COALESCE(`Text0_0_loc6`,'') <> '' OR COALESCE(`Text0_1_loc6`,'') <> '' OR COALESCE(`Text1_0_loc6`,'') <> '' OR COALESCE(`Text1_1_loc6`,'') <> '' OR COALESCE(`Text2_0_loc6`,'') <> '' OR COALESCE(`Text2_1_loc6`,'') <> '' OR COALESCE(`Text3_0_loc6`,'') <> '' OR COALESCE(`Text3_1_loc6`,'') <> '' OR COALESCE(`Text4_0_loc6`,'') <> '' OR COALESCE(`Text4_1_loc6`,'') <> '' OR COALESCE(`Text5_0_loc6`,'') <> '' OR COALESCE(`Text5_1_loc6`,'') <> '' OR COALESCE(`Text6_0_loc6`,'') <> '' OR COALESCE(`Text6_1_loc6`,'') <> '' OR COALESCE(`Text7_0_loc6`,'') <> '' OR COALESCE(`Text7_1_loc6`,'') <> '' UNION ALL
SELECT `ID`,'esMX', `Text0_0_loc7`, `Text0_1_loc7`, `Text1_0_loc7`, `Text1_1_loc7`, `Text2_0_loc7`, `Text2_1_loc7`, `Text3_0_loc7`, `Text3_1_loc7`, `Text4_0_loc7`, `Text4_1_loc7`, `Text5_0_loc7`, `Text5_1_loc7`, `Text6_0_loc7`, `Text6_1_loc7`, `Text7_0_loc7`, `Text7_1_loc7` FROM `locales_npc_text` WHERE COALESCE(`Text0_0_loc7`,'') <> '' OR COALESCE(`Text0_1_loc7`,'') <> '' OR COALESCE(`Text1_0_loc7`,'') <> '' OR COALESCE(`Text1_1_loc7`,'') <> '' OR COALESCE(`Text2_0_loc7`,'') <> '' OR COALESCE(`Text2_1_loc7`,'') <> '' OR COALESCE(`Text3_0_loc7`,'') <> '' OR COALESCE(`Text3_1_loc7`,'') <> '' OR COALESCE(`Text4_0_loc7`,'') <> '' OR COALESCE(`Text4_1_loc7`,'') <> '' OR COALESCE(`Text5_0_loc7`,'') <> '' OR COALESCE(`Text5_1_loc7`,'') <> '' OR COALESCE(`Text6_0_loc7`,'') <> '' OR COALESCE(`Text6_1_loc7`,'') <> '' OR COALESCE(`Text7_0_loc7`,'') <> '' OR COALESCE(`Text7_1_loc7`,'') <> '' UNION ALL
SELECT `ID`,'ruRU', `Text0_0_loc8`, `Text0_1_loc8`, `Text1_0_loc8`, `Text1_1_loc8`, `Text2_0_loc8`, `Text2_1_loc8`, `Text3_0_loc8`, `Text3_1_loc8`, `Text4_0_loc8`, `Text4_1_loc8`, `Text5_0_loc8`, `Text5_1_loc8`, `Text6_0_loc8`, `Text6_1_loc8`, `Text7_0_loc8`, `Text7_1_loc8` FROM `locales_npc_text` WHERE COALESCE(`Text0_0_loc8`,'') <> '' OR COALESCE(`Text0_1_loc8`,'') <> '' OR COALESCE(`Text1_0_loc8`,'') <> '' OR COALESCE(`Text1_1_loc8`,'') <> '' OR COALESCE(`Text2_0_loc8`,'') <> '' OR COALESCE(`Text2_1_loc8`,'') <> '' OR COALESCE(`Text3_0_loc8`,'') <> '' OR COALESCE(`Text3_1_loc8`,'') <> '' OR COALESCE(`Text4_0_loc8`,'') <> '' OR COALESCE(`Text4_1_loc8`,'') <> '' OR COALESCE(`Text5_0_loc8`,'') <> '' OR COALESCE(`Text5_1_loc8`,'') <> '' OR COALESCE(`Text6_0_loc8`,'') <> '' OR COALESCE(`Text6_1_loc8`,'') <> '' OR COALESCE(`Text7_0_loc8`,'') <> '' OR COALESCE(`Text7_1_loc8`,'') <> '' UNION ALL
SELECT `ID`,'itIT', `Text0_0_loc9`, `Text0_1_loc9`, `Text1_0_loc9`, `Text1_1_loc9`, `Text2_0_loc9`, `Text2_1_loc9`, `Text3_0_loc9`, `Text3_1_loc9`, `Text4_0_loc9`, `Text4_1_loc9`, `Text5_0_loc9`, `Text5_1_loc9`, `Text6_0_loc9`, `Text6_1_loc9`, `Text7_0_loc9`, `Text7_1_loc9` FROM `locales_npc_text` WHERE COALESCE(`Text0_0_loc9`,'') <> '' OR COALESCE(`Text0_1_loc9`,'') <> '' OR COALESCE(`Text1_0_loc9`,'') <> '' OR COALESCE(`Text1_1_loc9`,'') <> '' OR COALESCE(`Text2_0_loc9`,'') <> '' OR COALESCE(`Text2_1_loc9`,'') <> '' OR COALESCE(`Text3_0_loc9`,'') <> '' OR COALESCE(`Text3_1_loc9`,'') <> '' OR COALESCE(`Text4_0_loc9`,'') <> '' OR COALESCE(`Text4_1_loc9`,'') <> '' OR COALESCE(`Text5_0_loc9`,'') <> '' OR COALESCE(`Text5_1_loc9`,'') <> '' OR COALESCE(`Text6_0_loc9`,'') <> '' OR COALESCE(`Text6_1_loc9`,'') <> '' OR COALESCE(`Text7_0_loc9`,'') <> '' OR COALESCE(`Text7_1_loc9`,'') <> '' UNION ALL
SELECT `ID`,'ptBR', `Text0_0_loc10`, `Text0_1_loc10`, `Text1_0_loc10`, `Text1_1_loc10`, `Text2_0_loc10`, `Text2_1_loc10`, `Text3_0_loc10`, `Text3_1_loc10`, `Text4_0_loc10`, `Text4_1_loc10`, `Text5_0_loc10`, `Text5_1_loc10`, `Text6_0_loc10`, `Text6_1_loc10`, `Text7_0_loc10`, `Text7_1_loc10` FROM `locales_npc_text` WHERE COALESCE(`Text0_0_loc10`,'') <> '' OR COALESCE(`Text0_1_loc10`,'') <> '' OR COALESCE(`Text1_0_loc10`,'') <> '' OR COALESCE(`Text1_1_loc10`,'') <> '' OR COALESCE(`Text2_0_loc10`,'') <> '' OR COALESCE(`Text2_1_loc10`,'') <> '' OR COALESCE(`Text3_0_loc10`,'') <> '' OR COALESCE(`Text3_1_loc10`,'') <> '' OR COALESCE(`Text4_0_loc10`,'') <> '' OR COALESCE(`Text4_1_loc10`,'') <> '' OR COALESCE(`Text5_0_loc10`,'') <> '' OR COALESCE(`Text5_1_loc10`,'') <> '' OR COALESCE(`Text6_0_loc10`,'') <> '' OR COALESCE(`Text6_1_loc10`,'') <> '' OR COALESCE(`Text7_0_loc10`,'') <> '' OR COALESCE(`Text7_1_loc10`,'') <> '' UNION ALL
SELECT `ID`,'ptPT', `Text0_0_loc11`, `Text0_1_loc11`, `Text1_0_loc11`, `Text1_1_loc11`, `Text2_0_loc11`, `Text2_1_loc11`, `Text3_0_loc11`, `Text3_1_loc11`, `Text4_0_loc11`, `Text4_1_loc11`, `Text5_0_loc11`, `Text5_1_loc11`, `Text6_0_loc11`, `Text6_1_loc11`, `Text7_0_loc11`, `Text7_1_loc11` FROM `locales_npc_text` WHERE COALESCE(`Text0_0_loc11`,'') <> '' OR COALESCE(`Text0_1_loc11`,'') <> '' OR COALESCE(`Text1_0_loc11`,'') <> '' OR COALESCE(`Text1_1_loc11`,'') <> '' OR COALESCE(`Text2_0_loc11`,'') <> '' OR COALESCE(`Text2_1_loc11`,'') <> '' OR COALESCE(`Text3_0_loc11`,'') <> '' OR COALESCE(`Text3_1_loc11`,'') <> '' OR COALESCE(`Text4_0_loc11`,'') <> '' OR COALESCE(`Text4_1_loc11`,'') <> '' OR COALESCE(`Text5_0_loc11`,'') <> '' OR COALESCE(`Text5_1_loc11`,'') <> '' OR COALESCE(`Text6_0_loc11`,'') <> '' OR COALESCE(`Text6_1_loc11`,'') <> '' OR COALESCE(`Text7_0_loc11`,'') <> '' OR COALESCE(`Text7_1_loc11`,'') <> ''
",
    'DO 0');
PREPARE _copy_npc_text_locale FROM @copy_npc_text_locale;
EXECUTE _copy_npc_text_locale;
DEALLOCATE PREPARE _copy_npc_text_locale;

-- Old table `locales_npc_text` is dropped in _17, once the replacement is confirmed in game.
