-- Restore access to the Orgrimmar Skyway when the retail elevator transports
-- are unavailable. The original elevator gameobjects are
-- GAMEOBJECT_TYPE_TRANSPORT and this core refuses manual transport spawns from
-- `gameobject`, so use paired SmartAI goobers as a functional lift.

DELETE FROM `smart_scripts`
 WHERE `source_type` = 1 AND `entryorguid` IN (301900, 301901);

DELETE FROM `gameobject`
 WHERE `id` IN (301900, 301901);

DELETE FROM `gameobject_template`
 WHERE `entry` IN (301900, 301901);

INSERT INTO `gameobject_template`
 (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`,
  `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`,
  `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`,
  `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`,
  `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`,
  `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`,
  `unkInt32`, `AIName`, `ScriptName`, `VerifiedBuild`)
VALUES
 (301900, 10, 9542, 'Orgrimmar Skyway Lift', '', '', '', 1.0,
  0, 0, 0, 0, 0, 0,
  0, 0, 0, 3000, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 'SmartGameObjectAI', '', 18414),
 (301901, 10, 9542, 'Orgrimmar Skyway Lift', '', '', '', 1.0,
  0, 0, 0, 0, 0, 0,
  0, 0, 0, 3000, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 'SmartGameObjectAI', '', 18414);

INSERT INTO `gameobject`
 (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `phaseId`,
  `position_x`, `position_y`, `position_z`, `orientation`,
  `rotation0`, `rotation1`, `rotation2`, `rotation3`,
  `spawntimesecs`, `animprogress`, `state`, `ScriptName`)
VALUES
 (550100, 301900, 1, 1637, 1637, 1, 1, 0,
  1769.0000, -4424.1400, 40.0998, 1.308997,
  0, 0, 0.608761, 0.793353,
  300, 255, 1, ''),
 (550101, 301901, 1, 1637, 1637, 1, 1, 0,
  1770.9000, -4380.0200, 101.4760, 4.450590,
  0, 0, -0.793353, 0.608761,
  300, 255, 1, '');

INSERT INTO `smart_scripts`
 (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`,
  `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`,
  `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`,
  `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`,
  `comment`)
VALUES
 (301900, 1, 0, 0, 64, 0,
  100, 0, 0, 0, 0, 0,
  62, 1, 0, 0, 0, 0, 0,
  7, 0, 0, 0, 1770.9000, -4380.0200, 101.4760, 4.450590,
  'Orgrimmar Skyway Lift - On Gossip Hello - Teleport player up to the Skyway'),
 (301901, 1, 0, 0, 64, 0,
  100, 0, 0, 0, 0, 0,
  62, 1, 0, 0, 0, 0, 0,
  7, 0, 0, 0, 1769.0000, -4424.1400, 40.0998, 1.308997,
  'Orgrimmar Skyway Lift - On Gossip Hello - Teleport player down from the Skyway');
