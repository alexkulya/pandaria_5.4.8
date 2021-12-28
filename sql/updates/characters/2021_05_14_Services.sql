-- agregando el registro para las profesiones
ALTER TABLE `executed_services` CHANGE `type` `type` ENUM('rename','change_acc','customize','change_race','change_class','change_prof','char_restore','guild_rename','unban','level_down','marketplace','transfer','boost','item_restore','boost_profession','boost_profession_small') CHARSET utf8 COLLATE utf8_general_ci NOT NULL; 
-- solo debe ejecutarse una vez
