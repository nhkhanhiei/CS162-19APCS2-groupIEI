#include "Header.h"
#include "HeaderStaffClass.h"
#include "AcademicCourses.h"
void ManHinhChinh(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2)
{
	int choice;
	system("cls");
	cout << "---------------------APCS_MOODLE-------------------------\n";
	cout << "1. Login" << endl;
	cout << "2. Exit" << endl;
	do
	{
		cout << "Enter your choice (1-2): ";
		cin >> choice;
		if (choice < 1 || choice>2)
			cout << "Wrong choice! Please retry" << endl;
	} while (choice < 1 || choice>2);

	switch (choice)
	{
	case 1:
		system("cls");
		Login(a, n, b,n1,c,n2);
		break;
	case 2:
		system("cls");
		cout << "******************************************************************************" << endl;
		cout << "----------------------HEN GAP LAI, GOODBYE FOR NOW!!<3------------------------" << endl;
		cout << "******************************************************************************" << endl;
		exit;
	}

}

void Login(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2) 
{
	string id; string pass;
	
	cout << "Username: "; cin >> id;
	cout << "Password: "; cin>> pass;
	int check = 0;
	if (isdigit(id[0]))
	{
		for (int i = 0; i < n; i++)
		{

			if (a[i].id == stoi(id) && pass.compare(a[i].password) == 0) {

				check = 1;
				MenuSinhVien(a, n, b, n1, c, n2, i);
				return;
			}
		}
	}
	else
	{
		for (int i = 0; i < n1; i++)
		{
			//id.compare(b[i].username) == 0 && pass.compare(b[i].pass) == 0
			if (id == b[i].username && pass == b[i].pass) {

				check = 1;
				MenuStaff(a, n, b, n1, c, n2, i);
				return;
			}
		}
		for (int j = 0; j < n2; j++)
		{
			if (id.compare(c[j].username) == 0 && pass.compare(c[j].password)==0)
			{
				check = 1;
				MenuLecturer(a, n, b, n1, c, n2, j);
				return;
			}
		}
	}
	
	if (check == 0)
	{
		system("cls");
		cout << "Your username or password is invalid, please retry!!" << endl;
		Login(a, n, b, n1, c, n2);
	}

}



void MenuSinhVien(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i)
{
	int choice;
	system("cls");
	cout << "******************************************" << endl;
	cout << "    Hello " << a[i].fullname << endl;
	cout << "       1. Check-in" << endl;
	cout << "       2. Attendance result" << endl;
	cout << "       3. Schedule" << endl;
	cout << "       5. Grades" << endl;
	cout << "       6. Setting" << endl;
	cout << "       7. Sign out" << endl;
	cout << "******************************************" << endl;
	do
	{
		cout << "Enter your choice (1-7): ";
		cin >> choice;
		if (choice < 1 || choice>7)
			cout << "Wrong choice! Please retry" << endl;
	} while (choice < 1 || choice>7);
	switch (choice)
	{
	case 6:
		SettingSV(a, n, b, n1, c, n2,i);
		break;
	case 7:
		ManHinhChinh(a, n, b, n1, c, n2);
		break;
	default:
		break;
	}
}

void MenuStaff(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i )
{
	int choice;
	system("cls");
	cout << "******************************************" << endl;
	cout << "    Hello " << b[i].fullname << endl;
	cout << "       1. Class" << endl;
	cout << "       2. Course" << endl;
	cout << "       3. Scoreboard" << endl;
	cout << "       5. Attendance list" << endl;
	cout << "       6. Setting" << endl;
	cout << "       7. Sign out" << endl;
	cout << "******************************************" << endl;
	do
	{
		cout << "Enter your choice (1-7): ";
		cin >> choice;
		if (choice < 1 || choice>7)
			cout << "Wrong choice! Please retry" << endl;
	} while (choice < 1 || choice>7);
	switch (choice)
	{
	case 1:
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;
	case 2:
		MenuStaffCourses(a, n, b, n1, c, n2, i);
	case 6:
		SettingStaff(a, n, b, n1, c, n2, i);
		break;
	case 7:
		ManHinhChinh(a, n, b, n1,c,n2);
		break;
	default:
		break;
	}
}

