#pragma once
#include <iostream>
#include <fstream>
#include "clsUtil.h"
#include "clsDate.h"
#include "clsString.h"
#include "clsPerson.h"
using namespace std;
class clsAdminSchoolSystem : public clsPerson
{
private:
	struct stLogsUsers;
	enum eMode { eAddMode = 1, eUpdateMode = 2, eEmptyMode = 3 };
	eMode _Mode;
	string _UserName;
	string _Password;
	int _Permessions;
	bool _MarkFlagDelet = false;
	static stLogsUsers _ConvertUsersToObjectLogs(string Line, string Sepratoer = "#//#")
	{
		vector <string> _Logs;
		_Logs = clsString::Split(Line , Sepratoer);
		stLogsUsers LogsUsrs;
		LogsUsrs.DataTime = _Logs[0];
		LogsUsrs.User = _Logs[1];
		LogsUsrs.Password = _Logs[2];
		LogsUsrs.Permssions = stoi(_Logs[3]);

		return LogsUsrs;
	}
	
	static  clsAdminSchoolSystem _ConvertUserToObject(string Line, string Sepratoer = "#//#")
	{
		vector <string> _vAdmin;
		_vAdmin = clsString::Split(Line, Sepratoer);


		return clsAdminSchoolSystem(eMode::eUpdateMode, _vAdmin[0], _vAdmin[1] , _vAdmin[2], _vAdmin[3], _vAdmin[4], clsUtil::DecryptText(_vAdmin[5],2),  stoi(_vAdmin[6]));
	}
	static string _ConvertUserObjectToLine(clsAdminSchoolSystem User, string Sepratoer = "#//#")
	{
		string DataLine;
		DataLine += User.FirstName + Sepratoer;
		DataLine += User.LastName + Sepratoer;
		DataLine += User.Phone + Sepratoer;
		DataLine += User.Email + Sepratoer;
		DataLine += User.GetUserName() + Sepratoer;
		DataLine += clsUtil::EncryptText(User.Password, 2)  + Sepratoer;
		DataLine += to_string(User.Permessions);

		return DataLine;
	}
	 string _ConvertUsersLogs(string Sepratoer = "#//#")
	{
		string DataLine;
		DataLine += clsDate::GetSystemDateTimeString() + Sepratoer;
		DataLine += GetUserName() + Sepratoer;
		DataLine += clsUtil::EncryptText(Password , 2) + Sepratoer;
		DataLine += to_string(Permessions);
		return DataLine;
	}
	static clsAdminSchoolSystem _GetObjectEmpty()
	{
		return clsAdminSchoolSystem(eMode::eEmptyMode, "", "", "", "", "", "", 0);
	}
	static void _SaveUserToFile(vector <clsAdminSchoolSystem> _vUser)
	{
		
		fstream Myfile;
		Myfile.open("user.txt", ios::out);
		string Line;
		if (Myfile.is_open())
		{
			
			for (clsAdminSchoolSystem U : _vUser)
			{
				if (U.MarkForDelete() == false)
				{
					Line = _ConvertUserObjectToLine(U);
					Myfile << Line << endl;
					Myfile.close();
				}
			}

			
		}
		
	}
	static vector <clsAdminSchoolSystem> _LoadDateUserfromFile()
	{
		fstream MyFile;
		vector <clsAdminSchoolSystem> _vUser;
		MyFile.open("user.txt", ios::in);
		string Line;
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsAdminSchoolSystem Users = _ConvertUserToObject(Line);
				_vUser.push_back(Users);
			}

			MyFile.close();
		}

		return _vUser;
	}
	 void _AddNewUser()
	{
		_AddUsers(_ConvertUserObjectToLine(*this));
	}
	 void _AddUsers(string Line)
	{
		vector <clsAdminSchoolSystem> _vUsers;
		fstream Myfile;
		Myfile.open("user.txt", ios::out | ios::app);
		
		if (Myfile.is_open())
		{
			Myfile << Line << endl;
			Myfile.close();
		}

	}
	 void _Update()
	 {
		 
		  vector <clsAdminSchoolSystem> _vUser;
		  _vUser = _LoadDateUserfromFile();
		 
		  for (clsAdminSchoolSystem& U : _vUser)
		  {
			  if (U.GetUserName() == GetUserName())
			  {
				  U = *this;
				  break;
			  }
		  }
		  _SaveUserToFile(_vUser);
	 }
	

