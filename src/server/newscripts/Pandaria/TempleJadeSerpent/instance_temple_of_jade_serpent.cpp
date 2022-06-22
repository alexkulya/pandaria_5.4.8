/*
    Dungeon : Template of the Jade Serpent 85-87
    Instance General Script
    Jade servers
*/

#include "NewScriptPCH.h"

#define EVENT_LOREWALKER_STONESTEP_SUNS 0
#define EVENT_LOREWALKER_STONESTEP_TRIAL 1

enum eSpells
{
    SPELL_CORRUPTED_WATERS      = 115167,
    //Spells for Lorewalker Stonestep event.
    SPELL_SHA_CORRUPTION        = 107034, //On spawn: Lot of mobs and decoration
    //HAUNTING SHA SPELLS
    SPELL_SHA_EXPLOSION_2       = 111812,
    //ZAO SUNSEEKER SPELLS
    SPELL_SHA_CORRUPTION_2      = 123947,
    SPELL_SHOOT_SUN             = 112084, //10 52 00 - 11 26 50 - 11 52 35
    SPELL_SHOOT_SUN_2           = 112085,
    SPELL_SHA_CORRUPTION_3      = 120000, //OnSpawn: Jiang
    SPELL_HELLFIRE_ARROW        = 113017,
    //LOREWALKER STONESTEP SPELLS
    SPELL_JADE_BLAST            = 107035,
    SPELL_JADE_BLAST_2          = 107048,
    SPELL_ROOT_SELF             = 106822,
    SPELL_LOREWALKER_ALACRITY   = 122714, //To cast on players
    SPELL_MEDITATION            = 122715,
    //SCROLL SPELLS
    SPELL_SCROLL_FLOOR          = 107350, //On spawn
    SPELL_JADE_ENERGY           = 107384,
    SPELL_JADE_ENERGY_2         = 111452, //On spawn
    SPELL_DRAW_SHA_2            = 111393,
    SPELL_DRAW_SHA_3            = 111431,
    SPELL_SHA_BURNING           = 111588, //OnDied
    SPELL_SHA_EXPLOSION         = 111579, //OnDied
    SPELL_DEATH                 = 98391,  //OnDied
    //SUN SPELLS
    SPELL_DRAW_SHA              = 111395,
    SPELL_SUN                   = 107349,
    SPELL_GROW_LOW              = 104921,
    SPELL_GROW_HIGH             = 111701,
    SPELL_SUNFIRE_EXPLOSION     = 111737,
    SPELL_DUMMY_NUKE            = 105898, //11 00 04 - 11 07 05 - 11 40 22
    SPELL_SUNFIRE_BLAST         = 111853,
    SPELL_SUNFIRE_RAYS          = 107223, //09 26 28 - 09 46 29 - 10 06 46
    SPELL_EXTRACT_SHA           = 111764,
    SPELL_EXTRACT_SHA_2         = 111806,
    SPELL_EXTRACT_SHA_3         = 111807,
    SPELL_EXTRACT_SHA_4         = 111768,
    SPELL_UNKNOWN               = 105581,
    //JIANG SPELLS
    SPELL_JUGGLER_JIANG         = 114745, //OnSpawn: Jiang
    //THE SONGBIRD QUEEN SPELLS
    SPELL_SINGING_SONGBIRD      = 114789, //OnSpawn: Songbird
    //HAUNTING SHA SPELLS
    SPELL_HAUNTING_GAZE         = 114650, //OnSpawn
    //XIANG SPELLS
    SPELL_JUGGLER_XIANG         = 114718,
    //FISH SPELLS
    SPELL_WATER_BUBBLE          = 114549, //OnSpawn
    //ChannelSpell : 42808, 512
    
    SPELL_POSSESSED_BY_SHA                  = 110164, //On Spawn
    SPELL_JADE_ESSENCE                      = 106797, //AddAura on phase 2
    SPELL_TRANSFORM_VISUAL                  = 74620, //When the dragon is dead, cast this and remove the possess aura.
    
    SPELL_FIGMENT_OF_DOUBT_2    = 106935,
    SPELL_COPY_WEAPON           = 41054,
    SPELL_COPY_WEAPON_2         = 41055,
    SPELL_BOUNDS_OF_REALITY_2   = 117665,
};

enum eCreatures
{
    CREATURE_WISE_MARI              = 56448,

