-- =====================================================================
-- Remove `locales_quest_objective` rows whose quest objective the core refuses
-- to load, silencing the "Quest Objective locale X has invalid Quest Objective
-- Y! Skipping." startup warnings.
--
-- ObjectMgr::LoadQuestObjectives validates each objective's objectId against the
-- table matching its type (0/3 NPC -> creature_template, 1 ITEM -> item_template,
-- 2 GO -> gameobject_template). Some legacy quests (e.g. 8149 Uther's Tomb, 8150
-- Grom's Monument, 11997 Obtain Felo'melorn) carry objective rows whose objectId
-- is not a valid entity of that type, so the objective is skipped and never
-- registered - then its locale strings warn on load. The locale rows are dead
-- data for objectives that never load, so they are safe to delete.
-- (40 NPC-type rows + 12 GO-type rows.)
-- =====================================================================

DELETE l FROM `locales_quest_objective` l
JOIN `quest_objective` o ON o.`id` = l.`id`
WHERE (o.`type` IN (0,3) AND o.`objectId` NOT IN (SELECT `entry` FROM `creature_template`))
   OR (o.`type` = 1      AND o.`objectId` NOT IN (SELECT `entry` FROM `item_template`))
   OR (o.`type` = 2      AND o.`objectId` NOT IN (SELECT `entry` FROM `gameobject_template`));
