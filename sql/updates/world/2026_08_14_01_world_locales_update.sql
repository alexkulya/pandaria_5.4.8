RENAME TABLE `locales_item` TO `item_template_locale`;

DELETE FROM `command` WHERE `name` IN ("reload locales_creature", "reload locales_gossip_menu_option", "reload locales_item");
INSERT INTO `command` (`name`, `security`, `help`) VALUES
("reload creature_template_locale", 5, "Syntax: .reload creature_template_locale\nReload creature_template_locale table."),
("reload gossip_menu_option_locale", 5, "Syntax: .reload gossip_menu_option_locale\nReload gossip_menu_option_locale table."),
("reload item_template_locale", 5, "Syntax: .reload item_template_locale\nReload item_template_locale table.");
