/* fix https://es.wowhead.com/quest=29570/rescatar-la-expedici%C3%B3n */
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 17894;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 17894);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17894, 0, 0, 0, 64, 0, 100, 6, 0, 0, 0, 0, 33, 17894, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Windcaller Claw - On Gossip Hello - Quest Credit \'Lost in Action\' (Phase 1) (No Repeat)');
/*  spawn creature https://tbc.wowhead.com/npc=17894/windcaller-claw*/
DELETE FROM `creature` WHERE `id` = 17894;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawntimesecs_max`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `movement_type`, `npcflag`, `npcflag2`, `unit_flags`, `unit_flags2`, `dynamicflags`, `ScriptName`, `walk_mode`) values
("962675", "17894", "546", "0", "0", "4", "1", "0", "0", "292.791", "-125.394", "29.726", "3.14187", "300", "0", "0", "0", "47312", "0", "0", "0", "0", "0", "0", "0", "", "0");



