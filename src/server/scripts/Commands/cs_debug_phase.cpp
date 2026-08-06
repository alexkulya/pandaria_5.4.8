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
Name: debug_phase_command
%Complete: 100
Comment: Implementation of the `.debug phase` command
Category: commandscripts
EndScriptData */

// This is not a CommandScript of its own: ScriptMgr::GetChatCommands() only
// concatenates the tables returned by every CommandScript, and
// ChatHandler::ExecuteCommandInTable descends into the first entry whose name
// matches and returns unconditionally. A second script declaring its own
// "debug" table would therefore leave its subcommands unreachable. So the entry
// stays registered in cs_debug.cpp and only the implementation lives here.

#include "Chat.h"
#include "ConditionMgr.h"
#include "ObjectMgr.h"
#include "PhaseMgr.h"
#include "Player.h"

#include <set>
#include <sstream>
#include <unordered_map>

namespace
{
    // `trinity_string` entries backing the diff output. Kept here instead of in
    // Language.h: that header is pulled in by most of the core, so adding a
    // debug-only string there would trigger a full rebuild.
    enum PhaseDiffStrings
    {
        PHASING_DIFF_BASELINE           = 21100,
        PHASING_DIFF_HEADER             = 21101,
        PHASING_DIFF_ZONE_CHANGED       = 21102,
        PHASING_DIFF_PHASEMASK_CHANGED  = 21103,
        PHASING_DIFF_PHASEMASK_SAME     = 21104,
        PHASING_DIFF_DEF_ACTIVATED      = 21105,
        PHASING_DIFF_DEF_DEACTIVATED    = 21106,
        PHASING_DIFF_TERRAIN_CHANGED    = 21107,
        PHASING_DIFF_TERRAIN_SAME       = 21108,
        PHASING_DIFF_NOTHING            = 21109
    };

    // Snapshot of everything the command compares between two runs. Rebuilt from
    // the phase definition store rather than read out of PhaseMgr, so the
    // phasing hot path stays untouched.
    struct PhaseSnapshot
    {
        PhaseSnapshot() : zoneId(0), phasemask(0) { }

        uint32 zoneId;
        uint32 phasemask;
        std::set<uint32> activeDefinitions;
        std::set<uint32> terrainSwaps;
    };

    std::unordered_map<uint64, PhaseSnapshot>& GetPhaseSnapshots()
    {
        static std::unordered_map<uint64, PhaseSnapshot> snapshots;
        return snapshots;
    }

    // Mirrors PhaseMgr::Recalculate + PhaseMgr::CheckDefinition, including the
    // NO_MORE_PHASES early out, so the snapshot matches what the core would
    // actually apply to this player right now.
    PhaseSnapshot BuildPhaseSnapshot(Player* player)
    {
        PhaseSnapshot snapshot;
        snapshot.zoneId = player->GetZoneId();
        snapshot.phasemask = player->GetPhaseMask();

        PhaseDefinitionStore const* store = sObjectMgr->GetPhaseDefinitionStore();
        PhaseDefinitionStore::const_iterator itr = store->find(snapshot.zoneId);
        if (itr == store->end())
            return snapshot;

        for (PhaseDefinitionContainer::const_iterator phase = itr->second.begin(); phase != itr->second.end(); ++phase)
        {
            bool meetsConditions = true;
            if (ConditionList const* conditions = sConditionMgr->GetConditionsForPhaseDefinition(phase->zoneId, phase->entry))
            {
                ConditionSourceInfo srcInfo(player);
                meetsConditions = sConditionMgr->IsObjectMeetToConditions(srcInfo, *conditions);
            }

            if (!meetsConditions)
                continue;

            snapshot.activeDefinitions.insert(phase->entry);

            if (phase->terrainswapmap)
                snapshot.terrainSwaps.insert(phase->terrainswapmap);

            if (phase->IsLastDefinition())
                break;
        }

        return snapshot;
    }

