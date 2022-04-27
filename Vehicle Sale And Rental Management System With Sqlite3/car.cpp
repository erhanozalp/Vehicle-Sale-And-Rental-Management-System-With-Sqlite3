#include <iostream>
#include "car.h"
#include "sqlite3.h"
#include "Admin.h"
#include "Users.h"
using namespace std;

Car::Car()
{
    createTable();
   // cout << "Car no args constructor" << endl;
}

int Car::getYear()
{
    return year;
}
void Car::setYear(int year)
{
    this->year = year;
}
int Car::getHp()
{
    return hp;
}
void Car::setHp(int hp)
{
    this->hp = hp;
}
float Car::getKm()
{
    return km;
}
void Car::setKm(float km)
{
    this->km = km;
}
float Car::getWeight()
{
    return weight;
}
void Car::setWeight(float weight)
{
    this->weight = weight;
}

string Car::getCategory()
{
    return category;
}
void Car::setCategory(string category)
{
    this->category = category;
}

string Car::getModel()
{
    return model;
}
void Car::setModel(string model)
{
    this->model = model;
}

string Car::getShift()
{
    return shift;
}
void Car::setShift(string shift)
{
    this->shift = shift;
}

string Car::getIsDamaged()
{
    return isDamaged;
}
void Car::setIsDamaged(string damage)
{
    this->isDamaged = isDamaged;
}

string Car::getSedanOrHatchbag()
{
    return bodyType;
}
void Car::setSedanOrHatchbag(string bodyType)
{
    this->bodyType = bodyType;
}

Car::~Car()
{
    //cout << "Car destructor" << endl;
}

void Car::insertData(const string &brand, const string &model, const string &type, const string &year, const string &km, const string &hp, const string &fuel, const string &shift, const string &bodyType, const string &color, const string &usage, float price, const string &weight, const string &isDamaged)
{

    sqlite3 *DB;
    char *messageError;

    string sql("INSERT INTO CAR (USERNAME, USERTYPE, BRAND, MODEL, TYPE, YEAR, KM, HP, FUEL, SHIFT, BODYTYPE, COLOR, USAGE, PRICE, WEIGHT, ISDAMAGED) VALUES('" + Users::getuserNameBuff() + "', '" + Users::getuserTypeBuff() + "', '" + brand + "', '" + model + "', '" + type + "', '" + year + "', '" + km + "', '" + hp + "', '" + fuel + "', '" + shift + "', '"+bodyType+"', '" + color + "', '" + usage + "', '" + std::to_string(price) + "', '" + weight + "', '" + isDamaged + "');");

    int exit = sqlite3_open("VehicleManagement.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error !!!" << endl;
        sqlite3_free(messageError);
    }
    //else
    //cout << "Records inserted Successfully!" << endl;
}

void Car::createTable()
{
    sqlite3 *DB;
    char *messageError;

    string sql = "CREATE TABLE IF NOT EXISTS CAR("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "USERNAME TEXT NOT NULL, "
                 "USERTYPE      TEXT NOT NULL, "
                 "BRAND      TEXT NOT NULL, "
                 "MODEL      TEXT NOT NULL, "
                 "TYPE      TEXT NOT NULL, "
                 "YEAR      DOUBLE NOT NULL, "
                 "KM      DOUBLE NOT NULL, "
                 "HP      DOUBLE NOT NULL, "
                 "FUEL      TEXT NOT NULL, "
                 "SHIFT      TEXT NOT NULL, "
                 "BODYTYPE      TEXT NOT NULL, "
                 "COLOR      TEXT NOT NULL, "
                 "USAGE      TEXT NOT NULL, "
                 "PRICE      DOUBLE NOT NULL, "
                 "WEIGHT      DOUBLE NOT NULL, "
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
            //cout << "Table created Successfully" << endl;
            sqlite3_close(DB);
    }
    catch (const exception &e)
    {
        cerr << e.what();
    }
}

