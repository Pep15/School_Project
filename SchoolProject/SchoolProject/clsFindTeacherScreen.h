#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsFindTeacherScreen :protected clsScreen
{
private:

	static void _PrintCardTeachers(clsSchoolSystem Teacher)
	{
		cout << "\nCard of Teacher:";
		cout << "\n__________________";
		cout << "\nFirst Name: " << Teacher.FirstName;
		cout << "\nLast Name : " << Teacher.LastName;
		cout << "\nFull Name : " << Teacher.FullName();
		cout << "\nPassword  : " << Teacher.Password;
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

	static void ShowFindTeacherScreen()
	{
		if (!CheckAccessRight(clsAdminSchoolSystem::eFind))
		{
			return;
		}
		
		_DrawScreenForSystem("\tFind Teacher Screen");
		_Getusername(Users.GetUserName());
		string NumberID;
		cout << "\nEnter ID Teacher: ";
		NumberID = clsInputValidate<string>::ReadString();

		while (!clsSchoolSystem::IsExitTeacher(NumberID))
		{
			cout << "\nThis Teacher ID not Found on system! , Enter Correct ID Teacher: ";
			NumberID = clsInputValidate<string>::ReadString();
		}

		clsSchoolSystem FindTeacher = clsSchoolSystem::FindTeachersByID(NumberID);
		_PrintCardTeachers(FindTeacher);


		if (!FindTeacher.IsEmpty())
		{
			cout << "\nTeacher Found :-)\n";
		}
		else
		{
			cout << "\nTeacher Not Found :-(\n";
		}
	}

	
};

