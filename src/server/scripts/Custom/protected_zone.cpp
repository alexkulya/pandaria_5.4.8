 enum ForbiddenAreas
 {
	// AREA_TIMELESS_ISLE			= 6757,	// Timeless Isle
	// AREA_ISLE_OF_GIANT			= 6661, // IsleofGiants
	// AREA_ISLE_OF_THUNDER		= 6507  // IsleofThunder
 };
     
 class protected_zone : public PlayerScript
 {
	 
 public:
     protected_zone() : PlayerScript("protected_zone") {}
     
     void OnUpdateZone(Player* player, uint32 newZone, uint32 newArea)
     {
		 switch (newZone)
		 {
			// case AREA_TIMELESS_ISLE:
			// case AREA_ISLE_OF_GIANT:
			// case AREA_ISLE_OF_THUNDER:
				// if (player->GetSession()->GetSecurity() >= 1)
					// return;
				// player->TeleportTo(0, 278.867340f, 348.756195f, 141.279770f, 4.510715f); // teleport to dalaran crater
				// break;
		 }
     }
 };
     
 void AddSC_protected_zone()
 {
     new protected_zone();
 }