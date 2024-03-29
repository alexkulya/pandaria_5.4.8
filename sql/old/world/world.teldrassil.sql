-- Аура и условие госсип меню на Иверроне

DELETE FROM `creature` WHERE `guid` BETWEEN 10000 AND 10012;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `movement_type`) VALUES
(10000, 63331, 1, 1, 1, 10424.83, 765.6614, 1322.754, 1.998563, 120, 0, 0),
(10001, 12160, 1, 1, 1, 10313.05, 816.032, 1327.698, 3.972167, 120, 10, 1),
(10002, 12160, 1, 1, 1, 10413.19, 731.5011, 1321.063, 5.983846, 120, 10, 1),
(10003, 12160, 1, 1, 1, 10348.853, 751.136, 1325.35, 5.057269, 120, 10, 1),
(10004, 62242, 1, 1, 1, 10626.83, 927.5742, 1327.541, 2.04279, 120, 15, 1),
(10005, 62242, 1, 1, 1, 10625.32, 821.9661, 1316.752, 5.311656, 120, 15, 1),
(10006, 62242, 1, 1, 1, 10575.35, 963.194, 1325.54, 4.892617, 120, 15, 1),
(10007, 62242, 1, 1, 1, 10423.52, 919.1991, 1324.547, 5.583723, 120, 15, 1),
(10008, 62242, 1, 1, 1, 10283.21, 854.236, 1341.771, 4.222265, 120, 15, 1),
(10009, 61757, 1, 1, 1, 10690.396, 669.625, 1335.091, 5.874082, 120, 15, 1),
(10010, 2079, 1, 1, 1, 10312.7, 830.055, 1326.52, 5.41052, 120, 0, 0),
(10012, 2079, 1, 1, 1, 10312.7, 830.122, 1326.53, 2.37365, 120, 0, 0);

UPDATE `creature` SET `position_x` = 10322.9, `position_y` = 820.333, `position_z` = 1326.23, `orientation` = 5.55015 WHERE `guid` = 276859 AND `id` = 2079;
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (302852, 302853);

DELETE FROM `creature` WHERE `guid` = 564233 AND `id` = 63331;
DELETE FROM `creature_addon` WHERE `guid` = 564233;

DELETE FROM `creature_template_addon` WHERE `entry` = 2079;
DELETE FROM `creature_addon` WHERE `guid` IN (276859, 10010, 10012);
INSERT INTO `creature_addon` (`guid`, `bytes2`, `auras`) VALUES
(276859, 1, "60921"), -- Generic Quest Invisibility 3
(10010, 1, "49414"), -- Generic Quest Invisibility 1
(10012, 1, "49415"); -- Generic Quest Invisibility 2

