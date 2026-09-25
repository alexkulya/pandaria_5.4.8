-- Firelands - Druid of the Flame (53619).
--
-- The SmartAI loader skips this row because spell 100101 does not exist in
-- this 5.4.8 client. The same instance-data action is already attached to the
-- valid Kneel to the Flame! spell hit (99705), so remove only the duplicate
-- invalid spell-hit listener.

DELETE FROM `smart_scripts`
 WHERE `entryorguid` = 53619
   AND `source_type` = 0
   AND `event_type` = 31
   AND `event_param1` = 100101
   AND `action_type` = 34
   AND `action_param1` = 14
   AND `action_param2` = 1;
