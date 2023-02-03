UPDATE `quest_template` SET `RewardSpellCast` = 0, `Flags` = 2621440 WHERE `Id` = 24959;
UPDATE `creature_template` SET `InhabitType` = 4, `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 49044;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 49044 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(49044, 0, 0, 1, 19, 0, 100, 0, 24959, 0, 0, 0, 11, 73524, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Agatha - On Quest Accept (24959) - Cast Spell 'Val'kyr Resurrection'"),
(49044, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 73523, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Agatha - On Quest Accept (24959) (Link) - Remove Aura 'Rigor Mortis'");

DELETE FROM `creature_template_addon` WHERE `entry` = 49044;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `auras`) VALUES
(49044, 50397184, 4097, "49414");

UPDATE `quest_template` SET `DetailsEmote1` = 1, `DetailsEmote2` = 1 WHERE `Id` = 24959;

UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 49129;
UPDATE `creature` SET `movement_type` = 2, `wander_distance` = 0 WHERE `guid` = 192757 AND `id` = 49129;
UPDATE `creature_addon` SET `path_id` = 192757, `bytes2` = 1 WHERE `guid` = 192757;
DELETE FROM `waypoint_data` WHERE `id` = 192757;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `entry`) VALUES
(192757, 1, 1725.01, 1667.63, 137.94, 0, 0, 1, 49129),
(192757, 2, 1710.03, 1656.84, 140.835, 0, 0, 1, 49129),
(192757, 3, 1698.03, 1652.92, 146.397, 0, 0, 1, 49129),
(192757, 4, 1702.94, 1634.51, 140.377, 0, 0, 1, 49129),
(192757, 5, 1716.34, 1617.19, 134.848, 0, 0, 1, 49129),
(192757, 6, 1731.1, 1618.59, 133.88, 0, 0, 1, 49129),
(192757, 7, 1747.64, 1639.03, 128.976, 0, 0, 1, 49129),
(192757, 8, 1746.05, 1657.5, 131.738, 0, 0, 1, 49129),
(192757, 9, 1744.97, 1676.7, 139.807, 0, 0, 1, 49129),
(192757, 10, 1737.38, 1689.39, 142.346, 0, 0, 1, 49129),
(192757, 11, 1721.84, 1699.9, 145.727, 0, 0, 1, 49129),
(192757, 12, 1702.88, 1701.67, 147.952, 0, 0, 1, 49129),
(192757, 13, 1684.23, 1697.14, 151.702, 0, 0, 1, 49129),
(192757, 14, 1679.76, 1677.61, 157.186, 0, 0, 1, 49129),
(192757, 15, 1688.75, 1665.62, 152.315, 0, 0, 1, 49129),
(192757, 16, 1706.31, 1666.57, 144.594, 0, 0, 1, 49129),
(192757, 17, 1721.01, 1675.69, 138.709, 0, 0, 1, 49129);

UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 49128;
UPDATE `creature` SET `movement_type` = 2, `wander_distance` = 0 WHERE `guid` = 192760 AND `id` = 49128;
DELETE FROM `creature_addon` WHERE `guid` = 192760;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`) VALUES
(192760, 192760, 50331648, 1);
DELETE FROM `waypoint_data` WHERE `id` = 192760;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `entry`) VALUES
(192760, 1, 1757.78, 1593.55, 116.917, 0, 0, 1, 49128),
(192760, 2, 1758.89, 1604.89, 127.626, 0, 0, 1, 49128),
(192760, 3, 1754.94, 1620.19, 131.002, 0, 0, 1, 49128),
(192760, 4, 1741.96, 1635.04, 141.067, 0, 0, 1, 49128),
(192760, 5, 1722.93, 1649.94, 144.151, 0, 0, 1, 49128),
(192760, 6, 1703.4, 1655.41, 156.222, 0, 0, 1, 49128),
(192760, 7, 1683.45, 1647.61, 158.232, 0, 0, 1, 49128),
(192760, 8, 1678.86, 1635.12, 154.974, 0, 0, 1, 49128),
(192760, 9, 1681.15, 1625.05, 153.188, 0, 0, 1, 49128),
(192760, 10, 1699.46, 1616.94, 146.098, 0, 0, 1, 49128),
(192760, 11, 1701.61, 1601.05, 142.797, 0, 0, 1, 49128),
(192760, 12, 1697.91, 1578.1, 144.346, 0, 0, 1, 49128),
(192760, 13, 1705.4, 1557.76, 143.995, 0, 0, 1, 49128),
(192760, 14, 1719.17, 1551.01, 136.678, 0, 0, 1, 49128),
(192760, 15, 1736.93, 1555, 129.218, 0, 0, 1, 49128),
(192760, 16, 1746.94, 1565.07, 123.072, 0, 0, 1, 49128),
(192760, 17, 1755.16, 1577.36, 119.816, 0, 0, 1, 49128);

UPDATE `creature` SET `movement_type` = 2, `wander_distance` = 0, `position_x` = 1674.95, `position_y` = 1683.32, `position_z` = 139.203 WHERE `guid` = 192759 AND `id` = 50372;
UPDATE `creature_template` SET `InhabitType` = 4, `AIName` = "", `ScriptName` = "npc_aradne" WHERE `entry` = 50372;

