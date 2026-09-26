-- Quest 31766 "Touching Ground" - use the correct passenger vehicle for the
-- Jade Forest rappelling rope. Vehicle 546 uses an upright passenger seat; the
-- live value 2479 can drop the player out of the safe descent path.
UPDATE `creature_template`
   SET `VehicleId` = 546
 WHERE `entry` = 66640;
