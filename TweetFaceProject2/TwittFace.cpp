
#include "TwittFace.h"
#include "Users.h"
#include "FansPage.h"
#include <string.h>

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


void TwittFace::addUserToSystem(const char* userName, int day, int month, int year)
{
	User* newUserTwittFace = new User(userName, day ,month, year);

	allTheUsers.push_back(newUserTwittFace);
}


void TwittFace::addFanPageToSystem(const char* fanPageName)
{
	FansPage* newFanPageTwittFace = new FansPage(fanPageName);

	allTheFanPages.push_back(newFanPageTwittFace);
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
	for (int i = 0; i < allTheFanPages.size(); i++)
	{
		if (strcmp(allTheFanPages[i]->getName(), fanPageName) == 0)
			return allTheFanPages[i];
	}

	return nullptr;
}