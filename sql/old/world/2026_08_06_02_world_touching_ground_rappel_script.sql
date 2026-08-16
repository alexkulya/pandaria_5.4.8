-- Quest 31766 - Touching Ground
-- Wire the DBC summon/seat spells and the temporary rope creature.

UPDATE `creature_template`
   SET `ScriptName` = 'npc_jade_forest_rappelling_rope'
 WHERE `entry` = 66640;

DELETE FROM `spell_script_names`
 WHERE `spell_id` IN (130960, 130970, 85299)
   AND `ScriptName` IN (
       'spell_jade_forest_rappelling_rope',
       'spell_jade_forest_rappelling_rope_aura',
       'spell_reverse_cast_ride_seat_1'
   );

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
    (130960, 'spell_jade_forest_rappelling_rope'),
    (130970, 'spell_jade_forest_rappelling_rope_aura'),
    (85299,  'spell_reverse_cast_ride_seat_1');
