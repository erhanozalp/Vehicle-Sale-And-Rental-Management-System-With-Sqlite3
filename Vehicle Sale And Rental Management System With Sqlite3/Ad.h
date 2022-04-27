#include <string>
#include "vehicle.h"
using namespace std;

class Ad
{
private:
    string date;
    string model;
    string type;

    Vehicle *v = new Vehicle;

protected:
public:
    Ad();
    void addAd(string);
    void addCar(string);
    void addMotor(string);
    void addVessels(string);
    ~Ad();

    void addLessorAd();
    void deleteAd(string);
    void updateAd(string);
    void seeAds(string);
};