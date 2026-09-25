-- Jade Forest Horde chain after quest 31769 "The Final Blow!".
-- Public quest flow opens 31770, 29694 and 31771 only after 31769, then
-- 31774 after the immediate Honeydew/Sha follow-up block is finished.

UPDATE `quest_template`
   SET `PrevQuestId` = 31769
 WHERE `Id` IN (29694, 31978);

DELETE FROM `conditions`
 WHERE `SourceTypeOrReferenceId` = 19
   AND `SourceEntry` = 31774
   AND `ConditionTypeOrReference` = 8
   AND `ConditionValue1` IN (31771, 31773);

INSERT INTO `conditions`
 (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,
  `ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,
  `NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
 (19, 0, 31774, 0, 0, 8, 0, 31771, 0, 0, 0, 0, 0, '', 'Seeking Zin''jun requires Face to Face With Consequence rewarded'),
 (19, 0, 31774, 0, 0, 8, 0, 31773, 0, 0, 0, 0, 0, '', 'Seeking Zin''jun requires Prowler Problems rewarded');
