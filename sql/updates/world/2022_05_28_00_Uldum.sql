-- Colossus of the Moon
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `id` = 2 AND `entryorguid` = 46042;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(46042,0,2,0,9,0,100,0,0,8,15000,17000,11,85840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Colossus of the Moon - On Close - Cast 'Thunderclap'");

-- Captain Kronkh
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47978;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47978;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47978,0,0,0,9,0,100,0,0,8,120000,120000,11,80983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kronkh - On Close - Cast 'Commanding Shout'");

-- Amethyst Scarab
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 46129;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 46129;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(46129,0,0,0,0,0,100,0,4000,9000,10000,13600,11,87395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amethyst Scarab - In Combat - Cast 'Serrated Slash'");

-- Crazed Digger
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 46590;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 46590;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(46590,0,0,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Digger - At 15% HP - Flee"),
(46590,0,1,0,2,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Digger - At 15% HP - Say Text Line 0");
DELETE FROM `creature_text` WHERE `entry` = 46590;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(46590,0,0,"%s attempts to run away in fear","",0,16,0,100,0,0,0,"Crazed Digger");

-- Diseased Vulture
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47202;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47202;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47202,0,0,0,0,0,100,0,3000,4000,13000,16000,11,81236,0,0,0,0,0,2,32,0,0,0,0,0,0,"Diseased Vulture - In Combat - Cast 'Diseased Spit'");

-- Dreadstalker
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47749;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47749;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47749,0,0,0,0,0,100,0,5000,5000,13300,17500,11,88876,0,0,0,0,0,2,32,0,0,0,0,0,0,"Dreadstalker - In Combat - Cast 'Paralytic Venom'");

-- Dark Pharaoh Tekahn
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47753;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47753;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47753,0,0,0,0,0,100,0,0,0,3400,4700,11,88886,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Pharaoh Tekahn - In Combat - Cast 'Shadow Bolt'"),
(47753,0,1,0,0,0,100,0,5000,5000,11000,13000,11,88883,0,0,0,0,0,5,1,0,0,0,0,0,0,"Dark Pharaoh Tekahn - In Combat - Cast 'Pact of Darkness'"),
(47753,0,2,0,9,0,100,0,5,25,15800,18300,11,88887,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Pharaoh Tekahn - On Close - Cast 'Dark Rune'");

-- Dark Ritualist Zakahn
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 49148;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 49148;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(49148,0,0,0,9,0,100,0,0,8,12400,13500,11,9081,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ritualist Zakahn - On Close - Cast 'Shadow Bolt Volley'"),
(49148,0,1,0,4,0,100,1,0,0,0,0,11,91614,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ritualist Zakahn - On Aggro - Cast 'Zakahn's Serpents'"),
(49148,0,2,0,1,0,100,1,1000,1000,1000,1000,11,68797,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ritualist Zakahn - OOC - Cast 'Soulguard Channel'");

-- Decrepit Watcher
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47385;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47385;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47385,0,0,0,0,0,100,0,8000,8000,16000,19000,11,87753,0,0,0,0,0,1,0,0,0,0,0,0,0,"Decrepit Watcher - In Combat - Cast 'Blazing Eruption'");

-- Emerald Scarab
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 46128;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 46128;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(46128,0,0,0,0,0,100,0,4000,9000,10000,13600,11,87395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emerald Scarab - In Combat - Cast 'Serrated Slash'"),
(46128,0,1,0,9,0,100,0,0,8,14500,15500,11,87393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emerald Scarab - On Close - Cast 'Corrosive Spray'");

-- Eternal Protector
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47227;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47227;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47227,0,0,0,0,0,100,0,3000,3000,17800,21300,11,14868,0,0,0,0,0,5,0,0,0,0,0,0,0,"Eternal Protector - In Combat - Cast 'Curse of Agony'"),
(47227,0,1,0,9,0,100,0,0,5,8000,11000,11,85424,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eternal Protector - On Close - Cast 'Spirit Burst'");

-- Cyrus the Black
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 50064;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 50064;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(50064,0,0,0,0,0,100,0,3000,4000,13600,15800,11,93589,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cyrus the Black - In Combat - Cast 'Disease Breath'"),
(50064,0,1,0,0,0,100,0,9000,9000,17800,21300,11,93587,0,0,0,0,0,2,1,0,0,0,0,0,0,"Cyrus the Black - In Combat - Cast 'Ritual of Bloodletting'"),
(50064,0,2,0,2,0,100,1,0,50,0,0,11,93585,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cyrus the Black - At 50% HP - Cast 'Serum of Torment'");

-- Crown Technician
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 51613;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 51613;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(51613,0,0,0,0,0,100,0,0,0,3500,4100,11,70074,64,0,0,0,0,2,0,0,0,0,0,0,0,"Crown Technician - In Combat - Cast 'Shoot'"),
(51613,0,1,0,9,0,100,0,0,5,8000,10000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crown Technician - On Close - Cast 'Kick'");

-- Captain Margun
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47981;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47981;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47981,0,0,0,0,0,100,0,5000,5000,14500,15300,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Margun - In Combat - Cast 'Backhand'"),
(47981,0,1,0,9,0,100,0,0,10,12000,12300,11,84309,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Margun - On Close - Cast 'Coin Toss'");

-- Cursed Engineer
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 46617;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 46617;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(46617,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Engineer - On Aggro - Say Text Line 0");
DELETE FROM `creature_text` WHERE `entry` = 46617;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(46617,0,0,"Hubba-hubba!","",0,12,0,50,0,0,0,"Cursed Engineer"),
(46617,0,1,"You could bounce a washer off those legs!","",0,12,0,50,0,0,0,"Cursed Engineer"),
(46617,0,2,"Weaponized sharks? Why didn't I think of that!","",0,12,0,50,0,0,0,"Cursed Engineer"),
(46617,0,3,"ROCK ON!","",0,12,0,50,0,0,0,"Cursed Engineer"),
(46617,0,4,"So... EPIC!","",0,12,0,50,0,0,0,"Cursed Engineer"),
(46617,0,5,"200 horsepower, dual combustion engine with modified flux capacitors! ZOING!","",0,12,0,50,0,0,0,"Cursed Engineer"),
(46617,0,6,"Shake it like a sine wave, baby!","",0,12,0,50,0,0,0,"Cursed Engineer");

-- Mangy Hyena
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 45202;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 45202;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(45202,0,0,0,0,0,100,0,5000,8000,12000,12000,11,85415,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mangy Hyena - In Combat - Cast 'Mangle'");

-- Madexx
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 51402;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 51402;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(51402,0,0,0,13,0,100,0,12000,18000,0,0,11,79840,0,0,0,0,0,6,1,0,0,0,0,0,0,"Madexx - On Target Spellcast - Cast 'Harden'"),
(51402,0,1,0,2,0,100,1,0,30,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - At 30% HP - Cast 'Sand Step'"),
(51402,0,2,0,4,0,100,1,0,0,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - On Aggro - Cast 'Sand Step'"),
(51402,0,3,0,0,0,100,0,5000,5000,14000,16000,11,79607,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - In Combat - Cast 'Venom Splash'");

-- Madexx
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 50154;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 50154;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(50154,0,0,0,13,0,100,0,12000,18000,0,0,11,79840,0,0,0,0,0,6,1,0,0,0,0,0,0,"Madexx - On Target Spellcast - Cast 'Harden'"),
(50154,0,1,0,2,0,100,1,0,30,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - At 30% HP - Cast 'Sand Step'"),
(50154,0,2,0,4,0,100,1,0,0,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - On Aggro - Cast 'Sand Step'"),
(50154,0,3,0,0,0,100,0,5000,5000,14000,16000,11,79607,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - In Combat - Cast 'Venom Splash'");

-- Madexx
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 51403;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 51403;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(51403,0,0,0,13,0,100,0,12000,18000,0,0,11,79840,0,0,0,0,0,6,1,0,0,0,0,0,0,"Madexx - On Target Spellcast - Cast 'Harden'"),
(51403,0,1,0,2,0,100,1,0,30,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - At 30% HP - Cast 'Sand Step'"),
(51403,0,2,0,4,0,100,1,0,0,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - On Aggro - Cast 'Sand Step'"),
(51403,0,3,0,0,0,100,0,5000,5000,14000,16000,11,79607,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - In Combat - Cast 'Venom Splash'");

-- Madexx
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 51404;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 51404;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(51404,0,0,0,13,0,100,0,12000,18000,0,0,11,79840,0,0,0,0,0,6,1,0,0,0,0,0,0,"Madexx - On Target Spellcast - Cast 'Harden'"),
(51404,0,1,0,2,0,100,1,0,30,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - At 30% HP - Cast 'Sand Step'"),
(51404,0,2,0,4,0,100,1,0,0,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - On Aggro - Cast 'Sand Step'"),
(51404,0,3,0,0,0,100,0,5000,5000,14000,16000,11,79607,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - In Combat - Cast 'Venom Splash'");

-- Madexx
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 51401;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 51401;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(51401,0,0,0,13,0,100,0,12000,18000,0,0,11,79840,0,0,0,0,0,6,1,0,0,0,0,0,0,"Madexx - On Target Spellcast - Cast 'Harden'"),
(51401,0,1,0,2,0,100,1,0,30,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - At 30% HP - Cast 'Sand Step'"),
(51401,0,2,0,4,0,100,1,0,0,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - On Aggro - Cast 'Sand Step'"),
(51401,0,3,0,0,0,100,0,5000,5000,14000,16000,11,79607,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - In Combat - Cast 'Venom Splash'");

-- Kavem the Callous
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47567;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47567;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47567,0,0,0,9,0,100,0,0,8,120000,120000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kavem the Callous - On Close - Cast 'Battle Shout'"),
(47567,0,1,0,2,0,100,1,0,50,0,0,11,79878,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kavem the Callous - At 50% HP - Cast 'Bloodthirst'"),
(47567,0,2,0,0,0,100,0,3000,3000,11000,13000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kavem the Callous - In Combat - Cast 'Rend'"),
(47567,0,3,0,4,0,100,1,0,0,0,0,11,79883,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kavem the Callous - On Aggro - Cast 'Shattering Throw'"),
(47567,0,4,0,0,0,100,0,8000,8000,17800,19600,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kavem the Callous - In Combat - Cast 'Slam'");

-- Mar'at Guardian
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48874;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48874;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48874,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mar'at Guardian - In Combat - Cast 'Shoot'"),
(48874,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mar'at Guardian - At 15% HP - Flee"),
(48874,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mar'at Guardian - At 15% HP (Link) - Say Text Line 0"),
(48874,0,3,0,0,0,100,0,3400,5500,10800,15400,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mar'at Guardian - In Combat - Cast 'Cleave'");
DELETE FROM `creature_text` WHERE `entry` = 48874;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(48874,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Mar'at Guardian");

-- Indentured Protector
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 45949;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 45949;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(45949,0,0,0,0,0,100,0,0,0,2300,3900,11,91856,64,0,0,0,0,2,0,0,0,0,0,0,0,"Indentured Protector - In Combat - Cast 'Throw'"),
(45949,0,1,0,0,0,100,0,5000,5000,13500,14200,11,86085,0,0,0,0,0,2,0,0,0,0,0,0,0,"Indentured Protector - In Combat - Cast 'Mutilate'");

-- Immortal Colossus
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48548;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48548;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48548,0,0,0,0,0,100,0,5000,5000,12000,13000,11,90422,0,0,0,0,0,2,0,0,0,0,0,0,0,"Immortal Colossus - In Combat - Cast 'Colossal Cleave'");

-- High Priest Sekhemet
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47730;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47730;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47730,0,0,0,0,0,100,0,0,0,3400,4700,11,79932,64,0,0,0,0,2,0,0,0,0,0,0,0,"High Priest Sekhemet - In Combat - Cast 'Shadow Bolt'"),
(47730,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Priest Sekhemet - At 15% HP - Flee"),
(47730,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Priest Sekhemet - At 15% HP (Link) - Say Text Line 0"),
(47730,0,3,0,0,0,100,0,8200,8500,18500,22300,11,86845,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Priest Sekhemet - In Combat - Cast 'Shadow Eruption'");
DELETE FROM `creature_text` WHERE `entry` = 47730;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(47730,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"High Priest Sekhemet");

-- General Ammantep
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 45772;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 45772;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(45772,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"General Ammantep - In Combat - Cast 'Shoot'"),
(45772,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Ammantep - At 15% HP - Flee"),
(45772,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Ammantep - At 15% HP (Link) - Say Text Line 0");
DELETE FROM `creature_text` WHERE `entry` = 45772;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(45772,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"General Ammantep");

-- Furious Specter
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47220;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47220;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47220,0,0,0,0,0,100,0,5000,5000,17200,18900,11,69633,0,0,0,0,0,5,0,0,0,0,0,0,0,"Furious Specter - In Combat - Cast 'Veil of Shadow'"),
(47220,0,1,0,0,0,100,0,8000,11000,9000,14000,11,92919,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furious Specter - In Combat - Cast 'Wail of Souls'");

-- Obsidian Colossus
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 46646;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 46646;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(46646,0,0,0,0,0,100,0,8000,8000,17900,18500,11,87988,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Colossus - In Combat - Cast 'Force Punch'"),
(46646,0,1,0,9,0,100,0,8,20,15800,18300,11,87990,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Colossus - On Close - Cast 'Shadow Storm'"),
(46646,0,2,0,0,0,100,0,3000,3000,12000,13000,11,87680,0,0,0,0,0,2,0,0,0,0,0,0,0,"Obsidian Colossus - In Combat - Cast 'Sweeping Attack'");

-- Neferset Blade Twister
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47727;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47727;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47727,0,0,0,0,0,100,0,5000,5000,12000,13400,11,88844,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Blade Twister - In Combat - Cast 'Cauterizing Strike'");

-- Neferset Armorer
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47722;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47722;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47722,0,0,0,0,0,100,0,4500,4500,15800,18900,11,86070,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Armorer - In Combat - Cast 'Pierce Armor'"),
(47722,0,1,0,0,0,100,0,3000,3000,21200,22000,11,21118,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Armorer - In Combat - Cast 'Spell Reflection'");

-- Neferset Ritualist
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47762;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47762;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47762,0,0,0,0,0,100,0,0,0,3400,4700,11,88886,64,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Ritualist - In Combat - Cast 'Shadow Bolt'"),
(47762,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Ritualist - At 15% HP - Flee"),
(47762,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Ritualist - At 15% HP (Link) - Say Text Line 0"),
(47762,0,3,0,0,0,100,0,2000,3000,22000,25000,11,69391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Ritualist - In Combat - Cast 'Dark Blessing'"),
(47762,0,4,0,9,0,100,0,0,20,15800,19900,11,88902,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Ritualist - On Close - Cast 'Meteor'");
DELETE FROM `creature_text` WHERE `entry` = 47762;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(47762,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Neferset Ritualist");

-- Neferset Savage
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47729;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47729;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47729,0,0,0,0,0,100,0,5000,5000,14800,15600,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Savage - In Combat - Cast 'Mortal Strike'"),
(47729,0,1,0,0,0,100,0,9000,9200,22400,22700,11,88846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Savage - In Combat - Cast 'Shockwave'");

-- Neferset Raider
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48626;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48626;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48626,0,0,0,0,0,100,0,5000,5000,11000,12300,11,13608,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Raider - In Combat - Cast 'Hooked Net'");

-- Neferset Scryer
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48625;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48625;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48625,0,0,0,0,0,100,0,0,0,3400,4700,11,88886,64,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Scryer - In Combat - Cast 'Shadow Bolt'"),
(48625,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Scryer - At 15% HP - Flee"),
(48625,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Scryer - At 15% HP (Link) - Say Text Line 0"),
(48625,0,3,0,0,0,100,0,3000,3000,18500,19100,11,90607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Scryer - In Combat - Cast 'Curse of Impotence'"),
(48625,0,4,0,0,0,100,0,1000,1000,34500,35600,11,31976,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Scryer - In Combat - Cast 'Shadow Shield'");
DELETE FROM `creature_text` WHERE `entry` = 48625;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(48625,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Neferset Scryer");

-- Prince Nadun
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 45799;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 45799;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(45799,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Nadun - In Combat - Cast 'Shoot'");

-- Rabid Hyena
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 51671;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 51671;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(51671,0,0,0,0,0,100,0,4500,4500,11000,12500,11,85415,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rabid Hyena - In Combat - Cast 'Mangle'");

-- Ramkahen Field Worker
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47699;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47699;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47699,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Field Worker - In Combat - Cast 'Shoot'"),
(47699,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Field Worker - At 15% HP - Flee"),
(47699,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Field Worker - At 15% HP (Link) - Say Text Line 0");
DELETE FROM `creature_text` WHERE `entry` = 47699;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(47699,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Ramkahen Field Worker");

-- Pyramid Watcher
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47810;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47810;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47810,0,0,0,0,0,100,0,8000,8000,16000,19000,11,87753,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pyramid Watcher - In Combat - Cast 'Blazing Eruption'");

-- Ramkahen Ranger
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 49255;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 49255;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(49255,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Ranger - In Combat - Cast 'Shoot'"),
(49255,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Ranger - At 15% HP - Flee"),
(49255,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Ranger - At 15% HP (Link) - Say Text Line 0");
DELETE FROM `creature_text` WHERE `entry` = 49255;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(49255,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Ramkahen Ranger");

-- Ramkahen Ranger Captain
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 49253;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 49253;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(49253,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Ranger Captain - In Combat - Cast 'Shoot'"),
(49253,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Ranger Captain - At 15% HP - Flee"),
(49253,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Ranger Captain - At 15% HP (Link) - Say Text Line 0");
DELETE FROM `creature_text` WHERE `entry` = 49253;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(49253,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Ramkahen Ranger Captain");

-- Ramkahen Marksman
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48514;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48514;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48514,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Marksman - In Combat - Cast 'Shoot'"),
(48514,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Marksman - At 15% HP - Flee"),
(48514,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Marksman - At 15% HP (Link) - Say Text Line 0");
DELETE FROM `creature_text` WHERE `entry` = 48514;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(48514,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Ramkahen Marksman");

-- Ramkahen Guardian
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 51776;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 51776;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(51776,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Guardian - In Combat - Cast 'Shoot'"),
(51776,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Guardian - At 15% HP - Flee"),
(51776,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Guardian - At 15% HP (Link) - Say Text Line 0");
DELETE FROM `creature_text` WHERE `entry` = 51776;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(51776,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Ramkahen Guardian");

-- Neferset Cursebringer
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47760;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47760;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47760,0,0,0,0,0,100,0,5000,5000,17000,19200,11,88901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Cursebringer - In Combat - Cast 'Curse of Blood'"),
(47760,0,1,0,0,0,100,0,3000,9000,11000,14500,11,15968,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Cursebringer - In Combat - Cast 'Lash of Pain'");

-- Neferset Looter
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48627;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48627;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48627,0,0,0,0,0,100,0,3500,5500,12000,13000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Looter - In Combat - Cast 'Exploit Weakness'"),
(48627,0,1,0,0,0,100,0,9000,9000,21000,22000,11,36250,0,0,0,0,0,2,1,0,0,0,0,0,0,"Neferset Looter - In Combat - Cast 'Steal Armor'");

-- Neferset Snake Charmer
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47738;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47738;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47738,0,0,0,0,0,100,0,4000,5000,11900,13500,11,88863,0,0,0,0,0,2,32,0,0,0,0,0,0,"Neferset Snake Charmer - In Combat - Cast 'Instant Poison'"),
(47738,0,1,0,0,0,100,0,9000,9000,25000,25000,11,88862,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Snake Charmer - In Combat - Cast 'Viper's Call'");

-- Neferset Venom Keeper
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47741;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47741;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47741,0,0,0,0,0,100,0,5000,5000,17000,18000,11,85713,0,0,0,0,0,2,32,0,0,0,0,0,0,"Neferset Venom Keeper - In Combat - Cast 'Intoxicating Venom'"),
(47741,0,1,0,0,0,100,0,9000,9000,12000,13000,11,88867,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Venom Keeper - In Combat - Cast 'Anesthetics'");

-- Oathsworn Skinner
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 51759;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 51759;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(51759,0,0,0,0,0,100,0,8000,8000,16000,16000,11,96098,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oathsworn Skinner - In Combat - Cast 'Fan of Knives'"),
(51759,0,1,0,0,0,100,0,3000,3000,11000,11500,11,84031,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oathsworn Skinner - In Combat - Cast 'Spinal Pierce'");

-- Pygmy Scout
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48041;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48041;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48041,0,0,0,0,0,100,0,0,0,2300,3900,11,79444,64,0,0,0,0,2,0,0,0,0,0,0,0,"Pygmy Scout - In Combat - Cast 'Throw'"),
(48041,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pygmy Scout - At 15% HP - Flee"),
(48041,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pygmy Scout - At 15% HP (Link) - Say Text Line 0"),
(48041,0,3,0,9,0,100,0,0,8,15000,15000,11,73864,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pygmy Scout - On Close - Cast 'Sand Trap'");
DELETE FROM `creature_text` WHERE `entry` = 48041;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(48041,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Pygmy Scout");

-- Pygmy Oaf
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48040;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48040;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48040,0,0,0,9,0,100,0,0,8,15000,18000,11,86695,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pygmy Oaf - On Close - Cast 'Whirlwind'"),
(48040,0,1,0,0,0,100,0,5000,5000,12500,13600,11,86699,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pygmy Oaf - In Combat - Cast 'Shockwave'");

-- Pygmy Thief
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48043;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48043;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48043,0,0,0,0,0,100,0,0,0,2300,3900,11,87341,64,0,0,0,0,2,0,0,0,0,0,0,0,"Pygmy Thief - In Combat - Cast 'Shoot'"),
(48043,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pygmy Thief - At 15% HP - Flee"),
(48043,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pygmy Thief - At 15% HP (Link) - Say Text Line 0");
DELETE FROM `creature_text` WHERE `entry` = 48043;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(48043,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Pygmy Thief");

-- Ramkahen Guardian
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48883;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48883;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48883,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Guardian - In Combat - Cast 'Shoot'"),
(48883,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Guardian - At 15% HP - Flee"),
(48883,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Guardian - At 15% HP (Link) - Say Text Line 0"),
(48883,0,3,0,9,0,100,0,0,20,15000,16000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Guardian - On Close - Cast 'Net'");
DELETE FROM `creature_text` WHERE `entry` = 48883;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(48883,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Ramkahen Guardian");

-- Ramkahen Guardian
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 51776;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 51776;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(51776,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Guardian - In Combat - Cast 'Shoot'"),
(51776,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Guardian - At 15% HP - Flee"),
(51776,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Guardian - At 15% HP (Link) - Say Text Line 0"),
(51776,0,3,0,9,0,100,0,0,8,8000,12000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Guardian - On Close - Cast 'Cleave'");
DELETE FROM `creature_text` WHERE `entry` = 51776;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(51776,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Ramkahen Guardian");

-- Myzerian
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48444;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48444;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48444,0,0,0,0,0,100,0,6000,8000,12000,14000,11,90075,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Black Cleave'"),
(48444,0,1,0,0,0,100,0,4000,4000,15000,17500,11,90076,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Fire Spit'"),
(48444,0,2,0,0,0,100,0,12000,12000,25000,27000,11,90078,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Rupture Line'"),
(48444,0,3,0,0,0,100,0,5000,14000,17500,21500,11,90074,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Tail Sweep'");

-- Myzerian
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48428;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48428;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48428,0,0,0,0,0,100,0,6000,8000,12000,14000,11,90075,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Black Cleave'"),
(48428,0,1,0,0,0,100,0,4000,4000,15000,17500,11,90076,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Fire Spit'"),
(48428,0,2,0,0,0,100,0,12000,12000,25000,27000,11,90078,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Rupture Line'"),
(48428,0,3,0,0,0,100,0,5000,14000,17500,21500,11,90074,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Tail Sweep'");

-- Schnottz Sea Trooper
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47982;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47982;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47982,0,0,0,0,0,100,0,3000,3000,11000,12000,11,38029,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Sea Trooper - In Combat - Cast 'Stab'"),
(47982,0,1,0,0,0,100,0,5000,5000,7000,15000,11,13608,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Sea Trooper - In Combat - Cast 'Hooked Net'");

-- Schnottz Overseer
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48205;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48205;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48205,0,0,0,0,0,100,0,5000,5000,12000,13500,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Overseer - In Combat - Cast 'Slam'"),
(48205,0,1,0,0,0,100,0,3000,8000,16800,19900,11,32191,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Overseer - In Combat - Cast 'Heavy Dynamite'");

-- Schnottz Excavator
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48204;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48204;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48204,0,0,0,13,0,100,0,12000,18000,0,0,11,11978,0,0,0,0,0,6,1,0,0,0,0,0,0,"Schnottz Excavator - On Target Spellcast - Cast 'Kick'"),
(48204,0,1,0,9,0,100,0,0,8,15800,16400,11,7978,0,0,0,0,0,5,0,0,0,0,0,0,0,"Schnottz Excavator - On Close - Cast 'Throw Dynamite'");

-- Schnottz Overseer
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 51753;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 51753;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(51753,0,0,0,0,0,100,0,5000,5000,12000,13500,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Overseer - In Combat - Cast 'Slam'"),
(51753,0,1,0,0,0,100,0,3000,8000,16800,19900,11,32191,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Overseer - In Combat - Cast 'Heavy Dynamite'");

-- Schnottz Rifleman
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47067;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47067;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47067,0,0,0,0,0,100,0,0,0,2300,3900,11,84837,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Rifleman - In Combat - Cast 'Shoot'"),
(47067,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Rifleman - At 15% HP - Flee"),
(47067,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Rifleman - At 15% HP (Link) - Say Text Line 0"),
(47067,0,3,0,0,0,100,0,8000,8000,14500,16800,11,8858,0,0,0,0,0,5,0,0,0,0,0,0,0,"Schnottz Rifleman - In Combat - Cast 'Bomb'"),
(47067,0,4,0,0,0,100,0,11000,11000,19000,19000,11,31358,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Rifleman - In Combat - Cast 'Fear'");
DELETE FROM `creature_text` WHERE `entry` = 47067;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(47067,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Schnottz Rifleman");

-- Schnottz Elite Trooper
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48443;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48443;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48443,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Elite Trooper - In Combat - Cast 'Shoot'"),
(48443,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Elite Trooper - At 15% HP - Flee"),
(48443,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Elite Trooper - At 15% HP (Link) - Say Text Line 0"),
(48443,0,3,0,0,0,100,0,8000,8000,14500,16800,11,93449,0,0,0,0,0,5,0,0,0,0,0,0,0,"Schnottz Elite Trooper - In Combat - Cast 'Bomb'");
DELETE FROM `creature_text` WHERE `entry` = 48443;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(48443,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Schnottz Elite Trooper");

-- Schnottz Elite Infantryman
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48631;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48631;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48631,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Elite Infantryman - In Combat - Cast 'Shoot'"),
(48631,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Elite Infantryman - At 15% HP - Flee"),
(48631,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Elite Infantryman - At 15% HP (Link) - Say Text Line 0"),
(48631,0,3,0,0,0,100,0,8000,8000,14500,16800,11,93449,0,0,0,0,0,5,0,0,0,0,0,0,0,"Schnottz Elite Infantryman - In Combat - Cast 'Bomb'");
DELETE FROM `creature_text` WHERE `entry` = 48631;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(48631,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Schnottz Elite Infantryman");

-- Schnottz Air Officer
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 46993;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 46993;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(46993,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Air Officer - In Combat - Cast 'Shoot'"),
(46993,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Air Officer - At 15% HP - Flee"),
(46993,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Air Officer - At 15% HP (Link) - Say Text Line 0"),
(46993,0,3,0,0,0,100,0,8000,8000,14500,16800,11,93449,0,0,0,0,0,5,0,0,0,0,0,0,0,"Schnottz Air Officer - In Combat - Cast 'Bomb'");
DELETE FROM `creature_text` WHERE `entry` = 46993;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(46993,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Schnottz Air Officer");

-- Schnottz Air Trooper
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 46979;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 46979;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(46979,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Air Trooper - In Combat - Cast 'Shoot'"),
(46979,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Air Trooper - At 15% HP - Flee"),
(46979,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Air Trooper - At 15% HP (Link) - Say Text Line 0"),
(46979,0,3,0,0,0,100,0,8000,8000,14500,16800,11,93449,0,0,0,0,0,5,0,0,0,0,0,0,0,"Schnottz Air Trooper - In Combat - Cast 'Bomb'");
DELETE FROM `creature_text` WHERE `entry` = 46979;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(46979,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Schnottz Air Trooper");

-- Schnottz's Landing Laborer
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47974;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47974;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47974,0,0,0,0,0,100,0,0,0,2300,3900,11,89205,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz's Landing Laborer - In Combat - Cast 'Shoot'"),
(47974,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz's Landing Laborer - At 15% HP - Flee"),
(47974,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz's Landing Laborer - At 15% HP (Link) - Say Text Line 0");
DELETE FROM `creature_text` WHERE `entry` = 47974;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(47974,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Schnottz's Landing Laborer");

-- Schnottz's Landing Laborer
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47291;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47291;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47291,0,0,0,9,0,100,0,0,8,120000,120000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz's Landing Laborer - On Close - Cast 'Battle Shout'");

-- Schnottz's Landing Laborer
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47690;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47690;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47690,0,0,0,9,0,100,0,0,8,120000,120000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz's Landing Laborer - On Close - Cast 'Battle Shout'");

-- Warlord Ihsenn
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47755;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47755;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47755,0,0,0,2,0,100,1,0,30,0,0,11,6434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Ihsenn - At 30% HP - Cast 'Slice and Dice'");

-- Vizier Tanotep
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 46136;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 46136;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(46136,0,0,0,0,0,100,0,5000,5000,12000,14000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vizier Tanotep - In Combat - Cast 'Mortal Strike'"),
(46136,0,1,0,0,0,100,0,8000,9000,17800,19600,11,88846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vizier Tanotep - In Combat - Cast 'Shockwave'");

-- Venomscale Spitter
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 51673;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 51673;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(51673,0,0,0,0,0,100,0,5000,5000,13300,17500,11,88876,0,0,0,0,0,2,32,0,0,0,0,0,0,"Venomscale Spitter - In Combat - Cast 'Paralytic Venom'");

-- Turquoise Scarab
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 46126;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 46126;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(46126,0,0,0,0,0,100,0,4000,4000,15600,16400,11,87395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Turquoise Scarab - In Combat - Cast 'Serrated Slash'"),
(46126,0,1,0,0,0,100,0,16800,17900,16800,17900,11,88023,0,0,0,0,0,1,0,0,0,0,0,0,0,"Turquoise Scarab - In Combat - Cast 'Shroud of Gold'"),
(46126,0,2,0,4,0,100,1,0,0,0,0,11,88023,0,0,0,0,0,1,0,0,0,0,0,0,0,"Turquoise Scarab - On Aggro - Cast 'Shroud of Gold'");

-- Tormented Tomb-Robber
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 45765;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 45765;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(45765,0,0,0,2,0,100,1,0,35,0,0,11,87354,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormented Tomb-Robber - At 35% HP - Cast 'Ethereal Form'");

-- Temple Scarab
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47801;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47801;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47801,0,0,0,0,0,100,0,4000,9000,10000,13600,11,87395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Temple Scarab - In Combat - Cast 'Serrated Slash'"),
(47801,0,1,0,9,0,100,0,0,8,14500,15500,11,87393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Temple Scarab - On Close - Cast 'Corrosive Spray'");

-- Sweeping Winds
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 51672;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 51672;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(51672,0,0,0,9,0,100,0,0,8,18500,18900,11,77500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sweeping Winds - On Close - Cast 'Wind Blast'");

-- Skarf
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 45204;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 45204;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(45204,0,0,0,0,0,100,0,5000,5000,12000,13500,11,85835,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skarf - In Combat - Cast 'Maul'"),
(45204,0,1,0,9,0,100,0,5,15,15800,18300,11,44531,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skarf - On Close - Cast 'Dash'");

-- Shaggy Desert Coyote
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47190;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47190;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47190,0,0,0,0,0,100,0,5000,5000,12000,13500,11,85835,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shaggy Desert Coyote - In Combat - Cast 'Maul'"),
(47190,0,1,0,0,0,100,0,9900,9900,16400,17400,11,85691,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shaggy Desert Coyote - In Combat - Cast 'Piercing Howl'");

-- Slacking Laborer
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47292;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47292;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47292,0,0,0,4,0,100,1,0,0,0,0,11,14890,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slacking Laborer - On Aggro - Cast 'Dismounting Blow'");

-- Schnottz Elite Trooper
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 48668;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 48668;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(48668,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Elite Trooper - In Combat - Cast 'Shoot'"),
(48668,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Elite Trooper - At 15% HP - Flee"),
(48668,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Elite Trooper - At 15% HP (Link) - Say Text Line 0"),
(48668,0,3,0,0,0,100,0,5000,5000,12000,13000,11,88844,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Elite Trooper - In Combat - Cast 'Cauterizing Strike'");
DELETE FROM `creature_text` WHERE `entry` = 48668;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(48668,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Schnottz Elite Trooper");

-- Sapphire Scarab
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 46127;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 46127;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(46127,0,0,0,0,0,100,0,3000,9000,7000,13600,11,87395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sapphire Scarab - In Combat - Cast 'Serrated Slash'"),
(46127,0,1,0,0,0,100,0,5000,5000,16800,17900,11,87396,0,0,0,0,0,2,1,0,0,0,0,0,0,"Sapphire Scarab - In Combat - Cast 'Sapphire Gaze'");

-- Sand Serpent
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47283;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47283;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47283,0,0,0,0,0,100,0,5000,5000,12000,13000,11,89905,0,0,0,0,0,2,32,0,0,0,0,0,0,"Sand Serpent - In Combat - Cast 'Venomous Bite'");

-- Sand Scorpid
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47803;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47803;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47803,0,0,0,0,0,100,0,3500,3500,10800,11200,11,31289,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sand Scorpid - In Combat - Cast 'Claw'"),
(47803,0,1,0,0,0,100,0,8000,8000,16800,17300,11,32093,0,0,0,0,0,2,32,0,0,0,0,0,0,"Sand Scorpid - In Combat - Cast 'Poison Spit'");

-- Tiger
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47726;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47726;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47726,0,0,0,0,0,100,0,5000,5000,12000,13500,11,85835,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tiger - In Combat - Cast 'Maul'"),
(47726,0,1,0,9,0,100,0,5,15,15800,18300,11,44531,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tiger - On Close - Cast 'Dash'");

-- Sultan Oogah
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 45205;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 45205;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(45205,0,0,0,0,0,100,0,0,0,2300,3900,11,87341,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sultan Oogah - In Combat - Cast 'Shoot'"),
(45205,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sultan Oogah - At 15% HP - Flee"),
(45205,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sultan Oogah - At 15% HP (Link) - Say Text Line 0"),
(45205,0,3,0,0,0,100,0,8000,8000,22500,23800,11,87322,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sultan Oogah - In Combat - Cast 'Veil of Shimmering Sand'");
DELETE FROM `creature_text` WHERE `entry` = 45205;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`text_range`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(45205,0,0,"%s attempts to run away in fear!","",0,16,0,100,0,0,0,"Sultan Oogah");

-- Sand-Husk Scarab
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 51674;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 51674;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(51674,0,0,0,0,0,100,0,4000,9000,10000,13600,11,87395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sand-Husk Scarab - In Combat - Cast 'Serrated Slash'"),
(51674,0,1,0,9,0,100,0,0,8,14500,15500,11,87393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sand-Husk Scarab - On Close - Cast 'Corrosive Spray'");

-- Scorpion-Lord Namkhare
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47742;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47742;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47742,0,0,0,4,0,100,1,0,0,0,0,11,89424,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scorpion-Lord Namkhare - On Aggro - Cast 'Call Scorpid'"),
(47742,0,1,0,0,0,100,0,5000,5000,12000,13000,11,88863,0,0,0,0,0,2,32,0,0,0,0,0,0,"Scorpion-Lord Namkhare - In Combat - Cast 'Instant Poison'"),
(47742,0,2,0,0,0,100,0,2000,8000,7000,16000,11,38338,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpion-Lord Namkhare - In Combat - Cast 'Net'");

-- Titanic Guardian
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 47032;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = 47032;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(47032,0,0,0,0,0,100,0,8000,8000,16000,19000,11,87753,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanic Guardian - In Combat - Cast 'Blazing Eruption'"),
(47032,0,1,0,0,0,100,0,3000,3000,13000,13000,11,87656,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanic Guardian - In Combat - Cast 'Cast Decrepit Ruin'"),
(47032,0,2,0,0,0,100,0,12000,12000,29000,35000,11,87698,0,0,0,0,0,1,1,0,0,0,0,0,0,"Titanic Guardian - In Combat - Cast 'Cast Summon Meteor'");
