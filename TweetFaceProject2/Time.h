#ifndef __TIME_H
#define __TIME_H

#include <iostream>

class Time
{
private:
	int hour;
	int minute;

public:
	Time();
	Time(int hour, int minute) noexcept(false);

	friend std::ostream& operator<<(std::ostream& os, const Time& time)
	{
		os << time.hour << " " << time.minute;
		return os;
	}

	int getHour() const { return hour; };
	int getminute() const { return minute; };
};

#endif