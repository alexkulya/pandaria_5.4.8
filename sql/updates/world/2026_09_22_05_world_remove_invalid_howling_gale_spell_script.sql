-- Howling Gale is handled by its NPC data in Vortex Pinnacle. This imported
-- spell_script_names row has the spell id pasted into the ScriptName and the
-- referenced spell id is not present in the local MoP DBC.
DELETE FROM `spell_script_names`
 WHERE `spell_id` = 85084
   AND `ScriptName` = '85084spell_howling_gale_howling_gale';
