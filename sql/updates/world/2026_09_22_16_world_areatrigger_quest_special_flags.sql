-- Quests completed through areatrigger_involvedrelation must carry
-- QUEST_SPECIAL_FLAGS_EXPLORATION_OR_EVENT (2), otherwise the core logs and
-- patches them only in memory on every startup.

UPDATE `quest_template`
   SET `SpecialFlags` = `SpecialFlags` | 2
 WHERE `Id` IN (
    869, 13564, 14066, 25621, 26512, 26930, 27007,
    27152, 27610, 29392, 29415, 29536, 29539
 );
