-- =====================================================================
-- Quest 31765 "Paint It Red!" - fix objective required counts.
--
-- The two kill objectives were stored with amount = 1 each, so the log showed
-- "slain 1 / destroyed 1". Retail requires 80 Thunder Hold Soldiers and 9
-- Thunder Hold Cannons.
--     obj index 0: 66200 "Thunder Hold Soldier"  -> 80
--     obj index 1: 66203 "Thunder Hold Cannon"   -> 9
-- =====================================================================

UPDATE `quest_objective` SET `amount` = 80 WHERE `questId` = 31765 AND `objectId` = 66200;
UPDATE `quest_objective` SET `amount` = 9  WHERE `questId` = 31765 AND `objectId` = 66203;
