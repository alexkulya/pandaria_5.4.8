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

#include "ScriptPCH.h"
#include "MapManager.h"
#include "World.h"
#include "GameEventMgr.h"
#include "Chat.h"
#include "Object.h"
#include "PassiveAI.h"

namespace AFDRoyale {
WorldLocation const DropCenter { 37, 179.298798f, 11.457070f, 600.0f };
WorldLocation const RingCenter { 37, 179.298798f, 11.457070f, 237.332336f };
float const RingDistances[]  = { 600.0f, 600.0f, 500.0f, 400.0f, 300.0f, 200.0f, 100.0f,  50.0f,  25.0f,  15.0f,  10.0f,   5.0f,   0.0f,   0.0f };
uint32 const RingTimersPct[] = {      0,     10,     25,     40,     54,     67,     80,     87,     91,     93,     94,     95,    100,    100 };
float const RingMultiplierDistance = 19.05f;

template<typename T> T percentage(T value, T total) { return (value * 100) / total; }
template<typename T> T clamp(T value, T min, T max) { return std::min(max, std::max(min, value)); }
template<typename From, typename To> To linear_map(From value, From fromMin, From fromMax, To toMin, To toMax) { return toMin + (value - fromMin) * (toMax - toMin) / (fromMax - fromMin); }

enum
{
    // Game
    SPELL_IN_GAME                   = 100114,
    SPELL_IN_MAP                    = 100115, // spell_area
    SPELL_LEAVING_GAME              = 100116,
    SPELL_WINNER_VISUAL             = 70571,
    SPELL_FIREWORKS_1               = 11543,
    SPELL_FIREWORKS_2               = 11544,
    SPELL_FIREWORKS_3               = 30161,

    // Drop
    SPELL_DROP                      = 100117,
    SPELL_COSMETIC_PARACHUTE        = 56093,
    SPELL_FEATHERFALL_PARACHUTE     = 50553,
    SPELL_FLAG_VISUAL               = 53797,

    // Ring
    SPELL_RING_VISUAL               = 63894,
    SPELL_OUT_OF_RING_VISUAL        = 50224,
    SPELL_OUT_OF_RING_DAMAGE_AURA   = 100118,
    SPELL_OUT_OF_RING_DAMAGE_VISUAL = 49853,
    SPELL_RING_HEALING_SUPPRESSION  = 30843,

    // Buffs
    SPELL_BUFF_BERSERK_TRIGGER      = 100119,
    SPELL_BUFF_BERSERK              = 14744,
    SPELL_BUFF_SPEED_TRIGGER        = 100120,
    SPELL_BUFF_SPEED_RUN            = 62375,
    SPELL_BUFF_SPEED_MOUNT          = 100121,
    SPELL_BUFF_FOOD_TRIGGER         = 100122,
    SPELL_BUFF_FOOD_HEAL            = 23965,
    SPELL_BUFF_FOOD_ENERGIZE        = 60628,
    SPELL_BUFF_FOOD_DEFEND          = 33962,
    SPELL_BUFF_SIGHT_TRIGGER        = 100123,
    SPELL_BUFF_SIGHT                = 100124,
    SPELL_PORTAL_TRIGGER            = 100125,
    SPELL_PORTAL_VISUAL             = 41232,

    // Creatures
    NPC_CONTROLLER                  = 170000,
    NPC_RING                        = 170001,
    NPC_FIREWORKS                   = 170002,

    // GameObjects
    GO_BUFF_BERSERK                 = 500400,
    GO_BUFF_SPEED                   = 500401,
    GO_BUFF_FOOD                    = 500402,
    GO_BUFF_SIGHT                   = 500403,
    GO_PORTAL                       = 500404,
    GO_PORTAL_TARGET                = 500405,

    // Sounds
    SOUND_START                     = 8463,
    SOUND_DEATH                     = 9283,
    SOUND_BUFF_BERSERK              = 4120,
    SOUND_BUFF_SPEED                = 3339,
    SOUND_BUFF_SIGHT                = 1517,
    SOUND_BUFF_SIGHT_PERSONAL       = 12985,
    SOUND_VICTORY_HORDE             = 8454,
    SOUND_VICTORY_ALLIANCE          = 8455,
    MUSIC_DROP                      = 15120,

    // Spell Visuals
    SPELL_VISUAL_KIT_DEATH          = 7773,

    // Menu
    MENU_ROYALE = 61362234,
    ACTION_ROYALE_QUEUE = 0,
    ACTION_ROYALE_LEAVE_QUEUE,
    ACTION_ROYALE_LEAVE_GAME,
};

enum Config
{
    CONFIG_MIN_PLAYERS          = 62396534,
    CONFIG_GAME_DURATION        = 50854629,
    CONFIG_PREPARATION_TIMER    = 12895202,
    CONFIG_ENDING_TIMER         = 69264942,
    CONFIG_RING_UPDATE_TIMER    = 72356234,
    CONFIG_RING_VISUAL_COUNT    = 52955302,
    CONFIG_CURRENT_STATE        = 62395624,
    CONFIG_CHANGE_STATE         = 92659233,
    CONFIG_CURRENT_GAMETIME     = 76628251,
    CONFIG_CHANGE_GAMETIME      = 39766102,
    CONFIG_RING_DPS_PCT         = 78269651,
    CONFIG_RING_DPS_DENOM       = 23281458,
    CONFIG_RING_DPS_HIGH_TICK   = 19927314,
    CONFIG_RING_DPS_HIGH_TIME   = 57287718,
    CONFIG_RING_DPS_HIGH_TIME_T = 85233412,
    CONFIG_RING_SUPPRESSION_TIME= 92658857,
    CONFIG_RING_SUPPRESSION_PCT = 68552712,
    CONFIG_DROP_SPEED           = 58460821,
    CONFIG_BUFF_BERSERK_DMG_PCT = 76722912,
    CONFIG_BUFF_BERSERK_DUR     = 53846515,
    CONFIG_BUFF_BERSERK_SCALE   = 76722913,
    CONFIG_BUFF_SPEED_RUN_PCT   = 44146973,
    CONFIG_BUFF_SPEED_MOUNT_PCT = 50376522,
    CONFIG_BUFF_SPEED_DUR       = 93657857,
    CONFIG_BUFF_FOOD_HEAL_PCT   = 75633334,
    CONFIG_BUFF_FOOD_MANA_PCT   = 29646742,
    CONFIG_BUFF_FOOD_DEF_PCT    = 82623534,
    CONFIG_BUFF_FOOD_DEF_DUR    = 90283553,
    CONFIG_BUFF_SIGHT_DETECT    = 52752521,
    CONFIG_BUFF_SIGHT_DUR       = 24114733,
    CONFIG_PORTALS_MAX_COUNT    = 56662360,
    CONFIG_LOOT_PROB_BERSERK    = 34623533,
    CONFIG_LOOT_PROB_SPEED      = 83417255,
    CONFIG_LOOT_PROB_FOOD       = 97390462,
    CONFIG_LOOT_PROB_SIGHT      = 80985444,
    CONFIG_LOOT_DURATION        = 57252022,
    CONFIG_REWARD_ID            = 72267723,
    CONFIG_REWARD_COUNT         = 93210010,
};

class Game
{
    public:
        enum class State
        {
            Queue,
            Preparing,
            InProgress,
            Ending,
        };

