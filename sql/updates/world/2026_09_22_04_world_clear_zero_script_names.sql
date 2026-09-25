-- ScriptName is optional. A literal "0" is not a valid core script name and
-- only produces a startup warning, so keep the DB behavior and clear it.
UPDATE `conditions`
   SET `ScriptName` = ''
 WHERE `ScriptName` = '0';

UPDATE `creature_template`
   SET `ScriptName` = ''
 WHERE `ScriptName` = '0';
