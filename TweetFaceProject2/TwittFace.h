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
	TwittFace() = default;
	TwittFace(TwittFace& twitFace) = delete;
	const TwittFace& operator=(const TwittFace& other) = delete;
	~TwittFace();

	int getNumOfUsers() const { return allTheUsers.size(); }
	int getNumOfFanPages() const { return allTheFanPages.size(); }
	User& getUser(int i) { return *(allTheUsers[i]); }
	const User& getUser(int i) const { return *(allTheUsers[i]); }
	FansPage& getFanPage(int i) { return *(allTheFanPages[i]); }
	const FansPage& getFanPage(int i) const { return *(allTheFanPages[i]); }
	User& getUserbyName(std::string userName) noexcept(false);
	FansPage& getFanPagebyName(std::string fanPageName) noexcept(false);

	void addUserToSystem(std::string userName, int day, int month, int year) noexcept(false);
	void addFanPageToSystem(std::string fanPageName) noexcept(false);

	bool checkIfUserExist(std::string userName);
	bool checkIfFanPageExist(std::string fanPageName);
};

#endif // !___TWITTFACE_H