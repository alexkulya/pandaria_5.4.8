UPDATE `creature`
SET `wander_distance` = 0
WHERE `id` = 43704
  AND `movement_type` = 0
  AND `wander_distance` <> 0;
