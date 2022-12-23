
#include "FansPage.h"
#include <string>
#include "Status.h"
#include "Users.h"
#include <iostream>

using namespace std;

FansPage::FansPage(std::string name)
{
	this->name = name;
}


FansPage::~FansPage()
{
	for (int i = 0; i < publishBoard.size(); i++)
	{
		delete publishBoard[i];
	}
}


const FansPage& FansPage::operator+=(User& newFan)
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


void FansPage::addStatus(std::string text)
{
	Status* tweet = new Status(text);
	publishBoard.push_back(tweet);
}


void FansPage::printAllStatuses() const
{
	int size = publishBoard.size();

	for (int i = 0; i < size; i++)
	{
		publishBoard[i]->printStatus();
	}
}


bool FansPage::checkIfFan(const User& fan) const
{
	int size = Fans.size();

	for (int i = 0; i < size; i++)
	{
		if (Fans[i]->getName() == fan.getName())
			return true;
	}

	return false;
}


void FansPage::removeFan(User& fan)
{
	int size = Fans.size();

	if (checkIfFan(fan) == true)
	{
		for (int i = 0; i < size; i++)
		{
			if (Fans[i] == &fan)
			{
				if (i != size - 1)
					swap(Fans[i], Fans[size - 1]);
				Fans.pop_back();
				i = size;
			}
		}
		fan.removeFansPage(*this);
	}
}


void FansPage::printAllFans() const
{
	int size = Fans.size();

	for (int i = 0; i < size; i++)
	{
		Fans[i]->printUser();
	}
}

void FansPage::printFanPage() const
{
	cout << "\nThe fan page name is: " << name << endl;
}
