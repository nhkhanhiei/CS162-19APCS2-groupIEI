#include "Header.h"

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
	file.open("Staff1.txt", ios::out);
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