DELETE FROM `creature_addon` WHERE `guid` = 192759;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`) VALUES
(192759, 192759, 50331648, 1);

DELETE FROM `waypoint_data` WHERE `id` = 192759;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `entry`) VALUES
(192759, 1, 1674.95, 1683.32, 143.203, 0, 0, 0, 50372),
(192759, 2, 1676.98, 1681.87, 142.799, 0, 0, 0, 50372),
(192759, 3, 1679.82, 1681.69, 142.267, 0, 0, 0, 50372),
(192759, 4, 1681.72, 1683.03, 141.959, 0, 0, 0, 50372),
(192759, 5, 1683.93, 1685.34, 141.606, 0, 10000, 0, 50372),
(192759, 6, 1686.35, 1686.91, 141.154, 0, 0, 0, 50372),
(192759, 7, 1688.19, 1690.18, 140.926, 0, 0, 0, 50372),
(192759, 8, 1689.24, 1693.53, 140.947, 0, 0, 0, 50372),
(192759, 9, 1691.95, 1695.14, 140.673, 0, 0, 0, 50372),
(192759, 10, 1695.06, 1695.14, 140.008, 0, 0, 0, 50372),
(192759, 11, 1697.34, 1693.19, 139.244, 0, 0, 0, 50372),
(192759, 12, 1698, 1691.2, 139.049, 0, 0, 0, 50372),
(192759, 13, 1698.51, 1688.87, 138.864, 0, 10000, 0, 50372),
(192759, 14, 1698.55, 1685.78, 138.671, 0, 0, 0, 50372),
(192759, 15, 1698.47, 1683.06, 138.616, 0, 0, 0, 50372),
(192759, 16, 1697.66, 1680.8, 138.579, 0, 10000, 0, 50372),
(192759, 17, 1699.37, 1684.32, 138.532, 0, 0, 0, 50372),
(192759, 18, 1702.7, 1690.31, 138.334, 0, 0, 0, 50372),
(192759, 19, 1704.96, 1695.01, 138.167, 0, 0, 0, 50372),
(192759, 20, 1706.95, 1696.84, 137.934, 0, 0, 0, 50372),
(192759, 21, 1707.11, 1700.6, 138.225, 0, 10000, 0, 50372),
(192759, 22, 1710.43, 1700.99, 137.2, 0, 0, 0, 50372),
(192759, 23, 1716.15, 1701.67, 135.765, 0, 0, 0, 50372),
(192759, 24, 1721.19, 1702.27, 134.121, 0, 0, 0, 50372),
(192759, 25, 1726.76, 1703.41, 132.53, 0, 0, 0, 50372),
(192759, 26, 1730.24, 1703.47, 132.115, 0, 0, 0, 50372),
(192759, 27, 1733.31, 1703.32, 132.178, 0, 10000, 0, 50372),
(192759, 28, 1726.35, 1702.37, 132.503, 0, 0, 0, 50372),
(192759, 29, 1719.89, 1698.69, 134.855, 0, 0, 0, 50372),
(192759, 30, 1710.81, 1691.48, 137.626, 0, 0, 0, 50372),
(192759, 31, 1703.63, 1685.48, 138.024, 0, 0, 0, 50372),
(192759, 32, 1697.91, 1681.32, 138.569, 0, 10000, 0, 50372),
(192759, 33, 1698.1, 1683.77, 138.69, 0, 0, 0, 50372),
(192759, 34, 1698.15, 1688.19, 138.898, 0, 10000, 0, 50372),
(192759, 35, 1699.09, 1691.26, 138.879, 0, 0, 0, 50372),
(192759, 36, 1701.96, 1695.36, 138.619, 0, 0, 0, 50372),
(192759, 37, 1705.86, 1696.63, 138.068, 0, 0, 0, 50372),
(192759, 38, 1706.74, 1700.46, 138.263, 0, 10000, 0, 50372),
(192759, 39, 1700.76, 1698.66, 139.131, 0, 0, 0, 50372),
(192759, 40, 1696.39, 1697.44, 139.9, 0, 0, 0, 50372),
(192759, 41, 1691.82, 1695.35, 140.723, 0, 0, 0, 50372),
(192759, 42, 1687.56, 1692.08, 141.147, 0, 0, 0, 50372),
(192759, 43, 1686.83, 1690.55, 141.241, 0, 0, 0, 50372);

DELETE FROM `creature_text` WHERE `entry` = 50372;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(50372, 0, 0, "", "Rise from the grave and serve the Dark Lady!", 12, 0, 100, 1, 0, 0, "Aradne"),
(50372, 0, 1, "", "In the name of Sylvanas, the Banshee Queen, I bestow this gift upon you!", 12, 0, 100, 1, 0, 0, "Aradne"),
(50372, 0, 2, "", "Rise from death's slumber and join your brothers!", 12, 0, 100, 1, 0, 0, "Aradne"),
(50372, 0, 3, "", "Waken, sleeper. Your new life awaits.", 12, 0, 100, 1, 0, 0, "Aradne"),
(50372, 0, 4, "", "You are returned to life. The Banshee Queen asks for your service.", 12, 0, 100, 1, 0, 0, "Aradne");

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_deathknell_grave_target" WHERE `entry` = 50373;

DELETE FROM `conditions` WHERE `SourceEntry` = 93446 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 93446, 0, 0, 31, 0, 3, 50373, 0, 0, 0, "", "Raise Undead target Deathknell Grave Target");

UPDATE `creature` SET `movement_type` = 0, `wander_distance` = 0 WHERE `id` = 50373;

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_risen_dead" WHERE `entry` = 50374;
DELETE FROM `creature_text` WHERE `entry` = 50374;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(50374, 0, 0, "What... what's happening to me? Why have you done this to me?", "", 12, 0, 100, 6, 0, 0, "Risen Dead"),
(50374, 1, 0, "I should be dead and to death I will return!", "", 12, 0, 100, 5, 0, 0, "Risen Dead"),
(50374, 2, 0, "I never asked for this! Leave me alone!", "", 12, 0, 100, 5, 0, 0, "Risen Dead"),
(50374, 3, 0, "What magic is this that turns back the hand of death?", "", 12, 0, 100, 6, 0, 0, "Risen Dead"),
(50374, 4, 0, "If the Banshee Queen has offered me this chance, I will gladly serve.", "", 12, 0, 100, 1, 0, 0, "Risen Dead"),
(50374, 5, 0, "This is Lady Sylvanas's doing?", "", 12, 0, 100, 6, 0, 0, "Risen Dead"),
(50374, 6, 0, "What use has the Dark Lady for me?", "", 12, 0, 100, 6, 0, 0, "Risen Dead"),
(50374, 7, 0, "I... I don't remember... Why have you done this?", "", 12, 0, 100, 6, 0, 0, "Risen Dead"),
(50374, 8, 0, "%s commits suicide.", "", 16, 0, 100, 0, 0, 0, "Risen Dead"),
(50374, 9, 0, "%s enrages and transforms into a Mindless Zombie and runs away.", "", 16, 0, 100, 0, 0, 0, "Risen Dead"),
(50374, 10, 0, "%s walks off towards the barracks.", "", 16, 0, 100, 0, 0, 0, "Risen Dead");

DELETE FROM `creature` WHERE `guid` IN (193857, 193848, 193854, 193855, 193850);
DELETE FROM `creature_addon` WHERE `guid` IN (193857, 193848, 193854, 193855, 193850);

DELETE FROM `waypoint_data` WHERE `id` IN (50374*100, 50374*100+01);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `entry`) VALUES
(50374*100, 1, 1702, 1677.55, 134.298, 0, 0, 1, 50374),
(50374*100, 2, 1693.66, 1670.64, 134.032, 0, 0, 1, 50374),
(50374*100, 3, 1686.21, 1661.74, 133.171, 0, 0, 1, 50374),
(50374*100, 4, 1681.66, 1655.15, 136.316, 0, 0, 1, 50374),
(50374*100, 5, 1676.76, 1643.16, 139.253, 0, 0, 1, 50374),
(50374*100, 6, 1669.11, 1631.08, 139.495, 0, 0, 1, 50374),
(50374*100, 7, 1664.203, 1620.63, 140.526, 0, 0, 1, 50374),

(50374*100+01, 1, 1695.44, 1672.29, 133.945, 0, 0, 0, 50374),
(50374*100+01, 2, 1691.08, 1660.22, 131.406, 0, 0, 0, 50374),
(50374*100+01, 3, 1709.56, 1643.45, 124.713, 0, 0, 0, 50374),
(50374*100+01, 4, 1723.48, 1633.31, 120.426, 0, 0, 0, 50374);

UPDATE `creature_template` SET `ScriptName` = "npc_mindless_zombie" WHERE `entry` = 1501;
UPDATE `creature` SET `wander_distance` = 5, `movement_type` = 1 WHERE `id` = 1501;

UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 20725;

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_undertaker_mordo" WHERE `entry` = 1568;

DELETE FROM `waypoint_data` WHERE `id` IN (50414*100, 50414*100+01);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `entry`) VALUES
(50414*100, 1, 1694.16, 1677.08, 134.786, 0, 0, 0, 50414),
(50414*100, 2, 1691.29, 1675.84, 135.295, 0, 0, 0, 50414),

(50414*100+01, 1, 1691.29, 1675.85, 135.295, 0, 0, 0, 50414),
(50414*100+01, 2, 1690.59, 1661.87, 131.92, 0, 0, 0, 50414),
(50414*100+01, 3, 1719.38, 1633.98, 121.065, 0, 0, 0, 50414);

DELETE FROM `creature_text` WHERE `entry` IN (1568, 50414);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(1568, 0, 0, "Let's see, I just saw a corpse with a jaw that would fit you...", "", 12, 0, 100, 0, 0, 0, "Undertaker Mordo"),
(1568, 1, 0, "That should do the job. Come back right away if it falls off again.", "", 12, 0, 100, 0, 0, 0, "Undertaker Mordo"),

(50414, 0, 0, "T-thank you, Under-t-taker.", "", 12, 0, 100, 0, 0, 0, "Risen Recruit");

UPDATE `creature_template` SET `ScriptName` = "npc_darnell" WHERE `entry` = 49141;

DELETE FROM `creature_text` WHERE `entry` = 49141;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(49141, 0, 0, "Greetings, $n.", "", 12, 0, 100, 3, 0, 0, "Darnell"),
(49141, 1, 0, "The Shadow Grave is this way.  Follow me, $n.", "", 12, 0, 100, 1, 0, 0, "Darnell"),
(49141, 2, 0, "This way!", "", 12, 0, 100, 1, 0, 0, "Darnell"),
(49141, 3, 0, "Now, where could those supplies be?", "", 12, 0, 100, 1, 0, 0, "Darnell"),
(49141, 4, 0, "Maybe they're over here?", "", 12, 0, 100, 1, 0, 0, "Darnell"),
(49141, 5, 0, "Hmm...", "", 12, 0, 100, 1, 0, 0, "Darnell"),
(49141, 6, 0, "No, not over here.", "", 12, 0, 100, 1, 0, 0, "Darnell"),
(49141, 7, 0, "Hey, give me a hand, $n!  I can't find the supplies that Mordo needed!", "", 12, 0, 100, 1, 0, 0, "Darnell"),
(49141, 8, 0, "Let's see now... where could they be...", "", 12, 0, 100, 1, 0, 0, "Darnell"),
(49141, 9, 0, "Nice work!  You've found them.  Let's bring these back to Mordo.", "", 12, 0, 100, 1, 0, 0, "Darnell"),
(49141, 10, 0, "I saw someone up there whose jaw fell off.  I wonder if Mordo can fix him up?", "", 12, 0, 100, 1, 0, 0, "Darnell");

DELETE FROM `disables` WHERE `entry` = 49141 AND `sourceType` = 10;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(10, 49141, 1, "", "", "Darnell - MMAP");

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_vile_fin_puddlejumper" WHERE `entry` = 1543;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_vile_fin_minor_oracle" WHERE `entry` = 1544;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_sedrick_calston" WHERE `entry` = 38925;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_captured_vile_fin_puddlejumper" WHERE `entry` = 38923;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_captured_vile_fin_minor_oracle" WHERE `entry` = 39078;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1543, 1544) AND `source_type` = 0;
DELETE FROM `spell_script_names` WHERE `spell_id` = 73108;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(73108, "spell_murloc_leash");

DELETE FROM `creature_text` WHERE `entry` IN (1543, 1544);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(1543, 0, 0, "The %s is ready to be captured!", "", 16, 0, 100, 0, 0, 0, "Vile Fin Puddlejumper"),

(1544, 0, 0, "The %s is ready to be captured!", "", 16, 0, 100, 0, 0, 0, "Vile Fin Minor Oracle");

-- Marshal Redpath
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_marshal_redpath", `gossip_menu_id` = 12485 WHERE `entry` = 49230;
UPDATE `creature` SET `orientation` = 5.8555, `spawntimesecs` = 60 WHERE `id` = 49230;

DELETE FROM `creature_text` WHERE `entry` = 49230;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(49230, 0, 0, "BLEEAAAGGHHH! I'm a monster, don't look at me!", "", 12, 0, 100, 1, 0, 0, "Marshal Redpath"),
(49230, 0, 1, "Who are you calling a monster? You're the monster! I'm just a man who died.", "", 12, 0, 100, 1, 0, 0, "Marshal Redpath");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 49230 AND `source_type` = 0;

DELETE FROM `waypoint_data` WHERE `id` = 49230*100;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`) VALUES
(49230*100, 1, 1752.72, 1626.94, 116.001, 0, 0, 1),
(49230*100, 2, 1758.17, 1604.42, 110.959, 0, 0, 1),
(49230*100, 3, 1756.88, 1585.49, 111.543, 0, 0, 1),
(49230*100, 4, 1751.61, 1564.8, 113.489, 0, 0, 1),
(49230*100, 5, 1752.27, 1548.56, 113.92, 0, 0, 1),
(49230*100, 6, 1763.14, 1538.02, 114.346, 0, 0, 1);

