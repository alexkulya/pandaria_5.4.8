-- =====================================================================
-- Jade Forest (zone 5785) - phasing and fire effects, Horde side.
--
-- Consolidates what used to be migrations _06, _12, _13, _19, _20 and _21.
--
-- Layout of the zone's phase definitions, all with flags = 0 (so they are
-- additive: PhaseMgr::Recalculate ORs every definition that passes its
-- conditions, and unions their terrain swaps):
--
--   entry 1  phasemask 67108865  terrain 1076  Horde crash site
--   entry 2  phasemask 0         terrain  972  Battlefield  (cond in _02)
--   entry 3  phasemask 0         terrain  971  Alliance hub
--   entry 4  all zeroes, inert
--   entry 7  phasemask 33554433  terrain    0  Sha manifestations  (new)
--
-- Rows 5 and 6 were Krasarang Wilds definitions copied into this zone by
-- mistake; the real ones live in zones 5805 / 6134 / 6138 with their own
-- conditions. Left alone on purpose: entry 4, an inert row.
-- =====================================================================


-- ---------------------------------------------------------------------
-- 1) Entry 1 - the wrecked, burning Hellscream's Fist.
--
-- This row is the whole crash site. Its terrain swap 1076 is the hull and
-- its phasemask 67108864 carries everything standing on it:
--     55135 General Nazgrim, 64856/64868-64874/65148/66667 officers,
--     66793 Hellscream's Fist Engineer x53,
--     66795 Gunship Fire Bunny          x52  <- the fire, see section 3
--     66183 Gunship Turret              x3   (quest 31765 "Paint it Red!")
--     GOs 215718 Fuel Cell x25, 215711 Alarm x12, 215689 Rope x3, ...
--
-- It used to be gated on CONDITION_QUESTREWARDED 31769 "The Final Blow!",
-- which is the LAST quest of the arrival chain
--     31853 -> 29690 -> 31765 -> 31766 -> 31767/31768 -> 31769
-- so the ship was invisible for the entire arrival. It only flashed into
-- view while the 121545 scene aura was up (see `spell_phase`), and vanished
-- the moment that aura fell off.
--
-- The wreck is the Horde landing site and stays there for good, so gate it
-- by team, exactly like the Alliance hub row below.
-- ---------------------------------------------------------------------

DELETE FROM `conditions`
 WHERE `SourceTypeOrReferenceId` = 25 AND `SourceGroup` = 5785 AND `SourceEntry` IN (1, 3, 5, 6, 7);

DELETE FROM `phase_definitions`
 WHERE `zoneId` = 5785 AND `entry` IN (5, 6);

INSERT INTO `phase_definitions`
 (`zoneId`,`entry`,`phasemask`,`phaseId`,`terrainswapmap`,`worldMapArea`,`flags`,`comment`)
VALUES
 (5785, 7, 33554433, 0, 0, 0, 0, 'Jade Forest Sha manifestation phase')
ON DUPLICATE KEY UPDATE `phasemask` = VALUES(`phasemask`), `comment` = VALUES(`comment`);

INSERT INTO `conditions`
 (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,
  `ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,
  `NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
 -- CONDITION_TEAM = 6, HORDE = 67 / ALLIANCE = 469 (SharedDefines.h:886)
 (25, 5785, 1, 0, 0, 6, 0,  67, 0, 0, 0, 0, 0, '', 'Jade Forest Hellscream''s Fist crash site only for the Horde'),
 -- Entry 3 had no conditions at all, so the Horde was dragging the Alliance
 -- hub terrain around too. Nothing changes for the Alliance.
 (25, 5785, 3, 0, 0, 6, 0, 469, 0, 0, 0, 0, 0, '', 'Jade Forest Alliance Hub Phase only for the Alliance'),
 -- CONDITION_QUESTREWARDED = 8
 (25, 5785, 7, 0, 0, 8, 0, 31769, 0, 0, 0, 0, 0, '', 'Jade Forest Sha manifestations after quest 31769 (The Final Blow) is rewarded');


-- ---------------------------------------------------------------------
-- 2) Entry 7 - the Sha manifestations.
--
-- They are the reward of finishing the chain, not part of the landing:
--     quest_objective 31771 -> 66425 x20 and 66426 x7
--     quest_template  31771 "Face to Face With Consequence" PrevQuestId 31769
-- All of them sit in the same pocket, x 3041..3396 / y -1042..-788, well
-- south of the crash site at (3150, -708), and every spawn of these entries
-- on map 870 is inside it. Bit 1<<25 is unused on this map.
--
-- GO 215910 is left alone on purpose: same name as 215860, but its single
-- spawn is at (421, 2236) in Krasarang, nowhere near the Jade Forest.
-- ---------------------------------------------------------------------

UPDATE `creature`
   SET `phaseMask` = 33554432
 WHERE `map` = 870
   AND `id` IN (66425,   -- Sha Haunt      x63
                66426,   -- Sha Harbinger  x17
                66688,   -- Sha Tendrils   x18
                66928);  -- Sha Shooter    x24

UPDATE `gameobject`
   SET `phaseMask` = 33554432
 WHERE `map` = 870
   AND `id` IN (215859,   -- Sha GroundPatch Small Tendrils x6
                215860);  -- Sha GroundPatch Med Tendrils   x6


