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

#include "BattlePayMgr.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Player.h"
#include "ServiceBoost.h"

void WorldSession::HandleBattlePayGetProductList(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_BATTLE_PAY_GET_PRODUCT_LIST");

    if (!sBattlePayMgr->IsStoreEnabled())
    {
        WorldPacket data(SMSG_BATTLE_PAY_GET_PRODUCT_LIST_RESPONSE);

        data.WriteBits(0, 19);
        data.WriteBits(0, 19);
        data.WriteBits(0, 20);
        data.FlushBits();

        data << uint32(BATTLE_PAY_CURRENCY_UNKNOWN);
        data << uint32(BATTLE_PAY_STATUS_UNAVAILABLE);
        SendPacket(&data);
        return;
    }

    sBattlePayMgr->SendBattlePayProductList(this);
    sBattlePayMgr->SendPointsBalance(this);
}

void WorldSession::HandleBattlePayStartPurchase(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_BATTLE_PAY_START_PURCHASE");

    uint32 productID = recvData.read<uint32>();
    uint32 clientToken = recvData.read<uint32>();

    ObjectGuid guid;
    recvData.ReadGuidMask(guid, 2, 3, 5, 1, 4, 7, 0, 6);
    recvData.ReadGuidBytes(guid, 5, 3, 7, 1, 4, 0, 6, 2);

    uint32 purchaseId = irand(1, 999999); // temp solution

    sBattlePayMgr->AddQuenedPurchaseResponse(new PurchaseInfo(this, guid, purchaseId, productID, BATTLE_PAY_PURCHASE_STATUS_READY, BATTLE_PAY_RESULT_OK, clientToken, 0, false), 500, true);
}

void WorldSession::HandleBattlePayGetPurchaseList(WorldPacket& /*recvData*/)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_BATTLE_PAY_GET_PURCHASE_LIST");

    sBattlePayMgr->SendBattlePayPurchaseList(this);
}

void WorldSession::HandleBattlePayConfirmPurchaseResponse(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_BATTLE_PAY_CONFIRM_PURCHASE_RESPONSE");

    uint64 currentPrice = recvData.read<uint64>(); // TODO: use it!
    uint32 serverToken = recvData.read<uint32>();
    bool confirm = recvData.read<bool>();

    PurchaseInfo* purchase = sBattlePayMgr->GetPurchaseInfo();
    if (confirm && serverToken == purchase->ServerToken)
        sBattlePayMgr->AddQuenedPurchaseResponse(new PurchaseInfo(this, purchase->SelectedPlayer, purchase->PurchaseId, purchase->ProductId, BATTLE_PAY_PURCHASE_STATUS_BUYING, BATTLE_PAY_RESULT_OK, purchase->ClientToken, serverToken, false), 8000, true); // do not touch timers! everything here should be as it is! decreasing timer will cause errors, for example: window with purchase close automatically and causing random client crashes
    else
        sBattlePayMgr->SendBattlePayPurchaseUpdate(new PurchaseInfo(this, purchase->SelectedPlayer, purchase->PurchaseId, purchase->ProductId, BATTLE_PAY_PURCHASE_STATUS_ALLOWED_TO_BUY, BATTLE_PAY_RESULT_DECLINED, purchase->ClientToken, 0, false));
}

void WorldSession::HandleBattlePayCharBoost(WorldPacket& recvData)
{
    TC_LOG_DEBUG("network", "WORLD: Received CMSG_BATTLE_PAY_CHAR_BOOST");

    if (!HasBoost())
    {
        TC_LOG_ERROR("network", "WorldSession::HandleBattleCharBoost called, but player has not allowed boost.");
        recvData.rfinish();
        return;
    }

    ObjectGuid guid, guid2;

    recvData.read_skip<uint32>();
    recvData.ReadGuidMask(guid2, 1);
    recvData.ReadGuidMask(guid, 0);
    recvData.ReadGuidMask(guid2, 5, 4);
    recvData.ReadGuidMask(guid, 3);
    recvData.ReadGuidMask(guid2, 6, 0);
    recvData.ReadGuidMask(guid, 5);
    recvData.ReadGuidMask(guid2, 3, 7);
    recvData.ReadGuidMask(guid, 1);
    recvData.ReadGuidMask(guid2, 2);
    recvData.ReadGuidMask(guid, 2);
    bool hasCharInfo = !recvData.ReadBit();
    recvData.ReadGuidMask(guid, 7, 4, 6);

    recvData.ReadGuidBytes(guid, 2);
    recvData.ReadGuidBytes(guid2, 0);
    recvData.ReadGuidBytes(guid, 0, 7);
    recvData.ReadGuidBytes(guid2, 7);
    recvData.ReadGuidBytes(guid, 3);
    recvData.ReadGuidBytes(guid2, 6, 4, 5);
    recvData.ReadGuidBytes(guid, 1, 6, 4);
    recvData.ReadGuidBytes(guid2, 1, 2, 3);
    recvData.ReadGuidBytes(guid, 5);

    if (hasCharInfo)
    {
        uint32 charInfo = recvData.read<uint32>();

        sBattlePayMgr->SendBattlePayDistributionUpdate(this, BATTLE_PAY_SERVICE_BOOST, CHARACTER_BOOST_CHOOSED);
        GetBoost()->SetBoostedCharInfo(guid, CHARACTER_BOOST_ITEMS, (charInfo & CHARACTER_BOOST_SPEC_MASK), (charInfo & CHARACTER_BOOST_FACTION_ALLIANCE));

        WorldPacket data(SMSG_CHARACTER_UPGRADE_STARTED, 8);
        data.WriteGuidMask(guid, 6, 2, 5, 4, 7, 0, 3, 1);
        data.WriteGuidBytes(guid, 4, 1, 6, 0, 7, 5, 2, 3);
        SendPacket(&data);
    }
}
