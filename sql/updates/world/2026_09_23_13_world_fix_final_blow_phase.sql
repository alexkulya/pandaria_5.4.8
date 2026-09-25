-- Quest 31769 "The Final Blow!" - Thunder Hold final assault phase.
--
-- The battlefield terrain swap was only active for 31765 and 29694, leaving
-- the 31766 -> 31769 ground assault in the normal terrain. Keep the burning
-- Thunder Hold battlefield terrain through the active assault quests.
--
-- Also isolate Captain Doren, the final barricades and their munitions in a
-- private phase bit that is active only while 31769 is in the player's quest
-- log. This prevents the barricades from coming back after the quest is done,
-- while keeping their normal respawn behavior for another player doing 31769.

SET @ZONE_JADE_FOREST := 5785;
SET @FINAL_BLOW_PHASE_ENTRY := 8;
SET @FINAL_BLOW_PHASE_MASK := 134217728; -- 1 << 27, unused by map 870 spawns here.

DELETE FROM `conditions`
 WHERE `SourceTypeOrReferenceId` = 25
   AND `SourceGroup` = @ZONE_JADE_FOREST
   AND `SourceEntry` = 2
   AND `ElseGroup` IN (2, 3, 4, 5);

INSERT INTO `conditions`
 (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,
  `ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,
  `NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
 (25, @ZONE_JADE_FOREST, 2, 0, 2, 9, 0, 31766, 0, 0, 0, 0, 0, '', 'Jade Forest Battlefield Phase also while quest 31766 (Touching Ground) is taken'),
 (25, @ZONE_JADE_FOREST, 2, 0, 3, 9, 0, 31767, 0, 0, 0, 0, 0, '', 'Jade Forest Battlefield Phase also while quest 31767 (Finish Them!) is taken'),
 (25, @ZONE_JADE_FOREST, 2, 0, 4, 9, 0, 31768, 0, 0, 0, 0, 0, '', 'Jade Forest Battlefield Phase also while quest 31768 (Fire Is Always the Answer) is taken'),
 (25, @ZONE_JADE_FOREST, 2, 0, 5, 9, 0, 31769, 0, 0, 0, 0, 0, '', 'Jade Forest Battlefield Phase also while quest 31769 (The Final Blow!) is taken');

INSERT INTO `phase_definitions`
 (`zoneId`,`entry`,`phasemask`,`phaseId`,`terrainswapmap`,`worldMapArea`,`flags`,`comment`)
VALUES
 (@ZONE_JADE_FOREST, @FINAL_BLOW_PHASE_ENTRY, @FINAL_BLOW_PHASE_MASK, 0, 0, 0, 0, 'Jade Forest Thunder Hold final assault phase')
ON DUPLICATE KEY UPDATE
 `phasemask` = VALUES(`phasemask`),
 `phaseId` = VALUES(`phaseId`),
 `terrainswapmap` = VALUES(`terrainswapmap`),
 `worldMapArea` = VALUES(`worldMapArea`),
 `flags` = VALUES(`flags`),
 `comment` = VALUES(`comment`);

DELETE FROM `conditions`
 WHERE `SourceTypeOrReferenceId` = 25
   AND `SourceGroup` = @ZONE_JADE_FOREST
   AND `SourceEntry` = @FINAL_BLOW_PHASE_ENTRY;

INSERT INTO `conditions`
 (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,
  `ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,
  `NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
 (25, @ZONE_JADE_FOREST, @FINAL_BLOW_PHASE_ENTRY, 0, 0, 9, 0, 31769, 0, 0, 0, 0, 0, '', 'Thunder Hold final assault objects only while 31769 is taken');

UPDATE `creature`
   SET `phaseMask` = @FINAL_BLOW_PHASE_MASK
 WHERE `map` = 870
   AND `id` IN (66283, 66554, 66555, 66556);

UPDATE `gameobject`
   SET `phaseMask` = @FINAL_BLOW_PHASE_MASK
 WHERE `map` = 870
   AND `id` IN (215646, 215647, 215649, 215650, 215681)
   AND `position_x` BETWEEN 3100 AND 3210
   AND `position_y` BETWEEN -1005 AND -900;
