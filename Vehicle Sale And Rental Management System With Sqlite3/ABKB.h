#ifndef _ABKB_H_
#define _ABKB_H_
#include <iostream>
#include "Users.h"
#include "Admin.h"
#include "Seller.h"
#include "Lessor.h"
#include "Client.h"
#include "motorcycle.h"
#include "Vessels.h"
#include "sqlite3.h"

using namespace std;

void login(Users &);

void mainMenu();

void createDB();

#endif