#include "ItemSpec.h"
#include "DBCStores.h"

enum ItemSpecType
{
    ITEM_SPEC_TYPE_MISC     = 0,
    ITEM_SPEC_TYPE_CLOTH    = 1,
    ITEM_SPEC_TYPE_LEATHER  = 2,
    ITEM_SPEC_TYPE_MAIL     = 3,
    ITEM_SPEC_TYPE_PLATE    = 4,
    ITEM_SPEC_TYPE_WEAPON   = 5,
    ITEM_SPEC_TYPE_RELIC    = 6,
};

enum ItemSpecStat
{
    ITEM_SPEC_STAT_INTELLECT        = 0,
    ITEM_SPEC_STAT_AGILITY          = 1,
    ITEM_SPEC_STAT_STRENGTH         = 2,
    ITEM_SPEC_STAT_SPIRIT           = 3,
    ITEM_SPEC_STAT_HIT              = 4,
    ITEM_SPEC_STAT_DODGE            = 5,
    ITEM_SPEC_STAT_PARRY            = 6,
    ITEM_SPEC_STAT_ONE_HANDED_AXE   = 7,
    ITEM_SPEC_STAT_TWO_HANDED_AXE   = 8,
    ITEM_SPEC_STAT_ONE_HANDED_SWORD = 9,
    ITEM_SPEC_STAT_TWO_HANDED_SWORD = 10,
    ITEM_SPEC_STAT_ONE_HANDED_MACE  = 11,
    ITEM_SPEC_STAT_TWO_HANDED_MACE  = 12,
    ITEM_SPEC_STAT_DAGGER           = 13,
    ITEM_SPEC_STAT_FIST_WEAPON      = 14,
    ITEM_SPEC_STAT_GUN              = 15,
    ITEM_SPEC_STAT_BOW              = 16,
    ITEM_SPEC_STAT_CROSSBOW         = 17,
    ITEM_SPEC_STAT_STAFF            = 18,
    ITEM_SPEC_STAT_POLEARM          = 19,
    ITEM_SPEC_STAT_THROWN           = 20,
    ITEM_SPEC_STAT_WAND             = 21,
    ITEM_SPEC_STAT_SHIELD           = 22,
    ITEM_SPEC_STAT_RELIC            = 23,
    ITEM_SPEC_STAT_CRIT             = 24,
    ITEM_SPEC_STAT_HASTE            = 25,
    ITEM_SPEC_STAT_END              = 26,
};

class ItemSpecCreationInfo
{
    friend class ItemSpecInfo;
public:
    ItemSpecCreationInfo(ItemTemplate const* proto, uint32 level);

private:
    void AddStat(ItemSpecStat stat, bool isMain);
    void AddItemStat(uint32 stat);
    static ItemSpecStat GetStatForWeapon(ItemTemplate const* proto);
    static ItemSpecStat GetStatForItemStat(uint32 itemStat);

private:
    ItemSpecType m_type = ITEM_SPEC_TYPE_MISC;
    std::vector<ItemSpecStat> m_specStats;
    bool m_hasItemStat = false;
};

ItemSpecCreationInfo::ItemSpecCreationInfo(ItemTemplate const* proto, uint32 level)
{
    if (proto->Class == ITEM_CLASS_WEAPON)
    {
        m_type = ITEM_SPEC_TYPE_WEAPON;
        auto stat = GetStatForWeapon(proto);
        if (stat != ITEM_SPEC_STAT_END)
            AddStat(stat, true);
    }
    else if (proto->Class == ITEM_CLASS_ARMOR)
    {
        if (proto->SubClass == ITEM_SUBCLASS_ARMOR_CLOTH)
        {
            if (proto->InventoryType != INVTYPE_CLOAK)
                m_type = ITEM_SPEC_TYPE_CLOTH;
        }
        else if (proto->SubClass == ITEM_SUBCLASS_ARMOR_LEATHER)
        {
            m_type = ITEM_SPEC_TYPE_LEATHER;
        }
        else if (proto->SubClass == ITEM_SUBCLASS_ARMOR_MAIL)
        {
            m_type = ITEM_SPEC_TYPE_MAIL;
        }
        else if (proto->SubClass == ITEM_SUBCLASS_ARMOR_PLATE)
        {
            m_type = ITEM_SPEC_TYPE_PLATE;
        }
        else if (proto->SubClass == ITEM_SUBCLASS_ARMOR_SHIELD)
        {
            AddStat(ITEM_SPEC_STAT_SHIELD, true);
        }
        else if (proto->SubClass > ITEM_SUBCLASS_ARMOR_SHIELD && proto->SubClass <= ITEM_SUBCLASS_ARMOR_RELIC)
        {
            m_type = ITEM_SPEC_TYPE_RELIC;
            AddStat(ITEM_SPEC_STAT_RELIC, true);
        }
    }
    if (proto->ScalingStatDistribution)
    {
        auto entry = sScalingStatDistributionStore.LookupEntry(proto->ScalingStatDistribution);
        if (entry)
        {
            for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
            {
                if (entry->Modifier[i])
                    AddItemStat(entry->StatMod[i]);
            }
        }
    }
    else
    {
        for (uint32 i = 0; i < MAX_ITEM_PROTO_STATS; ++i)
            AddItemStat(proto->ItemStat[i].ItemStatType);
    }
}

void ItemSpecCreationInfo::AddStat(ItemSpecStat stat, bool isMain)
{
    for (auto&& it : m_specStats)
        if (it == stat)
            return;

    m_specStats.push_back(stat);
    if (!isMain)
        m_hasItemStat = true;
}

