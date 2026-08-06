-- Quest 31766 - Touching Ground
-- The objective is interacting with a Rappelling Rope, not killing/talking
-- to NPC 66646. This makes the client display the objective gear above the
-- rope while the quest is incomplete and lets the GO interaction satisfy it.

UPDATE `quest_objective`
   SET `type` = 2,
       `objectId` = 215689,
       `description` = 'Rappel into Honeydew Glade'
 WHERE `questId` = 31766
   AND `id` = 269231;
