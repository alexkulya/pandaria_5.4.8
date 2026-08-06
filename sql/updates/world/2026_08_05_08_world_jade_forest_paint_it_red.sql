-- #####################################################################
-- Quest 31765 "Paint it Red!" and the Thunder Hold bombardment.
--
-- Consolidates what used to be migrations _08 and _11:
--     1) the second ability on the clickable Gunship Turrets
--     2) the ported spell scripts and the spellclick rows
--     3) SAI so the Alliance cannons fire back
--     4) object_visibility, so the camp is visible from the turret at all
-- #####################################################################


-- =====================================================================
-- Jade Forest - give the clickable Gunship Turrets their second ability.
--
-- Two sets of "Gunship Turret" are spawned on the Horde gunship:
--
--   66674 / 66676 / 66677 - VehicleId 277,  npcflag 16777216 (SPELLCLICK)
--                           spell1 = 130163, spell2 = 0
--   66183                 - VehicleId 2455, npcflag 0 (not clickable)
--                           spell1 = 130163, spell2 = 130994
--
-- Only the first set can be entered, because only it carries the spellclick
-- flag and a row in npc_spellclick_spells. But it exposes a single ability, so
-- the player ends up in a turret with one button instead of the two the
-- encounter is meant to have:
--
--   130163 - "Full Automatic Fire"
--   130994 - the second turret ability, present only on 66183
--
-- Both vehicles resolve to a single seat and both seats are usable
-- (VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT | VEHICLE_SEAT_FLAG_CAN_CONTROL):
--   VehicleId 277  -> seat 2483  flags 0xE2110A13
--   VehicleId 2455 -> seat 11876 flags 0x6210880F
-- so the only difference that matters is the spell list. Copy the second
-- ability onto the clickable turrets.
--
-- Note: this does NOT touch npc_spellclick_spells. Those rows must stay on
-- 57573 (the generic ride-vehicle spell, the only one carrying
-- SPELL_AURA_CONTROL_VEHICLE). Spells 130996/130997/130998 are
-- "Summon Skyfire Gyrocopter": they summon creature 66183 as a plain ally
-- (SummonProperties 3283 = category ALLY, type NONE) and grant kill credit,
-- with no vehicle-control aura anywhere in their effects, so they can never
-- seat a player.
-- =====================================================================

-- CORRECTION: an earlier version of this migration set spell2 = 130994 on the
-- clickable turrets, on the assumption that their button was 130163. Compared
-- against the reference database (world on port 3307) that was wrong:
--
--          column     |  reference   |  what was here
--   -----------------+--------------+-----------------
--     VehicleId      |     2455     |   277
--     spell1         |   130973     |   130163
--     spell2         |        0     |   130994
--     faction        |       35     |   1735
--     unit_flags     |     2048     |   0
--
-- 130973 is the right spell: SpellEffect gives it effect 32 TRIGGER_MISSILE
-- with tgtA 89 TARGET_DEST_TRAJ, triggering 130994. The PLAYER casts it, so
-- the client attaches the trajectory to the cast request and
-- Spell::SelectImplicitTrajTargets works on its own. 130994 is not a second
-- button: it is what 130973 fires, and it carries the damage and the four
-- KILL_CREDIT2 of the quest.
--
-- npc_spellclick_spells, smart_scripts and conditions already matched the
-- reference and are left alone.
UPDATE `creature_template`
   SET `VehicleId`  = 2455,
       `spell1`     = 130973,
       `spell2`     = 0,
       `faction`    = 35,
       `unit_flags` = 2048
 WHERE `entry` IN (66674, 66676, 66677);

-- 66183 is the summoned turret, not clickable. The reference leaves it with
-- spell1 130163 and no spell2; 130994 had been added here by mistake.
UPDATE `creature_template`
   SET `spell2` = 0, `unit_flags` = 2048
 WHERE `entry` = 66183;
-- =====================================================================
-- Quest 31765 "Paint it Red!" - bind the ported spell scripts.
--
-- The three scripts are ports of TrinityCore's own zone_the_jade_forest.cpp:
--     spell_summon_gunship_turret          130996 / 130997 / 130998
--     spell_cannon_explosion_reversecast   130233 -> triggers 130234
--     spell_barrel_explosion_reversecast   130246 -> triggers 130247
--
-- All six spells exist in this client's DBC, so nothing is invented here.
--
-- npc_spellclick_spells must remain on 57573, the generic vehicle-control
-- spell. Using 130996/130997/130998 here only summons another turret and does
-- not put the player into the clicked vehicle.
--
--     57573       "Ride Vehicle Hardcoded" - carries SPELL_AURA_CONTROL_VEHICLE,
--                 so the player simply mounts the turret that was clicked
--                 (66674/66676/66677, one ability).
--     130996/7/8  "Summon Gunship Turret" - SPELL_EFFECT_SUMMON of creature
--                 66183, the turret that actually carries both abilities
--                 (130163 + 130994), plus the periodic dummy on EFFECT_1 that
--                 the ported script hooks.
--
-- ROLLBACK: if boarding stops working, put the stopgap back with
--     UPDATE `npc_spellclick_spells` SET `spell_id` = 57573, `cast_flags` = 1
--      WHERE `npc_entry` IN (66674, 66676, 66677);
--     followed by `.reload npc_spellclick_spells`.
-- =====================================================================

