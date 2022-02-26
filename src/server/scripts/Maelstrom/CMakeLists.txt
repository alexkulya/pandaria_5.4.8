# This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
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
  Maelstrom/zone_kezan.cpp
  Maelstrom/zone_deepholm.cpp
  Maelstrom/TheStonecore/boss_corborus.cpp
  Maelstrom/TheStonecore/boss_high_priestess_azil.cpp
  Maelstrom/TheStonecore/boss_ozruk.cpp
  Maelstrom/TheStonecore/boss_slabhide.cpp
  Maelstrom/TheStonecore/instance_the_stonecore.cpp
  Maelstrom/TheStonecore/the_stonecore.cpp
  Maelstrom/TheStonecore/the_stonecore.h
)

message("  -> Prepared: The Maelstrom")