void MenuStaffClass(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i)
{
	int choice; char choice1;
	system("cls");
	cout << "******************************************" << endl;
	cout << "-------------------Class------------------" << endl;
	cout << "       1. Import Students of a class" << endl;
	cout << "       2. Add new Student" << endl;
	cout << "       3. Edit a Student" << endl;
	cout << "       4. Remove a Student" << endl;
	cout << "       5. Exchange Student between two classes" << endl;
	cout << "       6. View list of classes" << endl;
	cout << "       7. View list of Students in a class" << endl;
	cout << "       8. Return" << endl;
	cout << "******************************************" << endl;
	do
	{
		cout << "Enter your choice (1-8): ";
		cin >> choice;
		if (choice < 1 || choice>8)
			cout << "Wrong choice! Please retry" << endl;
	} while (choice < 1 || choice>8);

	switch (choice)
	{
	case 1:
		system("cls");
		cout << "Note: Enter whole name of the class. Example: 19APCS1, 19apcs2,.." << endl;
		importClass();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;
	case 2:
		system("cls");
		cout << "Note: Enter whole name of the class. Example: 19APCS1, 19apcs2,.." << endl;
		addStudent();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;
	case 3:
		system("cls");
		cout << "Note: Enter whole name of the class. Example: 19APCS1, 19apcs2,.." << endl;
		editStudent();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;
	case 4:
		system("cls");
		cout << "Note: Enter whole name of the class. Example: 19APCS1, 19apcs2,.." << endl;
		removeStudent();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;
	case 5:
		system("cls");
		cout << "Note: Enter whole name of the class. Example: 19APCS1, 19apcs2,.." << endl;
		changeClassStudent();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;
	case 6:
		system("cls");
		viewClass();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;
	case 7:
		system("cls");
		cout << "Note: Enter whole name of the class. Example: 19APCS1, 19apcs2,.." << endl;
		viewStudent();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;
		
	case 8:
		MenuStaff(a, n, b, n1, c, n2,i);
		break;
	default:
		break;
	}
}

void MenuStaffCourses(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i)
{
	int choice; char choice1;
	system("cls");
	cout << "******************************************" << endl;
	cout << "-------------------Courses------------------" << endl;
	cout << "       1. Create/update/delete/view academic years and semester" << endl;
	cout << "       2. Import Courses from CSV file" << endl;
	cout << "       3. Add new course" << endl;
	cout << "       4. Edit a course" << endl;
	cout << "       5. Remove a course" << endl;
	cout << "       6. Remove student from a course" << endl;
	cout << "       7. Add a specific student to a course" << endl;
	cout << "       8. View list of course in current semester" << endl;
	cout << "       9. View list of student of a course" << endl;
	cout << "       10. View attendance list of a course" << endl;
	cout << "       11. Create / update / delete / view all lecturers" << endl;
	cout << "       12. Return" << endl;

	cout << "******************************************" << endl;
	do
	{
		cout << "Enter your choice (1-8): ";
		cin >> choice;
		if (choice < 1 || choice>8)
			cout << "Wrong choice! Please retry" << endl;
	} while (choice < 1 || choice>8);

	switch (choice)
	{
	case 1:
		system("cls");
		MenuStaffCoursesYearsSemesters(a, n, b, n1, c, n2, i);
		break;
	case 2:
		system("cls");
		cin.ignore();
		ImportAndCreateFile();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;
	case 3:
		system("cls");
		cin.ignore();
		AddNewCourse();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;
	case 4:
		system("cls");
		cin.ignore();
		EditCourse();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;
	case 5:
		system("cls");
		cin.ignore();
		RemoveCourse();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;
	case 6:
		system("cls");
		viewClass();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;
	case 7:
		system("cls");
		cout << "Note: Enter whole name of the class. Example: 19APCS1, 19apcs2,.." << endl;
		viewStudent();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffClass(a, n, b, n1, c, n2, i);
		break;

	case 8:
		MenuStaff(a, n, b, n1, c, n2, i);
		break;
	default:
		break;
	}
}

void MenuStaffCoursesYearsSemesters(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i)
{
	int choice; char choice1;
	system("cls");
	cout << "******************************************" << endl;
	cout << "-------------------Years and Semesters------------------" << endl;
	cout << "       1. Create academic years and semester" << endl;
	cout << "       2. Update academic years and semester" << endl;
	cout << "       3. Delete academic years and semester" << endl;
	cout << "       4. View academic years and semester" << endl;
	cout << "******************************************" << endl;
	do
	{
		cout << "Enter your choice (1-4): ";
		cin >> choice;
		if (choice < 1 || choice > 4)
			cout << "Wrong choice! Please retry" << endl;
	} while (choice < 1 || choice > 4);

	switch (choice)
	{
	case 1:
		system("cls");
		cin.ignore();
		CreateYandS();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffCourses(a, n, b, n1, c, n2,i);
		break;
	case 2:
		system("cls");
		cin.ignore();
		UpdateYandS();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffCourses(a, n, b, n1, c, n2, i);
		break;
	case 3:
		system("cls");
		cin.ignore();
		DeleteYandS();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffCourses(a, n, b, n1, c, n2, i);
	case 4:
		system("cls");
		cin.ignore();
		ViewYandS();
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		MenuStaffCourses(a, n, b, n1, c, n2, i);
		break;
	default:
		break;
	}
}


