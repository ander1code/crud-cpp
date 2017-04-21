#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include "sqlite3.h"
#include "Date.h"
#include "Customer.h"

using namespace std;

class Controller
{
private:
	Customer cust;
	sqlite3* conn;

	int BeginTrans();
	int Commit();
	int Rollback();
	int InsertPerson(int id, std::string name, std::string email, double salary, Date birthday, std::string gender);
	int InsertCustomer();
	int EditPerson(int id, std::string name, std::string email, double salary, Date birthday, std::string gender);
	int EditCustomer();
	int DeletePerson(int id);
	int DeleteCustomer();

public:
	Controller(Customer cust);
	Controller();
	~Controller();
	int Insert_Customer();
	int Edit_Customer();
	int Delete_Customer();
	static int callbackGET(void *unused, int count, char **data, char **columns);
	int GetPhysicalPersonByID();
	int GetPhysicalPersonByName();
};

#endif
