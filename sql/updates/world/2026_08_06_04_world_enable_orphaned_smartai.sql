-- Eight creatures have rows in smart_scripts but lost their AIName, so those
-- scripts never ran. One matters: 66654 is the barrel stack of quest 31768, so
-- the barrels ignored the flare gun and the quest could not be completed.
--
-- The 34 SmartVehicleAI creatures the loader also warns about work fine and are
-- left alone; two more carry a C++ ScriptName that would be displaced.

UPDATE `creature_template`
   SET `AIName` = 'SmartAI'
 WHERE `entry` IN (
        66654,   -- Thunder Hold Supplies  (quest 31768 barrels)
        64360,   -- General Nazgrim
        64362,   -- Shademaster Kiryn
        64363,   -- Shokia
        64364,   -- Rivett Clutchpop
        73556,   -- Earthen Familiar
        73559,   -- Water Familiar
        73560    -- Fire Familiar
   )
   AND `AIName` = ''
   AND `ScriptName` = '';
