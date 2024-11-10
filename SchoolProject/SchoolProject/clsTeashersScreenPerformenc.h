#pragma once
#include "clsPerfomanceStudent.h"
#include "clsPerfomanceSubject.h"
#include "clsPointerTeachersScreen.h"
using namespace std;
class clsTeashersScreenPerformenc : protected clsScreen
{
private:

	enum ChoosePerformenceMange{ eTeacherSelf=1 ,eStudents=2 , eSubjects=3 , eMain=4};
	static int _ReadPefromnceStudents()
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
	static void _ShowListScreenTeacher()
	{
		clsPointerTeachersScreen::ShowScreenTeachers();
	}
	static void _ShowStudentManagement()
	{
		clsPerfomanceStudent::ShowPerfromenceScreen();
	}
	static void _ShowSubjectsManagment()
	{
		clsPerfomanceSubject::ShowPerfomanceScreen();
	}
	static void _PerformenceChooseMenue(ChoosePerformenceMange Choose)
	{
		switch (Choose)
		{
		case clsTeashersScreenPerformenc::eTeacherSelf:
		{
			system("cls");
			_ShowListScreenTeacher();
			_GoBackToMainMenue();
			break;
		}
		case clsTeashersScreenPerformenc::eStudents:
		{
			system("cls");
			_ShowStudentManagement();
			_GoBackToMainMenue();
			break;
		}
		case clsTeashersScreenPerformenc::eSubjects:
		{
			system("cls");
			_ShowSubjectsManagment();
			_GoBackToMainMenue();
			break;
		}
		case clsTeashersScreenPerformenc::eMain:
		{

		}

		}
	 
	}
public:

	static void ShowPerfromenceScreen()
	{
		system("cls");
		_DrawScreenForSystem("\t    Colloge Screen");
		_Getusername(Teachers.IDTEACHERS());
		cout << setw(101) << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show List itself Teacher.\n";
		cout << setw(37) << left << "" << "\t[2] Manage Students.\n";
		cout << setw(37) << left << "" << "\t[3] Manage Subjects.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformenceChooseMenue((ChoosePerformenceMange)_ReadPefromnceStudents());
	}
};

