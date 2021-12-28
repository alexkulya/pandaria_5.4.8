#include "BattlePetAura.h"
#include "PetBattle.h"

void BattlePetAura::OnApply()
{
    // apply any state modifiers for the aura
    for (uint32 i = 0; i < sBattlePetAbilityStateStore.GetNumRows(); i++)
    {
        auto stateEntry = sBattlePetAbilityStateStore.LookupEntry(i);
        if (!stateEntry)
            continue;

        if (stateEntry->AbilityId != m_ability)
            continue;

        // store state and modifier for removal
        if (m_auraStates.find(stateEntry->StateId) == m_auraStates.end())
            m_auraStates[stateEntry->StateId] = 0;

        int32 newValue = stateEntry->Value + m_target->States[stateEntry->StateId];
        m_auraStates[stateEntry->StateId] += newValue;

        // update state
        m_petBattle->UpdatePetState(m_caster, m_target, 0, stateEntry->StateId, newValue);
    }
}

void BattlePetAura::OnExpire()
{
    // remove any state modifiers for the aura
    for (auto&& stateEntry : m_auraStates)
    {
        int32 newValue = m_target->States[stateEntry.first] - stateEntry.second;
        m_petBattle->UpdatePetState(m_caster, m_target, 0, stateEntry.first, newValue);
    }

    m_auraStates.clear();
}

void BattlePetAura::Process()
{
    // expire aura if it has reached max duration
    if (m_duration != -1 && m_turn > m_maxDuration && !m_expired)
    {
        Expire();
        return;
    }

    // handle aura effects
    if (auto abilityEntry = sBattlePetAbilityStore.LookupEntry(m_ability))
    {
        uint32 turnCount = 0;
        uint32 topMaxTurnId = 0;

        // find longest duration effect
        for (uint32 i = 0; i < sBattlePetAbilityTurnStore.GetNumRows(); i++)
        {
            auto abilityTurnEntry = sBattlePetAbilityTurnStore.LookupEntry(i);
            if (!abilityTurnEntry || abilityTurnEntry->AbilityId != m_ability)
                continue;

            turnCount++;
            topMaxTurnId = std::max(topMaxTurnId, abilityTurnEntry->Duration);
        }

        for (uint32 i = 0; i < sBattlePetAbilityTurnStore.GetNumRows(); i++)
        {
            // make sure ability turn entry is for auras ability
            auto abilityTurnEntry = sBattlePetAbilityTurnStore.LookupEntry(i);
            if (!abilityTurnEntry || abilityTurnEntry->AbilityId != m_ability)
                continue;

            // make sure ability has reached duration required for effect
            if (abilityTurnEntry->Duration != m_turn && turnCount != 1 && topMaxTurnId != 1)
                continue;

            for (uint32 j = 0; j < sBattlePetAbilityEffectStore.GetNumRows(); j++)
            {
                auto abilityEffectEntry = sBattlePetAbilityEffectStore.LookupEntry(j);
                if (!abilityEffectEntry || abilityEffectEntry->AbilityTurnId != abilityTurnEntry->Id)
                    continue;

                // initialise ability effect
                BattlePetAbilityEffect abilityEffect;
                abilityEffect.SetAbilityInfo(m_ability, abilityEffectEntry, abilityEntry->FamilyId);
                abilityEffect.SetCaster(m_caster);
                abilityEffect.AddTarget(m_target);
                abilityEffect.SetParentBattle(m_petBattle);

                abilityEffect.Execute();
            }
        }
    }

    // notify client of aura update
    // Sometimes has turn and stack depth
    PetBattleEffect effect(PET_BATTLE_EFFECT_AURA_CHANGE, m_caster->GetGlobalIndex());
    effect.UpdateAura(m_target->GetGlobalIndex(), m_id, m_ability, m_duration, m_turn);

    m_petBattle->AddEffect(effect);

    m_turn++;

    if (m_duration != -1)
        m_duration--;
}

void BattlePetAura::Expire()
{
    if (m_expired)
        return;

    m_expired = true;

    // notify client of aura removal
    PetBattleEffect effect{ PET_BATTLE_EFFECT_AURA_REMOVE, m_caster->GetGlobalIndex() };
    effect.SetTurn(1, 1); // TODO: wtf?
    effect.UpdateAura(m_target->GetGlobalIndex(), m_id, m_ability, 0, 0);

    m_petBattle->AddEffect(effect);

    // cast any removal procs the ability might have
    m_petBattle->Cast(m_target, m_ability, m_turn, PET_BATTLE_ABILITY_PROC_ON_AURA_REMOVED);

    OnExpire();
}
