
#include <iostream>
#include <string.h>
#include "Users.h"
#include "Status.h"
#include "FansPage.h"

using namespace std;
#pragma warning(disable: 4996)

User::User(const char* _name, const int day, const int month, const int year) : bDay(day, month, year)
{
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	statusCount = 0;
	statusPhysic = 1;
	friendsCount = 0;
	friendsPhysic = 1;
	pagesCount = 0;
	pagesPhysic = 1;
	publishBoard = new Status * [statusPhysic];
	friends = new User * [friendsPhysic];
	pArrFansPages = new FansPage * [pagesPhysic];
}


User::~User()
{
	delete[]name;

	for (int i = 0; i < statusCount; i++)
	{
		delete[]publishBoard[i];
	}

	delete[]publishBoard;
	delete[]friends;
	delete[]pArrFansPages;
}


void User::printTenLastStatusOfTheUser() const
{
	for (int i = statusCount - 1; (i > (statusCount - 1) - 10) && (i >= 0); i--)
		publishBoard[i]->printStatus();
}


void User::addStatus(Status& tweet)
{
	if (statusCount == statusPhysic)
	{
		statusPhysic *= 2;
		Status** tmp = new Status * [statusPhysic];

		for (int i = 0; i < statusCount; i++)
			tmp[i] = publishBoard[i];

		delete[]publishBoard;
		publishBoard = tmp;
	}

	publishBoard[statusCount] = &tweet;
	statusCount++;
}


void User::addFriend(User& _friend)
{
	if (checkIfFriend(_friend.getName()) == false)
	{
		if (friendsCount == friendsPhysic)
		{
			friendsPhysic *= 2;
			User** tmp = new User * [friendsPhysic];

			for (int i = 0; i < friendsCount; i++)
				tmp[i] = friends[i];

			delete[]friends;
			friends = tmp;
		}
		friends[friendsCount] = &_friend;
		friendsCount++;

		_friend.addFriend(*this);
	}
}


void User::removeFriend(User& _friend)
{
	if (checkIfFriend(_friend.getName()) == true)
	{
		for (int i = 0; i < friendsCount; i++)
		{
			if (friends[i] == &_friend)
			{
				if (i != friendsCount - 1)
					friends[i] = friends[friendsCount - 1];
				friends[friendsCount - 1] = nullptr;
				i = friendsCount;
				friendsCount--;
			}
		}
		_friend.removeFriend(*this);
	}
}


void User::printAllFriends() const
{
	for (int i = 0; i < friendsCount; i++)
		friends[i]->printUser();
}


void User::printAllStatuses() const
{
	for (int i = 0; i < statusCount; i++)
		publishBoard[i]->printStatus();
}


void User::addFansPage(FansPage& fanPage)
{
	if (checkIfFanOfFanPage(fanPage) == false)
	{
		if (pagesCount == pagesPhysic)
		{
			pagesPhysic *= 2;
			FansPage** tmp = new FansPage * [pagesPhysic];

			for (int i = 0; i < pagesCount; i++)
				tmp[i] = pArrFansPages[i];

			delete[]pArrFansPages;
			pArrFansPages = tmp;
		}

		pArrFansPages[pagesCount] = &fanPage;
		pagesCount++;

		fanPage.addFan(*this);
	}
}


void User::removeFansPage(FansPage& page)
{
	if (checkIfFanOfFanPage(page) == true)
	{
		for (int i = 0; i < pagesCount; i++)
		{
			if (pArrFansPages[i] == &page)
			{
				if (i != pagesCount - 1)
					pArrFansPages[i] = pArrFansPages[pagesCount - 1];
				pArrFansPages[pagesCount - 1] = nullptr;
				i = pagesCount;
				pagesCount--;
			}
		}
		page.removeFan(*this);
	}
}


bool User::checkIfFriend(const char* name) const
{
	for (int i = 0; i < friendsCount; i++)
	{
		if (strcmp(friends[i]->getName(), name) == 0)
			return true;
	}

	return false;
}


bool User::checkIfFanOfFanPage(const FansPage& fanPage) const
{
	for (int i = 0; i < pagesCount; i++)
	{
		if (pArrFansPages[i]->getName() == fanPage.getName())
			return true;
	}

	return false;
}


void User::printAllFanPages() const
{
	for (int i = 0; i < pagesCount; i++)
		pArrFansPages[i]->printFanPage();
}


void User::printUser() const
{
	cout << "\nUser Name is: " << name << endl
		<< "Birth day is: " << (bDay.getDay() < 10 ? "0" : "") << bDay.getDay() << " / "
		<< (bDay.getmonth() < 10 ? "0" : "") << bDay.getmonth() << " / " << bDay.getYear() << endl;
}