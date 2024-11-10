#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsDate.h"
#include "clsString.h"
#include "clsUtil.h"
#include "clsPerson.h"
using namespace std;
class clsStudentSystem : public clsPerson
{
private:

	enum Mode { AddMode = 1, UpdateMode = 2, EmptyMode = 3 };
	Mode _Mode;
	string _ID_Students;
	string _Address;
	string _NumberOfHouse;
	string _NumberOfFather;
	string _NumberOfMother;
	string _Password;
	string _Age;
	bool _FlageStudentsDelete = false;
	static clsStudentSystem _ConvertStudentsToObjects(string Line, string Speroter = "#//#")
	{
		vector <string> _vStudents;
		_vStudents = clsString::Split(Line, Speroter);

		return clsStudentSystem(Mode::UpdateMode, _vStudents[0], _vStudents[1], _vStudents[2], _vStudents[3]
			, _vStudents[4], _vStudents[5], _vStudents[6], _vStudents[7], _vStudents[8], _vStudents[9], _vStudents[10]);
	} 
	static string _ConvertStudentsObjectToLine(clsStudentSystem Students, string Speroter = "#//#")
	{
		string DataStudents;
		DataStudents += Students.FirstName + Speroter;
		DataStudents += Students.LastName + Speroter;
		DataStudents += Students.Email + Speroter;
		DataStudents += Students.Phone + Speroter;
		DataStudents += Students.GetIDstudents() + Speroter;
		DataStudents += Students.Address + Speroter;
		DataStudents += Students.NumberOfHouse + Speroter;
		DataStudents += Students.NumberOfFather + Speroter;
		DataStudents += Students.NumberOfMother + Speroter;
		DataStudents += Students.Password + Speroter;
		DataStudents += Students.Age;

		return DataStudents;
	}
	static clsStudentSystem _GetEmptyStudents()
	{
		return clsStudentSystem(Mode::EmptyMode, "", "", "", "", "", "", "", "", "", "", "");
	}
	static vector <clsStudentSystem> _LoadDateFromFile()
	{
		vector <clsStudentSystem> _vStudents;
		fstream MyFile;
		MyFile.open("Students.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsStudentSystem Students = _ConvertStudentsToObjects(Line);
				_vStudents.push_back(Students);
			}
		}

		return _vStudents;
	}
	static void SaveDateToFile(vector <clsStudentSystem> _vStudents)
	{
		fstream MyFile;
		MyFile.open("Students.txt", ios::out);
		string DataLine;
		if (MyFile.is_open())
		{
			for (clsStudentSystem S : _vStudents)
			{
				if (S._FlageStudentsDelete == false)
				{
					DataLine = _ConvertStudentsObjectToLine(S);
					MyFile << DataLine << endl;
					
				}
			}

			MyFile.close();
		}
	}
	void AddStudents()
	{
		AddNewStudents(_ConvertStudentsObjectToLine(*this));
	}
	void AddNewStudents(string Line)
	{
		fstream MyFile;
		MyFile.open("Students.txt", ios::out | ios::app);
		
		if (MyFile.is_open())
		{

			MyFile << Line << endl;
			MyFile.close();

		}
	}
	void _Update()
	{
		vector <clsStudentSystem> _vStudents;
		_vStudents = _LoadDateFromFile();

		for (clsStudentSystem &S : _vStudents)
		{
			if (S.GetIDstudents() == S.GetIDstudents())
			{
				S = *this;
			}
		}

		SaveDateToFile(_vStudents);
	}

