#include "Seller.h"
#include "sqlite3.h"
#include <iostream>
#include "Users.h"
#include "Admin.h"

Seller::Seller()
{
	createTable();
}

Seller::~Seller()
{
}

void Seller::signUp(string type)
{
	string name, surName, phone, username, passw, sellerAddress;

	try
	{
		cout << "\nEnter Your Name: ";
		getline(cin >> ws, name);
		cout << "Enter Your Surname: ";
		getline(cin >> ws, surName);
		cout << "Enter Wallet: ";
		cin >> wallet;
		if (wallet < 0)
		{
			throw 1;
		}
		cout << "Enter Your Phone Number: ";
		getline(cin >> ws, phone);

		if (phone.size() != 0)
		{
			cout << "Enter Your Username: ";
			getline(cin >> ws, username);
			cout << "Enter Your Password: ";
			getline(cin >> ws, passw);

			userAddress.GetAddress(username);

			insertData(name, surName, phone, type, username, passw, wallet);
		}
		}
	catch (int &ex)
	{
		cerr << "Wallet value can not be below zero! Try to sign up again!" << endl;
	}
}

void Seller::createTable()
{
	sqlite3 *DB;
	char *messageError;

	string sql = "CREATE TABLE IF NOT EXISTS SELLER("
				 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
				 "NAME      TEXT NOT NULL, "
				 "SURNAME     TEXT NOT NULL, "
				 "PHONE       TEXT  NOT NULL, "
				 "TYPE   TEXT NOT NULL, "
				 "USERNAME     TEXT NOT NULL, "
				 "PASSWORD  TEXT NOT NULL,"
				 "WALLET DOUBLE NOT NULL); ";

	try
	{
		int exit = 0;
		exit = sqlite3_open("VehicleManagement.db", &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK)
		{
			//cerr << "Error in createTable function Seller." << endl;
			sqlite3_free(messageError);
		}
		else
			
			sqlite3_close(DB);
	}
	catch (const exception &e)
	{
		cerr << e.what();
	}
}

void Seller::insertData(const string &name, const string &surName, const string &phone, const string &type, const string &userName, const string &passw, double wallet)
{
	isExist(userName, type);
	if (Admin::getBuff() != userName)
	{
		sqlite3 *DB;
		char *messageError;

		string sql("INSERT INTO " + type + " (NAME, SURNAME, PHONE, TYPE, USERNAME, PASSWORD, WALLET) VALUES('" + name + "' , '" + surName + "', '" + phone + "','" + type + "','" + userName + "','" + passw + "','" + std::to_string(wallet) + "');");

		int exit = sqlite3_open("VehicleManagement.db", &DB);
		/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK)
		{
			//cerr << "Error in insertData function Seller." << endl;
			sqlite3_free(messageError);
		}
		else
		{
			
		}
	}
	else
	{
		cout << "This username has taken!!!" << endl;

		signUp(type);
	}
}

void Seller::signIn()
{
	int checkCounter{3};
	while (checkCounter > 0)
	{
		string username, password, bufftwo;
		cout << "\nEnter seller username: ";
		cin >> username;

		cout << "Enter suitable password for the user " << username << ": ";
		cin >> password;
		

		selectUserData(username, "SELLER");
		Users::setuserNameBuff(username);

		bufftwo = getBuff();
		if (password == bufftwo)
		{

			cout << "\nAccess Granted!\nWelcome Seller " << username << "\n\n";
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

void Seller::addAd()
{
	Ad a;

	a.addAd("seller");
}

void Seller::addRentingAd()
{
	Ad a;

	a.addLessorAd();
}

void Seller::updateAddress()
{
	char selection;

	while (1)
	{
		cout << "\n---------------------------------------------" << endl;
		cout << "                 UPDATE ADDRESS" << endl;
		cout << "---------------------------------------------" << endl;
		cout << "\nAre you sure that you want to change your address information?" << endl;
		cout << "Your address informations will be deleted and you will enter your new address information (y/n): ";
		cin >> selection;

		if (selection == 'y' || selection == 'Y')
		{
			Address a;
			a.deleteDatabase();

			cout << "Your address has deleted..." << endl;

			string username = Users::getuserNameBuff();

			cout << "Enter your new address\n"
				 << endl;

			userAddress.GetAddress(username);
			break;
		}
		else
		{
			cout << "You have input an invalid value. You will redirecting to the panel..." << endl;
			break;
		}
	}
}

void Seller::panel()
{
	bool a = true;
	int choice;

	while (a)
	{
		try
		{
			cout << "\n---------------------------------------------" << endl;
			cout << "                SELLER PANEL" << endl;
			cout << "---------------------------------------------" << endl;
			cout << "1-Add new selling ad\n2-Add new renting ad\n3-Update your ad\n4-See ads\n5-Wallet\n6-See Adress Informations\n7-UpdateAdress\n8-Log out\nYour choice:";
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
				Users::setuserTypeBuff("LESSOR");
				addRentingAd();
				Users::setuserTypeBuff("SELLER");
			}
			else if (choice == 3)
			{
				Ad see;
				see.updateAd("T");
			}
			else if (choice == 4)
			{
				Ad see;
				see.seeAds("T");
			}
			else if (choice == 5)
			{
				cout << "\n---------------------------------------------" << endl;
				cout << "            TOTAL MONEY" << endl;
				cout << "---------------------------------------------\n" << endl;
				Vehicle v;
				v.selectWalletFrom("SELLER", Admin::getuserNameBuff());
				cout << Admin::getWalletBuff() << " $" << endl;
			}
			else if (choice == 6)
			{
				Address a;
				cout << "\n---------------------------------------------" << endl;
				cout << "            ADDRESS INFORMATIONS" << endl;
				cout << "---------------------------------------------" << endl;
				a.selectData();
			}
			else if (choice == 7)
			{
				updateAddress();
			}
			else if (choice == 8)
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
			cerr << "You have input a numeric value. Please try again!" << endl;
		}
	}
}