        static Game* instance()
        {
            static Game _instance;
            return &_instance;
        }

        Game()
        {
            m_spawnedCreatures.reserve(100);

            AreaTableEntry* area = const_cast<AreaTableEntry*>(sAreaTableStore.LookupEntry(268));
            area->flags |= AREA_FLAG_ARENA;

            GetConfig(CONFIG_MIN_PLAYERS)           = 10;
            GetConfig(CONFIG_GAME_DURATION)         = 8 * MINUTE * IN_MILLISECONDS;
            GetConfig(CONFIG_PREPARATION_TIMER)     = 30 * IN_MILLISECONDS;
            GetConfig(CONFIG_ENDING_TIMER)          = 35 * IN_MILLISECONDS;
            GetConfig(CONFIG_RING_UPDATE_TIMER)     = 2500;
            GetConfig(CONFIG_RING_VISUAL_COUNT)     = 3;
            GetConfig(CONFIG_RING_DPS_PCT)          = 1;
            GetConfig(CONFIG_RING_DPS_DENOM)        = 2;
            GetConfig(CONFIG_RING_DPS_HIGH_TICK)    = 30;
            GetConfig(CONFIG_RING_DPS_HIGH_TIME)    = 85,
            GetConfig(CONFIG_RING_DPS_HIGH_TIME_T)  = 10,
            GetConfig(CONFIG_RING_SUPPRESSION_TIME) = 80;
            GetConfig(CONFIG_RING_SUPPRESSION_PCT)  = 100;
            GetConfig(CONFIG_DROP_SPEED)            = 8;
            GetConfig(CONFIG_BUFF_BERSERK_DMG_PCT)  = 5;
            GetConfig(CONFIG_BUFF_BERSERK_DUR)      = 30 * MINUTE * IN_MILLISECONDS;
            GetConfig(CONFIG_BUFF_BERSERK_SCALE)    = 1;
            GetConfig(CONFIG_BUFF_SPEED_RUN_PCT)    = 100,
            GetConfig(CONFIG_BUFF_SPEED_MOUNT_PCT)  = 50,
            GetConfig(CONFIG_BUFF_SPEED_DUR)        = 10 * IN_MILLISECONDS,
            GetConfig(CONFIG_BUFF_FOOD_HEAL_PCT)    = 100,
            GetConfig(CONFIG_BUFF_FOOD_MANA_PCT)    = 100,
            GetConfig(CONFIG_BUFF_FOOD_DEF_PCT)     = 5;
            GetConfig(CONFIG_BUFF_FOOD_DEF_DUR)     = 30 * MINUTE * IN_MILLISECONDS;
            GetConfig(CONFIG_BUFF_SIGHT_DETECT)     = 100,
            GetConfig(CONFIG_BUFF_SIGHT_DUR)        = 5 * MINUTE * IN_MILLISECONDS;
            GetConfig(CONFIG_PORTALS_MAX_COUNT)     = 8;
            GetConfig(CONFIG_LOOT_PROB_BERSERK)     = 9;
            GetConfig(CONFIG_LOOT_PROB_SPEED)       = 5;
            GetConfig(CONFIG_LOOT_PROB_FOOD)        = 5;
            GetConfig(CONFIG_LOOT_PROB_SIGHT)       = 1;
            GetConfig(CONFIG_LOOT_DURATION)         = 30;
            GetConfig(CONFIG_REWARD_ID)             = 32548;
            GetConfig(CONFIG_REWARD_COUNT)          = 1;
        }

        uint32& GetConfig(Config cfg) const { return sWorld->GetDebugValue(cfg).UInt32; }

        State GetState() const { return m_state; }
        uint32 GetTimeUntilNextGame() const
        {
            switch (m_state)
            {
                default:
                case State::Queue:      return 0;
                case State::Preparing:  return m_preparationTimer;
                case State::InProgress: return GetConfig(CONFIG_GAME_DURATION) - std::min(GetConfig(CONFIG_GAME_DURATION), m_gameTime) + GetConfig(CONFIG_ENDING_TIMER);
                case State::Ending:     return m_endingTimer;
            }
        }

        bool IsPlayerInGame(Player* player) const { return m_gamePlayers.find(player->GetGUID()) != m_gamePlayers.end(); }
        uint32 GetGamePlayersCount() const { return m_gamePlayers.size(); }

        uint32 GetQueuedPlayersCount() const { return m_queuedPlayers.size(); }
        uint32 IsPlayerInQueue(Player* player) const { return m_queuedPlayers.find(player->GetGUID()) != m_queuedPlayers.end(); }
        void EnterQueue(Player* player)
        {
            m_queuedPlayers.insert(player->GetGUID());
        }
        void LeaveQueue(Player* player)
        {
            m_queuedPlayers.erase(player->GetGUID());
        }
        void LeaveGame(Player* player)
        {
            m_gamePlayers.erase(player->GetGUID());
            m_deadPlayers.erase(player->GetGUID());

            player->RemoveAurasDueToSpell(SPELL_IN_GAME);
            //player->RemoveAurasDueToSpell(SPELL_IN_MAP);
            //player->RemoveAurasDueToSpell(SPELL_LEAVING_GAME);
            player->RemoveAurasDueToSpell(SPELL_WINNER_VISUAL);
            player->RemoveAurasDueToSpell(SPELL_DROP);
            player->RemoveAurasDueToSpell(SPELL_COSMETIC_PARACHUTE);
            player->RemoveAurasDueToSpell(SPELL_FEATHERFALL_PARACHUTE);
            player->RemoveAurasDueToSpell(SPELL_FLAG_VISUAL);
            player->RemoveAurasDueToSpell(SPELL_OUT_OF_RING_VISUAL);
            player->RemoveAurasDueToSpell(SPELL_OUT_OF_RING_DAMAGE_AURA);
            player->RemoveAurasDueToSpell(SPELL_RING_HEALING_SUPPRESSION);
            player->RemoveAurasDueToSpell(SPELL_BUFF_BERSERK_TRIGGER);
            player->RemoveAurasDueToSpell(SPELL_BUFF_BERSERK);
            player->RemoveAurasDueToSpell(SPELL_BUFF_SPEED_TRIGGER);
            player->RemoveAurasDueToSpell(SPELL_BUFF_SPEED_RUN);
            player->RemoveAurasDueToSpell(SPELL_BUFF_SPEED_MOUNT);
            player->RemoveAurasDueToSpell(SPELL_BUFF_FOOD_TRIGGER);
            player->RemoveAurasDueToSpell(SPELL_BUFF_FOOD_HEAL);
            player->RemoveAurasDueToSpell(SPELL_BUFF_FOOD_ENERGIZE);
            player->RemoveAurasDueToSpell(SPELL_BUFF_FOOD_DEFEND);
            player->RemoveAurasDueToSpell(SPELL_BUFF_SIGHT_TRIGGER);
            player->RemoveAurasDueToSpell(SPELL_BUFF_SIGHT);

            if (player->FindMap() == GetMap())
            {
                if (player->isDead())
                    player->ResurrectPlayer(100.0f);
                if (!player->TeleportToBGEntryPoint())
                    player->TeleportTo(player->m_homebindMapId, player->m_homebindX, player->m_homebindY, player->m_homebindZ, 0.0f);
            }
        }

