#include <iostream>
#include <string>
#include "Client.h"
#include "sqlite3.h"
#include "Users.h"

using namespace std;

Client::Client()
{
	createTable();
}

Client::~Client() {}

void Client::createTable()
{
	sqlite3 *DB;
	char *messageError;

	string sql = "CREATE TABLE IF NOT EXISTS CLIENT("
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
			//cerr << "Error in createTable function Client." << endl;
			sqlite3_free(messageError);
		}
		
		sqlite3_close(DB);
	}
	catch (const exception &e)
	{
		cerr << e.what();
	}
}

void Client::signIn()
{
	int checkCounter{3};
	while (checkCounter > 0)
	{
		string username, password, bufftwo;
		cout << "\nEnter client username: ";
		cin >> username;

		cout << "Enter suitable password for the user " << username << ": ";
		cin >> password;

		selectUserData(username, "CLIENT");
		Users::setuserNameBuff(username);

		bufftwo = getBuff();
		if (password == bufftwo)
		{

			cout << "\nAccess Granted!\nWelcome Client " << username << endl;
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

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	for (int i = 0; i < argc; i++)
	{
		//column name and value
		cout << azColName[i] << ":" << argv[i] << "\t";
	}
	cout << "\n"
		 << endl;
	return 0;
}

void Client::seeAds(string tableName, string userType)
{
	sqlite3 *DB;
	char *messageError;

	string sql = "SELECT * FROM '" + tableName + "' WHERE  USERTYPE = '" + userType + "';";

	int exit = sqlite3_open("VehicleManagement.db", &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

	if (exit != SQLITE_OK)
	{
		cerr << "Error !!!" << endl;
		sqlite3_free(messageError);
	}
	
}


void Client::panel()
{
	bool a = true;
	int choice;

	while (a)
	{
		try
		{
			cout << "\n---------------------------------------------" << endl;
			cout << "                 CLIENT PANEL" << endl;
			cout << "---------------------------------------------" << endl;
			cout << "\n1-See seller ads\n2-See renting ads\n3-Wallet\n4-See address Informations\n5-Update Adress\n6-Log out\nYour choice:";
			Users::cinError();
			cin >> choice;
			Vehicle v;
			if (isdigit(choice) == true)
			{
				throw 1;
			}

			if (choice == 1)
			{
				int x;
				cout << "\n---------------------------------------------" << endl;
				cout << "               VEHICLE TYPE" << endl;
				cout << "---------------------------------------------" << endl;
				cout << "\n1-Car\n2-Motorcycle\n3-Vessel\n4-Go Back\nYour choice: ";
				Users::cinError();
				cin >> x;

				if (x == 1)
				{
					cout << "\n---------------------------------------------" << endl;
					cout << "                   CARS" << endl;
					cout << "---------------------------------------------" << endl;
					seeAds("CAR", "SELLER");
					
					v.buyOrRentSelection("CAR", "S");
				}
				else if (x == 2)
				{
					cout << "\n---------------------------------------------" << endl;
					cout << "                   MOTORCYCLE" << endl;
					cout << "---------------------------------------------" << endl;
					seeAds("MOTORCYCLE", "SELLER");
					v.buyOrRentSelection("MOTORCYCLE", "S");
				}
				else if (x == 3)
				{
					cout << "\n---------------------------------------------" << endl;
					cout << "                    VESSELS" << endl;
					cout << "---------------------------------------------" << endl;
					seeAds("VESSEL", "SELLER");
					v.buyOrRentSelection("VESSEL", "S");
				}
				else if (x == 4)
				{
					break;
				}
				else
				{
					cout << "Invalid Input!";
				}
			}
			else if (choice == 2)
			{
				int x;
				cout << "\n---------------------------------------------" << endl;
				cout << "               VEHICLE TYPE" << endl;
				cout << "---------------------------------------------" << endl;
				cout << "\n1-Car\n2-Motorcycle\n3-Vessel\n4-Go Back\nYour choice: ";
				Users::cinError();
				cin >> x;
				switch (x)
				{
				case 1:
					cout << "\n---------------------------------------------" << endl;
					cout << "                   CARS" << endl;
					cout << "---------------------------------------------" << endl;
					seeAds("CAR", "LESSOR");
					v.buyOrRentSelection("CAR", "L");

					break;
				case 2:
					cout << "\n---------------------------------------------" << endl;
					cout << "                   MOTORCYCLE" << endl;
					cout << "---------------------------------------------" << endl;
					seeAds("MOTORCYCLE", "LESSOR");
					v.buyOrRentSelection("MOTORCYCLE", "L");

					break;
				case 3:
					cout << "\n---------------------------------------------" << endl;
					cout << "                    VESSELS" << endl;
					cout << "---------------------------------------------" << endl;
					seeAds("VESSEL", "LESSOR");
					v.buyOrRentSelection("VESSEL", "L");

					break;
				default:
					cout << "Invalid!!!" << endl;

					break;
				}
			}
			else if (choice == 3)
			{
				cout << "\n---------------------------------------------" << endl;
				cout << "            TOTAL MONEY" << endl;
				cout << "---------------------------------------------\n"
					 << endl;
				Vehicle v;
				v.selectWalletFrom("CLIENT", Admin::getuserNameBuff());
				cout << Admin::getWalletBuff() << " $" << endl;
			}
			else if (choice == 4)
			{
				Address a;
				cout << "\n---------------------------------------------" << endl;
				cout << "            ADDRESS INFORMATIONS" << endl;
				cout << "---------------------------------------------" << endl;
				a.selectData();
			}
			else if (choice == 5)
			{
				updateAddress();
			}
			else if (choice == 6)
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
			cerr << "You have to input a numeric value. Please try again." << endl;
		}
	}
}