#ifndef _COURSES_H_
#define _COURSES_H_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <iomanip>
using namespace std;


//Create / update / delete / view academic years and semesters

struct Semester
{
	string year, semester;
};

void CreateYandS();
void UpdateYandS();
void DeleteYandS();
void ViewYandS();

struct DateCourses
{
	int day, month, year;
};

struct CourseData
{
	int id;
	string courseID;
	string courseName;
	string Class;
	string lecturerUsername;
	string lecturerName;
	string lecturerDegree;
	string lecturerGender;
	DateCourses startDate;
	DateCourses endDate;
	int dayStudy;
	int startHour;
	int startMin;
	int endHour;
	int endMin;
	string lectureRoom;
};
typedef CourseData CSD;

struct StudentCourses
{
	string id, password, name, DoB, Class, status;
};

DateCourses stringToDate(string a);
int DayStudy(string a);
string dayFormat(int a);
string AttendanceDate(DateCourses a, int skip, int starth, int startm, int endh, int endm);
void CreateCourseSchedule(string year, string semester, string Class, CSD schedule[], int k);
void CreateCourseStudent(string year, string semester, string Class, CSD schedule[], int k);
void UpdateLecturer();
void ImportAndCreateFile();
void AddNewCourse();
void EditCourse();
void RemoveCourse();
void RemoveStudentFromCourse();
string DoBtoPassword(string input);
void AddNewStudentToCourse();
void ViewListOfCourse();
void ViewListOfStudentInCourse();
void ViewAttendanceListOfCourse();
void ViewAllLecturers();

















#endif // !_COURSES_H_

