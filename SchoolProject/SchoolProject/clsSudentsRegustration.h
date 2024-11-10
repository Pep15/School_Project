//#pragma once
//#include <iostream>
//#include <vector>
//#include <fstream>
//#include "clsSystemSubjects.h"
//#include "clsString.h"
//#include "clsUtil.h"
//using namespace std;
//class clsSudentsRegustration : public clsSystemSubjects
//{
//private:
//
//	enum Mode {eAddMode = 1 , eUpdateMode=2 , eEmptyMode=3};
//	Mode _Mode;
//	string _Subjects;
//	string _CodeSubject;
//	string _Credits;
//	string _Class;
//	string _NameTeacher;
//	string _IDTeacher;
//	//clsSystemSubjects _Regustration;
//	bool _FlageDeleteSubject = false;
//	
//	static clsSudentsRegustration GetEmptyRegustration()
//	{
//		return clsSudentsRegustration(Mode::eEmptyMode, "", "", "", "", "", "");
//	}
//	static vector <clsSystemSubjects> _LoadDateFromFile()
//	{
//		fstream MyFile;
//		MyFile.open("Regustration.txt", ios::in);
//		vector <clsSystemSubjects> _vRegustration;
//		string Line;
//		if (MyFile.is_open())
//		{
//			while (getline(MyFile , Line))
//			{
//				clsSystemSubjects Regustratuion = clsSystemSubjects::ConvertSubjectToObjects(Line);
//				_vRegustration.push_back(Regustratuion);
//			}
//			MyFile.close();
//		}
//
//		return _vRegustration;
//	}
//	static void _SaveDateToFile(vector <clsSystemSubjects> _vRegustration , string CodeSubject)
//	{
//		fstream Myfile;
//		Myfile.open("Regustration.txt", ios::out | ios::app);
//
//		if (Myfile.is_open())
//		{
//			string Line;
//			for (clsSystemSubjects& R : _vRegustration)
//			{
//				if (R.GetCodeSubjects() == CodeSubject)
//				{
//					Line = clsSystemSubjects::_ConvertObjectsSubjectToLine(R);
//					
//					Myfile << Line << endl;
//				}
//			}
//
//			
//			
//		}
//		GetAddNewSubjects(CodeSubject);
//		Myfile.close();
//		
//	}
//	void _AddNewSubjectsRegustar()
//	{
//		_AddNewSubject(_ConvertObjectsSubjectToLine(*this));
//	}
//	void _AddNewSubjectRegustration(string Line)
//	{
//		fstream MyFile;
//		MyFile.open("Regustration.txt", ios::out | ios::app);
//
//		if (MyFile.is_open())
//		{
//			MyFile << Line << endl;
//			MyFile.close();
//		}
//	}
//	void _Update()
//	{
//		vector <clsSystemSubjects> _vRegustration;
//		_vRegustration = _LoadDateFromFile();
//
//		for (clsSystemSubjects& R : _vRegustration)
//		{
//			if (R.GetCodeSubjects() == _CodeSubject)
//			{
//				R = *this;
//				break;
//			}
//		}
//
//		_SaveDateToFile(_vRegustration , _CodeSubject);
//	}
//
//public:
//
//	
//	clsSudentsRegustration(Mode Mode,string Subjects, string CodeSubjects , string Credits , string Class , string NameTeacher , string IDTeacher ) :
//		clsSystemSubjects((clsSystemSubjects::Mode)Mode,Subjects , CodeSubjects, Credits , Class , IDTeacher , NameTeacher)
//	{
//		_Mode = Mode;
//		_Subjects = Subjects;
//		_CodeSubject = CodeSubjects;
//		_Credits = Credits;
//		_Class = Class;
//		_NameTeacher = NameTeacher;
//		_IDTeacher = IDTeacher;
//	}
//	bool isEmpty()
//	{
//		return (_Mode == Mode::eEmptyMode);
//	}
//	bool MarkForDeleteSubject()
//	{
//		return _FlageDeleteSubject;
//	}
//	string GetCodeSubject()
//	{
//		return _CodeSubject;
//	}
//	string GetSubject()
//	{
//		return _Subjects;
//	}
//	string GetCredits()
//	{
//		return _Credits;
//	}
//	string GetClass()
//	{
//		return _Class;
//	}
//	string GetNameTeacher()
//	{
//		return _NameTeacher;
//	}
//	string GetIDTeacher()
//	{
//		return _IDTeacher;
//	}
//	bool Delete()
//	{
//		vector <clsSystemSubjects> _vRegustration;
//		_vRegustration = _LoadDateFromFile();
//		for (clsSystemSubjects& R : _vRegustration)
//		{
//			if (R.GetCodeSubjects() == _CodeSubject)
//			{
//				R.FlagDeletedSubject() = true;
//				break;
//			}
//		}
//
//		_SaveDateToFile(_vRegustration, _CodeSubject);
//		*this = GetEmptyRegustration();
//		return true;
//	}
//	bool isExsit(string CodeSubject)
//	{
//		clsSystemSubjects Regustration = clsSystemSubjects::Find(CodeSubject);
//		return (!Regustration.IsEmpty());
//	}
//	static clsSystemSubjects FindByCodeSubject(string CodeSubjects)
//	{
//		fstream MyFile;
//		
//		MyFile.open("Regustration.txt", ios::in);
//		if (MyFile.is_open())
//		{
//			string Line;
//			while (getline(MyFile, Line))
//			{
//				clsSystemSubjects Regustration =  clsSystemSubjects::ConvertSubjectToObjects(Line);
//				
//				if (Regustration.GetCodeSubjects() == CodeSubjects)
//				{
//					return Regustration;
//					MyFile.close();
//				}
//			}
//			MyFile.close();
//		}
//
//
//		GetEmptyRegustration();
//	}
//	enum enSaveResultRegustration{ svSeccussed = 0, svObjectEmpty = 1, svFaildToSaveObject = 2 };
//	  enSaveResultRegustration save()
//	{
//		switch (_Mode)
//		{
//		case clsSudentsRegustration::eAddMode:
//		{
//			if (clsSudentsRegustration::isExsit(_CodeSubject))
//			{
//				return enSaveResultRegustration::svFaildToSaveObject;
//			}
//			else
//			{
//				_AddNewSubjectsRegustar();
//				_Mode = Mode::eUpdateMode;
//				return enSaveResultRegustration::svSeccussed;
//			}
//		}
//		case clsSudentsRegustration::eUpdateMode:
//		{
//			_Update();
//			return enSaveResultRegustration::svSeccussed;
//			break;
//		}
//		case clsSudentsRegustration::eEmptyMode:
//		{
//			if (clsSystemSubjects::IsEmpty())
//			{
//				return enSaveResultRegustration::svObjectEmpty;
//			}
//
//			break;
//		}
//		}
//	}
//
//	static vector <clsSystemSubjects> GetLoadDateFromFile()
//	{
//		return _LoadDateFromFile();
//	}
//	static void SaveFile(vector <clsSystemSubjects> _vRegstration , string CodeSubject)
//	{
//		_SaveDateToFile(_vRegstration  , CodeSubject);
//	}
//
//	static clsSudentsRegustration GetAddNewSubjects(string CodeSubject)
//	{
//		return clsSudentsRegustration(Mode::eAddMode , "", CodeSubject, "", "", "", "");
//	}
//};
//