        bool CanJoin(Player* player)
        {
            if (player->IsGameMaster())
                return false;

            if (player->InBattleground())
                return false;

            if (!player->IsAlive())
                return false;

            return true;
        }

        void UpdateState(uint32 diff)
        {
            GetConfig(CONFIG_CURRENT_STATE) = (uint32)m_state;
            if (uint32& change = GetConfig(CONFIG_CHANGE_STATE))
            {
                ChangeState((State)change);
                change = 0;
            }

            switch (m_state)
            {
                case State::Queue:
                {
                    if (!sWorld->getBoolConfig(CONFIG_ICORE_ROYALE_EVENT_ENABLED))
                        return;

                    std::vector<uint64> toRemove;
                    for (auto&& guid : m_queuedPlayers)
                    {
                        if (Player* player = ObjectAccessor::FindPlayerInOrOutOfWorld(guid))
                        {
                            if (!CanJoin(player))
                                toRemove.push_back(guid);
                        }
                        else
                            toRemove.push_back(guid);
                    }

                    for (auto&& guid : toRemove)
                        m_queuedPlayers.erase(guid);

                    if (GetQueuedPlayersCount() >= GetConfig(CONFIG_MIN_PLAYERS))
                        PrepareGame();
                    break;
                }
                case State::Preparing:
                    if (m_preparationTimer >= diff)
                        m_preparationTimer -= diff;
                    else
                        StartGame();
                    break;
                case State::InProgress:
                    UpdateGame(diff);
                    break;
                case State::Ending:
                    if (m_endingTimer >= diff)
                        m_endingTimer -= diff;
                    else
                        ResetGame();
                    break;
            }
        }

        Map* GetMap() const { return sMapMgr->CreateBaseMap(DropCenter.GetMapId()); }
        Creature* GetController() const { return GetMap()->GetCreature(m_controllerGUID); }
        Creature* GetRing(uint32 index = 0) const { return index < m_ringGUIDs.size() ? GetMap()->GetCreature(m_ringGUIDs[index]) : nullptr; }
        Position const* GetRandomPortalTarget() const { return GetMap()->GetGameObject(Trinity::Containers::SelectRandomContainerElement(m_portalTargetGUIDs)); }

        bool IsRingPoweredUp() const { return m_ringPowerUpWarning; }

    private:
        State m_state = State::Queue;
        std::set<uint64> m_gamePlayers;
        std::set<uint64> m_deadPlayers;
        std::set<uint64> m_queuedPlayers;
        uint32 m_preparationTimer;
        uint32 m_gameTime;
        uint32 m_ringUpdateTimer;
        bool m_ringWarning;
        bool m_ringHealingSuppresionWarning;
        bool m_ringPowerUpWarning;
        uint32 m_endingTimer;

        std::vector<uint64> m_spawnedCreatures;
        uint64 m_controllerGUID = 0;
        std::vector<uint64> m_ringGUIDs;

        std::vector<uint64> m_buffGUIDs;
        std::vector<uint64> m_portalGUIDs;
        std::vector<uint64> m_portalTargetGUIDs;

        void ChangeState(State state)
        {
            switch (state)
            {
                case State::Queue:
                    m_gamePlayers.clear();
                    m_deadPlayers.clear();
                    m_spawnedCreatures.clear();
                    m_controllerGUID = 0;
                    m_ringGUIDs.clear();
                    break;
                case State::Preparing:
                    m_preparationTimer = GetConfig(CONFIG_PREPARATION_TIMER);
                    break;
                case State::InProgress:
                    m_queuedPlayers.clear();
                    m_gameTime = 0;
                    m_ringUpdateTimer = 0;
                    m_ringWarning = false;
                    m_ringHealingSuppresionWarning = false;
                    m_ringPowerUpWarning = false;
                    break;
                case State::Ending:
                    m_endingTimer = GetConfig(CONFIG_ENDING_TIMER);
                    break;
            }
            m_state = state;
        }

