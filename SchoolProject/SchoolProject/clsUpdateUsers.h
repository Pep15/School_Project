#pragma once
#include "clsAdminSchoolSystem.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsUpdateUsers : protected clsScreen
{
private:


	static void _ReadCardUpdateUsers(clsAdminSchoolSystem& Users)
	{
		Users.FirstName = clsInputValidate<string>::ReadString("\nPlease enter First Name: ");
		Users.LastName = clsInputValidate<string>::ReadString("\nPlease enter Last Name: ");
		Users.Email = clsInputValidate<string>::ReadString("\nPlease enter eamil account: ");
		Users.Phone = clsInputValidate<string>::ReadString("\nPlease enter Phone: ");
		Users.Password = clsInputValidate<string>::ReadString("\nPlease enter Password: ");

	}
	static void _PrintCardUsers(clsAdminSchoolSystem& Users)
	{
		cout << "\nCard of Teacher:";
		cout << "\n__________________";
		cout << "\nFirst Name: " << Users.FirstName;
		cout << "\nLast Name : " << Users.LastName;
		cout << "\nFull Name : " << Users.FullName();
		cout << "\nEmail .Acc: " << Users.Email;
		cout << "\nNumber    : " << Users.Phone;
		cout << "\nPassword  : " << Users.Password;
		cout << "\nUserName  : " << Users.GetUserName();
		cout << "\n__________________";


	}
public:

	static void ShowUpdateScreenUsers()
	{
		if (!CheckAccessRight(clsAdminSchoolSystem::eUpdate))
		{
			return;
		}
		_DrawScreenForSystem("\tUpdate Users Screen");

		string UserName;
		_Getusername(Users.GetUserName());
		cout << "\nEnter user name: ";
		UserName = clsInputValidate<string>::ReadString();

		while (!clsAdminSchoolSystem::IsThereUsers(UserName))
		{
			cout << "\nThis user not found on system!! , please enter another user: ";
			UserName = clsInputValidate<string>::ReadString();
		}
		clsAdminSchoolSystem Users = clsAdminSchoolSystem::FindByUserName(UserName);
		_PrintCardUsers(Users);

		char Answer = 'n';
		cout << "\nAre you sure do you want to preformnce update this user? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\n\nUpdate Users Info:";
			cout << "\n____________________\n";
			_ReadCardUpdateUsers(Users);

			clsAdminSchoolSystem::enSccessfulSaveResult Result;
			Result = Users.Save();

			switch (Result)
			{
			case clsAdminSchoolSystem::vsSccessfull:
			{
				
				cout << "\nSeccssfull Update";
				_PrintCardUsers(Users);
				break;
			}
			case clsAdminSchoolSystem::ObjectEmpty:
			{
				cout << "\n There is not Updateing in file becouse empty :-(";
				break;
			}
			}
		}
		

	}
};

