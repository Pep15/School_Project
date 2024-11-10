#pragma once
#include "clsSchoolSystem.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsUpdateTeacherScreen : protected clsScreen
{
	static void _ReadTeachersRecord(clsSchoolSystem& Teacher)
	{
		Teacher.FirstName = clsInputValidate<string>::ReadString("\nEnter First Name: ");
		Teacher.LastName = clsInputValidate<string>::ReadString("\nEnter Last Name: ");
		Teacher.Password = clsInputValidate<string>::ReadString("\nEnter Password: ");
		Teacher.Email = clsInputValidate<string>::ReadString("\nEnter Email Account: ");
		Teacher.Phone = clsInputValidate<string>::ReadString("\nEnter Phone Number: ");
		Teacher.AnotherNumber = clsInputValidate<string>::ReadString("\nEnter secound Phone: ");
		Teacher.Address1 = clsInputValidate<string>::ReadString("\nEnter Address1: ");
		Teacher.Address2 = clsInputValidate<string>::ReadString("\nEnter Address2: ");
		Teacher.NumberOfHouse = clsInputValidate<string>::ReadString("\nEnter House number: ");

	}
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

	static void ShowTeacherUpdateScreen()
	{
		if (!CheckAccessRight(clsAdminSchoolSystem::eUpdate))
		{
			return;
		}
		_DrawScreenForSystem("\tUpdate Teacher Screen");
		_Getusername(Users.GetUserName());
		string IDTeachers;
		cout << "\nEnter Number ID of Teacher: ";
		IDTeachers = clsInputValidate<string>::ReadString();

		while (!clsSchoolSystem::IsExitTeacher(IDTeachers))
		{
			cout << "\nThis ID is not there , enter another ID: ";
			IDTeachers = clsInputValidate<string>::ReadString();
		}

		clsSchoolSystem UPdateTeacher = clsSchoolSystem::FindTeachersByID(IDTeachers);
		_PrintTeachersRecord(UPdateTeacher);


		cout << "\nAre you sure you want to update this client y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\n\nUpdate Client Info:";
			cout << "\n____________________\n";
			_ReadTeachersRecord(UPdateTeacher);



			clsSchoolSystem::enSaveResultTeacher Result;

			Result = UPdateTeacher.Save();

			switch (Result)
			{
			case clsSchoolSystem::svSeccussed:
				cout << "Teacher Record update seccussfully :-)\n";
				_PrintTeachersRecord(UPdateTeacher);
				break;
			case clsSchoolSystem::svObjectEmpty:
				cout << "\nThere is no Record update becuse is empty :-(\n";
				break;
			
			}
		}
	}
};

