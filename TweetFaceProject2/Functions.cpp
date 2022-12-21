
#include "Functions.h"
#include <iostream>
#include "TwittFace.h"
#include "Users.h"
#include "FansPage.h"
#include <string>
#include "Status.h"
#include "Users.h"

using namespace std;

const char USER = 'U';
const char FANPAGE = 'F';

void printMenu()
{
	cout << "\nPlease press a number for your deserve action:" << endl
		<< " 1 - Add a user." << endl
		<< " 2 - Add fans page." << endl
		<< " 3 - Add Status for a user / fans page." << endl
		<< " 4 - Show all the statuses for a user / fans page." << endl
		<< " 5 - Show 10 most recent statuses of all the friends of a user." << endl
		<< " 6 - Connect friendship between 2 friends." << endl
		<< " 7 - Delete friendship between 2 friends." << endl
		<< " 8 - Add a user to a fan page." << endl
		<< " 9 - Delete a user from a fan page." << endl
		<< "10 - Show all the users and fan pages at the system." << endl
		<< "11 - Show all the friends of a user / fans of a fan page" << endl
		<< "12 - Exit" << endl
		<< "Your choice: ";
}

void action(int value, TwittFace& system)
{
	switch (value)
	{
	case 1:
		addUser(system);
		break;
	case 2:
		addFanPage(system);
		break;
	case 3:
		addStatus(system);
		break;
	case 4:
		printAllStatuses(system);
		break;
	case 5:
		printTenMostRecentFriendsStatuses(system);
		break;
	case 6:
		connectUsers(system);
		break;
	case 7:
		seperateUsers(system);
		break;
	case 8:
		addFanToFanPage(system);
		break;
	case 9:
		removeFanFromFanPage(system);
		break;
	case 10:
		printAllObjects(system);
		break;
	case 11:
		showAllFriendsOrFans(system);
		break;
	default:
		break;
	}
}

// action 1
void addUser(TwittFace& system)
{
	std::string userName;
	int day, month, year;
	cout << "Please enter User name (no more than 30 characters): ";
	cleanBuffer();
	getline(cin, userName);

	if (system.getPUserbyName(userName) == nullptr)
	{
		cout << "\nPlease enter your birth day (day (space/enter)  month (space/enter) year ): ";
		cin >> day >> month >> year;
		system.addUserToSystem(userName, day, month, year);
		cout << "\nUser added successfully" << endl;
	}
	else
		cout << "\nThe name already taken, back to menu." << endl;
}

// sub function
void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

// action 2
void addFanPage(TwittFace& system)
{
	std::string fanPageName;
	cout << "Please enter fan page name (no more than 30 characters): ";
	cleanBuffer();
	getline(cin, fanPageName);

	if (system.getPFanPagebyName(fanPageName) == nullptr)
	{
		system.addFanPageToSystem(fanPageName);
		cout << "\nFan page added successfully" << endl;
	}
	else
		cout << "\nThe name already taken, back to menu." << endl;
}

// action 3
void addStatus(TwittFace& system)
{
	char answer;
	cout << "Please select to who you want to add new status: (U-user / F-fan page / else to go back to menu) ";
	cin >> answer;
	if (answer == USER)
		addStatusToUser(system);
	else if (answer == FANPAGE)
		addStatuesToFanPage(system);
	else
		cout << "\nYou entered wrong input, back to menu." << endl;
}

