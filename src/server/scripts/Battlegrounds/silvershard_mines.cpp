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
