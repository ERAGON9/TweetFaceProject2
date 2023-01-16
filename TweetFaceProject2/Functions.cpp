#include "Functions.h"
#include <iostream>
#include "TwittFace.h"
#include "Users.h"
#include "FansPage.h"
#include <string>
#include "Status.h"
#include "Users.h"
#include "Exceptions.h"
#include <fstream>
#include <sstream>

using namespace std;

const char USER = 'U';
const char FANPAGE = 'F';
enum options { OPTION1=1, OPTION2, OPTION3, OPTION4, OPTION5, OPTION6, OPTION7, OPTION8, OPTION9, OPTION10, OPTION11 };
enum StatusTypes { TEXT = 1, IMAGE, VIDEO };

void printMenu()
{
	cout << "\nPlease press a number for your deserve action:" << endl
		<< " 1 - Add a user." << endl
		<< " 2 - Add fans page." << endl
		<< " 3 - Add Status for a user / fans page." << endl
		<< " 4 - Show all the statuses for a user / fans page." << endl
		<< " 5 - Show 10 most recent statuses of all the friends of a user." << endl
		<< " 6 - Connect friendship between 2 users." << endl
		<< " 7 - Delete friendship between 2 users." << endl
		<< " 8 - Add a user to a fan page." << endl
		<< " 9 - Delete a user from a fan page." << endl
		<< "10 - Show all the users and fan pages at the system." << endl
		<< "11 - Show all the friends of a user / fans of a fan page." << endl
		<< "12 - Exit." << endl
		<< "Your choice: ";
}

void action(int value, TwittFace& system)
{
	try
	{
		switch (value)
		{
		case options::OPTION1:
			addUser(system);
			break;
		case options::OPTION2:
			addFanPage(system);
			break;
		case options::OPTION3:
			addStatus(system);
			break;
		case options::OPTION4:
			printAllStatuses(system);
			break;
		case options::OPTION5:
			printTenMostRecentFriendsStatuses(system);
			break;
		case options::OPTION6:
			connectUsers(system);
			break;
		case options::OPTION7:
			seperateUsers(system);
			break;
		case options::OPTION8:
			addFanToFanPage(system);
			break;
		case options::OPTION9:
			removeFanFromFanPage(system);
			break;
		case options::OPTION10:
			printAllObjects(system);
			break;
		case options::OPTION11:
			showAllFriendsOrFans(system);
			break;
		default:
			break;
		}
	}
	catch (TweetFaceException& e)
	{
		cout << e.what() << ", back to menu." << endl;
	}
	catch (...)
	{
		cout << "\nSome eror occurred, call support team.";
		exit(1);
	}
}

// sub function
void cleanBuffer()
{
	char c;

	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

// Action 1
void addUser(TwittFace& system) noexcept(false)
{
	string userName;
	int day, month, year;

	cout << "Please enter User name: ";
	cleanBuffer();
	getline(cin, userName);

	if (userName.size() == 0)         // Check if name is empty for console input.
		throw EmptyNameException();

	cout << "\nPlease enter your birth date (day (space/enter)  month (space/enter) year ): ";
	cin >> day >> month >> year;

	system.addUserToSystem(userName, day, month, year);
	cout << "\nUser added successfully" << endl;
}

// Action 2
void addFanPage(TwittFace& system)
{
	string fanPageName;
	cout << "Please enter fan page name: ";
	cleanBuffer();
	getline(cin, fanPageName);

	system.addFanPageToSystem(fanPageName);
	cout << "\nFan page added successfully" << endl;
}

// Action 3
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
		cout << "\nBack to menu." << endl;
}

// Sub function of action 3
void addStatusToUser(TwittFace& system) noexcept(false)
{
	string userName, statusText, imageName, videoName;
	int statusType;

	cout << "\nPlease enter the name of the user: ";
	cleanBuffer();
	getline(cin, userName);
	User& curUser = system.getUserbyName(userName);

	cout << "\nPlease enter what kind of status do you want to create (1-text, 2-image and text, 3-video and text): ";
	cin >> statusType;
	if (statusType > 3 || statusType < 1)
		throw NoSuchStatusTypeException();

	cout << "\nPlease enter the new text for the status: ";
	cleanBuffer();
	getline(cin, statusText);

	switch (statusType)
	{
	case StatusTypes::TEXT:
		curUser.addTextStatus(statusText);
		break;
	case StatusTypes::IMAGE:
		cout << "\nPlease enter the image name (for example: dog.jpg): ";
		getline(cin, imageName);
		curUser.addImageStatus(statusText, imageName);
		break;
	case StatusTypes::VIDEO:
		cout << "\nPlease enter the video name (for example: dog walk to park.mp4): ";
		getline(cin, videoName);
		curUser.addVideoStatus(statusText, videoName);
		break;
	default:
		break;
	}
	cout << "\nUser status added successfully" << endl;
}