public:

	struct stLogsUsers
	{
		string DataTime;
		string User;
		string Password;
		int Permssions;
	};
	enum EnPermssionsMangagments {eAll = -1 , eAdd=1 , eFind=2 , eUpdate=4 , eDelete=8 , eShowLists=16 , eLogsShows=32};
	clsAdminSchoolSystem(eMode Mode, string FirstName, string LastName, string Phone
		, string Email, string UserName, string Password, int Permessions)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permessions = Permessions;

	}
	bool MarkForDelete()
	{
		return _MarkFlagDelet;
	}
	bool Delet()
	{
		fstream MyFile;
		vector <clsAdminSchoolSystem> _vUser;
		_vUser = _LoadDateUserfromFile();
		MyFile.open("user.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsAdminSchoolSystem U : _vUser)
			{
				if (U.MarkForDelete() == _MarkFlagDelet)
				{
					U._MarkFlagDelet = true;
					break;
				}
			}

		}
		*this = _GetObjectEmpty();
		_SaveUserToFile(_vUser);
		return true;

	}
    bool IsEmpty()
	{
		return (_Mode == eMode::eEmptyMode);
	}
	string GetUserName()
	{
		return _UserName;
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
	void SetPermessions(int Permessions)
	{
		_Permessions = Permessions;
	}
	int GetPermessions()
	{
		return _Permessions;
	}
	__declspec(property(get = GetPermessions, put = SetPermessions))int Permessions;
	static clsAdminSchoolSystem FindByUserName(string UserName)
	{
		fstream Myfile;

		Myfile.open("user.txt", ios::in);

		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				clsAdminSchoolSystem User = clsAdminSchoolSystem::_ConvertUserToObject(Line);
				if (clsString::UpperAllString(User.GetUserName()) == clsString::UpperAllString(UserName))
				{
					Myfile.close();
					return User;

				}
			}
		}

		return  _GetObjectEmpty();
	}
	static clsAdminSchoolSystem Find(string UserName , string Password)
	{
		fstream Myfile;

		Myfile.open("user.txt", ios::in);

		if (Myfile.is_open())
		{
			string Line;
			while (getline(Myfile, Line))
			{
				clsAdminSchoolSystem User = clsAdminSchoolSystem::_ConvertUserToObject(Line);
				if (clsString::UpperAllString(User.GetUserName()) == clsString::UpperAllString(UserName) && User.Password == Password)
				{
					Myfile.close();
					return User;

				}
			}
		}

		return  _GetObjectEmpty();
	}
	static bool IsThereUsers(string UserName)
	{
		clsAdminSchoolSystem User = clsAdminSchoolSystem::FindByUserName(UserName);
		return (!User.IsEmpty());
	}
	enum enSccessfulSaveResult { vsSccessfull = 1, falidSaveSccessfull , ObjectEmpty=3};
	static clsAdminSchoolSystem GetAddNewUsers(string UserName)
	{
		return clsAdminSchoolSystem(eMode::eAddMode, "", "", "", "", UserName, "", 0);
	}
	 enSccessfulSaveResult Save()
	{
		switch (_Mode)
		{
		case clsAdminSchoolSystem::eAddMode:
		{
			if (IsThereUsers(_UserName))
			{
				return enSccessfulSaveResult::falidSaveSccessfull;
			}
			else
			{
				_AddNewUser();
				_Mode = eUpdateMode;
				return enSccessfulSaveResult::vsSccessfull;
			}
			break;
		}
		case clsAdminSchoolSystem::eUpdateMode:
		{
			_Update();
			return enSccessfulSaveResult::vsSccessfull;
			
		}
		break;
			
		case clsAdminSchoolSystem::eEmptyMode:
		{
			if (clsAdminSchoolSystem::IsEmpty())
			{
				return enSccessfulSaveResult::falidSaveSccessfull;
				
			}
			break;
		}
			
		}
	}
	static vector <clsAdminSchoolSystem> LoadDataFromFile()
	 {
		return  _LoadDateUserfromFile();
	 }
	 bool PermssionsRight(EnPermssionsMangagments Permssion)
	{
		if (this->Permessions == EnPermssionsMangagments::eAll)
			return true;
		if ((Permssion & this->Permessions) == Permssion)
			return true;
		else
			return false;
	}

	 void SaveLoginsToFiles()
	 {
		 fstream MyFile;
		 string Line = _ConvertUsersLogs();
		 MyFile.open("Logs.txt", ios::out | ios::app);
		 if (MyFile.is_open())
		 {
			 MyFile << Line << endl;
			 
		 }

		 MyFile.close();
	 }

	 static vector <stLogsUsers> GetLoadLogsUsers()
	 {
		 fstream Myfile;
		 vector <stLogsUsers> _Logs;
		 Myfile.open("Logs.txt", ios::in);
		 stLogsUsers ULogsUsers;
		 if (Myfile.is_open())
		 {
			 string DataLine;
			 while (getline(Myfile, DataLine))
			 {
				 ULogsUsers = _ConvertUsersToObjectLogs(DataLine);
				 _Logs.push_back(ULogsUsers);
			 }

			 Myfile.close();
		 }

		 return _Logs;
	 }
};

