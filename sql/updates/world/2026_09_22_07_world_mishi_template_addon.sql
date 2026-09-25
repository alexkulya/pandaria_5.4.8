UPDATE `creature_template_addon` SET `emote` = 0 WHERE `entry` = 64249 AND `emote` = 1;

UPDATE `waypoints` SET `pointid` = `pointid` + 100 WHERE `entry` = 64249 AND `pointid` BETWEEN 0 AND 8;
UPDATE `waypoints` SET `pointid` = `pointid` - 99 WHERE `entry` = 64249 AND `pointid` BETWEEN 100 AND 108;