// Sub function of action 3
void addStatuesToFanPage(TwittFace& system)
{
	string fanPageName, statusText, imageName, videoName;
	int statusType;

	cout << "\nPlease enter the name of the fan page: ";
	cleanBuffer();
	getline(cin, fanPageName);
	FansPage& curFanPage = system.getFanPagebyName(fanPageName);

	cout << "\nPlease enter what kind of status do you want to create (1-text, 2-image and text, 3-video and text): ";
	cin >> statusType;
	if (statusType > 3 || statusType < 1)
		throw NoSuchStatusTypeException();

	cout << "\nPlease enter the new text for the status: ";
	cleanBuffer();
	getline(cin, statusText);

	switch (statusType)
	{
	case StatusTypes::TEXT:
		curFanPage.addTextStatus(statusText);
		break;
	case StatusTypes::IMAGE:
		cout << "\nPlease enter the image name (for example dog.jpg): ";
		getline(cin, imageName);
		curFanPage.addImageStatus(statusText, imageName);
		break;
	case StatusTypes::VIDEO:
		cout << "\nPlease enter the video name (for example dog_walk_to_park.mp4): ";
		getline(cin, videoName);
		curFanPage.addVideoStatus(statusText, videoName);
		break;
	default:
		break;
	}
	cout << "\nFan page status added successfully" << endl;
}

// Action 4
void printAllStatuses(TwittFace& system)
{
	char answer;
	cout << "Please select to who you want to show all the statuses: (U-user / F-fan page / else to go back to menu) ";
	cin >> answer;
	if (answer == USER)
		printAllUserStatuses(system);
	else if (answer == FANPAGE)
		printAllFanPageStatuses(system);
	else
		cout << "\nBack to menu." << endl;
}

// Sub function of action 4
void printAllUserStatuses(TwittFace& system) noexcept(false)
{
	string userName;

	cout << "\nPlease enter the name of the user: ";
	cleanBuffer();
	getline(cin, userName);
	User& curUser = system.getUserbyName(userName);

	if (curUser.getNumOfStatuses() > 0)
	{
		cout << "\nAll the user statuses are:" << endl;
		curUser.printAllStatuses();
	}
	else
		throw NoUserStatusesException();
}

// Sub function of action 4
void printAllFanPageStatuses(TwittFace& system) noexcept(false)
{
	string fanPageName;

	cout << "\nPlease enter the name of the fan page: ";
	cleanBuffer();
	getline(cin, fanPageName);
	FansPage& curFanPage = system.getFanPagebyName(fanPageName);

	if (curFanPage.getNumOfStatuses() > 0)
	{
		cout << "\nAll the fan page statuses are:" << endl;
		curFanPage.printAllStatuses();
	}
	else
		throw NoPageStatusesException();
}

// Action 5
void printTenMostRecentFriendsStatuses(TwittFace& system) noexcept(false)
{
	int countStatuses = 0, numberOfFriends;
	string userName;

	cout << "Please enter the name of the user: ";
	cleanBuffer();
	getline(cin, userName);
	User& curUser = system.getUserbyName(userName);

	numberOfFriends = curUser.getNumOfFriends();

	if (numberOfFriends == 0)
		throw NoFriendsException();

	for (int i = 0; i < numberOfFriends; i++)
	{
		const User& friendOfUser = curUser.getFriend(i);
		if (friendOfUser.getNumOfStatuses() > 0)
		{
			cout << "\nThe most recent statuses of " << friendOfUser.getName() << " are:" << endl;
			friendOfUser.printTenLastStatusOfTheUser();
			++countStatuses;
		}
	}

	if (countStatuses == 0)
		throw NoFriendsStatusesException();
}

// Action 6
void connectUsers(TwittFace& system) noexcept(false)
{
	string name1, name2;
	cout << "Please enter the name of the first user: ";
	cleanBuffer();
	getline(cin, name1);

	User& curUser1 = system.getUserbyName(name1);

	cout << "\nPlease enter the name of the second user: ";
	getline(cin, name2);

	if (name1 != name2)
	{
		User& curUser2 = system.getUserbyName(name2);

		if (curUser1.checkIfFriends(name2) == false)
		{
			curUser1 += curUser2;
			cout << "\nThe connection added successfully" << endl;
		}
		else
			throw ExistingFriensdshipException();
	}
	else
		throw SelfFriensdshipException();
}

