/*
* This file is part of the Pandaria 5.4.8 Project. See THANKS file for Copyright information
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
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

#ifndef _M_DELAY_EXECUTOR_H
#define _M_DELAY_EXECUTOR_H

#include "ActivationQueue.h"

#include <thread>
#include <vector>

class DelayExecutor
{
    public:

        DelayExecutor();
        virtual ~DelayExecutor();

        static DelayExecutor* instance();

        int execute(Trinity::MethodRequest* new_req);

        int start(int num_threads = 1, Trinity::MethodRequest* pre_svc_hook = NULL, Trinity::MethodRequest* post_svc_hook = NULL);

        int deactivate();

        bool activated();

        virtual int svc();

    private:

        Trinity::ActivationQueue queue_;
        Trinity::MethodRequest* pre_svc_hook_;
        Trinity::MethodRequest* post_svc_hook_;
        bool activated_;
        // ACE_Task_Base kept its own thread list; with it gone the pool is held
        // here so deactivate() can still join every worker.
        std::vector<std::thread> threads_;

        void activated(bool s);
};

#endif // _M_DELAY_EXECUTOR_H
