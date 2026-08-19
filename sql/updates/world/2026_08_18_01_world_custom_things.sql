UPDATE `creature_template` SET `name` = "Turtle", `subname` = "Daily Quests", `modelid1` = 29161, `modelid2` = 0, `scale` = 1.2, `npcflag` = 3, `ScriptName` = "", `flags_extra` = 0 WHERE `entry` = 190001;
UPDATE `creature_template` SET `name` = "Orc", `subname` = "Master of Transmogrification", `modelid1` = 29187, `modelid2` = 0, `scale` = 1, `npcflag` = 1, `ScriptName` = "npc_transmogrifier", `flags_extra` = 0 WHERE `entry` = 190002;
DELETE FROM `creature` WHERE `id` IN (190001, 190002, 190003, 190004, 190005, 190006, 190007, 190008, 190009, 190010, 190011, 190013);
DELETE FROM `creature_template` WHERE `entry` IN (190003, 190004, 190005, 190006, 190007, 190008, 190009, 190010, 190011, 190013);
DELETE FROM `creature_template_locale` WHERE `entry` IN (190003, 190004, 190005, 190006, 190007, 190008, 190009, 190010, 190011, 190013);
DELETE FROM `creature_template_addon` WHERE `entry` IN (190001, 190002, 190003, 190004, 190005, 190006, 190007, 190008, 190009, 190010, 190011, 190013);
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (190001, 190002, 190003, 190004, 190005, 190006, 190007, 190008, 190009, 190010, 190011, 190013));
DELETE FROM `gossip_menu_option` WHERE `menu_id` BETWEEN 63000 AND 63021;
DELETE FROM `gossip_menu_option_locale` WHERE `MenuID` BETWEEN 63000 AND 63021;
DELETE FROM `gossip_menu` WHERE `entry` BETWEEN 63000 AND 63021;
DELETE FROM `npc_text` WHERE `ID` IN (110000, 110001, 110002, 110003, 110004, 110005, 110006);
DELETE FROM `npc_text_locale` WHERE `ID` IN (110000, 110001, 110002, 110003, 110004, 110005, 110006);
DELETE FROM `npc_vendor` WHERE `entry` IN (190001, 190003);
DELETE FROM `npc_trainer` WHERE `entry` IN (190003, 190004);
DELETE FROM `creature_queststarter` WHERE `id` = 190001;
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(190001, 40000), (190001, 40001), (190001, 40002), (190001, 40003), (190001, 40004), (190001, 40005), (190001, 40006), (190001, 40007),
(190001, 40008), (190001, 40009), (190001, 40010), (190001, 40011), (190001, 40012), (190001, 40013), (190001, 40014), (190001, 40015),
(190001, 40016), (190001, 40017), (190001, 40018), (190001, 40019), (190001, 40020), (190001, 40021), (190001, 40022), (190001, 40023),
(190001, 40024), (190001, 40025), (190001, 40026), (190001, 40027), (190001, 40028), (190001, 40029), (190001, 40030), (190001, 40031),
(190001, 40032), (190001, 40033), (190001, 40034), (190001, 40035), (190001, 40036), (190001, 40037), (190001, 40038), (190001, 40039),
(190001, 40040), (190001, 40100), (190001, 40101), (190001, 40102), (190001, 40103), (190001, 40104), (190001, 40105), (190001, 40106),
(190001, 40107), (190001, 40108), (190001, 40109), (190001, 40110), (190001, 40111), (190001, 40112), (190001, 40113), (190001, 40114),
(190001, 40115), (190001, 40120), (190001, 40121), (190001, 40122), (190001, 40123), (190001, 40124), (190001, 40125), (190001, 40126),
(190001, 40127), (190001, 40128), (190001, 40129), (190001, 40130), (190001, 40131), (190001, 40132), (190001, 40133), (190001, 40134),
(190001, 40135), (190001, 40136), (190001, 40137), (190001, 40138), (190001, 40139), (190001, 40140), (190001, 40141), (190001, 40142),
(190001, 40143), (190001, 40144), (190001, 40145), (190001, 40146), (190001, 40147), (190001, 40148), (190001, 40149), (190001, 40150),
(190001, 40151), (190001, 40152), (190001, 40153), (190001, 40154), (190001, 40155), (190001, 40190), (190001, 40191), (190001, 40192),
(190001, 40193), (190001, 40200), (190001, 40201), (190001, 40202), (190001, 40203), (190001, 40204), (190001, 40205), (190001, 40206),
(190001, 40300), (190001, 40301), (190001, 40302), (190001, 40303), (190001, 40304), (190001, 40305), (190001, 40306), (190001, 40307),
(190001, 40308), (190001, 40309), (190001, 40310), (190001, 40311);
DELETE FROM `creature_questender` WHERE `id` = 190001;
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(190001, 40000), (190001, 40001), (190001, 40002), (190001, 40003), (190001, 40004), (190001, 40005), (190001, 40006), (190001, 40007),
(190001, 40008), (190001, 40009), (190001, 40010), (190001, 40011), (190001, 40012), (190001, 40013), (190001, 40014), (190001, 40015),
(190001, 40016), (190001, 40017), (190001, 40018), (190001, 40019), (190001, 40020), (190001, 40021), (190001, 40022), (190001, 40023),
(190001, 40024), (190001, 40025), (190001, 40026), (190001, 40027), (190001, 40028), (190001, 40029), (190001, 40030), (190001, 40031),
(190001, 40032), (190001, 40033), (190001, 40034), (190001, 40035), (190001, 40036), (190001, 40037), (190001, 40038), (190001, 40039),
(190001, 40040), (190001, 40100), (190001, 40101), (190001, 40102), (190001, 40103), (190001, 40104), (190001, 40105), (190001, 40106),
(190001, 40107), (190001, 40108), (190001, 40109), (190001, 40110), (190001, 40111), (190001, 40112), (190001, 40113), (190001, 40114),
(190001, 40115), (190001, 40120), (190001, 40121), (190001, 40122), (190001, 40123), (190001, 40124), (190001, 40125), (190001, 40126),
(190001, 40127), (190001, 40128), (190001, 40129), (190001, 40130), (190001, 40131), (190001, 40132), (190001, 40133), (190001, 40134),
(190001, 40135), (190001, 40136), (190001, 40137), (190001, 40138), (190001, 40139), (190001, 40140), (190001, 40141), (190001, 40142),
(190001, 40143), (190001, 40144), (190001, 40145), (190001, 40146), (190001, 40147), (190001, 40148), (190001, 40149), (190001, 40150),
(190001, 40151), (190001, 40152), (190001, 40153), (190001, 40154), (190001, 40155), (190001, 40190), (190001, 40191), (190001, 40192),
(190001, 40193), (190001, 40200), (190001, 40201), (190001, 40202), (190001, 40203), (190001, 40204), (190001, 40205), (190001, 40206),
(190001, 40300), (190001, 40301), (190001, 40302), (190001, 40303), (190001, 40304), (190001, 40305), (190001, 40306), (190001, 40307),
(190001, 40308), (190001, 40309), (190001, 40310), (190001, 40311);
UPDATE `quest_template` SET `SpecialFlags` = 1 WHERE `Id` BETWEEN 40000 AND 40040;
UPDATE `quest_template` SET `SpecialFlags` = 1 WHERE `Id` BETWEEN 40100 AND 40115;
UPDATE `quest_template` SET `SpecialFlags` = 1 WHERE `Id` BETWEEN 40120 AND 40155;
UPDATE `quest_template` SET `SpecialFlags` = 1 WHERE `Id` BETWEEN 40190 AND 40193;
UPDATE `quest_template` SET `SpecialFlags` = 1 WHERE `Id` BETWEEN 40200 AND 40206;
UPDATE `quest_template` SET `SpecialFlags` = 1 WHERE `Id` BETWEEN 40300 AND 40311;
DELETE FROM `pool_template` WHERE `entry` IN (40000, 40001, 40002, 40003, 40004, 40005, 40006, 40007, 40008, 40009, 40010, 40011, 40012, 40013, 40014, 40015, 40016, 40017, 40018, 40019);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(40000, 1, "Daily Quests (Pack 1)"),
(40001, 1, "Daily Quests (Pack 2)"),
(40002, 1, "Daily Quests (Pack 3)"),
(40003, 1, "Daily Quests (Pack 4)"),
(40004, 1, "Daily Quests (Pack 5)"),
(40005, 1, "Daily Quests (Pack 6)"),
(40006, 1, "Daily Quests (Pack 7)"),
(40007, 1, "Daily Quests (Pack 8)"),
(40008, 1, "Daily Quests (Pack 9)"),
(40009, 1, "Daily Quests (Pack 10)"),
(40010, 1, "Daily Quests (Pack 11)"),
(40011, 1, "Daily Quests (Pack 12)"),
(40012, 1, "Daily Quests (Pack 13)"),
(40013, 1, "Daily Quests (Pack 14)"),
(40014, 1, "Daily Quests (Pack 15)"),
(40015, 1, "Daily Quests (Pack 16)"),
(40016, 1, "Daily Quests (Pack 17)"),
(40017, 1, "Daily Quests (Pack 18)"),
(40018, 1, "Daily Quests (Pack 19)"),
(40019, 1, "Daily Quests (Pack 20)");
DELETE FROM `pool_quest` WHERE `pool_entry` IN (40000, 40001, 40002, 40003, 40004, 40005, 40006, 40007, 40008, 40009, 40010, 40011, 40012, 40013, 40014, 40015, 40016, 40017, 40018, 40019);
INSERT INTO `pool_quest` (`entry`, `pool_entry`, `chance`, `description`) VALUES
(40000, 40000, 0, "PvE: Scarlet Monastery"), (40001, 40000, 0, "PvE: Dire Maul"), (40002, 40000, 0, "PvE: Barrens"), (40003, 40000, 0 ,"PvE: Plaguelands"),
(40004, 40000, 0, "PvE: Maraudon"), (40005, 40000, 0, "PvE: Blackrock Mountain"), (40006, 40000, 0, "PvE: City Dungeons"), (40007, 40000, 0, "PvE: Ancient Dungeons"),
(40008, 40000, 0, "PvE: Variety Classic Dungeons"), (40009, 40001, 0, "PvE: Hellfire Peninsula (Normal)"), (40010, 40001, 0, "PvE: Hellfire Peninsula (Heroic)"), (40011, 40001, 0, "PvE: Zangarmarsh (Normal)"),
(40012, 40001, 0, "PvE: Zangarmarsh (Heroic)"), (40013, 40001, 0, "PvE: Auchindon (Normal)"), (40014, 40001, 0, "PvE: Auchindon (Heroic)"), (40015, 40001, 0, "PvE: Netherstorm (Normal)"),
(40016, 40001, 0, "PvE: Netherstorm (Heroic)"), (40017, 40001, 0, "PvE: Variety Burning Crusade Dungeons (Normal)"), (40018, 40001, 0, "PvE: Variety Burning Crusade Dungeons (Heroic)"), (40019, 40002, 0, "PvE: Trolls and Vrykuls (Normal)"),
(40020, 40002, 0, "PvE: Trolls and Vrykuls (Heroic)"), (40021, 40002, 0, "PvE: Arachnids and Dragons (Normal)"), (40022, 40002, 0, "PvE: Arachnids and Dragons (Heroic)"), (40023, 40002, 0, "PvE: Past and Present (Normal)"),
(40024, 40002, 0, "PvE: Past and Present (Heroic)"), (40025, 40002, 0, "PvE: Final Destination (Normal)"), (40026, 40002, 0, "PvE: Final Destination (Heroic)"), (40027, 40003, 0, "PvE: Old Good Times (Heroic)"),
(40028, 40003, 0, "PvE: Earth, Air and Water (Normal)"), (40029, 40003, 0, "PvE: Earth, Air and Water (Heroic)"), (40030, 40003, 0, "PvE: Lost in The Sands (Normal)"), (40031, 40003, 0, "PvE: Lost in The Sands (Heroic)"),
(40032, 40003, 0, "PvE: Twilight Hammer Yet Again (Normal)"), (40033, 40003, 0, "PvE: Twilight Hammer Yet Again (Heroic)"), (40034, 40003, 0, "PvE: Trolls and Their Gods (Heroic)"), (40035, 40003, 0, "PvE: Lost in Time (Heroic)"),
(40036, 40004, 0, "PvE: Seen Better Days (Heroic)"), (40037, 40004, 0, "PvE: Exotic Places (Normal)"), (40038, 40004, 0, "PvE: Exotic Places (Heroic)"), (40039, 40004, 0, "PvE: Ancient Enemies (Normal)"),
(40040, 40004, 0, "PvE: Ancient Enemies (Heroic)"), (40100, 40005, 0, "World: Master Crafter"), (40113, 40005, 0, "World: Punctuation Master"), (40114, 40005, 0, "World: Lover of Antiquities"),
(40115, 40005, 0, "World: Artifact Master"), (40101, 40006, 0, "World: Dungeon Enthusiast"), (40102, 40006, 0, "World: Raid Enthusiast"), (40103, 40006, 0, "World: Scenario Enthusiast"),
(40104, 40006, 0, "World: Challenge Enthusiast"), (40105, 40006, 0, "World: Raid Finder Enthusiast"), (40106, 40007, 0, "World: Small Game Hunter"), (40107, 40007, 0, "World: Small Game Hunter"),
(40108, 40007, 0, "World: Small Game Hunter"), (40109, 40008, 0, "World: Variety Hunter"), (40110, 40008, 0, "World: Variety Hunter"), (40111, 40008, 0, "World: Variety Hunter"),
(40112, 40008, 0, "World: Variety Hunter"), (40120, 40009, 0, "World: Fishing in Eastern Kingdoms"), (40121, 40009, 0, "World: Fishing in Eastern Kingdoms"), (40122, 40009, 0, "World: Fishing in Eastern Kingdoms"),
(40123, 40009, 0, "World: Fishing in Eastern Kingdoms"), (40124, 40009, 0, "World: Fishing in Eastern Kingdoms"), (40125, 40009, 0, "World: Fishing in Eastern Kingdoms"), (40126, 40009, 0, "World: Fishing in Eastern Kingdoms"),
(40127, 40009, 0, "World: Fishing in Eastern Kingdoms"), (40128, 40009, 0, "World: Fishing in Eastern Kingdoms"), (40129, 40009, 0, "World: Fishing in Eastern Kingdoms"), (40130, 40010, 0, "World: Fishing in Kalimdor"),
(40131, 40010, 0, "World: Fishing in Kalimdor"), (40132, 40010, 0, "World: Fishing in Kalimdor"), (40133, 40010, 0, "World: Fishing in Kalimdor"), (40134, 40010, 0, "World: Fishing in Kalimdor"),
(40135, 40010, 0, "World: Fishing in Kalimdor"), (40136, 40010, 0, "World: Fishing in Kalimdor"), (40137, 40010, 0, "World: Fishing in Kalimdor"), (40138, 40010, 0, "World: Fishing in Kalimdor"),
(40139, 40010, 0, "World: Fishing in Kalimdor"), (40140, 40011, 0, "World: Fishing in Outland"), (40141, 40011, 0, "World: Fishing in Outland"), (40142, 40011, 0, "World: Fishing in Outland"),
(40143, 40012, 0, "World: Fishing in Northrend"), (40144, 40012, 0, "World: Fishing in Northrend"), (40145, 40012, 0, "World: Fishing in Northrend"), (40146, 40012, 0, "World: Fishing in Northrend"),
(40147, 40012, 0, "World: Fishing in Northrend"), (40148, 40013, 0, "World: Fishing in New Lands of Kalimdor"), (40149, 40013, 0, "World: Fishing in New Lands of Eastern Kingdoms"), (40150, 40013, 0, "World: Fishing in New Lands"),
(40151, 40014, 0, "World: Fishing in Pandaria"), (40152, 40014, 0, "World: Fishing in Pandaria"), (40153, 40014, 0, "World: Fishing in Pandaria"), (40154, 40014, 0, "World: Fishing in Pandaria"),
(40155, 40014, 0, "World: Fishing in Pandaria"), (40190, 40015, 0, "World: Regicide"), (40191, 40015, 0, "World: Regicide"), (40192, 40015, 0, "World: Regicide"),
(40193, 40015, 0, "World: Regicide"), (40311, 40015, 0, "PvP: Rated Conqueror"), (40200, 40016, 0, "PvP: Arena"), (40206, 40016, 0, "PvP: Unholy Trinity"),
(40201, 40017, 0, "PvP: King of Big Numbers"), (40202, 40017, 0, "PvP: Battleground Warrior"), (40203, 40017, 0, "PvP: Outdoor Warrior"), (40204, 40018, 0, "PvP: Wintergrasp"),
(40205, 40018, 0, "PvP: Tol Barad"), (40300, 40019, 0, "PvP: Alterac Valley"), (40301, 40019, 0, "PvP: Warsong Gulch"), (40302, 40019, 0, "PvP: Arathi Basin"),
(40303, 40019, 0, "PvP: Eye of The Storm"), (40304, 40019, 0, "PvP: Strand of the Ancients"), (40305, 40019, 0, "PvP: Isle of Conquest"), (40306, 40019, 0, "PvP: Twin Peaks"),
(40307, 40019, 0, "PvP: The Battle for Gilneas"), (40308, 40019, 0, "PvP: Temple of Kotmogu"), (40309, 40019, 0, "PvP: Deepwind Gorge"), (40310, 40019, 0, "PvP: Silvershard Mines");
UPDATE `quest_template` SET `Objectives` = "Participate in a kill of one of your enemy faction's leader.$B$BToday's targets are:$BAlliance players: Garrosh Hellscream$BHorde players: King Varian Wrynn.", `RequestItemsText` = "Participate in a kill of one of your enemy faction's leader.$B$BToday's targets are:$BAlliance players: Garrosh Hellscream$BHorde players: King Varian Wrynn." WHERE `Id` = 40190;
UPDATE `quest_template` SET `Objectives` = "Participate in a kill of one of your enemy faction's leader.$B$BToday's targets are:$BAlliance players: Baine Bloodhoof$BHorde players: Muradin Bronzebeard.", `RequestItemsText` = "Participate in a kill of one of your enemy faction's leader.$B$BToday's targets are:$BAlliance players: Baine Bloodhoof$BHorde players: Muradin Bronzebeard." WHERE `Id` = 40191;
UPDATE `quest_template` SET `Objectives` = "Participate in a kill of one of your enemy faction's leader.$B$BToday's targets are:$BAlliance players: Lady Sylvanas Windrunner$BHorde players: High Priestess Tyrande Whisperwind.", `RequestItemsText` = "Participate in a kill of one of your enemy faction's leader.$B$BToday's targets are:$BAlliance players: Lady Sylvanas Windrunner$BHorde players: High Priestess Tyrande Whisperwind." WHERE `Id` = 40192;
UPDATE `quest_template` SET `Objectives` = "Participate in a kill of one of your enemy faction's leader.$B$BToday's targets are:$BAlliance players: Lor'themar Theron$BHorde players: Prophet Velen.", `RequestItemsText` = "Participate in a kill of one of your enemy faction's leader.$B$BToday's targets are:$BAlliance players: Lor'themar Theron$BHorde players: Prophet Velen." WHERE `Id` = 40193;
UPDATE `quest_template_locale` SET `Title` = "PvE: Монастырь Алого ордена (об.)", `Objectives` = "Пройдите любое крыло подземелья Монастырь Алого ордена на обычном уровне сложности." WHERE `ID` = 40000;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое крыло подземелья Монастырь Алого ордена на обычном уровне сложности." WHERE `ID` = 40000 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Забытый Город", `Objectives` = "Пройдите любое крыло подземелья Забытый Город." WHERE `ID` = 40001;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое крыло подземелья Забытый Город." WHERE `ID` = 40001 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Степи", `Objectives` = "Пройдите любое подземелье, находящееся в Степях." WHERE `ID` = 40002;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье, находящееся в Степях." WHERE `ID` = 40002 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Чумные земли (об.)", `Objectives` = "Пройдите любое подземелье, находящееся в Восточных или Западных Чумных землях на обычном уровне сложности." WHERE `ID` = 40003;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье, находящееся в Восточных или Западных Чумных землях на обычном уровне сложности." WHERE `ID` = 40003 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Мародон", `Objectives` = "Пройдите любое крыло подземелья Мародон." WHERE `ID` = 40004;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое крыло подземелья Мародон." WHERE `ID` = 40004 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Черная гора", `Objectives` = "Пройдите любое подземелье, находящееся в Черной горе." WHERE `ID` = 40005;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье, находящееся в Черной горе." WHERE `ID` = 40005 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Городские подземелья", `Objectives` = "Пройдите любое подземелье, находящееся в городах." WHERE `ID` = 40006;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье, находящееся в городах." WHERE `ID` = 40006 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Древние подземелья", `Objectives` = "Пройдите любое подземелье из перечисленного списка: Непроглядная Пучина, Ульдаман или Затонувший храм." WHERE `ID` = 40007;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка: Непроглядная Пучина, Ульдаман или Затонувший храм." WHERE `ID` = 40007 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Разные классические подземелья (об.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Мертвые копи, Крепость Темного Клыка или Зул'Фаррак." WHERE `ID` = 40008;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Мертвые копи, Крепость Темного Клыка или Зул'Фаррак." WHERE `ID` = 40008 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Полуостров Адского Пламени (об.)", `Objectives` = "Пройдите любое подземелье, находящееся на Полуострове Адского Пламени, на обычном уровне сложности." WHERE `ID` = 40009;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье, находящееся на Полуострове Адского Пламени, на обычном уровне сложности." WHERE `ID` = 40009 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Полуостров Адского Пламени (гер.)", `Objectives` = "Пройдите любое подземелье, находящееся на Полуострове Адского Пламени, на героическом уровне сложности." WHERE `ID` = 40010;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье, находящееся на Полуострове Адского Пламени, на героическом уровне сложности." WHERE `ID` = 40010 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Зангартопь (об.)", `Objectives` = "Пройдите любое подземелье, находящееся в Зангартопи, на обычном уровне сложности." WHERE `ID` = 40011;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье, находящееся в Зангартопи, на обычном уровне сложности." WHERE `ID` = 40011 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Зангартопь (гер.)", `Objectives` = "Пройдите любое подземелье, находящееся в Зангартопи, на героическом уровне сложности." WHERE `ID` = 40012;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье, находящееся в Зангартопи, на героическом уровне сложности." WHERE `ID` = 40012 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Аукидон (об.)", `Objectives` = "Пройдите любое подземелье, находящееся в Аукидоне, на обычном уровне сложности." WHERE `ID` = 40013;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье, находящееся в Аукидоне, на обычном уровне сложности." WHERE `ID` = 40013 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Аукидон (гер.)", `Objectives` = "Пройдите любое подземелье, находящееся в Аукидоне, на героическом уровне сложности." WHERE `ID` = 40014;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье, находящееся в Аукидоне, на героическом уровне сложности." WHERE `ID` = 40014 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Пустоверть (об.)", `Objectives` = "Пройдите любое подземелье, находящееся в Пустоверти, на обычном уровне сложности." WHERE `ID` = 40015;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье, находящееся в Пустоверти, на обычном уровне сложности." WHERE `ID` = 40015 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Пустоверь (гер.)", `Objectives` = "Пройдите любое подземелье, находящееся в Пустоверти, на героическом уровне сложности." WHERE `ID` = 40016;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье, находящееся в Пустоверти, на героическом уровне сложности." WHERE `ID` = 40016 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Разные подземелья Burning Crusade (об.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Побег из Дарнхольда, Черные топи или Терраса Магистров." WHERE `ID` = 40017;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Побег из Дарнхольда, Черные топи или Терраса Магистров." WHERE `ID` = 40017 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Разные подземелья Burning Crusade (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Побег из Дарнхольда, Черные топи или Терраса Магистров." WHERE `ID` = 40018;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Побег из Дарнхольда, Черные топи или Терраса Магистров." WHERE `ID` = 40018 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Тролли и врайкулы (об.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Крепость Драк'Тарон, Гундрак, Крепость Утгард или Вершина Утгард." WHERE `ID` = 40019;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Крепость Драк'Тарон, Гундрак, Крепость Утгард или Вершина Утгард." WHERE `ID` = 40019 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Тролли и врайкулы (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Крепость Драк'Тарон, Гундрак, Крепость Утгард или Вершина Утгард." WHERE `ID` = 40020;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Крепость Драк'Тарон, Гундрак, Крепость Утгард или Вершина Утгард." WHERE `ID` = 40020 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Членистоногие и крылатые (об.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Азжол-Неруб, Ан'кахет: Старое Королевство, Окулус или Нексус." WHERE `ID` = 40021;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Азжол-Неруб, Ан'кахет: Старое Королевство, Окулус или Нексус." WHERE `ID` = 40021 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Членистоногие и крылатые (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Азжол-Неруб, Ан'кахет: Старое Королевство, Окулус или Нексус." WHERE `ID` = 40022;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Азжол-Неруб, Ан'кахет: Старое Королевство, Окулус или Нексус." WHERE `ID` = 40022 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Прошлое и настоящее (об.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Очищение Стратхольма, Аметистовая крепость, Чертоги Молний или Чертоги Камня." WHERE `ID` = 40023;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Очищение Стратхольма, Аметистовая крепость, Чертоги Молний или Чертоги Камня." WHERE `ID` = 40023 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Прошлое и настоящее (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Очищение Стратхольма, Аметистовая крепость, Чертоги Молний или Чертоги Камня." WHERE `ID` = 40024;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Очищение Стратхольма, Аметистовая крепость, Чертоги Молний или Чертоги Камня." WHERE `ID` = 40024 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Конечная остановка (об.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Испытание чемпиона, Кузня Душ, Яма Сарона или Залы Отражений." WHERE `ID` = 40025;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Испытание чемпиона, Кузня Душ, Яма Сарона или Залы Отражений." WHERE `ID` = 40025 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Конечная остановка (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Испытание чемпиона, Кузня Душ, Яма Сарона или Залы Отражений." WHERE `ID` = 40026;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Испытание чемпиона, Кузня Душ, Яма Сарона или Залы Отражений." WHERE `ID` = 40026 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Старые добрые времена (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Крепость Темного Клыка или Мертвые копи." WHERE `ID` = 40027;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Крепость Темного Клыка или Мертвые копи." WHERE `ID` = 40027 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Земля, воздух и вода (об.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Каменные Недра, Вершина Смерча или Трон Приливов." WHERE `ID` = 40028;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Каменные Недра, Вершина Смерча или Трон Приливов." WHERE `ID` = 40028 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Земля, воздух и вода (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Каменные Недра, Вершина Смерча или Трон Приливов." WHERE `ID` = 40029;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Каменные Недра, Вершина Смерча или Трон Приливов." WHERE `ID` = 40029 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Затерянные в песках (об.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Затерянный город Тол'вир или Чертоги Созидания." WHERE `ID` = 40030;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Затерянный город Тол'вир или Чертоги Созидания." WHERE `ID` = 40030 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Затерянные в песках (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Затерянный город Тол'вир или Чертоги Созидания." WHERE `ID` = 40031;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Затерянный город Тол'вир или Чертоги Созидания." WHERE `ID` = 40031 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Опять Сумеречный Молот (об.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Грим Батол или Пещеры Черной горы." WHERE `ID` = 40032;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Грим Батол или Пещеры Черной горы." WHERE `ID` = 40032 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Опять Сумеречный Молот (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Грим Батол или Пещеры Черной горы." WHERE `ID` = 40033;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Грим Батол или Пещеры Черной горы." WHERE `ID` = 40033 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Тролли и их боги (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровни сложности: Зул'гуруб или Зул'Аман." WHERE `ID` = 40034;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровни сложности: Зул'гуруб или Зул'Аман." WHERE `ID` = 40034 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Потерянные во времени (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Конец Времен, Источник Вечности или Время Сумерек." WHERE `ID` = 40035;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Конец Времен, Источник Вечности или Время Сумерек." WHERE `ID` = 40035 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Бывали и лучшие времена (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Некроситет, Монастырь Алого ордена или Залы Алого ордена." WHERE `ID` = 40036;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Некроситет, Монастырь Алого ордена или Залы Алого ордена." WHERE `ID` = 40036 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Экзотические места (об.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Хмелеварня Буйных Портеров, Храм Нефритовой Змеи или Монастырь Шадо-Пан." WHERE `ID` = 40037;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Хмелеварня Буйных Портеров, Храм Нефритовой Змеи или Монастырь Шадо-Пан." WHERE `ID` = 40037 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Экзотические места (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Хмелеварня Буйных Портеров, Храм Нефритовой Змеи или Монастырь Шадо-Пан." WHERE `ID` = 40038;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Хмелеварня Буйных Портеров, Храм Нефритовой Змеи или Монастырь Шадо-Пан." WHERE `ID` = 40038 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Древние враги (об.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Врата Заходящего Солнца, Осада храма Нюцзао или Дворец Могу'шан." WHERE `ID` = 40039;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на обычном уровне сложности: Врата Заходящего Солнца, Осада храма Нюцзао или Дворец Могу'шан." WHERE `ID` = 40039 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvE: Древние враги (гер.)", `Objectives` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Врата Заходящего Солнца, Осада храма Нюцзао или Дворец Могу'шан." WHERE `ID` = 40040;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое подземелье из перечисленного списка на героическом уровне сложности: Врата Заходящего Солнца, Осада храма Нюцзао или Дворец Могу'шан." WHERE `ID` = 40040 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Мастер на все руки", `Objectives` = "Изготовьте несколько предметов.$b$b- ИЛИ -$b$bВыкопайте руду, соберите траву или снимите шкуру несколько раз." WHERE `ID` = 40100;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Изготовьте несколько предметов.$b$b- ИЛИ -$b$bВыкопайте руду, соберите траву или снимите шкуру несколько раз." WHERE `ID` = 40100 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Любитель подземелий", `Objectives` = "Пройдите любое случайное подземелье обычного или героического уровня сложности в составе группы, собранной через Поиск Подземелий." WHERE `ID` = 40101;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое случайное подземелье обычного или героического уровня сложности в составе группы, собранной через Поиск Подземелий." WHERE `ID` = 40101 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рейдер-энтузиаст", `Objectives` = "Убейте любого рейдового босса." WHERE `ID` = 40102;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Убейте любого рейдового босса." WHERE `ID` = 40102 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Любитель сценариев", `Objectives` = "Пройдите любой сценарий." WHERE `ID` = 40103;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любой сценарий." WHERE `ID` = 40103 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Любитель испытаний", `Objectives` = "Пройдите любое испытание." WHERE `ID` = 40104;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любое испытание." WHERE `ID` = 40104 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Любитель поиска рейдов", `Objectives` = "Пройдите любой рейд, используя Поиск Рейдов." WHERE `ID` = 40105;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Пройдите любой рейд, используя Поиск Рейдов." WHERE `ID` = 40105 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Не совсем великий охотник", `Objectives` = "Убейте существ, относящихся к одному из перечисленных семейств: Волки, Медведи, Долгоноги или Кроколиски." WHERE `ID` = 40106;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Убейте существ, относящихся к одному из перечисленных семейств: Волки, Медведи, Долгоноги или Кроколиски." WHERE `ID` = 40106 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Не совсем великий охотник", `Objectives` = "Убейте существ, относящихся к одному из перечисленных семейств: Кошки, Скорпиды, Вепри или Гиены." WHERE `ID` = 40107;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Убейте существ, относящихся к одному из перечисленных семейств: Кошки, Скорпиды, Вепри или Гиены." WHERE `ID` = 40107 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Не совсем великий охотник", `Objectives` = "Убейте существ, относящихся к одному из перечисленных семейств: Пауки, Ящеры, Крабы или Летучие мыши." WHERE `ID` = 40108;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Убейте существ, относящихся к одному из перечисленных семейств: Пауки, Ящеры, Крабы или Летучие мыши." WHERE `ID` = 40108 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Охотник на всякую всячину", `Objectives` = "Убейте существ, относящихся к одному из перечисленных видов: Элементали или Драконы." WHERE `ID` = 40109;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Убейте существ, относящихся к одному из перечисленных видов: Элементали или Драконы." WHERE `ID` = 40109 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Охотник на всякую всячину", `Objectives` = "Убейте существ, относящихся к одному из перечисленных видов: Демоны или Механизмы." WHERE `ID` = 40110;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Убейте существ, относящихся к одному из перечисленных видов: Демоны или Механизмы." WHERE `ID` = 40110 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Охотник на всякую всячину", `Objectives` = "Убейте существ, относящихся к одному из перечисленных видов: Нежить или Великаны." WHERE `ID` = 40111;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Убейте существ, относящихся к одному из перечисленных видов: Нежить или Великаны." WHERE `ID` = 40111 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Охотник на всякую всячину", `Objectives` = "Убейте существ, относящихся к одному из перечисленных видов: Мелкие существа." WHERE `ID` = 40112;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Убейте существ, относящихся к одному из перечисленных видов: Мелкие существа." WHERE `ID` = 40112 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Мастер пунктуации", `Objectives` = "Выполните определенное количество заданий. Выполнение Заданий Лояльности не влияет на прогресс этого задания, однако другие повторяемые задания - влияют." WHERE `ID` = 40113;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Выполните определенное количество заданий. Выполнение Заданий Лояльности не влияет на прогресс этого задания, однако другие повторяемые задания - влияют." WHERE `ID` = 40113 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Любитель древностей", `Objectives` = "Проведите определенное количество археологических исследований на любом континенте." WHERE `ID` = 40114;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Проведите определенное количество археологических исследований на любом континенте." WHERE `ID` = 40114 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Мастер артефактов", `Objectives` = "Соберите определенное количество археологических артефактов." WHERE `ID` = 40115;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Соберите определенное количество археологических артефактов." WHERE `ID` = 40115 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Восточных королевствах", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Дун Морог или Призрачные земли." WHERE `ID` = 40120;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Дун Морог или Призрачные земли." WHERE `ID` = 40120 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Восточных королевствах", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Болото Печали или Тирисфальские леса." WHERE `ID` = 40121;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Болото Печали или Тирисфальские леса." WHERE `ID` = 40121 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Восточных королевствах", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Красногорье или Внутренние земли." WHERE `ID` = 40122;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Красногорье или Внутренние земли." WHERE `ID` = 40122 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Восточных королевствах", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Тернистая долина или Лок Модан." WHERE `ID` = 40123;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Тернистая долина или Лок Модан." WHERE `ID` = 40123 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Восточных королевствах", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Элвиннский лес или Серебряный бор." WHERE `ID` = 40124;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Элвиннский лес или Серебряный бор." WHERE `ID` = 40124 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Восточных королевствах", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Альтеракские горы или Западный Край." WHERE `ID` = 40125;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Альтеракские горы или Западный Край." WHERE `ID` = 40125 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Восточных королевствах", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Болотина или Восточные Чумные земли." WHERE `ID` = 40126;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Болотина или Восточные Чумные земли." WHERE `ID` = 40126 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Восточных королевствах", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Западные Чумные земли или Перевал Мертвого Ветра." WHERE `ID` = 40127;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Западные Чумные земли или Перевал Мертвого Ветра." WHERE `ID` = 40127 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Восточных королевствах", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Сумеречный лес или Нагорье Арати." WHERE `ID` = 40128;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Сумеречный лес или Нагорье Арати." WHERE `ID` = 40128 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Восточных королевствах", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Предгорья Хилсбрада или Леса Вечной Песни." WHERE `ID` = 40129;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Предгорья Хилсбрада или Леса Вечной Песни." WHERE `ID` = 40129 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Калимдоре", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Азшара или Фералас." WHERE `ID` = 40130;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Азшара или Фералас." WHERE `ID` = 40130 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Калимдоре", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Оскверненный лес или Танарис." WHERE `ID` = 40131;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Оскверненный лес или Танарис." WHERE `ID` = 40131 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Калимдоре", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Темные берега или Кратер Ун'Горо." WHERE `ID` = 40132;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Темные берега или Кратер Ун'Горо." WHERE `ID` = 40132 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Калимдоре", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Пустоши или Лунная поляна." WHERE `ID` = 40133;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Пустоши или Лунная поляна." WHERE `ID` = 40133 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Калимдоре", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Тысяча Игл или Когтистые горы." WHERE `ID` = 40134;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Тысяча Игл или Когтистые горы." WHERE `ID` = 40134 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Калимдоре", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Зимние Ключи или Остров Лазурной Дымки." WHERE `ID` = 40135;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Зимние Ключи или Остров Лазурной Дымки." WHERE `ID` = 40135 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Калимдоре", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Пылевые топи или Ясеневый лес." WHERE `ID` = 40136;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Пылевые топи или Ясеневый лес." WHERE `ID` = 40136 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Калимдоре", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Дуротар или Тельдрассил." WHERE `ID` = 40137;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Дуротар или Тельдрассил." WHERE `ID` = 40137 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Калимдоре", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Северные степи, Южные степи или Силитус." WHERE `ID` = 40138;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Северные степи, Южные степи или Силитус." WHERE `ID` = 40138 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Калимдоре", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Мулгор или Остров Кровавой Дымки." WHERE `ID` = 40139;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Мулгор или Остров Кровавой Дымки." WHERE `ID` = 40139 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Запределье", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Долина Призрачной Луны или Пустоверть." WHERE `ID` = 40140;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Долина Призрачной Луны или Пустоверть." WHERE `ID` = 40140 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Запределье", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Награнд или Зангартопь." WHERE `ID` = 40141;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Награнд или Зангартопь." WHERE `ID` = 40141 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Запределье", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Полуостров Адского Пламени или Лес Тероккар." WHERE `ID` = 40142;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Полуостров Адского Пламени или Лес Тероккар." WHERE `ID` = 40142 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Нордсколе", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Драконий Погост или Ледяная Корона." WHERE `ID` = 40143;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Драконий Погост или Ледяная Корона." WHERE `ID` = 40143 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Нордсколе", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Ревущий фьорд или Лес Хрустальной Песни." WHERE `ID` = 40144;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Ревущий фьорд или Лес Хрустальной Песни." WHERE `ID` = 40144 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Нордсколе", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Грозовая Гряда или Борейская тундра." WHERE `ID` = 40145;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Грозовая Гряда или Борейская тундра." WHERE `ID` = 40145 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Нордсколе", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Низина Шолазар или Седые холмы." WHERE `ID` = 40146;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Низина Шолазар или Седые холмы." WHERE `ID` = 40146 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Нордсколе", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Зул'Драк или Озеро Ледяных Оков." WHERE `ID` = 40147;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Зул'Драк или Озеро Ледяных Оков." WHERE `ID` = 40147 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в новых землях Калимдора", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Ульдум или Гора Хиджал." WHERE `ID` = 40148;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Ульдум или Гора Хиджал." WHERE `ID` = 40148 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в новых землях Восточных королевств", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Сумеречное нагорье или Руины Гилнеаса." WHERE `ID` = 40149;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Сумеречное нагорье или Руины Гилнеаса." WHERE `ID` = 40149 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в новых землях", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Тол Барад, Полуостров Тол Барад или Подземье." WHERE `ID` = 40150;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Тол Барад, Полуостров Тол Барад или Подземье." WHERE `ID` = 40150 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Пандарии", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Вершина Кунь-Лай или Нефритовый лес." WHERE `ID` = 40151;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Вершина Кунь-Лай или Нефритовый лес." WHERE `ID` = 40151 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Пандарии", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Долина Четырех Ветров или Красарангские джунгли." WHERE `ID` = 40152;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Долина Четырех Ветров или Красарангские джунгли." WHERE `ID` = 40152 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Пандарии", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Танлунские степи или Жуткие пустоши." WHERE `ID` = 40153;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Танлунские степи или Жуткие пустоши." WHERE `ID` = 40153 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Пандарии", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Сокрытая лестница или Вечноцветущий дол." WHERE `ID` = 40154;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Сокрытая лестница или Вечноцветущий дол." WHERE `ID` = 40154 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Рыбалка в Пандарии", `Objectives` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Остров Грома, Остров Великанов или Вневременный остров." WHERE `ID` = 40155;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Порыбачьте определенное количество раз в одной из перечисленных зон: Остров Грома, Остров Великанов или Вневременный остров." WHERE `ID` = 40155 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Цареубийство", `Objectives` = "Поучаствуйте в убийстве одного из лидеров враждебной фракции.$b$bСегодняшние цели:$bИгрокам альянса: Гаррош Адский Крик$bИгрокам орды: Король Вариан Ринн." WHERE `ID` = 40190;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в убийстве одного из лидеров враждебной фракции.$b$bСегодняшние цели:$bИгрокам альянса: Гаррош Адский Крик$bИгрокам орды: Король Вариан Ринн." WHERE `ID` = 40190 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Цареубийство", `Objectives` = "Поучаствуйте в убийстве одного из лидеров враждебной фракции.$b$bСегодняшние цели:$bИгрокам альянса: Бейн Кровавое Копыто$bИгрокам орды: Мурадин Бронзобород." WHERE `ID` = 40191;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в убийстве одного из лидеров враждебной фракции.$b$bСегодняшние цели:$bИгрокам альянса: Бейн Кровавое Копыто$bИгрокам орды: Мурадин Бронзобород." WHERE `ID` = 40191 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Цареубийство", `Objectives` = "Поучаствуйте в убийстве одного из лидеров враждебной фракции.$b$bСегодняшние цели:$bИгрокам альянса: Леди Сильвана Ветрокрылая$bИгрокам орды: Верховная жрица Тиранда Шелест Ветра." WHERE `ID` = 40192;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в убийстве одного из лидеров враждебной фракции.$b$bСегодняшние цели:$bИгрокам альянса: Леди Сильвана Ветрокрылая$bИгрокам орды: Верховная жрица Тиранда Шелест Ветра." WHERE `ID` = 40192 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "Мир: Цареубийство", `Objectives` = "Поучаствуйте в убийстве одного из лидеров враждебной фракции.$b$bСегодняшние цели:$bИгрокам альянса: Лор'темар Терон$bИгрокам орды: Пророк Велен." WHERE `ID` = 40193;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в убийстве одного из лидеров враждебной фракции.$b$bСегодняшние цели:$bИгрокам альянса: Лор'темар Терон$bИгрокам орды: Пророк Велен." WHERE `ID` = 40193 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Арена", `Objectives` = "Поучаствуйте в нескольких рейтинговых боях на арене.$b$b- ИЛИ -$b$bВыиграйте один рейтинговый бой на арене." WHERE `ID` = 40200;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в нескольких рейтинговых боях на арене.$b$b- ИЛИ -$b$bВыиграйте один рейтинговый бой на арене." WHERE `ID` = 40200 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Король больших цифр", `Objectives` = "Нанесите или вылечите определенное количество урона во время сражения на поле боя." WHERE `ID` = 40201;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Нанесите или вылечите определенное количество урона во время сражения на поле боя." WHERE `ID` = 40201 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Завоеватель полей боя", `Objectives` = "Получите определенное количество почетных побед на полях боя." WHERE `ID` = 40202;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Получите определенное количество почетных побед на полях боя." WHERE `ID` = 40202 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Завоеватель открытого воздуха", `Objectives` = "Получите определенное количество почетных побед на территории открытых PvP сражений, в том числе на Озере Ледяных Оков или Тол Бараде." WHERE `ID` = 40203;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Получите определенное количество почетных побед на территории открытых PvP сражений, в том числе на Озере Ледяных Оков или Тол Бараде." WHERE `ID` = 40203 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Озеро Ледяных Оков", `Objectives` = "Поучаствуйте в битве на Озере Ледяных Оков и получите ранг Первого лейтенанта к концу сражения." WHERE `ID` = 40204;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в битве на Озере Ледяных Оков и получите ранг Первого лейтенанта к концу сражения." WHERE `ID` = 40204 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Тол Барад", `Objectives` = "Поучаствуйте в битве на Тол Бараде и получите ранг Первого лейтенанта к концу сражения." WHERE `ID` = 40205;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в битве на Тол Бараде и получите ранг Первого лейтенанта к концу сражения." WHERE `ID` = 40205 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Несвятая троица", `Objectives` = "Поучаствуйте в рейтинговом сражении 3v3 на арене." WHERE `ID` = 40206;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в рейтинговом сражении 3v3 на арене." WHERE `ID` = 40206 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Альтеракская долина", `Objectives` = "Поучаствуйте в битве за Альтеракскую долину (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40300;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в битве за Альтеракскую долину (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40300 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Ущелье Песни Войны", `Objectives` = "Поучаствуйте в битве за Ущелье Песни Войны (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40301;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в битве за Ущелье Песни Войны (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40301 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Низина Арата", `Objectives` = "Поучаствуйте в битве за Низину Арати (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40302;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в битве за Низину Арати (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40302 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Око Бури", `Objectives` = "Поучаствуйте в битве за Око Бури (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40303;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в битве за Око Бури (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40303 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Берег Древних", `Objectives` = "Поучаствуйте в битве за Берег Древних (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40304;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в битве за Берег Древних (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40304 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Остров Завоеваний", `Objectives` = "Поучаствуйте в битве за Остров Завоеваний (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40305;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в битве за Остров Завоеваний (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40305 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Два Пика", `Objectives` = "Поучаствуйте в битве за Два Пика (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40306;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в битве за Два Пика (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40306 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Битва за Гилнеас", `Objectives` = "Поучаствуйте в Битве за Гилнеас (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40307;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в Битве за Гилнеас (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40307 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Храм Котмогу", `Objectives` = "Поучаствуйте в битве за Храм Котмогу (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40308;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в битве за Храм Котмогу (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40308 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Каньон Суровых Ветров", `Objectives` = "Поучаствуйте в битве за Каньон Суровых Ветров (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40309;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в битве за Каньон Суровых Ветров (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40309 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Сверкающие копи", `Objectives` = "Поучаствуйте в битве за Сверкающие копи (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40310;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Поучаствуйте в битве за Сверкающие копи (не через Случайное поле боя).$b$b- ИЛИ -$b$bПоучаствуйте в нескольких сражениях на любых полях боя.$b$b- ИЛИ -$b$bВыиграйте сражение на любом поле боя." WHERE `ID` = 40310 AND `locale` = "ruRU";
UPDATE `quest_template_locale` SET `Title` = "PvP: Покоритель рейтингов", `Objectives` = "Победите или поучаствуйте в определенном количестве сражений на рейтинговых полях боя." WHERE `ID` = 40311;
UPDATE `quest_request_items_locale` SET `CompletionText` = "Победите или поучаствуйте в определенном количестве сражений на рейтинговых полях боя." WHERE `ID` = 40311 AND `locale` = "ruRU";
UPDATE `quest_template` SET `Details` = "This is a special daily loyalty quest that will award you with bonuses in the form of Orb of Loyalty.", `OfferRewardText` = "The reward will be added to you immediately after quest completion.", `CompletedText` = "Return to the turtle to receive the reward." WHERE `Id` IN
(40000, 40001, 40002, 40003, 40004, 40005, 40006, 40007, 40008, 40009, 40010, 40011, 40012, 40013, 40014, 40015, 40016, 40017, 40018, 40019, 40020, 40021, 40022, 40023,
 40024, 40025, 40026, 40027, 40028, 40029, 40030, 40031, 40032, 40033, 40034, 40035, 40036, 40037, 40038, 40039, 40040, 40100, 40101, 40102, 40103, 40104, 40105, 40106,
 40107, 40108, 40109, 40110, 40111, 40112, 40113, 40114, 40115, 40120, 40121, 40122, 40123, 40124, 40125, 40126, 40127, 40128, 40129, 40130, 40131, 40132, 40133, 40134,
 40135, 40136, 40137, 40138, 40139, 40140, 40141, 40142, 40143, 40144, 40145, 40146, 40147, 40148, 40149, 40150, 40151, 40152, 40153, 40154, 40155, 40190, 40191, 40192,
 40193, 40200, 40201, 40202, 40203, 40204, 40205, 40206, 40300, 40301, 40302, 40303, 40304, 40305, 40306, 40307, 40308, 40309, 40310, 40311);
UPDATE `quest_template_locale` SET `Details` = "Это специальное ежедневное задание лояльности, в награду за которое вы получите бонусы в виде Сфер Лояльности.", `CompletedText` = "Возвращайтесь к черепахе, чтобы получить награду." WHERE `ID` IN
(40000, 40001, 40002, 40003, 40004, 40005, 40006, 40007, 40008, 40009, 40010, 40011, 40012, 40013, 40014, 40015, 40016, 40017, 40018, 40019, 40020, 40021, 40022, 40023,
 40024, 40025, 40026, 40027, 40028, 40029, 40030, 40031, 40032, 40033, 40034, 40035, 40036, 40037, 40038, 40039, 40040, 40100, 40101, 40102, 40103, 40104, 40105, 40106,
 40107, 40108, 40109, 40110, 40111, 40112, 40113, 40114, 40115, 40120, 40121, 40122, 40123, 40124, 40125, 40126, 40127, 40128, 40129, 40130, 40131, 40132, 40133, 40134,
 40135, 40136, 40137, 40138, 40139, 40140, 40141, 40142, 40143, 40144, 40145, 40146, 40147, 40148, 40149, 40150, 40151, 40152, 40153, 40154, 40155, 40190, 40191, 40192,
 40193, 40200, 40201, 40202, 40203, 40204, 40205, 40206, 40300, 40301, 40302, 40303, 40304, 40305, 40306, 40307, 40308, 40309, 40310, 40311);
UPDATE `quest_offer_reward_locale` SET `RewardText` = "Награда будет выдана вам сразу же после завершения задания." WHERE `ID` IN
(40000, 40001, 40002, 40003, 40004, 40005, 40006, 40007, 40008, 40009, 40010, 40011, 40012, 40013, 40014, 40015, 40016, 40017, 40018, 40019, 40020, 40021, 40022, 40023,
 40024, 40025, 40026, 40027, 40028, 40029, 40030, 40031, 40032, 40033, 40034, 40035, 40036, 40037, 40038, 40039, 40040, 40100, 40101, 40102, 40103, 40104, 40105, 40106,
 40107, 40108, 40109, 40110, 40111, 40112, 40113, 40114, 40115, 40120, 40121, 40122, 40123, 40124, 40125, 40126, 40127, 40128, 40129, 40130, 40131, 40132, 40133, 40134,
 40135, 40136, 40137, 40138, 40139, 40140, 40141, 40142, 40143, 40144, 40145, 40146, 40147, 40148, 40149, 40150, 40151, 40152, 40153, 40154, 40155, 40190, 40191, 40192,
 40193, 40200, 40201, 40202, 40203, 40204, 40205, 40206, 40300, 40301, 40302, 40303, 40304, 40305, 40306, 40307, 40308, 40309, 40310, 40311) AND `locale` = "ruRU";
UPDATE `item_template` SET `description` = "|cFF00C0FFYou can exchange it for virtual points on the Pandaria 5.4.8 server.|r" WHERE `entry` = 35626;
DELETE FROM `item_template_locale` WHERE `ID` = 35626 AND `locale` = "ruRU";
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`) VALUES
(35626, "ruRU", "Сфера Лояльности", "|cFF00C0FFМожно обменять на виртуальные очки сервера Pandaria 5.4.8.|r");
DELETE FROM `command` WHERE `name` = "isengard";
