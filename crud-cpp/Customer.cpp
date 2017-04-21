#include "Date.h"
#include<iostream>
#include "Customer.h"

using namespace std;

	void Customer::setSalary(double salary)
	{
		this->salary = salary;
	}

	double Customer::getSalary()
	{
		return this->salary;
	}

	void Customer::setBirthday(Date birthday)
	{
		this->birthday = birthday;
	}

	Date Customer::getBirthday()
	{
		return this->birthday;
	}

	void Customer::setGender(std::string gender)
	{
		this->gender = gender;
	}

	std::string Customer::getGender()
	{
		return this->gender;
	}

	void Customer::setID(int id)
	{
		this->id = id;
	}

	int Customer::getID()
	{
		return this->id;
	}

	void Customer::setName(std::string name)
	{
		this->name = name;
	}

	std::string Customer::getName()
	{
		return this->name;
	}

	void Customer::setEmail(std::string email)
	{
		this->email = email;
	}

	std::string Customer::getEmail()
	{
		return this->email;
	}

	Customer::~Customer()
	{

	}
