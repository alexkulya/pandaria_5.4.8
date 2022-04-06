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
