-- Quest 31766 - Touching Ground
-- The three ropes are the clickable object shown beside the ship's guns.
-- Keep them in the complete Horde arrival mask so they remain visible while
-- the player transitions between the normal and wreck phases.

UPDATE `gameobject`
   SET `phaseMask` = 67108865
 WHERE `map` = 870
   AND `id` = 215689
   AND `zoneId` = 5785;
