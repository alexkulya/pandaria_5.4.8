-- =====================================================================
-- Quest 29690 "Into the Mists" (Horde) - play the Jade Forest arrival
-- scene (SceneScriptPackage 87) that was silently failing.
--
-- Root cause: General Nazgrim (55054) casts spell 121545 on the player via
-- SmartAI INVOKER_CAST. Spell 121545 effects (from client SpellEffect.dbc):
--     eff0: Apply Aura 261 (Phase 1149)
--     eff1: 198 PLAY_SCENE_ID, MiscValue 87  -> scene 87 (package 228)
--     eff2: 77 SCRIPT_EFFECT (no server script)
-- Spell::EffectPlaySceneId reads GetCaster()->ToPlayer(); because the caster
-- is Nazgrim (a creature, not the player), ToPlayer() is NULL and the scene
-- effect returns early. The phase aura still lands on the player, so it looks
-- like an abrupt transition with no cinematic.
--
-- Fix: keep casting 121545 (for the phase) but ALSO play the scene directly
-- on the invoker via SMART_ACTION_PLAY_SCENE_ID (201), which calls
-- player->GetSceneMgr().PlayScene(87) on the player - the same path as the
-- ".scene play 87" GM command - sidestepping the caster problem.
-- =====================================================================

SET @NAZGRIM  := 55054;
SET @SCENE_ID := 87;
SET @TELEPORT := 121545;   -- despite the name, this only phases + plays scene
SET @MENU     := 14988;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @NAZGRIM AND `source_type` = 0;
INSERT INTO `smart_scripts`
    (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,
     `event_param1`,`event_param2`,`event_param3`,`event_param4`,
     `action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,
     `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)
VALUES
-- On gossip select -> close gossip
(@NAZGRIM, 0, 0, 1, 62, 0, 100, 0, @MENU, 0, 0, 0, 72, 0,          0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'q29690 - Nazgrim - Gossip Select - Close Gossip'),
-- Linked -> cast 121545 on invoker (applies phase 1149 + script effect)
(@NAZGRIM, 0, 1, 2, 61, 0, 100, 0, 0,     0, 0, 0, 85, @TELEPORT,  0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'q29690 - Nazgrim - Linked - Cast 121545 (phase)'),
-- Linked -> play the Into the Mists scene (87) directly on the player
(@NAZGRIM, 0, 2, 0, 61, 0, 100, 0, 0,     0, 0, 0, 201, @SCENE_ID, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'q29690 - Nazgrim - Linked - Play Into the Mists scene 87');