// sub function of action 3
void addStatusToUser(TwittFace& system)
{
	std::string userName;
	cout << "\nPlease enter the name of the user: ";
	cleanBuffer();
	getline(cin, userName);

	User* curUser = system.getPUserbyName(userName);

	if (curUser != nullptr)
	{
		std::string statusData;
		cout << "\nPlease enter the new status (no more than 500 characters): ";
		getline(cin, statusData);
		curUser->addStatus(statusData);
		cout << "\nUser status added successfully" << endl;
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// sub function of action 3
void addStatuesToFanPage(TwittFace& system)
{
	std::string fanPageName;
	cout << "\nPlease enter the name of the fan page: ";
	cleanBuffer();
	getline(cin, fanPageName);

	FansPage* curFanPage = system.getPFanPagebyName(fanPageName);

	if (curFanPage != nullptr)
	{
		std::string statusData;
		cout << "\nPlease enter the new status (no more than 500 characters): ";
		getline(cin, statusData);
		curFanPage->addStatus(statusData);
		cout << "\nFan page status added successfully" << endl;
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// action 4
void printAllStatuses(TwittFace& system)
{
	char answer;
	cout << "Please select to who you want to show all the statuses: (U-user / F-fan page) ";
	cin >> answer;
	if (answer == USER)
		printAllUserStatuses(system);
	else if (answer == FANPAGE)
		printAllFanPageStatuses(system);
	else
		cout << "\nYou entered wrong input, back to menu." << endl;
}

// sub function of action 4
void printAllUserStatuses(TwittFace& system)
{
	std::string userName;
	cout << "\nPlease enter the name of the user: ";
	cleanBuffer();
	getline(cin, userName);

	User* curUser = system.getPUserbyName(userName);

	if (curUser != nullptr)
	{
		cout << "\nAll the user statuses are:" << endl;
		curUser->printAllStatuses();
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// sub function of action 4
void printAllFanPageStatuses(TwittFace& system)
{
	std::string fanPageName;
	cout << "\nPlease enter the name of the fan page: ";
	cleanBuffer();
	getline(cin, fanPageName);

	FansPage* curFanPage = system.getPFanPagebyName(fanPageName);

	if (curFanPage != nullptr)
	{
		cout << "\nAll the fan page statuses are:" << endl;
		curFanPage->printAllStatuses();
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// action 5
void printTenMostRecentFriendsStatuses(TwittFace& system)
{
	std::string userName;
	cout << "Please enter the name of the user: ";
	cleanBuffer();
	getline(cin, userName);

	User* curUser = system.getPUserbyName(userName);

	if (curUser != nullptr)
	{
		for (int i = 0; i < curUser->getNumOfFriends(); i++)
		{
			cout << "\nThe most recent statuses of " << curUser->getFriends()[i]->getName() << " are:" << endl;
			curUser->getFriends()[i]->printTenLastStatusOfTheUser();
		}
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// action 6
void connectUsers(TwittFace& system)
{
	std::string name1, name2;

	cout << "Please enter the name of the first user: ";
	cleanBuffer();
	getline(cin, name1);

	User* curUser1 = system.getPUserbyName(name1);

	if (curUser1 != nullptr)
	{
		cout << "\nPlease enter the name of the second user: ";
		getline(cin, name2);

		User* curUser2 = system.getPUserbyName(name2);

		if (curUser2 != nullptr)
		{
			if (curUser1->checkIfFriend(name2) == false)
			{
				curUser1->addFriend(*curUser2);
				cout << "\nThe connection added successfully" << endl;
			}
			else
				cout << "\nYou entered two users that already friends" << endl;
		}
		else
			cout << "\nThe name does not exist at the system, back to menu." << endl;
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// action 7
void seperateUsers(TwittFace& system)
{
	std::string name1, name2;

	cout << "Please enter the name of the first user: ";
	cleanBuffer();
	getline(cin, name1);

	User* curUser1 = system.getPUserbyName(name1);

	if (curUser1 != nullptr)
	{
		cout << "\nPlease enter the name of the second user: ";
		getline(cin, name2);

		User* curUser2 = system.getPUserbyName(name2);

		if (curUser2 != nullptr)
		{
			if (curUser1->checkIfFriend(name2) == true)
			{
				curUser1->removeFriend(*curUser2);
				cout << "\nThe seperate happened, the two users no more friends" << endl;
			}
			else
				cout << "\nYou entered two users that not friends" << endl;
		}
		else
			cout << "\nThe name does not exist at the system, back to menu." << endl;
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// action 8
void addFanToFanPage(TwittFace& system)
{
	std::string fanPageName, newfanName;
	cout << "Please enter the name of the fan page: ";
	cleanBuffer();
	getline(cin, fanPageName);

	FansPage* curFanPage = system.getPFanPagebyName(fanPageName);

	if (curFanPage != nullptr)
	{
		cout << "\nPlease enter the name of the new fan (user name): ";
		getline(cin, newfanName);

		User* newFan = system.getPUserbyName(newfanName);

		if (newFan != nullptr)
		{
			if (curFanPage->checkIfFan(*newFan) == false)
			{
				curFanPage->addFan(*newFan);
				cout << "\nThe user is a fan of the fan page now" << endl;
			}
			else
				cout << "\nThe user already a fan of this fan page, back to menu." << endl;
		}
		else
			cout << "\nThe name does not exist at the system, back to menu." << endl;
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// action 9
void removeFanFromFanPage(TwittFace& system)
{
	std::string fanPageName, oldfanName;
	cout << "Please enter the name of the fan page: ";
	cleanBuffer();
	getline(cin, fanPageName);

	FansPage* curFanPage = system.getPFanPagebyName(fanPageName);

	if (curFanPage != nullptr)
	{
		cout << "\nPlease enter the name of the user, to be no more a fan of the fan page: ";
		getline(cin, oldfanName);

		User* oldFan = system.getPUserbyName(oldfanName);

		if (oldFan != nullptr)
		{
			if (curFanPage->checkIfFan(*oldFan) == true)
			{
				curFanPage->removeFan(*oldFan);
				cout << "\nThe user no more fan of the fan page" << endl;
			}
			else
				cout << "\nThe user already not a fan of this fan page, back to menu." << endl;
		}
		else
			cout << "\nThe name does not exist at the system, back to menu." << endl;
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// action 10
void printAllObjects(TwittFace& system)
{
	cout << "All the users at the system are: " << endl;
	for (int i = 0; i < system.getNumOfUsers(); i++)
	{
		system.getTheUser(i).printUser();
	}

	cout << "\nAll the fan pages at the system are: " << endl;
	for (int j = 0; j < system.getNumOfFanPages(); j++) // check that actions
	{
		system.getAllTheFanPages(j).printFanPage();
	}
}

// action 11
void showAllFriendsOrFans(TwittFace& system)
{
	char answer;
	cout << "Please select if to show, all the friends of a user/ all the fans of a fan page: (U-user / F-fan page) ";
	cin >> answer;
	if (answer == USER)
		showAllFriens(system);
	else if (answer == FANPAGE)
		showAllFans(system);
	else
		cout << "\nYou entered wrong input, back to menu." << endl;
}

// sub function of action 11
void showAllFriens(TwittFace& system)
{
	std::string userName;
	cout << "\nPlease enter the name of the user: ";
	cleanBuffer();
	getline(cin, userName);

	User* curUser = system.getPUserbyName(userName);

	if (curUser != nullptr)
	{
		cout << "\nAll the friends of " << userName << " are:" << endl;
		system.getPUserbyName(userName)->printAllFriends();
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}

// sub function of action 11
void showAllFans(TwittFace& system)
{
	std::string fanPageName;
	cout << "\nPlease enter the name of the fan page: ";
	cleanBuffer();
	getline(cin, fanPageName);

	FansPage* curFanPage = system.getPFanPagebyName(fanPageName);

	if (curFanPage != nullptr)
	{
		cout << "\nAll the fans of " << fanPageName << " are:" << endl;
		system.getPFanPagebyName(fanPageName)->printAllFans();
	}
	else
		cout << "\nThe name does not exist at the system, back to menu." << endl;
}