#pragma once
#include <iostream>
#include <iomanip>
#include "clsSystemSubjects.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsDeleteSubjectRegstration : protected clsScreen
{
private:
	static void _PrintCardOfSubjects(clsSystemSubjects::stRegustrtion& Regustration)
	{
		cout << "\nCard of Subjects:\n";
		cout << "\n__________________";
		cout << "\nSubject .N: " << Regustration.Subjects;
		cout << "\nSubject .C: " << Regustration.CodeSubject;
		cout << "\nCredits   : " << Regustration.Credits;
		cout << "\nClass .N  : " << Regustration.Class;
		cout << "\nID Teacher: " << Regustration.IDTeacher;
		cout << "\nTeacher .N: " << Regustration.NameTeacher;
		cout << "\n__________________";
	}

public:

	static void ShowDeleteRegustration()
	{
		_DrawScreenForSystem("\tDelete Subject Regstration");
		_Getusername(Students.GetIDstudents());
		string CodeSubject;

		cout << "\nEnter code Subject: ";
		cin >> CodeSubject;

		while (!clsSystemSubjects::CheckCodeSubject(CodeSubject))
		{
			cout << setw(37) << left << "" << "Please this code subject [" << CodeSubject << "] does not on exsit! ";
			cout << "\nEnter correct code subject: ";
			CodeSubject = clsInputValidate<string>::ReadString();
		}

		clsSystemSubjects::stRegustrtion DeleteSubject = clsSystemSubjects::FindRegstration(CodeSubject);

		_PrintCardOfSubjects(DeleteSubject);

		char Answer = 'n';
		cout << "\nAre you sure do you want to delete this subject? y/n? ";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (DeleteSubject.DeleteForRegustration())
			{
				cout << "\nThe Subject Deleted Successfully :-)\n";
				_PrintCardOfSubjects(DeleteSubject);
			}
			else
			{
				cout << "\nError Delete Subject :-(\n";
			}
		}


	}
};