// Action 7
void seperateUsers(TwittFace& system) noexcept(false)
{
	string name1, name2;

	cout << "Please enter the name of the first user: ";
	cleanBuffer();
	getline(cin, name1);

	User& curUser1 = system.getUserbyName(name1);

	cout << "\nPlease enter the name of the second user: ";
	getline(cin, name2);

	if (name1 != name2)
	{
		User& curUser2 = system.getUserbyName(name2);

		if (curUser1.checkIfFriends(name2) == true)
		{
			curUser1.removeFriend(curUser2);
			cout << "\nThe seperate happened, the two users no more friends" << endl;
		}
		else
			throw NotUserFriendsException();
	}
	else
		throw DeleteSelfFriensdshipException();
}

// Action 8
void addFanToFanPage(TwittFace& system) noexcept(false)
{
	string fanPageName, newfanName;
	cout << "Please enter the name of the fan page: ";
	cleanBuffer();
	getline(cin, fanPageName);

	FansPage& curFanPage = system.getFanPagebyName(fanPageName);

	cout << "\nPlease enter the user name of the new fan: ";
	getline(cin, newfanName);

	User& newFan = system.getUserbyName(newfanName);

	if (curFanPage.checkIfFan(newFan) == false)
	{
		curFanPage += newFan;
		cout << "\nThe user is a fan of the fan page now" << endl;
	}
	else
		throw UserFanOfFanPageException();
}

// Action 9
void removeFanFromFanPage(TwittFace& system) noexcept(false)
{
	string fanPageName, oldfanName;
	cout << "Please enter the name of the fan page: ";
	cleanBuffer();
	getline(cin, fanPageName);

	FansPage& curFanPage = system.getFanPagebyName(fanPageName);

	cout << "\nPlease enter the name of the user, to be no more a fan of the fan page: ";
	getline(cin, oldfanName);

	User& oldFan = system.getUserbyName(oldfanName);

	if (curFanPage.checkIfFan(oldFan) == true)
	{
		curFanPage.removeFan(oldFan);
		cout << "\nThe user no more fan of the fan page" << endl;
	}
	else
		throw UserNotFunOfFunPageException();
}

// Action 10
void printAllObjects(TwittFace& system)
{
	cout << "All the users at the system are: " << endl;

	int usersAmount = system.getNumOfUsers();
	for (int i = 0; i < usersAmount; i++)
	{
		system.getUser(i).printUser();
	}

	cout << "\nAll the fan pages at the system are: " << endl;

	int fanPagesAmount = system.getNumOfFanPages();
	for (int j = 0; j < fanPagesAmount; j++) // check that actions
	{
		system.getFanPage(j).printFanPage();
	}
}

// Action 11
void showAllFriendsOrFans(TwittFace& system)
{
	char answer;
	cout << "Please select if to show, all the friends of a user/ all the fans of a fan page: (U-user / F-fan page / else to go back to menu) ";
	cin >> answer;
	if (answer == USER)
		showAllFriens(system);
	else if (answer == FANPAGE)
		showAllFans(system);
	else
		cout << "\nBack to menu." << endl;
}

// Sub function of action 11
void showAllFriens(TwittFace& system) noexcept(false)
{
	string userName;
	cout << "\nPlease enter the name of the user: ";
	cleanBuffer();
	getline(cin, userName);

	User& curUser = system.getUserbyName(userName);

	if (curUser.getNumOfFriends() == 0)
		throw NoFriendsException();

	cout << "\nAll the friends of " << userName << " are:" << endl;
	curUser.printAllFriends();

}

// Sub function of action 11
void showAllFans(TwittFace& system) noexcept(false)
{
	string fanPageName;
	cout << "\nPlease enter the name of the fan page: ";
	cleanBuffer();
	getline(cin, fanPageName);

	FansPage& curFanPage = system.getFanPagebyName(fanPageName);

	if (curFanPage.getNumOfFans() == 0)
		throw NoFansException();

	cout << "\nAll the fans of " << fanPageName << " are:" << endl;
	curFanPage.printAllFans();
}

