#include <iostream>
#include <string>
#include "Ad.h"
#include "sqlite3.h"
#include "car.h"
#include "motorcycle.h"
#include "Vessels.h"
#include "vehicle.h"
#include "Users.h"
using namespace std;

Ad::Ad()
{
}

Ad::~Ad() { delete v; }

void Ad::addCar(string type)
{
    try
    {
        Car c;
        string model, category, shift, isDamaged, bodyType, brand, usage, color, fuel;
        string year, hp;
        string km, weight;
        double price, dailyPrice;

        cout << "Enter Brand: ";
        getline(cin >> ws, brand);
        cout << "Enter Model: ";
        getline(cin >> ws, model);
        cout << "Enter Year: ";
        cin >> year;
        cout << "Enter Km: ";
        cin >> km;
        cout << "Enter Hp: ";
        cin >> hp;
        cout << "Enter Fuel: ";
        getline(cin >> ws, fuel);
        cout << "Enter Shift: ";
        getline(cin >> ws, shift);
        cout << "Enter Body Type: ";
        getline(cin >> ws, bodyType);
        cout << "Enter Color: ";
        getline(cin >> ws, color);
        cout << "Enter From: ";
        getline(cin >> ws, usage);
        if (type == "lessor")
        {
            cout << "Enter Daily Price:";
            Users::cinError();
            cin >> dailyPrice;
            if (dailyPrice < 0)
            {
                throw 1;
            }
        }
        else
        {
            cout << "Enter Price: ";
            Users::cinError();
            cin >> price;
            if (price < 0)
            {
                throw 'a';
            }
        }
        cout << "Enter Weight: ";
        cin >> weight;
        cout << "Enter is damage or not: ";
        getline(cin >> ws, isDamaged);

        if(isDamaged.size() != 0){
            if (type == "lessor")
            {
                c.insertData(brand, model, "CAR", year, km, hp, fuel, shift, bodyType, color, usage, dailyPrice, weight, isDamaged);
            }
            else
            {
                c.insertData(brand, model, "CAR", year, km, hp, fuel, shift, bodyType, color, usage, price, weight, isDamaged);
            }    
        }

    }
    catch (int &ex)
    {
        cerr << "Daily price can not be below zero! Please try to add the vessel again." << endl;
    }
    catch (char &ex)
    {
        cerr << "Price can not be below zero! Please try to add the vessel again." << endl;
    }
}

void Ad::addMotor(string type)
{
    try
    {
        string model, shift, isDamaged, brand, usage, color;
        string year, hp, numberOfWheels;
        string km, weight;
        double price, dailyPrice;
        Motorcycle m;
        cout << "Enter Brand: ";
        getline(cin >> ws, brand);
        cout << "Enter Model: ";
        getline(cin >> ws, model);
        cout << "Enter Year: ";
        cin >> year;
        cout << "Enter Km: ";
        cin >> km;
        cout << "Enter Hp: ";
        cin >> hp;
        cout << "Enter Shift: ";
        getline(cin >> ws, shift);
        cout << "Enter Number of Wheels: ";
        cin >> numberOfWheels;
        cout << "Enter Color: ";
        getline(cin >> ws, color);
        cout << "Enter From: ";
        getline(cin >> ws, usage);
        if (type == "lessor")
        {
            cout << "Enter Daily Price:";
            Users::cinError();
            cin >> dailyPrice;
            if (dailyPrice < 0)
            {
                throw 1;
            }
        }
        else
        {
            cout << "Enter Price: ";
            Users::cinError();
            cin >> price;
            if (price < 0)
            {
                throw 's';
            }
        }
        cout << "Enter Weight: ";
        cin >> weight;
        cout << "Enter is damage or not: ";
        getline(cin >> ws, isDamaged);

        if(isDamaged.size() != 0){
            if (type == "lessor")
            {
                m.insertData(brand, model, "MOTORCYCLE", year, km, hp, shift, numberOfWheels, color, usage, dailyPrice, weight, isDamaged);
            }
            else
            {
                m.insertData(brand, model, "MOTORCYCLE", year, km, hp, shift, numberOfWheels, color, usage, price, weight, isDamaged);
            }
        }
        
    }
    catch (int &ex)
    {
        cerr << "Daily price can not be below zero! Please try to add the vessel again." << endl;
    }
    catch (char &ex)
    {
        cerr << "Price can not be below zero! Please try to add the vessel again." << endl;
    }
}

void Ad::addVessels(string type)
{
    try
    {
        string isDamaged, brand, usage, color;
        string motorAmount, kamara, bedNumber, totalActiveHour;
        double price, dailyPrice;
        string height, width;
        Vessels v;
        cout << "Enter Brand: ";
        getline(cin >> ws, brand);
        cout << "Enter Motor Amount: ";
        cin >> motorAmount;
        cout << "Enter Kamara: ";
        cin >> kamara;
        cout << "Enter Number of Beds: ";
        cin >> bedNumber;
        cout << "Enter Total Active Hour: ";
        cin >> totalActiveHour;
        cout << "Enter Height: ";
        cin >> height;
        cout << "Enter Width: ";
        cin >> width;
        cout << "Enter Color: ";
        getline(cin >> ws, color);
        cout << "Enter From: ";
        getline(cin >> ws, usage);
        if (type == "lessor")
        {
            cout << "Enter Daily Price:";
            Users::cinError();
            cin >> dailyPrice;
            if (dailyPrice < 0)
            {
                throw 1;
            }
        }
        else
        {
            cout << "Enter Price: ";
            Users::cinError();
            cin >> price;
            if (price < 0)
            {
                throw 'a';
            }
        }
        cout << "Enter is damage or not: ";
        getline(cin >> ws, isDamaged);
        
        if(isDamaged.size() != 0){
            if (type == "lessor")
            {
                v.insertData(brand, motorAmount, kamara, "VESSEL", bedNumber, totalActiveHour, height, width, color, usage, dailyPrice, isDamaged);
            }
            else
            {
                v.insertData(brand, motorAmount, kamara, "VESSEL", bedNumber, totalActiveHour, height, width, color, usage, price, isDamaged);
            }
        }
      
    }
    catch (int &ex)
    {
        cerr << "Daily price can not be below zero! Please try to add the vessel again." << endl;
    }
    catch (char &ex)
    {
        cerr << "Price can not be below zero! Please try to add the vessel again." << endl;
    }
}

