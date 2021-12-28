#include "ScriptMgr.h"
#include "Chat.h"
#include "ServiceMgr.h"

class honor_1000 : public ItemScript
{
public:
    honor_1000() : ItemScript("honor_1000") {}

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground()) //Item is not usable in combat, arenas and battlegrounds. This can be modified to your taste.
        {
            player->GetSession()->SendNotification("You may not use this token whilst you are in combat or present in an arena or battleground.");
        }
        else if(player->HasItemCount(item->GetEntry(), 1, true)) //verify that the characters have the item
        {
            player->ModifyCurrency(392, 1000 * CURRENCY_PRECISION); // add 1000 honor points
            ChatHandler(player->GetSession()).SendSysMessage("Thanks for helping the WoW project, you just received 1000 honor points.");

            //Item is destroyed on useage.
            player->DestroyItemCount(item->GetEntry(), 1, true);

            //save pj
            player->SaveToDB();
        }
        else
        {
            ChatHandler(player->GetSession()).SendSysMessage("You do not have the necessary token.");
        }
        return true;
    }
};

class justice_1000 : public ItemScript
{
public:
    justice_1000() : ItemScript("justice_1000") {}

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground()) //Item is not usable in combat, arenas and battlegrounds. This can be modified to your taste.
        {
            player->GetSession()->SendNotification("You may not use this token whilst you are in combat or present in an arena or battleground.");
        }
        else if(player->HasItemCount(item->GetEntry(), 1, true)) //verify that the characters have the item
        {
            player->ModifyCurrency(CURRENCY_TYPE_JUSTICE_POINTS, 1000 * CURRENCY_PRECISION, true, true, true); // add 1000 justice points
            ChatHandler(player->GetSession()).SendSysMessage("Thanks for helping the WoW project, you just received 1000 justice points.");

            //Item is destroyed on useage.
            player->DestroyItemCount(item->GetEntry(), 1, true);

            //save pj
            player->SaveToDB();
        }
        else
        {
            ChatHandler(player->GetSession()).SendSysMessage("You do not have the necessary token.");
        }
        return true;
    }
};

class valor_1000 : public ItemScript
{
public:
    valor_1000() : ItemScript("valor_1000") {}

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground()) //Item is not usable in combat, arenas and battlegrounds. This can be modified to your taste.
        {
            player->GetSession()->SendNotification("You may not use this token whilst you are in combat or present in an arena or battleground.");
        }
        else if(player->HasItemCount(item->GetEntry(), 1, true)) //verify that the characters have the item
        {
            player->ModifyCurrency(CURRENCY_TYPE_VALOR_POINTS, 1000 * CURRENCY_PRECISION, true, true, true); // add 1000 valor points
            ChatHandler(player->GetSession()).SendSysMessage("Thanks for helping the WoW project, you just received 1000 valor points.");

            //Item is destroyed on useage.
            player->DestroyItemCount(item->GetEntry(), 1, true);

            //save pj
            player->SaveToDB();
        }
        else
        {
            ChatHandler(player->GetSession()).SendSysMessage("You do not have the necessary token.");
        }
        return true;
    }
};

class conquest_1000 : public ItemScript
{
public:
    conquest_1000() : ItemScript("conquest_1000") {}

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground()) //Item is not usable in combat, arenas and battlegrounds. This can be modified to your taste.
        {
            player->GetSession()->SendNotification("You may not use this token whilst you are in combat or present in an arena or battleground.");
        }
        else if(player->HasItemCount(item->GetEntry(), 1, true)) //verify that the characters have the item
        {
            player->ModifyCurrency(390, 1000 * CURRENCY_PRECISION); // add 1000 conquest points
            ChatHandler(player->GetSession()).SendSysMessage("Thanks for helping the WoW project, you just received 1000 conquest points.");

            //Item is destroyed on useage.
            player->DestroyItemCount(item->GetEntry(), 1, true);

            //save pj
            player->SaveToDB();
        }
        else
        {
            ChatHandler(player->GetSession()).SendSysMessage("You do not have the necessary token.");
        }
        return true;
    }
};

void AddSC_Custom_Items() // Add to scriptloader normally
{
    new honor_1000();
    new justice_1000();
    new valor_1000();
    new conquest_1000();
}
