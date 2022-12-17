#ifndef __STATUS_H
#define __STATUS_H

#include "Date.h"
#include "Time.h"


class Status
{
private:
	Date date;
	Time time;
	char* text;

public:
	Status(const char* txt);
	Status(const Status& other) = delete;
	~Status();

	void printStatus() const;
};

#endif // !__STATUS_H