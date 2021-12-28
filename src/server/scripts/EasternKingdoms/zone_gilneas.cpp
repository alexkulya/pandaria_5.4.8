#include "ScriptMgr.h"
#include "ScriptedCreature.h"

struct npc_rampaging_worgen : public ScriptedAI
{
    npc_rampaging_worgen(Creature* creature) : ScriptedAI(creature) { }

    void DamageTaken(Unit* attacker, uint32& damage) override
    {
        if (attacker->GetTypeId() != TYPEID_PLAYER && !HealthAbovePct(75))
            damage = 0;

        if (!HealthAbovePct(10) && !me->HasAura(8599))
        {
            Talk(0);
            DoCast(me, 8599);
        }
    }
};

void AddSC_gilneas()
{
    new creature_script<npc_rampaging_worgen>("npc_rampaging_worgen");
}
