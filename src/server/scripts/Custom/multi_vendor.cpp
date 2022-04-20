/* hack script for dk base camp teleport */
#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "Spell.h"
#include "ObjectMgr.h"
#include "PlayerDump.h"


// Options
enum eEnums
{
    CHANGE_ITEMBACK             = 0,
    EFIRALS                     = 38186,
    CHANGE_FACTION              = 1,
    CHANGE_RACE                 = 2,
    CHANGE_GENDER               = 3,
    RECOVERY_CHAR               = 4,
    EFIRALS_TRANS               = 5,

    CHANGE_FACTION_COUNT        = 200,
    CHANGE_RACE_COUNT           = 150,
    CHANGE_GENDER_COUNT         = 100,
    RECOVERY_CHAR_COUNT         = 225,
};

class multi_vendor : public CreatureScript
{
public:
    multi_vendor() : CreatureScript("multi_vendor"){}

    bool OnGossipHello(Player* player, Creature* creature)
    {
        float rate = sWorld->getRate(RATE_DONATE);
        uint32 priceFaction = uint32(200 * rate);
        uint32 priceRace = uint32(150 * rate);
        uint32 priceGender = uint32(100 * rate);
        uint32 priceRecobery = uint32(225 * rate);
        if(sWorld->getBoolConfig(CONFIG_FUN_OPTION_ENABLED))
            priceFaction = 0;

        LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
        char printinfo[500]; // Max length

        sprintf(printinfo, sObjectMgr->GetTrinityString(20003, loc_idx), priceFaction);
        player->ADD_GOSSIP_ITEM(0, printinfo, GOSSIP_SENDER_MAIN, CHANGE_FACTION);

        sprintf(printinfo, sObjectMgr->GetTrinityString(20004, loc_idx), priceRace);
        player->ADD_GOSSIP_ITEM(0, printinfo, GOSSIP_SENDER_MAIN, CHANGE_RACE);

        sprintf(printinfo, sObjectMgr->GetTrinityString(20005, loc_idx), priceGender);
        player->ADD_GOSSIP_ITEM(0, printinfo, GOSSIP_SENDER_MAIN, CHANGE_GENDER);

        sprintf(printinfo, sObjectMgr->GetTrinityString(20010, loc_idx), priceRecobery);
        player->ADD_GOSSIP_ITEM(0, printinfo, GOSSIP_SENDER_MAIN, RECOVERY_CHAR);
        player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20014, loc_idx), GOSSIP_SENDER_MAIN, EFIRALS_TRANS);

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if(!player || !creature || !player->getAttackers().empty())
            return true;

        if (player->InBattlegroundQueue())
        {
            ChatHandler(player).PSendSysMessage("You should leave from battleground queue.");
            return true;
        }

        if (sObjectMgr->IsPlayerInLogList(player))
        {
            sObjectMgr->DumpDupeConstant(player);
            TC_LOG_DEBUG("dupe", "---ItemBack; action: %u;", action);
        }

        float rate = sWorld->getRate(RATE_DONATE);
        uint32 priceFaction = uint32(200 * rate);
        if(sWorld->getBoolConfig(CONFIG_FUN_OPTION_ENABLED))
            priceFaction = 0;
        uint32 priceRace = uint32(150 * rate);
        uint32 priceGender = uint32(100 * rate);
        uint32 priceRecobery = uint32(225 * rate);
        uint32 countefirs = player->GetItemCount(EFIRALS, false);
        uint32 accountId = player->GetSession()->GetAccountId();
        LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
        if(accountId < 1)
            return true;

        bool activate = false;
        ChatHandler chH = ChatHandler(player);

        switch(sender)
        {
            case GOSSIP_SENDER_MAIN:
            {
                switch(action)
                {
                    case CHANGE_FACTION:
                    {
                        if(countefirs < priceFaction)
                        {
                            chH.PSendSysMessage(20000, priceFaction);
                            player->CLOSE_GOSSIP_MENU();
                            break;
                        }

                        player->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
                        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '64' WHERE guid = %u", player->GetGUIDLow());
                        CharacterDatabase.PExecute("INSERT INTO character_donate_service SET `account`='%u',`guid`='%u', `service`='%s', `cost`='%u', `targetguid`='%u'",accountId , player->GetGUIDLow(), "CHANGE_FACTION", priceFaction, player->GetGUIDLow());
                        player->DestroyItemCount(EFIRALS, priceFaction, true);
                        activate = true;
                        player->CLOSE_GOSSIP_MENU();
                        break;
                    }
                    case CHANGE_RACE:
                    {
                        if(countefirs < priceRace)
                        {
                            chH.PSendSysMessage(20000, priceRace);
                            player->CLOSE_GOSSIP_MENU();
                            break;
                        }

                        player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
                        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '128' WHERE guid = %u", player->GetGUIDLow());
                        CharacterDatabase.PExecute("INSERT INTO character_donate_service SET `account`='%u',`guid`='%u', `service`='%s', `cost`='%u', `targetguid`='%u'", accountId, player->GetGUIDLow(), "CHANGE_RACE", priceRace, player->GetGUIDLow());
                        player->DestroyItemCount(EFIRALS, priceRace, true);
                        activate = true;
                        player->CLOSE_GOSSIP_MENU();
                        break;
                    }
                    case CHANGE_GENDER:
                    {
                        if(countefirs < priceGender)
                        {
                            chH.PSendSysMessage(20000, priceGender);
                            break;
                        }

                        player->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
                        CharacterDatabase.PExecute("UPDATE characters SET at_login = at_login | '8' WHERE guid = '%u'", player->GetGUIDLow());
                        CharacterDatabase.PExecute("INSERT INTO character_donate_service SET `account`='%u',`guid`='%u', `service`='%s', `cost`='%u', `targetguid`='%u'", accountId, player->GetGUIDLow(), "CHANGE_GENDER", priceGender, player->GetGUIDLow());
                        player->DestroyItemCount(EFIRALS, priceGender, true);
                        activate = true;
                        player->CLOSE_GOSSIP_MENU();
                        break;
                    }
                    case EFIRALS_TRANS:
                    {
                        if(countefirs < 10 || countefirs > 9999)
                        {
                            chH.PSendSysMessage(20018);
                            player->CLOSE_GOSSIP_MENU();
                            break;
                        }

                        QueryResult result = CharacterDatabase.PQuery("SELECT name, guid FROM `characters` WHERE account = '%u' AND guid != '%u'", accountId, player->GetGUIDLow());
                        if (!result)
                        {
                            player->CLOSE_GOSSIP_MENU();
                            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20015, loc_idx), GOSSIP_SENDER_MAIN, CHANGE_ITEMBACK);
                            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
                        }
                        else
                        {
                            player->CLOSE_GOSSIP_MENU();
                            uint32 transcount = CalculatePct(countefirs, 85);
                            uint32 delcount = (countefirs - transcount);
                            char printinfo[500]; // Max length
                            sprintf(printinfo, sObjectMgr->GetTrinityString(20016, loc_idx), countefirs, transcount, delcount);
                            player->ADD_GOSSIP_ITEM(0, printinfo, GOSSIP_SENDER_MAIN, EFIRALS_TRANS);
                            do
                            {
                                Field* fields = result->Fetch();
                                std::string playerName  = fields[0].GetString();
                                uint32 guid             = fields[1].GetUInt32();

                                char chardata[50]; // Max length: name(12) + guid(11) + _.log (5) + \0
                                sprintf(chardata, "%s", playerName.c_str());
                                player->ADD_GOSSIP_ITEM(0, chardata, GOSSIP_SENDER_INN_INFO, guid);

                            }while (result->NextRow());
                        }
                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
                        return true;
                    }
                    case RECOVERY_CHAR:
                    {
                        QueryResult result = CharacterDatabase.PQuery("SELECT deleteInfos_Name, guid, level, class, deleteDate FROM `characters` WHERE deleteInfos_Account = '%u'", accountId);
                        if (!result)
                        {
                            player->CLOSE_GOSSIP_MENU();
                            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20009, loc_idx), GOSSIP_SENDER_MAIN, CHANGE_ITEMBACK);
                            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
                        }
                        else
                        {
                            player->CLOSE_GOSSIP_MENU();
                            do
                            {
                                Field* fields = result->Fetch();
                                std::string playerName  = fields[0].GetString();
                                uint32 guid             = fields[1].GetUInt32();
                                uint8 level             = fields[2].GetUInt8();
                                uint8 pclass            = fields[3].GetUInt8();
                                uint32 deleteDate       = fields[4].GetUInt32();

                                char chardata[200]; // Max length: name(12) + guid(11) + _.log (5) + \0
                                sprintf(chardata, "%s level %d class %s", playerName.c_str(), level, GetClassNameById(pclass).c_str());
                                player->ADD_GOSSIP_ITEM(0, chardata, GOSSIP_SENDER_INFO, guid);

                            }while (result->NextRow());
                        }

                        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
                        return true;
                    }
                }
                break;
            }
            case GOSSIP_SENDER_INN_INFO:
            {
                if(countefirs < 10 || countefirs > 9999)
                {
                    chH.PSendSysMessage(20018);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                }
                QueryResult result = CharacterDatabase.PQuery("SELECT name, guid FROM `characters` WHERE account = '%u' AND guid = '%u'", accountId, action);
                if (!result || action == player->GetGUIDLow())
                {
                    player->CLOSE_GOSSIP_MENU();
                    break;
                }
                else
                {
                    Player* receiver = ObjectAccessor::FindPlayer(action);
                    uint32 transcount = CalculatePct(countefirs, 85);
                    player->DestroyItemCount(EFIRALS, countefirs, true);
                    // from console show not existed sendermail
                    MailSender sendermail(MAIL_NORMAL, 0, MAIL_STATIONERY_GM);
                    // fill mail
                    MailDraft draft(sObjectMgr->GetTrinityString(20017, loc_idx), sObjectMgr->GetTrinityString(20017, loc_idx));
                    SQLTransaction trans = CharacterDatabase.BeginTransaction();

                    if (Item* item = Item::CreateItem(EFIRALS, transcount, 0))
                    {
                        TC_LOG_DEBUG("efir", "EFIRALS_TRANS item %u; transcount efir = %u playerGUID %u, itemGUID %u receiver %u", EFIRALS, transcount, player->GetGUID(), item->GetGUID(), action);

                        player->SaveInventoryAndGoldToDB(trans);
                        item->SaveToDB(trans);                           // save for prevent lost at next mail load, if send fail then item will deleted
                        draft.AddItem(item);
                        draft.SendMailTo(trans, MailReceiver(receiver, GUID_LOPART(action)), sendermail);
                        CharacterDatabase.CommitTransaction(trans);
                        chH.PSendSysMessage(20019, transcount);
                    }
                    CharacterDatabase.PExecute("INSERT INTO character_donate_service SET `account`='%u',`guid`='%u', `service`='%s', `cost`='%u', `targetguid`='%u'", accountId , player->GetGUIDLow(), "EFIRALS_TRANS", transcount, action);
                }
                break;
            }
            case GOSSIP_SENDER_INFO:
            {
                if(countefirs < priceRecobery)
                {
                    chH.PSendSysMessage(20000, priceRecobery);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                }
                std::string name = "";
                uint8 gender = GENDER_NONE;
                uint8 race = RACE_NONE;
                uint8 playerClass = 0;
                uint8 level = 1;

                QueryResult result = CharacterDatabase.PQuery("SELECT deleteInfos_Account, guid, deleteInfos_Name, gender, race, class, level FROM `characters` WHERE guid = '%u'", action);
                if (result)
                {
                    Field* fields = result->Fetch();
                    uint32 account = fields[0].GetUInt32();
                    name = fields[2].GetString();
                    gender = fields[3].GetUInt8();
                    race = fields[4].GetUInt8();
                    playerClass = fields[5].GetUInt8();
                    level = fields[6].GetUInt8();
                    if(!account || account != accountId)
                    {
                        player->CLOSE_GOSSIP_MENU();
                        break;
                    }
                }
                else
                {
                    player->CLOSE_GOSSIP_MENU();
                    break;
                }

                CharacterDatabase.PExecute("UPDATE `characters` SET at_login = at_login | '1', name = deleteInfos_Name, account = deleteInfos_Account, deleteDate = NULL, deleteInfos_Name = NULL, deleteInfos_Account = NULL WHERE deleteDate IS NOT NULL AND guid = '%u'", action);

                player->DestroyItemCount(EFIRALS, priceRecobery, true);
                sWorld->AddCharacterNameData(action, name, gender, race, playerClass, level);
                CharacterDatabase.PExecute("INSERT INTO character_donate_service SET `account`='%u',`guid`='%u', `service`='%s', `cost`='%u', `targetguid`='%u'",accountId , player->GetGUIDLow(), "RECOVERY_CHAR", priceRecobery, action);
                chH.PSendSysMessage(20011);
            }
            break;
        }

        if(activate)
            chH.PSendSysMessage(LANG_CUSTOMIZE_PLAYER, chH.GetNameLink(player).c_str());

        player->CLOSE_GOSSIP_MENU();
        return true;
    }
    std::string GetClassNameById(uint8 id)
    {
        std::string sClass = "";
        switch (id)
        {
            case CLASS_WARRIOR:         sClass = "Warrior";        break;
            case CLASS_PALADIN:         sClass = "Pala";           break;
            case CLASS_HUNTER:          sClass = "Hunt";           break;
            case CLASS_ROGUE:           sClass = "Rogue";          break;
            case CLASS_PRIEST:          sClass = "Priest";         break;
            case CLASS_DEATH_KNIGHT:    sClass = "DK";             break;
            case CLASS_SHAMAN:          sClass = "Shama";          break;
            case CLASS_MAGE:            sClass = "Mage";           break;
            case CLASS_WARLOCK:         sClass = "Warlock";        break;
            case CLASS_DRUID:           sClass = "Druid";          break;
        }
        return sClass;
    }
};

