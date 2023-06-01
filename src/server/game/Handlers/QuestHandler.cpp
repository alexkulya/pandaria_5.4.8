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

#include "Common.h"
#include "Log.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "World.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "GossipDef.h"
#include "QuestDef.h"
#include "ObjectAccessor.h"
#include "Group.h"
#include "Battleground.h"
#include "ScriptMgr.h"
#include "GameObjectAI.h"
#include "PoolMgr.h"

void WorldSession::HandleQuestgiverStatusQueryOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;

    guid[4] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();
    guid[2] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[5]);
    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[2]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[3]);

    uint32 questStatus = DIALOG_STATUS_NONE;
    uint32 defstatus = DIALOG_STATUS_NONE;

    Object* questgiver = ObjectAccessor::GetObjectByTypeMask(*_player, guid, TYPEMASK_UNIT|TYPEMASK_GAMEOBJECT);
    if (!questgiver)
    {
        TC_LOG_INFO("network", "Error in CMSG_QUESTGIVER_STATUS_QUERY, called for non-existing questgiver (Typeid: %u GUID: %u)", GuidHigh2TypeId(GUID_HIPART(guid)), GUID_LOPART(guid));
        return;
    }

    switch (questgiver->GetTypeId())
    {
    case TYPEID_UNIT:
        {
            TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_STATUS_QUERY for npc, guid = %u", uint32(GUID_LOPART(guid)));
            Creature* cr_questgiver=questgiver->ToCreature();
            if (!cr_questgiver->IsHostileTo(_player))       // do not show quest status to enemies
            {
                questStatus = sScriptMgr->GetDialogStatus(_player, cr_questgiver);
                if (questStatus > 6)
                    questStatus = getDialogStatus(_player, cr_questgiver, defstatus);
            }
            break;
        }
    case TYPEID_GAMEOBJECT:
        {
            TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_STATUS_QUERY for GameObject guid = %u", uint32(GUID_LOPART(guid)));
            GameObject* go_questgiver=(GameObject*)questgiver;
            questStatus = sScriptMgr->GetDialogStatus(_player, go_questgiver);
            if (questStatus > 6)
                questStatus = getDialogStatus(_player, go_questgiver, defstatus);
            break;
        }
    default:
        TC_LOG_ERROR("network", "QuestGiver called for unexpected type %u", questgiver->GetTypeId());
        break;
    }

    //inform client about status of quest
    _player->PlayerTalkClass->SendQuestGiverStatus(questStatus, guid);
}

void WorldSession::HandleQuestgiverHelloOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;

    guid[5] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();
    guid[2] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[5]);
    recvData.ReadByteSeq(guid[2]);

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_HELLO npc = %u", GUID_LOPART(guid));

    Creature* creature = GetPlayer()->GetNPCIfCanInteractWith(guid, UNIT_NPC_FLAG_NONE);
    if (!creature)
    {
        TC_LOG_DEBUG("network", "WORLD: HandleQuestgiverHelloOpcode - Unit (GUID: %u) not found or you can't interact with him.",
            GUID_LOPART(guid));
        return;
    }

    // remove fake death
    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);
    // Stop the npc if moving
    creature->StopMoving();

    if (!sScriptMgr->OnGossipHello(_player, creature))
        _player->TalkedToCreature(creature->GetEntry(), creature->GetGUID());

    _player->PrepareGossipMenu(creature, creature->GetGossipMenuId(), true);
    _player->SendPreparedGossip(creature);

    creature->AI()->sGossipHello(_player);
}

void WorldSession::HandleQuestgiverAcceptQuestOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;

    uint32 questId = recvData.read<uint32>();
    recvData.ReadGuidMask(guid, 6, 0);
    bool startCheat = recvData.ReadBit();
    recvData.ReadGuidMask(guid, 2, 7, 5, 4, 3, 1);
    recvData.ReadGuidBytes(guid, 5, 4, 0, 1, 6, 2, 3, 7);

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_ACCEPT_QUEST npc = %u, quest = %u, startCheat = %u", uint32(GUID_LOPART(guid)), questId, startCheat);

    Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
    Quest const* prevQuestInChain = sObjectMgr->GetQuestTemplate(quest->GetPrevQuestId());
    if (!quest)
        return;

    Object* object;
    if (!IS_PLAYER_GUID(guid))
        object = ObjectAccessor::GetObjectByTypeMask(*_player, guid, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT | TYPEMASK_ITEM);
    else
        object = ObjectAccessor::FindPlayerInOrOutOfWorld(guid);

    if (prevQuestInChain)
    {
        if (object == _player && !prevQuestInChain->HasFlag(QUEST_FLAGS_AUTOCOMPLETE))
            return;
    }
    else
    {
        if (object == _player && !quest->HasFlag(QUEST_FLAGS_AUTO_TAKE))
            return;
    }

