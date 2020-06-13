#include "Scoreboard.h"

void toUpper(char& c)
{
	c = toupper(static_cast<unsigned char>(c));
}

void viewScoreboard()
{
	string temp, filename;

	cout << "Input scoreboard you would like to see: \n" << endl;
	cout << "   Year(yyyy-yyyy): ";
	getline(cin, filename);
	for_each(filename.begin(), filename.end(), toUpper);
	string f1 = filename;

	cout << "   Semester: ";
	getline(cin, temp);
	for_each(temp.begin(), temp.end(), toUpper);
	string f2 = temp;
	filename += '-' + temp;

	cout << "   Class: ";
	getline(cin, temp);
	for_each(temp.begin(), temp.end(), toUpper);
	string f3 = temp;
	filename += '-' + temp;

	cout << "   Course ID: ";
	getline(cin, temp);
	for_each(temp.begin(), temp.end(), toUpper);
	string f4 = temp;

	filename += '-' + temp + "-Student.txt";
	fstream fin;
	fin.open(filename, ios::in);

	if (fin.fail())
	{
		cout << "\nUnable to open file!" << endl;
		fin.close();
		return;
	}

	system("cls");
	cout << "<School year: " << f1 << "\\ Semester: " << f2 << "\\ Class: " << f3 << "\\ Course: " << f4 << ">" << endl;
	cout << "\n";
	int n;
	fin >> n;
	fin.ignore();
	StudentMenu* student = new StudentMenu[n + 1];
	for (int i = 0; i < n; i++)
	{
		getline(fin, student[i].id);
		getline(fin, student[i].password);
		getline(fin, student[i].name);
		getline(fin, student[i].DoB);
		getline(fin, student[i].Class);
		getline(fin, student[i].status);
		getline(fin, student[i].midterm);
		getline(fin, student[i].final);
		getline(fin, student[i].bonus);
		getline(fin, student[i].total);
		for (int j = 0; j < 10; j++)
			getline(fin, student[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << student[i].name << ": " << endl;

		cout << "   + Midterm: " << student[i].midterm;
		if (student[i].midterm == "-1")
			cout << " (Student yet to have this grade!)" << endl;
		else
			cout << endl;
		cout << "   + Final: " << student[i].final;
		if (student[i].final == "-1")
			cout << "   (Student yet to have this grade!)" << endl;
		else
			cout << endl;
		cout << "   + Bonus: " << student[i].bonus;
		if (student[i].bonus == "-1")
			cout << "   (Student yet to have this grade!)" << endl;
		else
			cout << endl;
		cout << "   + Total: " << student[i].total;
		if (student[i].total == "-1")
			cout << "   (Student yet to have this grade!)" << endl;
		else
			cout << endl;
		cout << "\n";
	}

	fin.close();
	delete[] student;
}

void exportScoreboard()
{
	string temp, filename;

	cout << "Input scoreboard you would like to export: \n" << endl;
	cout << "   Year(yyyy-yyyy): ";
	getline(cin, filename);
	for_each(filename.begin(), filename.end(), toUpper);
	string f1 = filename;

	cout << "   Semester: ";
	getline(cin, temp);
	for_each(temp.begin(), temp.end(), toUpper);
	string f2 = temp;
	filename += '-' + temp;

	cout << "   Class: ";
	getline(cin, temp);
	for_each(temp.begin(), temp.end(), toUpper);
	string f3 = temp;
	filename += '-' + temp;

	cout << "   Course ID: ";
	getline(cin, temp);
	for_each(temp.begin(), temp.end(), toUpper);
	string f4 = temp;

	filename += '-' + temp + "-Student.txt";
	fstream fin;
	fin.open(filename, ios::in);

	if (fin.fail())
	{
		cout << "\nUnable to open file!" << endl;
		fin.close();
		return;
	}

	int n;
	fin >> n;
	fin.ignore();
	StudentMenu* student = new StudentMenu[n + 1];
	for (int i = 0; i < n; i++)
	{
		getline(fin, student[i].id);
		getline(fin, student[i].password);
		getline(fin, student[i].name);
		getline(fin, student[i].DoB);
		getline(fin, student[i].Class);
		getline(fin, student[i].status);
		getline(fin, student[i].midterm);
		getline(fin, student[i].final);
		getline(fin, student[i].bonus);
		getline(fin, student[i].total);
		for (int j = 0; j < 10; j++)
			getline(fin, student[i].att[j]);
		getline(fin, temp);
		fin.ignore(1, '\n');
	}
	fin.close();

	fstream fout;
	string F;
	F += f3;
	F += "-";
	F += f4;
	F += "-Scoreboard.csv";

	fout.open(F, ios::out);
	fout << "No,Student ID,Fullname,Midterm,Final,Bonus,Total";
	string def;
	fout << endl;
	for (int i = 0; i < n; i++)
	{
		fout << i + 1 << "," << student[i].id << "," << student[i].name << "," << student[i].midterm << "," << student[i].final << "," << student[i].bonus << "," << student[i].total << ",";
		fout << endl;
	}
	fout.close();
	delete[] student;

	cout << "\nExport successfully!" << endl;
}