#include<iostream>
#include<fstream>
#include<string>
#include <cstring>
#include<sstream>
#include <cctype>
#include<algorithm>
#include<ctime>
#include<string>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

struct Date
{
	string day;
	string month;
	string year;
};

struct Student
{
	string id, password, name, DoB, Class, status, midterm, final, bonus, total;
	string att[11];
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
	string startDate;
	string endDate;
	string dayStudy;
	int startHour;
	int startMin;
	int endHour;
	int endMin;
	string lectureRoom;
};

void toUpper(char& c)
{
	c = toupper(static_cast<unsigned char>(c));
}

void importScoreboard()
{
	cout << "Input scoreboard you would like to export: \n" << endl;

	cout << "   Class: ";
	string classTemp;
	getline(cin, classTemp);
	for_each(classTemp.begin(), classTemp.end(), toUpper);

	cout << "   Course ID: ";
	string courseTemp;
	getline(cin, courseTemp);
	for_each(courseTemp.begin(), courseTemp.end(), toUpper);

	string fileCsv;
	fileCsv += classTemp + '-' + courseTemp + "-Scoreboard.csv";
	fstream fin;
	fin.open(fileCsv, ios::in);

	if (fin.fail())
	{
		cout << "Unable to open CSV file!" << endl;
		fin.close();
	}
	else
	{
		string Dump;
		int i = 0;
		while (!fin.eof())
		{
			getline(fin, Dump);
			i++;
		}
		fin.close();

		string* row;
		row = new string[i - 1];

		fstream fin2;
		fin2.open(fileCsv, ios::in);

		string linetemp;
		getline(fin2, linetemp);

		int z = 0;
		while (!fin2.eof())
		{
			getline(fin2, row[z]);
			for (int q = 0; q < row[z].length(); q++)
			{
				if (row[z][q] == ',')
				{
					row[z].erase(0, q + 1);
					break;
				}
			}
			z++;
		}

		fstream F;

		cout << "\n   School year (yyyy-yyyy) of class: ";
		string yearTemp;
		getline(cin, yearTemp);
		for_each(yearTemp.begin(), yearTemp.end(), toUpper);

		cout << "   Semester of class: ";
		string semTemp;
		getline(cin, semTemp);
		for_each(semTemp.begin(), semTemp.end(), toUpper);

		string Fname;
		Fname += yearTemp + '-' + semTemp + '-' + classTemp + '-' + courseTemp + "-Student.txt";

		F.open(Fname, ios::in);

		if (F.fail())
		{
			cout << "Unable to open file!" << endl;
			F.close();
			return;
		}

		string trash;
		int n;
		F >> n;
		F.ignore();
		Student* student = new Student[n + 1];
		for (int i = 0; i < n; i++)
		{
			getline(F, student[i].id);
			getline(F, student[i].password);
			getline(F, student[i].name);
			getline(F, student[i].DoB);
			getline(F, student[i].Class);
			getline(F, student[i].status);
			getline(F, student[i].midterm);
			getline(F, student[i].final);
			getline(F, student[i].bonus);
			getline(F, student[i].total);
			for (int j = 0; j < 10; j++)
				getline(F, student[i].att[j]);
			getline(F, trash);
			F.ignore(1, '\n');
		}

		F.close();

		fstream Ft;
		Ft.open(Fname, ios::out);

		Ft << i - 1 << endl;
		for (int j = 0; j < i - 1; j++)
		{
			istringstream iss(row[j]);
			string token[6];
			int k = 0;
			for (int e = 0; e < 6; e++)
				token[e].clear();
			while (getline(iss, token[k], ','))
			{
				k++;
			}

			student[j].id = token[0];
			student[j].name = token[1];
			student[j].midterm = token[2];
			student[j].final = token[3];
			student[j].bonus = token[4];
			student[j].total = token[5];

			Ft << student[j].id << endl;
			Ft << student[j].password << endl;
			Ft << student[j].name << endl;
			Ft << student[j].DoB << endl;
			Ft << student[j].Class << endl;
			Ft << student[j].status << endl;
			Ft << student[j].midterm << endl;
			Ft << student[j].final << endl;
			Ft << student[j].bonus << endl;
			Ft << student[j].total << endl;
			for (int w = 0; w < 10; w++)
				Ft << student[j].att[w] << endl;
			Ft << 1 << endl;
			Ft << endl;
		}

		Ft.close();
		delete[] student;
		delete[] row;

		cout << "\nImport students done!" << endl;
	}

}

int main()
{
	importScoreboard();
	if (_CrtDumpMemoryLeaks())
		cout << "\nMemory leak!" << endl;
	system("pause>nul");
	return 0;
}