void initialNetworkData(TwittFace& system) noexcept(false)
{
	system.addUserToSystem("Lior Barak", lior_details::Lior_day, lior_details::Lior_month, lior_details::Lior_year);
	system.addUserToSystem("Shalev Kedar", shalev_details::Shalev_day, shalev_details::Shalev_month, shalev_details::Shalev_year);
	system.addUserToSystem("Noa Margolius", Noa_details::Noa_day, Noa_details::Noa_month, Noa_details::Noa_year);

	system.addFanPageToSystem("Lior Business");
	system.addFanPageToSystem("Shalev Business");
	system.addFanPageToSystem("Noa Business");

	system.getUserbyName("Lior Barak").addTextStatus("Lior Barak first status");
	system.getUserbyName("Lior Barak").addImageStatus("Lior Barak second status", "lior.jpg");
	system.getUserbyName("Shalev Kedar").addTextStatus("Shalev Kedar first status");
	system.getUserbyName("Shalev Kedar").addImageStatus("Shalev Kedar second status", "shalev.jpg");
	system.getUserbyName("Noa Margolius").addTextStatus("Noa Margolius first status");
	system.getUserbyName("Noa Margolius").addVideoStatus("Noa Margolius second status", "noa.mp4");

	system.getFanPagebyName("Lior Business").addTextStatus("Lior Business first status");
	system.getFanPagebyName("Lior Business").addVideoStatus("Lior Business second status", "lior at business.mp4");
	system.getFanPagebyName("Shalev Business").addTextStatus("Shalev Business first status");
	system.getFanPagebyName("Shalev Business").addImageStatus("Shalev Business second status", "shalev at business.jpg");
	system.getFanPagebyName("Noa Business").addVideoStatus("Noa Business first status", "noa at business.mp4");
	system.getFanPagebyName("Noa Business").addImageStatus("Noa Business second status", "noa at the park.jpg");

	system.getUserbyName("Shalev Kedar") += system.getUserbyName("Lior Barak");
	system.getUserbyName("Lior Barak") += system.getUserbyName("Noa Margolius");
	system.getUserbyName("Shalev Kedar") += system.getFanPagebyName("Shalev Business");
	system.getUserbyName("Noa Margolius") += system.getFanPagebyName("Noa Business");
	system.getFanPagebyName("Lior Business") += system.getUserbyName("Lior Barak");
}


void saveDataToFile(const TwittFace& system, const char* fileName)
{
	ofstream outFile(fileName, ios::trunc);

	saveUsersAndStatuses(system, outFile);

	saveFansPagesAndStatuses(system, outFile);

	saveConections(system, outFile);

	outFile.close();
}

void saveUsersAndStatuses(const TwittFace& system, ofstream& outFile)
{
	int i, j, numOfUsers = system.getNumOfUsers(), numOfStatusesForAUser;

	outFile << numOfUsers << endl;
	for (i = 0; i < numOfUsers; i++)
	{
		const User& curUser = system.getUser(i);
		outFile << curUser << endl;

		numOfStatusesForAUser = curUser.getNumOfStatuses();
		outFile << numOfStatusesForAUser << endl;

		for (j = 0; j < numOfStatusesForAUser; j++)
		{
			const Status& curUserStatus = curUser.getStatus(j);
			outFile << typeid(curUserStatus).name() + 6 << " " << curUserStatus << endl;
		}
	}
}

void saveFansPagesAndStatuses(const TwittFace& system, ofstream& outFile)
{
	int i, j, numOfFanPages = system.getNumOfFanPages(), numOfStatusesForAFanPage;

	outFile << numOfFanPages << endl;
	for (i = 0; i < numOfFanPages; i++)
	{
		const FansPage& curFanPage = system.getFanPage(i);
		outFile << curFanPage << endl;

		numOfStatusesForAFanPage = curFanPage.getNumOfStatuses();
		outFile << numOfStatusesForAFanPage << endl;

		for (j = 0; j < numOfStatusesForAFanPage; j++)
		{
			const Status& curFanPageStatus = curFanPage.getStatus(j);
			outFile << typeid(curFanPageStatus).name() + 6 << " " << curFanPageStatus << endl;
		}
	}
}

void saveConections(const TwittFace& system, ofstream& outFile)
{
	int i, j, numOfUsers = system.getNumOfUsers(), numOfFriendsForUser, numOfFansPagesForUser;

	outFile << numOfUsers << endl;
	for (i = 0; i < numOfUsers; i++)
	{
		const User& curUser = system.getUser(i);
		outFile << curUser.getName() << endl;

		numOfFriendsForUser = curUser.getNumOfFriends();
		outFile << numOfFriendsForUser << endl;

		for (j = 0; j < numOfFriendsForUser; j++)
		{
			outFile << curUser.getFriend(j).getName() << endl;
		}

		numOfFansPagesForUser = curUser.getNumOfFansPages();
		outFile << numOfFansPagesForUser << endl;

		for (j = 0; j < numOfFansPagesForUser; j++)
		{
			outFile << curUser.getFansPage(j).getName() << endl;
		}
	}
}

