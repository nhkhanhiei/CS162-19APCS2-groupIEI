#ifndef _STAFF_CLASS_H_
#define _STAFF_CLASS_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <sstream>

using namespace std;

struct DateClass
{
	string day;
	string month;
	string year;
};

struct StudentClass
{
	int id = 0;
	string password;
	string fullname;
	DateClass dob;
	int status = 0;
};

void toUpper(char& c);
int viewClass();
int viewStudent();
void addStudent();
void removeStudent();
void editStudent();
void changeClassStudent();
void importClass();


#endif