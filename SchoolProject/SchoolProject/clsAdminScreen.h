#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsmainScreen.h"
using namespace std;

class clsAdminScreen 
{
private:
	enum enScreenManange {
		eAdminScreen = 1,
		eTeachersScreen = 2,
		eLogout = 3
	};
	static int _ReadChoose()
	{
		int Choose;

		cout << "\nPlease enter number between 1 to 3: ";
		Choose = clsInputValidate<int>::ReadNumberBetween(1, 3);

		return Choose;
	}
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		
	}
	static void _ShowAdminScreen()
	{
		cout << "\n Will be here soon  !";
	}
	static void _ShowTeacherScreen()
	{
		clsmainScreen::ShowMainMenue();
	}

	static void _PerformencScreenMange(enScreenManange Choose)
	{
		switch (Choose)
		{
		case clsAdminScreen::eAdminScreen:
		{
			system("cls");
			_ShowAdminScreen();
			_GoBackToMainMenue();
			break;
		}
			
		case clsAdminScreen::eTeachersScreen:
		{
			system("cls");
			_ShowTeacherScreen();
			_GoBackToMainMenue();
			break;
		}
			
		
		}
	}

public:

	static void ScreenMainChoose()
	{
		system("cls");
		
		cout << setw(101) << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[2] Manage Teachers.\n";
		cout << setw(37) << left << "" << "\t[6] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformencScreenMange((enScreenManange)_ReadChoose());
	}
};

