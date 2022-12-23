#ifndef __FANSPAGE_H
#define __FANSPAGE_H

#include <string>
#include <vector>

class Status;
class User;

class FansPage
{
private:
	std::string name;

	std::vector<User*> Fans;
	std::vector<Status*> publishBoard;

public:
	FansPage(std::string name);
	FansPage(const FansPage& other) = delete;
	~FansPage();

	const FansPage& operator+=(User& newFan);
	bool operator>(const FansPage& fanPage) const;
	bool operator<(const FansPage& fanPage) const;
	bool operator>(const User& user) const;
	bool operator<(const User& user) const;

	std::string getName() const { return name; }
	int getNumOfFans() const { return Fans.size(); }

	void addStatus(std::string text);
	void printAllStatuses() const;
	bool checkIfFan(const User& fan) const;
	void removeFan(User& fan);
	void printAllFans() const;
	void printFanPage() const;
};

#endif // !__FANSPAGE_H