-- Icecrown - Matthias Lehner (32423).
--
-- SMART_EVENT_REWARD_QUEST uses event_param2/event_param3 as cooldown
-- min/max. The quest 13398 row had cooldownMin=1 and cooldownMax=0, so the
-- loader skipped its Lich King summon action with "min/max params wrong
-- (1/0)". The paired quest 13359 row already uses 0/0.

UPDATE `smart_scripts`
   SET `event_param2` = 0,
       `event_param3` = 0
 WHERE `entryorguid` = 32423
   AND `source_type` = 0
   AND `id` = 0
   AND `event_type` = 20
   AND `event_param1` = 13398
   AND `action_type` = 12
   AND `action_param1` = 32443;
