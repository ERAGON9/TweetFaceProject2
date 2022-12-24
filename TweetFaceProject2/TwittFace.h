#ifndef __TWITTFACE_H
#define __TWITTFACE_H

#include <vector>
#include "Users.h"
#include "FansPage.h"

class User;
class FansPage;

class TwittFace
{
private:
	std::vector<User*> allTheUsers;
	std::vector<FansPage*> allTheFanPages;

public:
	TwittFace();
	TwittFace(TwittFace& twitFace) = delete;
	~TwittFace();

	int getNumOfUsers() const { return allTheUsers.size(); }
	int getNumOfFanPages() const { return allTheFanPages.size(); }
	User& getUser(const int i) { return *(allTheUsers[i]); }
	FansPage& getFanPage(const int i) { return *(allTheFanPages[i]); }

	User& getUserbyName(std::string userName);
	FansPage& getFanPagebyName(std::string fanPageName);
	void addUserToSystem(std::string userName, int day, int month, int year);
	void addFanPageToSystem(std::string fanPageName) throw (const char*);
	bool checkIfUserExist(std::string userName);
	bool checkIfFanPageExist(std::string fanPageName);
};

#endif // !___TWITTFACE_H