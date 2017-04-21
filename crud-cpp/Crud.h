#ifndef CRUD_H
#define CRUD_H

#include <iostream>
#include "Date.h"

using namespace std;

class Crud
{
	public:
		static int Insert_Customer(std::string name, std::string email, double salary, Date birthday, std::string gender);
		static int Edit_Customer(int id, std::string name, std::string email, double salary, Date birthday, std::string gender);
		static int Delete_Customer(int id);
		static int GetPhysicalPersonByID(int id);
		static int GetPhysicalPersonByName(std::string name);
};

#endif