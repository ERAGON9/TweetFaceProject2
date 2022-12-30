#ifndef __USERS_H
#define __USERS_H

#include <vector>
#include <string>
#include "Date.h"

class FansPage;
class Status;

class User
{
private:
	std::string name;
	Date bDay;

	std::vector<Status*> publishBoard;
	std::vector<User*> friends;
	std::vector<FansPage*> fansPages;

public:
	User(const std::string _name, int day, int month, int year);
	User(const User& other) = delete;
	~User();

	const User& operator+=(User& _friend);
	const User& operator+=(FansPage& fanPage);
	bool operator>(const User& _friend) const;
	bool operator<(const User& _friend) const;
	bool operator>(const FansPage& fanPage) const;
	bool operator<(const FansPage& fanPage) const;

	std::string getName() const { return name; }
	int getNumOfFriends() const { return friends.size(); }
	int getNumOfStatuses() const { return publishBoard.size(); }
	User& getFriend(const int i) { return *(friends[i]); }

	void printTenLastStatusOfTheUser() const;
	void addStatus(const std::string text);
	void removeFriend(User& _friend);
	void printAllFriends() const;
	void printAllStatuses() const;
	void removeFansPage(FansPage& page);
	bool checkIfFriends(const std::string name) const;
	bool checkIfFanOfFanPage(const FansPage& fanPage) const;
	void printAllFanPages() const;
	void printUser() const;
};

#endif // !__USERS_H