#include<iostream>
#include<fstream>
#include<ctime>
#include<chrono>
#include<string>

#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main()
{
    
    time_t now = time(0);

    tm* time = localtime(&now);

    cout << "Year:" << 1900 + time->tm_year << endl;
    cout << "Month: " << 1 + time->tm_mon << endl;
    cout << "Day: " << time->tm_mday << endl;
    cout << "Time: " << time->tm_hour << ":";
    cout << time->tm_min << ":";
    cout << time->tm_sec << endl;
    
    string temp;
    getline(cin, temp);
    cout << temp;
    
  
 
	return 0;
}