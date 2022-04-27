/*
Developers: Team 16
1-Erhan ÖZALP 201911047
2-Yunus Emre GÖRGÜ 201911202
3-Ahmet Vedat UYGUN 201911065 
*/

#include <iostream>
#include "ABKB.h"
#include "sqlite3.h"
#include "Admin.h"
using namespace std;

int main(int argc, char const *argv[])
{
    sqlite3 *DB;

    int exit = 0;
    exit = sqlite3_open("VehicleManagement.db", &DB);
    sqlite3_close(DB);

        while (1)
    {
        mainMenu();
    }

    return 0;
}