void loadDataFromFile(TwittFace& system, ifstream& inFile)
{
	readUsersAndStatuses(system, inFile);
	readFansPagesAndStatuses(system, inFile);
	readConections(system, inFile);
}

void readUsersAndStatuses(TwittFace& system, ifstream& inFile)
{
	int i, j, numOfUsers, day, month, year, hour, minute, numOfStatuses;
	string name, statusType, txt, media, str;
	char delimeter;

	getline(inFile, str);
	istringstream my_stream1(str);
	my_stream1 >> numOfUsers;

	for (i = 0; i < numOfUsers; i++)
	{
		getline(inFile, name);

		getline(inFile, str);
		istringstream my_stream2(str);
		my_stream2 >> day >> month >> year;

		system.addUserToSystem(name, day, month, year);
		User& currUser = system.getUser(i);

		getline(inFile, str);
		istringstream my_stream3(str);
		my_stream3 >> numOfStatuses;

		for (j = 0; j < numOfStatuses; j++)
		{
			getline(inFile, str);
			istringstream my_stream4(str);
			my_stream4 >> statusType >> day >> month >> year >> hour >> minute;

			if (statusType == (typeid(Status).name() + 6))
			{
				getline(inFile, txt);
				currUser.addPreviousTextStatus(txt, day, month, year, hour, minute);
			}
			else if (statusType == (typeid(ImageStatus).name() + 6))
			{
				getline(inFile, txt);
				getline(inFile, media);
				currUser.addPreviusImageStatus(txt, media, day, month, year, hour, minute);
			}
			else if (statusType == (typeid(VideoStatus).name() + 6))
			{
				getline(inFile, txt);
				getline(inFile, media);
				currUser.addPreviousVideoStatus(txt, media, day, month, year, hour, minute);
			}
		}
	}
}

void readFansPagesAndStatuses(TwittFace& system, ifstream& inFile)
{
	int i, j, numOfPages,day, month, year, hour, minute, numOfStatuses;
	string name, statusType, txt, media, str;

	getline(inFile, str);
	istringstream my_stream1(str);
	my_stream1 >> numOfPages;

	for (i = 0; i < numOfPages; i++)
	{
		getline(inFile, name);
		system.addFanPageToSystem(name);
		FansPage& currPage = system.getFanPage(i);

		getline(inFile, str);
		istringstream my_stream2(str);
		my_stream2 >> numOfStatuses;

		for (j = 0; j < numOfStatuses; j++)
		{
			getline(inFile, str);
			istringstream my_stream3(str);
			my_stream3 >> statusType >> day >> month >> year >> hour >> minute;

			if (statusType == (typeid(Status).name() + 6))
			{
				getline(inFile, txt);
				currPage.addTextStatus(txt);
			}
			else if (statusType == (typeid(ImageStatus).name() + 6))
			{
				getline(inFile, txt);
				getline(inFile, media);
				currPage.addImageStatus(txt, media);
			}
			else if (statusType == (typeid(VideoStatus).name() + 6))
			{
				getline(inFile, txt);
				getline(inFile, media);
				currPage.addVideoStatus(txt, media);
			}
		}
	}
}

void readConections(TwittFace& system, ifstream& inFile)
{
	int i, j, numOfUsers, numOfFiends, numOfFanPages;
	string name, str;

	getline(inFile, str);
	istringstream my_stream1(str);
	my_stream1 >> numOfUsers;

	for (i = 0; i < numOfUsers; i++)
	{
		getline(inFile, name);
		User& currUser = system.getUserbyName(name);

		getline(inFile, str);
		istringstream my_stream2(str);
		my_stream2 >> numOfFiends;

		for (j = 0; j < numOfFiends; j++)
		{
			getline(inFile, name);
			currUser += system.getUserbyName(name);
		}

		getline(inFile, str);
		istringstream my_stream3(str);
		my_stream3 >> numOfFanPages;

		for (j = 0; j < numOfFanPages; j++)
		{
			getline(inFile, name);
			currUser += system.getFanPagebyName(name);
		}
	}
}
