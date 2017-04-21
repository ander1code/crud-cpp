#include <iostream>
#include "Date.h"
#include "Customer.h"
#include "Controller.h"
#include "Crud.h"

using namespace std;

	int Crud::Insert_Customer(std::string name, std::string email, double salary, Date birthday, std::string gender)
	{
		Customer cust;
		cust = Customer();
		cust.setName(name);
		cust.setEmail(email);
		cust.setSalary(salary);
		cust.setBirthday(birthday);
		cust.setGender(gender);
		Controller ctr = Controller(cust);
		return ctr.Insert_Customer();
		return 1;
	}

	int Crud::Edit_Customer(int id, std::string name, std::string email, double salary, Date birthday, std::string gender)
	{
		Customer cust;
		cust = Customer();
		cust.setID(id);
		cust.setName(name);
		cust.setEmail(email);
		cust.setSalary(salary);
		cust.setBirthday(birthday);
		cust.setGender(gender);
		Controller ctr = Controller(cust);
		return ctr.Edit_Customer();
		return 1;
	}


	int Crud::Delete_Customer(int id)
	{
		Customer cust;
		cust = Customer();
		cust.setID(id);
		Controller ctr = Controller(cust);
		return ctr.Delete_Customer();
		return 1;
	}

	int Crud::GetPhysicalPersonByID(int id)
	{
		Customer cust;
		cust = Customer();
		cust.setID(id);
		Controller ctr = Controller(cust);
		return ctr.GetPhysicalPersonByID();
		return 1;
	}

	int Crud::GetPhysicalPersonByName(std::string name)
	{
		Customer cust;
		cust = Customer();
		cust.setName(name);
		Controller ctr = Controller(cust);
		return ctr.GetPhysicalPersonByName();
		return 1;
	}

