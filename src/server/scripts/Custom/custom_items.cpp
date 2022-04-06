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

#include "ScriptMgr.h"
#include "Chat.h"
#include "ServiceMgr.h"

#define GetText(a, b, c) a->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU ? b : c

namespace BattlePay
{
    enum Type:int64
    {
        Gold_1K                             = 10000000U,
        Gold_5K                             = 50000000U,
        Gold_10K                            = 100000000U,
        Gold_30K                            = 300000000U,
        Gold_80K                            = 800000000U,
        Gold_150K                           = 1500000000U
    };
}

class battle_pay_currency_honor_1000 : public ItemScript
{
public:
    battle_pay_currency_honor_1000(const char *ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (player->HasItemCount(item->GetEntry(), 1, true))
        {
            player->ModifyCurrency(392, 1000 * CURRENCY_PRECISION);
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Спасибо за помощь проекту Pandaria 5.4.8, вы только что получили 1000 очков чести.", "Thanks for helping the Pandaria 5.4.8 project, you just received 1000 honor points."));
            player->DestroyItemCount(item->GetEntry(), 1, true);
            player->SaveToDB();
        }
        else
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "У вас нет необходимого жетона.", "You do not have the necessary token."));
        }
        return true;
    }
};

class battle_pay_currency_justice_1000 : public ItemScript
{
public:
    battle_pay_currency_justice_1000(const char *ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (player->HasItemCount(item->GetEntry(), 1, true))
        {
            player->ModifyCurrency(CURRENCY_TYPE_JUSTICE_POINTS, 1000 * CURRENCY_PRECISION, true, true, true);
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Спасибо за помощь проекту Pandaria 5.4.8, вы только что получили 1000 очков справедливости.", "Thanks for helping the Pandaria 5.4.8 project, you just received 1000 justice points."));
            player->DestroyItemCount(item->GetEntry(), 1, true);
            player->SaveToDB();
        }
        else
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "У вас нет необходимого жетона.", "You do not have the necessary token."));
        }
        return true;
    }
};

class battle_pay_currency_valor_1000 : public ItemScript
{
public:
    battle_pay_currency_valor_1000(const char *ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (player->HasItemCount(item->GetEntry(), 1, true))
        {
            player->ModifyCurrency(CURRENCY_TYPE_VALOR_POINTS, 1000 * CURRENCY_PRECISION, true, true, true);
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Спасибо за помощь проекту Pandaria 5.4.8, вы только что получили 1000 очков доблести.", "Thanks for helping the Pandaria 5.4.8 project, you just received 1000 valor points."));
            player->DestroyItemCount(item->GetEntry(), 1, true);
            player->SaveToDB();
        }
        else
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "У вас нет необходимого жетона.", "You do not have the necessary token."));
        }
        return true;
    }
};

class battle_pay_currency_conquest_1000 : public ItemScript
{
public:
    battle_pay_currency_conquest_1000(const char *ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (player->HasItemCount(item->GetEntry(), 1, true))
        {
            player->ModifyCurrency(390, 1000 * CURRENCY_PRECISION);
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Спасибо за помощь проекту Pandaria 5.4.8, вы только что получили 1000 очков завоевания.", "Thanks for helping the Pandaria 5.4.8 project, you just received 1000 conquest points."));
            player->DestroyItemCount(item->GetEntry(), 1, true);
            player->SaveToDB();
        }
        else
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "У вас нет необходимого жетона.", "You do not have the necessary token."));
        }
        return true;
    }
};

