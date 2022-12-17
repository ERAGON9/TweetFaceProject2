
#include "Date.h"
#include <ctime>

#pragma warning(disable: 4996)

Date::Date()
{
	time_t timeSecounds = time(0);
	tm* currentTime = localtime(&timeSecounds);

	day = currentTime->tm_mday;
	month = 1 + currentTime->tm_mon;
	year = 1900 + currentTime->tm_year;
}

Date::Date(const int day, const int month, const int year) : day(day), month(month), year(year)
{}