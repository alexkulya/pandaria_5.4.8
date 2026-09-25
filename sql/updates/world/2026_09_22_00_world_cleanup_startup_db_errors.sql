-- Clean startup DB errors caused by orphaned or invalid world references.
-- These rows are skipped by the core during loading, so removing/fixing them
-- makes startup validation quieter without disabling valid content.

UPDATE `creature_template`
   SET `flags_extra` = `flags_extra` & ~(4194304 | 536870912 | 1073741824)
 WHERE (`flags_extra` & (4194304 | 536870912 | 1073741824)) <> 0;

UPDATE `creature_template`
   SET `unit_class` = 1
 WHERE `entry` = 59637
   AND `unit_class` = 0;

DELETE a
  FROM `creature_template_addon` a
  LEFT JOIN `creature_template` t ON t.`entry` = a.`entry`
 WHERE t.`entry` IS NULL;

DELETE a
  FROM `creature_addon` a
  LEFT JOIN `creature` c ON c.`guid` = a.`guid`
 WHERE c.`guid` IS NULL;

DELETE c
  FROM `creature` c
  LEFT JOIN `creature_template` t ON t.`entry` = c.`id`
 WHERE t.`entry` IS NULL;

DELETE p
  FROM `pool_creature` p
  LEFT JOIN `creature` c ON c.`guid` = p.`guid`
 WHERE c.`guid` IS NULL;

DELETE e
  FROM `game_event_creature` e
  LEFT JOIN `creature` c ON c.`guid` = e.`guid`
 WHERE c.`guid` IS NULL;

DELETE l
  FROM `achievement_reward_locale` l
  LEFT JOIN `achievement_reward` r ON r.`entry` = l.`ID`
 WHERE r.`entry` IS NULL;

DELETE qo
  FROM `quest_objective` qo
  LEFT JOIN `quest_template` qt ON qt.`Id` = qo.`questId`
 WHERE qt.`Id` IS NULL;

DELETE qo
  FROM `quest_objective` qo
  LEFT JOIN `creature_template` ct ON ct.`entry` = qo.`objectId`
 WHERE qo.`type` IN (0, 3, 11)
   AND ct.`entry` IS NULL;

DELETE qo
  FROM `quest_objective` qo
  LEFT JOIN `item_template` it ON it.`entry` = qo.`objectId`
 WHERE qo.`type` = 1
   AND it.`entry` IS NULL;

DELETE qo
  FROM `quest_objective` qo
  LEFT JOIN `gameobject_template` gt ON gt.`entry` = qo.`objectId`
 WHERE qo.`type` = 2
   AND gt.`entry` IS NULL;

DELETE FROM `quest_objective`
 WHERE `type` >= 14;

DELETE l
  FROM `quest_objective_locale` l
  LEFT JOIN `quest_objective` qo ON qo.`id` = l.`ID`
 WHERE qo.`id` IS NULL;

DELETE l
  FROM `quest_objective_locale` l
  JOIN `quest_objective` qo ON qo.`id` = l.`ID`
  JOIN `disables` d ON d.`sourceType` = 1
                   AND d.`entry` = qo.`questId`;

DELETE l
  FROM `locales_quest_objective` l
  LEFT JOIN `quest_objective` qo ON qo.`id` = l.`id`
 WHERE qo.`id` IS NULL;

DELETE l
  FROM `locales_quest_objective` l
  JOIN `quest_objective` qo ON qo.`id` = l.`id`
  JOIN `disables` d ON d.`sourceType` = 1
                   AND d.`entry` = qo.`questId`;

DELETE c
  FROM `conditions` c
  LEFT JOIN `creature_template` ct ON ct.`entry` = c.`ConditionValue2`
 WHERE c.`ConditionTypeOrReference` = 31
   AND c.`ConditionValue1` = 3
   AND c.`ConditionValue2` <> 0
   AND ct.`entry` IS NULL;

DELETE c
  FROM `conditions` c
  LEFT JOIN `gameobject_template` gt ON gt.`entry` = c.`ConditionValue2`
 WHERE c.`ConditionTypeOrReference` = 31
   AND c.`ConditionValue1` = 5
   AND c.`ConditionValue2` <> 0
   AND gt.`entry` IS NULL;

DELETE g
  FROM `gameobject` g
  JOIN `gameobject_template` gt ON gt.`entry` = g.`id`
 WHERE gt.`type` = 11;

DELETE e
  FROM `game_event_gameobject` e
  LEFT JOIN `gameobject` g ON g.`guid` = e.`guid`
 WHERE g.`guid` IS NULL;

DELETE v
  FROM `vehicle_template_accessory` v
  LEFT JOIN `npc_spellclick_spells` n ON n.`npc_entry` = v.`entry`
 WHERE n.`npc_entry` IS NULL;

INSERT INTO `trinity_string` (`entry`, `content_default`)
SELECT 15005, ''
 WHERE NOT EXISTS (
       SELECT 1
         FROM `trinity_string`
        WHERE `entry` = 15005
 );
