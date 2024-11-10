#pragma once
#include <iostream>
#include <iomanip>
#include "clsTeacherLogin.h"
#include "clsAdminScreen.h"
#include "clsUsersLogin.h"
#include "clsStudentsLogin.h"
using namespace std;
class ClsLoginScreen
{

private:
	enum eLoginScreen {
		eAdminLogin = 1,
		eTeacherLogin = 2,
		eStudentLogin = 3
	
	};
	static int _ReadChooesLogin()
	{
		int Choose = 0;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 3]? ";
		Choose = clsInputValidate<int>::ReadNumberBetween(1, 3);

		return Choose;
	}
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		//ShowScreenLogin();
	}
	static void _ShowScreenAdminLogin()
	{
		clsUsersLogin::PreformnceLoginAdmin();
	}
	static void _ShowScreenTeacherLogin()
	{
		clsTeacherLogin::PreformnceLogin();
	}
	static void _ShowScreenStudentsLogin()
	{
		clsStudentsLogin::PreformnceLogin();
	}
	static void _PerformencLoginChoose(eLoginScreen Login)
	{
		switch (Login)
		{
		case ClsLoginScreen::eAdminLogin:
		{
			system("cls");
			_ShowScreenAdminLogin();
			
			break;
		}
			
		case ClsLoginScreen::eTeacherLogin:
		{
			system("cls");
			_ShowScreenTeacherLogin();
			break;
		}
		case ClsLoginScreen::eStudentLogin:
		{
			system("cls");
			_ShowScreenStudentsLogin();
			
			break;
		}
			
		
		}
	}

public:

	static void ShowScreenLogin()
	{

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Login As Admin\n";
		cout << setw(37) << left << "" << "\t[2] Login As Teacher.\n";
		cout << setw(37) << left << "" << "\t[3] Login As Student.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformencLoginChoose((eLoginScreen)_ReadChooesLogin());
	}
	

};

