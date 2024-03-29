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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"

enum q24697
{
    NPC_DIEMETRADON       = 9163,
    NPC_YOUNG_DIEMETRADON = 9162,
};

 // Un'Goro Pit Bunny - Instakill Dinosaur - 71771
class spell_instakill_dinosaur : public SpellScript
{
    PrepareSpellScript(spell_instakill_dinosaur);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([=](WorldObject* obj) { return obj->GetEntry() != NPC_DIEMETRADON && obj->GetEntry() != NPC_YOUNG_DIEMETRADON; });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_instakill_dinosaur::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
    }
};

void AddSC_ungoro_crater()
{
    register_spell_script(spell_instakill_dinosaur);
}
