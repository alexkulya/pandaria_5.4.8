-- These spell_target_position rows point at effects that either do not exist
-- for the spell or do not use TARGET_DEST_DB (17). The core ignores them and
-- logs an error on every startup.

DELETE FROM `spell_target_position`
 WHERE (`id` = 65042  AND `effIndex` = 2)
    OR (`id` = 100679 AND `effIndex` = 2)
    OR (`id` = 49986  AND `effIndex` = 1)
    OR (`id` = 66925  AND `effIndex` = 0)
    OR (`id` = 66836  AND `effIndex` = 0)
    OR (`id` = 105002 AND `effIndex` = 0);
