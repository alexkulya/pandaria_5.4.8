-- =====================================================================
-- Quest 31765 "Paint It Red!" - phase the player into the Jade Forest
-- Battlefield when the quest is accepted.
--
-- Jade Forest (zone 5785) phase_definitions:
--     entry 1  "Jade Forest Horde Starting Area"  phasemask 67108865, terrain 1076
--     entry 2  "Jade Forest Battlefield Phase"    terrainswap 972
-- Neither had any row in `conditions`, and PhaseMgr::CheckDefinition treats a
-- condition-less definition as ALWAYS active. So the Battlefield phase (entry 2)
-- was permanently applied to everyone, and accepting the quest changed nothing.
--
-- Gate the Battlefield phase behind CONDITION_QUESTTAKEN (9) for quest 31765, so
-- the terrain swap to the battlefield only happens while the quest is active -
-- i.e. it switches on the moment the player accepts it. The starting-area phase
-- (entry 1) is left untouched because it also carries the phasemask (67108865)
-- that keeps the Gunship Turret and Thunder Hold NPCs visible during the fight.
-- =====================================================================

DELETE FROM `conditions`
 WHERE `SourceTypeOrReferenceId` = 25 AND `SourceGroup` = 5785 AND `SourceEntry` = 2;

INSERT INTO `conditions`
 (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,
  `ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,
  `NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
 (25, 5785, 2, 0, 0, 9, 0, 31765, 0, 0, 0, 0, 0, '', 'Jade Forest Battlefield Phase active only while quest 31765 (Paint It Red) is taken');
