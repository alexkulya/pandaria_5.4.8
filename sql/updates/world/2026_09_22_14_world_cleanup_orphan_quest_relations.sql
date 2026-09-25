-- Clean up startup DBErrors caused by quest relations pointing to templates
-- that are not present in this 5.4.8 database. These rows cannot work until
-- the quests themselves exist, and the core skips them on every boot.

DELETE FROM `creature_queststarter`
 WHERE `quest` IN (40312, 32592, 40313, 40325, 40326, 40327, 40328, 40329);

DELETE FROM `creature_questender`
 WHERE `quest` IN (40312, 32592, 40313, 40325, 40326, 40327, 40328, 40329);

DELETE FROM `pool_quest`
 WHERE `entry` IN (40313, 40325, 40326, 40327, 40328, 40329);

DELETE FROM `spell_area`
 WHERE `quest_start` IN (40328, 40329)
    OR `quest_end` IN (40328, 40329);

DELETE FROM `quest_poi_points`
 WHERE `questId` IN (40312, 32592, 40313, 40325, 40326, 40327, 40328, 40329);

DELETE FROM `quest_poi`
 WHERE `questId` IN (40312, 32592, 40313, 40325, 40326, 40327, 40328, 40329);

-- These NPCs start or end valid quests, but were missing the questgiver bit.
UPDATE `creature_template`
   SET `npcflag` = `npcflag` | 2
 WHERE `entry` IN (58507, 62540, 63359, 67414, 68084, 68538, 69741, 70100, 70552, 73136, 73318);
