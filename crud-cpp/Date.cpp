#include "Date.h"
#include <exception>
#include <iostream>
#include <sstream>

using namespace std;

	bool Date::ValidDay()
	{
		if ((this->day > 0) && (this->day < 32))
		{
			if (this->day == 29)
			{
				if ((this->month == 2) && ((this->year % 4) == 0))
				{
					return true;
				}
				else
				{
					throw "Invalid month's day.";
					exit(0);
				}
			}

			if (this->day == 30)
			{
				if (this->month == 4)
				{
					return true;
				}

				if (this->month == 6)
				{
					return true;
				}

				if (this->month == 9)
				{
					return true;
				}

				if (this->month == 11)
				{
					return true;
				}
			}

			return true;
		}
		else
		{
			throw "Invalid month's day.";
			exit(0);
		}
	}


	bool Date::ValidMonth()
	{
		if (this->month > 0 && this->month < 13)
		{
			return true;
		}
		else
		{
			throw "Invalid month.";
			exit(0);
		}
	}

	bool Date::ValidYear()
	{
		if (this->year > 1700)
		{
			return true;
		}
		else
		{
			throw "Invalid year.";
			exit(0);
		}
	}

	Date::Date()
	{

	}

	Date::Date(int year, int month, int day)
	{
		this->year = year;
		this->ValidYear();
		this->month = month;
		this->ValidMonth();
		this->day = day;
		this->ValidDay();
	}

	std::string Date::ToString()
	{
		ostringstream ss;
		ss << this->year << "-" << this->month << "-" << this->day;
		return ss.str();
	}

	Date::~Date()
	{

	}