#define CLOSE_GOSSIP_CLEAR_DIVIDER() \
    do { \
    _player->PlayerTalkClass->SendCloseGossip(); \
    _player->SetDivider(0); \
    } while (0)

    // no or incorrect quest giver
    if (!object)
    {
        CLOSE_GOSSIP_CLEAR_DIVIDER();
        return;
    }

    if (Player* playerQuestObject = object->ToPlayer())
    {
        if ((_player->GetDivider() && _player->GetDivider() != guid) ||
            ((object != _player && !playerQuestObject->CanShareQuest(questId))))
        {
            CLOSE_GOSSIP_CLEAR_DIVIDER();
            return;
        }
        if (!_player->IsInSameRaidWith(playerQuestObject))
        {
            CLOSE_GOSSIP_CLEAR_DIVIDER();
            return;
        }
    }
    else
    {
        if (!object->hasQuest(questId))
        {
            CLOSE_GOSSIP_CLEAR_DIVIDER();
            return;
        }
    }

    // some kind of WPE protection
    if (!_player->CanInteractWithQuestGiver(object))
    {
        CLOSE_GOSSIP_CLEAR_DIVIDER();
        return;
    }

    if (quest)
    {
        // prevent cheating
        if (!GetPlayer()->CanTakeQuest(quest, true))
        {
            CLOSE_GOSSIP_CLEAR_DIVIDER();
            return;
        }

        if (_player->GetDivider() != 0)
        {
            Player* player = ObjectAccessor::FindPlayer(_player->GetDivider());
            if (player)
            {
                player->SendPushToPartyResponse(_player, QUEST_PARTY_MSG_ACCEPT_QUEST);
                _player->SetDivider(0);
            }
        }

        if (_player->CanAddQuest(quest, true))
        {
            _player->AddQuest(quest, object);

            if (quest->HasFlag(QUEST_FLAGS_PARTY_ACCEPT))
            {
                if (Group* group = _player->GetGroup())
                {
                    for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
                    {
                        Player* player = itr->GetSource();

                        if (!player || player == _player)     // not self
                            continue;

                        if (player->CanTakeQuest(quest, true))
                        {
                            player->SetDivider(_player->GetGUID());

                            //need confirmation that any gossip window will close
                            player->PlayerTalkClass->SendCloseGossip();

                            _player->SendQuestConfirmAccept(quest, player);
                        }
                    }
                }
            }

            bool brokenQuest = sObjectMgr->IsBrokenQuest(questId);

            if (_player->CanCompleteQuest(questId) || brokenQuest)
                _player->CompleteQuest(questId, brokenQuest, false);

            switch (object->GetTypeId())
            {
                case TYPEID_UNIT:
                    object->ToCreature()->AI()->sQuestAccept(_player, quest);
                    break;
                case TYPEID_ITEM:
                case TYPEID_CONTAINER:
                {
                    Item* item = (Item*)object;

                    // destroy not required for quest finish quest starting item
                    bool destroyItem = true;
                    if (item->GetTemplate()->MaxCount > 0)
                    {
                        // Prevent destroying the item if it should have been added as a source item for the quest, but failed because of uniqueness
                        if (quest->GetSrcItemId() == item->GetEntry())
                            destroyItem = false;
                        for (uint8 i = 0; i < QUEST_SOURCE_ITEM_IDS_COUNT && destroyItem; ++i)
                            if (quest->RequiredSourceItemId[i] == item->GetEntry())
                                destroyItem = false;

                        // Prevent destroying the item if it is required for the quest
                        if (destroyItem)
                        {
                            for (auto&& objective : quest->m_questObjectives)
                            {
                                if (objective->Type == QUEST_OBJECTIVE_TYPE_ITEM && objective->ObjectId == item->GetEntry())
                                {
                                    destroyItem = false;
                                    break;
                                }
                            }
                        }
                    }

                    if (destroyItem)
                    {
                        // Dirty hack
                        if (item->GetCount() > 1)
                        {
                            item->SetCount(item->GetCount() - 1);
                            item->SetState(ITEM_CHANGED, _player);
                        }
                        else
                            _player->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);
                    }
                    break;
                }
                case TYPEID_GAMEOBJECT:
                    object->ToGameObject()->AI()->QuestAccept(_player, quest);
                    break;
                default:
                    break;
            }

            if (!quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_project_DAILY_QUEST)) // For these, the gossip is reopened in creature script
                _player->PlayerTalkClass->SendCloseGossip();

            if (quest->GetSrcSpell() > 0)
                _player->CastSpell(_player, quest->GetSrcSpell(), true);

            return;
        }
    }

    CLOSE_GOSSIP_CLEAR_DIVIDER();