void ItemSpecCreationInfo::AddItemStat(uint32 itemStat)
{
    auto specStat = GetStatForItemStat(itemStat);
    if (specStat != ITEM_SPEC_STAT_END)
        AddStat(specStat, false);
}

ItemSpecStat ItemSpecCreationInfo::GetStatForWeapon(ItemTemplate const* proto)
{
    switch (proto->SubClass)
    {
        case ITEM_SUBCLASS_WEAPON_AXE:          return ITEM_SPEC_STAT_ONE_HANDED_AXE;
        case ITEM_SUBCLASS_WEAPON_AXE2:         return ITEM_SPEC_STAT_TWO_HANDED_AXE;
        case ITEM_SUBCLASS_WEAPON_SWORD:        return ITEM_SPEC_STAT_ONE_HANDED_SWORD;
        case ITEM_SUBCLASS_WEAPON_SWORD2:       return ITEM_SPEC_STAT_TWO_HANDED_SWORD;
        case ITEM_SUBCLASS_WEAPON_MACE:         return ITEM_SPEC_STAT_ONE_HANDED_MACE;
        case ITEM_SUBCLASS_WEAPON_MACE2:        return ITEM_SPEC_STAT_TWO_HANDED_MACE;
        case ITEM_SUBCLASS_WEAPON_DAGGER:       return ITEM_SPEC_STAT_DAGGER;
        case ITEM_SUBCLASS_WEAPON_FIST_WEAPON:  return ITEM_SPEC_STAT_FIST_WEAPON;
        case ITEM_SUBCLASS_WEAPON_GUN:          return ITEM_SPEC_STAT_GUN;
        case ITEM_SUBCLASS_WEAPON_BOW:          return ITEM_SPEC_STAT_BOW;
        case ITEM_SUBCLASS_WEAPON_CROSSBOW:     return ITEM_SPEC_STAT_CROSSBOW;
        case ITEM_SUBCLASS_WEAPON_STAFF:        return ITEM_SPEC_STAT_STAFF;
        case ITEM_SUBCLASS_WEAPON_POLEARM:      return ITEM_SPEC_STAT_POLEARM;
        case ITEM_SUBCLASS_WEAPON_THROWN:       return ITEM_SPEC_STAT_THROWN;
        case ITEM_SUBCLASS_WEAPON_WAND:         return ITEM_SPEC_STAT_WAND;
    }
    return ITEM_SPEC_STAT_END;
}

ItemSpecStat ItemSpecCreationInfo::GetStatForItemStat(uint32 stat)
{
    switch (stat)
    {
        case ITEM_MOD_INTELLECT:            return ITEM_SPEC_STAT_INTELLECT;
        case ITEM_MOD_AGILITY:              return ITEM_SPEC_STAT_AGILITY;
        case ITEM_MOD_STRENGTH:             return ITEM_SPEC_STAT_STRENGTH;
        case ITEM_MOD_SPIRIT:               return ITEM_SPEC_STAT_SPIRIT;
        case ITEM_MOD_HIT_RATING:           return ITEM_SPEC_STAT_HIT;
        case ITEM_MOD_DODGE_RATING:         return ITEM_SPEC_STAT_DODGE;
        case ITEM_MOD_PARRY_RATING:         return ITEM_SPEC_STAT_PARRY;
        case ITEM_MOD_CRIT_MELEE_RATING:
        case ITEM_MOD_CRIT_RANGED_RATING:
        case ITEM_MOD_CRIT_RATING:
        case ITEM_MOD_CRIT_SPELL_RATING:    return ITEM_SPEC_STAT_CRIT;
        case ITEM_MOD_HASTE_RATING:         return ITEM_SPEC_STAT_HASTE;
        default:
            break;
    }
    return ITEM_SPEC_STAT_END;
}

ItemSpecInfo::ItemSpecInfo(ItemTemplate const* proto, uint32 level)
{
    dbc::FillItemSpecOverride(proto->ItemId, m_specs);

    if (m_specs.empty())
    {
        ItemSpecCreationInfo info{ proto, level };

        auto& stats = info.m_specStats;
        // I dunno, the item stats check is used only in lua version of a function, client builds the specs anyway.
        if (info.m_hasItemStat && !stats.empty())
        {
            uint32 primairyStat = ITEM_SPEC_STAT_END;
            bool found = false;
            for (uint32 i = 0; i < sItemSpecStore.GetNumRows(); ++i)
            {
                if (auto entry = sItemSpecStore.LookupEntry(i))
                {
                    if (level >= entry->MinLevel && level <= entry->MaxLevel)
                    {
                        if (info.m_type == entry->ItemType)
                        {
                            found = true;
                            auto it = std::find(stats.begin(), stats.end(), entry->PrimaryStat);
                            if (it == stats.end())
                                continue;
                            if (entry->SecondaryStat == ITEM_SPEC_STAT_END)
                            {
                                if (primairyStat != entry->PrimaryStat)
                                    m_specs.insert(Specializations(entry->SpecializationId));
                            }
                            else
                            {
                                it = std::find(stats.begin(), stats.end(), entry->SecondaryStat);
                                if (it == stats.end())
                                    continue;
                                m_specs.insert(Specializations(entry->SpecializationId));
                                primairyStat = entry->PrimaryStat;
                            }
                        }
                        else if (found) // The table is sorted, no need to iterate forward
                            break;
                    }
                }
            }
        }
    }
}
