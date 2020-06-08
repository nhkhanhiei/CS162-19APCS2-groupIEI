#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>
using namespace std;


//Create / update / delete / view academic years and semesters

struct Semester
{
	string year, semester;
};

void CreateYandS()
{
	int n;
	string k, t;
	Semester data[1000];
	cout << "Input year: ";
	getline(cin, k);
	cout << "Input Semester: ";
	getline(cin, t);
	
	ifstream fin("Semester.txt");
	if (fin.is_open())
	{
		fin >> n;
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
				fin.ignore();
			getline(fin, data[i].year);
			getline(fin, data[i].semester);
		}
	}
	else
		cout << "Could not open file!" << endl;
	fin.close();

	ofstream fout("Semester.txt");
	if (fout.is_open())
	{
		fout << n + 1 << endl;
		for (int i = 0; i < n; i++)
		{
			fout << data[i].year << endl;
			fout << data[i].semester << endl;
			fout << endl;
		}
		fout << k << endl;
		fout << t << endl;
	}
	else
		cout << "Could not open file!" << endl;
	fout.close();
}

void UpdateYandS()
{
	int n;
	string x, y, k, t;
	Semester data[1000];

	ifstream fin("Semester.txt");
	if (fin.is_open())
	{
		fin >> n;
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
				fin.ignore();
			getline(fin, data[i].year);
			getline(fin, data[i].semester);
		}
	}
	else
	{
		cout << "Could not open file to read!" << endl;
		return;
	}
	fin.close();

	cout << "Input Year you want to update: ";
	getline(cin, x);
	cout << "Input Semester you want to update: ";
	getline(cin, y);

	for (int i = 0; i < n; i++)
	{
		if (x == data[i].year && y == data[i].semester)
		{
			cout << "Input updated year: ";
			getline(cin, k);
			cout << "Input updated Semester: ";
			getline(cin, t);
			data[i].year = k;
			data[i].semester = t;
			break;
		}
		if (i == n - 1 && (x != data[i].year || y != data[i].semester))
			cout << "No year found!" << endl;
	}

	ofstream fout("Semester.txt");
	if (fout.is_open())
	{
		fout << n << endl;
		for (int i = 0; i < n; i++)
		{
			fout << data[i].year << endl;
			fout << data[i].semester << endl;
			fout << endl;
		}
	}
	else
		cout << "Could not open file to update!" << endl;
	fout.close();
}

void DeleteYandS()
{
	int n, m = -1;
	string x, y, k, t;
	Semester data[1000];

	ifstream fin("Semester.txt");
	if (fin.is_open())
	{
		fin >> n;
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
				fin.ignore();
			getline(fin, data[i].year);
			getline(fin, data[i].semester);
		}
	}
	else
	{
		cout << "Could not open file to read!" << endl;
		return;
	}
	fin.close();

	cout << "Input Year you want to delete: ";
	getline(cin, x);
	cout << "Input Semester you want to delete: ";
	getline(cin, y);

	for (int i = 0; i < n; i++)
	{
		if (x == data[i].year && y == data[i].semester) {
			m = i;
			break;
		}
		if (i == n - 1 && (x != data[i].year || y != data[i].semester))
			cout << "No year found!" << endl;
	}
	
	if (m != -1)
	{
		ofstream fout("Semester.txt");
		if (fout.is_open())
		{
			fout << n - 1 << endl;
			for (int i = 0; i < n; i++)
			{
				if (i == m)
					continue;
				fout << data[i].year << endl;
				fout << data[i].semester << endl;
				fout << endl;
			}
		}
		else
			cout << "Could not open file to delete!" << endl;
		fout.close();
	}
}

void ViewYandS()
{
	int n;

	ifstream f("Semester.txt");
	if (f.is_open())
	{
		f >> n;
		Semester* data = new Semester[n];
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
				f.ignore();
			getline(f, data[i].year);
			getline(f, data[i].semester);
		}
		for (int i = 0; i < n; i++)
		{
			cout << "Year: " << data[i].year << endl;
			cout << "Semester: " << data[i].semester << endl;
		}
		delete[] data;
	}
	else
		cout << "Could not open file!" << endl;
	f.close();
}

//From a semester, import courses from a csv file

struct Date
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
	Date startDate;
	Date endDate;
	int dayStudy;
	int startHour;
	int startMin;
	int endHour;
	int endMin;
	string lectureRoom;
};
typedef CourseData CSD;

struct Student
{
	string id, password, name, DoB, Class, status;
};

Date stringToDate(string a)
{
	Date b;
	istringstream iss(a);
	string token;
	int k = 0;
	while (getline(iss, token, '/'))
	{
		if (k == 0)
		{
			b.month = stoi(token);
			k++;
		}
		else if (k == 1)
		{
			b.day = stoi(token);
			k++;
		}
		else 
		{
			b.year = 2000 + stoi(token);
		}
	}
	return b;
}

int DayStudy(string a)
{
	if (a == "MON")
		return 2;
	if (a == "TUE")
		return 3;
	if (a == "WED")
		return 4;
	if (a == "THU")
		return 5;
	if (a == "FRI")
		return 6;
	if (a == "SAT")
		return 7;
	if (a == "SUN")
		return 8;
}

string dayFormat(int a)
{
	if (a < 10)
		return "0" + to_string(a);
	else
		return to_string(a);
}

