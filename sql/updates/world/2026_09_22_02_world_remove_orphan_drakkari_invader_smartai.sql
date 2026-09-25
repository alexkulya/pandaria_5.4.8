-- Drakkari Invader (27754) has SmartAI rows but no creature_template or spawns
-- in this MoP world DB, so worldserver skips these rows on startup.
DELETE FROM `smart_scripts`
 WHERE `source_type` = 0
   AND `entryorguid` = 27754;
