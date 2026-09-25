-- Remove linked-spell relations that reference spells not present in the
-- 5.4.8 Spell.dbc loaded by this server.

DELETE FROM `spell_linked_spell`
 WHERE (`spell_trigger` = 123262 AND `spell_effect` = 203754)
    OR (`spell_trigger` = 200002 AND `spell_effect` = 200004)
    OR (`spell_trigger` = 200003 AND `spell_effect` = 200005);
