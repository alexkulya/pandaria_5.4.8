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

/*
5.0
Transmogrification 3.3.5a - Gossip menu
By Rochet2
ScriptName for NPC:
Creature_Transmogrify
TODO:
Make DB saving even better (Deleting)? What about coding?
Fix the cost formula
-- Too much data handling, use default costs
Are the qualities right?
Blizzard might have changed the quality requirements.
(TC handles it with stat checks)
Cant transmogrify rediculus items // Foereaper: would be fun to stab people with a fish
-- Cant think of any good way to handle this easily, could rip flagged items from cata DB

alexkulya: добавить тексты для госсип меню.
           добавить тексты информационных окон.
           исправить обновление внешнего вида без релога.
           исправить удаление трансмута с отдельной вещи и со всех вещей.
           добавить невидимый трансмут.
*/

#include "CustomTransmogrification.h"
#pragma execution_character_set("UTF-8")

class npc_transmogrifier : public CreatureScript
{
public:
    npc_transmogrifier() : CreatureScript("npc_transmogrifier") { }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        bool ru = player->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU;

        WorldSession* session = player->GetSession();

        if (sTransmogrification->GetEnableTransmogInfo())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/ICONS/INV_Misc_Book_11:26:26:-18:0|tКак работает трансмогрификация?" : "|TInterface/ICONS/INV_Misc_Book_11:26:26:-18:0|tHow does transmogrification work?", EQUIPMENT_SLOT_END + 9, 0);

        for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
        {
            if (const char* slotName = sTransmogrification->GetSlotName(slot, session))
            {
                Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
                uint32 entry = newItem ? sTransmogrification->GetFakeEntry(newItem->GetGUID()) : 0;
                std::string icon = entry ? sTransmogrification->GetItemIcon(entry, 26, 26, -18, 0) : sTransmogrification->GetSlotIcon(slot, 26, 26, -18, 0);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, icon + std::string(slotName), EQUIPMENT_SLOT_END, slot);
            }
	    }

    #ifdef PRESETS
        if (sTransmogrification->GetEnableSets())
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/RAIDFRAME/UI-RAIDFRAME-MAINASSIST:26:26:-18:0|tКомплекты" : "|TInterface/RAIDFRAME/UI-RAIDFRAME-MAINASSIST:26:26:-18:0|tManage sets", EQUIPMENT_SLOT_END + 4, 0);
    #endif
        player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/ICONS/INV_Enchant_Disenchant:26:26:-18:0|t|cffff0000Сбросить все изменения|r" : "|TInterface/ICONS/INV_Enchant_Disenchant:26:26:-18:0|t|cffff0000Remove all transmogrifications|r", EQUIPMENT_SLOT_END + 2, 0, ru ? "Сбросить все изменения внешнего вида надетых на вас вещей?" : "Remove transmogrifications from all equipped items?", 0, false);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:26:26:-18:0|tОбновить меню" : "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:26:26:-18:0|tUpdate menu", EQUIPMENT_SLOT_END + 1, 0);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();
        WorldSession* session = player->GetSession();

        switch (sender)
        {
            case EQUIPMENT_SLOT_END:
                ShowTransmogItems(player, creature, action);
                break;
            case EQUIPMENT_SLOT_END + 1:
                OnGossipHello(player, creature);
                break;
            case EQUIPMENT_SLOT_END + 2:
            {
                bool removed = false;
                SQLTransaction trans = CharacterDatabase.BeginTransaction();

                for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
                {
                    if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                    {
                        if (!sTransmogrification->GetFakeEntry(newItem->GetGUID()))
                            continue;

                        sTransmogrification->DeleteFakeEntry(player, slot, newItem, &trans);
                        removed = true;
                    }
                }

                if (removed)
                {
                    session->SendNotification("%s", session->GetTrinityString(LANG_ERR_UNTRANSMOG_OK));
                    player->CastSpell(player, 27123, true);
                    player->CastSpell(player, 51908, true);
                    CharacterDatabase.CommitTransaction(trans);
                }
                else
                    session->SendNotification(LANG_ERR_UNTRANSMOG_NO_TRANSMOGS);
                OnGossipHello(player, creature);
            }
            break;
            case EQUIPMENT_SLOT_END + 3:
            {
                if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, action))
                {
                    if (sTransmogrification->GetFakeEntry(newItem->GetGUID()))
                    {
                        sTransmogrification->DeleteFakeEntry(player, action, newItem);
                        session->SendNotification("%s", session->GetTrinityString(LANG_ERR_UNTRANSMOG_OK));
                        player->CastSpell(player, 27123, true);
                        player->CastSpell(player, 51908, true);
                    }
                    else
                        session->SendNotification(LANG_ERR_UNTRANSMOG_NO_TRANSMOGS);
                }
                OnGossipSelect(player, creature, EQUIPMENT_SLOT_END, action);
            }
            break;
