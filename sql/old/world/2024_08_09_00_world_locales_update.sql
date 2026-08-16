-- achievement_reward_locale
DROP TABLE IF EXISTS `achievement_reward_locale`;
CREATE TABLE IF NOT EXISTS `achievement_reward_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT "0",
  `Locale` VARCHAR(4) NOT NULL,
  `Subject` TEXT,
  `Text` TEXT,
  PRIMARY KEY (`ID`, `Locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

INSERT INTO `achievement_reward_locale` (`ID`, `Locale`, `Subject`, `Text`)
  (SELECT `entry`, "koKR", `subject_loc1`, `text_loc1` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc1) > 0 OR LENGTH(text_loc1) > 0);

INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "frFR", `subject_loc2`, `text_loc2` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc2) > 0 OR LENGTH(text_loc2) > 0);

INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "deDE", `subject_loc3`, `text_loc3` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc3) > 0 OR LENGTH(text_loc3) > 0);

INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "zhCN", `subject_loc4`, `text_loc4` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc4) > 0 OR LENGTH(text_loc4) > 0);

INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "zhTW", `subject_loc5`, `text_loc5` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc5) > 0 OR LENGTH(text_loc5) > 0);

INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "esES", `subject_loc6`, `text_loc6` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc6) > 0 OR LENGTH(text_loc6) > 0);

INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "esMX", `subject_loc7`, `text_loc7` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc7) > 0 OR LENGTH(text_loc7) > 0);

INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "ruRU", `subject_loc8`, `text_loc8` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc8) > 0 OR LENGTH(text_loc8) > 0);