-- ---------------------------------------------------------------------
-- 3) Fire effects.
--
-- The fire of this whole zone is carried by invisible stalkers whose only
-- job is to hold a cosmetic aura - and their `creature_template_addon`
-- rows had `auras` EMPTY, so they rendered nothing. The wreck was there
-- but not burning, and the bombarded Alliance camp had no flames.
-- The same hole exists in both 5.4.8 reference dumps available locally,
-- so it is an upstream data gap.
--
-- Spell names come from the client's own Spell.dbc:
--     130755  "Cosmetic Gunship Fires"   - the only gunship fire spell
--     130483  "Cosmetic - Fire"
--     130974  "Sha Ground Effect 1"      - what 66477 wrongly carried
-- ---------------------------------------------------------------------

INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`)
VALUES
 -- x52 over both decks of the wreck (z 300..336, phasemask 67108864)
 (66795, 0, 0, 0, 1, 0, '130755'),
 -- x52 on the bombarded ground below (z 247..267)
 (66336, 0, 0, 0, 1, 0, '130483'),
 -- x59, the cannon impact fires. It carried 130974, a Sha ground decal,
 -- which is what painted the white splashes all over Thunder Hold.
 (66477, 0, 0, 0, 1, 0, '130483')
ON DUPLICATE KEY UPDATE `auras` = VALUES(`auras`);


-- =====================================================================
-- Result for a Horde player in the Jade Forest:
--     terrain 1076 + phasemask 67108864 from the moment they enter the
--       zone -> the burning wreck, Nazgrim 55135 and the gunship turrets
--       are there for the whole 29690 -> 31769 chain and stay afterwards
--     terrain  972 only while quest 29694 is taken       (migration _02)
--     phasemask 33554432 only after 31769 is rewarded    -> Sha
-- The Alliance sees none of it, only terrain 971 through row 5785/3.
-- =====================================================================


-- #####################################################################
-- Tooling: strings for the `.debug phase` diff output.
-- Folded in from the old migration _07. Not Jade Forest data, but it is
-- the diagnostic that made the phasing above debuggable, so it travels
-- with it rather than in a file of its own.
-- #####################################################################
-- =====================================================================
-- Strings for the `.debug phase` diff output.
--
-- The command already dumped the current phasing state through the
-- LANG_PHASING_* strings (entries 178-184). These entries back the second
-- half of the report: what changed since the previous run of the command,
-- so accepting a quest or crossing a zone border can be told apart from
-- "nothing happened".
--
-- Range 21100-21109, matching the PhaseDiffStrings enum declared inside
-- cs_debug_phase.cpp. The ids live with the command rather than in Language.h
-- so a debug-only string does not force a rebuild of everything that includes
-- that header.
-- =====================================================================

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 21100 AND 21109;

INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(21100, '|cff0099FFPhaseMgr: Baseline stored for %s (zoneId %u). Run .debug phase again after the action to see what changed.|r'),
(21101, '|cff0099FFPhaseMgr: Changes for %s since the previous report:|r'),
(21102, '|cffFFCC00PhaseMgr: Zone %u -> %u.|r'),
(21103, '|cffFFCC00PhaseMgr: Phasemask %u -> %u (CHANGED).|r'),
(21104, '|cff888888PhaseMgr: Phasemask unchanged (%u).|r'),
(21105, '|cff40FF40PhaseMgr: Definition entry %u (zoneId %u) is now ACTIVE - phasemask %u, terrainswap %u, phaseId %u.|r'),
(21106, '|cffFF4040PhaseMgr: Definition entry %u (zoneId %u) is no longer active - phasemask %u, terrainswap %u, phaseId %u.|r'),
(21107, '|cffFFCC00PhaseMgr: Terrain swaps %s -> %s (CHANGED).|r'),
(21108, '|cff888888PhaseMgr: Terrain swaps unchanged (%s).|r'),
(21109, '|cff888888PhaseMgr: Nothing changed since the previous report.|r');


-- #####################################################################
-- Entry 2 - the Battlefield terrain swap, during "Paint it Red!".
--
-- Migration _02 gated row 5785/2 (terrain 972) on CONDITION_QUESTTAKEN
-- 29694 "Regroup!", which is taken AFTER the bombardment is over. But the
-- script ported from TrinityCore says otherwise - on boarding the turret it
-- re-evaluates the phase definitions with quest 31765:
--
--     // spell_summon_gunship_turret::HandleAfterApply
--     phaseUpdateData.AddQuestUpdate(QUEST_PAINT_IT_RED);   // 31765
--     player->GetPhaseMgr().NotifyConditionChanged(phaseUpdateData);
--
-- That call is pointless unless a definition of this zone is gated on
-- 31765, and entry 2 is the only candidate. Terrain 972 is very likely what
-- dresses the Alliance camp during the attack - the banners and the burning
-- state visible in the reference footage but absent here. Worth noting: the
-- Alliance banner is neither a creature nor a gameobject anywhere near the
-- camp (nearest one is 571 yards away), so terrain is the only thing left
-- that can be drawing it.
--
-- Conditions of the same SourceEntry in different ElseGroups are OR'ed, so
-- this adds 31765 without disturbing the 29694 row that _02 inserts.
-- Reverting is just deleting the ElseGroup 1 row below.
-- #####################################################################

DELETE FROM `conditions`
 WHERE `SourceTypeOrReferenceId` = 25 AND `SourceGroup` = 5785 AND `SourceEntry` = 2 AND `ElseGroup` = 1;

INSERT INTO `conditions`
 (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,
  `ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,
  `NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
 -- CONDITION_QUESTTAKEN = 9
 (25, 5785, 2, 0, 1, 9, 0, 31765, 0, 0, 0, 0, 0, '',
  'Jade Forest Battlefield Phase also while quest 31765 (Paint it Red) is taken');