        void PrepareGame()
        {
            for (auto&& guid : m_queuedPlayers)
            {
                if (Player* player = ObjectAccessor::FindPlayer(guid))
                {
                    if (!CanJoin(player))
                        continue;

                    player->MonsterWhisper(Format("Игра на рояле начнётся через %u |4секунду:секунды:секунд;!\nЭто последний шанс выйти из очереди", GetConfig(CONFIG_PREPARATION_TIMER) / IN_MILLISECONDS).c_str(), player, true);
                }
            }

            // Increase visibility in map
            GetMap()->SetVisibilityRange(1000.0f);

            // Preload grids
            for (float x = -1056.0f; x < 1587.0f; x += SIZE_OF_GRIDS)
                for (float y = -1588.0f; y < 1587.0f; y += SIZE_OF_GRIDS)
                    GetMap()->LoadGrid(x, y);

            // Spawn controller and ring(s)
            SummonCreature(NPC_CONTROLLER, RingCenter, &m_controllerGUID);
            m_ringGUIDs.resize(GetConfig(CONFIG_RING_VISUAL_COUNT));
            uint32 i = 0;
            for (auto&& guid : m_ringGUIDs)
            {
                if (Creature* ring = SummonCreature(NPC_RING, RingCenter, &guid))
                {
                    ring->SetFacingTo((2 * M_PI / m_ringGUIDs.size()) * i++);
                    ring->SetObjectScale(RingDistances[0] / RingMultiplierDistance);
                }
            }

            // Gather buff and portal GUIDs
            if (m_buffGUIDs.empty())
            {
                for (auto&& cell : sObjectMgr->GetMapObjectGuids(GetMap()->GetId(), REGULAR_DIFFICULTY))
                {
                    for (auto&& guid : cell.second.gameobjects)
                    {
                        if (GameObjectData const* data = sObjectMgr->GetGOData(guid))
                        {
                            switch (data->id)
                            {
                                case GO_BUFF_BERSERK:
                                case GO_BUFF_SPEED:
                                case GO_BUFF_FOOD:
                                case GO_BUFF_SIGHT:
                                    m_buffGUIDs.push_back(MAKE_NEW_GUID(guid, data->id, HIGHGUID_GAMEOBJECT));
                                    break;
                                case GO_PORTAL:
                                    m_portalGUIDs.push_back(MAKE_NEW_GUID(guid, data->id, HIGHGUID_GAMEOBJECT));
                                    break;
                                case GO_PORTAL_TARGET:
                                    m_portalTargetGUIDs.push_back(MAKE_NEW_GUID(guid, data->id, HIGHGUID_GAMEOBJECT));
                                    break;
                            }
                        }
                    }
                }
            }

            // Respawn buffs
            for (auto&& guid : m_buffGUIDs)
                if (GameObject* buff = GetMap()->GetGameObject(guid))
                    buff->Respawn();

            // Despawn portals
            for (auto&& guid : m_portalGUIDs)
                if (GameObject* portal = GetMap()->GetGameObject(guid))
                    portal->ForcedDespawn();

            // Respawn random portals
            std::list<uint64> activePortals;
            std::copy(m_portalGUIDs.begin(), m_portalGUIDs.end(), std::back_inserter(activePortals));
            Trinity::Containers::RandomResizeList(activePortals, GetConfig(CONFIG_PORTALS_MAX_COUNT));
            for (auto&& guid : activePortals)
                if (GameObject* portal = GetMap()->GetGameObject(guid))
                    portal->Respawn();

            ChangeState(State::Preparing);
        }

        void StartGame()
        {
            for (auto&& guid : m_queuedPlayers)
            {
                if (Player* player = ObjectAccessor::FindPlayer(guid))
                {
                    if (!CanJoin(player))
                        continue;

                    WorldLocation loc
                    {
                        DropCenter.GetMapId(),
                        DropCenter.GetPositionX(),
                        DropCenter.GetPositionY(),
                        DropCenter.GetPositionZ(),
                        frand(0, 2 * M_PI)
                    };
                    player->PlayDirectSound(SOUND_START, player);
                    player->AddAura(SPELL_IN_GAME, player);
                    player->SetBattlegroundEntryPoint();
                    player->TeleportTo(loc);
                    m_gamePlayers.insert(guid);
                }
            }

            ChangeState(State::InProgress);
        }

