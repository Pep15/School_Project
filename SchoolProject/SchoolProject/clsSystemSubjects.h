#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsSchoolSystem.h"
#include "clsPerson.h"
#include "clsString.h"
#include "clsUtil.h"
#include "Global.h"
using namespace std;
class clsSystemSubjects 
{
private:
	struct stRegustrtion;
	enum Mode {AddMode , UpdateMode , EmptyMode};
	Mode _Mode;
	string _Subjects;
	string _CodeSubject;
	string _Credits;
	string _Class;
	string _IDTeacher;
	string _NameTeacher;
	bool _FlagDeletedSubjects = false;
	static stRegustrtion _ConvertSubjectRegustrationToObject(string Line, string Sepretoer = "#//#")
	{
		vector <string> _vRegustration;
		stRegustrtion Reguster;
		_vRegustration = clsString::Split(Line, Sepretoer);
		Reguster.sUpdateMode;
		Reguster.Subjects += _vRegustration[0];
		Reguster.CodeSubject += _vRegustration[1];
		Reguster.Credits += _vRegustration[2];
		Reguster.Class += _vRegustration[3];
		Reguster.IDTeacher += _vRegustration[4];
		Reguster.NameTeacher += _vRegustration[5];

		return Reguster;
	}
	 static string _ConvertSubjectRegustrationToLine(stRegustrtion Regustration,string Sepretoer = "#//#")
	{
		string DataLine;

		DataLine += Regustration.Subjects + Sepretoer;
		DataLine += Regustration.CodeSubject + Sepretoer;
		DataLine += Regustration.Credits + Sepretoer;
		DataLine += Regustration.Class+ Sepretoer;
		DataLine += Regustration.IDTeacher + Sepretoer;
		DataLine += Regustration.NameTeacher ;

		return DataLine;
	}
	static clsSystemSubjects _ConvertSubjectToObjects(string Line, string Sepretoer = "#//#")
	{
		vector <string> _vSubjects;
		
		_vSubjects = clsString::Split(Line, Sepretoer);
		
		return clsSystemSubjects(Mode::UpdateMode, _vSubjects[0] , _vSubjects[1] , _vSubjects[2] , _vSubjects[3] , _vSubjects[4] , _vSubjects[5]);
	}
	static vector <clsSystemSubjects> _LoadDateFromFile()
	{
		vector <clsSystemSubjects> _vSubjects;
		fstream MyFile;
		MyFile.open("Subjects.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsSystemSubjects Subjects = _ConvertSubjectToObjects(Line);
				_vSubjects.push_back(Subjects);
			}

			MyFile.close();
		}
		
