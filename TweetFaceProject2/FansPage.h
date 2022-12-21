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

	std::vector<User*> pArrFans;

	Status** publishBoard;
	int statusCount;
	int statusPhysic;

public:
	FansPage(std::string name = " ");
	FansPage(const FansPage& other) = delete;

	std::string getName() const { return name; }

	void addStatus(std::string text);
	void printAllStatuses() const;
	void addFan(User& newFan);
	bool checkIfFan(const User& fan) const;
	void removeFan(User& fan);
	void printAllFans() const;
	void printFanPage() const;
};

#endif // !__FANSPAGE_H