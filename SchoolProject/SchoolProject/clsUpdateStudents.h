#pragma once
#include "clsStudentSystem.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsUpdateStudents : protected clsScreen
{
private:
	static void _ReadCardOfStudents(clsStudentSystem& Students)
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

	static void ShowScreenUpdateStaudents()
	{
		_DrawScreenForSystem("\tUpdate Student Screen");
		_Getusername(Teachers.IDTEACHERS());
		string IDStudents;
		cout << "\nPlease enter student ID: ";
		IDStudents = clsInputValidate<string>::ReadString();
		while (!clsStudentSystem::IsExsitStudents(IDStudents))
		{
			cout << "\nThis Student not found on system!! , please enter another student: ";
			IDStudents = IDStudents = clsInputValidate<string>::ReadString();
		}

		clsStudentSystem UpStudents = clsStudentSystem::FindByIDStudents(IDStudents);
		_PrintCardOfStudents(UpStudents);

		clsStudentSystem::enSaveResultStudents Results;

		Results = UpStudents.Save();

		char Answer = 'n';
		cout << "\nAre you sure do you want to preformnce update this Students? y/n? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Users Info:";
			cout << "\n____________________\n";
			_ReadCardOfStudents(UpStudents);

			switch (Results)
			{
			case clsStudentSystem::svSeccussed: 
			{
				cout << "\nSeccssfull Update";
				_PrintCardOfStudents(UpStudents);
				break;
			}
				
			case clsStudentSystem::svObjectEmpty:
			{
				cout << "\n There is not Updateing in file becouse empty :-(";
				break;
			}
				
			}
		}
	}
};