class item_back : public CreatureScript
{
public:
    item_back() : CreatureScript("item_back"){}

    bool OnGossipHello(Player* player, Creature* creature)
    {
        QueryResult result = CharacterDatabase.PQuery("SELECT itemguid, itemEntry, count, efircount FROM character_donate WHERE owner_guid = '%u' AND state = 0 AND `type` = 0", player->GetGUIDLow());
        if (!result)
        {
            LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20008, loc_idx), GOSSIP_SENDER_MAIN, CHANGE_ITEMBACK);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
        }
        else
        {
            LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20006, loc_idx), GOSSIP_SENDER_MAIN, CHANGE_ITEMBACK);
            do
            {
                Field* fields = result->Fetch();
                uint32 item_guid = fields[0].GetUInt32();
                uint32 entry = fields[1].GetUInt32();
                uint32 count = fields[2].GetUInt32();
                uint32 efir = fields[3].GetUInt32() * 0.8;
                ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(entry);
                if (pProto && pProto->Stackable < 2)
                {
                    std::string Name = pProto->Name1;

                    if (loc_idx >= 0)
                    {
                        if (ItemLocale const* il = sObjectMgr->GetItemLocale(pProto->ItemId))
                            ObjectMgr::GetLocaleString(il->Name, loc_idx, Name);
                    }
                    char printinfo[500];
                    sprintf(printinfo, sObjectMgr->GetTrinityString(20043, loc_idx), Name.c_str(), efir);

                    player->ADD_GOSSIP_ITEM_EXTENDED(0, printinfo, GOSSIP_SENDER_MAIN, item_guid, sObjectMgr->GetTrinityString(20042, loc_idx), 0, false);
                }
            }while (result->NextRow());
        }

        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        TC_LOG_DEBUG("network", "item_back sender %u, action %u", sender, action);

        if(!player || !creature || sender != GOSSIP_SENDER_MAIN || !player->getAttackers().empty())
            return true;

        ChatHandler chH = ChatHandler(player);

        if (player->InBattlegroundQueue())
        {
            chH.PSendSysMessage("You should leave from battleground queue.");
            return true;
        }

        if (sObjectMgr->IsPlayerInLogList(player))
        {
            sObjectMgr->DumpDupeConstant(player);
            TC_LOG_DEBUG("dupe", "---ItemBack; action: %u;", action);
        }

        TC_LOG_DEBUG("network", "item_back sender %u, action %u", sender, action);

        if(action > 0)
        {
            QueryResult result = CharacterDatabase.PQuery("SELECT `owner_guid`, `itemEntry`, `efircount`, `count` FROM character_donate WHERE itemguid = '%u' AND state = 0", action);
            if(!result)
            {
                player->CLOSE_GOSSIP_MENU(); return true;
            }

            Field* fields = result->Fetch();
            uint32 owner_guid = fields[0].GetUInt32();
            uint32 entry = fields[1].GetUInt32();
            uint32 efircount = fields[2].GetUInt32();
            uint32 count = fields[3].GetUInt32();
            uint32 countitem = player->GetItemCount(entry, false);

            if(owner_guid != player->GetGUIDLow())
            {
                player->CLOSE_GOSSIP_MENU(); return true;
            }

            QueryResult result2 = CharacterDatabase.PQuery("SELECT `owner_guid` FROM item_instance WHERE guid = '%u'", action);
            if(!result2)
            {
                if(countitem == 0)
                    CharacterDatabase.PExecute("UPDATE character_donate SET state = 3, deletedate = '%s' WHERE itemguid = '%u'", TimeToTimestampStr(time(NULL)).c_str(), action);

                player->CLOSE_GOSSIP_MENU(); return true;
            }

            Field* fields2 = result2->Fetch();
            uint32 owner_guid2 = fields2[0].GetUInt32();
            if(owner_guid != owner_guid2)
            {
                player->CLOSE_GOSSIP_MENU(); return true;
            }

            if(player->GetGUIDLow() != owner_guid2)
            {
                player->CLOSE_GOSSIP_MENU(); return true;
            }

            if(Item *item = GetItemByGuid(action, player))
            {
                TC_LOG_DEBUG("efir", "ItemBack item %u; count efir = %u playerGUID %u, itemGUID %u", item->GetEntry(), count, player->GetGUID(), action);

                player->DestroyItemCount(item, count, true);
                player->AddItem(EFIRALS, uint32(efircount * 0.8));
                player->SaveToDB();
                if (sObjectMgr->IsPlayerInLogList(player))
                    sObjectMgr->DumpDupeConstant(player);

                CharacterDatabase.PExecute("UPDATE character_donate SET state = 4, deletedate = '%s' WHERE itemguid = '%u'", TimeToTimestampStr(time(NULL)).c_str(), action);
                chH.PSendSysMessage(20002, uint32(efircount * 0.8));
            }
        }
        else
            chH.PSendSysMessage(20001);

        player->CLOSE_GOSSIP_MENU();
        return true;
    }

    Item* GetItemByGuid(uint64 guid, Player* player) const
    {
        for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
            if (Item *pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                if (pItem->GetGUIDLow() == guid)
                    return pItem;

        for (int i = BANK_SLOT_ITEM_START; i < BANK_SLOT_ITEM_END; ++i)
            if (Item *pItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
                if (pItem->GetGUIDLow() == guid)
                    return pItem;

        for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
            if (Bag *pBag = player->GetBagByPos(i))
                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                    if (Item* pItem = pBag->GetItemByPos(j))
                        if (pItem->GetGUIDLow() == guid)
                            return pItem;

        for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
            if (Bag *pBag = player->GetBagByPos(i))
                for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                    if (Item* pItem = pBag->GetItemByPos(j))
                        if (pItem->GetGUIDLow() == guid)
                            return pItem;

        return NULL;
    }

    bool CanStoreItem(Player* player)
    {
        ChatHandler chH = ChatHandler(player);
        uint32 itemId = 38186;
        uint32 count = 1;
        uint32 _noSpaceForCount = 0;
        ItemPosCountVec dest;
        InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, count, &_noSpaceForCount);
        if (msg != EQUIP_ERR_OK)
            count -= _noSpaceForCount;

        if (count == 0 || dest.empty())
        {
            // -- TODO: Send to mailbox if no space
            chH.PSendSysMessage("You don't have any space in your bags.");
            return false;
        }
        return true;
    }
};


