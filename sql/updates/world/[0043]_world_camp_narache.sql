-- Похитительница винтовок - спавны без движения и статик эмоция

UPDATE `creature` SET `wander_distance` = 10, `movement_type` = 1 WHERE `guid` = 260260;
DELETE FROM `creature_addon` WHERE `guid` = 260260;
UPDATE `creature_addon` SET `bytes2` = 1 WHERE `guid` = 260338;
DELETE FROM `creature_template_addon` WHERE `entry` = 3209;

DELETE FROM `waypoint_data` WHERE `id` IN (260260, 260338);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `move_flag`) VALUES
(260338, 0, -2931.39, -252.705, 59.468, 0),
(260338, 1, -2932.56, -261.01, 58.968, 0),
(260338, 2, -2931.23, -273.128, 59.0048, 0),
(260338, 3, -2930.8, -289.241, 59.1898, 0),
(260338, 4, -2930.68, -302.472, 58.8884, 0),
(260338, 5, -2932.27, -318.439, 58.6325, 0),
(260338, 6, -2938.28, -335.476, 57.9827, 0),
(260338, 7, -2949.51, -348.207, 56.5066, 0),
(260338, 8, -2966.47, -362.797, 54.0955, 0),
(260338, 9, -2979.69, -376.811, 51.4516, 0),
(260338, 10, -2992.68, -392.806, 49.0324, 0),
(260338, 11, -2996.55, -412.488, 48.0749, 0),
(260338, 12, -3000.19, -438.071, 45.7977, 0),
(260338, 13, -3000.51, -446.528, 45.5091, 0),
(260338, 14, -3000.19, -438.071, 45.7977, 0),
(260338, 15, -2996.55, -412.488, 48.0749, 0),
(260338, 16, -2992.68, -392.806, 49.0324, 0),
(260338, 17, -2979.69, -376.811, 51.4516, 0),
(260338, 18, -2966.47, -362.797, 54.0955, 0),
(260338, 19, -2949.51, -348.207, 56.5066, 0),
(260338, 20, -2938.28, -335.476, 57.9827, 0),
(260338, 21, -2932.27, -318.439, 58.6325, 0),
(260338, 22, -2930.68, -302.472, 58.8884, 0),
(260338, 23, -2930.8, -289.241, 59.1898, 0),
(260338, 24, -2931.23, -273.128, 59.0048, 0),
(260338, 25, -2932.56, -261.01, 58.968, 0),
(260338, 26, -2931.39, -252.705, 59.468, 0),
(260338, 27, -2934.3, -247.455, 59.9105, 0);

UPDATE `creature_template` SET `ScriptName` = "npc_mulgore_captured_brave" WHERE `entry` = 38345;
DELETE FROM `creature_text` WHERE `entry` = 38345;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38345, 0, 0, "The quilboar will pay!", "", 12, 0, 100, 4, 0, 0, "Captured Brave"),
(38345, 0, 1, "Thank the Earth Mother!", "", 12, 0, 100, 4, 0, 0, "Captured Brave"),
(38345, 0, 2, "I can move again!", "", 12, 0, 100, 4, 0, 0, "Captured Brave");

