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

#include "Common.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "AuctionHouseMgr.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "Config.h"
#include <vector>
#include "CustomLogs.h"

enum eAuctionHouse
{
    AH_MINIMUM_DEPOSIT = 100
};

AuctionQueryContext::~AuctionQueryContext()
{
    if (Player* player = ObjectAccessor::FindPlayerInOrOutOfWorld(playerGuid))
    {
        TRINITY_WRITE_GUARD(ACE_RW_Thread_Mutex, player->m_activeAuctionQueriesLock);
        player->m_activeAuctionQueries.erase(this);
    }
}

int AuctionQueryContext::call()
{
    AuctionHouseObject* auctionHouse = sAuctionMgr->GetAuctionsMap(auctioneerFaction);
    if (!auctionHouse)
        return 0;

    Player* player = ObjectAccessor::FindPlayer(playerGuid);
    if (!player)
        return 0;

    WorldPacket data(SMSG_AUCTION_LIST_RESULT, 1024 * 1024);
    uint32 count = 0;
    uint32 totalcount = 0;
    uint32 throttle = 300;
    data << uint32(0);

    if (auctionHouse->BuildListAuctionItems(data, nullptr, playerGuid, loc_idx, locdbc_idx,
        searchedname, listfrom, levelmin, levelmax, false,
        inventoryType, itemClass, itemSubClass, quality, getAll, sortOrder,
        count, totalcount, throttle))
    {
        data.put<uint32>(0, count);
        data << uint32(totalcount);
        data << uint32(throttle); // g_auctionThrottle, msecs to pass before a new query is allowed
        player->SendDirectMessage(&data);

        return 1;
    }

    return 0;
}

AuctionHouseMgr::AuctionHouseMgr()
{
    std::stringstream dir, path;
    path << sConfigMgr->GetStringDefault("LogsDir", "") << "/auction.log";

    logger.reset(new LogFile());
    logger->Open(path.str().c_str(), "a");

    searchThread = std::thread([this]()
    {
        while (true)
        {
            ACE_Method_Request* request = searchQueries.dequeue();
            if (!request)
                break;

            request->call();
            delete request;
        }
    });
}

AuctionHouseMgr::~AuctionHouseMgr()
{
    for (ItemMap::iterator itr = mAitems.begin(); itr != mAitems.end(); ++itr)
        delete itr->second;
}

void AuctionHouseMgr::Unload()
{
    searchQueries.queue()->close();
    if (searchThread.joinable())
        searchThread.join();
}

AuctionHouseObject* AuctionHouseMgr::GetAuctionsMap(uint32 factionTemplateId)
{
    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION))
        return &mNeutralAuctions;

    // teams have linked auction houses
    FactionTemplateEntry const* uEntry = sFactionTemplateStore.LookupEntry(factionTemplateId);
    if (!uEntry)
        return &mNeutralAuctions;
    else if (uEntry->ourMask & FACTION_MASK_ALLIANCE)
        return &mAllianceAuctions;
    else if (uEntry->ourMask & FACTION_MASK_HORDE)
        return &mHordeAuctions;
    else
        return &mNeutralAuctions;
}

uint32 AuctionHouseMgr::GetAuctionDeposit(AuctionHouseEntry const* entry, uint32 time, Item* pItem, uint32 count)
{
    uint32 MSV = pItem->GetTemplate()->SellPrice;

    if (MSV <= 0)
        return AH_MINIMUM_DEPOSIT;

    float multiplier = CalculatePct(float(entry->depositPercent), 3);
    uint32 timeHr = (((time / 60) / 60) / 12);
    uint32 deposit = uint32(((multiplier * MSV * count / 3) * timeHr * 3) * sWorld->getRate(RATE_AUCTION_DEPOSIT));

    TC_LOG_DEBUG("auctionHouse", "MSV:        %u", MSV);
    TC_LOG_DEBUG("auctionHouse", "Items:      %u", count);
    TC_LOG_DEBUG("auctionHouse", "Multiplier: %f", multiplier);
    TC_LOG_DEBUG("auctionHouse", "Deposit:    %u", deposit);

    if (deposit < AH_MINIMUM_DEPOSIT)
        return AH_MINIMUM_DEPOSIT;
    else
        return deposit;
}

//does not clear ram
void AuctionHouseMgr::SendAuctionWonMail(AuctionEntry* auction, SQLTransaction& trans)
{
    Item* pItem = GetAItem(auction->itemGUIDLow);
    if (!pItem)
        return;

    uint32 bidderAccId = 0;
    uint64 bidderGuid = MAKE_NEW_GUID(auction->bidder, 0, HIGHGUID_PLAYER);
    Player* bidder = ObjectAccessor::FindPlayer(bidderGuid);
    // data for gm.log
    std::string bidderName;
    bool logGmTrade = false;

    if (bidder)
    {
        bidderAccId = bidder->GetSession()->GetAccountId();
        bidderName = bidder->GetName();
        logGmTrade = bidder->GetSession()->GetSecurity() >= SEC_MODERATOR;
    }
    else
    {
        bidderAccId = sObjectMgr->GetPlayerAccountIdByGUID(bidderGuid);
        logGmTrade = AccountMgr::GetSecurity(bidderAccId, realmID) >= SEC_MODERATOR;

        if (logGmTrade && !sObjectMgr->GetPlayerNameByGUID(bidderGuid, bidderName))
            bidderName = sObjectMgr->GetTrinityStringForDBCLocale(LANG_UNKNOWN);
    }

    if (logGmTrade)
    {
        std::string ownerName;
        if (!sObjectMgr->GetPlayerNameByGUID(auction->owner, ownerName))
            ownerName = sObjectMgr->GetTrinityStringForDBCLocale(LANG_UNKNOWN);

        uint32 ownerAccId = sObjectMgr->GetPlayerAccountIdByGUID(auction->owner);

        sLog->outCommand(bidderAccId, "GM %s (Account: %u) won item in auction: %s (Entry: %u Count: %u) and pay money: %u. Original owner %s (Account: %u)",
            bidderName.c_str(), bidderAccId, pItem->GetTemplate()->Name1.c_str(), pItem->GetEntry(), pItem->GetCount(), auction->bid, ownerName.c_str(), ownerAccId);
    }

    // receiver exist
    if (bidder || bidderAccId)
    {
        // set owner to bidder (to prevent delete item with sender char deleting)
        // owner in `data` will set at mail receive and item extracting
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_ITEM_OWNER);
        stmt->setUInt32(0, auction->bidder);
        stmt->setUInt32(1, pItem->GetGUIDLow());
        trans->Append(stmt);

        if (bidder)
        {
            bidder->GetSession()->SendAuctionBidderNotification(auction->GetHouseId(), auction->Id, bidderGuid, 0, 0, auction->itemEntry);
            // FIXME: for offline player need also
            bidder->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_WON_AUCTIONS, 1);
        }

        MailDraft(auction->BuildAuctionMailSubject(AUCTION_WON), auction->BuildAuctionMailBody(AUCTION_WON))
            .AddItem(pItem)
            .SendMailTo(trans, MailReceiver(bidder, auction->bidder), auction, MAIL_CHECK_MASK_COPIED);
    }
}

