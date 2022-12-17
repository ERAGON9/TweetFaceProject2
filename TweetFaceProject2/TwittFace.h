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
	bool isUserExist(const char* userName) const;
	User& getUserbyName(const char* userName);
	bool isFanPageExist(const char* fanPageName) const;
	FansPage& getFanPagebyName(const char* fanPageName);
};

#endif // !___TWITTFACE_H