#ifdef PRESETS
            case EQUIPMENT_SLOT_END + 4:
            {
                bool ru = player->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU;

                if (!sTransmogrification->GetEnableSets())
                {
                    OnGossipHello(player, creature);
                    return true;
                }

                if (sTransmogrification->GetEnableSetInfo())
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/ICONS/INV_Misc_Book_11:26:26:-18:0|tКак работать с комплектами?" : "|TInterface/ICONS/INV_Misc_Book_11:26:26:-18:0|tHow do sets work?", EQUIPMENT_SLOT_END + 10, 0);

                for (Transmogrification::presetIdMap::const_iterator it = sTransmogrification->presetByName[player->GetGUID()].begin(); it != sTransmogrification->presetByName[player->GetGUID()].end(); ++it)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "|TInterface/ICONS/INV_Misc_Statue_02:26:26:-18:0|t" + it->second, EQUIPMENT_SLOT_END + 6, it->first);

                if (sTransmogrification->presetByName[player->GetGUID()].size() < sTransmogrification->GetMaxSets())
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/GuildBankFrame/UI-GuildBankFrame-NewTab:26:26:-18:0|tСохранить комплект" : "|TInterface/GuildBankFrame/UI-GuildBankFrame-NewTab:26:26:-18:0|tSave set", EQUIPMENT_SLOT_END + 8, 0);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/ICONS/Ability_Spy:26:26:-18:0|tНазад..." : "|TInterface/ICONS/Ability_Spy:26:26:-18:0|tBack...", EQUIPMENT_SLOT_END + 1, 0);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            }
            break;
            case EQUIPMENT_SLOT_END + 5:
            {
                if (!sTransmogrification->GetEnableSets())
                {
                    OnGossipHello(player, creature);
                    return true;
                }
                // action = presetID
                for (Transmogrification::slotMap::const_iterator it = sTransmogrification->presetById[player->GetGUID()][action].begin(); it != sTransmogrification->presetById[player->GetGUID()][action].end(); ++it)
                {
                    if (Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, it->first))
                        sTransmogrification->PresetTransmog(player, item, it->second, it->first);
                }
                OnGossipSelect(player, creature, EQUIPMENT_SLOT_END + 6, action);
            }
            break;
            case EQUIPMENT_SLOT_END + 6:
            {
                bool ru = player->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU;

                if (!sTransmogrification->GetEnableSets())
                {
                    OnGossipHello(player, creature);
                    return true;
                }
                // action = presetID
                for (Transmogrification::slotMap::const_iterator it = sTransmogrification->presetById[player->GetGUID()][action].begin(); it != sTransmogrification->presetById[player->GetGUID()][action].end(); ++it)
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, sTransmogrification->GetItemIcon(it->second, 26, 26, -18, 0) + sTransmogrification->GetItemLink(it->second, session), sender, action);

                player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/ICONS/INV_Misc_Statue_02:26:26:-18:0|tНадеть комплект" : "|TInterface/ICONS/INV_Misc_Statue_02:26:26:-18:0|tUse this set", EQUIPMENT_SLOT_END + 5, action, ru ? "После трансмогрификации измененные предметы нельзя будет передать или вернуть торговцу!\n Продолжить?\n\n" : "Using this set for transmogrify will bind transmogrified items to you and make them non-refundable and non-tradeable.\nDo you wish to continue?\n\n" + sTransmogrification->presetByName[player->GetGUID()][action], 0, false);
                player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/PaperDollInfoFrame/UI-GearManager-LeaveItem-Opaque:26:26:-18:0|tУдалить комплект" : "|TInterface/PaperDollInfoFrame/UI-GearManager-LeaveItem-Opaque:26:26:-18:0|tDelete set", EQUIPMENT_SLOT_END + 7, action, ru ? "Вы точно хотите удалить " : "Are you sure you want to delete " + sTransmogrification->presetByName[player->GetGUID()][action] + "?", 0, false);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/ICONS/Ability_Spy:26:26:-18:0|tНазад..." : "|TInterface/ICONS/Ability_Spy:26:26:-18:0|tBack...", EQUIPMENT_SLOT_END + 4, 0);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            }
            break;
            case EQUIPMENT_SLOT_END + 7:
            {
                if (!sTransmogrification->GetEnableSets())
                {
                    OnGossipHello(player, creature);
                    return true;
                }
                // action = presetID
                CharacterDatabase.PExecute("DELETE FROM `custom_transmogrification_sets` WHERE Owner = %u AND PresetID = %u", player->GetGUIDLow(), action);
                sTransmogrification->presetById[player->GetGUID()][action].clear();
                sTransmogrification->presetById[player->GetGUID()].erase(action);
                sTransmogrification->presetByName[player->GetGUID()].erase(action);

                OnGossipSelect(player, creature, EQUIPMENT_SLOT_END + 4, 0);
            }
            break;
            case EQUIPMENT_SLOT_END + 8:
            {
                bool ru = player->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU;

                if (!sTransmogrification->GetEnableSets() || sTransmogrification->presetByName[player->GetGUID()].size() >= sTransmogrification->GetMaxSets())
                {
                    OnGossipHello(player, creature);
                    return true;
                }

                uint32 cost = 0;
                bool canSave = false;

                for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
                {
                    if (!sTransmogrification->GetSlotName(slot, session))
                        continue;

                    if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                    {
                        uint32 entry = sTransmogrification->GetFakeEntry(newItem->GetGUID());

                        if (!entry)
                            continue;

                        const ItemTemplate* temp = sObjectMgr->GetItemTemplate(entry);

                        if (!temp)
                            continue;

                        if (!sTransmogrification->SuitableForTransmogrification(player, temp))
                            continue;

                        cost += sTransmogrification->GetSpecialPrice(temp);
                        canSave = true;
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, sTransmogrification->GetItemIcon(entry, 26, 26, -18, 0) + sTransmogrification->GetItemLink(entry, session), EQUIPMENT_SLOT_END + 8, 0);
                    }
                }

                if (canSave)
                    player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/GuildBankFrame/UI-GuildBankFrame-NewTab:26:26:-18:0|tСохранить комплект" : "|TInterface/GuildBankFrame/UI-GuildBankFrame-NewTab:26:26:-18:0|tSave set", 0, 0, ru ? "Введите название комплекта" : "Insert set name", cost*sTransmogrification->GetSetCostModifier() + sTransmogrification->GetSetCopperCost(), true);

                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:26:26:-18:0|tОбновить меню" : "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:26:26:-18:0|tUpdate menu", sender, action);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/ICONS/Ability_Spy:26:26:-18:0|tНазад..." : "|TInterface/ICONS/Ability_Spy:26:26:-18:0|tBack...", EQUIPMENT_SLOT_END + 4, 0);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            }
            break;
            case EQUIPMENT_SLOT_END + 10:
            {
                bool ru = player->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU;
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/ICONS/Ability_Spy:26:26:-18:0|tНазад..." : "|TInterface/ICONS/Ability_Spy:26:26:-18:0|tBack...", EQUIPMENT_SLOT_END + 4, 0);
                player->SEND_GOSSIP_MENU(sTransmogrification->GetSetNpcText(), creature->GetGUID());
            }
            break;
