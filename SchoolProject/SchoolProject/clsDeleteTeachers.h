#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsSchoolSystem.h"
using namespace std;
class clsDeleteTeachers : protected clsScreen
{
private:

	static void _PrintTeachersRecord(clsSchoolSystem Teacher)
	{
		cout << "\nCard of Teacher:\n";
		cout << "\n__________________";
		cout << "\nFirst Name: " << Teacher.FirstName;
		cout << "\nLast Name : " << Teacher.LastName;
		cout << "\nFull Name : " << Teacher.FullName();
		cout << "\nEmail .Acc: " << Teacher.Email;
		cout << "\nPhone N   : " << Teacher.Phone;
		cout << "\nSecoundryN: " << Teacher.AnotherNumber;
		cout << "\nAddress1  : " << Teacher.Address1;
		cout << "\nAddress2  : " << Teacher.Address2;
		cout << "\nHouse N   : " << Teacher.NumberOfHouse;
		cout << "\nID Teacher: " << Teacher.IDTEACHERS();
		cout << "\n__________________";

	}


public:

	static void ShowTeachersDeletScreen()
	{
		if (!CheckAccessRight(clsAdminSchoolSystem::eDelete))
		{
			return;
		}
		
		_DrawScreenForSystem("\tDelete Teacher Screen");
		_Getusername(Users.GetUserName());
		string TeacherID;
		cout << "\nEnter ID of Teacher: ";
		TeacherID = clsInputValidate<string>::ReadString();
		while (!clsSchoolSystem::IsExitTeacher(TeacherID))
		{
			cout << "\nThere is no ID Teacher on the system, Enter another ID: ";
			TeacherID = clsInputValidate<string>::ReadString();

		}

		clsSchoolSystem DeleteTeacher = clsSchoolSystem::FindTeachersByID(TeacherID);
		_PrintTeachersRecord(DeleteTeacher);

		char Ansewer = 'n';
		cout << "\n\nAre you sure do you want to delete this Teacher: y/n? ";
		cin >> Ansewer;

		if (Ansewer == 'y' || Ansewer == 'Y')
		{
			if (DeleteTeacher.Delete())
			{
				cout << "\nTeacher Deleted Successfully :-)\n";
				_PrintTeachersRecord(DeleteTeacher);
			}
			else
			{
				cout << "\nError Delete Teacher :-(\n";
			}
		}
	}
};

