
#include "Time.h"
#include <ctime>

#pragma warning(disable: 4996)

Time::Time()
{
	time_t timeSecounds = time(0);
	tm* currentTime = localtime(&timeSecounds);

	hour = currentTime->tm_hour;
	minute = currentTime->tm_min;
}