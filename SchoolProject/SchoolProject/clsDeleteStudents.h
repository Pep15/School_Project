#pragma once
#include "clsSystemSubjects.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsSchoolSystem.h"
using namespace std;
class clsDeleteStudents : protected clsScreen
{
private:
	static void _PrintCardOfStudents(clsStudentSystem Students)
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

	static void ShowScreenDeleteStaudents()
	{
		_DrawScreenForSystem("\tDelete student Screen");
		_Getusername(Teachers.IDTEACHERS());
		string IDStudents;
		cout << "\nPlease eter ID Students: ";
		IDStudents = clsInputValidate<string>::ReadString();

		while (!clsStudentSystem::IsExsitStudents(IDStudents))
		{
			cout << "\nThere is no ID Studen on the system, Enter another ID: ";
			IDStudents = clsInputValidate<string>::ReadString();
		}

		clsStudentSystem DeleteStudents = clsStudentSystem::FindByIDStudents(IDStudents);
		_PrintCardOfStudents(DeleteStudents);

		char Answer = 'n';
		cout << "\nAre you sure did you want to delete this student? y/n? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (DeleteStudents.Delete())
			{
				cout << "\nStudents Deleted Successfully :-)\n";
				_PrintCardOfStudents(DeleteStudents);
			}
			else
			{
				cout << "\nError Delete Student :-(\n";
			}
		}
	}

};

