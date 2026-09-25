-- Azuremyst Isle trainer reward scripts.
--
-- SMART_EVENT_REWARD_QUEST uses event_param1 = quest, event_param2 =
-- cooldownMin, event_param3 = cooldownMax. These two rows had cooldownMin=2
-- and cooldownMax=0, so the SmartAI loader skipped the whole actionlist call
-- with "uses min/max params wrong (2/0)".

UPDATE `smart_scripts`
   SET `event_param2` = 0,
       `event_param3` = 0
 WHERE `source_type` = 0
   AND `event_type` = 20
   AND `action_type` = 80
   AND (
        (`entryorguid` = 17214 AND `id` = 0 AND `event_param1` = 9463 AND `action_param1` = 1721400)
     OR (`entryorguid` = 17215 AND `id` = 2 AND `event_param1` = 9473 AND `action_param1` = 1721500)
   );
