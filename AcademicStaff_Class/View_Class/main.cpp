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

int main()
{
	viewClass();
	if (_CrtDumpMemoryLeaks())
		cout << "\nMemory leak!" << endl;
	system("pause>nul");
	return 0;
}