#ifndef _VESSELS_H_
#define _VESSELS_H_
#include <string>
#include "vehicle.h"
using namespace std;

class Vessels : public Vehicle
{
private:
    int motorAmount, kamara, bedNumber, totalActiveHour;
    float height, width;

public:
    Vessels();
    ~Vessels();
    int getMotorAmount();
    void setMotorAmount(int);
    int getKamara();
    void setKamara(int);
    int getBedNumber();
    void setBedNumber(int);
    int getTotalACtiveHour();
    void setTotalActiveHour(int);
    float getHeight();
    void setHeight(float);
    float getWidth();
    void setWidth(float);
    void createTable();
    void insertData(const string&, const string&, const string&, const string&, const string&, const string&, const string&, const string&, const string&, const string&, float, const string&);
    void selectData(string);
    void deleteDatabase(string);
};

#endif