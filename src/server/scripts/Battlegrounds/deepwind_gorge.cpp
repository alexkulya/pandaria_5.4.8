#include "ScriptMgr.h"
#include "BattlegroundDG.h"

enum Events
{
    EVENT_NEW_WAYPOINT = 1,
};

// Mine cart - 71071 / 71073
struct npc_dg_cart : public ScriptedAI
{
    npc_dg_cart(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (me->GetOwner() && me->GetDistance(me->GetOwner()->GetPosition()) > 5.0f)
        {
            me->SetSpeed(MOVE_RUN, (me->GetOwner()->GetSpeed(MOVE_RUN) + 1.f) / playerBaseMoveSpeed[MOVE_RUN], true);
            if (!me->isMoving() && events.Empty())
                events.ScheduleEvent(EVENT_NEW_WAYPOINT, 700);
            if (events.ExecuteEvent() == EVENT_NEW_WAYPOINT)
                me->GetMotionMaster()->MoveChase(me->GetOwner(), frand(0.5f, 1.f), frand(0.f, 2.f * M_PI));
            if (!me->HasAura(52595))
                me->GetOwner()->CastSpell(me, 52595, true);
        }
    }

private:
    EventMap events;
};

// Horde mine cart - 141210
// Alliance mine cart - 140876
class spell_mine_cart: public AuraScript
{
    PrepareAuraScript(spell_mine_cart);

    void HandleOnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        uint32 entry = 0;
        if (GetSpellInfo()->Id == BG_DG_HORDE_MINE_CART)
            entry = 71073;
        else if (GetSpellInfo()->Id == BG_DG_ALLIANCE_MINE_CART)
            entry = 71071;

        if (entry != 0)
        {
            std::list<Creature*> carts;
            GetCaster()->GetCreatureListWithEntryInGrid(carts, entry, 500.f);
            for (auto&& cart : carts)
            {
                if (TempSummon* tempSummon = cart->ToTempSummon())
                    tempSummon->UnSummon();
            }
        }
    }

    void Register()
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_mine_cart::HandleOnRemove, EFFECT_3, SPELL_AURA_428, AURA_EFFECT_HANDLE_REAL);
    }
};

// 97388 - Capturing
// 124492 - Capturing (Sivershard Mines but who cares)
class spell_dg_capturing : public SpellScript
{
    PrepareSpellScript(spell_dg_capturing);

    bool Load() override
    {
        GetCaster()->RemoveAurasByType(SPELL_AURA_MOUNTED);
        return true;
    }

    SpellCastResult CheckCast()
    {
        Player* caster = GetCaster()->ToPlayer();
        if (!caster || caster->isTotalImmune())
            return SPELL_FAILED_TRY_AGAIN;
        if (caster->GetTotalAuraModifier(SPELL_AURA_DEFLECT_SPELLS) >= 100)
            return SPELL_FAILED_TRY_AGAIN;
        if (!GetSpell()->GetCastTime() && caster->IsNonMeleeSpellCasted(false, true, true))
            return SPELL_FAILED_SPELL_IN_PROGRESS;

        return SPELL_CAST_OK;
    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_dg_capturing::CheckCast);
    }
};

void AddSC_deepwind_gorge()
{
    new creature_script<npc_dg_cart>("npc_dg_cart");
    new aura_script<spell_mine_cart>("spell_mine_cart");
    new spell_script<spell_dg_capturing>("spell_dg_capturing");
}
