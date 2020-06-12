#include "Header.h"
#include "HeaderStaffClass.h"

void NhapStafftuFile(Staff*& a, int& n) {
	fstream file;
	file.open("Staff.txt", ios::in);
	if (file.fail())
	{
		cout << "Unable to read Staff file!" << endl;
	}
	else
	{
		file >> n;
		file.ignore();
		a = new Staff[n];
		for (int i = 0; i < n; i++)
		{
			getline(file,a[i].username);
			getline(file, a[i].pass);
			getline(file, a[i].fullname);
			file >> a[i].gend;
			file.ignore();
			file.ignore();
		}
	}
	file.close();
}

void DocStaff(Staff a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << endl;
		cout << "Username: " << a[i].username << endl;
		cout << "Password: " << a[i].pass << endl;
		cout << "Fullname: " << a[i].fullname << endl;
		
		cout << "Gender: ";
		if (a[i].gend == 1)
		{
			cout << "Female" << endl;
		}
		else
		{
			cout << "Male" <<endl;
		}
		cout << "\n";
	}
}

void StaffProfile(Staff b[], int n1, int i) {
	cout << "------------ACCOUNT PROFILE-------------\n";
	cout << "Username: " << b[i].username << endl;
	cout << "Password: " << b[i].pass << endl;
	cout << "Fullname: " << b[i].fullname << endl;

	cout << "Gender: ";
	if (b[i].gend == 1)
	{
		cout << "Female" << endl;
	}
	else
	{
		cout << "Male" << endl;
	}
	cout << "\n";
}


void CapNhatPassStaff(Staff a[], int n, string newpass, int index) {
	fstream file;
	file.open("Staff.txt", ios::out);
	if (file.fail())
	{
		cout << "Unable to create Student file!" << endl;
	}
	else
	{
		file << n << endl;
		//a = new Student[n];
		for (int i = 0; i < n; i++)
		{
			file << a[i].username << endl;
			if (i == index)
			{
				file << newpass << endl;
			}
			else
			{
				file << a[i].pass << endl;
			}
			file << a[i].fullname << endl;
			if (i == n - 1)
			{
				file << a[i].gend;
			}
			else
			{
				file << a[i].gend << endl;
				file << endl;
			}
		}
	}
	file.close();
}



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

		StudentClass* sOfClass;
		sOfClass = new StudentClass[z];

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

		StudentClass* sOfClass;
		sOfClass = new StudentClass[z + 1];

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
		file.close();

		fstream file1;
		file1.open("Student.txt", ios::in);
		if (file1.fail())
		{
			cout << "Unable to read Student file!" << endl;
		}
		else
		{
			int x;
			file1 >> x;
			Student* a;
			a = new Student[x + 1];
			for (int i = 0; i < x + 1; i++)
			{
				file1 >> a[i].id;
				file1.ignore();
				getline(file1, a[i].password);
				getline(file1, a[i].fullname);
				file1 >> a[i].dob.year;
				file1.ignore();
				file1 >> a[i].dob.month;
				file1.ignore();
				file1 >> a[i].dob.day;
				file1.ignore();
				getline(file1, a[i].classes);
				file1 >> a[i].status;
				file1.ignore();
				file1.ignore();
			}
			file1.close();

			a[x].id = sOfClass[z].id;
			a[x].password = sOfClass[z].password;
			a[x].dob.day = stoi(sOfClass[z].dob.day);
			a[x].dob.month = stoi(sOfClass[z].dob.month);
			a[x].dob.year = stoi(sOfClass[z].dob.year);
			a[x].classes = cl;
			a[x].fullname = sOfClass[z].fullname;
			a[x].status = sOfClass[z].status;

			file1.open("Student.txt", ios::out);
			if (file1.fail())
			{
				cout << "Unable to create Student file!" << endl;
			}
			else
			{
				file1 << x+1 << endl;
				//a = new Student[n];
				for (int i = 0; i < x+1; i++)
				{
					file1 << a[i].id << endl;
					file1 << a[i].password << endl;
					file1 << a[i].fullname << endl;
					file1 << a[i].dob.year << " ";
					if (a[i].dob.month < 10)
					{
						file1 << "0" << a[i].dob.month << " ";
					}
					else
					{
						file1 << a[i].dob.month << " ";
					}
					if (a[i].dob.day < 10)
					{
						file1 << "0" << a[i].dob.day << endl;
					}
					else
					{
						file1 << a[i].dob.day << endl;
					}
					file1 << a[i].classes << endl;
					if (i == x)
					{
						file1 << a[i].status;
					}
					else
					{
						file1 << a[i].status << endl;
						file1 << endl;
					}
				}
			}
			file1.close();
			delete[] a;
		}
		delete[] sOfClass;
		
	}
}

