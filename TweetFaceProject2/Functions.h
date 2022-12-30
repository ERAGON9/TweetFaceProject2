#ifndef __FUNCTION_H
#define __FUNCTION_H

class TwittFace;
class User;
enum lior_details { Lior_day = 3, Lior_month = 2, Lior_year = 1999 };
enum shalev_details { Shalev_day = 29, Shalev_month = 3, Shalev_year = 1999 };
enum Noa_details { Noa_day = 9, Noa_month = 6, Noa_year = 1999 };

void printMenu();
void action(int value, TwittFace& system);
void cleanBuffer();
// Action 1
void addUser(TwittFace& system);
// Action 2
void addFanPage(TwittFace& system);
// Action 3
void addStatus(TwittFace& system);
// Sub function of action 3
void addStatusToUser(TwittFace& system);
// Sub function of action 3
void addStatuesToFanPage(TwittFace& system);
// Action 4
void printAllStatuses(TwittFace& system);
// Sub function of action 4
void printAllUserStatuses(TwittFace& system) throw(const char*);
// Sub function of action 4
void printAllFanPageStatuses(TwittFace& system) throw(const char*);
// Action 5
void printTenMostRecentFriendsStatuses(TwittFace& system);
// Action 6
void connectUsers(TwittFace& system) throw(const char*);
// Action 7
void seperateUsers(TwittFace& system) throw(const char*);
// Action 8
void addFanToFanPage(TwittFace& system) throw(const char*);
// Action 9
void removeFanFromFanPage(TwittFace& system) throw(const char*);
// Action 10
void printAllObjects(TwittFace& system);
// Action 11
void showAllFriendsOrFans(TwittFace& system);
// Sub function of action 11
void showAllFriens(TwittFace& system);
// Sub function of action 11
void showAllFans(TwittFace& system);

void initialNetworkData(TwittFace& system);

#endif // !__FUNCTION_H