void Ad::addAd(string typee)
{
    int type;
    bool a = true;

    while (a)
    {
        cout << "\n---------------------------------------------" << endl;
        cout << "               VEHICLE TYPE" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "1-Car\n2-Motorcycle\n3-Vessel\n4-Go back to " << typee << " menu\nYour choice: ";
        Users::cinError();
        cin >> type;

        if (type == 1)
        {
            addCar("erhan");
        }
        else if (type == 2)
        {
            addMotor("erhan");
        }
        else if (type == 3)
        {
            addVessels("erhan");
        }
        else if (type == 4)
        {
            a = false;
        }
        else
        {
            cout << "You have input an invalid value. Please try again!" << endl;
        }
    }
}

void Ad::addLessorAd()
{
    int type;
    bool a = true;

    while (a)
    {
        cout << "\n---------------------------------------------" << endl;
        cout << "               VEHICLE TYPE" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "1-Car\n2-Motorcycle\n3-Vessel\n4-Go back to menu\nYour choice:" << endl;
        Users::cinError();
        cin >> type;
        cout << "\n"
             << endl;

        if (type == 1)
        {
            addCar("lessor");
        }
        else if (type == 2)
        {
            addMotor("lessor");
        }
        else if (type == 3)
        {
            addVessels("lessor");
        }
        else if (type == 4)
        {
            a = false;
        }
        else
        {
            cout << "You have input an invalid value. Please try again!" << endl;
        }
    }
}

void Ad::deleteAd(string username)
{
    int type;
    bool a = true;

    while (a)
    {
        cout << "\n---------------------------------------------" << endl;
        cout << "               VEHICLE TYPE" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "\n1-Cars\n2-Motorcycles\n3-Vessels\n4-Go Back" << endl;
        cout << "Select vehicle type:";
        Users::cinError();
        cin >> type;

        if (type == 1)
        {
            string x = "CAR";
            v->deleteSelection(x);
        }
        else if (type == 2)
        {
            string x = "MOTORCYCLE";
            v->deleteSelection(x);
        }
        else if (type == 3)
        {
            string x = "VESSEL";
            v->deleteSelection(x);
        }
        else if (type == 4)
        {

            break;
        }
        else
        {

            cout << "Invalid input! Please try again.";
        }
    }
}

void Ad::updateAd(string username)
{
    int type;
    bool a = true;

    while (a)
    {
        cout << "\n---------------------------------------------" << endl;
        cout << "               VEHICLE TYPE" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "\n1-Cars\n2-Motorcycles\n3-Vessels\n4-Go Back" << endl;
        cout << "Select vehicle type:";
        Users::cinError();
        cin >> type;

        if (type == 1)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "                   CARS" << endl;
            cout << "---------------------------------------------" << endl;
            string x = "CAR";
            v->updateSelections(x, username);
        }
        else if (type == 2)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "                   MOTORCYCLE" << endl;
            cout << "---------------------------------------------" << endl;
            string x = "MOTORCYCLE";
            v->updateSelections(x, username);
        }
        else if (type == 3)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "                    VESSELS" << endl;
            cout << "---------------------------------------------" << endl;
            string x = "VESSEL";
            v->updateSelections(x, username);
        }
        else if (type == 4)
        {
            a = false;
        }
        else
        {
            cout << "Invalid input! Please try again.";
        }
    }
}

void Ad::seeAds(string username)
{
    int type;
    bool a = true;

    while (a)
    {
        cout << "\n---------------------------------------------" << endl;
        cout << "               VEHICLE TYPE" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "\n1-Cars\n2-Motorcycles\n3-Vessels\n4-Go Back" << endl;
        cout << "Select vehicle type:";
        Users::cinError();
        cin >> type;

        if (type == 1)
        {
            string x = "CAR";
            cout << "\n---------------------------------------------" << endl;
            cout << "                   CARS" << endl;
            cout << "---------------------------------------------" << endl;
            v->selectData(x, username);
        }
        else if (type == 2)
        {
            string x = "MOTORCYCLE";
            cout << "\n---------------------------------------------" << endl;
            cout << "                   MOTORCYCLE" << endl;
            cout << "---------------------------------------------" << endl;
            v->selectData(x, username);
        }
        else if (type == 3)
        {
            string x = "VESSEL";
            cout << "\n---------------------------------------------" << endl;
            cout << "                    VESSELS" << endl;
            cout << "---------------------------------------------" << endl;
            v->selectData(x, username);
        }
        else if (type == 4)
        {

            break;
        }
        else
        {

            cout << "Invalid input! Please try again.";
        }
    }
}
