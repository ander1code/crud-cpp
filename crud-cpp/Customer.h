#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Date.h"
#include<iostream>
using namespace std;

class Customer : public Person
{
	private:
		int id;
		std::string name;
		std::string email;
		double salary;
		Date birthday;
		std::string gender;
	public:
		void setSalary(double salary);
		double getSalary();
		void setBirthday(Date birthday);
		Date getBirthday();
		void setGender(std::string gender);
		std::string getGender();
		void setID(int id);
		int getID();
		void setName(std::string name);
		std::string getName();
		void setEmail(std::string email);
		std::string getEmail();
		~Customer();
};

#endif