DELETE FROM `spell_area` WHERE `spell` IN (49417, 49416, 60922, 92549, 94566) AND `area` = 188;
DELETE FROM `spell_area` WHERE `spell` = 92237 AND `area` = 257;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(49417, 188, 0, 28713, 0, 0, 2, 1, 0, 41), -- Generic Quest Invisibility Detection 2
(49416, 188, 28713, 28714, 0, 0, 2, 1, 66, 41), -- Generic Quest Invisibility Detection 1
(60922, 188, 28714, 0, 0, 0, 2, 1, 66, 0), -- Generic Quest Invisibility Detection 3
-- (92549, 188, 0, 28727, 0, 0, 2, 1, 0, 43), -- See Quest Invis 4                           (?)
(94566, 188, 28723, 0, 0, 0, 2, 1, 66, 0), -- Generic Quest Invisibility Detection 5
(92237, 257, 28725, 28728, /* -92239*/0, 0, 2, 1, 74, 41); -- Summon Tarindrella Aura           (?)

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (2079, 49478, 34756, 34757, 2077);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2079, 49478, 34756, 34757, 2077) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2079*100, 49478*100, 34757*100) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2079,0,0,0,20,0,100,0,28713,0,0,0,80,2079*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Ilthalaine - On Quest (ID: 28713) Rewarded - Start Script"),
(2079,0,1,0,19,0,100,0,3118,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - On Quest (ID: 3118) Accepted - Say Text Line 1"),
(2079,0,2,0,19,0,100,0,3117,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - On Quest (ID: 3117) Accepted - Say Text Line 1"),
(2079,0,3,0,19,0,100,0,26841,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - On Quest (ID: 26841) Accepted - Say Text Line 1"),
(2079,0,4,0,19,0,100,0,3119,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - On Quest (ID: 3119) Accepted - Say Text Line 1"),
(2079,0,5,0,19,0,100,0,3116,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - On Quest (ID: 3116) Accepted - Say Text Line 1"),
(2079,0,6,0,19,0,100,0,3120,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - On Quest (ID: 3120) Accepted - Say Text Line 1"),

(2079*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - On Script - Say Text Line 0"),
(2079*100,9,1,0,0,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ilthalaine - On Script - Store Target (Invoker)"),
(2079*100,9,2,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,19,49477,10,0,0,0,0,0,"Ilthalaine - On Script - Say Text Line 0 (Creature ID: 49477)"),
(2079*100,9,3,0,0,0,100,0,1000,1000,0,0,100,1,0,0,0,0,0,19,49478,10,0,0,0,0,0,"Ilthalaine - On Script - Send Target (Creature ID: 49478)"),
(2079*100,9,4,0,0,0,100,0,6000,6000,0,0,45,1,1,0,0,0,0,19,49478,10,0,0,0,0,0,"Ilthalaine - On Script - Set Data 1 1 (Creature ID: 49478)"),

(49478,0,0,0,38,0,100,0,1,1,0,0,80,49478*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dentaria Silverglade - On Data Set 1 1 - Start Script"),

(49478*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Dentaria Silverglade - On Script - Say Text Line 0"),
(49478*100,9,1,0,0,0,100,0,6000,6000,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,"Dentaria Silverglade - On Script - Say Text Line 1"),

(34757,0,0,0,10,0,100,0,1,25,25000,25000,80,34757*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doranel Amberleaf - OOC LOS - Start Script"),

(34757*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doranel Amberleaf - On Script - Say Text Line 0"),
(34757*100,9,1,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,19,34756,15,0,0,0,0,0,"Doranel Amberleaf - On Script - Say Text Line 0 (Creature ID: 34756)"),
(34757*100,9,2,0,0,0,100,0,2000,2000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.795327,"Doranel Amberleaf - On Script - Set Orientation (2.795327)"),
(34757*100,9,3,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.3058,"Doranel Amberleaf - On Script - Set Orientation (5.3058)"),

(2077,0,0,0,1,0,70,0,2000,4000,7000,9000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melithar Forteramure - OOC - Play Emote Talk"),
(2077,0,1,0,19,0,100,0,3118,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - On Quest Accept (3118) - Say Text Line 0"),
(2077,0,2,0,19,0,100,0,3117,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - On Quest Accept (3117) - Say Text Line 0"),
(2077,0,3,0,19,0,100,0,26841,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - On Quest Accept (26841) - Say Text Line 0"),
(2077,0,4,0,19,0,100,0,3119,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - On Quest Accept (3119) - Say Text Line 0"),
(2077,0,5,0,19,0,100,0,3116,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - On Quest Accept (3116) - Say Text Line 0"),
(2077,0,6,0,19,0,100,0,3120,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - On Quest Accept (3120) - Say Text Line 0"),
(2077,0,7,0,19,0,100,0,31168,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Melithar Forteramure - On Quest Accept (31168) - Say Text Line 0");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup`= 1 AND `SourceEntry` = 34757;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,1,34757,0,31,0,4,0,0,0,0,"","SAI event require a player");

DELETE FROM `creature_text` WHERE `entry` IN (2079, 49478, 34756, 34757, 2077);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text_female`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(2079,0,0,"I'm sorry, Huntress. None of our new $cs are ready. They still have much to learn.","",12,0,100,1,0,0,"Ilthalaine"),
(2079,1,0,"You'll find the trainer inside of Aldrassil, $n.","",12,0,100,1,0,0,"Ilthalaine"),

(49478,0,0,"","We will leave you to your training, Ilthalaine. This is your area of expertise.",12,0,100,1,0,0,"Dentaria Silverglade"),
(49478,1,0,"","Study well, $n. We may need you fighting by our side before the next moon fills.",12,0,100,1,0,0,"Dentaria Silverglade"),

(34756,0,0,"","Shh! Someone's here.",12,0,100,1,0,0,"Moriana Dawnlight"),

(34757,0,0,"Don't get me wrong... I'm grateful to have Shando Stormrage back, but this is all really suspicious. What happened to Fandral?","",12,0,100,6,0,0,"Doranel Amberleaf"),

(2077,0,0,"You'll find the trainer inside of Aldrassil, $n.","",12,0,100,1,0,0,"Melithar Staghelm");

UPDATE `creature_template` SET `npcflag` = 0, `gossip_menu_id` = 0 WHERE `entry` = 8583;

UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` IN (277063, 276892, 276628, 277061, 276632);
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `id` IN (34756, 34757);

DELETE FROM `creature_addon` WHERE `guid` IN (277063, 276892, 276628, 277061, 276632);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(277063, 277063, 1, "18950"),
(276892, 276892, 1, "18950"),
(276628, 276628, 1, "18950"),
(277061, 277061, 1, "18950"),
(276632, 276632, 1, "18950");

DELETE FROM `waypoint_data` WHERE `id` IN (277063, 276892, 276628, 277061, 276632);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`, `entry`) VALUES
(277063, 1, 10397.1, 883.697, 1321.38, 0, 0, 0, 0, 100, 0, 12160),
(277063, 2, 10365.1, 866.052, 1324.96, 0, 0, 0, 0, 100, 0, 12160),
(277063, 3, 10355.6, 852.585, 1325.15, 0, 0, 0, 0, 100, 0, 12160),
(277063, 4, 10323.4, 827.04, 1326.37, 0, 0, 0, 0, 100, 0, 12160),
(277063, 5, 10368, 747.071, 1321.5, 0, 0, 0, 0, 100, 0, 12160),
(277063, 6, 10323.4, 827.04, 1326.37, 0, 0, 0, 0, 100, 0, 12160),
(277063, 7, 10353.7, 850.765, 1325.19, 0, 0, 0, 0, 100, 0, 12160),
(277063, 8, 10366.6, 867.413, 1324.95, 0, 0, 0, 0, 100, 0, 12160),
(277063, 9, 10383.3, 875.205, 1323.82, 0, 0, 0, 0, 100, 0, 12160),
(277063, 10, 10395.7, 884.819, 1321.46, 0, 0, 0, 0, 100, 0, 12160),
(277063, 11, 10417.3, 886.186, 1318.98, 0, 0, 0, 0, 100, 0, 12160),

(276892, 1, 10502.5, 835.888, 1361.22, 0, 0, 0, 0, 100, 0, 12160),
(276892, 2, 10512.7, 820.212, 1354.79, 0, 0, 0, 0, 100, 0, 12160),
(276892, 3, 10520.4, 825.945, 1354.79, 0, 0, 0, 0, 100, 0, 12160),
(276892, 4, 10510.2, 848.159, 1348.96, 0, 0, 0, 0, 100, 0, 12160),
(276892, 5, 10488.9, 856.99, 1342.79, 0, 0, 0, 0, 100, 0, 12160),
(276892, 6, 10462.4, 858.067, 1339, 0, 0, 0, 0, 100, 0, 12160),
(276892, 7, 10419.6, 885.502, 1319.2, 0, 0, 0, 0, 100, 0, 12160),
(276892, 8, 10460.5, 858.739, 1338.22, 0, 0, 0, 0, 100, 0, 12160),
(276892, 9, 10497.2, 855.959, 1344.87, 0, 0, 0, 0, 100, 0, 12160),
(276892, 10, 10514.3, 843.018, 1350.85, 0, 0, 0, 0, 100, 0, 12160),
(276892, 11, 10521.8, 823.973, 1354.79, 0, 0, 0, 0, 100, 0, 12160),
(276892, 12, 10513.1, 821.36, 1354.79, 0, 0, 0, 0, 100, 0, 12160),
(276892, 13, 10502.5, 835.888, 1361.22, 0, 0, 0, 0, 100, 0, 12160),
(276892, 14, 10492.3, 845.633, 1366.7, 0, 0, 0, 0, 100, 0, 12160),
(276892, 15, 10469.2, 849.412, 1375.61, 0, 0, 0, 0, 100, 0, 12160),
(276892, 16, 10450.9, 843.149, 1380.85, 0, 0, 0, 0, 100, 0, 12160),
(276892, 17, 10483.7, 849.269, 1370.22, 0, 0, 0, 0, 100, 0, 12160),

(276628, 1, 10501.6, 787.122, 1397.8, 0, 0, 0, 0, 100, 0, 12160),
(276628, 2, 10484.2, 786.734, 1395.33, 0, 0, 0, 0, 100, 0, 12160),
(276628, 3, 10461.4, 798.532, 1388.93, 0, 0, 0, 0, 100, 0, 12160),
(276628, 4, 10444.6, 821.521, 1382.36, 0, 0, 0, 0, 100, 0, 12160),
(276628, 5, 10444.9, 834.345, 1380.91, 0, 0, 0, 0, 100, 0, 12160),
(276628, 6, 10449.3, 841.089, 1381.17, 0, 0, 0, 0, 100, 0, 12160),
(276628, 7, 10444.9, 834.345, 1380.91, 0, 0, 0, 0, 100, 0, 12160),
(276628, 8, 10444.6, 821.521, 1382.36, 0, 0, 0, 0, 100, 0, 12160),
(276628, 9, 10461.4, 798.532, 1388.93, 0, 0, 0, 0, 100, 0, 12160),
(276628, 10, 10484.2, 786.734, 1395.33, 0, 0, 0, 0, 100, 0, 12160),
(276628, 11, 10501.6, 787.122, 1397.8, 0, 0, 0, 0, 100, 0, 12160),

(277061, 1, 10484.9, 800.648, 1326.81, 0, 0, 0, 0, 100, 0, 12160),
(277061, 2, 10495.4, 797.863, 1328.54, 0, 0, 0, 0, 100, 0, 12160),
(277061, 3, 10504.5, 796.76, 1330.43, 0, 0, 0, 0, 100, 0, 12160),
(277061, 4, 10522.4, 782.14, 1329.6, 0, 0, 0, 0, 100, 0, 12160),
(277061, 5, 10502.7, 796.839, 1330.35, 0, 0, 0, 0, 100, 0, 12160),
(277061, 6, 10490.3, 799.39, 1326.82, 0, 0, 0, 0, 100, 0, 12160),
(277061, 7, 10484.9, 800.648, 1326.81, 0, 0, 0, 0, 100, 0, 12160),
(277061, 8, 10473.1, 799.122, 1322.74, 0, 0, 0, 0, 100, 0, 12160),
(277061, 9, 10460.3, 799.294, 1322.59, 0, 0, 0, 0, 100, 0, 12160),
(277061, 10, 10402.6, 764.818, 1322.69, 0, 0, 0, 0, 100, 0, 12160),
(277061, 11, 10461.5, 799.607, 1322.67, 0, 0, 0, 0, 100, 0, 12160),
(277061, 12, 10476.7, 799.978, 1324.27, 0, 0, 0, 0, 100, 0, 12160),
(277061, 13, 10484.9, 800.648, 1326.81, 0, 0, 0, 0, 100, 0, 12160),

(276632, 1, 10427.9, 771.281, 1335.5, 0, 0, 0, 0, 100, 0, 12160),
(276632, 2, 10435.2, 776.668, 1337.29, 0, 0, 0, 0, 100, 0, 12160),
(276632, 3, 10428.3, 786.768, 1337.29, 0, 0, 0, 0, 100, 0, 12160),
(276632, 4, 10442.5, 797.24, 1345.63, 0, 0, 0, 0, 100, 0, 12160),
(276632, 5, 10452.2, 797.576, 1345.65, 0, 0, 0, 0, 100, 0, 12160),
(276632, 6, 10442.4, 796.852, 1345.63, 0, 0, 0, 0, 100, 0, 12160),
(276632, 7, 10428.6, 787.004, 1337.29, 0, 0, 0, 0, 100, 0, 12160),
(276632, 8, 10434.9, 776.611, 1337.29, 0, 0, 0, 0, 100, 0, 12160),
(276632, 9, 10421.2, 767.289, 1331.54, 0, 0, 0, 0, 100, 0, 12160),
(276632, 10, 10404.1, 759.106, 1322.68, 0, 0, 0, 0, 100, 0, 12160),
(276632, 11, 10418.7, 765.651, 1329.76, 0, 0, 0, 0, 100, 0, 12160);

UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` IN (48624, 48623, 62242);
UPDATE `creature_template` SET `RegenHealth` = 0 WHERE `entry` = 44617;
UPDATE `creature` SET `curhealth` = 650 WHERE `id` = 44617;

DELETE FROM `creature` WHERE `guid` = 308260 AND `id` = 14432;
DELETE FROM `creature` WHERE `guid` = 302860 AND `id` = 14429;
UPDATE `creature` SET `movement_type` = 1, `wander_distance` = 15 WHERE `id` IN (1984, 2031, 1989, 2032, 1985, 1986, 1988);
UPDATE `creature` SET `movement_type` = 1, `wander_distance` = 7 WHERE `id` IN (2042, 1998, 1995, 2022, 2007, 2006, 2008, 1996, 1999, 2043, 1997, 2000, 2001, 2034, 7235);
UPDATE `creature` SET `movement_type` = 1, `wander_distance` = 5 WHERE guid IN (277643, 278482, 278481, 278478, 278219, 278185, 278183, 278080, 278063, 278046, 278483);
UPDATE `creature` SET `movement_type` = 1, `wander_distance` = 5 WHERE `id` IN (2029, 2030);
UPDATE `creature` SET `movement_type` = 1, `wander_distance` = 3 WHERE `id` IN (2003, 2002, 2004, 2005, 2017, 2015, 2018, 2019, 2020, 2021, 2010, 2011, 2009, 2152);
UPDATE `creature` SET `movement_type` = 1, `wander_distance` = 2 WHERE `id` IN (7319, 2162, 1993);

DELETE FROM `creature_addon` WHERE `guid` IN (277954, 277611, 278587, 278301, 277866, 278300, 278374, 278023, 277994, 277906, 277903, 277828, 277667, 277540,
                                              277995, 278386, 277993, 277830, 277827, 277542, 277537, 277502, 277385, 278388, 277384, 278389, 278379, 278317,
                                              277536, 277997, 277996, 277992, 277539, 277541, 277798, 277668, 277700, 278641, 278635, 278616, 278612, 278611,
                                              278309, 278643, 278583, 278546, 278652, 277943, 277947, 278057, 278520, 278607, 278154, 278527, 278549, 278358,
                                              277711, 278458, 277822, 278505, 277705, 278162, 278210, 278472, 277723, 278676, 278673, 278138, 278787, 278781,
                                              278776, 278743, 278804, 278044, 278745, 278809);
DELETE FROM `waypoint_data` WHERE `id` IN (277954, 277611, 278587, 278301, 277866, 278300, 278374, 278023, 277994, 277906, 277903, 277828, 277667, 277540,
                                           277995, 278386, 277993, 277830, 277827, 277542, 277537, 277502, 277385, 278388, 277384, 278389, 278379, 278317,
                                           277536, 277997, 277996, 277992, 277539, 277541, 277798, 277668, 277700, 278641, 278635, 278616, 278612, 278611,
                                           278309, 278643, 278583, 278546, 278652, 277943, 277947, 278057, 278520, 278607, 278154, 278527, 278549, 278358,
                                           277711, 278458, 277822, 278505, 277705, 278162, 278210, 278472, 277723, 278676, 278673, 278138, 278787, 278781,
                                           278776, 278743, 278804, 278044, 278745, 278809);

UPDATE `creature` SET `position_x` = 10185.9, `position_y` = 2405.57, `position_z` = 1395.25, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 276797;
UPDATE `creature` SET `position_x` = 10006.7, `position_y` = 2410.92, `position_z` = 1361.76, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 276799;
UPDATE `creature` SET `position_x` = 10157.1, `position_y` = 2614.14, `position_z` = 1358.51, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 276801;
UPDATE `creature` SET `position_x` = 10153.2, `position_y` = 2617.7, `position_z` = 1359.43, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 276803;
UPDATE `creature` SET `position_x` = 9729.06, `position_y` = 2581.71, `position_z` = 1375.61, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 276805;
UPDATE `creature` SET `position_x` = 10117.1, `position_y` = 2486.55, `position_z` = 1348.28, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 276807;
UPDATE `creature` SET `position_x` = 10097.5, `position_y` = 2531.02, `position_z` = 1386.95, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 276809;

UPDATE `creature` SET `position_x` = 10185.9, `position_y` = 2405.57, `position_z` = 1395.25, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 276798;
UPDATE `creature` SET `position_x` = 10006.7, `position_y` = 2410.92, `position_z` = 1361.76, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 276800;
UPDATE `creature` SET `position_x` = 10157.1, `position_y` = 2614.14, `position_z` = 1358.51, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 276802;
UPDATE `creature` SET `position_x` = 10153.2, `position_y` = 2617.7, `position_z` = 1359.43, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 276804;
UPDATE `creature` SET `position_x` = 9729.06, `position_y` = 2581.71, `position_z` = 1375.61, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 276806;
UPDATE `creature` SET `position_x` = 10117.1, `position_y` = 2486.55, `position_z` = 1348.28, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 276808;
UPDATE `creature` SET `position_x` = 10097.5, `position_y` = 2531.02, `position_z` = 1386.95, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 276810;

DELETE FROM `creature_addon` WHERE `guid` IN (276797, 276799, 276801, 276803, 276805, 276807, 276809, 276798, 276800, 276802, 276804, 276806, 276808, 276810);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`) VALUES
(276797, 276797, 22470, 50331648, 1),
(276799, 276799, 22470, 50331648, 1),
(276801, 276801, 22470, 50331648, 1),
(276803, 276803, 22470, 50331648, 1),
(276805, 276805, 22470, 50331648, 1),
(276807, 276807, 22470, 50331648, 1),
(276809, 276809, 22470, 50331648, 1);

DELETE FROM `waypoint_data` WHERE `id` IN (276797, 276799, 276801, 276803, 276805, 276807, 276809);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `entry`) VALUES
(276797, 1, 10185.9, 2405.57, 1395.25, 0, 0, 1, 0, 100, 51371),
(276797, 2, 10135.1, 2486.21, 1387.95, 0, 0, 1, 0, 100, 51371),
(276797, 3, 9771.23, 2495.11, 1383.25, 0, 0, 1, 0, 100, 51371),
(276797, 4, 9717.32, 2436.95, 1386.71, 0, 0, 1, 0, 100, 51371),
(276797, 5, 9687.7, 2312.07, 1389.12, 0, 0, 1, 0, 100, 51371),
(276797, 6, 9882.23, 2187.54, 1412.66, 0, 0, 1, 0, 100, 51371),

(276799, 1, 10006.7, 2410.92, 1361.76, 0, 0, 1, 0, 100, 51371),
(276799, 2, 10051.9, 2296.17, 1370.38, 0, 0, 1, 0, 100, 51371),
(276799, 3, 10187.2, 2298.91, 1396.86, 0, 0, 1, 0, 100, 51371),
(276799, 4, 10261.5, 2330.4, 1405.96, 0, 0, 1, 0, 100, 51371),
(276799, 5, 10235, 2383.42, 1393.46, 0, 0, 1, 0, 100, 51371),
(276799, 6, 10184, 2415.55, 1371.17, 0, 0, 1, 0, 100, 51371),

(276801, 1, 10157.1, 2614.14, 1358.51, 0, 0, 1, 0, 100, 51371),
(276801, 2, 10286.9, 2528.8, 1375.04, 0, 0, 1, 0, 100, 51371),
(276801, 3, 10122.5, 2268.79, 1379.15, 0, 0, 1, 0, 100, 51371),
(276801, 4, 9887.86, 2229.97, 1375.38, 0, 0, 1, 0, 100, 51371),
(276801, 5, 9813.08, 2453.12, 1384.1, 0, 0, 1, 0, 100, 51371),
(276801, 6, 10079.2, 2452.31, 1386.35, 0, 0, 1, 0, 100, 51371),
(276801, 7, 10094, 2384.67, 1355.89, 0, 0, 1, 0, 100, 51371),

(276803, 1, 10153.2, 2617.7, 1359.43, 0, 0, 1, 0, 100, 51371),
(276803, 2, 10209.6, 2662.43, 1365.51, 0, 0, 1, 0, 100, 51371),
(276803, 3, 10182.4, 2718.96, 1360.89, 0, 0, 1, 0, 100, 51371),
(276803, 4, 10061.2, 2722.89, 1358.32, 0, 0, 1, 0, 100, 51371),
(276803, 5, 9917.8, 2662.94, 1374.56, 0, 0, 1, 0, 100, 51371),
(276803, 6, 9749.58, 2529.89, 1382.73, 0, 0, 1, 0, 100, 51371),
(276803, 7, 9929.26, 2413.39, 1368.38, 0, 0, 1, 0, 100, 51371),
(276803, 8, 10111.6, 2505.27, 1377.64, 0, 0, 1, 0, 100, 51371),
(276803, 9, 10140.3, 2551.62, 1351.89, 0, 0, 1, 0, 100, 51371),

(276805, 1, 9729.06, 2581.71, 1375.61, 0, 0, 1, 0, 100, 51371),
(276805, 2, 9712.63, 2489.88, 1372.3, 0, 0, 1, 0, 100, 51371),
(276805, 3, 9627.21, 2418.57, 1384.62, 0, 0, 1, 0, 100, 51371),
(276805, 4, 9641.67, 2389.37, 1386.17, 0, 0, 1, 0, 100, 51371),
(276805, 5, 9725.69, 2424.25, 1384.37, 0, 0, 1, 0, 100, 51371),
(276805, 6, 9765.59, 2536.23, 1384.58, 0, 0, 1, 0, 100, 51371),
(276805, 7, 9830.08, 2598.35, 1382.41, 0, 0, 1, 0, 100, 51371),

(276807, 1, 10117.1, 2486.55, 1348.28, 0, 0, 1, 0, 100, 51371),
(276807, 2, 10221.5, 2416.68, 1374.04, 0, 0, 1, 0, 100, 51371),
(276807, 3, 10127.8, 2258.41, 1386.26, 0, 0, 1, 0, 100, 51371),
(276807, 4, 9894.26, 2418.2, 1365.34, 0, 0, 1, 0, 100, 51371),
(276807, 5, 9927.19, 2597.11, 1361.58, 0, 0, 1, 0, 100, 51371),
(276807, 6, 9955.24, 2560.75, 1347.12, 0, 0, 1, 0, 100, 51371),
(276807, 7, 10008.2, 2566.36, 1341.74, 0, 0, 1, 0, 100, 51371),

(276809, 1, 10097.5, 2531.02, 1386.95, 0, 0, 1, 0, 100, 51371),
(276809, 2, 10026.9, 2634.01, 1370.47, 0, 0, 1, 0, 100, 51371),
(276809, 3, 10026.9, 2634.01, 1370.47, 0, 0, 1, 0, 100, 51371),
(276809, 4, 9800.44, 2311.64, 1404, 0, 0, 1, 0, 100, 51371),
(276809, 5, 9960.37, 2370.48, 1389.53, 0, 0, 1, 0, 100, 51371);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (276797, 276799, 276801, 276803, 276805, 276807, 276809);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`) VALUES
(276797, 276797, 0, 0, 2),
(276797, 276798, 4, 90, 2),

(276799, 276799, 0, 0, 2),
(276799, 276800, 4, 90, 2),

(276801, 276801, 0, 0, 2),
(276801, 276802, 4, 90, 2),

(276803, 276803, 0, 0, 2),
(276803, 276804, 4, 90, 2),

(276805, 276805, 0, 0, 2),
(276805, 276806, 4, 90, 2),

(276807, 276807, 0, 0, 2),
(276807, 276808, 4, 90, 2),

(276809, 276809, 0, 0, 2),
(276809, 276810, 4, 90, 2);

UPDATE `creature` SET `position_x` = 9882.95, `position_y` = 900.002, `position_z` = 1307.93, `orientation` = 1.55456, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 277016;

DELETE FROM `creature_addon` WHERE `guid` = 277016;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(277016, 277016, 1);

DELETE FROM `waypoint_data` WHERE `id` = 277016;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `entry`) VALUES
(277016, 1, 9886.37, 904.421, 1307.55, 0, 0, 0, 0, 100, 2041),
(277016, 2, 9882.54, 917.294, 1307.55, 0, 0, 0, 0, 100, 2041),
(277016, 3, 9878.88, 925.45, 1307.82, 0, 0, 0, 0, 100, 2041),
(277016, 4, 9871.89, 936.968, 1307.84, 0, 0, 0, 0, 100, 2041),
(277016, 5, 9864.17, 948.02, 1306.99, 0, 0, 0, 0, 100, 2041),
(277016, 6, 9856.83, 959.301, 1306.12, 0, 0, 0, 0, 100, 2041),
(277016, 7, 9849.88, 975.782, 1305.41, 0, 0, 0, 0, 100, 2041),
(277016, 8, 9846.68, 993.447, 1305.44, 0, 0, 0, 0, 100, 2041),
(277016, 9, 9845.72, 1006.92, 1305.53, 0, 0, 0, 0, 100, 2041),
(277016, 10, 9845.28, 1020.41, 1305.34, 0, 0, 0, 0, 100, 2041),
(277016, 11, 9846.05, 1031.29, 1305, 0, 0, 0, 0, 100, 2041),
(277016, 12, 9848.78, 1044.59, 1305.17, 0, 0, 0, 0, 100, 2041),
(277016, 13, 9852.76, 1057.36, 1306.07, 0, 0, 0, 0, 100, 2041),
(277016, 14, 9851.18, 1052.11, 1305.52, 0, 0, 0, 0, 100, 2041),
(277016, 15, 9847.88, 1039.12, 1304.95, 0, 0, 0, 0, 100, 2041),
(277016, 16, 9832.69, 1023.72, 1308.11, 0, 0, 0, 0, 100, 2041),
(277016, 17, 9823.19, 1019.2, 1305.44, 0, 0, 0, 0, 100, 2041),
(277016, 18, 9810.24, 1016.12, 1303.97, 0, 0, 0, 0, 100, 2041),
(277016, 19, 9801.49, 1015.03, 1302.59, 0, 0, 0, 0, 100, 2041),
(277016, 20, 9797.42, 1014.18, 1301.21, 0, 0, 0, 0, 100, 2041),
(277016, 21, 9786.14, 1007.42, 1299.12, 0, 0, 0, 0, 100, 2041),
(277016, 22, 9772.47, 990.013, 1297.39, 0, 0, 0, 0, 100, 2041),
(277016, 23, 9759.59, 972.153, 1293.23, 0, 0, 0, 0, 100, 2041),
(277016, 24, 9750.87, 956.592, 1294.03, 0, 0, 0, 0, 100, 2041),
(277016, 25, 9744.92, 944.502, 1293.48, 0, 0, 0, 0, 100, 2041),
(277016, 26, 9742.14, 936.156, 1294.69, 0, 0, 0, 0, 100, 2041),
(277016, 27, 9746.44, 926.057, 1295.85, 0, 0, 0, 0, 100, 2041),
(277016, 28, 9757.6, 918.558, 1296.82, 0, 0, 0, 0, 100, 2041),
(277016, 29, 9773.63, 910.609, 1297.95, 0, 0, 0, 0, 100, 2041),
(277016, 30, 9791.31, 908.167, 1297.97, 0, 0, 0, 0, 100, 2041),
(277016, 31, 9808.96, 907.724, 1300.93, 0, 0, 0, 0, 100, 2041),
(277016, 32, 9826.47, 909.933, 1303.68, 0, 0, 0, 0, 100, 2041),
(277016, 33, 9839.64, 909.51, 1305.52, 0, 0, 0, 0, 100, 2041),
(277016, 34, 9847.78, 906.097, 1306.13, 0, 0, 0, 0, 100, 2041),
(277016, 35, 9855.5, 902.546, 1306.55, 0, 0, 0, 0, 100, 2041),
(277016, 36, 9871.58, 897.968, 1308.28, 0, 0, 0, 0, 100, 2041),
(277016, 37, 9877.62, 893.394, 1308.87, 0, 0, 0, 0, 100, 2041),
(277016, 38, 9878.54, 875.883, 1306.7, 0, 0, 0, 0, 100, 2041),
(277016, 39, 9876.33, 848.658, 1307.22, 0, 0, 0, 0, 100, 2041),
(277016, 40, 9878.99, 862.769, 1307.25, 0, 0, 0, 0, 100, 2041),
(277016, 41, 9880.77, 871.567, 1307.16, 0, 0, 0, 0, 100, 2041),
(277016, 42, 9886.14, 888.723, 1307.61, 0, 0, 0, 0, 100, 2041),
(277016, 43, 9886.9, 897.315, 1307.5, 0, 0, 0, 0, 100, 2041);

UPDATE `creature` SET `position_x` = 10547.014648, `position_y` = 875.161499, `position_z` = 1309.603149, `orientation` = 1.639151 WHERE `guid` = 276862;

UPDATE `creature_template_addon` SET `bytes1` = 65536 WHERE `entry` = 49479;
UPDATE `creature_template_addon` SET `bytes1` = 3 WHERE `entry` = 8584;
DELETE FROM `creature_addon` WHERE `guid` = 276856;
INSERT INTO `creature_addon` (`guid`, `bytes1`) VALUES
(276856, 8);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 49479;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 49479 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 49479*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(49479,0,0,0,20,0,100,0,28724,0,0,0,80,49479*100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dentaria Silverglade - On Quest (28724) Rewarded - Start Script"),
(49479,0,1,0,19,0,100,0,28725,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dentaria Silverglade - On Quest (28725) Accepted - Say Text Line 1"),
(49479,0,2,0,19,0,100,0,28729,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dentaria Silverglade - On Quest (28729) Accepted - Say Text Line 2"),
(49479,0,3,0,19,0,100,0,28730,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dentaria Silverglade - On Quest (28730) Accepted - Say Text Line 3"),

(49479*100,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dentaria Silverglade - On Script - Remove NPC Flag Quest Giver"),
(49479*100,9,1,0,0,0,100,0,0,0,0,0,11,87071,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dentaria Silverglade - On Script - Cast Cosmetic Spell 'Alchemy'"),
(49479*100,9,2,0,0,0,100,0,11000,11000,0,0,11,92388,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dentaria Silverglade - On Script - Cast Cosmetic Spell 'Curing Ivveron'"),
(49479*100,9,3,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dentaria Silverglade - On Script - Say Text Line 0"),
(49479*100,9,4,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dentaria Silverglade - On Script - Add NPC Flag Quest Giver");

DELETE FROM `conditions` WHERE `SourceEntry` = 92388 AND `SourceGroup` = 1 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 92388, 0, 0, 31, 0, 3, 8584, 0, 0, 0, 0, "", "Spell ID: 92388 target Iverron");

DELETE FROM `creature_text` WHERE `entry` = 49479;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text_female`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(49479,0,0,"","Iverron's poison is cured, but it will take some time for him to recover.",12,0,100,1,0,0,"Dentaria Silverglade"),
(49479,1,0,"","Shadowthread Cave lies to the north. Be careful, it's dangerous there of late.",12,0,100,397,0,0,"Dentaria Silverglade"),
(49479,2,0,"","The moonwell is to the northeast, on the other side of the pool and up the hill.",12,0,100,397,0,0,"Dentaria Silverglade"),
(49479,3,0,"","The ramp up to Aldrassil is just in sight over there. Circle around and find Tenaron up top.",12,0,100,397,0,0,"Dentaria Silverglade");

DELETE FROM `creature` WHERE `guid` = 372316 AND `id` = 49480;
