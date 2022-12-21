
#include "Status.h"
#include <string>
#include <iostream>

using namespace std;
#pragma warning(disable: 4996)

const int TEN = 10;

Status::Status(const std::string text) : date(), time()
{
	this->text = text;
}

void Status::printStatus() const
{
	cout << "\nThe status wroten at: " << (date.getDay() < TEN ? "0" : "") << date.getDay() << " / "
		<< (date.getmonth() < TEN ? "0" : "") << date.getmonth() << " / " << date.getYear() << endl
		<< "At time: " << (time.getHour() < 10 ? "0" : "") << time.getHour() << " : "
		<< (time.getminute() < TEN ? "0" : "") << time.getminute() << endl
		<< "The status is: " << text << endl;
}