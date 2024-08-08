
DROP TABLE IF EXISTS `achievement_reward_locale`;
CREATE TABLE IF NOT EXISTS `achievement_reward_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `Locale` VARCHAR(4) NOT NULL,
  `Subject` TEXT,
  `Text` TEXT,
  PRIMARY KEY (`ID`, `Locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

RENAME TABLE `locales_creature` TO `creature_template_locale`;

-- locales_achievement_reward
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
  
  DROP TABLE IF EXISTS `locales_achievement_reward`;

DELETE FROM `achievement_reward_locale` WHERE `ID` IN (13, 45, 614, 876, 1250, 1956, 2096, 2143, 3478, 3656, 4478, 4602, 4603, 4784, 4785) AND `locale` = 'deDE';
INSERT INTO `achievement_reward_locale` (`ID`, `Locale`, `Subject`, `Text`) VALUES
(13, 'deDE', 'Stufe 80', 'Herzlichen Glückwunsch zu Eurem Erreichen der 80. Abenteuersaison! Ihr habt Euch zweifelsohne der Sache verschrieben, Azeroth von den Übeln zu befreien, die uns geplagt haben.$B$BUnd obwohl die bisherige Reise keine Kleinigkeit war, steht der wahre Kampf noch bevor.$B$BKämpft weiter!$B$BRhonin'),
(45, 'deDE', 'Ihr seid rumgekommen!', 'Nun seht Euch mal an!$B$BUnd ich dachte, ich hätte hier an diesem eisigen Ort schon einiges gesehen! Diesem Zwerg scheint es offensichtlich, dass das Feuer eines Forschers in Euren Augen brennt.$B$BTragt diesen Wappenrock mit Stolz, dann wissen Eure Freunde, wen sie nach dem Weg fragen müssen, wenn die Zeit gekommen ist!$B$BMacht weiter so!$B$BBrann Bronzebart'),
(614, 'deDE', 'Für die Allianz!', 'Krieg wütet in unseren Ländern. Nur die tapfersten aller Helden wagen es, der Horde dort einen Schlag zu versetzen, wo es wehtut. Ihr gehört zu eben diesen Helden.$B$BDer Schlag, den Ihr der Führung der Horde versetzt habt, bereitet den Weg für unseren letzten Angriff. Die Horde wird sich vor der Macht der Allianz verbeugen.$B$BEure Taten bleiben nicht ungewürdigt. Reitet mit Stolz!$B$B--Euer König'),
(876, 'deDE', 'Brutaler Kämpfer', 'Ihr habt ein ganz schönes Händchen dafür Euch in diese Arena zu werfen. Nehmt dies. Tragt es mit Stolz. Jetzt geht wieder rein und zeigt ihnen, wie es gemacht wird! $B$BOnkel Sal'),
(1250, 'deDE', 'Stinkers neues Zuhause', 'Ich habe gehört, wie gut Ihr Euch um unsere pelzigen Freunde kümmert. Ich hoffe, es macht Euch nichts aus, aber ich muss Stinker ein neues Zuhause verschaffen. Er weigert sich einfach, friedlich mit den Anderen zu spielen.$B$BBitte stellt sicher, dass er zweimal täglich gefüttert wird. Und, ähm... er hat eine Schwäche für schwarze Katzen.$B$B--Breanni'),
(1956, 'deDE', 'Höheres Studium', 'Herzlichen Glückwunsch zu Eurem Abschluss in den Schulen der arkanen Magie. In Anerkennung Eurer Hingabe lege ich diesen speziellen Buchband bei, der die Serie vervollständigt.$B$BIch denke, dass Ihr diesen Folianten sehr unterhaltsam finden werdet. Doch das dürft Ihr selbst entscheiden.$B$BHochachtungsvoll,$B$BRhonin'),
(2096, 'deDE', 'Der Münzmeister', 'Grüße und Glückwünsche dazu, dass Ihr das gesamte Set der Dalaranmünzen gesammelt habt! Als Belohnung Eurer harten Arbeit habe ich diesem Schreiben ein frisch geprägtes Titansiegel von Dalaran beigelegt. Dies ist eine besondere Münze, die wir nur den leidenschaftlichsten aller Sammler verleihen.$B$BIch hoffe, Ihr findet Freude an dieser speziellen Belohnung. Ihr habt Sie Euch verdient!$B$BHochachtungsvoll,$B$BJepetto Spaßbrumm'),
(2143, 'deDE', 'Vorreiter der Kavallerie', 'Ich konnte nicht umhin, zu sehen wie gut Ihr mit Tieren umgeht. Bei allem was hier vorgeht, laufen meine Geschäfte besser denn je.$B$BIch nehme nicht an, dass es Euch etwas ausmacht, für mich auf diesen Albinodrachen aufzupassen? Ich habe einfach nicht genug Zeit, mich um all diese Tiere zu kümmern.$B$BViele Grüße.$B$BMei'),
(3478, 'deDE', 'Der vergessene Puter', 'Könnt Ihr begreifen, wie es dieser fette Truthahn lebendig durch den November geschafft hat?!$B$BAlle seine Freunde sind auf den reich gedeckten Tischen serviert worden. Mit Moosbeerenchutney und Gewürzbrotfüllung und... OOOH... jetzt bekomme ich Hunger. Egal! Er ist jetzt ganz allein. Deswegen habe ich überlegt, ob Ihr Euch vielleicht um Ihn kümmern würdet. In meinem Laden ist einfach nicht mehr genug Platz für ihn!$B$BHaltet ihn nur bitte von Kochstellen fern. Er bekommt in ihrer Nähe immer so einen merkwürdigen Blick...$B$B--Breanni'),
(3656, 'deDE', 'Der vergessene Puter', 'Könnt Ihr begreifen, wie es dieser fette Truthahn lebendig durch den November geschafft hat?!$B$BAlle seine Freunde sind auf den reich gedeckten Tischen serviert worden. Mit Moosbeerenchutney und Gewürzbrotfüllung und... OOOH... jetzt bekomme ich Hunger. Egal! Er ist jetzt ganz allein. Deswegen habe ich überlegt, ob Ihr Euch vielleicht um Ihn kümmern würdet. In meinem Laden ist einfach nicht mehr genug Platz für ihn!$B$BHaltet ihn nur bitte von Kochstellen fern. Er bekommt in ihrer Nähe immer so einen merkwürdigen Blick...$B$B--Breanni'),
(4478, 'deDE', 'Streuner', 'Werter Meister der Geduld, wir möchten Eure Beharrlichkeit belohnen, mit der Ihr immer wieder Dungeons mit Leuten betretet, die Ihr wahrscheinlich noch nie zuvor getroffen habt. Hoffentlich habt Ihr ein paar Jungspunden zeigen können, wie der Hase läuft.$B$BLange Rede, kurzer Sinn. Wir haben zufällig gehört, dass Ihr mit Zufallsgruppen herumstreunt. Und wie der Zufall so will ist hier also ein kleiner Streuner, den wir Euch zufallen lassen, um mit Euch zu streunen, während Ihr zufälligen Zufällen zufallt, oder so.$B$BKnuddels.$B$BEure Freunde beim Entwickler-Team von WoW'),
(4602, 'deDE', 'Ruhm des Schlachtzüglers von Eiskrone', '$N,$B$BAls der Einfluss des Lichkönigs schwand, haben sich einige seiner mächtigeren Schergen aus seinem Griff befreit.$B$BDieser von meinen Männern gefangen genommene Frostwyrmdrache ist ein Paradebeispiel dafür. Sie hat einen eigenen Willen und noch mehr.$B$BEiner meiner Männer verlor einen Arm als er sie einritt, aber sie kann jetzt recht gut mit Reitern umgehen - vorausgesetzt Ihr seid geschickt und habt einen starken Willen.$B$BBitte nehmt diese prächtige Bestie als Geschenk der Ritter der Schwarzen Klinge an. Es war mir eine Ehre, an Eurer Seite in der größten aller Schlachten zu kämpfen.$B$BHochachtungsvoll,$BDarion Mograine.'),
(4603, 'deDE', 'Ruhm des Schlachtzüglers von Eiskrone', '$N,$B$BAls der Einfluss des Lichkönigs schwand, haben sich einige seiner mächtigeren Schergen aus seinem Griff befreit.$B$BDieser von meinen Männern gefangen genommene Frostwyrmdrache ist ein Paradebeispiel dafür. Sie hat einen eigenen Willen und noch mehr.$B$BEiner meiner Männer verlor einen Arm als er sie einritt, aber sie kann jetzt recht gut mit Reitern umgehen - vorausgesetzt Ihr seid geschickt und habt einen starken Willen.$B$BBitte nehmt diese prächtige Bestie als Geschenk der Ritter der Schwarzen Klinge an. Es war mir eine Ehre, an Eurer Seite in der größten aller Schlachten zu kämpfen.$B$BHochachtungsvoll,$BDarion Mograine.'),
(4784, 'deDE', 'Emblemrüstmeister in Dalaran\'s Silbernen Enklave', 'Eure Erfolge in Nordend sind nicht unbemerkt geblieben, Freund.$B$BDie verdienten Embleme können benutzt werden, um Gegenstände bei den verschiedenen Emblemrüstmeistern zu kaufen.$B$BIhr findet uns in der Silbernen Enklave, wo jede Emblemart einen eigenen Rüstmeister hat.$B$BWir freuen uns auf Eure Ankunft!'),
(4785, 'deDE', 'Emblemrüstmeister in Dalaran\'s Sonnenhäschers Zuflucht', 'Eure Erfolge in Nordend sind nicht unbemerkt geblieben, Freund.$B$BDie verdienten Embleme können benutzt werden, um Gegenstände bei den verschiedenen Emblemrüstmeistern zu kaufen.$B$BIhr findet uns in Sonnenhäschers Zuflucht, wo jede Emblemart einen eigenen Rüstmeister hat.$B$BWir freuen uns auf Eure Ankunft!');