#undef CLOSE_GOSSIP_CLEAR_DIVIDER
}

void WorldSession::HandleQuestgiverQueryQuestOpcode(WorldPacket& recvData)
{
    ObjectGuid guid;
    uint32 questId;

    recvData >> questId;
    guid[2] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    recvData.ReadBit();

    recvData.ReadByteSeq(guid[2]);
    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[5]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[6]);

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_QUERY_QUEST npc = %u, quest = %u", uint32(GUID_LOPART(guid)), questId);

    // Verify that the guid is valid and is a questgiver or involved in the requested quest
    Object* object = ObjectAccessor::GetObjectByTypeMask(*_player, guid, TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT | TYPEMASK_ITEM);
    if (!object)
    {
        _player->PlayerTalkClass->SendCloseGossip();
        return;
    }

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
    {
        if (object->GetTypeId() == TYPEID_UNIT && sScriptMgr->OnQuestSelect(_player, object->ToCreature(), quest))
            return;

        if (!object->hasQuest(questId) && !object->hasInvolvedQuest(questId))
        {
            _player->PlayerTalkClass->SendCloseGossip();
            return;
        }

        // not sure here what should happen to quests with QUEST_FLAGS_AUTOCOMPLETE
        // if this breaks them, add && object->GetTypeId() == TYPEID_ITEM to this check
        // item-started quests never have that flag
        if (!_player->CanTakeQuest(quest, true))
            return;

        if (quest->IsAutoAccept() && _player->CanAddQuest(quest, true))
            _player->AddQuestAndCheckCompletion(quest, object);

        if (!sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_COMPLETE) && quest->GetQuestMethod() == 0)
            _player->PlayerTalkClass->SendQuestGiverRequestItems(quest, object->GetGUID(), _player->CanCompleteQuest(quest->GetQuestId()), true);
        else
            _player->PlayerTalkClass->SendQuestGiverQuestDetails(quest, object->GetGUID(), true);
    }
}

void WorldSession::HandleQuestQueryOpcode(WorldPacket& recvData)
{
    if (!_player)
        return;

    ObjectGuid guid;
    uint32 questId;

    recvData >> questId;

    guid[0] = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[2] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[4]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[5]);
    recvData.ReadByteSeq(guid[2]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[0]);

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUEST_QUERY quest = %u", questId);

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
        _player->PlayerTalkClass->SendQuestQueryResponse(quest);
}

