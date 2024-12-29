ALTER TABLE `guild_member`
  MODIFY COLUMN `first_prof_recipes` text CHARACTER SET ascii COLLATE ascii_general_ci,
  MODIFY COLUMN `second_prof_recipes` text CHARACTER SET ascii COLLATE ascii_general_ci;