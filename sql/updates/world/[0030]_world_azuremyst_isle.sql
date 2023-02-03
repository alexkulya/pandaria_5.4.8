DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 7305;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 7305, 8669, 0, 0, 8, 0, 9280, 0, 0, 0, 0, 0, "", "Proenitus - Show Gossip Text only if Replenishing the Healing Crystals rewarded - or"),
(14, 7305, 8669, 0, 1, 8, 0, 9369, 0, 0, 0, 0, 0, "", "Proenitus - Show Gossip Text only if Replenishing the Healing Crystals rewarded - or"),
(14, 7305, 8667, 0, 0, 8, 0, 9280, 0, 0, 1, 0, 0, "", "Proenitus - Show Gossip Text only if Replenishing the Healing Crystals not rewarded - and"), 
(14, 7305, 8667, 0, 0, 8, 0, 9369, 0, 0, 1, 0, 0, "", "Proenitus - Show Gossip Text only if Replenishing the Healing Crystals not rewarded");

DELETE FROM `creature` WHERE `id` = 17102;
DELETE FROM `creature_addon` WHERE `guid` IN (308064, 308065, 308066, 308068);