void WorldSession::HandleQuestgiverChooseRewardOpcode(WorldPacket& recvData)
{
    uint32 questId, reward;
    ObjectGuid guid;

    recvData >> reward;     // 5.x - reward value is now an item ID and not slot ID
    recvData >> questId;

    guid[2] = recvData.ReadBit();
    guid[6] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[2]);
    recvData.ReadByteSeq(guid[5]);
    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[4]);

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_CHOOSE_REWARD npc = %u, quest = %u, reward = %u", uint32(GUID_LOPART(guid)), questId, reward);

    Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
    if (!quest)
        return;

    Object* object = ObjectAccessor::GetObjectByTypeMask(*_player, guid, TYPEMASK_PLAYER | TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT);;
    if (!object)
        return;

    if (!quest->HasFlag(QUEST_FLAGS_AUTOCOMPLETE) && !object->hasInvolvedQuest(questId))
        return;

    // some kind of WPE protection
    if (!_player->CanInteractWithQuestGiver(object))
        return;

    if ((!_player->CanSeeStartQuest(quest) &&  _player->GetQuestStatus(questId) == QUEST_STATUS_NONE) ||
        (_player->GetQuestStatus(questId) != QUEST_STATUS_COMPLETE && !quest->IsAutoComplete()))
    {
        TC_LOG_ERROR("network", "Error in QUEST_STATUS_COMPLETE: player %s (guid %u) tried to complete quest %u, but is not allowed to do so (possible packet-hacking or high latency)",
            _player->GetName().c_str(), _player->GetGUIDLow(), questId);
        return;
    }

    if (_player->CanRewardQuest(quest, reward, true))
    {
        _player->RewardQuest(quest, reward, object);

        switch (object->GetTypeId())
        {
            case TYPEID_UNIT:
            case TYPEID_PLAYER:
            {
                //For AutoSubmition was added plr case there as it almost same exclute AI script cases.
                Creature* creatureQGiver = object->ToCreature();

                if (!creatureQGiver || !(sScriptMgr->OnQuestReward(_player, creatureQGiver, quest, reward)))
                {
                    // Send next quest
                    if (Quest const* nextQuest = _player->GetNextQuest(guid, quest))
                    {
                        if (nextQuest->IsAutoAccept() && _player->CanAddQuest(nextQuest, true) && _player->CanTakeQuest(nextQuest, true))
                            _player->AddQuestAndCheckCompletion(nextQuest, object);

                        _player->PlayerTalkClass->SendQuestGiverQuestDetails(nextQuest, guid, true);
                    }

                    if (creatureQGiver)
                        creatureQGiver->AI()->sQuestReward(_player, quest, reward);
                }
                break;
            }
            case TYPEID_GAMEOBJECT:
                if (!sScriptMgr->OnQuestReward(_player, ((GameObject*)object), quest, reward))
                {
                    // Send next quest
                    if (Quest const* nextQuest = _player->GetNextQuest(guid, quest))
                    {
                        if (nextQuest->IsAutoAccept() && _player->CanAddQuest(nextQuest, true) && _player->CanTakeQuest(nextQuest, true))
                            _player->AddQuestAndCheckCompletion(nextQuest, object);

                        _player->PlayerTalkClass->SendQuestGiverQuestDetails(nextQuest, guid, true);
                    }

                    object->ToGameObject()->AI()->QuestReward(_player, quest, reward);
                }
                break;
            default:
                break;
        }
    }
    else
        _player->PlayerTalkClass->SendQuestGiverOfferReward(quest, guid, true);

    // HACKALERT
    // I fucking dunno why client does not send query for quest status.
    if (quest->IsAutoComplete())
        HandleQuestgiverStatusMultipleQuery(recvData);
}

void WorldSession::HandleQuestgiverRequestRewardOpcode(WorldPacket& recvData)
{
    uint32 questId;
    ObjectGuid guid;

    recvData >> questId;

    guid[6] = recvData.ReadBit();
    guid[3] = recvData.ReadBit();
    guid[1] = recvData.ReadBit();
    guid[2] = recvData.ReadBit();
    guid[4] = recvData.ReadBit();
    guid[0] = recvData.ReadBit();
    guid[5] = recvData.ReadBit();
    guid[7] = recvData.ReadBit();

    recvData.ReadByteSeq(guid[3]);
    recvData.ReadByteSeq(guid[0]);
    recvData.ReadByteSeq(guid[7]);
    recvData.ReadByteSeq(guid[6]);
    recvData.ReadByteSeq(guid[2]);
    recvData.ReadByteSeq(guid[1]);
    recvData.ReadByteSeq(guid[5]);
    recvData.ReadByteSeq(guid[4]);

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_REQUEST_REWARD npc = %u, quest = %u", uint32(GUID_LOPART(guid)), questId);

    Quest const* quest = sObjectMgr->GetQuestTemplate(questId);

    if (!quest)
        return;

    Object* object = ObjectAccessor::GetObjectByTypeMask(*_player, guid, TYPEMASK_PLAYER | TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT);

    if (!quest->HasFlag(QUEST_FLAGS_AUTOCOMPLETE))
    {
        if (!object || !object->hasInvolvedQuest(questId))
            return;

        // some kind of WPE protection
        if (!_player->CanInteractWithQuestGiver(object))
            return;
    }

    bool brokenQuest = sObjectMgr->IsBrokenQuest(questId);

    if (_player->CanCompleteQuest(questId) || brokenQuest)
        _player->CompleteQuest(questId, brokenQuest, false);

    if (_player->GetQuestStatus(questId) != QUEST_STATUS_COMPLETE)
        return;

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
        _player->PlayerTalkClass->SendQuestGiverOfferReward(quest, guid, true);
}

void WorldSession::HandleQuestgiverCancel(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_CANCEL");

    _player->PlayerTalkClass->SendCloseGossip();
}

void WorldSession::HandleQuestLogSwapQuest(WorldPacket& recvData)
{
    uint8 slot1, slot2;
    recvData >> slot1 >> slot2;

    if (slot1 == slot2 || slot1 >= MAX_QUEST_LOG_SIZE || slot2 >= MAX_QUEST_LOG_SIZE)
        return;

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTLOG_SWAP_QUEST slot 1 = %u, slot 2 = %u", slot1, slot2);

    GetPlayer()->SwapQuestSlot(slot1, slot2);
}

