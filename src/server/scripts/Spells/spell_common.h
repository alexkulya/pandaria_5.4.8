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

#ifndef SPELL_COMMON_H
#define SPELL_COMMON_H

#include "SpellScript.h"

enum CommonSpells
{
    SPELL_CLONE_ME          = 45204,
    SPELL_COPY_WEAPONS      = 41054,
    SPELL_ELUSIVENESS       = 21009,
};

class visual_stacks_controller : public AuraScript
{
protected:
    visual_stacks_controller() { }
    visual_stacks_controller(uint32 rightPartVisual) : secondPartSpell(rightPartVisual) { }

    void Initialize(uint32 spellId, uint32 stacks = 2)
    {
        secondPartSpell = spellId;
        secondPartStacks = stacks;
    }

    void HandleApply(AuraEffect const*, AuraEffectHandleModes)
    {
        Unit* owner = GetUnitOwner();
        if (GetStackAmount() >= secondPartStacks)
            owner->CastSpell(owner, secondPartSpell, true);
        else
            owner->RemoveAurasDueToSpell(secondPartSpell);
    }

    void HandleRemove(AuraEffect const*, AuraEffectHandleModes)
    {
        GetUnitOwner()->RemoveAurasDueToSpell(secondPartSpell);
    }
private:
    uint32 secondPartSpell = 0;
    uint32 secondPartStacks = 2;
};

class spirit_based_aura_effect : public AuraScript
{
protected:
    float GetSpiritWithoutShortDurationBonuses(Unit* caster)
    {
        // Actually totem has -1 duration =/ but I don't know more bonuses which are non passive and permanent at the same time
        float spirit = caster->GetStat(STAT_SPIRIT);
        for (auto&& itr : caster->GetAuraEffectsByType(SPELL_AURA_MOD_STAT))
            if (itr->GetMiscValue() == STAT_SPIRIT)
                if (!itr->GetBase()->IsPassive() && itr->GetBase()->GetMaxDuration() < 10 * MINUTE * IN_MILLISECONDS)
                    spirit -= itr->GetAmount();

        float mult = caster->GetTotalAuraMultiplier(SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE, MiscMaskB(1 << STAT_SPIRIT));
        spirit /= mult;

        return spirit;
    }
};

class spell_smart_heal : public SpellScript
{
protected:
    void ApplySmartHeal(std::list<WorldObject*>& targets, uint32 count, bool ignoreLos = false)
    {
        Position pos = GetCaster()->GetPosition();
        if (GetSpell()->m_targets.HasDst())
            pos = GetSpell()->m_targets.GetDst()->_position;
        Unit* caster = GetOriginalCaster();
        if (!caster)
            caster = GetCaster();
        if (GetSpellInfo()->HasAttribute(SPELL_ATTR2_CAN_TARGET_NOT_IN_LOS))
            ignoreLos = true;
        Spell::ApplySmartHeal(caster, targets, count, ignoreLos, &pos);
    }
};

inline float GetDamageTakenCorrectiveFactor(Unit* caster, Unit* target, SpellInfo const* spellInfo)
{
    SpellSchoolMask attackSchoolMask = spellInfo ? spellInfo->GetSchoolMask() : caster->GetMeleeDamageSchoolMask();
    float takenTotalMod = target->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, attackSchoolMask);
    if (spellInfo)
    {
        if (uint32 mechanicMask = spellInfo->GetAllEffectsMechanicMask())
        {
            for (auto&& it : target->GetAuraEffectsByType(SPELL_AURA_MOD_MECHANIC_DAMAGE_TAKEN_PERCENT))
                if (mechanicMask & uint32(1 << (it->GetMiscValue())))
                    AddPct(takenTotalMod, it->GetAmount());
        }
    }

    for (auto&& it : target->GetAuraEffectsByType(SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN_PCT))
        AddPct(takenTotalMod, it->GetAmount());

    if (Player* player = target->GetAffectingPlayer())
        takenTotalMod *= player->GetResilienceReduction();

    return takenTotalMod;
}

#endif // !SPELL_COMMON_H
