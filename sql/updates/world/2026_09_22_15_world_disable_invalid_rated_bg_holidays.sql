-- Rated Battleground 15v15/25v25 are old 2012 events whose Holidays.dbc
-- entries do not provide a usable first date/duration in this client build.
-- Leaving holidayStage enabled makes the core try to derive event timing from
-- invalid DBC data on every startup.

UPDATE `game_event`
   SET `holidayStage` = 0
 WHERE `holiday` IN (442, 443)
   AND `eventEntry` IN (79, 80);
