#pragma once
#include <iostream>
#include "clsmainScreen.h"
#include "clsScreen.h"
#include "clsPointerTeachersScreen.h"
#include "clsTeashersScreenPerformenc.h"
#include "Global.h"
using namespace std;
class clsTeacherLogin : protected clsScreen
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

			Teachers = clsSchoolSystem::Find(UserName, Password);

			faildLogin = Teachers.IsEmpty();

		} while (faildLogin);
		
		clsTeashersScreenPerformenc::ShowPerfromenceScreen();
		return true;

	}

public:

	static bool PreformnceLogin()
	{
		system("cls");
		_DrawScreenForSystem("\tTeachers Login" );
		_Getusername(Teachers.IDTEACHERS());
		return _LoginAdmin();
		
		
	}
};

