
#ifndef __DATE_H
#define __DATE_H

#include "Exceptions.h"
#include <iostream>

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date();                                                  // constractor with the current date.
	Date(int day, int month, int year) noexcept(false);   // constructor with day, month, year by values.

	friend std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		os << date.day << " " << date.month << " " << date.year;
		return os;
	}

	const int getDay() const { return day; };
	const int getmonth() const { return month; };
	const int getYear() const { return year; };
};

#endif