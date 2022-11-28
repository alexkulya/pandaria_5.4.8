UPDATE `gameobject_template` SET `data0` = 86855 WHERE `entry` = 206195;
UPDATE `quest_objective` SET `objectId` = 113135 WHERE `questId` = 10794 AND `id` = 273866 AND `index` = 0;
UPDATE `quest_objective` SET `objectId` = 45155 WHERE `questId` = 27152 AND `id` = 261619 AND `index` = 0;
UPDATE `quest_objective` SET `objectId` = 73 WHERE `questId` = 30759 AND `id` = 272423 AND `index` = 0;
DELETE FROM `quest_objective` WHERE `questId` = 31906 AND `id` = 269192 AND `index` = 1;
DELETE FROM `quest_objective` WHERE `questId` = 31907 AND `id` = 269192 AND `index` = 0;
DELETE FROM `quest_objective` WHERE `questId` = 31907 AND `id` = 269193 AND `index` = 0;
DELETE FROM `quest_objective` WHERE `questId` = 31907 AND `id` = 269194 AND `index` = 0;
UPDATE `quest_objective` SET `type` = 1 WHERE `questId` = 31939 AND `id` = 270827 AND `index` = 1;

DELETE FROM `creature_template` WHERE `entry` IN (108639,108644,100290,99418);
INSERT INTO `creature_template`(`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `difficulty_entry_4`, `difficulty_entry_5`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction_A`, `faction_H`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Mana_mod_extra`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `VignetteID`, `TrackingQuestID`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(108639, 0, 0, 0, 0, 0, 0, 0, 16925, 0, 0, 0, 'Tomb Credit', NULL, NULL, 0, 1, 1, 0, 0, 35, 35, 0, 0, 1, 1.14286, 1, 0, 0, 0, 0, 0, 1, 2000, 2000, 1, 32768, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 1074790400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, '', 18414),
(108644, 0, 0, 0, 0, 0, 0, 0, 16925, 0, 0, 0, 'Tomb Credit', NULL, NULL, 0, 1, 1, 0, 0, 35, 35, 0, 0, 1, 1.14286, 1, 0, 0, 0, 0, 0, 1, 2000, 2000, 1, 32768, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 1074790400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, '', 18414),
(100290, 0, 0, 0, 0, 0, 0, 0, 56187, 56187, 0, 0, 'Flame Bunny', NULL, NULL, 0, 1, 1, 0, 0, 35, 35, 0, 0, 1, 1.14286, 1, 0, 0, 0, 0, 0, 1, 2000, 2000, 1, 32768, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 1074790400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, '', 18414),
(99418, 0, 0, 0, 0, 0, 0, 0, 69861, 0, 0, 0, 'Aethas\'s Portal', NULL, 'questinteract', 0, 100, 100, 5, 0, 35, 35, 0, 0, 1, 1.14286, 1, 0, 0, 0, 0, 0, 1, 2000, 2000, 1, 768, 526336, 0, 0, 0, 0, 0, 0, 0, 0, 10, 1611661328, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, '', 18414);


DELETE FROM `gameobject_template` WHERE `entry` IN (211679,212375);
INSERT INTO `gameobject_template`(`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `unkInt32`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES 
(211679, 10, 9277, 'Test Quest Gear Icon', '', '', '', 1, 0, 0, 0, 0, 0, 0, 1690, 0, 0, 3000, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 1),
(212375, 10, 11740, 'Iron Belly Spirits', '', '', '', 1, 0, 0, 0, 0, 0, 0, 43, 0, 0, 3000, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 1);


DELETE FROM `creature_text` WHERE `entry` = 30007 AND `groupid` = 4 AND `id` = 0;
INSERT INTO `creature_text`(`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(30007, 4, 0, 'Yggdras emerges!', 41, 0, 100, 0, 0, 0, 'gurgthock EMOTE_YGGDRAS_SPAWN');

DELETE FROM `creature_text` WHERE `entry` = 61567 AND `groupid` = 5 AND `id` = 1;
DELETE FROM `creature_text` WHERE `entry` = 61567 AND `groupid` = 5 AND `id` = 0;
INSERT INTO `creature_text`(`entry`, `groupid`, `id`, `text`, `text_female`, `TextRange`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(61567, 5, 1, 'Did you think you stood a chance?!', NULL, 0, 14, 0, 100, 0, 0, 29394, 66447, ''),
(61567, 5, 0, 'Your carved bones will decorate the weapons of our warriors!', NULL, 0, 14, 0, 100, 0, 0, 29393, 66446, '');
