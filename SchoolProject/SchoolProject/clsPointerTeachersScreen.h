#pragma once
#include <iostream>
#include <iomanip>
#include "clsSchoolSystem.h"
#include "clsScreen.h"
#include "Global.h"
using namespace std;
class clsPointerTeachersScreen : protected clsScreen
{

private:

    static void _PrintCardTeacher()
    {
        cout << setw(8) << left << "" << "| " << setw(12) << left << Teachers.IDTEACHERS();
        cout << "| " << setw(18) << left << Teachers.FullName();
        cout << "| " << setw(10) << left << Teachers.Phone;
        cout << "| " << setw(19) << left << Teachers.AnotherNumber;
        cout << "| " << setw(18) << left << Teachers.Email;
        cout << "| " << setw(15) << left << Teachers.Address1;
        cout << "| " << setw(15) << left << Teachers.Address2;
        cout << "| " << setw(12) << left << Teachers.NumberOfHouse;

    }

public:

    static void ShowScreenTeachers()
    {
        
        
        Teachers.GetLoadNumberOfTeachers();
        string Title = "          Screen List Teachers";
        _DrawScreenForSystem(Title);
        _Getusername(Teachers.IDTEACHERS());
        cout << setw(8) << left << "" << "\n\t_______________________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "ID TEACHER";
        cout << "| " << left << setw(18) << "Full Name";
        cout << "| " << left << setw(10) << "Phone";
        cout << "| " << left << setw(19) << "AnotherNumber";
        cout << "| " << left << setw(18) << "Email";
        cout << "| " << left << setw(15) << "Address1";
        cout << "| " << left << setw(15) << "Address2";
        cout << "| " << left << setw(12) << "NumberOfHouse";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;

        if (Teachers.GetLoadNumberOfTeachers().size() == 0)
            cout << "\t\t\t\tThere are no Teacher on system!";
        else
        {
           
            _PrintCardTeacher();
             cout << endl;
            
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;
    }
};

