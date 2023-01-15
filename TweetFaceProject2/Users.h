#ifndef __USERS_H
#define __USERS_H

#include <vector>
#include <string>
#include "Date.h"
#include<iostream>

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

	friend std::ostream& operator<<(std::ostream& os, const User& user)
	{
		os << user.name << std::endl << user.bDay;
		return os;
	}

	std::string getName() const { return name; }
	int getNumOfFriends() const { return friends.size(); }
	int getNumOfStatuses() const { return publishBoard.size(); }
	User& getFriend(int i) const { return *(friends[i]); }
	Status& getStatus(int i) { return *(publishBoard[i]); }

	void addTextStatus(const std::string text);
	void addImageStatus(const std::string text, const std::string image);
	void addVideoStatus(const std::string text, const std::string video);

	void removeFriend(User& _friend);
	void removeFansPage(FansPage& page);
	bool checkIfFriends(const std::string name) const;
	bool checkIfFanOfFanPage(const FansPage& fanPage) const;

	void printAllFriends() const;
	void printAllStatuses() const;
	void printTenLastStatusOfTheUser() const;
	void printAllFanPages() const;
	void printUser() const;
};

#endif // !__USERS_H