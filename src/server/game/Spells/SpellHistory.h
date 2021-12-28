#ifndef SPELL_HISTORY_H
#define SPELL_HISTORY_H

#include "QueryResult.h"
#include "Transaction.h"
#include "TimeValue.h"

class Unit;

class SpellHistory
{
    struct ChargeData
    {
        uint32 ConsumedCharges;
        TimeValue CurrentResetTime;
        TimeValue BaseRegenTime;
    };

    struct CooldownInfo
    {
        int64  RecoveryTime;
        uint32 Category;
        int64  CategoryRecoveryTime;
    };

public:
    struct CooldownEntry
    {
        uint32 SpellId = 0;
        TimeValue CooldownEnd;
        uint32 ItemId = 0;
        uint32 CategoryId = 0;
        TimeValue CategoryEnd;
        TimeValue ProhibitionEnd;
        bool OnHold = false;
    };

    struct RppmProcEntry
    {
        TimeValue LastAttempt;
        TimeValue LastSuccess;
        WeaponAttackType AttackTyep = BASE_ATTACK;
    };

public:
    SpellHistory(Unit* owner);

    void LoadFromDB(PreparedQueryResult&& result, PreparedQueryResult&& chargesResult);

    template <typename Owner>
    void SaveToDB(SQLTransaction& result);

    // Is spell can be casted
    bool IsReady(uint32 spellId, uint32 itemId = 0, bool ignoreCategoryCooldown = false) const;
    bool IsReady(SpellInfo const* spellInfo, uint32 itemId, bool ignoreCategoryCooldown) const;

    void SetCooldownOnHold(SpellInfo const* spellInfo, uint32 itemId);
    void StartCooldown(SpellInfo const* spellInfo, uint32 itemId, Spell* spell = nullptr);
    void StartCooldownOnEvent(SpellInfo const* spellInfo, uint32 itemId, Spell* spell);

    void ProhibitSpell(uint32 spellId, TimeValue cooldow);
    void AddCooldown(uint32 spellId, uint32 itemId, int64 cooldown, uint32 categroy, int64 categoryCooldown);
    void RemoveCooldown(uint32 spellId, bool send);
    void RemoveArenaSpellCooldowns(bool removeActivePetCooldowns);
    void RemoveAllCooldowns();
    template <typename Pred>
    void RemoveCooldowns(Pred pred);
    void ModifyCooldown(uint32 spellId, int32 cooldown);
    void SendCooldown(uint32 spellId, int32 cooldown);
    void SendCooldownEvent(SpellInfo const* spellInfo, uint32 itemId = 0, Spell* spell = nullptr);

    uint32 GetCooldownDelay(uint32 spellId, uint32 itemId = 0) const;
    TimeValue GetChargeCooldown(uint32 spellId);

    bool IsProcReady(uint32 spellId) const
    {
        auto it = _procCooldowns.find(spellId);
        return it == _procCooldowns.end() || it->second <= TimeValue::Now();
    }

    void StartProcCooldown(uint32 spellId, TimeValue const& cooldown)
    {
        auto now = TimeValue::Now();
        _procCooldowns[spellId] = now + cooldown;
    }

    void RppmProcAttempt(uint32 spellId, WeaponAttackType type);
    void RppmPorcSuccess(uint32 spellId, WeaponAttackType type);

    RppmProcEntry const* GetRppmProcEntry(uint32 spellId, WeaponAttackType itemGuid);

    void UpdateCharges();

    void SendSpellHistory() const;

    void OnEncounterStart();

    Player* GetPlayer() const;

    std::unordered_map<uint32, CooldownEntry> const& GetCooldowns() const { return _cooldowns; }

    void ClearAllSpellCharges();
    void ClearChargesForSpell(uint32 spell);

private:
    bool HasCooldown(SpellInfo const* spellInfo) const;
    bool HasCharge(uint32 categoryId) const;
    bool HasCategoryCooldown(uint32 categoryId) const;
    void SendClearCooldowns(std::vector<uint32> const& cooldowns);
    void SendSpellCharges() const;
    CooldownInfo GetCooldownInfo(SpellInfo const* spellInfo, uint32 itemId) const;

private:
    Unit* _owner;
    std::unordered_map<uint32, CooldownEntry> _cooldowns;
    std::unordered_map<uint32, CooldownEntry> _categoryCooldowns;
    std::unordered_map<uint32, ChargeData> _spellCharges;
    std::unordered_map<uint32, TimeValue> _procCooldowns;
    std::multimap<uint32, RppmProcEntry> _procHistory;
};

template <typename Pred>
inline void SpellHistory::RemoveCooldowns(Pred pred)
{
    std::vector<uint32> toClear;
    for (auto it = _cooldowns.begin(); it != _cooldowns.end();)
    {
        auto& entry = it->second;
        ++it;
        if (pred(entry))
            RemoveCooldown(entry.SpellId, true);
    }
}

#endif // !SPELL_HISTORY_H
