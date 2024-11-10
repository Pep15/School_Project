#pragma once
#include "clsSystemSubjects.h"
#include "clsScreen.h"
class clsFindSubject : protected clsScreen
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

	static void ShowFindSubject()
	{
		_DrawScreenForSystem("\tFind Subject Screen");
		_Getusername(Teachers.IDTEACHERS());

		string CodeSubject;
		cout << "\nPlease enter Code Subject: ";
		cin >> CodeSubject;

		while (!clsSystemSubjects::IsExitCodeSubjet(CodeSubject))
		{
			cout << "\nCode subject with [" << CodeSubject << "] does not exist: ";
			cin >> CodeSubject;
		}

		clsSystemSubjects Subjects = clsSystemSubjects::Find(CodeSubject);
		_PrintCardOfSubjects(Subjects);

		if (!Subjects.IsEmpty())
		{
			cout << "\nSubject Found :-)\n";
		}
		else
		{
			cout << "\nSubject Not Found :-(\n";
		}
	}
};

