#include "ScriptPCH.h"
#include "Chat.h"


uint32 auras[] = { 70233, 70234, 70235, 70244, 70242, 70243 };

class buff_commandscript : public CommandScript
{
public:
    buff_commandscript() : CommandScript("buff_commandscript") { }

	ChatCommand* GetCommands() const
    {
        static ChatCommand IngameCommandTable[] =
        {
			{ "buff",            SEC_PLAYER,  false, &HandleBuffCommand,             "", NULL },
            { NULL,             0,                  false, NULL,                              "", NULL }
        };
		 return IngameCommandTable;
    }

	static bool HandleBuffCommand(ChatHandler * handler, const char * args)
    {
        Player * me = handler->GetSession()->GetPlayer();
	
		me->RemoveAurasByType(SPELL_AURA_MOUNTED);
		for(int i = 0; i < 11; i++)
		    me->AddAura(auras[i], me);
		handler->PSendSysMessage("You're buffed now!");
		return true;
    }
};

void AddSC_buff_commandscript()
{
    new buff_commandscript();
}
