#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
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
typedef CourseData CSD;


void CreateCourseSchedule(string year, string semester, string Class, string schedule[], int k)
{
	string filename = year + '-' + semester + "-Schedule-" + Class + ".txt";
	ofstream f(filename);
	if (f.is_open())
	{
		f << k;
		for (int i = 0; i < k)
	}
	else 
		cout << "Could not open file!" << endl;
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


	string schedule[1000];
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


}

int main()
{
	InportAndCreateFile();
	system("pause>nul");
	return 0;
}