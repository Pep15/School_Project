#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsmainScreen.h"
#include "clsScreen.h"
#include "clsManageUserAdmin.h"
using namespace std;
class clsAdminScreenPreformenc : protected clsScreen
{
private:

	enum enChooseType { eManageUsersAdminScreen=1 , eManageTeachersScreen=2 , MainMenue=3};
	static int _ReadChooseType()
	{
		int Choose;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 3]? ";
		Choose = clsInputValidate<int>::ReadNumberBetween(1, 3);

		return Choose;
	}
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
	}
	static void _ShowScreenUsersAdmin()
	{
		clsManageUserAdmin::ShowMainMenue();
	}
	static void _ShowScreenTeachersScreen()
	{
		clsmainScreen::ShowMainMenue();
	}
	static void _PerformencManageUsersScreen(enChooseType Performence)
	{
		switch (Performence)
		{
		case clsAdminScreenPreformenc::eManageUsersAdminScreen:
		{
			system("cls");
			_ShowScreenUsersAdmin();
			_GoBackToMainMenue();
			break;
		}

		case clsAdminScreenPreformenc::eManageTeachersScreen:
		{
			system("cls");
			_ShowScreenTeachersScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsAdminScreenPreformenc::MainMenue:
		{

		}

		}
	}

public:

	static void ShowMainMenue()
	{

		system("cls");
		_DrawScreenForSystem("\t     Manage Screen");
		_Getusername(Users.GetUserName());
		cout << setw(101) << "" << "===========================================\n";
		cout << setw(37) << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << "" << "===========================================\n";
		cout << setw(37) << "" << "\t[1] Manage Users\n";
		cout << setw(37) << "" << "\t[2] Manage Teachers\n";
		cout << setw(37) << "" << "\t[3] Main Login.\n";
		cout << setw(37) << "" << "===========================================\n";
		_PerformencManageUsersScreen((enChooseType)_ReadChooseType());
	}
};

