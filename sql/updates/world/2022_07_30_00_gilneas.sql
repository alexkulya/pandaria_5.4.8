UPDATE `creature` SET `wander_distance` = 0, `movement_type` = 0 WHERE `guid` IN (221337, 221334, 221338, 221335, 221336);
UPDATE `creature` SET `phaseMask` = 4096 WHERE `guid` IN (219834, 219266, 220087, 220956, 220611, 219827, 219830);

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_chance_the_cat" WHERE `entry` = 36459;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 36459 AND `source_type` = 0;

DELETE FROM `creature` WHERE `guid` = 221857 AND `id` = 36461;
DELETE FROM `creature_addon` WHERE `guid` = 221857;
DELETE FROM `waypoint_data` WHERE `id` = 221857;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_lucius_the_cruel" WHERE `entry` = 36461;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_wahl" WHERE `entry` = 36458;

DELETE FROM `creature_text` WHERE `entry` IN (36458, 36461);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(36458, 0, 0, "", "You do not mess with my kitty you son of a mongrel!", 14, 0, 100, 0, 0, 0, "Grandma Wahl"),

(36461, 0, 0, "I'll be taking this cat. It seems to work as the perfect bait. Prepare to die now, fool!", "", 12, 0, 100, 0, 0, 0, "Lucius the Cruel");

UPDATE `npc_spellclick_spells` SET `spell_id` = 68743 WHERE `npc_entry` = 36459;

DELETE FROM `conditions` WHERE `SourceGroup` = 36459 AND `SourceEntry` = 68743 AND `SourceTypeOrReferenceId` = 18;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 36459, 68743, 0, 0, 9, 0, 14401, 0, 0, 0, 0, 0, "", "Requires Grandma's Cat (14401) to enable spellclick");
