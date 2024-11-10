#pragma once
#include "clsStudentSystem.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class eListStudents : protected clsScreen
{

private:

    static void _PrintUserRecordLine(clsStudentSystem& Studentes)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << Studentes.GetIDstudents();
        cout << "| " << setw(20) << left << Studentes.FullName();
        cout << "| " << setw(12) << left << Studentes.Phone;
        cout << "| " << setw(20) << left << Studentes.Email;
        cout << "| " << setw(12) << left << Studentes.Address;
        cout << "| " << setw(20) << left << Studentes.NumberOfHouse;
        cout << "| " << setw(20) << left << Studentes.NumberOfFather;
        cout << "| " << setw(20) << left << Studentes.NumberOfMother;
        cout << "| " << setw(10) << left << Studentes.Age;
        cout << "| " << setw(10) << left << Studentes.Password;
        

    }

public:

    static void ShowScreenListStudnts()
    {
        vector <clsStudentSystem> vStudents = clsStudentSystem::GetLoadDateFromFile();

        string titel = "           Students Screen List";
        string SubTitle = "           (" + to_string(vStudents.size()) + ") Student(s).";
        _DrawScreenForSystem(titel, SubTitle);
        _Getusername(Teachers.IDTEACHERS());

        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________";
        cout << "____________________________________________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "ID Students";
        cout << "| " << left << setw(20) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(12) << "Address";
        cout << "| " << left << setw(20) << "Number Of House";
        cout << "| " << left << setw(20) << "Number Of Father";
        cout << "| " << left << setw(20) << "Number Of Mother";
        cout << "| " << left << setw(10) << "Age";
        cout << "| " << left << setw(10) << "Password";
        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________";
        cout << "____________________________________________________________________________________________\n" << endl;

        if (vStudents.size() == 0)
        {
            cout << "\nThere no users on the system!";
        }
        else
        {
            for (clsStudentSystem S : vStudents)
            {
                _PrintUserRecordLine(S);
                cout << endl;
            }
        }
        cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________";
        cout << "____________________________________________________________________________________________\n" << endl;
    }
};

