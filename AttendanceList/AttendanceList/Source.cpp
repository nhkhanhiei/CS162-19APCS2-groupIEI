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

struct Student
{
	string id, password, name, DoB, Class, status,midterm,final,bonus,total;
	string att[11];
};

struct Schedule
{
	Dates day[11];
	int startHour;
	int startMin;
	int endHour;
	int endMin;
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
	cout << "Course ID: ";
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
		getline(fin, student[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}
	for (int i = 0; i < n; i++)
	{
		cout << student[i].name << ": " << endl;
		for (int j = 0; j < 10; j++)
		{
			int length = student[i].att[j].length();
			if (student[i].att[j][length - 1] == '1')
			{
				student[i].att[j].resize(11);
				cout << student[i].att[j] << ": Absent" << endl;
			}
			else
			{
				student[i].att[j].resize(11);
				cout << student[i].att[j] << ": Present" << endl;
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
	cout << "Course ID: ";
	getline(cin, temp);
	filename += '-' + temp + "-Student.txt";
	fstream fin;
	fin.open(filename, ios::in || ios::out);
	fstream fout;
	int pos = filename.find(".txt");
	filename.erase(pos);
	filename += ".csv";
	fout.open(filename, ios::out);
	if (fin.fail())
	{
		cout << "Can't open course file!" << endl;
		fin.close();
		return;
	}
	if (fout.fail())
	{
		cout << "Can't open destination file!" << endl;
		fin.close();
		fout.close();
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
			getline(fin, student[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}
	



	fout << "No,Student ID,Full name,Class,";
	string def;
	for (int j = 0; j < 10; j++)
	{
		def = student[0].att[j];
		def.resize(10);
		fout << def << ",";
	}
	fout << endl;
	for (int i = 0; i < n; i++)
	{
		fout << i + 1 << "," << student[i].id << "," << student[i].name <<
			"," << student[i].Class << ",";
		bool last = false;
		for (int j = 0; j < 10; j++)
		{
			if (j == 9)
				last = true;
			int length = student[i].att[j].length();
			if (student[i].att[j][length - 1] == '1')
				fout << "Absent";
			else fout << "Present";
			if (last)
				fout << endl;
			else fout << ",";
		}
	}
	fin.close();
	fout.close();
	delete[] student;
}
void ViewStudentList()
{
	//2019-2020-HK2-19APCS1-CM101-Student.txt
	string temp, filename;
	cout << "Which student list would you like to see?" << endl;
	cout << "Please enter the following information of the course: " << endl;
	cout << "Year(yyyy-yyyy): ";
	getline(cin, filename);
	cout << "Semester: ";
	getline(cin, temp);
	filename += '-' + temp;
	cout << "Class: ";
	getline(cin, temp);
	filename += '-' + temp;
	cout << "Course ID: ";
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
			getline(fin, student[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}
	cout << "List of students studying: ";
	for (int i = 0; i < n; i++)
	{
		if (student[i].status == "1")
			cout << student[i].name << endl;
	}
	fin.close();
	delete[] student;
}
void EditAttendance()
{
	string temp, filename;
	cout << "Which attendance list would you like to edit?" << endl;
	cout << "Please enter the following information: " << endl;
	cout << "Year(yyyy-yyyy): ";
	getline(cin, filename);
	cout << "Semester: ";
	getline(cin, temp);
	filename += '-' + temp;
	cout << "Class: ";
	getline(cin, temp);
	filename += '-' + temp;
	cout << "Course ID: ";
	getline(cin, temp);
	filename += '-' + temp + "-Student.txt";

	
	fstream fin;
	fin.open(filename, ios::in | ios::out);
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
			getline(fin, student[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}

	//Get student
	cout << "Which student's attendace would you like to edit?" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << student[i].name << endl;
	}
	int pos = 0;
	cout << "Please choose from 1 to " << n  << ": " ;
	cin >> pos;
	pos--;
	int length = student[pos].att->length();
	if (student[pos].status == "0")
	{
		cout << "This student has been removed from the course" << endl;
		fin.close();
		delete[] student;
		return;
	}
	for (int j = 0; j < 10; j++)
	{
		int length = student[pos].att[j].length();
		if (student[pos].att[j][length - 1] == '1')
		{
			temp = student[pos].att[j];
			temp.resize(11);
			cout << j+1 << ". " << temp << ": Absent" << endl;
		}
		else
		{
			temp = student[pos].att[j];
			temp.resize(11);
			cout << j + 1 << ". " << temp << ": Present" << endl;
		}
	}
	int choice;
	cout << "Enter the day of attendance you would like to change (1-10): " << endl;
	cin >> choice;
	if (student[pos].att[choice-1][length - 1] == '0')
	{
		cout << "Attendace edited to absent" << endl;
		student[pos].att[choice - 1][length - 1] = '1';
	}
	else {
		cout << "Attendace edited to present" << endl;
		student[pos].att[choice - 1][length - 1] = '0';
	}

	fstream fout;
	fout.open(filename, ios::out);
	if (fout.fail())
	{
		cout << "Can't open destination file!" << endl;
		fin.close();
		fout.close();
		delete[] student;
		return;
	}
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << student[i].id << endl;
		fout << student[i].password << endl;
		fout << student[i].name << endl;
		fout << student[i].DoB << endl;
		fout << student[i].Class << endl;
		fout << student[i].status << endl;
		fout << student[i].midterm << endl;
		fout << student[i].final << endl;
		fout << student[i].bonus << endl;
		fout << student[i].total << endl;
		for (int j = 0; j < 10; j++)
			fout << student[i].att[j] << endl;
		fout << 1 << endl << endl;
	}
	fin.close();
	fout.close();
	delete[] student;
}
void EditGrade()
{
	string temp, filename;
	cout << "Which course's grade would you like to edit?" << endl;
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
	fin.open(filename, ios::in | ios::out);
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
			getline(fin, student[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}

	//Get student
	cout << "Which student's grade would you like to edit?" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << student[i].name << endl;
	}
	int pos = 0;
	cout << "Please choose from 1 to " << n << ": ";
	cin >> pos;
	pos--;
	int length = student[pos].att->length();
	if (student[pos].status == "0")
	{
		cout << "This student has been removed from the course" << endl;
		fin.close();
		delete[] student;
		return;
	}
	cout << "Scores of " << student[pos].name << endl;
	cout << "1.Midterm:  " << student[pos].midterm << endl;
	cout << "2.Final: " << student[pos].final << endl;
	cout << "3.Bonus: " << student[pos].bonus << endl;
	cout << "4.Total: " << student[pos].total << endl;
	int choice;
	cout << "Enter the grade you would like to change (1-4): ";
	cin >> choice;
	cout << "Enter the new grade: ";
	switch (choice)
	{
	case 1: cin >> student[pos].midterm; break;
	case 2: cin >> student[pos].final; break;
	case 3: cin >> student[pos].bonus; break;
	case 4: cin >> student[pos].total; break;
	}

	fstream fout;
	fout.open(filename, ios::out);
	if (fout.fail())
	{
		cout << "Can't open destination file!" << endl;
		fin.close();
		fout.close();
		delete[] student;
		return;
	}
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << student[i].id << endl;
		fout << student[i].password << endl;
		fout << student[i].name << endl;
		fout << student[i].DoB << endl;
		fout << student[i].Class << endl;
		fout << student[i].status << endl;
		fout << student[i].midterm << endl;
		fout << student[i].final << endl;
		fout << student[i].bonus << endl;
		fout << student[i].total << endl;
		for (int j = 0; j < 10; j++)
			fout << student[i].att[j] << endl;
		fout << 1 << endl << endl;
	}
	fin.close();
	fout.close();
	delete[] student;
}
//To see if the present time is one of the 9 periods in the file
int CheckTime(Schedule days) // return the position of that period in the periods(day) array or -1 if false
{
	time_t now = time(0);
	tm* time = localtime(&now);
	time->tm_year += 1900;
	time->tm_mon++;
	for (int i = 0; i < 10; i++)
	{
		if (days.day[i].day == time->tm_mday && days.day[i].month == time->tm_mon && days.day[i].year == time->tm_year)
		{
			if (time->tm_hour >= days.startHour && time->tm_hour <= days.endHour)
			{
				if (time->tm_hour == days.endHour)
				{
					if (time->tm_min <= days.endMin)
						return i;
					else return -1;
				}
				else return i;
			}
		}

	}
	return -1;
}
void CheckIn()
{
	string name;
	string temp, filename;
	cout << "Please enter your name: ";
	getline(cin, name);
	cout << "Please enter the information of the course you are checking in : " << endl;
	cout << "Year(yyyy-yyyy): ";
	getline(cin, filename);
	cout << "Semester: ";
	getline(cin, temp);
	filename += '-' + temp;
	cout << "Class: ";
	getline(cin, temp);
	filename += '-' + temp;
	cout << "Course ID: ";
	getline(cin, temp);
	filename += '-' + temp + "-Student.txt";
	fstream fin;
	fin.open("2019-2020-HK2-19APCS1-CS162-Student.txt", ios::in | ios::out);
	if (fin.fail())
	{
		cout << "Can't open the course file!";
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
			getline(fin, student[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}

	//Get student
	int pos = -1;
	for (int i = 0; i < n; i++)
	{
		if (student[i].name == name)
			pos = i;
	}
	if (student[pos].status == "0")
	{
		cout << "You have been removed from the course" << endl;
		fin.close();
		delete[] student;
		return;
	}
	if (pos == -1)
	{
		cout << "Your name doesn't exist in the list of students studying this course" << endl;
		fin.close();
		delete[] student;
		return;
	}
	Schedule days;
	//Get hour and min
	string temptime;
	temp = student[0].att[0];
	int length = temp.length();
	int countspace = 0;
	bool next = false;
	for (int i = 11; i < length; i++)
	{
		if (temp[i] == ' ')
		{
			countspace++;
			switch (countspace)
			{
			case 1: days.startHour = stoi(temptime); temptime.clear(); break;
			case 2: days.startMin = stoi(temptime); temptime.clear(); break;
			case 3: days.endHour = stoi(temptime); temptime.clear(); break;
			case 4: days.endMin = stoi(temptime); temptime.clear(); break;
			}
			continue;
		}
		temptime += temp[i];
	}

	//Get day,month,year
	for (int i = 0; i < 10; i++)
	{
		temp = student[pos].att[i];
		days.day[i].year = stoi(temp.substr(0, 4));
		days.day[i].month = stoi(temp.substr(5, 2));
		days.day[i].day = stoi(temp.substr(8, 2));
	}
	
	int tpos = CheckTime(days);
	if (tpos == -1)
		cout << "There is currently no class to check in" << endl;
	else {
		student[pos].att[tpos][length-1] = '0';
	}
	fstream fout;
	fout.open(filename, ios::out);
	if (fout.fail())
	{
		cout << "Can't open destination file!" << endl;
		fin.close();
		fout.close();
		delete[] student;
		return;
	}
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << student[i].id << endl;
		fout << student[i].password << endl;
		fout << student[i].name << endl;
		fout << student[i].DoB << endl;
		fout << student[i].Class << endl;
		fout << student[i].status << endl;
		fout << student[i].midterm << endl;
		fout << student[i].final << endl;
		fout << student[i].bonus << endl;
		fout << student[i].total << endl;
		for (int j = 0; j < 10; j++)
			fout << student[i].att[j] << endl;
		fout << 1 << endl << endl;
	}
	cout << "Checked in successfully" << endl;
	fin.close();
	fout.close();
	delete[] student;
}
int main()
{
	//ViewAttendance();
	//ExportAttendance();
	//ViewStudentList();
	//EditAttendance();
	//EditGrade();
	CheckIn();
	return 0;
}