UPDATE `gossip_menu_option` SET `action_menu_id` = 12486 WHERE `menu_id` = 12485;
UPDATE `gossip_menu_option` SET `npc_option_npcflag` = 1 WHERE `menu_id` = 12486;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 12485;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,12485,0,0,9,24960,0,0,0,"","Show gossip if player has quest: The wakening");

-- Lilian Voss
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_lilian_voss", `gossip_menu_id` = 12483 WHERE `entry` = 38895;
UPDATE `creature` SET `spawntimesecs` = 60 WHERE `id` = 38895;

DELETE FROM `creature_text` WHERE `entry` = 38895;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38895, 0, 0, "", "No. You're lying! My father will protect me!", 12, 0, 100, 1, 0, 0, "Lilian Voss"),
(38895, 0, 1, "", "You don't understand... I CAN'T be undead! Not me, not now...", 12, 0, 100, 22, 0, 0, "Lilian Voss");

DELETE FROM `creature_template_addon` WHERE `entry` = 38895;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `emote`) VALUES
(38895, 4097, 431);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 38895 AND `source_type` = 0;

DELETE FROM `waypoint_data` WHERE `id` = 38895*100;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`) VALUES
(38895*100, 1, 1752.21, 1652.93, 119.551, 0, 0, 1),
(38895*100, 2, 1752.72, 1635.44, 116.883, 0, 0, 1),
(38895*100, 3, 1755.51, 1611.9, 112.498, 0, 0, 1),
(38895*100, 4, 1756.03, 1591.45, 111.872, 0, 0, 1),
(38895*100, 5, 1755.69, 1570.22, 112.78, 0, 0, 1),
(38895*100, 6, 1751.78, 1550.02, 114.082, 0, 0, 1),
(38895*100, 7, 1762.13, 1539.01, 114.289, 0, 0, 1);

UPDATE `gossip_menu_option` SET `action_menu_id` = 12484 WHERE `menu_id` = 12483;
UPDATE `gossip_menu_option` SET `npc_option_npcflag` = 1 WHERE `menu_id` = 12484;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 12483;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,12483,0,0,9,24960,0,0,0,"","Show gossip if player has quest: The wakening");

-- Valdred Moray
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_valdred_moray", `gossip_menu_id` = 12487 WHERE `entry` = 49231;
UPDATE `creature` SET `spawntimesecs` = 60 WHERE `id` = 49231;

DELETE FROM `creature_text` WHERE `entry` = 49231;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(49231, 0, 0, "Valdred Moray, reporting for duty, sir!", "", 14, 0, 100, 66, 0, 0, "Valdred Moray"),
(49231, 0, 1, "I see. Well then, let's get to work, $n! The Dark Lady needs us, right?", "", 12, 0, 100, 1, 0, 0, "Valdred Moray");

DELETE FROM `creature_template_addon` WHERE `entry` = 49231;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`) VALUES
(49231, 8, 4097);

DELETE FROM `smart_scripts` WHERE `entryorguid` = 49231 AND `source_type` = 0;

