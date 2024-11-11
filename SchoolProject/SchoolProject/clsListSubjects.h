#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsSystemSubjects.h"
using namespace std;
class clsListSubjects : protected clsScreen
{

private:

	static void _PrintSubjectRecordLine(clsSystemSubjects::stRegustrtion& Subject)
	{
	
		cout << setw(8) << left << "" << "| " << setw(12) << left << Subject.CodeSubject;
		cout << "| " << setw(20) << left << Subject.Subjects;
		cout << "| " << setw(10) << left << Subject.Credits;
		cout << "| " << setw(15) << left << Subject.Class;
		cout << "| " << setw(25) << left << Subject.IDTeacher;
		cout << "| " << setw(15) << left << Subject.NameTeacher;
	}

public:


	static void ShowListScreen()
	{
		vector<clsSystemSubjects::stRegustrtion> _vRegustration = clsSystemSubjects::LoadDateShownSubjectRegstration();
		string title = " Subjects Screen List";
		string subTitle = " (" + to_string(_vRegustration.size()) + ") Subject(s).";
		_DrawScreenForSystem(title, subTitle);
		_Getusername(Students.GetIDstudents());
		cout << setw(8) << left << "" << "\n\t________________________________________________________";
		cout << "______________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(12) << "CodeSubjects";
		cout << "| " << left << setw(20) << "Subjects";
		cout << "| " << left << setw(10) << "Credits";
		cout << "| " << left << setw(15) << "Class";
		cout << "| " << left << setw(25) << "IDTeacher";
		cout << "| " << left << setw(25) << "NameTeacher";
		cout << setw(8) << left << "" << "\n\t________________________________________________________";
		cout << "______________________________________________________\n" << endl;

		if (_vRegustration.size() == 0)
		{
			cout << "\nThere are no subjects on the system!";
		}
		else
		{
			for (clsSystemSubjects::stRegustrtion& S : _vRegustration)
			{
				_PrintSubjectRecordLine(S);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t________________________________________________________";
		cout << "______________________________________________________\n" << endl;
	}
};

