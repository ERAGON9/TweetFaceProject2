
#include "FansPage.h"
#include <string>
#include "Status.h"
#include "Users.h"
#include <iostream>
#include "Exceptions.h"

using namespace std;

FansPage::FansPage(std::string name)
{
	this->name = name;
}


FansPage::~FansPage()
{
	auto itr = publishBoard.begin();
	auto itrEnd = publishBoard.end();

	for (; itr != itrEnd; ++itr)
	{
		delete *itr;
	}
}


FansPage& FansPage::operator+=(User& newFan)
{
	if (checkIfFan(newFan) == false)
	{
		Fans.push_back(&newFan);

		newFan += *this;
	}

	return *this;
}


bool FansPage::operator>(const FansPage& fanPage) const
{
	if (Fans.size() > fanPage.Fans.size())
		return true;
	else
		return false;
}


bool FansPage::operator<(const FansPage& fanPage) const
{
	return fanPage > *this;
}


bool FansPage::operator>(const User& user) const
{
	if (Fans.size() > user.getNumOfFriends())
		return true;
	else
		return false;
}
bool FansPage::operator<(const User& user) const
{
	return user > *this;
}


void FansPage::addTextStatus(std::string text)
{
	Status* tweet = new Status(text);
	publishBoard.push_back(tweet);
}


void FansPage::addImageStatus(const string text, const string image)
{
	Status* tweet = new ImageStatus(text, image);
	publishBoard.push_back(tweet);
}


void FansPage::addVideoStatus(const string text, const string video)
{
	Status* tweet = new VideoStatus(text, video);
	publishBoard.push_back(tweet);
}


bool FansPage::checkIfFan(const User& fan) const
{
	auto itr = Fans.begin();
	auto itrEnd = Fans.end();
	string fanName = fan.getName();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == fanName)
			return true;
	}

	return false;
}


void FansPage::removeFan(User& fan)
{
	bool Found = false;
	auto itr = Fans.begin();
	auto itrEnd = Fans.end();

	if (checkIfFan(fan) == true)
	{
		while (Found == false)
		{
			if ((*itr) == &fan)
			{
				if (itr != (itrEnd - 1))
					swap(*itr, *(itrEnd - 1));
				Fans.pop_back();
				Found = true;
			}
			else
				++itr;
		}
		fan.removeFansPage(*this);
	}
}


void FansPage::printAllStatuses() const
{
	auto itr = publishBoard.begin();
	auto itrEnd = publishBoard.end();

	for (; itr != itrEnd; ++itr)
	{
		(*itr)->printStatus();
	}
}


void FansPage::printAllFans() const
{
	if (Fans.size() == 0)
		throw NoFansException();

	auto itr = Fans.begin();
	auto itrEnd = Fans.end();

	for (; itr != itrEnd; ++itr)
	{
		(*itr)->printUser();
	}
}

void FansPage::printFanPage() const
{
	cout << "\nThe fan page name is: " << name << endl;
}
