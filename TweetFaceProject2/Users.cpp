
#include <iostream>
#include <string>
#include "Users.h"
#include "Status.h"
#include "FansPage.h"

using namespace std;

User::User(const string _name, int day, int month, int year) : bDay(day, month, year)
{
	this->name = _name;
}


User::~User()
{
	for (int i = 0; i < publishBoard.size(); i++)
	{
		delete publishBoard[i];
	}
}



const User& User::operator+=(User& _friend)
{
	if (checkIfFriend(_friend.getName()) == false)
	{
		friends.push_back(&_friend);

		_friend += *this;
	}

	return *this;
}


const User& User::operator+=(FansPage& fanPage)
{
	if (checkIfFanOfFanPage(fanPage) == false)
	{
		fansPages.push_back(&fanPage);

		fanPage += *this;
	}

	return *this;
}


bool User::operator>(const User& _friend) const
{
	if (friends.size() > _friend.friends.size())
		return true;
	else
		return false;
}

bool User::operator<(const User& _friend) const
{
	return _friend > *this;
}

bool User::operator>(const FansPage& fanPage) const
{
	if (friends.size() > fanPage.getNumOfFans())
		return true;
	else
		return false;
}
bool User::operator<(const FansPage& fanPage) const
{
	return fanPage > *this;
}

void User::printTenLastStatusOfTheUser() const
{
	int size = publishBoard.size();

	for (int i = size - 1; (i > (size - 1) - 10) && (i >= 0); i--)
	{
		publishBoard[i]->printStatus();
	}
}


void User::addStatus(const string text)
{
	Status* tweet = new Status(text);
	publishBoard.push_back(tweet);
}


void User::removeFriend(User& _friend)
{
	int size = friends.size();

	if (checkIfFriend(_friend.getName()) == true)
	{
		for (int i = 0; i < size; i++)
		{
			if (friends[i] == &_friend)
			{
				if (i != friends.size() - 1)
					swap(friends[i], friends[size - 1]);
				friends.pop_back();
				i = size;
			}
		}
		_friend.removeFriend(*this);
	}
}


void User::printAllFriends() const
{
	int size = friends.size();

	for (int i = 0; i < size; i++)
	{
		friends[i]->printUser();
	}
}


void User::printAllStatuses() const
{
	int size = publishBoard.size();

	for (int i = 0; i < size; i++)
	{
		publishBoard[i]->printStatus();
	}
}


void User::removeFansPage(FansPage& page)
{
	int size = fansPages.size();

	if (checkIfFanOfFanPage(page) == true)
	{
		for (int i = 0; i < size; i++)
		{
			if (fansPages[i] == &page)
			{
				if (i != fansPages.size() - 1)
					swap(fansPages[i], fansPages[size - 1]);
				fansPages.pop_back();
				i = size;
			}
		}
		page.removeFan(*this);
	}
}


bool User::checkIfFriend(const string name) const
{
	int size = friends.size();

	for (int i = 0; i < size; i++)
	{
		if (friends[i]->name == name)
			return true;
	}

	return false;
}


bool User::checkIfFanOfFanPage(const FansPage& fanPage) const
{
	int size = fansPages.size();

	for (int i = 0; i < size; i++)
	{
		if (fansPages[i]->getName() == fanPage.getName())
			return true;
	}

	return false;
}


void User::printAllFanPages() const
{
	int size = fansPages.size();

	for (int i = 0; i < size; i++)
	{
		fansPages[i]->printFanPage();
	}
}


void User::printUser() const
{
	cout << "\nUser Name is: " << name << endl
		<< "Birth day is: " << (bDay.getDay() < 10 ? "0" : "") << bDay.getDay() << " / "
		<< (bDay.getmonth() < 10 ? "0" : "") << bDay.getmonth() << " / " << bDay.getYear() << endl;
}