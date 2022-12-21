#ifndef __Users_H
#define __Users_H

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

	std::string getName() const { return name; }
	const int getNumOfFriends() const { return friends.size(); }
	User& getFriend(const int i) { return *(friends[i]); }

	void printTenLastStatusOfTheUser() const;
	void addStatus(const std::string text);
	void addFriend(User& _friend);
	void removeFriend(User& _friend);
	void printAllFriends() const;
	void printAllStatuses() const;
	void addFansPage(FansPage& page);
	void removeFansPage(FansPage& page);
	bool checkIfFriend(const string name) const;
	bool checkIfFanOfFanPage(const FansPage& fanPage) const;
	void printAllFanPages() const;
	void printUser() const;
};

#endif // !__Users_H