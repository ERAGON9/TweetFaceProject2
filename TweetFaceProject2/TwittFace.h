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
	User& getTheUser(const int i) { return *(allTheUsers[i]); }
	FansPage& getAllTheFanPages(const int i) { return *(allTheFanPages[i]); }

	void addUserToSystem(std::string userName, int day, int month, int year);
	void addFanPageToSystem(std::string fanPageName) throw (const char*);
	User* getPUserbyName(std::string userName);
	FansPage* getPFanPagebyName(std::string fanPageName);
};

#endif // !___TWITTFACE_H