UPDATE `creature` SET `position_x` = 2280.15, `position_y` = 5179.14, `position_z` = 11.423, `orientation` = 4.38078, `spawntimesecs` = 180 WHERE `guid` = 114713;
UPDATE `creature` SET `position_x` = 2280.96, `position_y` = 5180.91, `position_z` = 11.423, `orientation` = 3.735, `spawntimesecs` = 180 WHERE `guid` = 114714;
UPDATE `creature` SET `position_x` = 2282.03, `position_y` = 5179.58, `position_z` = 11.423, `orientation` = 3.76991, `spawntimesecs` = 180 WHERE `guid` = 114715;
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 114713;
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (114714, 114715);
DELETE FROM `creature` WHERE `guid` = 110383 AND `id` = 25260;
UPDATE `creature_template` SET `flags_extra` = 2, `InhabitType` = 3 WHERE  `entry` IN (25258, 25259, 25261);

UPDATE `creature_template_addon` SET `bytes2` = 4097 WHERE `entry` = 25260;
DELETE FROM `creature_template_addon` WHERE `entry` IN (25258, 25259, 25261);
DELETE FROM `creature_addon` WHERE `guid` IN (110383, 114713, 114714, 114715);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(114713, 114713*10, 4097),
(114714, 0, 4097),
(114715, 0, 4097);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (25245, 25258, 25259, 25260, 25261);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25245, 25258, 25259, 25260, 25261) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25258*100, 25258*100+01, 25258*100+02, 25258*100+03) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25245,0,0,0,38,0,100,0,1,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"James Deacon - On Data Set 1 1 - Say Text Line 0"),
(25245,0,1,0,38,0,100,0,2,2,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"James Deacon - On Data Set 2 2 - Say Text Line 1"),
(25245,0,2,0,38,0,100,0,3,3,0,0,5,397,0,0,0,0,0,1,0,0,0,0,0,0,0,"James Deacon - On Data Set 3 3 - Play Emote (397)"),

