
#include "Date.h"
#include <ctime>

#pragma warning (disable: 4996)

const int LAST_CENTURY = 1900;
const int CURRENT_YEAR = 2022;
const int FIRST_DAY_OF_THE_MONTH = 1;
const int LAST_DAY_OF_THE_MONTH = 30;
const int FIRST_MONTH_OF_THE_YEAR = 1;
const int LAST_MONTH_OF_THE_YEAR = 12;

Date::Date()
{
	time_t timeSecounds = time(0);
	tm* currentTime = localtime(&timeSecounds);

	day = currentTime->tm_mday;
	month = 1 + currentTime->tm_mon;
	year = LAST_CENTURY + currentTime->tm_year;
}

Date::Date(int day, int month, int year) throw (const char*)
{

	if (day < FIRST_DAY_OF_THE_MONTH || day > LAST_DAY_OF_THE_MONTH)
		throw "\nDay must be between 1 to 31";
	if (month < FIRST_MONTH_OF_THE_YEAR || month > LAST_MONTH_OF_THE_YEAR)
		throw "\nMonth must be between 1 to 31";
	if (year < LAST_CENTURY || year > CURRENT_YEAR)
		throw "\nYear must be between 1900 to 2022";

	this->day = day;
	this->month = month;
	this->year = year;
}