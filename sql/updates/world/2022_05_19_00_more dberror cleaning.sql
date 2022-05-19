UPDATE `creature_template` SET `npcflag` = 3 WHERE entry IN (
68538,
69741,
70100,
58507,
62540,
63359,
68084,
73335,
73318,
70752,
70751,
70552,
70100);
UPDATE `quest_template` SET `SpecialFlags` = 2 WHERE Id IN (
30470,
32640,
32641,
14066,
27007,
27152,
29536,
29539,
13564,
869,
27610,
26512,
26930,
25621,
29415,
29392);
UPDATE `creature_template` SET `npcflag` = 2 WHERE entry = 73136;
UPDATE `creature_template` SET `npcflag` = 2 WHERE entry = 67414;
DELETE FROM `creature` WHERE guid IN (
300016,
190058,
66033,
66049,
66076,
66103,
66098,
66001,
190060);
DELETE FROM `creature_addon` WHERE guid = 357467;
UPDATE `quest_template` SET `SpecialFlags` = 1 WHERE Id IN (
31539,
30470,
32640,
32641);
DELETE FROM `creature_queststarter` WHERE quest IN (
40312,
32592,
40313,
40325,
40326,
40327,
40328,
40329);
DELETE FROM `creature_questender` WHERE quest IN (
40312,
32592,
40313,
40325,
40326,
40327,
40328,
40329);
UPDATE `creature_template` SET `ScriptName` = '' WHERE `ScriptName` IN (
'boss_arlokk',
'boss_azshir_the_sleepless',
'boss_bloodmage_thalnos',
'boss_boss_ras_frostwhisper',
'boss_darkmaster_gandling',
'boss_death_knight_darkreaver',
'boss_doctor_theolen_krastinov',
'boss_fenstalker',
'boss_gahzranka',
'boss_glutton',
'boss_hakkar',
'boss_herod',
'boss_high_inquisitor_fairbanks',
'boss_houndmaster_loksey',
'boss_illucia_barov',
'boss_instructor_malicia',
'boss_interrogator_vishas',
'boss_jeklik',
'boss_jindo',
'boss_kirtonos_the_herald',
'boss_koragg',
'boss_kormok',
'boss_lord_alexei_barov',
'boss_lord_raadan',
'boss_lorekeeper_polkelt',
'boss_marli',
'boss_mordresh_fire_eye',
'boss_mr_smite',
'boss_protectors_of_the_endless',
'boss_scarlet_commander_mograine',
'boss_scorn',
'boss_the_ravenian',
'boss_thekal',
'boss_thurg',
'boss_trial_of_king',
'boss_tuten_kash',
'boss_twilight_corrupter',
'boss_vectus',
'boss_arcanist_doan');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
('48181','spell_warl_haunt_t16');
UPDATE `creature_template` SET `ScriptName` = 'npc_pandaren_firework_launcher' WHERE entry = 65934;
UPDATE `creature_template` SET `ScriptName` = 'npc_deadmines_prototype_reaper' WHERE entry =49208;
UPDATE `creature_template` SET `ScriptName` = 'npc_burning_steppes_war_reaver' WHERE entry = 7039;
UPDATE `creature_template` SET `ScriptName` = 'npc_burning_steppes_chiseled_golem' WHERE entry = 48037;
UPDATE `creature_template` SET `ScriptName` = 'npc_warden_of_the_sunwell' WHERE entry = 37523;
UPDATE `creature_template` SET `ScriptName` = 'npc_stranglethorn_emerine' WHERE entry = 43885;
UPDATE `creature_template` SET `ScriptName` = 'npc_stranglethorn_priestess_hurala' WHERE entry = 42812;
UPDATE `creature_template` SET `ScriptName` = 'npc_stranglethorn_priestess_hurala' WHERE entry = 44017;
UPDATE `creature_template` SET `ScriptName` = 'npc_gurgthock_twilands' WHERE entry = 46935;
UPDATE `creature_template` SET `ScriptName` = 'npc_twilight_hurp_derp' WHERE entry = 46944;
UPDATE `creature_template` SET `ScriptName` = 'npc_twilight_calders_creation' WHERE entry = 46946;
UPDATE `creature_template` SET `ScriptName` = 'npc_twilight_calders_creation' WHERE entry = 46945;
UPDATE `creature_template` SET `ScriptName` = 'npc_twilight_calders_creation' WHERE entry = 46947;
UPDATE `creature_template` SET `ScriptName` = 'npc_twilight_lord_tulvan' WHERE entry = 46948;
UPDATE `creature_template` SET `ScriptName` = 'npc_twilight_emberscar_devourer' WHERE entry = 46949;
UPDATE `creature_template` SET `ScriptName` = 'npc_twilight_firebeads_patrol' WHERE entry = 46849;
UPDATE `creature_template` SET `ScriptName` = 'npc_firelands_majordomo_stagheim_event' WHERE entry = 54015;
UPDATE `creature_template` SET `ScriptName` = 'npc_azshara_awol_grunt' WHERE entry = 42646;
UPDATE `creature_template` SET `ScriptName` = 'npc_princess_stillpineAI' WHERE entry = 17682;
UPDATE `creature_template` SET `ScriptName` = 'npc_aged_dying_ancient_kodo' WHERE entry = 4700;
UPDATE `creature_template` SET `ScriptName` = 'npc_watershed_patrol' WHERE entry = 3193;
UPDATE `creature_template` SET `ScriptName` = 'npc_watershed_patrol' WHERE entry = 39325;
UPDATE `creature_template` SET `ScriptName` = 'npc_watershed_patrol' WHERE entry = 39326;
UPDATE `creature_template` SET `ScriptName` = 'npc_watershed_patrol' WHERE entry = 39324;
UPDATE `creature_template` SET `ScriptName` = 'npc_feralas_mountain_giant' WHERE entry = 40026;
UPDATE `creature_template` SET `ScriptName` = 'npc_barrent_wounded_defender' WHERE entry = 38805;
UPDATE `creature_template` SET `ScriptName` = 'npc_sun_moon_colossus' WHERE entry = 46042;
UPDATE `creature_template` SET `ScriptName` = 'npc_queldelar_weapon' WHERE entry = 37158;
UPDATE `creature_template` SET `ScriptName` = 'boss_keristrasza' WHERE entry = 26723;
UPDATE `creature_template` SET `ScriptName` = 'npcs_ashyen_and_keleth' WHERE entry = 17900;
UPDATE `creature_template` SET `ScriptName` = 'npcs_ashyen_and_keleth' WHERE entry = 17901;

