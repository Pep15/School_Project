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
		cout << "| " << setw(25) << left << Subject.Subjects;
		cout << "| " << setw(7) << left << Subject.Credits;
		cout << "| " << setw(8) << left << Subject.Class;
		cout << "| " << setw(12) << left << Subject.IDTeacher;
		cout << "| " << setw(20) << left << Subject.NameTeacher << "|";
	}

public:


	static void ShowListScreen()
	{
		vector<clsSystemSubjects::stRegustrtion> _vRegustration = clsSystemSubjects::LoadDateShownSubjectRegstration();
		string title = " Subjects Screen List";
		string subTitle = " (" + to_string(_vRegustration.size()) + ") Subject(s).";
		_DrawScreenForSystem(title, subTitle);
		_Getusername(Students.GetIDstudents());
		cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________";
		cout << "\n" << setw(8) << left << "" << "| " << left << setw(12) << "Code"
			<< "| " << left << setw(25) << "Subject"
			<< "| " << left << setw(7) << "Credits"
			<< "| " << left << setw(8) << "Class"
			<< "| " << left << setw(12) << "Teacher ID"
			<< "| " << left << setw(20) << "Name Teacher"
			<< "|";
		cout << "\n" << setw(8) << left << "" << "\t______________________________________________________________________________________________________";
		cout << "\n" << endl;
		if (_vRegustration.size() == 0)
		{
			cout << "\nThere are no subjects on the system!";
		}
		else
		{
			for (clsSystemSubjects::stRegustrtion& S : _vRegustration)
			{
				_PrintSubjectRecordLine(S);
				cout << "\n" << setw(5) << left << "" << "\t______________________________________________________________________________________________________";
			}
		}
		cout << setw(8) << left << "" << "\n" << endl;
	}
};

