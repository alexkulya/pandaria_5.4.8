-- Quest 31766 "Touching Ground" - give the rope creature a vehicle kit.
--
-- Migration _02 wired every script of the descent and they are all correct:
--     GO 215689  data10 = 130960                  (the goober casts the spell)
--     130960  -> spell_jade_forest_rappelling_rope (summons creature 66640)
--     85299   -> spell_reverse_cast_ride_seat_1    (rope seats the player)
--     66640   -> npc_jade_forest_rappelling_rope   (carries him down)
--
-- But 66640 was left with VehicleId = 0, so it never becomes a vehicle and the
-- whole chain dies silently on the last step:
--
--     AuraEffect::HandleAuraControlVehicle (SpellAuraEffects.cpp:3168)
--         if (!target->IsVehicle())
--             return;
--
-- 85299 reverse-casts 52391 "Vehicle Control", an APPLY_AURA of
-- SPELL_AURA_CONTROL_VEHICLE (236). With no vehicle kit that aura returns
-- immediately, the player is never seated, PassengerBoarded never fires and
-- the scheduled MovePoint down the rope never runs - which is why the player
-- simply ended up at the bottom with no descent.
--
-- Seat index: the handler uses `m_amount - 1` (SpellAuraEffects.cpp:3188) and
-- 52391 has BasePoints 1, so it asks for seat 0. A single seat is enough.
--
-- CAVEAT: the retail VehicleId for 66640 could not be established. It is not
-- in the reference database, Wowhead has no data for this NPC, and the value
-- lives in world data rather than in the DBCs. 2427 is used by 65689
-- "Mountain Climber Rope", the closest analogue in this database (same
-- faction 35, same npcflag 0, also a rope that carries a passenger), and its
-- single seat 11776 has flags 0x0200800F: no CAN_CONTROL, no CAN_CAST and no
-- IS_USING_VEHICLE_CONTROLS, i.e. a pure passenger seat with no vehicle UI,
-- which is exactly what being carried down a rope needs.
--
-- If the descent looks wrong (bad attachment point or orientation), the other
-- passenger-only rope vehicles in this database are 2386 "Rope Seat",
-- 2322 and 2514 "Zip Line".

-- CORRECTION: 2427 was the first pick, but its seat 11776 carries
-- passengerPitch -1.222 rad (about -70 degrees) because Mountain Climber Rope
-- is meant for scaling a wall - it laid the player flat on his back during the
-- descent. 2386 "Rope Seat" is the right one: same passenger-only seat flags,
-- the name matches, and its seat 11574 has yaw, pitch and roll all at zero, so
-- the player hangs upright.
-- SEAT POSE: the wanted look is the player hanging off the rope, gripping it
-- with both hands. There is no rappel animation in this client at all -
-- AnimationData.dbc has nothing matching rappel, climb, hang, rope, descend or
-- zip - so the seat was picked by scanning every VehicleSeat in the DBC for the
-- closest combination instead of guessing among the rope-named vehicles:
--
--     2427 seat 11776  body 0            upper Mount             pitch -1.222
--     2386 seat 11574  body Fall         upper UseStandingLoop   pitch 0
--     1399 seat  9296  body SitChairLow  upper Mount             pitch 0
--      546 seat  6387  body Hover        upper Mount             pitch 0   <- this
--
-- 2427 laid the player flat on his back, 2386 read as walking because of the
-- standing torso, 1399 sat him down. 546 is the only seat in the file that
-- pairs a Hover body - suspended in the air - with Mount on the upper body,
-- which is the game's "both hands gripping" pose. Yaw, pitch and roll are all
-- zero and the seat is passenger-only with CAN_ENTER_OR_EXIT.
UPDATE `creature_template`
   SET `VehicleId` = 546
 WHERE `entry` = 66640;

-- The carrier creature also had a junk model: modelid1 1126 resolves to
-- CREATURE\INFERNAL\INFERNAL.M2 (an Infernal), and TrinityCore picks at random
-- among the non-zero modelid1..4, so half the time the "rope" showed up as a
-- giant demon. modelid2 was already 11686
-- CREATURE\INVISIBLESTALKER\INVISIBLESTALKER.M2, which is the right one: the
-- rope the player sees is drawn by aura 130970, triggered on the caster by
-- effect 1 of 130960, not by the creature itself.
UPDATE `creature_template`
   SET `modelid1` = 11686,
       `modelid2` = 0
 WHERE `entry` = 66640;

