#ifndef __TWITTFACE_H
#define __TWITTFACE_H

class User;
class FansPage;

class TwittFace
{
private:
	User** allTheUsers;
	int usersLogic;
	int userPhysic;

	FansPage** allTheFanPages;
	int fanPagesLogic;
	int fansPagesPhysic;

public:
	TwittFace();
	TwittFace(TwittFace& twitFace) = delete;
	~TwittFace();

	int getNumOfUsers() const { return usersLogic; }
	int getNumOfFanPages() const { return fanPagesLogic; }
	User** getAllTheUsers() { return allTheUsers; }
	FansPage** getAllTheFanPages() { return allTheFanPages; }

	void addUserToSystem(User& newUser);
	void addFanPageToSystem(FansPage& newFanPage);
	User* getPUserbyName(const char* userName);
	FansPage* getPFanPagebyName(const char* fanPageName);
};

#endif // !___TWITTFACE_H