DELETE FROM `waypoint_data` WHERE `id` = 49231*100;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`) VALUES
(49231*100, 1, 1728.97, 1696.68, 127.857, 0, 0, 0),
(49231*100, 2, 1716.91, 1690.64, 132.728, 0, 0, 0),
(49231*100, 3, 1707.91, 1685.12, 133.644, 0, 0, 0),
(49231*100, 4, 1695.44, 1677.7, 134.632, 0, 0, 0);

UPDATE `gossip_menu_option` SET `action_menu_id` = 12488 WHERE `menu_id` = 12487;
UPDATE `gossip_menu_option` SET `action_menu_id` = 12489 WHERE `menu_id` = 12488;
UPDATE `gossip_menu_option` SET `npc_option_npcflag` = 1 WHERE `menu_id` IN (12488, 12489);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 12487;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,12487,0,0,9,24960,0,0,0,"","Show gossip if player has quest: The wakening");

-- Faerie Dragon Event (Full)
UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 318974 AND `id` = 51966;

UPDATE `creature` SET `position_x` = 1765.84, `position_y` = 2205.46, `position_z` = 148.782, `orientation` = 0.78, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 318968;
UPDATE `creature` SET `position_x` = 1733.86, `position_y` = 2239.33, `position_z` = 150.096, `orientation` = 0.01, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 318969;
UPDATE `creature` SET `position_x` = 1756.01, `position_y` = 2279.27, `position_z` = 149.163, `orientation` = 5.5, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 318970;
UPDATE `creature` SET `position_x` = 1821.38, `position_y` = 2298.49, `position_z` = 144.901, `orientation` = 4.18, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 318976;
UPDATE `creature` SET `position_x` = 1865.11, `position_y` = 2269.06, `position_z` = 145.072, `orientation` = 3.63, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 318977;
UPDATE `creature` SET `position_x` = 1857.66, `position_y` = 2210.51, `position_z` = 143.898, `orientation` = 2.72, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 318978;
UPDATE `creature` SET `position_x` = 1813.91, `position_y` = 2174.47, `position_z` = 143.531, `orientation` = 1.73, `wander_distance` = 0, `movement_type` = 0 WHERE `guid` = 318979;

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (51963, 51966);
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 51966;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (51966, 51963, -318968, -318969, -318970, -318976, -318977, -318978, -318979) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (51966*100, 51963*100, 51963*100+01, 51963*100+02, 51963*100+03, 51963*100+04, 51963*100+05, 51963*100+06) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(51966, 0, 0, 0, 1, 0, 100, 0, 10000, 10000, 4510000, 4510000, 80, 51966*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Faerie Circle - OOC (Every 75 min) - Start Script"),
(51966, 0, 1, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 96186, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Faerie Circle - On Just Summoned - Cast Spell 'Faerie Circle Wind Chimes'"),

(-318968, 0, 0, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Update - Set Visiblity (0) (No Repeat)"),
(-318968, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 1 1 - Set Visiblity (1)"),
(-318968, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1784.42, 2225.54, 149.007, 0, "Fey-Drunk Darter - On Data Set 1 1 (Link) - Move To Position"),
(-318968, 0, 3, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, 51963*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 2 2 - Start Script"),
(-318968, 0, 4, 5, 38, 0, 100, 0, 3, 3, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 3 3 - Set Visiblity (0)"),
(-318968, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 92, 0, 96184, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Faerie Circle - On Data Set 3 3 (Link) - Interrupt Spell 'Gift of the Heart'"),
(-318968, 0, 6, 7, 61, 0, 100, 0, 0, 0, 0, 0, 92, 0, 96187, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Faerie Circle - On Data Set 3 3 (Link) - Interrupt Spell 'Faerie Dragon's Song'"),
(-318968, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1765.84, 2205.46, 148.782, 0, "Fey-Drunk Darter - On Data Set 3 3 (Link) - Move To Position"),

(-318969, 0, 0, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Update - Set Visiblity (0) (No Repeat)"),
(-318969, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 1 1 - Set Visiblity (1)"),
(-318969, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1781.42, 2242.3, 148.941, 0, "Fey-Drunk Darter - On Data Set 1 1 (Link) - Move To Position"),
(-318969, 0, 3, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, 51963*100+01, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 2 2 - Start Script"),
(-318969, 0, 4, 5, 38, 0, 100, 0, 3, 3, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 3 3 - Set Visiblity (0)"),
(-318969, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 92, 0, 96184, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Faerie Circle - On Data Set 3 3 (Link) - Interrupt Spell 'Gift of the Heart'"),
(-318969, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1733.86, 2239.33, 150.096, 0, "Fey-Drunk Darter - On Data Set 3 3 (Link) - Move To Position"),

(-318970, 0, 0, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Update - Set Visiblity (0) (No Repeat)"),
(-318970, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 1 1 - Set Visiblity (1)"),
(-318970, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1787.99, 2255.03, 149.103, 0, "Fey-Drunk Darter - On Data Set 1 1 (Link) - Move To Position"),
(-318970, 0, 3, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, 51963*100+02, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 2 2 - Start Script"),
(-318970, 0, 4, 5, 38, 0, 100, 0, 3, 3, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 3 3 - Set Visiblity (0)"),
(-318970, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 92, 0, 96184, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Faerie Circle - On Data Set 3 3 (Link) - Interrupt Spell 'Gift of the Heart'"),
(-318970, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1756.01, 2279.27, 149.163, 0, "Fey-Drunk Darter - On Data Set 3 3 (Link) - Move To Position"),

(-318976, 0, 0, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Update - Set Visiblity (0) (No Repeat)"),
(-318976, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 1 1 - Set Visiblity (1)"),
(-318976, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1808.14, 2259.5, 148.599, 0, "Fey-Drunk Darter - On Data Set 1 1 (Link) - Move To Position"),
(-318976, 0, 3, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, 51963*100+03, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 2 2 - Start Script"),
(-318976, 0, 4, 5, 38, 0, 100, 0, 3, 3, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 3 3 - Set Visiblity (0)"),
(-318976, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 92, 0, 96184, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Faerie Circle - On Data Set 3 3 (Link) - Interrupt Spell 'Gift of the Heart'"),
(-318976, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1821.38, 2298.49, 144.901, 0, "Fey-Drunk Darter - On Data Set 3 3 (Link) - Move To Position"),

(-318977, 0, 0, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Update - Set Visiblity (0) (No Repeat)"),
(-318977, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 1 1 - Set Visiblity (1)"),
(-318977, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1821.41, 2247.84, 148.731, 0, "Fey-Drunk Darter - On Data Set 1 1 (Link) - Move To Position"),
(-318977, 0, 3, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, 51963*100+04, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 2 2 - Start Script"),
(-318977, 0, 4, 5, 38, 0, 100, 0, 3, 3, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 3 3 - Set Visiblity (0)"),
(-318977, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 92, 0, 96184, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Faerie Circle - On Data Set 3 3 (Link) - Interrupt Spell 'Gift of the Heart'"),
(-318977, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1865.11, 2269.06, 145.072, 0, "Fey-Drunk Darter - On Data Set 3 3 (Link) - Move To Position"),

(-318978, 0, 0, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Update - Set Visiblity (0) (No Repeat)"),
(-318978, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 1 1 - Set Visiblity (1)"),
(-318978, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1818.87, 2229.71, 148.816, 0, "Fey-Drunk Darter - On Data Set 1 1 (Link) - Move To Position"),
(-318978, 0, 3, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, 51963*100+05, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 2 2 - Start Script"),
(-318978, 0, 4, 5, 38, 0, 100, 0, 3, 3, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 3 3 - Set Visiblity (0)"),
(-318978, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 92, 0, 96184, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Faerie Circle - On Data Set 3 3 (Link) - Interrupt Spell 'Gift of the Heart'"),
(-318978, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1857.66, 2210.51, 143.898, 0, "Fey-Drunk Darter - On Data Set 3 3 (Link) - Move To Position"),

(-318979, 0, 0, 0, 60, 0, 100, 1, 1000, 1000, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Update - Set Visiblity (0) (No Repeat)"),
(-318979, 0, 1, 2, 38, 0, 100, 0, 1, 1, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 1 1 - Set Visiblity (1)"),
(-318979, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1803.93, 2220.34, 148.872, 0, "Fey-Drunk Darter - On Data Set 1 1 (Link) - Move To Position"),
(-318979, 0, 3, 0, 38, 0, 100, 0, 2, 2, 0, 0, 80, 51963*100+06, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 2 2 - Start Script"),
(-318979, 0, 4, 5, 38, 0, 100, 0, 3, 3, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Data Set 3 3 - Set Visiblity (0)"),
(-318979, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 92, 0, 96184, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Faerie Circle - On Data Set 3 3 (Link) - Interrupt Spell 'Gift of the Heart'"),
(-318979, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1813.91, 2174.47, 143.531, 0, "Fey-Drunk Darter - On Data Set 3 3 (Link) - Move To Position"),

(51966*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 318968, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 1 1 (Creature GUID: 318968)"),
(51966*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 318969, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 1 1 (Creature GUID: 318969)"),
(51966*100, 9, 2, 0, 0, 0, 100, 0, 360000, 360000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 318970, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 1 1 (Creature GUID: 318970) (36 sec)"), -- 6 min
(51966*100, 9, 3, 0, 0, 0, 100, 0, 900000, 900000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 318976, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 1 1 (Creature GUID: 318976) (1.5 min)"), -- 15 min
(51966*100, 9, 4, 0, 0, 0, 100, 0, 480000, 480000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 318977, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 1 1 (Creature GUID: 318977) (48 sec)"), -- 8 min
(51966*100, 9, 5, 0, 0, 0, 100, 0, 120000, 120000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 318978, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 1 1 (Creature GUID: 318978) (12 sec)"), -- 2 min
(51966*100, 9, 6, 0, 0, 0, 100, 0, 960000, 960000, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 318979, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 1 1 (Creature GUID: 318979) (1.6 min)"), -- 16 min
(51966*100, 9, 7, 0, 0, 0, 100, 0, 1440000, 1440000, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 318968, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 2 2 (Creature GUID: 318968) (1.73 min)"), -- 24 min
(51966*100, 9, 8, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 318969, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 2 2 (Creature GUID: 318969)"),
(51966*100, 9, 9, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 318970, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 2 2 (Creature GUID: 318970)"),
(51966*100, 9, 10, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 318976, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 2 2 (Creature GUID: 318976)"),
(51966*100, 9, 11, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 318977, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 2 2 (Creature GUID: 318977)"),
(51966*100, 9, 12, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 318978, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 2 2 (Creature GUID: 318978)"),
(51966*100, 9, 13, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, 318979, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 2 2 (Creature GUID: 318979)"),
(51966*100, 9, 14, 0, 0, 0, 100, 0, 500, 500, 0, 0, 11, 96181, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Cast Spell 'Faerie Circle Base'"),
(51966*100, 9, 15, 0, 0, 0, 100, 0, 138000, 138000, 0, 0, 92, 0, 96181, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Interrupt Spell 'Faerie Circle Base' (2.3 min)"),
(51966*100, 9, 16, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, 318968, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 3 3 (Creature GUID: 318968)"),
(51966*100, 9, 17, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, 318969, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 3 3 (Creature GUID: 318969)"),
(51966*100, 9, 18, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, 318970, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 3 3 (Creature GUID: 318970)"),
(51966*100, 9, 19, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, 318976, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 3 3 (Creature GUID: 318976)"),
(51966*100, 9, 20, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, 318977, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 3 3 (Creature GUID: 318977)"),
(51966*100, 9, 21, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, 318978, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 3 3 (Creature GUID: 318978)"),
(51966*100, 9, 22, 0, 0, 0, 100, 0, 200, 200, 0, 0, 45, 3, 3, 0, 0, 0, 0, 10, 318979, 51963, 0, 0, 0, 0, 0, "Faerie Circle - On Script - Set Data 3 3 (Creature GUID: 318979)"),

(51963*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 96187, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Script - Cast Spell 'Faerie Dragon's Song'"),
(51963*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 12, 51966, 3, 138000, 0, 0, 0, 8, 0, 0, 0, 1802.609, 2239.78, 148.9559, 0.2094, "Fey-Drunk Darter - On Script - Summon Creature"),
(51963*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 96184, 0, 0, 0, 0, 0, 10, 318974, 51966, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Script - Cast Spell 'Gift of the Heart' (Creature GUID: 318974)"),

(51963*100+01, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 96184, 0, 0, 0, 0, 0, 10, 318974, 51966, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Script - Cast Spell 'Gift of the Heart' (Creature GUID: 318974)"),
(51963*100+02, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 96184, 0, 0, 0, 0, 0, 10, 318974, 51966, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Script - Cast Spell 'Gift of the Heart' (Creature GUID: 318974)"),
(51963*100+03, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 96184, 0, 0, 0, 0, 0, 10, 318974, 51966, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Script - Cast Spell 'Gift of the Heart' (Creature GUID: 318974)"),
(51963*100+04, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 96184, 0, 0, 0, 0, 0, 10, 318974, 51966, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Script - Cast Spell 'Gift of the Heart' (Creature GUID: 318974)"),
(51963*100+05, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 96184, 0, 0, 0, 0, 0, 10, 318974, 51966, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Script - Cast Spell 'Gift of the Heart' (Creature GUID: 318974)"),
(51963*100+06, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 96184, 0, 0, 0, 0, 0, 10, 318974, 51966, 0, 0, 0, 0, 0, "Fey-Drunk Darter - On Script - Cast Spell 'Gift of the Heart' (Creature GUID: 318974)");

DELETE FROM `conditions` WHERE `SourceEntry` = 96184 AND `SourceTypeOrReferenceId` = 13 AND `SourceGroup` = 1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 96184, 0, 0, 31, 0, 3, 51966, 0, 0, 0, "", "Spell 'Gift of the Heart' target 'Faerie Circle'");

UPDATE `creature_template` SET `faction_A` = 14, `faction_H` = 14 WHERE `entry` = 49422;

DELETE FROM `creature_addon` WHERE `guid` = 193968;
DELETE FROM `waypoint_data` WHERE `id` = 193968;

UPDATE `creature` SET `wander_distance` = 3, `movement_type` = 1 WHERE `id` IN (49422, 49423);
UPDATE `creature_template` SET `ScriptName` = "", `AIName` = "SmartAI" WHERE `entry` IN (49422, 49423);
UPDATE `creature_template` SET `unit_flags` = 33280, `ScriptName` = "", `AIName` = "SmartAI" WHERE `entry` = 49424;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (49422, 49423, 49424) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(49422, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Rotbrain Berserker - On Aggro - Say Text Line 0 (No Repeat)"),
(49422, 0, 1, 2, 2, 0, 100, 1, 0, 30, 0, 0, 11, 63227, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Rotbrain Berserker - 0-30% HP - Cast Spell 'Enrage' (No Repeat)"),
(49422, 0, 2, 0, 61, 0, 100, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Rotbrain Berserker - 0-30% HP (Link) - Say Text Line 1 (No Repeat)"),
(49422, 0, 3, 0, 0, 0, 100, 0, 4000, 7000, 15000, 18000, 11, 79881, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Rotbrain Berserker - In Combat - Cast Spell 'Slam'"),
(49422, 0, 4, 0, 25, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 49428, 50, 0, 0, 0, 0, 0, "Rotbrain Berserker - On Reset - Start Attack (Creature ID: 49428, 50 Yards)"),
(49422, 0, 5, 0, 1, 0, 100, 0, 10000, 10000, 10000, 10000, 49, 0, 0, 0, 0, 0, 0, 11, 49428, 50, 0, 0, 0, 0, 0, "Rotbrain Berserker - OOC (10000 - 10000) - Start Attack (Creature ID: 49428, 50 Yards)"),

(49423, 0, 0, 0, 4, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Rotbrain Magus - On Aggro - Say Text Line 0 (No Repeat)"),
(49423, 0, 1, 0, 0, 0, 100, 0, 0, 0, 3400, 4700, 11, 9053, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Rotbrain Magus - In Combat - Cast Spell 'Fireball'"),
(49423, 0, 2, 0, 0, 0, 100, 0, 7000, 9000, 18000, 25000, 11, 11962, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Rotbrain Magus - In Combat - Cast Spell 'Immolate'"),
(49423, 0, 3, 0, 25, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 49428, 50, 0, 0, 0, 0, 0, "Rotbrain Magus - On Reset - Start Attack (Creature ID: 49428, 50 Yards)"),
(49423, 0, 4, 0, 1, 0, 100, 0, 10000, 10000, 10000, 10000, 49, 0, 0, 0, 0, 0, 0, 11, 49428, 50, 0, 0, 0, 0, 0, "Rotbrain Magus - OOC (10000 - 10000) - Start Attack (Creature ID: 49428, 50 Yards)"),

(49424, 0, 0, 1, 4, 0, 100, 1, 0, 0, 0, 0, 11, 83015, 0, 0, 0, 0, 0, 21, 25, 0, 0, 0, 0, 0, 0, "Marshal Redpath - On Aggro - Cast Spell 'Heroic Leap' (No Repeat)"),
(49424, 0, 1, 0, 61, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Marshal Redpath - On Aggro (Link) - Say Text Line 0 (No Repeat)"),
(49424, 0, 2, 0, 0, 0, 100, 1, 5000, 9000, 6000, 10000, 11, 33239, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Marshal Redpath - In Combat - Cast Spell 'Whirlwind'");

DELETE FROM `creature_text` WHERE `entry` IN (49422, 49423, 49424);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(49422, 0, 0, "I'll kill you!", "I'll kill you!", 12, 0, 15, 0, 0, 0, "Rotbrain Berserker"),
(49422, 0, 1, "Look what they've done to me!", "Look what they've done to me!", 12, 0, 15, 0, 0, 0, "Rotbrain Berserker"),
(49422, 0, 2, "Who am I?", "Who am I?", 12, 0, 15, 0, 0, 0, "Rotbrain Berserker"),
(49422, 1, 0, "%s becomes enraged!", "%s becomes enraged!", 16, 0, 100, 0, 0, 0, "Rotbrain Berserker"),

(49423, 0, 0, "I'll kill you!", "I'll kill you!", 12, 0, 15, 0, 0, 0, "Rotbrain Magus"),
(49423, 0, 1, "Look what they've done to me!", "Look what they've done to me!", 12, 0, 15, 0, 0, 0, "Rotbrain Magus"),
(49423, 0, 2, "Who am I?", "Who am I?", 12, 0, 15, 0, 0, 0, "Rotbrain Magus"),

(49424, 0, 0, "BLEEAAAGGHHH! I'm a monster, don't look at me!", "", 14, 0, 100, 0, 0, 0, "Rotbrain Magus");

-- Caretaker Caice
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 2307;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2307 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(2307, 0, 0, 0, 19, 0, 100, 0, 25089, 0, 0, 0, 85, 91938, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Caretaker Caice - On Quest Accept (25089) - Cast Spell To Summon");

-- Generic Bunny
UPDATE `creature` SET `position_x` = 1816.2699, `position_y` = 1589.7817, `position_z` = 96.536, `orientation` = 6.1166 WHERE `guid` = 192714;
UPDATE `creature` SET `position_x` = 1685.6896, `position_y` = 1647.7761, `position_z` = 137.354, `orientation` = 1.6925 WHERE `guid` = 192713;
UPDATE `creature` SET `position_x` = 1708.0999, `position_y` = 1644.4699, `position_z` = 126.151, `orientation` = 5.5768 WHERE `guid` = 192770;
UPDATE `creature` SET `position_x` = 1689.6483, `position_y` = 1674.8232, `position_z` = 135.612, `orientation` = 0.1570 WHERE `guid` = 192771;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-192770, -192714);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-192770, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 45, 1, 1, 0, 0, 0, 0, 11, 49337, 8, 0, 0, 0, 0, 0, "Generic Bunny - PRK - On Update OOC (1000 - 1000) - Set Data 1 1 To Creature ID: 49337"),
(-192714, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 45, 2, 2, 0, 0, 0, 0, 11, 49337, 5, 0, 0, 0, 0, 0, "Generic Bunny - PRK - On Update OOC (1000 - 1000) - Set Data 2 2 To Creature ID: 49337");

-- Darnell
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 49337;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 49337 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (49337*100, 49337*100+01, 49337*100+02) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(49337, 0, 0, 4, 54, 0, 100, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Just Summoned - Say Text Line 0 (No Repeat)"),
(49337, 0, 1, 0, 38, 0, 100, 1, 1, 1, 0, 0, 80, 49337*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Data Set 1 1 - Start Script (No Repeat)"),
(49337, 0, 2, 0, 38, 0, 100, 1, 2, 2, 0, 0, 80, 49337*100+01, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Data Set 2 2 - Start Script (No Repeat)"),
(49337, 0, 3, 4, 54, 0, 100, 1, 0, 0, 0, 0, 80, 49337*100+02, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Just Summoned - Start Script (No Repeat)"),
(49337, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Just Summoned (Link) - Set React State (Passive)"),
(49337, 0, 5, 0, 8, 0, 100, 0, 46598, 0, 0, 0, 11, 91935, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Spell Hit (46598) - Cast Spell Self (91935)"),
(49337, 0, 6, 0, 38, 0, 100, 1, 3, 3, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Data Set 3 3 - Despawn Self"),

(49337*100, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Script - Say Text Line 1"),
(49337*100, 9, 1, 0, 0, 0, 100, 0, 100, 100, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Script - Set Run On"),
(49337*100, 9, 2, 0, 0, 0, 100, 0, 500, 500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1783.75, 1595.59, 105.206, 0, "Darnell - On Script - Move To Position"),
(49337*100, 9, 3, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 29, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Script - Set Follow Owner"),

(49337*100+01, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Script - Say Text Line 2"),
(49337*100+01, 9, 1, 0, 0, 0, 100, 0, 100, 100, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Script - Set Run On"),
(49337*100+01, 9, 2, 0, 0, 0, 100, 0, 500, 500, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1861.56, 1603.44, 98.11, 0, "Darnell - On Script - Move To Position"),
(49337*100+01, 9, 3, 0, 0, 0, 100, 0, 2500, 2500, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Script - Say Text Line 3"),
(49337*100+01, 9, 4, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 29, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Script - Set Follow Owner"),

(49337*100+02, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Script - Say Text Line 4"),
(49337*100+02, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, "Darnell - On Script - Say Text Line 5");

DELETE FROM `creature_text` WHERE `entry` = 49337;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(49337, 0, 0, "Hello again..", "", 12, 0, 100, 3, 0, 0, "Darnell"),
(49337, 1, 0, "I know the way to Deathknell. Come with me!", "", 12, 0, 100, 273, 0, 0, "Darnell"),
(49337, 2, 0, "Good, you're still here. Now, where's Deathguard Saltain?", "", 12, 0, 100, 1, 0, 0, "Darnell"),
(49337, 3, 0, "Ah, here he is.", "", 12, 0, 100, 1, 0, 0, "Darnell"),
(49337, 4, 0, "We make our way, $N. Saltain said that we can find a few dead bodies up here.", "", 12, 0, 100, 1, 0, 0, "Darnell"),
(49337, 5, 0, "I think I see some corpses up ahead. Let's go, $N! You do the searching and fighting. I'll do the lifting.", "", 12, 0, 100, 1, 0, 0, "Darnell");

DELETE FROM `conditions` WHERE `SourceEntry` = 49337 AND `SourceTypeOrReferenceId` = 22;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 49337, 0, 0, 9, 0, 26800, 0, 0, 1, 0, 0, "", "SAI only when player has not take quest (26800)"),
(22, 4, 49337, 0, 0, 9, 0, 26800, 0, 0, 0, 0, 0, "", "SAI only when player has take quest (26800)");

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 1740;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1740 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1740*100, 1740*100+01) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1740, 0, 0, 0, 19, 0, 100, 0, 26800, 0, 0, 0, 80, 1740*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Saltain - On Quest Accept (26800) - Start Script"),
(1740, 0, 1, 0, 20, 0, 100, 0, 26800, 0, 0, 0, 80, 1740*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Saltain - On Quest Reward (26800) - Start Script"),
(1740, 0, 2, 0, 20, 0, 100, 0, 25089, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 49337, 20, 0, 0, 0, 0, 0, "Saltain - On Quest Reward (25089) - Set Data 3 3 To Creature ID: 49337"),

(1740*100, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 85, 91938, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Saltain - On Script - Cast Spell To Summon"),

(1740*100+01, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 3, 3, 0, 0, 0, 0, 19, 49337, 20, 0, 0, 0, 0, 0, "Saltain - On Script - Set Data 3 3 To Creature ID: 49337"),
(1740*100+01, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 49340, 20, 0, 0, 0, 0, 0, "Saltain - On Script - Set Data 1 1 To Creature ID: 49340");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 49340 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 49340*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(49340, 0, 0, 1, 75, 0, 100, 1, 0, 49337, 3, 0, 86, 91945, 2, 19, 49337, 20, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Corpse - On Distance Creature (49337) - Cross Cast Spell"),
(49340, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 46598, 2, 0, 0, 0, 0, 19, 49337, 20, 0, 0, 0, 0, 0, "Corpse - On Distance Creature (49337) (Link) - Cast Spell"),
(49340, 0, 2, 0, 38, 0, 100, 1, 1, 1, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Corpse - On Data Set 1 1 - Despawn Self");

UPDATE `creature_template` SET `RegenHealth` = 0 WHERE `entry` = 44795;
UPDATE `creature` SET `curhealth` = 900 WHERE `id` = 44795;

-- Lilian Voss
DELETE FROM `smart_scripts` WHERE `entryorguid` = 38910 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (38910*100, 38910*100+01) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(38910, 0, 0, 1, 62, 1, 100, 0, 11132, 0, 0, 0, 80, 38910*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Gossip Option 0 Selected - Run Script (Phase 1)"),
(38910, 0, 1, 8, 61, 1, 100, 0, 11132, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Gossip Option 0 Selected - Close Gossip (Phase 1)"),
(38910, 0, 2, 3, 62, 2, 100, 0, 11132, 0, 0, 0, 80, 38910*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Gossip Option 0 Selected - Run Script (Phase 2)"),
(38910, 0, 3, 9, 61, 2, 100, 0, 11132, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Gossip Option 0 Selected - Close Gossip (Phase 2)"),
(38910, 0, 4, 0, 25, 0, 100, 0, 0, 0, 0, 0, 17, 431, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Reset - Set Emote State (431)"),
(38910, 0, 5, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Reset - Set Event Phase 1"),
(38910, 0, 6, 10, 40, 0, 100, 0, 11, 38910*100, 0, 0, 17, 431, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Waypoint 11 Reached - Set Emote State (431)"),
(38910, 0, 7, 10, 40, 0, 100, 0, 11, 38910*100+01, 0, 0, 17, 431, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Waypoint 11 Reached - Set Emote State (431)"),
(38910, 0, 8, 11, 61, 0, 100, 0, 11132, 0, 0, 0, 85, 73210, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Gossip Option 0 Selected - Invoker Cast 'Show Mirror' (Phase 1)"),
(38910, 0, 9, 11, 61, 0, 100, 0, 11132, 0, 0, 0, 85, 73210, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Gossip Option 0 Selected - Invoker Cast 'Show Mirror' (Phase 1)"),
(38910, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 82, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - Link - Add Npc Flag Gossip"),
(38910, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 83, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - Link - Remove Npc Flag Gossip"),

(38910*100, 9, 0, 0, 0, 0, 100, 0, 500, 500, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Set Orientation To Invoker"),
(38910*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Set Emote State (26)"),
(38910*100, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Play Emote (18)"),
(38910*100, 9, 3, 0, 0, 0, 100, 0, 3200, 3200, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Say Text Line 0"),
(38910*100, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 33, 38910, 0, 0, 0, 0, 0, 17, 0, 30, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Quest Credit 'The Truth of the Grave'"),
(38910*100, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, 38910*100, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Start Waypoint"),
(38910*100, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Set Event Phase 2"),

(38910*100+01, 9, 0, 0, 0, 0, 100, 0, 500, 500, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Set Orientation To Invoker"),
(38910*100+01, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Set Emote State (26)"),
(38910*100+01, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Play Emote (18)"),
(38910*100+01, 9, 3, 0, 0, 0, 100, 0, 3200, 3200, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Say Text Line 0"),
(38910*100+01, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 33, 38910, 0, 0, 0, 0, 0, 17, 0, 30, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Quest Credit 'The Truth of the Grave'"),
(38910*100+01, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 53, 1, 38910*100+01, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Start Waypoint"),
(38910*100+01, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lilian Voss - On Script - Set Event Phase 1");

DELETE FROM `waypoints` WHERE `entry` IN (3891000, 3891001);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(3891000, 1, 1857.42, 1561.47, 99.079, "Lilian Voss"),
(3891000, 2, 1864.89, 1574.94, 99.0361, "Lilian Voss"),
(3891000, 3, 1868.91, 1575.56, 97.5441, "Lilian Voss"),
(3891000, 4, 1875.28, 1574.12, 94.314, "Lilian Voss"),
(3891000, 5, 1875.91, 1572.36, 94.314, "Lilian Voss"),
(3891000, 6, 1873, 1570.42, 94.314, "Lilian Voss"),
(3891000, 7, 1868.25, 1568.28, 94.314, "Lilian Voss"),
(3891000, 8, 1864.41, 1567.87, 94.314, "Lilian Voss"),
(3891000, 9, 1861.8, 1563.51, 94.3124, "Lilian Voss"),
(3891000, 10, 1860.59, 1558.04, 94.782, "Lilian Voss"),
(3891000, 11, 1857.21, 1555.61, 94.7926, "Lilian Voss"),

(3891001, 1, 1860.59, 1558.04, 94.782, "Lilian Voss"),
(3891001, 2, 1861.8, 1563.51, 94.3124, "Lilian Voss"),
(3891001, 3, 1864.41, 1567.87, 94.314, "Lilian Voss"),
(3891001, 4, 1868.25, 1568.28, 94.314, "Lilian Voss"),
(3891001, 5, 1873, 1570.42, 94.314, "Lilian Voss"),
(3891001, 6, 1875.91, 1572.36, 94.314, "Lilian Voss"),
(3891001, 7, 1875.28, 1574.12, 94.314, "Lilian Voss"),
(3891001, 8, 1868.91, 1575.56, 97.5441, "Lilian Voss"),
(3891001, 9, 1864.89, 1574.94, 99.0361, "Lilian Voss"),
(3891001, 10, 1857.42, 1561.47, 99.079, "Lilian Voss"),
(3891001, 11, 1854.83, 1555.63, 99.07, "Lilian Voss");

DELETE FROM `creature_text` WHERE `entry` = 38910;
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(38910, 0, 0, "", "You don't understand... I CAN'T be undead! Not me, not now...", 12, 0, 100, 18, 0, 0, "Lilian Voss");

DELETE FROM `conditions` WHERE `SourceGroup` = 11132 AND `SourceTypeOrReferenceId` = 15;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11132, 0, 0, 0, 9, 0, 24961, 0, 0, 0, 0, "", "Show gossip if player has Quest: The truth of the grave");

DELETE FROM `creature_queststarter` WHERE `quest` = 24961 AND `id` = 38910;

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (1569, 49426);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1569, 49426) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 49426*100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(1569, 0, 0, 1, 20, 0, 100, 0, 24971, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Shadow Priest Sarvis - On Quest Reward (24971) - Say Text Line 0"),

(49426, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 49426*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deathguard Darnell - On Just Summoned - Start Script"),

(49426*100, 9, 0, 0, 0, 0, 100, 0, 100, 100, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 1843.147095, 1631.313599, 96.93, 0, "Deathguard Darnell - On Script - Move To Position"),
(49426*100, 9, 1, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, "Deathguard Darnell - On Script - Say Text Line 0"),
(49426*100, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deathguard Darnell - On Script - Say Text Line 1"),
(49426*100, 9, 3, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deathguard Darnell - On Script - Say Text Line 2"),
(49426*100, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deathguard Darnell - On Script - Say Text Line 3"),
(49426*100, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 21, 100, 0, 0, 0, 0, 0, 0, "Deathguard Darnell - On Script - Say Text Line 4"),
(49426*100, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 5, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deathguard Darnell - On Script - Play Emote (3)"),
(49426*100, 9, 7, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Deathguard Darnell - On Script - Despawn Self");

DELETE FROM `creature_text` WHERE `entry` IN (1569, 49426);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(1569, 0, 0, "Well, look who's here!", "", 12, 0, 100, 5, 0, 0, "Shadow Priest Sarvis"),

(49426, 0, 0, "Hi, $n! What do you think about my new gear?", "", 12, 0, 100, 23, 0, 0, "Deathguard Darnell"),
(49426, 1, 0, "They're making me into a Deathguard. Can you believe it?", "", 12, 0, 100, 1, 0, 0, "Deathguard Darnell"),
(49426, 2, 0, "I'll probably be staying here in Deathknell. If things work out though... who knows? Maybe I'll get to meet the Dark Lady herself.", "", 12, 0, 100, 6, 0, 0, "Deathguard Darnell"),
(49426, 3, 0, "How about you? I've heard that Sarvis is going to send you off to Calston Estate. Big assignment, eh?", "", 12, 0, 100, 1, 0, 0, "Deathguard Darnell"),
(49426, 4, 0, "Well, I won't hold you up. It's been a pleasure. I hope our paths cross again soon.", "", 12, 0, 100, 66, 0, 0, "Deathguard Darnell");

UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` IN (1513, 1553);

