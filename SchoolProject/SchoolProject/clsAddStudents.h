#pragma once
#include <iostream>
#include "clsStudentSystem.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsAddStudents : protected clsScreen
{
private: 

	static void _ReadCardOfStudents(clsStudentSystem &Students)
	{
		Students.FirstName = clsInputValidate<string>::ReadString("\nPlease enter First Name: ");
		Students.LastName = clsInputValidate<string>::ReadString("\nPlease enter Last Name: ");
		Students.Email = clsInputValidate<string>::ReadString("\nPlease enter eamil account: ");
		Students.Phone = clsInputValidate<string>::ReadString("\nPlease enter Phone: ");
		Students.Address = clsInputValidate<string>::ReadString("\nPlease enter your Adrees: ");
		Students.NumberOfHouse = clsInputValidate<string>::ReadString("\nPlease enter your Number of House: ");
		Students.NumberOfFather = clsInputValidate<string>::ReadString("\nPlease enter your Number of Father: ");
		Students.NumberOfMother = clsInputValidate<string>::ReadString("\nPlease enter your Number of Mother: ");
		Students.Age = clsInputValidate<string>::ReadString("\nPlease enter your Age: ");
		Students.Password = clsInputValidate<string>::ReadString("\nPlease enter Password: ");
	}
	static void _PrintCardOfStudents(clsStudentSystem &Students)
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

	static void ShowScreenAddStudents()
	{
		_DrawScreenForSystem("\tAdd New Students Screen");
		_Getusername(Teachers.IDTEACHERS());
		string IDStudents;
		_Getusername(Students.GetIDstudents());
		IDStudents = clsInputValidate<string>::ReadString("\nEnter your ID Students: ");
		while (clsStudentSystem::IsExsitStudents(IDStudents))
		{
			cout << "\nThis Id is found on the system, Please enter another ID student: ";
			IDStudents = clsInputValidate<string>::ReadString();
		}

		clsStudentSystem Student = clsStudentSystem::GetAddNewStudents(IDStudents);
		_ReadCardOfStudents(Student);

		clsStudentSystem::enSaveResultStudents Results;

		Results = Student.Save();

		switch (Results)
		{
		case clsStudentSystem::svSeccussed:
		{
			_PrintCardOfStudents(Student);
			cout << "\nThe Student Add successfully:-)\n";
			break;
		}
		case clsStudentSystem::svObjectEmpty:
		{
			cout << "\n There is no adding in file:-(";
			break;
			
		}
			break;
		case clsStudentSystem::svFaildToSaveObject:
		{
			cout << "\nError account was not saved because account number is used!";
			break;
		}
		}


	}
};

