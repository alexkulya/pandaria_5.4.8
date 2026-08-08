-- First step of the locale rename series. Only the two safe moves: drop the
-- dead twins of tables the core already reads under the new name, and rename
-- locales_item, which needs no restructuring.
--
-- locales_gossip_menu_option is kept: 6850 of its rows hold female gossip text
-- that has no column in the new schema and no reader in the core, and dropping
-- it cannot be undone.

DROP TABLE IF EXISTS `locales_achievement_reward`;
DROP TABLE IF EXISTS `locales_battle_pay_product`;


-- ---------------------------------------------------------------------
-- 2) locales_item -> item_template_locale.
--
--    This one needs no restructuring at all: its columns are already
--    ID / locale / Name / Description / VerifiedBuild, so only the name is
--    out of line with the convention. 394989 rows move with the rename, which
--    is a metadata operation.
--
--    Paired with ObjectMgr.cpp:2492, which is the single place that reads it,
--    plus the `.reload locales_item` command label in cs_reload.cpp.
-- ---------------------------------------------------------------------

DROP TABLE IF EXISTS `item_template_locale`;
RENAME TABLE `locales_item` TO `item_template_locale`;