        void UpdateGame(uint32 diff)
        {
            GetConfig(CONFIG_CURRENT_GAMETIME) = m_gameTime;
            if (uint32& change = GetConfig(CONFIG_CHANGE_GAMETIME))
            {
                m_gameTime = change;
                change = 0;
            }

            m_gameTime = clamp<float>(m_gameTime + diff, 0, GetConfig(CONFIG_GAME_DURATION));
            float gamePercent = percentage<float>(m_gameTime, GetConfig(CONFIG_GAME_DURATION));

            float ringDistance = [&]
            {
                auto itr = std::find_if(std::begin(RingTimersPct), std::end(RingTimersPct), [gamePercent](uint32 pct) { return pct > gamePercent; });
                if (itr == std::end(RingTimersPct))
                    return 0.0f;

                uint32 index = std::distance(std::begin(RingTimersPct), itr);
                if (!index)
                    return 0.0f;

                return linear_map<float, float>(gamePercent, RingTimersPct[index - 1], RingTimersPct[index], RingDistances[index - 1], RingDistances[index]);
            }();

            if (m_ringUpdateTimer <= diff)
            {
                if (!m_ringWarning && ringDistance < RingDistances[0])
                {
                    m_ringWarning = true;
                    for (auto&& ref : GetMap()->GetPlayers())
                        if (Player* player = ref.GetSource())
                            player->MonsterWhisper("|cFF54D15BКруг начинает сужаться!|r", player, true);
                }

                m_ringUpdateTimer = GetConfig(CONFIG_RING_UPDATE_TIMER);
                for (uint32 i = 0; i < m_ringGUIDs.size(); ++i)
                {
                    if (Creature* ring = GetRing(i))
                    {
                        ring->SetObjectScale(ringDistance / RingMultiplierDistance);
                        if (i > 0 && ringDistance < 100.0f)
                        {
                            ring->DespawnOrUnsummon();
                            m_ringGUIDs[i] = 0;
                        }
                    }
                }
            }
            else
                m_ringUpdateTimer -= diff;

            if (!m_ringHealingSuppresionWarning && gamePercent >= GetConfig(CONFIG_RING_SUPPRESSION_TIME))
            {
                m_ringHealingSuppresionWarning = true;
                for (auto&& ref : GetMap()->GetPlayers())
                    if (Player* player = ref.GetSource())
                        player->MonsterWhisper("|cFF54D15BКруг начинает подавлять вашу силу исцеления!|r", player, true);
            }

            if (!m_ringPowerUpWarning && gamePercent >= GetConfig(CONFIG_RING_DPS_HIGH_TIME))
            {
                m_ringPowerUpWarning = true;
                for (auto&& ref : GetMap()->GetPlayers())
                    if (Player* player = ref.GetSource())
                        player->MonsterWhisper("|cFF54D15BУрон от круга усиливается!|r", player, true);
            }

            std::vector<uint64> guids;
            for (auto&& ref : GetMap()->GetPlayers())
                if (Player* player = ref.GetSource())
                    if (player->IsInWorld() && player->FindMap() == GetMap() && !player->IsGameMaster())
                        guids.push_back(player->GetGUID());

            Player* lastPlayer = nullptr;
            bool onlySurvivor = true;
            uint32 playersRemaining = std::count_if(guids.begin(), guids.end(), [this](uint64 guid) { return m_gamePlayers.find(guid) != m_gamePlayers.end() && m_deadPlayers.find(guid) == m_deadPlayers.end(); });
            for (auto&& guid : guids)
            {
                Player* player = ObjectAccessor::FindPlayer(guid);
                if (!player)
                    continue;

                // Teleport out wrong players
                if (!player->HasAura(SPELL_IN_GAME))
                {
                    if (m_gamePlayers.find(guid) != m_gamePlayers.end())
                    {
                        --playersRemaining;
                        SendMapWideSystemMessage(Format("%s %s из игры. Осталось в живых: %u", player->GetName().c_str(), player->GetGender() == GENDER_MALE ? "выбыл" : "выбыла", playersRemaining));
                    }

                    LeaveGame(player);
                    continue;
                }

                // Remove priest's Spirit of Redemption
                if (player->HasAura(27827))
                    player->RemoveAurasDueToSpell(27827);

                // Teleport out dead players
                if (!player->IsAlive() && !player->HasAura(SPELL_LEAVING_GAME))
                {
                    m_deadPlayers.insert(guid);

                    std::map<uint32, Config> lootBuffs =
                    {
                        { GO_BUFF_BERSERK, CONFIG_LOOT_PROB_BERSERK },
                        { GO_BUFF_SPEED,   CONFIG_LOOT_PROB_SPEED   },
                        { GO_BUFF_FOOD,    CONFIG_LOOT_PROB_FOOD    },
                        { GO_BUFF_SIGHT,   CONFIG_LOOT_PROB_SIGHT   },
                    };
                    std::function<double(std::pair<uint32, Config> const&)> f = [this](std::pair<uint32, Config> const& loot) -> double { return GetConfig(loot.second); };
                    auto lootBuff = Trinity::Containers::SelectRandomWeightedContainerElement(lootBuffs, f);
                    if (Creature* controller = GetController())
                        if (GameObject* loot = controller->SummonGameObject(lootBuff->first, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation(), { }, GetConfig(CONFIG_LOOT_DURATION)))
                            loot->SetOwnerGUID(0);

                    --playersRemaining;
                    SendMapWideSystemMessage(Format("%s %s%s. Осталось в живых: %u",
                        player->GetName().c_str(),
                        roll_chance_i(5) ? (RAND<char const*>("трагически ", "поэтически ", "глупо ", "позорно ", "смешно ", "бездарно ", "уныло ", "- представляете? - ", "грациозно ", "красиво ", "филигранно ")) : "",
                        player->GetGender() == GENDER_MALE ? "умер" : "умерла",
                        playersRemaining));

                    player->SendPlaySpellVisualKit(player->GetGUID(), 1, SPELL_VISUAL_KIT_DEATH);
                    player->PlayDirectSound(SOUND_DEATH);

                    player->AddAura(SPELL_LEAVING_GAME, player);
                    player->MonsterWhisper(Format("Вы умерли, дожив до %u-го места", playersRemaining + 1).c_str(), player, true);
                    ChatHandler(player).PSendSysMessage("Вы покинете битву через 10 секунд");
                    continue;
                }

                if (player->IsAlive() && player->HasAura(SPELL_LEAVING_GAME))
                {
                    m_deadPlayers.erase(guid);

                    ++playersRemaining;
                    SendMapWideSystemMessage(Format("%s %s. Осталось в живых: %u", player->GetName().c_str(), player->GetGender() == GENDER_MALE ? "ожил" : "ожила", playersRemaining));

                    player->RemoveAurasDueToSpell(SPELL_LEAVING_GAME);
                    player->MonsterWhisper("Вы ожили! Это чудо! Продолжаем играть...", player, true);
                }

                // Handle out of ring players
                if (player->IsAlive())
                {
                    bool outOfRing = player->GetExactDist(&RingCenter) >= ringDistance;

                    if (player->HasAura(SPELL_OUT_OF_RING_DAMAGE_AURA) != outOfRing)
                    {
                        if (outOfRing)
                        {
                            player->AddAura(SPELL_OUT_OF_RING_VISUAL, player);
                            if (Creature* ring = GetRing())
                                ring->AddAura(SPELL_OUT_OF_RING_DAMAGE_AURA, player);
                        }
                        else
                        {
                            player->RemoveAurasDueToSpell(SPELL_OUT_OF_RING_VISUAL);
                            player->RemoveAurasDueToSpell(SPELL_OUT_OF_RING_DAMAGE_AURA);
                        }
                    }

                    if (m_ringHealingSuppresionWarning && (player->HasAura(SPELL_RING_HEALING_SUPPRESSION) != outOfRing))
                    {
                        if (outOfRing)
                        {
                            if (Creature* ring = GetRing())
                                ring->AddAura(SPELL_RING_HEALING_SUPPRESSION, player);
                            if (Aura* aura = player->GetAura(SPELL_RING_HEALING_SUPPRESSION))
                            {
                                aura->SetMaxDuration(-1);
                                aura->SetDuration(-1);
                                for (uint32 i = 0; i < 2; ++i)
                                    if (AuraEffect* effect = aura->GetEffect(i))
                                        effect->SetAmount(-(int32)GetConfig(CONFIG_RING_SUPPRESSION_PCT));
                            }
                        }
                        else
                        {
                            player->RemoveAurasDueToSpell(SPELL_RING_HEALING_SUPPRESSION);
                        }
                    }
                }

                if (player->IsAlive())
                {
                    if (!lastPlayer)
                        lastPlayer = player;
                    else
                        onlySurvivor = false;
                }
            }

            // Let some time pass so we can be sure all the players have loaded into the map
            if (m_gameTime >= 1 * MINUTE * IN_MILLISECONDS)
            {
                // Give victory to last surviving player
                if (lastPlayer && onlySurvivor && !lastPlayer->HasAura(SPELL_LEAVING_GAME))
                {
                    Player* player = lastPlayer;

                    sLog->outError("AFD Royale Winner: %s (GUID: %u)", player->GetName().c_str(), player->GetGUIDLow());

                    player->SetFullHealth();
                    player->AddAura(SPELL_WINNER_VISUAL, player);
                    player->AddAura(SPELL_LEAVING_GAME, player);
                    if (Aura* aura = player->GetAura(SPELL_LEAVING_GAME))
                    {
                        aura->SetMaxDuration(30 * IN_MILLISECONDS);
                        aura->SetDuration(30 * IN_MILLISECONDS);
                    }
                    player->MonsterWhisper("Вы победили!", player, true);

                    SendMapWideSystemMessage(Format("%s %s в битве!", player->GetName().c_str(), player->GetGender() == GENDER_MALE ? "победил" : "победила"));

                    uint32 minutes = ((m_gameTime / IN_MILLISECONDS) + MINUTE - 1) / MINUTE;
                    sWorld->SendGlobalText(Format("Лучший игрец на рояле за %s %u |4минуту:минуты:минут;: %s", (minutes % 10) == 1 ? "последнюю" : "последние", minutes, player->GetName().c_str()).c_str(), player->GetSession());

                    player->PlayDirectSound(player->GetTeam() == ALLIANCE ? SOUND_VICTORY_ALLIANCE : SOUND_VICTORY_HORDE, player);

                    if (uint32 reward = GetConfig(CONFIG_REWARD_ID))
                    {
                        uint32 count = GetConfig(CONFIG_REWARD_COUNT);

                        if (ItemTemplate const* proto = sObjectMgr->GetItemTemplate(reward))
                        {
                            std::string name = proto->Name1;
                            if (ItemLocale const* locale = sObjectMgr->GetItemLocale(proto->ItemId))
                                sObjectMgr->GetLocaleString(locale->Name, player->GetSession()->GetSessionDbLocaleIndex(), name);

                            char const* icon = "";
                            if (ItemDisplayInfoEntry const* display = sItemDisplayInfoStore.LookupEntry(proto->DisplayInfoID))
                                icon = display->inventoryIcon[LOCALE_enUS];

                            player->MonsterWhisper(Format("Ваша награда: |c%x%s|TInterface/Icons/%s:0|t|Hitem:%u:%u:%u:%u:%u:%u:%d:%u:%u|h[%s]|h|r",
                                ItemQualityColors[proto->Quality],
                                count > 1 ? Format("%u x ", count).c_str() : "",
                                icon,
                                proto->ItemId, 0, 0, 0, 0, 0, 0, 0, uint32(player->GetLevel()),
                                name.c_str()).c_str(), player, true);
                        }

                        if (!player->AddItem(reward, count))
                        {
                            if (Item* item = Item::CreateItem(reward, count))
                            {
                                SQLTransaction trans = CharacterDatabase.BeginTransaction();
                                item->SaveToDB(trans);

                                LostItemsMailDraft mail { };
                                mail.AddItem(item);
                                mail.SendMailTo(trans, player);
                                CharacterDatabase.CommitTransaction(trans);
                            }
                        }
                    }

                    ChatHandler(player).PSendSysMessage("Вы покинете битву через 30 секунд");

                    EndGame();
                    return;
                }

                // No players remain (i.e. logged out)
                if (guids.empty())
                {
                    EndGame();
                    return;
                }
            }
        }

