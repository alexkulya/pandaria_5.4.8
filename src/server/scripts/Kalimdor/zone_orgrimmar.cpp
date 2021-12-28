/*
 * Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2006-2014 ScriptDev2 <https://github.com/scriptdev2/scriptdev2/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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

#include "GameObject.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "AreaTrigger.h"
//#include "AreaTriggerAI.h"
#include "LFGMgr.h"
//#include "SceneHelper.h"

class spell_waters_of_farseeing_94687 : public SpellScriptLoader
{
public:
    spell_waters_of_farseeing_94687() : SpellScriptLoader("spell_waters_of_farseeing_94687") { }

    class spell_waters_of_farseeing_94687_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_waters_of_farseeing_94687_AuraScript);

        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
        {
            if (Unit* caster = GetCaster())
                if (Player* player = caster->ToPlayer())
                    if (player->GetQuestStatus(28805) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(28826) == QUEST_STATUS_INCOMPLETE)
                        player->KilledMonsterCredit(50054);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_waters_of_farseeing_94687_AuraScript::OnApply, EFFECT_0, SPELL_AURA_SCREEN_EFFECT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_waters_of_farseeing_94687_AuraScript();
    }
};

void AddSC_orgrimmar()
{
    new spell_waters_of_farseeing_94687();
}