template<int64 Gold>
class battle_pay_gold : public ItemScript
{
public:
    battle_pay_gold(const char *ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (uint64(player->GetMoney() + Gold) > MAX_MONEY_AMOUNT)
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Превышен максимально допустимый лимит золота.", "Maximum allowed gold limit exceeded."));
        }
        else
        {
            player->ModifyMoney(Gold);
            player->DestroyItemCount(item->GetEntry(), 1, true);

            std::ostringstream gold_amount_message_ru, gold_amount_message_en;
            gold_amount_message_ru << "Спасибо за помощь проекту Pandaria 5.4.8, вы только что получили " << Gold/10000 << " золотых.";
            gold_amount_message_en << "Thanks for helping the Pandaria 5.4.8 project, you just received " << Gold/10000 << " gold.";
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, gold_amount_message_ru.str().c_str(), gold_amount_message_en.str().c_str()));
            player->SaveToDB();
        }
        return true;
    }
};

template<uint32 Level>
class battle_pay_level : public ItemScript
{
public:
    battle_pay_level(const char *ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (Level <= player->getLevel())
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Текущий уровень вашего персонажа слишком высокий.", "Your current character level is too high."));
        }
        else
        {
            player->GiveLevel(Level);
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Спасибо за помощь проекту Pandaria 5.4.8, вы только что повысили уровень своего порсонажа до 90-го.", "Thanks for helping the Pandaria 5.4.8 project, you just leveled up your character to level 90."));
            player->DestroyItemCount(item->GetEntry(), 1, true);
            player->SaveToDB();
        }
        return true;
    }
};

template<AtLoginFlags FlagAtLogin>
class battle_pay_service : public ItemScript
{
public:
    battle_pay_service(const char *ScriptName) : ItemScript(ScriptName) { }

    bool OnUse(Player *player, Item *item, const SpellCastTargets &)
    {
        if (player->IsInCombat() || player->InArena() || player->InBattleground())
        {
            player->GetSession()->SendNotification(GetText(player, "Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.", "You may not use this token whilst you are in combat or present in an arena or battleground."));
        }
        else if (player->HasAtLoginFlag((AtLoginFlags)0xFFFFFFFF))
        {
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Вы уже активировали эту функцию.", "You have already activated this feature."));
        }
        else
        {
            player->SetAtLoginFlag(FlagAtLogin);
            player->DestroyItemCount(item->GetEntry(), 1, true);
            ChatHandler(player->GetSession()).SendSysMessage(GetText(player, "Спасибо за помощь проекту Pandaria 5.4.8, вы только что активировали функцию по изменению своего персонажа. Пожалуйста перезайдите на свою учетную запись.", "Thanks for helping the Pandaria 5.4.8 project, you have just activated the function to change your character. Please re-login to your account."));
            player->SaveToDB();
        }
        return true;
    }
};

void AddSC_custom_items()
{
    new battle_pay_currency_honor_1000("battle_pay_currency_honor_1000");
    new battle_pay_currency_justice_1000("battle_pay_currency_justice_1000");
    new battle_pay_currency_valor_1000("battle_pay_currency_valor_1000");
    new battle_pay_currency_conquest_1000("battle_pay_currency_conquest_1000");
    new battle_pay_gold<BattlePay::Gold_1K>("battle_pay_gold_1k");
    new battle_pay_gold<BattlePay::Gold_5K>("battle_pay_gold_5k");
    new battle_pay_gold<BattlePay::Gold_10K>("battle_pay_gold_10k");
    new battle_pay_gold<BattlePay::Gold_30K>("battle_pay_gold_30k");
    new battle_pay_gold<BattlePay::Gold_80K>("battle_pay_gold_80k");
    new battle_pay_gold<BattlePay::Gold_150K>("battle_pay_gold_150k");
    new battle_pay_level<90>("battle_pay_service_level_90");
    new battle_pay_service<AtLoginFlags::AT_LOGIN_RENAME>("battle_pay_service_rename");
    new battle_pay_service<AtLoginFlags::AT_LOGIN_CHANGE_FACTION>("battle_pay_service_change_faction");
    new battle_pay_service<AtLoginFlags::AT_LOGIN_CHANGE_RACE>("battle_pay_service_change_race");
    new battle_pay_service<AtLoginFlags::AT_LOGIN_CUSTOMIZE>("battle_pay_service_customize");
}
