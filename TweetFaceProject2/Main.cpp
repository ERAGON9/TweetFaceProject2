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
const int EXIT = 12;

int main()
{
	TwittFace system;
	int input;

	User lior("Lior Barak", 3, 2, 1999);
	User shalev("Shalev Kedar", 29, 3, 1999);
	User noa("Noa Margolius", 9, 6, 1999);
	FansPage liorFP("Lior Business");
	FansPage shalevFP("Shalev Business");
	FansPage noaFP("Noa Business");

	system.addUserToSystem(lior);
	system.addUserToSystem(shalev);
	system.addUserToSystem(noa);
	system.addFanPageToSystem(liorFP);
	system.addFanPageToSystem(shalevFP);
	system.addFanPageToSystem(noaFP);

	lior.addStatus("Lior Barak First status");
	lior.addStatus("Lior Barak Second status");
	shalev.addStatus("Shalev Kedar First status");
	shalev.addStatus("Shalev Kedar Second status");
	noa.addStatus("Noa Margolius First status");
	noa.addStatus("Noa Margolius Second status");
	liorFP.addStatus("Lior Business First status");
	liorFP.addStatus("Lior Business Second status");
	shalevFP.addStatus("Shalev BusinessFirst status");
	shalevFP.addStatus("Shalev Business Second status");
	noaFP.addStatus("Noa Business First status");
	noaFP.addStatus("Noa Business Second status");

	shalev.addFriend(lior);
	lior.addFriend(noa);
	shalev.addFansPage(shalevFP);
	lior.addFansPage(liorFP);
	noa.addFansPage(noaFP);

	do
	{
		printMenu();
		cin >> input;
		cout << endl;
		action(input, system);

	} while (input != EXIT);
}