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
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
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
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
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
			fin.ignore(numeric_limits<streamsize>::max(), '\n');
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
			f.ignore(numeric_limits<streamsize>::max(), '\n');
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

string schedule[100];
CSD Schedule[100];
Student student[200];
int k = 0; // num of course
int n; // num of student
int u; // num of lecturer
string x, y, z, t;


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
				for (int d = 0; d < 4; d++) {
					fout << 7 << endl;
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

void UpdateLecturer()
{
	string name[100];
	ifstream fread("Lecturer.txt");
	if (fread.is_open())
	{
		fread >> u;
		fread.ignore();
		for (int i = 0; i < u; i++)
		{
			for (int j = 0; j < 2; j++)
				fread.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(fread, name[i]);
			for (int j = 0; j < 3; j++)
				fread.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	else
		cout << "Could not open file!" << endl;
	fread.close();

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < u; j++)
		{
			if (Schedule[i].lecturerName == name[j])
				break;
			if (j == u - 1 && Schedule[i].lecturerName != name[j])
			{
				string temp;
				ifstream in("Lecturer.txt");
				ofstream out("Lecturer1.txt");
				if (in.is_open() && out.is_open())
				{
					getline(in, temp);
					out << u + 1 << endl;
					while (!in.eof())
					{
						getline(in, temp);
						out << temp << endl;
					}
				}
				else
					cout << "Could not update lecturer!" << endl;
				out.close();
				in.close();

				remove("Lecturer.txt");
				rename("Lecturer1.txt", "Lecturer.txt");

				ofstream fout("Lecturer.txt", ios::app);
				if (fout.is_open())
				{
					fout << Schedule[i].lecturerUsername << endl;
					fout << Schedule[i].lecturerUsername << endl;
					fout << Schedule[i].lecturerName << endl;
					fout << Schedule[i].lecturerDegree << endl;
					fout << Schedule[i].lecturerGender << endl;
				}
				else
					cout << "Could not update lecturer!" << endl;
				fout.close();
				u++;
				break;
			}
		}
		
	}
}

void ImportAndCreateFile()
{
	cout << "Input to Import: " << endl;
	cout << "---------------------------------------" << endl;
	cout << "Enter Year: ";
	getline(cin, x);
	cout << "Enter Semester: ";
	getline(cin, y);
	cout << "Enter Class: ";
	getline(cin, z);
	cout << "Enter File: ";
	getline(cin, t);

	string temp;
	
	ifstream import(t);
	if (import.is_open()) {
		getline(import, temp);
		while (getline(import, schedule[k]))
		{
			k++;
		}
		cout << "Import successfully" << endl;
	}
	else
		cout << "Import Failed!" << endl;
	import.close();


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
	UpdateLecturer();
}

// Manually add an new course (must import first)
void AddNewCourse()
{
	CSD newcourse;
	string startdate, enddate;
	cout << "Add new course" << endl;
	cout << "------------------------" << endl;
	newcourse.id = k + 1;
	cout << "Input course id: ";
	getline(cin, newcourse.courseID);
	cout << "Input course name: ";
	getline(cin, newcourse.courseName);
	cout << "Input course class: ";
	getline(cin, newcourse.Class);
	cout << "Input course lecturer username: ";
	getline(cin, newcourse.lecturerUsername);
	cout << "Input course lecturer name: ";
	getline(cin, newcourse.lecturerName);
	cout << "Input course lecturer degree: ";
	getline(cin, newcourse.lecturerDegree);
	cout << "Input course lecturer Gender (0: male, 1: female): ";
	getline(cin, newcourse.lecturerGender);
	cout << "Input course start date (m/d/y): ";
	getline(cin, startdate);
	newcourse.startDate = stringToDate(startdate);
	cout << "Input course end date (m/d/y): ";
	getline(cin, enddate);
	newcourse.endDate = stringToDate(enddate);
	cout << "Input course day study: ";
	cin >> newcourse.dayStudy;
	cout << "Input course start hour: ";
	cin >> newcourse.startHour;
	cout << "Input course start minute: ";
	cin >> newcourse.startMin;
	cout << "Input course end hour: ";
	cin >> newcourse.endHour;
	cout << "Input course end minute: ";
	cin >> newcourse.endMin;
	cout << "Input course lecture room: ";
	cin.ignore();
	getline(cin, newcourse.lectureRoom);

	k++;

	Schedule[k - 1].courseID = newcourse.courseID;
	Schedule[k - 1].courseName = newcourse.courseName;
	Schedule[k - 1].Class = newcourse.Class;
	Schedule[k - 1].lecturerUsername = newcourse.lecturerUsername;
	Schedule[k - 1].lecturerName = newcourse.lecturerName;
	Schedule[k - 1].lecturerDegree = newcourse.lecturerDegree;
	Schedule[k - 1].lecturerGender = newcourse.lecturerGender;
	Schedule[k - 1].startDate = newcourse.startDate;
	Schedule[k - 1].endDate = newcourse.endDate;
	Schedule[k - 1].dayStudy = newcourse.dayStudy;
	Schedule[k - 1].startHour = newcourse.startHour;
	Schedule[k - 1].startMin = newcourse.startMin;
	Schedule[k - 1].endHour = newcourse.endHour;
	Schedule[k - 1].endMin = newcourse.endMin;
	Schedule[k - 1].lectureRoom = newcourse.lectureRoom;

	string filename = x + "-" + y + "-Schedule-" + z + ".txt";
	ofstream f(filename);
	if (f.is_open())
	{
		f << k << endl;
		for (int i = 0; i < k; i++)
		{
			if (i == k - 1)
			{
				f << newcourse.courseID << endl;
				f << newcourse.courseName << endl;
				f << newcourse.Class << endl;
				f << newcourse.lecturerUsername << endl;
				f << newcourse.lecturerName << endl;
				f << newcourse.lecturerDegree << endl;
				f << newcourse.lecturerGender << endl;
				f << newcourse.startDate.year << " " << dayFormat(newcourse.startDate.month) << " " << dayFormat(newcourse.startDate.day) << endl;
				f << newcourse.endDate.year << " " << dayFormat(newcourse.endDate.month) << " " << dayFormat(newcourse.endDate.day) << endl;
				f << newcourse.dayStudy << endl;
				f << newcourse.startHour << " " << newcourse.startMin << endl;
				f << newcourse.endHour << " " << newcourse.endMin << endl;
				f << newcourse.lectureRoom << endl;
				f << endl;
			}
			else
			{
				f << Schedule[i].courseID << endl;
				f << Schedule[i].courseName << endl;
				f << Schedule[i].Class << endl;
				f << Schedule[i].lecturerUsername << endl;
				f << Schedule[i].lecturerName << endl;
				f << Schedule[i].lecturerDegree << endl;
				f << Schedule[i].lecturerGender << endl;
				f << Schedule[i].startDate.year << " " << dayFormat(Schedule[i].startDate.month) << " " << dayFormat(Schedule[i].startDate.day) << endl;
				f << Schedule[i].endDate.year << " " << dayFormat(Schedule[i].endDate.month) << " " << dayFormat(Schedule[i].endDate.day) << endl;
				f << Schedule[i].dayStudy << endl;
				f << Schedule[i].startHour << " " << Schedule[i].startMin << endl;
				f << Schedule[i].endHour << " " << Schedule[i].endMin << endl;
				f << Schedule[i].lectureRoom << endl;
				f << endl;
			}
		}
	}
	else
		cout << "Could not open file!" << endl;
	f.close();

	string File = x + "-" + y + "-" + z + "-" + newcourse.courseID + "-Student.txt";
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
			for (int d = 0; d < 4; d++) {
				fout << 7 << endl;
			}
			for (int h = 0; h < 10; h++)
			{
				fout << AttendanceDate(newcourse.startDate, q, newcourse.startHour, newcourse.startMin, newcourse.endHour, newcourse.endMin) << endl;
				q += 7;
			}
			fout << 1 << endl;
			fout << endl;
		}
	}
	else
		cout << "Could not open file!" << endl;
	fout.close();
	UpdateLecturer();
}

