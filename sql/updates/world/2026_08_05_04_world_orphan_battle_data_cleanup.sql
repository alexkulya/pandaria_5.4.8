-- =====================================================================
-- Remove orphaned rows that trigger startup warnings in the worldserver.
--
-- All of these reference a parent row / item that does not exist, so the core
-- already skips them at load and only keeps the noisy warning. Deleting them
-- (any row without a valid parent) silences the warnings and is future-proof.
--
--   battle_pet_item_to_species -> itemId not in item_template
--       64439  (species 277)
--       100908 (species 1257)
--   battle_pay_group_locale    -> ID not in battle_pay_group   (13, 14)
--   battle_pay_entry_locale    -> ID not in battle_pay_entry   (368-379)
-- =====================================================================

DELETE FROM `battle_pet_item_to_species`
 WHERE `itemId` NOT IN (SELECT `entry` FROM `item_template`);

DELETE FROM `battle_pay_group_locale`
 WHERE `ID` NOT IN (SELECT `id` FROM `battle_pay_group`);

DELETE FROM `battle_pay_entry_locale`
 WHERE `ID` NOT IN (SELECT `id` FROM `battle_pay_entry`);
