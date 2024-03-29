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

struct Students
{
	string id, password, name, DoB, Class, status,midterm,final,bonus,total;
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


void ViewAttendance()
{
	//2019-2020-HK2-19APCS1-CM101-Students.txt
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
	filename += '-' + temp + "-Students.txt" ;
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
	Students* Students = new Students[n+1];
	for (int i = 0; i < n; i++)
	{
		getline(fin, Students[i].id);
		getline(fin, Students[i].password);
		getline(fin, Students[i].name);
		getline(fin, Students[i].DoB);
		getline(fin, Students[i].Class);
		getline(fin, Students[i].status);
		getline(fin, Students[i].midterm);
		getline(fin, Students[i].final);
		getline(fin, Students[i].bonus);
		getline(fin, Students[i].total);
		for(int j = 0; j < 10; j++)
		getline(fin, Students[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}
	for (int i = 0; i < n; i++)
	{
		cout << Students[i].name << ": " << endl;
		for (int j = 0; j < 10; j++)
		{
			int length = Students[i].att[j].length();
			if (Students[i].att[j][length - 1] == '1')
			{
				Students[i].att[j].resize(11);
				cout << Students[i].att[j] << ": Absent" << endl;
			}
			else
			{
				Students[i].att[j].resize(11);
				cout << Students[i].att[j] << ": Present" << endl;
			}
		}
		cout << endl;
	}
	fin.close();
	delete[] Students;
}
void ExportAttendance()
{
	//2019-2020-HK2-19APCS1-CM101-Students.txt
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
	filename += '-' + temp + "-Students.txt";
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
	Students* Students = new Students[n + 1];
	for (int i = 0; i < n; i++)
	{
		getline(fin, Students[i].id);
		getline(fin, Students[i].password);
		getline(fin, Students[i].name);
		getline(fin, Students[i].DoB);
		getline(fin, Students[i].Class);
		getline(fin, Students[i].status);
		getline(fin, Students[i].midterm);
		getline(fin, Students[i].final);
		getline(fin, Students[i].bonus);
		getline(fin, Students[i].total);
		for (int j = 0; j < 10; j++)
			getline(fin, Students[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}
	



	fout << "No,Students ID,Full name,Class,";
	string def;
	for (int j = 0; j < 10; j++)
	{
		def = Students[0].att[j];
		def.resize(10);
		fout << def << ",";
	}
	fout << endl;
	for (int i = 0; i < n; i++)
	{
		fout << i + 1 << "," << Students[i].id << "," << Students[i].name <<
			"," << Students[i].Class << ",";
		bool last = false;
		for (int j = 0; j < 10; j++)
		{
			if (j == 9)
				last = true;
			int length = Students[i].att[j].length();
			if (Students[i].att[j][length - 1] == '1')
				fout << "Absent";
			else fout << "Present";
			if (last)
				fout << endl;
			else fout << ",";
		}
	}
	fin.close();
	fout.close();
	delete[] Students;
}
void ViewStudentsList()
{
	//2019-2020-HK2-19APCS1-CM101-Students.txt
	string temp, filename;
	cout << "Which Students list would you like to see?" << endl;
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
	filename += '-' + temp + "-Students.txt";
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
	Students* Students = new Students[n + 1];
	for (int i = 0; i < n; i++)
	{
		getline(fin, Students[i].id);
		getline(fin, Students[i].password);
		getline(fin, Students[i].name);
		getline(fin, Students[i].DoB);
		getline(fin, Students[i].Class);
		getline(fin, Students[i].status);
		getline(fin, Students[i].midterm);
		getline(fin, Students[i].final);
		getline(fin, Students[i].bonus);
		getline(fin, Students[i].total);
		for (int j = 0; j < 10; j++)
			getline(fin, Students[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}
<<<<<<< HEAD
	cout << "List of Studentss studying: ";
	for (int i = 0; i < n; i++)
	{
		if (Students[i].status == "1")
			cout << Students[i].name << endl;
=======
	cout << "List of students studying: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (student[i].status == "1")
		{
			cout << student[i].name << endl;
			cout << student[i].id << endl;
		}
>>>>>>> 85c6975f8f8fd4ce9a56df6c17c801caa3897d25
	}
	fin.close();
	delete[] Students;
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
	filename += '-' + temp + "-Students.txt";

	
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
	Students* Students = new Students[n + 1];
	for (int i = 0; i < n; i++)
	{
		getline(fin, Students[i].id);
		getline(fin, Students[i].password);
		getline(fin, Students[i].name);
		getline(fin, Students[i].DoB);
		getline(fin, Students[i].Class);
		getline(fin, Students[i].status);
		getline(fin, Students[i].midterm);
		getline(fin, Students[i].final);
		getline(fin, Students[i].bonus);
		getline(fin, Students[i].total);
		for (int j = 0; j < 10; j++)
			getline(fin, Students[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}

<<<<<<< HEAD
	//Get Students
	cout << "Which Students's attendace would you like to edit?" << endl;
=======
	//Get student
	cout << "Which student's attendance would you like to edit?" << endl;
>>>>>>> 85c6975f8f8fd4ce9a56df6c17c801caa3897d25
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << Students[i].name << endl;
	}
	int pos = 0;
	cout << "Please choose from 1 to " << n  << ": " ;
	cin >> pos;
	pos--;
	int length = Students[pos].att->length();
	if (Students[pos].status == "0")
	{
		cout << "This Students has been removed from the course" << endl;
		fin.close();
		delete[] Students;
		return;
	}
	for (int j = 0; j < 10; j++)
	{
		int length = Students[pos].att[j].length();
		if (Students[pos].att[j][length - 1] == '1')
		{
			temp = Students[pos].att[j];
			temp.resize(11);
			cout << j+1 << ". " << temp << ": Absent" << endl;
		}
		else
		{
			temp = Students[pos].att[j];
			temp.resize(11);
			cout << j + 1 << ". " << temp << ": Present" << endl;
		}
	}
	int choice;
	cout << "Enter the day of attendance you would like to change (1-10): " << endl;
	cin >> choice;
	if (Students[pos].att[choice-1][length - 1] == '0')
	{
		cout << "Attendace edited to absent" << endl;
		Students[pos].att[choice - 1][length - 1] = '1';
	}
	else {
		cout << "Attendace edited to present" << endl;
		Students[pos].att[choice - 1][length - 1] = '0';
	}

	fstream fout;
	fout.open(filename, ios::out);
	if (fout.fail())
	{
		cout << "Can't open destination file to edit attendance!" << endl;
		fin.close();
		fout.close();
		delete[] Students;
		return;
	}
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << Students[i].id << endl;
		fout << Students[i].password << endl;
		fout << Students[i].name << endl;
		fout << Students[i].DoB << endl;
		fout << Students[i].Class << endl;
		fout << Students[i].status << endl;
		fout << Students[i].midterm << endl;
		fout << Students[i].final << endl;
		fout << Students[i].bonus << endl;
		fout << Students[i].total << endl;
		for (int j = 0; j < 10; j++)
			fout << Students[i].att[j] << endl;
		fout << 1 << endl << endl;
	}
	fin.close();
	fout.close();
	delete[] Students;
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
	filename += '-' + temp + "-Students.txt";


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
	Students* Students = new Students[n + 1];
	for (int i = 0; i < n; i++)
	{
		getline(fin, Students[i].id);
		getline(fin, Students[i].password);
		getline(fin, Students[i].name);
		getline(fin, Students[i].DoB);
		getline(fin, Students[i].Class);
		getline(fin, Students[i].status);
		getline(fin, Students[i].midterm);
		getline(fin, Students[i].final);
		getline(fin, Students[i].bonus);
		getline(fin, Students[i].total);
		for (int j = 0; j < 10; j++)
			getline(fin, Students[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}

	//Get Students
	cout << "Which Students's grade would you like to edit?" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << Students[i].name << endl;
	}
	int pos = 0;
	cout << "Please choose from 1 to " << n << ": ";
	cin >> pos;
	pos--;
	int length = Students[pos].att->length();
	if (Students[pos].status == "0")
	{
		cout << "This Students has been removed from the course" << endl;
		fin.close();
		delete[] Students;
		return;
	}
	cout << "Scores of " << Students[pos].name << endl;
	cout << "1.Midterm:  " << Students[pos].midterm << endl;
	cout << "2.Final: " << Students[pos].final << endl;
	cout << "3.Bonus: " << Students[pos].bonus << endl;
	cout << "4.Total: " << Students[pos].total << endl;
	int choice;
	cout << "Enter the grade you would like to change (1-4): ";
	cin >> choice;
	cout << "Enter the new grade: ";
	switch (choice)
	{
	case 1: cin >> Students[pos].midterm; break;
	case 2: cin >> Students[pos].final; break;
	case 3: cin >> Students[pos].bonus; break;
	case 4: cin >> Students[pos].total; break;
	}

	fstream fout;
	fout.open(filename, ios::out);
	if (fout.fail())
	{
		cout << "Can't open destination file!" << endl;
		fin.close();
		fout.close();
		delete[] Students;
		return;
	}
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << Students[i].id << endl;
		fout << Students[i].password << endl;
		fout << Students[i].name << endl;
		fout << Students[i].DoB << endl;
		fout << Students[i].Class << endl;
		fout << Students[i].status << endl;
		fout << Students[i].midterm << endl;
		fout << Students[i].final << endl;
		fout << Students[i].bonus << endl;
		fout << Students[i].total << endl;
		for (int j = 0; j < 10; j++)
			fout << Students[i].att[j] << endl;
		fout << 1 << endl << endl;
	}
	fin.close();
	fout.close();
	delete[] Students;
}
//To see if the present time is one of the 9 periods in the file
int CheckTime(Schedules days) // return the position of that period in the periods(day) array or -1 if false
{
	time_t now = time(0);
	tm* time = localtime(&now);
	cout << "Year:" << 1900 + time->tm_year << endl;
	cout << "Month: " << 1 + time->tm_mon << endl;
	cout << "Day: " << time->tm_mday << endl;
	cout << "Time: " << time->tm_hour << ":";
	cout << time->tm_min << ":";
	cout << time->tm_sec << endl;
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
	filename += '-' + temp + "-Students.txt";
	fstream fin;
	fin.open(filename, ios::in | ios::out);
	if (fin.fail())
	{
		cout << "Can't open the course file!";
		fin.close();
		return;
	}
	int n;
	fin >> n;
	fin.ignore();
	Students* Students = new Students[n + 1];
	for (int i = 0; i < n; i++)
	{
		getline(fin, Students[i].id);
		getline(fin, Students[i].password);
		getline(fin, Students[i].name);
		getline(fin, Students[i].DoB);
		getline(fin, Students[i].Class);
		getline(fin, Students[i].status);
		getline(fin, Students[i].midterm);
		getline(fin, Students[i].final);
		getline(fin, Students[i].bonus);
		getline(fin, Students[i].total);
		for (int j = 0; j < 10; j++)
			getline(fin, Students[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}

	//Get Students
	int pos = -1;
	for (int i = 0; i < n; i++)
	{
		if (Students[i].name == name)
			pos = i;
	}
	if (Students[pos].status == "0")
	{
		cout << "You have been removed from the course" << endl;
		fin.close();
		delete[] Students;
		return;
	}
	if (pos == -1)
	{
		cout << "Your name doesn't exist in the list of Studentss studying this course" << endl;
		fin.close();
		delete[] Students;
		return;
	}
	Schedules days;
	//Get hour and min
	string temptime;
	temp = Students[0].att[0];
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
		temp = Students[pos].att[i];
		days.day[i].year = stoi(temp.substr(0, 4));
		days.day[i].month = stoi(temp.substr(5, 2));
		days.day[i].day = stoi(temp.substr(8, 2));
	}
	
	int tpos = CheckTime(days);
	if (tpos == -1)
		cout << "There is currently no class to check in" << endl;
	else {
		Students[pos].att[tpos][length-1] = '0';
	}
	fstream fout;
	fout.open(filename, ios::out);
	if (fout.fail())
	{
		cout << "Can't open destination file!" << endl;
		fin.close();
		fout.close();
		delete[] Students;
		return;
	}
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << Students[i].id << endl;
		fout << Students[i].password << endl;
		fout << Students[i].name << endl;
		fout << Students[i].DoB << endl;
		fout << Students[i].Class << endl;
		fout << Students[i].status << endl;
		fout << Students[i].midterm << endl;
		fout << Students[i].final << endl;
		fout << Students[i].bonus << endl;
		fout << Students[i].total << endl;
		for (int j = 0; j < 10; j++)
			fout << Students[i].att[j] << endl;
		fout << 1 << endl << endl;
	}
	cout << "Checked in successfully" << endl;
	fin.close();
	fout.close();
	delete[] Students;
}
void ViewCheckIn()
{
	string name;
	string temp, filename;
	cout << "Please enter your name: ";
	getline(cin, name);
	cout << "Please enter the information of the course whose check-in results you need : " << endl;
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
	filename += '-' + temp + "-Students.txt";
	fstream fin;
	fin.open(filename, ios::in | ios::out);
	if (fin.fail())
	{
		cout << "Can't open the course file!";
		fin.close();
		return;
	}
	int n;
	fin >> n;
	fin.ignore();
	Students* Students = new Students[n + 1];
	for (int i = 0; i < n; i++)
	{
		getline(fin, Students[i].id);
		getline(fin, Students[i].password);
		getline(fin, Students[i].name);
		getline(fin, Students[i].DoB);
		getline(fin, Students[i].Class);
		getline(fin, Students[i].status);
		getline(fin, Students[i].midterm);
		getline(fin, Students[i].final);
		getline(fin, Students[i].bonus);
		getline(fin, Students[i].total);
		for (int j = 0; j < 10; j++)
			getline(fin, Students[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}

	//Get Students
	int pos = -1;
	for (int i = 0; i < n; i++)
	{
		if (Students[i].name == name)
			pos = i;
	}
	if (Students[pos].status == "0")
	{
		cout << "You have been removed from the course" << endl;
		fin.close();
		delete[] Students;
		return;
	}
	if (pos == -1)
	{
		cout << "Your name doesn't exist in the list of Studentss studying this course" << endl;
		fin.close();
		delete[] Students;
		return;
	}
	cout << "Your check-in results: " << endl;
	for (int j = 0; j < 10; j++)
	{
		int length = Students[pos].att[j].length();
		if (Students[pos].att[j][length - 1] == '1')
		{
			Students[pos].att[j].resize(11);
			cout << Students[pos].att[j] << ": Absent" << endl;
		}
		else
		{
			Students[pos].att[j].resize(11);
			cout << Students[pos].att[j] << ": Present" << endl;
		}
	cout << endl;
	}
	fin.close();
	delete[] Students;
}
void ViewScheduless()
{
	string temp, filename;
	cout << "Please enter the information of the course: " << endl;
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
	filename += '-' + temp + "-Students.txt";
	fstream fin;
	fin.open(filename, ios::in | ios::out);
	if (fin.fail())
	{
		cout << "Can't open the course file!";
		fin.close();
		return;
	}
	int n;
	fin >> n;
	fin.ignore();
	Students Students;
	getline(fin, Students.id);
	getline(fin, Students.password);
	getline(fin, Students.name);
	getline(fin, Students.DoB);
	getline(fin, Students.Class);
	getline(fin, Students.status);
	getline(fin, Students.midterm);
	getline(fin, Students.final);
	getline(fin, Students.bonus);
	getline(fin, Students.total);
	for (int j = 0; j < 10; j++)
		getline(fin, Students.att[j]);
	
	Schedules days;
	//Get hour and min
	string temptime;
	temp = Students.att[0];
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
		temp = Students.att[i];
		days.day[i].year = stoi(temp.substr(0, 4));
		days.day[i].month = stoi(temp.substr(5, 2));
		days.day[i].day = stoi(temp.substr(8, 2));
	}
	cout << "You have classes on these following days from " << days.startHour << ":" << days.startMin << " to " <<
	days.endHour << ":" << days.endMin << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << days.day[i].day << "/" << days.day[i].month << "/" << days.day[i].year << endl;
	}
	fin.close();
}
//Students
void ViewScore()
{
	string name;
	string temp, filename;
	cout << "Please enter your name: ";
	getline(cin, name);
	cout << "Please enter the information of the course whose scores you need : " << endl;
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
	filename += '-' + temp + "-Students.txt";
	fstream fin;
	fin.open(filename, ios::in | ios::out);
	if (fin.fail())
	{
		cout << "Can't open the course file!";
		fin.close();
		return;
	}
	int n;
	fin >> n;
	fin.ignore();
	Students* Students = new Students[n + 1];
	for (int i = 0; i < n; i++)
	{
		getline(fin, Students[i].id);
		getline(fin, Students[i].password);
		getline(fin, Students[i].name);
		getline(fin, Students[i].DoB);
		getline(fin, Students[i].Class);
		getline(fin, Students[i].status);
		getline(fin, Students[i].midterm);
		getline(fin, Students[i].final);
		getline(fin, Students[i].bonus);
		getline(fin, Students[i].total);
		for (int j = 0; j < 10; j++)
			getline(fin, Students[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}

	//Get Students
	int pos = -1;
	for (int i = 0; i < n; i++)
	{
		if (Students[i].name == name)
			pos = i;
	}
	if (Students[pos].status == "0")
	{
		cout << "You have been removed from the course" << endl;
		fin.close();
		delete[] Students;
		return;
	}
	if (pos == -1)
	{
		cout << "Your name doesn't exist in the list of Studentss studying this course" << endl;
		fin.close();
		delete[] Students;
		return;
	}
	
	cout << "Your scores of this course: " << endl;
	cout << "Midterm: " << Students[pos].midterm << endl;
	cout << "Final: " << Students[pos].final << endl;
	cout << "Bonus: " << Students[pos].bonus << endl;
	cout << "Total: " << Students[pos].total << endl;
	fin.close();
	delete[] Students;
}
string dayFormat(int a)
{
	if (a < 10)
		return "0" + to_string(a);
	else
		return to_string(a);
}
int main()
{
	//ViewAttendance();
	//ExportAttendance();
	//ViewStudentsList();
	//EditAttendance();
	//EditGrade();
	CheckIn();
	//ViewCheckIn();
<<<<<<< HEAD
	//ViewScheduless();
	ViewScore();
=======
	//ViewSchedules();
	//ViewScore();
>>>>>>> 85c6975f8f8fd4ce9a56df6c17c801caa3897d25
	return 0;
}