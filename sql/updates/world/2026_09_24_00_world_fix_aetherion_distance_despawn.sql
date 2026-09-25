-- Aetherion (33041) timed actionlist.
--
-- SMART_EVENT_DISTANCE_CREATURE uses event_param3 as distance and
-- event_param4 as repeat timer. The imported row had repeat=0, so the
-- SmartAI loader rejected the event as "min/max params wrong (5/0)".

UPDATE `smart_scripts`
   SET `event_param4` = 5000
 WHERE `entryorguid` = 3304100
   AND `source_type` = 9
   AND `id` = 0
   AND `event_type` = 75
   AND `event_param1` = 0
   AND `event_param2` = 33041
   AND `event_param3` = 5
   AND `event_param4` = 0
   AND `action_type` = 41;
