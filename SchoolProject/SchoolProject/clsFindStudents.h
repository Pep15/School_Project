#pragma once
#include "clsStudentSystem.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsFindStudents : protected clsScreen
{
private:

	static void _PrintCardOfStudents(clsStudentSystem& Students)
	{
		cout << "\nCard of Student:\n";
		cout << "\n__________________";
		cout << "\nFirst Name: " << Students.FirstName;
		cout << "\nLast Name : " << Students.LastName;
		cout << "\nFull Name : " << Students.FullName();
		cout << "\nEmail .Acc: " << Students.Email;
		cout << "\nNumber    : " << Students.Phone;
		cout << "\nN .House  : " << Students.NumberOfHouse;
		cout << "\nN .Father : " << Students.NumberOfFather;
		cout << "\nN .Father : " << Students.NumberOfMother;
		cout << "\nAge       : " << Students.Age;
		cout << "\nPassword  : " << Students.Password;
		cout << "\nID .S     : " << Students.GetIDstudents();
		cout << "\n__________________";
	}

public:

	static void ShowScreenUpdateStudents()
	{
		_DrawScreenForSystem("\tFind Student Screen");
		_Getusername(Teachers.IDTEACHERS());

		string IDStudnets;
		cout << "\nPlease enter ID Student: ";
		IDStudnets = clsInputValidate<string>::ReadString();
		while (!clsStudentSystem::IsExsitStudents(IDStudnets))
		{
			cout << "\nThis Student not found on system! , please enter another: ";
			IDStudnets = clsInputValidate<string>::ReadString();
		}

		clsStudentSystem FStudents = clsStudentSystem::FindByIDStudents(IDStudnets);
		_PrintCardOfStudents(FStudents);

		if (!FStudents.IsEmpty())
		{
			cout << "\nUsers Found :-)\n";
		}
		else
		{
			cout << "\nUser Not Found :-(\n";
		}
	}
};