void AuctionHouseMgr::SendAuctionSalePendingMail(AuctionEntry* auction, SQLTransaction& trans)
{
    uint64 owner_guid = MAKE_NEW_GUID(auction->owner, 0, HIGHGUID_PLAYER);
    Player* owner = ObjectAccessor::FindPlayer(owner_guid);
    uint32 owner_accId = sObjectMgr->GetPlayerAccountIdByGUID(owner_guid);
    // owner exist (online or offline)
    if (owner || owner_accId)
        MailDraft(auction->BuildAuctionMailSubject(AUCTION_SALE_PENDING), auction->BuildAuctionMailBody(AUCTION_SALE_PENDING))
            .SendMailTo(trans, MailReceiver(owner, auction->owner), auction, MAIL_CHECK_MASK_COPIED);
}

//call this method to send mail to auction owner, when auction is successful, it does not clear ram
void AuctionHouseMgr::SendAuctionSuccessfulMail(AuctionEntry* auction, SQLTransaction& trans)
{
    uint64 owner_guid = MAKE_NEW_GUID(auction->owner, 0, HIGHGUID_PLAYER);
    Player* owner = ObjectAccessor::FindPlayer(owner_guid);
    uint32 owner_accId = sObjectMgr->GetPlayerAccountIdByGUID(owner_guid);
    // owner exist
    if (owner || owner_accId)
    {
        uint32 profit = auction->bid + auction->deposit - auction->GetAuctionCut();

        //FIXME: what do if owner offline
        if (owner)
        {
            owner->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS, profit);
            owner->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_HIGHEST_AUCTION_SOLD, auction->bid);
            //send auction owner notification, bidder must be current!
            owner->GetSession()->SendAuctionOwnerNotification(auction);
        }

        MailDraft(auction->BuildAuctionMailSubject(AUCTION_SUCCESSFUL), auction->BuildAuctionMailBody(AUCTION_SUCCESSFUL))
            .AddMoney(profit)
            .SendMailTo(trans, MailReceiver(owner, auction->owner), auction, MAIL_CHECK_MASK_COPIED, sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY));
    }
}

//does not clear ram
void AuctionHouseMgr::SendAuctionExpiredMail(AuctionEntry* auction, SQLTransaction& trans)
{
    //return an item in auction to its owner by mail
    Item* pItem = GetAItem(auction->itemGUIDLow);
    if (!pItem)
        return;

    uint64 owner_guid = MAKE_NEW_GUID(auction->owner, 0, HIGHGUID_PLAYER);
    Player* owner = ObjectAccessor::FindPlayer(owner_guid);
    uint32 owner_accId = sObjectMgr->GetPlayerAccountIdByGUID(owner_guid);
    // owner exist
    if (owner || owner_accId)
    {
        if (owner)
            owner->GetSession()->SendAuctionOwnerNotification(auction);

        MailDraft(auction->BuildAuctionMailSubject(AUCTION_EXPIRED), auction->BuildAuctionMailBody(AUCTION_EXPIRED))
            .AddItem(pItem)
            .SendMailTo(trans, MailReceiver(owner, auction->owner), auction, MAIL_CHECK_MASK_COPIED, 0);
    }
}

//this function sends mail to old bidder
void AuctionHouseMgr::SendAuctionOutbiddedMail(AuctionEntry* auction, uint32 newPrice, Player* newBidder, SQLTransaction& trans)
{
    uint64 oldBidder_guid = MAKE_NEW_GUID(auction->bidder, 0, HIGHGUID_PLAYER);
    Player* oldBidder = ObjectAccessor::FindPlayer(oldBidder_guid);

    uint32 oldBidder_accId = 0;
    if (!oldBidder)
        oldBidder_accId = sObjectMgr->GetPlayerAccountIdByGUID(oldBidder_guid);

    // old bidder exist
    if (oldBidder || oldBidder_accId)
    {
        if (oldBidder && newBidder)
            oldBidder->GetSession()->SendAuctionBidderNotification(auction->GetHouseId(), auction->Id, newBidder->GetGUID(), newPrice, auction->GetAuctionOutBid(), auction->itemEntry);

        MailDraft(auction->BuildAuctionMailSubject(AUCTION_OUTBIDDED), auction->BuildAuctionMailBody(AUCTION_OUTBIDDED))
            .AddMoney(auction->bid)
            .SendMailTo(trans, MailReceiver(oldBidder, auction->bidder), auction, MAIL_CHECK_MASK_COPIED);
    }
}

//this function sends mail, when auction is cancelled to old bidder
void AuctionHouseMgr::SendAuctionCancelledToBidderMail(AuctionEntry* auction, SQLTransaction& trans, Item* item)
{
    uint64 bidder_guid = MAKE_NEW_GUID(auction->bidder, 0, HIGHGUID_PLAYER);
    Player* bidder = ObjectAccessor::FindPlayer(bidder_guid);

    uint32 bidder_accId = 0;
    if (!bidder)
        bidder_accId = sObjectMgr->GetPlayerAccountIdByGUID(bidder_guid);

    if (bidder)
        bidder->GetSession()->SendAuctionRemovedNotification(auction->Id, auction->itemEntry, item->GetItemRandomPropertyId());

    // bidder exist
    if (bidder || bidder_accId)
        MailDraft(auction->BuildAuctionMailSubject(AUCTION_CANCELLED_TO_BIDDER), auction->BuildAuctionMailBody(AUCTION_CANCELLED_TO_BIDDER))
            .AddMoney(auction->bid)
            .SendMailTo(trans, MailReceiver(bidder, auction->bidder), auction, MAIL_CHECK_MASK_COPIED);
}

