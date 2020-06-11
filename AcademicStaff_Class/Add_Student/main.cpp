#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <sstream>

using namespace std;

struct Date
{
	string day;
	string month;
	string year;
};

struct Student
{
	int id = 0;
	string password;
	string fullname;
	Date dob;
	int status = 0;
};

void toUpper(char& c)
{
	c = toupper(static_cast<unsigned char>(c));
}

int viewClass()
{
	fstream file;
	file.open("Class.txt", ios::in);

	if (file.fail())
	{
		cout << "Unable to read Class file!" << endl;
		file.close();
		return -1;
	}
	else
	{
		string temp;
		int n;

		file >> n;
		cout << "List of available classes: \n" << endl;
		for (int i = 0; i < n; i++)
		{
			if (i == 0)
			{
				file.ignore();
			}
			getline(file, temp);
			cout << i + 1 << ". " << temp << endl;
			temp = "";
		}
		file.close();
		return n;
	}
}

int viewStudent()
{
	int confirm;
	confirm = viewClass();
	if (confirm == -1)
		return -1;

	cout << "\nInput class you want to view: " << flush;
	string cl;
	cin >> cl;
	for_each(cl.begin(), cl.end(), toUpper);
	system("cls");

	fstream file;
	string fileName = "Student-" + cl + ".txt";
	file.open(fileName, ios::in);

	if (file.fail())
	{
		cout << "Unable to read Student file!" << endl;
		file.close();
		return -1;
	}
	else
	{
		int z;
		file >> z;

		int count = 0;
		int tempDay = 0;
		int tempMonth = 0;
		int tempYear = 0;
		string temp;

		Student* sOfClass;
		sOfClass = new Student[z];

		for (int i = 0; i < z; i++)
		{
			temp = "";
			file >> sOfClass[i].id;
			file.ignore();
			getline(file, sOfClass[i].password);
			getline(file, sOfClass[i].fullname);
			file >> tempYear >> tempMonth >> tempDay;
			file.ignore();
			if (tempDay < 10)
			{
				sOfClass[i].dob.day += '0';
			}
			sOfClass[i].dob.day += to_string(tempDay);

			if (tempMonth < 10)
			{
				sOfClass[i].dob.month += '0';
			}
			sOfClass[i].dob.month += to_string(tempMonth);

			if (tempYear < 10)
				sOfClass[i].dob.year += "000";
			else if (tempYear < 100)
				sOfClass[i].dob.year += "00";
			else if (tempYear < 1000)
				sOfClass[i].dob.year += '0';
			sOfClass[i].dob.year += to_string(tempYear);

			getline(file, temp);
			file >> sOfClass[i].status;
			file.ignore();

			if (sOfClass[i].status == 1)
				count += 1;
		}

		cout << "List of students in class " << cl << ": \n" << endl;
		for (int i = 0; i < z; i++)
		{
			cout << i + 1 << ". " << endl;
			cout << "Student ID: " << sOfClass[i].id << endl;
			cout << "//Password: " << sOfClass[i].password << endl;
			cout << "Name: " << sOfClass[i].fullname << endl;
			cout << "Birthday: " << sOfClass[i].dob.day << "/" << sOfClass[i].dob.month << "/" << sOfClass[i].dob.year << endl;
			cout << "Status: " << sOfClass[i].status;
			if (sOfClass[i].status == 0)
				cout << " (Inactive)" << endl;
			else
				cout << " (Active)" << endl;
			cout << "\n";
		}
		cout << z << " student(s) in class, (" << count << " active)." << endl;
		delete[] sOfClass;
		file.close();
		return z;
	}
}

