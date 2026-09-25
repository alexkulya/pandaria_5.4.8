-- Quest 29690 "Into the Mists" (Horde) ends scene 87 by casting spell
-- 102930, "Into the Mists - Teleport Crash Site". The spell has
-- SPELL_EFFECT_TELEPORT_UNITS, but this database was missing its destination
-- row, leaving the player in a broken post-scene state instead of at the
-- Hellscream's Fist crash site.

DELETE FROM `spell_target_position`
 WHERE `id` = 102930 AND `effIndex` = 0;

INSERT INTO `spell_target_position`
 (`id`, `effIndex`, `target_map`, `target_position_x`, `target_position_y`,
  `target_position_z`, `target_orientation`)
VALUES
 (102930, 0, 870, 3178.8400, -696.8820, 321.1080, 3.49931);
