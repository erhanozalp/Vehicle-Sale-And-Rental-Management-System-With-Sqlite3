#ifndef _ADDRESS_H_
#define _ADDRESS_H_
#include <string>

using namespace std;

class Address
{
private:
    string city;
    string country;
    string district;
    string zipCode;
    string buildingNumber;
    string doorNumber;

protected:
    void createTable();

public:
    Address();
    ~Address();

    void GetAddress(string);

    void setCity(string);
    string getCity();

    void setCountry(string);
    string getCountry();

    void setDistrict(string);
    string getDistrict();

    void setZipCode(string);
    string getZipCode();

    void setBuildingNumber(string);
    string getBuildingNumber();

    void setDoorNumber(string);
    string getDoorNumber();

    void selectData();
    void deleteDatabase();

    void updateData(const string &, const string &);
    void insertData(const string &, const string &, const string &, const string &, const string &, const string &, const string &);
};

#endif