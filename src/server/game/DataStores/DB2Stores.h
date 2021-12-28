/*
 * Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITY_DB2STORES_H
#define TRINITY_DB2STORES_H

#include "DB2Store.h"
#include "DB2Structure.h"
#include <string>

extern DB2Storage<BattlePetAbilityEntry> sBattlePetAbilityStore;
extern DB2Storage<BattlePetAbilityStateEntry> sBattlePetAbilityStateStore;
extern DB2Storage<BattlePetAbilityEffectEntry> sBattlePetAbilityEffectStore;
extern DB2Storage<BattlePetAbilityTurnEntry> sBattlePetAbilityTurnStore;
extern DB2Storage<BattlePetBreedQualityEntry> sBattlePetBreedQualityStore;
extern DB2Storage<BattlePetBreedStateEntry> sBattlePetBreedStateStore;
extern DB2Storage<BattlePetSpeciesEntry> sBattlePetSpeciesStore;
extern DB2Storage<BattlePetSpeciesStateEntry> sBattlePetSpeciesStateStore;
extern DB2Storage<BattlePetSpeciesXAbilityEntry> sBattlePetSpeciesXAbilityStore;
extern DB2Storage<BattlePetStateEntry> sBattlePetStateStore;
extern DB2Storage<ItemToBattlePetEntry> sItemToBattlePetStore;

extern BattlePetBreedSet sBattlePetBreedSet;
extern BattlePetItemXSpeciesStore sBattlePetItemXSpeciesStore;

extern DB2Storage<BroadcastTextEntry> sBroadcastTextStore;
extern DB2Storage<ItemEntry> sItemStore;
extern DB2Storage<ItemCurrencyCostEntry> sItemCurrencyCostStore;
extern DB2Storage<ItemExtendedCostEntry> sItemExtendedCostStore;
extern DB2Storage<ItemSparseEntry> sItemSparseStore;
extern DB2Storage<ItemUpgradeEntry> sItemUpgradeStore;
extern DB2Storage<ItemToMountSpellEntry> sItemItemToMountSpellStore;
extern DB2Storage<KeyChainEntry> sKeyChainStore;
extern DB2Storage <MapChallengeModeEntry> sMapChallengeModeStore;
extern DB2Storage <RulesetItemUpgradeEntry> sRulesetItemUpgradeStore;
extern DB2Storage<SceneScriptEntry> sSceneScriptStore;
extern DB2Storage<SceneScriptPackageEntry> sSceneScriptPackageStore;
extern DB2Storage<SpellReagentsEntry> sSpellReagentsStore;
extern DB2Storage <VignetteEntry> sVignetteStore;

void LoadDB2Stores(std::string const& dataPath, uint32& availableDb2Locales);

float BattlePetSpeciesMainStat(uint16 stateId, uint16 speciesId);
float BattlePetBreedMainStatModifier(uint16 stateId, uint8 speciesId);
bool HasBattlePetSpeciesFlag(uint16 species, uint16 flag);

struct BattlePetAbilityPair
{
    BattlePetSpeciesXAbilityEntry const* FirstTier = nullptr;
    BattlePetSpeciesXAbilityEntry const* SecondTier = nullptr;
};

typedef std::array<BattlePetAbilityPair, 3> BattlePetAbilities;

namespace db2
{
    void LoadBattlePetCorrections();
    uint32 GetBattlePetSummonSpell(uint32 speciesId);
    uint32 GetBattlePetSpeciesFromSpell(uint32 spellId);
    uint32 GetBattlePetItem(uint32 species);
    BattlePetAbilities const* GetAbilitiesForPetSpecies(uint32 speciesId);
}

DB2StorageBase const* GetDB2Storage(uint32 type);

bool GetQuestRewardItemCountFromPackage(uint32 itemid, uint32 package, uint32& count);
uint32 GetUpgradeId(uint32 itemId);
bool IsMountCanBeAllowedForPlayer(uint32 spellId, uint32 raceMask);

#endif
