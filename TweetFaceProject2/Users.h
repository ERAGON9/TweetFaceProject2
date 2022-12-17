#ifndef __Users_H
#define __Users_H

#include "Date.h"
class FansPage;
class Status;

class User
{
private:
	char* name;
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
	User(const char* _name, const int day, const int month, const int year);
	User(const User& other) = delete;
	~User();

	const char* getName() const { return name; }
	const int getNumOfFriends() const { return friendsCount; }
	User** getFriends() { return friends; }

	void printTenLastStatusOfTheUser() const;
	void addStatus(Status& status);
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