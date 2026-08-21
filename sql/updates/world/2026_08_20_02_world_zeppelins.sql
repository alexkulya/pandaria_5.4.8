UPDATE `creature_template` SET `ScriptName` = "npc_krixx" WHERE `entry` = 23635;
UPDATE `creature_template` SET `ScriptName` = "npc_kraxx" WHERE `entry` = 23713;

-- Тирисфальские леса <-> Тернистая долина
UPDATE `creature_template` SET `ScriptName` = "npc_hin_denburg" WHERE `entry` = 3150;
-- Тернистая долина <-> Тирисфальские леса
UPDATE `creature_template` SET `ScriptName` = "npc_squibby_overspeck" WHERE `entry` = 12137;

-- Тирисфальские леса <-> Дуротар
UPDATE `creature_template` SET `ScriptName` = "npc_zapetta" WHERE `entry` = 9566;
-- Дуротар <-> Тирисфальские леса
UPDATE `creature_template` SET `ScriptName` = "npc_frezza" WHERE `entry` = 9564;

-- Тирисфальские леса <-> Ревущий фьорд
UPDATE `creature_template` SET `ScriptName` = "" WHERE `entry` = 26539;
-- Ревущий фьорд <-> Тирисфальские леса
UPDATE `creature_template` SET `ScriptName` = "" WHERE `entry` = 26540;

-- Тернистая долина <-> Дуротар
UPDATE `creature_template` SET `ScriptName` = "npc_nez_raz" WHERE `entry` = 3149;
-- Дуротар <-> Тернистая долина
UPDATE `creature_template` SET `ScriptName` = "npc_snurk_bucksquick" WHERE `entry` = 12136;

-- Борейская тундра <-> Дуротар
UPDATE `creature_template` SET `ScriptName` = "" WHERE `entry` = 26538;
-- Дуротар <-> Борейская тундра
UPDATE `creature_template` SET `ScriptName` = "" WHERE `entry` = 26537;

-- Дуротар <-> Громовой утес
UPDATE `creature_template` SET `ScriptName` = "" WHERE `entry` = 34765;
-- Громовой утес <-> Дуротар
UPDATE `creature_template` SET `ScriptName` = "" WHERE `entry` = 34766;