UPDATE `creature_template` SET `ScriptName` = 'npc_twilight_faction_champions' WHERE entry = 46946;
UPDATE `creature_template` SET `ScriptName` = 'npc_twilight_faction_champions' WHERE entry = 46945;
UPDATE `creature_template` SET `ScriptName` = 'npc_voljin_ancient_enemy' WHERE entry = 38225;
UPDATE `creature_template` SET `ScriptName` = 'npc_zarjira' WHERE entry = 38306;
UPDATE `creature_template` SET `ScriptName` = 'npc_fire_of_the_seas' WHERE entry = 38542;
UPDATE `creature_template` SET `ScriptName` = 'npc_princess_stillpine' WHERE entry = 17682;
UPDATE `creature_template` SET `ScriptName` = 'npcs_rutgar_and_frankal' WHERE entry = 15221;
UPDATE `creature_template` SET `ScriptName` = 'npcs_rutgar_and_frankal' WHERE entry = 15222;
UPDATE `creature_template` SET `ScriptName` = 'npc_marion_wormswing' WHERE entry = 41112;
UPDATE `creature_template` SET `ScriptName` = 'npc_wounded_blood_elf' WHERE entry = 16993;
UPDATE `creature_template` SET `ScriptName` = 'npc_maghar_captive' WHERE entry = 18210;
UPDATE `creature_template` SET `ScriptName` = 'npc_corki' WHERE entry = 18445;
UPDATE `creature_template` SET `ScriptName` = 'npc_corki' WHERE entry = 20812;
UPDATE `creature_template` SET `ScriptName` = 'npc_corki' WHERE entry = 18369;
UPDATE `creature_template` SET `ScriptName` = 'npc_injured_rainspeaker_oracle' WHERE entry = 28217;
UPDATE `creature_template` SET `ScriptName` = 'npc_hyldsmeet_protodrake' WHERE entry = 29625;
UPDATE `creature_template` SET `ScriptName` = 'npc_hyldsmeet_protodrake' WHERE entry = 29679;
UPDATE `creature_template` SET `ScriptName` = 'npc_hyldsmeet_protodrake' WHERE entry = 29798;
UPDATE `creature_template` SET `ScriptName` = 'npc_gurgthock' WHERE entry = 46935;
UPDATE `creature_template` SET `ScriptName` = 'npc_orinoko_tuskbreaker' WHERE entry = 30020;
UPDATE `creature_template` SET `ScriptName` = 'npc_korrak_bloodrager' WHERE entry = 30023;
UPDATE `creature_template` SET `ScriptName` = 'npc_yggdras' WHERE entry = 30014;
UPDATE `creature_template` SET `ScriptName` = 'npc_stinkbeard' WHERE entry = 30017;
UPDATE `creature_template` SET `ScriptName` = 'npc_deepholm_wyvern' WHERE entry = 45005;
UPDATE `creature_template` SET `ScriptName` = 'npc_deepholm_wyvern_ride' WHERE entry = 45024;
UPDATE `creature_template` SET `ScriptName` = 'npc_maelstorm_aggra' WHERE entry = 45006;
UPDATE `creature_template` SET `ScriptName` = 'npc_achiev_prisoned_sha' WHERE entry = 56766;
UPDATE `creature_template` SET `ScriptName` = 'npc_achiev_prisoned_sha' WHERE entry = 58201;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_muckmaw_crocolisk' WHERE entry = 67922;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_commander_scargash' WHERE entry = 68474;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_krasari_stalker' WHERE entry = 68348;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_king_varian_wrynn' WHERE entry = 69026;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_faction_leader' WHERE entry = 67569;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_faction_leader' WHERE entry = 67883;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_faction_leader' WHERE entry = 68599;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_faction_leader' WHERE entry = 68057;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_faction_leader' WHERE entry = 68240;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_riverblade_marauder' WHERE entry = 68775;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_bogrot' WHERE entry = 67974;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_swamp_gas' WHERE entry = 68816;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_wakened_mogu' WHERE entry = 68102;
UPDATE `creature_template` SET `ScriptName` = 'npc_little_patience_spirit_bomb' WHERE entry = 68296;
UPDATE `creature_template` SET `ScriptName` = 'npc_tears_of_the_vale' WHERE entry = 73638;
UPDATE `creature_template` SET `ScriptName` = 'npc_golden_lotus_trigger' WHERE entry = 71711;
UPDATE `creature_template` SET `ScriptName` = 'npc_golden_lotus_trigger' WHERE entry = 71684;
UPDATE `creature_template` SET `ScriptName` = 'npc_golden_lotus_trigger' WHERE entry = 71686;
UPDATE `creature_template` SET `ScriptName` = 'npc_thok_monstrous_gastropod' WHERE entry = 73164;
UPDATE `creature_template` SET `ScriptName` = 'npc_siege_of_orgrimmar_theramore_prisoners' WHERE entry = 72498;
UPDATE `creature_template` SET `ScriptName` = 'npc_zandalari_beastcaller_passenger' WHERE entry = 69397;
UPDATE `creature_template` SET `ScriptName` = 'npc_willy_wilder' WHERE entry = 70126;
UPDATE `creature_template` SET `ScriptName` = 'npc_despondent_warden_of_zhu' WHERE entry = 57457;
UPDATE `creature_template` SET `ScriptName` = 'npc_despondent_warden_of_zhu' WHERE entry = 58242;
UPDATE `creature_template` SET `ScriptName` = 'npc_despondent_warden_of_zhu' WHERE entry = 58397;
UPDATE `creature_template` SET `ScriptName` = 'npc_despondent_warden_of_zhu' WHERE entry = 58463;
UPDATE `creature_template` SET `ScriptName` = 'npc_kun_lai_grandpa_grumplefloot' WHERE entry = 71082;
UPDATE `creature_template` SET `ScriptName` = 'npc_kunlai_old_poof_poof' WHERE entry = 60015;
UPDATE `creature_template` SET `ScriptName` = 'npc_ooking_shaman' WHERE entry = 60752;
UPDATE `creature_template` SET `ScriptName` = 'npc_silverback_piker' WHERE entry = 60746;
UPDATE `creature_template` SET `ScriptName` = 'npc_broketooth_leaper' WHERE entry = 60742;
UPDATE `creature_template` SET `ScriptName` = 'npc_broketooth_leaper' WHERE entry = 60744;
UPDATE `creature_template` SET `ScriptName` = 'npc_pandriarch_windfur' WHERE entry = 56206;
UPDATE `creature_template` SET `ScriptName` = 'npc_pandriarch_bramblestaff' WHERE entry = 56209;
UPDATE `creature_template` SET `ScriptName` = 'npc_pandriarch_goldendraft' WHERE entry = 56210;
UPDATE `creature_template` SET `ScriptName` = 'npc_big_bao' WHERE entry = 58508;
UPDATE `creature_template` SET `ScriptName` = 'npc_big_bao' WHERE entry = 58512;
UPDATE `creature_template` SET `ScriptName` = 'npc_big_bao' WHERE entry = 66026;
UPDATE `creature_template` SET `ScriptName` = 'npc_jf_wild_prowler' WHERE entry = 56653;
UPDATE `creature_template` SET `ScriptName` = 'npc_jf_wild_stalker' WHERE entry = 56683;
UPDATE `creature_template` SET `ScriptName` = 'npc_lorewalker_cho_stones_could_speak' WHERE entry = 63217;
UPDATE `creature_template` SET `ScriptName` = 'npc_prince_anduin_decision' WHERE entry = 56485;
UPDATE `creature_template` SET `ScriptName` = 'npc_prince_anduin_decision_helpers' WHERE entry = 56487;
UPDATE `creature_template` SET `ScriptName` = 'npc_prince_anduin_decision_helpers' WHERE entry = 56488;
UPDATE `creature_template` SET `ScriptName` = 'npc_prince_anduin_decision_helpers' WHERE entry = 54620;
UPDATE `creature_template` SET `ScriptName` = 'npc_jade_forest_alliance_barricade' WHERE entry = 66554;
UPDATE `creature_template` SET `ScriptName` = 'npc_jade_forest_alliance_barricade' WHERE entry = 66555;
UPDATE `creature_template` SET `ScriptName` = 'npc_jade_forest_alliance_barricade' WHERE entry = 66556;
UPDATE `creature_template` SET `ScriptName` = 'npc_jade_forest_playful_colored_serpent' WHERE entry = 56856;
UPDATE `creature_template` SET `ScriptName` = 'npc_jade_forest_playful_colored_serpent' WHERE entry = 56858;
UPDATE `creature_template` SET `ScriptName` = 'npc_jade_forest_playful_colored_serpent' WHERE entry = 56859;
UPDATE `creature_template` SET `ScriptName` = 'npc_jade_forest_playful_colored_serpent' WHERE entry = 56860;
UPDATE `creature_template` SET `ScriptName` = 'npc_jade_forest_instant_message_camera_bunny' WHERE entry = 56412;
UPDATE `creature_template` SET `ScriptName` = 'npc_longying_ranger' WHERE entry = 60730;
UPDATE `creature_template` SET `ScriptName` = 'npc_lin_silentstrike' WHERE entry = 60899;
UPDATE `creature_template` SET `ScriptName` = 'npc_lin_silentstrike' WHERE entry = 61816;
UPDATE `creature_template` SET `ScriptName` = 'npc_lin_silentstrike' WHERE entry = 62154;
UPDATE `creature_template` SET `ScriptName` = 'npc_lin_silentstrike' WHERE entry = 65771;
UPDATE `creature_template` SET `ScriptName` = 'npc_veb_shado_pan_trainee' WHERE entry = 58992;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_adolescent_mushan' WHERE entry = 56239;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_wyrmhorn_turtle' WHERE entry = 56256;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_lupello' WHERE entry = 56357;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_snagtooth_hooligan' WHERE entry = 56462;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_frenzyhop' WHERE entry = 56514;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_hornbill_strider' WHERE entry = 56753;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_grainhunter_hawk' WHERE entry = 57215;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_grainhunter_hawk' WHERE entry = 57216;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_springtail_gnasher' WHERE entry = 57413;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_mothfighter' WHERE entry = 57648;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_wildscale_herbalist' WHERE entry = 58216;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_ikthik_vanguard' WHERE entry = 58368;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_darkhide' WHERE entry = 58435;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_barrel_of_fireworks' WHERE entry = 59284;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_ik_thik_wing_commander' WHERE entry = 56723;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_manifestation_of_fear' WHERE entry = 59874;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_krungko_fingerlicker' WHERE entry = 64389;
UPDATE `creature_template` SET `ScriptName` = 'npc_vfw_unbarreled_pandaren' WHERE entry = 57681;
UPDATE `creature_template` SET `ScriptName` = 'npc_dread_waster_dread_lurker' WHERE entry = 62751;
UPDATE `creature_template` SET `ScriptName` = 'npc_dread_waster_nagging_dreadling' WHERE entry = 65996;
UPDATE `creature_template` SET `ScriptName` = 'npc_tushui_monk' WHERE entry = 55019;
UPDATE `creature_template` SET `ScriptName` = 'npc_tushui_monk' WHERE entry = 59649;
UPDATE `creature_template` SET `ScriptName` = 'npc_tushui_monk' WHERE entry = 65051;
UPDATE `creature_template` SET `ScriptName` = 'npc_tushui_monk' WHERE entry = 65468;
UPDATE `creature_template` SET `ScriptName` = 'npc_tushui_monk' WHERE entry = 65550;
UPDATE `creature_template` SET `ScriptName` = 'boss_jaomin_ro' WHERE entry = 57750;
UPDATE `creature_template` SET `ScriptName` = 'boss_jaomin_ro' WHERE entry = 54611;
UPDATE `creature_template` SET `ScriptName` = 'npc_min_dimwind' WHERE entry = 54785;
UPDATE `creature_template` SET `ScriptName` = 'npc_min_dimwind' WHERE entry = 54855;
UPDATE `creature_template` SET `ScriptName` = 'npc_min_dimwind' WHERE entry = 56503;
UPDATE `creature_template` SET `ScriptName` = 'npc_aysa_lake_escort' WHERE entry = 56661;
UPDATE `creature_template` SET `ScriptName` = 'npc_mandori_escort' WHERE entry = 65082;
UPDATE `creature_template` SET `ScriptName` = 'npc_mandori_escort' WHERE entry = 65038;
UPDATE `creature_template` SET `ScriptName` = 'boss_vordraka' WHERE entry = 56009;
UPDATE `creature_template` SET `ScriptName` = 'boss_zhao_ren' WHERE entry IN (
55786,
55874,
64554);