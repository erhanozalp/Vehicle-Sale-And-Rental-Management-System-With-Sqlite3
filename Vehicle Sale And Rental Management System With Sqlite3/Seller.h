#ifndef _SELLER_H
#define _SELLER_H
#include "Admin.h"
#include "Address.h"

class Seller : public Admin
{
private:
protected:
    void createTable();
    
    //Address
public:
    Seller();
    ~Seller();
    //denemek amaçlı publice aldık protected olacak burası yani aşağıdaki kod parçası
    void insertData(const string&, const string&, const string&, const string&, const string&, const string&, double);
    virtual void panel() override;
    //virtual void addAd();
    virtual void signIn() override;
    void signUp(string);
    virtual void addAd();
    void addRentingAd();
    virtual void updateAddress();
};

#endif