/*
Made by: Erictemponi
*/

#include "ScriptMgr.h"
#include "Config.h"
#include "Log.h"
#include "Guild.h"
#include "GuildMgr.h"

class StartingGuildScript : public PlayerScript
{
    public:
        StartingGuildScript() : PlayerScript("StartingGuildScript") { }

        // called when some player is created
        void OnCreate(Player* pPlayer)
        {
            if (sConfigMgr->GetBoolDefault("StartingGuild.Enable", false))
            {
                uint32 guildID;
                if (pPlayer->GetTeam() == HORDE)
                    guildID = sConfigMgr->GetIntDefault("StartingGuild.GuildID.Horde", 0);
                else
                    guildID = sConfigMgr->GetIntDefault("StartingGuild.GuildID.Alliance", 0);

                Guild* targetGuild = sGuildMgr->GetGuildById(guildID);
                if (targetGuild)
                {
                    ObjectGuid playerGuid = pPlayer->GetGUID();
                    // player's guild membership checked in AddMember before add
                    CharacterDatabaseTransaction trans(nullptr);
                    targetGuild->AddMember(trans, playerGuid);
                }
            }
        }
};


class StartingGuildWorld : public WorldScript
{
    public:
        StartingGuildWorld() :WorldScript("StartingGuildWorld") { }

        void OnStartup() override
        {
            if (sConfigMgr->GetBoolDefault("StartingGuild.Enable", false))
            {
                uint32 hordeGuildID = sConfigMgr->GetIntDefault("StartingGuild.GuildID.Horde", 0);
                uint32 allianceGuildID = sConfigMgr->GetIntDefault("StartingGuild.GuildID.Alliance", 0);
                Guild* hordeTargetGuild = sGuildMgr->GetGuildById(hordeGuildID);
                Guild* allianceTargetGuild = sGuildMgr->GetGuildById(allianceGuildID);
                if (!hordeTargetGuild)
                    sLog->outMessage("server", LOG_LEVEL_ERROR, "There is no Guild with ID %d. StartingGuild will not work for Horde players.", hordeGuildID);
                if (!allianceTargetGuild)
                    sLog->outMessage("server", LOG_LEVEL_ERROR, "There is no Guild with ID %d. StartingGuild will not work for Alliance players.", allianceGuildID);
            }
        }
};

void AddSC_starting_guild()
{
    new StartingGuildScript();
    new StartingGuildWorld();
}