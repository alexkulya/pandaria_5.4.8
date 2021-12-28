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

#include "TCSoap.h"
#include "Log.h"
#include "World.h"
#include "AccountMgr.h"
#include "Chat.h"
#include <soapService.h>
#include <mutex>
#include <condition_variable>

class SoapService::ServiceImpl : public Service
{
public:
    ~ServiceImpl()
    {
        Finished(this, false);
#ifdef _WIN32
        closesocket(soap->master);
#else
        shutdown(soap->master, SHUT_RDWR);
        close(soap->master);
#endif
        if (_thr.joinable())
            _thr.join();
        destroy();
    }

    void Run(std::string const& host, uint32 port)
    {
        Service_init(SOAP_C_UTFSTRING, SOAP_C_UTFSTRING);
        soap->bind_flags = SO_REUSEADDR;

        if (!soap_valid_socket(bind(host.c_str(), port, 100)))
        {
            TC_LOG_ERROR("soap", "TCSoap: couldn't bind to %s:%d", host.c_str(), port);
            World::StopNow(ERROR_EXIT_CODE);
            return;
        }

        TC_LOG_ERROR("soap", "TCSoap: bound to http://%s:%d", host.c_str(), port);

        _thr = std::thread([this]()
        {
            while (!World::IsStopped())
            {
                if (soap_valid_socket(accept()))
                {
                    TC_LOG_INFO("soap", "Connection accepted from  %d.%d.%d.%d", (int)(this->soap->ip >> 24) & 0xFF, (int)(this->soap->ip >> 16) & 0xFF, (int)(this->soap->ip >> 8) & 0xFF, (int)(this->soap->ip) & 0xFF);
                    serve();
                    soap_destroy(this->soap);
                    soap_end(this->soap);
                }
            }
        });
    }

    int executeCommand(char* command, char** result) override
    {
        TC_LOG_INFO("soap", "executeCommand invoked: %s", command ? command : "");

        // security check
        if (!soap->userid || !soap->passwd)
        {
            TC_LOG_ERROR("soap", "TCSoap: Client didn't provide login information");
            return 401;
        }

        uint32 accountId = AccountMgr::GetId(soap->userid);
        if (!accountId)
        {
            TC_LOG_ERROR("soap", "TCSoap: Client used invalid username '%s'", soap->userid);
            return 401;
        }

        if (!AccountMgr::CheckPassword(accountId, soap->passwd))
        {
            TC_LOG_ERROR("soap", "TCSoap: invalid password for account '%s'", soap->userid);
            return 401;
        }

        if (AccountMgr::GetSecurity(accountId) < SEC_ADMINISTRATOR)
        {
            TC_LOG_ERROR("soap", "TCSoap: %s's gmlevel is too low", soap->userid);
            return 403;
        }

        if (!command || !*command)
            return soap_sender_fault(soap, "Command mustn't be empty", "The supplied command was an empty string");

        std::unique_lock<std::mutex> g(_mut);
        // commands are executed in the world thread. We have to wait for them to be completed
        {
            // CliCommandHolder will be deleted from world, accessing after queueing is NOT save
            CliCommandHolder* cmd = new CliCommandHolder(this, command, &ServiceImpl::Print, &ServiceImpl::Finished);
            sWorld->QueueCliCommand(cmd);
        }

        _cond.wait(g, [this]() -> bool { return _executed; });
        char* buff = strdup(_resp.c_str());
        TC_LOG_INFO("soap", "Command invoked, result: %u\n%s", _result, buff);
        _executed = false;
        _resp.clear();

        if (_result)
        {
            *result = buff;
            return SOAP_OK;
        }
        else
            return soap_senderfault(buff, buff);
    }

    Service* copy() { std::abort(); }

private:
    static void Print(void* service, char const* args)
    {
        ((ServiceImpl*)service)->_resp.append(args);
    }

    static void Finished(void* service, bool success)
    {
        ServiceImpl* s = ((ServiceImpl*)service);
        s->_executed = true;
        s->_result = success;
        s->_cond.notify_all();
    }

private:
    std::string _resp;
    std::mutex _mut;
    std::condition_variable _cond;
    std::thread _thr;
    bool _executed = false;
    bool _result;
};

SoapService::SoapService()
{
}

SoapService::~SoapService()
{
    delete _impl;
}

void SoapService::Run(std::string const& host, uint32 port)
{
    _impl = new ServiceImpl();
    _impl->Run(host, port);
}

struct Namespace namespaces[] =
{
    { "SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL },
    { "SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL },
    { "xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL },
    { "xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL },
    { "ns1", "urn:TC", NULL, NULL },
    { NULL, NULL, NULL, NULL }
};