    std::string FormatPhaseIdList(std::set<uint32> const& values)
    {
        if (values.empty())
            return "-";

        std::ostringstream stream;
        for (std::set<uint32>::const_iterator itr = values.begin(); itr != values.end(); ++itr)
        {
            if (itr != values.begin())
                stream << ", ";
            stream << *itr;
        }

        return stream.str();
    }

    // Reports the definition rows behind entries that flipped, so the message
    // carries the phasemask/terrainswap that came or went with them.
    void ReportDefinitionChanges(ChatHandler* handler, uint32 zoneId, std::set<uint32> const& before, std::set<uint32> const& after)
    {
        PhaseDefinitionStore const* store = sObjectMgr->GetPhaseDefinitionStore();
        PhaseDefinitionStore::const_iterator itr = store->find(zoneId);
        if (itr == store->end())
            return;

        for (PhaseDefinitionContainer::const_iterator phase = itr->second.begin(); phase != itr->second.end(); ++phase)
        {
            bool const wasActive = before.find(phase->entry) != before.end();
            bool const isActive = after.find(phase->entry) != after.end();

            if (wasActive == isActive)
                continue;

            handler->PSendSysMessage(isActive ? PHASING_DIFF_DEF_ACTIVATED : PHASING_DIFF_DEF_DEACTIVATED,
                phase->entry, phase->zoneId, phase->phasemask, phase->terrainswapmap, phase->phaseId);
        }
    }
}

// Registered as `.debug phase` from cs_debug.cpp.
bool HandleDebugPhaseCommand(ChatHandler* handler, char const* /*args*/)
{
    Unit* unit = handler->getSelectedUnit();
    Player* player = handler->GetSession()->GetPlayer();
    if (unit && unit->GetTypeId() == TYPEID_PLAYER)
        player = unit->ToPlayer();

    player->GetPhaseMgr().SendDebugReportToPlayer(handler->GetSession()->GetPlayer());

    // Diff against the previous run of this command for the same player, so an
    // action taken in between (accepting a quest, changing zone) can be told
    // apart from "nothing happened".
    PhaseSnapshot const current = BuildPhaseSnapshot(player);
    std::unordered_map<uint64, PhaseSnapshot>& snapshots = GetPhaseSnapshots();
    std::unordered_map<uint64, PhaseSnapshot>::iterator previous = snapshots.find(player->GetGUID());

    if (previous == snapshots.end())
    {
        handler->PSendSysMessage(PHASING_DIFF_BASELINE, player->GetName().c_str(), current.zoneId);
        snapshots[player->GetGUID()] = current;
        return true;
    }

    PhaseSnapshot const before = previous->second;
    bool changed = false;

    handler->PSendSysMessage(PHASING_DIFF_HEADER, player->GetName().c_str());

    if (before.zoneId != current.zoneId)
    {
        handler->PSendSysMessage(PHASING_DIFF_ZONE_CHANGED, before.zoneId, current.zoneId);
        changed = true;
    }

    if (before.phasemask != current.phasemask)
    {
        handler->PSendSysMessage(PHASING_DIFF_PHASEMASK_CHANGED, before.phasemask, current.phasemask);
        changed = true;
    }
    else
        handler->PSendSysMessage(PHASING_DIFF_PHASEMASK_SAME, current.phasemask);

    if (before.terrainSwaps != current.terrainSwaps)
    {
        handler->PSendSysMessage(PHASING_DIFF_TERRAIN_CHANGED,
            FormatPhaseIdList(before.terrainSwaps).c_str(), FormatPhaseIdList(current.terrainSwaps).c_str());
        changed = true;
    }
    else
        handler->PSendSysMessage(PHASING_DIFF_TERRAIN_SAME, FormatPhaseIdList(current.terrainSwaps).c_str());

    if (before.activeDefinitions != current.activeDefinitions)
    {
        // Only the zone the player is in now can be resolved against the store.
        ReportDefinitionChanges(handler, current.zoneId, before.activeDefinitions, current.activeDefinitions);
        changed = true;
    }

    if (!changed)
        handler->PSendSysMessage(PHASING_DIFF_NOTHING);

    previous->second = current;
    return true;
}