void MenuLecturer(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i)
{
	int choice;
	system("cls");
	cout << "******************************************" << endl;
	cout << "    Hello " << c[i].Fullname << endl;
	cout << "       1. View list of courses in the current semester" << endl;
	cout << "       2. View list of student of a course" << endl;
	cout << "       3. View attendance list of a course" << endl;
	cout << "       5. Edit an attendance" << endl;
	cout << "       6. Import scoreboard" << endl;
	cout << "       7. Edit grade of a student" << endl;
	cout << "       8. View a scoreboard" << endl;
	cout << "       9. Setting" << endl;
	cout << "       10. Sign out" << endl;
	cout << "******************************************" << endl;
	do
	{
		cout << "Enter your choice (1-10): ";
		cin >> choice;
		if (choice < 1 || choice>10)
			cout << "Wrong choice! Please retry" << endl;
	} while (choice < 1 || choice>10);
	switch (choice)
	{
	case 9:
		SettingLecturer(a, n, b, n1, c, n2, i);
		break;
	case 10:
		ManHinhChinh(a, n, b, n1, c, n2);
		break;
	default:
		break;
	}
}

void SettingSV(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i) {
	int choice; string npass; char choice1;
	system("cls");
	cout << "******************************************" << endl;
	cout << "       1. View profile" << endl;
	cout << "       2. Change password" << endl;
	cout << "       3. Return" << endl;
	cout << "******************************************" << endl;
	do
	{
		cout << "Enter your choice (1-3): ";
		cin >> choice;
		if (choice < 1 || choice>3)
			cout << "Wrong choice! Please retry" << endl;
	} while (choice < 1 || choice>3);

	switch (choice)
	{
	case 1:
		system("cls");
		StudentProfile(a, n, i);
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		SettingSV(a, n, b, n1, c, n2, i);
		break;
	case 2:
		system("cls");
		npass = ChangePassword(a[i].password);
		CapNhatPassSV(a, n, npass, i);
		cout << "Your password has been changed successfully!!" << endl;
		cout << endl;

		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		SettingSV(a, n, b, n1, c, n2, i);
		break;
	case 3:
		MenuSinhVien(a, n,b,n1,c,n2, i);
		break;
	default:
		break;
	}
}

void SettingStaff(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i) {
	int choice; string npass; char choice1;
	system("cls");
	cout << "******************************************" << endl;
	cout << "       1. View profile" << endl;
	cout << "       2. Change password" << endl;
	cout << "       3. Return" << endl;
	cout << "******************************************" << endl;
	do
	{
		cout << "Enter your choice (1-3): ";
		cin >> choice;
		if (choice < 1 || choice>3)
			cout << "Wrong choice! Please retry" << endl;
	} while (choice < 1 || choice>3);

	switch (choice)
	{
	case 1:
		system("cls");
		StaffProfile(b, n1, i);
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		SettingStaff(a, n, b, n1, c, n2, i);
		break;
	case 2:
		system("cls");
		npass = ChangePassword(b[i].pass);
		CapNhatPassStaff(b, n1, npass, i);
		cout << "Your password has been changed successfully!!" << endl;
		cout << endl;

		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		SettingStaff(a, n, b, n1, c, n2, i);
		break;
	case 3:
		MenuSinhVien(a, n, b, n1, c, n2, i);
		break;
	default:
		break;
	}
}

void SettingLecturer(Student a[], int n, Staff b[], int n1, Lecturer c[], int n2, int i) {
	int choice; string npass; char choice1;
	system("cls");
	cout << "******************************************" << endl;
	cout << "       1. View profile" << endl;
	cout << "       2. Change password" << endl;
	cout << "       3. Return" << endl;
	cout << "******************************************" << endl;
	do
	{
		cout << "Enter your choice (1-3): ";
		cin >> choice;
		if (choice < 1 || choice>3)
			cout << "Wrong choice! Please retry" << endl;
	} while (choice < 1 || choice>3);

	switch (choice)
	{
	case 1:
		system("cls");
		LecturerProfile(c, n2, i);
		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		SettingLecturer(a, n, b, n1, c, n2, i);
		break;
	case 2:
		system("cls");
		npass = ChangePassword(c[i].password);
		CapNhatPassLecturer(c, n2, npass, i);
		cout << "Your password has been changed successfully!!" << endl;
		cout << endl;

		do
		{
			cout << "Press f to return ^^: "; cin >> choice1;
			if (choice1 != 'f')
			{
				cout << "Nooo press f ==!! ";
			}
		} while (choice1 != 'f');
		SettingLecturer(a, n, b, n1, c, n2, i);
		break;
	case 3:
		MenuLecturer(a, n, b, n1, c, n2, i);
		break;
	default:
		break;
	}
}

