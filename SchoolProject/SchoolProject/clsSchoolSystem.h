#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtil.h"
using namespace std;
class clsSchoolSystem : public clsPerson
{
private:

	enum enMode { eEmptyMode = 0, eUpdateMode = 1, eAddMode = 2 };
	enMode _Mode;
	string _AnotherNumber;
	string _Address1;
	string _Address2;
	string _NumberOfHouse;
	string _IDTeachers;
	string _Password;
	bool _MarkDeleteTeacher = false;
	static clsSchoolSystem _ConvertTeachersToObjects(string Line, string Sepretoer = "#//#")
	{
		vector <string> _vTeacher;

		_vTeacher = clsString::Split(Line, Sepretoer);
		return clsSchoolSystem(enMode::eUpdateMode , _vTeacher[0], _vTeacher[1], _vTeacher[2], _vTeacher[3], _vTeacher[4], _vTeacher[5]
			, _vTeacher[6], _vTeacher[7], _vTeacher[8] , _vTeacher[9]);
	}
	static string _ConvertTeachrsObjectToLine(clsSchoolSystem Teacher, string Sepretoer = "#//#")
	{
		string DataLine;
		DataLine += Teacher.FirstName + Sepretoer;
		DataLine += Teacher.LastName + Sepretoer;
		DataLine += Teacher.Email + Sepretoer;
		DataLine += Teacher.Phone + Sepretoer;
		DataLine += Teacher.AnotherNumber + Sepretoer;
		DataLine += Teacher.Address1 + Sepretoer;
		DataLine += Teacher.Address2 + Sepretoer;
		DataLine += Teacher.NumberOfHouse + Sepretoer;
		DataLine += Teacher.IDTEACHERS() + Sepretoer;
		DataLine += Teacher.Password , 2;

		return DataLine;
	}
	static void _SaveCleintsDataToFile(vector <clsSchoolSystem> _vTeachers)
	{

		fstream MyFile;
		MyFile.open("Teachers.txt", ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsSchoolSystem T : _vTeachers)
			{
				if (T.MarkForDeleted() == false)
				{
					//we only write records that are not marked for delete.  
					DataLine = _ConvertTeachrsObjectToLine(T);
					MyFile << DataLine << endl;
					

				}

			}

			MyFile.close();

		}

	}
	static vector <clsSchoolSystem> _LoadDateFromFile()
	{
		fstream MyFile;
		vector <clsSchoolSystem> _vTeacher;
		MyFile.open("Teachers.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsSchoolSystem Teacher = _ConvertTeachersToObjects(Line);
				_vTeacher.push_back(Teacher);
			}

			MyFile.close();
		}
		return _vTeacher;
	}
	void _Update()
	{
		
		vector <clsSchoolSystem> _vTeacher;
		_vTeacher = _LoadDateFromFile();

		for (clsSchoolSystem &T : _vTeacher)
		{
			if (T.IDTEACHERS() == IDTEACHERS())
			{
				T = *this;
				break;
			}
		}

		_SaveCleintsDataToFile(_vTeacher);
	}
	static clsSchoolSystem _GetSystemEmpty()
	{
		return clsSchoolSystem(enMode::eEmptyMode, "", "", "", "", "", "", "", "", "" , "");
	}
	void _AddTeacher()
	{
		_AddNewTeachers(_ConvertTeachrsObjectToLine(*this));
	}
	void _AddNewTeachers(string DataLine)
	{
		fstream MyFile;
		MyFile.open("Teachers.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}


	}
public:
	
	clsSchoolSystem(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AnotherNumber, string Address1
		, string Address2, string NumberOfHouse, string IDTeachers , string Password) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AnotherNumber = AnotherNumber;
		_Address1 = Address1;
		_Address2 = Address2;
		_NumberOfHouse = NumberOfHouse;
		_IDTeachers = IDTeachers;
		_Password = Password;

	}
	bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}
	bool MarkForDeleted()
	{
		return _MarkDeleteTeacher;
	}
	void SetAnotherNumber(string AnotherNumber)
	{
		_AnotherNumber = AnotherNumber;
	}
	string GetAnotherNumber()
	{
		return _AnotherNumber;
	}
	__declspec(property(get = GetAnotherNumber, put = SetAnotherNumber))string AnotherNumber;
	void SetAddress1(string Address1)
	{
		_Address1 = Address1;
	}
	string GetAddress1()
	{
		return _Address1;
	}
	__declspec(property(get = GetAddress1, put = SetAddress1))string Address1;
	void SetAddress2(string Address2)
	{
		_Address2 = Address2;
	}
	string GetAddress2()
	{
		return _Address2;
	}
	__declspec(property(get = GetAddress2, put = SetAddress2))string Address2;
	void SetNumberOfHouse(string NumberOfHouse)
	{
		_NumberOfHouse = NumberOfHouse;
	}
	string GetNumberOfHouse()
	{
		return _NumberOfHouse;
	}
	__declspec(property(get = GetNumberOfHouse, put = SetNumberOfHouse))string NumberOfHouse;
	string IDTEACHERS()
	{
		return _IDTeachers;
	}
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword))string Password;
	bool Delete()
	{
		vector <clsSchoolSystem> _vTeacher;
		_vTeacher = _LoadDateFromFile();
		for (clsSchoolSystem& T : _vTeacher)
		{
			if (T.IDTEACHERS() == _IDTeachers)
			{
				T._MarkDeleteTeacher = true;
				break;
			}


		}
		 
		
		*this = _GetSystemEmpty();
		_SaveCleintsDataToFile(_vTeacher);
		return true;
	}
	static clsSchoolSystem FindTeachersByID(string IDNnmber)
	{
		fstream MyFile;
		MyFile.open("Teachers.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				clsSchoolSystem Teacher = _ConvertTeachersToObjects(Line);
				if (Teacher.IDTEACHERS() == IDNnmber)
				{
					MyFile.close();
					return Teacher;
				}

			}

			MyFile.close();
		}

		return _GetSystemEmpty();
	}
	static clsSchoolSystem FindTeachersName(string FullName)
	{
		fstream MyFile;
		MyFile.open("Teachers.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				clsSchoolSystem Teacher = _ConvertTeachersToObjects(Line);
				if (Teacher.FullName() == FullName)
				{
					MyFile.close();
					return Teacher;
				}

			}

			MyFile.close();
		}

		return _GetSystemEmpty();
	}
	static clsSchoolSystem Find(string IDNnmber , string Password)
	{
		fstream MyFile;
		MyFile.open("Teachers.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{

				clsSchoolSystem Teacher = _ConvertTeachersToObjects(Line);
				if (Teacher.IDTEACHERS() == IDNnmber && Teacher.Password == Password)
				{
					MyFile.close();
					return Teacher;
				}

			}

			MyFile.close();
		}

		return _GetSystemEmpty();
	}
	static bool IsExitTeacher(string IDNumber)
	{
		clsSchoolSystem Teacher = clsSchoolSystem::FindTeachersByID(IDNumber);
		return (!Teacher.IsEmpty());
	}
	static bool IsExitTeacherName(string Name)
	{
		clsSchoolSystem Teacher = clsSchoolSystem::FindTeachersName(Name);
		return (!Teacher.IsEmpty());
	}
	static clsSchoolSystem GetAddNewTeachers(string IDNumber)
	{
		return clsSchoolSystem(enMode::eAddMode, "", "", "", "", "", "", "", "", IDNumber , "");
	}
	enum enSaveResultTeacher { svSeccussed = 0, svObjectEmpty = 1, svFaildToSaveObject = 2 };
	enSaveResultTeacher Save()
	{
		switch (_Mode)
		{
		case enMode::eEmptyMode:
		{
			if (clsSchoolSystem::IsEmpty())
			{

				return enSaveResultTeacher::svObjectEmpty;

			}
			break;
		}

		case enMode::eUpdateMode:
		{
			_Update();
			return enSaveResultTeacher::svSeccussed;
			break;
		}

		case enMode::eAddMode:
		{
			if (clsSchoolSystem::IsExitTeacher(_IDTeachers))
			{
				return enSaveResultTeacher::svFaildToSaveObject;
			}
			else
			{
				_AddTeacher();
				_Mode = eUpdateMode;
				return enSaveResultTeacher::svSeccussed;
			}
			break;
		}

		}
	}
	static vector <clsSchoolSystem>  GetLoadNumberOfTeachers()
	{
		 return _LoadDateFromFile();
	}

};

