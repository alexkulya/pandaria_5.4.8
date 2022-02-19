#include "ScriptMgr.h"
#include "Map.h"
#include "Player.h"
#include "SpellMgr.h"
#include "Unit.h"
#include "Weather.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"

enum Gilneas
{
    MAP_GILNEAS                             = 654,
    ZONE_ID_GILNEAS                         = 4714,
    ZONE_ID_GILNEAS_CITY                    = 4755,

    EVENT_CAST_CATACLYSM                    = 1,

    SPELL_CATACLYSM_1                       = 68953,
    SPELL_CATACLYSM_2                       = 80134,
    SPELL_CATACLYSM_3                       = 80133
};

uint32 cataclysmSpells[] =
{
    SPELL_CATACLYSM_1,
    SPELL_CATACLYSM_2,
    SPELL_CATACLYSM_3
};

class world_map_gilneas: public WorldMapScript
{
    public:
        world_map_gilneas() : WorldMapScript("world_map_gilneas", MAP_GILNEAS) { }

        void OnCreate(Map* map) override
        {
            map->SetZoneWeather(ZONE_ID_GILNEAS, WEATHER_STATE_RAIN_DRIZZLE, 0.3f);
            map->SetZoneWeather(ZONE_ID_GILNEAS_CITY, WEATHER_STATE_FINE, 1.0f);
            _events.ScheduleEvent(EVENT_CAST_CATACLYSM, 1);
        }

        void OnUpdate(Map* map, uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CAST_CATACLYSM:
                    {
                        Map::PlayerList const& players = map->GetPlayers();

                        for (auto const& i : players)
                        {
                            if (Player* player = i.GetSource())
                            {
                                for (uint8 i = 0; i < 3; i++)
                                {
                                    if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(cataclysmSpells[i]))
                                        if (player->HasAura(spell->TargetAuraSpell))
                                            player->CastSpell(player, cataclysmSpells[i]);
                                }
                            }
                        }

                        _events.RepeatEvent(urand(1 * MINUTE * IN_MILLISECONDS, 2 * MINUTE * IN_MILLISECONDS));
                        break;
                    }
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
};

void AddSC_world_map_scripts()
{
    new world_map_gilneas();
}
