-- Fix The Final Blow! (31769) final assault visibility and Captain Doren event.
--
-- The Hellscream's Fist crash-site objects already live in phaseMask 67108864,
-- exposed to Horde players through Jade Forest phase entry 1 (67108865 +
-- terrain swap 1076). The previous private phase made Doren/barricades diverge
-- from that ship phase, so remove it and put the assault objects back in the
-- normal Horde view.

DELETE FROM `conditions`
 WHERE `SourceTypeOrReferenceId` = 25
   AND `SourceGroup` = 5785
   AND `SourceEntry` = 8;

DELETE FROM `phase_definitions`
 WHERE `zoneId` = 5785
   AND `entry` = 8;

DELETE FROM `conditions`
 WHERE `SourceTypeOrReferenceId` = 25
   AND `SourceGroup` = 5785
   AND `SourceEntry` = 2
   AND `ElseGroup` IN (2, 3, 4, 5);

UPDATE `creature`
   SET `phaseMask` = 1
 WHERE `map` = 870
   AND `id` IN (66283, 66554, 66555, 66556);

UPDATE `gameobject`
   SET `phaseMask` = 1
 WHERE `map` = 870
   AND `id` IN (215646, 215647, 215649, 215650, 215681)
   AND `position_x` BETWEEN 3100 AND 3210
   AND `position_y` BETWEEN -1005 AND -900;

-- Captain Doren should not teleport the player away. On approach he escapes in
-- a flying machine, grants the quest credit, starts the existing event spell on
-- the player, and despawns.
DELETE FROM `smart_scripts`
 WHERE (`entryorguid` = 66283 AND `source_type` = 0)
    OR (`entryorguid` = 6628300 AND `source_type` = 9);

INSERT INTO `smart_scripts` (
    `entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`,
    `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`,
    `event_param4`, `action_type`, `action_param1`, `action_param2`,
    `action_param3`, `action_param4`, `action_param5`, `action_param6`,
    `target_type`, `target_param1`, `target_param2`, `target_param3`,
    `target_x`, `target_y`, `target_z`, `target_o`, `comment`
) VALUES
(66283, 0, 0, 0, 10, 0, 100, 1, 0, 15, 0, 0, 80, 6628300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captain Doren - On Player Within 15 Yards - Run Final Blow escape event'),
(6628300, 9, 0, 0, 0, 0, 100, 0, 500, 500, 0, 0, 11, 44151, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captain Doren - Final Blow - Cast Turbo-Charged Flying Machine on self'),
(6628300, 9, 1, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 85, 130992, 0, 0, 0, 0, 0, 17, 0, 20, 0, 0, 0, 0, 0, 'Captain Doren - Final Blow - Cast Captain Doren credit spell on nearby player'),
(6628300, 9, 2, 0, 0, 0, 100, 0, 500, 500, 0, 0, 85, 130937, 0, 0, 0, 0, 0, 17, 0, 20, 0, 0, 0, 0, 0, 'Captain Doren - Final Blow - Start airship event spell for nearby player'),
(6628300, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Captain Doren - Final Blow - Despawn after escape');
