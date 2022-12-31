
#include "Status.h"
#include <string>
#include <iostream>
#include "Exceptions.h"

using namespace std;

const int TEN = 10;

Status::Status(const std::string text) : date(), time()
{
	this->text = text;

	if (text.size() == 0)
		throw EmptyStatusException();
}


bool Status::operator==(const Status& otherStatus)
{
	if (text == otherStatus.getText())
		return true;
	else
		return false;
}


bool Status::operator!=(const Status& otherStatus)
{
	if (*this == otherStatus)
		return false;
	else
		return true;
}


void Status::printStatus() const
{
	cout << "\nThe status wroten at: " << (date.getDay() < TEN ? "0" : "") << date.getDay() << " / "
		<< (date.getmonth() < TEN ? "0" : "") << date.getmonth() << " / " << date.getYear() << endl
		<< "At time: " << (time.getHour() < 10 ? "0" : "") << time.getHour() << " : "
		<< (time.getminute() < TEN ? "0" : "") << time.getminute() << endl
		<< "The status is: " << text << endl;
}