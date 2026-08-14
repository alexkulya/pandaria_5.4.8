ALTER TABLE `guild_member` ADD COLUMN `activity` bigint(20) NOT NULL AFTER `achievement_points`;
ALTER TABLE `guild_member` ADD COLUMN `weekActivity` int(10) NOT NULL DEFAULT 0 AFTER `activity`;
