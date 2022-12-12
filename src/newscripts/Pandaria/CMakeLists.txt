# Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  Pandaria/boss_sha_of_anger.cpp
  Pandaria/boss_galion.cpp
  Pandaria/boss_oondasta.cpp
  Pandaria/boss_nalak.cpp

  Pandaria/MogushanPalace/instance_mogu_shan_palace.cpp
  Pandaria/MogushanPalace/mogu_shan_palace.cpp
  Pandaria/MogushanPalace/boss_trial_of_the_king.cpp
  Pandaria/MogushanPalace/boss_gekkan.cpp
  Pandaria/MogushanPalace/boss_xin_the_weaponmaster.cpp

  Pandaria/TempleJadeSerpent/instance_temple_of_jade_serpent.cpp
  Pandaria/TempleJadeSerpent/boss_wise_mari.cpp
  Pandaria/TempleJadeSerpent/boss_lorewalker_stonestep.cpp
  Pandaria/TempleJadeSerpent/boss_liu_flameheart.cpp
  Pandaria/TempleJadeSerpent/boss_sha_of_doubt.cpp

  Pandaria/StormstoutBrewery/instance_stormstout_brewery.cpp
  Pandaria/StormstoutBrewery/stormstout_brewery.cpp
  Pandaria/StormstoutBrewery/stormstout_brewery.h
  Pandaria/StormstoutBrewery/boss_ook_ook.cpp
  Pandaria/StormstoutBrewery/boss_hoptallus.cpp
  Pandaria/StormstoutBrewery/boss_yan_zhu.cpp

  Pandaria/GateSettingSun/instance_gate_setting_sun.cpp
  Pandaria/GateSettingSun/gate_setting_sun.cpp
  Pandaria/GateSettingSun/gate_setting_sun.h
  Pandaria/GateSettingSun/boss_saboteur_kiptilak.cpp
  Pandaria/GateSettingSun/boss_striker_gadok.cpp
  Pandaria/GateSettingSun/boss_commander_rimok.cpp
  Pandaria/GateSettingSun/boss_raigonn.cpp

  Pandaria/ShadopanMonastery/instance_shadopan_monastery.cpp
  Pandaria/ShadopanMonastery/shadopan_monastery.cpp
  Pandaria/ShadopanMonastery/shadopan_monastery.h
  Pandaria/ShadopanMonastery/boss_gu_cloudstrike.cpp
  Pandaria/ShadopanMonastery/boss_master_snowdrift.cpp
  Pandaria/ShadopanMonastery/boss_sha_of_violence.cpp
  Pandaria/ShadopanMonastery/boss_taran_zhu.cpp
  
  Pandaria/SiegeNiuzaoTemple/instance_siege_of_the_niuzoa_temple.cpp
  Pandaria/SiegeNiuzaoTemple/siege_of_the_niuzoa_temple.cpp
  Pandaria/SiegeNiuzaoTemple/siege_of_the_niuzoa_temple.h
  Pandaria/SiegeNiuzaoTemple/boss_jinbak.cpp
  Pandaria/SiegeNiuzaoTemple/boss_commander_vojak.cpp
  Pandaria/SiegeNiuzaoTemple/boss_general_pavalak.cpp
  Pandaria/SiegeNiuzaoTemple/boss_wing_leader_neronok.cpp
  

  Pandaria/MogushanVault/instance_mogu_shan_vault.cpp
  Pandaria/MogushanVault/mogu_shan_vault.cpp
  Pandaria/MogushanVault/mogu_shan_vault.h
  Pandaria/MogushanVault/boss_stone_guard.cpp
  Pandaria/MogushanVault/boss_feng.cpp
  Pandaria/MogushanVault/boss_garajal.cpp
  Pandaria/MogushanVault/boss_spirit_kings.cpp
  Pandaria/MogushanVault/boss_elegon.cpp
  Pandaria/MogushanVault/boss_will_of_emperor.cpp
  
  Pandaria/HeartFear/instance_heart_of_fear.cpp
  Pandaria/HeartFear/heart_of_fear.h
  Pandaria/HeartFear/boss_vizier_zorlok.cpp
  Pandaria/HeartFear/boss_lord_tayak.cpp
  Pandaria/HeartFear/boss_garalon.cpp
  Pandaria/HeartFear/boss_lord_meljarak.cpp
  Pandaria/HeartFear/boss_unsok.cpp
  Pandaria/HeartFear/boss_empress_shekzeer.cpp

  Pandaria/TerraceEndlessSpring/instance_terrace_of_endless_spring.cpp
  Pandaria/TerraceEndlessSpring/terrace_of_endless_spring.h
  Pandaria/TerraceEndlessSpring/boss_protectors.cpp
  Pandaria/TerraceEndlessSpring/boss_tsulong.cpp
  Pandaria/TerraceEndlessSpring/boss_lei_shi.cpp
  Pandaria/TerraceEndlessSpring/boss_sha_of_fear.cpp

  Pandaria/ThroneOfThunder/instance_throne_of_thunder.cpp
  Pandaria/ThroneOfThunder/throne_of_thunder.h
  Pandaria/ThroneOfThunder/boss_jinrokh.cpp
  Pandaria/ThroneOfThunder/boss_horridon.cpp
  Pandaria/ThroneOfThunder/boss_council_of_elders.cpp
  Pandaria/ThroneOfThunder/boss_tortos.cpp
  Pandaria/ThroneOfThunder/boss_megaera.cpp
  Pandaria/ThroneOfThunder/boss_jikun.cpp
  Pandaria/ThroneOfThunder/boss_durumu.cpp
  Pandaria/ThroneOfThunder/boss_primordius.cpp
  Pandaria/ThroneOfThunder/boss_dark_animus.cpp
  Pandaria/ThroneOfThunder/boss_iron_qon.cpp
  Pandaria/ThroneOfThunder/boss_twin_consorts.cpp
  Pandaria/ThroneOfThunder/boss_lei_shen.cpp
  Pandaria/ThroneOfThunder/boss_ra_den.cpp

  Pandaria/SiegeofOrgrimmar/instance_siege_of_orgrimmar.cpp
  Pandaria/SiegeofOrgrimmar/siege_of_orgrimmar.cpp
  Pandaria/SiegeofOrgrimmar/siege_of_orgrimmar.h
  Pandaria/SiegeofOrgrimmar/boss_immerseus.cpp
  Pandaria/SiegeofOrgrimmar/boss_fallen_protectors.cpp
  Pandaria/SiegeofOrgrimmar/boss_norushen.cpp
  Pandaria/SiegeofOrgrimmar/boss_sha_of_pride.cpp
  Pandaria/SiegeofOrgrimmar/boss_galakras.cpp
  Pandaria/SiegeofOrgrimmar/boss_iron_juggernaut.cpp
  Pandaria/SiegeofOrgrimmar/boss_korkron_dark_shaman.cpp
  Pandaria/SiegeofOrgrimmar/boss_general_nazgrim.cpp
  Pandaria/SiegeofOrgrimmar/boss_malkorok.cpp
  Pandaria/SiegeofOrgrimmar/boss_spoils_of_pandaria.cpp
  Pandaria/SiegeofOrgrimmar/boss_thok_the_bloodthirsty.cpp
  Pandaria/SiegeofOrgrimmar/boss_siegecrafter_blackfuse.cpp
  Pandaria/SiegeofOrgrimmar/boss_paragons_of_the_klaxxi.cpp
  Pandaria/SiegeofOrgrimmar/boss_garrosh_hellscream.cpp
  
  Pandaria/wandering_island.cpp
  Pandaria/timeless_isle.cpp

  Pandaria/valley_of_the_four_winds.cpp
  Pandaria/krasarang_wilds.cpp
  Pandaria/kun_lai_summit.cpp
)

message("  -> Prepared: Pandaria")
