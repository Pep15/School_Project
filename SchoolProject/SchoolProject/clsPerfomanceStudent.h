#pragma once
#include "clsStudentSystem.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsAddStudents.h"
#include "clsDeleteStudents.h"
#include "clsUpdateStudents.h"
#include "clsFindStudents.h"
#include "eListStudents.h"
using namespace std;
class clsPerfomanceStudent : protected clsScreen
{
private:
	enum ChoosePerformenceStudents {  eAdd = 1, eDelete = 2, eUpdate = 3, eFind = 4, eList = 5, eExit = 6 };
	static int _ReadPefromnceStudents()
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
		ShowPerfromenceScreen();
	}
	static void _ShowAddNewStudents()
	{
		clsAddStudents::ShowScreenAddStudents();
	}
	static void _ShowDeleteStudents()
	{
		clsDeleteStudents::ShowScreenDeleteStaudents();
	}
	static void _ShowUpdateStudents()
	{
		clsUpdateStudents::ShowScreenUpdateStaudents();
	}
	static void _ShowFindStudents()
	{
		clsFindStudents::ShowScreenUpdateStudents();
	}
	static void _ShowListScreenStudents()
	{
		eListStudents::ShowScreenListStudnts();
	}
	

	static void _PerformenceScreenChose(ChoosePerformenceStudents ChooseStuden)
	{
		switch (ChooseStuden)
		{
		case clsPerfomanceStudent::eAdd:
		{
			system("cls");
			_ShowAddNewStudents();
			_GoBackToMainMenue();
			break;
		}

		case clsPerfomanceStudent::eDelete:
		{
			system("cls");
			_ShowDeleteStudents();
			_GoBackToMainMenue();
			break;
		}
		case clsPerfomanceStudent::eUpdate:
		{
			system("cls");
			_ShowUpdateStudents();
			_GoBackToMainMenue();
			break;
		}
		case clsPerfomanceStudent::eList:
		{
			system("cls");
			_ShowListScreenStudents();
			_GoBackToMainMenue();
			break;
		}
		case clsPerfomanceStudent::eFind:
		{
			system("cls");
			_ShowFindStudents();
			_GoBackToMainMenue();
			break;
		}
		case clsPerfomanceStudent::eExit:
		{

		}


		}
	}

public:

	static void ShowPerfromenceScreen()
	{
		system("cls");
		_DrawScreenForSystem("\t    Students Screen");
		_Getusername(Teachers.IDTEACHERS());
		cout << setw(101) << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Add New Students.\n";
		cout << setw(37) << left << "" << "\t[2] Delete Students.\n";
		cout << setw(37) << left << "" << "\t[3] Update Students info.\n";
		cout << setw(37) << left << "" << "\t[4] Find Students.\n";
		cout << setw(37) << left << "" << "\t[5] Show List Students.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformenceScreenChose((ChoosePerformenceStudents)_ReadPefromnceStudents());
	}
};

