#pragma once
#include <iostream>
#include "clsSystemSubjects.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsDeleteSubjects : protected clsScreen
{
private:

	static void _PrintCardOfSubjects(clsSystemSubjects& Subjects)
	{
		cout << "\nCard of Subjects:\n";
		cout << "\n__________________";
		cout << "\nSubject .N: " << Subjects.Subject;
		cout << "\nSubject .C: " << Subjects.GetCodeSubjects();
		cout << "\nCredits   : " << Subjects.Creadits;
		cout << "\nClass .N  : " << Subjects.Class;
		cout << "\nID Teacher: " << Subjects.IDTeacher;
		cout << "\n__________________";
	}

public:

	static void ShowDeleteSubject()
	{
		_DrawScreenForSystem("\tDelete Teacher Screen");
		_Getusername(Teachers.IDTEACHERS());

		string CodeSubject;
		cout << "\nPlease enter Code Subject: ";
		cin >> CodeSubject;

		while (!clsSystemSubjects::IsExitCodeSubjet(CodeSubject))
		{
			cout << "\nThis code Subject [" << CodeSubject << "] did not found, please enter another: ";
			cin >> CodeSubject;
		}

		clsSystemSubjects Subjects = clsSystemSubjects::Find(CodeSubject);
		_PrintCardOfSubjects(Subjects);

		char Answer = 'n';
		cout << "\nDid you want to delete this subject? y/n? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Subjects.Delete())
			{
				cout << "\nSubject Deleted Successfully :-)\n";
				_PrintCardOfSubjects(Subjects);
				
			}
			else
			{
				cout << "\nError Delete subject :-(\n";
			}
		}
	}

};