void AuctionHouseMgr::LoadAuctionItems()
{
    uint32 oldMSTime = getMSTime();

    // need to clear in case we are reloading
    if (!mAitems.empty())
    {
        for (ItemMap::iterator itr = mAitems.begin(); itr != mAitems.end(); ++itr)
            delete itr->second;

        mAitems.clear();
    }

    // data needs to be at first place for Item::LoadFromDB
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AUCTION_ITEMS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 auction items. DB table `auctionhouse` or `item_instance` is empty!");

        return;
    }

    uint32 count = 0;

    do
    {
        Field* fields = result->Fetch();

        uint32 item_guid    = fields[18].GetUInt32();
        uint32 itemEntry    = fields[19].GetUInt32();

        ItemTemplate const* proto = sObjectMgr->GetItemTemplate(itemEntry);
        if (!proto)
        {
            TC_LOG_ERROR("misc", "AuctionHouseMgr::LoadAuctionItems: Unknown item (GUID: %u id: #%u) in auction, skipped.", item_guid, itemEntry);
            continue;
        }

        Item* item = NewItemOrBag(proto);
        if (!item->LoadFromDB(item_guid, 0, fields, itemEntry))
        {
            delete item;
            continue;
        }
        AddAItem(item);

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u auction items in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

}

void AuctionHouseMgr::LoadAuctions()
{
    uint32 oldMSTime = getMSTime();

    uint32 expirecount = 0;
    time_t curTime = sWorld->GetGameTime() + 60;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AUCTIONS);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 auctions. DB table `auctionhouse` is empty.");

        return;
    }

    uint32 count = 0;

    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    do
    {
        Field* fields = result->Fetch();

        AuctionEntry* aItem = new AuctionEntry();
        if (!aItem->LoadFromDB(fields))
        {
            aItem->DeleteFromDB(trans);
            delete aItem;
            continue;
        }

        if (aItem->expire_time > curTime)   // auction is still active
        {
            GetAuctionsMap(aItem->factionTemplateId)->AddAuction(aItem);
            ++count;
        }
        else    // no, delete expired
        {
            SQLTransaction eTrans = CharacterDatabase.BeginTransaction();
            if (aItem->bidder == 0)
            {
                // Cancel the auction, there was no bidder
                sAuctionMgr->SendAuctionExpiredMail(aItem, eTrans);
            }
            else
            {
                // Send the item to the winner and money to seller
                sAuctionMgr->SendAuctionSuccessfulMail(aItem, eTrans);
                sAuctionMgr->SendAuctionWonMail(aItem, eTrans);
            }

            // Delete the auction from the DB
            aItem->DeleteFromDB(eTrans);
            CharacterDatabase.CommitTransaction(eTrans);

            sAuctionMgr->RemoveAItem(aItem->itemGUIDLow);

            // Release memory
            delete aItem;
            ++expirecount;
        }
    } while (result->NextRow());

    CharacterDatabase.CommitTransaction(trans);

    TC_LOG_INFO("server.loading", ">> Loaded %u auctions (and %u deleted as expired) in %u ms", count, expirecount, GetMSTimeDiffToNow(oldMSTime));
}

void AuctionHouseMgr::AddAItem(Item* it)
{
    TRINITY_WRITE_GUARD(ACE_RW_Thread_Mutex, mAitemsLock);

    ASSERT(it);
    ASSERT(mAitems.find(it->GetGUIDLow()) == mAitems.end());
    mAitems[it->GetGUIDLow()] = it;
}

bool AuctionHouseMgr::RemoveAItem(uint32 id)
{
    TRINITY_WRITE_GUARD(ACE_RW_Thread_Mutex, mAitemsLock);

    ItemMap::iterator i = mAitems.find(id);
    if (i == mAitems.end())
        return false;

    mAitems.erase(i);
    return true;
}

void AuctionHouseMgr::Update()
{
    mHordeAuctions.Update();
    mAllianceAuctions.Update();
    mNeutralAuctions.Update();
}

// Taken from AuctionSortToColumnIndex
enum AuctionSortColumnIndex
{
    SORT_COLUMN_LEVEL = 0,
    SORT_COLUMN_QUALITY = 1,
    SORT_COLUMN_BUYOUTTHENBID = 2,
    SORT_COLUMN_DURATION = 3,
    SORT_COLUMN_STATUS = 4,
    SORT_COLUMN_NAME = 5,
    SORT_COLUMN_MINBIDBUYOUT = 6,
    SORT_COLUMN_SELLER = 7,
    SORT_COLUMN_BID = 8,
    SORT_COLUMN_QUANTITY = 9,
    SORT_COLUMN_BUYOUT = 10,
};

struct AuctionEntryForSorting
{
    AuctionEntry* Entry;
    ItemTemplate const* Template;
    std::wstring const* Name;       // Don't delete, pooled in AuctionHouseObject::BuildListAuctionItems
    std::string const* Owner;       // Don't delete, points to storage in sWorld
    uint32 Bid;

    AuctionEntryForSorting(AuctionEntry* entry, ItemTemplate const* proto, std::wstring const* name, std::string const* owner)
        : Entry(entry), Template(proto), Name(name), Owner(owner), Bid(entry->bid ? entry->bid : entry->startbid) { }
};