void WorldSession::HandleQuestLogRemoveQuest(WorldPacket& recvData)
{
    uint8 slot;
    recvData >> slot;

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTLOG_REMOVE_QUEST slot = %u", slot);

    if (slot < MAX_QUEST_LOG_SIZE)
    {
        if (uint32 questId = _player->GetQuestSlotQuestId(slot))
        {
            if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
            {
                if (quest->HasSpecialFlag(QUEST_SPECIAL_FLAGS_TIMED))
                    _player->RemoveTimedQuest(questId);

                if (quest->HasFlag(QUEST_FLAGS_FLAGS_PVP))
                {
                    _player->pvpInfo.IsHostile = _player->pvpInfo.IsInHostileArea || _player->HasPvPForcingQuest();
                    _player->UpdatePvPState();
                }
            }

            _player->DestroyQuestItems(questId);
            _player->RemoveActiveQuest(questId);
            _player->RemoveTimedAchievement(CRITERIA_START_TYPE_QUEST, questId);

            TC_LOG_INFO("network", "Player %u abandoned quest %u", _player->GetGUIDLow(), questId);
        }

        _player->SetQuestSlot(slot, 0);

        _player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_QUEST_ABANDONED, 1);
    }
}

void WorldSession::HandleQuestConfirmAccept(WorldPacket& recvData)
{
    uint32 questId;
    recvData >> questId;

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUEST_CONFIRM_ACCEPT questId = %u", questId);

    if (const Quest* quest = sObjectMgr->GetQuestTemplate(questId))
    {
        if (!quest->HasFlag(QUEST_FLAGS_PARTY_ACCEPT))
            return;

        Player* originalPlayer = ObjectAccessor::FindPlayerInOrOutOfWorld(_player->GetDivider());
        if (!originalPlayer)
            return;

        if (!_player->IsInSameRaidWith(originalPlayer))
            return;

        if (!originalPlayer->IsActiveQuest(questId))
            return;

        if (!_player->CanTakeQuest(quest, true))
            return;

        if (_player->CanAddQuest(quest, true))
        {
            _player->AddQuest(quest, NULL);                // NULL, this prevent DB script from duplicate running

            if (quest->GetSrcSpell() > 0)
                _player->CastSpell(_player, quest->GetSrcSpell(), true);
        }
    }

    _player->SetDivider(0);
}

