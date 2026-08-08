-- Repair implicit-target conditions whose SourceGroup effect mask includes an
-- effect that has no area, cone or nearby target. ConditionMgr rejects the
-- whole condition and warns 52 times on a clean startup.
--
-- Masks were recomputed from SpellEffect.dbc and applied as an intersection, so
-- distinct per-effect conditions are never merged.

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 63090 AND `SourceGroup` = 2;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 80199 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 80702 AND `SourceGroup` = 2;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 81744 AND `SourceGroup` = 7;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 81748 AND `SourceGroup` = 7;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 106332 AND `SourceGroup` = 2;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 109440 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 112879 AND `SourceGroup` = 3;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 114379 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 116711 AND `SourceGroup` = 3;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 120267 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 122551 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 125931 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 126642 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 131053 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 136461 AND `SourceGroup` = 64;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 136461 AND `SourceGroup` = 128;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 136909 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 137206 AND `SourceGroup` = 176816128;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 138002 AND `SourceGroup` = 12;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 140546 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 143487 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 146662 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 147353 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 147369 AND `SourceGroup` = 1;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 147370 AND `SourceGroup` = 1;

-- ---------------------------------------------------------------------
-- Part 2: rows that come back to life. THESE DO CHANGE BEHAVIOUR: the
-- condition is ignored today, and after trimming the mask it starts
-- filtering the effect it was written for. That is the intent of the data,
-- but it is worth verifying the encounters involved:
--     137433 / 137442 / 137443 / 137444  Horridon Control  (Throne of Thunder)
--     100342 / 100344 / 100345           Summon Flame Lord (Firelands)
--     89008  Mother''s Flame,  100555 Smouldering Roots,  85555 Burn Corpse
-- ---------------------------------------------------------------------
UPDATE `conditions` SET `SourceGroup` = 1 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 64558 AND `SourceGroup` = 7;
UPDATE `conditions` SET `SourceGroup` = 1 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 68355 AND `SourceGroup` = 7;
UPDATE `conditions` SET `SourceGroup` = 1 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 74670 AND `SourceGroup` = 3;
UPDATE `conditions` SET `SourceGroup` = 1 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 78499 AND `SourceGroup` = 3;
UPDATE `conditions` SET `SourceGroup` = 1 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 85555 AND `SourceGroup` = 3;
UPDATE `conditions` SET `SourceGroup` = 2 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 89008 AND `SourceGroup` = 3;
UPDATE `conditions` SET `SourceGroup` = 1 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 89892 AND `SourceGroup` = 7;
UPDATE `conditions` SET `SourceGroup` = 1 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 100342 AND `SourceGroup` = 7;
UPDATE `conditions` SET `SourceGroup` = 1 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 100344 AND `SourceGroup` = 7;
UPDATE `conditions` SET `SourceGroup` = 1 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 100345 AND `SourceGroup` = 7;
UPDATE `conditions` SET `SourceGroup` = 2 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 100555 AND `SourceGroup` = 3;
UPDATE `conditions` SET `SourceGroup` = 1 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 119841 AND `SourceGroup` = 3;
UPDATE `conditions` SET `SourceGroup` = 1 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 126022 AND `SourceGroup` = 3;
UPDATE `conditions` SET `SourceGroup` = 1 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 134789 AND `SourceGroup` = 3;
UPDATE `conditions` SET `SourceGroup` = 2 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 137433 AND `SourceGroup` = 3;
UPDATE `conditions` SET `SourceGroup` = 2 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 137442 AND `SourceGroup` = 3;
UPDATE `conditions` SET `SourceGroup` = 2 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 137443 AND `SourceGroup` = 3;
UPDATE `conditions` SET `SourceGroup` = 2 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 137444 AND `SourceGroup` = 3;
UPDATE `conditions` SET `SourceGroup` = 1 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 137967 AND `SourceGroup` = 7;
