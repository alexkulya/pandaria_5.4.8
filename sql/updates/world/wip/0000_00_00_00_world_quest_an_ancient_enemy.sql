UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 38326;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38300, 38326, 38301) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(38300, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spitescale Wavethrasher - On Respawn - Set React State Aggressive"),
(38300, 0, 1, 0, 0, 0, 100, 0, 4000, 5000, 17000, 23000, 11, 79810, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Spitescale Wavethrasher - In Combat - Cast Spell 'Frost Cleave'"),

(38326, 0, 0, 0, 0, 0, 100, 0, 3400, 4700, 3400, 4700, 11, 73212, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Darkspear Shaman - In Combat - Cast Spell 'Lightning Bolt'"),
(38326, 0, 1, 0, 2, 0, 100, 0, 0, 40, 14000, 21000, 11, 72014, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darkspear Shaman - At 40% HP - Cast Spell 'Chain Heal'"),

(38301, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Spitescale Siren - On Respawn - Set React State Aggressive"),
(38301, 0, 1, 0, 9, 0, 100, 0, 0, 40, 3400, 4700, 11, 32011, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Spitescale Siren - On Close 0-40 Yards - Cast Spell 'Chain Lightning'"),
(38301, 0, 2, 0, 0, 0, 100, 0, 5000, 8000, 22000, 24000, 11, 15117, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Spitescale Siren - In Combat - Cast Spell 'Water Bolt'"),
(38301, 0, 3, 0, 38, 0, 100, 0, 1, 1, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, "Spitescale Siren - On Data Set 1 1 - Start Attack");

UPDATE `creature_template_addon` SET `auras` = "91218" WHERE `entry` = 38306;

UPDATE `creature_template` SET `unit_flags` = 0 WHERE `entry` IN (38225, 38306, 38437, 38423, 38542);
UPDATE `creature_template` SET `speed_walk` = 0.001, `speed_run` = 0.001 WHERE `entry` = 38306;
UPDATE `creature_template` SET `faction_A` = 2102, `faction_H` = 2102 WHERE `entry` = 38300;
UPDATE `creature_template` SET `faction_A` = 2224, `faction_H` = 2224 WHERE `entry` = 38302;

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` IN (38423, 38225, 38437, 38306, 38542, 38302);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38423, 38225, 38437, 38306, 38542, 38302, -252718) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3842300, 3842301, 3822500, 3822501, 3830600, 3830601, 3830602, 3830603, 3843700, 3843701, 3843702) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(38423, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Respawn - Set Unit Flags (768)"),
(38423, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Respawn (Link) - Set Run Off"),
(38423, 0, 3, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 3842300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Data Set 1 1 - Start Script"),
(38423, 0, 4, 0, 0, 0, 100, 0, 1000, 1000, 8000, 8000, 11, 73255, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Zuni - In Combat - Cast Spell 'Earth Shock'"),
(38423, 0, 5, 0, 0, 0, 100, 0, 4000, 4000, 14000, 14000, 11, 73254, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Zuni - In Combat - Cast Spell 'Lightning Bolt'"),

(3842300, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Remove Flag Sitting"),
(3842300, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -730.031, -5594.71, 25.6244, 0, "Zuni - On Script - Move To Position"),
(3842300, 9, 2, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Set Home Position"),
(3842300, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Combat Movement Stop"),
(3842300, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zuni - On Script - Remove Unit Flags (768)"),
(3842300, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Zuni - On Script - Start Attack Creature ID: 38306, Distance 100 Yards"),

(38225, 0, 0, 0, 62, 0, 100, 0, 11020, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Gossip Select - Close Gossip"),
(38225, 0, 1, 0, 62, 0, 100, 0, 11020, 0, 0, 0, 53, 0, 38225, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Gossip Select - WP Start"),
(38225, 0, 2, 0, 62, 0, 100, 0, 11020, 0, 0, 0, 33, 38225, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Gossip Select - Quest Credit 1"),
(38225, 0, 3, 0, 62, 0, 100, 0, 11020, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 38437, 100, 0, 0, 0, 0, 0, "Vol'jin - On Gossip Select - Set Data 1 1 (Creature ID: 38437)"),
(38225, 0, 4, 0, 62, 0, 100, 0, 11020, 0, 0, 0, 81, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Gossip Select - Remove Npc Flag Quest Giver"),
(38225, 0, 5, 0, 40, 0, 100, 0, 1, 38225, 0, 0, 80, 3822500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On WP 1 Reached - Start Script"),
(38225, 0, 6, 0, 38, 0, 100, 0, 1, 1, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Vol'jin - On Data Set 1 1 - Start Attack Creature ID: 38306, Distance 100 Yards"),
(38225, 0, 7, 0, 0, 0, 100, 0, 2000, 2000, 2000, 2000, 11, 6660, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Vol'jin - In Combat - Cast Spell 'Shoot'"),
(38225, 0, 8, 0, 0, 0, 100, 0, 20000, 30000, 20000, 30000, 11, 73087, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Vol'jin - In Combat - Cast Spell 'Shadow Shock'"),

(3822500, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Script - Set Home Position"),
(3822500, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Script - Say Text Line 0"),
(3822500, 9, 2, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Vol'jin - On Script - Set Data 1 1 (Creature ID: 38306)"),
(3822500, 9, 3, 0, 0, 0, 100, 0, 400, 400, 0, 0, 17, 333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vol'jin - On Script - Set Emote State (333)"),
(3822500, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 252718, 38423, 0, 0, 0, 0, 0, "Vol'jin - On Script - Set Data 1 1 (Creature ID: 38423)"),

(38437, 0, 0, 0, 38, 0, 100, 0, 1, 1, 0, 0, 53, 0, 38437, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Data Set 1 1 - Start WP"),
(38437, 0, 1, 2, 40, 0, 100, 0, 1, 38437, 0, 0, 17, 333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On WP 1 Reached - Set Emote State (333)"),
(38437, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 101, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On WP 1 Reached (Link) - Set Home Position"),
(38437, 0, 3, 4, 38, 0, 100, 0, 2, 2, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 38306, 100, 0, 0, 0, 0, 0, "Vanira - On Data Set 2 2 - Start Attack Creature ID: 38306, Distance 100 Yards"),
(38437, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - On Data Set 2 2 (Link) - Say Text Line 0"),
(38437, 0, 5, 0, 0, 0, 100, 0, 0, 0, 600000, 600000, 11, 71984, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - In Combat - Cast Spell 'Healing Stream Totem'"),
(38437, 0, 6, 0, 0, 0, 100, 0, 1000, 1000, 600000, 600000, 11, 73393, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - In Combat - Cast Spell 'Mana Stream Totem'"),
(38437, 0, 7, 0, 0, 0, 100, 0, 2000, 2000, 65000, 65000, 11, 71974, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Vanira - In Combat - Cast Spell 'Serpent Ward'"),

(38306, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Respawn - Set React State Defensive"),
(38306, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Respawn (Link) - Set Unit Flags (768)"),
(38306, 0, 2, 0, 0, 0, 100, 0, 0, 0, 3000, 3000, 11, 46987, 0, 0, 0, 0, 0, 10, 252717, 38225, 0, 0, 0, 0, 0, "Zar'jira - In Combat - Cast Spell 'Frostbolt'"),
(38306, 0, 3, 0, 0, 0, 100, 0, 7000, 7000, 15000, 20000, 87, 3830601, 3830602, 3830603, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - In Combat - Start Random Script"),
(38306, 0, 4, 0, 38, 0, 100, 0, 1, 1, 0, 0, 80, 3830600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Data Set 1 1 - Start Script"),

(3830600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Script - Say Text Line 0"),
(3830600, 9, 1, 0, 0, 0, 100, 0, 16000, 16000, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Script - Remove Unit Flags (768)"),
(3830600, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Script - Combat Movement Stop"),
(3830600, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 2224, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Zar'jira - On Script - Set Faction (2224)"),
(3830600, 9, 4, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 38301, 40, 0, 0, 0, 0, 0, "Zar'jira - On Script - Set Data 1 1 (Creature ID: 38301)"),
(3830600, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 11, 38437, 100, 0, 0, 0, 0, 0, "Zar'jira - On Script - Set Data 2 2 (Creature ID: 38437)"),
(3830600, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 38225, 100, 0, 0, 0, 0, 0, "Zar'jira - On Script - Set Data 1 1 (Creature ID: 38225)"),

(3830601, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 38302, 1, 60000, 0, 0, 0, 8, 0, 0, 0, -742.144, -5579.74, 28, 5.6357, "Zar'jira - On Script - Summon Creature"),

(3830602, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 38302, 1, 60000, 0, 0, 0, 8, 0, 0, 0, -703.477, -5590.16, 28, 3.4007, "Zar'jira - On Script - Summon Creature"),

(3830603, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 38302, 6, 10000, 1, 0, 0, 8, 0, 0, 0, -699.04, -5595.67, 25.755, 0, "Zar'jira - On Script - Summon Creature"),

(38302, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Manifestation of the Sea Witch - On Respawn - Set React State Aggressive"),
(38302, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 50, 0, 0, 0, 0, 0, 0, "Manifestation of the Sea Witch - On Summmoned - Attack Start"),
(38302, 0, 2, 0, 0, 0, 100, 0, 7000, 7000, 10000, 10000, 11, 73432, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Manifestation of the Sea Witch - In Combat - Cast Spell 'Soul Scar'"),
(38302, 0, 3, 0, 6, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Manifestation of the Sea Witch - On Death - Despawn (1000 ms)");

DELETE FROM `creature_text` WHERE `entry` IN (38225, 38306, 38423, 38437);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `text_range`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38225, 0, 0, "Ya were foolish to come 'ere, Sea Witch. Ya escaped our vengeance once, but the Darkspear Tribe will not abide ya trespassin' again.", "", 0, 14, 0, 100, 1, 0, 20119, "Vol'jin"),
(38225, 1, 0, "She's drawing power from the fires! Stamp out the braziers, quickly!", "", 0, 41, 0, 100, 0, 0, 0, "Vol'jin"),
(38225, 2, 0, "It be done. Our ancient enemy is defeated.", "", 0, 12, 0, 100, 1, 0, 20121, "Vol'jin"),
(38225, 3, 0, "I been waitin' a long time for a chance to avenge my father. A great weight has been lifted from my shoulders.", "", 0, 12, 0, 100, 1, 0, 20122, "Vol'jin"),
(38225, 4, 0, "I must be returnin' ta Darkspear Hold. Please meet me there once Vanira is done with her healin' of the boy.", "", 0, 12, 0, 100, 1, 0, 20123, "Vol'jin"),

(38306, 0, 0, "", "You are weak Vol'jin, like your father was weak. Today I will finish what I started long ago - the Darkspear shall be wiped from existence!", 0, 14, 0, 100, 1, 0, 21810, "Zar'jira"),
(38306, 1, 0, "", "No! I will make your death slow and painful, little trolls.", 0, 14, 0, 100, 0, 0, 21813, "Zar'jira"),
(38306, 2, 0, "", "Not so fast, little troll!", 0, 14, 0, 100, 1, 0, 21815, "Zar'jira"),

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