DELETE FROM `spell_script_names` WHERE `spell_id` IN (130996, 130997, 130998, 130233, 130246);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(130996, 'spell_summon_gunship_turret'),
(130997, 'spell_summon_gunship_turret'),
(130998, 'spell_summon_gunship_turret'),
(130233, 'spell_cannon_explosion_reversecast'),
(130246, 'spell_barrel_explosion_reversecast');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (66674, 66676, 66677);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(66674, 57573, 1, 0),
(66676, 57573, 1, 0),
(66677, 57573, 1, 0);

-- =====================================================================
-- The Alliance camp shoots back.
--
-- 66203 "Thunder Hold Cannon" x13 shipped with no AIName, no template
-- spells and no smart_scripts at all, so the cannons just sat there while
-- the player bombarded the camp from the turret. Only 66395 "Thunder Hold
-- Cannoneer" had SAI, and its two casts are SMART_EVENT_UPDATE_IC - in
-- combat only - so nothing fired unless the player was engaged.
--
-- The client ships three spells for exactly this scene, and none of them
-- was referenced anywhere in the database:
--     130641  "Horde Intro Alliance Cannonfire HITS"
--     130642  "Horde Intro Alliance Cannonfire HITS (VISUAL)"
--     130717  "Horde Intro Alliance Cannonfire Trails SPECIAL"
--
-- SpellEffect.dbc says all three are EFFECT_DUMMY (3) with implicit target
-- 25, i.e. one-shot casts, NOT auras - they cannot go in
-- `creature_template_addon`, they have to be cast on a timer. 130717 is the
-- muzzle/trail one, so the cannon casts it on itself every 4-9 s while out
-- of combat.
-- =====================================================================

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 66203;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 66203 AND `source_type` = 0;
INSERT INTO `smart_scripts`
    (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,
     `event_param1`,`event_param2`,`event_param3`,`event_param4`,
     `action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,
     `target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`)
VALUES
-- SMART_EVENT_UPDATE_OOC(1): initial 1-6 s, then every 4-9 s so the 13
-- cannons drift out of sync instead of firing in one volley.
-- SMART_ACTION_CAST(11) -> SMART_TARGET_SELF(1)
(66203, 0, 0, 0, 1, 0, 100, 0, 1000, 6000, 4000, 9000, 11, 130717, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
 'Thunder Hold Cannon - out of combat - fire at Hellscream''s Fist');


-- =====================================================================
-- Make the camp visible from the gunship.
--
-- The turret sits at (3165, -740, 302) and `Visibility.Distance.Continents`
-- is 90 yards. Distance from the turret to the NEAREST spawn of every
-- entry in the camp:
--     66203 Cannon        102     66200 Soldier       141
--     66647 Sharp-Shooter 116     66286 Mender        151
--     66395 Cannoneer     117     66284 Laborer       155
--     66348 Armsman       125     66654 Supplies      161   <- the barrels
--     66285/66650 Infantry 131
-- Not a single one of the ~330 objects of the scene is inside 90 yards, so
-- the player mans the turret and looks at an empty camp: no soldiers, no
-- cannons, no barrels, and the quest counter barely moves because only
-- whatever briefly drifts into range can be hit.
--
-- Nothing is missing from the database - both 5.4.8 reference dumps have
-- exactly the same 684 spawns in this box. It is purely an area-of-interest
-- problem, and this core already solves it per entry through
-- `object_visibility` (ObjectMgr::LoadCustomVisibility -> WorldObject::
-- GetVisibilityRange), so neither the global config nor C++ has to change.
--
-- importance = GroundClutter keeps it cheap: CustomVisibility.Threshold.Map
-- defaults to DistantScenery, so anything below it is registered zone-only
-- (Object.cpp:3798). Both the player and the camp are in zone 5785, which is
-- all this scene needs. 350 yards covers the farthest object at 329.
-- =====================================================================

DELETE FROM `object_visibility` WHERE `type` = 'Creature' AND `entry` IN
    (66200,66202,66203,66283,66284,66285,66286,66287,66288,66336,
     66348,66395,66477,66554,66555,66556,66647,66648,66649,66650,66651,66654,66948);
INSERT INTO `object_visibility` (`type`,`entry`,`distance`,`active`,`importance`,`comment`) VALUES
('Creature', 66200, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Soldier (q31765 target)'),
('Creature', 66203, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Cannon (q31765 target)'),
('Creature', 66202, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Laborer'),
('Creature', 66284, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Laborer'),
('Creature', 66651, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Laborer'),
('Creature', 66285, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Infantryman (q31767 target)'),
('Creature', 66650, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Infantryman'),
('Creature', 66288, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Sharp-Shooter'),
('Creature', 66647, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Sharp-Shooter'),
('Creature', 66395, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Cannoneer'),
('Creature', 66348, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Armsman'),
('Creature', 66286, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Mender'),
('Creature', 66649, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Mender'),
('Creature', 66287, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Lieutenant'),
('Creature', 66648, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Lieutenant'),
('Creature', 66283, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Captain Doren (q31769 target)'),
('Creature', 66654, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Supplies (q31768 barrels)'),
('Creature', 66948, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Twisted Corpse'),
('Creature', 66554, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Alliance Barricade (q31769 target)'),
('Creature', 66555, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Alliance Barricade (q31769 target)'),
('Creature', 66556, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Alliance Barricade (q31769 target)'),
('Creature', 66336, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Fire Effects Bunny'),
('Creature', 66477, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Cannon Fire Effects Bunny');

-- The gunship's own fires, seen from the deck and from the camp below.
DELETE FROM `object_visibility` WHERE `type` = 'Creature' AND `entry` = 66795;
INSERT INTO `object_visibility` (`type`,`entry`,`distance`,`active`,`importance`,`comment`) VALUES
('Creature', 66795, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Hellscream''s Fist - Gunship Fire Bunny');

DELETE FROM `object_visibility` WHERE `type` = 'GameObject' AND `entry` IN (215646,215647,215649,215650,215681,215967);
INSERT INTO `object_visibility` (`type`,`entry`,`distance`,`active`,`importance`,`comment`) VALUES
('GameObject', 215649, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Munitions'),
('GameObject', 215650, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Explosives'),
('GameObject', 215646, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Barricade'),
('GameObject', 215647, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Barricade'),
('GameObject', 215681, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Barricade'),
('GameObject', 215967, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Stack of Cannonballs');


-- =====================================================================
-- Follow-ups after seeing the scene in game.
-- =====================================================================

-- 1) Aim the cannons at the gunship itself, not at the player.
--
--    SMART_TARGET_SELF only played the muzzle effect on the spot, and
--    SMART_TARGET_CLOSEST_PLAYER made them track the gunner wherever he
--    flew off to. The barrage has to go at Hellscream's Fist whether or not
--    anyone is aboard.
--
--    SMART_ACTION_CAST requires a real unit (SmartScript.cpp:492 skips
--    anything that fails IsUnit), so a fixed SMART_TARGET_POSITION cannot be
--    used. The only unit on the ship a cannon can even see is a Gunship
--    Turret: the crew sits on phasemask 67108864 while the cannons are on 1,
--    and 1 & 67108864 = 0. The turrets are on 67108865, which keeps bit 1,
--    so 1 & 67108865 = 1 and they resolve fine.
--
--    SMART_TARGET_CLOSEST_CREATURE(19): entry 66674, maxDist 400.
UPDATE `smart_scripts`
   SET `target_type` = 19, `target_param1` = 66674, `target_param2` = 400
 WHERE `entryorguid` = 66203 AND `source_type` = 0 AND `id` = 0;

-- 2) The props that were still popping in only at 90 yards. GO counts match
--    the reference dump exactly (157 = 157 in this box), so nothing is
--    missing from the spawn tables - these three simply had no
--    `object_visibility` row while everything around them got one.
DELETE FROM `object_visibility` WHERE `type` = 'GameObject' AND `entry` IN (215641, 215695, 215588);
INSERT INTO `object_visibility` (`type`,`entry`,`distance`,`active`,`importance`,`comment`) VALUES
('GameObject', 215641, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Water Barrel'),
('GameObject', 215695, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Barrel of Honeybrew'),
('GameObject', 215588, 350, 0, 'GroundClutter', 'Pandaria - Jade Forest - Thunder Hold - Damaged Thunder Hold Cannon');


-- 3) The quest credits of the barrage.
--    130973 (spell1 of the clickable turret) is a TRIGGER_MISSILE with a
--    trajectory and fires 130994. The damage of 130994 resolves fine, but its
--    four SPELL_EFFECT_KILL_CREDIT2 (3x 66200 + 1x 66203) hang off implicit
--    target 105, which this core flags as TARGET_SELECT_CATEGORY_NYI and which
--    never selects anybody (Spell.cpp:971). Without them the counter only
--    advances on real kills: 12 soldiers on a 60 second respawn to reach 80.
--    spell_gunship_turret_barrage credits per unit actually hit.
DELETE FROM `spell_script_names` WHERE `spell_id` IN (130163, 130994);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(130994, 'spell_gunship_turret_barrage');
