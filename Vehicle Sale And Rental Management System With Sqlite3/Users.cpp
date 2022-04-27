#include <iostream>
#include <string>
#include "Users.h"
#include "Address.h"

string Users::userNameBuff = "";
string Users::userTypeBuff = "";

Users::Users()
{
    //    cout << "users ctor" << endl;
}
Users::~Users()
{
    //cout << "users destruc" << endl;
}

string Users::getName()
{
    return name;
}

void Users::setUserName(string userName)
{
    this->userName = userName;
}

string Users::getUserName()
{
    return userName;
}

void Users::setSurName(string surName)
{
    this->surName = surName;
}

void Users::setName(string name)
{
    this->name = name;
}
string Users::getPhone()
{
    return phone;
}

void Users::setPhone(string phone)
{
    this->phone = phone;
}
string Users::getType()
{
    return type;
}

void Users::setType(string type)
{
    this->type = type;
}
string Users::getPassword()
{
    return passw;
}

void Users::setPassword(string passw)
{
    this->passw = passw;
}

double Users::getWallet()
{
    return wallet;
}

void Users::setWallet(double wallet)
{
    this->wallet = wallet;
}

Address Users::getUserAddress()
{
    return userAddress;
}
void Users::setUserAddress(string city, string country, string district, string zipCode, string buildingNumber, string doorNumber)
{
   // userAddress = Address(city, country, district, zipCode, buildingNumber, doorNumber);
}

void Users::signUp()
{
}

void Users::createTable()
{
}

void Users::insertData()
{
}
