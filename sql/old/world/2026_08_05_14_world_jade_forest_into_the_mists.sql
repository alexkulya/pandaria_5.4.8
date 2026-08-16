-- #####################################################################
-- Quest 29690 "Into the Mists" - the Horde arrival in Pandaria.
--
-- Consolidates what used to be migrations _14, _15 and _18:
--     1) the spell scripts that complete the arrival scene
--     2) the phasemask spell 121545 hands out while the scene runs
--     3) the real quest chain: 55054 in Orgrimmar starts it, 55135 ends it
--
-- The chain is
--     31853 All Aboard!  ->  29690 Into the Mists  ->  31765 Paint it Red!
-- #####################################################################


-- Complete the Horde arrival sequence for quest 29690.
-- These handlers are the missing SCRIPT_EFFECT parts of the client scene.

DELETE FROM `spell_script_names`
WHERE `spell_id` IN (121545, 130723, 130812)
  AND `ScriptName` IN (
    'spell_into_the_mists_scene_jade_forest',
    'spell_into_the_mists_scene_end_jade_forest',
    'spell_into_the_mists_cancel_blackout'
  );

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(121545, 'spell_into_the_mists_scene_jade_forest'),
(130723, 'spell_into_the_mists_scene_end_jade_forest'),
(130812, 'spell_into_the_mists_cancel_blackout');
-- Quest 29690 arrival phase.
-- The ship and its arrival NPCs use phase 67108864, while the normal
-- Jade Forest world remains phase 1. Keep both visible during 121545.

DELETE FROM `spell_phase` WHERE `id` = 121545;
INSERT INTO `spell_phase` (`id`, `phasemask`, `terrainswapmap`)
VALUES (121545, 67108865, 0);
-- Restore the real Horde chain: quest 29690 starts with Nazgrim 55054 in
-- Orgrimmar, then 121545 takes the player to the Jade Forest arrival ship.

DELETE FROM `creature_queststarter`
WHERE `id` = 55135 AND `quest` = 29690;

INSERT INTO `creature_queststarter` (`id`, `quest`)
VALUES (55054, 29690)
ON DUPLICATE KEY UPDATE `quest` = VALUES(`quest`);

UPDATE `creature_template`
SET `npcflag` = 2, `gossip_menu_id` = 0
WHERE `entry` = 55135;

DELETE FROM `smart_scripts`
WHERE `entryorguid` = 55135 AND `source_type` = 0;

DELETE FROM `smart_scripts`
WHERE `entryorguid` = 55054 AND `source_type` = 0;

INSERT INTO `smart_scripts`
    (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,
     `event_param1`,`event_param2`,`event_param3`,`event_param4`,
     `action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,
     `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)
VALUES
(55054, 0, 0, 1, 62, 0, 100, 0, 14988, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'q29690 - Orgrimmar Nazgrim - Close gossip'),
(55054, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 85, 121545, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'q29690 - Orgrimmar Nazgrim - Cast arrival scene'),
(55054, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 201, 87, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'q29690 - Orgrimmar Nazgrim - Play scene 87');

-- The map-870 copy was incorrectly made a second quest starter.
DELETE FROM `creature`
WHERE `guid` = 505831 AND `id` = 55054 AND `map` = 870;

-- GO 195276 is the intact Icecrown-era "Horde Gunship". The Jade Forest ship
-- is the *wreck*, which is terrain swap 1076 plus the phasemask 67108864
-- spawns (see migration _19), so no transport must exist for it.
DELETE FROM `gameobject` WHERE `guid` = 549845 AND `id` = 195276;
DELETE FROM `transports` WHERE `entry` = 195276;
