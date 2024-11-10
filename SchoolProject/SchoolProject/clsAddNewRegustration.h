#pragma once
#include <iostream>
#include <iomanip>
#include "clsSudentsRegustration.h"
#include "clsSystemSubjects.h"
#include "clsListSubject.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;
class clsAddNewRegustration : protected clsScreen
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
	static vector <clsSystemSubjects::stRegustrtion> _LoadDate()
	{
		vector<clsSystemSubjects::stRegustrtion> vRegustrations = clsSystemSubjects::LoadDateFromFileForReguster();
		return vRegustrations;
	}
	static void ShowListSubject() 
	{ 
		vector<clsSystemSubjects::stRegustrtion> _vRegustration = clsSystemSubjects::LoadDateFromFileForReguster(); 
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

	static void RegustrationsSubjects()
	{
		_DrawScreenForSystem("\tAdd New Subject Regstration");
		_Getusername(Students.GetIDstudents());
		ShowListSubject();
		string CodeSubject;
		cout << setw(37) << left << "" << "Choose what do you want to Subject: ";
		cin >> CodeSubject;
		while (!clsSystemSubjects::IsExitCodeSubjet(CodeSubject))
		{

			cout << setw(37) << left << "" << "Please this code subject [" << CodeSubject << "] does not on table! ";
			cout << "\nEnter correct code subject: ";
			cin >> CodeSubject;
		}

		clsSystemSubjects::SaveFileForStudentRegustration(_LoadDate() , CodeSubject);
		clsSystemSubjects::stRegustrtion PrintSubject = clsSystemSubjects::FindRegstration(CodeSubject);
		_PrintCardOfSubjects(PrintSubject);
		cout << "\nThe Subject Add successfully:-)\n";

		
	}
};

