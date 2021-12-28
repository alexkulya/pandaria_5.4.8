#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "dire_maul.h"

// Old Ironbark 11491
class npc_old_ironbark : public CreatureScript
{
    public:
        npc_old_ironbark() : CreatureScript("npc_old_ironbark") { }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action) override
        {
            player->PlayerTalkClass->ClearMenus();

            if (action == GOSSIP_ACTION_INFO_DEF + 1)
            {
                creature->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                uint32 delay = 0;
                uint64 guid = creature->GetGUID();

                Movement::MoveSplineInit init(creature);
                for (auto itr : ironbarkPath)
                    init.Path().push_back(G3D::Vector3(itr.GetPositionX(), itr.GetPositionY(), itr.GetPositionZ()));

                init.SetSmooth();
                init.SetUncompressed();
                init.Launch();
                creature->m_Events.Schedule(delay += creature->GetSplineDuration(), 1, [this,guid]()
                {
                    if (Unit* ironbark = ObjectAccessor::FindUnit(guid))
                        if (InstanceScript* instance = ironbark->GetInstanceScript())
                            if (GameObject* door = ObjectAccessor::GetGameObject(*ironbark, instance->GetData64(GO_CONSERVATORY_DOOR)))
                                door->UseDoorOrButton();
                });
            }

            player->CLOSE_GOSSIP_MENU();

            return true;
        }

        bool OnGossipHello(Player* player, Creature* creature) override
        {
            if (creature->IsQuestGiver())
                player->PrepareQuestMenu(creature->GetGUID());

            player->ADD_GOSSIP_ITEM_DB(player->GetDefaultGossipMenuForSource(creature), 0, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

            player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
            return true;
        }

        struct npc_old_ironbarkAI : public ScriptedAI
        {
            npc_old_ironbarkAI(Creature* creature) : ScriptedAI(creature) { }

            void UpdateAI(uint32 /*diff*/) override { }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_old_ironbarkAI(creature);
        }
};

void AddSC_dire_maul()
{
    new npc_old_ironbark();
}