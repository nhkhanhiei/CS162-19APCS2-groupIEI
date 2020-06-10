#include "Header.h"

//void MainUI(SinhVien a);

void NhapSVtuFile(Student *&a, int& n){
	fstream file;
	file.open("Student.txt", ios::in);
	if (file.fail())
	{
		cout << "Unable to read Student file!" << endl;
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
		cout << "Birthday: " << a[i].dob.day << "/" << a[i].dob.month << "/" << a[i].dob.year << endl;
		cout << "Class: " << a[i].classes << endl;
		cout << "Status: " << a[i].status;
		if (a[i].status == 0)
			cout << " (Inactive)" << endl;
		else
			cout << " (Active)" << endl;
		cout << "\n";
	}
}

void Login(Student a[], int n) {
	string id; string pass;
	
	cout << "Username: "; cin >> id;
	cout << "Password: "; cin >> pass;
	
	for (int i = 0; i < n; i++)
	{
		int check = 0;
		if (a[i].id == stoi(id) && pass.compare(a[i].password) == 0) {
			/*cout << i + 1 << ". " << endl;
			cout << "Student ID: " << a[i].id << endl;
			cout << "Password: " << a[i].password << endl;
			cout << "Name: " << a[i].fullname << endl;
			cout << "Birthday: " << a[i].dob.day << "/" << a[i].dob.month << "/" << a[i].dob.year << endl;
			cout << "Class: " << a[i].classes << endl;
			cout << "Status: " << a[i].status;
			if (a[i].status == 0)
				cout << " (Inactive)" << endl;
			else
				cout << " (Active)" << endl;
			cout << "\n";*/
			check = 1;
			MenuSinhVien(a, n, i);
			return;
		}
		else {
			system("cls");
			cout << "Sai ten dang nhap hoac mat khau!! Yeu cau dang Nhap lai!!" << endl;
			Login(a, n);
			break;
		}
	}
}

void ManHinhChinh(Student a[], int n)
{
	int choice;
	system("cls");
	cout << "---------------------APCS_MOODLE-------------------------\n";
	cout << "1. Dang nhap" << endl;
	cout << "2. Thoat" << endl;
	do
	{
		cout << "Nhap so de chon thong tin ban muon xem/thuc hien (1-2): ";
		cin >> choice;
		if (choice < 1 || choice>2)
			cout << "So da nhap khong dung, vui long nhap lai!" << endl;
	} while (choice < 1 || choice>2);

	switch (choice)
	{
	case 1:
		system("cls");
		Login(a, n);
		break;
	case 2:
		cout << "Hen gap lai!!" << endl;
		exit;
	}

}
void MenuSinhVien(Student a[], int n, int i) {
	int choice;
	system("cls");
	cout << "******************************************" << endl;
	cout << "     Xin Chao " << a[i].fullname << endl;
	cout << "       1. Diem danh" << endl;
	cout << "       2. Kiem tra ket qua diem danh" << endl;
	cout << "       3. Lich hoc" << endl;
	cout << "       5. Kiem tra diem cua mon hoc" << endl;
	cout << "       6. Cai dat" << endl;
	cout << "       7. Dang xuat" << endl;
	cout << "******************************************" << endl;
	do
	{
		cout << "Nhap so de chon thong tin ban muon xem/thuc hien (1-7): ";
		cin >> choice;
		if (choice < 1 || choice>7)
			cout << "So da nhap khong dung, vui long nhap lai!" << endl;
	} while (choice < 1 || choice>7);
	switch (choice)
	{
	case 6:
	case 7:
		ManHinhChinh(a, n);
		break;
	default:
		break;
	}
}

void SettingSV(Student a[], int n, int i) {
	system("cls");
	cout << "******************************************" << endl;
	cout << "       1. Thong tin ca nhan" << endl;
	cout << "       2. Doi mat khau" << endl;
	cout << "       3. Tro ve" << endl;
	cout << "******************************************" << endl;
}



int main() {
	Student* a = NULL; int n;
	NhapSVtuFile(a, n); 
	//Doc(a, n);
	//Login(a, n, s, s2);
	ManHinhChinh(a, n);
	delete[] a;
	return 0;
}