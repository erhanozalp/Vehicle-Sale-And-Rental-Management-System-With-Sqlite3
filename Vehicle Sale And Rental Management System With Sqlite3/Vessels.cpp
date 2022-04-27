#include <iostream>
#include "Vessels.h"
#include "sqlite3.h"
#include <string>
#include "Admin.h"
#include "Users.h"
using namespace std;

Vessels::Vessels()
{
    createTable();
    //cout << "Vessels no args constructor" << endl;
}

Vessels::~Vessels()
{
    //cout << "Vessels destructor" << endl;
}

int Vessels::getBedNumber()
{
    return bedNumber;
}

void Vessels::setBedNumber(int bedNumber)
{
    this->bedNumber = bedNumber;
}

float Vessels::getHeight()
{
    return height;
}

void Vessels::setHeight(float height)
{
    this->height = height;
}

int Vessels::getTotalACtiveHour()
{
    return totalActiveHour;
}

void Vessels::setTotalActiveHour(int totalHour)
{
    totalActiveHour = totalHour;
}

int Vessels::getMotorAmount()
{
    return motorAmount;
}

void Vessels::setMotorAmount(int motorAmount)
{
    this->motorAmount = motorAmount;
}

int Vessels::getKamara()
{
    return kamara;
}

void Vessels::setKamara(int kamara)
{
    this->kamara = kamara;
}

float Vessels::getWidth()
{
    return width;
}

void Vessels::setWidth(float width)
{
    this->width = width;
}

//Bunu ekle
void Vessels::createTable()
{
    sqlite3 *DB;
    char *messageError;

    string sql = "CREATE TABLE IF NOT EXISTS VESSEL("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "USERNAME      TEXT NOT NULL, "
                 "USERTYPE      TEXT NOT NULL, "
                 "BRAND      TEXT NOT NULL, "
                 "MOTORAMOUNT      INTEGER NOT NULL, "
                 "KAMARA      INTEGER NOT NULL, "
                 "TYPE      TEXT NOT NULL, "
                 "BEDNUMBER      INTEGER NOT NULL, "
                 "TOTALACTIVEHOUR      INTEGER NOT NULL, "
                 "HEIGHT      DOUBLE NOT NULL, "
                 "WIDTH      DOUBLE NOT NULL, "
                 "COLOR      TEXT NOT NULL, "
                 "USAGE      TEXT NOT NULL, "
                 "PRICE      DOUBLE NOT NULL, "
                 "ISDAMAGED     TEXT NOT NULL);";
    try
    {
        int exit = 0;
        exit = sqlite3_open("VehicleManagement.db", &DB);
        /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK)
        {
            cerr << "Error !!!" << endl;
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

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        // column name and value
        cout << azColName[i] << ": " << argv[i] << endl;
    }

    cout << "\n"
         << endl;
    return 0;
}

void Vessels::insertData(const string &brand, const string &motorAmount, const string &kamara, const string &type, const string &bedNumber, const string &totalActiveHour, const string &height, const string &width, const string &color, const string &usage, float price, const string &isDamaged)
{

    sqlite3 *DB;
    char *messageError;

    string sql("INSERT INTO VESSEL (USERNAME, USERTYPE, BRAND, MOTORAMOUNT, KAMARA, TYPE, BEDNUMBER, TOTALACTIVEHOUR, HEIGHT, WIDTH, COLOR, USAGE, PRICE, ISDAMAGED) VALUES('" + Users::getuserNameBuff() + "', '" + Users::getuserTypeBuff() + "', '" + brand + "', '" + motorAmount + "', '" + kamara + "', '" + type + "', '" + bedNumber + "', '" + totalActiveHour + "', '" + height + "', '" + width + "', '" + color + "', '" + usage + "', '" + std::to_string(price) + "' , '" + isDamaged + "');");

    int exit = sqlite3_open("VehicleManagement.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error !!!" << endl;
        sqlite3_free(messageError);
    }
    
}

void Vessels::selectData(string tableName)
{
    sqlite3 *DB;
    char *messageError;

    string sql = "SELECT * FROM " + tableName + ";";

    int exit = sqlite3_open("VehicleManagement.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

    if (exit != SQLITE_OK)
    {
        cerr << "Error !!!" << endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Records selected Successfully!" << endl;
}

void Vessels::deleteDatabase(string tableName)
{
    cout << "\nPlease Enter The ID of the car you want to Delete: ";
    string id;
    cin >> id;

    sqlite3 *DB;
    char *messageError;

    string sql = "DELETE FROM " + tableName + " WHERE ID = '" + id + "';";

    int exit = sqlite3_open("VehicleManagement.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
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
