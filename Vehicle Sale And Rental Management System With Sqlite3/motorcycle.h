#ifndef _MOTORCYCLE_H_
#define _MOTORCYCLE_H_
#include <string>
#include "car.h"
using namespace std;

class Motorcycle : public Car
{
private:
    int numberOfWheels;

public:
    Motorcycle();
    ~Motorcycle();
    void createTable();
    void insertData(const string&, const string&, const string&, const string&, const string&, const string&, const string&, const string&, const string&, const string&, float, const string&, const string&);
    void selectData(string);
    void deleteDatabase(string);
};
#endif