    CREATURE_SCROLL                 = 57080,
    CREATURE_ZAO_SUNSEEKER          = 58826,
    CREATURE_LOREWALKTER_STONESTEP  = 56843,
    CREATURE_SUN                    = 56915,
    CREATURE_SUN_TRIGGER            = 56861,
    CREATURE_HAUNTING_SHA_2         = 58856,

    CREATURE_STRIFE                 = 59726,
    CREATURE_PERIL                  = 59051,

    CREATURE_MINION_OF_DOUBTS       = 57109,
    CREATURE_LIU_FLAMEHEART         = 56732,
    CREATURE_YU_LON                 = 56762,
    CREATURE_JADE_FIRE              = 56893,

    CREATURE_FIGMENT_OF_DOUBT       = 56792,
    CREATURE_SHA_OF_DOUBT           = 56439,
};

enum eGameObjects
{
    GAMEOBJECT_DOOR_WISE_MARI           = 213550,
    GAMEOBJECT_DOOR_LOREWALKER_STONSTEP = 213549,
    GAMEOBJECT_DOOR_LIU_FLAMEHEART      = 213548,
    GAMEOBJECT_DOOR_LIU_FLAMEHEART_2    = 213544,
};

enum eTypes
{
    TYPE_LOREWALKTER_STONESTEP = 0,
    TYPE_NUMBER_SUN_DEFEATED = 1,
    TYPE_SET_SUNS_SELECTABLE = 2,
    TYPE_LOREWALKER_STONESTEP_TALK_AFTER_ZAO = 3,
    TYPE_SET_SCROLL_SELECTABLE = 4,
    TYPE_GET_EVENT_LOREWALKER_STONESTEP = 5,
    TYPE_LIU_FLAMEHEART_STATUS = 6,
    TYPE_IS_WIPE = 7,
    TYPE_CLASS_FIGMENT = 8,
    TYPE_CLASS_FIGMENT_DIE = 9,
};

enum eStatus
{
    STATUS_LOREWALKER_STONESTEP_NONE        = 1,
    STATUS_LOREWALKER_STONESTEP_INTRO       = 2,
    STATUS_LOREWALKER_STONESTEP_SPAWN_SUNS  = 3,
    STATUS_LOREWALKER_STONESTEP_SPAWN_SUNS_2= 4,
    STATUS_LOREWALKER_STONESTEP_ZAO_COMBAT  = 5,
    STATUS_LOREWALKER_STONESTEP_FINISH      = 6,
};

