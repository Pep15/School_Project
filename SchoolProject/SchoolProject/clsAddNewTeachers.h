#pragma once
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsSchoolSystem.h"
#include "clsScreen.h"
using namespace std;
class clsAddNewTeachers : protected clsScreen
{
private:
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
	static void PrintTeachersRecord(clsSchoolSystem &Teacher)
	{
		cout << "\nCard of Teacher:\n";
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

	static void ShowAddTeachersScreen()
	{
		if (!CheckAccessRight(clsAdminSchoolSystem::eAdd))
		{
			return;
		}
		_DrawScreenForSystem("\tAdd New Teacher Screen");
		_Getusername(Users.GetUserName());
		string IDTeachers = " ";
		cout << "\nEnter ID Teacher: ";
		IDTeachers = clsInputValidate<string>::ReadString();
		while (clsSchoolSystem::IsExitTeacher(IDTeachers))
		{
			cout << "\nThis ID is there , enter another ID: ";
			IDTeachers = clsInputValidate<string>::ReadString();
		}

		clsSchoolSystem NewTeachers = clsSchoolSystem::GetAddNewTeachers(IDTeachers);
		_ReadTeachersRecord(NewTeachers);

		clsSchoolSystem::enSaveResultTeacher Result;

		Result = NewTeachers.Save();

		switch (Result)
		{
		case clsSchoolSystem::svSeccussed:
		{
			PrintTeachersRecord(NewTeachers);
			cout << "\nThe Teacher Add on File:-)\n";
			break;
		}
		case clsSchoolSystem::svObjectEmpty:
		{
			cout << "\n There is no adding in file:-(";
			break;
		}
		case clsSchoolSystem::svFaildToSaveObject:
		{
			cout << "\nError account was not saved because account number is used!";
			break;
		}

		}

		
	}
};

