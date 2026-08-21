#include "Transport.h"

// The waypoints of a zeppelin's stations
typedef const std::pair<uint32, uint32> ZeppelinEndpoints; // Lower number must come first for optimzed location calculation!

enum ZeppelinStation
{
    STATION_DUROTAR,
    STATION_TIRISFAL,
    STATION_STRANGLETHORN_VALE,

    STATION_BOREAN_TUNDRA,
    STATION_HOWLING_FJORD,
    STATION_MULGORE
};

typedef const std::pair<ZeppelinStation, ZeppelinStation> ZeppelinRoute;

struct Zeppelin
{
    uint32 entry; // gamobject_template.entry
    ZeppelinEndpoints endpoints;
    ZeppelinRoute route;
};

Zeppelin ZEPPELIN_THE_THUNDERCALLER =
{
    164871,
    std::make_pair(4, 18),
    std::make_pair(STATION_DUROTAR, STATION_TIRISFAL)
};

Zeppelin ZEPPELIN_THE_IRON_EAGLE =
{
    175080,
    std::make_pair(3, 14),
    std::make_pair(STATION_STRANGLETHORN_VALE, STATION_DUROTAR)
};

Zeppelin ZEPPELIN_THE_PURPLE_PRINCESS =
{
    176495,
    std::make_pair(3, 19),
    std::make_pair(STATION_STRANGLETHORN_VALE, STATION_TIRISFAL)
};


Zeppelin ZEPPELIN_THE_MIGHTY_WIND =
{
    186238,
    std::make_pair(4, 19),
    std::make_pair(STATION_BOREAN_TUNDRA, STATION_DUROTAR)
};

Zeppelin ZEPPELIN_THE_CLOUDKISSER =
{
    181689,
    std::make_pair(3, 10),
    std::make_pair(STATION_HOWLING_FJORD, STATION_TIRISFAL)
};

Zeppelin ZEPPELIN_THE_ZEPHYR =
{
    190549,
    std::make_pair(4, 22),
    std::make_pair(STATION_MULGORE, STATION_DUROTAR)
};

std::map<uint32, uint32> waypointMap; // Transport entry + last waypoints

typedef std::pair<uint32, uint32> Announcement; // Announcer entry + textGroup

class go_zeppelin_script : public TransportScript
{
public:
    go_zeppelin_script(const char* name_subclass, bool logWaypoints, std::map<uint32, Announcement> announcementMap) : TransportScript(name_subclass)
    {
        this->logWaypoints = logWaypoints;
        this->announcementMap = announcementMap;
    };

    void OnRelocate(Transport* transport, uint32 waypointId, uint32 /*mapId*/, float /*x*/, float /*y*/, float /*z*/)
    {
        uint32 transportEntry = transport->GetGOInfo()->entry;

        if (logWaypoints)
        {
            std::map<uint32, uint32>::iterator wpIt = waypointMap.find(transportEntry);

            if (wpIt == waypointMap.end())
                waypointMap.insert(std::make_pair(transport->GetGOInfo()->entry, waypointId));
            else
                wpIt->second = waypointId;
        }

        std::map<uint32, Announcement>::iterator aIt = announcementMap.find(waypointId);

        if (aIt == announcementMap.end())
            return;

        Announcement ancmt = aIt->second;

        if (Creature* c = transport->FindNearestCreature(ancmt.first, 500.0f))
            c->AI()->Talk(ancmt.second);
    };

private:
    bool logWaypoints;
    std::map<uint32, Announcement> announcementMap;
};

enum ZeppelinLocation
{
    LOCATION_UNKNOWN,
    LOCATION_ARRIVED_FIRST,
    LOCATION_ARRIVED_SECOND,
    LOCATION_DEPARTED_FIRST,
    LOCATION_DEPARTED_SECOND
};

const std::pair<ZeppelinLocation, ZeppelinLocation> NPC_LOCATIONS = std::make_pair(LOCATION_ARRIVED_FIRST, LOCATION_ARRIVED_SECOND);

enum GossipType
{
    ARRIVED,
    DEPARTED
};

