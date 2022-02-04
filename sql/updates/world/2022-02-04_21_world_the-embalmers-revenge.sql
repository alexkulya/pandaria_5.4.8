--https://www.wowhead.com/quest=26727/the-embalmers-revenge
update creature set phaseMask = 3 where guid in (170402,170405,170406,170413,170431,170432);
update creature set phaseMask = 2 where id = 43903;
DELETE FROM `world_quest_phases` WHERE QuestId = 26727;
INSERT INTO `world_quest_phases` VALUES (26727, 2, 1, 42, 0, 10, 'Quest ID: 26727 - The Embalmer\'s Revenge (ON AURA UPDATE)');
INSERT INTO `world_quest_phases` VALUES (26727, 1, 2, 42, 0, 10, 'Quest ID: 26727 - The Embalmer\'s Revenge (ON AURA UPDATE)');
INSERT INTO `world_quest_phases` VALUES (26727, 1, 0, 42, 0, 10, 'Quest ID: 26727 - The Embalmer\'s Revenge (ON AURA UPDATE)');
INSERT INTO `world_quest_phases` VALUES (26727, 1, 3, 42, 0, 10, 'Quest ID: 26727 - The Embalmer\'s Revenge (ON AURA UPDATE)');
UPDATE `creature_template` SET `ScriptName`='', `AIName`='SmartAI' WHERE (`entry`='43862');
UPDATE creature_template SET AIName="SmartAI" WHERE entry=43915 LIMIT 1;
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=43862;
UPDATE `creature_template` SET `flags_extra`=2 WHERE `entry`=43915;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES ('43862', '0', '0', '0', '0', '0', '100', '0', '1000', '20000', '0', '0', '0', '11', '3106', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '缝合怪释放-腐蚀光环');
DELETE FROM `smart_scripts` WHERE `entryorguid`=43915 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(43915,0,0,1,54,0,100,0,5000,5000,8000,8000,1,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Stalvan Mistmantle - On Aggro - Say Line 0"),
(43915,0,1,0,61,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0.0,0.0,0.0,0.0,"Just Summoned - Set Passive");
INSERT INTO `gameobject` VALUES (99269, 182090, 0, 10, 42, 1, 2, 0, -10540.8, -1155.23, 29.0161, 6.24151, 0, 0, -0.0208371, 0.999783, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99270, 182090, 0, 10, 42, 1, 2, 0, -10540.6, -1159.19, 35.388, 5.97448, 0, 0, -0.153743, 0.988111, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99271, 182090, 0, 10, 42, 1, 2, 0, -10540.4, -1171.94, 27.6216, 0.0447138, 0, 0, -0.0223551, -0.99975, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99272, 183987, 0, 10, 42, 1, 2, 0, -10542.9, -1175.6, 39.9212, 0.260697, 0, 0, -0.12998, -0.991517, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99273, 182090, 0, 10, 42, 1, 2, 0, -10544.7, -1207.75, 27.1151, 6.15117, 0, 0, -0.0659589, 0.997822, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99274, 182090, 0, 10, 42, 1, 2, 0, -10540.7, -1220.71, 29.8575, 5.84094, 0, 0, -0.219326, 0.975652, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99275, 183987, 0, 10, 42, 1, 2, 0, -10547.5, -1214.76, 35.7341, 0.0957472, 0, 0, -0.0478553, -0.998854, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99276, 182090, 0, 10, 42, 1, 2, 0, -10583.2, -1192.99, 27.7733, 3.4926, 0, 0, -0.984639, 0.174604, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99277, 182090, 0, 10, 42, 1, 2, 0, -10582.4, -1205.13, 27.8314, 3.41013, 0, 0, -0.990999, 0.133867, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99278, 182090, 0, 10, 42, 1, 2, 0, -10580.3, -1199.63, 34.3414, 3.06848, 0, 0, -0.999332, -0.0365463, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99279, 183987, 0, 10, 42, 1, 2, 0, -10579.8, -1192.62, 34.3414, 3.06848, 0, 0, -0.999332, -0.0365463, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99280, 182090, 0, 10, 42, 1, 2, 0, -10580.6, -1161.37, 28.3222, 2.71113, 0, 0, -0.976927, -0.213575, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99281, 182090, 0, 10, 42, 1, 2, 0, -10586.3, -1170.55, 31.35, 2.44802, 0, 0, -0.94047, -0.339878, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99282, 182090, 0, 10, 42, 1, 2, 0, -10587.8, -1146.6, 29.086, 3.64182, 0, 0, -0.968884, 0.247516, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99283, 182090, 0, 10, 42, 1, 2, 0, -10603.4, -1190.91, 27.4704, 4.62356, 0, 0, -0.737803, 0.675016, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99284, 182090, 0, 10, 42, 1, 2, 0, -10591, -1189.35, 30.7609, 4.40365, 0, 0, -0.807421, 0.589976, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99285, 182090, 0, 10, 42, 1, 2, 0, -10572.1, -1134.95, 27.9579, 1.78513, 0, 0, -0.778685, -0.627415, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99286, 182090, 0, 10, 42, 1, 2, 0, -10524.9, -1203.88, 27.5918, 5.08774, 0, 0, -0.562763, 0.826619, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99287, 183987, 0, 10, 42, 1, 2, 0, -10529.3, -1203.04, 34.0747, 4.53403, 0, 0, -0.767272, 0.641322, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99288, 183987, 0, 10, 42, 1, 2, 0, -10535.9, -1202.71, 33.7218, 4.6165, 0, 0, -0.740182, 0.672407, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99289, 182090, 0, 10, 42, 1, 2, 0, -10535.9, -1204.26, 27.2317, 5.21734, 0, 0, -0.508055, 0.861325, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99290, 182090, 0, 10, 42, 1, 2, 0, -10590.6, -1194.73, 40.0958, 3.45805, 0, 0, -0.987508, 0.157568, 300, 0, 1);
INSERT INTO `gameobject` VALUES (99291, 182090, 0, 10, 42, 1, 2, 0, -10587.1, -1159.74, 43.4883, 3.13211, 0, 0, -0.999989, -0.0047428, 300, 0, 1);
DELETE FROM `vehicle_template_accessory` WHERE `entry` = '43915';
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `minion`, `description`) VALUES
(43862, 43915, 1, 'Stitches -> Abercrombie');
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = '43862';
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`) VALUES
(43862, 46598, 0);