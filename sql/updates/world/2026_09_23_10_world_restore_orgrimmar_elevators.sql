-- Restore the real Orgrimmar Skyway elevator transports from the Legion world DB.
-- The previous custom goobers only provided an emergency teleport and did not
-- spawn the visible retail elevator transports.

DELETE FROM `smart_scripts`
 WHERE `source_type` = 1 AND `entryorguid` IN (301900, 301901);

DELETE FROM `gameobject`
 WHERE `guid` IN (550100, 550101, 550110, 550111, 550112)
    OR `id` IN (301900, 301901, 206608, 206609, 206610);

DELETE FROM `gameobject_template`
 WHERE `entry` IN (301900, 301901);

INSERT INTO `gameobject`
 (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `phaseId`,
  `position_x`, `position_y`, `position_z`, `orientation`,
  `rotation0`, `rotation1`, `rotation2`, `rotation3`,
  `spawntimesecs`, `animprogress`, `state`, `ScriptName`)
VALUES
 (550110, 206608, 1, 1637, 1637, 1, 3, 0,
  1704.78, -4265.96, 34.8837, 3.97628,
  0, 0, 0.956305, -0.292372,
  180, 255, 1, ''),
 (550111, 206609, 1, 1637, 5167, 1, 3, 0,
  1902.05, -4373.10, 43.9968, 5.70721,
  0, 0, 0.956305, -0.292372,
  180, 255, 1, ''),
 (550112, 206610, 1, 1637, 5170, 1, 3, 0,
  1755.31, -4396.60, 42.3478, 3.74494,
  0, 0, 0.956305, -0.292372,
  180, 255, 1, '');
