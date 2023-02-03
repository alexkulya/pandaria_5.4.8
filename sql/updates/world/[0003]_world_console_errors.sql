UPDATE `creature_template` SET `unit_class` = 1 WHERE `entry` = 68045;
UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35 WHERE `entry` IN (180130, 180101, 186922, 181473, 181209, 182011, 180302, 180425, 180002, 181465,
                                                                                    182012, 180004, 180208, 181190, 187095, 180025, 180001, 180015, 181256, 181254,
                                                                                    180000, 180411, 182008, 181179, 181214, 181024, 181470, 180429, 182215, 181274,
                                                                                    181474, 181325, 181466, 181225, 181241, 181189, 181137, 181149, 180808, 181276,
                                                                                    181340, 182028, 182044, 181151, 182148, 181191, 181207, 180306, 182405, 180313,
                                                                                    180442, 180426, 187034, 182065, 181630, 182141, 182041, 186709, 181311, 181327,
                                                                                    182440, 180412, 181040, 181044, 181028, 181136, 181216, 181220, 181305, 182618,
                                                                                    181273, 182010, 181022, 181006, 181178, 181182, 181210, 187841, 181198, 187042,
                                                                                    181312, 180303, 181472, 181219, 187287, 181203, 180405, 180421, 180430, 180017,
                                                                                    180011, 181164, 180304, 185524, 187339, 185518, 181334, 181218, 180220, 180423,
                                                                                    180427, 181163, 182394, 180310, 180301, 182361, 182331, 182490, 181140, 181181,
                                                                                    181217, 181245, 181468, 188138, 181437, 180022, 181014, 181038, 180404, 180420,
                                                                                    180444, 180409, 182014, 181322, 187389, 182038, 187840, 181172, 181188, 181184,
                                                                                    181002, 180416, 180432, 188757, 185525, 182040, 182400, 181016, 185433, 181148,
                                                                                    181212, 180407, 188134, 181221, 180005, 180009, 182139, 181215, 181471, 182495,
                                                                                    185711, 180012, 180008, 180016, 180024, 181150, 180021, 188006, 181187, 180439,
                                                                                    180434, 182001, 184817, 181001, 181008, 182045, 180419, 181467, 181242, 181004,
                                                                                    180431, 187805, 181147, 181211, 180438, 181253, 181206, 181032, 181272, 181252,
                                                                                    182033, 181519, 186706, 180006, 180018, 182406, 185483, 180003, 180007, 180010,
                                                                                    180014, 180019, 180023, 180102, 180103, 180107, 180109, 180799, 180854, 180305,
                                                                                    180307, 180308, 180309, 180311, 180312, 180401, 180402, 180403, 180406, 180408,
                                                                                    180415, 180417, 180424, 180428, 180433, 180435, 180437, 180440, 180441, 180443,
                                                                                    180445, 180446, 181010, 181012, 181020, 181026, 181030, 181034, 181036, 181138,
                                                                                    181146, 181170, 181171, 181173, 181174, 181180, 181183, 181185, 181186, 181192,
                                                                                    181201, 181204, 181205, 181208, 181213, 181226, 181249, 181251, 181255, 181302,
                                                                                    181303, 181304, 181307, 181319, 181320, 181321, 181323, 181324, 181326, 181435,
                                                                                    181439, 181464, 181469, 181554, 181631, 182015, 182016, 182017, 182036, 182047,
                                                                                    182066, 182085, 182130, 182210, 182267, 182357, 182493, 183377, 185430, 185519,
                                                                                    185520, 185521, 185523, 185537, 186197, 186083, 187842, 188507, 188661, 187785,
                                                                                    181202, 182067, 180013, 180020);
/* 32930, 37921 */
UPDATE `creature_template` SET `exp` = 0 WHERE `entry` IN (66361, 61793, 63067, 64593, 65066, 66364, 66443, 66482, 65559, 64505, 66489, 66493, 66453, 66416,
                                                           66497, 66135, 65744, 66487, 66455, 66414, 66486, 57670, 66490, 65742, 56134, 66494, 63014, 65008,
                                                           65051, 59652, 63596, 57638, 64876, 63479, 62159, 62098, 66488, 67185, 61126, 66439, 57669, 66496,
                                                           66445, 66485, 66126, 65651, 66495, 66481, 65558, 66454, 67186, 66966, 66444, 56434, 56784, 57692,
                                                           60741, 61127, 61463, 61528, 66492, 61757, 61792, 61796, 66438, 63061, 63070, 63073, 63075, 63077,
                                                           63080, 63083, 63086, 63310, 63478, 63626, 64330, 64506, 64543, 64875, 65048, 65648, 66136, 66363, 66417);

UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (55267, 55290, 55368, 55378, 55381, 55480, 55667, 55693, 55770, 55964,
                                                                      56133, 56180, 56336, 56340, 56477, 56478, 56782, 58014, 58015, 58017,
                                                                      58360, 58376, 58410, 58547, 59138, 59296, 59392, 59395, 59397, 59401,
                                                                      59846, 59899, 59921, 61245, 62261, 64244, 64249);

UPDATE creature_template SET `ScriptName` = "npc_brawlers_guild_boss_bazzelflange" WHERE `entry` = 67260;
UPDATE creature_template SET `ScriptName` = "npc_brawlers_guild_brawlgar_arena_grunt" WHERE `entry` = 67267;
UPDATE creature_template SET `ScriptName` = "npc_brawlers_guild_brawlgar_arena_grunt" WHERE `entry` = 68408;
UPDATE creature_template SET `ScriptName` = "npc_brawlers_shock_field" WHERE `entry` = 67459;
UPDATE creature_template SET `ScriptName` = "npc_brawlers_guild_good_luck_goblin" WHERE `entry` = 68306;
UPDATE creature_template SET `ScriptName` = "npc_brawlers_guild_mecha_bruce" WHERE `entry` = 71081;
UPDATE creature_template SET `ScriptName` = "npc_brawlers_guild_blingtron_3000" WHERE `entry` = 70740;
UPDATE creature_template SET `ScriptName` = "npc_brawlers_guild_gnomish_tesla_coil" WHERE `entry` = 70743;
UPDATE creature_template SET `ScriptName` = "npc_brawlers_guild_card_traider" WHERE `entry` = 70751;
UPDATE creature_template SET `ScriptName` = "npc_brawlers_guild_blingtron_2000" WHERE `entry` = 70802;
UPDATE creature_template SET `ScriptName` = "npc_brawlers_guild_grandpa_grumplefloot" WHERE `entry` = 70678;

UPDATE creature_template SET `AIName` = "", `ScriptName` = "npc_hyjal_aronus_ride" WHERE `entry` = 39128;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39128 AND `source_type` = 0;
UPDATE creature_template SET `ScriptName` = "npc_hyjal_aronus" WHERE `entry` = 39140;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (100115, 100116, 100117, 100118, 100119, 100125);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(100115, "spell_afd_royale_in_map"),
(100116, "spell_afd_royale_leaving_game"),
(100117, "spell_afd_royale_drop"),
(100118, "spell_afd_royale_out_of_ring_damage_aura"),
(100119, "spell_afd_royale_buff_trigger"),
(100125, "spell_afd_royale_portal_trigger");

