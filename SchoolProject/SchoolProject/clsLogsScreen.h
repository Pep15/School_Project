#pragma once
#include <iostream>
#include <iomanip>
#include "clsAdminSchoolSystem.h"
#include "clsScreen.h"
using namespace std;
class clsLogsScreen : protected clsScreen
{
private:

	static void PrintLogsScreen(clsAdminSchoolSystem::stLogsUsers Users)
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << Users.DataTime;
		cout << "| " << setw(20) << left << Users.User;
		cout << "| " << setw(20) << left << Users.Password;
		cout << "| " << setw(10) << left << Users.Permssions;
	}

public:

	static void ShowScreenLogsRigstrations()
	{
		vector <clsAdminSchoolSystem::stLogsUsers> _Logs = clsAdminSchoolSystem::GetLoadLogsUsers();
		string Title = "\tLogin Register List Screen";
		string SubTitle = "\t\t(" + to_string(_Logs.size()) + ") Record(s).";
		_DrawScreenForSystem(Title, SubTitle);
		_Getusername(Users.GetUserName());

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (_Logs.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else
		{
			for (clsAdminSchoolSystem::stLogsUsers U : _Logs)
			{
				PrintLogsScreen(U);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;
		
	}
};

