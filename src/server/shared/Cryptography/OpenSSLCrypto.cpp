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

#include <OpenSSLCrypto.h>
#include "Errors.h"
#include <openssl/crypto.h>
#include <ace/Thread_Mutex.h>
#include <vector>
#include <ace/Thread.h>
#if OPENSSL_VERSION_NUMBER >= 0x30000000L
#include <openssl/provider.h>
OSSL_PROVIDER* LegacyProvider;
OSSL_PROVIDER* DefaultProvider;
#endif


void OpenSSLCrypto::threadsSetup([[maybe_unused]] boost::filesystem::path const& providerModulePath)
{
#if OPENSSL_VERSION_NUMBER >= 0x30000000L
#if PLATFORM == PLATFORM_WINDOWS
    OSSL_PROVIDER_set_default_search_path(nullptr, providerModulePath.string().c_str());
#endif
    // Loading any provider explicitly stops the default one from being loaded
    // implicitly, so "default" has to be requested alongside "legacy" (which is
    // where RC4 lives from OpenSSL 3.0 on). Fail here rather than on the first
    // session, when the cause is no longer obvious.
    LegacyProvider = OSSL_PROVIDER_load(nullptr, "legacy");
    WPFatal(LegacyProvider, "Failed to load the OpenSSL legacy provider. Check that legacy.so (legacy.dll on Windows) ships with the OpenSSL installation.");

    DefaultProvider = OSSL_PROVIDER_load(nullptr, "default");
    WPFatal(DefaultProvider, "Failed to load the OpenSSL default provider.");
#endif
}

void OpenSSLCrypto::threadsCleanup()
{
#if OPENSSL_VERSION_NUMBER >= 0x30000000L
    if (LegacyProvider)
        OSSL_PROVIDER_unload(LegacyProvider);

    if (DefaultProvider)
        OSSL_PROVIDER_unload(DefaultProvider);

    OSSL_PROVIDER_set_default_search_path(nullptr, nullptr);
#endif
}
