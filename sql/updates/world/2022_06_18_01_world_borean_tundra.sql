UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 95761;

DELETE FROM `creature_addon` WHERE `guid` = 95761;
INSERT INTO `creature_addon` (`guid`, `path_id`) VALUES
(95761, 95761);

DELETE FROM `waypoint_data` WHERE `id` = 95761;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `entry`) VALUES
(95761, 1, 3214.44, 5288.57, 47.3736, 0, 0, 0, 25812),
(95761, 2, 3221.93, 5276.38, 47.1691, 0, 0, 0, 25812),
(95761, 3, 3212.27, 5268.29, 47.552, 0, 0, 0, 25812),
(95761, 4, 3201.68, 5270, 47.6342, 0, 0, 0, 25812),
(95761, 5, 3195.56, 5278.42, 47.8828, 0, 0, 0, 25812),
(95761, 6, 3200.25, 5292.06, 47.6622, 0, 0, 0, 25812);

DELETE FROM `creature_text` WHERE `entry` IN (25317, 25220, 25222);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(25317, 0, 0, "What's the matter, $c?  Think you're too good to stand in line with the rest of us?", "What's the matter, $c?  Think you're too good to stand in line with the rest of us?", 12, 0, 100, 0, 0, 0, "Civilian Recruit to Player"),

(25220, 0, 0, "Miner.", "Miner.", 12, 7, 100, 66, 0, 0, "Civilian Recruit to Generic Quest Trigger - LAB"),
(25220, 0, 1, "Farmhand, sir.", "Farmhand, sir.", 12, 7, 100, 66, 0, 0, "Civilian Recruit to Generic Quest Trigger - LAB"),
(25220, 0, 2, "Tailor.", "Tailor.", 12, 7, 100, 66, 0, 0, "Civilian Recruit to Generic Quest Trigger - LAB"),
(25220, 0, 3, "Blacksmith.", "Blacksmith.", 12, 7, 100, 66, 0, 0, "Civilian Recruit to Generic Quest Trigger - LAB"),
(25220, 0, 4, "Carpenter.", "Carpenter.", 12, 7, 100, 66, 0, 0, "Civilian Recruit to Generic Quest Trigger - LAB"),
(25220, 0, 5, "Shipwright.", "Shipwright.", 12, 7, 100, 66, 0, 0, "Civilian Recruit to Generic Quest Trigger - LAB"),
(25220, 0, 6, "Mason, sir.", "Mason, sir.", 12, 7, 100, 66, 0, 0, "Civilian Recruit to Generic Quest Trigger - LAB"),
(25220, 0, 7, "Cook.", "Cook.", 12, 7, 100, 66, 0, 0, "Civilian Recruit to Generic Quest Trigger - LAB"),