class instance_temple_of_jade_serpent : public InstanceMapScript
{
public:
    instance_temple_of_jade_serpent() : InstanceMapScript("instance_temple_of_jade_serpent", 960) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_temple_of_jade_serpent_InstanceMapScript(map);
    }

    struct instance_temple_of_jade_serpent_InstanceMapScript : public InstanceScript
    {
        /*
        ** Wise Mari script.
        */
        Position roomCenter;
        uint32 waterDamageTimer;
        uint64 doorWiseMari;
        uint64 wiseMariGUID;
        /*
        ** End of Wise Mari script
        */

        /*
        ** LoreWalkter Stonestep script.
        */
        uint8 eventChoosen;
        uint64 lorewalkter_stonestep;
        uint64 zao_sunseeker;
        uint64 scroll;
        uint64 door_lorewalker;
        uint64 guidPeril;
        uint64 guidStrife;
        uint32 eventStatus_lorewalkter_stonestep;
        uint32 eventStatus_numberSunDefeated;
        uint32 wipeTimer;
        std::list<uint64> creatures_corrupted;
        std::list<uint64> sunfires;
        std::list<uint64> suns;
        std::list<uint64> sun_triggers;
        std::list<uint64> sha_summoned;
        /*
        ** End of Lorewalker Stonestep script.
        */

        /*
        ** Liu Flameheart script.
        */
        uint32 countMinionDeads;
        uint64 liuGuid;
        uint64 doorLiu;
        uint64 doorLiu_2;
        std::list<uint64> mobs_liu;
        /*
        ** End of Liu Flameheart script.
        */

        /*
        ** Sha of Doubt script.
        */
        uint64 sha_of_doubt_guid;
        uint8 countDps;
        uint8 countHeal;
        uint8 countTank;
        uint8 countFigments;
        /*
        ** End of Sha of Doubt script.
        */

        instance_temple_of_jade_serpent_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            // Wise Mari script
            doorWiseMari = 0;
            roomCenter.m_positionX = 1046.941f;
            roomCenter.m_positionY = -2560.606f;
            roomCenter.m_positionZ = 174.9552f;
            roomCenter.m_orientation = 4.33f;
            waterDamageTimer = 250;
            wiseMariGUID = 0;

            //LoreWalkter Stonestep script.
            lorewalkter_stonestep = 0;
            zao_sunseeker = 0;
            scroll = 0;
            guidPeril = 0;
            guidStrife = 0;
            eventStatus_lorewalkter_stonestep = STATUS_LOREWALKER_STONESTEP_NONE;
            eventStatus_numberSunDefeated = 0;
            eventChoosen = 0;
            wipeTimer = 3000;

            //Liu Flameheart script.
            countMinionDeads = 0;
            liuGuid = 0;
            doorLiu = 0;
            doorLiu_2 = 0;

            //Sha of doubt script.
            sha_of_doubt_guid = 0;
            countDps = 0;
            countTank = 0;
            countHeal = 0;
            countFigments = 0;
        }

        void Initialize()
        {
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GAMEOBJECT_DOOR_WISE_MARI:
                    doorWiseMari = go->GetGUID();
                    break;
                case GAMEOBJECT_DOOR_LIU_FLAMEHEART_2:
                    doorLiu_2 = go->GetGUID();
                    break;
                case GAMEOBJECT_DOOR_LOREWALKER_STONSTEP:
                    door_lorewalker = go->GetGUID();
                    break;
                case GAMEOBJECT_DOOR_LIU_FLAMEHEART:
                    doorLiu = go->GetGUID();
                    break;
            }
        }

        
        void OnCreatureCreate(Creature* creature)
        {
            OnCreatureCreate_lorewalker_stonestep(creature);
            OnCreatureCreate_liu_flameheart(creature);
            OnCreatureCreate_sha_of_doubt(creature);

            if (creature->GetEntry() == 56448)
            	wiseMariGUID = creature->GetGUID();
        }

        void OnUnitDeath(Unit* unit)
        {
            OnUnitDeath_lorewalker_stonestep(unit);
            OnUnitDeath_liu_flameheat(unit);
            OnUnitDeath_wise_mari(unit);
        }
        
        void Update(uint32 diff) 
        {
            // Challenge
            InstanceScript::Update(diff);

            //LOREWALKER STONESTEP: If Wipe, we must clean the event.
            if (wipeTimer <= diff
                && eventStatus_lorewalkter_stonestep >= STATUS_LOREWALKER_STONESTEP_INTRO
                && eventStatus_lorewalkter_stonestep < STATUS_LOREWALKER_STONESTEP_FINISH
                && IsWipe())
            {
                Wipe_lorewalker_stonestep();
                wipeTimer = 3000;
            }
            else
                wipeTimer -= diff;

            //WISE MARI
            if (waterDamageTimer <= diff)
            {
                // Handle damage of water in wise mari combat
                // Blizz handle that case with trigger and aura cast every 250 ms, anyway it's work
                Map::PlayerList const& PlayerList = instance->GetPlayers();

                if (!PlayerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        Player* plr = i->getSource();
                        if(!plr)
                            continue;

                        Unit* wiseMari = Unit::GetUnit(*plr, wiseMariGUID);
                        if (!wiseMari)
                        	continue;

                        if (!wiseMari->IsAlive() || !wiseMari->isInCombat())
                        	continue;

                        // position : center of the wise mari's room
                        Position pos;
                        plr->GetPosition(&pos);

                        if ((plr->GetDistance(roomCenter) < 20.00f && roomCenter.HasInArc(M_PI, &pos)) 
                            || (!roomCenter.HasInArc(M_PI, &pos) && plr->GetDistance(roomCenter) < 14.00f))
                        {
                            if (plr->GetPositionZ() > 174.05f && plr->GetPositionZ() < 174.23f)
                                plr->CastSpell(plr, SPELL_CORRUPTED_WATERS, true);
                        }

                        if (plr->GetDistance(roomCenter) < 30.00f && plr->GetPositionZ() > 170.19f && plr->GetPositionZ() < 170.215f)
                            plr->CastSpell(plr, SPELL_CORRUPTED_WATERS, true);
                    }
                }
                waterDamageTimer = 250;
            }
            else
                waterDamageTimer -= diff;
        }

        void SetData(uint32 type, uint32 data)
        {
            SetData_lorewalker_stonestep(type, data);
            //SetData_liu_flameheart(type, data);
            SetData_sha_of_doubt(type, data);
        }

        uint32 GetData(uint32 type)
        {
            switch (type)
            {
            case TYPE_CLASS_FIGMENT:
                if (countDps < 2)
                    return 0;
                else if (countHeal == 0)
                    return 1;
                else if (countTank == 0)
                    return 2;
                return 3;
                break;
            case TYPE_IS_WIPE:
                return IsWipe();
            case TYPE_GET_EVENT_LOREWALKER_STONESTEP:
                return eventChoosen;
            case TYPE_LOREWALKTER_STONESTEP:
                return eventStatus_lorewalkter_stonestep;
            case TYPE_NUMBER_SUN_DEFEATED:
                return eventStatus_numberSunDefeated;
            default:
                return STATUS_NONE;
            case TYPE_LIU_FLAMEHEART_STATUS:
                {
                    Creature* creature = instance->GetCreature(liuGuid);
                    if (creature == NULL)
                        return 2;

                    if (creature->GetHealthPct() < 70.f)
                        return 1;
                    else
                        return 0;
                }
                break;
            }
        }

        uint64 GetData64(uint32 type)
        {
            switch (type)
            {
            case CREATURE_ZAO_SUNSEEKER:
                return zao_sunseeker;
            case CREATURE_SHA_OF_DOUBT:
                return sha_of_doubt_guid;
            }
            return 0;
        }

        void OnUnitDeath_wise_mari(Unit* unit)
        {
            if (unit->GetEntry() == CREATURE_WISE_MARI)
            {
                GameObject* go = instance->GetGameObject(doorWiseMari);
                if (go != NULL)
                    go->SetGoState(GO_STATE_ACTIVE);
            }
        }

        void SetData_sha_of_doubt(uint32 type, uint32 data)
        {
            switch (type)
            {
            case TYPE_CLASS_FIGMENT_DIE:
                if (data == 0)
                    ++countDps;
                else if (data == 1)
                    ++countHeal;
                else
                    ++countTank;
                if (countDps + countHeal + countTank == countFigments)
                {
                    Creature* sha_doubt = instance->GetCreature(sha_of_doubt_guid);
                    if (!sha_doubt)
                        return;

                    sha_doubt->RemoveAura(SPELL_BOUNDS_OF_REALITY_2);
                }
                break;
            case TYPE_CLASS_FIGMENT:
                countFigments = 0;
                countDps = 0;
                countHeal = 0;
                countTank = 0;
                break;
            }
        }
        void OnCreatureCreate_sha_of_doubt(Creature* creature)
        {
            switch (creature->GetEntry())
            {
            case CREATURE_SHA_OF_DOUBT:
                sha_of_doubt_guid = creature->GetGUID();
                break;
            case CREATURE_FIGMENT_OF_DOUBT:
                if (creature->ToTempSummon())
                {
                    ++countFigments;
                    Unit* summoner = creature->ToTempSummon()->GetSummoner();
                    if (!summoner)
                        return;
                    summoner->AddAura(SPELL_FIGMENT_OF_DOUBT_2, creature);
                    creature->SetDisplayId(summoner->GetDisplayId());
                    creature->SetFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_MIRROR_IMAGE);
                    summoner->CastSpell(creature, SPELL_COPY_WEAPON, false);
                    summoner->CastSpell(creature, SPELL_COPY_WEAPON_2, false);
                    creature->setFaction(14);

                    Unit* caster = summoner;
                    Unit* target = creature;

                    if (!caster)
                        return;
                    uint32 prevItem = target->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID);
                    if (Player* player = caster->ToPlayer())

                    {
                        if (Item* mainItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND))
                            target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, mainItem->GetEntry());

                    }
                    else
                        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, caster->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID));

                    prevItem = target->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID) + 1;

                    if (Player* player = caster->ToPlayer())
                    {
                        if (Item* offItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND))
                            target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, offItem->GetEntry());
                    }
                    else
                        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1, caster->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 1));
                    
                    prevItem = target->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID) + 2;

                    if (Player* player = caster->ToPlayer())
                    {
                        if (Item* rangedItem = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED))
                            target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, rangedItem->GetEntry());
                    }
                    else 
                        target->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2, caster->GetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID + 2));
                }
                break;
            }
        }

        void OnCreatureCreate_liu_flameheart(Creature* creature)
        {
            switch (creature->GetEntry())
            {
            case CREATURE_JADE_FIRE:
                creature->setFaction(14);
                creature->SetDisplayId(11686);
                creature->SetReactState(REACT_PASSIVE);
                creature->CastSpell(creature, 107108, true);
                creature->ForcedDespawn(5000);
                break;
            case CREATURE_LIU_FLAMEHEART:
                liuGuid = creature->GetGUID();
                break;
            }
        }

        void OnUnitDeath_liu_flameheat(Unit* unit)
        {
            if (unit->ToCreature() && unit->ToCreature()->GetEntry() == CREATURE_MINION_OF_DOUBTS)
            {
                if (unit->GetAreaId() == 6119) //AreaId of Liu Flameheart.
                {
                    ++countMinionDeads;

                    //Spawn Liu Flameheart.
                    if (countMinionDeads == 3)
                        unit->SummonCreature(CREATURE_LIU_FLAMEHEART, 929.787f, -2561.016f, 180.070f + 5);
                }
            }

            if (unit->ToCreature() && unit->ToCreature()->GetEntry() == CREATURE_YU_LON)
            {
                Creature* creature = instance->GetCreature(liuGuid);
                if (!creature)
                    return;
                
                creature->RemoveAura(SPELL_JADE_ESSENCE);
                creature->CastSpell(creature, SPELL_TRANSFORM_VISUAL, false);
                creature->RemoveAura(SPELL_POSSESSED_BY_SHA);
                creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                if (Creature* liu = instance->GetCreature(liuGuid))
                    liu->Kill(liu, true);               

                //Open the door!
                if (GameObject* go = instance->GetGameObject(doorLiu))
                    go->SetGoState(GO_STATE_ACTIVE);

                if (GameObject* go2 = instance->GetGameObject(doorLiu_2))
                    go2->SetGoState(GO_STATE_ACTIVE);
            }
        }

        void SetData_lorewalker_stonestep(uint32 type, uint32 data)
        {
            switch (type)
            {
            case TYPE_SET_SCROLL_SELECTABLE:
                {
                    Creature* c = instance->GetCreature(scroll);
                    if (c == NULL)
                        return;
                    c->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }
                break;
            case TYPE_SET_SUNS_SELECTABLE:
                if (eventChoosen !=  EVENT_LOREWALKER_STONESTEP_SUNS)
                    return;
                for (std::list<uint64>::const_iterator guid = sha_summoned.begin(); guid != sha_summoned.end(); ++guid)
                {
                    Creature* creature = instance->GetCreature(*guid);
                    if (!creature)
                        continue;

                    creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    if (creature->GetAI())
                        creature->GetAI()->DoAction(TYPE_SET_SUNS_SELECTABLE);
                }
                for (std::list<uint64>::const_iterator guid = sun_triggers.begin(); guid != sun_triggers.end(); ++guid)
                {
                    Creature* creature = instance->GetCreature(*guid);
                    if (!creature)
                        continue;

                    creature->CastSpell(creature, SPELL_SUNFIRE_EXPLOSION, false);
                }
                break;
            case TYPE_LOREWALKTER_STONESTEP:
                eventStatus_lorewalkter_stonestep = data;
                break;
            case TYPE_LOREWALKER_STONESTEP_TALK_AFTER_ZAO:
                {
                    Creature* creature = instance->GetCreature(lorewalkter_stonestep);
                    if (!creature)
                        return;
                    if (creature->GetAI())
                        creature->GetAI()->DoAction(TYPE_LOREWALKER_STONESTEP_TALK_AFTER_ZAO);
                }
                break;
            case TYPE_NUMBER_SUN_DEFEATED:
                eventStatus_numberSunDefeated += data;
                //Respawn the haunting sha and corrupt Zao.
                if (eventStatus_numberSunDefeated == 5)
                {
                    eventStatus_lorewalkter_stonestep = STATUS_LOREWALKER_STONESTEP_ZAO_COMBAT;
                    Creature* zao = instance->GetCreature(zao_sunseeker);
                    if (!zao)
                        return;

                    for (std::list<uint64>::const_iterator guid = sha_summoned.begin(); guid != sha_summoned.end(); ++guid)
                    {
                        Creature* creature = instance->GetCreature(*guid);
                        if (!creature)
                            continue;
                        creature->Respawn(true);
                        if (creature->GetAI())
                            creature->GetAI()->DoAction(0);
                        creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }
                    //Stop the fire tornados.
                    for (std::list<uint64>::const_iterator guid = sunfires.begin(); guid != sunfires.end(); ++guid)
                    {
                        Creature* creature = instance->GetCreature(*guid);
                        if (!creature)
                            continue;

                        creature->RemoveAura(67422);
                    }
                    if (zao->GetAI())
                        zao->GetAI()->DoAction(2);
                }
                break;
            }
        }
        void OnCreatureCreate_lorewalker_stonestep(Creature* creature)
        {
            switch (creature->GetEntry())
            {
            case CREATURE_STRIFE:
                guidStrife = creature->GetGUID();
                break;
            case CREATURE_PERIL:
                guidPeril = creature->GetGUID();
                break;
            case CREATURE_HAUNTING_SHA_2:
                sha_summoned.push_back(creature->GetGUID());
                break;
            case CREATURE_SUN_TRIGGER:
                creature->setFaction(14);
                creature->SetDisplayId(11686);
                creature->SetReactState(REACT_PASSIVE);
                sun_triggers.push_back(creature->GetGUID());
                break;
            case CREATURE_SUN:
                creature->SetFlag(UNIT_NPC_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                suns.push_back(creature->GetGUID());
                break;
            case CREATURE_ZAO_SUNSEEKER:
                zao_sunseeker = creature->GetGUID();
                break;
            case CREATURE_LOREWALKTER_STONESTEP:
                lorewalkter_stonestep = creature->GetGUID();
                creature->CastSpell(creature, SPELL_ROOT_SELF, true);
                break;
            case CREATURE_SCROLL:
                scroll = creature->GetGUID();
                creature->SetFlag(UNIT_NPC_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                creature->CastSpell(creature, SPELL_SCROLL_FLOOR, false);
                creature->CastSpell(creature, SPELL_JADE_ENERGY_2, false);
                creature->CastSpell(creature, SPELL_GROW_LOW, false);
                break;
                //Some creature that need an aura.
            case 59149:
            case 56882:
            case 56871:
            case 56872:
            case 56873:
            case 56874:
            case 59545:
            case 59552:
            case 59544:
                creature->CastSpell(creature, SPELL_SHA_CORRUPTION, false);
                creatures_corrupted.push_back(creature->GetGUID());
                break;
            case 59555: //Haunting Sha
                creature->CastSpell(creature, SPELL_SHA_CORRUPTION, false);
                creature->CastSpell(creature, SPELL_HAUNTING_GAZE, false);
                creatures_corrupted.push_back(creature->GetGUID());
                break;
            case 59553: //Gru
                creature->CastSpell(creature, SPELL_SHA_CORRUPTION, false);
                creature->CastSpell(creature, SPELL_SINGING_SONGBIRD, false);
                creatures_corrupted.push_back(creature->GetGUID());
                break;
            case 59546: //Poisson
                creature->CastSpell(creature, SPELL_SHA_CORRUPTION, false);
                creature->CastSpell(creature, SPELL_WATER_BUBBLE, false);
                creatures_corrupted.push_back(creature->GetGUID());
                break;
            case 59547: //Jiang
                creature->CastSpell(creature, SPELL_SHA_CORRUPTION_3, false);
                creature->CastSpell(creature, SPELL_JUGGLER_JIANG, false);
                creatures_corrupted.push_back(creature->GetGUID());
                break;
            case 65317: //Xiang
                creature->CastSpell(creature, SPELL_SHA_CORRUPTION_3, false);
                creature->CastSpell(creature, SPELL_JUGGLER_XIANG, false);
                creatures_corrupted.push_back(creature->GetGUID());
                break;
            case 58815: //Feu solaire tourbillonement trigger
                creature->SetDisplayId(11686);
                creature->SetReactState(REACT_PASSIVE);
                sunfires.push_back(creature->GetGUID());
                break;
            default:
                if (creature->GetAreaId() == 6118)
                    mobs_liu.push_back(creature->GetGUID());
                break;
            }
        }
        void OnUnitDeath_lorewalker_stonestep(Unit* unit)
        {
            if (unit->ToCreature() && unit->ToCreature()->GetEntry() == CREATURE_STRIFE)
            {
                if (Creature* peril = instance->GetCreature(guidPeril))
                {
                    if (peril->isDead())
                    {
                        GameObject* go = instance->GetGameObject(door_lorewalker);
                        if (go != NULL)
                            go->SetGoState(GO_STATE_ACTIVE);
                        eventStatus_lorewalkter_stonestep = STATUS_LOREWALKER_STONESTEP_FINISH;

                        Map::PlayerList const& PlayerList = instance->GetPlayers();

                        if (!PlayerList.isEmpty())
                        {
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            {
                                Player* plr = i->getSource();
                                if( !plr)
                                    continue;
                                plr->CastSpell(plr, SPELL_LOREWALKER_ALACRITY, false);
                            }
                        }
                    }
                }
            }
            
            if (unit->ToCreature() && unit->ToCreature()->GetEntry() == CREATURE_PERIL)
            {
                if (Creature* strife = instance->GetCreature(guidStrife))
                {
                    if (strife->isDead())
                    {
                        GameObject* go = instance->GetGameObject(door_lorewalker);
                        if (go != NULL)
                            go->SetGoState(GO_STATE_ACTIVE);
                        eventStatus_lorewalkter_stonestep = STATUS_LOREWALKER_STONESTEP_FINISH;

                        Map::PlayerList const& PlayerList = instance->GetPlayers();

                        if (!PlayerList.isEmpty())
                        {
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            {
                                Player* plr = i->getSource();
                                if( !plr)
                                    continue;
                                plr->CastSpell(plr, SPELL_LOREWALKER_ALACRITY, false);
                            }
                        }
                    }
                }
            }
            
            if (unit->ToCreature() && unit->ToCreature()->GetEntry() == CREATURE_ZAO_SUNSEEKER)
            {
                GameObject* go = instance->GetGameObject(door_lorewalker);
                if (go != NULL)
                    go->SetGoState(GO_STATE_ACTIVE);
                eventStatus_lorewalkter_stonestep = STATUS_LOREWALKER_STONESTEP_FINISH;

                Map::PlayerList const& PlayerList = instance->GetPlayers();

                if (!PlayerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        Player* plr = i->getSource();
                        if( !plr)
                            continue;
                        plr->CastSpell(plr, SPELL_LOREWALKER_ALACRITY, false);
                    }
                }
            }
            
            if (unit->ToCreature() && unit->ToCreature()->GetEntry() == CREATURE_SUN)
            {
                //OnDied, summon two haunting sha.
                unit->CastSpell(unit, SPELL_EXTRACT_SHA_4, false);
                unit->CastSpell(unit, SPELL_EXTRACT_SHA_4, false);
            }
            
            // When the scroll dies, we must draw all the corrupted units.
            if (unit->GetGUID() == scroll)
            {
                unit->RemoveAura(SPELL_JADE_ENERGY_2);
                unit->RemoveAura(SPELL_SCROLL_FLOOR);
                unit->RemoveAura(SPELL_GROW_LOW);
                unit->CastSpell(unit, SPELL_SHA_BURNING, false);
                unit->CastSpell(unit, SPELL_SHA_EXPLOSION, false);
                unit->CastSpell(unit, SPELL_DEATH, false);

                //Depending on the event randomly choosen:
                eventChoosen = urand(EVENT_LOREWALKER_STONESTEP_SUNS, EVENT_LOREWALKER_STONESTEP_TRIAL);

                if (eventChoosen == EVENT_LOREWALKER_STONESTEP_SUNS)
                {
                    Creature* lorewalker = instance->GetCreature(lorewalkter_stonestep);
                    if (lorewalker && lorewalker->GetAI())
                        lorewalker->GetAI()->DoAction(STATUS_LOREWALKER_STONESTEP_SPAWN_SUNS);
                    
                    eventStatus_lorewalkter_stonestep = STATUS_LOREWALKER_STONESTEP_SPAWN_SUNS;

                    //Then draw all the corrupted units and summon the suns.
                    for (std::list<uint64>::const_iterator guid = creatures_corrupted.begin(); guid != creatures_corrupted.end(); ++guid)
                    {
                        if (*guid == lorewalkter_stonestep)
                            continue;
                        Creature* c = instance->GetCreature(*guid);
                        if (c == NULL)
                            continue;

                        unit->AddAura(SPELL_DRAW_SHA_2, c);
                        unit->AddAura(SPELL_DRAW_SHA_2, c);
                        c->CastSpell(unit, SPELL_DRAW_SHA_3, false);
                        c->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT, scroll);
                        c->SetUInt32Value(UNIT_CHANNEL_SPELL, 42808);
                        c->ForcedDespawn(2000);
                    }

                    TempSummon* sum = NULL;
                    //Suns
                    sum = unit->SummonCreature(CREATURE_SUN, 830.067f, -2466.660f, 179.240f);
                    sum = unit->SummonCreature(CREATURE_SUN, 836.632f, -2467.159f, 178.139f);
                    sum = unit->SummonCreature(CREATURE_SUN, 839.659f, -2469.159f, 182.496f);
                    sum = unit->SummonCreature(CREATURE_SUN, 845.263f, -2469.179f, 178.209f);
                    sum = unit->SummonCreature(CREATURE_SUN, 850.361f, -2474.320f, 178.196f);
                    //Trigger of the suns
                    sum = unit->SummonCreature(CREATURE_SUN_TRIGGER, 830.067f, -2466.660f, 176.320f);
                    sum = unit->SummonCreature(CREATURE_SUN_TRIGGER, 836.632f, -2467.159f, 176.320f);
                    sum = unit->SummonCreature(CREATURE_SUN_TRIGGER, 839.659f, -2469.159f, 176.320f);
                    sum = unit->SummonCreature(CREATURE_SUN_TRIGGER, 845.263f, -2469.179f, 176.320f);
                    sum = unit->SummonCreature(CREATURE_SUN_TRIGGER, 850.361f, -2474.320f, 176.320f);

                    //Summon Zao.
                    sum = unit->SummonCreature(CREATURE_ZAO_SUNSEEKER, 846.877f, -2449.110f, 175.044f);
                    if (!sum)
                        return;
                    sum->SetFacingTo(4.450f);

                    for (std::list<uint64>::const_iterator guid = sunfires.begin(); guid != sunfires.end(); ++guid)
                    {
                        Creature* c = instance->GetCreature(*guid);
                        if (c == NULL)
                            continue;
                        c->CastSpell(c, 67422, false); //Blustering Vortex, Fire vortex display
                    }
                }
                else if (eventChoosen == EVENT_LOREWALKER_STONESTEP_TRIAL)
                {
                    Creature* lorewalker = instance->GetCreature(lorewalkter_stonestep);
                    if (lorewalker && lorewalker->GetAI())
                        lorewalker->GetAI()->DoAction(TYPE_GET_EVENT_LOREWALKER_STONESTEP);

                    TempSummon* sum = NULL;
                    sum = unit->SummonCreature(CREATURE_STRIFE, 847.530f, -2469.184f, 174.960f);
                    if (sum != NULL)
                        sum->SetFacingTo(1.525f);
                    sum = unit->SummonCreature(CREATURE_PERIL, 836.906f, -2465.859f, 174.960f);
                    if (sum != NULL)
                        sum->SetFacingTo(1.014f);
                }
            }
        }
        
        void Wipe_lorewalker_stonestep()
        {
            Creature* creature = instance->GetCreature(lorewalkter_stonestep);
            if (creature)
            {
                creature->Respawn();
                if (creature->GetAI())
                    creature->GetAI()->Reset();
            }
            creature = instance->GetCreature(guidPeril);
            if (creature)
                creature->ForcedDespawn();
            creature = instance->GetCreature(guidStrife);
            if (creature)
                creature->ForcedDespawn();
            creature = instance->GetCreature(zao_sunseeker);
            if (creature)
            {
                creature->ForcedDespawn();
            }
            creature = instance->GetCreature(scroll);
            if (creature)
            {
                creature->Respawn();
                if (creature->GetAI())
                    creature->GetAI()->Reset();
                creature->SetFlag(UNIT_NPC_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                creature->CastSpell(creature, SPELL_SCROLL_FLOOR, false);
                creature->CastSpell(creature, SPELL_JADE_ENERGY_2, false);
                creature->CastSpell(creature, SPELL_GROW_LOW, false);
            }
            eventStatus_lorewalkter_stonestep = STATUS_LOREWALKER_STONESTEP_NONE;
            eventStatus_numberSunDefeated = 0;
            for (std::list<uint64>::const_iterator guid = creatures_corrupted.begin(); guid != creatures_corrupted.end(); ++guid)
            {
                creature = instance->GetCreature(*guid);
                if (creature)
                {
                    creature->Respawn();
                    if (creature->GetAI())
                        creature->GetAI()->Reset();
                }
            }
            for (std::list<uint64>::const_iterator guid = suns.begin(); guid != suns.end(); ++guid)
            {
                creature = instance->GetCreature(*guid);
                if (creature)
                {
                    creature->ForcedDespawn();
                }
            }
            suns.clear();
            for (std::list<uint64>::const_iterator guid = sha_summoned.begin(); guid != sha_summoned.end(); ++guid)
            {
                creature = instance->GetCreature(*guid);
                if (creature)
                {
                    creature->ForcedDespawn();
                }
            }
            sha_summoned.clear();
            for (std::list<uint64>::const_iterator guid = sunfires.begin(); guid != sunfires.end(); ++guid)
            {
                Creature* c = instance->GetCreature(*guid);
                if (c == NULL)
                    continue;
                c->RemoveAura(67422);
            }
        }
    };

};

void AddSC_instance_temple_of_jade_serpent()
{
    new instance_temple_of_jade_serpent();
}