void removeStudent()
{
	int confirm;
	confirm = viewClass();
	if (confirm == -1)
		return;
	cout << "\nInput class of student about to remove : " << flush;
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

		StudentClass* sOfClass;
		sOfClass = new StudentClass[z];

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
					cout << "\nRemove student successfully!" << endl;
					
				}
				else
				{
					cout << "\nRemove student fail!" << endl;
					check--;
				}
			}
			else if (sOfClass[i].id == tempID && sOfClass[i].status == 0)
			{
				cout << "This student is currently inactive, cannot be removed!" << endl;
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
			fstream file1;
			file1.open("Student.txt", ios::in);
			if (file1.fail())
			{
				cout << "Unable to read Student file!" << endl;
			}
			else
			{
				int x;
				file1 >> x;
				Student* a;
				a = new Student[x];
				for (int i = 0; i < x; i++)
				{
					file1 >> a[i].id;
					file1.ignore();
					getline(file1, a[i].password);
					getline(file1, a[i].fullname);
					file1 >> a[i].dob.year;
					file1.ignore();
					file1 >> a[i].dob.month;
					file1.ignore();
					file1 >> a[i].dob.day;
					file1.ignore();
					getline(file1, a[i].classes);
					file1 >> a[i].status;
					file1.ignore();
					file1.ignore();
				}
				file1.close();


				file1.open("Student.txt", ios::out);
				if (file1.fail())
				{
					cout << "Unable to create Student file!" << endl;
				}
				else
				{
					file1 << x << endl;
					//a = new Student[n];
					for (int i = 0; i < x; i++)
					{
						if (a[i].id == tempID)
						{
							a[i].status = 0;
						}
						file1 << a[i].id << endl;
						file1 << a[i].password << endl;
						file1 << a[i].fullname << endl;
						file1 << a[i].dob.year << " ";
						if (a[i].dob.month < 10)
						{
							file1 << "0" << a[i].dob.month << " ";
						}
						else
						{
							file1 << a[i].dob.month << " ";
						}
						if (a[i].dob.day < 10)
						{
							file1 << "0" << a[i].dob.day << endl;
						}
						else
						{
							file1 << a[i].dob.day << endl;
						}
						file1 << a[i].classes << endl;
						if (i == x-1)
						{
							file1 << a[i].status;
						}
						else
						{
							file1 << a[i].status << endl;
							file1 << endl;
						}
					}
				}
				file1.close();
				delete[] a;
			}
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
	cout << "\nInput class of student about to edit : " << flush;
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

		StudentClass* sOfClass;
		sOfClass = new StudentClass[z];

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

		int x;
		fstream file1; Student* a=NULL;
		file1.open("Student.txt", ios::in);
		if (file1.fail())
		{
			cout << "Unable to read Student file!" << endl;
		}
		else
		{
			
			file1 >> x;
			a = new Student[x];
			for (int i = 0; i < x; i++)
			{
				file1 >> a[i].id;
				file1.ignore();
				getline(file1, a[i].password);
				getline(file1, a[i].fullname);
				file1 >> a[i].dob.year;
				file1.ignore();
				file1 >> a[i].dob.month;
				file1.ignore();
				file1 >> a[i].dob.day;
				file1.ignore();
				getline(file1, a[i].classes);
				file1 >> a[i].status;
				file1.ignore();
				file1.ignore();
			}
			file1.close();
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
					cout << "\nInput new ID: " << flush;
					cin >> editID;
					if (editID == sOfClass[i].id)
					{
						cout << "\nOld and new ID are the same!" << endl;
						check--;
						break;
					}
					for (int j = 0; j < x; j++)
					{
						if (a[j].id == sOfClass[i].id)
						{
							a[j].id = editID;
							break;
						}
					}
					sOfClass[i].id = editID;
					check++;
					cout << "\nEdit student successfully!" << endl;
				}
				if (choice == 2)
				{
					string editName;
					cout << "\nInput new name: " << flush;
					cin.ignore();
					getline(cin, editName);
					if (editName == sOfClass[i].fullname)
					{
						cout << "\nOld and new name are the same!" << endl;
						check--;
						break;
					}
					for (int j = 0; j < x; j++)
					{
						if (a[j].id == sOfClass[i].id)
						{
							a[j].fullname = editName;
							break;
						}
					}
					sOfClass[i].fullname = editName;
					check++;
					cout << "\nEdit student successfully!" << endl;
				}
				if (choice == 3)
				{
					cout << "\nInput new DOB: " << endl;

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
						cout << "\nOld and new DOB are the same!" << endl;
						check--;
						break;
					}
					for (int j = 0; j < x; j++)
					{
						if (a[j].id == sOfClass[i].id)
						{
							a[j].dob.day = stoi(stringeditDay);
							a[j].dob.month = stoi(stringeditMonth);
							a[j].dob.year = stoi(stringeditYear);
							break;
						}
					}
					sOfClass[i].dob.year = stringeditYear;
					sOfClass[i].dob.month = stringeditMonth;
					sOfClass[i].dob.day = stringeditDay;
					check++;
					cout << "\nEdit student successfully!" << endl;
				}
				if (choice == 4)
				{
					cout << "\nYou want to activate/deactivate this student? (1: Active, 0: Inactive): " << flush;
					int editAct;
					do
					{
						cin >> editAct;
					} while (editAct != 1 and editAct != 0);
					if (sOfClass[i].status == editAct)
					{
						cout << "\nOld and new status are the same!" << endl;
						check--;
						break;
					}
					for (int j = 0; j < x; j++)
					{
						if (a[j].id == sOfClass[i].id)
						{
							a[j].status = editAct;
							break;
						}
					}
					sOfClass[i].status = editAct;
					check++;
					cout << "\nEdit student successfully!" << endl;
				}
				
			}
		}
		if (check == 0)
			cout << "\nThis student is not in the list!" << endl;

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

			file1.open("Student.txt", ios::out);
			if (file1.fail())
			{
				cout << "Unable to create Student file!" << endl;
			}
			else
			{
				file1 << x << endl;
				//a = new Student[n];
				for (int i = 0; i < x; i++)
				{
					file1 << a[i].id << endl;
					file1 << a[i].password << endl;
					file1 << a[i].fullname << endl;
					file1 << a[i].dob.year << " ";
					if (a[i].dob.month < 10)
					{
						file1 << "0" << a[i].dob.month << " ";
					}
					else
					{
						file1 << a[i].dob.month << " ";
					}
					if (a[i].dob.day < 10)
					{
						file1 << "0" << a[i].dob.day << endl;
					}
					else
					{
						file1 << a[i].dob.day << endl;
					}
					file1 << a[i].classes << endl;
					if (i == x-1)
					{
						file1 << a[i].status;
					}
					else
					{
						file1 << a[i].status << endl;
						file1 << endl;
					}
				}
			}
			file1.close();
			delete[] a;
		}
		delete[] sOfClass;
	}
}



