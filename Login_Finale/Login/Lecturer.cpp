#include "Header.h"

void NhapLecturertuFile(Lecturer*& c, int& n2) {
	fstream file;
	file.open("Lecturer.txt", ios::in);
	if (file.fail())
	{
		return;
	}
	else
	{
		file >> n2;
		file.ignore();
		c = new Lecturer[n2];
		for (int i = 0; i < n2; i++)
		{
			getline(file, c[i].username);
			getline(file, c[i].password);
			getline(file, c[i].Fullname);
			getline(file, c[i].Occupation);
			file >> c[i].gender;
			file.ignore();
			file.ignore();
		}
	}
	file.close();
}

void DocLecturer(Lecturer c[], int n2) {
	for (int i = 0; i < n2; i++)
	{
		cout << i + 1 << ". " << endl;
		cout << "Username: " << c[i].username << endl;
		cout << "Password: " << c[i].password << endl;
		cout << "Fullname: " << c[i].Fullname << endl;
		cout << "Occupation: " << c[i].Occupation << endl;
		cout << "Gender: ";
		if (c[i].gender == 1)
		{
			cout << "Female" << endl;
		}
		else
		{
			cout << "Male" << endl;
		}
		cout << "\n";
	}
}

void LecturerProfile(Lecturer c[], int n2, int i) {
	cout << "------------ACCOUNT PROFILE-------------\n";
	cout << "Username: " << c[i].username << endl;
	cout << "Password: " << c[i].password << endl;
	cout << "Fullname: " << c[i].Fullname << endl;

	cout << "Gender: ";
	if (c[i].gender == 1)
	{
		cout << "Female" << endl;
	}
	else
	{
		cout << "Male" << endl;
	}
	cout << "\n";
}


void CapNhatPassLecturer(Lecturer a[], int n, string newpass, int index) {
	fstream file;
	file.open("Lecturer.txt", ios::out);
	if (file.fail())
	{
		cout << "Unable to create Student file!" << endl;
	}
	else
	{
		file << n << endl;
		
		for (int i = 0; i < n; i++)
		{
			file << a[i].username << endl;
			if (i == index)
			{
				file << newpass << endl;
			}
			else
			{
				file << a[i].password << endl;
			}
			file << a[i].Fullname << endl;
			file << a[i].Occupation << endl;
			if (i == n - 1)
			{
				file << a[i].gender;
			}
			else
			{
				file << a[i].gender << endl;
				file << endl;
			}
		}
	}
	file.close();
}