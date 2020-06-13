#include "Header.h"
#include "HeaderStaffClass.h"

void NhapSVtuFile(Student*& a, int& n) {
	fstream file;
	file.open("Student.txt", ios::in);
	if (file.fail())
	{
		return;
	}
	else
	{
		file >> n;
		a = new Student[n];
		for (int i = 0; i < n; i++)
		{
			file >> a[i].id;
			file.ignore();
			getline(file, a[i].password);
			getline(file, a[i].fullname);
			file >> a[i].dob.year;
			file.ignore();
			file >> a[i].dob.month;
			file.ignore();
			file >> a[i].dob.day;
			file.ignore();
			getline(file, a[i].classes);
			file >> a[i].status;
			file.ignore();
			file.ignore();
		}
	}
	file.close();
}

void Doc(Student a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << endl;
		cout << "Student ID: " << a[i].id << endl;
		cout << "Password: " << a[i].password << endl;
		cout << "Name: " << a[i].fullname << endl;
		//cout << "Birthday: " << a[i].dob.day << "/" << a[i].dob.month << "/" << a[i].dob.year << endl;
		cout << "Birthday: ";
		if (a[i].dob.day < 10)
		{
			cout << "0" << a[i].dob.day << "/";
		}
		else
		{
			cout << a[i].dob.day << "/";
		}
		if (a[i].dob.month < 10)
		{
			cout << "0" << a[i].dob.month << "/";
		}
		else
		{
			cout << a[i].dob.month << "/";
		}
		cout << a[i].dob.year << endl;
		cout << "Class: " << a[i].classes << endl;
		cout << "Status: " << a[i].status;
		if (a[i].status == 0)
			cout << " (Inactive)" << endl;
		else
			cout << " (Active)" << endl;
		cout << "\n";
	}
}




void CapNhatPassSV(Student a[], int n, string newpass, int index) {
	fstream file;
	file.open("Student.txt", ios::out);
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
			file << a[i].id << endl;
			if (i == index)
			{
				file << newpass << endl;
			}
			else
			{
				file << a[i].password << endl;
			}
			file << a[i].fullname << endl;
			file << a[i].dob.year << " ";
			if (a[i].dob.month < 10)
			{
				file << "0" << a[i].dob.month << " ";
			}
			else
			{
				file << a[i].dob.month << " ";
			}
			if (a[i].dob.day < 10)
			{
				file << "0" << a[i].dob.day << endl;
			}
			else
			{
				file << a[i].dob.day << endl;
			}
			file << a[i].classes << endl;
			if (i == n - 1)
			{
				file << a[i].status;
			}
			else
			{
				file << a[i].status << endl;
				file << endl;
			}
		}
	}
	file.close();

	string fileName = "Student-" + a[index].classes + ".txt";
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

		file.close();

		file.open(fileName, ios::out);
		file << z << "\n";
		for (int i = 0; i < z; i++)
		{
			if (sOfClass[i].id == a[index].id)
			{
				sOfClass[i].password = newpass;
			}
			file << sOfClass[i].id;
			file << "\n";
			file << sOfClass[i].password;
			file << "\n";
			file << sOfClass[i].fullname << "\n";
			file << sOfClass[i].dob.year << " " << sOfClass[i].dob.month << " " << sOfClass[i].dob.day << "\n";
			file << a[index].classes << "\n";
			file << sOfClass[i].status;
			file << "\n\n";
		}
		file.close();
		delete[] sOfClass;
	}
}

string ChangePassword(string oldpass) {
	string pass; string pass1, pass2;

	cout << "-------------------CHANGE PASSWORD--------------------\n";
	do
	{
		cout << "Enter your current password: "; cin >> pass;
		cout << endl;
		if (pass.compare(oldpass) != 0)
		{
			cout << "Wrong password!! Please retry!!" << endl;
		}
	} while (pass.compare(oldpass) != 0);

	cout << "Enter new password: "; cin >> pass1;
	cout << "Enter new password again: "; cin >> pass2;
	if (pass1.compare(pass2) != 0)
	{
		system("cls");
		cout << "Fail to change your password, please retry!!!" << endl;
		ChangePassword(oldpass);
	}
	else
	{
		return pass2;
	}

}

void StudentProfile(Student a[], int n, int i)
{
	cout << "------------ACCOUNT PROFILE-------------\n";
	cout << "Fullname: " << a[i].fullname << endl;
	cout << "Student ID: " << a[i].id << endl;
	cout << "Password: " << a[i].password << endl;
	cout << "Birthday: ";
	if (a[i].dob.day < 10)
	{
		cout << "0" << a[i].dob.day << "/";
	}
	else
	{
		cout << a[i].dob.day << "/";
	}
	if (a[i].dob.month < 10)
	{
		cout << "0" << a[i].dob.month << "/";
	}
	else
	{
		cout << a[i].dob.month << "/";
	}
	cout << a[i].dob.year << endl;
	cout << "Class: " << a[i].classes << endl;
	cout << "Status: " << a[i].status;
	if (a[i].status == 0)
		cout << " (Inactive)" << endl;
	else
		cout << " (Active)" << endl;
	cout << "\n";
}