void changeClassStudent()
{
	int confirm;
	confirm = viewClass();
	if (confirm == -1)
		return;

	cout << "\nInput class of student about to move : " << flush;
	string cl;
	cin >> cl;
	for_each(cl.begin(), cl.end(), toUpper);
	cout << "\nClass " << cl << endl;
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

		StudentClass* sOfClass;
		sOfClass = new StudentClass[z];

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
		int check = 0; string clm;
		cout << "\nInput ID of student you want to move: " << flush;
		cin >> tempID;
		cout << endl;
		for (int i = 0; i < z; i++)
		{
			if (sOfClass[i].id == tempID)
			{
				cout << "Name: " << sOfClass[i].fullname << endl;
				cout << "Birthday: " << sOfClass[i].dob.day << "/" << sOfClass[i].dob.month << "/" << sOfClass[i].dob.year << endl;
				cout << "Status: " << sOfClass[i].status << endl;
				cout << "\n";
				cout << "Which class you want to move this student to?: " << flush;
				
				cin >> clm;
				for_each(clm.begin(), clm.end(), toUpper);

				if (clm == cl)
				{
					cout << "\nThis is the current class of this student!" << endl;
					check--;
				}
				else if (clm != cl)
				{
					fstream file2;
					string fileName2 = "Student-" + clm + ".txt";
					file2.open(fileName2, ios::in);

					if (file2.fail())
					{
						cout << "Unable to read Student file!" << endl;
						check--;
						file2.close();
					}
					else
					{
						int z2;
						file2 >> z2;
						int y = z2 + 1;
						int tempDay2 = 0;
						int tempMonth2 = 0;
						int tempYear2 = 0;
						string temp2;

						StudentClass* sOfClass2;
						sOfClass2 = new StudentClass[y];

						for (int i = 0; i < z2; i++)
						{
							temp2 = "";
							file2 >> sOfClass2[i].id;
							file2.ignore();
							getline(file2, sOfClass2[i].password);
							getline(file2, sOfClass2[i].fullname);
							file2 >> tempYear2 >> tempMonth2 >> tempDay2;
							file2.ignore();
							if (tempDay2 < 10)
							{
								sOfClass2[i].dob.day += '0';
							}
							sOfClass2[i].dob.day += to_string(tempDay2);

							if (tempMonth2 < 10)
							{
								sOfClass2[i].dob.month += '0';
							}
							sOfClass2[i].dob.month += to_string(tempMonth2);

							if (tempYear2 < 10)
								sOfClass2[i].dob.year += "000";
							else if (tempYear2 < 100)
								sOfClass2[i].dob.year += "00";
							else if (tempYear2 < 1000)
								sOfClass[i].dob.year += '0';
							sOfClass2[i].dob.year += to_string(tempYear2);

							getline(file2, temp2);
							file2 >> sOfClass2[i].status;
							file2.ignore();
						}

						file2.close();

						sOfClass2[z2].id = sOfClass[i].id;
						sOfClass2[z2].fullname = sOfClass[i].fullname;
						sOfClass2[z2].password = sOfClass[i].password;
						sOfClass2[z2].dob = sOfClass[i].dob;
						sOfClass2[z2].status = sOfClass[i].status;

						file2.open(fileName2, ios::out);
						file2 << z2 + 1 << "\n";
						for (int i = 0; i < z2 + 1; i++)
						{
							file2 << sOfClass2[i].id;
							file2 << "\n";
							file2 << sOfClass2[i].password;
							file2 << "\n";
							file2 << sOfClass2[i].fullname << "\n";
							file2 << sOfClass2[i].dob.year << " " << sOfClass2[i].dob.month << " " << sOfClass2[i].dob.day << "\n";
							file2 << clm << "\n";
							file2 << sOfClass2[i].status;
							file2 << "\n\n";
						}
						delete[] sOfClass2;
						file2.close();

						for (i; i < z - 1; i++)
						{
							sOfClass[i].id = sOfClass[i + 1].id;
							sOfClass[i].fullname = sOfClass[i + 1].fullname;
							sOfClass[i].password = sOfClass[i + 1].password;
							sOfClass[i].dob = sOfClass[i + 1].dob;
							sOfClass[i].status = sOfClass[i + 1].status;
						}
						check++;
					}
				}
			}
		}
		file.close();

		if (check == 0)
			cout << "\nThis ID doesn't exist!" << endl;

		if (check > 0)
		{
			file.open(fileName, ios::out);
			file << z - 1 << "\n";
			for (int i = 0; i < z - 1; i++)
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

			fstream file1;
			file1.open("Student.txt", ios::in);
			if (file1.fail())
			{
				cout << "Unable to read Student file!" << endl;
			}
			else
			{
				int x;
				file1 >> x;
				Student* a;
				a = new Student[x];
				for (int i = 0; i < x; i++)
				{
					file1 >> a[i].id;
					file1.ignore();
					getline(file1, a[i].password);
					getline(file1, a[i].fullname);
					file1 >> a[i].dob.year;
					file1.ignore();
					file1 >> a[i].dob.month;
					file1.ignore();
					file1 >> a[i].dob.day;
					file1.ignore();
					getline(file1, a[i].classes);
					file1 >> a[i].status;
					file1.ignore();
					file1.ignore();
				}
				file1.close();


				file1.open("Student.txt", ios::out);
				if (file1.fail())
				{
					cout << "Unable to create Student file!" << endl;
				}
				else
				{
					file1 << x << endl;
					//a = new Student[n];
					for (int i = 0; i < x; i++)
					{
						if (a[i].id == tempID)
						{
							a[i].classes = clm;
						}
						file1 << a[i].id << endl;
						file1 << a[i].password << endl;
						file1 << a[i].fullname << endl;
						file1 << a[i].dob.year << " ";
						if (a[i].dob.month < 10)
						{
							file1 << "0" << a[i].dob.month << " ";
						}
						else
						{
							file1 << a[i].dob.month << " ";
						}
						if (a[i].dob.day < 10)
						{
							file1 << "0" << a[i].dob.day << endl;
						}
						else
						{
							file1 << a[i].dob.day << endl;
						}
						file1 << a[i].classes << endl;
						if (i == x-1)
						{
							file1 << a[i].status;
						}
						else
						{
							file1 << a[i].status << endl;
							file1 << endl;
						}
					}
				}
				file1.close();
				delete[] a;
			}
			cout << "\nMove student successfully!" << endl;
		}
		delete[] sOfClass;
		file.close();
	}
}

