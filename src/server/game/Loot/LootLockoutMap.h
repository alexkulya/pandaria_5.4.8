#ifndef LOOT_LOCKOUT_MAP_H_INCLUDED
#define LOOT_LOCKOUT_MAP_H_INCLUDED

#include "Player.h"

class LootLockoutMap
{
public:
    LootLockoutMap(Player* owner) : m_owner(owner) { }

    void AddLootLockout(LootLockoutType type, uint32 id, Difficulty difficulty, bool pending)
    {
        auto& lootLockouts = m_lootLockouts[uint32(type)];
        auto& pendingLockouts = m_pendingLootLockouts[uint32(type)];

        for (auto&& itr : pendingLockouts)
            if (itr.Id == id && itr.Difficulty == difficulty)
                return;

        for (auto&& itr : lootLockouts)
            if (itr.Id == id && itr.Difficulty == difficulty)
                return;

        if (type != LootLockoutType::PersonalLoot)
            pending = false;

        lootLockouts.push_back({ id, difficulty });
        m_owner->GetSession()->SendLfgPlayerLockInfo();

        if (pending)
        {
            lootLockouts.pop_back(); // It's already last
            pendingLockouts.push_back({ id, difficulty });
        }

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_CHARACTER_LOOTLOCKOUTS);
        stmt->setUInt32(0, m_owner->GetGUIDLow());
        stmt->setUInt32(1, id);
        stmt->setUInt32(2, difficulty);
        stmt->setUInt32(3, uint32(type));
        CharacterDatabase.Execute(stmt);
    }

    bool HasLootLockout(LootLockoutType type, uint32 id, Difficulty difficulty, bool checkPending) const
    {
        auto& lootLockouts = m_lootLockouts[uint32(type)];
        auto& pendingLockouts = m_pendingLootLockouts[uint32(type)];

        for (auto&& itr : lootLockouts)
            if (itr.Id == id && itr.Difficulty == difficulty)
                return true;

        if (checkPending)
            for (auto&& itr : pendingLockouts)
                if (itr.Id == id && itr.Difficulty == difficulty)
                    return true;

        return false;
    }

    void Clear()
    {
        for (auto&& itr : m_lootLockouts)
            itr.clear();

        for (auto&& itr : m_pendingLootLockouts)
            itr.clear();

        m_owner->GetSession()->SendLfgPlayerLockInfo();
    }

    void FlushPendingLootLockouts()
    {
        for (uint32 i = 0; i < uint32(LootLockoutType::Max); ++i)
            for (auto&& itr : m_pendingLootLockouts[i])
                m_lootLockouts[i].push_back(itr);

        for (auto&& itr : m_pendingLootLockouts)
            itr.clear();
    }

    void LoadFromDB(PreparedQueryResult result)
    {
        if (!result)
            return;

        do
        {
            Field* fields = result->Fetch();
            if (fields[2].GetUInt32() < uint32(LootLockoutType::Max))
                m_lootLockouts[fields[2].GetUInt32()].push_back({ fields[0].GetUInt32(), Difficulty(fields[1].GetUInt32()) });
        } while (result->NextRow());
    }

private:
    struct LootLockout
    {
        uint32 Id;
        ::Difficulty Difficulty;
    };

    std::list<LootLockout> m_lootLockouts[uint32(LootLockoutType::Max)];
    std::list<LootLockout> m_pendingLootLockouts[uint32(LootLockoutType::Max)];

    Player* m_owner;
};

#endif // !LOOT_LOCKOUT_MAP_H_INCLUDED
