DELETE FROM `spell_script_names`
WHERE `ScriptName` = 'spell_common_unlearn_talent';

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-127650, 'spell_common_unlearn_talent');
