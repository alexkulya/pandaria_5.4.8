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
