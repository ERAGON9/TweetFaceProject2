#ifndef __STATUS_H
#define __STATUS_H

#include <string>
#include "Date.h"
#include "Time.h"


class Status
{
private:
	Date date;
	Time time;
	std::string text;

public:
	Status(const std::string text);
	Status(const Status& other) = delete;
	bool operator==(const Status& otherStatus);
	bool operator!=(const Status& otherStatus);

	std::string getText() const { return text; }
	void printStatus() const;
};

#endif // !__STATUS_H