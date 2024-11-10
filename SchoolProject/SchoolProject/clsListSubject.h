#pragma once
#include "clsSystemSubjects.h"
#include "clsScreen.h"
#include <iomanip>
class clsListSubject : protected clsScreen
{

private: 
	static void _PrintSubjectRecordLine(clsSystemSubjects& Subject)
	{

		cout << setw(8) << left << "" << "| " << setw(15) << left << Subject.GetCodeSubjects();
		cout << "| " << setw(15) << left << Subject.Subject;
		cout << "| " << setw(15) << left << Subject.Creadits;
		cout << "| " << setw(15) << left << Subject.Class;
		cout << "| " << setw(15) << left << Subject.IDTeacher;
		cout << "| " << setw(15) << left << Subject.NameTeacher;
	}

public:

	 static void ShowListSubject() 
	 {
		vector<clsSystemSubjects> vSubjects = clsSystemSubjects::GetDataFromFile(); 
		string title = " Subjects Screen List"; 
		string subTitle = " (" + to_string(vSubjects.size()) + ") Subject(s)."; 
		 _DrawScreenForSystem(title, subTitle); 
		 cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________________"; 
		 cout << "\n" << endl; cout << setw(8) << left << "" << "| " << left << setw(15) << "Code"; 
		 cout << "| " << left << setw(15) << "Subject"; 
		 cout << "| " << left << setw(15) << "Credits";
		 cout << "| " << left << setw(15) << "Class"; 
		 cout << "| " << left << setw(15) << "Teacher ID";
		 cout << "| " << left << setw(15) << "Name Teacher";
		 cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________________";
		 cout << "\n" << endl;

		 if (vSubjects.size() == 0) 
		 { 
			 cout << "\nThere are no subjects on the system!";
		 } 
		 else 
		 { 
			 for (clsSystemSubjects& S : vSubjects) 
			 { 
				 _PrintSubjectRecordLine(S);
			 } 
		 } 
		 
		 cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________________";
		 cout << "\n" << endl; 
	 }
};