		return _vSubjects;
	}

	static vector <clsSystemSubjects::stRegustrtion> _LoadDateFromFileForReguster()
	{
		vector <clsSystemSubjects::stRegustrtion> _vRegustration;
		fstream MyFile;
		MyFile.open("Subjects.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsSystemSubjects::stRegustrtion Regustration = _ConvertSubjectRegustrationToObject(Line);
				_vRegustration.push_back(Regustration);
			}

			MyFile.close();
		}

		return _vRegustration;
	}
	static vector <clsSystemSubjects::stRegustrtion> _LoadDateFromFileForRegusterDeleted()
	{
		vector <clsSystemSubjects::stRegustrtion> _vRegustration;
		fstream MyFile;
		MyFile.open("Regustration.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsSystemSubjects::stRegustrtion Regustration = _ConvertSubjectRegustrationToObject(Line);
				_vRegustration.push_back(Regustration);
			}

			MyFile.close();
		}

		return _vRegustration;
	}
	static void _SaveDateToFile(vector <clsSystemSubjects> _vSubjects)
	{
		fstream MyFile;
		MyFile.open("Subjects.txt", ios::out);
		
		if (MyFile.is_open())
		{
			string Line;
			for (clsSystemSubjects& S : _vSubjects)
			{
				if (S.FlagDeletedSubject() == false)
				{
					Line = _ConvertObjectsSubjectToLine(S);
					MyFile << Line << endl;
				}
			}
		}

		MyFile.close();

	}
	static void _SaveDateToFileForRegustration(vector <stRegustrtion> _vRegustration , string CodeSubject)
	{
		fstream MyFile;
		MyFile.open("Regustration.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			string Line;
			for (clsSystemSubjects::stRegustrtion& R : _vRegustration)
			{
				if (R.CodeSubject == CodeSubject)
				{
					Line = clsSystemSubjects::_ConvertSubjectRegustrationToLine(R);
					MyFile << Line << endl;
				}
			}
		}

		MyFile.close();

		

	}
	static void _SaveDateToFileForDeleteRegstration(vector <stRegustrtion> &_vRegustration)
	{
		fstream MyFile;
		MyFile.open("Regustration.txt", ios::out);

		if (MyFile.is_open())
		{
			string Line;
			for (clsSystemSubjects::stRegustrtion& R : _vRegustration)
			{
				if (R.FlagDeletedSubjects == false)
				{
					Line = _ConvertSubjectRegustrationToLine(R);
					MyFile << Line << endl;
				}
			}
		}

		MyFile.close();

		

	}
	static string _ConvertObjectsSubjectToLine(clsSystemSubjects Subject, string Seporter = "#//#")
	{
		string DataLine;
		DataLine += Subject.Subject + Seporter;
		DataLine += Subject.GetCodeSubjects() + Seporter;
		DataLine += Subject.Creadits + Seporter;
		DataLine += Subject.Class + Seporter;
		DataLine += Subject.IDTeacher + Seporter;
		DataLine += Subject.NameTeacher;


		return DataLine;
	}
	static clsSystemSubjects _GetEmptySubjects()
	{
		return clsSystemSubjects(Mode::EmptyMode, "", "", "" , "" , ""  , "");
	}
	void _AddSubject()
	{
		_AddNewSubject(_ConvertObjectsSubjectToLine(*this));
	}
	void _AddNewSubject(string Line)
	{
		fstream MyFile;
		MyFile.open("Subjects.txt", ios::out | ios::app);
		
		if (MyFile.is_open())
		{
			MyFile << Line << endl;
			MyFile.close();
		}
	}
	void _Update()
	{
		vector <clsSystemSubjects> _vSubjects;
		_vSubjects = _LoadDateFromFile();

		for (clsSystemSubjects& S : _vSubjects)
		{
			if (S.Subject == S.Subject)
			{
				S = *this;
				break;
			}
		}

		_SaveDateToFile(_vSubjects);
	}
