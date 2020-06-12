#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<ctime>
#include<string>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

struct Dates
{
	int day;
	int month;
	int year;
};

struct StudentMenu
{
	string id, password, name, DoB, Class, status, midterm, final, bonus, total;
	string att[11];
};

struct Schedules
{
	Dates day[11];
	int startHour;
	int startMin;
	int endHour;
	int endMin;
};

void ViewAttendance();
void ExportAttendance();
void ViewStudentsList();
void EditAttendance();
void EditGrade();
//To see if the present time is one of the 9 periods in the file
int CheckTime(Schedules days);
void CheckIn();
void ViewCheckIn();
void ViewSchedules();
//Students
void ViewScore();

void toUpper(char& c);
void viewScoreboard();
void importScoreboard();
void exportScoreboard();