class char_transfer : public CreatureScript
{
public:
    char_transfer() : CreatureScript("char_transfer"){}

    bool OnGossipHello(Player* player, Creature* creature)
    {
        QueryResult result = LoginDatabase.PQuery("SELECT `to_realm`, `name` FROM realm_transfer WHERE from_realm = '%u';", realmID);
        if (!result)
        {
            LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20027, loc_idx), GOSSIP_SENDER_MAIN, 0);
            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
        }
        else
        {
            LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20031, loc_idx), GOSSIP_SENDER_MAIN, 0);
            do
            {
                Field* fields = result->Fetch();
                uint32 realm = fields[0].GetUInt32();
                std::string name = fields[1].GetString();

                player->ADD_GOSSIP_ITEM(0, name, GOSSIP_SENDER_MAIN, realm);
            }while (result->NextRow());
        }

        player->SetTransferId(0);
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if(!player || !creature || !player->getAttackers().empty())
            return true;

        player->PlayerTalkClass->ClearMenus();
        ChatHandler chH = ChatHandler(player);

        switch (sender)
        {
            case GOSSIP_SENDER_MAIN:
            {
                if(QueryResult check_wpe = LoginDatabase.PQuery("SELECT `name` FROM realm_transfer WHERE from_realm = '%u' AND to_realm = '%u';", realmID, action))
                    player->SetTransferId(action);
                else
                    return true;

                QueryResult result = CharacterDatabase.PQuery("SELECT guid, name FROM characters WHERE account = '%u' AND transfer = 0", player->GetSession()->GetAccountId());
                if (!result)
                {
                    LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
                    player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20027, loc_idx), GOSSIP_SENDER_MAIN, 0);
                    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,creature->GetGUID());
                }
                else
                {
                    LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
                    player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(20028, loc_idx), GOSSIP_SENDER_MAIN, 0);
                    do
                    {
                        Field* fields = result->Fetch();
                        uint32 guid = fields[0].GetUInt32();
                        std::string name = fields[1].GetString();

                        player->ADD_GOSSIP_ITEM(0, name, GOSSIP_SENDER_INN_INFO, guid);
                    }while (result->NextRow());
                }
                break;
            }
            case GOSSIP_SENDER_INN_INFO:
            {
                if(action > 0)
                {
                    QueryResult result = CharacterDatabase.PQuery("SELECT guid, name FROM characters WHERE guid = '%u' AND account = '%u' AND transfer = 0", action, player->GetSession()->GetAccountId());
                    if(!result)
                    {
                        player->CLOSE_GOSSIP_MENU();
                        return true;
                    }

                    Field* fields = result->Fetch();
                    uint32 guid = fields[0].GetUInt32();
                    std::string name = fields[1].GetString();
                    uint32 account_id = player->GetSession()->GetAccountId();
                    std::string dump;

                    if(PlayerDumpWriter().WriteDump(uint32(guid), dump) != DUMP_SUCCESS)
                    {
                        chH.PSendSysMessage(LANG_COMMAND_EXPORT_FAILED);
                        chH.SetSentErrorMessage(true);
                        return false;
                    }

                    PreparedStatement * stmt = LoginDatabase.GetPreparedStatement(LOGIN_SET_DUMP);
                    if(stmt)
                    {
                        stmt->setUInt32(0, account_id);
                        stmt->setUInt32(1, guid);
                        stmt->setUInt32(2, realmID);
                        stmt->setUInt32(3, player->GetTransferId());
                        stmt->setUInt32(4, 1);
                        stmt->setString(5, dump);
                        LoginDatabase.Execute(stmt);
                    }
                    CharacterDatabase.PQuery("UPDATE characters SET deleteInfos_Name = name, deleteInfos_Account = account, deleteDate = UNIX_TIMESTAMP(), name = '', account = 0, `transfer` = '%u' WHERE guid = %u", player->GetTransferId(), guid);

                    if(player->GetGUIDLow() == guid)
                        player->GetSession()->KickPlayer();
                }
                break;
            }
        }
        player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
        return true;
    }
};

