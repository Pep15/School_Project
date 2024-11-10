#pragma once
#include <iostream>
#include "clsStudentSystem.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsAddNewRegustration.h"
#include "clsDeleteSubjectRegstration.h"
#include "clsListSubjects.h"
using namespace std;
class clsPerfomanceRegstrationSubjects : protected clsScreen
{
private:

	enum ChoosePerformenceSubjectRegstration { eAdd = 1, eDelete = 2, eList = 3, eExit = 4 };
	static int _ReadPefromnceRegustration()
	{
		int Choose = 0;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 4]? ";
		Choose = clsInputValidate<int>::ReadNumberBetween(1, 4);
		return Choose;
	}
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowPerfromenceScreen();
	}

	static void _ShowAddScreenRegustration()
	{
		clsAddNewRegustration::RegustrationsSubjects();
	}

	static void _ShowDeleteSubjectregstration()
	{
		clsDeleteSubjectRegstration::ShowDeleteRegustration();
	}

	static void _ShowListRegstration()
	{
		clsListSubjects::ShowListScreen();
	}

	static void _PreformenceRegstration(ChoosePerformenceSubjectRegstration Choose)
	{
		switch (Choose)
		{
		case clsPerfomanceRegstrationSubjects::eAdd:
		{
			system("cls");
			_ShowAddScreenRegustration();
			_GoBackToMainMenue();
			break;
		}
		case clsPerfomanceRegstrationSubjects::eDelete:
		{
			system("cls");
			_ShowDeleteSubjectregstration();
			_GoBackToMainMenue();
			break;
		}
		case clsPerfomanceRegstrationSubjects::eList:
		{
			system("cls");
			_ShowListRegstration();
			_GoBackToMainMenue();
			break;
		}	
		case clsPerfomanceRegstrationSubjects::eExit:
		{
			break;
		}
		
		}
	}

public:


	static void ShowPerfromenceScreen()
	{
		system("cls");
		_DrawScreenForSystem("\tRegster Screen");
		_Getusername(Students.GetIDstudents());
		cout << setw(101) << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Add New Regstration subject.\n";
		cout << setw(37) << left << "" << "\t[2] Delete Regstration subject.\n";
		cout << setw(37) << left << "" << "\t[3] Show Regstration subject.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PreformenceRegstration((ChoosePerformenceSubjectRegstration)_ReadPefromnceRegustration());
	}
};