UPDATE `gameobject_template` SET `AIName` = "", `ScriptName` = "zeppelin_the_thundercaller" WHERE `entry` = 164871;
UPDATE `gameobject_template` SET `AIName` = "", `ScriptName` = "zeppelin_the_iron_eagle" WHERE `entry` = 175080;
UPDATE `gameobject_template` SET `AIName` = "", `ScriptName` = "zeppelin_the_purple_princess" WHERE `entry` = 176495;
UPDATE `gameobject_template` SET `AIName` = "", `ScriptName` = "zeppelin_the_cloudkisser" WHERE `entry` = 181689;
UPDATE `gameobject_template` SET `AIName` = "", `ScriptName` = "zeppelin_the_mighty_wind" WHERE `entry` = 186238;
UPDATE `gameobject_template` SET `AIName` = "SmartGameObjectAI", `ScriptName` = "zeppelin_the_zephyr" WHERE `entry` = 190549;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (164871, 175080, 176495, 181689, 186238, 190549) AND `source_type` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (175080*100, 176495*100, 190549*100, 190549*100+01, 190549*100+02, 190549*100+03) AND `source_type` = 9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(190549, 1, 0, 0, 71, 0, 100, 0, 21868, 0, 0, 0, 80, 190549*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Zephyr - On Event 21868 Inform - Start Script"),
(190549, 1, 1, 0, 71, 0, 100, 0, 21869, 0, 0, 0, 80, 190549*100+01, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Zephyr - On Event 21869 Inform - Start Script"),
(190549, 1, 2, 0, 71, 0, 100, 0, 21870, 0, 0, 0, 80, 190549*100+02, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Zephyr - On Event 21870 Inform - Start Script"),
(190549, 1, 3, 0, 71, 0, 100, 0, 21871, 0, 0, 0, 80, 190549*100+03, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Zephyr - On Event 21871 Inform - Start Script"),

(190549*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 34715, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Say Text Line 0"),
(190549*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 34721, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Say Text Line 1"),
(190549*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 34765, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Say Text Line 0"),
(190549*100, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 5, 5, 0, 0, 0, 0, 0, 19, 34715, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Play Emote (5)"),
(190549*100, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 25, 0, 0, 0, 0, 0, 19, 34721, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Play Emote (25)"),

(190549*100+01, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 34715, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Say Text Line 1"),
(190549*100+01, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 34721, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Say Text Line 0"),
(190549*100+01, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 5, 25, 0, 0, 0, 0, 0, 19, 34721, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Play Emote (25)"),

(190549*100+02, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 34715, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Say Text Line 2"),
(190549*100+02, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 34721, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Say Text Line 1"),
(190549*100+02, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 34766, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Say Text Line 0"),
(190549*100+02, 9, 3, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 5, 5, 0, 0, 0, 0, 0, 19, 34715, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Play Emote (5)"),
(190549*100+02, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 25, 0, 0, 0, 0, 0, 19, 34721, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Play Emote (25)"),

(190549*100+03, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 34715, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Say Text Line 3"),
(190549*100+03, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 34721, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Say Text Line 2"),
(190549*100+03, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 5, 25, 0, 0, 0, 0, 0, 19, 34721, 100, 0, 0, 0, 0, 0, "The Zephyr - On Script - Play Emote (25)");

DELETE FROM `creature_text` WHERE `entry` IN (3150, 12137, 9566, 9564, 26539, 26540, 3149, 12136, 26538, 26537, 34765, 34766);
INSERT INTO `creature_text` (`entry`, `text_group`, `id`, `text`, `text_female`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `text_range`, `comment`) VALUES
-- Тирисфальские леса <-> Тернистая долина
(3150, 0, 0, "The zeppelin to Grom'gol has just arrived! All aboard for Stranglethorn!", "", 14, 0, 100, 22, 0, 0, 0, "Hin Denburg - Zeppelin Arrival"),
(3150, 1, 0, "Hey! Did I remember to refill the tank before the zeppelin left? Oh, well!", "", 12, 0, 100, 0, 0, 0, 0, "Hin Denburg - Zeppelin Departure"),
-- Тернистая долина <-> Тирисфальские леса
(12137, 0, 0, "The zeppelin to Undercity has just arrived! All aboard for Tirisfal Glades!", "", 14, 0, 100, 22, 0, 0, 0, "Squibby Overspeck - Zeppelin Arrival"),

-- Тирисфальские леса <-> Дуротар
(9566, 0, 0, "The zeppelin to Orgrimmar has just arrived! All aboard for Durotar!", "", 14, 0, 100, 22, 0, 0, 0, "Zapetta - Zeppelin Arrival"),
(9566, 1, 0, "There goes the zeppelin to Orgrimmar. I hope there's no explosions this time.", "", 12, 0, 100, 0, 0, 0, 0, "Zapetta - Zeppelin Departure"),
-- Дуротар <-> Тирисфальские леса
(9564, 0, 0, "The zeppelin to Undercity has just arrived! All aboard for Tirisfal Glades!", "", 14, 0, 100, 22, 0, 0, 0, "Frezza - Zeppelin Arrival"),

-- Тирисфальские леса <-> Ревущий фьорд
(26539, 0, 0, "", "The zeppelin to Vengeance Landing has just arrived! All aboard for Howling Fjord!", 14, 0, 100, 22, 0, 0, 0, "Meefi Farthrottle - Zeppelin Arrival"),
-- Ревущий фьорд <-> Тирисфальские леса
(26540, 0, 0, "The zeppelin to Undercity has just arrived! All aboard for Tirisfal Glades!", "", 14, 0, 100, 22, 0, 0, 0, "Drenk Spannerspark - Zeppelin Arrival"),

-- Тернистая долина <-> Дуротар
(3149, 0, 0, "The zeppelin to Orgrimmar has just arrived! All aboard for Durotar!", "", 14, 0, 100, 22, 0, 0, 0, "Nez'raz - Zeppelin Arrival"),
-- Дуротар <-> Тернистая долина
(12136, 0, 0, "", "The zeppelin to Grom'gol has just arrived! All aboard for Stranglethorn!", 14, 0, 100, 22, 0, 0, 0, "Snurk Bucksquick - Zeppelin Arrival"),

-- Борейская тундра <-> Дуротар
(26538, 0, 0, "The zeppelin to Orgrimmar has just arrived! All aboard for Durotar!", "", 14, 0, 100, 22, 0, 0, 0, "Nargo Screwbore - Zeppelin Arrival"),
-- Дуротар <-> Борейская тундра
(26537, 0, 0, "The zeppelin to Warsong Hold has just arrived! All aboard for Borean Tundra!", "", 14, 0, 100, 22, 0, 0, 0, "Greeb Ramrocket - Zeppelin Arrival"),

-- Дуротар <-> Громовой утес
(34765, 0, 0, "", "The zeppelin to Thunder Bluff has arrived! All aboard for a smooth ride across the Barrens!", 14, 0, 100, 22, 0, 0, 0, "Zelli Hotnozzle - Dock at Orgrimmar"),
-- Громовой утес <-> Дуротар
(34766, 0, 0, "Step right up! The zeppelin to Orgrimmar has arrived! All aboard to Durotar!", "", 14, 0, 100, 22, 0, 0, 0, "Krendle Bigpockets - Dock at Thunder Bluff");

UPDATE `creature_template` SET `gossip_menu_id` = 2441 WHERE `entry` = 3149;
UPDATE `creature_template` SET `gossip_menu_id` = 3842 WHERE `entry` = 12137;

DELETE FROM `event_scripts` WHERE `id` IN (15312, 15314, 15318, 15320, 15322, 15324, 19126, 19127, 19137, 19139, 21868, 21870);
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(15312, 0, 16, 11804, 2, 0, 0, 0, 0, 0), -- "The Purple Princess", arrival in Tirisfal Glades
(15314, 0, 16, 11804, 2, 0, 0, 0, 0, 0), -- "The Purple Princess", arrival in Stranglethorn Vale
(15318, 0, 16, 11804, 2, 0, 0, 0, 0, 0), -- "The Thundercaller", arrival in Durotar
(15320, 0, 16, 11804, 2, 0, 0, 0, 0, 0), -- "The Thundercaller", arrival in Tirisfal Glades
(15322, 0, 16, 11804, 2, 0, 0, 0, 0, 0), -- "The Iron Eagle", arrival in Durotar
(15324, 0, 16, 11804, 2, 0, 0, 0, 0, 0), -- "The Iron Eagle", arrival in Stranglethorn Vale
(19126, 0, 16, 11804, 2, 0, 0, 0, 0, 0), -- "The Cloudkisser", arrival in Howling Fjord
(19127, 0, 16, 11804, 2, 0, 0, 0, 0, 0), -- "The Cloudkisser", arrival in Tirisfal Glades
(19137, 0, 16, 11804, 2, 0, 0, 0, 0, 0), -- "The Mighty Wind", arrival in Durotar
(19139, 0, 16, 11804, 2, 0, 0, 0, 0, 0), -- "The Mighty Wind", arrival in Borean Tundra
(21868, 0, 16, 11804, 2, 0, 0, 0, 0, 0), -- Arrival in Orgrimmar (Durotar)
(21870, 0, 16, 11804, 2, 0, 0, 0, 0, 0); -- Arrival in Thunder Bluff (Mulgore)

DELETE FROM `creature_text_locale` WHERE `CreatureID` IN (3150, 12137, 9566, 9564, 26539, 26540, 3149, 12136, 26538, 26537, 34765, 34766) AND `Locale` = "ruRU";
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`, `TextFemale`) VALUES
-- 3150
(3150, 0, 0, "ruRU", "Дирижабль в Гром'гол отправляется! Все на борт, летим в Тернистую долину!", ""),
(3150, 1, 0, "ruRU", "Эй! Я не забыл наполнить бак до отлета дирижабля? Ну хорошо!", ""),
-- 12137
(12137, 0, 0, "ruRU", "Дирижабль до Подгорода прибыл! Кому в Тирисфальские леса – садитесь!", ""),
-- 9566
(9566, 0, 0, "ruRU", "Только что прилетел дирижабль, который отправится в Оргриммар! Все на борт! Мы летим в Дуротар!", ""),
(9566, 1, 0, "ruRU", "А вот дирижабль на Оргриммар. Надеюсь, на этот раз обойдется без взрывов.", ""),
-- 9564
(9564, 0, 0, "ruRU", "Дирижабль до Подгорода прибыл! Кому в Тирисфальские леса – садитесь!", ""),
-- 26539
(26539, 0, 0, "ruRU", "", "Только что прилетел дирижабль, который отправится в Лагерь Возмездия! Все на борт! Мы летим к Ревущему фьорду!"),
-- 26540
(26540, 0, 0, "ruRU", "Дирижабль до Подгорода прибыл! Кому в Тирисфальские леса – садитесь!", ""),
-- 3149
(3149, 0, 0, "ruRU", "Только что прилетел дирижабль, который отправится в Оргриммар! Все на борт! Мы летим в Дуротар!", ""),
-- 12136
(12136, 0, 0, "ruRU", "", "Дирижабль в Гром'гол отправляется! Все на борт, летим в Тернистую долину!"),
-- 26538
(26538, 0, 0, "ruRU", "Дирижабль в Оргриммар отправляется! Все на борт, летим в Дуротар!", ""),
-- 26537
(26537, 0, 0, "ruRU", "Только что прилетел дирижабль, который отправится в крепость Песни Войны! Все на борт! Мы летим в Борейскую тундру!", ""),
-- 34765
(34765, 0, 0, "ruRU", "", "Наш дирижабль отправляется в Громовой Утес! Кто хочет прокатиться по Степям – добро пожаловать на борт!"),
-- 34766
(34766, 0, 0, "ruRU", "Дирижабль в Оргриммар отправляется! Все на борт, летим в Дуротар!", "");

UPDATE `creature_text_locale` SET `TextFemale` = "" WHERE `CreatureID` IN (9564, 26537);
UPDATE `creature_text_locale` SET `Text` = "" WHERE `CreatureID` = 12136;
