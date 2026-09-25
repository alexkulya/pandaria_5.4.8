-- Jade Forest - Amber Kearnen (55283), quest 29727.
--
-- The imported SmartAI row uses action_type 208. In this core 208 is
-- SMART_ACTION_END_project, the enum sentinel, not a runnable action, so the
-- loader skips it every startup:
--   SmartAIMgr: EntryOrGuid 55283 using event(0) has invalid action type (208)
--
-- Quest 29727 "SI:7 Report: Take No Prisoners" is a full sniper/vehicle scene
-- ("Guide Sully through the hozen camp", objective credit 55408). The bad row
-- neither starts a valid scene nor awards the correct objective credit, so do
-- not replace it with autocomplete here. Remove only the invalid script and
-- clear SmartAI if no script remains.

DELETE FROM `smart_scripts`
 WHERE `entryorguid` = 55283
   AND `source_type` = 0
   AND `event_type` = 19
   AND `event_param1` = 29727
   AND `action_type` = 208;

UPDATE `creature_template`
   SET `AIName` = ''
 WHERE `entry` = 55283
   AND `AIName` = 'SmartAI'
   AND NOT EXISTS (
       SELECT 1
         FROM `smart_scripts`
        WHERE `entryorguid` = 55283
          AND `source_type` = 0
   );