// Will calculate one of 5 types of location from waypoints
ZeppelinLocation getZeppelinLocation(Zeppelin* zeppelin)
{
    if (waypointMap.find(zeppelin->entry) == waypointMap.end())
        return LOCATION_UNKNOWN;

    uint32 lastWaypoint = waypointMap.at(zeppelin->entry);
    ZeppelinEndpoints endpoints = zeppelin->endpoints;

    if (lastWaypoint < endpoints.second)
    {
        if (lastWaypoint > endpoints.first)
            return LOCATION_DEPARTED_FIRST;
        if (lastWaypoint == endpoints.first)
            return LOCATION_ARRIVED_FIRST;
        return LOCATION_DEPARTED_SECOND;
    }

    if (lastWaypoint == endpoints.second)
        return LOCATION_ARRIVED_SECOND;
    return LOCATION_DEPARTED_SECOND;
};

const uint32 GOSSIP_WHERE_IS_THE_ZEPPELIN = 1969;
const uint32 GOSSIP_UNKNOWN = 11163;

/// @todo DB entries suggest slightly different gossip for some NPCs with the same information (e.g. [..] Should be back in a few minutes...)
const std::map<std::pair<ZeppelinStation, GossipType>, uint32> GOSSIP_MAP =
{
    std::make_pair(std::make_pair(STATION_DUROTAR, ARRIVED), 11169),
    std::make_pair(std::make_pair(STATION_DUROTAR, DEPARTED), 11170),
    std::make_pair(std::make_pair(STATION_TIRISFAL, ARRIVED), 11173),
    std::make_pair(std::make_pair(STATION_TIRISFAL, DEPARTED), 11175),
    std::make_pair(std::make_pair(STATION_STRANGLETHORN_VALE, ARRIVED), 11167),
    std::make_pair(std::make_pair(STATION_STRANGLETHORN_VALE, DEPARTED), 11172)
};

// Gets the right gossip entry from the map
uint32 getGossipEntry(Zeppelin* zeppelin)
{
    ZeppelinRoute route = zeppelin->route;

    switch (getZeppelinLocation(zeppelin))
    {
        case LOCATION_ARRIVED_FIRST:
            return GOSSIP_MAP.at(std::make_pair(route.first, ARRIVED));
        case LOCATION_ARRIVED_SECOND:
            return GOSSIP_MAP.at(std::make_pair(route.second, ARRIVED));
        case LOCATION_DEPARTED_FIRST:
            return GOSSIP_MAP.at(std::make_pair(route.first, DEPARTED));
        case LOCATION_DEPARTED_SECOND:
            return GOSSIP_MAP.at(std::make_pair(route.second, DEPARTED));
        default: // LOCATION_UNKNOWN
            return GOSSIP_UNKNOWN;
    }
};

// Zeppelin masters are only distinguished by their associated zeppelin and location, so we can define a superclass for them.
class ZeppelinMaster : public CreatureScript
{
public:
    ZeppelinMaster(const char* name_subclass, Zeppelin* zeppelin, ZeppelinLocation npcLocation) : CreatureScript(name_subclass)
    {
        this->zeppelin = zeppelin;
        this->npcLocation = npcLocation;
    };

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (getZeppelinLocation(zeppelin) != npcLocation)
        {
            player->ADD_GOSSIP_ITEM_DB(GOSSIP_WHERE_IS_THE_ZEPPELIN, 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        }

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    };

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 /*action*/)
    {
        player->PlayerTalkClass->ClearMenus();
        player->SEND_GOSSIP_MENU(getGossipEntry(zeppelin), creature->GetGUID());
        return true;
    };

private:
    Zeppelin* zeppelin;
    ZeppelinLocation npcLocation;
};

// As with zeppelin masters, engineers are only distinguished by their associated zeppelins.
class ZeppelinEngineer : public CreatureScript
{
public:
    ZeppelinEngineer(const char* name_subclass, Zeppelin* firstZeppelin, Zeppelin* secondZeppelin) : CreatureScript(name_subclass)
    {
        observedZeppelins = std::make_pair(firstZeppelin, secondZeppelin);
    };