(25258,0,0,0,34,0,100,1,2,5,0,0,80,25258*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Reached Point 5 - Start Script (No Repeat)"),
(25258,0,1,0,34,0,100,0,2,9,0,0,80,25258*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Reached Point 9 - Start Script"),
(25258,0,2,0,34,0,100,0,2,10,0,0,80,25258*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Reached Point 10 - Start Script"),
(25258,0,3,0,34,0,100,1,2,15,0,0,12,25260,3,180000,0,0,0,8,0,0,0,2255.77,5186.26,11.4391,1.47479,"Footman Rob - On Reached Point 15 - Summon Creature 'Footman Mitch' (No Repeat)"),
(25258,0,4,0,34,0,100,0,2,17,0,0,80,25258*100+03,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Reached Point 17 - Start Script"),
(25258,0,5,0,17,0,100,0,25260,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Footman Rob - On Summoned Unit - Store Targetlist"),
(25258,0,6,0,1,0,100,1,100,100,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - Out of Combat - Change Equipment (No Repeat)"),
(25258,0,7,0,1,0,100,1,100,100,0,0,71,0,0,0,0,0,0,10,114714,25259,0,0,0,0,0,"Footman Rob - Out of Combat - Change Equipment (No Repeat)"),
(25258,0,8,0,1,0,100,1,100,100,0,0,71,0,0,0,0,0,0,10,114715,25261,0,0,0,0,0,"Footman Rob - Out of Combat - Change Equipment (No Repeat)"),

(25258*100,9,0,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Say Text Line 0"),
(25258*100,9,1,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,10,114714,25259,0,0,0,0,0,"Footman Rob - On Script - Say Text Line 0"),

(25258*100+01,9,0,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Say Text Line 1"),
(25258*100+01,9,1,0,0,0,100,0,6000,6000,0,0,45,1,1,0,0,0,0,10,95029,25245,0,0,0,0,0,"Footman Rob - On Script - Set Data 1 1"),
(25258*100+01,9,2,0,0,0,100,0,6000,6000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Say Text Line 2"),
(25258*100+01,9,3,0,0,0,100,0,6000,6000,0,0,45,2,2,0,0,0,0,10,95029,25245,0,0,0,0,0,"Footman Rob - On Script - Set Data 2 2"),
(25258*100+01,9,4,0,0,0,100,0,3000,3000,0,0,45,3,3,0,0,0,0,10,95029,25245,0,0,0,0,0,"Footman Rob - On Script - Set Data 3 3"),
(25258*100+01,9,5,0,0,0,100,0,7000,7000,0,0,17,423,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Set Emote State (423)"),
(25258*100+01,9,6,0,0,0,100,0,0,0,0,0,71,1,0,2703,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(25258*100+01,9,7,0,0,0,100,0,0,0,0,0,71,1,0,2703,0,0,0,10,114714,25259,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(25258*100+01,9,8,0,0,0,100,0,0,0,0,0,71,1,0,2703,0,0,0,10,114715,25261,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(25258*100+01,9,9,0,0,0,100,0,5000,5000,0,0,17,423,0,0,0,0,0,10,114714,25259,0,0,0,0,0,"Footman Rob - On Script - Set Emote State (423)"),
(25258*100+01,9,10,0,0,0,100,0,0,0,0,0,17,423,0,0,0,0,0,10,114715,25261,0,0,0,0,0,"Footman Rob - On Script - Set Emote State (423)"),
(25258*100+01,9,11,0,0,0,100,0,22000,22000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Set Emote State (0)"),
(25258*100+01,9,12,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,10,114714,25259,0,0,0,0,0,"Footman Rob - On Script - Set Emote State (0)"),
(25258*100+01,9,13,0,0,0,100,0,0,0,0,0,17,0,0,0,0,0,0,10,114715,25261,0,0,0,0,0,"Footman Rob - On Script - Set Emote State (0)"),
(25258*100+01,9,14,0,0,0,100,0,0,0,0,0,71,1,0,2703,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(25258*100+01,9,15,0,0,0,100,0,0,0,0,0,71,1,0,2703,0,0,0,10,114714,25259,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(25258*100+01,9,16,0,0,0,100,0,0,0,0,0,71,1,0,2703,0,0,0,10,114715,25261,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(25258*100+01,9,17,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(25258*100+01,9,18,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,10,114714,25259,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),
(25258*100+01,9,19,0,0,0,100,0,0,0,0,0,71,0,0,0,0,0,0,10,114715,25261,0,0,0,0,0,"Footman Rob - On Script - Change Equipment"),

(25258*100+02,9,0,0,0,0,100,0,1000,1000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Say Text Line 3"),
(25258*100+02,9,1,0,0,0,100,0,3000,3000,0,0,45,1,1,0,0,0,0,10,114714,25259,0,0,0,0,0,"Footman Rob - On Script - Set Data 1 1"),
(25258*100+02,9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,10,114715,25261,0,0,0,0,0,"Footman Rob - On Script - Set Data 1 1"),
(25258*100+02,9,3,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,10,114715,25261,0,0,0,0,0,"Footman Rob - On Script - Say Text Line 0"),
(25258*100+02,9,4,0,0,0,100,0,6000,6000,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Play Emote (11)"),
(25258*100+02,9,5,0,0,0,100,0,0,0,0,0,5,11,0,0,0,0,0,10,114714,25259,0,0,0,0,0,"Footman Rob - On Script - Play Emote (11)"),
(25258*100+02,9,6,0,0,0,100,0,0,0,0,0,5,11,0,0,0,0,0,10,114715,25261,0,0,0,0,0,"Footman Rob - On Script - Play Emote (11)"),
(25258*100+02,9,7,0,0,0,100,0,1000,1000,0,0,5,274,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Play Emote (274)"),
(25258*100+02,9,8,0,0,0,100,0,0,0,0,0,5,274,0,0,0,0,0,10,114714,25259,0,0,0,0,0,"Footman Rob - On Script - Play Emote (274)"),
(25258*100+02,9,9,0,0,0,100,0,0,0,0,0,5,274,0,0,0,0,0,10,114715,25261,0,0,0,0,0,"Footman Rob - On Script - Play Emote (274)"),

(25258*100+03,9,0,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,10,114714,25259,0,0,0,0,0,"Footman Rob - On Script - Set Data 2 2"),
(25258*100+03,9,1,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,10,114715,25261,0,0,0,0,0,"Footman Rob - On Script - Set Data 2 2"),
(25258*100+03,9,2,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,12,1,0,0,0,0,0,0,"Footman Rob - On Script - Set Data 1 1"),
(25258*100+03,9,3,0,0,0,100,0,100,100,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Rob - On Script - Despawn (1000 ms)"),

(25259,0,0,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.282578,"Footman George - On Data Set 1 1 - Set Orientation (4.282578)"),
(25259,0,1,0,38,0,100,0,2,2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman George - On Data Set 2 2 - Despawn"),

(25260,0,0,1,63,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Mitch - On Just Created - Say Text Line 0"),
(25260,0,1,2,61,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Mitch - On Just Created - Set Run Off"),
(25260,0,2,0,61,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,2264.93652,5221.9863,11.2882,4.3713,"Footman Mitch - On Just Created - Move To Position"),
(25260,0,3,0,38,0,100,0,1,1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Mitch - On Data Set 1 1 - Despawn"),

(25261,0,0,0,38,0,100,0,1,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.28258,"Footman Chuck - On Data Set 1 1 - Set Orientation (4.28258)"),
(25261,0,2,0,38,0,100,0,2,2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Footman Chuck - On Data Set 2 2 - Despawn");

DELETE FROM `creature_text` WHERE `entry` IN (25245, 25258, 25259, 25260, 25261);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
-- James Deacon
(25245, 0, 0, "You lads know the drill. No alcohol to servicemen on duty. You want the general to kill me himself?", "", 12, 7, 100, 274, 0, 0, "James Deacon"),
(25245, 1, 0, "All right, all right... but you didn't get these from me!", "", 12, 7, 100, 6, 0, 0, "James Deacon"),
-- Footman Rob
(25258, 0, 0, "One last drink before we head to the front?", "", 12, 7, 100, 1, 0, 0, "Footman Rob"),
(25258, 1, 0, "Barkeep! Bring out your strongest ale. We're off to the front.", "", 12, 7, 100, 1, 0, 0, "Footman Rob"),
(25258, 2, 0, "You'll surely make an exception for us, eh? We might not come back.", "", 12, 7, 100, 1, 0, 0, "Footman Rob"),
(25258, 3, 0, "I guess that's it then. Off we go.", "", 12, 7, 100, 1, 0, 0, "Footman Rob"),
-- Footman George
(25259, 0, 0, "Sure, why not?", "", 12, 7, 100, 6, 0, 0, "Footman George"),
-- Footman Mitch
(25260, 0, 0, "Hey, guys! Wait up!", "", 12, 7, 100, 0, 0, 0, "Footman Mitch"),
-- Footman Chuck
(25261, 0, 0, "That was the worst beer I've ever had.", "", 12, 7, 100, 0, 0, 0, "Footman Chuck");

DELETE FROM `creature_formations` WHERE `leaderGUID` = 114713;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(114713, 114713, 0, 0, 4, 0, 0),
(114713, 114714, 2, 305, 4, 0, 0),
(114713, 114715, 2, 55, 4, 0, 0);

DELETE FROM `waypoint_data` WHERE `id` = 114713*10;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
(114713*10, 1, 2277.23, 5177.21, 11.34, 0, 0, 0, 0, 100, 0),
(114713*10, 2, 2268.97, 5175.55, 11.1665, 0, 0, 0, 0, 100, 0),
(114713*10, 3, 2254.59, 5188.89, 11.384, 0, 0, 0, 0, 100, 0),
(114713*10, 4, 2254.27, 5196.42, 11.3837, 0, 0, 0, 0, 100, 0),
(114713*10, 5, 2260.67, 5200.36, 11.3711, 0, 0, 0, 0, 100, 0),
(114713*10, 6, 2264.38, 5199.09, 11.3676, 0, 13000, 0, 0, 100, 0),
(114713*10, 7, 2270.18, 5196.94, 12.4959, 0, 0, 0, 0, 100, 0),
(114713*10, 8, 2275.23, 5194.94, 12.49, 0, 0, 0, 0, 100, 0),
(114713*10, 9, 2276.23, 5197.58, 12.4896, 0, 0, 0, 0, 100, 0),
(114713*10, 10, 2279.08, 5206.5, 12.494, 0, 60000, 0, 0, 100, 0),
(114713*10, 11, 2278.6, 5205.3, 12.4926, 0, 16000, 0, 0, 100, 0),
(114713*10, 12, 2275.55, 5197.84, 12.4897, 0, 0, 0, 0, 100, 0),
(114713*10, 13, 2275.60, 5194.96, 12.489, 0, 0, 0, 0, 100, 0),
(114713*10, 14, 2265.21, 5198.54, 11.3533, 0, 0, 0, 0, 100, 0),
(114713*10, 15, 2258.23, 5201.82, 11.3182, 0, 0, 0, 0, 100, 0),
(114713*10, 16, 2258.98, 5205.83, 11.322, 0, 0, 0, 0, 100, 0),
(114713*10, 17, 2261, 5212.02, 11.2373, 0, 0, 0, 0, 100, 0),
(114713*10, 18, 2268.17, 5226.07, 11.2421, 0, 5000, 0, 0, 100, 0);
