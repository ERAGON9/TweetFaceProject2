#ifndef __TIME_H
#define __TIME_H

class Time
{
private:
	int hour;
	int minute;

public:
	Time();
	const int getHour() const { return hour; };
	const int getminute() const { return minute; };
};

#endif