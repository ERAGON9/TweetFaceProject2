#ifndef __FUNCTION_H
#define __FUNCTION_H

#include <fstream>

class TwittFace;
class User;

enum lior_details { Lior_day = 3, Lior_month = 2, Lior_year = 1999 };
enum shalev_details { Shalev_day = 29, Shalev_month = 3, Shalev_year = 1999 };
enum Noa_details { Noa_day = 9, Noa_month = 6, Noa_year = 1999 };

void printMenu();
void action(int value, TwittFace& system);
void cleanBuffer();
// Action 1
void addUser(TwittFace& system) noexcept(false);
// Action 2
void addFanPage(TwittFace& system);
// Action 3
void addStatus(TwittFace& system);
// Sub function of action 3
void addStatusToUser(TwittFace& system) noexcept(false);
// Sub function of action 3
void addStatuesToFanPage(TwittFace& system);
// Action 4
void printAllStatuses(TwittFace& system);
// Sub function of action 4
void printAllUserStatuses(TwittFace& system) noexcept(false);
// Sub function of action 4
void printAllFanPageStatuses(TwittFace& system) noexcept(false);
// Action 5
void printTenMostRecentFriendsStatuses(TwittFace& system) noexcept(false);
// Action 6
void connectUsers(TwittFace& system) noexcept(false);
// Action 7
void seperateUsers(TwittFace& system) noexcept(false);
// Action 8
void addFanToFanPage(TwittFace& system) noexcept(false);
// Action 9
void removeFanFromFanPage(TwittFace& system) noexcept(false);
// Action 10
void printAllObjects(TwittFace& system);
// Action 11
void showAllFriendsOrFans(TwittFace& system);
// Sub function of action 11
void showAllFriens(TwittFace& system) noexcept(false);
// Sub function of action 11
void showAllFans(TwittFace& system) noexcept(false);
// Initial at the first run of the program hard coded data for the network.
void initialNetworkData(TwittFace& system) noexcept(false);


void saveDataToFile(const TwittFace& system, const char* fileName);
void saveUsersAndStatuses(const TwittFace& system, std::ofstream& outFile);
void saveFansPagesAndStatuses(const TwittFace& system, std::ofstream& outFile);
void saveConections(const TwittFace& system, std::ofstream& outFile);
void readUsersAndStatuses(TwittFace& system, std::ifstream& inFile);
void readFansPagesAndStatuses(TwittFace& system, std::ifstream& inFile);
void readConections(TwittFace& system, std::ifstream& inFile);
void loadDataFromFile(TwittFace& system, std::ifstream& inFile);

#endif // !__FUNCTION_H

