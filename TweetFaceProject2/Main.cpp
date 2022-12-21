/*
Welcome to TwittFaceProject:
created by Lior Barak, 206631418 and Shalev Kedar 314714080
The project administor a network of conections between friends and fan pages.
Every user (a friend) and fan page can upload statuses, and more option with a 12 options menu.
Good luck!
*/
#include <iostream>
#include "TwittFace.h"
#include "Users.h"
#include "Status.h"
#include "FansPage.h"
#include "Functions.h"

using namespace std;
#pragma warning(disable: 4996)


int main()
{
	TwittFace system;
	int input;

	system.addUserToSystem("Lior Barak", 3, 2, 1999);
	system.addUserToSystem("Shalev Kedar", 29, 3, 1999);
	system.addUserToSystem("Noa Margolius", 9, 6, 1999);
	system.addFanPageToSystem("Lior Business");
	system.addFanPageToSystem("Shalev Business");
	system.addFanPageToSystem("Noa Business");

	system.getPUserbyName("Lior Barak")->addStatus("Lior Barak first status");
	system.getPUserbyName("Lior Barak")->addStatus("Lior Barak second status");
	system.getPUserbyName("Shalev Kedar")->addStatus("Shalev Kedar first status");
	system.getPUserbyName("Shalev Kedar")->addStatus("Shalev Kedar second status");
	system.getPUserbyName("Noa Margolius")->addStatus("Noa Margolius first status");
	system.getPUserbyName("Noa Margolius")->addStatus("Noa Margolius second status");
	system.getPFanPagebyName("Lior Business")->addStatus("Lior Business first status");
	system.getPFanPagebyName("Lior Business")->addStatus("Lior Business second status"); 
	system.getPFanPagebyName("Shalev Business")->addStatus("Shalev Business first status");
	system.getPFanPagebyName("Shalev Business")->addStatus("Shalev Business second status");
	system.getPFanPagebyName("Noa Business")->addStatus("Noa Business first status");
	system.getPFanPagebyName("Noa Business")->addStatus("Noa Business second status");
	system.getPUserbyName("Shalev Kedar")->addFriend(*(system.getPUserbyName("Lior Barak")));
	system.getPUserbyName("Shalev Kedar")->addFansPage(*(system.getPFanPagebyName("Shalev Business")));
	system.getPUserbyName("Lior Barak")->addFriend(*(system.getPUserbyName("Noa Margolius")));
	system.getPUserbyName("Lior Barak")->addFansPage(*(system.getPFanPagebyName("Lior Business")));
	system.getPUserbyName("Noa Margolius")->addFansPage(*(system.getPFanPagebyName("Noa Business")));

	do
	{
		printMenu();
		cin >> input;
		cout << endl;
		action(input, system);

	} while (input != 12);
}