public:


	clsStudentSystem(Mode Mode, string FirstName, string LastName, string Email, string Phone, string ID_Students,string Address, string NumberOFHouse
		, string NumberOfFather, string NumberOfMother, string Password, string Age) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_ID_Students = ID_Students;
		_Address = Address;
		_NumberOfHouse = NumberOFHouse;
		_NumberOfFather = NumberOfFather;
		_NumberOfMother = NumberOfMother;
		_Password = Password;
		_Age = Age;
	}
	bool MarkForDelete()
	{
		return _FlageStudentsDelete;
	}
	bool IsEmpty()
	{
		return (_Mode == Mode::EmptyMode);
	}
	string GetIDstudents()
	{
		return _ID_Students;
	}
	void SetAddress(string Address)
	{
		_Address = Address;
	}
	string GetAddress()
	{
		return _Address;
	}
	__declspec(property(get = GetAddress, put = SetAddress))string Address;
	void SetNumberOfHouse(string NumberOfHouse)
	{
		_NumberOfHouse = NumberOfHouse;
	}
	string GetNumberOfHouse()
	{
		return _NumberOfHouse;
	}
	__declspec(property(get = GetNumberOfHouse, put = SetNumberOfHouse))string NumberOfHouse;
	void SetNumberOfFather(string NumberOfFather)
	{
		_NumberOfFather = NumberOfFather;
	}
	string GetNumberOfFather()
	{
		return _NumberOfFather;
	}
	__declspec(property(get = GetNumberOfFather, put = SetNumberOfFather))string NumberOfFather;
	void SetNumberOfMother(string NumberOfMoather)
	{
		_NumberOfMother = NumberOfMoather;
	}
	string GetNumberOfMother()
	{
		return _NumberOfMother;
	}
	__declspec(property(get = GetNumberOfMother, put = SetNumberOfMother))string NumberOfMother;
	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword))string Password;
	void SetAge(string Age)
	{
		_Age = Age;
	}
	string GetAge()
	{
		return _Age;
	}
	__declspec(property(get = GetAge, put = SetAge))string Age;
	static clsStudentSystem FindByIDStudents(string IDStudents)
	{
		fstream MyFile;
		MyFile.open("Students.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsStudentSystem Students = _ConvertStudentsToObjects(Line);

				if (Students.GetIDstudents() == IDStudents)
				{
					MyFile.close();
					return Students;
				}

				
			}
			
			MyFile.close();
		}
		return _GetEmptyStudents();
	}
	static clsStudentSystem FindByEmailIDStudentsPassword(string Email , string Password)
	{
		fstream MyFile;
		MyFile.open("Students.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsStudentSystem Students = _ConvertStudentsToObjects(Line);

				if (Students.Email == Email && Students.Password == Password)
				{
					MyFile.close();
					return Students;
				}

				MyFile.close();
			}
			return _GetEmptyStudents();
		}
	}
	bool Delete()
	{
		fstream Myfile;
		vector <clsStudentSystem> _vStudents;
		
		_vStudents = _LoadDateFromFile();
		Myfile.open("Students.txt", ios::out);
			for (clsStudentSystem S : _vStudents)
			{
				if (S.GetIDstudents() == _ID_Students)
				{
					S._FlageStudentsDelete = true;
					break;
				}
			}

			*this = _GetEmptyStudents();

			return true;
	}
	static bool IsExsitStudents(string IDStudents)
	{
		clsStudentSystem Students = clsStudentSystem::FindByIDStudents(IDStudents);
		return (!Students.IsEmpty());
	}
	enum enSaveResultStudents { svSeccussed = 0, svObjectEmpty = 1, svFaildToSaveObject = 2 };
	enSaveResultStudents Save()
	{
		switch (_Mode)
		{
		case clsStudentSystem::AddMode:
		{
			if (IsExsitStudents(_ID_Students))
			{
				return enSaveResultStudents::svFaildToSaveObject;
			}
			else
			{
				AddStudents();
				_Mode = UpdateMode;
				return svSeccussed;
				break;
			}
		
			
		}
			
		case clsStudentSystem::UpdateMode:
		{
			_Update();
			return enSaveResultStudents::svSeccussed;
			break;
		}
			
		case clsStudentSystem::EmptyMode:
		{
			if (clsStudentSystem::IsEmpty())
			{
				AddStudents();
				return enSaveResultStudents::svObjectEmpty;
			}
		}
		}
	}
	static vector <clsStudentSystem> GetLoadDateFromFile()
	{
		return _LoadDateFromFile();
	}
	static clsStudentSystem GetAddNewStudents(string IDStudents)
	{
		return clsStudentSystem(Mode::AddMode, "", "", "", "", IDStudents, "", "", "", "", "", "");
	}
};