template<class T> inline int32 AuctionCompare(bool reverse, T const& a, T const& b) { return a == b ? 0 : (a < b) ^ reverse ? -1 : 1; }
template<> inline int32 AuctionCompare<std::string const*>(bool reverse, std::string const* const& a, std::string const* const& b) { int32 comp = a->compare(*b); return reverse ? -comp : comp; }
template<> inline int32 AuctionCompare<std::wstring const*>(bool reverse, std::wstring const* const& a, std::wstring const* const& b) { int32 comp = a->compare(*b); return reverse ? -comp : comp; }
template<class T> inline int32 AuctionCompare(bool reverse, T const& a1, T const& b1, T const& a2, T const& b2) { return a1 != b1 ? AuctionCompare(reverse, a1, b1) : AuctionCompare(reverse, a2, b2); }

void AuctionHouseMgr::QueryAuctionItems(uint32 auctioneerFaction, Player* player,
    std::string const& searchedname, uint32 listfrom, uint8 levelmin, uint8 levelmax, uint8 usable,
    uint32 inventoryType, uint32 itemClass, uint32 itemSubClass, uint32 quality,
    bool getAll, std::vector<int8> const& sortOrder)
{
    if (usable || sWorld->getBoolConfig(CONFIG_AUCTIONHOUSE_FORCE_MAIN_THREAD))
    {
        // Execute "Usable Items" queries in main thread to prevent access to invalid Player*
        AuctionHouseObject* auctionHouse = GetAuctionsMap(auctioneerFaction);
        if (!auctionHouse)
            return;

        WorldPacket data(SMSG_AUCTION_LIST_RESULT, 1024 * 1024);
        uint32 count = 0;
        uint32 totalcount = 0;
        uint32 throttle = 300;
        data << uint32(0);

        if (auctionHouse->BuildListAuctionItems(data, player, player->GetGUID(), player->GetSession()->GetSessionDbLocaleIndex(), player->GetSession()->GetSessionDbcLocale(),
            searchedname, listfrom, levelmin, levelmax, usable,
            inventoryType, itemClass, itemSubClass, quality, getAll, sortOrder,
            count, totalcount, throttle))
        {
            data.put<uint32>(0, count);
            data << uint32(totalcount);
            data << uint32(throttle); // g_auctionThrottle, msecs to pass before a new query is allowed
            player->SendDirectMessage(&data);
        }
    }
    else
    {
        // Execute other queries in a dedicated thread
        AuctionQueryContext* context = new AuctionQueryContext();
        context->auctioneerFaction = auctioneerFaction;
        context->playerGuid = player->GetGUID();
        context->loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
        context->locdbc_idx = player->GetSession()->GetSessionDbcLocale();
        context->searchedname = searchedname;
        context->listfrom = listfrom;
        context->levelmin = levelmin;
        context->levelmax = levelmax;
        context->inventoryType = inventoryType;
        context->itemClass = itemClass;
        context->itemSubClass = itemSubClass;
        context->quality = quality;
        context->getAll = getAll;
        context->sortOrder = sortOrder;

        {
            TRINITY_WRITE_GUARD(ACE_RW_Thread_Mutex, player->m_activeAuctionQueriesLock);
            player->m_activeAuctionQueries.insert(context);
        }
        searchQueries.enqueue(context);
    }
}

AuctionHouseEntry const* AuctionHouseMgr::GetAuctionHouseEntry(uint32 factionTemplateId, bool forClient)
{
    uint32 houseid = 7; // goblin auction house

    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION) || forClient)
    {
        // FIXME: found way for proper auctionhouse selection by another way
        // AuctionHouse.dbc have faction field with _player_ factions associated with auction house races.
        // but no easy way convert creature faction to player race faction for specific city
        switch (factionTemplateId)
        {
            case 12:   houseid = 1; break; // human
            case 29:   houseid = 6; break; // orc, and generic for horde
            case 55:   houseid = 2; break; // dwarf, and generic for alliance
            case 68:   houseid = 4; break; // undead
            case 80:   houseid = 3; break; // n-elf
            case 104:  houseid = 5; break; // trolls
            case 120:  houseid = 7; break; // booty bay, neutral
            case 474:  houseid = 7; break; // gadgetzan, neutral
            case 855:  houseid = 7; break; // everlook, neutral
            case 1604: houseid = 6; break; // b-elfs,
            default:                       // for unknown case
            {
                FactionTemplateEntry const* u_entry = sFactionTemplateStore.LookupEntry(factionTemplateId);
                if (!u_entry)
                    houseid = 7; // goblin auction house
                else if (u_entry->ourMask & FACTION_MASK_ALLIANCE)
                    houseid = 1; // human auction house
                else if (u_entry->ourMask & FACTION_MASK_HORDE)
                    houseid = 6; // orc auction house
                else
                    houseid = 7; // goblin auction house
                break;
            }
        }
    }

    return sAuctionHouseStore.LookupEntry(houseid);
}

void AuctionHouseObject::AddAuction(AuctionEntry* auction, bool skipLock)
{
    if (!skipLock)
        AuctionsMapLock.acquire_write();

    ASSERT(auction);

    AuctionsMap[auction->Id] = auction;
    sScriptMgr->OnAuctionAdd(this, auction);

    if (!skipLock)
        AuctionsMapLock.release();
}

bool AuctionHouseObject::RemoveAuction(AuctionEntry* auction, uint32 /*itemEntry*/, bool skipLock)
{
    if (!skipLock)
        AuctionsMapLock.acquire_write();

    bool wasInMap = AuctionsMap.erase(auction->Id) ? true : false;

    sScriptMgr->OnAuctionRemove(this, auction);

    // we need to delete the entry, it is not referenced any more
    delete auction;
    auction = NULL;

    if (!skipLock)
        AuctionsMapLock.release();

    return wasInMap;
}