        void EndGame()
        {
            for (auto&& ref : GetMap()->GetPlayers())
            {
                if (Player* player = ref.GetSource())
                {
                    if (player->IsInWorld() && player->FindMap() == GetMap() && !player->IsGameMaster())
                    {
                        player->RemoveAurasDueToSpell(SPELL_OUT_OF_RING_VISUAL);
                        player->RemoveAurasDueToSpell(SPELL_OUT_OF_RING_DAMAGE_AURA);
                        player->RemoveAurasDueToSpell(SPELL_RING_HEALING_SUPPRESSION);
                        if (!player->HasAura(SPELL_LEAVING_GAME))
                            player->AddAura(SPELL_LEAVING_GAME, player);
                    }
                }
            }

            ChangeState(State::Ending);
        }

        void ResetGame()
        {
            for (auto&& ref : GetMap()->GetPlayers())
                if (Player* player = ref.GetSource())
                    if (player->IsInWorld() && player->FindMap() == GetMap() && !player->IsGameMaster())
                        LeaveGame(player);

            for (auto&& guid : m_spawnedCreatures)
                if (Creature* creature = GetMap()->GetCreature(guid))
                    creature->DespawnOrUnsummon();

            ChangeState(State::Queue);
        }

        Creature* SummonCreature(uint32 entry, Position const& pos, uint64* guid)
        {
            if (Creature* creature = GetMap()->SummonCreature(entry, pos))
            {
                m_spawnedCreatures.push_back(creature->GetGUID());
                if (guid)
                    *guid = creature->GetGUID();
                return creature;
            }
            return nullptr;
        }

        void SendMapWideSystemMessage(std::string const& text)
        {
            WorldPacket data;
            ChatHandler::BuildChatPacket(data, CHAT_MSG_SYSTEM, LANG_UNIVERSAL, 0, 0, text);
            GetMap()->SendToPlayers(&data);
        }
};

}

#define sRoyale (AFDRoyale::Game::instance())

class npc_afd_royale_controller : CreatureScript
{
    public:
        npc_afd_royale_controller() : CreatureScript("npc_afd_royale_controller") { }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_afd_royale_controllerAI(creature);
        }

        struct npc_afd_royale_controllerAI : public ScriptedAI
        {
            npc_afd_royale_controllerAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void UpdateAI(uint32 const diff) override
            {
            }
        };
};

class npc_afd_royale_ring : CreatureScript
{
    public:
        npc_afd_royale_ring() : CreatureScript("npc_afd_royale_ring") { }

        struct npc_afd_royale_ringAI : public NullCreatureAI
        {
            npc_afd_royale_ringAI(Creature* creature) : NullCreatureAI(creature)
            {
                using namespace AFDRoyale;
                me->setActive(true, ActiveFlags::Script);
                me->SetCustomVisibilityDistance(2000.0f, false);
                me->AddAura(SPELL_RING_VISUAL, me);
            }

            void UpdateAI(uint32 diff) override
            {
                using namespace AFDRoyale;
                if (!me->HasAura(SPELL_RING_VISUAL))
                    me->AddAura(SPELL_RING_VISUAL, me);
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_afd_royale_ringAI(creature);
        }
};

class spell_afd_royale_in_map : public SpellScriptLoader
{
    public:
        spell_afd_royale_in_map() : SpellScriptLoader("spell_afd_royale_in_map") { }

        class spell_afd_royale_in_map_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_afd_royale_in_map_AuraScript);

            void HandleApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                using namespace AFDRoyale;

                Unit* target = GetTarget();
                if (!sRoyale->IsPlayerInGame(target->ToPlayer()))
                    return;

                target->AddAura(SPELL_DROP, target);
                target->m_Events.Schedule(500, [target]
                {
                    target->KnockbackFrom(target->GetPositionX(), target->GetPositionY(), sRoyale->GetConfig(CONFIG_DROP_SPEED), 0.0f);
                    target->MonsterWhisper("Отмените бафф |TInterface\\Icons\\Spell_Magic_FeatherFall:32|t для начала посадки!", target->ToPlayer(), true);
                    target->PlayDirectMusic(MUSIC_DROP, target->ToPlayer());
                });
            }

            void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                sRoyale->LeaveGame(GetTarget()->ToPlayer());
            }

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                using namespace AFDRoyale;

                Unit* target = GetTarget();
                if (target->HasAura(SPELL_WINNER_VISUAL))
                {
                    Position pos;
                    target->GetRandomNearPosition(pos, 20.0f);
                    if (Creature* controller = sRoyale->GetController())
                        if (Creature* fireworks = controller->SummonCreature(NPC_FIREWORKS, pos, TEMPSUMMON_TIMED_DESPAWN, 10000))
                            fireworks->CastSpell(fireworks, RAND(SPELL_FIREWORKS_1, SPELL_FIREWORKS_2, SPELL_FIREWORKS_3), true);
                }
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_afd_royale_in_map_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectApplyFn(spell_afd_royale_in_map_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_afd_royale_in_map_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_afd_royale_in_map_AuraScript();
        }
};

