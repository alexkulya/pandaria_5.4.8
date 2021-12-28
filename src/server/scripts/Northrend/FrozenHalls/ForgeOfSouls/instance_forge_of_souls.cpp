/*
 * Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2006-2014 ScriptDev2 <https://github.com/scriptdev2/scriptdev2/>
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

#include "ScriptPCH.h"
#include "forge_of_souls.h"
#include "Group.h"

#define MAX_ENCOUNTER 2

/* Forge of Souls encounters:
 0 - Bronjahm, The Godfather of Souls
 1 - The Devourer of Souls
*/

class instance_forge_of_souls : public InstanceMapScript
{
    public:
        instance_forge_of_souls() : InstanceMapScript(FoSScriptName, 632) { }

        struct instance_forge_of_souls_InstanceScript : public InstanceScript
        {
            instance_forge_of_souls_InstanceScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(MAX_ENCOUNTER);
                uiBronjahm = 0;
                uiDevourer = 0;
                soulFragmentsAlive = 0;

                uiSylvanas_Part1 = 0;
                uiJaina_Part1 = 0;
                uiKalira = 0;
                uiElandra = 0;
                uiLoralen = 0;
                uiKoreln = 0;

                team = TEAM_NEUTRAL;
            }

            void OnPlayerEnter(Player* player) override
            {
                if (player && team == TEAM_NEUTRAL)
                    team = player->GetTeamId();
            }

            TeamId UpdateTeamInInstance() const
            {
                if (team != TEAM_NEUTRAL)
                    return team;

                Map::PlayerList const& players = instance->GetPlayers();
                if (!players.isEmpty())
                    if (Player* player = players.begin()->GetSource())
                        return const_cast<instance_forge_of_souls_InstanceScript*>(this)->team = player->GetTeamId();

                return TEAM_NEUTRAL;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                UpdateTeamInInstance();

                switch (creature->GetEntry())
                {
                    case NPC_BRONJAHM:
                        uiBronjahm = creature->GetGUID();
                        break;
                    case NPC_DEVOURER:
                        uiDevourer = creature->GetGUID();
                        break;
                }
            }

            uint32 GetCreatureEntry(uint32 guidlow, CreatureData const* data) override
            {
                UpdateTeamInInstance();

                switch (data->id)
                {
                    case NPC_JAINA_PART1:
                    case NPC_JAINA_PART2:
                    case NPC_KORELN:
                    case NPC_ELANDRA:
                    case NPC_CHAMPION_1_ALLIANCE:
                    case NPC_CHAMPION_2_ALLIANCE:
                    case NPC_CHAMPION_3_ALLIANCE:
                        if (team != TEAM_ALLIANCE)
                            return 0;
                        break;
                    case NPC_SYLVANAS_PART1:
                    case NPC_SYLVANAS_PART2:
                    case NPC_KALIRA:
                    case NPC_LORALEN:
                    case NPC_CHAMPION_1_HORDE:
                    case NPC_CHAMPION_2_HORDE:
                    case NPC_CHAMPION_3_HORDE:
                        if (team != TEAM_HORDE)
                            return 0;
                        break;
                    default:
                        break;
                }
                return InstanceScript::GetCreatureEntry(guidlow, data);
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_TEAM_IN_INSTANCE:
                        UpdateTeamInInstance();
                        return uint32(team);
                    case DATA_SOUL_POWER:
                        return soulFragmentsAlive;
                    default:
                        break;
                }
                return 0;
            }

            void SetData(uint32 data, uint32 value)
            {
                switch (data)
                {
                    case DATA_SOUL_POWER:
                        if (value == 1)
                            ++soulFragmentsAlive;
                        else if (value == 0)
                            --soulFragmentsAlive;
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_BRONJAHM:
                        return uiBronjahm;
                    case DATA_DEVOURER:
                        return uiDevourer;
                    default:
                        break;
                }
                return 0;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "F S " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* in) override
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(in);

                char dataHead1, dataHead2;

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'F' && dataHead2 == 'S')
                {
                    for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                } else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        private:
            uint64 uiBronjahm;
            uint64 uiDevourer;

            uint64 uiSylvanas_Part1;
            uint64 uiJaina_Part1;
            uint64 uiKalira;
            uint64 uiElandra;
            uint64 uiLoralen;
            uint64 uiKoreln;

            TeamId team;
            uint32 soulFragmentsAlive;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_forge_of_souls_InstanceScript(map);
        }
};

void AddSC_instance_forge_of_souls()
{
    new instance_forge_of_souls();
}
