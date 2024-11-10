#pragma once
#include <iostream>
#include "clsAdminSchoolSystem.h"
#include "clsSchoolSystem.h"
#include "clsStudentSystem.h"
#include "clsSystemSubjects.h"
using namespace std;
clsSchoolSystem Teachers = clsSchoolSystem::Find("", "");
clsAdminSchoolSystem Users = clsAdminSchoolSystem::Find("", "");
clsStudentSystem Students = clsStudentSystem::FindByEmailIDStudentsPassword("", "");






