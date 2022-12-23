#ifndef __TIME_H
#define __TIME_H

class Time
{
private:
	int hour;
	int minute;

public:
	Time();
	int getHour() const { return hour; };
	int getminute() const { return minute; };
};

#endif