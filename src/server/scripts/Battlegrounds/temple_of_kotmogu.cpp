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

#include "BattlegroundTOK.h"

// 121164, 121175, 121176, 121177 - Orb of Power
class spell_orb_of_power : public AuraScript
{
    PrepareAuraScript(spell_orb_of_power);

    void HandleRemove(AuraEffect const*, AuraEffectHandleModes)
    {
        if (Player* player = GetUnitOwner()->ToPlayer())
            if (Battleground* bg = player->GetBattleground())
                if (BattlegroundTOK* tok = dynamic_cast<BattlegroundTOK*>(bg))
                    tok->ReleaseOrb(player);
    }

    void HandleTick(AuraEffect const*)
    {
        IncreaseAmount(GetEffect(EFFECT_0));
        IncreaseAmount(GetEffect(EFFECT_1));
        IncreaseAmount(GetEffect(EFFECT_2));
        if (AuraEffect* scale = GetEffect(EFFECT_4))
            scale->ChangeAmount(scale->GetAmount() + 5);
    }

    void IncreaseAmount(AuraEffect* eff)
    {
        if (eff)
        {
            int32 newAmount = eff->GetAmount() + eff->GetBaseAmount();
            eff->ChangeAmount(newAmount);
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_orb_of_power::HandleRemove, EFFECT_3, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_orb_of_power::HandleTick, EFFECT_3, SPELL_AURA_PERIODIC_DUMMY);
    }
};

void AddSC_temple_of_kotmogu()
{
    new aura_script<spell_orb_of_power>("spell_orb_of_power");
}