DELETE FROM `conditions` WHERE `SourceEntry` = 71725 AND `SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 71725, 0, 0, 31, 0, 3, 38345, 0, 0, 0, 0, "", "Unlocking - Target 'Captured Brave'");

UPDATE `creature` SET `spawntimesecs` = 30 WHERE `id` = 38345;
UPDATE `gameobject_template` SET `data3` = 180000 WHERE `entry` = 202112;

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` IN (36942, 36943);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (36942, 36943) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(36942, 0, 0, 0, 0, 0, 100, 0, 8000, 10000, 9000, 11000, 11, 81502, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Fledgling Brave - In Combat - Cast Spell 'Cleave'"),
(36942, 0, 1, 0, 0, 0, 100, 0, 13000, 15000, 14000, 16000, 11, 81500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fledgling Brave - In Combat - Cast Spell 'War Stomp'"),

(36943, 0, 0, 0, 0, 0, 100, 0, 8000, 10000, 28000, 30000, 11, 11977, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Bristleback Invader - In Combat - Cast Spell 'Rend'");

UPDATE `creature` SET `wander_distance` = 10, `movement_type` = 1 WHERE `id` IN (2966, 2952, 36708);
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (260106, 261692, 261693, 261689, 260157, 260156, 260158);
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `id` = 36697;
UPDATE `creature` SET `wander_distance` = 3, `movement_type` = 1 WHERE `guid` IN (261772, 261773, 261774, 261775, 261776, 261777, 261779);

DELETE FROM `creature_addon` WHERE `guid` IN (261772, 261773, 261774, 261775, 261776, 261777, 261779);
DELETE FROM `waypoint_data` WHERE `id` IN (261772, 261773, 261774, 261775, 261776, 261777, 261779);

UPDATE `creature_template_addon` SET `auras` = "" WHERE `entry` IN (2952, 36697, 36708, 43599);
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` IN (2952, 2966, 36696, 36697, 36708, 43599, 36712);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2952, 2966, 36696, 36697, 36708, 43599, 36712) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2952, 0, 0, 0, 11, 0, 100, 1, 0, 0, 0, 0, 11, 81653, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bristleback Invaders - On Respawn - Cast Spell 'Bristleback' (No Repeat)"),

(2966, 0, 0, 0, 0, 0, 100, 0, 2000, 4500, 12000, 15000, 11, 79581, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Young Battleboar - In Combat - Cast Spell 'Angry Snort'"),

(36696, 0, 0, 1, 8, 0, 100, 1, 69228, 0, 0, 0, 11, 42726, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Armored Battleboar - On Spell Hit - Cast Spell 'Cosmetic - Immolation (Whole Body)'"),
(36696, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 70113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Armored Battleboar - On Spell Hit (Link) - Cast Spell 'Sprint - No Visual'"),
(36696, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Armored Battleboar - On Spell Hit (Link) - Set React State Passive"),
(36696, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 122, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Armored Battleboar - On Spell Hit (Link) - Flee"),
(36696, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 1, 7000, 7000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Armored Battleboar - On Spell Hit (Link) - Create Timed Event"),
(36696, 0, 5, 6, 59, 0, 100, 0, 1, 0, 0, 0, 28, 42726, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Armored Battleboar - On Timed Event Triggered - Remove Aura 'Cosmetic - Immolation (Whole Body)'"),
(36696, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Armored Battleboar - On Timed Event Triggered (Link) - Set React State Aggressive"),
(36696, 0, 7, 0, 0, 0, 100, 1, 2000, 2000, 0, 0, 11, 3385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Armored Battleboar - In Combat - Cast Spell 'Boar Charge'"),

(36697, 0, 0, 0, 11, 0, 100, 1, 0, 0, 0, 0, 11, 81653, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bristleback Thorncaller - On Respawn - Cast Spell 'Bristleback' (No Repeat)"),
(36697, 0, 1, 0, 1, 0, 100, 1, 1000, 1000, 1000, 1000, 11, 51733, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bristleback Thorncaller - Out of Combat - Cast Spell 'Shadow Channelling' (No Repeat)"),
(36697, 0, 2, 0, 9, 0, 100, 0, 0, 30, 14000, 15000, 11, 31287, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Bristleback Thorncaller - Within 0-30 Range - Cast Spell 'Entangling Roots'"),

(36708, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, 11, 81655, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Bristleback Gun Thief - In Combat - Cast Spell 'Shoot'"),
(36708, 0, 1, 0, 9, 0, 100, 0, 5, 30, 12000, 18000, 11, 81654, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Bristleback Gun Thief - Within 5-30 Range - Cast Spell 'Clumsy Shot'"),
(36708, 0, 2, 0, 11, 0, 100, 1, 0, 0, 0, 0, 11, 81653, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Bristleback Gun Thief - On Respawn - Cast Spell 'Bristleback' (No Repeat)"),

(43599, 0, 0, 0, 11, 0, 100, 1, 0, 0, 0, 0, 11, 81653, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Thornguard - On Respawn - Cast SPell 'Bristleback' (No Repeat)"),
(43599, 0, 1, 0, 0, 0, 100, 0, 2000, 4500, 12000, 18000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Thornguard - In Combat - Cast Spell 'Cleave'"),

(36712, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Chief Squealer Thornmantle - On Aggro - Say Text Line 0 (No Repeat)"),
(36712, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 12000, 15000, 11, 81691, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Chief Squealer Thornmantle - In Combat - Cast Spell 'Quillhorn'"),
(36712, 0, 2, 0, 0, 0, 100, 0, 4000, 9000, 18000, 24000, 11, 81695, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Chief Squealer Thornmantle - In Combat - Cast Spell 'Torch Toss'");

DELETE FROM `creature_text` WHERE `entry` = 36712;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36712, 0, 0, "Squealer take this land! Tauren will burn!", "", 12, 0, 100, 0, 0, 0, "Chief Squealer Thornmantle");

DELETE FROM `conditions` WHERE `SourceEntry` = 69228 AND `SourceTypeOrReferenceId` = 13 AND `SourceGroup` IN (3, 4);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 3, 69228, 0, 0, 31, 0, 3, 36727, 0, 0, 0, 0, "", "Throw Torch - Target First Trough"),
(13, 3, 69228, 0, 1, 31, 0, 3, 37155, 0, 0, 0, 0, "", "Throw Torch - Target Second Trough"),
(13, 3, 69228, 0, 2, 31, 0, 3, 37156, 0, 0, 0, 0, "", "Throw Torch - Target Third Trough"),
(13, 4, 69228, 0, 0, 31, 0, 3, 36696, 0, 0, 0, 0, "", "Throw Torch - Target Armored Battleboar");
