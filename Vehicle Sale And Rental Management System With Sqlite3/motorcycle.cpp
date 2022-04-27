
#include <iostream>
#include "motorcycle.h"
#include "sqlite3.h"
#include "Admin.h"
#include "Users.h"
using namespace std;

Motorcycle::Motorcycle()
{
    createTable();
    
}
Motorcycle::~Motorcycle()
{
    
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

void Motorcycle::createTable()
{
    sqlite3 *DB;
    char *messageError;

    string sql = "CREATE TABLE IF NOT EXISTS MOTORCYCLE("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "USERNAME      TEXT NOT NULL, "
                 "USERTYPE      TEXT NOT NULL, "
                 "BRAND      TEXT NOT NULL, "
                 "MODEL      TEXT NOT NULL, "
                 "TYPE      TEXT NOT NULL, "
                 "YEAR      DOUBLE NOT NULL, "
                 "KM      DOUBLE NOT NULL, "
                 "HP      DOUBLE NOT NULL, "
                 "SHIFT      TEXT NOT NULL, "
                 "NUMBEROFWHEELS      TEXT NOT NULL, "
                 "COLOR      TEXT NOT NULL, "
                 "USAGE      TEXT NOT NULL, "
                 "PRICE      DOUBLE NOT NULL, "
                 "WEIGHT      DUBLE NOT NULL, "
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

void Motorcycle::insertData(const string &brand, const string &model, const string &type, const string &year, const string &km, const string &hp, const string &shift, const string &numberofwheels, const string &color, const string &usage, float price, const string &weight, const string &isDamaged)
{

    sqlite3 *DB;
    char *messageError;

    string sql("INSERT INTO MOTORCYCLE (USERNAME, USERTYPE, BRAND, MODEL, TYPE, YEAR, KM, HP, SHIFT, NUMBEROFWHEELS,COLOR, USAGE, PRICE, WEIGHT, ISDAMAGED) VALUES('" + Users::getuserNameBuff() + "', '" + Users::getuserTypeBuff() + "', '" + brand + "', '" + model + "', '" + type + "', '" + year + "', '" + km + "', '" + hp + "', '" + shift + "', '" + numberofwheels + "', '" + color + "', '" + usage + "', '" + std::to_string(price) + "', '" + weight + "', '" + isDamaged + "');");

    int exit = sqlite3_open("VehicleManagement.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error !!!" << endl;
        sqlite3_free(messageError);
    }
    
}

void Motorcycle::selectData(string tableName)
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
    
}

void Motorcycle::deleteDatabase(string tableName)
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