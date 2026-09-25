-- Fix the post-cinematic state for quest 31769 "The Final Blow!".
--
-- Retail flow:
--   1. Approaching Captain Doren completes the final objective and plays the
--      Hellscream's Fist crash scene.
--   2. After the scene, Captain Doren/barricades are gone.
--   3. General Nazgrim is available for turn-in and Taran Zhu appears for the
--      Sha/Nazgrim scene and follow-up quest 31771.
--
-- The Sha phase was gated only on 31769 being rewarded, which is too late for
-- the scene before turn-in. Also, the scene Nazgrim/Taran spawns were in the
-- base phase and Captain Doren/barricades could return after respawn.

DELETE FROM `conditions`
 WHERE `SourceTypeOrReferenceId` = 25
   AND `SourceGroup` = 5785
   AND `SourceEntry` = 7;

INSERT INTO `conditions`
 (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,
  `ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,
  `NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
 -- CONDITION_QUEST_COMPLETE = 28, CONDITION_QUESTREWARDED = 8.
 (25, 5785, 7, 0, 0, 28, 0, 31769, 0, 0, 0, 0, 0, '',
  'Jade Forest Sha/Taran Zhu phase while quest 31769 is complete but not rewarded'),
 (25, 5785, 7, 0, 1, 8, 0, 31769, 0, 0, 0, 0, 0, '',
  'Jade Forest Sha/Taran Zhu phase after quest 31769 is rewarded');

-- The Nazgrim turn-in and Taran Zhu scene spawns should belong to the Sha scene phase.
UPDATE `creature`
   SET `phaseMask` = 33554432
 WHERE `map` = 870
   AND `guid` IN (506117, 506320)
   AND `id` IN (66656, 66657);

-- Doren, final barricade creatures, and their munitions should only be visible
-- while 31769 is active/incomplete. QuestStatus: INCOMPLETE = 3.
DELETE FROM `object_visibility_state`
 WHERE (`type` = 'Creature' AND `entryorguid` IN (66283, 66554, 66555, 66556))
    OR (`type` = 'GameObject' AND `entryorguid` IN (215646, 215647, 215649, 215650, 215681));

INSERT INTO `object_visibility_state`
 (`type`, `entryorguid`, `visibilityQuestID`, `visibilityQuestState`)
VALUES
 ('Creature', 66283, 31769, 3),
 ('Creature', 66554, 31769, 3),
 ('Creature', 66555, 31769, 3),
 ('Creature', 66556, 31769, 3),
 ('GameObject', 215646, 31769, 3),
 ('GameObject', 215647, 31769, 3),
 ('GameObject', 215649, 31769, 3),
 ('GameObject', 215650, 31769, 3),
 ('GameObject', 215681, 31769, 3);
