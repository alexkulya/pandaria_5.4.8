/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
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

#ifndef DEF_TRANSMOGRIFICATION_H
#define DEF_TRANSMOGRIFICATION_H

#include <vector>
#include "Player.h"
#include "Config.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "GameEventMgr.h"
#include <unordered_map>

#define PRESETS // comment this line to disable preset feature totally
#define MAX_OPTIONS 25 // do not alter

class Item;
class Player;
class WorldSession;
struct ItemTemplate;

enum TransmogTrinityStrings
{
    LANG_ERR_TRANSMOG_OK                              = 15008,
    LANG_ERR_TRANSMOG_INVALID_SLOT                    = 15009,
    LANG_ERR_TRANSMOG_INVALID_SRC_ENTRY               = 15010,
    LANG_ERR_TRANSMOG_MISSING_SRC_ITEM                = 15011,
    LANG_ERR_TRANSMOG_MISSING_DEST_ITEM               = 15012,
    LANG_ERR_TRANSMOG_INVALID_ITEMS                   = 15013,
    LANG_ERR_TRANSMOG_NOT_ENOUGH_MONEY                = 15014,
    LANG_ERR_TRANSMOG_NOT_ENOUGH_TOKENS               = 15015,
    LANG_ERR_UNTRANSMOG_OK                            = 15016,
    LANG_ERR_UNTRANSMOG_NO_TRANSMOGS                  = 15017,

#ifdef PRESETS
    LANG_PRESET_ERR_INVALID_NAME                      = 15018,
#endif

    LANG_TRANSMOGRIFICATION_SLOT_NAME_HEAD            = 15019,
    LANG_TRANSMOGRIFICATION_SLOT_NAME_SHOULDERS       = 15020,
    LANG_TRANSMOGRIFICATION_SLOT_NAME_BODY            = 15021,
    LANG_TRANSMOGRIFICATION_SLOT_NAME_CHEST           = 15022,
    LANG_TRANSMOGRIFICATION_SLOT_NAME_WAIST           = 15023,
    LANG_TRANSMOGRIFICATION_SLOT_NAME_LEGS            = 15024,
    LANG_TRANSMOGRIFICATION_SLOT_NAME_FEET            = 15025,
    LANG_TRANSMOGRIFICATION_SLOT_NAME_WRISTS          = 15026,
    LANG_TRANSMOGRIFICATION_SLOT_NAME_HANDS           = 15027,
    LANG_TRANSMOGRIFICATION_SLOT_NAME_BACK            = 15028,
    LANG_TRANSMOGRIFICATION_SLOT_NAME_MAINHAND        = 15029,
    LANG_TRANSMOGRIFICATION_SLOT_NAME_OFFHAND         = 15030,
    LANG_TRANSMOGRIFICATION_SLOT_NAME_RANGED          = 15031,
    LANG_TRANSMOGRIFICATION_SLOT_NAME_TABARD          = 15032
};

class Transmogrification
{
public:
    typedef std::unordered_map<uint64, uint64> transmogData;
    typedef std::unordered_map<uint64, transmogData> transmogMap;
    transmogMap entryMap; // entryMap[pGUID][iGUID] = entry
    transmogData dataMap; // dataMap[iGUID] = pGUID

#ifdef PRESETS
    bool EnableSetInfo;
    uint32 SetNpcText;

    typedef std::map<uint8, uint32> slotMap;
    typedef std::map<uint8, slotMap> presetData;
    typedef std::unordered_map<uint64, presetData> presetDataMap;
    presetDataMap presetById; // presetById[pGUID][presetID][slot] = entry
    typedef std::map<uint8, std::string> presetIdMap;
    typedef std::unordered_map<uint64, presetIdMap> presetNameMap;
    presetNameMap presetByName; // presetByName[pGUID][presetID] = presetName

    void PresetTransmog(Player* player, Item* itemTransmogrified, uint32 fakeEntry, uint8 slot);

