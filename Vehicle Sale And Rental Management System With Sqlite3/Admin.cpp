#include <iostream>
#include "Admin.h"
#include <string>
#include "sqlite3.h"
#include "Users.h"

string Admin::buff = "";
int Admin::WalletBuff = 0;
int Admin::carPriceBuff = 0;
int Admin::carOwnerWalletBuff = 0;
Admin::Admin()
{

    createTable();
    isExist("erhan", "ADMIN");
    if (Admin::getBuff() != "erhan")
    {
        insertData("erhan", "123e");
    }
    isExist("vedat", "ADMIN");
    if (Admin::getBuff() != "vedat")
    {
        insertData("vedat", "123v");
    }
}

Admin::~Admin() {}

void Admin::addUsers()
{
    string uAdmin, pAdmin;
    cout << "\nEnter username that will be added: ";
    getline(cin >> ws, uAdmin);
    cout << "Enter Password: ";
    getline(cin >> ws, pAdmin);
    isExist(uAdmin, "ADMIN");
    if (Admin::getBuff() != uAdmin)
    {
        insertData(uAdmin, pAdmin);
    }
    else
    {
        cout << "This username has taken!!!" << endl;
        addUsers();
    }
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    if (argc == 1)
    {
        Admin::setBuff(*argv);
        return 0;
    }

    for (int i = 0; i < argc; i++)
    {

        //column name and value
        cout << azColName[i] << ":" << argv[i] << "\t";
    }
    cout << "\n"
         << endl;
    return 0;
}

void Admin::selectUserData(string username, string typeName)
{
    sqlite3 *DB;
    char *messageError;

    string sql = "SELECT PASSWORD FROM '" + typeName + "' WHERE  USERNAME = '" + username + "';";

    int exit = sqlite3_open("VehicleManagement.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

    if (exit != SQLITE_OK)
    {
        cerr << "Error !!!" << endl;
        sqlite3_free(messageError);
    }
    
}

void Admin::isExist(string username, string tableName)
{
    sqlite3 *DB;
    char *messageError;

    string sql = "SELECT USERNAME FROM " + tableName + " WHERE  USERNAME = '" + username + "';";

    int exit = sqlite3_open("VehicleManagement.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

    if (exit != SQLITE_OK)
    {
        cerr << "Error !!!" << endl;
        sqlite3_free(messageError);
    }
    
}

// retrieve contents of database used by selectData()
/* argc: holds the number of results, argv: holds each value in array, azColName: holds each column returned in array, */

void Admin::signIn()
{
    int checkCounter{3};
    while (checkCounter > 0)
    {
        string username, password, bufftwo;
        cout << "\nEnter admin username: ";
        cin >> username;

        cout << "Enter suitable password for the user " << username << ": ";
        cin >> password;
        //cout << "Remaining attempt: " << checkCounter << endl;

        selectUserData(username, "ADMIN");
        Users::setuserNameBuff(username);
        bufftwo = getBuff();
        if (password == bufftwo)
        {

            cout << "\nAccess Granted!\nWelcome Admin " << username << endl;
            break;
        }
        else
        {
            cout << "Invalid username or password. Please try again!" << endl;
            checkCounter--;
            cout << "Remaining attempt: " << checkCounter << endl;

            if (checkCounter == 0)
            {
                cout << "\nProgram terminating due to 3 invalid attempt!" << endl;
                exit(1);
            }
        }
    }
}

void Admin::deleteUsers()
{
    //Select * from all user information to here. List them and their ilans. And admin can delete any user he wants or banned them.
    while (1)
    {
        cout << "\n---------------------------------------------" << endl;
        cout << "                 USER TYPE" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "1-Admins\n2-Sellers\n3-Lessors\n4-Clients" << endl;
        cout << "Your choice:";
        int choice;
        Users::cinError();
        cin >> choice;
        string admin = "ADMIN";
        string seller = "SELLER";
        string lessor = "LESSOR";
        string client = "CLIENT";

        if (choice == 1)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "                ADMINS" << endl;
            cout << "---------------------------------------------" << endl;
            selectData(admin);
            deleteDatabase(admin);
            break;
        }
        else if (choice == 2)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "                SELLERS" << endl;
            cout << "---------------------------------------------" << endl;
            selectData(seller);
            deleteDatabase(seller);
            break;
        }
        else if (choice == 3)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "                LESSORS" << endl;
            cout << "---------------------------------------------" << endl;
            selectData(lessor);
            deleteDatabase(lessor);
            break;
        }
        else if (choice == 4)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "                CLIENTS" << endl;
            cout << "---------------------------------------------" << endl;
            selectData(client);
            deleteDatabase(client);
            break;
        }
        else
        {
            cout << "Invalid input. Please try again!" << endl;
        }
    }
}
void Admin::deleteDatabase(string tableName)
{
    cout << "\nPlease Enter The Username To Delete: ";
    string deletename;
    cin >> deletename;

    sqlite3 *DB;
    char *messageError;

    string sql = "DELETE FROM " + tableName + " WHERE USERNAME = '" + deletename + "';";

    int exit = sqlite3_open("VehicleManagement.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error !!!" << endl;
        sqlite3_free(messageError);
    }
    else
    {
        //cout << "User Deleted Successfully!" << endl;
    }
}

