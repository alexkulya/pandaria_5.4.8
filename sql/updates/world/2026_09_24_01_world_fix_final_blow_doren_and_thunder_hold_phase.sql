-- Quest 31769 "The Final Blow!" - repair Captain Doren trigger and
-- Thunder Hold assault phasing.
--
-- Doren used to carry both OOC LOS variants in the imported data. Keeping only
-- param1 = 0 makes the approach event miss some tester/player relation states,
-- especially cross-faction GM testing the Horde chain.
--
-- The normal Thunder Hold defenders/workers belong to the previous assault
-- quests. If they remain in base phase 1, they are still visible during 31769
-- after the barricades, blocking the retail final scene where Doren escapes and
-- the airship/cinematic takes over.

DELETE FROM `smart_scripts`
 WHERE `entryorguid` = 66283
   AND `source_type` = 0;

INSERT INTO `smart_scripts` (
    `entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`,
    `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`,
    `event_param4`, `action_type`, `action_param1`, `action_param2`,
    `action_param3`, `action_param4`, `action_param5`, `action_param6`,
    `target_type`, `target_param1`, `target_param2`, `target_param3`,
    `target_x`, `target_y`, `target_z`, `target_o`, `comment`
) VALUES
(66283, 0, 0, 0, 10, 0, 100, 1, 0, 15, 0, 0, 80, 6628300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
 'Captain Doren - On hostile player within 15 yards - Run Final Blow escape event'),
(66283, 0, 1, 0, 10, 0, 100, 1, 1, 15, 0, 0, 80, 6628300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
 'Captain Doren - On friendly/neutral player within 15 yards - Run Final Blow escape event');

DELETE FROM `conditions`
 WHERE `SourceTypeOrReferenceId` = 25
   AND `SourceGroup` = 5785
   AND `SourceEntry` = 8;

DELETE FROM `phase_definitions`
 WHERE `zoneId` = 5785
   AND `entry` = 8;

INSERT INTO `phase_definitions`
 (`zoneId`, `entry`, `phasemask`, `phaseId`, `terrainswapmap`, `worldMapArea`, `flags`, `comment`)
VALUES
 (5785, 8, 134217728, 0, 0, 0, 0, 'Jade Forest Thunder Hold early assault phase');

INSERT INTO `conditions`
 (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,
  `ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,
  `NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
 (25, 5785, 8, 0, 0, 9, 0, 31765, 0, 0, 0, 0, 0, '',
  'Thunder Hold defenders while 31765 is active'),
 (25, 5785, 8, 0, 1, 9, 0, 31766, 0, 0, 0, 0, 0, '',
  'Thunder Hold defenders while 31766 is active'),
 (25, 5785, 8, 0, 2, 9, 0, 31767, 0, 0, 0, 0, 0, '',
  'Thunder Hold defenders while 31767 is active'),
 (25, 5785, 8, 0, 3, 9, 0, 31768, 0, 0, 0, 0, 0, '',
  'Thunder Hold defenders while 31768 is active');

UPDATE `creature`
   SET `phaseMask` = 134217728
 WHERE `map` = 870
   AND `zoneId` = 5785
   AND `id` IN (
        66200, -- Thunder Hold Soldier
        66202, -- Thunder Hold Laborer
        66203, -- Thunder Hold Cannon
        66284, -- Thunder Hold Laborer
        66285, -- Thunder Hold Infantryman
        66286, -- Thunder Hold Mender
        66287, -- Thunder Hold Lieutenant
        66288, -- Thunder Hold Sharp-Shooter
        66348, -- Thunder Hold Armsman
        66395, -- Thunder Hold Cannoneer
        66647, -- Thunder Hold Sharp-Shooter
        66648, -- Thunder Hold Lieutenant
        66649, -- Thunder Hold Mender
        66650, -- Thunder Hold Infantryman
        66651, -- Thunder Hold Laborer
        66654, -- Thunder Hold Supplies
        66948  -- Twisted Corpse
   );

-- These cannon spawns ship with zoneId = 0 in this dump, so catch them by
-- their Thunder Hold coordinates instead of the zone column.
UPDATE `creature`
   SET `phaseMask` = 134217728
 WHERE `map` = 870
   AND `id` = 66203
   AND `position_x` BETWEEN 3000 AND 3250
   AND `position_y` BETWEEN -925 AND -800;
