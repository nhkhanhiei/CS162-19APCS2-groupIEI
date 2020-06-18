#include "StudentMenu.h"
#include "HeaderStaffClass.h"

void ViewAttendance()
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
	StudentMenu* student = new StudentMenu[n + 1];
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
	StudentMenu* student = new StudentMenu[n + 1];
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
void ViewStudentsList()
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
	StudentMenu* student = new StudentMenu[n + 1];
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
	StudentMenu* student = new StudentMenu[n + 1];
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
	for (int j = 0; j < 10; j++)
	{
		int length = student[pos].att[j].length();
		if (student[pos].att[j][length - 1] == '1')
		{
			temp = student[pos].att[j];
			temp.resize(11);
			cout << j + 1 << ". " << temp << ": Absent" << endl;
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
	if (student[pos].att[choice - 1][length - 1] == '0')
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
	StudentMenu* student = new StudentMenu[n + 1];
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
int CheckTime(Schedules days) // return the position of that period in the periods(day) array or -1 if false
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
	StudentMenu* student = new StudentMenu[n + 1];
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
	Schedules days;
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
		student[pos].att[tpos][length - 1] = '0';
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
	if(tpos != -1)
	cout << "Checked in successfully" << endl;
	fin.close();
	fout.close();
	delete[] student;
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
	filename += '-' + temp + "-Student.txt";
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
	StudentMenu* student = new StudentMenu[n + 1];
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
	cout << "Your check-in results: " << endl;
	for (int j = 0; j < 10; j++)
	{
		int length = student[pos].att[j].length();
		if (student[pos].att[j][length - 1] == '1')
		{
			student[pos].att[j].resize(11);
			cout << student[pos].att[j] << ": Absent" << endl;
		}
		else
		{
			student[pos].att[j].resize(11);
			cout << student[pos].att[j] << ": Present" << endl;
		}
		cout << endl;
	}
	fin.close();
	delete[] student;
}
void ViewSchedules()
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
	filename += '-' + temp + "-Student.txt";
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
	StudentMenu student;
	getline(fin, student.id);
	getline(fin, student.password);
	getline(fin, student.name);
	getline(fin, student.DoB);
	getline(fin, student.Class);
	getline(fin, student.status);
	getline(fin, student.midterm);
	getline(fin, student.final);
	getline(fin, student.bonus);
	getline(fin, student.total);
	for (int j = 0; j < 10; j++)
		getline(fin, student.att[j]);

	Schedules days;
	//Get hour and min
	string temptime;
	temp = student.att[0];
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
		temp = student.att[i];
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
//Student
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
	filename += '-' + temp + "-Student.txt";
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
	StudentMenu* student = new StudentMenu[n + 1];
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

	cout << "Your scores of this course: " << endl;
	cout << "Midterm: " << student[pos].midterm << endl;
	cout << "Final: " << student[pos].final << endl;
	cout << "Bonus: " << student[pos].bonus << endl;
	cout << "Total: " << student[pos].total << endl;
	fin.close();
	delete[] student;
}

/*void toUpper(char& c)
{
	c = toupper(static_cast<unsigned char>(c));
}*/

void viewScoreboard()
{
	string temp, filename;

	cout << "Input scoreboard you would like to see: \n" << endl;
	cout << "   Year(yyyy-yyyy): ";
	getline(cin, filename);
	for_each(filename.begin(), filename.end(), toUpper);
	string f1 = filename;

	cout << "   Semester: ";
	getline(cin, temp);
	for_each(temp.begin(), temp.end(), toUpper);
	string f2 = temp;
	filename += '-' + temp;

	cout << "   Class: ";
	getline(cin, temp);
	for_each(temp.begin(), temp.end(), toUpper);
	string f3 = temp;
	filename += '-' + temp;

	cout << "   Course ID: ";
	getline(cin, temp);
	for_each(temp.begin(), temp.end(), toUpper);
	string f4 = temp;

	filename += '-' + temp + "-Student.txt";
	fstream fin;
	fin.open(filename, ios::in);

	if (fin.fail())
	{
		cout << "\nUnable to open file!" << endl;
		fin.close();
		return;
	}

	system("cls");
	cout << "<School year: " << f1 << "\\ Semester: " << f2 << "\\ Class: " << f3 << "\\ Course: " << f4 << ">" << endl;
	cout << "\n";
	int n;
	fin >> n;
	fin.ignore();
	StudentMenu* student = new StudentMenu[n + 1];
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

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << student[i].name << ": " << endl;

		cout << "   + Midterm: " << student[i].midterm;
		if (student[i].midterm == "-1")
			cout << " (Student yet to have this grade!)" << endl;
		else
			cout << endl;
		cout << "   + Final: " << student[i].final;
		if (student[i].final == "-1")
			cout << "   (Student yet to have this grade!)" << endl;
		else
			cout << endl;
		cout << "   + Bonus: " << student[i].bonus;
		if (student[i].bonus == "-1")
			cout << "   (Student yet to have this grade!)" << endl;
		else
			cout << endl;
		cout << "   + Total: " << student[i].total;
		if (student[i].total == "-1")
			cout << "   (Student yet to have this grade!)" << endl;
		else
			cout << endl;
		cout << "\n";
	}

	fin.close();
	delete[] student;
}

void importScoreboard()
{
	cout << "Input scoreboard you would like to import: \n" << endl;

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
		StudentMenu* student = new StudentMenu[n + 1];
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

		cout << "\nImport students' score done!" << endl;
	}

}

void exportScoreboard()
{
	string temp, filename;

	cout << "Input scoreboard you would like to export: \n" << endl;
	cout << "   Year(yyyy-yyyy): ";
	getline(cin, filename);
	for_each(filename.begin(), filename.end(), toUpper);
	string f1 = filename;

	cout << "   Semester: ";
	getline(cin, temp);
	for_each(temp.begin(), temp.end(), toUpper);
	string f2 = temp;
	filename += '-' + temp;

	cout << "   Class: ";
	getline(cin, temp);
	for_each(temp.begin(), temp.end(), toUpper);
	string f3 = temp;
	filename += '-' + temp;

	cout << "   Course ID: ";
	getline(cin, temp);
	for_each(temp.begin(), temp.end(), toUpper);
	string f4 = temp;

	filename += '-' + temp + "-Student.txt";
	fstream fin;
	fin.open(filename, ios::in);

	if (fin.fail())
	{
		cout << "\nUnable to open file!" << endl;
		fin.close();
		return;
	}

	int n;
	fin >> n;
	fin.ignore();
	StudentMenu* student = new StudentMenu[n + 1];
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
	fin.close();

	fstream fout;
	string F;
	F += f3;
	F += "-";
	F += f4;
	F += "-Scoreboard.csv";

	fout.open(F, ios::out);
	fout << "No,Student ID,Fullname,Midterm,Final,Bonus,Total";
	string def;
	fout << endl;
	for (int i = 0; i < n; i++)
	{
		fout << i + 1 << "," << student[i].id << "," << student[i].name << "," << student[i].midterm << "," << student[i].final << "," << student[i].bonus << "," << student[i].total << ",";
		fout << endl;
	}
	fout.close();
	delete[] student;

	cout << "\nExport successfully!" << endl;
}