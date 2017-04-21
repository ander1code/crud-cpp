#ifndef DATE_H
#define DATE_H

#include "Date.h"
#include <iostream>

class Date
{
	private:
		int day;
		int month;
		int year;

		bool ValidDay();
		bool ValidMonth();
		bool ValidYear();
	public:
		Date();
		Date(int year, int month, int day);
		std::string ToString();
		~Date();
};

#endif