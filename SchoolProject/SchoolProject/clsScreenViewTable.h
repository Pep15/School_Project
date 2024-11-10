#pragma once
#include <iostream>
#include <iomanip>
#include "clsSchoolSystem.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsScreenViewTable : protected clsScreen
{
private:

	static void _PrintCardTeacher(clsSchoolSystem &Teacher)
	{
        cout << setw(8) << left << "" << "| " << setw(12) << left << Teacher.IDTEACHERS();
        cout << "| " << setw(18) << left << Teacher.FullName();
        cout << "| " << setw(10) << left << Teacher.Phone;
        cout << "| " << setw(19) << left << Teacher.AnotherNumber;
        cout << "| " << setw(18) << left << Teacher.Email;
        cout << "| " << setw(15) << left << Teacher.Address1;
        cout << "| " << setw(15) << left << Teacher.Address2;
        cout << "| " << setw(12) << left << Teacher.NumberOfHouse;

	}

public:

    static void ShowScreenTeachers()
    {
        if (!CheckAccessRight(clsAdminSchoolSystem::eShowLists))
        {
            return;
        }
        vector <clsSchoolSystem> vTeacher = clsSchoolSystem::GetLoadNumberOfTeachers();

        string Title = "          Screen List Teachers";
        string SubTitle = "         (" + to_string(vTeacher.size()) + ") Teacher(s).\n";
        _DrawScreenForSystem(Title, SubTitle);
        _Getusername(Users.GetUserName());
        cout << setw(8) << left << "" << "\n\t_______________________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "ID TEACHER";
        cout << "| " << left << setw(18) << "Full Name";
        cout << "| " << left << setw(10) << "Phone";
        cout << "| " << left << setw(19) << "AnotherNumber";
        cout << "| " << left << setw(18)  << "Email";
        cout << "| " << left << setw(15) << "Address1";
        cout << "| " << left << setw(15) << "Address2";
        cout << "| " << left << setw(12) << "NumberOfHouse";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;

        if (vTeacher.size() == 0)
            cout << "\t\t\t\tThere are no Teacher on system!";
        else
        {
            for (clsSchoolSystem T : vTeacher)
            {
                _PrintCardTeacher(T);
                cout << endl;
            }
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________________________";
        cout << "_________________________________________________________________\n" << endl;
    }
};

