
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


User& TwittFace::getUserbyName(string userName)  throw (const char*)
{
	for (int i = 0; i < allTheUsers.size(); i++)
	{
		if (allTheUsers[i]->getName() == userName)
			return *(allTheUsers[i]);
	}

	throw "\nThe name of the user does not exist at the system";
}


FansPage& TwittFace::getFanPagebyName(string fanPageName)
{
	for (int i = 0; i < allTheFanPages.size(); i++)
	{
		if (allTheFanPages[i]->getName() == fanPageName)
			return *(allTheFanPages[i]);
	}

	throw "\nThe name of the fan page does not exist at the system";
}


void TwittFace::addUserToSystem(string userName, int day, int month, int year) throw (const char*)
{
	if (this->checkIfUserExist(userName))
		throw "\nThe name already taken";

	User* newUserTwittFace = new User(userName, day, month, year);

	allTheUsers.push_back(newUserTwittFace);
}


void TwittFace::addFanPageToSystem(string fanPageName) throw (const char*)
{
	if (this->checkIfFanPageExist(fanPageName))
		throw "\nThe name already taken";

	FansPage* newFanPageTwittFace = new FansPage(fanPageName);

	allTheFanPages.push_back(newFanPageTwittFace);
}


bool TwittFace::checkIfUserExist(std::string userName)
{
	for (int i = 0; i < allTheUsers.size(); i++)
	{
		if (allTheUsers[i]->getName() == userName)
			return true;
	}

	return false;
}


bool TwittFace::checkIfFanPageExist(std::string fanPageName)
{
	for (int i = 0; i < allTheFanPages.size(); i++)
	{
		if (allTheFanPages[i]->getName() == fanPageName)
			return true;
	}

	return false;
}