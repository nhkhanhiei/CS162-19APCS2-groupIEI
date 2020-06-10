#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
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
struct Attendance {
	string day;
};
struct Student
{
	string id, password, name, DoB, Class, status,midterm,final,bonus,total;
	Attendance att[11];
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

void ViewAttendance()
{
	//2019-2020-HK2-19APCS1-CM101-Student.txt
	string temp,filename;
	cout << "Which attendance list would you like to see?" << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Year(yyyy-yyyy): " ;
	getline(cin, filename);
	cout << "Semester: ";
	getline(cin, temp);
	filename += '-' + temp;
	cout << "Class: ";
	getline(cin, temp);
	filename += '-' + temp;
	cout << "Course name: ";
	getline(cin, temp);
	filename += '-' + temp + "-Student.txt" ;
	fstream fin;
	fin.open(filename, ios::in || ios:: out);
	if (fin.fail())
	{
		cout << "Khong mo duoc file";
		fin.close();
		return;
	}
	int n;
	fin >> n;
	fin.ignore();
	Student* student = new Student[n+1];
	for (int i = 0; i < n; i++)
	{
		getline(fin, student[i].id);
		getline(fin, student[i].password);
		getline(fin, student[i].name);
		getline(fin, student[i].DoB);
		getline(fin, student[i].Class);
		getline(fin, student[i].status);
		getline(fin, student[i].midterm);
		getline(fin, student[i].final);
		getline(fin, student[i].bonus);
		getline(fin, student[i].total);
		for(int j = 0; j < 10; j++)
		getline(fin, student[i].att[j].day);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}
	for (int i = 0; i < n; i++)
	{
		cout << student[i].name << ": " << endl;
		for (int j = 0; j < 10; j++)
		{
			int length = student[i].att[j].day.length();
			if (student[i].att[j].day[length - 1] == '1')
			{
				student[i].att[j].day.resize(11);
				cout << student[i].att[j].day << ": Absent" << endl;
			}
			else
			{
				student[i].att[j].day.resize(11);
				cout << student[i].att[j].day << ": Present" << endl;
			}
		}
		cout << endl;
	}
	fin.close();
	delete[] student;
}
void ExportAttendance()
{
	//2019-2020-HK2-19APCS1-CM101-Student.txt
	string temp, filename;
	cout << "Which attendance list would you like to export?" << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Year(yyyy-yyyy): ";
	getline(cin, filename);
	cout << "Semester: ";
	getline(cin, temp);
	filename += '-' + temp;
	cout << "Class: ";
	getline(cin, temp);
	filename += '-' + temp;
	cout << "Course name: ";
	getline(cin, temp);
	filename += '-' + temp + "-Student.txt";
	fstream fin;
	fin.open(filename, ios::in || ios::out);
	if (fin.fail())
	{
		cout << "Khong mo duoc file";
		fin.close();
		return;
	}
	int n;
	fin >> n;
	fin.ignore();
	Student* student = new Student[n + 1];
	for (int i = 0; i < n; i++)
	{
		getline(fin, student[i].id);
		getline(fin, student[i].password);
		getline(fin, student[i].name);
		getline(fin, student[i].DoB);
		getline(fin, student[i].Class);
		getline(fin, student[i].status);
		getline(fin, student[i].midterm);
		getline(fin, student[i].final);
		getline(fin, student[i].bonus);
		getline(fin, student[i].total);
		for (int j = 0; j < 10; j++)
			getline(fin, student[i].att[j].day);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}
	fin.close();


	fstream fout;
	int pos = filename.find(".txt");
	filename.erase(pos);
	filename += ".csv";
	fout.open(filename, ios::in || ios::out || ios::trunc);
	fout << "No, Student ID, Full name, Class, Day, Attendance" << endl;
	for (int i = 0; i < n; i++)
	{
		fout << i+1 << ", " << student[i].id << ", " << student[i].name <<
			", " << student[i].Class 
	}
	fout.close();
	
	delete[] student;
}
void ViewStudentList()
{
	//2019-2020-HK2-19APCS1-CM101-Student.txt
	string temp, filename;
	cout << "Which attendance list would you like to see?" << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Year(yyyy-yyyy): ";
	getline(cin, filename);
	cout << "Semester: ";
	getline(cin, temp);
	filename += '-' + temp;
	cout << "Class: ";
	getline(cin, temp);
	filename += '-' + temp;
	cout << "Course name: ";
	getline(cin, temp);
	filename += '-' + temp + "-Student.txt";
	fstream fin;
	fin.open(filename, ios::in || ios::out);
	if (fin.fail())
	{
		cout << "Khong mo duoc file";
		fin.close();
		return;
	}
	int n;
	fin >> n;
	fin.ignore();
	Student* student = new Student[n + 1];
	for (int i = 0; i < n; i++)
	{
		getline(fin, student[i].id);
		getline(fin, student[i].password);
		getline(fin, student[i].name);
		getline(fin, student[i].DoB);
		getline(fin, student[i].Class);
		getline(fin, student[i].status);
		getline(fin, student[i].midterm);
		getline(fin, student[i].final);
		getline(fin, student[i].bonus);
		getline(fin, student[i].total);
		for (int j = 0; j < 10; j++)
			getline(fin, student[i].att[j].day);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}
	fin.close();
	delete[] student;
}
int main()
{
	//ViewAttendance();
	ExportAttendance();

	return 0;
}