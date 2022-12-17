#ifndef __FUNCTION_H
#define __FUNCTION_H

class TwittFace;
class User;

void initHardCodedData(TwittFace& system);
void printMenu();
void action(int value, TwittFace& system);
void addUser(TwittFace& system);
void addFanPage(TwittFace& system);
void addStatus(TwittFace& system);
void addStatusToUser(TwittFace& system);
void addStatuesToFanPage(TwittFace& system);
void cleanBuffer();
void printAllStatuses(TwittFace& system);
void printAllUserStatuses(TwittFace& system);
void printAllFanPageStatuses(TwittFace& system);
void printTenMostRecentFriendsStatuses(TwittFace& system);
void connectUsers(TwittFace& system);
void seperateUsers(TwittFace& system);
void addFanToFanPage(TwittFace& system);
void removeFanFromFanPage(TwittFace& system);
void printAllObjects(TwittFace& system);
void showAllFriendsOrFans(TwittFace& system);
void showAllFriens(TwittFace& system);
void showAllFans(TwittFace& system);

#endif // !__FUNCTION_H

