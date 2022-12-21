
#include "TwittFace.h"
#include "Users.h"
#include "FansPage.h"
#include <string>

#pragma warning(disable: 4996)

TwittFace::TwittFace()
{
}

TwittFace::~TwittFace()
{
	int i;

	for (i = 0; i < allTheUsers.size(); i++)
	{
		delete allTheUsers[i];
	}

	for (i = 0; i < allTheFanPages.size(); i++)
	{
		delete allTheFanPages[i];
	}
}


void TwittFace::addUserToSystem(std::string userName, int day, int month, int year)
{
	User* newUserTwittFace = new User(userName, day ,month, year);

	allTheUsers.push_back(newUserTwittFace);
}


void TwittFace::addFanPageToSystem(std::string fanPageName)
{
	FansPage* newFanPageTwittFace = new FansPage(fanPageName);

	allTheFanPages.push_back(newFanPageTwittFace);
}


User* TwittFace::getPUserbyName(std::string userName)
{
	for (int i = 0; i < allTheUsers.size(); i++)
	{
		if (allTheUsers[i]->getName() == userName)
			return allTheUsers[i];
	}
	return nullptr;   // If the name not belong to user at the system, the function return NULL;
}


FansPage* TwittFace::getPFanPagebyName(std::string fanPageName)
{
	for (int i = 0; i < allTheFanPages.size(); i++)
	{
		if (allTheFanPages[i]->getName() == fanPageName)
			return allTheFanPages[i];
	}

	return nullptr;
}