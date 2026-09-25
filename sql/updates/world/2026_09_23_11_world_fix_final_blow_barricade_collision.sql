-- Quest 31769 "The Final Blow!"
-- Nazgrim's Flare Gun already credits the Alliance Barricade creatures and
-- calls ACTION_UPD_COLLISION on their AI. The templates were still bound to
-- SmartAI, so that action never reached the Jade Forest barricade script that
-- temporarily phases out the nearby barricade gameobjects/collision.

UPDATE `creature_template`
   SET `AIName` = '',
       `ScriptName` = 'npc_jade_forest_alliance_barricade'
 WHERE `entry` IN (66554, 66555, 66556);