void WorldSession::HandleQuestgiverCompleteQuest(WorldPacket& recvData)
{
    uint32 questId;
    ObjectGuid playerGuid;
    bool autoCompleteMode;      // 0 - standard complete quest mode with npc, 1 - auto-complete mode

    recvData >> questId;

    playerGuid[4] = recvData.ReadBit();
    playerGuid[2] = recvData.ReadBit();
    playerGuid[1] = recvData.ReadBit();
    playerGuid[5] = recvData.ReadBit();
    playerGuid[6] = recvData.ReadBit();
    playerGuid[7] = recvData.ReadBit();
    playerGuid[3] = recvData.ReadBit();
    autoCompleteMode = recvData.ReadBit();
    playerGuid[0] = recvData.ReadBit();

    recvData.ReadByteSeq(playerGuid[0]);
    recvData.ReadByteSeq(playerGuid[2]);
    recvData.ReadByteSeq(playerGuid[1]);
    recvData.ReadByteSeq(playerGuid[4]);
    recvData.ReadByteSeq(playerGuid[3]);
    recvData.ReadByteSeq(playerGuid[6]);
    recvData.ReadByteSeq(playerGuid[7]);
    recvData.ReadByteSeq(playerGuid[5]);

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_COMPLETE_QUEST npc = %u, questId = %u", uint32(GUID_LOPART(playerGuid)), questId);

    Object* object = ObjectAccessor::GetObjectByTypeMask(*_player, playerGuid, TYPEMASK_PLAYER | TYPEMASK_UNIT | TYPEMASK_GAMEOBJECT);
    if (autoCompleteMode == 0)
    {
        if (!object || !object->hasInvolvedQuest(questId))
            return;

        // some kind of WPE protection
        if (!_player->CanInteractWithQuestGiver(object))
            return;
    }

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(questId))
    {
        if (autoCompleteMode && !quest->HasFlag(QUEST_FLAGS_AUTO_SUBMIT) && !quest->HasFlag(QUEST_FLAGS_AUTOCOMPLETE))
        {
            TC_LOG_ERROR("network", "Possible hacking attempt: Player %s [playerGuid: %u] tried to complete questId [entry: %u] by auto-submit flag for quest witch not suport it.",
                _player->GetName().c_str(), _player->GetGUIDLow(), questId);
            return;
        }

        if (!_player->CanSeeStartQuest(quest) && _player->GetQuestStatus(questId) == QUEST_STATUS_NONE)
        {
            TC_LOG_ERROR("network", "Possible hacking attempt: Player %s [guid: %u] tried to complete quest [entry: %u] without being in possession of the quest!",
                _player->GetName().c_str(), _player->GetGUIDLow(), questId);
            return;
        }

        if (Battleground* bg = _player->GetBattleground())
            bg->HandleQuestComplete(questId, _player);

        bool brokenQuest = sObjectMgr->IsBrokenQuest(questId);

        if (_player->CanCompleteQuest(questId) || brokenQuest)
            _player->CompleteQuest(questId, brokenQuest, false);

        if (_player->GetQuestStatus(questId) != QUEST_STATUS_COMPLETE)
        {
            if (quest->IsRepeatable())
                _player->PlayerTalkClass->SendQuestGiverRequestItems(quest, playerGuid, _player->CanCompleteRepeatableQuest(quest), false);
            else
                _player->PlayerTalkClass->SendQuestGiverRequestItems(quest, playerGuid, _player->CanRewardQuest(quest, false), false);
        }
        else
        {
            if (quest->GetQuestObjectiveCountType(QUEST_OBJECTIVE_TYPE_ITEM))
                _player->PlayerTalkClass->SendQuestGiverRequestItems(quest, playerGuid, _player->CanRewardQuest(quest, false), false);
            else
                _player->PlayerTalkClass->SendQuestGiverOfferReward(quest, playerGuid, true);
        }

        if (Creature* creature = object->ToCreature())
            sScriptMgr->OnQuestComplete(_player, creature, quest);
    }
}

void WorldSession::HandleQuestgiverQuestAutoLaunch(WorldPacket& /*recvPacket*/)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_QUEST_AUTOLAUNCH");
}

void WorldSession::HandlePushQuestToParty(WorldPacket& recvPacket)
{
    uint32 questId = recvPacket.read<uint32>();

    if (!_player->CanShareQuest(questId))
        return;

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_PUSHQUESTTOPARTY questId = %u", questId);

    Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
    if (!quest)
        return;

    Player* const sender = GetPlayer();

    if (sPoolMgr->IsPartOfAPool<Quest>(questId) && !sPoolMgr->IsSpawnedObject<Quest>(questId))
    {
        sender->SendPushToPartyResponse(sender, QUEST_PARTY_MSG_CANT_BE_SHARED_TODAY);
        return;
    }

    Group* group = sender->GetGroup();
    if (!group)
        return;

    for (GroupReference* itr = group->GetFirstMember(); itr != NULL; itr = itr->next())
    {
        Player* receiver = itr->GetSource();

        if (!receiver || receiver == sender)
            continue;

        if (!receiver->SatisfyQuestStatus(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QUEST_PARTY_MSG_HAVE_QUEST);
            continue;
        }

        if (receiver->GetQuestStatus(questId) == QUEST_STATUS_COMPLETE)
        {
            sender->SendPushToPartyResponse(receiver, QUEST_PARTY_MSG_FINISH_QUEST);
            continue;
        }

        if (!receiver->CanTakeQuest(quest, false))
        {
            sender->SendPushToPartyResponse(receiver, QUEST_PARTY_MSG_CANT_TAKE_QUEST);
            continue;
        }

        if (!receiver->SatisfyQuestLog(false))
        {
            sender->SendPushToPartyResponse(receiver, QUEST_PARTY_MSG_LOG_FULL);
            continue;
        }

        if (receiver->GetDivider() != 0)
        {
            sender->SendPushToPartyResponse(receiver, QUEST_PARTY_MSG_BUSY);
            continue;
        }

        sender->SendPushToPartyResponse(receiver, QUEST_PARTY_MSG_SHARING_QUEST);

        if (quest->IsAutoAccept() && receiver->CanAddQuest(quest, true) && receiver->CanTakeQuest(quest, true))
            receiver->AddQuestAndCheckCompletion(quest, sender);

        if ((quest->IsAutoComplete() && quest->IsRepeatable() && !quest->IsDailyOrWeekly()) || quest->HasFlag(QUEST_FLAGS_AUTOCOMPLETE))
            receiver->PlayerTalkClass->SendQuestGiverRequestItems(quest, sender->GetGUID(), receiver->CanCompleteRepeatableQuest(quest), true);
        else
        {
            receiver->SetDivider(sender->GetGUID());
            receiver->PlayerTalkClass->SendQuestGiverQuestDetails(quest, receiver->GetGUID(), true);
        }
    }
}

