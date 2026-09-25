-- Tornado (64267) has a DB SmartAI aura script, but the referenced C++
-- ScriptName is not registered in this core, so worldserver skips its SmartAI.
UPDATE `creature_template`
   SET `AIName` = 'SmartAI',
       `ScriptName` = ''
 WHERE `entry` = 64267;