string AttendanceDate(Date a, int skip, int starth, int startm, int endh, int endm)
{
	struct tm  t = { 0 };
	t.tm_mday = a.day;
	t.tm_mon = a.month - 1;
	t.tm_year = a.year - 1900;

	// Add 'skip' days to the date.                                                               
	t.tm_mday += skip;
	mktime(&t);

	string d, m;
	if (t.tm_mday < 10)
		d = "0" + to_string(t.tm_mday);
	else
		d = to_string(t.tm_mday);

	if (t.tm_mon + 1 < 10)
		m = "0" + to_string(t.tm_mon + 1);
	else
		m = to_string(t.tm_mon + 1);
	string date = to_string(t.tm_year + 1900) + " " + m + " " + d + " " + to_string(starth) + " " + to_string(startm) + " " + to_string(endh) + " " + to_string(endm) + " " + "-1";
	return date;
}

void CreateCourseSchedule(string year, string semester, string Class, CSD schedule[], int k)
{
	string filename = year + '-' + semester + "-Schedule-" + Class + ".txt";
	ofstream f(filename);
	if (f.is_open())
	{
		f << k << endl;
		for (int i = 0; i < k; i++)
		{
			f << schedule[i].courseID << endl;
			f << schedule[i].courseName << endl;
			f << schedule[i].Class << endl;
			f << schedule[i].lecturerUsername << endl;
			f << schedule[i].lecturerName << endl;
			f << schedule[i].lecturerDegree << endl;
			f << schedule[i].lecturerGender << endl;
			f << schedule[i].startDate.year << " " << dayFormat(schedule[i].startDate.month) << " " << dayFormat(schedule[i].startDate.day) << endl;
			f << schedule[i].endDate.year << " " << dayFormat(schedule[i].endDate.month) << " " << dayFormat(schedule[i].endDate.day) << endl;
			f << schedule[i].dayStudy << endl;
			f << schedule[i].startHour << " " << schedule[i].startMin << endl;
			f << schedule[i].endHour << " " << schedule[i].endMin << endl;
			f << schedule[i].lectureRoom << endl;
			f << endl;
		}
	}
	else 
		cout << "Could not open file!" << endl;
}

void CreateCourseStudent(string year, string semester, string Class, CSD schedule[], int k)
{
	int n;
	Student student[200];
	string filename = "Student-" + Class + ".txt";
	ifstream f(filename);
	if (f.is_open())
	{
		f >> n;
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
				f.ignore();
			getline(f, student[i].id);
			getline(f, student[i].password);
			getline(f, student[i].name);
			getline(f, student[i].DoB);
			getline(f, student[i].Class);
			getline(f, student[i].status);
			f.ignore(1, '\n');
		}
	}
	else
		cout << "Could not open file!" << endl;
	f.close();

	for (int i = 0; i < k; i++)
	{
		string File = year + "-" + semester + "-" + Class + "-" + schedule[i].courseID + "-Student.txt";
		ofstream fout(File);
		if (fout.is_open())
		{
			fout << n << endl;
			for (int j = 0; j < n; j++)
			{
				int q = 0;
				fout << student[j].id << endl;
				fout << student[j].password << endl;
				fout << student[j].name << endl;
				fout << student[j].DoB << endl;
				fout << student[j].Class << endl;
				fout << student[j].status << endl;
				for (int k = 0; k < 4; k++) {
					fout << -1 << endl;
				}
				for (int h = 0; h < 10; h++)
				{
					fout << AttendanceDate(schedule[i].startDate, q, schedule[i].startHour, schedule[i].startMin, schedule[i].endHour, schedule[i].endMin) << endl;
					q += 7;
				}
				fout << 1 << endl;
				fout << endl;
			}
		}
		else
			cout << "Could not open file!" << endl;
		fout.close();
	}
}

void ImportAndCreateFile()
{
	string x, y, z, t;
	cout << "Enter Year: ";
	getline(cin, x);
	cout << "Enter Semester: ";
	getline(cin, y);
	cout << "Enter Class: ";
	getline(cin, z);
	cout << "Enter File: ";
	getline(cin, t);


	string schedule[100];
	string temp;
	int k = 0;

	ifstream import(t);
	if (import.is_open()) {
		getline(import, temp);
		while (getline(import, schedule[k]))
		{
			k++;
		}
	}
	else
		cout << "Import Failed!" << endl;
	import.close();

	CSD Schedule[100];
	int a = 0;
	for (int i = 0; i < k; i++)
	{
		istringstream iss(schedule[i]);
		string token;
		getline(iss, token, ',');
		Schedule[i].id = stoi(token);
		getline(iss, token, ',');
		Schedule[i].courseID = token;
		getline(iss, token, ',');
		Schedule[i].courseName = token;
		getline(iss, token, ',');
		Schedule[i].Class = token;
		getline(iss, token, ',');
		Schedule[i].lecturerUsername = token;
		getline(iss, token, ',');
		Schedule[i].lecturerName = token;
		getline(iss, token, ',');
		Schedule[i].lecturerDegree = token;
		getline(iss, token, ',');
		if (token == "Male")
			Schedule[i].lecturerGender = "0";
		else
			Schedule[i].lecturerGender = "1";
		getline(iss, token, ',');
		Schedule[i].startDate = stringToDate(token);
		getline(iss, token, ',');
		Schedule[i].endDate = stringToDate(token);
		getline(iss, token, ',');
		Schedule[i].dayStudy = DayStudy(token);
		getline(iss, token, ',');
		Schedule[i].startHour = stoi(token);
		getline(iss, token, ',');
		Schedule[i].startMin = stoi(token);
		getline(iss, token, ',');
		Schedule[i].endHour = stoi(token);
		getline(iss, token, ',');
		Schedule[i].endMin = stoi(token);
		getline(iss, token, ',');
		Schedule[i].lectureRoom = token;
	}

	CreateCourseSchedule(x, y, z, Schedule, k);
	CreateCourseStudent(x, y, z, Schedule, k);
}

int main()
{
	ImportAndCreateFile();
	system("pause>nul");
	return 0;
}