#pragma once
#include "clsAdminSchoolSystem.h"
#include "clsScreen.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include <iomanip>
using namespace std;
class clsAddUserScreen : protected clsScreen
{
private:

	static void _ReadCardAddNewUsers(clsAdminSchoolSystem &Users)
	{
		Users.FirstName = clsInputValidate<string>::ReadString("\nPlease enter First Name: ");
		Users.LastName = clsInputValidate<string>::ReadString("\nPlease enter Last Name: ");
		Users.Email = clsInputValidate<string>::ReadString("\nPlease enter eamil account: ");
		Users.Phone = clsInputValidate<string>::ReadString("\nPlease enter Phone: ");
		Users.Password = clsInputValidate<string>::ReadString("\nPlease enter Password: ");
		Users.Permessions = _ReadPermssionsToUsers();

	}
	static void _PrintCardUsers(clsAdminSchoolSystem &Users)
	{
		cout << "\nCard of Teacher:\n";
		cout << "\n__________________";
		cout << "\nFirst Name: " << Users.FirstName;
		cout << "\nLast Name : " << Users.LastName;
		cout << "\nFull Name : " << Users.FullName();
		cout << "\nEmail .Acc: " << Users.Email;
		cout << "\nNumber    : " << Users.Phone;
		cout << "\nPassword  : " << Users.Password;
		cout << "\nUserName  : " << Users.GetUserName();
		cout << "\nPermssion : " << Users.Permessions;
		cout << "\n__________________";


	}
	static int _ReadPermssionsToUsers()
	{
		int Permssions = 0;
		char Answer = 'n';
		
		cout << "\nDo you want to give full access: y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want give Add access: y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permssions += clsAdminSchoolSystem::EnPermssionsMangagments::eAdd;
		}
		cout << "\nDo you want give Find access: y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permssions += clsAdminSchoolSystem::EnPermssionsMangagments::eFind;
		}
		cout << "\nDo you want give update access: y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permssions += clsAdminSchoolSystem::EnPermssionsMangagments::eUpdate;
		}
		cout << "\nDo you want give Delete access: y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permssions += clsAdminSchoolSystem::EnPermssionsMangagments::eDelete;
		}
		cout << "\nDo you want give Show List: y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permssions += clsAdminSchoolSystem::EnPermssionsMangagments::eShowLists;
		}
		cout << "\nDo you want give Show Logs: y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permssions += clsAdminSchoolSystem::EnPermssionsMangagments::eLogsShows;
		}

		return Permssions;
	}
public:
	static void ShowScreenAddUsers()
	{
		if (!CheckAccessRight(clsAdminSchoolSystem::eAdd))
		{
			return;
		}
		_DrawScreenForSystem("\tAdd New Users Screen");
		string UserName;
		_Getusername(Users.GetUserName());
		UserName = clsInputValidate<string>::ReadString("\nPlease enter UserName: ");
		while (clsAdminSchoolSystem::IsThereUsers(UserName))
		{
			cout << "\nThis User Find, Please enter another User: ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsAdminSchoolSystem Users = clsAdminSchoolSystem::GetAddNewUsers(UserName);
		_ReadCardAddNewUsers(Users);

		clsAdminSchoolSystem::enSccessfulSaveResult Result;

		Result = Users.Save();

		switch (Result)
		{
		case clsAdminSchoolSystem::vsSccessfull:
		{
			_PrintCardUsers(Users);
			cout << "\nThe User Add on File:-)\n";
			break;
		}
		case clsAdminSchoolSystem::falidSaveSccessfull:
		{
			cout << "\nError account was not saved because account number is used!";
			break;
		}
			
		case clsAdminSchoolSystem::ObjectEmpty:
		{
			cout << "\n There is no adding in file:-(";
			break;
		}
		
		}
	}
};

