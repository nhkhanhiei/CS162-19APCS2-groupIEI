#include "Header.h"


int main() {
	Student* a = NULL; int n; 
	Staff* b = NULL; int n1;
	Lecturer *c = NULL ; int n2 = 1;
	NhapSVtuFile(a, n); 
	NhapStafftuFile(b, n1);
	NhapLecturertuFile(c, n2);
	//DocLecturer(c, n2);
	//DocStaff(b, n1);
	//Doc(a, n);
	//Login(a, n, s, s2);
	ManHinhChinh(a, n,b,n1,c,n2);
	delete[] c;
	delete[] b;
	delete[] a;
	
	return 0;
}