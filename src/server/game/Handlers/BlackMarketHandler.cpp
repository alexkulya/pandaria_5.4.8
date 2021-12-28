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

#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "Unit.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "BlackMarketMgr.h"
#include "CustomLogs.h"

void WorldSession::HandleBlackMarketHelloOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_BLACK_MARKET_OPEN");

    ObjectGuid guid;
    recvData.ReadGuidMask(guid, 4, 5, 2, 7, 0, 1, 3, 6);
    recvData.ReadGuidBytes(guid, 3, 5, 0, 6, 4, 1, 7, 2);

    if (GetPlayer()->HasUnitState(UNIT_STATE_DIED))
        GetPlayer()->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);

    SendBlackMarketHello(guid, sBlackMarketMgr->isBlackMarketOpen());
}

void WorldSession::SendBlackMarketHello(ObjectGuid guid, bool open)
{
    WorldPacket data(SMSG_BLACK_MARKET_OPEN_RESULT, 9);
    data.WriteGuidMask(guid, 2, 0, 4, 1, 3, 6, 5, 7);
    data.WriteBit(open);
    data.FlushBits();
    data.WriteGuidBytes(guid, 6, 1, 2, 5, 0, 7, 4, 3);
    SendPacket(&data);
}

void WorldSession::HandleBlackMarketRequestItemOpcode(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_BLACK_MARKET_REQUEST_ITEMS");

    ObjectGuid guid;
    uint32 timestamp = recvData.read<uint32>();
    recvData.ReadGuidMask(guid, 2, 6, 0, 3, 4, 5, 1, 7);
    recvData.ReadGuidBytes(guid, 6, 2, 3, 5, 7, 4, 1, 0);

    SendBlackMarketRequestItemsResult();
}

void WorldSession::SendBlackMarketRequestItemsResult()
{
    WorldPacket data(SMSG_BLACK_MARKET_REQUEST_ITEMS_RESULT);
    sBlackMarketMgr->BuildBlackMarketRequestItemsResult(data, GetPlayer()->GetGUIDLow());
    SendPacket(&data);
}

void WorldSession::HandleBlackMarketBidOnItem(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_BLACK_MARKET_BID_ON_ITEM");

    ObjectGuid guid;
    uint32 itemId = recvData.read<uint32>();
    uint32 auctionId = recvData.read<uint32>();
    uint64 bidAmount = recvData.read<uint64>();
    recvData.ReadGuidMask(guid, 0, 5, 4, 3, 7, 6, 1, 2);
    recvData.ReadGuidBytes(guid, 4, 3, 6, 5, 7, 1, 0, 2);

    TC_LOG_DEBUG("blackMarket", ">> HandleBlackMarketBid >> MarketID : %u, BidAmount : " UI64FMTD ", ItemID : %u", auctionId, bidAmount, itemId);

    if (!bidAmount)
        return;

    BlackMarketAuction* auction = sBlackMarketMgr->GetAuction(auctionId);
    if (!auction)
    {
        TC_LOG_DEBUG("blackMarket", "HandleBlackMarketBid - Auction (MarketID: %u) not found.", auctionId);
        SendBlackMarketBidOnItemResult(auctionId, itemId, ERR_BMAH_ITEM_NOT_FOUND);
        return;
    }

    if (auction->GetCurrentBidder() == GetPlayer()->GetGUIDLow())
    {
        TC_LOG_DEBUG("blackMarket", "HandleBlackMarketBid - Player (GUID: %u) is already the highest bidder.", GetPlayer()->GetGUIDLow());
        SendBlackMarketBidOnItemResult(auctionId, itemId, ERR_BMAH_ALREADY_BID);
        return;
    }

    if (auction->GetCurrentBid() > bidAmount && bidAmount != auction->GetTemplate()->MinBid)
    {
        TC_LOG_DEBUG("blackMarket", "HandleBlackMarketBid - Player (GUID: %u) could not bid. The current bid (%u) is higher than the given amount (" UI64FMTD ").", GetPlayer()->GetGUIDLow(), auction->GetCurrentBid(), bidAmount);
        SendBlackMarketBidOnItemResult(auctionId, itemId, ERR_BMAH_HIGHER_BID);
        return;
    }

    uint64 currentRequiredIncrement = !auction->GetNumBids() ? auction->GetCurrentBid() : (auction->GetCurrentBid() + auction->GetMinIncrement());
    if (currentRequiredIncrement > bidAmount)
    {
        TC_LOG_DEBUG("blackMarket", "HandleBlackMarketBid - Player (GUID: %u) could not bid. The BidAmount (" UI64FMTD ") is lower than the current requiredIncrement (" UI64FMTD ").", GetPlayer()->GetGUIDLow(), bidAmount, currentRequiredIncrement);
        SendBlackMarketBidOnItemResult(auctionId, itemId, ERR_BMAH_DATABASE_ERROR);
        return;
    }

    uint64 newIncrement = bidAmount - currentRequiredIncrement;
    if (!GetPlayer()->HasEnoughMoney(bidAmount))
    {
        TC_LOG_DEBUG("blackMarket", "HandleBlackMarketBid - Player (GUID: %u) has not enough money to bid.", GetPlayer()->GetGUIDLow());
        SendBlackMarketBidOnItemResult(auctionId, itemId, ERR_BMAH_NOT_ENOUGH_MONEY);
        return;
    }
    else
    {
        GetPlayer()->ModifyMoney(-int64(bidAmount));
        logs::CurrencyTransaction(GetPlayer(), CurrencyOperation::BlackMarket, itemId, -int64(bidAmount));
    }

    sBlackMarketMgr->UpdateAuction(auction, currentRequiredIncrement, newIncrement, GetPlayer());

    SendBlackMarketBidOnItemResult(auctionId, itemId, ERR_BMAH_OK);
    SendBlackMarketHello(guid, sBlackMarketMgr->isBlackMarketOpen());
}

void WorldSession::SendBlackMarketBidOnItemResult(uint32 auctionId, uint32 itemID, BlackMarketError result)
{
    WorldPacket data(SMSG_BLACK_MARKET_BID_ON_ITEM_RESULT, 12);
    data << uint32(itemID);
    data << uint32(result);
    data << uint32(auctionId);
    SendPacket(&data);
}
