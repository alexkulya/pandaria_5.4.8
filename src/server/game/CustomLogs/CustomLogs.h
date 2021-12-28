#ifndef CUSTOM_LOGS_H
#define CUSTOM_LOGS_H

#include "Common.h"

class LogFile
{
public:
    LogFile() { }
    ~LogFile() { Close(); }

    void Write(char const* str, ...);

    void Open(char const* path, char const* mode)
    {
        Close();
        _file = fopen(path, mode);
    }

    void Open(std::string const& path, char const* mode)
    {
        Open(path.c_str(), mode);
    }

    void Close()
    {
        if (_file)
        {
            fclose(_file);
            _file = nullptr;
        }
    }

protected:
    FILE* _file = nullptr;
};

class Player;

enum class CurrencyOperation
{
    Null,
    LootMob,
    LootItem,
    Mail,
    QuerstReward,
    Trade,
    SellItem,
    GuildBank,
    Auction,
    Transmogrification,
    BlackMarket,
    Max
};

namespace logs
{
    // need to use after ModifyMoney()
    void CurrencyTransaction(Player const* player, CurrencyOperation operation, uint32 param, int64 sum, char const* attachments = nullptr);
    void ItemLog(Player const* player, Item const* item, uint32 count, char const* str, ...);
    void StopItemLogging(uint32 guid);
}

#endif // !CUSTOM_LOGS_H
