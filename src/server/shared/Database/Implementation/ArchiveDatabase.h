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

#ifndef ARCHIVE_DATABASE_H
#define ARCHIVE_DATABASE_H

#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"

enum ArchiveDatabaseStatements
{
    ARCH_INS_CURRENCY_TRANSACTIONS,
    ARCH_MAX,
};

class ArchiveDatabaseConnection : public MySQLConnection
{
public:
    ArchiveDatabaseConnection(MySQLConnectionInfo& connInfo, ConnectionFlags index)
        : MySQLConnection(connInfo, index) { }

    void DoPrepareStatements()
    {
        if (!m_reconnecting)
            m_stmts.resize(ARCH_MAX);

        PrepareStatement(ARCH_INS_CURRENCY_TRANSACTIONS, "INSERT INTO `currency_transactions` (`guid`, `unix_time`, `operation`, `param`, `attachments`, `amount_before`, `amount_after`, `realmid`) VALUES (?, ?, ?, ?, ?, ?, ?, ?)", CONNECTION_ASYNC);
    }
};

typedef DatabaseWorkerPool<ArchiveDatabaseConnection> ArchiveDatabaseWorkerPool;

#endif // !ARCHIVE_DATABASE_H