-- gossip_menu_option_locale
DROP TABLE IF EXISTS `gossip_menu_option_locale`;
CREATE TABLE IF NOT EXISTS `gossip_menu_option_locale` (
  `MenuID` SMALLINT(6) UNSIGNED NOT NULL DEFAULT "0",
  `OptionID` SMALLINT(6) UNSIGNED NOT NULL DEFAULT "0",
  `Locale` VARCHAR(4) NOT NULL,
  `OptionText` TEXT,
  `BoxText` TEXT,
  PRIMARY KEY (`MenuID`, `OptionID`, `Locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "koKR", `option_text_loc1`, `box_text_loc1` FROM `locales_gossip_menu_option` WHERE LENGTH(option_text_loc1) > 0 || LENGTH(box_text_loc1) > 0);

INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "frFR", `option_text_loc2`, `box_text_loc2` FROM `locales_gossip_menu_option` WHERE LENGTH(option_text_loc2) > 0 || LENGTH(box_text_loc2) > 0);

INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "deDE", `option_text_loc3`, `box_text_loc3` FROM `locales_gossip_menu_option` WHERE LENGTH(option_text_loc3) > 0 || LENGTH(box_text_loc3) > 0);

INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "zhCN", `option_text_loc4`, `box_text_loc4` FROM `locales_gossip_menu_option` WHERE LENGTH(option_text_loc4) > 0 || LENGTH(box_text_loc4) > 0);

INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "zhTW", `option_text_loc5`, `box_text_loc5` FROM `locales_gossip_menu_option` WHERE LENGTH(option_text_loc5) > 0 || LENGTH(box_text_loc5) > 0);

INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "esES", `option_text_loc6`, `box_text_loc6` FROM `locales_gossip_menu_option` WHERE LENGTH(option_text_loc6) > 0 || LENGTH(box_text_loc6) > 0);

INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "esMX", `option_text_loc7`, `box_text_loc7` FROM `locales_gossip_menu_option` WHERE LENGTH(option_text_loc7) > 0 || LENGTH(box_text_loc7) > 0);

INSERT INTO `gossip_menu_option_locale` (`MenuID`, `OptionID`, `Locale`, `OptionText`, `BoxText`)
  (SELECT `menu_id`, `id`, "ruRU", `option_text_loc8`, `box_text_loc8` FROM `locales_gossip_menu_option` WHERE LENGTH(option_text_loc8) > 0 || LENGTH(box_text_loc8) > 0);

-- battle_pay_group_locale
DROP TABLE IF EXISTS `battle_pay_group_locale`;
CREATE TABLE IF NOT EXISTS `battle_pay_group_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT "0",
  `Locale` VARCHAR(4) NOT NULL,
  `Name` TEXT,
  PRIMARY KEY (`ID`, `Locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, "koKR", `name_loc1`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc1`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, "frFR", `name_loc2`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc2`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, "deDE", `name_loc3`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc3`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, "zhCN", `name_loc4`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc4`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, "zhTW", `name_loc5`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc5`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, "esES", `name_loc6`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc6`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, "esMX", `name_loc7`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc7`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, "ruRU", `name_loc8`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc8`) > 0;

-- battle_pay_entry_locale
DROP TABLE IF EXISTS `battle_pay_entry_locale`;
CREATE TABLE IF NOT EXISTS `battle_pay_entry_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT "0",
  `Locale` VARCHAR(4) NOT NULL,
  `Title` TEXT,
  `Description` TEXT,
  PRIMARY KEY (`ID`, `Locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "koKR", `title_loc1`, `description_loc1` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc1`) > 0 OR LENGTH(`description_loc1`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "frFR", `title_loc2`, `description_loc2` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc2`) > 0 OR LENGTH(`description_loc2`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "deDE", `title_loc3`, `description_loc3` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc3`) > 0 OR LENGTH(`description_loc3`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "zhCN", `title_loc4`, `description_loc4` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc4`) > 0 OR LENGTH(`description_loc4`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "zhTW", `title_loc5`, `description_loc5` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc5`) > 0 OR LENGTH(`description_loc5`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "esES", `title_loc6`, `description_loc6` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc6`) > 0 OR LENGTH(`description_loc6`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "esMX", `title_loc7`, `description_loc7` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc7`) > 0 OR LENGTH(`description_loc7`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "ruRU", `title_loc8`, `description_loc8` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc8`) > 0 OR LENGTH(`description_loc8`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "itIT", `title_loc9`, `description_loc9` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc9`) > 0 OR LENGTH(`description_loc9`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "ptBR", `title_loc10`, `description_loc10` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc10`) > 0 OR LENGTH(`description_loc10`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "ptPT", `title_loc11`, `description_loc11` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc11`) > 0 OR LENGTH(`description_loc11`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

-- battle_pay_product_locale
DROP TABLE IF EXISTS `battle_pay_product_locale`;
CREATE TABLE IF NOT EXISTS `battle_pay_product_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT "0",
  `Locale` VARCHAR(4) NOT NULL,
  `Title` TEXT,
  `Description` TEXT,
  PRIMARY KEY (`ID`, `Locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "koKR", `title_loc1`, `description_loc1` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc1`) > 0 OR LENGTH(`description_loc1`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "frFR", `title_loc2`, `description_loc2` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc2`) > 0 OR LENGTH(`description_loc2`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "deDE", `title_loc3`, `description_loc3` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc3`) > 0 OR LENGTH(`description_loc3`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "zhCN", `title_loc4`, `description_loc4` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc4`) > 0 OR LENGTH(`description_loc4`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "zhTW", `title_loc5`, `description_loc5` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc5`) > 0 OR LENGTH(`description_loc5`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "esES", `title_loc6`, `description_loc6` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc6`) > 0 OR LENGTH(`description_loc6`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "esMX", `title_loc7`, `description_loc7` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc7`) > 0 OR LENGTH(`description_loc7`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "ruRU", `title_loc8`, `description_loc8` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc8`) > 0 OR LENGTH(`description_loc8`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "itIT", `title_loc9`, `description_loc9` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc9`) > 0 OR LENGTH(`description_loc9`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "ptBR", `title_loc10`, `description_loc10` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc10`) > 0 OR LENGTH(`description_loc10`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, "ptPT", `title_loc11`, `description_loc11` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc11`) > 0 OR LENGTH(`description_loc11`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

RENAME TABLE `locales_creature` TO `creature_template_locale`;
DROP TABLE IF EXISTS `locales_achievement_reward`;
DROP TABLE IF EXISTS `locales_gossip_menu_option`;
DROP TABLE IF EXISTS `locales_battle_pay_group`;
DROP TABLE IF EXISTS `locales_battle_pay_entry`;
DROP TABLE IF EXISTS `locales_battle_pay_product`;
