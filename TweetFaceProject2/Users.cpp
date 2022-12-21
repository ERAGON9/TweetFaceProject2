
#include <iostream>
#include <string.h>
#include "Users.h"
#include "Status.h"
#include "FansPage.h"

using namespace std;
#pragma warning(disable: 4996)

User::User(const string _name, int day, int month, int year) : bDay(day, month, year)
{
	this->name = name;
}


User::~User()
{
	for (int i = 0; i < publishBoard.size(); i++)
	{
		delete publishBoard[i];
	}
}


void User::printTenLastStatusOfTheUser() const
{
	for (int i = publishBoard.size() - 1; (i > (publishBoard.size() - 1) - 10) && (i >= 0); i--)
		publishBoard[i]->printStatus();
}


void User::addStatus(const string text)
{
	Status* tweet = new Status(text);
	publishBoard.push_back(tweet);
}


void User::addFriend(User& _friend)
{
	if (checkIfFriend(_friend.getName()) == false)
	{
		friends.push_back(&_friend);

		_friend.addFriend(*this);
	}
}


void User::removeFriend(User& _friend)
{
	if (checkIfFriend(_friend.getName()) == true)
	{
		for (int i = 0; i < friends.size(); i++)
		{
			if (friends[i] == &_friend)
			{
				if (i != friends.size() - 1)
					friends[i] = friends[friends.size() - 1];
				friends.pop_back();
				i = friends.size();
			}
		}
		_friend.removeFriend(*this);
	}
}


void User::printAllFriends() const
{
	for (int i = 0; i < friends.size(); i++)
		friends[i]->printUser();
}


void User::printAllStatuses() const
{
	for (int i = 0; i < publishBoard.size(); i++)
		publishBoard[i]->printStatus();
}


void User::addFansPage(FansPage& fanPage)
{
	if (checkIfFanOfFanPage(fanPage) == false)
	{
		fansPages.push_back(&fanPage);

		fanPage.addFan(*this);
	}
}


void User::removeFansPage(FansPage& page)
{
	if (checkIfFanOfFanPage(page) == true)
	{
		for (int i = 0; i < fansPages.size(); i++)
		{
			if (fansPages[i] == &page)
			{
				if (i != fansPages.size() - 1)
					fansPages[i] = fansPages[fansPages.size() - 1];
				fansPages.pop_back();
				i = fansPages.size();
			}
		}
		page.removeFan(*this);
	}
}


bool User::checkIfFriend(const string name) const
{
	for (int i = 0; i < friends.size(); i++)
	{
		if (friends[i]->name == name)
			return true;
	}

	return false;
}


bool User::checkIfFanOfFanPage(const FansPage& fanPage) const
{
	for (int i = 0; i < fansPages.size(); i++)
	{
		if (fansPages[i]->getName() == fanPage.getName())
			return true;
	}

	return false;
}


void User::printAllFanPages() const
{
	for (int i = 0; i < fansPages.size(); i++)
		fansPages[i]->printFanPage();
}


void User::printUser() const
{
	cout << "\nUser Name is: " << name << endl
		<< "Birth day is: " << (bDay.getDay() < 10 ? "0" : "") << bDay.getDay() << " / "
		<< (bDay.getmonth() < 10 ? "0" : "") << bDay.getmonth() << " / " << bDay.getYear() << endl;
}