// Edit Existing Course (must import first)
void EditCourse()
{
	int t;
	cout << "Input id of course to edit: ";
	cin >> t;

	string file = x + "-" + y + "-" + z + "-" + Schedule[t - 1].courseID + "-Student.txt";

	string startdate, enddate;
	Schedule[t-1].id = t;
	cout << "Edit Course" << endl;
	cout << "------------------------" << endl;
	cout << "Input course id: ";
	cin.ignore();
	getline(cin, Schedule[t-1].courseID);
	cout << "Input course name: ";
	getline(cin, Schedule[t-1].courseName);
	cout << "Input course class: ";
	getline(cin, Schedule[t-1].Class);
	cout << "Input course lecturer username: ";
	getline(cin, Schedule[t-1].lecturerUsername);
	cout << "Input course lecturer name: ";
	getline(cin, Schedule[t-1].lecturerName);
	cout << "Input course lecturer degree: ";
	getline(cin, Schedule[t-1].lecturerDegree);
	cout << "Input course lecturer Gender (0: male, 1: female): ";
	getline(cin, Schedule[t-1].lecturerGender);
	cout << "Input course start date (m/d/y): ";
	getline(cin, startdate);
	Schedule[t-1].startDate = stringToDate(startdate);
	cout << "Input course end date (m/d/y): ";
	getline(cin, enddate);
	Schedule[t-1].endDate = stringToDate(enddate);
	cout << "Input course day study: ";
	cin >> Schedule[t-1].dayStudy;
	cout << "Input course start hour: ";
	cin >> Schedule[t-1].startHour;
	cout << "Input course start minute: ";
	cin >> Schedule[t-1].startMin;
	cout << "Input course end hour: ";
	cin >> Schedule[t-1].endHour;
	cout << "Input course end minute: ";
	cin >> Schedule[t-1].endMin;
	cout << "Input course lecture room: ";
	cin.ignore();
	getline(cin, Schedule[t-1].lectureRoom);

	string filename = x + "-" + y + "-Schedule-" + z + ".txt";
	ofstream f(filename);
	if (f.is_open())
	{
		f << k << endl;
		for (int i = 0; i < k; i++)
		{
			f << Schedule[i].courseID << endl;
			f << Schedule[i].courseName << endl;
			f << Schedule[i].Class << endl;
			f << Schedule[i].lecturerUsername << endl;
			f << Schedule[i].lecturerName << endl;
			f << Schedule[i].lecturerDegree << endl;
			f << Schedule[i].lecturerGender << endl;
			f << Schedule[i].startDate.year << " " << dayFormat(Schedule[i].startDate.month) << " " << dayFormat(Schedule[i].startDate.day) << endl;
			f << Schedule[i].endDate.year << " " << dayFormat(Schedule[i].endDate.month) << " " << dayFormat(Schedule[i].endDate.day) << endl;
			f << Schedule[i].dayStudy << endl;
			f << Schedule[i].startHour << " " << Schedule[i].startMin << endl;
			f << Schedule[i].endHour << " " << Schedule[i].endMin << endl;
			f << Schedule[i].lectureRoom << endl;
			f << endl;
		}
	}
	else
		cout << "Could not open file!" << endl;
	f.close();

	string File = x + "-" + y + "-" + z + "-" + Schedule[t-1].courseID + "-Student.txt";
	int m;
	Student temp;
	ofstream fout(File);
	ifstream fin(file);
	if (fin.is_open() && fout.is_open())
	{
		fin >> m;
		fout << m << endl;
		for (int j = 0; j < m; j++)
		{
			if (j == 0)
				fin.ignore();
			getline(fin, temp.id);
			getline(fin, temp.password);
			getline(fin, temp.name);
			getline(fin, temp.DoB);
			getline(fin, temp.Class);
			getline(fin, temp.status);
			for (int p = 0; p < 16; p++)
				fin.ignore(numeric_limits<streamsize>::max(), '\n');
			int q = 0;
			fout << temp.id << endl;
			fout << temp.password << endl;
			fout << temp.name << endl;
			fout << temp.DoB << endl;
			fout << temp.Class << endl;
			fout << temp.status << endl;
			for (int d = 0; d < 4; d++) {
				fout << 7 << endl;
			}
			for (int h = 0; h < 10; h++)
			{
				fout << AttendanceDate(Schedule[t-1].startDate, q, Schedule[t-1].startHour, Schedule[t-1].startMin, Schedule[t-1].endHour, Schedule[t-1].endMin) << endl;
				q += 7;
			}
			fout << 1 << endl;
			fout << endl;
		}
	}
	else
		cout << "Could not open file!" << endl;
	fout.close();
	fin.close();
	remove((file).c_str());
	UpdateLecturer();
}

