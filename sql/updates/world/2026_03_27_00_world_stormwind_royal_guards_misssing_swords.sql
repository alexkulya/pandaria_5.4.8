-- Description: Stormwind Royal Guards misssing swords
-- Author: https://github.com/xXBentRealityXx
-- Patch: https://github.com/alexkulya/pandaria_5.4.8/issues/1578

SET @ENTRY := 42218;
UPDATE creature_equip_template SET itemEntry1 = 21573 WHERE `entry`=@ENTRY;

-- Add second equips for guards on horseback holding the banner
DELETE FROM `creature_equip_template` WHERE `entry`=@ENTRY AND `id`=2;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(@ENTRY, 2, 0, 21572, 2551);

-- Change equip template if guard has aura 78855
UPDATE creature c SET c.equipment_id = 2 WHERE c.guid IN (178445, 178448, 178449, 178787, 178788, 178789, 178790, 178791, 178792, 178793, 178794, 178795, 179869, 179871, 179873, 179874, 179876, 179877) AND c.id = @ENTRY;

-- Stormwind Royal Guard SAI
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,0,0,0,0,0,71,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - On Aggro - Change Equipment"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,28,78855,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - On Aggro - Remove Aura 'Stormwind Flag Carrier'"),
(@ENTRY,0,2,3,7,0,100,0,0,0,0,0,71,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - On Evade - Change Equipment"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,75,78855,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormwind Royal Guard - On Evade - Add Aura 'Stormwind Flag Carrier'"),
(@ENTRY,0,4,0,0,0,100,0,0,0,3000,5000,11,95826,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormwind Royal Guard - In Combat - Cast 'Shoot'");
