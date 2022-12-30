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
const int EXIT = 12;
const int FIRST = 1;

int main()
{
	TwittFace system;
	int input;

	try
	{
		initialNetworkData(system);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		cout << "\nOccurred at main hard coded data." << endl;
	}
	catch (...)
	{
		cout << "\nSome eror occurred at main hard coded data, call support team.";
		exit(1);
	}

	do
	{
		printMenu();
		cin >> input;
		cout << endl;
		if (input >= FIRST && input <= EXIT)
			action(input, system);
		else
			cout << "You entered wrong input, try again." << endl;

	} while (input != EXIT);
}
