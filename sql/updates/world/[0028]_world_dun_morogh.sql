DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 42092;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(42092, 78510, 3, 0);

UPDATE `creature_template` SET `npcflag` = 16777216 WHERE `entry` = 42092;