void AuctionHouseObject::Update()
{
    TRINITY_WRITE_GUARD(ACE_RW_Thread_Mutex, AuctionsMapLock);

    time_t curTime = sWorld->GetGameTime();
    ///- Handle expired auctions

    // If storage is empty, no need to update. next == NULL in this case.
    if (AuctionsMap.empty())
        return;

    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_AUCTION_BY_TIME);
    stmt->setUInt32(0, (uint32)curTime+60);
    PreparedQueryResult result = CharacterDatabase.Query(stmt);

    if (!result)
        return;

    do
    {
        // from auctionhousehandler.cpp, creates auction pointer & player pointer
        AuctionEntry* auction = GetAuction(result->Fetch()->GetUInt32(), true);

        if (!auction)
            continue;

        SQLTransaction trans = CharacterDatabase.BeginTransaction();

        ///- Either cancel the auction if there was no bidder
        if (auction->bidder == 0)
        {
            sAuctionMgr->SendAuctionExpiredMail(auction, trans);
            sScriptMgr->OnAuctionExpire(this, auction);
        }
        ///- Or perform the transaction
        else
        {
            //we should send an "item sold" message if the seller is online
            //we send the item to the winner
            //we send the money to the seller
            sAuctionMgr->SendAuctionSuccessfulMail(auction, trans);
            sAuctionMgr->SendAuctionWonMail(auction, trans);
            sScriptMgr->OnAuctionSuccessful(this, auction);
        }

        uint32 itemEntry = auction->itemEntry;

        ///- In any case clear the auction
        auction->DeleteFromDB(trans);
        CharacterDatabase.CommitTransaction(trans);

        sAuctionMgr->RemoveAItem(auction->itemGUIDLow);
        RemoveAuction(auction, itemEntry, true);
    }
    while (result->NextRow());
}

void AuctionHouseObject::BuildListBidderItems(WorldPacket& data, Player* player, uint32& count, uint32& totalcount)
{
    TRINITY_READ_GUARD(ACE_RW_Thread_Mutex, AuctionsMapLock);

    for (AuctionEntryMap::const_iterator itr = AuctionsMap.begin(); itr != AuctionsMap.end(); ++itr)
    {
        AuctionEntry* Aentry = itr->second;
        if (Aentry && Aentry->bidder == player->GetGUIDLow())
        {
            if (itr->second->BuildAuctionInfo(data))
                ++count;

            ++totalcount;
        }
    }
}

void AuctionHouseObject::BuildListOwnerItems(WorldPacket& data, Player* player, uint32& count, uint32& totalcount)
{
    TRINITY_READ_GUARD(ACE_RW_Thread_Mutex, AuctionsMapLock);

    for (AuctionEntryMap::const_iterator itr = AuctionsMap.begin(); itr != AuctionsMap.end(); ++itr)
    {
        AuctionEntry* Aentry = itr->second;
        if (Aentry && Aentry->owner == player->GetGUIDLow())
        {
            if (Aentry->BuildAuctionInfo(data))
                ++count;

            ++totalcount;
        }
    }
}

