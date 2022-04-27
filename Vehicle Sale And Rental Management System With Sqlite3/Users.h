#ifndef _USER_H_
#define _USER_H_
#include <iostream>
#include <string>
#include "Address.h"
#include <limits>

using namespace std;

class Users
{
private:
protected:
    string name, surName, phone, type, passw, userName;

    double wallet;

    static string userNameBuff;
    static string userTypeBuff;

    Address userAddress;

protected:
    void createTable();

public:
    Users();
    ~Users();

    string getName();
    void setName(string);

    string getSurName();
    void setSurName(string);

    string getUserName();
    void setUserName(string);

    string getPhone();
    void setPhone(string);

    string getType();
    void setType(string);

    string getPassword();
    void setPassword(string);

    double getWallet();
    void setWallet(double);

    Address getUserAddress();
    void setUserAddress(string, string, string, string, string, string);

    virtual void signUp();
    virtual void signIn() = 0;
    void insertData();
    virtual void isExist(string, string) = 0;

    static void cinError()
    {
        if (cin.fail())
        {

            cin.clear();

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    static string getuserNameBuff()
    {
        return userNameBuff;
    }
    static void setuserNameBuff(string _buff)
    {
        userNameBuff = _buff;
    }

    static string getuserTypeBuff()
    {
        return userTypeBuff;
    }
    static void setuserTypeBuff(string _buff)
    {
        userTypeBuff = _buff;
    }
};

#endif