DELETE FROM `creature_addon` WHERE `guid` IN (193272, 194133, 194649, 193748, 194563, 192742, 192695, 192696, 192697, 194454, 194052, 193474,
                                              193213, 193829, 194130, 193679, 193680, 194434, 194135, 193652, 193899, 193458);
DELETE FROM `waypoint_data` WHERE `id` IN (193272, 194133, 194649, 193748, 194563, 192742, 192695, 192696, 192697, 194454, 194052, 193474,
                                           193213, 193829, 194130, 193679, 193680, 194434, 194135, 193652, 193899, 193458);
UPDATE `creature` SET `movement_type` = 1, `wander_distance` = 20 WHERE `id` IN (1513, 1553);
UPDATE `creature` SET `movement_type` = 1, `wander_distance` = 10 WHERE `id` IN (1547, 1548, 1890);
UPDATE `creature` SET `movement_type` = 1, `wander_distance` = 5 WHERE `id` IN (1508, 1509);

UPDATE `game_weather` SET `spring_rain_chance` = 20, `summer_rain_chance` = 15, `fall_rain_chance` = 20, `winter_rain_chance` = 20, `winter_snow_chance` = 0 WHERE `zone` = 85;
UPDATE `creature_template` SET `unit_flags` = 32768 WHERE `entry` = 1934;