bool AuctionHouseObject::BuildListAuctionItems(WorldPacket& data, Player* player, uint64 playerGuid, LocaleConstant loc_idx, LocaleConstant locdbc_idx,
    std::string const& searchedname, uint32 listfrom, uint8 levelmin, uint8 levelmax, uint8 usable,
    uint32 inventoryType, uint32 itemClass, uint32 itemSubClass, uint32 quality,
    bool getAll, std::vector<int8> const& sortOrder,
    uint32& count, uint32& totalcount, uint32& throttle)
{
    TRINITY_READ_GUARD(ACE_RW_Thread_Mutex, AuctionsMapLock);

    uint32 now = getMSTime();
    bool isExecutedInMainThread = usable || sWorld->getBoolConfig(CONFIG_AUCTIONHOUSE_FORCE_MAIN_THREAD);

    // converting string that we try to find to lower case
    std::wstring wsearchedname;
    if (!Utf8toWStr(searchedname, wsearchedname))
        return false;

    wstrToUpper(wsearchedname);

    std::vector<AuctionEntryForSorting*> matched;
    matched.reserve(AuctionsMap.size());

    bool hasNameSortOrder = false;
    bool hasOwnerSortOrder = false;
    for (auto&& order : sortOrder)
    {
        if (abs(order) - 1 == SORT_COLUMN_NAME)
            hasNameSortOrder = true;
        else if (abs(order) - 1 == SORT_COLUMN_SELLER)
            hasOwnerSortOrder = true;
    }

    AuctionHouseMgr* aucMgr = sAuctionMgr;
    ObjectMgr* objMgr = sObjectMgr;

    int cacheLock = -1;
    if (hasNameSortOrder || !wsearchedname.empty())
        cacheLock = ItemNameCacheLock.acquire_read();

    for (auto&& entry : AuctionsMap)
    {
        Item *item = aucMgr->GetAItem(entry.second->itemGUIDLow);
        if (!item)
            continue;

        ItemTemplate const *proto = objMgr->GetItemTemplate(item->GetEntry());

        if (itemClass != 0xffffffff && proto->Class != itemClass)
            continue;

        if (itemSubClass != 0xffffffff && proto->SubClass != itemSubClass)
            continue;

        if (inventoryType != 0xffffffff && (proto->InventoryType == INVTYPE_ROBE ? INVTYPE_CHEST : proto->InventoryType) != inventoryType)
            continue;

        if (quality != 0xffffffff && proto->Quality < quality)
            continue;

        if (levelmin != 0x00 && proto->RequiredLevel < levelmin)
            continue;

        if (levelmax != 0x00 && proto->RequiredLevel > levelmax)
            continue;

        if (usable != 0x00 && player && player->CanUseItem(item) != EQUIP_ERR_OK)
            continue;

        // Allow search by suffix (ie: of the Monkey) or partial name (ie: Monkey)
        std::wstring* wname = nullptr;
        // No need to do any of this if no search term was entered or no name sorting was selected
        if (hasNameSortOrder || !wsearchedname.empty())
        {
            int32 propRefID = item->GetItemRandomPropertyId();
            uint64 cacheEntry = uint64(proto->ItemId) | (uint64(uint32(propRefID)) << 32);
            auto itr = ItemNameCache[loc_idx].find(cacheEntry);
            if (itr == ItemNameCache[loc_idx].end())
            {
                std::string name = proto->Name1;
                if (name.empty())
                    continue;

                // local name
                if (loc_idx >= 0)
                    if (ItemLocale const *il = objMgr->GetItemLocale(proto->ItemId))
                        ObjectMgr::GetLocaleString(il->Name, loc_idx, name);

                // DO NOT use GetItemEnchantMod(proto->RandomProperty) as it may return a result
                //  that matches the search but it may not equal item->GetItemRandomPropertyId()
                //  used in BuildAuctionInfo() which then causes wrong items to be listed
                if (propRefID)
                {
                    // Append the suffix to the name (ie: of the Monkey) if one exists
                    DbcStr const* temp = nullptr;
                    if (propRefID < 0)
                    {
                        if (ItemRandomSuffixEntry const* itemRandProp = sItemRandomSuffixStore.LookupEntry(-propRefID))
                            temp = &itemRandProp->nameSuffix;
                    }
                    else if (ItemRandomPropertiesEntry const* itemRandProp = sItemRandomPropertiesStore.LookupEntry(propRefID))
                        temp = &itemRandProp->nameSuffix;

                    // dbc local name
                    if (temp)
                    {
                        if (locdbc_idx < 0)
                            locdbc_idx = LOCALE_enUS;

                        // Append the suffix (ie: of the Monkey) to the name using localization
                        name += " ";
                        name += (*temp)[locdbc_idx];
                    }
                }

                // Switch to write lock
                if (cacheLock != -1)
                    ItemNameCacheLock.release();
                cacheLock = ItemNameCacheLock.acquire_write();

                wname = &ItemNameCache[loc_idx][cacheEntry];

                // Switch back to read lock
                if (cacheLock != -1)
                    ItemNameCacheLock.release();
                cacheLock = ItemNameCacheLock.acquire_read();

                if (!Utf8toWStr(name, *wname))
                    ASSERT(false);

                wstrToUpper(*wname);
            }
            else
                wname = &itr->second;

            // Perform the search (with or without suffix)
            if (!wsearchedname.empty() && wname->find(wsearchedname) == std::wstring::npos)
                continue;
        }

        std::string const* owner = NULL;
        if (hasOwnerSortOrder)
            if (CharacterNameData const* charData = sWorld->GetCharacterNameData(entry.second->owner))
                owner = &charData->m_name;

        matched.push_back(new AuctionEntryForSorting(entry.second, proto, wname, owner));
    }

    if (cacheLock != -1)
        ItemNameCacheLock.release();

    totalcount = matched.size();

    if (!sortOrder.empty() && sWorld->getBoolConfig(CONFIG_AUCTIONHOUSE_ALLOW_SORTING))
    {
        std::sort(matched.begin(), matched.end(), [&playerGuid, &sortOrder](AuctionEntryForSorting* const& a, AuctionEntryForSorting* const& b)
        {
            for (auto&& order : sortOrder)
            {
                int32 result = 0;
                bool reverse = order < 0;
                switch ((AuctionSortColumnIndex)(abs(order) - 1))
                {
                    case SORT_COLUMN_LEVEL:         result = AuctionCompare(reverse, std::max(1u, a->Template->RequiredLevel), std::max(1u, b->Template->RequiredLevel)); break;
                    case SORT_COLUMN_QUALITY:       result = AuctionCompare(!reverse, a->Template->Quality, b->Template->Quality); break;
                    case SORT_COLUMN_BUYOUTTHENBID: result = AuctionCompare(reverse, a->Entry->buyout ? a->Entry->buyout : a->Bid, b->Entry->buyout ? b->Entry->buyout : b->Bid, a->Bid, b->Bid); break;
                    case SORT_COLUMN_DURATION:      result = AuctionCompare(reverse, a->Entry->expire_time, b->Entry->expire_time); break;
                    case SORT_COLUMN_STATUS:        result = AuctionCompare(!reverse, playerGuid == a->Entry->bidder ? 2 : a->Entry->buyout ? 1 : 0, playerGuid == b->Entry->bidder ? 2 : b->Entry->buyout ? 1 : 0); break;
                    case SORT_COLUMN_NAME:          result = AuctionCompare(reverse, a->Name, b->Name); break;
                    case SORT_COLUMN_MINBIDBUYOUT:  result = AuctionCompare(reverse, a->Entry->buyout ? a->Entry->buyout : a->Bid, b->Entry->buyout ? b->Entry->buyout : b->Bid); break;
                    case SORT_COLUMN_SELLER:        result = a->Owner && b->Owner ?
                        AuctionCompare(reverse, a->Owner, b->Owner) :
                        AuctionCompare(reverse, a->Entry->owner, b->Entry->owner); break;
                    case SORT_COLUMN_BID:           result = AuctionCompare(reverse, a->Bid, b->Bid); break;
                    case SORT_COLUMN_QUANTITY:      result = AuctionCompare(reverse, a->Entry->itemCount, b->Entry->itemCount); break;
                    case SORT_COLUMN_BUYOUT:        result = AuctionCompare(reverse, a->Entry->buyout, b->Entry->buyout); break;
                    default:                        result = 0; break;
                }

                if (result)
                    return result < 0;
            }
            return false;
        });
    }

    // Cut first [listfrom] elements out of the list
    if (listfrom)
    {
        if (matched.size() <= listfrom)
        {
            for (auto&& match : matched)
                delete match;

            matched.clear();
        }
        else
        {
            auto endItr = matched.begin() + listfrom;
            for (auto itr = matched.begin(); itr != endItr; ++itr)
                delete *itr;

            matched.erase(matched.begin(), endItr);
        }
    }

    // Erase all elements outside of current page
    if (!getAll && matched.size() > 50)
    {
        for (auto itr = matched.begin() + 50; itr != matched.end(); ++itr)
            delete *itr;

        matched.resize(50);
    }

    count = matched.size();

    for (auto&& match : matched)
    {
        match->Entry->BuildAuctionInfo(data);
        delete match;
    }

    throttle = usable ? 1500 : 300;

    uint32 diff = GetMSTimeDiffToNow(now);
    if (isExecutedInMainThread && diff >= sWorld->getIntConfig(CONFIG_AUCTIONHOUSE_MIN_DIFF_FOR_LOG))
    {
        std::stringstream ss;
        for (auto&& order : sortOrder)
            ss << int32(order) << ",";

        aucMgr->GetLogger()->Write("AuctionHouseObject::BuildListAuctionItems: Query took too long to execute (%u ms): player: %s (%u), wsearchedname: \"%s\", listfrom: %u, levelmin: %u, levelmax: %u, usable: %u, inventoryType: %d, itemClass: %d, itemSubClass: %d, quality: %d, getAll: %s, sortOrder: %s returned %u results out of %u",
            diff, player ? player->GetName().c_str() : "<optimized>", GUID_LOPART(playerGuid), searchedname.c_str(), listfrom, uint32(levelmin), uint32(levelmax), uint32(usable), inventoryType, itemClass, itemSubClass, quality, getAll ? "true" : "false", ss.str().c_str(), count, totalcount);
    }

    if (isExecutedInMainThread && diff >= sWorld->getIntConfig(CONFIG_AUCTIONHOUSE_MIN_DIFF_FOR_THROTTLE))
        throttle = usable ? 3000 : 1000;

    return true;
}

