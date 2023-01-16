#ifndef __FANSPAGE_H
#define __FANSPAGE_H

#include <string>
#include <vector>
#include <iostream>

class Status;
class User;

class FansPage
{
private:
	std::string name;

	std::vector<Status*> publishBoard;
	std::vector<User*> Fans;

public:
	FansPage(std::string name);
	FansPage(const FansPage& other) = delete;
	~FansPage();

	FansPage& operator+=(User& newFan);
	bool operator>(const FansPage& fanPage) const;
	bool operator<(const FansPage& fanPage) const;
	bool operator>(const User& user) const;
	bool operator<(const User& user) const;

	friend std::ostream& operator<<(std::ostream& os, const FansPage& fanPage)
	{
		os << fanPage.name;
		return os;
	}

	std::string getName() const { return name; }
	int getNumOfFans() const { return Fans.size(); }
	int getNumOfStatuses() const { return publishBoard.size(); }
	const Status& getStatus(int i) const { return *(publishBoard[i]); }

	void addTextStatus(std::string text);
	void addImageStatus(const std::string text, const std::string image);
	void addVideoStatus(const std::string text, const std::string video);

	bool checkIfFan(const User& fan) const;
	void removeFan(User& fan);

	void printAllStatuses() const;
	void printAllFans() const;
	void printFanPage() const;
};

#endif // !__FANSPAGE_H