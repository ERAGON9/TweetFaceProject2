
#include "TwittFace.h"
#include "Users.h"
#include "FansPage.h"
#include <string>

using namespace std;

TwittFace::~TwittFace()
{
	auto itr = allTheUsers.begin();
	auto itrEnd = allTheUsers.end();
	auto itr2 = allTheFanPages.begin();
	auto itrEnd2 = allTheFanPages.end();

	for (; itr != itrEnd; ++itr)
	{
		delete (*itr);
	}

	for (; itr2 != itrEnd2; ++itr2)
	{
		delete (*itr2);
	}

}


User& TwittFace::getUserbyName(string userName)  throw (const char*)
{
	auto itr = allTheUsers.begin();
	auto itrEnd = allTheUsers.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == userName)
			return *(*itr);
	}

	throw "\nThe name of the user does not exist at the system";
}


FansPage& TwittFace::getFanPagebyName(string fanPageName) throw (const char*)
{
	auto itr = allTheFanPages.begin();
	auto itrEnd = allTheFanPages.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == fanPageName)
			return *(*itr);
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
	auto itr = allTheUsers.begin();
	auto itrEnd = allTheUsers.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == userName)
			return true;
	}

	return false;
}


bool TwittFace::checkIfFanPageExist(std::string fanPageName)
{
	auto itr = allTheFanPages.begin();
	auto itrEnd = allTheFanPages.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == fanPageName)
			return true;
	}

	return false;
}