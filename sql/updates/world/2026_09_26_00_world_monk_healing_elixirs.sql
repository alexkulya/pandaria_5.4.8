-- Chi Brew (115399) is not an aura spell, so it cannot run the Healing Elixirs
-- AuraScript. Keep the script on Healing Elixirs (122280) only.
DELETE FROM `spell_script_names`
 WHERE `spell_id` = 115399
   AND `ScriptName` = 'spell_monk_healing_elixirs';
