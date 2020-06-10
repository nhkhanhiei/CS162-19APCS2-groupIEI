#ifndef _HAHA_H_
#define _HAHA_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Date {
	int day, month, year;
};

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

void NhapSVtuFile(Student*& a, int& n);
void Doc(Student a[], int n);
void Login(Student a[], int n);
void ManHinhChinh(Student a[], int n);
void MenuSinhVien(Student a[], int n, int i);



#endif
