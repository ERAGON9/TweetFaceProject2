#ifndef __DATE_H
#define __DATE_H

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date();                                                 // constractor with the current date.
	Date(const int day, const int month, const int year);   // constructor with day,month,year by values.
	const int getDay() const { return day; };
	const int getmonth() const { return month; };
	const int getYear() const { return year; };
};

#endif