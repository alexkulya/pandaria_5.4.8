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

#ifndef SF_SINGLETON_H
#define SF_SINGLETON_H

namespace Trinity
{
    // Replacement for ACE_Singleton<T, Mutex>.
    //
    // The mutex parameter is gone on purpose. ACE needed it because C++98 gave
    // no guarantee about concurrent initialisation of a function-local static,
    // so ACE_Singleton<T, ACE_Thread_Mutex> did its own double-checked locking.
    // Since C++11 the standard requires exactly that guarantee, so the single
    // static below is already safe under concurrent first use and carrying a
    // mutex argument would only preserve ACE's shape, not any behaviour.
    //
    // Classes with a private constructor grant access with
    //
    //     friend class Trinity::Singleton<MyManager>;
    //
    // which works because the local static is constructed inside a member of
    // the befriended class.
    //
    // Destruction differs from ACE and it is worth knowing: ACE registered
    // every instance with ACE_Object_Manager and destroyed them during
    // ACE::fini(), whereas these are destroyed with the other function-local
    // statics at process exit, in reverse order of construction.
    template<class T>
    class Singleton
    {
    public:
        static T* instance()
        {
            static T instance;
            return &instance;
        }

    private:
        Singleton();
        ~Singleton();
        Singleton(Singleton const&);
        Singleton& operator=(Singleton const&);
    };
}

#endif // SF_SINGLETON_H
