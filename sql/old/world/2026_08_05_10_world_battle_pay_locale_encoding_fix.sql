-- =====================================================================
-- Battle Pay: repair the double-encoded esES/esMX locale rows.
--
-- These rows store UTF-8 that was written through a latin1 connection, so
-- every non-ASCII character was encoded twice: 'o' with acute is stored as
-- C383C2B3 instead of C3B3. The core connects with
-- mysql_set_character_set(utf8) (MySQLConnection.cpp) and passes the bytes
-- straight to the client, so the shop shows "PromociAtildesup3n" style
-- mojibake instead of "Promocion" with the accent.
--
-- Affected (both columns considered):
--     battle_pay_entry_locale    15 rows esES + 15 rows esMX
--     battle_pay_product_locale  10 rows esES + 10 rows esMX
--     ruRU rows are clean and are not touched.
--
-- Detection uses the mojibake markers themselves: a double-encoded latin1
-- range character always begins C382 ('A' circumflex) or C383 ('A' tilde),
-- byte pairs that never appear in legitimate Spanish text. This matters,
-- because the repair is destructive when applied to a correctly encoded
-- string: MySQL does not fail on the invalid conversion, it silently
-- TRUNCATES at the first offending character. Each column is therefore
-- guarded independently, so a row whose Title is damaged but whose
-- Description is already correct only gets its Title rewritten.
--
-- The transformation was verified to be lossless on every matched row: the
-- inverse (re-reading the repaired UTF-8 bytes as latin1) reproduces the
-- stored value exactly for all 50 of them, which is what rules out silent
-- truncation.
-- =====================================================================

SET NAMES utf8mb4;

UPDATE `battle_pay_entry_locale`
SET `Title` = IF(HEX(`Title`) REGEXP 'C38[23]',
                 CONVERT(BINARY(CONVERT(`Title` USING latin1)) USING utf8mb4), `Title`),
    `Description` = IF(HEX(`Description`) REGEXP 'C38[23]',
                 CONVERT(BINARY(CONVERT(`Description` USING latin1)) USING utf8mb4), `Description`)
WHERE `Locale` IN ('esES', 'esMX')
  AND (HEX(`Title`) REGEXP 'C38[23]' OR HEX(`Description`) REGEXP 'C38[23]');

UPDATE `battle_pay_product_locale`
SET `Title` = IF(HEX(`Title`) REGEXP 'C38[23]',
                 CONVERT(BINARY(CONVERT(`Title` USING latin1)) USING utf8mb4), `Title`),
    `Description` = IF(HEX(`Description`) REGEXP 'C38[23]',
                 CONVERT(BINARY(CONVERT(`Description` USING latin1)) USING utf8mb4), `Description`)
WHERE `Locale` IN ('esES', 'esMX')
  AND (HEX(`Title`) REGEXP 'C38[23]' OR HEX(`Description`) REGEXP 'C38[23]');
