-- Spirit of Violence (64656) is part of A Celestial Experience in Kun-Lai Summit.
-- The core has no registered C++ script named celestial_experience_sha, while
-- the DB already contains SmartAI using this creature's combat spells.
UPDATE `creature_template`
   SET `AIName` = 'SmartAI',
       `ScriptName` = ''
 WHERE `entry` = 64656;
