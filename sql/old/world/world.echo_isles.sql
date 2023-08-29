UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 38217;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38217, -251585) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-251585, 0, 0, 0, 0, 0, 100, 0, 0, 0, 2300, 3900, 11, 95826, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Darkspear Watcher - In Combat - Cast 'Shoot'"),
(-251585, 0, 1, 0, 1, 0, 100, 0, 1000, 3000, 2000, 4000, 5, 37, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkspear Watcher - OOC - Play Emote (37)");

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 37951;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 37951 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 37951*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(37951, 0, 0, 1, 19, 0, 100, 0, 24750, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Jin'thala - On Quest Accept - Say Text Line 0"),
(37951, 0, 1, 18, 61, 0, 100, 0, 0, 0, 0, 0, 12, 37988, 8, 0, 0, 0, 0, 8, 0, 0, 0, -1173.453, -5266.401, 0.9423928, 0.2298513, "Jin'thala - On Quest Accept (Link) - Summon Zuni"),

(37951, 0, 2, 3, 19, 0, 100, 0, 24758, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Jin'thala - On Quest Accept - Say Text Line 0"),
(37951, 0, 3, 18, 61, 0, 100, 0, 0, 0, 0, 0, 12, 37988, 8, 0, 0, 0, 0, 8, 0, 0, 0, -1173.453, -5266.401, 0.9423928, 0.2298513, "Jin'thala - On Quest Accept (Link) - Summon Zuni"),

(37951, 0, 4, 5, 19, 0, 100, 0, 24770, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Jin'thala - On Quest Accept - Say Text Line 0"),
(37951, 0, 5, 18, 61, 0, 100, 0, 0, 0, 0, 0, 12, 37988, 8, 0, 0, 0, 0, 8, 0, 0, 0, -1173.453, -5266.401, 0.9423928, 0.2298513, "Jin'thala - On Quest Accept (Link) - Summon Zuni"),

(37951, 0, 6, 7, 19, 0, 100, 0, 24776, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Jin'thala - On Quest Accept - Say Text Line 0"),
(37951, 0, 7, 18, 61, 0, 100, 0, 0, 0, 0, 0, 12, 37988, 8, 0, 0, 0, 0, 8, 0, 0, 0, -1173.453, -5266.401, 0.9423928, 0.2298513, "Jin'thala - On Quest Accept (Link) - Summon Zuni"),

(37951, 0, 8, 9, 19, 0, 100, 0, 24782, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Jin'thala - On Quest Accept - Say Text Line 0"),
(37951, 0, 9, 18, 61, 0, 100, 0, 0, 0, 0, 0, 12, 37988, 8, 0, 0, 0, 0, 8, 0, 0, 0, -1173.453, -5266.401, 0.9423928, 0.2298513, "Jin'thala - On Quest Accept (Link) - Summon Zuni"),

(37951, 0, 10, 11, 19, 0, 100, 0, 24607, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Jin'thala - On Quest Accept - Say Text Line 0"),
(37951, 0, 11, 18, 61, 0, 100, 0, 0, 0, 0, 0, 12, 37988, 8, 0, 0, 0, 0, 8, 0, 0, 0, -1173.453, -5266.401, 0.9423928, 0.2298513, "Jin'thala - On Quest Accept (Link) - Summon Zuni"),

(37951, 0, 12, 13, 19, 0, 100, 0, 24764, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Jin'thala - On Quest Accept - Say Text Line 0"),
(37951, 0, 13, 18, 61, 0, 100, 0, 0, 0, 0, 0, 12, 37988, 8, 0, 0, 0, 0, 8, 0, 0, 0, -1173.453, -5266.401, 0.9423928, 0.2298513, "Jin'thala - On Quest Accept (Link) - Summon Zuni"),

(37951, 0, 14, 15, 19, 0, 100, 0, 26272, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Jin'thala - On Quest Accept - Say Text Line 0"),
(37951, 0, 15, 18, 61, 0, 100, 0, 0, 0, 0, 0, 12, 37988, 8, 0, 0, 0, 0, 8, 0, 0, 0, -1173.453, -5266.401, 0.9423928, 0.2298513, "Jin'thala - On Quest Accept (Link) - Summon Zuni"),

(37951, 0, 16, 17, 19, 0, 100, 0, 31159, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Jin'thala - On Quest Accept - Say Text Line 0"),
(37951, 0, 17, 18, 61, 0, 100, 0, 0, 0, 0, 0, 12, 37988, 8, 0, 0, 0, 0, 8, 0, 0, 0, -1173.453, -5266.401, 0.9423928, 0.2298513, "Jin'thala - On Quest Accept (Link) - Summon Zuni"),

(37951, 0, 18, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 37951*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jin'thala - On Quest Accept (Link) - Start Script"),

(37951*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jin'thala - On Script - Remove Npc Flag Quest Giver"),
(37951*100, 9, 1, 0, 0, 0, 100, 0, 16000, 16000, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Jin'thala - On Script - Add Npc Flag Quest Giver");

DELETE FROM `creature_text` WHERE `entry` = 37951;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(37951, 0, 0, "$n. Zuni. Ya'll find ya trainer in the trainin' grounds to the east. Bring pride to the Darkspear.", "", 12, 0, 100, 1, 0, 0, "Jin'thala");

DELETE FROM `waypoints` WHERE `entry` = 37988*10;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(37988*10, 1, -1167.87, -5281.1, 1.15112, "Zuni Point 1"),
(37988*10, 2, -1171.67, -5302.84, 6.65308, "Zuni Point 2"),
(37988*10, 3, -1179.91, -5314.7, 11.0816, "Zuni Point 3"),
(37988*10, 4, -1190.13, -5326.58, 13.3516, "Zuni Point 4"),
(37988*10, 5, -1207.07, -5354.74, 13.2643, "Zuni Point 5"),
(37988*10, 6, -1207.28, -5373.21, 12.4616, "Zuni Point 6"),
(37988*10, 7, -1181.83, -5379.26, 11.951, "Zuni Point 7"),
(37988*10, 8, -1162.04, -5391.74, 12.06027, "Zuni Point 8");

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 37988;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 37988 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (37988*100, 37988*100+01) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(37988, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 37988*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Just Summon - Start Script"),
(37988, 0, 1, 0, 40, 0, 100, 0, 8, 0, 0, 0, 80, 37988*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On WP 8 Reached - Start Script"),

(37988*100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.2298513, "Zuni - On Script - Set Orientation (0.2298513)"),
(37988*100, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.655128, "Zuni - On Script - Set Orientation (1.655128)"),
(37988*100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Say Text Line 0"),
(37988*100, 9, 3, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 53, 1, 37988*10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Start WP"),

(37988*100+01, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.490659, "Zuni - On Script - Set Orientation (3.490659)"),
(37988*100+01, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Say Text Line 1"),
(37988*100+01, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Despawn Self");

DELETE FROM `creature_text` WHERE `entry` = 37988;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(37988, 0, 0, "Ya, mon. Let's crack some tiki target skulls!", "", 12, 0, 100, 5, 0, 21366, "Zuni"),
(37988, 1, 0, "Ya trainer should be somewhere in the grounds 'ere. I'll catch you lata, mon.", "", 12, 0, 100, 1, 0, 21367, "Zuni");

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38038, 38278, 38279, 42619, 38281, 38268, 38282, 38272, 38280) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3803800, 3803801, 3803802) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
-- Tiki Target
(38038, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 87, 3803800, 3803801, 3803802, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On Respawn - Run Random Script"),
(38038, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 117, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - Linked To Id 0 - Set Health Regen 0"),
(38038, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 102, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - Linked To Id 0 - Set Health Regen 0"),
(38038, 0, 3, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 203, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - In Combat - Combat Stop"),
(38038, 0, 4, 0, 8, 0, 100, 0, 100, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On SpellHit Charge - Quest Credit"),
(38038, 0, 5, 0, 8, 0, 100, 0, 20271, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On SpellHit Judgment - Quest Credit"),
(38038, 0, 6, 0, 8, 0, 100, 0, 56641, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On SpellHit Steady Shot - Quest Credit"),
(38038, 0, 7, 0, 8, 0, 100, 0, 2098, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On SpellHit Run Through - Quest Credit"),
(38038, 0, 8, 0, 8, 0, 100, 0, 73899, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On SpellHit Primal Strike - Quest Credit"),
(38038, 0, 9, 0, 8, 0, 100, 0, 122, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On SpellHit Frost Nova - Quest Credit"),
(38038, 0, 10, 0, 8, 0, 100, 0, 172, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On SpellHit Corruption - Quest Credit"),
(38038, 0, 11, 0, 8, 0, 100, 0, 589, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On SpellHit Shadow Word: Pain - Quest Credit"),
(38038, 0, 12, 0, 8, 0, 100, 0, 8921, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On SpellHit Moonfire - Quest Credit"),
(38038, 0, 13, 0, 8, 0, 100, 0, 100787, 0, 0, 0, 33, 44175, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On SpellHit Tiger Palm - Quest Credit"),
(38038, 0, 14, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 71240, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On Death - Cast Spell 'Tiki Target Death'"),
-- Tiki Target Action List 00
(3803800, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 71064, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Training Dummy - On Action List - Cast Visual 1"),
(3803800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38281, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803800, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38268, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803800, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 42619, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803800, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38272, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803800, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38282, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803800, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38278, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803800, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38279, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803800, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38280, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
-- Tiki Target Action List 01
(3803801, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 71065, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On Script - Cast Tiki Target Visual 2"),
(3803801, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38281, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803801, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38268, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803801, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 42619, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803801, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38272, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803801, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38282, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803801, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38278, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803801, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38279, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803801, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38280, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
-- Tiki Target Action List 02
(3803802, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 71066, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Tiki Target - On Script - Cast Tiki Target Visual 3"),
(3803802, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38281, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803802, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38268, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803802, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 42619, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803802, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38272, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803802, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38282, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803802, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38278, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803802, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38279, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
(3803802, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 11, 38280, 50, 0, 0, 0, 0, 0, "Tiki Target - On Script - Set Data 0 1"),
-- Novice Darkspear Priest
(38278, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 11, 9734, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Priest - On Data Set 0 1 - Attack Start"),
(38278, 0, 1, 0, 60, 0, 100, 0, 3000, 6000, 3000, 6000, 11, 9734, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Priest - In Combat - Cast Spell 'Holy Smite'"),
-- Novice Darkspear Mage
(38279, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 11, 20797, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Mage - On Data Set 0 1 - Attack Start"),
(38279, 0, 1, 0, 60, 0, 100, 0, 3500, 6500, 3500, 6500, 11, 20797, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Mage - In Combat - Cast Spell 'Fireball'"),
-- Novice Darkspear Warlock
(42619, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 11, 20791, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Warlock - On Data Set 0 1 - Attack Start"),
(42619, 0, 1, 0, 60, 0, 100, 0, 3500, 6500, 3500, 6500, 11, 20791, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Warlock - In Combat - Cast Spell 'Shadow Bolt'"),
-- Novice Darkspear Shaman
(38281, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 11, 20802, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Shaman - On Data Set 0 1 - Attack Start"),
(38281, 0, 1, 0, 60, 0, 100, 0, 3500, 6500, 3500, 6500, 11, 20802, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Shaman - In Combat - Cast Spell 'Lightning Bolt'"),
-- Novice Darkspear Warrior
(38268, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Warrior - On Data Set 0 1 - Attack Start"),
(38268, 0, 1, 0, 60, 0, 100, 0, 3000, 6000, 3000, 6000, 11, 25710, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Novice Darkspear Warrior - In Combat - Cast Spell 'Heroic Strike'"),
-- Novice Darkspear Hunter
(38282, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 11, 6660, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Hunter - On Data Set 0 1 - Attack Start"),
(38282, 0, 1, 0, 60, 0, 100, 0, 1000, 4000, 1000, 4000, 11, 6660, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Hunter - In Combat - Cast Spell 'Shoot'"),
-- Novice Darkspear Rogue
(38272, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Rogue - On Data Set 0 1 - Attack Start"),
(38272, 0, 1, 0, 60, 0, 100, 0, 3000, 6000, 3000, 6000, 11, 60195, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Novice Darkspear Rogue - In Combat - Cast Spell 'Sinister Strike'"),
-- Novice Darkspear Druid
(38280, 0, 0, 0, 38, 0, 100, 0, 0, 1, 0, 0, 11, 9739, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Druid - On Data Set 0 1 - Attack Start"),
(38280, 0, 1, 0, 60, 0, 100, 0, 2500, 2500, 2500, 2500, 11, 9739, 0, 0, 0, 0, 0, 19, 38038, 20, 0, 0, 0, 0, 0, "Novice Darkspear Druid - In Combat - Cast Spell 'Wrath'");

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` IN (38326, 38324);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38300, 38326, 38301, 38324) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(38300, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spitescale Wavethrasher - On Respawn - Set React State Aggressive"),
(38300, 0, 1, 0, 0, 0, 100, 0, 4000, 5000, 17000, 23000, 11, 79810, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Spitescale Wavethrasher - In Combat - Cast Spell 'Frost Cleave'"),

(38326, 0, 0, 0, 0, 0, 100, 0, 3400, 4700, 3400, 4700, 11, 73212, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Darkspear Shaman - In Combat - Cast Spell 'Lightning Bolt'"),
(38326, 0, 1, 0, 2, 0, 100, 0, 0, 40, 14000, 21000, 11, 72014, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkspear Shaman - At 40% HP - Cast Spell 'Chain Heal'"),
(38326, 0, 2, 0, 1, 0, 100, 0, 1000, 1000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 11, 38300, 30, 0, 0, 0, 0, 0, "Darkspear Shaman - OOC - Start Attack Creature ID: 38300, 30 Yards"),

(38301, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spitescale Siren - On Respawn - Set React State Aggressive"),
(38301, 0, 1, 0, 9, 0, 100, 0, 0, 40, 3400, 4700, 11, 32011, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Spitescale Siren - On Close 0-40 Yards - Cast Spell 'Chain Lightning'"),
(38301, 0, 2, 0, 0, 0, 100, 0, 5000, 8000, 22000, 24000, 11, 15117, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Spitescale Siren - In Combat - Cast Spell 'Water Bolt'"),
(38301, 0, 3, 0, 38, 0, 100, 0, 1, 1, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, "Spitescale Siren - On Data Set 1 1 - Start Attack"),

(38324, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 5000, 5000, 49, 0, 0, 0, 0, 0, 0, 11, 38300, 30, 0, 0, 0, 0, 0, "Darkspear Tribesman - OOC - Start Attack Creature ID: 38300, 30 Yards");

UPDATE `creature_template_addon` SET `auras` = "91218" WHERE `entry` = 38306;

UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` IN (38225, 38306, 38437, 38423, 38542);
UPDATE `creature_template` SET `speed_walk` = 0.001, `speed_run` = 0.001 WHERE `entry` = 38306;
UPDATE `creature_template` SET `faction_A` = 2224, `faction_H` = 2224 WHERE `entry` IN (38302, 38300);

UPDATE `creature` SET `spawntimesecs` = 3600 WHERE `guid` IN (252720, 252718, 252905, 252906, 252719);
UPDATE `creature` SET `spawntimesecs` = 300 WHERE `guid` = 252717;

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` IN (38423, 38225, 38437, 38306, 38542, 38302, 38452);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38423, 38225, 38437, 38306, 38542, 38302, -252718, 38452) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3842300, 3842301, 3842302, 3822500, 3822501, 3822502, 3822503, 3830600, 3830601, 3830602, 3830603, 3830604,
                                                    3830605, 3843700, 3843701, 3843702, 3843703) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(38423, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Respawn - Set Unit Flags (768)"),
(38423, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Respawn (Link) - Set Run Off"),
(38423, 0, 3, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 3842300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Data Set 1 1 - Start Script"),
(38423, 0, 4, 0, 0, 0, 100, 0, 1000, 1000, 8000, 8000, 11, 73255, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Zuni - In Combat - Cast Spell 'Earth Shock'"),
(38423, 0, 5, 0, 0, 0, 100, 0, 4000, 4000, 14000, 14000, 11, 73254, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Zuni - In Combat - Cast Spell 'Lightning Bolt'"),
(38423, 0, 6, 0, 0, 0, 100, 0, 10000, 10000, 21000, 21000, 11, 73253, 0, 0, 0, 0, 0, 18, 50, 0, 0, 0, 0, 0, 0, "Zuni - In Combat - Cast Spell 'Healing Wave'"),
(38423, 0, 7, 8, 38, 0, 100, 0, 2, 2, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Data Set 2 2 - Auto Attack Stop"),
(38423, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 75, 73004, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Data Set 2 2 (Link) - Cast Cosmetic Spell"),
(38423, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 93199, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Data Set 2 2 (Link) - Cast Cosmetic Spell"),
(38423, 0, 10, 11, 38, 0, 100, 0, 3, 3, 0, 0, 28, 73004, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Data Set 3 3 - Remove Cosmetic Spell"),
(38423, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 28, 93199, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Data Set 3 3 (Link) - Remove Cosmetic Spell"),
(38423, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Data Set 3 3 (Link) - Auto Attack Start"),
(38423, 0, 13, 0, 4, 0, 100, 0, 0, 0, 0, 0, 91, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Aggro - Remove Flag Sitting"),
(38423, 0, 14, 0, 4, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Zuni - On Aggro - Start Attack Creature ID: 38306, Distance 100 Yards"),
(38423, 0, 15, 16, 38, 0, 100, 0, 4, 4, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Data Set 4 4 - Auto Attack Stop"),
(38423, 0, 16, 17, 61, 0, 100, 0, 0, 0, 0, 0, 75, 73004, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Data Set 4 4 (Link) - Cast Cosmetic Spell"),
(38423, 0, 17, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 93199, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Data Set 4 4 (Link) - Cast Cosmetic Spell"),
(38423, 0, 18, 0, 38, 0, 100, 0, 5, 5, 0, 0, 80, 3842301, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Data Set 5 5 - Start Script"),
(38423, 0, 19, 0, 34, 0, 100, 0, 8, 1, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On MI 1 - Set Home Position"),
(38423, 0, 20, 0, 38, 0, 100, 0, 6, 6, 0, 0, 80, 3842302, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Data Set 6 6 - Start Script"),

(3842300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Remove Flag Sitting"),
(3842300, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -730.031, -5594.71, 25.6244, 0, "Zuni - On Script - Move To Position"),
(3842300, 9, 2, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Set Home Position"),
(3842300, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Combat Movement Stop"),
(3842300, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Remove Unit Flags (768)"),
(3842300, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Zuni - On Script - Start Attack Creature ID: 38306, Distance 100 Yards"),

(3842301, 9, 0, 0, 0, 0, 100, 0, 200, 200, 0, 0, 28, 73004, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Remove Cosmetic Spell"),
(3842301, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 93199, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Remove Cosmetic Spell"),
(3842301, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Set Unit Flags (768)"),
(3842301, 9, 3, 0, 0, 0, 100, 0, 400, 400, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Say Text Line 0"),
(3842301, 9, 4, 0, 0, 0, 100, 0, 200, 200, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Set Run On"),
(3842301, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, -712.563, -5575.99, 27, 0, "Zuni - On Script - Move To Position"),

(3842302, 9, 0, 0, 0, 0, 100, 0, 200, 200, 0, 0, 11, 69252, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Cast Spell 'Frost Explosion'"),
(3842302, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 75, 114371, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Add Aura 'Permanent Feign Death'"),
(3842302, 9, 2, 0, 0, 0, 100, 0, 600, 600, 0, 0, 45, 6, 6, 0, 0, 0, 0, 11, 38437, 100, 0, 0, 0, 0, 0, "Zuni - On Script - Set Data 6 6 (Creature ID: 38437)"),
(3842302, 9, 3, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 41, 40000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Despawn Self (40000 ms)"),

(38225, 0, 0, 0, 62, 0, 100, 0, 11020, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Gossip Select - Close Gossip"),
(38225, 0, 1, 0, 62, 0, 100, 0, 11020, 0, 0, 0, 33, 38225, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Gossip Select - Quest Credit 1"),
(38225, 0, 2, 3, 62, 0, 100, 0, 11020, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Gossip Select - Store Target List (Invoker)"),
(38225, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3822503, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Gossip Select (Link) - Start Script"),
(38225, 0, 4, 0, 40, 0, 100, 0, 1, 38225, 0, 0, 80, 3822500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On WP 1 Reached - Start Script"),
(38225, 0, 5, 6, 38, 0, 100, 0, 1, 1, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Vol'jin - On Data Set 1 1 - Start Attack Creature ID: 38306, Distance 100 Yards"),
(38225, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3822501, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Data Set 1 1 (Link) - Start Script"),
(38225, 0, 7, 0, 0, 2, 100, 0, 3000, 4000, 3000, 4000, 11, 20463, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Vol'jin - In Combat- Cast Spell 'Shoot' (Phase 2)"),
(38225, 0, 8, 0, 0, 2, 100, 0, 20000, 30000, 20000, 30000, 11, 73087, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Vol'jin - In Combat - Cast Spell 'Shadow Shock' (Phase 2)"),
(38225, 0, 9, 10, 38, 0, 100, 0, 2, 2, 0, 0, 70, 0, 0, 0, 0, 0, 0, 11, 38452, 100, 0, 0, 0, 0, 0, "Vol'jin - On Data Set 2 2 - Respawn Target"),
(38225, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 72044, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Data Set 2 2 (Link) - Cast Cosmetic Spell"),
(38225, 0, 11, 0, 38, 0, 100, 0, 3, 3, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Data Set 3 3 - Set Phase 2"),
(38225, 0, 12, 13, 38, 0, 100, 0, 4, 4, 0, 0, 70, 0, 0, 0, 0, 0, 0, 11, 38452, 100, 0, 0, 0, 0, 0, "Vol'jin - On Data Set 4 4 - Respawn Target"),
(38225, 0, 13, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 72044, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Data Set 4 4 (Link) - Cast Cosmetic Spell"),
(38225, 0, 14, 0, 38, 0, 100, 0, 5, 5, 0, 0, 53, 1, 382250, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Data Set 5 5 - Start WP"),
(38225, 0, 15, 0, 40, 0, 100, 0, 2, 382250, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On WP 2 Reached - Despawn Self (1000 ms)"),
(38225, 0, 16, 17, 11, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Respawn - Clear Emote State (0)"),
(38225, 0, 17, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3822502, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Respawn (Link) - Start Script"),

(3822500, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Script - Set Home Position"),
(3822500, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Script - Combat Movement Stop"),
(3822500, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Script - Say Text Line 0"),
(3822500, 9, 3, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Vol'jin - On Script - Set Data 1 1 (Creature ID: 38306)"),
(3822500, 9, 4, 0, 0, 0, 100, 0, 400, 400, 0, 0, 100, 1, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Vol'jin - On Script - Send Target List To Creature ID: 38306"),
(3822500, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Script - Set Emote State (333)"),
(3822500, 9, 6, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 252718, 38423, 0, 0, 0, 0, 0, "Vol'jin - On Script - Set Data 1 1 (Creature ID: 38423)"),

(3822501, 9, 0, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Script - Set Phase 2"),

(3822502, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 11, 38423, 100, 0, 0, 0, 0, 0, "Vol'jin - On Script - Respawn Target"),
(3822502, 9, 1, 0, 0, 0, 100, 0, 100, 100, 0, 0, 70, 0, 0, 0, 0, 0, 0, 11, 38437, 100, 0, 0, 0, 0, 0, "Vol'jin - On Script - Respawn Target"),
(3822502, 9, 2, 0, 0, 0, 100, 0, 100, 100, 0, 0, 70, 0, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Vol'jin - On Script - Respawn Target"),

(3822503, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 53, 0, 38225, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Script - WP Start"),
(3822503, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 38437, 100, 0, 0, 0, 0, 0, "Vol'jin - On Script - Set Data 1 1 (Creature ID: 38437)"),
(3822503, 9, 2, 0, 0, 0, 100, 0, 100, 100, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Script - Remove Npc Flag Quest Giver"),

(38437, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 53, 0, 38437, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Data Set 1 1 - Start WP"),
(38437, 0, 1, 2, 40, 0, 100, 0, 1, 38437, 0, 0, 17, 333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On WP 1 Reached - Set Emote State (333)"),
(38437, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On WP 1 Reached (Link) - Set Home Position"),
(38437, 0, 3, 4, 38, 0, 100, 0, 2, 2, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Vanira - On Data Set 2 2 - Start Attack Creature ID: 38306, Distance 100 Yards"),
(38437, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Data Set 2 2 (Link) - Say Text Line 0"),
(38437, 0, 5, 0, 0, 0, 100, 0, 0, 0, 600000, 600000, 11, 71984, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - In Combat - Cast Spell 'Healing Stream Totem'"),
(38437, 0, 6, 0, 0, 0, 100, 0, 1000, 1000, 600000, 600000, 11, 73393, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - In Combat - Cast Spell 'Mana Stream Totem'"),
(38437, 0, 7, 0, 0, 0, 100, 0, 2000, 2000, 65000, 65000, 11, 71974, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - In Combat - Cast Spell 'Serpent Ward'"),
(38437, 0, 8, 9, 38, 0, 100, 0, 3, 3, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Data Set 3 3 - Auto Attack Stop"),
(38437, 0, 9, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3843700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Data Set 3 3 (Link) - Start Script"),
(38437, 0, 10, 11, 38, 0, 100, 0, 4, 4, 0, 0, 28, 73004, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Data Set 4 4 - Remove Cosmetic Spell"),
(38437, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 28, 93199, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Data Set 4 4 (Link) - Remove Cosmetic Spell"),
(38437, 0, 12, 0, 61, 0, 100, 0, 0, 0, 0, 0, 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Data Set 4 4 (Link) - Auto Attack Start"),
(38437, 0, 13, 14, 38, 0, 100, 0, 5, 5, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Data Set 5 5 - Auto Attack Stop"),
(38437, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3843701, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Data Set 5 5 (Link) - Start Script"),
(38437, 0, 15, 0, 38, 0, 100, 0, 6, 6, 0, 0, 80, 3843702, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Data Set 6 6 - Start Script"),
(38437, 0, 16, 0, 34, 0, 100, 0, 8, 2, 0, 0, 80, 3843703, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On MI 1 - Start Script"),
(38437, 0, 17, 0, 11, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Respawn - Clear Emote State (0)"),
(38437, 0, 18, 19, 62, 0, 100, 0, 11107, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Gossip Select - Close Gossip"),
(38437, 0, 19, 0, 61, 0, 100, 0, 0, 0, 0, 0, 62, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, -1286.517578, -5566.907227, 20.926611, 3.940922, "Vanira - On Gossip Select (Link) - Teleport"),

(3843700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 66033, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Cast Cosmetic Spell"),
(3843700, 9, 1, 0, 0, 0, 100, 0, 400, 400, 0, 0, 11, 93199, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Cast Cosmetic Spell"),
(3843700, 9, 2, 0, 0, 0, 100, 0, 800, 800, 0, 0, 75, 73004, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Cast Cosmetic Spell"),

(3843701, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 66033, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Cast Cosmetic Spell"),
(3843701, 9, 1, 0, 0, 0, 100, 0, 400, 400, 0, 0, 11, 93199, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Cast Cosmetic Spell"),
(3843701, 9, 2, 0, 0, 0, 100, 0, 800, 800, 0, 0, 75, 73004, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Cast Cosmetic Spell"),
(3843701, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 45, 5, 5, 0, 0, 0, 0, 11, 38423, 100, 0, 0, 0, 0, 0, "Vanira - On Script - Set Data 5 5 (Creature ID: 38423)"),
(3843701, 9, 4, 0, 0, 0, 100, 0, 200, 200, 0, 0, 28, 93199, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Remove Cosmetic Spell"),
(3843701, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 73004, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Remove Cosmetic Spell"),
(3843701, 9, 6, 0, 0, 0, 100, 0, 600, 600, 0, 0, 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Auto Attack Start"),
(3843701, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Vanira - On Script - Start Attack Creature ID: 38306, Distance 100 Yards"),

(3843702, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Set Emote State (0)"),
(3843702, 9, 1, 0, 0, 0, 100, 0, 800, 800, 0, 0, 66, 0, 0, 0, 0, 0, 0, 11, 38423, 100, 0, 0, 0, 0, 0, "Vanira - On Script - Set Orientation To Creature ID: 38423"),
(3843702, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Say Text Line 1"),
(3843702, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Set Run On"),
(3843702, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 2, 0, 0, 0, 0, 0, 8, 0, 0, 0, -713.038391, -5578.651367, 25.499384, 0, "Vanira - On Script - Move To Position"),
(3843702, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 11, 38225, 100, 0, 0, 0, 0, 0, "Vanira - On Script - Say Text Line 2 (Creature ID: 38225)"),

(3843703, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Set Unit Field Bytes 1 (8)"),
(3843703, 9, 1, 0, 0, 0, 100, 0, 4500, 4500, 0, 0, 1, 3, 0, 0, 0, 0, 0, 11, 38225, 100, 0, 0, 0, 0, 0, "Vanira - On Script - Say Text Line 3 (Creature ID: 38225)"),
(3843703, 9, 2, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 11, 38225, 100, 0, 0, 0, 0, 0, "Vanira - On Script - Say Text Line 4 (Creature ID: 38225)"),
(3843703, 9, 3, 0, 0, 0, 100, 0, 9400, 9400, 0, 0, 45, 5, 5, 0, 0, 0, 0, 11, 38225, 100, 0, 0, 0, 0, 0, "Vanira - On Script - Set Data 5 5 (Creature ID: 38225)"),
(3843703, 9, 4, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Say Text Line 2"),
(3843703, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Set Unit Field Bytes 1 (0)"),
(3843703, 9, 6, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.888296, "Vanira - On Script - Set Orientation (5.888296)"),
(3843703, 9, 7, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Say Text Line 3"),
(3843703, 9, 8, 0, 0, 0, 100, 0, 7600, 7600, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Say Text Line 4"),
(3843703, 9, 9, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 82, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Add NPC Flag Gossip"),
(3843703, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Script - Despawn Self (60000 ms)"),

(38306, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Respawn - Set React State Defensive"),
(38306, 0, 1, 34, 61, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Respawn (Link) - Set Unit Flags (768)"),
(38306, 0, 2, 0, 0, 2, 100, 0, 0, 0, 3000, 3000, 11, 46987, 0, 0, 0, 0, 0, 10, 252717, 38225, 0, 0, 0, 0, 0, "Zar'jira - In Combat - Cast Spell 'Frostbolt' (Phase 2)"),
(38306, 0, 3, 0, 0, 2, 100, 0, 7000, 7000, 15000, 20000, 87, 3830601, 3830602, 3830603, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - In Combat - Start Random Script (Phase 2)"),
(38306, 0, 4, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 3830600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Data Set 1 1 - Start Script"),
(38306, 0, 5, 6, 2, 0, 100, 1, 0, 50, 0, 0, 92, 0, 46987, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - Between 0-50% Health - Interrupt Spell Cast"),
(38306, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 11, 34326, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - Between 0-50% Health (Link) - Cast Cosmetic Spell"),
(38306, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - Between 0-50% Health (Link) - Set Phase 1"),
(38306, 0, 8, 9, 61, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 11, 38437, 100, 0, 0, 0, 0, 0, "Zar'jira - Between 0-50% Health (Link) - Set Data 3 3 (Creature ID: 38437)"),
(38306, 0, 9, 10, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 11, 38423, 100, 0, 0, 0, 0, 0, "Zar'jira - Between 0-50% Health (Link) - Set Data 2 2 (Creature ID: 38423)"),
(38306, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 11, 38225, 100, 0, 0, 0, 0, 0, "Zar'jira - Between 0-50% Health (Link) - Set Data 2 2 (Creature ID: 38225)"),
(38306, 0, 11, 12, 60, 1, 100, 1, 1000, 1000, 0, 0, 18, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Update - Set Unit Flags (256)(Phase 1)"),
(38306, 0, 12, 13, 61, 1, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 38542, 100, 0, 0, 0, 0, 0, "Zar'jira - On Update (Link) - Set Data 1 1 (Creature ID: 38542)(Phase 1)"),
(38306, 0, 13, 14, 61, 1, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 38452, 100, 0, 0, 0, 0, 0, "Zar'jira - On Update (Link) - Set Data 1 1 (Creature ID: 38452)(Phase 1)"),
(38306, 0, 14, 0, 61, 1, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 11, 38225, 100, 0, 0, 0, 0, 0, "Zar'jira - On Update (Link) - Say Text Line 1 (Creature ID: 38225)(Phase 1)"),
(38306, 0, 15, 0, 38, 1, 100, 0, 2, 2, 0, 0, 63, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Data Set 2 2 - Store Variable Decimal 1 1 (Phase 1)"),
(38306, 0, 16, 17, 77, 0, 100, 0, 1, 3, 0, 0, 45, 2, 2, 0, 0, 0, 0, 11, 38452, 100, 0, 0, 0, 0, 0, "Zar'jira - On Variable Decimal 1 3 - Set Data 2 2 (Creature ID: 38452)"),
(38306, 0, 17, 18, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Variable Decimal 1 3 (Link) - Say Text Line 1"),
(38306, 0, 18, 19, 61, 0, 100, 0, 0, 0, 0, 0, 19, 256, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Variable Decimal 1 3 (Link) - Remove Unit Flags (256)"),
(38306, 0, 19, 20, 61, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 11, 38225, 100, 0, 0, 0, 0, 0, "Zar'jira - On Variable Decimal 1 3 (Link) - Set Data 3 3 (Creature ID: 38225)"),
(38306, 0, 20, 21, 61, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 11, 38437, 100, 0, 0, 0, 0, 0, "Zar'jira - On Variable Decimal 1 3 (Link) - Set Data 4 4 (Creature ID: 38437)"),
(38306, 0, 21, 22, 61, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 11, 38423, 100, 0, 0, 0, 0, 0, "Zar'jira - On Variable Decimal 1 3 (Link) - Set Data 3 3 (Creature ID: 38423)"),
(38306, 0, 22, 0, 61, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Variable Decimal 1 3 (Link) - Set Phase 2"),
(38306, 0, 23, 24, 2, 0, 100, 1, 0, 10, 0, 0, 92, 0, 46987, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - Between 0-10% Health - Interrupt Spell Cast"),
(38306, 0, 24, 25, 61, 0, 100, 0, 0, 0, 0, 0, 11, 34326, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - Between 0-10% Health (Link) - Cast Cosmetic Spell"),
(38306, 0, 25, 26, 61, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - Between 0-10% Health (Link) - Set Phase 0"),
(38306, 0, 26, 27, 61, 0, 100, 0, 0, 0, 0, 0, 45, 5, 5, 0, 0, 0, 0, 11, 38437, 100, 0, 0, 0, 0, 0, "Zar'jira - Between 0-10% Health (Link) - Set Data 5 5 (Creature ID: 38437)"),
(38306, 0, 27, 28, 61, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 11, 38423, 100, 0, 0, 0, 0, 0, "Zar'jira - Between 0-10% Health (Link) - Set Data 4 4 (Creature ID: 38423)"),
(38306, 0, 28, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 4, 4, 0, 0, 0, 0, 11, 38225, 100, 0, 0, 0, 0, 0, "Zar'jira - Between 0-10% Health (Link) - Set Data 4 4 (Creature ID: 38225)"),
(38306, 0, 29, 30, 2, 0, 100, 1, 0, 2, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - Between 0-2% Health - Auto Attack Stop"),
(38306, 0, 30, 0, 21, 0, 100, 0, 0, 0, 0, 0, 80, 3830604, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - Between 0-2% Health (Link) - Start Script"),
(38306, 0, 31, 32, 6, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Death - Say Text Line 3"),
(38306, 0, 32, 33, 61, 0, 100, 0, 0, 0, 0, 0, 33, 38306, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, "Zar'jira - On Death (Link) - Quest Credit 2"),
(38306, 0, 33, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 6, 6, 0, 0, 0, 0, 11, 38423, 100, 0, 0, 0, 0, 0, "Zar'jira - On Death (Link) - Set Data 6 6 (Creature ID: 38423)"),
(38306, 0, 34, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 3830605, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Respawn (Link) - Start Script"),

(3830600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Script - Say Text Line 0"),
(3830600, 9, 1, 0, 0, 0, 100, 0, 16000, 16000, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Script - Remove Unit Flags (768)"),
(3830600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Script - Combat Movement Stop"),
(3830600, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 2224, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Script - Set Faction (2224)"),
(3830600, 9, 4, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 38301, 40, 0, 0, 0, 0, 0, "Zar'jira - On Script - Set Data 1 1 (Creature ID: 38301)"),
(3830600, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 11, 38437, 100, 0, 0, 0, 0, 0, "Zar'jira - On Script - Set Data 2 2 (Creature ID: 38437)"),
(3830600, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 38225, 100, 0, 0, 0, 0, 0, "Zar'jira - On Script - Set Data 1 1 (Creature ID: 38225)"),
(3830600, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Script - Set Phase 2"),

(3830601, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 38302, 1, 60000, 0, 0, 0, 8, 0, 0, 0, -742.144, -5579.74, 28, 5.6357, "Zar'jira - On Script - Summon Creature"),

(3830602, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 38302, 1, 60000, 0, 0, 0, 8, 0, 0, 0, -703.477, -5590.16, 28, 3.4007, "Zar'jira - On Script - Summon Creature"),

(3830603, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 38302, 6, 10000, 1, 0, 0, 8, 0, 0, 0, -699.04, -5595.67, 25.755, 0, "Zar'jira - On Script - Summon Creature"),

(3830604, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 11, 38452, 100, 0, 0, 0, 0, 0, "Zar'jira - On Script - Set Data 2 2 (Creature ID: 38452)"),
(3830604, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 11, 38423, 100, 0, 0, 0, 0, 0, "Zar'jira - On Script - Set Orientation To Creature ID: 38423"),

(3830605, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, 252905, 0, 0, 0, 0, 0, 0, "Zar'jira - On Script - Respawn Target"),
(3830605, 9, 1, 0, 0, 0, 100, 0, 200, 200, 0, 0, 70, 0, 0, 0, 0, 0, 0, 10, 252906, 0, 0, 0, 0, 0, 0, "Zar'jira - On Script - Respawn Target"),

(38542, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fire of the Seas - On Respawn - Set Visibility Off"),
(38542, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fire of the Seas - On Data Set 1 1 - Set Visibility On"),
(38542, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 73294, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Fire of the Seas - On Data Set 2 2 (Link) - Cast Spell 'Fire of the Seas Energy Beam'"),
(38542, 0, 3, 4, 73, 0, 100, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fire of the Seas - On Spellclick - Set Visibility Off"),
(38542, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Fire of the Seas - On Spellclick (Link) - Set Data 2 2 (Creature ID: 38306)"),
(38542, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 92, 0, 73294, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fire of the Seas - On Spellclick (Link) - Interrupt Spell Cast (Instant)"),

(38302, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Manifestation of the Sea Witch - On Respawn - Set React State Aggressive"),
(38302, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, "Manifestation of the Sea Witch - On Summmoned - Attack Start"),
(38302, 0, 2, 0, 0, 0, 100, 0, 7000, 7000, 10000, 10000, 11, 73432, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Manifestation of the Sea Witch - In Combat - Cast Spell 'Soul Scar'"),
(38302, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Manifestation of the Sea Witch - On Death - Despawn Self (1000 ms)"),

(38452, 0, 0, 0, 8, 0, 100, 0, 72044, 0, 0, 0, 86, 72045, 0, 11, 38306, 100, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sea Witch Channel Bunny - On Spell Hit 72044 - Cross Cast Cosmetic Spell"),
(38452, 0, 1, 0, 38, 0, 100, 0, 2, 2, 0, 0, 51, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sea Witch Channel Bunny - On Data Set 2 2 - Kill Self");

DELETE FROM `conditions` WHERE `SourceEntry` = 72045 AND `SourceGroup` = 1 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 72045, 0, 0, 31, 0, 3, 38452, 0, 0, 0, 0, "", "Spell ID: 72045 target Sea Witch Channel Bunny");

UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 38452;
UPDATE `creature` SET `position_x` = -713.983215, `position_y` = -5587.527344, `wander_distance` = 0, `movement_type` = 0, `spawntimesecs` = 300 WHERE `guid` = 302892;
DELETE FROM `creature_addon` WHERE `guid` = 302892;
DELETE FROM `waypoint_data` WHERE `id` = 302892;

DELETE FROM `creature_text` WHERE `entry` IN (38225, 38306, 38423, 38437);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `text_range`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38225, 0, 0, "Ya were foolish to come 'ere, Sea Witch. Ya escaped our vengeance once, but the Darkspear Tribe will not abide ya trespassin' again.", "", 0, 14, 0, 100, 1, 0, 20119, "Vol'jin"),
(38225, 1, 0, "She's drawing power from the fires! Stamp out the braziers, quickly!", "", 0, 41, 0, 100, 0, 0, 0, "Vol'jin"),
(38225, 2, 0, "It be done. Our ancient enemy is defeated.", "", 0, 12, 0, 100, 1, 0, 20121, "Vol'jin"),
(38225, 3, 0, "I been waitin' a long time for a chance to avenge my father. A great weight has been lifted from my shoulders.", "", 0, 12, 0, 100, 1, 0, 20122, "Vol'jin"),
(38225, 4, 0, "I must be returnin' ta Darkspear Hold. Please meet me there once Vanira is done with her healin' of the boy.", "", 0, 12, 0, 100, 1, 0, 20123, "Vol'jin"),

(38306, 0, 0, "", "You are weak Vol'jin, like your father was weak. Today I will finish what I started long ago - the Darkspear shall be wiped from existence!", 0, 14, 0, 100, 1, 0, 21810, "Zar'jira"),
(38306, 1, 0, "", "Leave the fire alone, pesky trolls! Just give up and die.", 0, 14, 0, 100, 0, 0, 21812, "Zar'jira"),
(38306, 2, 0, "", "No! I will make your death slow and painful, little trolls.", 0, 14, 0, 100, 0, 0, 21813, "Zar'jira"),
(38306, 3, 0, "", "Not so fast, little troll!", 0, 14, 0, 100, 1, 0, 21815, "Zar'jira"),

(38423, 0, 0, "I'll get the fires dis time!", "", 0, 14, 0, 100, 5, 0, 21388, "Zuni"),

(38437, 0, 0, "", "Take care of her spirits! We be handlin' Zar'jira.", 0, 14, 0, 100, 5, 0, 21944, "Vanira"),
(38437, 1, 0, "", "ZUNI! NOOOO!", 0, 14, 0, 100, 5, 0, 21945, "Vanira"),
(38437, 2, 0, "", "I'm afraid there's nothin' I can do for our brother... her power tore away at his soul.", 0, 12, 0, 100, 1, 0, 21946, "Vanira"),
(38437, 3, 0, "", "I'll send some watchers ta get his body so we can offer a proper farewell... I wish I could do more.", 0, 12, 0, 100, 1, 0, 21947, "Vanira"),
(38437, 4, 0, "", "Vol'jin rushed off in eagerness, but I can take us back to safety. Just give me the word when ya ready, mon.", 0, 12, 0, 100, 275, 0, 21948, "Vanira");

DELETE FROM `waypoints` WHERE `entry` IN (38423, 38225, 382250, 38437);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(38225, 1, -722.57, -5597.48, 25.51, "Vol'jin"),

(382250, 1, -749.814, -5621.62, 23.6901, "Vol'jin"),
(382250, 2, -774.014, -5624.29, 18.497, "Vol'jin"),

(38437, 1, -720.41, -5600.99, 25.51, "Vanira");