void addStudent()
{
	int confirm;
	confirm = viewClass();
	if (confirm == -1)
		return;

	cout << "\nInput class of new student: " << flush;
	string cl;
	cin >> cl;
	for_each(cl.begin(), cl.end(), toUpper);
	system("cls");
	cout << "Class " << cl << endl;
	cout << "\n";

	fstream file;
	string fileName = "Student-" + cl + ".txt";
	file.open(fileName, ios::in);

	if (file.fail())
	{
		cout << "Unable to read Student file!" << endl;
		file.close();
	}
	else
	{
		int z;
		file >> z;

		int count = 0;
		int tempDay = 0;
		int tempMonth = 0;
		int tempYear = 0;
		string temp;

		Student* sOfClass;
		sOfClass = new Student[z + 1];

		for (int i = 0; i < z; i++)
		{
			temp = "";
			file >> sOfClass[i].id;
			file.ignore();
			getline(file, sOfClass[i].password);
			getline(file, sOfClass[i].fullname);
			file >> tempYear >> tempMonth >> tempDay;
			file.ignore();
			if (tempDay < 10)
			{
				sOfClass[i].dob.day += '0';
			}
			sOfClass[i].dob.day += to_string(tempDay);

			if (tempMonth < 10)
			{
				sOfClass[i].dob.month += '0';
			}
			sOfClass[i].dob.month += to_string(tempMonth);

			if (tempYear < 10)
				sOfClass[i].dob.year += "000";
			else if (tempYear < 100)
				sOfClass[i].dob.year += "00";
			else if (tempYear < 1000)
				sOfClass[i].dob.year += '0';
			sOfClass[i].dob.year += to_string(tempYear);

			getline(file, temp);
			file >> sOfClass[i].status;
			file.ignore();
			if (sOfClass[i].status == 1)
				count += 1;
		}

		string input;

		cout << "Class has had: " << z << " student(s), (" << count << " active).\n" << endl;

		cout << "Input information of new student: " << endl;
		cout << "   + ID: " << flush;
		cin >> sOfClass[z].id;
		cout << "   + Name: ";
		cin.ignore();
		getline(cin, input);
		sOfClass[z].fullname = input;
		cout << "   + Date of birth: " << endl;
		cout << "      * Day: " << flush;
		do
		{
			cin >> tempDay;
		} while (tempDay <= 0);
		cout << "      * Month: " << flush;
		do
		{
			cin >> tempMonth;
		} while (tempMonth <= 0);
		cout << "      * Year: " << flush;
		do
		{
			cin >> tempYear;
		} while (tempYear <= 0);

		if (tempDay < 10)
		{
			sOfClass[z].dob.day += '0';
		}
		sOfClass[z].dob.day += to_string(tempDay);

		if (tempMonth < 10)
		{
			sOfClass[z].dob.month += '0';
		}
		sOfClass[z].dob.month += to_string(tempMonth);

		if (tempYear < 10)
			sOfClass[z].dob.year += "000";
		else if (tempYear < 100)
			sOfClass[z].dob.year += "00";
		else if (tempYear < 1000)
			sOfClass[z].dob.year += '0';
		sOfClass[z].dob.year += to_string(tempYear);

		sOfClass[z].password = sOfClass[z].dob.year + sOfClass[z].dob.month + sOfClass[z].dob.day;

		sOfClass[z].status = 1;

		file.close();

		file.open(fileName, ios::out);
		file << z + 1 << "\n";
		for (int i = 0; i < z + 1; i++)
		{
			file << sOfClass[i].id;
			file << "\n";
			file << sOfClass[i].password;
			file << "\n";
			file << sOfClass[i].fullname << "\n";
			file << sOfClass[i].dob.year << " " << sOfClass[i].dob.month << " " << sOfClass[i].dob.day << "\n";
			file << cl << "\n";
			file << sOfClass[i].status;
			file << "\n\n";
		}
		cout << "\nAdd a new student successfully!" << endl;
		delete[] sOfClass;
		file.close();
	}
}

int main()
{
	addStudent();
	if (_CrtDumpMemoryLeaks())
		cout << "\nMemory leak!" << endl;
	system("pause>nul");
	return 0;
}