public:
	
	struct stRegustrtion
	{
		
		enum stMode { sAddMode, sUpdateMode, sEmptyMode };
		stMode  smode;
		string Subjects;
		string CodeSubject;
		string Credits;
		string Class;
		string NameTeacher;
		string IDTeacher;
		bool FlagDeletedSubjects = false;
		bool DeleteForRegustration()
		{
			vector <clsSystemSubjects::stRegustrtion> _vRegstration;
			_vRegstration = _LoadDateFromFileForRegusterDeleted();
			for (clsSystemSubjects::stRegustrtion& R : _vRegstration)
			{
				if (R.CodeSubject == CodeSubject)
				{
					R.FlagDeletedSubjects = true;
					break;
				}
			}

			_SaveDateToFileForDeleteRegstration(_vRegstration);
			return true;
			
		}
		
	};
	clsSystemSubjects(Mode Mode, string Subjects, string CodeSubject, string Credits,  string Class , string IDTeacher , string NameTeacher ) 
	{
		_Mode = Mode;
		_Subjects = Subjects;
		_CodeSubject = CodeSubject;
		_Credits = Credits;
		_Class = Class;
		_IDTeacher = IDTeacher;
		_NameTeacher = NameTeacher;
		
	}
	bool IsEmpty()
	{
		return (_Mode == Mode::EmptyMode);
	}
	bool& FlagDeletedSubject()
	{
		return _FlagDeletedSubjects;
	}
	void SetSubjects(string Subject)
	{
		_Subjects = Subject;
	}
	string GetSubjects()
	{
		return _Subjects;
	}
	__declspec(property(get = GetSubjects, put = SetSubjects))string Subject;
	string GetCodeSubjects()
	{
		return _CodeSubject;
	}
	void SetCredits(string Credits)
	{
		_Credits = Credits;
	}
	string GetCreadits()
	{
		return _Credits;
	}
	__declspec(property(get = GetCreadits, put = SetCredits))string Creadits;
	void SetClass(string Class)
	{
		_Class = Class;
	}
	string GetClass()
	{
		return _Class;
	}
	__declspec(property(get = GetClass, put = SetClass))string Class;
	void SetIDTeacher(string IDTeacher)
	{
		_IDTeacher = IDTeacher;
	}
	string GetIDTeacher()
	{
		return _IDTeacher;
	}
	__declspec(property(get = GetIDTeacher, put = SetIDTeacher))string IDTeacher;
	void SetNameTeacher(string NameTeacher)
	{
		_NameTeacher = NameTeacher;
	}
	string GetNameTeacher()
	{
		return _NameTeacher;
	}
	__declspec(property(get = GetNameTeacher, put = SetNameTeacher))string NameTeacher;
	static clsSystemSubjects Find(string CodeSubject)
	{
		fstream MyFile;
		MyFile.open("Subjects.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsSystemSubjects Subject = _ConvertSubjectToObjects(Line);

				if (Subject.GetCodeSubjects() == CodeSubject)
				{
					return Subject;
					MyFile.close();
				}
			}

			MyFile.close();
		}

		return _GetEmptySubjects();
	}
	static bool CheckCodeSubject(string CodeSubject)
	{
		fstream MyFile;
		MyFile.open("Regustration.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				stRegustrtion Regustration = _ConvertSubjectRegustrationToObject(Line);

				if (Regustration.CodeSubject == CodeSubject)
				{
					return true;
					MyFile.close();
				}
			}

			MyFile.close();
		}

		return false;
		
	}
	static stRegustrtion FindRegstration(string CodeSubject)
	{
		fstream MyFile;
		MyFile.open("Regustration.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				stRegustrtion Regustration = _ConvertSubjectRegustrationToObject(Line);

				if (Regustration.CodeSubject == CodeSubject)
				{
					return Regustration;
					MyFile.close();
				}
			}

			MyFile.close();
		}

		

	}
	static bool IsExitCodeSubjet(string CodeSubject)
	{
		clsSystemSubjects Subjects = clsSystemSubjects::Find(CodeSubject);
		return (!Subjects.IsEmpty());
	}
	bool Delete()
	{
		vector <clsSystemSubjects> _vSubjects;
		_vSubjects = _LoadDateFromFile();
		for (clsSystemSubjects& S : _vSubjects)
		{
			if (S.GetCodeSubjects() == _CodeSubject)
			{
				S._FlagDeletedSubjects = true;
				break;
			}
		}

		_SaveDateToFile(_vSubjects);
		*this = _GetEmptySubjects();
		return true;
	}
	
	enum enSccessedSubjects { svSeccussed = 0, svObjectEmpty = 1, svFaildToSaveObject = 2 };
	enSccessedSubjects Save()
	{
		switch (_Mode)
		{
		case clsSystemSubjects::AddMode:
			if (clsSystemSubjects::IsExitCodeSubjet(Subject))
			{
				return enSccessedSubjects::svFaildToSaveObject;
			}
			else
			{
				_AddSubject();
				_Mode = UpdateMode;
				return enSccessedSubjects::svSeccussed;
			}
			break;
		case clsSystemSubjects::UpdateMode:
		{
			_Update();
			return enSccessedSubjects::svSeccussed;
			break;
		}	
		case clsSystemSubjects::EmptyMode:
		{
			if (clsSystemSubjects::IsEmpty())
			{
				return enSccessedSubjects::svObjectEmpty;
			}

			break;
		}
			
		}
	}
	static vector <clsSystemSubjects> GetDataFromFile()
	{
		return _LoadDateFromFile();
	}
	static clsSystemSubjects GetAddNewSubjects(string CodeSubject)
	{
		return clsSystemSubjects(Mode::AddMode, "" , CodeSubject , "" , "" , ""  , "");
	}
	static clsSystemSubjects ConvertSubjectToObjects(string Line)
	 {
		return _ConvertSubjectToObjects(Line);
	 }
	static vector <stRegustrtion> LoadDateFromFileForReguster()
	{
		return _LoadDateFromFileForReguster();
	}
	static void SaveFileForStudentRegustration(vector <stRegustrtion> _vRegustration , string CodeSubject)
	{
		_SaveDateToFileForRegustration(_vRegustration , CodeSubject);
	}
	
	static vector <stRegustrtion> LoadDateShownSubjectRegstration()
	{
		return _LoadDateFromFileForRegusterDeleted();
	}
};

