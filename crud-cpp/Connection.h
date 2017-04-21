#ifndef CONNECTION_H
#define CONNECTION_H

#include "sqlite3.h"
using namespace std;


class Connection
{
public:
	static sqlite3 *Connect();
	static void Close(sqlite3 *db);
};

#endif