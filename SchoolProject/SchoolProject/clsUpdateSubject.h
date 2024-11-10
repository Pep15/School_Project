#pragma once
#include "clsSystemSubjects.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsUpdateSubject : protected clsScreen
{
private:


	static void _ReadStudentSubjets(clsSystemSubjects& Subjects)
	{
		Subjects.Subject = clsInputValidate<string>::ReadString("\nPlease enter new Subject: ");
		Subjects.Creadits = clsInputValidate<string>::ReadString("\nPlease enter new credits: ");
		Subjects.Class = clsInputValidate<string>::ReadString("\nPlease enter new class: ");
	}
	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter ID Teacher: ";
		AccountNumber = clsInputValidate<string>::ReadString();
		while (!clsSchoolSystem::IsExitTeacher(AccountNumber))
		{
			cout << "\nTeacher with [" << AccountNumber << "] does not exist.\n";
			cin >> AccountNumber;
		}
		return AccountNumber;
	}
	static string _ReadCodeSubject(string Massage)
	{
		string SubjectCode;
		cout << Massage;
		SubjectCode = clsInputValidate<string>::ReadString();
		while (!clsSystemSubjects::IsExitCodeSubjet(SubjectCode))
		{
			cout << "\nCode subject with [" << SubjectCode << "] does not exist: ";
			cin >> SubjectCode;
		}
		return SubjectCode;
	}
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

	static void ShowUpdateSubject()
	{
		_DrawScreenForSystem("\tUpdate Subject Screen");
		_Getusername(Teachers.IDTEACHERS());
		string CodeSubject = _ReadCodeSubject("\nPlease enter Code Subject: ");

		clsSystemSubjects Subjects = clsSystemSubjects::Find(CodeSubject);
		_PrintCardOfSubjects(Subjects);
		


		clsSystemSubjects::enSccessedSubjects Result;
		

		char Answer = 'n';
		cout << "\nAre you sure do you want to preformnce update this Subject? y/n? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\n\nUpdate Subject Info:";
			cout << "\n____________________\n";
			_ReadStudentSubjets(Subjects);
			Subjects.IDTeacher = _ReadAccountNumber();
			clsSchoolSystem Teacher = clsSchoolSystem::FindTeachersByID(Subjects.IDTeacher);
			Result = Subjects.Save();
			switch (Result)
			{
			case clsSystemSubjects::svSeccussed:
			{
				cout << "\nSeccssfull Update";
				_PrintCardOfSubjects(Subjects);
				break;
			}
				
			case clsSystemSubjects::svObjectEmpty:
			{
				cout << "\n There is not Updateing in file becouse empty :-(";
				break;
			}
				
			}
		}


	}
};