#endif
            case EQUIPMENT_SLOT_END + 9:
            {
                bool ru = player->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU;
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/ICONS/Ability_Spy:26:26:-18:0|tНазад..." : "|TInterface/ICONS/Ability_Spy:26:26:-18:0|tBack...", EQUIPMENT_SLOT_END + 1, 0);
                player->SEND_GOSSIP_MENU(sTransmogrification->GetTransmogNpcText(), creature->GetGUID());
            }
            break;
            default:
            {
                if (!sender && !action)
                {
                    OnGossipHello(player, creature);
                    return true;
                }
                // sender = slot, action = display
                TransmogTrinityStrings res = sTransmogrification->Transmogrify(player, MAKE_NEW_GUID(action, 0, HIGHGUID_ITEM), sender);

                if (res == LANG_ERR_TRANSMOG_OK)
                {
                    session->SendNotification("%s", session->GetTrinityString(LANG_ERR_TRANSMOG_OK));
                    player->CastSpell(player, 64784, true);
                    player->CastSpell(player, 72313, true);
                }
                else
                    session->SendNotification(res);

                OnGossipSelect(player, creature, EQUIPMENT_SLOT_END, sender);
            }
            break;
        }
        return true;
    }

#ifdef PRESETS
    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code)
    {
        player->PlayerTalkClass->ClearMenus();

        if (sender || action)
            return true;

        if (!sTransmogrification->GetEnableSets())
        {
            OnGossipHello(player, creature);
            return true;
        }

        std::string name(code);

        if (name.find('"') != std::string::npos || name.find('\\') != std::string::npos)
            player->GetSession()->SendNotification(LANG_PRESET_ERR_INVALID_NAME);
        else
        {
            for (uint8 presetID = 0; presetID < sTransmogrification->GetMaxSets(); ++presetID)
            {
                if (sTransmogrification->presetByName[player->GetGUID()].find(presetID) != sTransmogrification->presetByName[player->GetGUID()].end())
                    continue;

                int64 cost = 0;
                std::map<uint8, uint32> items;

                for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
                {
                    if (!sTransmogrification->GetSlotName(slot, player->GetSession()))
                        continue;

                    if (Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                    {
                        uint32 entry = sTransmogrification->GetFakeEntry(newItem->GetGUID());

                        if (!entry)
                            continue;

                        const ItemTemplate* temp = sObjectMgr->GetItemTemplate(entry);

                        if (!temp)
                            continue;

                        if (!sTransmogrification->SuitableForTransmogrification(player, temp))
                            continue;

                        cost += sTransmogrification->GetSpecialPrice(temp);
                        items[slot] = entry;
                    }
                }

                if (items.empty())
                    break;

                cost *= sTransmogrification->GetSetCostModifier();
                cost += sTransmogrification->GetSetCopperCost();

                if (!player->HasEnoughMoney(cost))
                {
                    player->GetSession()->SendNotification(LANG_ERR_TRANSMOG_NOT_ENOUGH_MONEY);
                    break;
                }

                std::ostringstream ss;

                for (std::map<uint8, uint32>::iterator it = items.begin(); it != items.end(); ++it)
                {
                    ss << uint32(it->first) << ' ' << it->second << ' ';
                    sTransmogrification->presetById[player->GetGUID()][presetID][it->first] = it->second;
                }
                sTransmogrification->presetByName[player->GetGUID()][presetID] = name;
                CharacterDatabase.PExecute("REPLACE INTO `custom_transmogrification_sets` (`Owner`, `PresetID`, `SetName`, `SetData`) VALUES (%u, %u, \"%s\", \"%s\")", player->GetGUIDLow(), uint32(presetID), name.c_str(), ss.str().c_str());

                if (cost)
                    player->ModifyMoney(-cost);
                break;
            }
        }

        OnGossipSelect(player, creature, EQUIPMENT_SLOT_END + 4, 0);
        return true;
    }
#endif

    void ShowTransmogItems(Player* player, Creature* creature, uint8 slot)
    {
        bool ru = player->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU;

        WorldSession* session = player->GetSession();
        Item* oldItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);

        if (oldItem)
        {
            uint32 limit = 0;
            uint32 price = sTransmogrification->GetSpecialPrice(oldItem->GetTemplate());
            price *= sTransmogrification->GetScaledCostModifier();
            price += sTransmogrification->GetCopperCost();
            std::ostringstream ss;
            ss << std::endl;

            if (sTransmogrification->GetRequireToken())
                ss << std::endl << std::endl << sTransmogrification->GetTokenAmount() << " x " << sTransmogrification->GetItemLink(sTransmogrification->GetTokenEntry(), session);

            for (uint8 i = INVENTORY_SLOT_ITEM_START; i < INVENTORY_SLOT_ITEM_END; ++i)
            {
                if (limit > MAX_OPTIONS)
                    break;

                Item* newItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i);

                if (!newItem)
                    continue;

                if (!sTransmogrification->CanTransmogrifyItemWithItem(player, oldItem->GetTemplate(), newItem->GetTemplate()))
                    continue;

                if (sTransmogrification->GetFakeEntry(oldItem->GetGUID()) == newItem->GetEntry())
                    continue;

                ++limit;

                player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, sTransmogrification->GetItemIcon(newItem->GetEntry(), 26, 26, -18, 0) + sTransmogrification->GetItemLink(newItem, session), slot, newItem->GetGUIDLow(), ru ? "После трансмогрификации предмет нельзя будет передать или вернуть торговцу!\n Продолжить? \n\n" : "Using this item for transmogrify will bind it to you and make it non-refundable and non-tradeable.\nDo you wish to continue?\n\n" + sTransmogrification->GetItemIcon(newItem->GetEntry(), 30, 30, -15, -10) + sTransmogrification->GetItemLink(newItem, session) + ss.str(), price, false);
            }

            for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
            {
                Bag* bag = player->GetBagByPos(i);

                if (!bag)
                    continue;

                for (uint32 j = 0; j < bag->GetBagSize(); ++j)
                {
                    if (limit > MAX_OPTIONS)
                        break;

                    Item* newItem = player->GetItemByPos(i, j);

                    if (!newItem)
                        continue;

                    if (!sTransmogrification->CanTransmogrifyItemWithItem(player, oldItem->GetTemplate(), newItem->GetTemplate()))
                        continue;

                    if (sTransmogrification->GetFakeEntry(oldItem->GetGUID()) == newItem->GetEntry())
                        continue;

                    ++limit;
                    player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, sTransmogrification->GetItemIcon(newItem->GetEntry(), 26, 26, -18, 0) + sTransmogrification->GetItemLink(newItem, session), slot, newItem->GetGUIDLow(), ru ? "После трансмогрификации предмет нельзя будет передать или вернуть торговцу!\n Продолжить? \n\n" : "Using this item for transmogrify will bind it to you and make it non-refundable and non-tradeable.\nDo you wish to continue?\n\n" + sTransmogrification->GetItemIcon(newItem->GetEntry(), 30, 30, -15, -10) + sTransmogrification->GetItemLink(newItem, session) + ss.str(), price, false);
                }
            }
        }

        player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/ICONS/INV_Enchant_Disenchant:26:26:-18:0|tОтменить трансмогрификацию" : "|TInterface/ICONS/INV_Enchant_Disenchant:26:26:-18:0|tRemove transmogrification", EQUIPMENT_SLOT_END + 3, slot, ru ? "Отменить трансмогрификацию с данного предмета?" : "Remove transmogrification from the slot?", 0, false);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:26:26:-18:0|tОбновить меню" : "|TInterface/PaperDollInfoFrame/UI-GearManager-Undo:26:26:-18:0|tUpdate menu", EQUIPMENT_SLOT_END, slot);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, ru ? "|TInterface/ICONS/Ability_Spy:26:26:-18:0|tНазад..." : "|TInterface/ICONS/Ability_Spy:26:26:-18:0|tBack...", EQUIPMENT_SLOT_END + 1, 0);
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
    }
};

