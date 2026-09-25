-- Quest 31769 "The Final Blow!" - repair live phasing after in-game test.
--
-- The Hellscream's Fist/crash-site phase was only TEAM_HORDE, so a GM or
-- cross-faction tester on the Horde chain could reach Doren without seeing the
-- ship. Keep normal Horde visibility, but also enable it for players actively
-- walking the Horde intro chain.
--
-- Several post-crash / Honeydew follow-up NPCs and barrel credit bunnies were
-- still in base phase 1, making them visible before 31769 is finished. Move
-- them into the existing post-31769 phase bit (33554432), exposed by
-- phase_definitions entry 7.

DELETE FROM `conditions`
 WHERE `SourceTypeOrReferenceId` = 25
   AND `SourceGroup` = 5785
   AND `SourceEntry` = 1;

INSERT INTO `conditions`
 (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,
  `ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,
  `NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
 -- CONDITION_TEAM = 6, HORDE = 67.
 (25, 5785, 1, 0, 0, 6, 0, 67, 0, 0, 0, 0, 0, '',
  'Jade Forest Hellscream''s Fist crash site for Horde'),
 -- CONDITION_QUESTTAKEN = 9. Cross-faction/GM testers on the Horde chain also need the ship.
 (25, 5785, 1, 0, 1, 9, 0, 31765, 0, 0, 0, 0, 0, '',
  'Jade Forest Hellscream''s Fist crash site while 31765 is active'),
 (25, 5785, 1, 0, 2, 9, 0, 31766, 0, 0, 0, 0, 0, '',
  'Jade Forest Hellscream''s Fist crash site while 31766 is active'),
 (25, 5785, 1, 0, 3, 9, 0, 31767, 0, 0, 0, 0, 0, '',
  'Jade Forest Hellscream''s Fist crash site while 31767 is active'),
 (25, 5785, 1, 0, 4, 9, 0, 31768, 0, 0, 0, 0, 0, '',
  'Jade Forest Hellscream''s Fist crash site while 31768 is active'),
 (25, 5785, 1, 0, 5, 9, 0, 31769, 0, 0, 0, 0, 0, '',
  'Jade Forest Hellscream''s Fist crash site while 31769 is active'),
 -- CONDITION_QUEST_COMPLETE = 28, CONDITION_QUESTREWARDED = 8.
 (25, 5785, 1, 0, 6, 28, 0, 31769, 0, 0, 0, 0, 0, '',
  'Jade Forest Hellscream''s Fist crash site while 31769 is complete'),
 (25, 5785, 1, 0, 7, 8, 0, 31769, 0, 0, 0, 0, 0, '',
  'Jade Forest Hellscream''s Fist crash site after 31769 is rewarded');

-- Post-31769 scene and Honeydew follow-up actors.
UPDATE `creature`
   SET `phaseMask` = 33554432
 WHERE `map` = 870
   AND `guid` IN (
        505833, -- Sergeant Gorrok rescue target
        506348, -- Kor'kron Dubs post-scene
        580178, -- General Nazgrim ground/camp scene
        505802, -- Mayor Honeydew
        505801, -- Elder Honeypaw
        506355, -- General Nazgrim lower scene
        505926, -- Sue-Ji the Tender
        505929, -- Ellie Honeypaw
        505895, 505925, -- Gi-Oh
        505827, -- Taran Zhu
        505898, -- Ellie Honeypaw
        505199, 505924, -- Kai-Lin Honeydew
        505832, -- Sergeant Gorrok
        505820  -- Ellie Honeypaw
   );

UPDATE `creature`
   SET `phaseMask` = 33554432
 WHERE `map` = 870
   AND `id` = 66873
   AND `position_x` BETWEEN 2850 AND 3350
   AND `position_y` BETWEEN -1050 AND -550;

-- The visible Honeybrew barrels used by 31772/31978 belong with the same
-- post-crash Honeydew phase as their credit bunnies.
UPDATE `gameobject`
   SET `phaseMask` = 33554432
 WHERE `map` = 870
   AND `id` = 215695
   AND `position_x` BETWEEN 2850 AND 3350
   AND `position_y` BETWEEN -1050 AND -550;
