#pragma once
#include "clsSystemSubjects.h"
#include "clsScreen.h"
#include <iomanip>
class clsListSubject : protected clsScreen
{

private: 
	static void _PrintSubjectRecordLine(clsSystemSubjects& Subject)
	{

		cout << setw(8) << left << "" << "| " << setw(12) << left << Subject.GetCodeSubjects();
		cout << "| " << setw(20) << left << Subject.Subject;
		cout << "| " << setw(10) << left << Subject.Creadits;
		cout << "| " << setw(15) << left << Subject.Class;
		cout << "| " << setw(25) << left << Subject.IDTeacher;
		cout << "| " << setw(15) << left << Subject.NameTeacher;
	}

public:

	 static void ShowListSubject() 
	 {
		vector<clsSystemSubjects> vSubjects = clsSystemSubjects::GetDataFromFile(); 
		string title = " Subjects Screen List"; 
		string subTitle = " (" + to_string(vSubjects.size()) + ") Subject(s)."; 
		 _DrawScreenForSystem(title, subTitle); 
		 cout << setw(8) << left << "" << "\n\t________________________________________________________";
		 cout << "______________________________________________________\n" << endl;

		 cout << setw(8) << left << "" << "| " << left << setw(12) << "CodeSubjects";
		 cout << "| " << left << setw(20) << "Subjects";
		 cout << "| " << left << setw(10) << "Credits";
		 cout << "| " << left << setw(15) << "Class";
		 cout << "| " << left << setw(25) << "IDTeacher";
		 cout << "| " << left << setw(15) << "NameTeacher";
		 cout << setw(8) << left << "" << "\n\t________________________________________________________";
		 cout << "______________________________________________________\n" << endl;
		 if (vSubjects.size() == 0) 
		 { 
			 cout << "\nThere are no subjects on the system!";
		 } 
		 else 
		 { 
			 for (clsSystemSubjects& S : vSubjects) 
			 { 
				 _PrintSubjectRecordLine(S);
				 cout << endl;
			 } 
		 } 
		 
		 cout << setw(8) << left << "" << "\n\t________________________________________________________";
		 cout << "______________________________________________________\n" << endl;
	 }
};

