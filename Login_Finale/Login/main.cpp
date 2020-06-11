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

void Login(Student a[], int n) {
	string id; string pass;
	
	cout << "Username: "; cin >> id;
	cout << "Password: "; cin >> pass; 
	int check = 0;
	for (int i = 0; i < n; i++)
	{
		
		if (a[i].id == stoi(id) && pass.compare(a[i].password) == 0) {
			
			check = 1;
			MenuSinhVien(a, n, i);
			break;
		}
	}
	if (check == 0)
	{
		system("cls");
		cout << "Sai ten dang nhap hoac mat khau!! Yeu cau dang Nhap lai!!" << endl;
		Login(a, n);
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
		system("cls");
		cout << "******************************************************************************" << endl;
		cout << "----------------------HEN GAP LAI, GOODBYE FOR NOW!!<3------------------------" << endl;
		cout << "******************************************************************************" << endl;
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
		SettingSV(a, n, i);
		break;
	case 7:
		ManHinhChinh(a, n);
		break;
	default:
		break;
	}
}

void SettingSV(Student a[], int n, int i) {
	int choice; string npass; char choice1;
	system("cls");
	cout << "******************************************" << endl;
	cout << "       1. Thong tin ca nhan" << endl;
	cout << "       2. Doi mat khau" << endl;
	cout << "       3. Tro ve" << endl;
	cout << "******************************************" << endl;
	do
	{
		cout << "Nhap so de chon thong tin ban muon xem/thuc hien (1-3): ";
		cin >> choice;
		if (choice < 1 || choice>3)
			cout << "So da nhap khong dung, vui long nhap lai!" << endl;
	} while (choice < 1 || choice>3);

	switch (choice)
	{
	case 1:
		system("cls");
		cout << "------------THONG TIN SINH VIEN-------------\n";
		cout << "Fullname: " << a[i].fullname << endl;
		cout << "Student ID: " << a[i].id << endl;
		cout << "Password: " << a[i].password << endl;
		cout << "Birthday: ";
		if (a[i].dob.day < 10)
		{
			cout << "0" << a[i].dob.day <<"/";
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
		
		do
		{
			cout << "Press f to return ^^: ";cin>> choice1;
			if (choice1!='f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1!='f');
		SettingSV(a, n, i);
		break;
	case 2:
		system("cls");
		npass = ChangePassword(a[i].password);
		CapNhatPassSV(a, n, npass, i);
		cout << "Mat khau duoc thay doi thang cong!!" << endl;
		cout << endl;
		
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		SettingSV(a, n, i);
		break;
	case 3:
		MenuSinhVien(a, n, i);
		break;
	default:
		break;
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
		file << n <<endl;
		//a = new Student[n];
		for (int i = 0; i < n; i++)
		{
			file << a[i].id<<endl;
			if (i == index)
			{
				file << newpass << endl;
			}
			else
			{
				file << a[i].password << endl;
			}
			file << a[i].fullname<<endl;
			file << a[i].dob.year << " ";
			if (a[i].dob.month<10)
			{
				file << "0" << a[i].dob.month << " ";
			}
			else
			{
				file << a[i].dob.month << " ";
			}
			if (a[i].dob.day<10)
			{
				file << "0" << a[i].dob.day << endl;
			}
			else
			{
				file << a[i].dob.day << endl;
			}
			file << a[i].classes << endl;
			if (i == n-1)
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
}

string ChangePassword(string oldpass) {
	string pass; string pass1,pass2;
	
	cout << "-------------------DOI MAT KHAU--------------------\n";
	do
	{
		cout << "Nhap mat khau hien tai: "; cin >> pass;
		cout << endl;
		if (pass.compare(oldpass) != 0)
		{
			cout << "Sai mat khau!! Vui long nhap lai!!" << endl;
		}
	} while (pass.compare(oldpass)!=0);
	/*do
	{
		cout << "Nhap mat khau moi: "; cin >> pass1;
		cout << "Nhap lai mat khau moi vua nhap: "; cin >> pass2;
		cout << endl;
		if (pass1.compare(pass2) != 0)
		{
			cout << "Thay doi mat khau that bai!! Vui long nhap lai mat khau moi!!" << endl;
		}
	} while (pass1.compare(pass2) != 0);*/
	cout << "Nhap mat khau moi: "; cin >> pass1;
	cout << "Nhap lai mat khau moi vua nhap: "; cin >> pass2;
	if (pass1.compare(pass2) != 0)
	{
		system("cls");
		cout << "Thay doi mat khau that bai!! Vui long nhap lai tu dau!!" << endl;
		ChangePassword(oldpass);
	}
	else
	{
		return pass2;
	}
	
}

int main() {
	Student* a = NULL; int n;
	

	/*cin >> str;
	cout << str;*/
	NhapSVtuFile(a, n); 
	//Doc(a, n);
	//Login(a, n, s, s2);
	ManHinhChinh(a, n);
	//string test;
	//GhiFile(a, n, test);
	delete[] a;
	return 0;
}