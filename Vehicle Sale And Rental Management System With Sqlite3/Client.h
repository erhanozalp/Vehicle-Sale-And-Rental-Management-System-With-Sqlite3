#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "Users.h"
#include "Seller.h"
#include <string>
#include "Address.h"

using namespace std;

class Client : public Seller
{
private:
    Vehicle *c = new Vehicle;

protected:
    void createTable();

public:
    Client();
    ~Client();
    virtual void signIn() override;
    void panel();
    void seeAds(string,string);
    
};

#endif