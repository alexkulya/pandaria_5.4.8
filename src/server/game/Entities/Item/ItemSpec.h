#ifndef ITEM_SPEC_H
#define ITEM_SPEC_H

#include "ItemPrototype.h"

class ItemSpecInfo
{
public:
    ItemSpecInfo(ItemTemplate const* temp, uint32 level);

    bool HasSpecializationId(uint32 spec) const
    {
        if (m_specs.empty())    // I don't exactly know
            return true;
        return m_specs.find(Specializations(spec)) != m_specs.end();
    }

private:
    std::set<Specializations> m_specs;
};

#endif // !ITEM_SPEC_H
