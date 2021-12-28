-- Reiniciando los índices de las arenas y los puntos de conquista
DELETE FROM `rated_pvp_info`;

DELETE FROM `character_currency` WHERE `currency` = 484;
DELETE FROM `character_currency` WHERE `currency` = 483;
UPDATE `character_currency` SET `season_count` = 55725, `total_count` = 0, `week_count` = 0, `flags` = 254 WHERE `currency` = 390;
