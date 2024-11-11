#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsSchoolSystem.h"
#include "clsInputValidate.h"
#include "clsAddNewTeachers.h"
#include "clsFindTeacherScreen.h"
#include "clsUpdateTeacherScreen.h"
#include "clsDeleteTeachers.h"
#include "clsScreenViewTable.h"
using namespace std;
class clsmainScreen : protected clsScreen
{
private:
	enum EnChooseScreenTeachers {
		eShowScreenAddTeacher = 1 , 
		eShowScreenFindTeacher = 2,
		eShowScreenUpdateTeacher = 3,
		eShowDeleteTeacher = 4,
		eShowScreenViewTeacher = 5,
		eExit = 6
	};
	static int _ReadMainMenueOption()
	{
		int Choose = 0;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
		Choose = clsInputValidate<int>::ReadNumberBetween(1, 6);

		return Choose;
		
		
	}
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}
	static void _ShowScreenAddNewTeacher()
	{
		clsAddNewTeachers::ShowAddTeachersScreen();
	}
	static void _ShowScreenFindTeacherScreen()
	{
		clsFindTeacherScreen::ShowFindTeacherScreen();
	}
	static void _ShowScreenUpdateTeacherScreen()
	{
		clsUpdateTeacherScreen::ShowTeacherUpdateScreen();
	}
	static void _ShowDeleteTeachers()
	{
		clsDeleteTeachers::ShowTeachersDeletScreen();
	}
	static void _ShowScreenViewTeacher()
	{
		clsScreenViewTable::ShowScreenTeachers();
	}
	static void _ExsitScreen()
	{

	}

	static void _PerfromMainMenueOption(EnChooseScreenTeachers Choose)
	{
		switch (Choose)
		{
		case clsmainScreen::eShowScreenAddTeacher:
		{
			system("cls");
			_ShowScreenAddNewTeacher();
			_GoBackToMainMenue();
			break;
		}
		
		case clsmainScreen::eShowScreenFindTeacher:
		{
			system("cls");
			_ShowScreenFindTeacherScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsmainScreen::eShowScreenUpdateTeacher:
		{
			system("cls");
			_ShowScreenUpdateTeacherScreen();
			_GoBackToMainMenue();
			break;
		}
			
		case clsmainScreen::eShowDeleteTeacher:
		{
			system("cls");
			_ShowDeleteTeachers();
			_GoBackToMainMenue();
			break;
		}
		case clsmainScreen::eShowScreenViewTeacher:
		{
			system("cls");
			_ShowScreenViewTeacher();
			_GoBackToMainMenue();
			break;
		}
		case clsmainScreen::eExit:
		{
			
		}
		}
	}

public:


	static void ShowMainMenue()
	{

		system("cls");
		_DrawScreenForSystem("\tTeachers Screen");
		_Getusername(Users.GetUserName());
		cout << endl;
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Add New Teacher.\n";
		cout << setw(37) << left << "" << "\t[2] Find Teacher.\n";
		cout << setw(37) << left << "" << "\t[3] Update Teacher info.\n";
		cout << setw(37) << left << "" << "\t[4] Delete Teacher.\n";
		cout << setw(37) << left << "" << "\t[5] Show List Teacher.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerfromMainMenueOption((EnChooseScreenTeachers)_ReadMainMenueOption());
	}

	

};