    bool EnableSets;
    uint8 MaxSets;
    float SetCostModifier;
    int32 SetCopperCost;

    bool GetEnableSets() const;
    uint8 GetMaxSets() const;
    float GetSetCostModifier() const;
    int32 GetSetCopperCost() const;

    void LoadPlayerSets(uint64 pGUID);
    void UnloadPlayerSets(uint64 pGUID);
#endif

    bool EnableTransmogInfo;
    uint32 TransmogNpcText;

    // Use IsAllowed() and IsNotAllowed()
    // these are thread unsafe, but assumed to be static data so it should be safe
    std::set<uint32> Allowed;
    std::set<uint32> NotAllowed;

    float ScaledCostModifier;
    int32 CopperCost;

    bool RequireToken;
    uint32 TokenEntry;
    uint32 TokenAmount;

    bool AllowPoor;
    bool AllowCommon;
    bool AllowUncommon;
    bool AllowRare;
    bool AllowEpic;
    bool AllowLegendary;
    bool AllowArtifact;
    bool AllowHeirloom;

    bool AllowMixedArmorTypes;
    bool AllowMixedWeaponTypes;
    bool AllowFishingPoles;

    bool IgnoreReqRace;
    bool IgnoreReqClass;
    bool IgnoreReqSkill;
    bool IgnoreReqSpell;
    bool IgnoreReqLevel;
    bool IgnoreReqEvent;
    bool IgnoreReqStats;

    bool IsAllowed(uint32 entry) const;
    bool IsNotAllowed(uint32 entry) const;
    bool IsAllowedQuality(uint32 quality) const;
    bool IsRangedWeapon(uint32 Class, uint32 SubClass) const;

    void LoadConfig(bool reload); // thread unsafe

    std::string GetItemIcon(uint32 entry, uint32 width, uint32 height, int x, int y) const;
    std::string GetSlotIcon(uint8 slot, uint32 width, uint32 height, int x, int y) const;
    const char * GetSlotName(uint8 slot, WorldSession* session) const;
    std::string GetItemLink(Item* item, WorldSession* session) const;
    std::string GetItemLink(uint32 entry, WorldSession* session) const;
    uint32 GetFakeEntry(uint64 itemGUID) const;
    void UpdateItem(Player* player, Item* item, uint32 newItemId) const;
    void DeleteFakeEntry(Player* player, uint8 slot, Item* itemTransmogrified, SQLTransaction* trans = NULL);
    void SetFakeEntry(Player* player, uint32 newEntry, uint8 slot, Item* itemTransmogrified);

    TransmogTrinityStrings Transmogrify(Player* player, uint64 itemGUID, uint8 slot, /*uint32 newEntry, */bool no_cost = false);
    bool CanTransmogrifyItemWithItem(Player* player, ItemTemplate const* destination, ItemTemplate const* source) const;
    bool SuitableForTransmogrification(Player* player, ItemTemplate const* proto) const;
    // bool CanBeTransmogrified(Item const* item);
    // bool CanTransmogrify(Item const* item);
    uint32 GetSpecialPrice(ItemTemplate const* proto) const;

    void DeleteFakeFromDB(uint64 itemGUID, SQLTransaction* trans = NULL);
    float GetScaledCostModifier() const;
    int32 GetCopperCost() const;

    bool GetRequireToken() const;
    uint32 GetTokenEntry() const;
    uint32 GetTokenAmount() const;

    bool GetAllowMixedArmorTypes() const;
    bool GetAllowMixedWeaponTypes() const;

    // Config
    bool GetEnableTransmogInfo() const;
    uint32 GetTransmogNpcText() const;
    bool GetEnableSetInfo() const;
    uint32 GetSetNpcText() const;
};

#define sTransmogrification ACE_Singleton<Transmogrification, ACE_Null_Mutex>::instance()

#endif