void WorldSession::HandleQuestPushResult(WorldPacket& recvPacket)
{
    ObjectGuid guid;
    uint32 questId = recvPacket.read<uint32>();
    uint8 msg = recvPacket.read<uint8>();
    recvPacket.ReadGuidMask(guid, 5, 3, 0, 6, 1, 2, 7, 4);
    recvPacket.ReadGuidBytes(guid, 1, 2, 0, 5, 6, 4, 7, 3);

    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUEST_PUSH_RESULT");

    if (_player->GetDivider())
    {
        if (_player->GetDivider() == guid)
            if (Player* player = ObjectAccessor::FindPlayerInOrOutOfWorld(_player->GetDivider()))
                player->SendPushToPartyResponse(_player, msg);

        _player->SetDivider(0);
    }
}

uint32 WorldSession::getDialogStatus(Player* player, Object* questgiver, uint32 defstatus)
{
    uint32 result = defstatus;

    QuestRelationBounds qr;
    QuestRelationBounds qir;

    switch (questgiver->GetTypeId())
    {
    case TYPEID_GAMEOBJECT:
        {
            qr  = sObjectMgr->GetGOQuestRelationBounds(questgiver->GetEntry());
            qir = sObjectMgr->GetGOQuestInvolvedRelationBounds(questgiver->GetEntry());
            break;
        }
    case TYPEID_UNIT:
        {
            qr  = sObjectMgr->GetCreatureQuestRelationBounds(questgiver->GetEntry());
            qir = sObjectMgr->GetCreatureQuestInvolvedRelationBounds(questgiver->GetEntry());
            break;
        }
    default:
        //its imposible, but check ^)
        TC_LOG_ERROR("network", "Warning: GetDialogStatus called for unexpected type %u", questgiver->GetTypeId());
        return DIALOG_STATUS_NONE;
    }

    for (QuestRelations::const_iterator i = qir.first; i != qir.second; ++i)
    {
        uint32 result2 = 0;
        uint32 quest_id = i->second;
        Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
        if (!quest)
            continue;

        ConditionList conditions = sConditionMgr->GetConditionsForNotGroupedEntry(CONDITION_SOURCE_TYPE_QUEST_ACCEPT, quest->GetQuestId());
        if (!sConditionMgr->IsObjectMeetToConditions(player, conditions))
            continue;

        QuestStatus status = player->GetQuestStatus(quest_id);
        if ((status == QUEST_STATUS_COMPLETE && !player->GetQuestRewardStatus(quest_id)) ||
            (!sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_COMPLETE) && quest->GetQuestMethod() == 0 && player->CanTakeQuest(quest, false)))
        {
            if (!sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_COMPLETE) && quest->GetQuestMethod() == 0 && quest->IsRepeatable() && !quest->IsDailyOrWeekly())
                result2 = DIALOG_STATUS_REWARD_REP;
            else
                result2 = DIALOG_STATUS_REWARD;
        }
        else if (status == QUEST_STATUS_INCOMPLETE)
            result2 = DIALOG_STATUS_INCOMPLETE;

        if (result2 > result)
            result = result2;
    }

    for (QuestRelations::const_iterator i = qr.first; i != qr.second; ++i)
    {
        uint32 result2 = 0;
        uint32 quest_id = i->second;
        Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);
        if (!quest)
            continue;

        ConditionList conditions = sConditionMgr->GetConditionsForNotGroupedEntry(CONDITION_SOURCE_TYPE_QUEST_ACCEPT, quest->GetQuestId());
        if (!sConditionMgr->IsObjectMeetToConditions(player, conditions))
            continue;

        QuestStatus status = player->GetQuestStatus(quest_id);
        if (status == QUEST_STATUS_NONE)
        {
            if (player->CanSeeStartQuest(quest))
            {
                if (player->SatisfyQuestLevel(quest, false))
                {
                    if (!sWorld->getBoolConfig(CONFIG_QUEST_IGNORE_AUTO_COMPLETE) && quest->GetQuestMethod() == 0)
                        result2 = DIALOG_STATUS_REWARD_REP;
                    else if (player->GetLevel() <= ((player->GetQuestLevel(quest) == -1) ? player->GetLevel() : player->GetQuestLevel(quest) + sWorld->getIntConfig(CONFIG_QUEST_LOW_LEVEL_HIDE_DIFF)))
                    {
                        if (quest->HasFlag(QUEST_FLAGS_DAILY) || quest->HasFlag(QUEST_FLAGS_WEEKLY))
                            result2 = DIALOG_STATUS_AVAILABLE_REP;
                        else
                            result2 = DIALOG_STATUS_AVAILABLE;
                    }
                    else
                        result2 = DIALOG_STATUS_LOW_LEVEL_AVAILABLE;
                }
                else
                    result2 = DIALOG_STATUS_UNAVAILABLE;
            }
        }

        if (result2 > result)
            result = result2;
    }

    return result;
}