-- InhabitType 3 is ground+water, with no air bit, so the carrier was not even
-- allowed to be airborne. The rope hangs off a deck that only exists in
-- terrain swap 1076 - a client-side swap the server has no vmap for - so the
-- server sees open air there and the creature has to fly to hold position and
-- to descend. 7 = ground | water | air.
UPDATE `creature_template`
   SET `InhabitType` = 7
 WHERE `entry` = 66640;

-- Anchor the rope visual. Effect 0 of 130970 "Rappelling Rope Aura" uses
-- tgtA 38 TARGET_UNIT_NEARBY_ENTRY, and that target reads the entry it should
-- look for from `conditions`, not from the spell. With no rows the core logs
--     Spell::SelectImplicitNearbyTargets: no conditions entry for target with
--     TARGET_CHECK_ENTRY of spell ID 130970, effect 0 - selecting default targets
-- and attaches the rope to whatever happens to be closest. Point it at 66640,
-- the carrier summoned by 130960, so the rope is drawn between the player and
-- the thing actually carrying him down.
-- SourceGroup is the effect mask: 1 = EFFECT_0 only. EFFECT_1 targets the
-- caster and needs no filter.
DELETE FROM `conditions`
 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 130970;

INSERT INTO `conditions`
 (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,
  `ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,
  `NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
 (13, 1, 130970, 0, 0, 31, 0, 3, 66640, 0, 0, 0, 0, '', 'Rappelling Rope Aura anchors to the rope carrier 66640');

-- Remove the stopgap that was fighting the real descent.
--
-- The rope carried two gameobject smart_scripts rows, both commented
-- "TEMP HACK!", that ran on every single click:
--
--   event 64 SMART_EVENT_GOSSIP_HELLO
--     -> action 62 SMART_ACTION_TELEPORT, map 870, (3120.98, -749.341, 227.332)
--   event 61 SMART_EVENT_LINK
--     -> action 28 SMART_ACTION_REMOVEAURASFROMSPELL, spell 130960
--
-- The first one is the "player just appears at the bottom" that started this
-- whole investigation: it teleports to a fixed point on the ground. The second
-- is what kept breaking every fix afterwards - 130960 is the spell the rope is
-- summoned by, so stripping that aura despawns the carrier and drops the
-- player out of the seat the instant he boards. The spells log shows it plainly:
--
--     RAPPEL: boarded, player at 3164.1 -735.3 301.6  rope at 298.4
--     SmartGameObjectAI::GossipHello
--     Aura 52391 now is remove mode 1
--     RAPPEL: unboarded at player z=298.4 rope z=298.4
--
-- With the scripted descent working there is nothing left for the hack to
-- stand in for. AIName is left as SmartGameObjectAI: with no rows it does
-- nothing, and clearing it is not needed.
DELETE FROM `smart_scripts`
 WHERE `entryorguid` = 215689 AND `source_type` = 1;

-- Make the rope actually stretch as the player descends.
--
-- 130970 "Rappelling Rope Aura" draws between the two units it lands on:
-- effect 1 on the caster (the player) and effect 0 on whatever
-- TARGET_UNIT_NEARBY_ENTRY resolves to. Pointing effect 0 at 66640 was wrong -
-- that is the carrier, and it descends together with the player, so the rope
-- stayed the same length the whole way down instead of paying out.
--
-- The anchor has to stay at the top, and the data already provides one:
-- 67129 "Rapelling Manfred" is parked next to the ropes and never moves.
--     rope 542186 (3166.9, -737.2)  <->  Manfred 570683 (3167.6, -738.1)  0.9 yd
--     rope 542184 (3154.6, -742.4)  <->  Manfred 570708 (3155.2, -743.3)  1.1 yd
--     rope 542183 (3135.2, -748.4)  <->  none
UPDATE `conditions`
   SET `ConditionValue2` = 67129,
       `Comment` = 'Rappelling Rope Aura anchors to Rapelling Manfred 67129'
 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 130970;

-- The westernmost rope had no anchor, so it would have grabbed one of the other
-- two and drawn the rope sideways across the deck. Same phasemask and
-- orientation as the existing pair, at the same offset from its rope
-- (about +0.7 x, -0.9 y) that the other two use.
DELETE FROM `creature` WHERE `guid` = 582672;
INSERT INTO `creature`
    (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,
     `position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawntimesecs_max`,
     `wander_distance`,`currentwaypoint`,`curhealth`,`curmana`,`movement_type`,`npcflag`)
VALUES
    (582672, 67129, 870, 5785, 6522, 1, 67108864, 0, 0,
     3135.9, -749.3, 301.8, 1.91403, 120, 0, 0, 0, 1, 0, 0, 0);
