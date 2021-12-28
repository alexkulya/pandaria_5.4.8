#include "ScriptPCH.h"
#include "well_of_eternity.h"
#include "GameObjectAI.h"

enum Spells
{
    SPELL_TELEPORT_TO_START                 = 107934, 
    SPELL_TELEPORT_TO_AZSHARA_PALACE        = 107979, 
    SPELL_TELEPORT_TO_WELL_OF_ETERNITY      = 107691,
};

enum InstanceTeleporter
{
    START_TELEPORT          = 1,
    AZSHARA_TELEPORT        = 2,
    WOE_TELEPORT            = 3,
};

class go_well_of_eternity_teleport : public GameObjectScript
{
    public:
        go_well_of_eternity_teleport() : GameObjectScript("go_well_of_eternity_teleport") { }

        bool OnGossipHello(Player* player, GameObject* go) override
        {
            bool ru = player->GetSession()->GetSessionDbLocaleIndex() == LOCALE_ruRU;

            if (player->IsInCombat())
                return true;

            if (InstanceScript* instance = go->GetInstanceScript())
            {
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ru ? "Телепорт ко входу в сад.":"Teleport to Start.", GOSSIP_SENDER_MAIN, START_TELEPORT);

                if (player->IsGameMaster())
                {
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ru ? "Перенестись во дворец Азшары.": "Teleport to Azshara's Palace.", GOSSIP_SENDER_MAIN, AZSHARA_TELEPORT);
                    player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ru ? "Перенестись в Источник Вечности.": "Teleport to Well of Eternity.", GOSSIP_SENDER_MAIN, WOE_TELEPORT);
                }
                else
                {
                    if (instance->GetBossState(DATA_PEROTHARN) == DONE)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ru ? "Перенестись во дворец Азшары.": "Teleport to Azshara's Palace.", GOSSIP_SENDER_MAIN, AZSHARA_TELEPORT);
                    if (instance->GetBossState(DATA_AZSHARA) == DONE)
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, ru ? "Перенестись в Источник Вечности.": "Teleport to Well of Eternity.", GOSSIP_SENDER_MAIN, WOE_TELEPORT);
                }
            }
        
            player->SEND_GOSSIP_MENU(player->GetGossipTextId(go), go->GetGUID());
            return true;
        }

        bool OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action) override
        {
            //player->PlayerTalkClass->ClearMenus();
            if (player->IsInCombat())
                return true;

            InstanceScript* instance = player->GetInstanceScript();
            if (!instance)
                return true;
            
            switch (action) 
            {
                case START_TELEPORT:
                    player->CastSpell(player, SPELL_TELEPORT_TO_START, true);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case AZSHARA_TELEPORT:
                    player->CastSpell(player, SPELL_TELEPORT_TO_AZSHARA_PALACE, true);
                    player->CLOSE_GOSSIP_MENU();
                    break;
                case WOE_TELEPORT:
                    player->CastSpell(player, SPELL_TELEPORT_TO_WELL_OF_ETERNITY, true);
                    player->CLOSE_GOSSIP_MENU();
                    break;
            }
            
            return true;
        }    
};

void AddSC_well_of_eternity_teleport()
{
    new go_well_of_eternity_teleport();
}
