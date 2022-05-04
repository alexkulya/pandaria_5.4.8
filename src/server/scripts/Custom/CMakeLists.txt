# This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

file(GLOB_RECURSE scripts_Custom Custom/*.cpp Custom/*.h)
source_group(Custom FILES ${scripts_Custom})

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
  Custom/arena_crystal.cpp
  Custom/challenge_commandscript.cpp
  Custom/reset_onduel_end.cpp
  Custom/utility_commandscript.cpp
  Custom/security_scripts.cpp
  Custom/arena_spectator.cpp
  Custom/boss_maximus.cpp
  Custom/donation_npc.cpp
  Custom/npc_arena_ladder.cpp
  Custom/npc_hks_title_rewarder.cpp
  Custom/professions_npc.cpp
  Custom/season_end_title_rewarder.cpp
  Custom/tele_gossip_codebox.cpp
  Custom/teleporter_npc.cpp
  Custom/transmogriefer.cpp
  Custom/viptransmog.cpp
  Custom/weptransmog.cpp
  Custom/beastmaster_npc.cpp
  Custom/enchanter_npc.cpp
  Custom/npc_arena1v1.cpp
  Custom/npc_arena1v1.h
  Custom/exchangeNPC.cpp
  Custom/mall_guide_alliance.cpp
  Custom/mall_guide_horde.cpp
  Custom/arena_script.cpp
  Custom/Item_Requester_NPC.cpp
  Custom/TransmogEngine.cpp
  Custom/TransmogEngine.h
  Custom/TransmogHandler.cpp
  Custom/TransmogMgr.cpp
  Custom/TransmogMgr.h
  Custom/cooldowns_crystal.cpp
  Custom/TemplateNPC.cpp
  Custom/TemplateNPC.h
  Custom/npc_solo3v3.cpp
  Custom/npc_solo3v3.h
)

message("  -> Prepared: Custom")