//this function inserts to WorldPacket auction's data
bool AuctionEntry::BuildAuctionInfo(WorldPacket& data) const
{
    Item* item = sAuctionMgr->GetAItem(itemGUIDLow);
    if (!item)
    {
        TC_LOG_ERROR("misc", "AuctionEntry::BuildAuctionInfo: Auction %u has a non-existent item: %u", Id, itemGUIDLow);
        return false;
    }
    data << uint32(Id);
    data << uint32(item->GetEntry());

    for (uint8 i = 0; i < PROP_ENCHANTMENT_SLOT_0; ++i) // PROP_ENCHANTMENT_SLOT_0 = 10
    {
        data << uint32(item->GetEnchantmentId(EnchantmentSlot(i)));
        data << uint32(item->GetEnchantmentDuration(EnchantmentSlot(i)));
        data << uint32(item->GetEnchantmentCharges(EnchantmentSlot(i)));
    }

    uint32 mask = item->GetUInt32Value(ITEM_FIELD_MODIFIERS_MASK);
    data << int32(mask);
    for (uint32 i = 0; i < ITEM_MODIFIER_INDEX_MAX; ++i)
        if (mask & (1 << i))
            data << item->GetDynamicUInt32Value(ITEM_DYNAMIC_MODIFIERS, i);

    data << int32(item->GetItemRandomPropertyId());                 // Random item property id
    data << uint32(item->GetItemSuffixFactor());                    // SuffixFactor
    data << uint32(item->GetCount());                               // item->count
    data << uint32(item->GetSpellCharges());                        // item->charge FFFFFFF
    data << uint32(0);                                              // Unknown
    data << uint64(owner);                                          // Auction->owner
    data << uint64(startbid);                                       // Auction->startbid (not sure if useful)
    data << uint64(bid ? GetAuctionOutBid() : 0);
    // Minimal outbid
    data << uint64(buyout);                                         // Auction->buyout
    data << uint32((expire_time - time(NULL)) * IN_MILLISECONDS);   // time left
    data << uint64(bidder);                                         // auction->bidder current
    data << uint64(bid);                                            // current bid
    return true;
}

uint32 AuctionEntry::GetAuctionCut() const
{
    uint32 pct = auctionHouseEntry->cutPercent;
    if (sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_AUCTION))
        pct = 5;
    int32 cut = int32(CalculatePct(bid, pct) * sWorld->getRate(RATE_AUCTION_CUT));
    return std::max(cut, 0);
}

/// the sum of outbid is (1% from current bid)*5, if bid is very small, it is 1c
uint32 AuctionEntry::GetAuctionOutBid() const
{
    uint32 outbid = CalculatePct(bid, 5);
    return outbid ? outbid : 1;
}

void AuctionEntry::DeleteFromDB(SQLTransaction& trans) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_AUCTION);
    stmt->setUInt32(0, Id);
    trans->Append(stmt);
}

void AuctionEntry::SaveToDB(SQLTransaction& trans) const
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_AUCTION);
    stmt->setUInt32(0, Id);
    stmt->setUInt32(1, auctioneer);
    stmt->setUInt32(2, itemGUIDLow);
    stmt->setUInt32(3, owner);
    stmt->setUInt32(4, buyout);
    stmt->setUInt32(5, uint32(expire_time));
    stmt->setUInt32(6, bidder);
    stmt->setUInt32(7, bid);
    stmt->setUInt32(8, startbid);
    stmt->setUInt32(9, deposit);
    trans->Append(stmt);
}

bool AuctionEntry::LoadFromDB(Field* fields)
{
    Id = fields[0].GetUInt32();
    auctioneer = fields[1].GetUInt32();
    itemGUIDLow = fields[2].GetUInt32();
    itemEntry = fields[3].GetUInt32();
    itemCount = fields[4].GetUInt32();
    owner = fields[5].GetUInt32();
    buyout = fields[6].GetUInt32();
    expire_time = fields[7].GetUInt32();
    bidder = fields[8].GetUInt32();
    bid = fields[9].GetUInt32();
    startbid = fields[10].GetUInt32();
    deposit = fields[11].GetUInt32();

    CreatureData const* auctioneerData = sObjectMgr->GetCreatureData(auctioneer);
    if (!auctioneerData)
    {
        TC_LOG_ERROR("misc", "Auction %u has not a existing auctioneer (GUID : %u)", Id, auctioneer);
        return false;
    }

    CreatureTemplate const* auctioneerInfo = sObjectMgr->GetCreatureTemplate(auctioneerData->id);
    if (!auctioneerInfo)
    {
        TC_LOG_ERROR("misc", "Auction %u has not a existing auctioneer (GUID : %u Entry: %u)", Id, auctioneer, auctioneerData->id);
        return false;
    }

    factionTemplateId = auctioneerInfo->faction_A;
    auctionHouseEntry = AuctionHouseMgr::GetAuctionHouseEntry(factionTemplateId);
    if (!auctionHouseEntry)
    {
        TC_LOG_ERROR("misc", "Auction %u has auctioneer (GUID : %u Entry: %u) with wrong faction %u", Id, auctioneer, auctioneerData->id, factionTemplateId);
        return false;
    }

    // check if sold item exists for guid
    // and itemEntry in fact (GetAItem will fail if problematic in result check in AuctionHouseMgr::LoadAuctionItems)
    if (!sAuctionMgr->GetAItem(itemGUIDLow))
    {
        TC_LOG_ERROR("misc", "Auction %u has not a existing item : %u", Id, itemGUIDLow);
        return false;
    }
    return true;
}

