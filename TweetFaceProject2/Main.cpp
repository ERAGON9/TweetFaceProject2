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
enum Noa_details { day = 9, month = 6, year = 1999 };

int main()
{
	TwittFace system;
	int input;

	system.addUserToSystem("Lior Barak", lior_details::Lior_day, lior_details::Lior_month, lior_details::Lior_year);
	system.addUserToSystem("Shalev Kedar", shalev_details::Shalev_day, shalev_details::Shalev_month, shalev_details::Shalev_year);
	system.addUserToSystem("Noa Margolius", Noa_details::day, Noa_details::month, Noa_details::year);
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

	*system.getPUserbyName("Shalev Kedar") += *system.getPUserbyName("Lior Barak");
	*system.getPUserbyName("Lior Barak") += *system.getPUserbyName("Noa Margolius");
	*system.getPUserbyName("Shalev Kedar") += *system.getPFanPagebyName("Shalev Business");
	*system.getPUserbyName("Lior Barak") += *system.getPFanPagebyName("Lior Business");
	*system.getPUserbyName("Noa Margolius") += *system.getPFanPagebyName("Noa Business");

	do
	{
		printMenu();
		cin >> input;
		cout << endl;
		action(input, system);

	} while (input != EXIT);
}