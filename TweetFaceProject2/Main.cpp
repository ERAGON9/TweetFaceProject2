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

	initHardCodedData(system);

	do
	{
		printMenu();
		cin >> input;
		cout << endl;
		action(input, system);

	} while (input != 12);
}