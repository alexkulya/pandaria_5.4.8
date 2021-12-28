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

/*
This placeholder for the instance is needed for dungeon finding to be able
to give credit after the boss defined in lastEncounterDungeon is killed.
Without it, the party doing random dungeon won't get satchel of spoils and
gets instead the deserter debuff.
*/

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ragefire_chasm.h"

class instance_ragefire_chasm : public InstanceMapScript
{
    public:
        instance_ragefire_chasm() : InstanceMapScript("instance_ragefire_chasm", 389) { }

        struct instance_ragefire_chasm_InstanceMapScript : public InstanceScript
        {
            instance_ragefire_chasm_InstanceMapScript(Map* map) : InstanceScript(map) { }

            uint64 AdaroggGUID;
            uint64 CoranthalGUID;
            uint64 SlagmawGUID;
            uint64 GordothGUID;

            void Initialize() override
            {
                SetBossNumber(TOTAL_ENCOUNTERS);

                AdaroggGUID   = 0;
                CoranthalGUID = 0;
                SlagmawGUID   = 0;
                GordothGUID   = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_ADAROGG:
                        AdaroggGUID = creature->GetGUID();
                        break;
                    case NPC_DARK_SHAMAN_CORANTHAL:
                        CoranthalGUID = creature->GetGUID();
                        break;
                    case NPC_SLAGMAW:
                        SlagmawGUID = creature->GetGUID();
                        break;
                    case NPC_GORDOTH:
                        GordothGUID = creature->GetGUID();
                        break;
                }
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case BOSS_ADAROGG:
                        return AdaroggGUID;
                    case BOSS_DARK_SHAMAN_CORANTHAL:
                        return CoranthalGUID;
                    case BOSS_SLAGMAW:
                        return SlagmawGUID;
                    case BOSS_GORDOTH:
                        return GordothGUID;
                }

                return 0;
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "R F C " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* in) override
            {
                if (!in)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(in);

                char dataHead1, dataHead2, dataHead3;

                std::istringstream loadStream(in);
                loadStream >> dataHead1 >> dataHead2 >> dataHead3;

                if (dataHead1 == 'R' && dataHead2 == 'F' && dataHead3 == 'C')
                {
                    for (uint8 i = 0; i < TOTAL_ENCOUNTERS; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;

                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_ragefire_chasm_InstanceMapScript(map);
        }
};

void AddSC_instance_ragefire_chasm()
{
    new instance_ragefire_chasm();
}