void importClass()
{
	int confirm;
	confirm = viewClass();
	if (confirm == -1)
		return;

	cout << "\nInput class to import from file CSV : " << flush;
	string cl;
	cin >> cl;
	for_each(cl.begin(), cl.end(), toUpper);
	string fileName;
	fileName = cl + "-Student.csv";
	fstream fin;
	fin.open(fileName, ios::in);
	if (fin.fail())
	{
		cout << "Unable to open CSV file!" << endl;
		fin.close();
	}
	else
	{
		string Temp;
		int i = 0;
		while (!fin.eof())
		{
			getline(fin, Temp);
			i++;
		}
		fin.close();

		string* row;
		row = new string[i - 1];

		fstream fin2;
		fin2.open(fileName, ios::in);

		string line, word, temp;
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


		fstream file;
		string fileName = "Student-" + cl + ".txt";
		string fileElement = fileName;
		file.open(fileName, ios::out);

		int w = 0;
		file << i - 1 << "\n";
		for (int j = 0; j < i - 1; j++)
		{
			istringstream iss(row[j]);
			string token[4];
			int k = 0;
			while (getline(iss, token[k], ','))
			{
				k++;
			}
			string tempPW = "";
			for (int i = 0; i < token[2].length(); i++)
			{
				if (token[2][i] == '-')
					continue;

				tempPW += token[2][i];
			}

			string tempDoB = "";
			for (int i = 0; i < token[2].length(); i++)
			{
				if (token[2][i] == '-')
					token[2][i] = ' ';

				tempDoB += token[2][i];
			}

			file << token[0] << endl;
			file << tempPW << endl;
			file << token[1] << endl;
			file << tempDoB << endl;
			file << token[3] << endl;
			file << 1 << endl;
			file << "\n";
			w++;

		}
		delete[] row;
		fin2.close();

		cout << "\nImport students done!" << endl;
		cout << "Success: " << w << endl;
		cout << "Fail: " << i - 1 - w << endl;


		fstream readFileTotal;
		readFileTotal.open("Student.txt", ios::in);

		if (readFileTotal.fail())
		{
			readFileTotal.close();

			fstream readFileelement;
			readFileelement.open(fileElement, ios::in);

			StudentClass* sOfClass;
			sOfClass = new StudentClass[w];

			int count = 0;
			int tempDay = 0;
			int tempMonth = 0;
			int tempYear = 0;
			string temp;

			for (int i = 0; i < w; i++)
			{
				getline(readFileelement, temp);
				temp = "";
				readFileelement >> sOfClass[i].id;
				readFileelement.ignore();
				getline(readFileelement, sOfClass[i].password);
				getline(readFileelement, sOfClass[i].fullname);
				readFileelement >> tempYear >> tempMonth >> tempDay;
				readFileelement.ignore();
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

				getline(readFileelement, temp);
				readFileelement >> sOfClass[i].status;
				readFileelement.ignore();
				if (sOfClass[i].status == 1)
					count += 1;
			}
			readFileelement.close();

			fstream openFileTotal;
			openFileTotal.open("Student.txt", ios::out);

			openFileTotal << w << "\n";
			for (int i = 0; i < w; i++)
			{
				openFileTotal << sOfClass[i].id;
				openFileTotal << "\n";
				openFileTotal << sOfClass[i].password;
				openFileTotal << "\n";
				openFileTotal << sOfClass[i].fullname << "\n";
				openFileTotal << sOfClass[i].dob.year << " " << sOfClass[i].dob.month << " " << sOfClass[i].dob.day << "\n";
				openFileTotal << cl << "\n";
				openFileTotal << sOfClass[i].status;
				openFileTotal << "\n\n";
			}
			delete[] sOfClass;
			openFileTotal.close();
		}
		else
		{
			int z;
			readFileTotal >> z;

			int count = 0;
			int tempDay = 0;
			int tempMonth = 0;
			int tempYear = 0;
			string temp;

			StudentClass* sOfClass;
			sOfClass = new StudentClass[z + w];

			for (int i = 0; i < z; i++)
			{
				temp = "";
				readFileTotal >> sOfClass[i].id;
				readFileTotal.ignore();
				getline(readFileTotal, sOfClass[i].password);
				getline(readFileTotal, sOfClass[i].fullname);
				readFileTotal >> tempYear >> tempMonth >> tempDay;
				readFileTotal.ignore();
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

				getline(readFileTotal, temp);
				readFileTotal >> sOfClass[i].status;
				readFileTotal.ignore();
				if (sOfClass[i].status == 1)
					count += 1;
			}
			readFileTotal.close();

			fstream readFileelement;
			readFileelement.open(fileElement, ios::in);

			count = 0;
			tempDay = 0;
			tempMonth = 0;
			tempYear = 0;
			temp = "";

			for (int i = z; i < z + w; i++)
			{
				getline(readFileelement, temp);
				temp = "";
				readFileelement >> sOfClass[i].id;
				readFileelement.ignore();
				getline(readFileelement, sOfClass[i].password);
				getline(readFileelement, sOfClass[i].fullname);
				readFileelement >> tempYear >> tempMonth >> tempDay;
				readFileelement.ignore();
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

				getline(readFileelement, temp);
				readFileelement >> sOfClass[i].status;
				readFileelement.ignore();
				if (sOfClass[i].status == 1)
					count += 1;
			}
			readFileelement.close();

			fstream openFileTotal;
			openFileTotal.open("Student.txt", ios::out);

			openFileTotal << z + w << "\n";
			for (int i = 0; i < z + w; i++)
			{
				openFileTotal << sOfClass[i].id;
				openFileTotal << "\n";
				openFileTotal << sOfClass[i].password;
				openFileTotal << "\n";
				openFileTotal << sOfClass[i].fullname << "\n";
				openFileTotal << sOfClass[i].dob.year << " " << sOfClass[i].dob.month << " " << sOfClass[i].dob.day << "\n";
				openFileTotal << cl << "\n";
				openFileTotal << sOfClass[i].status;
				openFileTotal << "\n\n";
			}
			delete[] sOfClass;
			openFileTotal.close();
		}
	}
}
