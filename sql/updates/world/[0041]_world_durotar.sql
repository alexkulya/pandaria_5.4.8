-- Durotar Riding Wolf SAI
SET @ENTRY := 39239;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"Durotar Riding Wolf - On Summoned - Run Script"),
(@ENTRY,0,1,0,40,0,100,0,1,39239,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durotar Riding Wolf - On Waypoint Reached - Waypoint Pause"),
(@ENTRY,0,2,3,58,0,100,0,18,39239,0,0,28,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durotar Riding Wolf - On Waypoint Ended - Remove All Auras"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,10682,10,0,0,0,0,0,"Durotar Riding Wolf - Linked To Id 2 - Set Data 0 1"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durotar Riding Wolf - Linked To Id 3 - Despawn");

-- Durotar Riding Wolf
DELETE FROM `waypoints` WHERE entry = 39239;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(39239, 1, -784.828430, -4853.188477, 18.949083,"Durotar Riding Wolf"),
(39239, 2,-757.674500, -4831.607910, 18713869,"Durotar Riding Wolf"),
(39239, 3,-741.303589, -4816.833984, 21.718535,"Durotar Riding Wolf"),
(39239, 4,-707.719421, -4785.533203, 32.301998,"Durotar Riding Wolf"),
(39239, 5,-697.944092, -4777.748047, 33.680172,"Durotar Riding Wolf"),
(39239, 6,-617.741699, -4710.905273, 33.676792,"Durotar Riding Wolf"),
(39239, 7,-600.734985, -4697.998047, 36.734055,"Durotar Riding Wolf"),
(39239, 8,-596.889160, -4701.468262, 36.190414,"Durotar Riding Wolf"),
(39239, 9,-516.861572, -4757.911621, 32.658184,"Durotar Riding Wolf"),
(39239, 10,-411.575012, -4789.998535, 32.343407,"Durotar Riding Wolf"),
(39239, 11,-370.150208, -4816.405273, 32.368488,"Durotar Riding Wolf"),
(39239, 12,-116.759697, -4746.250000, 22.285601,"Durotar Riding Wolf"),
(39239, 13,-3.148880, -4750.155762, 21.747847,"Durotar Riding Wolf"),
(39239, 14,90.526489, -4738.602051, 17.283243,"Durotar Riding Wolf"),
(39239, 15,106.053322, -4745.380371, 163148663,"Durotar Riding Wolf"),
(39239, 16,141.040482, -4767.691895, 12.295138,"Durotar Riding Wolf"),
(39239, 17,235.6723, -4735.171875, 10.103129,"Durotar Riding Wolf"),
(39239, 18,273.183441, -4746.169434, 9.778715,"Durotar Riding Wolf");

-- Kor'kron Loyalist SAI
SET @ENTRY := 39609;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,3,0,62,0,100,0,11245,0,0,0,85,74031,0,0,0,0,0,7,0,0,0,0,0,0,0,"summon wolf");

DELETE FROM `gossip_menu_option`  WHERE menu_id IN (11245);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_text_female`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `box_text_female`) VALUES
("11245", "0", "0", "Use my wolf to reach Garrosh", "", "1", "1", "0", "0", "0", "0", "", "");

DELETE FROM `locales_gossip_menu_option` WHERE menu_id =11245;
INSERT INTO `locales_gossip_menu_option` (`menu_id`, `option_text_loc6`, `option_text_loc7`) VALUES ('11245', 'Usa mi lobo para llegar a Garrosh', 'Usa mi lobo para llegar a Garrosh');