    bool OnGossipHello(Player* player, Creature* creature)
    {
        player->ADD_GOSSIP_ITEM_DB(Player::GetDefaultGossipMenuForSource(creature), 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->ADD_GOSSIP_ITEM_DB(Player::GetDefaultGossipMenuForSource(creature), 1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
        return true;
    };

    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        player->PlayerTalkClass->ClearMenus();

        switch (action)
        {
            case GOSSIP_ACTION_INFO_DEF + 1:
                player->SEND_GOSSIP_MENU(getGossipEntry(observedZeppelins.first), creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF + 2:
                player->SEND_GOSSIP_MENU(getGossipEntry(observedZeppelins.second), creature->GetGUID());
                break;
            default:
                return false;
        };

        return true;
    };

private:
    std::pair<Zeppelin*, Zeppelin*> observedZeppelins;
};

void AddSC_zeppelins()
{
    new go_zeppelin_script("zeppelin_the_thundercaller", true,
    {
        std::make_pair(ZEPPELIN_THE_THUNDERCALLER.endpoints.first, std::make_pair(9564, 0)),       // Frezza
        std::make_pair(ZEPPELIN_THE_THUNDERCALLER.endpoints.second, std::make_pair(9566, 0)),      // Zapetta
        std::make_pair(ZEPPELIN_THE_THUNDERCALLER.endpoints.second + 1, std::make_pair(9566, 1))
    });

    new go_zeppelin_script("zeppelin_the_iron_eagle", true,
    {
        std::make_pair(ZEPPELIN_THE_IRON_EAGLE.endpoints.first, std::make_pair(3149, 0)),          // Nez'raz
        std::make_pair(ZEPPELIN_THE_IRON_EAGLE.endpoints.second, std::make_pair(12136, 0))         // Snurk Bucksquick
    });

    new go_zeppelin_script("zeppelin_the_purple_princess", true,
    {
        std::make_pair(ZEPPELIN_THE_PURPLE_PRINCESS.endpoints.first, std::make_pair(12137, 0)),    // Squibby Overspeck
        std::make_pair(ZEPPELIN_THE_PURPLE_PRINCESS.endpoints.second, std::make_pair(3150, 0)),    // Hin Denburg
        std::make_pair(ZEPPELIN_THE_PURPLE_PRINCESS.endpoints.second + 1, std::make_pair(3150, 1))
    });

    new go_zeppelin_script("zeppelin_the_mighty_wind", false,
    {
        std::make_pair(ZEPPELIN_THE_MIGHTY_WIND.endpoints.first, std::make_pair(26538, 0)),        // Nargo Screwbore
        std::make_pair(ZEPPELIN_THE_MIGHTY_WIND.endpoints.second, std::make_pair(26537, 0))        // Greeb Ramrocket
    });

    new go_zeppelin_script("zeppelin_the_cloudkisser", false,
    {
        std::make_pair(ZEPPELIN_THE_CLOUDKISSER.endpoints.first, std::make_pair(26540, 0)),        // Drenk Spannerspark
        std::make_pair(ZEPPELIN_THE_CLOUDKISSER.endpoints.second, std::make_pair(26539, 0))        // Meefi Farthrottle
    });

    new go_zeppelin_script("zeppelin_the_zephyr", false,
    {
        //std::make_pair(ZEPPELIN_THE_ZEPHYR.endpoints.first, std::make_pair(34766, 0)),           // Krendle Bigpockets
        //std::make_pair(ZEPPELIN_THE_ZEPHYR.endpoints.second, std::make_pair(34765, 0))           // Zelli Hotnozzle
    });

    new ZeppelinMaster("npc_frezza", &ZEPPELIN_THE_THUNDERCALLER, NPC_LOCATIONS.first);
    new ZeppelinMaster("npc_zapetta", &ZEPPELIN_THE_THUNDERCALLER, NPC_LOCATIONS.second);

    new ZeppelinMaster("npc_nez_raz", &ZEPPELIN_THE_IRON_EAGLE, NPC_LOCATIONS.first);
    new ZeppelinMaster("npc_snurk_bucksquick", &ZEPPELIN_THE_IRON_EAGLE, NPC_LOCATIONS.second);

    new ZeppelinMaster("npc_squibby_overspeck", &ZEPPELIN_THE_PURPLE_PRINCESS, NPC_LOCATIONS.first);
    new ZeppelinMaster("npc_hin_denburg", &ZEPPELIN_THE_PURPLE_PRINCESS, NPC_LOCATIONS.second);

    new ZeppelinEngineer("npc_krixx", &ZEPPELIN_THE_THUNDERCALLER, &ZEPPELIN_THE_IRON_EAGLE);
    new ZeppelinEngineer("npc_kraxx", &ZEPPELIN_THE_THUNDERCALLER, &ZEPPELIN_THE_PURPLE_PRINCESS);
};