// Remove a Course (must import first)
void RemoveCourse()
{
	int t;
	cout << "Input id of course to remove: ";
	cin >> t;

	string file = x + "-" + y + "-" + z + "-" + Schedule[t - 1].courseID + "-Student.txt";

	remove((file).c_str());

	for (int i = t - 1; i < k; i++)
	{
		if (i == k - 1)
			break;
		Schedule[i].id = Schedule[i + 1].id;
		Schedule[i].courseID = Schedule[i + 1].courseID;
		Schedule[i].courseName = Schedule[i + 1].courseName;
		Schedule[i].Class = Schedule[i + 1].Class;
		Schedule[i].lecturerUsername = Schedule[i + 1].lecturerUsername;
		Schedule[i].lecturerName = Schedule[i + 1].lecturerName;
		Schedule[i].lecturerDegree = Schedule[i + 1].lecturerDegree;
		Schedule[i].lecturerGender = Schedule[i + 1].lecturerGender;
		Schedule[i].startDate = Schedule[i + 1].startDate;
		Schedule[i].endDate = Schedule[i + 1].endDate;
		Schedule[i].dayStudy = Schedule[i + 1].dayStudy;
		Schedule[i].startHour = Schedule[i + 1].startHour;
		Schedule[i].startMin = Schedule[i + 1].startMin;
		Schedule[i].endHour = Schedule[i + 1].endHour;
		Schedule[i].endMin = Schedule[i + 1].endMin;
		Schedule[i].lectureRoom = Schedule[i + 1].lectureRoom;
	}
	k--;

	string filename = x + "-" + y + "-Schedule-" + z + ".txt";
	ofstream f(filename);
	if (f.is_open())
	{
		f << k << endl;
		for (int i = 0; i < k; i++)
		{
			f << Schedule[i].courseID << endl;
			f << Schedule[i].courseName << endl;
			f << Schedule[i].Class << endl;
			f << Schedule[i].lecturerUsername << endl;
			f << Schedule[i].lecturerName << endl;
			f << Schedule[i].lecturerDegree << endl;
			f << Schedule[i].lecturerGender << endl;
			f << Schedule[i].startDate.year << " " << dayFormat(Schedule[i].startDate.month) << " " << dayFormat(Schedule[i].startDate.day) << endl;
			f << Schedule[i].endDate.year << " " << dayFormat(Schedule[i].endDate.month) << " " << dayFormat(Schedule[i].endDate.day) << endl;
			f << Schedule[i].dayStudy << endl;
			f << Schedule[i].startHour << " " << Schedule[i].startMin << endl;
			f << Schedule[i].endHour << " " << Schedule[i].endMin << endl;
			f << Schedule[i].lectureRoom << endl;
			f << endl;
		}
	}
	else
		cout << "Could not open file!" << endl;
	f.close();
}

