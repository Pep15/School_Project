#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsPerfomanceRegstrationSubjects.h"
#include "Global.h"
using namespace std;
class clsStudentsLogin : protected clsScreen
{
private:


	static bool _LoginAdmin()
	{
		bool faildLogin = false;
		string EmailAdress;
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


			EmailAdress = clsInputValidate<string>::ReadString("\nEnter Email Address: ");
			Password = clsInputValidate<string>::ReadString("\nEnter Password: ");

			Students = clsStudentSystem::FindByEmailIDStudentsPassword(EmailAdress, Password);

			faildLogin = Students.IsEmpty();

		} while (faildLogin);

		clsPerfomanceRegstrationSubjects::ShowPerfromenceScreen();
		return true;

	}

public:

	static bool PreformnceLogin()
	{
		system("cls");
		_DrawScreenForSystem("\tStudent Login");
		_Getusername(Students.GetIDstudents());
		return _LoginAdmin();


	}
};

