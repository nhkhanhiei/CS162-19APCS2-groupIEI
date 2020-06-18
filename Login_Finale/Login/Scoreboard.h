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

void toUpper(char& c);
void viewScoreboard();
void exportScoreboard();