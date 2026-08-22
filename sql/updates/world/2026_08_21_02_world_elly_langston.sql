UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 1328;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 1328 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1328*100, 1328*100+01, 1328*100+02, 1328*100+03, 1328*100+04, 1328*100+05, 1328*100+06) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1328,0,0,0,25,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Reset - Set Event Phase 1"),
(1328,0,1,0,22,0,100,0,5,5000,5000,0,80,1328*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Received Emote Applaud - Start Script"),
(1328,0,2,0,22,0,100,0,17,5000,5000,0,80,1328*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Received Emote Bow - Start Script"),
(1328,0,3,0,22,0,100,0,34,12000,12000,0,80,1328*100+01,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Received Emote Dance - Start Script"),
(1328,0,4,0,22,0,100,0,41,5000,5000,0,80,1328*100+02,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Received Emote Flex - Start Script"),
(1328,0,5,0,22,0,100,0,58,5000,5000,0,80,1328*100+03,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Received Emote Kiss - Start Script"),
(1328,0,6,0,22,0,100,0,77,5000,5000,0,80,1328*100+04,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Received Emote Rude - Start Script"),
(1328,0,7,0,22,0,100,0,84,5000,5000,0,80,1328*100+05,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Received Emote Shy - Start Script"),
(1328,0,8,0,22,0,100,0,101,8000,8000,0,80,1328*100+06,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Received Emote Wave - Start Script"),
(1328*100,9,0,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 2"),
(1328*100,9,1,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted On"),
(1328*100,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Orientation"),
(1328*100,9,3,0,0,0,100,0,1000,1000,0,0,5,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Play Emote (2)"),
(1328*100,9,4,0,0,0,100,0,3000,3000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 1"),
(1328*100,9,5,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted Off"),
(1328*100+01,9,0,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 2"),
(1328*100+01,9,1,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted On"),
(1328*100+01,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Orientation"),
(1328*100+01,9,3,0,0,0,100,0,1000,1000,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Emote State (10)"),
(1328*100+01,9,4,0,0,0,100,0,10000,10000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Emote State (0)"),
(1328*100+01,9,5,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 1"),
(1328*100+01,9,6,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted Off"),
(1328*100+02,9,0,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 2"),
(1328*100+02,9,1,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted On"),
(1328*100+02,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Orientation"),
(1328*100+02,9,3,0,0,0,100,0,1000,1000,0,0,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Play Emote (11)"),
(1328*100+02,9,4,0,0,0,100,0,3000,3000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 1"),
(1328*100+02,9,5,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted Off"),
(1328*100+03,9,0,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 2"),
(1328*100+03,9,1,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted On"),
(1328*100+03,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Orientation"),
(1328*100+03,9,3,0,0,0,100,0,1000,1000,0,0,5,24,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Play Emote (24)"),
(1328*100+03,9,4,0,0,0,100,0,3000,3000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 1"),
(1328*100+03,9,5,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted Off"),
(1328*100+04,9,0,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 2"),
(1328*100+04,9,1,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted On"),
(1328*100+04,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Orientation"),
(1328*100+04,9,3,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Elly Langston - On Script - Say Text Line 0"),
(1328*100+04,9,4,0,0,0,100,0,3000,3000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 1"),
(1328*100+04,9,5,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted Off"),
(1328*100+05,9,0,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 2"),
(1328*100+05,9,1,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted On"),
(1328*100+05,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Orientation"),
(1328*100+05,9,3,0,0,0,100,0,1000,1000,0,0,5,17,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Play Emote (17)"),
(1328*100+05,9,4,0,0,0,100,0,3000,3000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 1"),
(1328*100+05,9,5,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted Off"),
(1328*100+06,9,0,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 2"),
(1328*100+06,9,1,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted On"),
(1328*100+06,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Orientation"),
(1328*100+06,9,3,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Elly Langston - On Script - Say Text Line 1"),
(1328*100+06,9,4,0,0,0,100,0,6000,6000,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Event Phase 1"),
(1328*100+06,9,5,0,0,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elly Langston - On Script - Set Rooted Off");

DELETE FROM `creature_text` WHERE `entry` = 1328;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `text_range`, `comment`) VALUES
(1328,0,0,"","%s returns the rude gesture to $n.",16,0,100,14,0,0,0,"Elly Langston"),
(1328,1,0,"","What can I do for you?",12,0,100,1,0,0,0,"Elly Langston"),
(1328,1,1,"","What do you fancy, $g sir:miss,",12,0,100,1,0,0,0,"Elly Langston"),
(1328,1,2,"","Been a tough day? A nice ale should loosen those worries right up.",12,0,100,1,0,0,0,"Elly Langston"),
(1328,1,3,"","Well hello, $n, what can I get you today?",12,0,100,1,0,0,0,"Elly Langston"),
(1328,1,4,"","Hi, What would you like?",12,0,100,1,0,0,0,"Elly Langston"),
(1328,1,5,"","Good day, $c. What would you like?",12,0,100,1,0,0,0,"Elly Langston"),
(1328,1,6,"","Look what the cat dragged in. What can I get you, $n?",12,0,100,1,0,0,0,"Elly Langston"),
(1328,1,7,"","Do you think I need more pieces of flair?",12,0,100,1,0,0,0,"Elly Langston");

DELETE FROM `creature_text_locale` WHERE `CreatureID` = 1328 AND `Locale` = "ruRU";
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`, `TextFemale`) VALUES
(1328,0,0,"ruRU","","%s отвечает грубым жестом |3-2($n)."),
(1328,1,0,"ruRU","","Чем я могу тебе помочь?"),
(1328,1,1,"ruRU","","Что вас интересует, $gсэр:леди;?"),
(1328,1,2,"ruRU","","Привет, $n! Что тебе подать сегодня?"),
(1328,1,3,"ruRU","","Был тяжелый денек? Хороший эль разгонит все печали."),
(1328,1,4,"ruRU","","Привет, чего ищем?"),
(1328,1,5,"ruRU","","Добрый день, |3-6($c). Чего желаете?"),
(1328,1,6,"ruRU","","Да уж, чего только народ на себя не понацепит! Гм, чем могу помочь, $n?"),
(1328,1,7,"ruRU","","Думаете, мне стоит обзавестись еще несколькими работами Флер?");

UPDATE `creature_equip_template` SET `itemEntry2` = 2703 WHERE `entry` = 1328;

UPDATE `creature` SET `position_x` = -8622.055664, `position_y` = 404.047546, `position_z` = 102.925217, `orientation` = 2.223843 WHERE `guid` = 188747;

UPDATE `creature_addon` SET `path_id` = 188747*10, `bytes2` = 4097 WHERE `guid` = 188747;

DELETE FROM `waypoint_data` WHERE `id` IN (188747, 188747*10);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`) VALUES 
(188747*10, 1, -8622.97, 405.248, 102.925, 0, 0, 0),
(188747*10, 2, -8624.91, 407.725, 102.925, 0, 0, 0),
(188747*10, 3, -8627.22, 409.018, 102.925, 0, 0, 0),
(188747*10, 4, -8628.64, 408.493, 102.925, 0, 0, 0),
(188747*10, 5, -8629.96, 405.923, 102.925, 0, 0, 0),
(188747*10, 6, -8627.42, 402.783, 104.166, 0, 0, 0),
(188747*10, 7, -8623.61, 397.758, 107.026, 0, 0, 0),
(188747*10, 8, -8620.04, 393.178, 109.66, 0, 0, 0),
(188747*10, 9, -8618.33, 391.007, 110.173, 0, 0, 0),
(188747*10, 10, -8615.74, 390.473, 110.173, 0, 0, 0),
(188747*10, 11, -8611.37, 394.091, 110.173, 0, 0, 0),
(188747*10, 12, -8606.08, 398.157, 110.173, 0, 0, 0),
(188747*10, 13, -8602.42, 401.056, 110.173, 0, 0, 0),
(188747*10, 14, -8602.08, 404.607, 110.173, 0, 0, 0),
(188747*10, 15, -8604.64, 407.55, 108.909, 0, 0, 0),
(188747*10, 16, -8607.51, 411.058, 106.851, 0, 0, 0),
(188747*10, 17, -8611.7, 416.105, 103.879, 0, 0, 0),
(188747*10, 18, -8613.99, 418.439, 102.923, 0, 0, 0),
(188747*10, 19, -8616, 418.181, 102.923, 0, 0, 0),
(188747*10, 20, -8617.4, 414.947, 102.923, 0, 0, 0),
(188747*10, 21, -8613.99, 410.566, 102.923, 0, 0, 0),
(188747*10, 22, -8611.42, 406.53, 102.924, 0, 0, 0),
(188747*10, 23, -8612.95, 402.933, 102.925, 0, 0, 0),
(188747*10, 24, -8616.09, 400.423, 102.926, 0, 0, 0),
(188747*10, 25, -8619.58, 400.999, 102.926, 0, 0, 0),
(188747*10, 26, -8620.72, 402.516, 102.926, 0, 0, 0);