class PS_Transmogrification : public PlayerScript
{
public:
    PS_Transmogrification() : PlayerScript("Player_Transmogrify") { }

    void OnAfterSetVisibleItemSlot(Player* player, uint8 slot, Item *item)
    {
        if (!item)
            return;

        if (uint32 entry = sTransmogrification->GetFakeEntry(item->GetGUID()))
            player->SetUInt32Value(PLAYER_FIELD_VISIBLE_ITEMS + (slot * 2), entry);
    }

    void OnAfterMoveItemFromInventory(Player* /*player*/, Item* it, uint8 /*bag*/, uint8 /*slot*/, bool /*update*/)
    {
        sTransmogrification->DeleteFakeFromDB(it->GetGUIDLow());
    }
    
    void OnLogin(Player* player)
    {
        uint64 playerGUID = player->GetGUID();
        sTransmogrification->entryMap.erase(playerGUID);
        QueryResult result = CharacterDatabase.PQuery("SELECT GUID, FakeEntry FROM custom_transmogrification WHERE Owner = %u", player->GetGUIDLow());

        if (result)
        {
            do
            {
                uint64 itemGUID = MAKE_NEW_GUID((*result)[0].GetUInt32(), 0, HIGHGUID_ITEM);
                uint32 fakeEntry = (*result)[1].GetUInt32();

                if (sObjectMgr->GetItemTemplate(fakeEntry))
                {
                    sTransmogrification->dataMap[itemGUID] = playerGUID;
                    sTransmogrification->entryMap[playerGUID][itemGUID] = fakeEntry;
                }
                else
                {
                    //sLog->outError(LOG_FILTER_SQL, "Item entry (Entry: %u, itemGUID: %u, playerGUID: %u) does not exist, ignoring.", fakeEntry, GUID_LOPART(itemGUID), player->GetGUIDLow());
                    // CharacterDatabase.PExecute("DELETE FROM custom_transmogrification WHERE FakeEntry = %u", fakeEntry);
                }
            } while (result->NextRow());

            for (uint8 slot = EQUIPMENT_SLOT_START; slot < EQUIPMENT_SLOT_END; ++slot)
            {
                if (Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
                    player->SetVisibleItemSlot(slot, item);
            }
        }

#ifdef PRESETS
        if (sTransmogrification->GetEnableSets())
            sTransmogrification->LoadPlayerSets(playerGUID);
#endif
    }

    void OnLogout(Player* player)
    {
        uint64 pGUID = player->GetGUID();

        for (Transmogrification::transmogData::const_iterator it = sTransmogrification->entryMap[pGUID].begin(); it != sTransmogrification->entryMap[pGUID].end(); ++it)
            sTransmogrification->dataMap.erase(it->first);

        sTransmogrification->entryMap.erase(pGUID);

#ifdef PRESETS
        if (sTransmogrification->GetEnableSets())
            sTransmogrification->UnloadPlayerSets(pGUID);
#endif
    }
};

class WS_Transmogrification : public WorldScript
{
public:
    WS_Transmogrification() : WorldScript("WS_Transmogrification") { }

