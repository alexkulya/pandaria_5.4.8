/*
 * Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
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

/* ScriptData
Name: quest_commandscript
%Complete: 100
Comment: All quest related commands
Category: commandscripts
EndScriptData */

#include "Chat.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"

class quest_commandscript : public CommandScript
{
public:
    quest_commandscript() : CommandScript("quest_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> questCommandTable =
        {
            { "add",        SEC_ADMINISTRATOR,  false,  &HandleQuestAdd,        },
            { "complete",   SEC_ADMINISTRATOR,  false,  &HandleQuestComplete,   },
            { "remove",     SEC_ADMINISTRATOR,  false,  &HandleQuestRemove,     },
            { "reward",     SEC_ADMINISTRATOR,  false,  &HandleQuestReward,     },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "quest",      SEC_ADMINISTRATOR,  false,  questCommandTable       },
        };
        return commandTable;
    }

    static bool HandleQuestAdd(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayer();
        if (!player)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // .addquest #entry'
        // number or [name] Shift-click form |color|Hquest:quest_id:quest_level|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args, "Hquest");
        if (!cId)
            return false;

        uint32 entry = atol(cId);

        Quest const* quest = sObjectMgr->GetQuestTemplate(entry);

        if (!quest)
        {
            handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // check item starting quest (it can work incorrectly if added without item in inventory)
        ItemTemplateContainer const* itc = sObjectMgr->GetItemTemplateStore();
        ItemTemplateContainer::const_iterator result = find_if (itc->begin(), itc->end(), Finder<uint32, ItemTemplate>(entry, &ItemTemplate::StartQuest));

        if (result != itc->end())
        {
            handler->PSendSysMessage(LANG_COMMAND_QUEST_STARTFROMITEM, entry, result->second.ItemId);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // ok, normal (creature/GO starting) quest
        if (player->CanAddQuest(quest, true))
        {
            player->AddQuest(quest, NULL);

            bool brokenQuest = sObjectMgr->IsBrokenQuest(entry);
            if (player->CanCompleteQuest(entry) || brokenQuest)
                player->CompleteQuest(entry, brokenQuest, true);
        }

        return true;
    }

    static bool HandleQuestRemove(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayer();
        if (!player)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // .removequest #entry'
        // number or [name] Shift-click form |color|Hquest:quest_id:quest_level|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args, "Hquest");
        if (!cId)
            return false;

        uint32 entry = atol(cId);

        Quest const* quest = sObjectMgr->GetQuestTemplate(entry);

        if (!quest)
        {
            handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // remove all quest entries for 'entry' from quest log
        for (uint8 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
        {
            uint32 logQuest = player->GetQuestSlotQuestId(slot);
            if (logQuest == entry)
            {
                player->SetQuestSlot(slot, 0);

                // we ignore unequippable quest items in this case, its' still be equipped
                player->TakeQuestSourceItem(logQuest, false);

                if (quest->HasFlag(QUEST_FLAGS_FLAGS_PVP))
                {
                    player->pvpInfo.IsHostile = player->pvpInfo.IsInHostileArea || player->HasPvPForcingQuest();
                    player->UpdatePvPState();
                }
            }
        }

        player->RemoveActiveQuest(entry, false);
        player->RemoveRewardedQuest(entry);

        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_CHAR_QUESTSTATUS_REWARDED_BY_QUEST);
        stmt->setUInt32(0, player->GetGUIDLow());
        stmt->setUInt32(1, entry);
        CharacterDatabase.Execute(stmt);

        handler->SendSysMessage(LANG_COMMAND_QUEST_REMOVED);
        return true;
    }

    static bool HandleQuestComplete(ChatHandler* handler, const char* args)
    {
        Player* player = handler->getSelectedPlayer();
        if (!player)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // .quest complete #entry
        // number or [name] Shift-click form |color|Hquest:quest_id:quest_level|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args, "Hquest");
        if (!cId)
            return false;

        uint32 entry = atol(cId);

        Quest const* quest = sObjectMgr->GetQuestTemplate(entry);

        // If player doesn't have the quest
        if (!quest || player->GetQuestStatus(entry) == QUEST_STATUS_NONE)
        {
            handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        player->CompleteQuest(entry, true, true);
        return true;
    }

    static bool HandleQuestReward(ChatHandler* handler, char const* args)
    {
        Player* player = handler->getSelectedPlayer();
        if (!player)
        {
            handler->SendSysMessage(LANG_NO_CHAR_SELECTED);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // .quest reward #entry
        // number or [name] Shift-click form |color|Hquest:quest_id:quest_level|h[name]|h|r
        char* cId = handler->extractKeyFromLink((char*)args, "Hquest");
        if (!cId)
            return false;

        uint32 entry = atol(cId);

        Quest const* quest = sObjectMgr->GetQuestTemplate(entry);
        if (!quest)
        {
            handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (player->GetQuestStatus(entry) == QUEST_STATUS_NONE)
            HandleQuestAdd(handler, cId);
        if (player->GetQuestStatus(entry) != QUEST_STATUS_COMPLETE)
            HandleQuestComplete(handler, cId);
        if (player->GetQuestStatus(entry) != QUEST_STATUS_COMPLETE)
        {
            handler->PSendSysMessage(LANG_COMMAND_QUEST_NOTFOUND, entry);
            handler->SetSentErrorMessage(true);
            return false;
        }

        player->RewardQuest(quest, 0, player);
        return true;
    }
};

void AddSC_quest_commandscript()
{
    new quest_commandscript();
}