void WorldSession::HandleQuestgiverStatusMultipleQuery(WorldPacket& /*recvPacket*/)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_QUESTGIVER_STATUS_MULTIPLE_QUERY");

    uint32 count = 0;
    ByteBuffer byteData;

    WorldPacket data(SMSG_QUESTGIVER_STATUS_MULTIPLE, 3 + count * (1 + 8 + 4));

    size_t pos = data.bitwpos();
    data.WriteBits(count, 21);      // placeholder

    for (Player::ClientGUIDs::const_iterator itr = _player->m_clientGUIDs.begin(); itr != _player->m_clientGUIDs.end(); ++itr)
    {
        uint32 questStatus = DIALOG_STATUS_NONE;
        uint32 defstatus = DIALOG_STATUS_NONE;

        if (IS_CRE_OR_VEH_OR_PET_GUID(*itr))
        {
            // need also pet quests case support
            Creature* questgiver = ObjectAccessor::GetCreatureOrPetOrVehicle(*GetPlayer(), *itr);
            if (!questgiver || questgiver->IsHostileTo(_player))
                continue;
            if (!questgiver->HasFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER))
                continue;
            questStatus = sScriptMgr->GetDialogStatus(_player, questgiver);
            if (questStatus > 6)
                questStatus = getDialogStatus(_player, questgiver, defstatus);

            ObjectGuid guid = questgiver->GetGUID();

            data.WriteBit(guid[4]);
            data.WriteBit(guid[0]);
            data.WriteBit(guid[3]);
            data.WriteBit(guid[6]);
            data.WriteBit(guid[5]);
            data.WriteBit(guid[7]);
            data.WriteBit(guid[1]);
            data.WriteBit(guid[2]);

            byteData.WriteByteSeq(guid[6]);
            byteData.WriteByteSeq(guid[2]);
            byteData.WriteByteSeq(guid[7]);
            byteData.WriteByteSeq(guid[5]);
            byteData.WriteByteSeq(guid[4]);
            byteData << uint32(questStatus);
            byteData.WriteByteSeq(guid[1]);
            byteData.WriteByteSeq(guid[3]);
            byteData.WriteByteSeq(guid[0]);

            ++count;
        }
        else if (IS_GAMEOBJECT_GUID(*itr))
        {
            GameObject* questgiver = GetPlayer()->GetMap()->GetGameObject(*itr);
            if (!questgiver)
                continue;
            if (questgiver->GetGoType() != GAMEOBJECT_TYPE_QUESTGIVER)
                continue;
            questStatus = sScriptMgr->GetDialogStatus(_player, questgiver);
            if (questStatus > 6)
                questStatus = getDialogStatus(_player, questgiver, defstatus);

            ObjectGuid guid = questgiver->GetGUID();

            data.WriteBit(guid[4]);
            data.WriteBit(guid[0]);
            data.WriteBit(guid[3]);
            data.WriteBit(guid[6]);
            data.WriteBit(guid[5]);
            data.WriteBit(guid[7]);
            data.WriteBit(guid[1]);
            data.WriteBit(guid[2]);

            byteData.WriteByteSeq(guid[6]);
            byteData.WriteByteSeq(guid[2]);
            byteData.WriteByteSeq(guid[7]);
            byteData.WriteByteSeq(guid[5]);
            byteData.WriteByteSeq(guid[4]);
            byteData << uint32(questStatus);
            byteData.WriteByteSeq(guid[1]);
            byteData.WriteByteSeq(guid[3]);
            byteData.WriteByteSeq(guid[0]);

            ++count;
        }
    }

    data.FlushBits();
    data.PutBits(pos, count, 21);
    data.append(byteData);

    SendPacket(&data);
}
