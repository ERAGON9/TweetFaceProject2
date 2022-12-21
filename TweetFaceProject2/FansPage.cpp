
#include "FansPage.h"
#include <string>
#include "Status.h"
#include "Users.h"
#include <iostream>

using namespace std;
#pragma warning(disable: 4996)

FansPage::FansPage(std::string name)
{
	this->name = name;
	statusCount = 0;
	statusPhysic = 1;
	publishBoard = new Status * [statusPhysic];
}

void FansPage::addStatus(std::string text)
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
	
	Status* tweet = new Status(text);

	publishBoard[statusCount] = tweet;
	statusCount++;
}


void FansPage::printAllStatuses() const
{
	for (int i = 0; i < statusCount; i++)
		publishBoard[i]->printStatus();
}


void FansPage::addFan(User& newFan)
{
	if (checkIfFan(newFan) == false)
	{
		pArrFans.push_back(&newFan);
		newFan.addFansPage(*this);
	}
}


bool FansPage::checkIfFan(const User& fan) const
{
	int size = pArrFans.size();

	for (int i = 0; i < size; i++)
	{
		if (pArrFans[i]->getName() == fan.getName())
			return true;
	}

	return false;
}


void FansPage::removeFan(User& fan)
{
	int size = pArrFans.size();

	if (checkIfFan(fan) == true)
	{
		for (int i = 0; i < size; i++)
		{
			if (pArrFans[i] == &fan)
			{
				if (i != size - 1)
					swap(pArrFans[i], pArrFans[size - 1]);
				pArrFans[size - 1] = nullptr;
				i = size;
			}
		}
		fan.removeFansPage(*this);
	}
}


void FansPage::printAllFans() const
{
	int size = pArrFans.size();

	for (int i = 0; i < size; i++)
		pArrFans[i]->printUser();
}

void FansPage::printFanPage() const
{
	cout << "\nThe fan page name is: " << name << endl;
}