    void OnAfterConfigLoad(bool reload) override
    {
        if (reload)
            sTransmogrification->LoadConfig(reload);
    }

    void OnStartup() override
    {
        sTransmogrification->LoadConfig(false);
        //sLog->outInfo(LOG_FILTER_SERVER_LOADING, "Deleting non-existing transmogrification entries...");
        CharacterDatabase.Execute("DELETE FROM custom_transmogrification WHERE NOT EXISTS (SELECT 1 FROM item_instance WHERE item_instance.guid = custom_transmogrification.GUID)");

#ifdef PRESETS
        CharacterDatabase.Execute("DELETE FROM `custom_transmogrification_sets` WHERE NOT EXISTS(SELECT 1 FROM characters WHERE characters.guid = custom_transmogrification_sets.Owner)");
#endif
    }

    void OnBeforeConfigLoad(bool reload) override { }
};

class global_transmog_script : public GlobalScript
{
    public:
        global_transmog_script() : GlobalScript("global_transmog_script") { }
        
        void OnItemDelFromDB(SQLTransaction& trans, uint32 itemGuid)
        {
            sTransmogrification->DeleteFakeFromDB(itemGuid, &trans);
        }
        
        void OnMirrorImageDisplayItem(const Item *item, uint32 &display)
        {
            if (uint32 entry = sTransmogrification->GetFakeEntry(item->GetGUID()))
                display=uint32(sObjectMgr->GetItemTemplate(entry)->DisplayInfoID);
        }
};

void AddSC_transmog() 
{
    new global_transmog_script();
    new npc_transmogrifier();
    new PS_Transmogrification();
    new WS_Transmogrification();
}
