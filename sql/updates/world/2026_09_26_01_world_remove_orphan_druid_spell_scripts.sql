-- These druid spell script bindings reference script names that are not
-- registered by the core. They are ignored at startup and only produce
-- DBErrors.log noise.
DELETE FROM `spell_script_names`
 WHERE `ScriptName` IN (
    'spell_dru_rip',
    'spell_dru_solar_beam',
    'spell_dru_typhoon',
    'spell_dru_ursols_vortex',
    'spell_dru_ursols_vortex_snare'
);