float const rate[91]
{
    0, // 0
    0.5, // 1
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5,
    0.5, // 20
    1, // 21
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1, // 30
    1.5, // 31
    1.5,
    1.5,
    1.5,
    1.5,
    1.5,
    1.5,
    1.5,
    1.5,
    1.5, // 40
    2, // 41
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2, // 50
    2.5, // 51
    2.5,
    2.5,
    2.5,
    2.5,
    2.5,
    2.5,
    2.5,
    2.5,
    2.5, // 60
    3, // 61
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3, // 70
    5, // 71
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5,
    5, // 80
    10, // 81
    10,
    10,
    10,
    10, // 85
    20, // 86
    20,
    20,
    20, // 89
    25, // 90
};

class char_levelup : public CreatureScript
{
public:
    char_levelup() : CreatureScript("char_levelup"){}

    bool OnGossipHello(Player* player, Creature* creature)
    { 
        LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
        if (player->getLevel() != 90)
            player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityString(30100, loc_idx), GOSSIP_SENDER_MAIN, 3003, "", 1, true); // level
        
        player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityString(30104, loc_idx), GOSSIP_SENDER_MAIN, 3004, "", 0, true); // calculate
        player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(30101, loc_idx), GOSSIP_SENDER_MAIN, 3000); // price
        player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(30102, loc_idx), GOSSIP_SENDER_MAIN, 3001); // exit
        player->SEND_GOSSIP_MENU(100004, creature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        if(!player || !creature || !player->getAttackers().empty())
            return true;
        
        LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();

        player->PlayerTalkClass->ClearMenus();
        ChatHandler chH = ChatHandler(player);
        
        if (action == 3001)
        {
            player->CLOSE_GOSSIP_MENU();
            return true;
        }
        
        if (action == 3000)
        {
            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(30103, loc_idx), GOSSIP_SENDER_MAIN, 3002); // back
            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(30102, loc_idx), GOSSIP_SENDER_MAIN, 3001); // exit
            player->SEND_GOSSIP_MENU(100005, creature->GetGUID());
            return true;
        }
        
        if (action == 3002) // start
        {
            if (player->getLevel() != 90)
                player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityString(30100, loc_idx), GOSSIP_SENDER_MAIN, 3003, "", 0, true); // level
            
            player->ADD_GOSSIP_ITEM_EXTENDED(GOSSIP_ICON_CHAT, sObjectMgr->GetTrinityString(30104, loc_idx), GOSSIP_SENDER_MAIN, 3004, "", 0, true); // calculate
            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(30101, loc_idx), GOSSIP_SENDER_MAIN, 3000); // price
            player->ADD_GOSSIP_ITEM(0, sObjectMgr->GetTrinityString(30102, loc_idx), GOSSIP_SENDER_MAIN, 3001); // exit
            player->SEND_GOSSIP_MENU(100004, creature->GetGUID());
            return true;
        }
            
        return true;
    }
    
    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code)
    {
        LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
        player->PlayerTalkClass->ClearMenus();
        ChatHandler chH = ChatHandler(player);
        
        if (action == 3003 || action == 3004)
        {           
            ChatHandler chH = ChatHandler(player);
            
            if (!code)
            {
                player->CLOSE_GOSSIP_MENU();
                return false;
            }
            
            float efir;
            efir = 0;
            uint32 ucode = atof(code);
            if (!ucode)
            {
                player->CLOSE_GOSSIP_MENU();
                return false;
            }
            uint32 level = player->getLevel();
            
            if (ucode > 90 || ucode <= level)
            {
                player->CLOSE_GOSSIP_MENU();
                return false;
            }
            
            for (uint32 i = level+1; i <= ucode; i++)
                efir += rate[i];
            
            float efirend = ceil(efir);
            uint32 efirendu = uint32(efirend);
            if (action == 3004)
                chH.PSendSysMessage(30105, ucode, efirendu);
            else if (action == 3003)
            {
                if (player->GetItemCount(EFIRALS, false >= efirendu))
                {
                    player->DestroyItemCount(EFIRALS, efirendu, true);
                    player->GiveLevel(ucode);
                }
            }
        }
        player->CLOSE_GOSSIP_MENU();
        return false;        
    }
};

