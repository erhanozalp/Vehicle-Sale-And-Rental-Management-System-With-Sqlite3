#ifndef _VEHICLE_H_
#define _VEHICLE_H_
#include <string>

using namespace std;

class Vehicle
{
private:
protected:
    string type;
    double price;
    string brand;
    string usage;
    string color;
    string fuel;

public:
    Vehicle();
    ~Vehicle();
    string getType();
    void setType(string);
    double getPrice();
    void setPrice(double);
    string getBrand();
    void setBrand(string);
    string getUsage();
    void setUsage(bool);
    string getColor();
    void setColor(string);
    string getFuel();
    void setFuel(string);
    int getCapacity();
    void setCapacity(int);
    void selectData(const string &, const string &);
    void selectWalletFrom(const string &, const string &);
    void updateVehicle(const string &, const int &, const string &, const string &, string);

    void updateSelections(string, string);
    void deleteData(const string &, int);
    void deleteSelection(const string &);
    void buyOrRentSelection(string, string);
    void selectPriceFrom(const string &, const int &);

    void UpdateClientWallet(int);
    void UpdateCarOwnerWallet(string, int, string);
    void selectWalletFromOwner(const string &, const string &);
};

#endif
