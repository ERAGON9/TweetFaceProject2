
#include "TwittFace.h"
#include "Users.h"
#include "FansPage.h"
#include "Exceptions.h"
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


User& TwittFace::getUserbyName(string userName)  noexcept(false)
{
	auto itr = allTheUsers.begin();
	auto itrEnd = allTheUsers.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == userName)
			return *(*itr);
	}

	throw NoSuchUserException();
}


FansPage& TwittFace::getFanPagebyName(string fanPageName) noexcept(false)
{
	auto itr = allTheFanPages.begin();
	auto itrEnd = allTheFanPages.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == fanPageName)
			return *(*itr);
	}

	throw NoSuchFanPageException();
}


void TwittFace::addUserToSystem(string userName, int day, int month, int year) noexcept(false)
{
	if (this->checkIfUserExist(userName))
		throw takenNameException();

	if (userName.size() == 0)
		throw EmptyNameException();

	User* newUserTwittFace = new User(userName, day, month, year);

	allTheUsers.push_back(newUserTwittFace);
}


void TwittFace::addFanPageToSystem(string fanPageName) noexcept(false)
{
	if (this->checkIfFanPageExist(fanPageName))
		throw takenNameException();

	if (fanPageName.size() == 0)
		throw takenNameException();

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