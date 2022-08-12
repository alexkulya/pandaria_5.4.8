UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_king_genn_greymane" WHERE `entry` = 35550;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35550 AND `source_type` = 0;

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_vehicle_genn_horse" WHERE `entry` = 35905;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35905 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35905*100 AND `source_type` = 9;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 35905;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(35905, 63151, 1, 0);

DELETE FROM `waypoints` WHERE `entry` = 35905;

DELETE FROM `creature` WHERE `guid` = 371579;
DELETE FROM `creature_addon` WHERE `guid` = 371579;

DELETE FROM `creature_text` WHERE `entry` IN (35550, 35753, 35907, 35905);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(35550, 0, 0, "Fire!", "", 14, 0, 100, 0, 0, 19710, "King Genn Greymane"),
(35550, 0, 1, "Hold the barricades!  Do not give them an inch!", "", 14, 0, 100, 0, 0, 19709, "King Genn Greymane"),
(35550, 0, 2, "Keep them back!", "", 14, 0, 100, 0, 0, 19712, "King Genn Greymane"),

(35753, 0, 0, "Help! Up here!", "", 14, 0, 100, 1, 0, 20921, "Krennan Aranas"),

(35907, 0, 0, "Keep them back!", "", 12, 0, 100, 1, 0, 20922, "Krennan Aranas"),

(35905, 0, 0, "Rescue Krennan Aranas by using your vehicle's ability.$B|TInterface\Icons\inv_misc_groupneedmore.blp:64|t", "Rescue Krennan Aranas by using your vehicle's ability.$B|TInterface\Icons\inv_misc_groupneedmore.blp:64|t", 41, 0, 100, 0, 0, 0, "King Greymane's Horse");

UPDATE `creature_template` SET `InhabitType` = 4, `AIName` = "", `ScriptName` = "" WHERE `entry` = 35753;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_saved_aranas" WHERE `entry` = 35907;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35753, 35907) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 35907*100 AND `source_type` = 9;

DELETE FROM `creature_template_addon` WHERE `entry` = 35753;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `auras`) VALUES
(35753, 1, "78037");
