#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
struct Name
{
    string first;
    string last;
};
struct Bdate
{
    int year;
    int month;
    int day;
};
struct Person
{
    int no;
    string ID;
    Name name;
    string email;
    string phone;
    Bdate bdate;
    string jobtitle;
};

int makeStruct(struct Person person[])
{
    string line;
    ifstream ifs;
    stringstream ss;
    int length = 0;
    ifs.open("people-100.csv");
    if (!ifs)
    {
        cerr << "File Open Error\n";
        exit(0);
    }
    while (ifs >> line)
    {
        ss << cout << line << endl;
        length++;
    }

    return length;
}
/*******************************
 * Code your program here
 *******************************/