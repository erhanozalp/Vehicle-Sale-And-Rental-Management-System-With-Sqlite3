#include "ABKB.h"
#include <limits>
#include <ctype.h>
#include <string>
using namespace std;

void login(Users &u)
{
    u.signIn();
}

void mainMenu()
{
    int choice, selection;
    try
    {

        cout << "\n*******************************************" << endl;
        cout << "WELCOME TO THE CAR RENTAL MANAGEMENT SYSTEM" << endl;
        cout << "*******************************************" << endl;
        cout << "1-Sign In \n2-Sign Up\n3-Exit" << endl;
        cout << "Your choice:";
        //cin.clear();
        //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //cin.ignore();
        Users::cinError();
        cin >> choice;
        if (choice != 1 && choice != 2 && choice != 3)
        {
            throw 1;
        }
        Admin d;
        Seller s;
        Lessor l;
        Client c;
        if (choice == 1)
        {
            while (1)
            {
                cout << "\n---------------------------------------------" << endl;
                cout << "            USER SIGN IN" << endl;
                cout << "---------------------------------------------" << endl;
                cout << "1.Admin Login\n2.Seller Login\n3.Lessor Login\n4.Client Login\n5-Go Back to Menu\n6.Exit\nYour choice:";
                Users::cinError();
                cin >> selection;
                if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
                {
                    throw 1;
                }

                if (selection == 1)
                {
                    Users::setuserTypeBuff("SELLER");
                    login(d);
                    d.panel();
                }
                else if (selection == 2)
                {
                    Users::setuserTypeBuff("SELLER");
                    login(s);
                    s.panel();
                }
                else if (selection == 3)
                {
                    Users::setuserTypeBuff("LESSOR");
                    login(l);
                    l.panel();
                }
                else if (selection == 4)
                {

                    login(c);
                    c.panel();
                }
                else if (selection == 5)
                {
                    mainMenu();
                }
                else if (selection == 6)
                {
                    exit(1);
                }
                else
                {
                    cout << "Invalid input. Please try again!" << endl;
                }
            }
        }
        else if (choice == 2)
        {
            while (1)
            {
                int select;
                cout << "\n---------------------------------------------" << endl;
                cout << "            USER SIGN UP" << endl;
                cout << "---------------------------------------------" << endl;
                cout << "1- Sign up as Seller\n2- Sign up as a Lessor\n3- Sign up as a Client\n4- Go Back to Menu\nYour choice:";
                Users::cinError();
                cin >> select;
                if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
                {
                    throw 1;
                }

                else if (select == 1)
                {

                    s.signUp("SELLER");
                }
                else if (select == 2)
                {

                    l.signUp("LESSOR");
                }
                else if (select == 3)
                {

                    c.signUp("CLIENT");
                }
                else if (select == 4)
                {
                    mainMenu();
                }
                else
                {
                    cout << "Invalid input please try again!" << endl;
                    mainMenu();
                }
            }
        }
        else if (choice == 3)
        {
            exit(1);
        }
        // else
        // {
        //     cout << "Invalid input please try again!" << endl;
        //     //mainMenu();
        // }
    }
    catch (int &ex)
    {
        cerr << "Invalid value. Please try again!!" << endl;
    }
}

void createDB()
{
    sqlite3 *DB;

    int exit = 0;
    exit = sqlite3_open("VehicleManagement.db", &DB);

    sqlite3_close(DB);
}
