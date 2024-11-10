#pragma once
#include <iostream>
#include <iomanip>
#include "clsAdminSchoolSystem.h"
#include "clsScreen.h"
using namespace std;
class clsListUserScreen: protected clsScreen
{
private:

    static void _PrintUserRecordLine(clsAdminSchoolSystem &User)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << User.GetUserName();
        cout << "| " << setw(20) << left << User.FullName();
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Password;
        cout << "| " << setw(10) << left << User.Permessions;

    }

public:

    static void ShowScreenList()
    {
       if (!CheckAccessRight(clsAdminSchoolSystem::eShowLists))
        {
            return;
        }
        vector <clsAdminSchoolSystem> _vUser = clsAdminSchoolSystem::LoadDataFromFile();

        string titel = "           Users Screen List";
        string SubTitle = "           (" + to_string(_vUser.size()) + ") Users(s).";
        _DrawScreenForSystem(titel, SubTitle);
        _Getusername(Users.GetUserName());
        cout << setw(8) << left << "" << "\n\t_________________________________________";
        cout << "___________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "UserName";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(10) << "Permession";
        cout << setw(8) << left << "" << "\n\t_________________________________________";
        cout << "___________________________________________________________\n" << endl;

        if (_vUser.size() == 0)
        {
            cout << "\nThere no users on the system!";
        }
        else
        {
            for (clsAdminSchoolSystem& U : _vUser)
            {
                _PrintUserRecordLine(U);
                cout << endl;
            }
        }
        cout << setw(8) << left << "" << "\n\t_________________________________________";
        cout << "___________________________________________________________\n" << endl;
    }
};