UPDATE `creature` SET `position_x` = 2220.16, `position_y` = 1034.98, `position_z` = 35.4363, `wander_distance` = 0, `movement_type` = 2 WHERE `guid` = 192606 AND `id` = 10666;

DELETE FROM `creature_addon` WHERE `guid` = 192606;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(192606, 192606, 1);

DELETE FROM `waypoint_data` WHERE `id` = 192606;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_flag`, `action`, `action_chance`, `wpguid`) VALUES
(192606, 1, 2220.16, 1034.98, 35.4363, 0, 0, 0, 0, 100, 0),
(192606, 2, 2215.4, 1034.4, 35.4941, 0, 0, 0, 0, 100, 0),
(192606, 3, 2210.6, 1032.61, 35.5099, 0, 0, 0, 0, 100, 0),
(192606, 4, 2212.62, 1038.43, 34.859, 0, 0, 0, 0, 100, 0),
(192606, 5, 2211.79, 1034.79, 35.322, 0, 0, 0, 0, 100, 0),
(192606, 6, 2212.88, 1038.84, 34.8025, 0, 0, 0, 0, 100, 0),
(192606, 7, 2211.61, 1034.22, 35.3814, 0, 0, 0, 0, 100, 0),
(192606, 8, 2217.5, 1035.07, 35.4439, 0, 0, 0, 0, 100, 0),
(192606, 9, 2222.84, 1034.61, 35.5158, 0, 0, 0, 0, 100, 0),
(192606, 10, 2228.76, 1032.47, 35.7824, 0, 0, 0, 0, 100, 0),
(192606, 11, 2239.25, 1024.1, 36.4546, 0, 0, 0, 0, 100, 0),
(192606, 12, 2243.63, 1018.43, 36.6652, 0, 0, 0, 0, 100, 0),
(192606, 13, 2243.18, 1004.55, 36.5792, 0, 0, 0, 0, 100, 0),
(192606, 14, 2232.18, 994.276, 36.727, 0, 0, 0, 0, 100, 0),
(192606, 15, 2241.75, 1006.5, 36.6768, 0, 0, 0, 0, 100, 0),
(192606, 16, 2243.38, 1017.61, 36.7298, 0, 0, 0, 0, 100, 0),
(192606, 17, 2240.62, 1023.92, 36.4588, 0, 0, 0, 0, 100, 0),
(192606, 18, 2226.9, 1033.25, 35.6483, 0, 0, 0, 0, 100, 0);
