#include<iostream>
#include<fstream>
#include<ctime>
#include<chrono>
#include<string>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
    /*
    time_t now = time(0);

    tm* ltm = localtime(&now);

    cout << "Year:" << 1900 + ltm->tm_year << endl;
    cout << "Month: " << 1 + ltm->tm_mon << endl;
    cout << "Day: " << ltm->tm_mday << endl;
    cout << "Time: " << ltm->tm_hour << ":";
    cout << ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;
    
    string temp;
    getline(cin, temp);
    cout << temp;
    */
    int x = -1;
    if (x == -(-x))
        cout << FLT_MIN;

   /* struct tm  t = { 0 };
    t.tm_mday = a.day;
    t.tm_mon = a.month - 1;
    t.tm_year = a.year - 1900;*/
	return 0;
}