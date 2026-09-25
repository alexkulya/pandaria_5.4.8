-- Isle of Giants - remove SmartAI spells imported from the wrong expansion.
--
-- Pterrorwing Skyscreamer (70021) is a MoP Isle of Giants elite whose listed
-- ability is Skycall. Keep that cast and remove the invalid Hunter's Rush spell
-- id, which does not exist in 5.4.8.
--
-- Arnold Raygun (70034) is a Jurassic Expedition vendor. Its only SmartAI row
-- casts The Maw Must Feed, a non-5.4.8 spell id, so remove the row and clear
-- SmartAI from the vendor template.

DELETE FROM `smart_scripts`
 WHERE `entryorguid` = 70021
   AND `source_type` = 0
   AND `id` = 1
   AND `action_type` = 11
   AND `action_param1` = 223971;

DELETE FROM `smart_scripts`
 WHERE `entryorguid` = 70034
   AND `source_type` = 0
   AND `action_type` = 11
   AND `action_param1` = 215377;

UPDATE `creature_template`
   SET `AIName` = ''
 WHERE `entry` = 70034
   AND `AIName` = 'SmartAI'
   AND NOT EXISTS (
       SELECT 1
         FROM `smart_scripts`
        WHERE `entryorguid` = 70034
          AND `source_type` = 0
   );