void Admin::checkUserInformation()
{
    //Select * from all user information to here. List them and their ilans.
    int choice;
    while (1)
    {
        cout << "\n---------------------------------------------" << endl;
        cout << "                  USER TYPE" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "1-Admins\n2-Sellers\n3-Lessors\n4-Clients\n5-Go back to admin panel" << endl;
        cout << "Your choice:";
        Users::cinError();
        cin >> choice;
        string admin = "ADMIN";
        string seller = "SELLER";
        string lessor = "LESSOR";
        string client = "CLIENT";

        if (choice == 1)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "            ADMINS" << endl;
            cout << "---------------------------------------------" << endl;
            selectData(admin);
        }
        else if (choice == 2)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "            SELLERS" << endl;
            cout << "---------------------------------------------" << endl;
            selectData(seller);
        }
        else if (choice == 3)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "            LESSORS" << endl;
            cout << "---------------------------------------------" << endl;
            selectData(lessor);
        }
        else if (choice == 4)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "            CLIENTS" << endl;
            cout << "---------------------------------------------" << endl;
            selectData(client);
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid input. Please try again!" << endl;
        }
    }
}

void Admin::createTable()
{
    sqlite3 *DB;
    char *messageError;

    string sql = "CREATE TABLE IF NOT EXISTS ADMIN("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "USERNAME      TEXT NOT NULL, "
                 "PASSWORD     TEXT NOT NULL);";
    try
    {
        int exit = 0;
        exit = sqlite3_open("VehicleManagement.db", &DB);
        /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
        exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
        if (exit != SQLITE_OK)
        {
            cerr << "Error !!!" << endl;
            sqlite3_free(messageError);
        }
        else
            //cout << "Table created Successfully" << endl;
            sqlite3_close(DB);
    }
    catch (const exception &e)
    {
        cerr << e.what();
    }
}

void Admin::insertData(string username, string password)
{

    sqlite3 *DB;
    char *messageError;

    string sql("INSERT INTO ADMIN (USERNAME, PASSWORD) VALUES('" + username + "', '" + password + "');");

    int exit = sqlite3_open("VehicleManagement.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
    if (exit != SQLITE_OK)
    {
        cerr << "Error !!!" << endl;
        sqlite3_free(messageError);
    }
    
}
void Admin::selectData(string tableName)
{
    sqlite3 *DB;
    char *messageError;

    string sql = "SELECT * FROM " + tableName + ";";

    int exit = sqlite3_open("VehicleManagement.db", &DB);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here*/
    exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messageError);

    if (exit != SQLITE_OK)
    {
        cerr << "Error !!!" << endl;
        sqlite3_free(messageError);
    }
    
}
void Admin::selectionDeleteVehicle()
{
    int type;
    bool a = true;

    while (a)
    {
        cout << "\n---------------------------------------------" << endl;
        cout << "               VEHICLE TYPE" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "1-Cars\n2-Motorcycles\n3-Vessels\n4-Go Back" << endl;
        cout << "Select vehicle type:";
        Users::cinError();
        cin >> type;

        if (type == 1)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "                   CARS" << endl;
            cout << "---------------------------------------------" << endl;
            string x = "CAR";
            selectData(x);
            cout << "Enter id: ";
            int id;
            cin >> id;
            v.deleteData(x, id);
        }
        else if (type == 2)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "                   MOTORCYCLE" << endl;
            cout << "---------------------------------------------" << endl;
            string x = "MOTORCYCLE";
            selectData(x);
            cout << "Enter id: ";
            int id;
            cin >> id;
            v.deleteData(x, id);
        }
        else if (type == 3)
        {
            cout << "\n---------------------------------------------" << endl;
            cout << "                    VESSELS" << endl;
            cout << "---------------------------------------------" << endl;
            string x = "VESSEL";
            selectData(x);
            cout << "Enter id: ";
            int id;
            cin >> id;
            v.deleteData(x, id);
        }
        else if (type == 4)
        {

            break;
        }
        else
        {

            cout << "Invalid input! Please try again.";
        }
    }
}

void Admin::updateAd()
{

    Ad see;
    see.updateAd("F");
}

void Admin::panel()
{
    bool a = true;

    while (a)
    {
        try
        {

            int choice;

            cout << "\n---------------------------------------------" << endl;
            cout << "            ADMIN PANEL" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "1-Add new admin users\n2-Check User information\n3-Delete users\n4-Delete ad\n5-Update ad\n6-Log out\nYour choice:";
            Users::cinError();
            cin >> choice;
            if (isdigit(choice) == true)
            {
                throw 1;
            }

            else if (choice == 1)
            {
                addUsers();
            }
            else if (choice == 2)
            {
                checkUserInformation();
            }
            else if (choice == 3)
            {
                deleteUsers();
            }
            else if (choice == 4)
            {
                selectionDeleteVehicle();
            }
            else if (choice == 5)
            {
                updateAd();
            }
            else if (choice == 6)
            {
                a = false;
            }
            else
            {
                cout << "You have inputted an invalid value. Please try again!" << endl;
            }
        }
        catch (int &ex)
        {
            cerr << "You have to input an numeric value. Please try again!" << endl;
        }
    }
}
