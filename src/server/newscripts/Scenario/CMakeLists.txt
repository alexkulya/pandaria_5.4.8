# Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


file(GLOB_RECURSE sources_ArenaofAnnihilation Scenario/ArenaofAnnihilation/*.cpp Scenario/ArenaofAnnihilation/*.h)
source_group(ArenaofAnnihilation FILES ${sources_ArenaofAnnihilation})

file(GLOB_RECURSE sources_ABrewingStorm Scenario/ABrewingStorm/*.cpp Scenario/ABrewingStorm/*.h)
source_group(ABrewingStorm FILES ${sources_ABrewingStorm})

file(GLOB_RECURSE sources_ALittlePatience Scenario/ALittlePatience/*.cpp Scenario/ALittlePatience/*.h)
source_group(ALittlePatience FILES ${sources_ALittlePatience})

file(GLOB_RECURSE sources_AssoultOnZanvess Scenario/AssoultOnZanvess/*.cpp Scenario/AssoultOnZanvess/*.h)
source_group(AssoultOnZanvess FILES ${sources_AssoultOnZanvess})

file(GLOB_RECURSE sources_BattleOnTheHighSeas Scenario/BattleOnTheHighSeas/*.cpp Scenario/BattleOnTheHighSeas/*.h)
source_group(BattleOnTheHighSeas FILES ${sources_BattleOnTheHighSeas})

file(GLOB_RECURSE sources_BloodInTheSnow Scenario/BloodInTheSnow/*.cpp Scenario/BloodInTheSnow/*.h)
source_group(BloodInTheSnow FILES ${sources_BloodInTheSnow})

file(GLOB_RECURSE sources_BrewmoonFestival Scenario/BrewmoonFestival/*.cpp Scenario/BrewmoonFestival/*.h)
source_group(BrewmoonFestival FILES ${sources_BrewmoonFestival})

file(GLOB_RECURSE sources_CelestialTournament Scenario/CelestialTournament/*.cpp Scenario/CelestialTournament/*.h)
source_group(CelestialTournament FILES ${sources_CelestialTournament})

file(GLOB_RECURSE sources_CryptOfForgottenKings Scenario/CryptOfForgottenKings/*.cpp Scenario/CryptOfForgottenKings/*.h)
source_group(CryptOfForgottenKings FILES ${sources_CryptOfForgottenKings})

file(GLOB_RECURSE sources_DaggerInTheDark Scenario/DaggerInTheDark/*.cpp Scenario/DaggerInTheDark/*.h)
source_group(DaggerInTheDark FILES ${sources_DaggerInTheDark})

file(GLOB_RECURSE sources_DarkHeartOfPandaria Scenario/DarkHeartOfPandaria/*.cpp Scenario/DarkHeartOfPandaria/*.h)
source_group(DarkHeartOfPandaria FILES ${sources_DarkHeartOfPandaria})

file(GLOB_RECURSE sources_DominationPoint Scenario/DominationPoint/*.cpp Scenario/DominationPoint/*.h)
source_group(DominationPoint FILES ${sources_DominationPoint})

file(GLOB_RECURSE sources_FallofShanBu Scenario/FallofShanBu/*.cpp Scenario/FallofShanBu/*.h)
source_group(FallofShanBu FILES ${sources_FallofShanBu})

file(GLOB_RECURSE sources_GreenstoneVillage Scenario/GreenstoneVillage/*.cpp Scenario/GreenstoneVillage/*.h)
source_group(GreenstoneVillage FILES ${sources_GreenstoneVillage})

file(GLOB_RECURSE sources_LionsLanding Scenario/LionsLanding/*.cpp Scenario/LionsLanding/*.h)
source_group(LionsLanding FILES ${sources_LionsLanding})

file(GLOB_RECURSE sources_PursuingTheBlackHarvest Scenario/PursuingTheBlackHarvest/*.cpp Scenario/PursuingTheBlackHarvest/*.h)
source_group(PursuingTheBlackHarvest FILES ${sources_PursuingTheBlackHarvest})

file(GLOB_RECURSE sources_TheSecretsOfRagefire Scenario/TheSecretsOfRagefire/*.cpp Scenario/TheSecretsOfRagefire/*.h)
source_group(TheSecretsOfRagefire FILES ${sources_TheSecretsOfRagefire})

file(GLOB_RECURSE sources_ThunderForge Scenario/ThunderForge/*.cpp Scenario/ThunderForge/*.h)
source_group(ThunderForge FILES ${sources_ThunderForge})

file(GLOB_RECURSE sources_TrovesOfTheThunderKing Scenario/TrovesOfTheThunderKing/*.cpp Scenario/TrovesOfTheThunderKing/*.h)
source_group(TrovesOfTheThunderKing FILES ${sources_TrovesOfTheThunderKing})

file(GLOB_RECURSE sources_UngaIngoo Scenario/UngaIngoo/*.cpp Scenario/UngaIngoo/*.h)
source_group(UngaIngoo FILES ${sources_UngaIngoo})


set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  ${sources_ArenaofAnnihilation}
  ${sources_ABrewingStorm}
  ${sources_ALittlePatience}
  ${sources_AssoultOnZanvess}
  ${sources_BattleOnTheHighSeas}
  ${sources_BloodInTheSnow}
  ${sources_BrewmoonFestival}
  ${sources_CelestialTournament}
  ${sources_CryptOfForgottenKings}
  ${sources_DaggerInTheDark}
  ${sources_DarkHeartOfPandaria}
  ${sources_DominationPoint}
  ${sources_FallofShanBu}
  ${sources_GreenstoneVillage}
  ${sources_LionsLanding}
  ${sources_PursuingTheBlackHarvest}
  ${sources_TheSecretsOfRagefire}
  ${sources_ThunderForge}
  ${sources_TrovesOfTheThunderKing}
  ${sources_UngaIngoo}
)


message("  -> Prepared: Scenario")
