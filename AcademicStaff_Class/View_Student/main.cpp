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
	viewClass();
	cout << "Input class you want to view: " << flush;
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

int main()
{
	viewClass();
	if (_CrtDumpMemoryLeaks())
		cout << "\nMemory leak!" << endl;
	system("pause>nul");
	return 0;
}