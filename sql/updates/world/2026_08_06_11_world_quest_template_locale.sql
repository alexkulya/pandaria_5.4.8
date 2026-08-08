-- locales_quest -> quest_template_locale + quest_offer_reward_locale
--                   + quest_request_items_locale
--
-- Pure restructuring; the missing translations are imported separately in _16.
--
-- Three tables and not one because OfferRewardText and RequestItemsText do not
-- belong to the quest log: they are what the quest giver speaks on hand-in and
-- on the "you are missing items" window, read from two places in GossipDef.cpp.
-- Keeping them in the same row meant loading 18145 rows of dialogue to render a
-- log entry.
--
-- The four 4.x portrait columns are carried over because Pandaria quests use
-- them, and ObjectiveText1..4 is absent because this fork has no such columns.

DROP TABLE IF EXISTS `quest_template_locale`;

CREATE TABLE `quest_template_locale` (
    `ID`                   MEDIUMINT UNSIGNED NOT NULL DEFAULT 0,
    `locale`               VARCHAR(4)         NOT NULL,
    `Title`                TEXT,
    `Details`              TEXT,
    `Objectives`           TEXT,
    `EndText`              TEXT,
    `CompletedText`        TEXT,
    `QuestGiverTextWindow` TEXT,
    `QuestGiverTargetName` TEXT,
    `QuestTurnTextWindow`  TEXT,
    `QuestTurnTargetName`  TEXT,
    `VerifiedBuild`        INT DEFAULT 0,
    PRIMARY KEY (`ID`, `locale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

INSERT INTO `quest_template_locale`
    (`ID`,`locale`,`Title`,`Details`,`Objectives`,`EndText`,`CompletedText`,
     `QuestGiverTextWindow`,`QuestGiverTargetName`,`QuestTurnTextWindow`,`QuestTurnTargetName`)
SELECT `Id`,'koKR',`Title_loc1`, `Details_loc1`, `Objectives_loc1`, `EndText_loc1`, `CompletedText_loc1`, `QuestGiverTextWindow_loc1`, `QuestGiverTargetName_loc1`, `QuestTurnTextWindow_loc1`, `QuestTurnTargetName_loc1`  FROM `locales_quest` WHERE COALESCE(`Title_loc1`,'')  <> '' OR COALESCE(`Details_loc1`,'')  <> '' OR COALESCE(`Objectives_loc1`,'')  <> '' UNION ALL
SELECT `Id`,'frFR',`Title_loc2`, `Details_loc2`, `Objectives_loc2`, `EndText_loc2`, `CompletedText_loc2`, `QuestGiverTextWindow_loc2`, `QuestGiverTargetName_loc2`, `QuestTurnTextWindow_loc2`, `QuestTurnTargetName_loc2`  FROM `locales_quest` WHERE COALESCE(`Title_loc2`,'')  <> '' OR COALESCE(`Details_loc2`,'')  <> '' OR COALESCE(`Objectives_loc2`,'')  <> '' UNION ALL
SELECT `Id`,'deDE',`Title_loc3`, `Details_loc3`, `Objectives_loc3`, `EndText_loc3`, `CompletedText_loc3`, `QuestGiverTextWindow_loc3`, `QuestGiverTargetName_loc3`, `QuestTurnTextWindow_loc3`, `QuestTurnTargetName_loc3`  FROM `locales_quest` WHERE COALESCE(`Title_loc3`,'')  <> '' OR COALESCE(`Details_loc3`,'')  <> '' OR COALESCE(`Objectives_loc3`,'')  <> '' UNION ALL
SELECT `Id`,'zhCN',`Title_loc4`, `Details_loc4`, `Objectives_loc4`, `EndText_loc4`, `CompletedText_loc4`, `QuestGiverTextWindow_loc4`, `QuestGiverTargetName_loc4`, `QuestTurnTextWindow_loc4`, `QuestTurnTargetName_loc4`  FROM `locales_quest` WHERE COALESCE(`Title_loc4`,'')  <> '' OR COALESCE(`Details_loc4`,'')  <> '' OR COALESCE(`Objectives_loc4`,'')  <> '' UNION ALL
SELECT `Id`,'zhTW',`Title_loc5`, `Details_loc5`, `Objectives_loc5`, `EndText_loc5`, `CompletedText_loc5`, `QuestGiverTextWindow_loc5`, `QuestGiverTargetName_loc5`, `QuestTurnTextWindow_loc5`, `QuestTurnTargetName_loc5`  FROM `locales_quest` WHERE COALESCE(`Title_loc5`,'')  <> '' OR COALESCE(`Details_loc5`,'')  <> '' OR COALESCE(`Objectives_loc5`,'')  <> '' UNION ALL
SELECT `Id`,'esES',`Title_loc6`, `Details_loc6`, `Objectives_loc6`, `EndText_loc6`, `CompletedText_loc6`, `QuestGiverTextWindow_loc6`, `QuestGiverTargetName_loc6`, `QuestTurnTextWindow_loc6`, `QuestTurnTargetName_loc6`  FROM `locales_quest` WHERE COALESCE(`Title_loc6`,'')  <> '' OR COALESCE(`Details_loc6`,'')  <> '' OR COALESCE(`Objectives_loc6`,'')  <> '' UNION ALL
SELECT `Id`,'esMX',`Title_loc7`, `Details_loc7`, `Objectives_loc7`, `EndText_loc7`, `CompletedText_loc7`, `QuestGiverTextWindow_loc7`, `QuestGiverTargetName_loc7`, `QuestTurnTextWindow_loc7`, `QuestTurnTargetName_loc7`  FROM `locales_quest` WHERE COALESCE(`Title_loc7`,'')  <> '' OR COALESCE(`Details_loc7`,'')  <> '' OR COALESCE(`Objectives_loc7`,'')  <> '' UNION ALL
SELECT `Id`,'ruRU',`Title_loc8`, `Details_loc8`, `Objectives_loc8`, `EndText_loc8`, `CompletedText_loc8`, `QuestGiverTextWindow_loc8`, `QuestGiverTargetName_loc8`, `QuestTurnTextWindow_loc8`, `QuestTurnTargetName_loc8`  FROM `locales_quest` WHERE COALESCE(`Title_loc8`,'')  <> '' OR COALESCE(`Details_loc8`,'')  <> '' OR COALESCE(`Objectives_loc8`,'')  <> '' UNION ALL
SELECT `Id`,'itIT',`Title_loc9`, `Details_loc9`, `Objectives_loc9`, `EndText_loc9`, `CompletedText_loc9`, `QuestGiverTextWindow_loc9`, `QuestGiverTargetName_loc9`, `QuestTurnTextWindow_loc9`, `QuestTurnTargetName_loc9`  FROM `locales_quest` WHERE COALESCE(`Title_loc9`,'')  <> '' OR COALESCE(`Details_loc9`,'')  <> '' OR COALESCE(`Objectives_loc9`,'')  <> '' UNION ALL
SELECT `Id`,'ptBR',`Title_loc10`,`Details_loc10`,`Objectives_loc10`,`EndText_loc10`,`CompletedText_loc10`,`QuestGiverTextWindow_loc10`,`QuestGiverTargetName_loc10`,`QuestTurnTextWindow_loc10`,`QuestTurnTargetName_loc10` FROM `locales_quest` WHERE COALESCE(`Title_loc10`,'') <> '' OR COALESCE(`Details_loc10`,'') <> '' OR COALESCE(`Objectives_loc10`,'') <> '' UNION ALL
SELECT `Id`,'ptPT',`Title_loc11`,`Details_loc11`,`Objectives_loc11`,`EndText_loc11`,`CompletedText_loc11`,`QuestGiverTextWindow_loc11`,`QuestGiverTargetName_loc11`,`QuestTurnTextWindow_loc11`,`QuestTurnTargetName_loc11` FROM `locales_quest` WHERE COALESCE(`Title_loc11`,'') <> '' OR COALESCE(`Details_loc11`,'') <> '' OR COALESCE(`Objectives_loc11`,'') <> '';



-- ---------------------------------------------------------------------
-- 2) quest_offer_reward_locale - what the quest giver says on hand-in.
-- ---------------------------------------------------------------------
DROP TABLE IF EXISTS `quest_offer_reward_locale`;

CREATE TABLE `quest_offer_reward_locale` (
    `ID`            MEDIUMINT UNSIGNED NOT NULL DEFAULT 0,
    `locale`        VARCHAR(4)         NOT NULL,
    `RewardText`    TEXT,
    `VerifiedBuild` INT DEFAULT 0,
    PRIMARY KEY (`ID`, `locale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

INSERT INTO `quest_offer_reward_locale` (`ID`, `locale`, `RewardText`)
SELECT `Id`,'koKR',`OfferRewardText_loc1`  FROM `locales_quest` WHERE COALESCE(`OfferRewardText_loc1`,'')  <> '' UNION ALL
SELECT `Id`,'frFR',`OfferRewardText_loc2`  FROM `locales_quest` WHERE COALESCE(`OfferRewardText_loc2`,'')  <> '' UNION ALL
SELECT `Id`,'deDE',`OfferRewardText_loc3`  FROM `locales_quest` WHERE COALESCE(`OfferRewardText_loc3`,'')  <> '' UNION ALL
SELECT `Id`,'zhCN',`OfferRewardText_loc4`  FROM `locales_quest` WHERE COALESCE(`OfferRewardText_loc4`,'')  <> '' UNION ALL
SELECT `Id`,'zhTW',`OfferRewardText_loc5`  FROM `locales_quest` WHERE COALESCE(`OfferRewardText_loc5`,'')  <> '' UNION ALL
SELECT `Id`,'esES',`OfferRewardText_loc6`  FROM `locales_quest` WHERE COALESCE(`OfferRewardText_loc6`,'')  <> '' UNION ALL
SELECT `Id`,'esMX',`OfferRewardText_loc7`  FROM `locales_quest` WHERE COALESCE(`OfferRewardText_loc7`,'')  <> '' UNION ALL
SELECT `Id`,'ruRU',`OfferRewardText_loc8`  FROM `locales_quest` WHERE COALESCE(`OfferRewardText_loc8`,'')  <> '' UNION ALL
SELECT `Id`,'itIT',`OfferRewardText_loc9`  FROM `locales_quest` WHERE COALESCE(`OfferRewardText_loc9`,'')  <> '' UNION ALL
SELECT `Id`,'ptBR',`OfferRewardText_loc10` FROM `locales_quest` WHERE COALESCE(`OfferRewardText_loc10`,'') <> '' UNION ALL
SELECT `Id`,'ptPT',`OfferRewardText_loc11` FROM `locales_quest` WHERE COALESCE(`OfferRewardText_loc11`,'') <> '';



-- ---------------------------------------------------------------------
-- 3) quest_request_items_locale - the "you still need" window.
-- ---------------------------------------------------------------------
DROP TABLE IF EXISTS `quest_request_items_locale`;

CREATE TABLE `quest_request_items_locale` (
    `ID`             MEDIUMINT UNSIGNED NOT NULL DEFAULT 0,
    `locale`         VARCHAR(4)         NOT NULL,
    `CompletionText` TEXT,
    `VerifiedBuild`  INT DEFAULT 0,
    PRIMARY KEY (`ID`, `locale`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

INSERT INTO `quest_request_items_locale` (`ID`, `locale`, `CompletionText`)
SELECT `Id`,'koKR',`RequestItemsText_loc1`  FROM `locales_quest` WHERE COALESCE(`RequestItemsText_loc1`,'')  <> '' UNION ALL
SELECT `Id`,'frFR',`RequestItemsText_loc2`  FROM `locales_quest` WHERE COALESCE(`RequestItemsText_loc2`,'')  <> '' UNION ALL
SELECT `Id`,'deDE',`RequestItemsText_loc3`  FROM `locales_quest` WHERE COALESCE(`RequestItemsText_loc3`,'')  <> '' UNION ALL
SELECT `Id`,'zhCN',`RequestItemsText_loc4`  FROM `locales_quest` WHERE COALESCE(`RequestItemsText_loc4`,'')  <> '' UNION ALL
SELECT `Id`,'zhTW',`RequestItemsText_loc5`  FROM `locales_quest` WHERE COALESCE(`RequestItemsText_loc5`,'')  <> '' UNION ALL
SELECT `Id`,'esES',`RequestItemsText_loc6`  FROM `locales_quest` WHERE COALESCE(`RequestItemsText_loc6`,'')  <> '' UNION ALL
SELECT `Id`,'esMX',`RequestItemsText_loc7`  FROM `locales_quest` WHERE COALESCE(`RequestItemsText_loc7`,'')  <> '' UNION ALL
SELECT `Id`,'ruRU',`RequestItemsText_loc8`  FROM `locales_quest` WHERE COALESCE(`RequestItemsText_loc8`,'')  <> '' UNION ALL
SELECT `Id`,'itIT',`RequestItemsText_loc9`  FROM `locales_quest` WHERE COALESCE(`RequestItemsText_loc9`,'')  <> '' UNION ALL
SELECT `Id`,'ptBR',`RequestItemsText_loc10` FROM `locales_quest` WHERE COALESCE(`RequestItemsText_loc10`,'') <> '' UNION ALL
SELECT `Id`,'ptPT',`RequestItemsText_loc11` FROM `locales_quest` WHERE COALESCE(`RequestItemsText_loc11`,'') <> '';



-- Old table `locales_quest` is dropped in _17, once the replacement is confirmed in game.
