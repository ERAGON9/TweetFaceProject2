
#include <iostream>
#include <string>
#include "Users.h"
#include "Status.h"
#include "FansPage.h"
#include "Exceptions.h"

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


User& User::operator+=(User& _friend)
{
	if (checkIfFriends(_friend.getName()) == false)
	{
		friends.push_back(&_friend);

		_friend += *this;
	}

	return *this;
}


User& User::operator+=(FansPage& fanPage)
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


void User::addTextStatus(const string text)
{
	Status* tweet = new Status(text);
	publishBoard.push_back(tweet);
}

void User::addPreviousTextStatus(const string text, int day, int month, int year, int hour, int minute)
{
	Status* tweet = new Status(text, day, month, year, hour, minute);
	publishBoard.push_back(tweet);
}


void User::addImageStatus(const string text, const string image)
{
	Status* tweet = new ImageStatus(text, image);
	publishBoard.push_back(tweet);
}

void User::addPreviusImageStatus(const string text, const std::string image, int day, int month, 
	int year, int hour, int minute)
{
	Status* tweet = new ImageStatus(text, image, day, month, year, hour, minute);
	publishBoard.push_back(tweet);
}


void User::addVideoStatus(const string text, const string video)
{
	Status* tweet = new VideoStatus(text, video);
	publishBoard.push_back(tweet);
}

void User::addPreviousVideoStatus(const string text, const std::string video, int day, int month,
	int year, int hour, int minute)
{
	Status* tweet = new VideoStatus(text, video, day, month, year, hour, minute);
	publishBoard.push_back(tweet);
}


void User::removeFriend(User& _friend)
{
	bool Found = false;
	vector<User*>::iterator itr = friends.begin();
	vector<User*>::iterator itrEnd = friends.end();

	if (checkIfFriends(_friend.getName()) == true)
	{
		while (Found == false)
		{
			if (*itr == &_friend)
			{
				if (itr != (itrEnd - 1))
					swap(*itr, *(itrEnd - 1));
				friends.pop_back();
				Found = true;
			}
			else
				++itr;
		}
		_friend.removeFriend(*this);
	}
}


void User::removeFansPage(FansPage& page)
{
	bool Found = false;
	vector<FansPage*>::iterator itr = fansPages.begin();
	vector<FansPage*>::iterator itrEnd = fansPages.end();

	if (checkIfFanOfFanPage(page) == true)
	{
		while (Found == false)
		{
			if (*itr == &page)
			{
				if (itr != (itrEnd - 1))
					swap(*itr, *(itrEnd - 1));
				friends.pop_back();
				Found = true;
			}
			else
				++itr;
		}

		page.removeFan(*this);
	}
}


bool User::checkIfFriends(const string name) const
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
	auto itr = fansPages.begin();
	auto itrEnd = fansPages.end();
	string pageName = fanPage.getName();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == pageName)
			return true;
	}

	return false;
}


void User::printAllFriends() const
{
	if (friends.size() == 0)
		throw NoFriendsException();

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

void User::printAllFanPages() const
{
	auto itr = fansPages.begin();
	auto itrEnd = fansPages.end();

	for (; itr != itrEnd; ++itr)
	{
		(*itr)->printFanPage();
	}
}


void User::printUser() const
{
	cout << "\nUser Name is: " << name << endl
		<< "Birth day is: " << (bDay.getDay() < 10 ? "0" : "") << bDay.getDay() << " / "
		<< (bDay.getmonth() < 10 ? "0" : "") << bDay.getmonth() << " / " << bDay.getYear() << endl;
}