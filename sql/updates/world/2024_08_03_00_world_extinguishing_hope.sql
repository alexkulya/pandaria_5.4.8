-- Fire Extinguisher
DELETE FROM `spell_area` WHERE `spell` = 80209;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`,`quest_start_status`,`quest_end_status`) VALUES
(80209,9,26391,0,0,1101,2,1,10,0), -- Долина Североземья
(80209,59,26391,0,0,1101,2,1,10,0); -- Виноградники Североземья
