-- Vashj'ir intro - "Call of Duty" event credit.
--
-- Erunak Stonespeaker uses SMART_ACTION_CALL_AREAEXPLOREDOREVENTHAPPENS (15)
-- to credit the mercenary-ship objective when the player reaches him. This
-- action requires QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT (2), otherwise the
-- SmartAI loader skips the rows.

UPDATE `quest_template`
   SET `SpecialFlags` = `SpecialFlags` | 2
 WHERE `Id` IN (14482, 25924);
