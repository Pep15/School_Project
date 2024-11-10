#pragma once
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsAddUserScreen.h"
#include "clsFindUsersScreen.h"
#include "clsUpdateUsers.h"
#include "clsDeletUser.h"
#include "clsListUserScreen.h"
#include "clsLogsScreen.h"
using namespace std;
class clsManageUserAdmin : protected clsScreen
{
private:

	enum UsersChoose {eAddUsers=1 , eFindUsers=2 , eUpdateUsers=3 , eDeletUser=4 , eListUsers=5 , eShowLogs = 6,eExit=7};
	static int _ReadUserMangers()
	{
		int Choose = 0;
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 7]? ";
		Choose = clsInputValidate<int>::ReadNumberBetween(1, 7);
		return Choose;
	}
	static  void _GoBackToMainMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenue();
	}
	static void _ShowAddUserScreen()
	{
		clsAddUserScreen::ShowScreenAddUsers();
	}
	static void _ShowFindUsersScreen()
	{
		clsFindUsersScreen::ShowFindScreenUsers();
	}
	static void _ShowUpdateUsersScreen()
	{
		clsUpdateUsers::ShowUpdateScreenUsers();
	}
	static void _ShowDeleteUsersScreen()
	{
		clsDeletUser::ShowDeleteUsersScreen();
	}
	static void _ShowListUserScreen()
	{
		clsListUserScreen::ShowScreenList();
	}
	static void _ShowListLogsUsersScreen()
	{
		clsLogsScreen::ShowScreenLogsRigstrations();
	}
	static void _PerformenceMangeUsers(UsersChoose Performnce)
	{
		switch (Performnce)
		{
		case clsManageUserAdmin::eAddUsers:
		{
			system("cls");
			_ShowAddUserScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsManageUserAdmin::eFindUsers:
		{
			system("cls");
			_ShowFindUsersScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsManageUserAdmin::eUpdateUsers:
		{
			system("cls");
			_ShowUpdateUsersScreen();
			_GoBackToMainMenue();
			break;
		}	
		case clsManageUserAdmin::eDeletUser:
		{
			system("cls");
			_ShowDeleteUsersScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsManageUserAdmin::eListUsers:
		{
			system("cls");
			_ShowListUserScreen();
			_GoBackToMainMenue();
			break;
		}
		case clsManageUserAdmin::eShowLogs:
		{
			system("cls");
			_ShowListLogsUsersScreen();
			_GoBackToMainMenue();
			break;

		}
		case clsManageUserAdmin::eExit:
		{
			
		}
			
		}
	}

public:

	static void ShowMainMenue()
	{

		system("cls");
		_DrawScreenForSystem("\t    Users Screen");
		_Getusername(Users.GetUserName());
		cout << setw(101) << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Add New Users.\n";
		cout << setw(37) << left << "" << "\t[2] Find Users.\n";
		cout << setw(37) << left << "" << "\t[3] Update Users info.\n";
		cout << setw(37) << left << "" << "\t[4] Delete Users.\n";
		cout << setw(37) << left << "" << "\t[5] Show List Users.\n";
		cout << setw(37) << left << "" << "\t[6] Show Logs Users.\n";
		cout << setw(37) << left << "" << "\t[7] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformenceMangeUsers((UsersChoose)_ReadUserMangers());




	}

};

