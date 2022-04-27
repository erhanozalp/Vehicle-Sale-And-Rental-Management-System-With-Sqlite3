#include <iostream>
#include "Address.h"
#include <string>
#include "sqlite3.h"
#include "Admin.h"

using namespace std;

Address::Address()
{
    createTable();
}

void Address::GetAddress(string username)
{
    string city, country, district, zipCode, buildingNumber, doorNumber;

    cout << "Enter City: ";
    getline(cin >> ws, city);

    cout << "Enter Country: ";
    getline(cin >> ws, country);

    cout << "Enter District: ";
    getline(cin >> ws, district);

    cout << "Enter Zipcode: ";
    getline(cin >> ws, zipCode);

    cout << "Enter Buildingnumber: ";
    getline(cin >> ws, buildingNumber);

    cout << "Enter Doornumber: ";
    getline(cin >> ws, doorNumber);

    insertData(username, city, country, district, zipCode, buildingNumber, doorNumber);
}

string Address::getCity()
{
    return city;
}
void Address::setCity(string city)
{
    this->city = city;
}

string Address::getCountry()
{
    return country;
}
void Address::setCountry(string country)
{
    this->country = country;
}

string Address::getDistrict()
{
    return district;
}
void Address::setDistrict(string district)
{
    this->district = district;
}

string Address::getZipCode()
{
    return zipCode;
}
void Address::setZipCode(string zipCode)
{
    this->zipCode = zipCode;
}

string Address::getBuildingNumber()
{
    return buildingNumber;
}
void Address::setBuildingNumber(string buildingNumber)
{
    this->buildingNumber = buildingNumber;
}

string Address::getDoorNumber()
{
    return doorNumber;
}
void Address::setDoorNumber(string doorNumber)
{
    this->doorNumber = doorNumber;
}

Address::~Address()
{
   
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        // column name and value
        cout << azColName[i] << ":" << argv[i] << "\t";
    }

    cout << "\n"
         << endl;
    return 0;
}

void Address::insertData(const string &username, const string &city, const string &country, const string &district, const string &zipCode, const string &buildingNumber, const string &doorNumber)
{

    sqlite3 *DB;
    char *messageError;

    string sql("INSERT INTO ADDRESS (USERNAME, CITY, COUNTRY, DISTRICT, ZIPCODE, BUILDINGNUMBER, DOORNUMBER) VALUES('" + username + "', '" + city + "', '" + country + "', '" + district + "', '" + zipCode + "', '" + buildingNumber + "', '" + doorNumber + "');");

    int exit = sqlite3_open("VehicleManagement.db", &DB);

    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        cerr << "Error !!!" << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Added..." << endl;
}

void Address::createTable()
{

    sqlite3 *DB;
    char *messageError;

    string sql = "CREATE TABLE IF NOT EXISTS ADDRESS("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "USERNAME      TEXT NOT NULL, "
                 "CITY      TEXT NOT NULL, "
                 "COUNTRY       TEXT NOT NULL, "
                 "DISTRICT      TEXT NOT NULL, "
                 "ZIPCODE       TEXT NOT NULL, "
                 "BUILDINGNUMBER        TEXT NOT NULL, "
                 "DOORNUMBER        TEXT NOT NULL);";

    try
    {
        int exit = 0;
        exit = sqlite3_open("VehicleManagement.db", &DB);
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK)
        {
            cerr << "Error !!!" << endl;
            sqlite3_free(messageError);
        }
        else
        {
            sqlite3_close(DB);
        }
    }
    catch (const exception &e)
    {
        cerr << e.what();
    }
}

void Address::deleteDatabase()
{
    sqlite3 *DB;
    char *messageError;

    string sql = "DELETE FROM ADDRESS WHERE USERNAME = '" + Users::getuserNameBuff() + "';";

    int exit = sqlite3_open("VehicleManagement.db", &DB);

    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

    if (exit != SQLITE_OK)
    {
        cerr << "Error !!!" << endl;
        sqlite3_free(messageError);
    }
    else
    {
        cout << "User Deleted Successfully!" << endl;
    }
}

void Address::selectData()
{
    sqlite3 *DB;
    char *messageError;

    string sql = "SELECT * FROM ADDRESS WHERE USERNAME= '" + Users::getuserNameBuff() + "';";

    int exit = sqlite3_open("VehicleManagement.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

    if (exit != SQLITE_OK)
    {
        cerr << "Error !!!" << endl;
        sqlite3_free(messageError);
    }
}

void Address::updateData(const string &columnName, const string &newSet)
{

    sqlite3 *DB;
    char *messageError;

    string sql = ("UPDATE ADDRESS SET " + columnName + "= '" + newSet + "' WHERE USERNAME = '" + Users::getuserNameBuff() + "'");

    int exit = sqlite3_open("VehicleManagement.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error !!!" << endl;
        sqlite3_free(messageError);
    }
}
