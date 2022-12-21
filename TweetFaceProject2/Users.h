#ifndef __Users_H
#define __Users_H
#include <string>
#include "Date.h"
class FansPage;
class Status;

class User
{
private:
	std::string name;
	Date bDay;

	Status** publishBoard;
	int statusCount;
	int statusPhysic;

	User** friends;
	int friendsPhysic;
	int friendsCount;

	FansPage** pArrFansPages;
	int pagesPhysic;
	int pagesCount;

public:
	User(const char* _name, int day, int month, int year);
	User(const User& other) = delete;
	~User();

	std::string getName() const { return name; }
	const int getNumOfFriends() const { return friendsCount; }
	User** getFriends() { return friends; }

	void printTenLastStatusOfTheUser() const;
	void addStatus(const char* text);
	void addFriend(User& _friend);
	void removeFriend(User& _friend);
	void printAllFriends() const;
	void printAllStatuses() const;
	void addFansPage(FansPage& page);
	void removeFansPage(FansPage& page);
	bool checkIfFriend(const char* name) const;
	bool checkIfFanOfFanPage(const FansPage& fanPage) const;
	void printAllFanPages() const;
	void printUser() const;
};

#endif // !__Users_H