// 220030
class many_in_one_donate : public CreatureScript
{
    public:
        many_in_one_donate() : CreatureScript("many_in_one_donate") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Табарды", GOSSIP_SENDER_MAIN, 220026);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Оружие", GOSSIP_SENDER_MAIN, 220013);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Осада Оргриммара (566 ilvl)", GOSSIP_SENDER_MAIN, 220012);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Осада Оргриммара (572 ilvl) #1", GOSSIP_SENDER_MAIN, 220021);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Осада Оргриммара (572 ilvl) #2", GOSSIP_SENDER_MAIN, 220023);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Тир 15-16", GOSSIP_SENDER_MAIN, 220015);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "PvP 15 сезон 550 ilvl (офф)", GOSSIP_SENDER_MAIN, 220017);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "PvP 15 сезон 550 ilvl ", GOSSIP_SENDER_MAIN, 220018);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Ювелирные изделия", GOSSIP_SENDER_MAIN, 220014);           

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            player->GetSession()->SendListInventory(creature->GetGUID(), action);
            player->CustomMultiDonate = action;
            return true;
        }
};

// 220031
class many_in_one_donate_trans : public CreatureScript
{
    public:
        many_in_one_donate_trans() : CreatureScript("many_in_one_donate_trans") { }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Верховые животные #1", GOSSIP_SENDER_MAIN, 220016);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Верховые животные #2", GOSSIP_SENDER_MAIN, 220025);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Спутники", GOSSIP_SENDER_MAIN, 200204);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Рисовки и раритетные вещи", GOSSIP_SENDER_MAIN, 200203);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Накидки и рубашки с аурами", GOSSIP_SENDER_MAIN, 200205);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Вещи на трансмогрификацию", GOSSIP_SENDER_MAIN, 1);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Легендарные камни", GOSSIP_SENDER_MAIN, 250116);
            

