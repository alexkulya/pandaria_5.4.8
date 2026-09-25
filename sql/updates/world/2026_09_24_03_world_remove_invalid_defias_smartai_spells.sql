-- Remove SmartAI casts that the 5.4.8 core skips because their spell ids do
-- not exist in this client build.
--
-- These rows are duplicate/stray Cataclysm-era Defias and Mining Monkey casts:
-- each affected creature already has the matching valid cast row loaded by the
-- core, so deleting only the skipped rows keeps behavior intact while cleaning
-- DBErrors.

DELETE FROM `smart_scripts`
 WHERE `source_type` = 0
   AND `action_type` = 11
   AND (
        (`entryorguid` IN (47403, 47404) AND `action_param1` IN (90981, 90982))
     OR (`entryorguid` = 48278 AND `action_param1` = 91039)
     OR (`entryorguid` = 48417 AND `action_param1` = 90947)
     OR (`entryorguid` = 48418 AND `action_param1` = 91006)
     OR (`entryorguid` = 48419 AND `action_param1` = 91010)
   );
