#ifndef BATTLEGROUND_TV_H
#define BATTLEGROUND_TV_H

#include "Battleground.h"

enum BattlegroundTVObjectTypes
{
    BG_TV_OBJECT_DOOR_1         = 0,
    BG_TV_OBJECT_DOOR_2         = 1,
    BG_TV_OBJECT_BUFF_1         = 2,
    BG_TV_OBJECT_BUFF_2         = 3,
    BG_TV_OBJECT_MAX            = 4
};

enum BattlegroundTVObjects
{
    BG_TV_OBJECT_TYPE_DOOR_1    = 213196,
    BG_TV_OBJECT_TYPE_DOOR_2    = 213197,
    BG_TV_OBJECT_TYPE_BUFF_1    = 184663,
    BG_TV_OBJECT_TYPE_BUFF_2    = 184664
};

struct BattlegroundTVScore : public BattlegroundScore
{
};

class BattlegroundTV : public Battleground
{
public:
    BattlegroundTV();
    ~BattlegroundTV();

    /* inherited from BattlegroundClass */
    void AddPlayer(Player* player) override;
    void OnInvite(Player* player, GroupQueueInfo const* ginfo) override;
    void StartingEventCloseDoors() override;
    void StartingEventOpenDoors() override;

    void RemovePlayer(Player* player, uint64 guid, uint32 team);
    void HandleAreaTrigger(Player* Source, uint32 Trigger);
    bool SetupBattleground();
    void Reset() override;
    void FillInitialWorldStates(WorldStateBuilder& builder) override;
    void HandleKillPlayer(Player* player, Player* killer);
    bool HandlePlayerUnderMap(Player* player);
};
#endif
