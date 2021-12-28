#ifndef BATTLEGROUND_TTP_H
#define BATTLEGROUND_TTP_H

#include "Battleground.h"

enum BattlegroundTTPObjectTypes
{
    BG_TTP_OBJECT_DOOR_1         = 0,
    BG_TTP_OBJECT_DOOR_2         = 1,
    BG_TTP_OBJECT_BUFF_1         = 2,
    BG_TTP_OBJECT_BUFF_2         = 3,
    BG_TTP_OBJECT_MAX            = 4
};

enum BattlegroundTTPObjects
{
    BG_TTP_OBJECT_TYPE_DOOR_1    = 212921,
    BG_TTP_OBJECT_TYPE_DOOR_2    = 212921,
    BG_TTP_OBJECT_TYPE_BUFF_1    = 184663,
    BG_TTP_OBJECT_TYPE_BUFF_2    = 184664
};

class BattlegroundTTP : public Battleground
{
public:
    BattlegroundTTP();
    ~BattlegroundTTP();

    /* inherited from BattlegroundClass */
    void AddPlayer(Player* player) override;
    void OnInvite(Player* player, GroupQueueInfo const* ginfo) override;
    void StartingEventCloseDoors() override;
    void StartingEventOpenDoors() override;

    void RemovePlayer(Player* player, uint64 guid, uint32 team);
    void HandleAreaTrigger(Player* Source, uint32 Trigger);
    bool SetupBattleground();
    void FillInitialWorldStates(WorldStateBuilder& builder) override;
    void HandleKillPlayer(Player* player, Player* killer) override;
    bool HandlePlayerUnderMap(Player* player) override;
};
#endif