DELETE FROM `creature_template` WHERE `entry` IN (170000, 170001);
INSERT INTO `creature_template` (`entry`, `difficulty_entry_1`, `difficulty_entry_2`, `difficulty_entry_3`, `difficulty_entry_4`, `difficulty_entry_5`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `subname`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `exp`, `exp_unk`, `faction_A`, `faction_H`, `npcflag`, `npcflag2`, `speed_walk`, `speed_run`, `scale`, `rank`, `mindmg`, `maxdmg`, `dmgschool`, `attackpower`, `dmg_multiplier`, `baseattacktime`, `rangeattacktime`, `unit_class`, `unit_flags`, `unit_flags2`, `dynamicflags`, `family`, `trainer_type`, `trainer_class`, `trainer_race`, `minrangedmg`, `maxrangedmg`, `rangedattackpower`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `resistance1`, `resistance2`, `resistance3`, `resistance4`, `resistance5`, `resistance6`, `spell1`, `spell2`, `spell3`, `spell4`, `spell5`, `spell6`, `spell7`, `spell8`, `PetSpellDataId`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `InhabitType`, `HoverHeight`, `Health_mod`, `Mana_mod`, `Mana_mod_extra`, `Armor_mod`, `RacialLeader`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `movementId`, `RegenHealth`, `VignetteID`, `TrackingQuestID`, `mechanic_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES
(170000, 0, 0, 0, 0, 0, 0, 0, 19646, 0, 0, 0, "Royal Controller", NULL, NULL, 0, 80, 80, 2, 0, 35, 35, 1, 0, 1, 1.14286, 1, 0, 0, 0, 0, 0, 1, 2000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 138936390, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "", 0, 3, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "npc_afd_royale_controller", 18414),
(170001, 0, 0, 0, 0, 0, 0, 0, 19646, 0, 0, 0, "Royal Ring", NULL, NULL, 0, 80, 80, 2, 0, 35, 35, 1, 0, 1, 1.14286, 1, 0, 0, 0, 0, 0, 1, 2000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 138936390, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,"", 0, 3, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "npc_afd_royale_ring", 18414);

UPDATE `creature_template` SET `AIName` = "", `ScriptName` = "npc_ring_champions" WHERE `entry` IN (33738, 33746, 33747, 33743, 33740, 33748, 33744, 33745, 33749, 33739);

DELETE FROM `creature_questender` WHERE `id` = 190000;
DELETE FROM `creature_queststarter` WHERE `id` = 190000;
DELETE FROM `quest_template` WHERE `Id` = 39999;

UPDATE `creature` SET `movement_type` = 0 WHERE `guid` = 581232;
UPDATE `creature` SET `movement_type` = 0 WHERE `guid` = 581224;
UPDATE `creature` SET `movement_type` = 0 WHERE `guid` = 581235;

UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 69661;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 69774;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 59163;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 39140;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 69327;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 45005;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 72588;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 69660;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 56682;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 62682;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 69779;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 69087;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 69655;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 69662;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 69771;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 69777;
UPDATE `creature_template` SET `npcflag` = 0 WHERE `entry` = 70217;

UPDATE `quest_template` SET `RequiredSkillId` = 185 WHERE `id` = 33026;
UPDATE `quest_template` SET `RequiredSkillId` = 185 WHERE `id` = 33021;
UPDATE `quest_template` SET `RequiredSkillId` = 185 WHERE `id` = 33020;
UPDATE `quest_template` SET `RequiredSkillId` = 185 WHERE `id` = 33022;
UPDATE `quest_template` SET `RequiredSkillId` = 185 WHERE `id` = 33024;
UPDATE `quest_template` SET `RequiredSkillId` = 185 WHERE `id` = 33027;
UPDATE `quest_template` SET `RequiredSkillId` = 185 WHERE `id` = 33107;
UPDATE `quest_template` SET `RequiredSkillId` = 185 WHERE `id` = 33139;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 35417;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 35436;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 35433;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 36357;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 36358;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 35429;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 35433;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 35431;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 35431;

UPDATE `creature_template` SET `lootid` = 3869 WHERE `entry` = 3869;
UPDATE `creature_template` SET `lootid` = 35386 WHERE `entry` = 35386;
UPDATE `creature_template` SET `lootid` = 43687 WHERE `entry` = 43687;
UPDATE `creature_template` SET `lootid` = 58555 WHERE `entry` = 58555;
UPDATE `creature_template` SET `lootid` = 58569 WHERE `entry` = 58569;
UPDATE `creature_template` SET `lootid` = 58590 WHERE `entry` = 58590;
UPDATE `creature_template` SET `lootid` = 58605 WHERE `entry` = 58605;
UPDATE `creature_template` SET `lootid` = 58633 WHERE `entry` = 58633;
UPDATE `creature_template` SET `lootid` = 59746 WHERE `entry` = 59746;
UPDATE `creature_template` SET `lootid` = 65617 WHERE `entry` = 65617;
UPDATE `creature_template` SET `lootid` = 67304 WHERE `entry` = 67304;
UPDATE `creature_template` SET `lootid` = 68313 WHERE `entry` = 68313;
UPDATE `creature_template` SET `lootid` = 69570 WHERE `entry` = 69570;
UPDATE `creature_template` SET `lootid` = 70126 WHERE `entry` = 70126;
UPDATE `creature_template` SET `lootid` = 70246 WHERE `entry` = 70246;
UPDATE `creature_template` SET `lootid` = 70341 WHERE `entry` = 70341;
UPDATE `creature_template` SET `lootid` = 70448 WHERE `entry` = 70448;
UPDATE `creature_template` SET `lootid` = 71770 WHERE `entry` = 71770;
UPDATE `creature_template` SET `lootid` = 71771 WHERE `entry` = 71771;
UPDATE `creature_template` SET `lootid` = 71772 WHERE `entry` = 71772;
UPDATE `creature_template` SET `lootid` = 71773 WHERE `entry` = 71773;
UPDATE `creature_template` SET `lootid` = 72033 WHERE `entry` = 72033;
UPDATE `creature_template` SET `lootid` = 72412 WHERE `entry` = 72412;
UPDATE `creature_template` SET `lootid` = 72744 WHERE `entry` = 72744;
UPDATE `creature_template` SET `lootid` = 72791 WHERE `entry` = 72791;
UPDATE `creature_template` SET `lootid` = 72908 WHERE `entry` = 72908;
UPDATE `creature_template` SET `lootid` = 72929 WHERE `entry` = 72929;
UPDATE `creature_template` SET `lootid` = 72954 WHERE `entry` = 72954;
UPDATE `creature_template` SET `lootid` = 73012 WHERE `entry` = 73012;
UPDATE `creature_template` SET `lootid` = 73188 WHERE `entry` = 73188;
UPDATE `creature_template` SET `lootid` = 73414 WHERE `entry` = 73414;
UPDATE `creature_template` SET `lootid` = 73452 WHERE `entry` = 73452;

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 100;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 102;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 140;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 166;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 176;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 177;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 221;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 222;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 223;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 224;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 225;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 416;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 417;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 418;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 420;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 525;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 526;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 527;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 528;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 529;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 530;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 531;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 532;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 534;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 538;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 539;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 540;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 541;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 542;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 544;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 547;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 551;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 552;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 594;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 595;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 596;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 598;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 599;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 601;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 602;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 603;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 604;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 605;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 606;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 607;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 1826;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 3680;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 4439;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 4501;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 4502;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5621;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5622;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5623;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5624;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5625;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5626;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5627;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5628;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5629;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5630;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5631;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5746;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5820;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 5887;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 6432;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 6440;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 6441;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 6445;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 6758;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 7365;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 7415;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 7416;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 7418;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 7419;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 7608;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 7609;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 7860;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 9120;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 9120;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 9718;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 9721;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10289;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10289;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10303;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10310;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10314;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10314;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10408;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10417;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10438;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10444;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10453;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10454;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10455;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10718;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10784;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10785;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10786;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10787;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10788;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10789;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10790;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10791;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10792;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10793;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10794;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10795;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10796;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10797;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10798;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10799;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10802;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10803;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10804;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10805;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10806;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10807;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10808;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10809;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10810;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10811;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10812;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10813;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10814;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10815;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10816;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10817;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10818;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10819;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10878;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 10879;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 11418;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 11419;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 11498;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 11500;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 11559;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 11560;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 11561;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 11882;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 11959;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12064;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12065;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12199;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12200;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12201;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12202;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12204;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12205;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12206;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12207;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12209;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12210;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12211;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12212;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12213;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12214;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12215;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12216;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12217;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12218;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12219;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12220;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12221;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12222;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12223;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12224;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12225;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12226;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12227;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12238;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12302;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12303;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12304;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12305;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12306;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12307;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12308;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12309;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12310;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12311;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12312;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12313;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12314;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12315;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12316;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12317;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12318;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12319;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12321;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12322;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12323;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12324;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12439;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12519;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12547;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12743;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12751;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 12999;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13000;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13001;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13002;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13003;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13004;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13005;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13006;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13007;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13095;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13112;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13139;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13140;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13141;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13142;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13143;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13144;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13145;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13146;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13147;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13148;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13149;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13150;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13151;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13152;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13153;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13154;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13155;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13156;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13157;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13158;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13159;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13160;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13161;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13162;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13188;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13194;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13199;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13205;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13207;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13208;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13209;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13210;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13211;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13212;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13213;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13214;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13215;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13216;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13217;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13218;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13219;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13220;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13221;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13222;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13223;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13224;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13225;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13226;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13227;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13228;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13229;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13230;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 13328;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14280;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14385;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14398;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14400;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14407;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14408;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14409;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14410;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14411;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14412;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14414;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14773;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14774;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14775;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14776;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14777;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14778;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14779;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14780;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14781;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14782;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14783;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14784;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14785;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14786;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14787;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14788;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14789;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14790;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14791;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 14792;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15443;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15444;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15445;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15656;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15657;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15658;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15661;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15662;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15663;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15664;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15665;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15666;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15668;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15672;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15956;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 15957;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 16023;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 16024;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 17847;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 17848;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 18333;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 18453;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 3805;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 3806;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 3807;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 3808;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 3809;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 3810;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 3811;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 3812;
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` = 3813;

UPDATE `creature_template` SET `npcflag` = 2 WHERE `entry` IN (70751, 70752, 73335);