class spell_afd_royale_leaving_game : public SpellScriptLoader
{
    public:
        spell_afd_royale_leaving_game() : SpellScriptLoader("spell_afd_royale_leaving_game") { }

        class spell_afd_royale_leaving_game_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_afd_royale_leaving_game_AuraScript);

            void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
                    sRoyale->LeaveGame(GetTarget()->ToPlayer());
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectApplyFn(spell_afd_royale_leaving_game_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_afd_royale_leaving_game_AuraScript();
        }
};

class spell_afd_royale_drop : public SpellScriptLoader
{
    public:
        spell_afd_royale_drop() : SpellScriptLoader("spell_afd_royale_drop") { }

        class spell_afd_royale_drop_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_afd_royale_drop_AuraScript);

            void HandleApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                using namespace AFDRoyale;
                GetTarget()->AddAura(SPELL_COSMETIC_PARACHUTE, GetTarget());
                GetTarget()->AddAura(SPELL_FEATHERFALL_PARACHUTE, GetTarget());
                GetTarget()->AddAura(SPELL_FLAG_VISUAL, GetTarget());
            }

            void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                using namespace AFDRoyale;
                GetTarget()->RemoveAurasDueToSpell(SPELL_COSMETIC_PARACHUTE);
                GetTarget()->RemoveAurasDueToSpell(SPELL_FEATHERFALL_PARACHUTE);
                GetTarget()->RemoveAurasDueToSpell(SPELL_FLAG_VISUAL);
                GetTarget()->PlayDirectMusic(0, GetTarget()->ToPlayer());
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_afd_royale_drop_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_SAFE_FALL, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectApplyFn(spell_afd_royale_drop_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_SAFE_FALL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_afd_royale_drop_AuraScript();
        }
};

class spell_afd_royale_out_of_ring_damage_aura : public SpellScriptLoader
{
    public:
        spell_afd_royale_out_of_ring_damage_aura() : SpellScriptLoader("spell_afd_royale_out_of_ring_damage_aura") { }

        class spell_afd_royale_out_of_ring_damage_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_afd_royale_out_of_ring_damage_aura_AuraScript);

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                using namespace AFDRoyale;

                uint32 tick = aurEff->GetTickNumber();

                if (sRoyale->IsRingPoweredUp())
                    tick += sRoyale->GetConfig(CONFIG_RING_DPS_HIGH_TIME_T);

                if (uint32 high = sRoyale->GetConfig(CONFIG_RING_DPS_HIGH_TICK))
                    if (tick > high)
                        tick += (tick - high) * (tick - high);

                const_cast<AuraEffect*>(aurEff)->SetAmount(std::max(1u, sRoyale->GetConfig(CONFIG_RING_DPS_PCT) * tick / sRoyale->GetConfig(CONFIG_RING_DPS_DENOM)));

                GetTarget()->CastSpell(GetTarget(), SPELL_OUT_OF_RING_DAMAGE_VISUAL, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_afd_royale_out_of_ring_damage_aura_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_afd_royale_out_of_ring_damage_aura_AuraScript();
        }
};

class spell_afd_royale_buff_trigger : public SpellScriptLoader
{
    public:
        spell_afd_royale_buff_trigger() : SpellScriptLoader("spell_afd_royale_buff_trigger") { }

        class spell_afd_royale_buff_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_afd_royale_buff_trigger_SpellScript);

            void CastBuff(Unit* target, uint32 spell, AFDRoyale::Config cfgAmount0, AFDRoyale::Config cfgAmount1 = (AFDRoyale::Config)0, AFDRoyale::Config cfgAmount2 = (AFDRoyale::Config)0)
            {
                int32 bp0 = cfgAmount0 ? sRoyale->GetConfig(cfgAmount0) : 0;
                int32 bp1 = cfgAmount1 ? sRoyale->GetConfig(cfgAmount1) : 0;
                int32 bp2 = cfgAmount2 ? sRoyale->GetConfig(cfgAmount2) : 0;

                if (!bp0 && !bp1 && !bp2)
                    return;

                target->CastCustomSpell(target, spell,
                    cfgAmount0 ? &bp0 : nullptr,
                    cfgAmount1 ? &bp1 : nullptr,
                    cfgAmount2 ? &bp2 : nullptr,
                    true);
            }

            void SetDuration(Unit* target, uint32 spell, AFDRoyale::Config cfgDuration)
            {
                if (Aura* aura = target->GetAura(spell))
                {
                    uint32 duration = sRoyale->GetConfig(cfgDuration);
                    aura->SetMaxDuration(duration);
                    aura->SetDuration(duration);
                }
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                using namespace AFDRoyale;

                Unit* target = GetHitUnit();
                if (!target)
                    return;

                std::array<int32, MAX_SPELL_EFFECTS> amounts { };
                switch (GetSpellInfo()->Id)
                {
                    case SPELL_BUFF_BERSERK_TRIGGER:
                        CastBuff(target, SPELL_BUFF_BERSERK, CONFIG_BUFF_BERSERK_DMG_PCT, CONFIG_BUFF_BERSERK_SCALE);
                        SetDuration(target, SPELL_BUFF_BERSERK, CONFIG_BUFF_BERSERK_DUR);
                        target->PlayDistanceSound(SOUND_BUFF_BERSERK);
                        break;
                    case SPELL_BUFF_SPEED_TRIGGER:
                        if (!target->HasAura(SPELL_BUFF_SPEED_RUN))
                            CastBuff(target, SPELL_BUFF_SPEED_RUN, CONFIG_BUFF_SPEED_RUN_PCT);
                        SetDuration(target, SPELL_BUFF_SPEED_RUN, CONFIG_BUFF_SPEED_DUR);
                        CastBuff(target, SPELL_BUFF_SPEED_MOUNT, CONFIG_BUFF_SPEED_MOUNT_PCT);
                        SetDuration(target, SPELL_BUFF_SPEED_MOUNT, CONFIG_BUFF_SPEED_DUR);
                        target->PlayDistanceSound(SOUND_BUFF_SPEED);
                        break;
                    case SPELL_BUFF_FOOD_TRIGGER:
                        CastBuff(target, SPELL_BUFF_FOOD_HEAL, CONFIG_BUFF_FOOD_HEAL_PCT);
                        CastBuff(target, SPELL_BUFF_FOOD_ENERGIZE, CONFIG_BUFF_FOOD_MANA_PCT);
                        CastBuff(target, SPELL_BUFF_FOOD_DEFEND, CONFIG_BUFF_FOOD_DEF_PCT);
                        SetDuration(target, SPELL_BUFF_FOOD_DEFEND, CONFIG_BUFF_FOOD_DEF_DUR);
                        break;
                    case SPELL_BUFF_SIGHT_TRIGGER:
                        CastBuff(target, SPELL_BUFF_SIGHT, CONFIG_BUFF_SIGHT_DETECT);
                        SetDuration(target, SPELL_BUFF_SIGHT, CONFIG_BUFF_SIGHT_DUR);
                        target->CastSpell(target, 34709, true);
                        target->RemoveAurasDueToSpell(34709);
                        target->MonsterWhisper("|cFF9382C9Вы чувствуете местонахождение других игроков|r", target->ToPlayer(), true);
                        target->PlayDistanceSound(SOUND_BUFF_SIGHT);
                        target->PlayDirectSound(SOUND_BUFF_SIGHT_PERSONAL, target->ToPlayer());
                        break;
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_afd_royale_buff_trigger_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_afd_royale_buff_trigger_SpellScript();
        }
};

