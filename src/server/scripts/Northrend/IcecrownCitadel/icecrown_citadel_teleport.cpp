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

#include "ScriptedGossip.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "icecrown_citadel.h"
#include "Spell.h"

#define GOSSIP_SENDER_ICC_PORT 631
#define LIGHT_S_HAMMER_TELE 0
#define ORATORY_OF_THE_DAMNED_TELE 1
#define RAMPART_OF_SKULLS_TELE 2
#define DEATHBRINGER_S_RISE_TELE 3
#define UPPER_SPIRE_TELE 4
#define SINDRAGOSA_S_LAIR_TELE 5
#define FROZEN_THRONE_TELE 6

class icecrown_citadel_teleport : public GameObjectScript
{
    public:
        icecrown_citadel_teleport() : GameObjectScript("icecrown_citadel_teleport") { }

        bool OnGossipHello(Player* player, GameObject* go) override
        {
            if (go->GetEntry() != GO_SCOURGE_TRANSPORTER_LIGHTS_HAMMER)
                player->ADD_GOSSIP_ITEM_DB(player->GetDefaultGossipMenuForSource(go), LIGHT_S_HAMMER_TELE, GOSSIP_SENDER_ICC_PORT, LIGHT_S_HAMMER_TELEPORT);
            if (InstanceScript* instance = go->GetInstanceScript())
            {
                if (go->GetEntry() != GO_SCOURGE_TRANSPORTER_ORATORY && instance->GetBossState(DATA_LORD_MARROWGAR) == DONE || player->IsGameMaster())
                    player->ADD_GOSSIP_ITEM_DB(player->GetDefaultGossipMenuForSource(go), ORATORY_OF_THE_DAMNED_TELE, GOSSIP_SENDER_ICC_PORT, ORATORY_OF_THE_DAMNED_TELEPORT);
                if (go->GetEntry() != GO_SCOURGE_TRANSPORTER_RAMPART && instance->GetBossState(DATA_LADY_DEATHWHISPER) == DONE || player->IsGameMaster())
                    player->ADD_GOSSIP_ITEM_DB(player->GetDefaultGossipMenuForSource(go), RAMPART_OF_SKULLS_TELE, GOSSIP_SENDER_ICC_PORT, RAMPART_OF_SKULLS_TELEPORT);
                // if (go->GetEntry() != GO_SCOURGE_TRANSPORTER_DEATHBRINGERS && instance->GetBossState(DATA_GUNSHIP_EVENT) == DONE || player->IsGameMaster()) // todo: finish gunship battle
                if (go->GetEntry() != GO_SCOURGE_TRANSPORTER_DEATHBRINGERS && instance->GetBossState(DATA_LADY_DEATHWHISPER) == DONE || player->IsGameMaster())
                    player->ADD_GOSSIP_ITEM_DB(player->GetDefaultGossipMenuForSource(go), DEATHBRINGER_S_RISE_TELE, GOSSIP_SENDER_ICC_PORT, DEATHBRINGER_S_RISE_TELEPORT);
                if (go->GetEntry() != GO_SCOURGE_TRANSPORTER_UPPER_SPIRE && instance->GetData(DATA_COLDFLAME_JETS) == DONE || player->IsGameMaster())
                    player->ADD_GOSSIP_ITEM_DB(player->GetDefaultGossipMenuForSource(go), UPPER_SPIRE_TELE, GOSSIP_SENDER_ICC_PORT, UPPER_SPIRE_TELEPORT);
                if (go->GetEntry() != GO_SCOURGE_TRANSPORTER_SINDRAGOSAS_LAIR && instance->GetBossState(DATA_SINDRAGOSA_GAUNTLET) == DONE || player->IsGameMaster())
                    player->ADD_GOSSIP_ITEM_DB(player->GetDefaultGossipMenuForSource(go), SINDRAGOSA_S_LAIR_TELE, GOSSIP_SENDER_ICC_PORT, SINDRAGOSA_S_LAIR_TELEPORT);
                if (player->IsGameMaster()) // teleport to Frozen Throne only from area teleport (except GM)
                    player->ADD_GOSSIP_ITEM_DB(player->GetDefaultGossipMenuForSource(go), FROZEN_THRONE_TELE, GOSSIP_SENDER_ICC_PORT, /*LIGHT_S_HAMMER_TELEPORT*/FROZEN_THRONE_TELEPORT);
            }

            player->SEND_GOSSIP_MENU(player->GetGossipTextId(go), go->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action) override
        {
            if (player->HasItemCount(49278, 1, true))
                player->DestroyItemCount(49278, 1, true);

            player->PlayerTalkClass->ClearMenus();
            player->CLOSE_GOSSIP_MENU();

            SpellInfo const* spell = sSpellMgr->GetSpellInfo(action);
            if (!spell)
                return false;

            if (player->IsInCombat())
            {
                Spell::SendCastResult(player, spell, 0, SPELL_FAILED_AFFECTING_COMBAT);
                return true;
            }

            if (sender == GOSSIP_SENDER_ICC_PORT)
            {
                player->CastSpell(player, spell, true);
            }

            return true;
        }
};

class at_frozen_throne_teleport : public AreaTriggerScript
{
    public:
        at_frozen_throne_teleport() : AreaTriggerScript("at_frozen_throne_teleport") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (player->IsInCombat())
            {
                if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(FROZEN_THRONE_TELEPORT))
                    Spell::SendCastResult(player, spell, 0, SPELL_FAILED_AFFECTING_COMBAT);
                return true;
            }

            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetBossState(DATA_PROFESSOR_PUTRICIDE) == DONE && instance->GetBossState(DATA_BLOOD_QUEEN_LANA_THEL) == DONE
                    && instance->GetBossState(DATA_SINDRAGOSA) == DONE && instance->GetBossState(DATA_THE_LICH_KING) != IN_PROGRESS)
                {
                    player->CastSpell(player, FROZEN_THRONE_TELEPORT, true);
                   // instance->SetData(DATA_ICC_BUFF, 0); // no buff 30%
                }
            return true;
        }
};

// 70860 - Frozen Throne Teleport
class spell_frozen_throne_teleport_hack : public AuraScript
{
    PrepareAuraScript(spell_frozen_throne_teleport_hack);

    void HandleRemove(AuraEffect const*, AuraEffectHandleModes)
    {
        // Case when the grid isn't loaded yet =/ Can't be fixed with custom visibility
        if (auto spell = sSpellMgr->GetSpellTargetPosition(GetSpellInfo()->Id, EFFECT_0))
            if (GetUnitOwner()->GetPositionZ() < spell->target_Z && GetUnitOwner()->GetMapId() == spell->target_mapId)
                GetUnitOwner()->NearTeleportTo(spell->target_X, spell->target_Y, spell->target_Z, spell->target_Orientation);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_frozen_throne_teleport_hack::HandleRemove, EFFECT_2, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_icecrown_citadel_teleport()
{
    new icecrown_citadel_teleport();
    new at_frozen_throne_teleport();
    new aura_script<spell_frozen_throne_teleport_hack>("spell_frozen_throne_teleport_hack");
}