-- Gossip_menu_option_locale

DROP TABLE IF EXISTS `gossip_menu_option_locale`;
CREATE TABLE IF NOT EXISTS `gossip_menu_option_locale` (
  `MenuID` SMALLINT(6) UNSIGNED NOT NULL DEFAULT '0',
  `OptionID` SMALLINT(6) UNSIGNED NOT NULL DEFAULT '0',
  `Locale` VARCHAR(4) NOT NULL,
  `OptionText` TEXT,
  `BoxText` TEXT,
  PRIMARY KEY (`MenuID`, `OptionID`, `Locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;


-- Gossip_menu_option_locale
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
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `Locale` VARCHAR(4) NOT NULL,
  `Name` TEXT,
  PRIMARY KEY (`ID`, `Locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;


INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, 'koKR', `name_loc1`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc1`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, 'frFR', `name_loc2`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc2`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, 'deDE', `name_loc3`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc3`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, 'zhCN', `name_loc4`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc4`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, 'zhTW', `name_loc5`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc5`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, 'esES', `name_loc6`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc6`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, 'esMX', `name_loc7`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc7`) > 0;

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`)
SELECT `id`, 'ruRU', `name_loc8`
FROM `locales_battle_pay_group`
WHERE LENGTH(`name_loc8`) > 0;


INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`) VALUES
(1, 'esES', 'Recomendado'),
(2, 'esES', 'Monturas'),
(3, 'esES', 'Bolsas'),
(4, 'esES', 'Mascotas'),
(5, 'esES', 'Armas'),
(6, 'esES', 'Armadura'),
(7, 'esES', 'Mejoras'),
(8, 'esES', 'Juguetes'),
(9, 'esES', 'Monedas de Oro'),
(10, 'esES', 'Monedas y Divisas'),
(11, 'esES', 'Servicios de Juego'),
(12, 'esES', 'Reliquias Familiares');

INSERT INTO `battle_pay_group_locale` (`ID`, `Locale`, `Name`) VALUES
(1, 'esMX', 'Recomendado'),
(2, 'esMX', 'Monturas'),
(3, 'esMX', 'Bolsas'),
(4, 'esMX', 'Mascotas'),
(5, 'esMX', 'Armas'),
(6, 'esMX', 'Armadura'),
(7, 'esMX', 'Mejoras'),
(8, 'esMX', 'Juguetes'),
(9, 'esMX', 'Monedas de Oro'),
(10, 'esMX', 'Monedas y Divisas'),
(11, 'esMX', 'Servicios de Juego'),
(12, 'esMX', 'Reliquias Familiares');

  -- battle_pay_entry_locale

DROP TABLE IF EXISTS `battle_pay_entry_locale`;
CREATE TABLE IF NOT EXISTS `battle_pay_entry_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `Locale` VARCHAR(4) NOT NULL,
  `Title` TEXT,
  `Description` TEXT,
  PRIMARY KEY (`ID`, `Locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'koKR', `title_loc1`, `description_loc1` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc1`) > 0 OR LENGTH(`description_loc1`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'frFR', `title_loc2`, `description_loc2` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc2`) > 0 OR LENGTH(`description_loc2`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'deDE', `title_loc3`, `description_loc3` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc3`) > 0 OR LENGTH(`description_loc3`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'zhCN', `title_loc4`, `description_loc4` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc4`) > 0 OR LENGTH(`description_loc4`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'zhTW', `title_loc5`, `description_loc5` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc5`) > 0 OR LENGTH(`description_loc5`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'esES', `title_loc6`, `description_loc6` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc6`) > 0 OR LENGTH(`description_loc6`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'esMX', `title_loc7`, `description_loc7` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc7`) > 0 OR LENGTH(`description_loc7`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'ruRU', `title_loc8`, `description_loc8` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc8`) > 0 OR LENGTH(`description_loc8`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'itIT', `title_loc9`, `description_loc9` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc9`) > 0 OR LENGTH(`description_loc9`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'ptBR', `title_loc10`, `description_loc10` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc10`) > 0 OR LENGTH(`description_loc10`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'ptPT', `title_loc11`, `description_loc11` 
FROM `locales_battle_pay_entry` 
WHERE LENGTH(`title_loc11`) > 0 OR LENGTH(`description_loc11`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);
    
 -- Locales esES, esMX
 INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('1', 'esES', '|cffff8000Promoción', 'Posibilidad de "promocionar" tu personaje en la cuenta actual o crear uno nuevo con algunos bonos.\n\nComo bonos recibirás:\n- Equipamiento de nivel de objeto 408\n- Arma de nivel de objeto 408\n- Accesorios y capa de nivel de objeto 408\n- 1.000 de oro\n- Nivel 90 instantáneo\n- Montura: Rienda de viento anaranjado (Horda) o Grifo blanco (Alianza)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('2', 'esES', '|cffff8000Promoción', 'Posibilidad de "promocionar" tu personaje en la cuenta actual o crear uno nuevo con algunos bonos.\n\nComo bonos recibirás:\n- Equipamiento de nivel de objeto 408\n- Arma de nivel de objeto 408\n- Accesorios y capa de nivel de objeto 408\n- 1.000 de oro\n- Nivel 90 instantáneo\n- Montura: Rienda de viento anaranjado (Horda) o Grifo blanco (Alianza)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('3', 'esES', '|cff1eff00Ficha de Pandaria (Denominación: 01)', 'Agrega 1 punto virtual para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('4', 'esES', '|cff0070ddFicha de Pandaria (Denominación: 02)', 'Agrega 2 puntos virtuales para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('5', 'esES', '|cffa335eeFicha de Pandaria (Denominación: 05)', 'Agrega 5 puntos virtuales para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('6', 'esES', '|cffff8000Ficha de Pandaria (Denominación: 10)', 'Agrega 10 puntos virtuales para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('7', 'esES', '|cff1eff001.000 monedas de oro', 'Te da 1.000 monedas de oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('8', 'esES', '|cff1eff005.000 monedas de oro', 'Te da 5.000 monedas de oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('9', 'esES', '|cff0070dd10.000 monedas de oro', 'Te da 10.000 monedas de oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('10', 'esES', '|cff0070dd30.000 monedas de oro', 'Te da 30.000 monedas de oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('11', 'esES', '|cffa335ee80.000 monedas de oro', 'Te da 80.000 monedas de oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('12', 'esES', '|cffff8000150.000 monedas de oro', 'Te da 150.000 monedas de oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('13', 'esES', '|cffff8000Caja con suministros infinitos de Foror', 'Bolsa (slots: 36)\nEl fondo del cofre está roto. De ahí salen lágrimas...');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('14', 'esES', '|cffa335eeBolsa real', 'Bolsa (slots: 28)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('15', 'esES', '|cff0070ddCaja de aparejos del maestro de cebo', 'Bolsa de pesca (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('16', 'esES', '|cff0070ddBolsa trascendental', 'Bolsa de encantador (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('17', 'esES', '|cff0070ddBolsa de seda lujosa para gemas', 'Bolsa de joyero (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('18', 'esES', '|cff1eff00Bolsa de expedición de Hyjal', 'Bolsa de herborista (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('19', 'esES', '|cff0070ddCaja de herramientas de elementium', 'Bolsa de ingeniero (slots: 36)\nLa mejor caja de herramientas que este mundo haya visto. Incrustada en oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('20', 'esES', '|cff0070ddBolsa de escriba real', 'Bolsa de escriba (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('21', 'esES', '|cff0070ddBolsa minera reforzada tres veces', 'Bolsa de minero (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('22', 'esES', '|cff0070ddBolsa de cuero magnífica', 'Bolsa de peletero (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('23', 'esES', '|cff0070ddBolsa ilusoria', 'Bolsa (slots: 26)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('24', 'esES', '|cff0070ddBolsa raída de tela maldita', 'Bolsa (slots: 24)\nDe trozos de tela recogidos en Zul\'Aman.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('25', 'esES', '|cff0070ddBolsa de hielo', 'Bolsa (slots: 22)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('26', 'esES', '|cff0070ddBolsa de destello solar', 'Bolsa (slots: 20)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('27', 'esES', '|cff0070ddBolsa sin fondo', 'Bolsa (slots: 18)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('28', 'esES', '|cff1eff00Mochila de viajero', 'Bolsa (slots: 16)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('29', 'esES', 'Mochila de aprendiz', 'Bolsa (slots: 14)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('30', 'esES', 'Mochila grande', 'Bolsa (slots: 12)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('91', 'esES', '|cffa335eeMejora de profesión', 'Te da la oportunidad de subir cualquier profesión a nivel 600.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('92', 'esES', '|cff0070ddMejora de profesión menor', 'Te da la oportunidad de subir cualquier profesión al nivel máximo disponible (75, 150, 225, 300, 375, 450, 525 o 600 puntos).');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('93', 'esES', '|cffffd700Subida de nivel a 90', 'Todos los héroes pasan por momentos difíciles. A veces se requiere un nuevo impulso. Este aumento de nivel único lleva a uno de tus personajes a nivel 90 de inmediato.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('94', 'esES', '|cffffd700Cambio de nombre', 'No tienes que llevar el mismo nombre toda la vida. Tal vez te has cansado de que te pidan autógrafos (o te quieran golpear), o simplemente has pensado en uno mejor. ¡Un nuevo nombre es una nueva vida!');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('95', 'esES', '|cffffd700Cambio de facción', '«¡Traidor!..» Es fácil decirlo. A tus compañeros de facción probablemente no les gustará que te vayas. Pero, ¿qué les debes realmente? Quizás es hora de ver cómo están los demás. ¡Tal vez ya tienes amigos ahí! Quién sabe, tal vez los "épicos" realmente sean más épicos donde no estamos... El cambio de facción incluye un cambio de raza para facilitar la integración.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('96', 'esES', '|cffffd700Cambio de raza', 'La genética es cruel. Intenta vivir siendo verde todo el tiempo. O azul. O morado. Y además con orejas puntiagudas. A veces un cambio cosmético no es suficiente y se requiere un cambio radical: ¡cambiar de raza por completo!');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('97', 'esES', '|cffffd700Cambio de apariencia', 'Todo cambia. Personas, cortes de pelo, tasas de interés... Si te has cansado de cómo se ve tu personaje, y no quieres usar un casco todo el tiempo, este servicio te vendrá muy bien. ¡Ojalá existiera en la vida real! Puedes cambiar completamente la apariencia e incluso el género de tu personaje.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('98', 'esES', '|cffa335ee1.000 puntos de honor', 'Te da 1.000 puntos de honor.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('99', 'esES', '|cffa335ee1.000 puntos de justicia', 'Te da 1.000 puntos de justicia.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('100', 'esES', '|cffa335ee1.000 puntos de valor', 'Te da 1.000 puntos de valor.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('101', 'esES', '|cffa335ee1.000 puntos de conquista', 'Te da 1.000 puntos de conquista.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('102', 'esES', '|cff0070ddElixir de conocimiento antiguo', 'Un susurro apenas audible proviene de la botella.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('168', 'esES', '|cffffe4b5Capa antigua de la Luna Sangrienta', 'Espalda');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('169', 'esES', '|cffffe4b5Capa heredada del barón negro', 'Espalda');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('170', 'esES', '|cffffe4b5Capa desgarrada de la tormenta de arena', 'Espalda');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('171', 'esES', '|cffffe4b5Capa gastada de la gárgola de piedra', 'Espalda');

INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('1', 'esMX', '|cffff8000Promoción', 'Posibilidad de "promocionar" tu personaje en la cuenta actual o crear uno nuevo con algunos bonos.\n\nComo bonos recibirás:\n- Equipamiento de nivel de objeto 408\n- Arma de nivel de objeto 408\n- Accesorios y capa de nivel de objeto 408\n- 1.000 de oro\n- Nivel 90 instantáneo\n- Montura: Rienda de viento anaranjado (Horda) o Grifo blanco (Alianza)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('2', 'esMX', '|cffff8000Promoción', 'Posibilidad de "promocionar" tu personaje en la cuenta actual o crear uno nuevo con algunos bonos.\n\nComo bonos recibirás:\n- Equipamiento de nivel de objeto 408\n- Arma de nivel de objeto 408\n- Accesorios y capa de nivel de objeto 408\n- 1.000 de oro\n- Nivel 90 instantáneo\n- Montura: Rienda de viento anaranjado (Horda) o Grifo blanco (Alianza)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('3', 'esMX', '|cff1eff00Ficha de Pandaria (Denominación: 01)', 'Agrega 1 punto virtual para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('4', 'esMX', '|cff0070ddFicha de Pandaria (Denominación: 02)', 'Agrega 2 puntos virtuales para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('5', 'esMX', '|cffa335eeFicha de Pandaria (Denominación: 05)', 'Agrega 5 puntos virtuales para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('6', 'esMX', '|cffff8000Ficha de Pandaria (Denominación: 10)', 'Agrega 10 puntos virtuales para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('7', 'esMX', '|cff1eff001.000 monedas de oro', 'Te da 1.000 monedas de oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('8', 'esMX', '|cff1eff005.000 monedas de oro', 'Te da 5.000 monedas de oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('9', 'esMX', '|cff0070dd10.000 monedas de oro', 'Te da 10.000 monedas de oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('10', 'esMX', '|cff0070dd30.000 monedas de oro', 'Te da 30.000 monedas de oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('11', 'esMX', '|cffa335ee80.000 monedas de oro', 'Te da 80.000 monedas de oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('12', 'esMX', '|cffff8000150.000 monedas de oro', 'Te da 150.000 monedas de oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('13', 'esMX', '|cffff8000Caja con suministros infinitos de Foror', 'Bolsa (slots: 36)\nEl fondo del cofre está roto. De ahí salen lágrimas...');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('14', 'esMX', '|cffa335eeBolsa real', 'Bolsa (slots: 28)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('15', 'esMX', '|cff0070ddCaja de aparejos del maestro de cebo', 'Bolsa de pesca (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('16', 'esMX', '|cff0070ddBolsa trascendental', 'Bolsa de encantador (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('17', 'esMX', '|cff0070ddBolsa de seda lujosa para gemas', 'Bolsa de joyero (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('18', 'esMX', '|cff1eff00Bolsa de expedición de Hyjal', 'Bolsa de herborista (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('19', 'esMX', '|cff0070ddCaja de herramientas de elementium', 'Bolsa de ingeniero (slots: 36)\nLa mejor caja de herramientas que este mundo haya visto. Incrustada en oro.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('20', 'esMX', '|cff0070ddBolsa de escriba real', 'Bolsa de escriba (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('21', 'esMX', '|cff0070ddBolsa minera reforzada tres veces', 'Bolsa de minero (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('22', 'esMX', '|cff0070ddBolsa de cuero magnífica', 'Bolsa de peletero (slots: 36)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('23', 'esMX', '|cff0070ddBolsa ilusoria', 'Bolsa (slots: 26)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('24', 'esMX', '|cff0070ddBolsa raída de tela maldita', 'Bolsa (slots: 24)\nDe trozos de tela recogidos en Zul\'Aman.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('25', 'esMX', '|cff0070ddBolsa de hielo', 'Bolsa (slots: 22)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('26', 'esMX', '|cff0070ddBolsa de destello solar', 'Bolsa (slots: 20)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('27', 'esMX', '|cff0070ddBolsa sin fondo', 'Bolsa (slots: 18)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('28', 'esMX', '|cff1eff00Mochila de viajero', 'Bolsa (slots: 16)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('29', 'esMX', 'Mochila de aprendiz', 'Bolsa (slots: 14)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('30', 'esMX', 'Mochila grande', 'Bolsa (slots: 12)');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('91', 'esMX', '|cffa335eeMejora de profesión', 'Te da la oportunidad de subir cualquier profesión a nivel 600.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('92', 'esMX', '|cff0070ddMejora de profesión menor', 'Te da la oportunidad de subir cualquier profesión al nivel máximo disponible (75, 150, 225, 300, 375, 450, 525 o 600 puntos).');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('93', 'esMX', '|cffffd700Subida de nivel a 90', 'Todos los héroes pasan por momentos difíciles. A veces se requiere un nuevo impulso. Este aumento de nivel único lleva a uno de tus personajes a nivel 90 de inmediato.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('94', 'esMX', '|cffffd700Cambio de nombre', 'No tienes que llevar el mismo nombre toda la vida. Tal vez te has cansado de que te pidan autógrafos (o te quieran golpear), o simplemente has pensado en uno mejor. ¡Un nuevo nombre es una nueva vida!');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('95', 'esMX', '|cffffd700Cambio de facción', '«¡Traidor!..» Es fácil decirlo. A tus compañeros de facción probablemente no les gustará que te vayas. Pero, ¿qué les debes realmente? Quizás es hora de ver cómo están los demás. ¡Tal vez ya tienes amigos ahí! Quién sabe, tal vez los "épicos" realmente sean más épicos donde no estamos... El cambio de facción incluye un cambio de raza para facilitar la integración.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('96', 'esMX', '|cffffd700Cambio de raza', 'La genética es cruel. Intenta vivir siendo verde todo el tiempo. O azul. O morado. Y además con orejas puntiagudas. A veces un cambio cosmético no es suficiente y se requiere un cambio radical: ¡cambiar de raza por completo!');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('97', 'esMX', '|cffffd700Cambio de apariencia', 'Todo cambia. Personas, cortes de pelo, tasas de interés... Si te has cansado de cómo se ve tu personaje, y no quieres usar un casco todo el tiempo, este servicio te vendrá muy bien. ¡Ojalá existiera en la vida real! Puedes cambiar completamente la apariencia e incluso el género de tu personaje.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('98', 'esMX', '|cffa335ee1.000 puntos de honor', 'Te da 1.000 puntos de honor.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('99', 'esMX', '|cffa335ee1.000 puntos de justicia', 'Te da 1.000 puntos de justicia.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('100', 'esMX', '|cffa335ee1.000 puntos de valor', 'Te da 1.000 puntos de valor.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('101', 'esMX', '|cffa335ee1.000 puntos de conquista', 'Te da 1.000 puntos de conquista.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('102', 'esMX', '|cff0070ddElixir de conocimiento antiguo', 'Un susurro apenas audible proviene de la botella.');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('168', 'esMX', '|cffffe4b5Capa antigua de la Luna Sangrienta', 'Espalda');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('169', 'esMX', '|cffffe4b5Capa heredada del barón negro', 'Espalda');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('170', 'esMX', '|cffffe4b5Capa desgarrada de la tormenta de arena', 'Espalda');
INSERT INTO `battle_pay_entry_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('171', 'esMX', '|cffffe4b5Capa gastada de la gárgola de piedra', 'Espalda');


-- Battle Pay Product Locale
DROP TABLE IF EXISTS `battle_pay_product_locale`;
CREATE TABLE IF NOT EXISTS `battle_pay_product_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `Locale` VARCHAR(4) NOT NULL,
  `Title` TEXT,
  `Description` TEXT,
  PRIMARY KEY (`ID`, `Locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'koKR', `title_loc1`, `description_loc1` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc1`) > 0 OR LENGTH(`description_loc1`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'frFR', `title_loc2`, `description_loc2` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc2`) > 0 OR LENGTH(`description_loc2`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'deDE', `title_loc3`, `description_loc3` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc3`) > 0 OR LENGTH(`description_loc3`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'zhCN', `title_loc4`, `description_loc4` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc4`) > 0 OR LENGTH(`description_loc4`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'zhTW', `title_loc5`, `description_loc5` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc5`) > 0 OR LENGTH(`description_loc5`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'esES', `title_loc6`, `description_loc6` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc6`) > 0 OR LENGTH(`description_loc6`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'esMX', `title_loc7`, `description_loc7` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc7`) > 0 OR LENGTH(`description_loc7`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'ruRU', `title_loc8`, `description_loc8` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc8`) > 0 OR LENGTH(`description_loc8`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'itIT', `title_loc9`, `description_loc9` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc9`) > 0 OR LENGTH(`description_loc9`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'ptBR', `title_loc10`, `description_loc10` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc10`) > 0 OR LENGTH(`description_loc10`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`)
SELECT `id`, 'ptPT', `title_loc11`, `description_loc11` 
FROM `locales_battle_pay_product` 
WHERE LENGTH(`title_loc11`) > 0 OR LENGTH(`description_loc11`) > 0
ON DUPLICATE KEY UPDATE 
    `Title` = VALUES(`Title`), 
    `Description` = VALUES(`Description`);
    

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('1', 'esES', 'Tienda:\nFicha de Pandaria (Denominación: 01)', 'Agrega 1 punto virtual para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('2', 'esES', 'Tienda:\nFicha de Pandaria (Denominación: 02)', 'Agrega 2 puntos virtuales para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('3', 'esES', 'Tienda:\nFicha de Pandaria (Denominación: 05)', 'Agrega 5 puntos virtuales para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('4', 'esES', 'Tienda:\nFicha de Pandaria (Denominación: 10)', 'Agrega 10 puntos virtuales para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('13', 'esES', 'Tienda:\nCaja con suministros infinitos de Foror', 'Bolsa (slots: 36)\nEl fondo del cofre está roto. De ahí salen lágrimas...');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('14', 'esES', 'Tienda:\nBolsa real', 'Bolsa (slots: 28)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('15', 'esES', 'Tienda:\nCaja de aparejos del maestro de cebo', 'Bolsa de pesca (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('16', 'esES', 'Tienda:\nBolsa trascendental', 'Bolsa de encantador (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('17', 'esES', 'Tienda:\nBolsa de seda lujosa para gemas', 'Bolsa de joyero (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('18', 'esES', 'Tienda:\nBolsa de expedición de Hyjal', 'Bolsa de herborista (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('19', 'esES', 'Tienda:\nCaja de herramientas de elementium', 'Bolsa de ingeniero (slots: 36)\nLa mejor caja de herramientas que este mundo haya visto. Incrustada en oro.');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('20', 'esES', 'Tienda:\nBolsa de escriba real', 'Bolsa de escriba (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('21', 'esES', 'Tienda:\nBolsa minera reforzada tres veces', 'Bolsa de minero (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('22', 'esES', 'Tienda:\nBolsa de cuero magnífica', 'Bolsa de peletero (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('23', 'esES', 'Tienda:\nBolsa ilusoria', 'Bolsa (slots: 26)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('24', 'esES', 'Tienda:\nBolsa raída de tela maldita', 'Bolsa (slots: 24)\nDe trozos de tela recogidos en Zul\'Aman.');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('25', 'esES', 'Tienda:\nBolsa de hielo', 'Bolsa (slots: 22)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('26', 'esES', 'Tienda:\nBolsa de destello solar', 'Bolsa (slots: 20)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('27', 'esES', 'Tienda:\nBolsa sin fondo', 'Bolsa (slots: 18)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('28', 'esES', 'Tienda:\nMochila de viajero', 'Bolsa (slots: 16)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('29', 'esES', 'Tienda:\nMochila de aprendiz', 'Bolsa (slots: 14)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('30', 'esES', 'Tienda:\nMochila grande', 'Bolsa (slots: 12)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('168', 'esES', 'Tienda:\nCapa antigua de la Luna Sangrienta', 'Espalda');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('169', 'esES', 'Tienda:\nCapa heredada del barón negro', 'Espalda');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('170', 'esES', 'Tienda:\nCapa desgarrada de la tormenta de arena', 'Espalda');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('171', 'esES', 'Tienda:\nCapa gastada de la gárgola de piedra', 'Espalda');

INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('1', 'esMX', 'Tienda:\nFicha de Pandaria (Denominación: 01)', 'Agrega 1 punto virtual para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('2', 'esMX', 'Tienda:\nFicha de Pandaria (Denominación: 02)', 'Agrega 2 puntos virtuales para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('3', 'esMX', 'Tienda:\nFicha de Pandaria (Denominación: 05)', 'Agrega 5 puntos virtuales para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('4', 'esMX', 'Tienda:\nFicha de Pandaria (Denominación: 10)', 'Agrega 10 puntos virtuales para la tienda de Pandaria 5.4.8');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('13', 'esMX', 'Tienda:\nCaja con suministros infinitos de Foror', 'Bolsa (slots: 36)\nEl fondo del cofre está roto. De ahí salen lágrimas...');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('14', 'esMX', 'Tienda:\nBolsa real', 'Bolsa (slots: 28)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('15', 'esMX', 'Tienda:\nCaja de aparejos del maestro de cebo', 'Bolsa de pesca (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('16', 'esMX', 'Tienda:\nBolsa trascendental', 'Bolsa de encantador (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('17', 'esMX', 'Tienda:\nBolsa de seda lujosa para gemas', 'Bolsa de joyero (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('18', 'esMX', 'Tienda:\nBolsa de expedición de Hyjal', 'Bolsa de herborista (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('19', 'esMX', 'Tienda:\nCaja de herramientas de elementium', 'Bolsa de ingeniero (slots: 36)\nLa mejor caja de herramientas que este mundo haya visto. Incrustada en oro.');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('20', 'esMX', 'Tienda:\nBolsa de escriba real', 'Bolsa de escriba (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('21', 'esMX', 'Tienda:\nBolsa minera reforzada tres veces', 'Bolsa de minero (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('22', 'esMX', 'Tienda:\nBolsa de cuero magnífica', 'Bolsa de peletero (slots: 36)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('23', 'esMX', 'Tienda:\nBolsa ilusoria', 'Bolsa (slots: 26)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('24', 'esMX', 'Tienda:\nBolsa raída de tela maldita', 'Bolsa (slots: 24)\nDe trozos de tela recogidos en Zul\'Aman.');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('25', 'esMX', 'Tienda:\nBolsa de hielo', 'Bolsa (slots: 22)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('26', 'esMX', 'Tienda:\nBolsa de destello solar', 'Bolsa (slots: 20)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('27', 'esMX', 'Tienda:\nBolsa sin fondo', 'Bolsa (slots: 18)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('28', 'esMX', 'Tienda:\nMochila de viajero', 'Bolsa (slots: 16)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('29', 'esMX', 'Tienda:\nMochila de aprendiz', 'Bolsa (slots: 14)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('30', 'esMX', 'Tienda:\nMochila grande', 'Bolsa (slots: 12)');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('168', 'esMX', 'Tienda:\nCapa antigua de la Luna Sangrienta', 'Espalda');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('169', 'esMX', 'Tienda:\nCapa heredada del barón negro', 'Espalda');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('170', 'esMX', 'Tienda:\nCapa desgarrada de la tormenta de arena', 'Espalda');
INSERT INTO `battle_pay_product_locale` (`ID`, `Locale`, `Title`, `Description`) VALUES ('171', 'esMX', 'Tienda:\nCapa gastada de la gárgola de piedra', 'Espalda');


DROP TABLE IF EXISTS `locales_battle_pay_group`;
DROP TABLE IF EXISTS `locales_battle_pay_entry`;

