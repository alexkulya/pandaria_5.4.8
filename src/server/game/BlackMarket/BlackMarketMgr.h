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
 
#ifndef BLACK_MARKET_H
#define BLACK_MARKET_H


#include <ace/Singleton.h>

#include "Common.h"
#include "DatabaseEnv.h"
#include "DBCStructure.h"

class Item;
class Player;
class WorldPacket;

enum BMMailAuctionAnswers
{
    BM_AUCTION_OUTBIDDED = 0,
    BM_AUCTION_WON       = 1,
};

enum BlackMarketError : int32      // Extracted from client
{
    ERR_BMAH_OK                       = 0,
    ERR_BMAH_ITEM_NOT_FOUND           = 1,
    ERR_BMAH_ALREADY_BID              = 2,
    ERR_BMAH_HIGHER_BID               = 4,
    ERR_BMAH_DATABASE_ERROR           = 6,
    ERR_BMAH_NOT_ENOUGH_MONEY         = 7,
    ERR_BMAH_RESTRICTED_ACCOUNT_TRIAL = 9
};

#define BLACKMARKET_AUCTION_HOUSE 7

struct BlackMarketAuctionTemplate
{
    uint32 Id;
    uint32 MarketId;
    uint32 SellerNPCEntry;
    uint32 ItemEntry;
    uint32 Quantity;
    uint32 MinBid;
    uint32 Duration;
    int32 RandomStats;
    float Chance;
};
typedef struct BlackMarketAuctionTemplate BlackMarketAuctionTemplate;

struct BlackMarketAuction
{
public:
    BlackMarketAuction(uint32 auctionId, uint32 templateId, uint32 startTime, uint32 endTime, uint32 currentBidder, uint64 currentBid,
        uint64 minIncrement, uint32 numBids) :
        _auctionId(auctionId), _templateId(templateId), _startTime(startTime), _endTime(endTime), _currentBidder(currentBidder), _currentBid(currentBid),
        _minIncrement(minIncrement), _numBids(numBids) { }

    BlackMarketAuction() : _auctionId(1), _templateId(1), _startTime(0), _endTime(0), _currentBidder(0), _currentBid(0),
        _minIncrement(0), _numBids(0) { }

    void SetAuctionId(uint32 auctionId) { _auctionId = auctionId; }
    uint32 GetAuctionId() const { return _auctionId; }

    void SetTemplateId(uint32 templateId) { _templateId = templateId; }
    uint32 GetTemplateId() const { return _templateId; }

    void SetStartTime(uint32 startTime) { _startTime = startTime; }
    uint32 GetStartTime() const { return _startTime; }

    void SetEndTime(uint32 endTime) { _endTime = endTime; }
    uint32 GetEndTime() { return _endTime; }

    void SetCurrentBidder(uint32 currentBidder) { _currentBidder = currentBidder; }
    uint32 GetCurrentBidder() const { return _currentBidder; }

    void SetCurrentBid(uint64 currentBid) { _currentBid = currentBid; }
    uint64 GetCurrentBid() const { return _currentBid; }

    void SetMinIncrement(uint64 minIncrement) { _minIncrement = minIncrement; }
    uint64 GetMinIncrement() const { return _minIncrement; }

    void SetNumBids(uint32 numBids) { _numBids = numBids; }
    uint32 GetNumBids() const { return _numBids; }

    BlackMarketAuctionTemplate* GetTemplate() const;

    void DeleteFromDB(SQLTransaction& trans);
    void SaveToDB(SQLTransaction& trans);
    void UpdateToDB(SQLTransaction& trans);

    uint32 TimeLeft();

    bool IsActive() { return (time(NULL) >= GetStartTime()); }
    bool IsExpired() { return GetEndTime() < time(NULL); }

    std::string BuildAuctionMailSubject(BMMailAuctionAnswers response);
    std::string BuildAuctionMailBody(uint32 lowGuid);

private:
    uint32 _auctionId;
    uint32 _templateId;
    uint32 _startTime;
    uint32 _endTime;
    uint32 _currentBidder;
    uint64 _currentBid;
    uint64 _minIncrement;
    uint32 _numBids;
    BlackMarketAuctionTemplate* _template = nullptr;
};

typedef struct BlackMarketAuction BlackMarketAuction;
typedef std::map<uint32, BlackMarketAuctionTemplate*> BMAuctionTemplateStore;
typedef std::map<uint32, BlackMarketAuction*> BMAuctionStore;

class BlackMarketMgr
{
    friend class ACE_Singleton<BlackMarketMgr, ACE_Null_Mutex>;

private:
    BlackMarketMgr();
    ~BlackMarketMgr();

public:
    void Update();
    time_t GetLastUpdate() const { return _lastUpdate; }

    void LoadTemplates();
    void LoadAuctions();

    BlackMarketAuctionTemplate* GetTemplate(uint32 templateId) const;
    BlackMarketAuction* GetAuction(uint32 auctionId) const;

    uint32 GetFreeAuctionId();

    void CreateAuctions(uint32 number, SQLTransaction& trans);
    void UpdateAuction(BlackMarketAuction* auction, uint64 newPrice, uint64 requiredIncrement, Player* newBidder);

    void BuildBlackMarketRequestItemsResult(WorldPacket& data, uint32 guidLow);

    void SendAuctionWon(BlackMarketAuction* auction, SQLTransaction& trans);
    void SendAuctionOutbidded(BlackMarketAuction* auction, Player* newBidder, SQLTransaction& trans);

    bool isBlackMarketOpen() { return sWorld->getBoolConfig(CONFIG_BLACK_MARKET_OPEN); }

private:
    BMAuctionTemplateStore _templates;
    BMAuctionStore _auctions;
    time_t _lastUpdate = time_t(0);
};

#define sBlackMarketMgr ACE_Singleton<BlackMarketMgr, ACE_Null_Mutex>::instance()

#endif
