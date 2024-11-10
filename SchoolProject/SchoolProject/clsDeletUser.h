#pragma once
#include "clsAdminSchoolSystem.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsDeletUser : protected clsScreen
{
private:

	static void _PrintCardUsers(clsAdminSchoolSystem Users)
	{
		cout << "\nCard of Teacher:\n";
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

	static void ShowDeleteUsersScreen()
	{
		if (!CheckAccessRight(clsAdminSchoolSystem::eDelete))
		{
			return;
		}
		_DrawScreenForSystem("\tDelete Users Screen");

		string UserName;
		_Getusername(Users.GetUserName());
		cout << "\nEnter User Name: ";
		UserName = clsInputValidate<string>::ReadString();

		while (!clsAdminSchoolSystem::IsThereUsers(UserName))
		{
			cout << "\nThis User not found on system!, please enter another user name: ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsAdminSchoolSystem Users = clsAdminSchoolSystem::FindByUserName(UserName);
		_PrintCardUsers(Users);

		cout << "\nDid you want Delete this user? y/n? ";
		char Ansewr = 'n';
		cin >> Ansewr;

		if (Ansewr == 'y' || Ansewr == 'Y')
		{
			if (Users.Delet())
			{
				cout << "\nUsers Deleted Successfully :-)\n";
				_PrintCardUsers(Users);
			}
			else
			{
				cout << "\nError Delete Teacher :-(\n";
			}
		}
	}
};

