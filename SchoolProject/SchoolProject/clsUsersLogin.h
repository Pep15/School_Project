#pragma once
#include <iostream>
#include "clsAdminSchoolSystem.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "Global.h"
#include "clsAdminScreenPreformenc.h"
using namespace std;
class clsUsersLogin : protected clsScreen
{
private:

	static bool _LoginAdmin()
	{
		bool faildLogin = false;
		string UserName;
		string Password;
		int countfaildLogin = 0;
		do
		{
			if (faildLogin)
			{
				countfaildLogin++;
				cout << "\nInvalid Username/Password!\n\n";
				cout << "you Trial (" << 3 - countfaildLogin << ") Times login\n";
			}
			if (countfaildLogin == 3)
			{
				cout << "\nYour are locked after 3 faild trails \n\n";
				return false;
			}
			
			
			UserName = clsInputValidate<string>::ReadString("\nEnter User Name: ");
			Password = clsInputValidate<string>::ReadString("\nEnter Password: ");

			Users = clsAdminSchoolSystem::Find(UserName, Password);

			faildLogin = Users.IsEmpty();

		} while (faildLogin);
		Users.SaveLoginsToFiles();
		clsAdminScreenPreformenc::ShowMainMenue();
		return true;

	}
public:

	static bool PreformnceLoginAdmin()
	{
		system("cls");
		_DrawScreenForSystem("\tUsers Login");
		_Getusername(Users.GetUserName());
		return _LoginAdmin();
		
		
		
	}
};

