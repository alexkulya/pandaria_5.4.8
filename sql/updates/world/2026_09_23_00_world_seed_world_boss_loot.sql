-- Sha of Anger and Galleon had creature_template.lootid values pointing to
-- empty creature_loot_template entries. Keep the retail loot IDs and seed the
-- baseline world-boss drops verified from Wowhead, so the bosses are not left
-- lootless while the full class/spec gear tables are filled in later.

UPDATE `creature_template`
   SET `lootid` = `entry`
 WHERE `entry` IN (60491, 62346)
   AND `lootid` <> `entry`;

DELETE FROM `creature_loot_template`
 WHERE `entry` IN (60491, 62346)
   AND `item` IN (87771, 89317, 89783, 90839, 90840);

INSERT INTO `creature_loot_template`
 (`entry`, `item`, `ChanceOrQuestChance`, `lootmode`, `groupid`, `mincountOrRef`, `maxcount`)
VALUES
 (60491, 89317, 100, 'REGULAR', 0, 1, 1),  -- Claw of Anger
 (60491, 90839, 100, 'REGULAR', 0, 1, 1),  -- Cache of Sha-Touched Gold
 (60491, 87771, 0.28, 'REGULAR', 0, 1, 1), -- Reins of the Heavenly Onyx Cloud Serpent
 (62346, 90840, 100, 'REGULAR', 0, 1, 1),  -- Marauder's Gleaming Sack of Gold
 (62346, 89783, 0.26, 'REGULAR', 0, 1, 1); -- Son of Galleon's Saddle

DELETE FROM `conditions`
 WHERE `SourceTypeOrReferenceId` = 1
   AND `SourceGroup` = 60491
   AND `SourceEntry` = 89317;

INSERT INTO `conditions`
 (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`,
  `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`,
  `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`)
VALUES
 (1, 60491, 89317, 0, 0,
  8, 0, 31809, 0, 0,
  1, 0, 0, '', 'Claw of Anger drops from Sha of Anger until Remnants of Anger is rewarded');