// Remove a Student from a Course (must import first)
void RemoveStudentFromCourse()
{
	string removedstudent;
	int t;
	cout << "Input id of course to remove the student from: ";
	cin >> t;

	cout << "Input id of student you want to remove: ";
	cin.ignore();
	getline(cin, removedstudent);

	string file = x + "-" + y + "-" + z + "-" + Schedule[t - 1].courseID + "-Student.txt";

	int m;
	ifstream fi(file);
	if (fi.is_open())
	{
		fi >> m;
	}
	fi.close();

	ofstream fout(file);
	if (fout.is_open())
	{
		fout << m - 1 << endl;
		for (int j = 0; j < m; j++)
		{
			if (student[j].id == removedstudent)
				continue;
			int q = 0;
			fout << student[j].id << endl;
			fout << student[j].password << endl;
			fout << student[j].name << endl;
			fout << student[j].DoB << endl;
			fout << student[j].Class << endl;
			fout << student[j].status << endl;
			for (int d = 0; d < 4; d++) {
				fout << 7 << endl;
			}
			for (int h = 0; h < 10; h++)
			{
				fout << AttendanceDate(Schedule[t-1].startDate, q, Schedule[t-1].startHour, Schedule[t-1].startMin, Schedule[t-1].endHour, Schedule[t-1].endMin) << endl;
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

// Add a student to a course (must import first)
string DoBtoPassword(string input)
{
	input.erase(remove(input.begin(), input.end(), ' '), input.end());
	return input;
}

void AddNewStudentToCourse()
{
	int t;
	Student newstudent;
	cout << "Input course id to add new student in: ";
	cin >> t;
	cout << "Add new student" << endl;
	cout << "------------------------" << endl;
	cout << "Input new student id: ";
	cin.ignore();
	getline(cin, newstudent.id);
	cout << "Input new student name: ";
	getline(cin, newstudent.name);
	cout << "Input new student day of birth (yyyy mm dd): ";
	getline(cin, newstudent.DoB);
	newstudent.password = DoBtoPassword(newstudent.DoB);
	newstudent.Class = z;
	newstudent.status = "1";

	string File = x + "-" + y + "-" + z + "-" + Schedule[t-1].courseID + "-Student.txt";

	int m;
	ifstream fi(File);
	if (fi.is_open())
	{
		fi >> m;
	}
	fi.close();

	ofstream fout(File);
	if (fout.is_open())
	{
		fout << m + 1 << endl;
		for (int j = 0; j < m + 1; j++)
		{
			if (j == m)
			{
				int q = 0;
				fout << newstudent.id << endl;
				fout << newstudent.password << endl;
				fout << newstudent.name << endl;
				fout << newstudent.DoB << endl;
				fout << newstudent.Class << endl;
				fout << newstudent.status << endl;
				for (int d = 0; d < 4; d++) {
					fout << 7 << endl;
				}
				for (int h = 0; h < 10; h++)
				{
					fout << AttendanceDate(Schedule[t - 1].startDate, q, Schedule[t - 1].startHour, Schedule[t - 1].startMin, Schedule[t - 1].endHour, Schedule[t - 1].endMin) << endl;
					q += 7;
				}
				fout << 1 << endl;
				fout << endl;
			}
			else
			{
				int q = 0;
				fout << student[j].id << endl;
				fout << student[j].password << endl;
				fout << student[j].name << endl;
				fout << student[j].DoB << endl;
				fout << student[j].Class << endl;
				fout << student[j].status << endl;
				for (int d = 0; d < 4; d++) {
					fout << 7 << endl;
				}
				for (int h = 0; h < 10; h++)
				{
					fout << AttendanceDate(Schedule[t - 1].startDate, q, Schedule[t - 1].startHour, Schedule[t - 1].startMin, Schedule[t - 1].endHour, Schedule[t - 1].endMin) << endl;
					q += 7;
				}
				fout << 1 << endl;
				fout << endl;
			}
		}
	}
	else
		cout << "Could not open file!" << endl;
	fout.close();
}

//View list of Course (must import first)
void ViewListOfCourse()
{
	cout << "There is/are " << k << " course(s) in this current Semester: " << endl;
	cout << "--------------------------------------------" << endl;
	for (int i = 0; i < k; i++)
	{
		cout << i + 1 << ")" << endl;
		cout << setw(30) << left << "Course Id: " << Schedule[i].courseID << endl;
		cout << setw(30) << left << "Course Name: " << Schedule[i].courseName << endl;
		cout << setw(30) << left << "Course Class: " << Schedule[i].Class << endl;
		cout << setw(30) << left << "Course Lecturer username: " << Schedule[i].lecturerUsername << endl;
		cout << setw(30) << left << "Course Lecturer name: " << Schedule[i].lecturerName << endl;
		cout << setw(30) << left << "Course Lecturer Degree: " << Schedule[i].lecturerDegree << endl;
		cout << setw(30) << left << "Course Lecturer Gender: " << Schedule[i].lecturerGender << endl;
		cout << setw(30) << left << "Course Start date: " << Schedule[i].startDate.year << " " << dayFormat(Schedule[i].startDate.month) << " " << dayFormat(Schedule[i].startDate.day) << endl;
		cout << setw(30) << left << "Course End date: " << Schedule[i].endDate.year << " " << dayFormat(Schedule[i].endDate.month) << " " << dayFormat(Schedule[i].endDate.day) << endl;
		cout << setw(30) << left << "Course Day study: " << Schedule[i].dayStudy << endl;
		cout << setw(30) << left << "Course Start time: " << Schedule[i].startHour << " " << Schedule[i].startMin << endl;
		cout << setw(30) << left << "Course End time: " << Schedule[i].endHour << " " << Schedule[i].endMin << endl;
		cout << setw(30) << left << "Course Lecture room: " << Schedule[i].lectureRoom << endl;
		cout << "--------------------------------------------" << endl;
	}
}

//View list of Student in a Course (must import first)
void ViewListOfStudentInCourse()
{
	int t;
	cout << "Input id of course to view student list: ";
	cin >> t;

	string a;
	cout << "Input class to view student list: ";
	cin.ignore();
	getline(cin, a);

	
	string file = x + "-" + y + "-" + a + "-" + Schedule[t - 1].courseID + "-Student.txt";

	int m;

	Student temp;
	ifstream f(file);
	if (f.is_open())
	{
		f >> m;
		cout << "There is/are " << m << " Student(s) in this Course " << Schedule[t - 1].courseID << endl;
		cout << "--------------------------------------------" << endl;
		for (int i = 0; i < m; i++)
		{
			if (i == 0)
				f.ignore();
			getline(f, temp.id);
			getline(f, temp.password);
			getline(f, temp.name);
			getline(f, temp.DoB);
			getline(f, temp.Class);
			getline(f, temp.status);
			for (int p = 0; p < 16; p++)
				f.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << i + 1 << ")" << endl;
			cout << setw(30) << left << "Student Id: " << temp.id << endl;
			cout << setw(30) << left << "Student Password: " << temp.password << endl;
			cout << setw(30) << left << "Student Name: " << temp.name << endl;
			cout << setw(30) << left << "Student Day of Birth: " << temp.DoB << endl;
			cout << setw(30) << left << "Student Class: " << temp.Class << endl;
			cout << setw(30) << left << "Student Status: " << temp.status << endl;
			cout << "--------------------------------------------" << endl;
		}
	}
	else
		cout << "Could not open file to view!" << endl;
	f.close();
}

//View Attendance list of Student in a Course (must import first)
void ViewAttendanceListOfCourse()
{
	string a;

	int t;
	cout << "Input id of course to view attendance list: ";
	cin >> t;

	cout << "Input class to view student list: ";
	cin.ignore();
	getline(cin, a);
	

	cout << "Attendance List of Student(s) in this Course " << Schedule[t - 1].courseID << endl;
	cout << "--------------------------------------------" << endl;
	string file = x + "-" + y + "-" + a + "-" + Schedule[t - 1].courseID + "-Student.txt";
	int m;
	string temp;
	ifstream f(file);
	if (f.is_open())
	{
		f >> m;
		for (int i = 0; i < m; i++)
		{
			if (i == 0)
				f.ignore();
			getline(f, temp);
			cout << setw(17) << left << "Student Id: " << temp << endl;
			f.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(f, temp);
			cout << setw(17) << left << "Student Name: " << temp << endl;
			cout << "Attendance list: " << endl;
			for (int p = 0; p < 7; p++)
				f.ignore(numeric_limits<streamsize>::max(), '\n');
			for (int p = 0; p < 10; p++)
			{
				getline(f, temp);
				cout << temp << endl;
			}
			for (int p = 0; p < 2; p++)
				f.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "--------------------------------------------" << endl;
		}
	}
	else
		cout << "Could not open file to view!" << endl;
	f.close();
}

//View all Lecturers 
void ViewAllLecturers()
{
	int a;
	string temp;
	ifstream f("Lecturer.txt");
	if (f.is_open())
	{
		f >> a;
		cout << "There are " << a << " lecturers: " << endl;
		cout << "---------------------------------" << endl;
		for (int i = 0; i < a; i++)
		{
			if (i == 0)
				f.ignore();
			cout << i + 1 << ")" << endl;
			getline(f, temp);
			cout << setw(20) << left << "Username: " << temp << endl;
			getline(f, temp);
			cout << setw(20) << left << "Password: " << temp << endl;
			getline(f, temp);
			cout << setw(20) << left << "Name: " << temp << endl;
			getline(f, temp);
			cout << setw(20) << left << "Degree: " << temp << endl;
			getline(f, temp);
			if (temp == "0")
				cout << setw(20) << left << "Gender: " << "Male" << endl;
			else
				cout << setw(20) << left << "Gender: " << "Female" << endl;
			cout << "---------------------------------" << endl;
			f.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	else
		cout << "Could not open file to view!" << endl;
	f.close();
}

int main()
{
	//CreateYandS();
	ImportAndCreateFile();
	//AddNewCourse();
	//EditCourse();
	//RemoveCourse();
	RemoveStudentFromCourse();
	//AddNewStudentToCourse();
	//ViewListOfCourse();
	ViewListOfStudentInCourse();
	//ViewAttendanceListOfCourse();
	//ViewAllLecturers();
	system("pause>nul");
	return 0;
}