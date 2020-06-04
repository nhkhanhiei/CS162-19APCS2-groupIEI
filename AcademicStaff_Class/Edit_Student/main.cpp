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

void addStudent()
{
	int confirm;
	confirm = viewClass();
	if (confirm == -1)
		return;

	cout << "Input class of new student: " << flush;
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
		cout << "Add a new student successfully!" << endl;
		delete[] sOfClass;
		file.close();
	}
}

void removeStudent()
{
	int confirm;
	confirm = viewClass();
	if (confirm == -1)
		return;
	cout << "Input class of student about to remove : " << flush;
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
		}

		cout << "List of students: \n" << endl;
		for (int i = 0; i < z; i++)
		{
			cout << i + 1 << ". " << endl;
			cout << "Student ID: " << sOfClass[i].id << endl;
			cout << "Name: " << sOfClass[i].fullname << endl;
			cout << "Birthday: " << sOfClass[i].dob.day << "/" << sOfClass[i].dob.month << "/" << sOfClass[i].dob.year << endl;
			cout << "Status: " << sOfClass[i].status;
			if (sOfClass[i].status == 0)
				cout << " (Inactive)" << endl;
			else
				cout << " (Active)" << endl;
			cout << "\n";
		}

		int tempID;
		int check = 0;
		cout << "\nInput ID of student you want to remove: " << flush;
		cin >> tempID;
		system("cls");
		for (int i = 0; i < z; i++)
		{
			if (sOfClass[i].id == tempID && sOfClass[i].status != 0)
			{
				int sure;
				cout << "Name: " << sOfClass[i].fullname << endl;
				cout << "Birthday: " << sOfClass[i].dob.day << "/" << sOfClass[i].dob.month << "/" << sOfClass[i].dob.year << endl;
				cout << "Status: " << sOfClass[i].status << endl;
				cout << "\n";
				cout << "Are you sure to remove this student? (1=Yes, 2=No): " << flush;
				do
				{
					cin >> sure;
				} while (sure != 1 and sure != 2);
				if (sure == 1)
				{
					sOfClass[i].status = 0;
					check++;
					cout << "Remove student successfully!" << endl;
				}
				else
				{
					cout << "Remove student fail!" << endl;
					check--;
				}
			}
			else if (sOfClass[i].id == tempID && sOfClass[i].status == 0)
			{
				cout << "This student has already been removed!" << endl;
				check--;
			}
		}
		if (check == 0)
			cout << "This ID doesn't exist!" << endl;

		file.close();

		if (check > 0)
		{
			file.open(fileName, ios::out);
			file << z << "\n";
			for (int i = 0; i < z; i++)
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
			file.close();
		}
		delete[] sOfClass;
	}
}

void editStudent()
{
	int confirm;
	confirm = viewClass();
	if (confirm == -1)
		return;
	cout << "Input class of student about to edit : " << flush;
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
		}

		cout << "List of students: \n" << endl;
		for (int i = 0; i < z; i++)
		{
			cout << i + 1 << ". " << endl;
			cout << "Student ID: " << sOfClass[i].id << endl;
			cout << "Name: " << sOfClass[i].fullname << endl;
			cout << "Birthday: " << sOfClass[i].dob.day << "/" << sOfClass[i].dob.month << "/" << sOfClass[i].dob.year << endl;
			cout << "Status: " << sOfClass[i].status;
			if (sOfClass[i].status == 0)
				cout << " (Inactive)" << endl;
			else
				cout << " (Active)" << endl;
			cout << "\n";
		}

		int tempSTT;
		int check = 0;
		cout << "\nInput ordinal number of the student you want to edit: " << flush;
		cin >> tempSTT;
		system("cls");
		for (int i = 0; i < z; i++)
		{
			if (i + 1 == tempSTT)
			{
				int sure;
				cout << "1. ID: " << sOfClass[i].id << endl;
				cout << "2. Name: " << sOfClass[i].fullname << endl;
				cout << "3. Birthday: " << sOfClass[i].dob.day << "/" << sOfClass[i].dob.month << "/" << sOfClass[i].dob.year << endl;
				cout << "4. Status: " << sOfClass[i].status << endl;
				cout << "\n";
				cout << "Which data of student you want to change? (1-4): " << flush;
				int choice;
				do
				{
					cin >> choice;
				} while (choice < 1 or choice>4);

				if (choice == 1)
				{
					int editID;
					cout << "Input new ID: " << flush;
					cin >> editID;
					if (editID == sOfClass[i].id)
					{
						cout << "Old and new ID are the same!" << endl;
						check--;
						break;
					}
					sOfClass[i].id = editID;
					check++;
					cout << "Edit student successfully!" << endl;
				}
				if (choice == 2)
				{
					string editName;
					cout << "Input new name: " << flush;
					cin.ignore();
					getline(cin, editName);
					if (editName == sOfClass[i].fullname)
					{
						cout << "Old and new name are the same!" << endl;
						check--;
						break;
					}
					sOfClass[i].fullname = editName;
					check++;
					cout << "Edit student successfully!" << endl;
				}
				if (choice == 3)
				{
					cout << "Input new DOB: " << endl;

					cout << "   day: " << flush;
					int editDay;
					cin >> editDay;
					string stringeditDay;
					if (editDay < 10)
					{
						stringeditDay += '0';
					}
					stringeditDay += to_string(editDay);

					cout << "   month: " << flush;
					int editMonth;
					cin >> editMonth;
					string stringeditMonth;
					if (editMonth < 10)
					{
						stringeditMonth += '0';
					}
					stringeditMonth += to_string(editMonth);

					cout << "   year: " << flush;
					int editYear;
					cin >> editYear;
					string stringeditYear;
					if (editYear < 10)
						stringeditYear += "000";
					else if (editYear < 100)
						stringeditYear += "00";
					else if (editYear < 1000)
						stringeditYear += '0';
					stringeditYear += to_string(editYear);

					if (sOfClass[i].dob.day == stringeditDay && sOfClass[i].dob.month == stringeditMonth && sOfClass[i].dob.year == stringeditYear)
					{
						cout << "Old and new DOB are the same!" << endl;
						check--;
						break;
					}
					sOfClass[i].dob.year = stringeditYear;
					sOfClass[i].dob.month = stringeditMonth;
					sOfClass[i].dob.day = stringeditDay;
					check++;
					cout << "Edit student successfully!" << endl;
				}
				if (choice == 4)
				{
					cout << "You want to activate/deactivate this student? (1: Active, 0: Inactive): " << flush;
					int editAct;
					do
					{
						cin >> editAct;
					} while (editAct != 1 and editAct != 0);
					if (sOfClass[i].status == editAct)
					{
						cout << "Old and new status are the same!" << endl;
						check--;
						break;
					}
					sOfClass[i].status = editAct;
					check++;
					cout << "Edit student successfully!" << endl;
				}
			}
		}
		if (check == 0)
			cout << "This student is not in the list!" << endl;

		file.close();

		if (check > 0)
		{
			file.open(fileName, ios::out);
			file << z << "\n";
			for (int i = 0; i < z; i++)
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
			file.close();
		}
		delete[] sOfClass;
	}
}

int main()
{
	editStudent();
	if (_CrtDumpMemoryLeaks())
		cout << "\nMemory leak!" << endl;
	system("pause>nul");
	return 0;
}