
#include "TwittFace.h"
#include "Users.h"
#include "FansPage.h"
#include <string.h>

#pragma warning(disable: 4996)

TwittFace::TwittFace()
{
	fanPagesLogic = 0;
	fansPagesPhysic = 1;
	allTheFanPages = new FansPage * [fansPagesPhysic];
}

TwittFace::~TwittFace()
{
	//delete[]allTheUsers;
	delete[]allTheFanPages;

}


void TwittFace::addUserToSystem(const char* userName, int day, int month, int year)
{
	//if (allTheUsers.size() == allTheUsers.capacity())
	//	allTheUsers.reserve((allTheUsers.capacity() + 1) * 2);

	User* newUserTwittFace = new User(userName, day ,month, year);

	allTheUsers.push_back(newUserTwittFace);
}


void TwittFace::addFanPageToSystem(const char* fanPageName)
{
	if (fanPagesLogic == fansPagesPhysic)
	{
		fansPagesPhysic *= 2;
		FansPage** tmp = new FansPage * [fansPagesPhysic];

		for (int i = 0; i < fanPagesLogic; i++)
			tmp[i] = allTheFanPages[i];

		delete[] allTheFanPages;
		allTheFanPages = tmp;
	}

	FansPage* newFanPageTwittFace = new FansPage(fanPageName);

	allTheFanPages[fanPagesLogic] = newFanPageTwittFace;
	fanPagesLogic++;
}


User* TwittFace::getPUserbyName(const char* userName)
{
	for (int i = 0; i < allTheUsers.size(); i++)
	{
		if (strcmp(allTheUsers[i]->getName(), userName) == 0)
			return allTheUsers[i];
	}
	return nullptr;
}


FansPage* TwittFace::getPFanPagebyName(const char* fanPageName)
{
	for (int i = 0; i < fanPagesLogic; i++)
	{
		if (strcmp(allTheFanPages[i]->getName(), fanPageName) == 0)
			return allTheFanPages[i];
	}

	return nullptr;
}