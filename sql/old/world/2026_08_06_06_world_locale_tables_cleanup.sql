-- First step of the locale rename series. Only the safe move: drop the dead
-- twins of tables the core already reads under the new name.
--
-- locales_gossip_menu_option is kept: 6850 of its rows hold female gossip text
-- that has no column in the new schema and no reader in the core, and dropping
-- it cannot be undone.
--
-- locales_item -> item_template_locale used to live here too, but upstream now
-- performs that rename in 2026_08_14_01_world_locales_update.sql. Doing it in
-- both places would leave whichever migration runs second renaming a table that
-- no longer exists, so the rename is left to upstream and this file no longer
-- touches item_template_locale at all.

DROP TABLE IF EXISTS `locales_achievement_reward`;
DROP TABLE IF EXISTS `locales_battle_pay_product`;
