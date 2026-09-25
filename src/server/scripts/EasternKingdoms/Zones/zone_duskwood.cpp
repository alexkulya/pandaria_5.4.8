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

/* ScriptData
SDName: Duskwood
SD%Complete: 100
SDComment: Quest Support:8735
SDCategory: Duskwood
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"

enum DuskwoodData
{
    QUEST_NIGHTMARES_CORRUPTION     = 8735,

    NPC_TWILIGHT_CORRUPTER          = 15625,

    SPELL_SOUL_CORRUPTION           = 25805,
    SPELL_SHADOW_BOLT_VOLLEY        = 21307,

    SAY_TWILIGHT_CORRUPTER_SUMMON   = 0,
    SAY_TWILIGHT_CORRUPTER_DEATH    = 1,
    EMOTE_TWILIGHT_CORRUPTER_KILL   = 2
};

Position const TwilightCorrupterPosition = { -10328.16f, -489.57f, 49.95f, 0.0f };

class at_twilight_grove : public AreaTriggerScript
{
public:
    at_twilight_grove() : AreaTriggerScript("at_twilight_grove") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/) override
    {
        if (player->GetQuestStatus(QUEST_NIGHTMARES_CORRUPTION) == QUEST_STATUS_INCOMPLETE)
            if (!player->FindNearestCreature(NPC_TWILIGHT_CORRUPTER, 500.0f, true))
                if (Creature* corrupter = player->SummonCreature(NPC_TWILIGHT_CORRUPTER, TwilightCorrupterPosition, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000))
                    corrupter->AI()->Talk(SAY_TWILIGHT_CORRUPTER_SUMMON, player);

        return false;
    }
};

class boss_twilight_corrupter : public CreatureScript
{
public:
    boss_twilight_corrupter() : CreatureScript("boss_twilight_corrupter") { }

    struct boss_twilight_corrupterAI : public ScriptedAI
    {
        boss_twilight_corrupterAI(Creature* creature) : ScriptedAI(creature) { }

        uint32 SoulCorruptionTimer;
        uint32 ShadowBoltVolleyTimer;

        void Reset() override
        {
            SoulCorruptionTimer = 15000;
            ShadowBoltVolleyTimer = 8000;
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
                Talk(EMOTE_TWILIGHT_CORRUPTER_KILL, victim);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_TWILIGHT_CORRUPTER_DEATH);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (ShadowBoltVolleyTimer <= diff)
            {
                DoCastVictim(SPELL_SHADOW_BOLT_VOLLEY);
                ShadowBoltVolleyTimer = 12000;
            }
            else
                ShadowBoltVolleyTimer -= diff;

            if (SoulCorruptionTimer <= diff)
            {
                DoCastVictim(SPELL_SOUL_CORRUPTION);
                SoulCorruptionTimer = 20000;
            }
            else
                SoulCorruptionTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_twilight_corrupterAI(creature);
    }
};

void AddSC_duskwood()
{
    new at_twilight_grove();
    new boss_twilight_corrupter();
}
