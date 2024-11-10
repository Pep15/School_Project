#pragma once
#include <iostream>
#include <iomanip>
#include "clsDate.h"
#include "clsAdminSchoolSystem.h"
#include "Global.h"
using namespace std;
class clsScreen
{
protected:

  
	static void _DrawScreenForSystem(string Title,string SubTitle = "" )
	{
        string UserName;
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
       /* cout << "\t\t\t\t\tUser: " << _Getusername(UserName) << endl;
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate());*/
       
	}
  
    static string _Getusername(const string& UserName)
    {
        cout << "\t\t\t\t\tUser: " << UserName << endl;
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate());

        return UserName;
    }

public:

    
    static bool CheckAccessRight(clsAdminSchoolSystem::EnPermssionsMangagments Permssions)
    {
        if (!Users.PermssionsRight(Permssions))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }
    }
};

