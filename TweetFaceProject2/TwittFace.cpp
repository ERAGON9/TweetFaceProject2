
#include "TwittFace.h"
#include "Users.h"
#include "FansPage.h"
#include <string>

using namespace std;

TwittFace::TwittFace()
{}

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


void TwittFace::addUserToSystem(string userName, int day, int month, int year) throw (const char*)
{
	if (this->getPUserbyName(userName) != nullptr)
		throw "\nThe name already taken";

	User* newUserTwittFace = new User(userName, day, month, year);

	allTheUsers.push_back(newUserTwittFace);
}


void TwittFace::addFanPageToSystem(string fanPageName) throw (const char*)
{
	if (this->getPFanPagebyName(fanPageName) != nullptr)
		throw "\nThe name already taken";

	FansPage* newFanPageTwittFace = new FansPage(fanPageName);

	allTheFanPages.push_back(newFanPageTwittFace);
}


User* TwittFace::getPUserbyName(string userName)
{
	for (int i = 0; i < allTheUsers.size(); i++)
	{
		if (allTheUsers[i]->getName() == userName)
			return allTheUsers[i];
	}
	return nullptr;   // If the name don't belong to an User at the system, the function return NULL;
}


FansPage* TwittFace::getPFanPagebyName(string fanPageName)
{
	for (int i = 0; i < allTheFanPages.size(); i++)
	{
		if (allTheFanPages[i]->getName() == fanPageName)
			return allTheFanPages[i];
	}

	return nullptr; // If the name don't belong to a Fan Page at the system, the function return NULL;
}