-- Blackrock Invader
UPDATE `creature_template` SET `ScriptName` = "", `AIName` = "SmartAI" WHERE `entry` = 42937;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 42937 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(42937, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Blackrock Invader - On Aggro - Say Text Line 0");

UPDATE `creature` SET `modelid` = 0, `wander_distance` = 10, `movement_type` = 1 WHERE `id` = 42937;
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 178429;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 42937);
DELETE FROM `waypoint_data` WHERE `id` IN (178472, 178466, 178464, 178462, 178208, 178195, 178443);
