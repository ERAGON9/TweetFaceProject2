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

	void addUserToSystem(const char* userName, int day, int month, int year);
	void addFanPageToSystem(const char* fanPageName);
	User* getPUserbyName(const char* userName);
	FansPage* getPFanPagebyName(const char* fanPageName);
};

#endif // !___TWITTFACE_H