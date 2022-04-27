#include <iostream>
#include <string>
#include "Seller.h"
#include "Lessor.h"
#include "sqlite3.h"
#include "Users.h"

using namespace std;

Lessor::Lessor()
{
	createTable();
}

Lessor::~Lessor()
{
}

void Lessor::createTable()
{
	sqlite3 *DB;
	char *messageError;

	string sql = "CREATE TABLE IF NOT EXISTS LESSOR("
				 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
				 "NAME      TEXT NOT NULL, "
				 "SURNAME     TEXT NOT NULL, "
				 "PHONE       TEXT  NOT NULL, "
				 "TYPE   TEXT NOT NULL, "
				 "USERNAME     TEXT NOT NULL, "
				 "PASSWORD  TEXT NOT NULL, "
				 "WALLET DOUBLE NOT NULL); ";

	try
	{
		int exit = 0;
		exit = sqlite3_open("VehicleManagement.db", &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK)
		{
			//cerr << "Error in createTable function Client lessor." << endl;
			sqlite3_free(messageError);
		}
		
		sqlite3_close(DB);
	}
	catch (const exception &e)
	{
		cerr << e.what();
	}
}

void Lessor::signIn()
{
	int checkCounter{3};
	while (checkCounter > 0)
	{
		string username, password, bufftwo;
		cout << "\nEnter lessor username: ";
		cin >> username;

		cout << "Enter suitable password for the user " << username << ": ";
		cin >> password;
		

		selectUserData(username, "LESSOR");
		Users::setuserNameBuff(username);

		bufftwo = getBuff();
		if (password == bufftwo)
		{

			cout << "\nAccess Granted!\nWelcome Lessor " << username << endl;
			cout << Admin::getWalletBuff();
			break;
		}
		else
		{
			cout << "Invalid username or password. Please try again!" << endl;
			checkCounter--;
			cout << "Remaining attempt: " << checkCounter << endl;

			if (checkCounter == 0)
			{
				cout << "Program terminating due to 3 invalid attempt!" << endl;
				exit(1);
			}
		}
	}
}

void Lessor::addAd()
{
	Ad a;

	a.addLessorAd();
}

void Lessor::panel()
{

	bool a = true;
	int choice;

	while (a)
	{
		try
		{
			cout << "\n---------------------------------------------" << endl;
			cout << "                LESSOR PANEL" << endl;
			cout << "---------------------------------------------" << endl;
			cout << "\n1-Add new renting ad\n2-Update your ad\n3-See ads\n4-Wallet\n5-See address informations\n6-Update Adress\n7-Log out\nYour choice:";
			Users::cinError();
			cin >> choice;
			if (isdigit(choice) == true)
			{
				throw 1;
			}

			else if (choice == 1)
			{
				addAd();
			}
			else if (choice == 2)
			{
				Ad see;
				see.updateAd("T");
			}
			else if (choice == 3)
			{
				Ad see;
				see.seeAds("T");
			}
			else if (choice == 4)
			{
				cout << "\n---------------------------------------------" << endl;
				cout << "            TOTAL MONEY" << endl;
				cout << "---------------------------------------------\n"
					 << endl;

				Vehicle v;
				v.selectWalletFrom("LESSOR", Admin::getuserNameBuff());
				cout << Admin::getWalletBuff() << " $" << endl;
			}
			else if (choice == 5)
			{
				Address a;
				cout << "\n---------------------------------------------" << endl;
				cout << "            ADDRESS INFORMATIONS" << endl;
				cout << "---------------------------------------------" << endl;
				a.selectData();
			}
			else if (choice == 6)
			{
				updateAddress();
			}
			else if (choice == 7)
			{
				cout << "Logging out..." << endl;
				cout << "Bye!" << endl;
				a = false;
			}
			else
			{
				cout << "You have inputted an invalid value. Please try again!" << endl;
			}
		}
		catch (int &ex)
		{
			cerr << "You have to input a numeric value. Please try again!" << endl;
		}
	}
}
