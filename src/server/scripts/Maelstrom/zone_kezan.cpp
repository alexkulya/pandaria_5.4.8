#include "ScriptPCH.h"

struct npc_sister_goldskimmer : public ScriptedAI
{
    npc_sister_goldskimmer(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER && me->IsFriendlyTo(who) && me->isInFrontInMap(who, 7) && !who->HasAura(74973))
        {
            Talk(0, who);
            me->CastSpell(who, 74973, true);
        }
    }
};

void AddSC_kezan()
{
    new creature_script<npc_sister_goldskimmer>("npc_sister_goldskimmer");
}
