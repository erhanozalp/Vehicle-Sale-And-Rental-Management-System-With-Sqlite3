#ifndef _LESSOR_H_
#define _LESSOR_H_
#include "Seller.h"
#include "Address.h"

class Lessor : public Seller
{
private:
protected:
    void createTable();
    
    
public:
    Lessor();
    ~Lessor();

    virtual void signIn() override;
    virtual void panel() override;
    void addAd() ;
    void seeLessorAds();

    
};

#endif