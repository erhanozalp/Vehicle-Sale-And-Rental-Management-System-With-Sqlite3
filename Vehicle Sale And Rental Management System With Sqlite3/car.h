#ifndef _CAR_H_
#define _CAR_H_
#include <string>
#include "vehicle.h"
using namespace std;

class Car : public Vehicle
{
private:
protected:
    string model, category, shift;
    int year, hp;
    float km, weight;
    string isDamaged, bodyType;

    void createTable();

public:
    Car();

    string getModel();
    void setModel(string);
    string getCategory();
    void setCategory(string);
    string getShift();
    void setShift(string);

    float getKm();
    void setKm(float);
    float getWeight();
    void setWeight(float);

    int getYear();
    void setYear(int);
    int getHp();
    void setHp(int);

    string getIsDamaged();
    void setIsDamaged(string);
    string getSedanOrHatchbag();
    void setSedanOrHatchbag(string);

    void insertData(const string&, const string&, const string&, const string&, const string&, const string&, const string&, const string&, const string&, const string&, const string&, float, const string&, const string&);
    void selectData();

    ~Car();
};

#endif