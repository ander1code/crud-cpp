#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <sstream>
#include "Date.h"

using namespace std;

class Person
{
public:
	virtual void setID(int id) = 0;
	virtual int getID() = 0;
	virtual void setName(std::string name) = 0;
	virtual std::string getName() = 0;
	virtual void setEmail(std::string email) = 0;
	virtual std::string getEmail() = 0;
	virtual void setSalary(double salary) = 0;
	virtual double getSalary() = 0;
	virtual void setBirthday(Date birthday) = 0;
	virtual Date getBirthday() = 0;
	virtual void setGender(std::string gender) = 0;
	virtual std::string getGender() = 0;
};

#endif