            player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            switch(action)
            {
                case 1:
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Т1", GOSSIP_SENDER_MAIN, 220182);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Т2", GOSSIP_SENDER_MAIN, 220183);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Т3", GOSSIP_SENDER_MAIN, 220184);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Т4", GOSSIP_SENDER_MAIN, 220185);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Т5", GOSSIP_SENDER_MAIN, 220186);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Т6", GOSSIP_SENDER_MAIN, 220187);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "а1", GOSSIP_SENDER_MAIN, 220188);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "а2", GOSSIP_SENDER_MAIN, 220189);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "а3", GOSSIP_SENDER_MAIN, 220190);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "а4", GOSSIP_SENDER_MAIN, 220191);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Ткань", GOSSIP_SENDER_MAIN, 250112);            
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Кожа", GOSSIP_SENDER_MAIN, 250111);            
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Кольчуга", GOSSIP_SENDER_MAIN, 250113);            
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Латы", GOSSIP_SENDER_MAIN, 250110);            
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Оружие", GOSSIP_SENDER_MAIN, 250114);            
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Плащи", GOSSIP_SENDER_MAIN, 250115); 
                    
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_MONEY_BAG, "Трансмогрификация (испытания в подземельях. золото)", GOSSIP_SENDER_MAIN, 220024);            
                    player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                    break;    
                default:
                    player->GetSession()->SendListInventory(creature->GetGUID(), action);
                    player->CustomMultiDonate = action;
                    break;
            }
            return true;
        }
};

void AddSC_multi_vendor()
{
    new multi_vendor();
    new item_back();
    new char_transfer();
    new char_levelup();
    
    new many_in_one_donate();
    new many_in_one_donate_trans();
}
