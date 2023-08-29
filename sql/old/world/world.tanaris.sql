DELETE FROM `spell_script_names` WHERE `spell_id` = 75991;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75991, "spell_emergency_rocket_pack");

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 40505;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES
(40505, 46598, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry` = 40505;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(40505, 40511, 0, 1, "Steamwheedle Balloon - Throwing Station", 8, 0);

DELETE FROM `creature_template_addon` WHERE `entry` = 40505;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(40505, 0, 0, 50331648, 1, 0, "");

UPDATE `creature_template` SET `IconName` = "vehichleCursor", `npcflag` = 1, `ScriptName` = "npc_steamwheedle_balloon" WHERE `entry` = 40604;
UPDATE `creature_template` SET `unit_flags` = 768, `VehicleId` = 752, `spell1` = 75560, `spell2` = 73257, `spell6` = 75991,
                               `ScriptName` = "npc_balloon_throwing_station" WHERE `entry` = 40511;
UPDATE `creature_template` SET `minlevel` = 45, `maxlevel` = 45, `speed_walk` = 3.2, `speed_run` = 2, `VehicleId` = 751,
                               `unit_flags` = 768, `InhabitType` = 4, `ScriptName` = "npc_steamwheedle_balloon_escort" WHERE `entry` = 40505;

DELETE FROM `script_waypoint` WHERE `entry` = 40505;
INSERT INTO `script_waypoint` (`entry`, `pointid`, `location_x`, `location_y`, `location_z`, `point_comment`) VALUES
(40505, 1, -7090.10, -3909.76, 75, "Steamwheedle Balloon"),
(40505, 2, -7050.32, -4211.33, 75, "Steamwheedle Balloon"),
(40505, 3, -6875.14, -4618.66, 75, "Steamwheedle Balloon"),
(40505, 4, -6796.45, -4735.78, 75, "Steamwheedle Balloon"),
(40505, 5, -6767.71, -4796.64, 75, "Steamwheedle Balloon"),
(40505, 6, -6767.39, -4889.12, 75, "Steamwheedle Balloon"),
(40505, 7, -6869.06, -4908.59, 75, "Steamwheedle Balloon"),
(40505, 8, -6980.09, -4898.15, 75, "Steamwheedle Balloon"),
(40505, 9, -7089.12, -4832.38, 75, "Steamwheedle Balloon"),
(40505, 10, -7098.96, -4682.06, 75, "Steamwheedle Balloon"),
(40505, 11, -7086.16, -4553.28, 75, "Steamwheedle Balloon"),
(40505, 12, -7141.32, -4441.87, 75, "Steamwheedle Balloon"),
(40505, 13, -7068.47, -4360.89, 75, "Steamwheedle Balloon"),
(40505, 14, -6998.87, -4385.42, 75, "Steamwheedle Balloon"),
(40505, 15, -6929.76, -4617.46, 75, "Steamwheedle Balloon"),
(40505, 16, -6875.14, -4618.66, 75, "Steamwheedle Balloon");

-- Steamwheedle Survivor
UPDATE `creature_template` SET `ScriptName` = "", `AIName` = "SmartAI" WHERE `entry` = 38571;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 38571 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(38571,0,0,1,8,0,100,0,72337,1,0,0,11,75710,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Steamwheedle Survivor - On Spellhit - Cast Jump"),
(38571,0,1,0,61,0,100,0,0,0,0,0,33,38576,0,0,0,0,0,7,0,0,0,0.0,0.0,0.0,0.0,"Steamwheedle Survivor - On Spellhit (Link) - Quest Credit");

DELETE FROM `conditions` WHERE `SourceEntry` = 72337;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 72337, 0, 0, 31, 0, 3, 38571, 0, 0, 0, "", "Targeting Steamwheedle Survivor");
