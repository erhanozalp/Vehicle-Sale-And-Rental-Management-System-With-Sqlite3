#include "vehicle.h"
#include <iostream>
#include "sqlite3.h"
#include "Users.h"
#include "Admin.h"
#include "Client.h"
#include <sstream>
static int callback(void *NotUsed, int argc, char **argv, char **azColName);

string Vehicle::getBrand()
{
	return brand;
}

string Vehicle::getColor()
{
	return color;
}

double Vehicle::getPrice()
{
	return price;
}

string Vehicle::getFuel()
{
	return fuel;
}

string Vehicle::getUsage()
{
	return usage;
}

string Vehicle::getType()
{
	return type;
}

void Vehicle::setBrand(string brand)
{
	this->brand = brand;
}

void Vehicle::setColor(string color)
{
	this->color = color;
}

Vehicle::~Vehicle()
{
	
}

Vehicle::Vehicle()
{
	
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
	if (argc == 1)
	{
		stringstream strint(*argv);
		int x = 0;
		strint >> x;
		Admin::setWalletBuff(x);
		return 0;
	}
	for (int i = 0; i < argc; i++)
	{
		// column name and value
		cout << azColName[i] << ": " << argv[i] << "\t";
	}

	cout << "\n"
		 << endl;

	return 0;
}
static int callbackownerwallet(void *NotUsed, int argc, char **argv, char **azColName)
{
	if (argc == 1)
	{
		stringstream strint(*argv);
		int x = 0;
		strint >> x;
		Admin::SetcarOwnerWalletBuff(x);
		return 0;
	}
	for (int i = 0; i < argc; i++)
	{
		// column name and value
		cout << azColName[i] << ": " << argv[i] << "\t";
	}

	cout << "\n"
		 << endl;

	return 0;
}

static int callbackprice(void *NotUsed, int argc, char **argv, char **azColName)
{
	if (argc == 1)
	{
		stringstream strint(*argv);
		int x = 0;
		strint >> x;
		Admin::SetcarPriceBuff(x);
		return 0;
	}
	for (int i = 0; i < argc; i++)
	{
		// column name and value
		cout << azColName[i] << ": " << argv[i] << "\t";
	}

	cout << "\n"
		 << endl;

	return 0;
}

