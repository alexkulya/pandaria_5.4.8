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

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "BattlegroundSM.h"

// 128648 - tirggered from 128646 Defending Cart Aura 
class spell_defending_cart_arua : public SpellScript
{
    PrepareSpellScript(spell_defending_cart_arua);

    void FilterTarget(std::list<WorldObject*>& targets)
    {
        Unit* cart = GetCaster();
        targets.remove_if([=](WorldObject* target)
        {
            Unit* unit = target->ToUnit();
            if (!unit || unit->GetTypeId() != TYPEID_PLAYER)
                return true;
            if (cart->HasAura(BG_SM_CONTROL_VISUAL_ALLIANCE))
            {
                if (unit->ToPlayer()->GetBGTeam() != ALLIANCE)
                {
                    unit->RemoveAurasDueToSpell(GetSpellInfo()->Id);
                    return true;
                }
            }
            else if (cart->HasAura(BG_SM_CONTROL_VISUAL_HORDE))
            {
                if (unit->ToPlayer()->GetBGTeam() != HORDE)
                {
                    unit->RemoveAurasDueToSpell(GetSpellInfo()->Id);
                    return true;
                }
            }
            else
            {
                unit->RemoveAurasDueToSpell(GetSpellInfo()->Id);
                return true;
            }
            return false;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_defending_cart_arua::FilterTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

void AddSC_silvershard_mines()
{
    new spell_script<spell_defending_cart_arua>("spell_defending_cart_arua");
}
