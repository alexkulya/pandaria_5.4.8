-- Repair double-encoded text in the locale tables.
--
-- The database holds UTF-8 that was inserted through a Windows-1252 connection,
-- so every non-ASCII character was stored as the bytes of its own encoding read
-- as separate characters. Not from these migrations: the base dump is clean,
-- the English base tables are clean, and so are the imported rows. It happened
-- when the base dump was loaded.
--
-- Each UPDATE requires three things of a row: a mojibake byte signature, a
-- reinterpretation that yields valid text rather than NULL, and - the important
-- one - re-encoding that text the same wrong way must reproduce the stored
-- value exactly. That proves the transformation is the precise inverse of the
-- damage, so correctly stored text is left alone. It also rejected 20 page_text
-- rows whose "repair" truncated the page to a fragment.

UPDATE `item_template_locale` SET `Name` = CONVERT(BINARY CONVERT(`Name` USING latin1) USING utf8mb4)
 WHERE (HEX(`Name`) LIKE '%C382%' OR HEX(`Name`) LIKE '%C383%' OR HEX(`Name`) LIKE '%C390%' OR HEX(`Name`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Name` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Name` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Name` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Name` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Name` AS BINARY);
UPDATE `item_template_locale` SET `Description` = CONVERT(BINARY CONVERT(`Description` USING latin1) USING utf8mb4)
 WHERE (HEX(`Description`) LIKE '%C382%' OR HEX(`Description`) LIKE '%C383%' OR HEX(`Description`) LIKE '%C390%' OR HEX(`Description`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Description` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Description` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Description` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Description` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Description` AS BINARY);

-- gameobject_template_locale
UPDATE `gameobject_template_locale` SET `name` = CONVERT(BINARY CONVERT(`name` USING latin1) USING utf8mb4)
 WHERE (HEX(`name`) LIKE '%C382%' OR HEX(`name`) LIKE '%C383%' OR HEX(`name`) LIKE '%C390%' OR HEX(`name`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`name` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`name` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`name` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`name` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`name` AS BINARY);
UPDATE `gameobject_template_locale` SET `castBarCaption` = CONVERT(BINARY CONVERT(`castBarCaption` USING latin1) USING utf8mb4)
 WHERE (HEX(`castBarCaption`) LIKE '%C382%' OR HEX(`castBarCaption`) LIKE '%C383%' OR HEX(`castBarCaption`) LIKE '%C390%' OR HEX(`castBarCaption`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`castBarCaption` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`castBarCaption` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`castBarCaption` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`castBarCaption` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`castBarCaption` AS BINARY);

-- creature_template_locale
UPDATE `creature_template_locale` SET `Name` = CONVERT(BINARY CONVERT(`Name` USING latin1) USING utf8mb4)
 WHERE (HEX(`Name`) LIKE '%C382%' OR HEX(`Name`) LIKE '%C383%' OR HEX(`Name`) LIKE '%C390%' OR HEX(`Name`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Name` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Name` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Name` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Name` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Name` AS BINARY);
UPDATE `creature_template_locale` SET `FemaleName` = CONVERT(BINARY CONVERT(`FemaleName` USING latin1) USING utf8mb4)
 WHERE (HEX(`FemaleName`) LIKE '%C382%' OR HEX(`FemaleName`) LIKE '%C383%' OR HEX(`FemaleName`) LIKE '%C390%' OR HEX(`FemaleName`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`FemaleName` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`FemaleName` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`FemaleName` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`FemaleName` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`FemaleName` AS BINARY);
UPDATE `creature_template_locale` SET `SubName` = CONVERT(BINARY CONVERT(`SubName` USING latin1) USING utf8mb4)
 WHERE (HEX(`SubName`) LIKE '%C382%' OR HEX(`SubName`) LIKE '%C383%' OR HEX(`SubName`) LIKE '%C390%' OR HEX(`SubName`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`SubName` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`SubName` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`SubName` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`SubName` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`SubName` AS BINARY);

-- quest_template_locale
UPDATE `quest_template_locale` SET `Title` = CONVERT(BINARY CONVERT(`Title` USING latin1) USING utf8mb4)
 WHERE (HEX(`Title`) LIKE '%C382%' OR HEX(`Title`) LIKE '%C383%' OR HEX(`Title`) LIKE '%C390%' OR HEX(`Title`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Title` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Title` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Title` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Title` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Title` AS BINARY);
UPDATE `quest_template_locale` SET `Details` = CONVERT(BINARY CONVERT(`Details` USING latin1) USING utf8mb4)
 WHERE (HEX(`Details`) LIKE '%C382%' OR HEX(`Details`) LIKE '%C383%' OR HEX(`Details`) LIKE '%C390%' OR HEX(`Details`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Details` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Details` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Details` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Details` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Details` AS BINARY);
UPDATE `quest_template_locale` SET `Objectives` = CONVERT(BINARY CONVERT(`Objectives` USING latin1) USING utf8mb4)
 WHERE (HEX(`Objectives`) LIKE '%C382%' OR HEX(`Objectives`) LIKE '%C383%' OR HEX(`Objectives`) LIKE '%C390%' OR HEX(`Objectives`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Objectives` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Objectives` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Objectives` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Objectives` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Objectives` AS BINARY);
UPDATE `quest_template_locale` SET `EndText` = CONVERT(BINARY CONVERT(`EndText` USING latin1) USING utf8mb4)
 WHERE (HEX(`EndText`) LIKE '%C382%' OR HEX(`EndText`) LIKE '%C383%' OR HEX(`EndText`) LIKE '%C390%' OR HEX(`EndText`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`EndText` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`EndText` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`EndText` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`EndText` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`EndText` AS BINARY);
UPDATE `quest_template_locale` SET `CompletedText` = CONVERT(BINARY CONVERT(`CompletedText` USING latin1) USING utf8mb4)
 WHERE (HEX(`CompletedText`) LIKE '%C382%' OR HEX(`CompletedText`) LIKE '%C383%' OR HEX(`CompletedText`) LIKE '%C390%' OR HEX(`CompletedText`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`CompletedText` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`CompletedText` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`CompletedText` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`CompletedText` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`CompletedText` AS BINARY);
UPDATE `quest_template_locale` SET `QuestGiverTextWindow` = CONVERT(BINARY CONVERT(`QuestGiverTextWindow` USING latin1) USING utf8mb4)
 WHERE (HEX(`QuestGiverTextWindow`) LIKE '%C382%' OR HEX(`QuestGiverTextWindow`) LIKE '%C383%' OR HEX(`QuestGiverTextWindow`) LIKE '%C390%' OR HEX(`QuestGiverTextWindow`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`QuestGiverTextWindow` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`QuestGiverTextWindow` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`QuestGiverTextWindow` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`QuestGiverTextWindow` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`QuestGiverTextWindow` AS BINARY);
UPDATE `quest_template_locale` SET `QuestGiverTargetName` = CONVERT(BINARY CONVERT(`QuestGiverTargetName` USING latin1) USING utf8mb4)
 WHERE (HEX(`QuestGiverTargetName`) LIKE '%C382%' OR HEX(`QuestGiverTargetName`) LIKE '%C383%' OR HEX(`QuestGiverTargetName`) LIKE '%C390%' OR HEX(`QuestGiverTargetName`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`QuestGiverTargetName` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`QuestGiverTargetName` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`QuestGiverTargetName` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`QuestGiverTargetName` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`QuestGiverTargetName` AS BINARY);
UPDATE `quest_template_locale` SET `QuestTurnTextWindow` = CONVERT(BINARY CONVERT(`QuestTurnTextWindow` USING latin1) USING utf8mb4)
 WHERE (HEX(`QuestTurnTextWindow`) LIKE '%C382%' OR HEX(`QuestTurnTextWindow`) LIKE '%C383%' OR HEX(`QuestTurnTextWindow`) LIKE '%C390%' OR HEX(`QuestTurnTextWindow`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`QuestTurnTextWindow` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`QuestTurnTextWindow` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`QuestTurnTextWindow` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`QuestTurnTextWindow` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`QuestTurnTextWindow` AS BINARY);
UPDATE `quest_template_locale` SET `QuestTurnTargetName` = CONVERT(BINARY CONVERT(`QuestTurnTargetName` USING latin1) USING utf8mb4)
 WHERE (HEX(`QuestTurnTargetName`) LIKE '%C382%' OR HEX(`QuestTurnTargetName`) LIKE '%C383%' OR HEX(`QuestTurnTargetName`) LIKE '%C390%' OR HEX(`QuestTurnTargetName`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`QuestTurnTargetName` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`QuestTurnTargetName` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`QuestTurnTargetName` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`QuestTurnTargetName` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`QuestTurnTargetName` AS BINARY);

-- quest_offer_reward_locale
UPDATE `quest_offer_reward_locale` SET `RewardText` = CONVERT(BINARY CONVERT(`RewardText` USING latin1) USING utf8mb4)
 WHERE (HEX(`RewardText`) LIKE '%C382%' OR HEX(`RewardText`) LIKE '%C383%' OR HEX(`RewardText`) LIKE '%C390%' OR HEX(`RewardText`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`RewardText` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`RewardText` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`RewardText` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`RewardText` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`RewardText` AS BINARY);

-- quest_request_items_locale
UPDATE `quest_request_items_locale` SET `CompletionText` = CONVERT(BINARY CONVERT(`CompletionText` USING latin1) USING utf8mb4)
 WHERE (HEX(`CompletionText`) LIKE '%C382%' OR HEX(`CompletionText`) LIKE '%C383%' OR HEX(`CompletionText`) LIKE '%C390%' OR HEX(`CompletionText`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`CompletionText` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`CompletionText` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`CompletionText` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`CompletionText` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`CompletionText` AS BINARY);

-- quest_objective_locale
UPDATE `quest_objective_locale` SET `Description` = CONVERT(BINARY CONVERT(`Description` USING latin1) USING utf8mb4)
 WHERE (HEX(`Description`) LIKE '%C382%' OR HEX(`Description`) LIKE '%C383%' OR HEX(`Description`) LIKE '%C390%' OR HEX(`Description`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Description` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Description` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Description` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Description` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Description` AS BINARY);

-- page_text_locale
UPDATE `page_text_locale` SET `Text` = CONVERT(BINARY CONVERT(`Text` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text`) LIKE '%C382%' OR HEX(`Text`) LIKE '%C383%' OR HEX(`Text`) LIKE '%C390%' OR HEX(`Text`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text` AS BINARY);

-- points_of_interest_locale
UPDATE `points_of_interest_locale` SET `Name` = CONVERT(BINARY CONVERT(`Name` USING latin1) USING utf8mb4)
 WHERE (HEX(`Name`) LIKE '%C382%' OR HEX(`Name`) LIKE '%C383%' OR HEX(`Name`) LIKE '%C390%' OR HEX(`Name`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Name` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Name` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Name` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Name` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Name` AS BINARY);

-- creature_text_locale
UPDATE `creature_text_locale` SET `Text` = CONVERT(BINARY CONVERT(`Text` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text`) LIKE '%C382%' OR HEX(`Text`) LIKE '%C383%' OR HEX(`Text`) LIKE '%C390%' OR HEX(`Text`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text` AS BINARY);
UPDATE `creature_text_locale` SET `TextFemale` = CONVERT(BINARY CONVERT(`TextFemale` USING latin1) USING utf8mb4)
 WHERE (HEX(`TextFemale`) LIKE '%C382%' OR HEX(`TextFemale`) LIKE '%C383%' OR HEX(`TextFemale`) LIKE '%C390%' OR HEX(`TextFemale`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`TextFemale` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`TextFemale` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`TextFemale` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`TextFemale` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`TextFemale` AS BINARY);

-- gossip_menu_option_locale
UPDATE `gossip_menu_option_locale` SET `OptionText` = CONVERT(BINARY CONVERT(`OptionText` USING latin1) USING utf8mb4)
 WHERE (HEX(`OptionText`) LIKE '%C382%' OR HEX(`OptionText`) LIKE '%C383%' OR HEX(`OptionText`) LIKE '%C390%' OR HEX(`OptionText`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`OptionText` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`OptionText` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`OptionText` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`OptionText` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`OptionText` AS BINARY);
UPDATE `gossip_menu_option_locale` SET `BoxText` = CONVERT(BINARY CONVERT(`BoxText` USING latin1) USING utf8mb4)
 WHERE (HEX(`BoxText`) LIKE '%C382%' OR HEX(`BoxText`) LIKE '%C383%' OR HEX(`BoxText`) LIKE '%C390%' OR HEX(`BoxText`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`BoxText` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`BoxText` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`BoxText` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`BoxText` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`BoxText` AS BINARY);

-- npc_text_locale
UPDATE `npc_text_locale` SET `Text0_0` = CONVERT(BINARY CONVERT(`Text0_0` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text0_0`) LIKE '%C382%' OR HEX(`Text0_0`) LIKE '%C383%' OR HEX(`Text0_0`) LIKE '%C390%' OR HEX(`Text0_0`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text0_0` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text0_0` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text0_0` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text0_0` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text0_0` AS BINARY);
UPDATE `npc_text_locale` SET `Text0_1` = CONVERT(BINARY CONVERT(`Text0_1` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text0_1`) LIKE '%C382%' OR HEX(`Text0_1`) LIKE '%C383%' OR HEX(`Text0_1`) LIKE '%C390%' OR HEX(`Text0_1`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text0_1` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text0_1` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text0_1` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text0_1` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text0_1` AS BINARY);
UPDATE `npc_text_locale` SET `Text1_0` = CONVERT(BINARY CONVERT(`Text1_0` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text1_0`) LIKE '%C382%' OR HEX(`Text1_0`) LIKE '%C383%' OR HEX(`Text1_0`) LIKE '%C390%' OR HEX(`Text1_0`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text1_0` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text1_0` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text1_0` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text1_0` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text1_0` AS BINARY);
UPDATE `npc_text_locale` SET `Text1_1` = CONVERT(BINARY CONVERT(`Text1_1` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text1_1`) LIKE '%C382%' OR HEX(`Text1_1`) LIKE '%C383%' OR HEX(`Text1_1`) LIKE '%C390%' OR HEX(`Text1_1`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text1_1` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text1_1` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text1_1` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text1_1` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text1_1` AS BINARY);
UPDATE `npc_text_locale` SET `Text2_0` = CONVERT(BINARY CONVERT(`Text2_0` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text2_0`) LIKE '%C382%' OR HEX(`Text2_0`) LIKE '%C383%' OR HEX(`Text2_0`) LIKE '%C390%' OR HEX(`Text2_0`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text2_0` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text2_0` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text2_0` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text2_0` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text2_0` AS BINARY);
UPDATE `npc_text_locale` SET `Text2_1` = CONVERT(BINARY CONVERT(`Text2_1` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text2_1`) LIKE '%C382%' OR HEX(`Text2_1`) LIKE '%C383%' OR HEX(`Text2_1`) LIKE '%C390%' OR HEX(`Text2_1`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text2_1` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text2_1` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text2_1` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text2_1` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text2_1` AS BINARY);
UPDATE `npc_text_locale` SET `Text3_0` = CONVERT(BINARY CONVERT(`Text3_0` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text3_0`) LIKE '%C382%' OR HEX(`Text3_0`) LIKE '%C383%' OR HEX(`Text3_0`) LIKE '%C390%' OR HEX(`Text3_0`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text3_0` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text3_0` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text3_0` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text3_0` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text3_0` AS BINARY);
UPDATE `npc_text_locale` SET `Text3_1` = CONVERT(BINARY CONVERT(`Text3_1` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text3_1`) LIKE '%C382%' OR HEX(`Text3_1`) LIKE '%C383%' OR HEX(`Text3_1`) LIKE '%C390%' OR HEX(`Text3_1`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text3_1` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text3_1` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text3_1` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text3_1` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text3_1` AS BINARY);
UPDATE `npc_text_locale` SET `Text4_0` = CONVERT(BINARY CONVERT(`Text4_0` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text4_0`) LIKE '%C382%' OR HEX(`Text4_0`) LIKE '%C383%' OR HEX(`Text4_0`) LIKE '%C390%' OR HEX(`Text4_0`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text4_0` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text4_0` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text4_0` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text4_0` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text4_0` AS BINARY);
UPDATE `npc_text_locale` SET `Text4_1` = CONVERT(BINARY CONVERT(`Text4_1` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text4_1`) LIKE '%C382%' OR HEX(`Text4_1`) LIKE '%C383%' OR HEX(`Text4_1`) LIKE '%C390%' OR HEX(`Text4_1`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text4_1` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text4_1` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text4_1` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text4_1` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text4_1` AS BINARY);
UPDATE `npc_text_locale` SET `Text5_0` = CONVERT(BINARY CONVERT(`Text5_0` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text5_0`) LIKE '%C382%' OR HEX(`Text5_0`) LIKE '%C383%' OR HEX(`Text5_0`) LIKE '%C390%' OR HEX(`Text5_0`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text5_0` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text5_0` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text5_0` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text5_0` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text5_0` AS BINARY);
UPDATE `npc_text_locale` SET `Text5_1` = CONVERT(BINARY CONVERT(`Text5_1` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text5_1`) LIKE '%C382%' OR HEX(`Text5_1`) LIKE '%C383%' OR HEX(`Text5_1`) LIKE '%C390%' OR HEX(`Text5_1`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text5_1` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text5_1` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text5_1` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text5_1` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text5_1` AS BINARY);
UPDATE `npc_text_locale` SET `Text6_0` = CONVERT(BINARY CONVERT(`Text6_0` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text6_0`) LIKE '%C382%' OR HEX(`Text6_0`) LIKE '%C383%' OR HEX(`Text6_0`) LIKE '%C390%' OR HEX(`Text6_0`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text6_0` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text6_0` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text6_0` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text6_0` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text6_0` AS BINARY);
UPDATE `npc_text_locale` SET `Text6_1` = CONVERT(BINARY CONVERT(`Text6_1` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text6_1`) LIKE '%C382%' OR HEX(`Text6_1`) LIKE '%C383%' OR HEX(`Text6_1`) LIKE '%C390%' OR HEX(`Text6_1`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text6_1` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text6_1` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text6_1` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text6_1` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text6_1` AS BINARY);
UPDATE `npc_text_locale` SET `Text7_0` = CONVERT(BINARY CONVERT(`Text7_0` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text7_0`) LIKE '%C382%' OR HEX(`Text7_0`) LIKE '%C383%' OR HEX(`Text7_0`) LIKE '%C390%' OR HEX(`Text7_0`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text7_0` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text7_0` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text7_0` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text7_0` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text7_0` AS BINARY);
UPDATE `npc_text_locale` SET `Text7_1` = CONVERT(BINARY CONVERT(`Text7_1` USING latin1) USING utf8mb4)
 WHERE (HEX(`Text7_1`) LIKE '%C382%' OR HEX(`Text7_1`) LIKE '%C383%' OR HEX(`Text7_1`) LIKE '%C390%' OR HEX(`Text7_1`) LIKE '%C391%')
   AND CONVERT(BINARY CONVERT(`Text7_1` USING latin1) USING utf8mb4) IS NOT NULL
   AND CAST(CONVERT(BINARY CONVERT(`Text7_1` USING latin1) USING utf8mb4) AS BINARY) <> CAST(`Text7_1` AS BINARY)
   AND CAST(CONVERT(CONVERT(BINARY CONVERT(CONVERT(BINARY CONVERT(`Text7_1` USING latin1) USING utf8mb4) USING utf8mb4) USING latin1) USING utf8mb4) AS BINARY) = CAST(`Text7_1` AS BINARY);
