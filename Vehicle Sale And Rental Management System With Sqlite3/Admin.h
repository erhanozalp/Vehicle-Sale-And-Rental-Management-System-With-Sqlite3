#ifndef _ADMIN_H_
#define _ADMIN_H_
#include "Users.h"
#include <string>
#include <vector>
#include "Ad.h"

using namespace std;

class Admin : public Users
{
private:
    Vehicle v;

protected:
    void createTable();
    // buraya yazılacak denemek için publice yazdık void insertData(string, string);
    void deleteDatabase(string);

public:
    static string buff;

    static int WalletBuff;
    static int carPriceBuff;
    static int carOwnerWalletBuff;

    static int GetcarPriceBuff()
    {
        return carPriceBuff;
    }

    static void SetcarPriceBuff(int _buff)
    {
        carPriceBuff = _buff;
    }

    static int GetcarOwnerWalletBuff()
    {
        return carOwnerWalletBuff;
    }

    static void SetcarOwnerWalletBuff(int _buff)
    {
        carOwnerWalletBuff = _buff;
    }

    Admin();
    ~Admin();
    virtual void addUsers();
    virtual void signIn() override;
    void deleteUsers();
    // virtual void addAd();
    void updateAd();

    static int getWalletBuff()
    {
        return WalletBuff;
    }
    static void setWalletBuff(int _buff)
    {
        WalletBuff = _buff;
    }

    static string getBuff()
    {
        return buff;
    }
    static void setBuff(string _buff)
    {
        buff = _buff;
    }

    /*
    void delete();
    */
    void insertData(string, string);
    void checkUserInformation();
    void selectUserData(string, string);
    void seeAds(string);
    // void selectAdminData(string username);
    virtual void panel();
    void selectData(string);
    void isExist(string, string) override;
    void selectionDeleteVehicle();
};

#endif