void AuctionHouseMgr::DeleteExpiredAuctionsAtStartup()
{
    // Deletes expired auctions. Should be called at server start before loading auctions.

    // DO NOT USE after auctions are already loaded since this deletes from the DB
    //  and assumes the auctions HAVE NOT been loaded into a list or AuctionEntryMap yet
    // BUT, auction items have to be loaded, or it will be not found in mAitems and remains to float in the DB

    uint32 oldMSTime = getMSTime();
    uint32 expirecount = 0;
    time_t curTime = sWorld->GetGameTime();

    // Query the DB to see if there are any expired auctions
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_SEL_EXPIRED_AUCTIONS);
    stmt->setUInt32(0, (uint32)curTime+60);
    PreparedQueryResult expAuctions = CharacterDatabase.Query(stmt);

    if (!expAuctions)
    {
        TC_LOG_INFO("server.loading", ">> No expired auctions to delete");

        return;
    }

    do
    {
        Field* fields = expAuctions->Fetch();

        AuctionEntry* auction = new AuctionEntry();

        // Can't use LoadFromDB() because it assumes the auction map is loaded
        if (!auction->LoadFromFieldList(fields))
        {
            // For some reason the record in the DB is broken (possibly corrupt
            //  faction info). Delete the object and move on.
            delete auction;
            continue;
        }

        SQLTransaction trans = CharacterDatabase.BeginTransaction();

        if (auction->bidder==0)
        {
            // Cancel the auction, there was no bidder
            sAuctionMgr->SendAuctionExpiredMail(auction, trans);
        }
        else
        {
            // Send the item to the winner and money to seller
            sAuctionMgr->SendAuctionSuccessfulMail(auction, trans);
            sAuctionMgr->SendAuctionWonMail(auction, trans);
        }

        // Call the appropriate AuctionHouseObject script
        //  ** Do we need to do this while core is still loading? **
        sScriptMgr->OnAuctionExpire(GetAuctionsMap(auction->factionTemplateId), auction);

        // Delete the auction from the DB
        auction->DeleteFromDB(trans);
        CharacterDatabase.CommitTransaction(trans);

        sAuctionMgr->RemoveAItem(auction->itemGUIDLow);

        // Release memory
        delete auction;
        ++expirecount;

    }
    while (expAuctions->NextRow());

    TC_LOG_INFO("server.loading", ">> Deleted %u expired auctions in %u ms", expirecount, GetMSTimeDiffToNow(oldMSTime));


}

bool AuctionEntry::LoadFromFieldList(Field* fields)
{
    // Loads an AuctionEntry item from a field list. Unlike "LoadFromDB()", this one
    //  does not require the AuctionEntryMap to have been loaded with items. It simply
    //  acts as a wrapper to fill out an AuctionEntry struct from a field list

    Id = fields[0].GetUInt32();
    auctioneer = fields[1].GetUInt32();
    itemGUIDLow = fields[2].GetUInt32();
    itemEntry = fields[3].GetUInt32();
    itemCount = fields[4].GetUInt32();
    owner = fields[5].GetUInt32();
    buyout = fields[6].GetUInt32();
    expire_time = fields[7].GetUInt32();
    bidder = fields[8].GetUInt32();
    bid = fields[9].GetUInt32();
    startbid = fields[10].GetUInt32();
    deposit = fields[11].GetUInt32();

    CreatureData const* auctioneerData = sObjectMgr->GetCreatureData(auctioneer);
    if (!auctioneerData)
    {
        TC_LOG_ERROR("misc", "AuctionEntry::LoadFromFieldList() - Auction %u has not a existing auctioneer (GUID : %u)", Id, auctioneer);
        return false;
    }

    CreatureTemplate const* auctioneerInfo = sObjectMgr->GetCreatureTemplate(auctioneerData->id);
    if (!auctioneerInfo)
    {
        TC_LOG_ERROR("misc", "AuctionEntry::LoadFromFieldList() - Auction %u has not a existing auctioneer (GUID : %u Entry: %u)", Id, auctioneer, auctioneerData->id);
        return false;
    }

    factionTemplateId = auctioneerInfo->faction_A;
    auctionHouseEntry = AuctionHouseMgr::GetAuctionHouseEntry(factionTemplateId);

    if (!auctionHouseEntry)
    {
        TC_LOG_ERROR("misc", "AuctionEntry::LoadFromFieldList() - Auction %u has auctioneer (GUID : %u Entry: %u) with wrong faction %u", Id, auctioneer, auctioneerData->id, factionTemplateId);
        return false;
    }

    return true;
}

std::string AuctionEntry::BuildAuctionMailSubject(MailAuctionAnswers response) const
{
    std::ostringstream strm;
    strm << itemEntry << ":0:" << response << ':' << Id << ':' << itemCount;
    return strm.str();
}

#if COMPILER == COMPILER_MICROSOFT
#define GUID_FORMAT "%16I64X"
#else
#define GUID_FORMAT "%16llX"
#endif

std::string AuctionEntry::BuildAuctionMailBody(MailAuctionAnswers response) const
{
    switch (response)
    {
        case AUCTION_WON:
            return Format(GUID_FORMAT ":%d:%d", MAKE_NEW_GUID(owner, 0, HIGHGUID_PLAYER), bid, buyout);
        case AUCTION_SUCCESSFUL:
            return Format(GUID_FORMAT ":%d:%d:%d:%d", MAKE_NEW_GUID(bidder, 0, HIGHGUID_PLAYER), bid, buyout, deposit, GetAuctionCut());
        case AUCTION_SALE_PENDING:
        {
            uint32 delay = sWorld->getIntConfig(CONFIG_MAIL_DELIVERY_DELAY);
            WorldPacket data;
            uint32 eta;
            data.AppendPackedTime(time(nullptr) + delay);
            data >> eta;
            return Format(GUID_FORMAT ":%d:%d:%d:%d:%d:%d", MAKE_NEW_GUID(bidder, 0, HIGHGUID_PLAYER), bid, buyout, deposit, GetAuctionCut(), delay, eta);
        }
        default:
            return "";
    }
}
