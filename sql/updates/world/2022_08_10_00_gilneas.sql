UPDATE `quest_template` SET `flags` = 0 WHERE `Id` = 14204;

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_lorna_crowley_basement" WHERE `entry` = 35378;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_gilnean_mastiff" WHERE `entry` = 35631;
UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_bloodfang_lurker" WHERE `entry` = 35463;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35378, 35631, 35463) AND `source_type` = 0;

UPDATE `creature` SET `spawntimesecs` = 50 WHERE `id` = 35463;

DELETE FROM `spell_script_names` WHERE `spell_id` = 67805;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(67805, "spell_attack_lurker");

DELETE FROM `creature_text` WHERE `entry` = 35378;
INSERT INTO `creature_text` (`entry`,`text_group`,`id`,`text`,`text_female`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(35378,0,0,"","This mastiff will help you find the hidden worgen.",12,0,100,0,0,19696,"Lorna Crowley");
