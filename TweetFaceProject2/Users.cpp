
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
	vector<Status*>::iterator itr = publishBoard.begin();
	vector<Status*>::iterator itrEnd = publishBoard.end();

	for (; itr != itrEnd; ++itr)
	{
		delete *itr;
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
	auto itr = publishBoard.end();

	for (int i = 0; i < 10 && i < size; i++)
	{
		--itr;
		(*itr)->printStatus();
	}
}


void User::addStatus(const string text)
{
	Status* tweet = new Status(text);
	publishBoard.push_back(tweet);
}


void User::removeFriend(User& _friend)
{
	vector<User*>::iterator itr = friends.begin();
	vector<User*>::iterator itrEnd = friends.end();

	if (checkIfFriend(_friend.getName()) == true)
	{
		for (; itr != itrEnd; ++itr)
		{
			if (*itr == &_friend)
			{
				if (itr != itrEnd)
					swap(itr, itrEnd);
				friends.pop_back();
				itr = itrEnd;
			}
		}
		_friend.removeFriend(*this);
	}
}


void User::printAllFriends() const
{
	auto itr = friends.begin();
	auto itrEnd = friends.end();

	for (; itr != itrEnd; ++itr)
	{
		(*itr)->printUser();
	}
}


void User::printAllStatuses() const
{
	auto itr = publishBoard.begin();
	auto itrEnd = publishBoard.end();

	for (; itr != itrEnd; ++itr)
	{
		(*itr)->printStatus();
	}
}


void User::removeFansPage(FansPage& page)
{
	vector<FansPage*>::iterator itr = fansPages.begin();
	vector<FansPage*>::iterator itrEnd = fansPages.end();

	if (checkIfFanOfFanPage(page) == true)
	{
		for (; itr != itrEnd; ++itr)
		{
			if (*itr == &page)
			{
				if (itr != itrEnd)
					swap(itr, itrEnd);
				friends.pop_back();
				itr = itrEnd;
			}
		}

		page.removeFan(*this);
	}
}


bool User::checkIfFriend(const string name) const
{
	auto itr = friends.begin();
	auto itrEnd = friends.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->name == name)
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