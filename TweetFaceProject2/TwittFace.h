#ifndef __TWITTFACE_H
#define __TWITTFACE_H

using namespace std;
#include <vector>
#include "Users.h"
#include "FansPage.h"

class User;
class FansPage;

class TwittFace
{
private:
	vector<User*> allTheUsers;

	FansPage** allTheFanPages;
	//vector<FansPage> allTheFanPages;
	int fanPagesLogic;
	int fansPagesPhysic;

public:
	TwittFace();
	TwittFace(TwittFace& twitFace) = delete;
	~TwittFace();

	int getNumOfUsers() const { return allTheUsers.size(); }
	int getNumOfFanPages() const { return fanPagesLogic; }
	User& getTheUser(const int i) { return *(allTheUsers[i]); }
	FansPage& getAllTheFanPages(const int i) { return *(allTheFanPages[i]); }

	void addUserToSystem(const char* userName, int day, int month, int year);
	void addFanPageToSystem(const char* fanPageName);
	User* getPUserbyName(const char* userName);
	FansPage* getPFanPagebyName(const char* fanPageName);
};

#endif // !___TWITTFACE_H