class spell_afd_royale_portal_trigger : public SpellScriptLoader
{
    public:
        spell_afd_royale_portal_trigger() : SpellScriptLoader("spell_afd_royale_portal_trigger") { }

        class spell_afd_royale_portal_trigger_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_afd_royale_portal_trigger_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                using namespace AFDRoyale;
                if (Unit* target = GetHitUnit())
                {
                    if (Position const* pos = sRoyale->GetRandomPortalTarget())
                    {
                        target->CastSpell(target, SPELL_PORTAL_VISUAL, true);
                        target->NearTeleportTo(pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), pos->GetOrientation());
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_afd_royale_portal_trigger_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_afd_royale_portal_trigger_SpellScript();
        }
};

inline void AddMenuItem(Player *player, GossipOptionIcon icon, const std::string &msg, uint32 sender, uint32 action, const std::string &mbox = "", uint32 money = 0, bool coded = false)
{
    player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, icon, msg, sender, action, mbox, money, coded);
}

void AFDRoyaleGossipHelloHook(Player* player, Creature* creature)
{
    using namespace AFDRoyale;

    if (sRoyale->IsPlayerInGame(player))
    {
        AddMenuItem(player, GOSSIP_ICON_BATTLE, "Сбежать из рояля\n ", MENU_ROYALE, ACTION_ROYALE_LEAVE_GAME);
    }
    else if (sRoyale->IsPlayerInQueue(player))
    {
        std::string text = Format("\n|cFF593300В очереди: %u/%u|r", sRoyale->GetQueuedPlayersCount(), sRoyale->GetConfig(CONFIG_MIN_PLAYERS));
        if (uint32 time = (sRoyale->GetTimeUntilNextGame() + IN_MILLISECONDS - 1) / IN_MILLISECONDS)
            text += Format("\n|cFF593300Следующая игра через %u %s|r", time >= MINUTE ? (time + MINUTE - 1) / MINUTE : time, time >= MINUTE ? "|4минуту:минуты:минут;" : "|4секунду:секунды:секунд;");

        AddMenuItem(player, GOSSIP_ICON_BATTLE, "Передумать играть на рояле" + text + "\n ", MENU_ROYALE, ACTION_ROYALE_LEAVE_QUEUE);
    }
    else if (sRoyale->CanJoin(player))
    {
        AddMenuItem(player, GOSSIP_ICON_BATTLE, "Сыграть на рояле\n ", MENU_ROYALE, ACTION_ROYALE_QUEUE);
    }
}

bool AFDRoyaleGossipSelectHook(Player* player, Creature* creature, uint32 sender, uint32 action)
{
    using namespace AFDRoyale;

    if (sender != MENU_ROYALE)
        return false;

    switch (action)
    {
        case ACTION_ROYALE_QUEUE:       sRoyale->EnterQueue(player); sScriptMgr->OnGossipHello(player, creature); break;
        case ACTION_ROYALE_LEAVE_QUEUE: sRoyale->LeaveQueue(player); sScriptMgr->OnGossipHello(player, creature); break;
        case ACTION_ROYALE_LEAVE_GAME:  sRoyale->LeaveGame(player); player->CLOSE_GOSSIP_MENU(); break;
    }

    return true;
}

bool AFDRoyaleRepopRequestHook(Player* player)
{
    if (player->FindMap() == sRoyale->GetMap() && sRoyale->IsPlayerInGame(player))
    {
        sRoyale->LeaveGame(player);
        return true;
    }
    return false;
}

bool AFDRoyaleIsSpecialAuraHook(Aura const* aura, Unit const* target)
{
    using namespace AFDRoyale;

    switch (aura->GetId())
    {
        // Custom spells - never save or remove at respec
        case SPELL_IN_GAME:
        case SPELL_IN_MAP:
        case SPELL_LEAVING_GAME:
        case SPELL_DROP:
        case SPELL_OUT_OF_RING_DAMAGE_AURA:
        case SPELL_BUFF_SPEED_MOUNT:
        case SPELL_BUFF_SIGHT:
            return true;

        // Reused in-game spells - don't save and don't remove at respec only if inside the royale map
        case SPELL_WINNER_VISUAL:
        case SPELL_COSMETIC_PARACHUTE:
        case SPELL_FEATHERFALL_PARACHUTE:
        case SPELL_FLAG_VISUAL:
        case SPELL_OUT_OF_RING_VISUAL:
        case SPELL_BUFF_BERSERK:
        case SPELL_BUFF_SPEED_RUN:
        case SPELL_BUFF_FOOD_DEFEND:
        case SPELL_RING_HEALING_SUPPRESSION:
            return target->FindMap() == sRoyale->GetMap();

        default:
            return false;
    }
}

void AFDRoyaleUpdateHook(uint32 diff)
{
    sRoyale->UpdateState(diff);
}

void AddSC_event_afd_royale()
{
    new npc_afd_royale_controller();
    new npc_afd_royale_ring();
    new spell_afd_royale_in_map();
    new spell_afd_royale_leaving_game();
    new spell_afd_royale_drop();
    new spell_afd_royale_out_of_ring_damage_aura();
    new spell_afd_royale_buff_trigger();
    new spell_afd_royale_portal_trigger();
}
