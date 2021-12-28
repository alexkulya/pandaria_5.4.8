/*
* Copyright (C) 2011-2016 Project SkyFire <http://www.projectskyfire.org/>
* Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2005-2016 MaNGOS <http://getmangos.com/>
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

/* ScriptData
Name: ticket_commandscript
%Complete: 100
Comment: All ticket related commands
Category: commandscripts
EndScriptData */

#include "AccountMgr.h"
#include "Chat.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "Player.h"
#include "TicketMgr.h"
#include "ScriptMgr.h"

class ticket_commandscript : public CommandScript
{
public:
    ticket_commandscript() : CommandScript("ticket_commandscript") { }

    std::vector<ChatCommand> GetCommands() const
    {
        static std::vector<ChatCommand> ticketBugCommandTable =
        {
            { "assign",         SEC_GAMEMASTER, true,   &HandleTicketAssignToCommand<BugTicket>,    },
            { "close",          SEC_GAMEMASTER, true,   &HandleTicketCloseByIdCommand<BugTicket>,   },
            { "closedlist",     SEC_GAMEMASTER, true,   &HandleTicketListClosedCommand<BugTicket>,  },
            { "comment",        SEC_GAMEMASTER, true,   &HandleTicketCommentCommand<BugTicket>,     },
            { "delete",         SEC_GAMEMASTER, true,   &HandleTicketDeleteByIdCommand<BugTicket>,  },
            { "list",           SEC_GAMEMASTER, true,   &HandleTicketListCommand<BugTicket>,        },
            { "unassign",       SEC_GAMEMASTER, true,   &HandleTicketUnAssignCommand<BugTicket>,    },
            { "view",           SEC_GAMEMASTER, true,   &HandleTicketGetByIdCommand<BugTicket>,     },
            { "reset",          SEC_GAMEMASTER, true,   &HandleTicketResetCommand<BugTicket>,       },
        };

        static std::vector<ChatCommand> ticketResponseCommandTable =
        {
            { "append",         SEC_GAMEMASTER, true,   &HandleGMTicketResponseAppendCommand,   },
            { "appendln",       SEC_GAMEMASTER, true,   &HandleGMTicketResponseAppendLnCommand, },
        };
        static std::vector<ChatCommand> ticketCommandTable =
        {
            { "assign",         SEC_GAMEMASTER, true,   &HandleGMTicketAssignToCommand,         },
            { "bug",            SEC_GAMEMASTER, true,   ticketBugCommandTable                   },
            { "close",          SEC_GAMEMASTER, true,   &HandleGMTicketCloseByIdCommand,        },
            { "closedlist",     SEC_GAMEMASTER, true,   &HandleGMTicketListClosedCommand,       },
            { "comment",        SEC_GAMEMASTER, true,   &HandleGMTicketCommentCommand,          },
            { "complete",       SEC_GAMEMASTER, true,   &HandleGMTicketCompleteCommand,         },
            { "delete",         SEC_GAMEMASTER, true,   &HandleGMTicketDeleteByIdCommand,       },
            { "escalate",       SEC_GAMEMASTER, true,   &HandleGMTicketEscalateCommand,         },
            { "escalatedlist",  SEC_GAMEMASTER, true,   &HandleGMTicketListEscalatedCommand,    },
            { "list",           SEC_GAMEMASTER, true,   &HandleGMTicketListCommand,             },
            { "onlinelist",     SEC_GAMEMASTER, true,   &HandleGMTicketListOnlineCommand,       },
            { "reset",          SEC_GAMEMASTER, true,   &HandleGMTicketResetCommand,            },
            { "response",       SEC_GAMEMASTER, true,   ticketResponseCommandTable              },
            { "togglesystem",   SEC_GAMEMASTER, true,   &HandleToggleGMTicketSystem,            },
            { "unassign",       SEC_GAMEMASTER, true,   &HandleGMTicketUnAssignCommand,         },
            { "viewid",         SEC_GAMEMASTER, true,   &HandleGMTicketGetByIdCommand,          },
            { "viewname",       SEC_GAMEMASTER, true,   &HandleGMTicketGetByNameCommand,        },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "ticket",         SEC_GAMEMASTER, false,  ticketCommandTable                      },
        };
        return commandTable;
    }

    static bool HandleGMTicketAssignToCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* ticketIdStr = strtok((char*)args, " ");
        uint32 ticketId = atoi(ticketIdStr);

        char* targetStr = strtok(NULL, " ");
        if (!targetStr)
            return false;

        std::string target(targetStr);
        if (!normalizePlayerName(target))
            return false;

        GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
        if (!ticket || ticket->IsClosed())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        uint64 targetGuid = sObjectMgr->GetPlayerGUIDByName(target);
        uint32 accountId = sObjectMgr->GetPlayerAccountIdByGUID(targetGuid);
        // Target must exist and have administrative rights
        //if (!AccountMgr::HasPermission(accountId, rbac::RBAC_PERM_COMMANDS_BE_ASSIGNED_TICKET, realmID))
        //{
        //    handler->SendSysMessage(LANG_COMMAND_TICKETASSIGNERROR_A);
        //    return true;
        //}

        // If already assigned, leave
        if (ticket->IsAssignedTo(targetGuid))
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETASSIGNERROR_B, ticket->GetTicketId());
            return true;
        }

        // If assigned to different player other than current, leave
        //! Console can override though
        Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : NULL;
        if (player && ticket->IsAssignedNotTo(player->GetGUID()))
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetTicketId(), target.c_str());
            return true;
        }

        // Assign ticket
        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetAssignedTo(targetGuid, AccountMgr::IsAdminAccount(AccountMgr::GetSecurity(accountId, realmID)));
        ticket->SaveToDB(trans);
        sTicketMgr->UpdateLastChange();

        std::string msg = ticket->FormatMessageString(*handler, NULL, target.c_str(), NULL, NULL);
        handler->SendGlobalGMSysMessage(msg.c_str());
        return true;
    }

    static bool HandleGMTicketCloseByIdCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 ticketId = atoi(args);
        GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
        if (!ticket || ticket->IsClosed() || ticket->IsCompleted())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        // Ticket should be assigned to the player who tries to close it.
        // Console can override though
        Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : NULL;
        if (player && ticket->IsAssignedNotTo(player->GetGUID()))
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETCANNOTCLOSE, ticket->GetTicketId());
            return true;
        }

        sTicketMgr->CloseTicket<GmTicket>(ticket->GetTicketId(), player ? player->GetGUID() : -1);
        sTicketMgr->UpdateLastChange();

        std::string msg = ticket->FormatMessageString(*handler, player ? player->GetName().c_str() : "Console", NULL, NULL, NULL);
        handler->SendGlobalGMSysMessage(msg.c_str());

        // Inform player, who submitted this ticket, that it is closed
        if (Player* submitter = ticket->GetPlayer())
        {
            if (submitter->IsInWorld())
            {
                WorldPacket data(SMSG_GM_TICKET_UPDATE, 4);
                data << uint32(GMTICKET_RESPONSE_TICKET_DELETED);
                submitter->GetSession()->SendPacket(&data);
            }
        }
        return true;
    }

    static bool HandleGMTicketListClosedCommand(ChatHandler* handler, char const* /*args*/)
    {
        sTicketMgr->ShowClosedList<GmTicket>(*handler);
        return true;
    }

    static bool HandleGMTicketCommentCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* ticketIdStr = strtok((char*)args, " ");
        uint32 ticketId = atoi(ticketIdStr);

        char* comment = strtok(NULL, "\n");
        if (!comment)
            return false;

        GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
        if (!ticket || ticket->IsClosed())
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        // Cannot comment ticket assigned to someone else
        //! Console excluded
        Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : NULL;
        if (player && ticket->IsAssignedNotTo(player->GetGUID()))
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetTicketId());
            return true;
        }

        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetComment(comment);
        ticket->SaveToDB(trans);
        sTicketMgr->UpdateLastChange();

        std::string msg = ticket->FormatMessageString(*handler, NULL, ticket->GetAssignedToName().c_str(), NULL, NULL);
        msg += handler->PGetParseString(LANG_COMMAND_TICKETLISTADDCOMMENT, player ? player->GetName().c_str() : "Console", comment);
        handler->SendGlobalGMSysMessage(msg.c_str());

        return true;
    }

    static bool HandleGMTicketDeleteByIdCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 ticketId = atoi(args);
        GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
        if (!ticket)
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        if (!ticket->IsClosed())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETCLOSEFIRST);
            return true;
        }

        std::string msg = ticket->FormatMessageString(*handler, NULL, NULL, NULL, handler->GetSession() ? handler->GetSession()->GetPlayer()->GetName().c_str() : "Console");
        handler->SendGlobalGMSysMessage(msg.c_str());

        sTicketMgr->RemoveTicket<GmTicket>(ticket->GetTicketId());
        sTicketMgr->UpdateLastChange();

        if (Player* player = ticket->GetPlayer())
        {
            if (player->IsInWorld())
            {
                // Force abandon ticket
                WorldPacket data(SMSG_GM_TICKET_UPDATE, 4);
                data << uint32(GMTICKET_RESPONSE_TICKET_DELETED);
                player->GetSession()->SendPacket(&data);
            }
        }

        return true;
    }

    static bool HandleGMTicketResetCommand(ChatHandler* handler, char const* /*args*/)
    {
        if (sTicketMgr->GetOpenTicketCount<GmTicket>())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETPENDING);
            return true;
        }
        else
        {
            sTicketMgr->ResetTickets<GmTicket>();
            handler->SendSysMessage(LANG_COMMAND_TICKETRESET);
        }

        return true;
    }

    static bool HandleGMTicketUnAssignCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 ticketId = atoi(args);
        GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
        if (!ticket || ticket->IsClosed())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }
        // Ticket must be assigned
        if (!ticket->IsAssigned())
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETNOTASSIGNED, ticket->GetTicketId());
            return true;
        }

        // Get security level of player, whom this ticket is assigned to
        uint32 security = SEC_PLAYER;
        Player* assignedPlayer = ticket->GetAssignedPlayer();
        if (assignedPlayer && assignedPlayer->IsInWorld())
            security = assignedPlayer->GetSession()->GetSecurity();
        else
        {
            uint64 guid = ticket->GetAssignedToGUID();
            uint32 accountId = sObjectMgr->GetPlayerAccountIdByGUID(guid);
            security = AccountMgr::GetSecurity(accountId, realmID);
        }

        // Check security
        //! If no m_session present it means we're issuing this command from the console
        uint32 mySecurity = handler->GetSession() ? handler->GetSession()->GetSecurity() : SEC_CONSOLE;
        if (security > mySecurity)
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETUNASSIGNSECURITY);
            return true;
        }

        std::string assignedTo = ticket->GetAssignedToName(); // copy assignedto name because we need it after the ticket has been unnassigned
        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetUnassigned();
        ticket->SaveToDB(trans);
        sTicketMgr->UpdateLastChange();

        std::string msg = ticket->FormatMessageString(*handler, NULL, assignedTo.c_str(),
            handler->GetSession() ? handler->GetSession()->GetPlayer()->GetName().c_str() : "Console", NULL);
        handler->SendGlobalGMSysMessage(msg.c_str());

        return true;
    }

    static bool HandleGMTicketGetByIdCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 ticketId = atoi(args);
        GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
        if (!ticket || ticket->IsClosed() || ticket->IsCompleted())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetViewed();
        ticket->SaveToDB(trans);

        handler->SendSysMessage(ticket->FormatMessageString(*handler, true).c_str());
        return true;
    }

    template<typename T>
    static bool HandleTicketAssignToCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* ticketIdStr = strtok((char*)args, " ");
        uint32 ticketId = atoi(ticketIdStr);

        char* targetStr = strtok(NULL, " ");
        if (!targetStr)
            return false;

        std::string target(targetStr);
        if (!normalizePlayerName(target))
            return false;

        GmTicket* ticket = sTicketMgr->GetTicket<GmTicket>(ticketId);
        if (!ticket || ticket->IsClosed())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        ObjectGuid targetGuid = sObjectMgr->GetPlayerGUIDByName(target);
        uint32 accountId = sObjectMgr->GetPlayerAccountIdByGUID(targetGuid);
        // Target must exist and have administrative rights
        //if (!AccountMgr::HasPermission(accountId, rbac::RBAC_PERM_COMMANDS_BE_ASSIGNED_TICKET, realmID))
        //{
        //    handler->SendSysMessage(LANG_COMMAND_TICKETASSIGNERROR_A);
        //    return true;
        //}

        // If already assigned, leave
        if (ticket->IsAssignedTo(targetGuid))
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETASSIGNERROR_B, ticket->GetTicketId());
            return true;
        }

        // If assigned to different player other than current, leave
        //! Console can override though
        Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : NULL;
        if (player && ticket->IsAssignedNotTo(player->GetGUID()))
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetTicketId(), target.c_str());
            return true;
        }

        // Assign ticket
        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetAssignedTo(targetGuid, AccountMgr::IsAdminAccount(AccountMgr::GetSecurity(accountId, realmID)));
         sTicketMgr->UpdateLastChange();

        ticket->SaveToDB(trans);

        std::string msg = ticket->FormatMessageString(*handler, NULL, target.c_str(), NULL, NULL);
        handler->SendGlobalGMSysMessage(msg.c_str());
        return true;
    }

    template<typename T>
    static bool HandleTicketCloseByIdCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 ticketId = atoi(args);
        T* ticket = sTicketMgr->GetTicket<T>(ticketId);
        if (!ticket || ticket->IsClosed())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        // Ticket should be assigned to the player who tries to close it.
        // Console can override though
        Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : NULL;
        if (player && ticket->IsAssignedNotTo(player->GetGUID()))
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETCANNOTCLOSE, ticket->GetTicketId());
            return true;
        }

        sTicketMgr->CloseTicket<T>(ticket->GetTicketId(), player ? player->GetGUID() : -1);

        std::string msg = ticket->FormatMessageString(*handler, player ? player->GetName().c_str() : "Console", NULL, NULL, NULL);
        handler->SendGlobalGMSysMessage(msg.c_str());

        // Inform player, who submitted this ticket, that it is closed
        if (Player* submitter = ticket->GetPlayer())
            sTicketMgr->SendGmTicketUpdate(SMSG_GM_TICKET_UPDATE, GMTICKET_RESPONSE_TICKET_DELETED, submitter);

        return true;
    }

    static bool HandleGMTicketListCommand(ChatHandler* handler, char const* /*args*/)
    {
        sTicketMgr->ShowList<GmTicket>(*handler, false);
        return true;
    }

    template<typename T>
    static bool HandleTicketListClosedCommand(ChatHandler* handler, char const* /*args*/)
    {
        sTicketMgr->ShowClosedList<T>(*handler);
        return true;
    }

    template<typename T>
    static bool HandleTicketCommentCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        char* ticketIdStr = strtok((char*)args, " ");
        uint32 ticketId = atoi(ticketIdStr);

        char* comment = strtok(NULL, "\n");
        if (!comment)
            return false;

        T* ticket = sTicketMgr->GetTicket<T>(ticketId);
        if (!ticket || ticket->IsClosed())
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        // Cannot comment ticket assigned to someone else
        //! Console excluded
        Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : NULL;
        if (player && ticket->IsAssignedNotTo(player->GetGUID()))
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetTicketId());
            return true;
        }

        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetComment(comment);
        ticket->SaveToDB(trans);
        sTicketMgr->UpdateLastChange();

        std::string msg = ticket->FormatMessageString(*handler, NULL, ticket->GetAssignedToName().c_str(), NULL, NULL);
        msg += handler->PGetParseString(LANG_COMMAND_TICKETLISTADDCOMMENT, player ? player->GetName().c_str() : "Console", comment);
        handler->SendGlobalGMSysMessage(msg.c_str());

        return true;
    }

    template<typename T>
    static bool HandleTicketDeleteByIdCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 ticketId = atoi(args);
        T* ticket = sTicketMgr->GetTicket<T>(ticketId);
        if (!ticket)
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        if (!ticket->IsClosed())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETCLOSEFIRST);
            return true;
        }

        std::string msg = ticket->FormatMessageString(*handler, NULL, NULL, NULL, handler->GetSession() ? handler->GetSession()->GetPlayer()->GetName().c_str() : "Console");
        handler->SendGlobalGMSysMessage(msg.c_str());

        sTicketMgr->RemoveTicket<T>(ticket->GetTicketId());

        if (Player* player = ticket->GetPlayer())
            sTicketMgr->SendGmTicketUpdate(SMSG_GM_TICKET_UPDATE, GMTICKET_RESPONSE_TICKET_DELETED, player);

        return true;
    }

    template<typename T>
    static bool HandleTicketListCommand(ChatHandler* handler, char const* /*args*/)
    {
        sTicketMgr->ShowList<T>(*handler);
        return true;
    }

    template<typename T>
    static bool HandleTicketUnAssignCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 ticketId = atoi(args);
        T* ticket = sTicketMgr->GetTicket<T>(ticketId);
        if (!ticket || ticket->IsClosed())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }
        // Ticket must be assigned
        if (!ticket->IsAssigned())
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETNOTASSIGNED, ticket->GetTicketId());
            return true;
        }

        // Get security level of player, whom this ticket is assigned to
        uint32 security = SEC_PLAYER;
        Player* assignedPlayer = ticket->GetAssignedPlayer();
        if (assignedPlayer)
            security = assignedPlayer->GetSession()->GetSecurity();
        else
        {
            uint64 guid = ticket->GetAssignedToGUID();
            uint32 accountId = sObjectMgr->GetPlayerAccountIdByGUID(guid);
            security = AccountMgr::GetSecurity(accountId, realmID);
        }

        // Check security
        //! If no m_session present it means we're issuing this command from the console
        uint32 mySecurity = handler->GetSession() ? handler->GetSession()->GetSecurity() : SEC_CONSOLE;
        if (security > mySecurity)
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETUNASSIGNSECURITY);
            return true;
        }

        std::string assignedTo = ticket->GetAssignedToName(); // copy assignedto name because we need it after the ticket has been unnassigned
        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetUnassigned();
        ticket->SaveToDB(trans);

        std::string msg = ticket->FormatMessageString(*handler, NULL, assignedTo.c_str(), handler->GetSession() ? handler->GetSession()->GetPlayer()->GetName().c_str() : "Console", NULL);
        handler->SendGlobalGMSysMessage(msg.c_str());

        return true;
    }

    template<typename T>
    static bool HandleTicketGetByIdCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 ticketId = atoi(args);
        T* ticket = sTicketMgr->GetTicket<T>(ticketId);
        if (!ticket || ticket->IsClosed())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        handler->SendSysMessage(ticket->FormatMessageString(*handler, true).c_str());
        return true;
    }

    template<typename T>
    static bool HandleTicketResetCommand(ChatHandler* handler, char const* /*args*/)
    {
        if (sTicketMgr->GetOpenTicketCount<T>())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETPENDING);
            return true;
        }
        else
        {
            sTicketMgr->ResetTickets<T>();
            handler->SendSysMessage(LANG_COMMAND_TICKETRESET);
        }
        return true;
    }

    static bool HandleGMTicketCompleteCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 ticketId = atoi(args);
        GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
        if (!ticket || ticket->IsClosed() || ticket->IsCompleted())
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        if (Player* player = ticket->GetPlayer())
            if (player->IsInWorld())
                sTicketMgr->SendGmResponsee(player->GetSession(), ticket);

        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetCompleted();
        ticket->SaveToDB(trans);

        sTicketMgr->UpdateLastChange();
        return true;
    }

    static bool HandleGMTicketEscalateCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        uint32 ticketId = atoi(args);
        GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
        if (!ticket || ticket->IsClosed() || ticket->IsCompleted() || ticket->GetEscalatedStatus() != TICKET_UNASSIGNED)
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        ticket->SetEscalatedStatus(TICKET_IN_ESCALATION_QUEUE);

        if (Player* player = ticket->GetPlayer())
            if (player->IsInWorld())
                sTicketMgr->SendGmTicket(player->GetSession(), ticket);

        sTicketMgr->UpdateLastChange();
        return true;
    }

    static bool HandleGMTicketListEscalatedCommand(ChatHandler* handler, char const* /*args*/)
    {
        sTicketMgr->ShowGmEscalatedList(*handler);
        return true;
    }

    static bool HandleGMTicketListOnlineCommand(ChatHandler* handler, char const* /*args*/)
    {
        sTicketMgr->ShowList<GmTicket>(*handler, true);
        return true;
    }

    static bool HandleToggleGMTicketSystem(ChatHandler* handler, char const* /*args*/)
    {
        bool status = sWorld->getBoolConfig(CONFIG_TICKETS_GM_ENABLED) ? true : (sTicketMgr->GetGmTicketSystemStatus() ? true : false);
        int32 message = status ? LANG_ALLOW_TICKETS : LANG_DISALLOW_TICKETS;
        sTicketMgr->SetGmTicketSystemStatus(status);
        handler->PSendSysMessage(message);
        return true;
    }

    static bool HandleGMTicketGetByNameCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        std::string name(args);
        if (!normalizePlayerName(name))
            return false;

        // Detect target's GUID
        uint64 guid = 0;
        if (Player* player = sObjectAccessor->FindPlayerByName(name))
            guid = player->GetGUID();
        else
            guid = sObjectMgr->GetPlayerGUIDByName(name);

        // Target must exist
        if (!guid)
        {
            handler->SendSysMessage(LANG_NO_PLAYERS_FOUND);
            return true;
        }

        // Ticket must exist
        GmTicket* ticket = sTicketMgr->GetGmTicketByPlayerGuid(guid);
        if (!ticket)
        {
            handler->SendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        SQLTransaction trans = SQLTransaction(NULL);
        ticket->SetViewed();
        ticket->SaveToDB(trans);

        handler->SendSysMessage(ticket->FormatMessageString(*handler, true).c_str());
        return true;
    }

    static bool _HandleGMTicketResponseAppendCommand(char const* args, bool newLine, ChatHandler* handler)
    {
        if (!*args)
            return false;

        char* ticketIdStr = strtok((char*)args, " ");
        uint32 ticketId = atoi(ticketIdStr);

        char* response = strtok(NULL, "\n");
        if (!response)
            return false;

        GmTicket* ticket = sTicketMgr->GetTicket(ticketId);
        if (!ticket || ticket->IsClosed())
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETNOTEXIST);
            return true;
        }

        // Cannot add response to ticket, assigned to someone else
        //! Console excluded
        Player* player = handler->GetSession() ? handler->GetSession()->GetPlayer() : NULL;
        if (player && ticket->IsAssignedNotTo(player->GetGUID()))
        {
            handler->PSendSysMessage(LANG_COMMAND_TICKETALREADYASSIGNED, ticket->GetTicketId());
            return true;
        }

        SQLTransaction trans = SQLTransaction(NULL);
        ticket->AppendResponse(response);
        if (newLine)
            ticket->AppendResponse("\n");
        ticket->SaveToDB(trans);

        return true;
    }

    static bool HandleGMTicketResponseAppendCommand(ChatHandler* handler, char const* args)
    {
        return _HandleGMTicketResponseAppendCommand(args, false, handler);
    }

    static bool HandleGMTicketResponseAppendLnCommand(ChatHandler* handler, char const* args)
    {
        return _HandleGMTicketResponseAppendCommand(args, true, handler);
    }
};

void AddSC_ticket_commandscript()
{
    new ticket_commandscript();
}
