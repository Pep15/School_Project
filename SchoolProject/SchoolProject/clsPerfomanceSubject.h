#pragma once 
#include <iostream> 
#include "clsAddSbjects.h" 
#include "clsDeleteSubjects.h" 
#include "clsUpdateSubject.h" 
#include "clsFindSubject.h" 
#include "clsListSubject.h" 
#include "clsInputValidate.h" 
#include "clsScreen.h"
using namespace std; 
class clsPerfomanceSubject : protected clsScreen
{ 
private: 
	enum ChoosePerformenceMangeSubject { eAddSubject = 1, eDeleteSubject = 2, eUpdateSubject = 3, eFindSubject = 4, eListSubject = 5, Main = 6 }; 
	static int _ReadPefromnceStudents() 
	{ 
		int Choose = 0; cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? "; 
		Choose = clsInputValidate<int>::ReadNumberBetween(1, 6); 
		return Choose; 
	} 
	static void _GoBackToMainMenue() 
	{	
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n"; 
		system("pause>0");
		ShowPerfomanceScreen();
	} 
	static void _ShowAddSubjectScreen() 
	{ 
		clsAddSbjects::ShowScreenAddSubjects(); 
	} 
	static void _ShowDeleteSubjectScreen() 
	{ 
		clsDeleteSubjects::ShowDeleteSubject(); 
	}	
	static void _ShowUpdateSubjectScreen() 
	{ 
		clsUpdateSubject::ShowUpdateSubject(); 

	} 
	static void _ShowFindSubjectScreen() 
	{	 
		clsFindSubject::ShowFindSubject(); 
	} 
	static void _ShowListSubjectScreen() 
	{ 
		clsListSubject::ShowListSubject(); 
	} 
	
	static void _PerformenceScreenChose(ChoosePerformenceMangeSubject choice)
	{
		switch (choice)
		{
		case clsPerfomanceSubject::eAddSubject:
		{
			system("cls");
			_ShowAddSubjectScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsPerfomanceSubject::eDeleteSubject:
		{
			system("cls");
			_ShowDeleteSubjectScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsPerfomanceSubject::eUpdateSubject:
		{
			system("cls");
			_ShowUpdateSubjectScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsPerfomanceSubject::eFindSubject:
		{
			system("cls");
			_ShowFindSubjectScreen();
			_GoBackToMainMenue();
			break;
		}

		case clsPerfomanceSubject::eListSubject:
		{
			system("cls");
			_ShowListSubjectScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsPerfomanceSubject::Main:
		{
		
		}
		}
	}

public:

	static void ShowPerfomanceScreen()
	{
		system("cls");
		_DrawScreenForSystem("\t    Subject Screen");
		_Getusername(Teachers.IDTEACHERS());
		cout << setw(101) << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Add New Subject.\n";
		cout << setw(37) << left << "" << "\t[2] Delete Subject.\n";
		cout << setw(37) << left << "" << "\t[3] Update Subject info.\n";
		cout << setw(37) << left << "" << "\t[4] Find Subject.\n";
		cout << setw(37) << left << "" << "\t[5] Show List Subject.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformenceScreenChose((ChoosePerformenceMangeSubject)_ReadPefromnceStudents());
	}
};


