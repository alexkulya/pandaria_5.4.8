UPDATE `creature_template` SET `modelid1` = 29133, `modelid2` = 0, `name` = "Teleport", `ScriptName` = "npc_teleport" WHERE `entry` = 190000;

UPDATE `creature_template` SET `scale` = 0.5 WHERE `entry` = 190000;

DELETE FROM `npc_text` WHERE `ID` IN (300000, 300001, 300002, 300003, 300004);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`) VALUES
(300000, "For the Horde!", "For the Horde!"),
(300001, "For the Alliance!", "For the Alliance!"),
(300002, "What dungeons do you want to explore?", "What dungeons do you want to explore?"),
(300003, "What raid dungeons do you want to explore?", "What raid dungeons do you want to explore?"),
(300004, "Where would you like to go?", "Where would you like to go?");

DELETE FROM `locales_npc_text` WHERE `ID` IN (300000, 300001, 300002, 300003, 300004);
INSERT INTO `locales_npc_text` (`ID`, `Text0_0_loc8`, `Text0_1_loc8`) VALUES
(300000, "За Орду!", "За Орду!"),
(300001, "За Альянс!", "За Альянс!"),
(300002, "Какие подземелья вы хотите исследовать?", "Какие подземелья вы хотите исследовать?"),
(300003, "Какие рейдовые подземелья вы хотите исследовать?", "Какие рейдовые подземелья вы хотите исследовать?"),
(300004, "Куда бы вы хотели отправиться?", "Куда бы вы хотели отправиться?");
