#include "CustomLogs.h"
#include "Player.h"
#include "World.h"
#include "Config.h"
#include <boost/filesystem.hpp>

void LogFile::Write(char const* str, ...)
{
    if (!_file)
        return;

    va_list ap;
    va_start(ap, str);
    fprintf(_file, TimeStr(time(NULL), "%Y-%m-%d %H:%M:%S ").c_str());
    vfprintf(_file, str, ap);
    fprintf(_file, "\n");
    fflush(_file);
    va_end(ap);
}

namespace logs
{
    void CurrencyTransaction(Player const* player, CurrencyOperation operation, uint32 param, int64 sum, char const* attachments)
    {
        if (!sum)
            return;

        if (sum < 0)
        {
            if (operation != CurrencyOperation::GuildBank && operation != CurrencyOperation::Transmogrification && operation != CurrencyOperation::BlackMarket)
                return;
        }

        if (operation == CurrencyOperation::Null)
            return;

        int32 rep = int32(operation);
        if (operation != CurrencyOperation::Transmogrification && operation != CurrencyOperation::BlackMarket)
        {
            int64 amount = sWorld->getIntConfig(WorldIntConfigs(CONFIG_CURRENCY_LOG_LOOT_MOB - 1 + rep));
            if (amount < 0 || std::abs(sum) < amount)
                return;
        }

        PreparedStatement* stmt = ArchiveDatabase.GetPreparedStatement(ARCH_INS_CURRENCY_TRANSACTIONS);
        uint32 index = 0;
        stmt->setUInt32(index, player->GetGUIDLow());
        stmt->setUInt32(++index, time(nullptr));
        stmt->setUInt32(++index, rep);
        stmt->setUInt32(++index, param);
        stmt->setString(++index, attachments ? attachments : "");
        stmt->setUInt64(++index, player->GetMoney() - sum);
        stmt->setUInt64(++index, player->GetMoney());
        stmt->setUInt32(++index, realmID);

        ArchiveDatabase.Execute(stmt);
    }

    static std::unordered_map<uint32, std::unique_ptr<LogFile>> ItemLogMap;

    void ItemLog(Player const* player, Item const* item, uint32 count, char const* str, ...)
    {
        LogFile* itemLog = nullptr;

        auto it = ItemLogMap.find(player->GetGUIDLow());
        if (it == ItemLogMap.end())
        {
            std::string accName;
            sAccountMgr->GetName(player->GetSession()->GetAccountId(), accName);
            std::string p = sConfigMgr->GetStringDefault("LogsDir", "") + "/items/" + accName;

            boost::filesystem::path path{ p };
            boost::system::error_code c;
            if (!boost::filesystem::create_directories(path, c) && c.value() != 0)
            {
                TC_LOG_ERROR("server", "logs::ItemLog - Couldn't create directory %s, errno %u", p.c_str(), c.value());
                return;
            }
            
            itemLog = new LogFile();
            itemLog->Open((p + "/" + std::to_string(player->GetGUIDLow()) + ".log").c_str(), "a");
            ItemLogMap[player->GetGUIDLow()].reset(itemLog);
        }
        else
            itemLog = it->second.get();

        char buff[8196];
        buff[0] = 0;
        va_list ap;
        va_start(ap, str);
        vsnprintf(buff, sizeof(buff), str, ap);
        va_end(ap);
        itemLog->Write("%s, item: %u (GUID: %u), count: %u", buff, item->GetEntry(), item->GetGUIDLow(), count);
    }

    void StopItemLogging(uint32 guid)
    {
        ItemLogMap.erase(guid);
    }
}
