#pragma once
#include "clsSystemSubjects.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsSchoolSystem.h"
using namespace std;
class clsAddSbjects : protected clsScreen
{
private:

	static void _ReadStudentSubjets(clsSystemSubjects& Subjects)
	{
		Subjects.Subject = clsInputValidate<string>::ReadString("\nPlease enter Subject: ");
		Subjects.Creadits = clsInputValidate<string>::ReadString("\nPlease enter credits: ");
		Subjects.Class = clsInputValidate<string>::ReadString("\nPlease enter class: ");
	}
	static string _ReadAccountNumber()
	{
		string AccountNumber;
		cout << "\nPlease Enter ID Teacher: ";
		AccountNumber = clsInputValidate<string>::ReadString();
		while (!clsSchoolSystem::IsExitTeacher(AccountNumber))
		{
			cout << "\nTeacher with [" << AccountNumber << "] does not exist , Enter another ID: ";
			cin >> AccountNumber;
		}
		return AccountNumber;
	}
	static string _ReadCodeSubject(string Massage)
	{
		string SubjectCode;
		cout << Massage;
		SubjectCode = clsInputValidate<string>::ReadString();
		while (clsSystemSubjects::IsExitCodeSubjet(SubjectCode))
		{
			cout << "\nCode subject with [" << SubjectCode << "] does not exist, Enter another Code Subject:  ";
			cin >> SubjectCode;
		}
		return SubjectCode;
	}
	static string _ReadNameTeacher()
	{
		string NameTeacher;
		cout << "\nPlease Enter Name Teacher: ";
		NameTeacher = clsInputValidate<string>::ReadString();
		while (!clsSchoolSystem::IsExitTeacherName(NameTeacher))
		{
			cout << "\nTeacher with name [" << NameTeacher << "] does not exist, Enter another Name Teacher: ";
			cin >> NameTeacher;
		}
		return NameTeacher;
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
		cout << "\nTeacher .N: " << Subjects.NameTeacher;
		cout << "\n__________________";
	}

public:

	static void ShowScreenAddSubjects()
	{
		_DrawScreenForSystem("\tAdd New Subject Screen");
		_Getusername(Teachers.IDTEACHERS());
		string CodeSubject = _ReadCodeSubject("\nPlease enter Code Subject: ");

		clsSystemSubjects Subjects = clsSystemSubjects::GetAddNewSubjects(CodeSubject);
		_ReadStudentSubjets(Subjects);
		Subjects.IDTeacher = _ReadAccountNumber();
		clsSchoolSystem Teacher = clsSchoolSystem::FindTeachersByID(Subjects.IDTeacher);
		Subjects.NameTeacher = _ReadNameTeacher();
		Teacher = clsSchoolSystem::FindTeachersName(Subjects.NameTeacher);
		clsSystemSubjects::enSccessedSubjects Result;
		Result = Subjects.Save();
		
		switch (Result)
		{
		case clsSystemSubjects::svSeccussed:
			_PrintCardOfSubjects(Subjects);
			cout << "\nThe Subject Add successfully:-)\n";
			break;
		case clsSystemSubjects::svObjectEmpty:
			cout << "\n There is no adding in file:-(";
			break;
		case clsSystemSubjects::svFaildToSaveObject:
			cout << "\nError Subject was not saved because Subject number is used!";
			break;
		
		}

	}
};

