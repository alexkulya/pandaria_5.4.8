DELETE FROM `command` WHERE `name` IN ("reload locales_creature_text", "reload locales_gameobject", "reload locales_npc_text",
"reload locales_page_text", "reload locales_points_of_interest", "reload locales_quest",
"reload achievement_reward_locale", "reload creature_text_locale", "reload gameobject_template_locale", "reload npc_text_locale",
"reload page_text_locale", "reload points_of_interest_locale", "reload quest_template_locale", "reload quest_objective_locale", "reload quest_offer_reward_locale", "reload quest_request_items_locale");
INSERT INTO `command` (`name`, `security`, `help`) VALUES
("reload achievement_reward_locale", 5, "Syntax: .reload achievement_reward_locale\nReload achievement_reward_locale table."),
("reload creature_text_locale", 5, "Syntax: .reload creature_text_locale\nReload creature_text_locale table."),
("reload gameobject_template_locale", 5, "Syntax: .reload gameobject_template_locale\nReload gameobject_template_locale table."),
("reload npc_text_locale", 5, "Syntax: .reload npc_text_locale\nReload npc_text_locale table."),
("reload page_text_locale", 5, "Syntax: .reload page_text_locale\nReload page_text_locale table."),
("reload points_of_interest_locale", 5, "Syntax: .reload points_of_interest_locale\nReload points_of_interest_locale table."),
("reload quest_template_locale", 5, "Syntax: .reload quest_template_locale\nReload quest_template_locale table."),
("reload quest_objective_locale", 5, "Syntax: .reload quest_objective_locale\nReload quest_objective_locale table."),
("reload quest_offer_reward_locale", 5, "Syntax: .reload quest_offer_reward_locale\nReload quest_offer_reward_locale table."),
("reload quest_request_items_locale", 5, "Syntax: .reload quest_request_items_locale\nReload quest_request_items_locale table.");