(25222, 0, 0, "What did you do before you came to Northrend, then?", "", 12, 7, 100, 0, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 0, 1, "State your profession.", "", 12, 7, 100, 0, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 0, 2, "Yes, then. What is your trade?", "", 12, 7, 100, 0, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 0, 3, "Your previous line of work, recruit?", "", 12, 7, 100, 0, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 0, 4, "Your profession?", "", 12, 7, 100, 0, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 1, 0, "Yes, you're well seasoned in your field of work. Report to the civilian liaison at once, we need more like you!", "", 12, 7, 100, 273, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 1, 1, "I thought we had enough in your line of work, but it looks like we have some openings. Report to the civilian liaison.", "", 12, 7, 100, 273, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 1, 2, "I do have some openings in your line of work.  Report to the civilian liaison.", "", 12, 7, 100, 273, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 1, 3, "Yeah. We could use some more of you. Report to the civilian liaison for work assignment.", "", 12, 7, 100, 273, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 2, 0, "Not anymore! Here's your sword. Report to the barracks for duty!", "", 12, 7, 100, 397, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 2, 1, "Afraid not, friend. Here's your sword and shield. Report to the barracks for duty.", "", 12, 7, 100, 397, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 2, 2, "You're breaking my heart - I've quotas to fill, you know? Can you wield a sword? Off to the barracks.", "", 12, 7, 100, 397, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 2, 3, "With a sword arm like that? I'm afraid we need you in the front lines, my friend. Report to the barracks.", "", 12, 7, 100, 397, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 2, 4, "Looks like we have room for one more... no, my mistake. That's a seven not a one. Hope you're good with a sword - report to the barracks.", "", 12, 7, 100, 397, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 3, 0, "Next, please!", "", 12, 7, 100, 22, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 3, 1, "Keep it moving, people.", "", 12, 7, 100, 22, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB"),
(25222, 3, 2, "Next!", "", 12, 7, 100, 22, 0, 0, "Recruitment Officer Carven to Generic Quest Trigger - LAB");

DELETE FROM `waypoints` WHERE `entry` = 25220;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(25220, 1, 2253.644, 5195.469, 11.40062, "Civilian Recruit"),
(25220, 2, 2254.098, 5196.36, 11.40062, "Civilian Recruit"),
(25220, 3, 2277.823, 5238.724, 11.45096, "Civilian Recruit"),
(25220, 4, 2279.217, 5241.407, 11.45096, "Civilian Recruit"),
(25220, 5, 2280.84, 5244.218, 11.45719, "Civilian Recruit"),
(25220, 6, 2282.603, 5245.736, 11.36353, "Civilian Recruit"),
(25220, 7, 2284.867, 5246.299, 11.45096, "Civilian Recruit"),
(25220, 8, 2287.469, 5245.929, 11.45096, "Civilian Recruit"),
(25220, 9, 2289.469, 5244.898, 11.45096, "Civilian Recruit"),
(25220, 10, 2291.772, 5243.933, 11.45096, "Civilian Recruit"),
(25220, 11, 2294.129, 5242.708, 11.45096, "Civilian Recruit"),
(25220, 12, 2296.062, 5241.932, 12.3176, "Civilian Recruit"),
(25220, 13, 2303.019, 5253.306, 11.50584, "Civilian Recruit"),
(25220, 14, 2308.73, 5256.926, 11.50584, "Civilian Recruit"),
(25220, 15, 2320.826, 5259.258, 11.25584, "Civilian Recruit");

DELETE FROM `creature` WHERE `guid` IN (111468, 98098, 98127, 98162, 98163, 95781, 95780, 95034, 96926);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (24959, 25220, 25307);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` IN (-298790, -298791);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` IN (25220, 25307);
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryorguid` IN (25220*100, 25220*100+01);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-298790, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Generic Quest Trigger - LAB - On Spawn - Set Active On"),
(-298790, 0, 1, 0, 1, 0, 100, 0, 0, 0, 22000, 23000, 12, 25220, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Generic Quest Trigger - LAB - OOC - Cast Borean Tundra - Valiance Keep Flavor - Summon Recruit"),

(-298791, 0, 1, 0, 1, 0, 100, 0, 0, 0, 22000, 23000, 11, 45307, 8, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Generic Quest Trigger - LAB - OOC - Cast Borean Tundra - Valiance Keep Flavor - Queue Global Ping"),

(25307, 0, 0, 0, 19, 0, 100, 0, 11672, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 25317, 0, 0, 0, 0, 0, 0, "Recruitment Officer Blythe - On Quest Accepted (Enlistment Day) - Say Text Line 0 (Creature ID: 25317)"),

(25220, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 48, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Just Summoned - Set Active On"),
(25220, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 25220, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Just Summoned (Link) - Start WP"),
(25220, 0, 2, 0, 8, 0, 100, 0, 45313, 0, 0, 0, 54, 22000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Spellhit - Anchor Here - Pause WP (22000 ms)"),
(25220, 0, 3, 0, 8, 0, 100, 0, 45307, 0, 0, 0, 65, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Spellhit - Borean Tundra - Valiance Keep Flavor - Queue Global Ping - Resume WP"),
(25220, 0, 4, 0, 40, 0, 100, 0, 3, 25220, 0, 0, 11, 45313, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Reached WP3 - Cast 'Anchor Here'"),
(25220, 0, 5, 0, 40, 0, 100, 0, 4, 25220, 0, 0, 11, 45313, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Reached WP4 - Cast 'Anchor Here'"),
(25220, 0, 6, 0, 40, 0, 100, 0, 5, 25220, 0, 0, 11, 45313, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Reached WP5 - Cast 'Anchor Here'"),
(25220, 0, 7, 0, 40, 0, 100, 0, 6, 25220, 0, 0, 11, 45313, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Reached WP6 - Cast 'Anchor Here'"),
(25220, 0, 8, 0, 40, 0, 100, 0, 7, 25220, 0, 0, 11, 45313, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Reached WP7 - Cast 'Anchor Here'"),
(25220, 0, 9, 0, 40, 0, 100, 0, 8, 25220, 0, 0, 11, 45313, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Reached WP8 - Cast 'Anchor Here'"),
(25220, 0, 10, 0, 40, 0, 100, 0, 9, 25220, 0, 0, 11, 45313, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Reached WP9 - Cast 'Anchor Here'"),
(25220, 0, 11, 0, 40, 0, 100, 0, 10, 25220, 0, 0, 11, 45313, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Reached WP10 - Cast 'Anchor Here'"),
(25220, 0, 12, 0, 40, 0, 100, 0, 11, 25220, 0, 0, 11, 45313, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Reached WP11 - Cast 'Anchor Here'"),
(25220, 0, 13, 14, 40, 0, 100, 0, 12, 25220, 0, 0, 54, 18000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Reached WP11 - Cast 'Anchor Here'"),
(25220, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 87, 25220*100, 2522*100+001, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Reached WP11 - Start Random Script"), 
(25220, 0, 15, 0, 40, 0, 100, 0, 15, 25220, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Reached WP15 - Despawn Self"),

(25220*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 25222, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Script - Say Text Line 0 (Creature ID: 25222)"),
(25220*100, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Script - Say Text Line 0"),
(25220*100, 9, 2, 0, 0, 0, 100, 0, 6000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 25222, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Script - Say Text Line 1 (Creature ID: 25222)"),
(25220*100, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Script - Equip Items"),
(25220*100, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 65, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Script - Resume WP"),
(25220*100, 9, 5, 0, 0, 0, 100, 0, 4000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 25222, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Script - Say Text Line 3 (Creature ID: 25222)"),

(25220*100+01, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 25222, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Script - Say Text Line 0 (Creature ID: 25222)"),
(25220*100+01, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Script - Say Text Line 0"),
(25220*100+01, 9, 2, 0, 0, 0, 100, 0, 6000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 25222, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Script - Say Text Line 2 (Creature ID: 25222)"),
(25220*100+01, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 71, 0, 0, 2178, 143, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Script - Equip Items"),
(25220*100+01, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 65, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Script - Resume WP"),
(25220*100+01, 9, 5, 0, 0, 0, 100, 0, 4000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 25222, 0, 0, 0, 0, 0, 0, "Civilian Recruit - On Script - Say Text Line 3 (Creature ID: 25222)");
