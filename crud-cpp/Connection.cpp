#include "Connection.h"
#include "sqlite3.h"
#include <exception>

	sqlite3* Connection::Connect()
	{
		sqlite3 *db;
		int rc;
		rc = sqlite3_open("dbCrudCustomer.db", &db);
		if (rc == SQLITE_OK)
		{
			return db;
		}
		else
		{
			throw "Error connecting to database.";
			exit(0);
		}
	}

	void Connection::Close(sqlite3 *db)
	{
		int rc;
		rc = sqlite3_close(db);
		if (!(rc == SQLITE_OK))
		{
			throw "Error desconnecting to database.";
			exit(0);
		}
	}
