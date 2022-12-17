
#include "Status.h"
#include <string.h>
#include <iostream>

using namespace std;
#pragma warning(disable: 4996)

Status::Status(const char* txt) : date(), time()
{
	text = new char[strlen(txt) + 1];
	strcpy(text, txt);
}

Status::~Status()
{
	delete[]text;
}

void Status::printStatus() const
{
	cout << "\nThe status wroten at: " << (date.getDay() < 10 ? "0" : "") << date.getDay() << " / "
		<< (date.getmonth() < 10 ? "0" : "") << date.getmonth() << " / " << date.getYear() << endl
		<< "At time: " << (time.getHour() < 10 ? "0" : "") << time.getHour() << " : "
		<< (time.getminute() < 10 ? "0" : "") << time.getminute() << endl
		<< "The status is: " << text << endl;
}