void Vehicle::deleteData(const string &tableName, int id)
{
	sqlite3 *DB;
	char *messageError;
	string sql;

	sql = "DELETE FROM " + tableName + " WHERE ID = '" + std::to_string(id) + "';";

	int exit = sqlite3_open("VehicleManagement.db", &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
	if (exit != SQLITE_OK)
	{
		cerr << "Error !!!" << endl;
		sqlite3_free(messageError);
	}
}

void Vehicle::selectData(const string &tableName, const string &username)
{
	sqlite3 *DB;
	char *messageError;
	string sql;

	if (username == "F")
		sql = "SELECT * FROM " + tableName + ";";
	else
		sql = "SELECT * FROM " + tableName + " WHERE USERNAME = '" + Users::getuserNameBuff() + "';";

	int exit = sqlite3_open("VehicleManagement.db", &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

	if (exit != SQLITE_OK)
	{
		cerr << "Error !!!" << endl;
		sqlite3_free(messageError);
	}
}

void Vehicle::updateVehicle(const string &tableName, const int &id, const string &columnName, const string &newSet, string username)
{

	sqlite3 *DB;
	char *messageError;
	string sql;
	if (username == "F")
		sql = ("UPDATE " + tableName + " SET " + columnName + "= '" + newSet + "' WHERE ID = '" + std::to_string(id) + "'");
	else
		sql = ("UPDATE " + tableName + " SET " + columnName + "= '" + newSet + "' WHERE USERNAME = '" + Users::getuserNameBuff() + "' AND ID = '" + std::to_string(id) + "'");

	int exit = sqlite3_open("VehicleManagement.db", &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK)
	{
		cerr << "Error !!!" << endl;
		sqlite3_free(messageError);
	}
}

void Vehicle::selectWalletFromOwner(const string &tableName, const string &username)
{
	sqlite3 *DB;
	char *messageError;

	string sql = "SELECT WALLET FROM " + tableName + " WHERE USERNAME = '" + username + "';";

	int exit = sqlite3_open("VehicleManagement.db", &DB);

	exit = sqlite3_exec(DB, sql.c_str(), callbackownerwallet, NULL, &messageError);

	if (exit != SQLITE_OK)
	{
		cerr << "Error !!!" << endl;
		sqlite3_free(messageError);
	}
}
void Vehicle::selectWalletFrom(const string &tableName, const string &username)
{
	sqlite3 *DB;
	char *messageError;

	string sql = "SELECT WALLET FROM " + tableName + " WHERE USERNAME = '" + username + "';";

	int exit = sqlite3_open("VehicleManagement.db", &DB);

	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

	if (exit != SQLITE_OK)
	{
		cerr << "Error !!!" << endl;
		sqlite3_free(messageError);
	}
}

void Vehicle::selectPriceFrom(const string &tableName, const int &id)
{
	sqlite3 *DB;
	char *messageError;

	string sql = "SELECT PRICE FROM " + tableName + " WHERE ID = '" + std::to_string(id) + "';";

	int exit = sqlite3_open("VehicleManagement.db", &DB);

	exit = sqlite3_exec(DB, sql.c_str(), callbackprice, NULL, &messageError);

	if (exit != SQLITE_OK)
	{
		cerr << "Error !!!" << endl;
		sqlite3_free(messageError);
	}
}

void Vehicle::UpdateClientWallet(int newSet)
{
	sqlite3 *DB;
	char *messageError;
	string sql;
	sql = ("UPDATE CLIENT SET WALLET = '" + std::to_string(newSet) + "' WHERE USERNAME = '" + Users::getuserNameBuff() + "'");

	int exit = sqlite3_open("VehicleManagement.db", &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK)
	{
		cerr << "Error !!!" << endl;
		sqlite3_free(messageError);
	}
}

void Vehicle::UpdateCarOwnerWallet(string tableName, int newSet, string username)
{
	sqlite3 *DB;
	char *messageError;
	string sql;
	sql = ("UPDATE " + tableName + " SET WALLET = '" + std::to_string(newSet) + "' WHERE USERNAME = '" + username + "'");

	int exit = sqlite3_open("VehicleManagement.db", &DB);
	/* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK)
	{
		cerr << "Error !!!" << endl;
		sqlite3_free(messageError);
	}
}

void Vehicle::buyOrRentSelection(string tableName, string userType)
{

	int id;

	string newData, buy;

	cout << "Enter ID to buy: ";
	cin >> id;
	cout << "Enter car owner username: ";
	string carownerusername;
	cin >> carownerusername;
	selectPriceFrom(tableName, id);
	selectWalletFrom("CLIENT", Admin::getuserNameBuff());

	if (userType == "S")
	{
		cout << "Purchase? (y / n): ";
		selectWalletFromOwner("SELLER", carownerusername);
		cin >> buy;
		if (buy == "y")
		{
			if (Admin::getWalletBuff() > Admin::GetcarPriceBuff())
			{
				int x;
				x = Admin::getWalletBuff() - Admin::GetcarPriceBuff();
				UpdateClientWallet(x);

				x = 0;
				x = Admin::GetcarOwnerWalletBuff() + Admin::GetcarPriceBuff();
				UpdateCarOwnerWallet("SELLER", x, carownerusername);

				deleteData(tableName, id);
				cout << "Successful purchase/renting" << endl;
			}
			else
			{
				cout << "Money is not enough!";
				Client c;
				c.panel();
			}
		}
		else
		{
			Client c;
			c.panel();
		}
	}
	else
	{
		cout << "Rent? (y / n): ";
		selectWalletFromOwner("LESSOR", carownerusername);
		cin >> buy;
		if (buy == "y")
		{

			int numOfDays;

			cout << "Enter how many days you want to rent this car:";
			cin >> numOfDays;

			int a = Admin::GetcarPriceBuff();

			if (Admin::getWalletBuff() > numOfDays*a)
			{
				int x;
				x = Admin::getWalletBuff() - numOfDays*a;
				UpdateClientWallet(x);

				x = 0;
				x = Admin::GetcarOwnerWalletBuff() + numOfDays*a;
				UpdateCarOwnerWallet("LESSOR", x, carownerusername);

				deleteData(tableName, id);
				cout << "Successful purchase/renting" << endl;
			}
			else
			{
				cout << "Money is not enough!";
				Client c;
				c.panel();
			}
		}
		else
		{
			Client c;
			c.panel();
		}
	}

}

void Vehicle::updateSelections(string x, string username)
{
	while (1)
	{
		selectData(x, username);
		int id;
		string newData, cName;
		cout << "\nEnter id(press 0 to go back!): ";
		cin >> id;
		if (id == 0)
		{
			break;
		}
		else
		{
			cout << "Enter columname: ";
			getline(cin >> ws, cName);
			cout << "Enter set new: ";
			getline(cin >> ws, newData);
			updateVehicle(x, id, cName, newData, username);
			break;
		}
	}
}

void Vehicle::deleteSelection(const string &x)
{
	selectData(x, "dsadsa");
	int id, sel;
	while (1)
	{
		cout << "1-Enter id\n2-Go back\nYour choice:" << endl;
		Users::cinError();
		cin >> sel;

		if (sel == 1)
		{
			cout << "Enter id: ";
			cin >> id;
			deleteData(x, id);
		}
		else
		{
			break;
		}
	}
}
