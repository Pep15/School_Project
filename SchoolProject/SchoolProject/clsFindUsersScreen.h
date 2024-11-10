#pragma once
#include "clsAdminSchoolSystem.h"
#include "clsSchoolSystem.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsFindUsersScreen : protected clsScreen
{
private:

	static void _PrintCardUsers(clsAdminSchoolSystem Users)
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
		cout << "\n__________________";
	}

public:

	static void ShowFindScreenUsers()
	{
		if (!CheckAccessRight(clsAdminSchoolSystem::eFind))
		{
			return;
		}
		_DrawScreenForSystem("\tFind Users Screen");

		string UserName;
		_Getusername(Users.GetUserName());
		cout << "\nPlease enter UserName: ";
		UserName = clsInputValidate<string>::ReadString();
		while (!clsAdminSchoolSystem::IsThereUsers(UserName))
		{
			cout << "\nthis user not found on system! , please enter another: ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsAdminSchoolSystem Users = clsAdminSchoolSystem::FindByUserName(UserName);
		_PrintCardUsers(Users);

		if (!Users.IsEmpty())
		{
			cout << "\nUsers Found :-)\n";
		}
		else
		{
			cout << "\nUser Not Found :-(\n";
		}
	}
};

