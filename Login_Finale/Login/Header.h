#ifndef _HAHA_H_
#define _HAHA_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Date {
	int day, month, year;
};
// Account database
struct Student
{
	int id = 0;
	string password;
	string fullname;
	Date dob;
	string classes;
	int status = 0;
};

struct Lecturer {
	string username;
	string password;
	string Fullname;
	string Occupation;
	int gender;
};

struct Staff {
	string username;
	string pass;
	string fullname;
	int gend;
};

// GUI
void Login(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2);
void ManHinhChinh(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2);
void MenuSinhVien(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i);
void MenuStaff(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i);
void MenuLecturer(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i);
//-------------------------------------------------------------------------------------
//Supplement menu
void MenuStaffClass(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i);
void MenuStaffCourses(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i);
void MenuStaffCoursesYearsSemesters(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i);
//void MenuStaffLecturer(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i);
void MenuStaffScoreBoard(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i);
void MenuStaffAttendance(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i);


//-------------------------------------------------------------------------------------
void SettingSV(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i);
void SettingStaff(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i);
void SettingLecturer(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i);

string ChangePassword(string oldpass);

// Student function
void NhapSVtuFile(Student*& a, int& n);
void Doc(Student a[], int n);
void CapNhatPassSV(Student a[], int n, string newpass, int index);
void StudentProfile(Student a[], int n, int i);

// Staff function
void NhapStafftuFile(Staff*& a, int& n);
void DocStaff(Staff a[], int n);
void StaffProfile(Staff b[], int n1, int i);
void CapNhatPassStaff(Staff a[], int n, string newpass, int index);


//Lecturer functions
void NhapLecturertuFile(Lecturer*& c, int& n2);
void DocLecturer(Lecturer c[], int n2);
void LecturerProfile(Lecturer c[], int n2, int i);
void CapNhatPassLecturer(Lecturer a[], int n, string newpass, int index);
#endif
