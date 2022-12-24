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
enum lior_details { Lior_day = 3, Lior_month = 2, Lior_year = 1999 };
enum shalev_details { Shalev_day = 29, Shalev_month = 3, Shalev_year = 1999 };
enum Noa_details { Noa_day = 9, Noa_month = 6, Noa_year = 1999 };

int main()
{
	TwittFace system;
	int input;

	try
	{
		system.addUserToSystem("Lior Barak", lior_details::Lior_day, lior_details::Lior_month, lior_details::Lior_year);
		system.addUserToSystem("Shalev Kedar", shalev_details::Shalev_day, shalev_details::Shalev_month, shalev_details::Shalev_year);
		system.addUserToSystem("Noa Margolius", Noa_details::Noa_day, Noa_details::Noa_month, Noa_details::Noa_year);
		system.addFanPageToSystem("Lior Business");
		system.addFanPageToSystem("Shalev Business");
		system.addFanPageToSystem("Noa Business");

		system.getUserbyName("Lior Barak").addStatus("Lior Barak first status");
		system.getUserbyName("Lior Barak").addStatus("Lior Barak second status");
		system.getUserbyName("Shalev Kedar").addStatus("Shalev Kedar first status");
		system.getUserbyName("Shalev Kedar").addStatus("Shalev Kedar second status");
		system.getUserbyName("Noa Margolius").addStatus("Noa Margolius first status");
		system.getUserbyName("Noa Margolius").addStatus("Noa Margolius second status");
		system.getFanPagebyName("Lior Business").addStatus("Lior Business first status");
		system.getFanPagebyName("Lior Business").addStatus("Lior Business second status");
		system.getFanPagebyName("Shalev Business").addStatus("Shalev Business first status");
		system.getFanPagebyName("Shalev Business").addStatus("Shalev Business second status");
		system.getFanPagebyName("Noa Business").addStatus("Noa Business first status");
		system.getFanPagebyName("Noa Business").addStatus("Noa Business second status");

		system.getUserbyName("Shalev Kedar") += system.getUserbyName("Lior Barak");
		system.getUserbyName("Lior Barak") += system.getUserbyName("Noa Margolius");
		system.getUserbyName("Shalev Kedar") += system.getFanPagebyName("Shalev Business");
		system.getUserbyName("Lior Barak") += system.getFanPagebyName("Lior Business");
		system.getUserbyName("Noa Margolius") += system.getFanPagebyName("Noa Business");
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
		if (input >= 1 && input <= 12)
			action(input, system);
		else
			cout << "You entered wrong input, try again." << endl;

	} while (input != EXIT);
}