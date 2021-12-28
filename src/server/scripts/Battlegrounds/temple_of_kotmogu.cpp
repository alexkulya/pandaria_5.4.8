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
